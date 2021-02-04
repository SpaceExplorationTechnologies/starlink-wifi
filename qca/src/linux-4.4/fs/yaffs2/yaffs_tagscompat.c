/*
 * YAFFS: Yet Another Flash File System. A NAND-flash specific file system.
 *
 * Copyright (C) 2002-2011 Aleph One Ltd.
 *   for Toby Churchill Ltd and Brightstar Engineering
 *
 * Created by Charles Manning <charles@aleph1.co.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include "yaffs_guts.h"
#include "yaffs_tagscompat.h"
#include "yaffs_ecc.h"
#include "yaffs_getblockinfo.h"
#include "yaffs_trace.h"

#if 0
static void yaffs_handle_rd_data_error(struct yaffs_dev *dev, int nand_chunk);
#endif


/********** Tags ECC calculations  *********/


void yaffs_calc_tags_ecc(struct yaffs_tags *tags)
{
	/* Calculate an ecc */
	unsigned char *b = ((union yaffs_tags_union *)tags)->as_bytes;
	unsigned i, j;
	unsigned ecc = 0;
	unsigned bit = 0;

	tags->ecc = 0;

	for (i = 0; i < 8; i++) {
		for (j = 1; j & 0xff; j <<= 1) {
			bit++;
			if (b[i] & j)
				ecc ^= bit;
		}
	}
	tags->ecc = ecc;
}

int yaffs_check_tags_ecc(struct yaffs_tags *tags)
{
	unsigned ecc = tags->ecc;

	yaffs_calc_tags_ecc(tags);

	ecc ^= tags->ecc;

	if (ecc && ecc <= 64) {
		/* TODO: Handle the failure better. Retire? */
		unsigned char *b = ((union yaffs_tags_union *)tags)->as_bytes;

		ecc--;

		b[ecc / 8] ^= (1 << (ecc & 7));

		/* Now recvalc the ecc */
		yaffs_calc_tags_ecc(tags);

		return 1;	/* recovered error */
	} else if (ecc) {
		/* Wierd ecc failure value */
		/* TODO Need to do somethiong here */
		return -1;	/* unrecovered error */
	}
	return 0;
}

#if 0
/********** Tags **********/

static void yaffs_load_tags_to_spare(struct yaffs_spare *spare_ptr,
				     struct yaffs_tags *tags_ptr)
{
	union yaffs_tags_union *tu = (union yaffs_tags_union *)tags_ptr;

	yaffs_calc_tags_ecc(tags_ptr);

	spare_ptr->tb0 = tu->as_bytes[0];
	spare_ptr->tb1 = tu->as_bytes[1];
	spare_ptr->tb2 = tu->as_bytes[2];
	spare_ptr->tb3 = tu->as_bytes[3];
	spare_ptr->tb4 = tu->as_bytes[4];
	spare_ptr->tb5 = tu->as_bytes[5];
	spare_ptr->tb6 = tu->as_bytes[6];
	spare_ptr->tb7 = tu->as_bytes[7];
}

static void yaffs_get_tags_from_spare(struct yaffs_dev *dev,
				      struct yaffs_spare *spare_ptr,
				      struct yaffs_tags *tags_ptr)
{
	union yaffs_tags_union *tu = (union yaffs_tags_union *)tags_ptr;
	int result;

	tu->as_bytes[0] = spare_ptr->tb0;
	tu->as_bytes[1] = spare_ptr->tb1;
	tu->as_bytes[2] = spare_ptr->tb2;
	tu->as_bytes[3] = spare_ptr->tb3;
	tu->as_bytes[4] = spare_ptr->tb4;
	tu->as_bytes[5] = spare_ptr->tb5;
	tu->as_bytes[6] = spare_ptr->tb6;
	tu->as_bytes[7] = spare_ptr->tb7;

	result = yaffs_check_tags_ecc(tags_ptr);
	if (result > 0)
		dev->n_tags_ecc_fixed++;
	else if (result < 0)
		dev->n_tags_ecc_unfixed++;
}

static void yaffs_spare_init(struct yaffs_spare *spare)
{
	memset(spare, 0xff, sizeof(struct yaffs_spare));
}

static int yaffs_wr_nand(struct yaffs_dev *dev,
			 int nand_chunk, const u8 *data,
			 struct yaffs_spare *spare)
{
	int data_size = dev->data_bytes_per_chunk;

	return dev->drv.drv_write_chunk_fn(dev, nand_chunk,
				data, data_size,
				(u8 *) spare, sizeof(*spare));
}

static int yaffs_rd_chunk_nand(struct yaffs_dev *dev,
			       int nand_chunk,
			       u8 *data,
			       struct yaffs_spare *spare,
			       enum yaffs_ecc_result *ecc_result,
			       int correct_errors)
{
	int ret_val;
	struct yaffs_spare local_spare;
	int data_size;
	int spare_size;
	int ecc_result1, ecc_result2;
	u8 calc_ecc[3];

	if (!spare) {
		/* If we don't have a real spare, then we use a local one. */
		/* Need this for the calculation of the ecc */
		spare = &local_spare;
	}
	data_size = dev->data_bytes_per_chunk;
	spare_size = sizeof(struct yaffs_spare);

	if (dev->param.use_nand_ecc)
		return dev->drv.drv_read_chunk_fn(dev, nand_chunk,
						data, data_size,
						(u8 *) spare, spare_size,
						ecc_result);


	/* Handle the ECC at this level. */

	ret_val = dev->drv.drv_read_chunk_fn(dev, nand_chunk,
						 data, data_size,
						 (u8 *)spare, spare_size,
						NULL);
	if (!data || !correct_errors)
		return ret_val;

	/* Do ECC correction if needed. */
	yaffs_ecc_calc(data, calc_ecc);
	ecc_result1 = yaffs_ecc_correct(data, spare->ecc1, calc_ecc);
	yaffs_ecc_calc(&data[256], calc_ecc);
	ecc_result2 = yaffs_ecc_correct(&data[256], spare->ecc2, calc_ecc);

	if (ecc_result1 > 0) {
		yaffs_trace(YAFFS_TRACE_ERROR,
			"**>>yaffs ecc error fix performed on chunk %d:0",
			nand_chunk);
		dev->n_ecc_fixed++;
	} else if (ecc_result1 < 0) {
		yaffs_trace(YAFFS_TRACE_ERROR,
			"**>>yaffs ecc error unfixed on chunk %d:0",
			nand_chunk);
		dev->n_ecc_unfixed++;
	}

	if (ecc_result2 > 0) {
		yaffs_trace(YAFFS_TRACE_ERROR,
			"**>>yaffs ecc error fix performed on chunk %d:1",
			nand_chunk);
		dev->n_ecc_fixed++;
	} else if (ecc_result2 < 0) {
		yaffs_trace(YAFFS_TRACE_ERROR,
			"**>>yaffs ecc error unfixed on chunk %d:1",
			nand_chunk);
		dev->n_ecc_unfixed++;
	}

	if (ecc_result1 || ecc_result2) {
		/* We had a data problem on this page */
		yaffs_handle_rd_data_error(dev, nand_chunk);
	}

	if (ecc_result1 < 0 || ecc_result2 < 0)
		*ecc_result = YAFFS_ECC_RESULT_UNFIXED;
	else if (ecc_result1 > 0 || ecc_result2 > 0)
		*ecc_result = YAFFS_ECC_RESULT_FIXED;
	else
		*ecc_result = YAFFS_ECC_RESULT_NO_ERROR;

	return ret_val;
}

/*
 * Functions for robustisizing
 */

static void yaffs_handle_rd_data_error(struct yaffs_dev *dev, int nand_chunk)
{
	int flash_block = nand_chunk / dev->param.chunks_per_block;

	/* Mark the block for retirement */
	yaffs_get_block_info(dev, flash_block + dev->block_offset)->
		needs_retiring = 1;
	yaffs_trace(YAFFS_TRACE_ERROR | YAFFS_TRACE_BAD_BLOCKS,
		"**>>Block %d marked for retirement",
		flash_block);

	/* TODO:
	 * Just do a garbage collection on the affected block
	 * then retire the block
	 * NB recursion
	 */
}

static int yaffs_tags_compat_wr(struct yaffs_dev *dev,
			 int nand_chunk,
			 const u8 *data, const struct yaffs_ext_tags *ext_tags)
{
	struct yaffs_spare spare;
	struct yaffs_tags tags;

	yaffs_spare_init(&spare);

	if (ext_tags->is_deleted)
		spare.page_status = 0;
	else {
		tags.obj_id = ext_tags->obj_id;
		tags.chunk_id = ext_tags->chunk_id;

		tags.n_bytes_lsb = ext_tags->n_bytes & (1024 - 1);

		if (dev->data_bytes_per_chunk >= 1024)
			tags.n_bytes_msb = (ext_tags->n_bytes >> 10) & 3;
		else
			tags.n_bytes_msb = 3;

		tags.serial_number = ext_tags->serial_number;

		if (!dev->param.use_nand_ecc && data) {
			yaffs_ecc_calc(data, spare.ecc1);
			yaffs_ecc_calc(&data[256], spare.ecc2);
		}

		yaffs_load_tags_to_spare(&spare, &tags);
	}
	return yaffs_wr_nand(dev, nand_chunk, data, &spare);
}

static int yaffs_tags_compat_rd(struct yaffs_dev *dev,
			 int nand_chunk,
			 u8 *data, struct yaffs_ext_tags *ext_tags)
{
	struct yaffs_spare spare;
	struct yaffs_tags tags;
	enum yaffs_ecc_result ecc_result = YAFFS_ECC_RESULT_UNKNOWN;
	static struct yaffs_spare spare_ff;
	static int init;
	int deleted;

	if (!init) {
		memset(&spare_ff, 0xff, sizeof(spare_ff));
		init = 1;
	}

	if (!yaffs_rd_chunk_nand(dev, nand_chunk,
					data, &spare, &ecc_result, 1))
		return YAFFS_FAIL;

	/* ext_tags may be NULL */
	if (!ext_tags)
		return YAFFS_OK;

	deleted = (hweight8(spare.page_status) < 7) ? 1 : 0;

	ext_tags->is_deleted = deleted;
	ext_tags->ecc_result = ecc_result;
	ext_tags->block_bad = 0;	/* We're reading it */
	/* therefore it is not a bad block */
	ext_tags->chunk_used =
		memcmp(&spare_ff, &spare, sizeof(spare_ff)) ? 1 : 0;

	if (ext_tags->chunk_used) {
		yaffs_get_tags_from_spare(dev, &spare, &tags);
		ext_tags->obj_id = tags.obj_id;
		ext_tags->chunk_id = tags.chunk_id;
		ext_tags->n_bytes = tags.n_bytes_lsb;

		if (dev->data_bytes_per_chunk >= 1024)
			ext_tags->n_bytes |=
				(((unsigned)tags.n_bytes_msb) << 10);

		ext_tags->serial_number = tags.serial_number;
	}

	return YAFFS_OK;
}

static int yaffs_tags_compat_mark_bad(struct yaffs_dev *dev, int flash_block)
{
	struct yaffs_spare spare;

	memset(&spare, 0xff, sizeof(struct yaffs_spare));

	spare.block_status = 'Y';

	yaffs_wr_nand(dev, flash_block * dev->param.chunks_per_block, NULL,
		      &spare);
	yaffs_wr_nand(dev, flash_block * dev->param.chunks_per_block + 1,
		      NULL, &spare);

	return YAFFS_OK;
}

static int yaffs_tags_compat_query_block(struct yaffs_dev *dev,
				  int block_no,
				  enum yaffs_block_state *state,
				  u32 *seq_number)
{
	struct yaffs_spare spare0, spare1;
	static struct yaffs_spare spare_ff;
	static int init;
	enum yaffs_ecc_result dummy;

	if (!init) {
		memset(&spare_ff, 0xff, sizeof(spare_ff));
		init = 1;
	}

	*seq_number = 0;

	/* Look for bad block markers in the first two chunks */
	yaffs_rd_chunk_nand(dev, block_no * dev->param.chunks_per_block,
			    NULL, &spare0, &dummy, 0);
	yaffs_rd_chunk_nand(dev, block_no * dev->param.chunks_per_block + 1,
			    NULL, &spare1, &dummy, 0);

	if (hweight8(spare0.block_status & spare1.block_status) < 7)
		*state = YAFFS_BLOCK_STATE_DEAD;
	else if (memcmp(&spare_ff, &spare0, sizeof(spare_ff)) == 0)
		*state = YAFFS_BLOCK_STATE_EMPTY;
	else
		*state = YAFFS_BLOCK_STATE_NEEDS_SCAN;

	return YAFFS_OK;
}

void yaffs_tags_compat_install(struct yaffs_dev *dev)
{
	if(dev->param.is_yaffs2)
		return;
	if(!dev->tagger.write_chunk_tags_fn)
		dev->tagger.write_chunk_tags_fn = yaffs_tags_compat_wr;
	if(!dev->tagger.read_chunk_tags_fn)
		dev->tagger.read_chunk_tags_fn = yaffs_tags_compat_rd;
	if(!dev->tagger.query_block_fn)
		dev->tagger.query_block_fn = yaffs_tags_compat_query_block;
	if(!dev->tagger.mark_bad_fn)
		dev->tagger.mark_bad_fn = yaffs_tags_compat_mark_bad;
}
#else

#include "yaffs_packedtags1.h"

static int yaffs_tags_compat_write(struct yaffs_dev *dev,
				   int nand_chunk,
				   const u8 *data,
				   const struct yaffs_ext_tags *tags)
{
	struct yaffs_packed_tags1 pt1;
	u8 tag_buf[9];
	int retval;

	/* we assume that yaffs_packed_tags1 and yaffs_tags are compatible */
	compile_time_assertion(sizeof(struct yaffs_packed_tags1) == 12);
	compile_time_assertion(sizeof(struct yaffs_tags) == 8);

	yaffs_pack_tags1(&pt1, tags);
	yaffs_calc_tags_ecc((struct yaffs_tags *)&pt1);

	/* When deleting a chunk, the upper layer provides only skeletal
	 * tags, one with is_deleted set.  However, we need to update the
	 * tags, not erase them completely.  So we use the NAND write property
	 * that only zeroed-bits stick and set tag bytes to all-ones and
	 * zero just the (not) deleted bit.
	 */
	if (!dev->param.tags_9bytes) {
		if (tags->is_deleted) {
			memset(&pt1, 0xff, 8);
			/* clear delete status bit to indicate deleted */
			pt1.deleted = 0;
		}
		memcpy(tag_buf, &pt1, 8);
	} else {
		if (tags->is_deleted) {
			memset(tag_buf, 0xff, 8);
			tag_buf[8] = 0;
		} else {
			memcpy(tag_buf, &pt1, 8);
			tag_buf[8] = 0xff;
		}
	}

	retval = dev->drv.drv_write_chunk_fn(dev, nand_chunk,
			data,
			(data) ? dev->data_bytes_per_chunk : 0,
			tag_buf,
			(dev->param.tags_9bytes) ? 9 : 8);

	return retval;
}

/* Return with empty extended tags but add ecc_result.
 */
static int return_empty_tags(struct yaffs_ext_tags *tags,
			     enum yaffs_ecc_result ecc_result,
			     int retval)
{
	if (tags) {
		memset(tags, 0, sizeof(*tags));
		tags->ecc_result = ecc_result;
	}

	return retval;
}

static int yaffs_tags_compat_read(struct yaffs_dev *dev,
				  int nand_chunk,
				  u8 *data,
				  struct yaffs_ext_tags *tags)
{
	struct yaffs_packed_tags1 pt1;
	enum yaffs_ecc_result ecc_result;
	int retval;
	int deleted;
	u8 tag_buf[9];

	retval = dev->drv.drv_read_chunk_fn(dev, nand_chunk,
			data, dev->param.total_bytes_per_chunk,
			tag_buf,
			(dev->param.tags_9bytes) ? 9 : 8,
			&ecc_result);

	switch (ecc_result) {
	case YAFFS_ECC_RESULT_NO_ERROR:
	case YAFFS_ECC_RESULT_FIXED:
		break;

	case YAFFS_ECC_RESULT_UNFIXED:
	default:
		return_empty_tags(tags, YAFFS_ECC_RESULT_UNFIXED, 0);
		tags->block_bad = dev->drv.drv_check_bad_fn(dev, nand_chunk);
		return YAFFS_FAIL;
	}

	/* Check for a blank/erased chunk. */
	if (yaffs_check_ff(tag_buf, 8)) {
		/* when blank, upper layers want ecc_result to be <= NO_ERROR */
		return return_empty_tags(tags, YAFFS_ECC_RESULT_NO_ERROR,
					 YAFFS_OK);
	}

	memcpy(&pt1, tag_buf, 8);

	if (!dev->param.tags_9bytes) {
		/* Read deleted status (bit) then return it to it's non-deleted
		 * state before performing tags mini-ECC check. pt1.deleted is
		 * inverted.
		 */
		deleted = !pt1.deleted;
		pt1.deleted = 1;
	} else {
		deleted = (hweight8(tag_buf[8]) < 7) ? 1 : 0;
	}

	/* Check the packed tags mini-ECC and correct if necessary/possible. */
	retval = yaffs_check_tags_ecc((struct yaffs_tags *)&pt1);
	switch (retval) {
	case 0:
		/* no tags error, use MTD result */
		break;
	case 1:
		/* recovered tags-ECC error */
		dev->n_tags_ecc_fixed++;
		if (ecc_result == YAFFS_ECC_RESULT_NO_ERROR)
			ecc_result = YAFFS_ECC_RESULT_FIXED;
		break;
	default:
		/* unrecovered tags-ECC error */
		dev->n_tags_ecc_unfixed++;
		return return_empty_tags(tags, YAFFS_ECC_RESULT_UNFIXED,
					 YAFFS_FAIL);
	}

	/* Unpack the tags to extended form and set ECC result.
	 * [set should_be_ff just to keep yaffs_unpack_tags1 happy]
	 */
	pt1.should_be_ff = 0xffffffff;
	yaffs_unpack_tags1(tags, &pt1);
	tags->ecc_result = ecc_result;

	/* Set deleted state */
	tags->is_deleted = deleted;
	return YAFFS_OK;
}

static int yaffs_tags_compat_mark_bad(struct yaffs_dev *dev, int block_no)
{
	return dev->drv.drv_mark_bad_fn(dev, block_no);
}

static int yaffs_tags_compat_query_block(struct yaffs_dev *dev,
					 int block_no,
					 enum yaffs_block_state *state,
					 u32 *seq_number)
{
	struct yaffs_ext_tags tags;
	int retval;

	yaffs_trace(YAFFS_TRACE_MTD, "%s %d", __func__, block_no);

	*seq_number = 0;

	retval = dev->drv.drv_check_bad_fn(dev, block_no);
	if (retval == YAFFS_FAIL) {
		*state = YAFFS_BLOCK_STATE_DEAD;
		goto out;
	}

	yaffs_tags_compat_read(dev, block_no * dev->param.chunks_per_block,
			       NULL, &tags);

	if (tags.ecc_result != YAFFS_ECC_RESULT_NO_ERROR) {
		yaffs_trace(YAFFS_TRACE_MTD, "block %d is marked bad",
			    block_no);
		*state = YAFFS_BLOCK_STATE_NEEDS_SCAN;
	} else if (tags.chunk_used) {
		*seq_number = tags.seq_number;
		*state = YAFFS_BLOCK_STATE_NEEDS_SCAN;
	} else {
		*state = YAFFS_BLOCK_STATE_EMPTY;
	}

	retval = YAFFS_OK;

out:
	yaffs_trace(YAFFS_TRACE_MTD,
		    "block query returns seq %u state %d",
		    *seq_number, *state);

	return retval;
}

void yaffs_tags_compat_install(struct yaffs_dev *dev)
{
	if (dev->param.is_yaffs2)
		return;

	if (!dev->tagger.write_chunk_tags_fn)
		dev->tagger.write_chunk_tags_fn = yaffs_tags_compat_write;

	if (!dev->tagger.read_chunk_tags_fn)
		dev->tagger.read_chunk_tags_fn = yaffs_tags_compat_read;

	if (!dev->tagger.query_block_fn)
		dev->tagger.query_block_fn = yaffs_tags_compat_query_block;

	if (!dev->tagger.mark_bad_fn)
		dev->tagger.mark_bad_fn = yaffs_tags_compat_mark_bad;
}
#endif
