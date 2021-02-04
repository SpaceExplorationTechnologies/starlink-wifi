#ifndef __ASM_ARM_STRING_H
#define __ASM_ARM_STRING_H

/*
 * We don't do inline string functions, since the
 * optimised inline asm versions are not small.
 */

#define __HAVE_ARCH_STRRCHR
extern char * strrchr(const char * s, int c);

#define __HAVE_ARCH_STRCHR
extern char * strchr(const char * s, int c);

#define __HAVE_ARCH_MEMCPY
extern void * memcpy(void *, const void *, __kernel_size_t);
extern void * __memcpy(void *, const void *, __kernel_size_t);

#define __HAVE_ARCH_MEMMOVE
extern void * memmove(void *, const void *, __kernel_size_t);
extern void * __memmove(void *, const void *, __kernel_size_t);

#define __HAVE_ARCH_MEMCHR
extern void * memchr(const void *, int, __kernel_size_t);

#define __HAVE_ARCH_MEMSET
extern void * memset(void *, int, __kernel_size_t);
extern void * __memset(void *, int, __kernel_size_t);

extern void __memzero(void *ptr, __kernel_size_t n);

#ifndef CONFIG_KASAN
#define memset(p,v,n)							\
	({								\
	 	void *__p = (p); size_t __n = n;			\
		if ((__n) != 0) {					\
			if (__builtin_constant_p((v)) && (v) == 0)	\
				__memzero((__p),(__n));			\
			else						\
				memset((__p),(v),(__n));		\
		}							\
		(__p);							\
	})
#endif
#if defined(CONFIG_KASAN) && !defined(__SANITIZE_ADDRESS__)

/*
 * For files that not instrumented (e.g. mm/slub.c) we
 * should use not instrumented version of mem* functions.
 */

#define memcpy(dst, src, len) __memcpy(dst, src, len)
#define memmove(dst, src, len) __memmove(dst, src, len)
#define memset(s, c, n) __memset(s, c, n)
#endif


#endif
