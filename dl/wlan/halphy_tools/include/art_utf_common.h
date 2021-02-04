/*
 * Copyright (c) 2011 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */
#ifndef  _ART_UTF_COMMON_H_
#define  _ART_UTF_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#ifdef __GNUC__
#define __ATTRIB_PACK           __attribute__ ((packed))
#define __ATTRIB_PRINTF         __attribute__ ((format (printf, 1, 2)))
#define __ATTRIB_NORETURN       __attribute__ ((noreturn))
#define __ATTRIB_ALIGN(x)       __attribute__ ((aligned((x))))
#ifndef INLINE
#define INLINE                  __inline__
#endif
#else /* Not GCC */

#define __ATTRIB_PRINTF
#define __ATTRIB_NORETURN
#define __ATTRIB_ALIGN(x)
#ifndef INLINE
#define INLINE                  __inline
#endif
#endif /* End __GNUC__ */

#ifndef ATHR_WIN_DEF /* Not GCC */
#ifndef __GNUC__
#define __ATTRIB_PACK
#endif
#endif

#ifndef ATHR_WIN_DEF /* Not GCC */
#define PREPACK
#define POSTPACK				__ATTRIB_PACK
#endif

#define MPATTERN                (10*4)
#define ATH_MAC_LEN             6
#define RATE_MASK_ROW_MAX       9
#define RATE_POWER_MAX_INDEX    8
#define RATE_MASK_BIT_MAX       32

#ifdef AR6002_REV2
#define TCMD_MAX_RATES 12
#else
//#define TCMD_MAX_RATES 183 /* 150 + 3 CCK short preamble */
//Add this for 4x4 changes..
#define TCMD_MAX_RATES 219 /* 150 + 3 CCK short preamble */
//#define TCMD_MAX_RATES 47 /* 44 + 3 CCK short preamble */
#endif

#define PSAT_WHAL_NUM_11G_CAL_PIERS_MAX 3
#define PSAT_WHAL_NUM_11A_CAL_PIERS_MAX 8

typedef enum {
    ZEROES_PATTERN = 0,
    ONES_PATTERN,
    REPEATING_10,
    PN7_PATTERN,
    PN9_PATTERN,
    PN15_PATTERN,
    USER_DEFINED_PATTERN
}TX_DATA_PATTERN;

typedef enum {
    TCMD_CONT_TX_OFF = 0,
    TCMD_CONT_TX_SINE,
    TCMD_CONT_TX_FRAME,
    TCMD_CONT_TX_TX99,
    TCMD_CONT_TX_TX100, 
    TCMD_CONT_TX_OFFSETTONE,
    TCMD_CONT_TX_PSAT_CAL,
    TCMD_CONT_TX_CWTONE,
    TCMD_CONT_TX_CLPCPKT,
} TCMD_CONT_TX_MODE;

typedef enum {
    TCMD_CONT_RX_OFF = 0,
    TCMD_CONT_RX_ON,
    TCMD_CONT_RX_TX_ON,
} TCMD_CONT_RX_MODE;

typedef enum {
    TCMD_WLAN_MODE_NOHT = 0,
    TCMD_WLAN_MODE_HT20 = 1,
    TCMD_WLAN_MODE_HT40PLUS = 2,
    TCMD_WLAN_MODE_HT40MINUS = 3,
    TCMD_WLAN_MODE_CCK = 4,

    TCMD_WLAN_MODE_VHT20 = 5,
    TCMD_WLAN_MODE_VHT40PLUS = 6,
    TCMD_WLAN_MODE_VHT40MINUS = 7,
    TCMD_WLAN_MODE_VHT80_0 = 8,
    TCMD_WLAN_MODE_VHT80_1 = 9,
    TCMD_WLAN_MODE_VHT80_2 = 10,
    TCMD_WLAN_MODE_VHT80_3 = 11,

    TCMD_WLAN_MODE_VHT80P80 = 12,
    TCMD_WLAN_MODE_VHT160 = 13,

    TCMD_WLAN_MODE_VHT80P80_0 = 21,  
    TCMD_WLAN_MODE_VHT80P80_1 = 22,
    TCMD_WLAN_MODE_VHT80P80_2 = 23,
    TCMD_WLAN_MODE_VHT80P80_3 = 24,
    TCMD_WLAN_MODE_VHT80P80_4 = 25,
    TCMD_WLAN_MODE_VHT80P80_5 = 26,
    TCMD_WLAN_MODE_VHT80P80_6 = 27,
    TCMD_WLAN_MODE_VHT80P80_7 = 28,

    TCMD_WLAN_MODE_VHT160_0 = 29,
    TCMD_WLAN_MODE_VHT160_1 = 30,
    TCMD_WLAN_MODE_VHT160_2 = 31,
    TCMD_WLAN_MODE_VHT160_3 = 32,
    TCMD_WLAN_MODE_VHT160_4 = 33,
    TCMD_WLAN_MODE_VHT160_5 = 34,
    TCMD_WLAN_MODE_VHT160_6 = 35,
    TCMD_WLAN_MODE_VHT160_7 = 36,

    TCMD_WLAN_MODE_MAX,
    TCMD_WLAN_MODE_INVALID = TCMD_WLAN_MODE_MAX,

} TCMD_WLAN_MODE;

typedef enum {
    TCMD_CONT_RX_PROMIS =0,
    TCMD_CONT_RX_FILTER,
    TCMD_CONT_RX_REPORT,
    TCMD_CONT_RX_SETMAC,
    TCMD_CONT_RX_SET_ANT_SWITCH_TABLE,
 
    TC_CMD_RESP,
} TCMD_CONT_RX_ACT;

//
// TX/RX status defines and structures
//
#define MSTREAM_UTF 4
#define MCHAIN_UTF 4
#define MAX_PILOT_UTF 16

#define CONFIG_ADDR_ADDRESS_MASK    0x000FFFFF
#define CONFIG_ADDR_ADDRESS_SHIFT   0
#define CONFIG_ADDR_MODE_MASK       0x00300000
#define CONFIG_ADDR_MODE_SHIFT      20
#define CONFIG_ADDR_NUMVALUES_MASK  0x00c00000
#define CONFIG_ADDR_NUMVALUES_SHIFT 22
#define CONFIG_ADDR_CTRL_MASK       0xff000000
#define CONFIG_ADDR_PREPOST_MASK    0x01000000
#define CONFIG_ADDR_CTRL_SHIFT      24

#define CONFIG_ADDR_FLAG_MASK		0x01000000  // sticky write flag, specify sticky write before/after h/w cal in M_STICKY_WRITE_CMD_ID
#define CONFIG_ADDR_FLAG_SHIFT		24

typedef struct txStats_utf 
{
	A_UINT32 totalPackets;
	A_UINT32 goodPackets;
	A_UINT32 underruns;
	A_UINT32 otherError;
	A_UINT32 excessiveRetries;
    A_UINT32 rateBit;
	//
	// retry histogram
	//
	A_INT32 shortRetry;
	A_INT32 longRetry;

	A_UINT32 startTime;
	A_UINT32 endTime;
	A_UINT32 byteCount;
	A_UINT32 dontCount;
	//
	// rssi histogram for good packets
	//
	A_INT32 rssi;
	A_INT32 rssic[MCHAIN_UTF];
	A_INT32 rssie[MCHAIN_UTF];

	A_UINT32 thermCal;/* thermal value for calibration */
        A_UINT32 pdadc;
        A_UINT32 paCfg;
        A_INT32  gainIdx;
        A_INT32  dacGain;
} __ATTRIB_PACK TX_STATS_STRUCT_UTF;


typedef struct rxStats_uft 
{
	A_UINT32 totalPackets;
	A_UINT32 goodPackets;
	A_UINT32 otherError;
	A_UINT32 crcPackets;
    A_UINT32 decrypErrors;
    A_UINT32 rateBit;

	// Added for RX tput calculation
	A_UINT32 startTime;
	A_UINT32 endTime;
	A_UINT32 byteCount;
	A_UINT32 dontCount;
	//
	// rssi histogram for good packets
	//
	A_INT32 rssi;
	A_INT32 rssic[MCHAIN_UTF];
	A_INT32 rssie[MCHAIN_UTF];
	//
	// evm histogram for good packets
	//
	A_INT32 evm[MSTREAM_UTF];
	//
	// rssi histogram for bad packets
	//
	A_INT32 badrssi;
	A_INT32 badrssic[MCHAIN_UTF];
	A_INT32 badrssie[MCHAIN_UTF];
	//
	// evm histogram for bad packets
	//
	A_INT32 badevm[MSTREAM_UTF];
	//
	// NF values
	//	
    A_INT32 noisefloor[MSTREAM_UTF];
	A_INT32 pilotevm[MSTREAM_UTF][MAX_PILOT_UTF];
	//
	// DMA error packets
	//
    A_UINT32 bitErrorCompares;

} __ATTRIB_PACK RX_STATS_STRUCT_UTF;
	
#if defined(AR6002_REV6)
#include "art_utf_ar6004.h"
#elif defined(AR6002_REV7)
#include "art_utf_ar6006.h"
#elif defined(QC98XXDLL) || defined (AR9888) ||  defined(AR6320)
#include "art_utf_qc98xx.h"
#elif defined(AR900B) || defined(QCA9984) || defined(IPQ4019) || defined(QCA9888)
#include "art_utf_qc900b.h"
#endif


#ifdef __cplusplus
}
#endif

#endif //_ART_UTF_TX_COMMON_H_



