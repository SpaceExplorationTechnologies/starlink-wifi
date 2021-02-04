/* Copyright (c) 2014-2016, The Linux Foundation. All rights reserved.
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/err.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/bio.h>
#include <linux/blkdev.h>
#include <linux/mempool.h>
#include <linux/slab.h>
#include <linux/device-mapper.h>
#include <linux/printk.h>
#include <crypto/ice.h>
#include <linux/qcom_scm.h>

#define DM_MSG_PREFIX "req-crypt"


#define MIN_IOS 256
#define AES_XTS_IV_LEN 16
#define MAX_MSM_ICE_KEY_LUT_SIZE 32

#define DM_REQ_CRYPT_ERROR -1

struct req_crypt_result {
	struct completion completion;
	int err;
};


static struct dm_dev *dev;
static struct kmem_cache *_req_crypt_io_pool;
static sector_t start_sector_orig;
static mempool_t *req_io_pool;
static struct ice_crypto_setting *ice_settings;

struct req_dm_crypt_io {
	struct ice_crypto_setting ice_settings;
	struct request *cloned_request;
	int error;
	atomic_t pending;
};

struct req_dm_split_req_io {
	u8 IV[AES_XTS_IV_LEN];
	int size;
	struct request *clone;
};

/*
 * If bio->bi_dev is a partition, remap the location
 */
static inline void req_crypt_blk_partition_remap(struct bio *bio)
{
	struct block_device *bdev = bio->bi_bdev;

	if (bio_sectors(bio) && bdev != bdev->bd_contains) {
		struct hd_struct *p = bdev->bd_part;
		/*
		* Check for integer overflow, should never happen.
		*/
		if (p->start_sect > (UINT_MAX - bio->bi_iter.bi_sector))
			BUG();

		bio->bi_iter.bi_sector += p->start_sect;
		bio->bi_bdev = bdev->bd_contains;
	}
}

/*
 * The endio function is called from ksoftirqd context (atomic).
 * For ICE operation simply free up req_io and return from this
 * function
 */
static int req_crypt_endio(struct dm_target *ti, struct request *clone,
			    int error, union map_info *map_context)
{
	struct req_dm_crypt_io *req_io = map_context->ptr;

	/* If it is for ICE, free up req_io and return */
	mempool_free(req_io, req_io_pool);
	return error;
}

/*
 * This function is called with interrupts disabled
 * The function remaps the clone for the underlying device.
 * it is returned to dm once mapping is done
 */
static int req_crypt_map(struct dm_target *ti, struct request *clone,
			 union map_info *map_context)
{
	struct req_dm_crypt_io *req_io = NULL;
	int error = DM_REQ_CRYPT_ERROR, copy_bio_sector_to_req = 0;
	struct bio *bio_src = NULL;
	gfp_t gfp_flag = GFP_KERNEL;

	if (in_interrupt() || irqs_disabled())
		gfp_flag = GFP_NOWAIT;

	req_io = mempool_alloc(req_io_pool, gfp_flag);
	if (!req_io) {
		DMERR("%s req_io allocation failed\n", __func__);
		BUG();
		return DM_REQ_CRYPT_ERROR;
	}

	/* Save the clone in the req_io, the callback to the worker
	 * queue will get the req_io
	 */
	req_io->cloned_request = clone;
	map_context->ptr = req_io;
	atomic_set(&req_io->pending, 0);

	/* Get the queue of the underlying original device */
	clone->q = bdev_get_queue(dev->bdev);
	clone->rq_disk = dev->bdev->bd_disk;

	__rq_for_each_bio(bio_src, clone) {
		bio_src->bi_bdev = dev->bdev;
		/* Currently the way req-dm works is that once the underlying
		 * device driver completes the request by calling into the
		 * block layer. The block layer completes the bios (clones) and
		 * then the cloned request. This is undesirable for req-dm-crypt
		 * hence added a flag BIO_DONTFREE, this flag will ensure that
		 * blk layer does not complete the cloned bios before completing
		 * the request. When the crypt endio is called, post-processing
		 * is done and then the dm layer will complete the bios (clones)
		 * and free them.
		 */
		bio_src->bi_flags |= 1 << BIO_INLINECRYPT;

		/*
		 * If this device has partitions, remap block n
		 * of partition p to block n+start(p) of the disk.
		 */
		req_crypt_blk_partition_remap(bio_src);
		if (copy_bio_sector_to_req == 0) {
			clone->__sector = bio_src->bi_iter.bi_sector;
			copy_bio_sector_to_req++;
		}
		blk_queue_bounce(clone->q, &bio_src);
	}

	/* Set all crypto parameters for inline crypto engine */
	memcpy(&req_io->ice_settings, ice_settings,
					sizeof(struct ice_crypto_setting));

	return DM_MAPIO_REMAPPED;


}


static void req_crypt_dtr(struct dm_target *ti)
{
	DMDEBUG("dm-req-crypt Destructor.\n");

	if (req_io_pool) {
		mempool_destroy(req_io_pool);
		req_io_pool = NULL;
	}

	kfree(ice_settings);
	ice_settings = NULL;

	if (_req_crypt_io_pool)
		kmem_cache_destroy(_req_crypt_io_pool);

	if (dev) {
		dm_put_device(ti, dev);
		dev = NULL;
	}
}

static int qcom_set_ice_config(char **argv)
{
	int ret;
	struct ice_config_sec *ice;

	ice = kmalloc(sizeof(struct ice_config_sec), GFP_KERNEL);
	if (!ice) {
		DMERR("%s: no memory allocated\n", __func__);
		return -ENOMEM;
	}

	/* update the ice config structure to send tz */
	ice->index = ice_settings->key_index;
	ice->key_size = ice_settings->key_size;
	ice->algo_mode = ice_settings->algo_mode;
	ice->key_mode = ice_settings->key_mode;

	ret = qcom_config_sec_ice(ice, sizeof(struct ice_config_sec));

	if (ret)
		DMERR("%s: ice configuration fail\n", __func__);

	kfree(ice);
	return ret;
}

/*
 * Construct an encryption mapping:
 * <cipher> <key> <iv_offset> <dev_path> <start>
 */
static int req_crypt_ctr(struct dm_target *ti, unsigned int argc, char **argv)
{
	int err = DM_REQ_CRYPT_ERROR;
	unsigned long long tmpll;
	char dummy;

	DMDEBUG("dm-req-crypt Constructor.\n");

	if (argc < 5) {
		DMERR(" %s Not enough args\n", __func__);
		err = DM_REQ_CRYPT_ERROR;
		goto ctr_exit;
	}

	if (argv[3]) {
		if (dm_get_device(ti, argv[3],
				dm_table_get_mode(ti->table), &dev)) {
			DMERR(" %s Device Lookup failed\n", __func__);
			err =  DM_REQ_CRYPT_ERROR;
			goto ctr_exit;
		}
	} else {
		DMERR(" %s Arg[3] invalid\n", __func__);
		err =  DM_REQ_CRYPT_ERROR;
		goto ctr_exit;
	}

	if (argv[4]) {
		if (sscanf(argv[4], "%llu%c", &tmpll, &dummy) != 1) {
			DMERR("%s Invalid device sector\n", __func__);
			err =  DM_REQ_CRYPT_ERROR;
			goto ctr_exit;
		}
	} else {
		DMERR(" %s Arg[4] invalid\n", __func__);
		err =  DM_REQ_CRYPT_ERROR;
		goto ctr_exit;
	}
	start_sector_orig = tmpll;

	_req_crypt_io_pool = KMEM_CACHE(req_dm_crypt_io, 0);
	if (!_req_crypt_io_pool) {
		err =  DM_REQ_CRYPT_ERROR;
		goto ctr_exit;
	}

	/* configure ICE settings */
	ice_settings =
		kzalloc(sizeof(struct ice_crypto_setting), GFP_KERNEL);
	if (!ice_settings) {
		err = -ENOMEM;
		goto ctr_exit;
	}
	ice_settings->key_size = ICE_CRYPTO_KEY_SIZE_128;
	ice_settings->algo_mode = ICE_CRYPTO_ALGO_MODE_AES_XTS;
	ice_settings->key_mode = ICE_CRYPTO_USE_KEY0_HW_KEY;
	if (kstrtou16(argv[1], 0, &ice_settings->key_index) ||
		ice_settings->key_index < 0 ||
		ice_settings->key_index > MAX_MSM_ICE_KEY_LUT_SIZE) {
		DMERR("%s Err: key index %d received for ICE\n",
				__func__, ice_settings->key_index);
		err = DM_REQ_CRYPT_ERROR;
		goto ctr_exit;
	}

	req_io_pool = mempool_create_slab_pool(MIN_IOS, _req_crypt_io_pool);
	if (!req_io_pool) {
		DMERR("%s req_io_pool not allocated\n", __func__);
		err = -ENOMEM;
		goto ctr_exit;
	}

	/*
	 * If underlying device supports flush/discard, mapped target
	 * should also allow it
	 */
	ti->num_flush_bios = 1;
	ti->num_discard_bios = 1;

	err = qcom_set_ice_config(argv);
	if (err) {
		DMERR("%s: ice configuration fail\n", __func__);
		goto ctr_exit;
	}

	DMINFO("%s: Mapping block_device %s to dm-req-crypt ok!\n",
		__func__, argv[3]);
ctr_exit:
	if (err)
		req_crypt_dtr(ti);

	return err;
}

static int req_crypt_iterate_devices(struct dm_target *ti,
				 iterate_devices_callout_fn fn, void *data)
{
	return fn(ti, dev, start_sector_orig, ti->len, data);
}

static struct target_type req_crypt_target = {
	.name   = "req-crypt",
	.version = {1, 0, 0},
	.module = THIS_MODULE,
	.ctr    = req_crypt_ctr,
	.dtr    = req_crypt_dtr,
	.map_rq = req_crypt_map,
	.rq_end_io = req_crypt_endio,
	.iterate_devices = req_crypt_iterate_devices,
};

static int __init req_dm_crypt_init(void)
{
	int r;


	r = dm_register_target(&req_crypt_target);
	if (r < 0) {
		DMERR("register failed %d", r);
		return r;
	}

	DMINFO("dm-req-crypt successfully initalized.\n");

	return r;
}

static void __exit req_dm_crypt_exit(void)
{
	dm_unregister_target(&req_crypt_target);
}

module_init(req_dm_crypt_init);
module_exit(req_dm_crypt_exit);

MODULE_DESCRIPTION(DM_NAME " target for request based transparent encryption / decryption");
MODULE_LICENSE("GPL v2");
