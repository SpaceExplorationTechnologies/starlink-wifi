#ifndef _RLE_H_
#define _RLE_H_

#ifdef CONFIG_RLE_DECOMPRESS
int rle_decode(const unsigned char *src, size_t srclen,
	       unsigned char *dst, size_t dstlen,
	       size_t *src_done, size_t *dst_done);
#else
static inline int
rle_decode(const unsigned char *src, size_t srclen,
	   unsigned char *dst, size_t dstlen,
	   size_t *src_done, size_t *dst_done)
{
	return -ENOTSUPP;
}
#endif /* CONFIG_RLE_DECOMPRESS */

#endif /* _RLE_H_ */
