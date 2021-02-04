/*
 * Copyright (c) 2015-2017, The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/* Usage:
 *
 * Step 1:
 *
 * insmod fw_auth_test.ko
 *
 * Step 2:
 *
 * Fill in the appropriate paths of files in place of "<>" below.
 *
 * cat <signature data file> > /sys/firmware/signature_data
 * cat <certificate data file> > /sys/firmware/cert_data
 * cat <binary file to be authenticated> > /sys/firmware/bin_data
 *
 * Step 3:
 *
 * To verify RSA signature:
 *
 * echo 1 > /sys/firmware/auth_enable
 *
 *
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <misc/fw_auth.h>
#include <crypto/hash.h>
#include <linux/fs.h>
#include <crypto/public_key.h>
#include <linux/highuid.h>
#include <linux/sysfs.h>
#include <linux/gfp.h>
#include <linux/fcntl.h>
#include <linux/syscalls.h>

static int auth_enable;
static int fw_bin_size;
static int sign_size;
static int cert_size;
static uint8_t *fw_bin_data;
static uint8_t *sign_data;
static uint8_t *cert_data;

static ssize_t fw_bin_write(struct file *filp, struct kobject *kobj,
	struct bin_attribute *bin_attr,
	char *buf, loff_t pos, size_t count)
{
	uint8_t *tmp;
	/*
	 * Position '0' means new file being written,
	 * Hence allocate new memory after freeing already allocated mem if any
	 */
	if (pos == 0) {
		kfree(fw_bin_data);
		fw_bin_data = kzalloc((count) * sizeof(uint8_t), GFP_KERNEL);
	} else {
		tmp = fw_bin_data;
		fw_bin_data = krealloc(tmp,
			(pos + count) * sizeof(uint8_t), GFP_KERNEL);
	}

	if (!fw_bin_data)
		return -ENOMEM;

	memcpy((fw_bin_data + pos), buf, count);
	fw_bin_size = pos + count;
	return count;
}

static ssize_t cert_write(struct file *filp, struct kobject *kobj,
	struct bin_attribute *bin_attr,
	char *buf, loff_t pos, size_t count)
{
	uint8_t *tmp;

	if (pos == 0) {
		kfree(cert_data);
		cert_data = kzalloc((count) * sizeof(uint8_t), GFP_KERNEL);
	} else {
		tmp = cert_data;
		cert_data = krealloc(tmp, (pos + count) * sizeof(uint8_t),
					GFP_KERNEL);
	}

	if (!cert_data)
		return -ENOMEM;

	memcpy((cert_data + pos), buf, count);
	cert_size = pos + count;
	return count;
}

static ssize_t signature_write(struct file *filp, struct kobject *kobj,
	struct bin_attribute *bin_attr,
	char *buf, loff_t pos, size_t count)
{
	uint8_t *tmp;

	if (pos == 0) {
		kfree(sign_data);
		sign_data = kzalloc((count) * sizeof(uint8_t), GFP_KERNEL);
	} else {
		tmp = sign_data;
		sign_data = krealloc(tmp, (pos + count) * sizeof(uint8_t),
					GFP_KERNEL);
	}

	if (!sign_data)
		return -ENOMEM;

	memcpy((sign_data + pos), buf, count);
	sign_size = pos + count;
	return count;
}

struct bin_attribute fw_bin_attr = {
	.attr = {.name = "bin_data", .mode = 0644},
	.write = fw_bin_write,
};

struct bin_attribute cert_attr = {
	.attr = {.name = "cert_data", .mode = 0644},
	.write = cert_write,
};

struct bin_attribute signature_attr = {
	.attr = {.name = "signature_data", .mode = 0644},
	.write = signature_write,
};

static int auth_test(void)
{
	struct auth_input *ai;
	int ret = 0;
	int total_len = 0;

	total_len = fw_bin_size + cert_size + sign_size
				+ sizeof(struct auth_input);
	ai = kzalloc(total_len, GFP_KERNEL);
	if (!ai) {
		ret = -ENOMEM;
		goto err_free;
	}

	ai->sig_hash_algo = HASH_ALGO_SHA256;
	ai->pk_algo = PKEY_ALGO_RSA;
	ai->cert_type = PKEY_ID_X509;

	if (fw_bin_data && cert_data && sign_data) {
		ai->data = (uint8_t *) fw_bin_data;
		ai->data_len = fw_bin_size;
		ai->certBuffer = (uint8_t *) cert_data;
		ai->cert_len = cert_size;
		ai->signature = (uint8_t *) sign_data;
		ai->sig_len = sign_size;
	} else {
		pr_err("\nInput Data not provided");
		ret = -ENOMEM;
		goto err_free_ai;
	}

	ret = authenticate_fw(ai);
	pr_info("\nAuthentication %s\n", (ret == 0) ? "Passed" : "Failed");

err_free_ai:
	kfree(ai);

err_free:
	kfree(fw_bin_data);
	fw_bin_data = NULL;
	fw_bin_size = 0;

	kfree(cert_data);
	cert_data = NULL;
	cert_size = 0;

	kfree(sign_data);
	sign_data = NULL;
	sign_size = 0;

	return ret;
}

static ssize_t
store_auth_enable(struct device *dev, struct attribute *attr,
				const char *buf, size_t count)
{
	int err;

	if (!buf) {
		pr_err("\n Input must not be NULL");
		return -EINVAL;
	}
	if (kstrtouint(buf, 10, &auth_enable))
		pr_err("\n Please enter a valid unsigned integer");

	if (auth_enable == 1) {
		err = auth_test();
		if (err)
			pr_err("\n Authentication Failed with Error:(%d)\n"
						, err);
	} else {
		pr_info("\nEcho 1 to auth_enable to test authentication");
	}
	return count;
}

static ssize_t
show_auth_enable(struct device *dev, struct attribute *attr,
				char *buf)
{
	return snprintf(buf, sizeof(auth_enable), "%d", auth_enable);
}

static DEVICE_ATTR(auth_enable, 0644, show_auth_enable, store_auth_enable);

static struct attribute *auth_attrs[] = {
	&dev_attr_auth_enable.attr,
	NULL,
};

static struct attribute_group auth_attr_grp = {
	.attrs = auth_attrs,
};

struct kobject *auth_kobj;

static int __init auth_init(void)
{
	int err;

	auth_kobj = kobject_create_and_add("fw_auth", firmware_kobj);
	err = sysfs_create_group(auth_kobj, &auth_attr_grp);
	if (err) {
		kobject_put(auth_kobj);
		return err;
	}

	return 0;
}

static int __init auth_test_init(void)
{
	sysfs_create_bin_file(firmware_kobj, &fw_bin_attr);
	sysfs_create_bin_file(firmware_kobj, &cert_attr);
	sysfs_create_bin_file(firmware_kobj, &signature_attr);

	if (!auth_init())
		pr_info("\nAuthentication Test Module Loaded!\n");
	else
		pr_info("\nFailed to load Authentication Test module\n");
	return 0;
}

static void __exit auth_test_exit(void)
{
	kfree(fw_bin_data);
	kfree(cert_data);
	kfree(sign_data);

	sysfs_remove_bin_file(firmware_kobj, &fw_bin_attr);
	sysfs_remove_bin_file(firmware_kobj, &cert_attr);
	sysfs_remove_bin_file(firmware_kobj, &signature_attr);

	sysfs_remove_group(auth_kobj, &auth_attr_grp);
	kobject_put(auth_kobj);
	pr_info("\nAuthentication Test Module Unloaded!\n");
}

MODULE_LICENSE("Dual BSD/GPL");
module_init(auth_test_init);
module_exit(auth_test_exit);
