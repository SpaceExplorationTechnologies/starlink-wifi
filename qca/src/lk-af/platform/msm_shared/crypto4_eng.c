/* Copyright (c) 2012,2014 The Linux Foundation. All rights reserved.

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of The Linux Foundation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <string.h>
#include <endian.h>
#include <debug.h>
#include <stdlib.h>
#include <reg.h>
#include <bits.h>
#include <platform/iomap.h>
#include <crypto4_eng.h>
#include <crypto_hash.h>
#include <scm.h>
#include <smem.h>
#include <board.h>

#if CRYPTO_BAM_SUPPORT
#include <bam.h>
#define CE1_BAM_BASE		0x18510000
#define CE_FIFO_SIZE		512
#define CE_READ_PIPE		1
#define CE_WRITE_PIPE		0
#define CE_READ_PIPE_LOCK_GRP	0
#define CE_WRITE_PIPE_LOCK_GRP	0
#define CE_ARRAY_SIZE		20
#define CRYPTO_READ_PIPE_INDEX	1
#define CRYPTO_WRITE_PIPE_INDEX	0
#define CRYPTO_MAX_THRESHOLD	(32 * 1024)
#define ADD_WRITE_DESC(bam, buf_addr, buf_size, flags) \
	bam_add_desc(bam, CRYPTO_WRITE_PIPE_INDEX, buf_addr, buf_size, flags)
static struct bam_instance bam;
#endif

extern void dsb(void);
extern void ce_async_reset();

void wr_ce(uint32_t val,uint32_t reg)
{
    uint32_t platform_id;

	platform_id = board_platform_id();

	if((platform_id == APQ8064) || (platform_id == APQ8064AA)
		|| (platform_id == APQ8064AB)|| (platform_id == APQ8064AU) )
		writel(val,CRYPTO_ENG_REG(CE3_CRYPTO4_BASE, reg));
	else
		writel(val,CRYPTO_ENG_REG(CE1_CRYPTO4_BASE, reg));
}
uint32_t rd_ce(uint32_t reg)
{

	uint32_t val;
    uint32_t platform_id;

	platform_id = board_platform_id();

	if((platform_id == APQ8064) || (platform_id == APQ8064AA)
		|| (platform_id == APQ8064AB) || (platform_id == APQ8064AU) )
		val = readl(CRYPTO_ENG_REG(CE3_CRYPTO4_BASE, reg));
	else
		val = readl(CRYPTO_ENG_REG(CE1_CRYPTO4_BASE, reg));

	return val;
}

/*
 * Function to reset the crypto engine.
 */

void crypto_eng_reset(void)
{
	ce_async_reset();
	return;
}


/* Function to switch the CE1 context
 * from register to ADM
 */
void crypto_eng_cleanup(void)
{

    unsigned int val;

    enum ap_ce_channel_type chn = AP_CE_ADM_USE;
    /* Make a SMC call to TZ to make CE1 use ADM interface for HLOS*/
    val = switch_ce_chn_cmd(chn);
    dprintf(INFO, "TZ channel swith returned %d\n", val);

}

#if CRYPTO_BAM_SUPPORT
static struct bam_desc *crypto_allocate_fifo(uint32_t size)
{
	struct bam_desc *ptr;

	ptr = (struct bam_desc *) memalign(lcm(CACHE_LINE, BAM_DESC_SIZE),
					   ROUNDUP(size * BAM_DESC_SIZE, CACHE_LINE));

	if (ptr == NULL)
		dprintf(CRITICAL, "Could not allocate fifo buffer\n");

	return ptr;
}

static int crypto4_bam_init(void)
{

	uint32_t bam_ret ;

	bam.base = CE1_BAM_BASE;
	/* Read pipe parameter initializations. */
	bam.pipe[CRYPTO_READ_PIPE_INDEX].pipe_num = CE_READ_PIPE;
	/* System consumer */
	bam.pipe[CRYPTO_READ_PIPE_INDEX].trans_type = BAM2SYS;
	/* Set the descriptor FIFO start ptr */
	bam.pipe[CRYPTO_READ_PIPE_INDEX].fifo.head =
		crypto_allocate_fifo(CE_FIFO_SIZE);
	/* Set the descriptor FIFO lengths */
	bam.pipe[CRYPTO_READ_PIPE_INDEX].fifo.size = CE_FIFO_SIZE;

	/* Write pipe parameter initializations.*/
	bam.pipe[CRYPTO_WRITE_PIPE_INDEX].pipe_num = CE_WRITE_PIPE;
	/* System producer */
	bam.pipe[CRYPTO_WRITE_PIPE_INDEX].trans_type = SYS2BAM;
	/* Write fifo uses the same fifo as read */
	bam.pipe[CRYPTO_WRITE_PIPE_INDEX].fifo.head =
		crypto_allocate_fifo(CE_FIFO_SIZE);
	/* Set the descriptor FIFO lengths */
	bam.pipe[CRYPTO_WRITE_PIPE_INDEX].fifo.size = CE_FIFO_SIZE;

	/* Programs the minimum threshold for BAM transfer*/
	bam.threshold = CRYPTO_MAX_THRESHOLD;

	/* Align descriptor size to 512 bytes, BAM needs each buffer
	 * address to be aligned with 512 bytes. The desc_len field has 16 bits,
	 * 0xFE00 alignes the buffers to 512 bytes, same time uses the maximum
	 * possible buffer size in each descriptor.
	 */
        bam.max_desc_len = 0xFE00;

        bam.ee = 0;
	/* Initialize MMC BAM */
	bam_init(&bam);

	/* Initialize BAM MMC read pipe */
	bam_sys_pipe_init(&bam, CRYPTO_READ_PIPE_INDEX);

	bam_ret = bam_pipe_fifo_init(&bam, CRYPTO_READ_PIPE_INDEX);

	if (bam_ret)
	{
		dprintf(CRITICAL, "CRYPTO: BAM Read pipe fifo init error\n");
		goto ce_bam_init_error;
	}

	/* Initialize BAM MMC write pipe */
	bam_sys_pipe_init(&bam, CRYPTO_WRITE_PIPE_INDEX);

	bam_ret = bam_pipe_fifo_init(&bam, CRYPTO_WRITE_PIPE_INDEX);

	if (bam_ret)
	{
		dprintf(CRITICAL, "CRYPTO: BAM Write pipe fifo init error\n");
		goto ce_bam_init_error;
	}

	bam_ret = CRYPTO_ERR_NONE;

ce_bam_init_error:

	return bam_ret;
}

static void crypto_wait_for_data(struct bam_instance *bam, uint32_t pipe_num)
{
	/* Read offset update for the circular FIFO */
	bam_read_offset_update(bam, pipe_num);
}

#endif

/*
 * Function to initialize the crypto engine for a new session. It enables the
 * auto shutdown feature of CRYPTO and mask various interrupts since we use
 * polling. We are not using DMOV now.
 */

void crypto_eng_init(void)
{

	unsigned int val;

	enum ap_ce_channel_type chn = AP_CE_REGISTER_USE;
#if CRYPTO_BAM_SUPPORT
	/* Setup BAM */
	if (crypto4_bam_init() != CRYPTO_ERR_NONE)
	{
		dprintf(CRITICAL, "CRYPTO: BAM init error\n");
		return;
	}
	/* Write basic config to CE.
	 *  Note: This setting will be changed to be set from TZ.
	 */
	chn = AP_CE_BAM_USE;
#endif
	/* Make a SMC call to TZ to make CE1 use register interface for HLOS*/
	val = switch_ce_chn_cmd(chn);
	dprintf(INFO, "TZ channel swith returned %d\n", val);
	return;
}

/*
 * Function to set various SHAx registers in CRYPTO based on algorithm type.
 */

void
crypto_set_sha_ctx(void *ctx_ptr, unsigned int bytes_to_write,
		   crypto_auth_alg_type auth_alg, bool first, bool last)
{
	crypto_SHA1_ctx *sha1_ctx = (crypto_SHA1_ctx *) ctx_ptr;
	crypto_SHA256_ctx *sha256_ctx = (crypto_SHA256_ctx *) ctx_ptr;
	unsigned int i = 0;
	unsigned int iv_len = 0;
	unsigned int *auth_iv;
	unsigned int seg_cfg_val;
	unsigned int total_bytes_to_write;

	seg_cfg_val = SEG_CFG_AUTH_ALG_SHA;

	if (auth_alg == CRYPTO_AUTH_ALG_SHA1) {
		seg_cfg_val |= SEG_CFG_AUTH_SIZE_SHA1;

		if (last) {
			seg_cfg_val |= SEG_CFG_LAST;
		}

		iv_len = SHA1_INIT_VECTOR_SIZE;
		auth_iv = sha1_ctx->auth_iv;
	} else if (auth_alg == CRYPTO_AUTH_ALG_SHA256) {
		seg_cfg_val |= SEG_CFG_AUTH_SIZE_SHA256;

		if (last) {
			seg_cfg_val |= SEG_CFG_LAST;
		}

		iv_len = SHA256_INIT_VECTOR_SIZE;
		auth_iv = sha256_ctx->auth_iv;
	} else {
		dprintf(CRITICAL,
			"crypto_set_sha_ctx invalid auth algorithm\n");
		return;
	}

	for (i = 0; i < iv_len; i++) {
#if CRYPTO_BAM_SUPPORT
		wr_ce(htonl(*(auth_iv + i)), CRYPTO_AUTH_IVn(i));
#else
		wr_ce(*(auth_iv + i), CRYPTO_AUTH_IVn(i));
#endif
	}

	total_bytes_to_write = (bytes_to_write + (CRYPTO_BURST_LEN - 1))
				& (~(CRYPTO_BURST_LEN - 1));
	wr_ce(seg_cfg_val, CRYPTO_AUTH_SEG_CFG);

	/* Typecast with crypto_SHA1_ctx because offset of auth_bytecnt in both
	   crypto_SHA1_ctx and crypto_SHA256_ctx are same */

	wr_ce(((crypto_SHA1_ctx *) ctx_ptr)->auth_bytecnt[0],
	      CRYPTO_AUTH_BYTECNTn(0));
	wr_ce(((crypto_SHA1_ctx *) ctx_ptr)->auth_bytecnt[1],
	      CRYPTO_AUTH_BYTECNTn(1));

	wr_ce(bytes_to_write, CRYPTO_AUTH_SEG_SIZE);

	wr_ce(total_bytes_to_write, CRYPTO_SEG_SIZE);

#ifndef CRYPTO_BAM_SUPPORT
	/*
	 * Ensure previous instructions (any writes to config registers)
	 * are completed.
	 *
	 * TODO: Revisit dsb.
	 */
	dsb();

	wr_ce(GOPROC_GO, CRYPTO_GOPROC);
#endif

	return;
}

/*
 * Function to send data to CRYPTO. This is non-DMOV implementation and uses
 * polling to send the requested amount of data.
 */

void
crypto_send_data(void *ctx_ptr, unsigned char *data_ptr,
		 unsigned int buff_size, unsigned int bytes_to_write,
		 unsigned int *ret_status)
{
#ifndef CRYPTO_BAM_SUPPORT
	crypto_SHA1_ctx *sha1_ctx = (crypto_SHA1_ctx *) ctx_ptr;
	unsigned int bytes_left = 0;
	unsigned int i = 0;
	unsigned int ce_status = 0;
	unsigned int ce_err_bmsk = 0;
	unsigned int is_not_aligned = FALSE;
	unsigned char data[4];
	unsigned char *buff_ptr = data_ptr;

	/* Check if the buff_ptr is aligned */
	if (!(IS_ALIGNED(buff_ptr))) {
		is_not_aligned = TRUE;
	}

	/* Fill the saved_buff with data from buff_ptr. First we have to write
	   all the data from the saved_buff and then we will write data from
	   buff_ptr. We will update bytes_left and buff_ptr in the while loop
	   once are done writing all the data from saved_buff. */

	if (sha1_ctx->saved_buff_indx != 0) {
		memcpy(sha1_ctx->saved_buff + sha1_ctx->saved_buff_indx,
		       buff_ptr,
		       (((buff_size + sha1_ctx->saved_buff_indx) <=
			 CRYPTO_SHA_BLOCK_SIZE)
			? buff_size : ((unsigned)CRYPTO_SHA_BLOCK_SIZE -
				       sha1_ctx->saved_buff_indx)));

		if (bytes_to_write >= CRYPTO_SHA_BLOCK_SIZE) {
			bytes_left = CRYPTO_SHA_BLOCK_SIZE;
		} else {
			bytes_left = bytes_to_write;
		}
	} else {
		bytes_left = bytes_to_write;
	}

	/* Error bitmask to check crypto engine status */
	ce_err_bmsk = (SW_ERR | DIN_RDY | DIN_SIZE_AVAIL);

	while (bytes_left >= 4) {
		ce_status = rd_ce(CRYPTO_STATUS);
		ce_status &= ce_err_bmsk;

		if (ce_status & SW_ERR) {
			/* If there is SW_ERR, reset the engine */
			crypto_eng_reset();
			*ret_status = CRYPTO_ERR_FAIL;
			dprintf(CRITICAL, "crypto_send_data sw error\n");
			return;
		}

		/* We can write data now - 4 bytes at a time in network byte order */
		if ((ce_status & DIN_RDY)
		    && ((ce_status & DIN_SIZE_AVAIL) >= 4)) {
			if (sha1_ctx->saved_buff_indx != 0) {
				/* Write from saved_buff */
				wr_ce(htonl
				      (*
				       ((unsigned int *)(sha1_ctx->saved_buff) +
					i)), CRYPTO_DATA_IN);
			} else {
				if (!is_not_aligned) {
					/* Write from buff_ptr aligned */
					wr_ce(htonl
					      (*((unsigned int *)buff_ptr + i)),
					      CRYPTO_DATA_IN);
				} else {
					/* If buff_ptr is not aligned write byte by byte */
					data[0] = *(buff_ptr + i);
					data[1] = *(buff_ptr + i + 1);
					data[2] = *(buff_ptr + i + 2);
					data[3] = *(buff_ptr + i + 3);
					/* i will incremented by 1 in outside block */
					i += 3;
					wr_ce(htonl(*data),
					      CRYPTO_DATA_IN);
					memset(data, 0, 4);
				}
			}
			i++;
			bytes_left -= 4;

			/* Check if we have written from saved_buff. Adjust buff_ptr and
			   bytes_left accordingly */
			if ((sha1_ctx->saved_buff_indx != 0)
			    && (bytes_left == 0)
			    && (bytes_to_write > CRYPTO_SHA_BLOCK_SIZE)) {
				bytes_left =
				    (bytes_to_write - CRYPTO_SHA_BLOCK_SIZE);
				buff_ptr =
				    (unsigned char *)((unsigned char *)data_ptr
						      + CRYPTO_SHA_BLOCK_SIZE -
						      sha1_ctx->
						      saved_buff_indx);
				i = 0;
				sha1_ctx->saved_buff_indx = 0;
				if (!(IS_ALIGNED(buff_ptr))) {
					is_not_aligned = TRUE;
				}
			}
		}
	}

	/* We might have bytes_left < 4. Write them now if available */
	if (bytes_left) {
		memset(data, 0, sizeof(unsigned int));

		if (sha1_ctx->saved_buff_indx)
			buff_ptr = (sha1_ctx->saved_buff + bytes_to_write - 1);
		else
			buff_ptr =
			    (((unsigned char *)data_ptr) + buff_size - 1);

		for (i = 0; i < bytes_left; i++) {
			data[3 - i] = *(buff_ptr - bytes_left + i + 1);
		}

		ce_status = rd_ce(CRYPTO_STATUS);
		ce_status &= ce_err_bmsk;

		if (ce_status & SW_ERR) {
			crypto_eng_reset();
			*ret_status = CRYPTO_ERR_FAIL;
			dprintf(CRITICAL, "crypto_send_data sw error 2\n");
			return;
		}
		if ((ce_status & DIN_RDY)
		    && ((ce_status & DIN_SIZE_AVAIL) >= 4)) {
			wr_ce(*data, CRYPTO_DATA_IN);
		}
	}
	*ret_status = CRYPTO_ERR_NONE;
#else
	unsigned int bam_status;
	unsigned int total_bytes_to_write;
	total_bytes_to_write = (bytes_to_write + (CRYPTO_BURST_LEN - 1))
				& (~((CRYPTO_BURST_LEN - 1)));
	arch_clean_invalidate_cache_range((addr_t) data_ptr, bytes_to_write);
	bam_status = ADD_WRITE_DESC(&bam, data_ptr, total_bytes_to_write,
					BAM_DESC_NWD_FLAG | BAM_DESC_INT_FLAG
					| BAM_DESC_EOT_FLAG);
	if (bam_status)
	{
		dprintf(CRITICAL, "Crypto send data failed\n");
		*ret_status = CRYPTO_ERR_FAIL;
		goto CRYPTO_SEND_DATA_ERR;
	}
	dprintf(SPEW, "start CE engine\n");
	wr_ce(GOPROC_GO, CRYPTO_GOPROC);
	crypto_wait_for_data(&bam, CRYPTO_WRITE_PIPE_INDEX);
	*ret_status = CRYPTO_ERR_NONE;
CRYPTO_SEND_DATA_ERR:
#endif
	return;
}

/*
 * Function to get digest from CRYPTO. We poll for AUTH_DONE from CRYPTO.
 */

void
crypto_get_digest(unsigned char *digest_ptr, unsigned int *ret_status,
		  crypto_auth_alg_type auth_alg, bool last)
{
	unsigned int ce_status = 0;
	unsigned int ce_err_bmsk = 0;
	unsigned int i = 0;
	unsigned int digest_len = 0;

	ce_err_bmsk = (OPERATION_DONE | SW_ERR);

	do {
		ce_status = rd_ce(CRYPTO_STATUS);
		ce_status &= ce_err_bmsk;
	}
	while (ce_status == 0);

	if (ce_status & SW_ERR) {
		crypto_eng_reset();
		*ret_status = CRYPTO_ERR_FAIL;
		dprintf(CRITICAL, "crypto_get_digest sw error\n");
		return;
	}

	/* Digest length depends on auth_alg */

	if (auth_alg == CRYPTO_AUTH_ALG_SHA1) {
		digest_len = SHA1_INIT_VECTOR_SIZE;
	} else if (auth_alg == CRYPTO_AUTH_ALG_SHA256) {
		digest_len = SHA256_INIT_VECTOR_SIZE;
	}

	/* Retrieve digest from CRYPTO */

	for (i = 0; i < digest_len; i++) {
		unsigned int auth_iv = rd_ce(CRYPTO_AUTH_IVn(i));

		if (last) {
			*((unsigned int *)digest_ptr + i) = (auth_iv);
		} else {
			*((unsigned int *)digest_ptr + i) = htonl(auth_iv);
		}
	}
	*ret_status = CRYPTO_ERR_NONE;
	return;
}

/* Function to restore auth_bytecnt registers for ctx_ptr */

void crypto_get_ctx(void *ctx_ptr)
{
	((crypto_SHA1_ctx *) ctx_ptr)->auth_bytecnt[0] =
	    rd_ce(CRYPTO_AUTH_BYTECNTn(0));
	((crypto_SHA1_ctx *) ctx_ptr)->auth_bytecnt[1] =
	    rd_ce(CRYPTO_AUTH_BYTECNTn(1));
	return;
}

uint32_t crypto_get_max_auth_blk_size(void)
{
	return CRYPTO_MAX_AUTH_BLOCK_SIZE;
}
