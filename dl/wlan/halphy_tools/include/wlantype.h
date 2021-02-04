/*
 * Copyright (c) 2013-2017 Qualcomm Technologies, Inc. All rights reserved.
 * 2013-2016 Qualcomm Atheros, Inc.
 * Qualcomm Technologies Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */
/*
 * Copyright ?2000-2002 Atheros Communications, Inc.,  All Rights Reserved.
 *
 * wlantype.h - Basic datatypes for each platform
 * $Id: //depot/sw/qca_main/components/wlan/qca-wifi-fw/1.2/drivers/host/tools/systemtools/src2/include/wlantype.h#2 $
 */

#ifndef __INCwlantypeh
#define __INCwlantypeh

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if (defined(_HOST_SIM_TESTING) && defined(Linux)) || (defined(WIN32) && !defined(T_WINNT))
#define MULTI_RATE_RETRY_ENABLE 1
#define UPSD 1

#ifdef NT_HW
#ifndef WIN32
#define WIN32
#endif

/* Bring in our include file for the NT environment */
#include "ntdefs.h"
#endif  /* NT_HW */

#ifdef NDIS_HW
#ifndef WIN32
#define WIN32
#endif

/* Bring in our include file for the NDIS environment */
#include "ndisdefs.h"
#endif  /* NDIS_HW */

/* No OS's have this define */
typedef const unsigned char     cu8;
typedef union wlanMACAddr WLAN_MACADDR;

/*
 * Following conditional compiles need to be correct. This is just a sample.
 * It also needs to be corrected for bit ordering for the CPU.
 */
#ifdef WIN32
#undef ARCH_BIG_ENDIAN

typedef char                    A_CHAR;
typedef unsigned char           A_UCHAR;
typedef A_CHAR                  A_INT8;
typedef A_UCHAR                 A_UINT8;
typedef short                   A_INT16;
typedef unsigned short          A_UINT16;
typedef long int                A_INT32;
typedef unsigned long int       A_UINT32;
typedef unsigned long int       A_UINT;

typedef unsigned char           u8;
typedef unsigned short          u16;
typedef unsigned int            u32;

typedef A_UCHAR                 A_BOOL;
typedef void *                  OS_DEVICE_ID;

typedef __int64                 A_INT64;
typedef unsigned __int64        A_UINT64;

typedef long                    A_INT_PTR;
typedef unsigned long           A_UINT_PTR;

#define A_LL                    "I64"

typedef A_UINT64                A_LONGSTATS;

typedef unsigned __int64        u64;
typedef __int64                 s64;
#endif /* WIN32 */

#ifdef VXWORKS
/* Bring in our include file for the VxWorks environment */
#include "vxdefs.h"

typedef signed char             A_CHAR;
typedef A_CHAR                  A_INT8;
typedef INT16                   A_INT16;
typedef INT32                   A_INT32;

typedef UINT8                   A_UINT8;
typedef UINT16                  A_UINT16;
typedef UINT32                  A_UINT32;

typedef UCHAR                   A_UCHAR;
typedef USHORT                  A_USHORT;
typedef UINT                    A_UINT;
typedef ULONG                   A_ULONG;

typedef BOOL                    A_BOOL;
typedef ARGINT                  A_ARGINT;

typedef long long               A_INT64;
typedef unsigned long long      A_UINT64;
#define A_LL                    "ll"

typedef A_UINT32                A_LONGSTATS;    /* compiler/libc issues */(_HOST_SIM_TESTING)

typedef unsigned long long      u64;
typedef long long               s64;
#endif /* VXWORKS */


#ifdef Linux
typedef char                    A_CHAR;
typedef A_CHAR                  A_INT8;
typedef short                   A_INT16;
typedef long                    A_INT32;

typedef unsigned char           A_UCHAR;
typedef A_UCHAR                 A_UINT8;
typedef unsigned short          A_UINT16;
typedef unsigned long           A_UINTL;     /* Use this to declare pointers, since pointers in 64 bit platform are of 8byte */
typedef unsigned int            A_UINT32;    /* Use this to declare data  */
typedef unsigned long           A_UINT;
typedef unsigned long           UINT;


typedef int                     A_BOOL;

typedef long long               A_INT64;
typedef unsigned long long      A_UINT64;
typedef unsigned long           ULONGLONG;

typedef long                    A_INT_PTR;
typedef unsigned long           A_UINT_PTR;

#define A_LL                    "ll"

typedef A_UINT64                A_LONGSTATS;

#endif /* Linux */

#if defined(__APPLE__)
#include <stdint.h>
typedef char                    A_CHAR;
typedef A_CHAR                  A_INT8;
typedef short                   A_INT16;
typedef int                     A_INT32;

typedef unsigned char           A_UCHAR;
typedef A_UCHAR                 A_UINT8;
typedef unsigned short          A_UINT16;
typedef unsigned int            A_UINT32;
typedef unsigned int            A_UINT;
typedef unsigned int            UINT;

typedef int                     A_BOOL;

/* 'long' is 32-bit in 32-bit userland, 64 bit in 64-bit userland, unlike Win64 */
typedef long long               A_INT64;
typedef unsigned long long      A_UINT64;
typedef unsigned long long      ULONGLONG;

typedef long                    A_INT_PTR;
typedef unsigned long           A_UINT_PTR;

#define A_LL                    "ll"

typedef A_UINT64                A_LONGSTATS;

#endif /* __APPLE__ */
	
#if defined(WIN32) || defined(VXWORKS) || defined(Linux) || defined(__APPLE__)
typedef A_INT8                  A_RSSI;
typedef A_INT32                 A_RSSI32;
#endif

#define RSSI_DUMMY_MARKER       0x127

/* Endianness byte swapping functions */

#define A_swab16(x) \
        ((A_UINT16)( \
                (((A_UINT16)(x) & (A_UINT16)0x00ffU) << 8) | \
                (((A_UINT16)(x) & (A_UINT16)0xff00U) >> 8) ))
#define A_swab32(x) \
        ((A_UINT32)( \
                (((A_UINT32)(x) & (A_UINT32)0x000000ffUL) << 24) | \
                (((A_UINT32)(x) & (A_UINT32)0x0000ff00UL) <<  8) | \
                (((A_UINT32)(x) & (A_UINT32)0x00ff0000UL) >>  8) | \
                (((A_UINT32)(x) & (A_UINT32)0xff000000UL) >> 24) ))
#ifdef WIN32
/* Windows chose not to implement the standard ULL constant suffix */
#define A_swab64(x) \
        ((A_UINT64)( \
                (A_UINT64)(((A_UINT64)(x) & (A_UINT64)0x00000000000000ff) << 56) | \
                (A_UINT64)(((A_UINT64)(x) & (A_UINT64)0x000000000000ff00) << 40) | \
                (A_UINT64)(((A_UINT64)(x) & (A_UINT64)0x0000000000ff0000) << 24) | \
                (A_UINT64)(((A_UINT64)(x) & (A_UINT64)0x00000000ff000000) <<  8) | \
                (A_UINT64)(((A_UINT64)(x) & (A_UINT64)0x000000ff00000000) >>  8) | \
                (A_UINT64)(((A_UINT64)(x) & (A_UINT64)0x0000ff0000000000) >> 24) | \
                (A_UINT64)(((A_UINT64)(x) & (A_UINT64)0x00ff000000000000) >> 40) | \
                (A_UINT64)(((A_UINT64)(x) & (A_UINT64)0xff00000000000000) >> 56) ))
#else /* WIN32 */
#define A_swab64(x) \
        ((A_UINT64)( \
                (A_UINT64)(((A_UINT64)(x) & (A_UINT64)0x00000000000000ffULL) << 56) | \
                (A_UINT64)(((A_UINT64)(x) & (A_UINT64)0x000000000000ff00ULL) << 40) | \
                (A_UINT64)(((A_UINT64)(x) & (A_UINT64)0x0000000000ff0000ULL) << 24) | \
                (A_UINT64)(((A_UINT64)(x) & (A_UINT64)0x00000000ff000000ULL) <<  8) | \
                (A_UINT64)(((A_UINT64)(x) & (A_UINT64)0x000000ff00000000ULL) >>  8) | \
                (A_UINT64)(((A_UINT64)(x) & (A_UINT64)0x0000ff0000000000ULL) >> 24) | \
                (A_UINT64)(((A_UINT64)(x) & (A_UINT64)0x00ff000000000000ULL) >> 40) | \
                (A_UINT64)(((A_UINT64)(x) & (A_UINT64)0xff00000000000000ULL) >> 56) ))
#endif /* WIN32 */

#ifdef ARCH_BIG_ENDIAN

#define cpu2le64(x) A_swab64((x))
#define le2cpu64(x) A_swab64((x))
#define cpu2le32(x) A_swab32((x))
#define le2cpu32(x) A_swab32((x))
#define cpu2le16(x) A_swab16((x))
#define le2cpu16(x) A_swab16((x))
#define cpu2be64(x) ((A_UINT64)(x))
#define be2cpu64(x) ((A_UINT64)(x))
#define cpu2be32(x) ((A_UINT32)(x))
#define be2cpu32(x) ((A_UINT32)(x))
#define cpu2be16(x) ((A_UINT16)(x))
#define be2cpu16(x) ((A_UINT16)(x))

#else /* Little_Endian */

#define cpu2le64(x) ((A_UINT64)(x))
#define le2cpu64(x) ((A_UINT64)(x))
#define cpu2le32(x) ((A_UINT32)(x))
#define le2cpu32(x) ((A_UINT32)(x))
#define cpu2le16(x) ((A_UINT16)(x))
#define le2cpu16(x) ((A_UINT16)(x))
#define cpu2be64(x) A_swab64((x))
#define be2cpu64(x) A_swab64((x))
#define cpu2be32(x) A_swab32((x))
#define be2cpu32(x) A_swab32((x))
#define cpu2be16(x) A_swab16((x))
#define be2cpu16(x) A_swab16((x))

#endif /* Endianness */

#ifdef __GNUC__
#define __ATTRIB_PACK           __attribute__ ((packed))
#define __ATTRIB_PRINTF         __attribute__ ((format (printf, 1, 2)))
#define __ATTRIB_NORETURN       __attribute__ ((noreturn))
#define INLINE                  __inline__
#else /* Not GCC */
#define __ATTRIB_PACK
#define __ATTRIB_PRINTF
#define __ATTRIB_NORETURN
#define INLINE                  __inline
#endif /* End __GNUC__ */

/*
 * Driver and protocol related things that will be required by
 * all apps and drivers.
 */

/* Generic error codes that can be used by hw, sta, ap, sim, dk
 * and any other environments. Since these are enums, feel free to
 * add any more codes that you need.
 */

#include "athdefs.h"

/*
 * Define some useful macros
 */

#define A_MAX(x, y)         (((x) > (y)) ? (x) : (y))
#define A_MIN(x, y)         (((x) < (y)) ? (x) : (y))
#define A_ABS(x)            (((x) >= 0) ? (x) : (-(x)))
#define A_LPF_RSSI(x, y, len) ((x != RSSI_DUMMY_MARKER) ? (((x) * ((len) - 1) + (y)) / (len)) : (y))
#define A_LPF_RATE(x, y, len) ((x) ? (((x) * ((len) - 1) + (y)) / (len)) : (y))
#define A_ROUNDUP(x, y)     ((((x) + ((y) - 1)) / (y)) * (y))
#define A_ROUNDUP_PAD(x, y) (A_ROUNDUP(x, y) - (x))
#define MAKE_BOOL(x)        ((x) ? TRUE : FALSE)
#define A_TOLOWER(c)        (((c) >= 'A' && (c) <= 'Z') ? ((c)-'A'+'a') : (c))
#define A_TOUPPER(c)        (((c) >= 'a' && (c) <= 'z') ? ((c)-'a'+'A') : (c))
#define TU_TO_MS(x)         ((x) * 1024 / 1000)
#define TU_TO_US(x)         ((x) << 10)
#define MS_TO_TU(x)         ((x) * 1000 / 1024)
#define KHZ_TO_MHZ(x)       ((x) / 1000)
#define MHZ_TO_KHZ(x)       ((x) * 1000)

#ifdef DEBUG
#define A_UNUSED_VAR(x)
#else
#define A_UNUSED_VAR(x)     (x)=(x)
#endif

/*
 * The following macros are used for manipulating extended-precision values.
 * A_EP_RND returns the value rounded to normal precision, and A_EP_MUL
 * is used to multiply up from normal to extended precision.
 */
#define A_EP_RND(x, mul)   ((((x)%(mul)) >= ((mul)/2)) ? ((x) + ((mul) - 1)) / (mul) : (x)/(mul))
#define A_EP_MUL(x, mul)   ((x) * (mul))
/*
 * The following macros define the number of bits and masks
 */
#define NUM_BITS_NBL 4
#define NUM_BITS_BYTE 8
#define NBL_MASK   0x0f
/*
 * Enumerated types
 */
typedef enum {
    DISCONNECT_NOW,
    DISCONNECT_DELAYED
} DISCONNECT_ENUM;

typedef enum {
    REMOVE_BSS,
    DONT_REMOVE_BSS
} REMOVE_BSS_ENUM;

typedef enum {
    SEND_DEAUTH,
    DONT_SEND_DEAUTH
} SEND_DEAUTH_ENUM;

typedef enum {
    RESET_INC_CTR,
    RESET_DONT_INC_CTR
} RESET_CTR_ENUM;

typedef enum {
    DO_WAIT,
    DONT_WAIT
} DRAIN_ENUM;

typedef enum {
    DO_COMPLETE,
    DONT_COMPLETE
} COMPLETION_ENUM;

typedef enum {
    DO_CLEAR_TX_Q,
    DONT_CLEAR_TX_Q
} CLEAR_TX_Q_ENUM;

typedef enum {
    ANTENNA_CONTROLLABLE,
    ANTENNA_FIXED_A,
    ANTENNA_FIXED_B,
    ANTENNA_DUMMY_MAX
} ANTENNA_CONTROL;

typedef enum {
    ATH_DEV_TYPE_UNDEFINED,
    ATH_DEV_TYPE_CARDBUS,
    ATH_DEV_TYPE_PCI,
    ATH_DEV_TYPE_MINIPCI,
    ATH_DEV_TYPE_AP,
    ATH_DEV_TYPE_MAX
} ATH_DEV_TYPE;

#define ARRAY_NUM_ENTRIES(a) (sizeof(a)/sizeof(*(a)))

#ifdef MDK_BUILD
#include "commoninit_defs.h"
#endif

#else
#include "athdefs.h"
#endif //HOST_SIM_TESTING

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCwlantypeh */
