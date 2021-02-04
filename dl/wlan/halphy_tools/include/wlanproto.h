/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/*
 *  Copyright ?2000-2002 Atheros Communications, Inc.,  All Rights Reserved.
 *  $ATH_LICENSE_TARGET_C$
 *
 * wlanproto.h - Data structures for 802.11 protocol
 *
 */

#ifndef __INCwlanprotoh
#define __INCwlanprotoh

/*
 * This file has the declarations specific to the 802.11 protocol.
 * It has all the fields and frames (that we will use) and also
 * mnemonic defines for constants. Although the MLME/PLME is part
 * of the protocol too, we have kept it in a separate file for
 * convenience.
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "wlantype.h"

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif

/* PHY related definitions */

/* Predefined PHY types from dot11PHYType field of 802.11 MIB specification */
typedef enum phyType {
    PHY_FHSS = 1,     // Frequency hopping
    PHY_DSSS,         // Direct Sequence Spread Spectrum (original 1, 2 Mbps)
    PHY_IR,           // Infra Red Baseband
    PHY_OFDM,         // OFDM
    PHY_HRDSSS,       // High Rate DSSS, 11b with extensions for 5.5 and 11 Mbps
    PHY_CCK = PHY_HRDSSS, // 11b is commonly called CCK in our code
    PHY_ERP
} PHY_TYPE;

/* MAC related definitions */
/* MAC Address prefix allocated for Atheros devices */
#define Atheros_MACADDR0        0x00
#define Atheros_MACADDR1        0x03
#define Atheros_MACADDR2        0x7f
#define Atheros_MACADDR3        0x00
#define Atheros_MACADDR4        0x00
#define Atheros_MACADDR5        0x00

/* List of Element IDs */
#define ELE_SSID                0       /* SSID */
#define ELE_SUPPORTED_RATES     1       /* Supported Rates */
#define ELE_FH_PARAM_SET        2       /* FH Parameter set */
#define ELE_DS_PARAM_SET        3       /* DS Parameter set */
#define ELE_CF_PARAM_SET        4       /* CF Parameter set */
#define ELE_TIM                 5       /* TIM vector */
#define ELE_IBSS_PARAM_SET      6       /* IBSS parameter set */
#define ELE_COUNTRY_INFO        7       /* Country Information */
#define ELE_CHLG_TEXT           16      /* Challenge text */
         /* 17-31 reserved for challenge txt extension */
#define ELE_NONERP              42      /* NOERP indication, 11g Spec Draft 5 */
#define ELE_EXT_SUPPORTED_RATES 50      /* Extended Supported Rates, 11g D6.1 */
#define ELE_NPLUSI              51      /* N + I demo element */
#define ELE_TPC                 150     /* Transmit Power Control */
#define ELE_CCKM                156     /* CCKM Request and Response elements */
#define ELE_WPA                 221     /* WiFi Protected Access element */
#define ELE_VENDOR_PRIVATE      221     /* Vendor private space; must demux OUI */

/* Max sizes of variable size information elements */
#define ELE_INFO_SIZE           255     /* Max possible size for any element */
#define ELE_SSID_SIZE           32      /* SSID 0 - 32 octets */
#define ELE_RATE_SIZE           12      /* Supported rates 1 - 12 */
#define ELE_RATE_SIZE_11B       8       /* Supported rates 1 - 8 for 11b only */
#define ELE_EXT_RATE_SIZE       253     /* Extended Supported rates */
#define ELE_BITMAP_SIZE         251     /* TIM bitmap */
#define ELE_CHLG_TEXT_SIZE      253     /* Challenge text size */
#define ELE_CF_PARAM_SIZE       6       /* CF param element size */
#define ELE_IBSS_PARAM_SIZE     2       /* IBSS param element size */
#define ELE_UCSE_SIZE           32      /* unicast/pairwise key cipher suite size */
#define ELE_MCSE_SIZE           4       /* multicast/group key cipher suite size */
#define ELE_AUTHSE_SIZE         32      /* Authentication suite size */
#define ELE_COUNTRY_SIZE        3       /* Country string size */
#define ELE_TPC_SIZE            6       /* Transmit Power Control length */

/* The elements are mapped into seq ID which are used to
 * represent them. This is avoid a sparse array when we
 * not using the most of the Element IDs, get rid of this
 * and the mapping table when the elementIDs move away from 
 * being sparse.
 */
typedef enum {
    MAP_ELE_SSID,
    MAP_ELE_SUPPORTED_RATES,
    MAP_ELE_FH_PARAM_SET,
    MAP_ELE_DS_PARAM_SET,
    MAP_ELE_CF_PARAM_SET,
    MAP_ELE_TIM,
    MAP_ELE_IBSS_PARAM_SET,       
    MAP_ELE_COUNTRY_INFO,
    MAP_ELE_CHLG_TEXT,
    MAP_ELE_NONERP,
    MAP_ELE_EXT_SUPPORTED_RATES,
    MAP_ELE_CKIP_CSN,
    MAP_ELE_TPC,
    MAP_ELE_UNUSED,
    MAP_ELE_ESCAPE
} WLAN_ELEM_ID_MAP;

/* Frame control field of the MAC header */

/* values for the protocol version field */
#define PROTOCOL_VER_0          0       /* Standard specifies version 0 */

/* Values for frame type */
#define FRAME_MGT               0       /* Managemnt frame */
#define FRAME_CTRL              1       /* Control frame */
#define FRAME_DATA              2       /* Data frame */
#define FRAME_RESERVED          3       /* 3 is reserved value */

/* Values for frame subtype */
#define SUBT_ASSOC_REQ          0       /* Association request */
#define SUBT_ASSOC_RESP         1       /* Association response */
#define SUBT_REASSOC_REQ        2       /* Reassociation request */
#define SUBT_REASSOC_RESP       3       /* Reassociation response */
#define SUBT_PROBE_REQ          4       /* Probe request */
#define SUBT_PROBE_RESP         5       /* Probe response */
#define SUBT_BEACON             8       /* Beacon frame */
#define SUBT_ATIM               9       /* ATIM message */
#define SUBT_DISASSOC           10      /* Disassociation */
#define SUBT_AUTH               11      /* Authentication */
#define SUBT_DEAUTH             12      /* Deauthentication */
#define SUBT_ACTION             13      /* Action */

#define SUBT_PSPOLL             10      /* Power save poll */
#define SUBT_RTS                11      /* Request to Send */
#define SUBT_CTS                12      /* Clear to Send */
#define SUBT_ACK                13      /* ACK frame */
#define SUBT_CFEND              14      /* Contention-free end */
#define SUBT_CFENDACK           15      /* CF-End + CF-ACK */

#define SUBT_DATA               0       /* Just data */
#define SUBT_DATA_CFACK         1       /* Data + CF-Ack */
#define SUBT_DATA_CFPOLL        2       /* Data + CF-Poll */
#define SUBT_DATA_CFACK_CFPOLL  3       /* Data + CF-Ack + CF-Poll */
#define SUBT_NODATA             4       /* Null function, no data */
#define SUBT_NODATA_CFACK       5       /* No data + CF-Ack */
#define SUBT_NODATA_CFPOLL      6       /* No data + CF-Poll */
#define SUBT_NODATA_CFACK_CFPOLL 7      /* No data + CF-Ack + */
                                        /* CF-Poll */
#define SUBT_QOS                8       /* The QoS dimension */
#define SUBT_QOS_NULL           12      /* SUBT_NODATA | SUBT_QOS */

/* MAC Address definitions */
#define WLAN_MAC_ADDR_SIZE      6
union wlanMACAddr {
    A_UINT8  octets[WLAN_MAC_ADDR_SIZE];
    A_UINT16 words[WLAN_MAC_ADDR_SIZE/2];
    struct {
        A_UINT32 word;
        A_UINT16 half;
    } __ATTRIB_PACK st;
} __ATTRIB_PACK;

/*
 * Define the frame size related constants for ethernet and 802.11 frames
 */
#define MAX_ETHER_FRAME_SIZE    1514    /* max length for Ethernet/802.3 frame */
#define ETHER_HDR_SIZE          14      /* Ethernet/802.3  header length */
#define MAX_ETHER_BODY_SIZE     1500    /* max body length for Ethernet/802.3 */
#define ETHER_TYPE_SIZE         2       /* size of type or length for Ethernet/802.3 */
#define MAX_WLAN_FRAME_SIZE     2342    /* max length for 802.11 frame */
#define WLAN_HDR_SIZE           24      /* length for 802.11 frame header without address 4 */
#define WLAN_HDR4_SIZE          32      /* length for 802.11 frame header with adress 4 */
#define MAX_WLAN_BODY_SIZE      2312    /* max length for 802.11 frame body */
//#define WLAN_CTRL_FRAME_SIZE    (sizeof(WLAN_FRAME_ACK) + FCS_FIELD_SIZE)

#define FCS_FIELD_SIZE          4       /* size of FCS */
#define WEP_IV_FIELD_SIZE       4       /* wep IV field size */
#define AES_IV_FIELD_SIZE       4       /* aes IV field size */
#define EXT_IV_FIELD_SIZE       4       /* ext IV field size */
#define EXT_IV_BIT              (1 << 29)      /* ext IV bit */
#define WEP_ICV_FIELD_SIZE      4       /* wep ICV field size */
#define AES_ICV_FIELD_SIZE      8       /* AES ICV field size */
#define WEP_FIELDS_SIZE (WEP_IV_FIELD_SIZE + WEP_ICV_FIELD_SIZE) /* total size of wep fields needed */

#define MAX_IV_FIELD_SIZE       (WEP_IV_FIELD_SIZE + EXT_IV_FIELD_SIZE)
#define MAX_ICV_FIELD_SIZE      AES_ICV_FIELD_SIZE

#define AES_KEY_SIZE_BYTES      16              /* 128 bits */
#define TKIP_KEY_SIZE_BYTES     32              /* 256 bits */

#define CKIP_MIC_FIELD_SIZE     8 /* includes both MIC and SEQ fields */
#define TKIP_MIC_FIELD_SIZE     8 /* added at end of frame */

/* EAPOL/802.1x frames are identified by their EAPOL typeOrLen field in SNAP header. */
#define EAPOL_TYPEORLEN         0x888e // deprecate this name
#define ETHERTYPE_EAPOL         EAPOL_TYPEORLEN
#define DDP_SNAP                0x0000 // only valid with Aironet SNAP

/*
 * A conservative estimate of the max encap header size
 * needed here would be 32 bytes for WLAN - assume four
 * addr bridge mode with QoS (or just word aligned); max
 * 8 bytes of IV, and another 10 bytes of overhead for
 * CKIP encapsulation - all rounded up.
 */
#define MAX_ENCAP_HDRLEN 52

typedef struct EapolSNAPhdr_s {
    A_UINT8     snapHeader[8];
} EAPOL_SNAP_HDR;

/* MAC header sizes in octets for various types of frames */
#define MAC_HDR_MGT_SIZE        24      /* All management frames */
#define MAC_HDR_DATA3_SIZE      24      /* Data frames with 3 addr */
#define MAC_HDR_DATA4_SIZE      30      /* Data frames with 4 addr */
                                        /* when ToDS and FromDS are set */
#define MAC_HDR_CTRL1_SIZE      10      /* Control frames with 1 addr */
                                        /* CTS, ACK types */
#define MAC_HDR_CTRL2_SIZE      16      /* Control frames with 2 addr */
                                        /* all other types */

/* Power management modes */
#define PS_MODE_ACTIVE          0       /* Station is active */
#define PS_MODE_POWER_SAVE      1       /* Station going in power save mode */

/* Type of wireless lan service - access point or station */
typedef enum {
    WLAN_STA_SERVICE = 0,
    WLAN_AP_SERVICE  = 1
} WLAN_SERVICE;

#define WLAN_OK                 A_OK

#ifdef ARCH_BIG_ENDIAN

typedef struct wlanFrameControl {
    A_UINT8     fSubtype:4,             /* frame subtype */
                fType:2,                /* frame type - contro, mgt, data */
                protoVer:2;             /* protocol version */
    A_UINT8     order:1,                /* True for StrictOrdered service class */
                wep:1,                  /* True for WEP encrypted body */
                moreData:1,             /* True if more DUs are buffered */
                pwrMgt:1,               /* True if STA going into PS mode */
                retry:1,                /* True if frame is being retransmitted */
                moreFrag:1,             /* True if more fragments still to come */
                FromDS:1,               /* FromDS bit, frame coming from DS */
                ToDS:1;                 /* ToDS bit, frame going to DS */
} __ATTRIB_PACK FRAME_CONTROL;

typedef union wlanSeqCtrl {
    struct {
        A_UINT8     seqNumLo:4,         /* Lower bits of the sequence number 0-4095 */
                    fragNum:4;          /* Fragment number */
        A_UINT8     seqNumHi;           /* High bits of the sequence number 0-4095 */
    } __ATTRIB_PACK sc;
    A_UINT16    data;
} __ATTRIB_PACK SEQ_CONTROL;

#define WLAN_GET_SEQNUM(_sc)                                            \
    (((A_UINT16)((_sc).sc.seqNumHi) << 4) | (A_UINT16)((_sc).sc.seqNumLo))
#define WLAN_SET_SEQNUM(_sc, _num)   {                                \
    (_sc).sc.seqNumHi = (A_UINT8)((_num) >> 4);                         \
    (_sc).sc.seqNumLo = (A_UINT8)((_num) & 0x0f);                       \
} 

#else /* Little_Endian */

typedef struct wlanFrameControl {
    A_UINT8     protoVer:2,             /* protocol version */
                fType:2,                /* frame type - contro, mgt, data */
                fSubtype:4;             /* frame subtype */
    A_UINT8     ToDS:1,                 /* ToDS bit, frame going to DS */
                FromDS:1,               /* FromDS bit, frame coming from DS */
                moreFrag:1,             /* True if more fragments still to come */
                retry:1,                /* True if frame is being retransmitted */
                pwrMgt:1,               /* True if STA going into PS mode */
                moreData:1,             /* True if more DUs are buffered */
                wep:1,                  /* True for WEP encrypted body */
                order:1;                /* True for StrictOrdered service class */
} __ATTRIB_PACK FRAME_CONTROL;

typedef union wlanSeqCtrl {
    struct {
        A_UINT16    fragNum:4,          /* Fragment number */
                    seqNum:12;          /* Sequence number 0-4095 */
    } __ATTRIB_PACK sc;
    A_UINT16    data;
} __ATTRIB_PACK SEQ_CONTROL;

#define WLAN_GET_SEQNUM(_sc)        ((_sc).sc.seqNum)
#define WLAN_SET_SEQNUM(_sc, _num)   {            \
    (_sc).sc.seqNum = (_num);                       \
} 

#endif /* Endianness */

#define WLAN_GET_FRAGNUM(_sc)       ((_sc).sc.fragNum)
#define WLAN_SET_FRAGNUM(_sc, _num) {            \
    (_sc).sc.fragNum = (_num);                      \
} 

/*
 * Duration field is used in two different ways.
 * When bit 15 is 0, bits 0:14 are used to update NAV.
 * When bit 15 is 1 and bit 14 is 1, bits 0:13 are Association ID.
 * Bit 15 and 14 are 1 during CFP
 */
typedef A_UINT16                            DURATION;
#define WLAN_GET_DURATION(_dur)             le2cpu16(_dur)
#define WLAN_SET_DURATION_NAV(_dur, _nav)   do {    \
    A_UINT16 val = _nav;                            \
    ASSERT((val & 0x8000) == 0);                    \
    (_dur) = cpu2le16(val);                         \
} while (0)
#define WLAN_SET_DURATION_CFP(_dur)         do {    \
    (_dur) = cpu2le16(0x8000);                      \
} while (0)
#define WLAN_SET_DURATION_AID(_dur, _aid)   do {    \
    A_UINT16 val = 0xc000 | (_aid);                 \
    (_dur) = cpu2le16(val);                         \
} while (0)

typedef union wlanMACAddr WLAN_MACADDR;
typedef WLAN_MACADDR BSSID;             /* BSSID is 48 bit field, same format */
                                        /* as MAC address, but not called MAC */
                                        /* address. Hence a separate definition */

#ifdef ARCH_BIG_ENDIAN

typedef struct wlanCapabilityInfo {
    A_UINT16    reserved0:4,            /* Reserved bits */
                rsn:1,                  /* RSN enable */
                shortSlotTime:1,        /* G mode short slot time */
                reserved1:2,            /* Reserved bits */
                agility:1,              /* Channel agility in use */
                pbcc:1,                 /* 1 = PBCC modulation allowed */
                shortPreamble:1,        /* 1 = Short preamble allowed, 0 = not */
                privacy:1,              /* Set by AP if WEP required */
                cfPollReq:1,            /* CF poll request */
                cfPollable:1,           /* CF poll ability of STA */
                ibss:1,                 /* Set for IBSS type network */
                ess:1;                  /* Set for ESS type network */
} __ATTRIB_PACK CAP_INFO;

#else /* Little_Endian */

typedef struct wlanCapabilityInfo {
    A_UINT16    ess:1,                  /* Set for ESS type network */
                ibss:1,                 /* Set for IBSS type network */
                cfPollable:1,           /* CF poll ability of STA */
                cfPollReq:1,            /* CF poll request */
                privacy:1,              /* Set by AP if WEP required */
                shortPreamble:1,        /* 1 = Short preamble allowed, 0 = not */
                pbcc:1,                 /* 1 = PBCC modulation allowed */
                agility:1,              /* Channel agility in use */
                reserved1:2,            /* Reserved bits */
                shortSlotTime:1,        /* G mode short slot time */
                rsn:1,                  /* RSN enable */
                reserved0:4;            /* Reserved bits */
} __ATTRIB_PACK CAP_INFO;

#endif /* Endianness */

//#define NTID    17                      /* number of possible QoS flows (4-bit tid + group address) */
#ifdef ARCH_BIG_ENDIAN

typedef struct wlanQoSCntl {
    A_UINT8    reserved:1,
               ackpolicy:2,
               eosp:1,
               tid:4;
    A_UINT8    txop:8;
} __ATTRIB_PACK QOS_CNTL;    

#else /* Little_Endian */

typedef struct wlanQosCntl {
    A_UINT8     tid:4,
                eosp:1,
                ackpolicy:2,
                reserved:1;
    A_UINT8     txop:8;
} __ATTRIB_PACK QOS_CNTL;

#endif /* Endianness */

#ifdef ARCH_BIG_ENDIAN

typedef struct wlanNonERPInfo {
    A_UINT8     reserved:5,             /* Reserved bits */
                preamble:1,             /* Set when using long preamble */
                protect:1,              /* Set when protection mechanism on */
                present:1;              /* Set when nonERP STA present */
} __ATTRIB_PACK NONERP_INFO;

#else /* Little_Endian */

typedef struct wlanNonERPInfo {
    A_UINT8     present:1,              /* Set when nonERP STA present */
                protect:1,              /* Set when protection mechanism on */
                preamble:1,             /* Set when using long preamble */
                reserved:5;             /* Reserved bits */
} __ATTRIB_PACK NONERP_INFO;

#endif /* Endianness */


#ifdef ARCH_BIG_ENDIAN
typedef struct wlanAthAdvCapiInfo {
    A_UINT8     boost:1,
                reserved:2,             /* 5:6 Reserved bits */
                useFriendlyTurbo:1,     /* 4 Using Friendly Turbo feature */
                useXr:1,                /* 3 Using XR feature */
                useFastFrame:1,         /* 2 Using FastFrame feature */
                useCompression:1,       /* 1 Using compression feature */
                useTurboPrime:1;        /* 0 Using Turbo Prime feature */

} __ATTRIB_PACK ATHADVCAP_INFO1;

#else /* Little_Endian */

typedef struct wlanAthAdvCapiInfo {
    A_UINT8     useTurboPrime:1,        /* 0 Using Turbo Prime feature */
                useCompression:1,       /* 1 Using compression feature */
                useFastFrame:1,         /* 2 Using FastFrame feature */
                useXr:1,                /* 3 Using XR feature */
                useFriendlyTurbo:1,     /* 4 Using Friendly Turbo Feature */
                reserved:2,             /* 5:6 Reserved bits */
                boost:1;
} __ATTRIB_PACK ATHADVCAP_INFO1;

#endif /* Endianness */

/*
 * Macro to determine if the Advance Capabilities indicate if the Super Features are On.
 */
#define IS_SUPER_FEATURE_ON(_athAdvCap)                 \
        MAKE_BOOL((_athAdvCap)->useFastFrame    ||      \
                  (_athAdvCap)->useCompression  ||      \
                  (_athAdvCap)->useTurboPrime)

typedef struct wlanTimeStamp {
    A_UINT32    low;                    /* Timestamp low order 32 bits */
    A_UINT32    high;                   /* Timestamp high order 32 bits */
} __ATTRIB_PACK WLAN_TIMESTAMP;

/* TSF macros */
#define TSF_TO_TU(_t)                   (((_t).high << 22) | ((_t).low >> 10))
#define TSF_ADD(_t, _x) do {            \
    (_t).low += (_x);                   \
    if ((_t).low < (_x)) (_t).high++;   \
} while (0)
#define TSF_SUB(_t, _x) do {            \
    (_t).low -= (_x);                   \
    if ((_t).low > (_x)) (_t).high--;   \
} while (0)

/*
 * if:      y == x   y > x   y < x
 * returns:    0       1      -1
 */
#define TSF_COMP(x, y)                  \
    (((y).high > (x).high) ?  1 :       \
     ((y).high < (x).high) ? -1 :       \
     ((y).low  > (x).low)  ?  1 :       \
     ((y).low  < (x).low)  ? -1 : 0)

typedef struct wlanInfoElement {
    A_UINT8     elementID;              /* 1 byte element ID */
    A_UINT8     length;                 /* Length field */
    A_UINT8     value[ELE_INFO_SIZE];   /* Max 255 byte array of octets */
} __ATTRIB_PACK INFO_ELEMENT;

typedef struct wlanSSID {
    A_UINT8     elementID;              /* 1 byte element ID */
    A_UINT8     length;                 /* Length field */
    A_UINT8     ssid[ELE_SSID_SIZE];    /* Variable size 0-32 array of octets */
} __ATTRIB_PACK SSID;

typedef struct wlanRateSet {
    A_UINT8     elementID;              /* 1 byte element ID */
    A_UINT8     length;                 /* Length field */
    A_UINT8     rates[ELE_RATE_SIZE];   /* Rates 1-8 array of octets */
} __ATTRIB_PACK RATE_SET;

typedef struct wlanExtRateSet {
    A_UINT8     elementID;                /* 1 byte element ID */
    A_UINT8     length;                   /* Length field */
    A_UINT8     rates[ELE_EXT_RATE_SIZE]; /* Rates 1-n array of octets */
} __ATTRIB_PACK EXT_RATE_SET;

#define VALID_ERS_ELEMENT(_ersp)                \
        (  ((_ersp)->elementID == ELE_EXT_SUPPORTED_RATES) \
        && ((_ersp)->length > 0) )

typedef struct wlanFHParamSet {
    A_UINT8     elementID;              /* 1 byte element ID */
    A_UINT8     length;                 /* Length field */
    A_UINT16    dwellTime;              /* Dwell time in TU */
    A_UINT8     hopSet;                 /* Hop set */
    A_UINT8     hopPattern;             /* Hop Pattern */
    A_UINT8     hopIndex;               /* Hop index selects current index in pattern */
} __ATTRIB_PACK FH_PARAM_SET;

typedef struct wlanDSParamSet {
    A_UINT8     elementID;              /* 1 byte element ID */
    A_UINT8     length;                 /* Length field */
    A_UINT8     currentChannel;         /* 1 byte channel */
} __ATTRIB_PACK DS_PARAM_SET;

typedef struct wlanCFParamSet {
    A_UINT8     elementID;              /* 1 byte element ID */
    A_UINT8     length;                 /* Length field */
    A_UINT8     cfpCount;               /* how many DTIMs before next CFP start */
    A_UINT8     cfpPeriod;              /* No.of DTIMs between CFPs */
    A_UINT16    cfpMaxDuration;         /* Max duration of CFP in TU */
    A_UINT16    cfpDurRemain;           /* Remaining duration */
} __ATTRIB_PACK CF_PARAM_SET;

#define VALID_CF_ELEMENT(_cfp)                          \
        (  ((_cfp)->elementID == ELE_CF_PARAM_SET)      \
        && ((_cfp)->length == ELE_CF_PARAM_SIZE)        \
        && ((_cfp)->cfpPeriod > 0) )

typedef struct wlanTIMElement {
    A_UINT8     elementID;              /* 1 byte element ID */
    A_UINT8     length;                 /* Length field */
    A_UINT8     dtimCount;              /* How many beacons before next DTIM */
    A_UINT8     dtimPeriod;             /* No. of beacons between DTIMs */
    A_UINT8     bitmapControl;
    A_UINT8     bitmap[ELE_BITMAP_SIZE];        /* 251 bytes Partial virtual Bitmap */
} __ATTRIB_PACK TIM_ELEMENT;

typedef struct wlanNonERPElement {
    A_UINT8     elementID;             /* 1 byte element ID */
    A_UINT8     length;                /* Length field */
    NONERP_INFO info;                  /* 1 char  */
} __ATTRIB_PACK NONERP_ELEMENT;

typedef struct countryInfoList {
    A_UINT8     elementID;         /* 1 byte element ID */
    A_UINT8     length;            /* Total length of the list */
    A_UINT8     countryString[3];  /* ISO 2 char country string + (I)ndoor/(O)utdoor */
    struct {
        A_UINT8 firstChannel;
        A_UINT8 numChannel;
        A_UINT8 maxTxPwr;
    } __ATTRIB_PACK subBand[4];                  /* SubBand List starts here */
    A_UINT8     pad;               /* Final pad that may be required if 4 subbands used */
} __ATTRIB_PACK COUNTRY_INFO_LIST;

typedef struct wlanIBSSParamSet {
    A_UINT8     elementID;              /* 1 byte element ID */
    A_UINT8     length;                 /* Length field */
    A_UINT16    atimWindow;             /* ATIM window length in TU */
} __ATTRIB_PACK IBSS_PARAM_SET;

typedef struct wlanChlgText {
    A_UINT8     elementID;              /* 1 byte element ID */
    A_UINT8     length;                 /* Length field */
    A_UINT8     chlgText[ELE_CHLG_TEXT_SIZE];   /* Challenge text, 1-253 byte */
} __ATTRIB_PACK CHLG_TEXT;

typedef struct wlanRSNESet {
    A_UINT8     elementID;                  /* 1 byte element ID */
    A_UINT8     length;                     /* Length field */
    A_UINT16    version;                    /* RSN spec revision */
    A_UINT32    mCipher[ELE_MCSE_SIZE/4];   /* multicast/group key cipher */
    A_UINT16    uCipherCount;               /* count of pairwise key ciphers */
    A_UINT32    uCiphers[ELE_UCSE_SIZE/4];  /* ciphers 1-6 array of 4 octets */
    A_UINT16    authSelectorCount;          /* authentication selector count */
    A_UINT32    authSelectors[ELE_AUTHSE_SIZE/4];/* selectors 4*n octets */
} __ATTRIB_PACK RSNE_SET;

/*
 *  Strategy:  When using WPA, the STA will use this IE in the air, but
 *  will store the data internally in Atheros-private CSN style.  The
 *  assumption is that the OUI in the IE will be the same OUI as should
 *  be used in each of the suite elements.
 */
typedef struct wlanVendorIe {
    A_UINT8    elementID;
    A_UINT8    length;
    A_UINT8    oui[3];
    A_UINT8    value[1];
} __ATTRIB_PACK VENDOR_IE;

typedef struct vendorIe {
    A_UINT8    elementID;
    A_UINT8    length;
    A_UINT8    oui[3];
    A_UINT8    ouiType;
    A_UINT16   version;
    A_UINT8    value[1];
} __ATTRIB_PACK COMMON_VENDOR_IE;

typedef COMMON_VENDOR_IE ATH_VENDOR_IE;
typedef COMMON_VENDOR_IE MS_VENDOR_IE;
typedef COMMON_VENDOR_IE AIRONET_VENDOR_IE;

typedef struct wlanAthAdvCapIe {
    A_UINT8         elementID;
    A_UINT8         length;
    A_UINT8         oui[3];
    A_UINT8         ouiType;
    A_UINT16        version;
    ATHADVCAP_INFO1  info;
    A_UINT16        defKeyIndex;
} __ATTRIB_PACK ATH_ADVCAP_IE;

#define VALID_ATH_ADVCAP_ELEMENT(_np)                    \
        (   ((_np)->elementID == ELE_VENDOR_PRIVATE) &&  \
            ((_np)->length >= 6)                     &&  \
            IS_ATHEROS_OUI((_np)->oui)               &&  \
            ((_np)->ouiType == ATH_OUI_TYPE_CAP)     &&  \
            ((_np)->version == ATH_OUI_VER_CAP))

typedef struct wlanAthXRParamIe {
    A_UINT8         elementID;
    A_UINT8         length;
    A_UINT8         oui[3];
    A_UINT8         ouiType;
    A_UINT16        version;
    A_UINT16        info;
    WLAN_MACADDR    baseBssid;
    WLAN_MACADDR    xrBssid;
    A_UINT16        baseBeaconInterval;
    A_UINT16        xrBeaconInterval;
    ATHADVCAP_INFO1  baseBssAdvCapinfo;
    ATHADVCAP_INFO1  xrBssAdvCapinfo;
}  ATH_XR_PARAM_IE;

#define VALID_ATH_XR_PARAM_ELEMENT(_np)                  \
        (   ((_np)->elementID == ELE_VENDOR_PRIVATE) &&  \
            ((_np)->length >= 6)                     &&  \
            IS_ATHEROS_OUI((_np)->oui)               &&  \
            ((_np)->ouiType == ATH_OUI_TYPE_XR)      &&  \
            ((_np)->version == ATH_OUI_VER_XR))

typedef struct WMEv1AcRecord {
#ifdef ARCH_BIG_ENDIAN
    A_UINT8     rsrv     : 1,
                aci      : 2,
                acm      : 1,
                aifs     : 4;
    A_UINT8     logCwMax : 4,
                logCwMin : 4;
#else
    A_UINT8     aifs     : 4,
                acm      : 1,
                aci      : 2,
                rsrv     : 1;
    A_UINT8     logCwMin : 4,
                logCwMax : 4;
#endif
    A_UINT16    txOpLimit;
} __ATTRIB_PACK WMEv1_AC_RECORD;

#define TXOP_TO_US(_txOp)   ((A_UINT32)(_txOp) << 5)
#define US_TO_TXOP(_us)     ((A_UINT16)((A_UINT32)(_us) >> 5))
#define LOG_TO_CW(_log)     ((1 << (A_UINT32)(_log)) - 1)

typedef enum {
    ACI_BE = 0x0,
    ACI_BK = 0x1,
    ACI_Vi = 0x2,
    ACI_Vo = 0x3,

    ACI_MAX = 0x4
} WMEv1_ACI;

typedef struct WMEv1Param {
    A_UINT8         info;
    A_UINT8         _pad;   /* for now */
    WMEv1_AC_RECORD ac[ACI_MAX];
} __ATTRIB_PACK WMEv1_PARAM;

#define WMEv1_OUI_TYPE            2
#define WMEv1_TSPEC_OUI_SUBTYPE   2
#define WMEv1_PARAM_OUI_SUBTYPE   1
#define WMEv1_SHORT_OUI_SUBTYPE   0

#define WMEv1_PARAM_OUI_VERSION   1
#define WMEv1_TSPEC_OUI_VERSION   1

typedef struct WMEv1ParamIe {
    A_UINT8         elementID;
    A_UINT8         length;
    A_UINT8         oui[3];
    A_UINT8         ouiType;
    A_UINT8         ouiSubType;
    A_UINT8         version;
    WMEv1_PARAM     info;
} __ATTRIB_PACK WMEv1_PARAM_IE, ATH_WME_PARAM_IE;

#define VALID_WMEv1_PARAM_IE(_np) (                               \
    ((_np)->elementID == ELE_VENDOR_PRIVATE)                   && \
    ((_np)->length >= (FIELD_OFFSET(WMEv1_PARAM_IE, info) - \
        FIELD_OFFSET(WMEv1_PARAM_IE, oui[0])))           && \
    ((_np)->oui[0] == 0x00)                                    && \
    ((_np)->oui[1] == 0x50)                                    && \
    ((_np)->oui[2] == 0xf2)                                    && \
    ((_np)->ouiType == WMEv1_OUI_TYPE)                         && \
    ((_np)->ouiSubType == WMEv1_PARAM_OUI_SUBTYPE)             && \
    ((_np)->version == WMEv1_PARAM_OUI_VERSION)                   \
)
#define VALID_WMEv1_SHORT_IE(_np) (                               \
    ((_np)->elementID == ELE_VENDOR_PRIVATE)                   && \
    ((_np)->length >= (FIELD_OFFSET(WMEv1_PARAM_IE, info.info) - \
        FIELD_OFFSET(WMEv1_PARAM_IE, oui[0])))           && \
    ((_np)->oui[0] == 0x00)                                    && \
    ((_np)->oui[1] == 0x50)                                    && \
    ((_np)->oui[2] == 0xf2)                                    && \
    ((_np)->ouiType == WMEv1_OUI_TYPE)                         && \
    ((_np)->ouiSubType == WMEv1_SHORT_OUI_SUBTYPE)             && \
    ((_np)->version == WMEv1_PARAM_OUI_VERSION)                   \
)
#define VALID_WMEv1_TSPEC_ELEMENT(_np) (                               \
    ((_np)->elementID == ELE_VENDOR_PRIVATE)                        && \
    ((_np)->length >= (FIELD_OFFSET(WMEv1_TSPEC_ELEMENT, body.endMarker) -     \
        FIELD_OFFSET(WMEv1_TSPEC_ELEMENT, oui[0])))                      && \
    ((_np)->oui[0] == 0x00)                                         && \
    ((_np)->oui[1] == 0x50)                                         && \
    ((_np)->oui[2] == 0xf2)                                         && \
    ((_np)->ouiType == WMEv1_OUI_TYPE)                              && \
    ((_np)->ouiSubType == WMEv1_TSPEC_OUI_SUBTYPE)                  && \
    ((_np)->version == WMEv1_TSPEC_OUI_VERSION)                        \
)


#define VALID_ATH_WME_PARAM_IE(_np) (                             \
    ((_np)->elementID == ELE_VENDOR_PRIVATE)                   && \
    ((_np)->length >= (FIELD_OFFSET(ATH_WME_PARAM_IE, info) -     \
        FIELD_OFFSET(ATH_WME_PARAM_IE, oui[0])))               && \
    IS_ATHEROS_OUI((_np)->oui)                                 && \
    ((_np)->ouiType == ATH_OUI_TYPE_WME)                       && \
    ((_np)->ouiSubType == ATH_OUI_SUBTYPE_WME_PARAM)           && \
    ((_np)->version == ATH_OUI_VERSION_WME_PARAM)                 \
)

#define WME_MGT_NOTIF_CAT_CODE  17

typedef enum {
    WME_MGT_NOTIF_ACTION_SETUP_REQ      = 0,
    WME_MGT_NOTIF_ACTION_SETUP_RESP     = 1,
    WME_MGT_NOTIF_ACTION_TEARDOWN       = 2,

    WME_MGT_NOTIF_ACTION_MAX            = 3
} WME_MGT_NOTIF_ACTION_CODE;

typedef enum {
    WME_MGT_NOTIF_DIALOG_TEARDOWN       = 0,
    WME_MGT_NOTIF_DIALOG_SETUP          = 1
} WME_MGT_NOTIF_DIALOG_TOKEN;

typedef enum {
    WME_MGT_NOTIF_STATUS_ADM_ACCEPTED   = 0,
    WME_MGT_NOTIF_STATUS_INV_PARAM      = 1,
    WME_MGT_NOTIF_STATUS_RESERVED       = 2,
    WME_MGT_NOTIF_STATUS_REFUSED        = 3,

    WME_ACTION_MAX                      = 4
} WME_MGT_NOTIF_STATUS_CODE;

#ifdef ARCH_BIG_ENDIAN
typedef struct wmeV1TspecTSInfo {
    A_UINT8     one:1,
                direction:2,
                tid:4,
                reserved1:1;
    A_UINT8     reserved2:2,
                dot1Dtag:3,
                psb:1,
                reserved3:1,
                zero:1;
    A_UINT8     reserved5:7,
                reserved4:1;
} __ATTRIB_PACK WMEv1_TSPEC_TSINFO;
#else
typedef struct wmeV1TspecTSInfo {
    A_UINT8     reserved1:1,
                tid:4,
                direction:2,
                one:1;
    A_UINT8     zero:1,
                reserved3:1,
                psb:1,
                dot1Dtag:3,
                reserved2:2;
    A_UINT8     reserved4:1,
                reserved5:7;
}  __ATTRIB_PACK WMEv1_TSPEC_TSINFO;
#endif

typedef struct WMEv1TspecBody {
    WMEv1_TSPEC_TSINFO      tsInfo;             
    A_UINT16                nominalMsduSize;
    A_UINT16                maxMsduSize;
    A_UINT32                minSrvInternal;
    A_UINT32                maxSrvInternal;
    A_UINT32                inactivityInterval;
    A_UINT32                suspensionInterval;
    A_UINT32                srvStartTime;
    A_UINT32                minDataRate;
    A_UINT32                meanDataRate;
    A_UINT32                peakDataRate;
    A_UINT32                maxBurstSize;
    A_UINT32                delayBound;
    A_UINT32                minPhyRate;
    A_UINT16                surplusBwAllow;
    A_UINT16                mediumTime;
    A_UINT8                 endMarker;         /* not in spec but used internally */
} __ATTRIB_PACK WMEv1_TSPEC_BODY;

typedef struct wlanWmeV1TspecElement {
    A_UINT8             elementID;             /* 1 byte element ID */
    A_UINT8             length;                /* Length field */
    A_UINT8             oui[3];
    A_UINT8             ouiType;
    A_UINT8             ouiSubType;
    A_UINT8             version;
    WMEv1_TSPEC_BODY    body;
} __ATTRIB_PACK WMEv1_TSPEC_ELEMENT;

typedef enum {
    WME_TSPEC_DIR_UPLINK = 0x0,
    WME_TSPEC_DIR_DNLINK = 0x1,
    WME_TSPEC_DIR_RESERVED = 0x2,
    WME_TSPEC_DIR_BIDIR = 0x3
} WME_TSPEC_DIRECTION;

typedef enum {
    WME_TSPEC_PSB_LEGACY = 0x0,
    WME_TSPEC_PSB_TRIGGERED = 0x1
} WME_TSPEC_PSB;


typedef struct wlanWPAie {
    A_UINT8    elementID;
    A_UINT8    length;
    A_UINT8    oui[3];
    A_UINT8    ouiType;
    A_UINT16   version;
    A_UINT32   mCipher[1];   /* group key selection */
    A_UINT16   uCipherCount; /* count of pairwise key ciphers */
    A_UINT32   uCiphers[ELE_UCSE_SIZE/4];  /* ciphers 1-6 array of 4 octets */
    A_UINT16   authSelectorCount;          /* authentication selector count */
    A_UINT32   authSelectors[ELE_AUTHSE_SIZE/4];/* selectors 4*n octets */
    A_UINT16   caps;  /* Capabilities */
} __ATTRIB_PACK WPA_IE;

/*   mCipher, uCipherCount, at least 1 uCipher, authCount, at least 1 AKM */
#define MIN_WPAIE_ELELEN                                         \
                     (FIELD_OFFSET(WPA_IE, uCiphers) - 2 +       \
                     (1*sizeof(A_UINT32)) + sizeof(A_UINT16) +   \
                     (1*sizeof(A_UINT32)))

#define VALID_WPA_ELEMENT(_wpaep)                           \
        (   ((_wpaep)->elementID == ELE_VENDOR_PRIVATE) &&  \
            ((_wpaep)->length >= MIN_WPAIE_ELELEN)      &&  \
            ((_wpaep)->oui[0] == 0x00)                  &&  \
            ((_wpaep)->oui[1] == 0x50)                  &&  \
            ((_wpaep)->oui[2] == 0xF2)                  &&  \
            ((_wpaep)->ouiType == WPA_OUI_TYPE)         &&  \
            ((_wpaep)->version == WPAIE_VERSION)            )

typedef struct wlanUcseSet {
    A_UINT16    uCipherCount;               /* Length field */
    A_UINT32    uCiphers[ELE_UCSE_SIZE/4];  /* ciphers 1-6 array of 4 octets */
} __ATTRIB_PACK UCSE_SET;

#define VALID_UCSE_ELEMENT(_ucsep)                      \
        (   ((_ucsep)->uCipherCount >= 1)               \
         && ((_ucsep)->uCipherCount <= (ELE_UCSE_SIZE/4)))

#define VALID_CIPHER_OUI(_ucsep)                        \
        (   ((_ucsep  & 0xffffff) == ATH_OUI) ||        \
            ((_ucsep  & 0xffffff) == WPA_OUI) ||        \
            ((_ucsep  & 0xffffff) == AIRONET_OUI))

typedef struct wlanmcseSet {
    A_UINT32    mCipher[1];
} __ATTRIB_PACK MCSE_SET;

#define VALID_MCSE_ELEMENT(_mcsep)                      \
        (TRUE)

typedef struct wlanAuthseSet {
    A_UINT16    authSelectorCount;                  /* Length field */
    A_UINT32    authSelectors[ELE_AUTHSE_SIZE/4];   /* selectors 4*n octets */
} __ATTRIB_PACK AUTHSE_SET;

#define VALID_AUTHSE_ELEMENT(_authcsep)                 \
        (   ((_authcsep)->authSelectorCount >= 1)            \
         && ((_authcsep)->authSelectorCount <= (ELE_AUTHSE_SIZE/4)))

#define VALID_AUTH_OUI(_ucsep)                          \
        (   ((_ucsep  & 0xffffff) == ATH_OUI) ||        \
            ((_ucsep  & 0xffffff) == WPA_OUI) ||        \
            ((_ucsep  & 0xffffff) == AIRONET_OUI))

typedef enum wpaMsgNum {
    WPA_MSG1 = 1,
    WPA_MSG2,
    WPA_MSG3,
    WPA_MSG4,
} WPA_MSGNUM;

typedef struct wlanAironetIE {
    A_UINT8 elementID;       /* 1 byte element ID */
    A_UINT8 length;          /* Length field */
    A_UINT8 load;
    A_UINT8 hops;
    A_UINT8 devType;
    A_UINT8 refresh;
#define AIE_DEVICETYPE      0x66
    A_UINT8 cwmin;
    A_UINT8 cwmax;
    A_UINT8 reserved1[2];
    A_UINT8 flags;
#define AIE_CKIP_MIC        0x08
#define AIE_CKIP_KP         0x10
    A_UINT8 distance;
    A_UCHAR name[16];       /* may not be null terminated */
    A_UINT8 reserved2[4];
} __ATTRIB_PACK AIRONET_IE;


#define VALID_TPC_ELEMENT(_x)                \
        ( (_x)->elementID == ELE_TPC      && \
          (_x)->length    == ELE_TPC_SIZE && \
          (_x)->oui[0]    == 0x00         && \
          (_x)->oui[1]    == 0x40         && \
          (_x)->oui[2]    == 0x96         && \
          (_x)->oui[3]    == 0x00 )


typedef struct wlanInfoElementSet {
    INFO_ELEMENT           *pInfoElement[MAP_ELE_ESCAPE + 1];
    /* These are simple ptrs arising from VendorPrivate IEs */
    INFO_ELEMENT           *pWpaIe;
    ATH_ADVCAP_IE          *pAthCap;
    ATH_WME_PARAM_IE       *pAthWmeIe;
    ATH_XR_PARAM_IE        *pAthXrIe;
    WMEv1_PARAM_IE         *pWmeV1Ie;
    WMEv1_TSPEC_ELEMENT     *pWmeV1Tspec;
} __ATTRIB_PACK INFO_ELEMENT_SET;

/* Additional macros */

#define IS_ELEMENT_USED(_x) ((_x)->length != 0)

/**********************************************************/

/*
 * This section defines all types of 802.11 frames
 */

/*
 * PLCP Header
 * Frames delivered by MAC to the host will have the PLCP
 * header before the actual MAC header begins.
 */

#ifdef ARCH_BIG_ENDIAN

typedef struct wlanPLCPHeader {
    A_UINT32    tail:6,                 /* 6 tail bits */
                parity:1,               /* parity bit */
                length:12,              /* 12 bits length field */
                reserved:1,             /* Reserved bit */
                rate:4,                 /* 4 bits rate */
                rssi:8;                 /* receiver signal strength */
    A_UINT16    service;                /* 16 service bits, ignored */
} __ATTRIB_PACK WLAN_PLCP_HEADER;

#else /* Little_Endian */

typedef struct wlanPLCPHeader {
    A_UINT32    rssi:8,                 /* receiver signal strength */
                rate:4,                 /* 4 bits rate */
                reserved:1,             /* Reserved bit */
                length:12,              /* 12 bits length field */
                parity:1,               /* parity bit */
                tail:6;                 /* 6 tail bits */
    A_UINT16    service;                /* 16 service bits, ignored */
} __ATTRIB_PACK WLAN_PLCP_HEADER;

#endif /* Endianness */

/*
 * Control frames, section 7.2.1 of the spec.
 * The MAC Header part of control frames varies, hence we
 * haven't declared a separate structure for it.
 */

typedef struct wlanFrameRTS {
    FRAME_CONTROL frameCtrl;      /* Frame control */
    DURATION      durationNav;    /* Duration 0-32767 */
    WLAN_MACADDR  recAddr;        /* Receiver address */
    WLAN_MACADDR  transAddr;      /* Transmitter addr */
} __ATTRIB_PACK WLAN_FRAME_RTS;

typedef struct wlanFrameCTS {
    FRAME_CONTROL frameCtrl;      /* Frame control */
    DURATION      durationNav;    /* Duration 0-32767 */
    WLAN_MACADDR  recAddr;        /* Receiver address */
} __ATTRIB_PACK WLAN_FRAME_CTS;

typedef struct wlanFrameACK {
    FRAME_CONTROL frameCtrl;      /* Frame control */
    DURATION      durationNav;    /* Duration 0-32767 */
    WLAN_MACADDR  recAddr;        /* Receiver address */
} __ATTRIB_PACK WLAN_FRAME_ACK;

typedef struct wlanFramePspoll {
    FRAME_CONTROL frameCtrl;      /* Frame control */
    DURATION      durationId;     /* bits 0:10 AID */
    BSSID         bssId;          /* BSS ID */
    WLAN_MACADDR  transAddr;      /* Transmitter addr */
} __ATTRIB_PACK WLAN_FRAME_PSPOLL;

typedef struct wlanFrameCFEnd {
    FRAME_CONTROL frameControl;   /* Frame control */
    DURATION      durationNav;    /* set to 0 */
    WLAN_MACADDR  recAddr;        /* Receiver address */
    BSSID         bssId;          /* BSS ID */
} __ATTRIB_PACK WLAN_FRAME_CFEND;

typedef struct wlanFrameCFEndAck {
    FRAME_CONTROL frameControl;   /* Frame control */
    DURATION      durationNav;    /* set to 0 */
    WLAN_MACADDR  recAddr;        /* Receiver address */
    BSSID         bssId;          /* BSS ID */
} __ATTRIB_PACK WLAN_FRAME_CFENDACK;

/*
 * Data frames, section 7.2.2
 */

/* Maximum size of payload, i.e. frame body in data packet */
#define MAX_80211_FRAME_BODY_SIZE       MAX_WLAN_BODY_SIZE

/*
 * Size of empty packet, i.e. data packet with null body.
 * When you want to allocate a complete data packet, add the
 * payload size to EMPTY_80211_DATA_FRAME_SIZE and then
 * typecast it back to WLAN_FRAME_DATA. However, the FCS
 * field's offset depends on the data body size.
 */

#define EMPTY_80211_DATA_FRAME_SIZE     34

/* MAC header for the data packets is defined separately. */

/* 3 Address frame */
typedef struct wlanDataMacHeader3 {
    FRAME_CONTROL frameControl;
    DURATION      durationNav;
    WLAN_MACADDR  address1;
    WLAN_MACADDR  address2;
    WLAN_MACADDR  address3;
    SEQ_CONTROL   seqControl;
} __ATTRIB_PACK WLAN_DATA_MAC_HEADER3;

/* 3 Address frame with encryption fields */
typedef struct wlanFrame3DataEncrypt {
    WLAN_DATA_MAC_HEADER3 macHeader;
    A_UINT32              iv;             /* IV for encryption */
    A_UINT8               FrameBody[MAX_80211_FRAME_BODY_SIZE];
    A_UINT32              icv;            /* ICV for encryption */
} __ATTRIB_PACK WLAN_FRAME_3_DATA_ENCRYPT;

/* 3 Address frame with encryption fields, extended IV field */
typedef struct wlanFrame3DataEncryptExtIV {
    WLAN_DATA_MAC_HEADER3 macHeader;
    A_UINT32            iv;             /* IV for encryption */
    A_UINT32            extIv;          /* extended IV for encryption */
    A_UINT8             FrameBody[MAX_80211_FRAME_BODY_SIZE];
    A_UINT32            icv;            /* ICV for encryption */
} __ATTRIB_PACK WLAN_FRAME_3_DATA_ENCRYPT_EXTIV;

/* 3 Address QoS header */
typedef struct wlanQoSDataMacHeader3 {
    FRAME_CONTROL frameControl;
    DURATION      durationNav;
    WLAN_MACADDR  address1;
    WLAN_MACADDR  address2;
    WLAN_MACADDR  address3;
    SEQ_CONTROL   seqControl;
    QOS_CNTL      qosControl;
} __ATTRIB_PACK WLAN_QOS_DATA_MAC_HEADER3;


/* BAR frame header */
typedef struct wlanBarControlMacHeader {
    FRAME_CONTROL frameControl;
    DURATION      durationNav;
    WLAN_MACADDR  address1;
    WLAN_MACADDR  address2;
    A_UINT32      barControl;  // also include barAckStartSeqNum;
} __ATTRIB_PACK WLAN_BAR_CONTROL_MAC_HEADER;

/* 4 Address QoS header */
typedef struct wlanQoSDataMacHeader4 {
    FRAME_CONTROL frameControl;
    DURATION      durationNav;
    WLAN_MACADDR  address1;
    WLAN_MACADDR  address2;
    WLAN_MACADDR  address3;
    SEQ_CONTROL   seqControl;
    WLAN_MACADDR  address4;
    QOS_CNTL      qosControl;
} __ATTRIB_PACK WLAN_QOS_DATA_MAC_HEADER4;

/*
 * 4 Address frame from DS to DS
 * This data structure is also not only the largest size frame
 * header but a superset of all possible frame headers.
 * !! not true:  wlanQoSDataMacHeader4 is the largest frame !!
 * Hence it can be safely used as a generic frame header called
 * WLAN_FRAME_HEADER.
 */
typedef struct wlanDataMacHeader {
    FRAME_CONTROL frameControl;
    DURATION      durationNav;
    WLAN_MACADDR  address1;
    WLAN_MACADDR  address2;
    WLAN_MACADDR  address3;
    SEQ_CONTROL   seqControl;
    WLAN_MACADDR  address4;
} __ATTRIB_PACK WLAN_DATA_MAC_HEADER, WLAN_FRAME_HEADER;

/* Maximum size data frame */
typedef struct wlanFrameData {
    WLAN_DATA_MAC_HEADER        macHeader;
    A_UINT8                     FrameBody[MAX_80211_FRAME_BODY_SIZE];
} __ATTRIB_PACK WLAN_FRAME_DATA;

/* Maximum size data frame witn encryption fields */
typedef struct wlanFrameDataEncrypt {
    WLAN_DATA_MAC_HEADER        macHeader;
    A_UINT32                    iv;     /* IV for encryption */
    A_UINT8                     FrameBody[MAX_80211_FRAME_BODY_SIZE];
    A_UINT32                    icv;    /* ICV for encryption */
} __ATTRIB_PACK WLAN_FRAME_DATA_ENCRYPT;

/* Maximum size data frame witn encryption fields and padding */

typedef struct wlanFrameDataEncryptPad {
    WLAN_DATA_MAC_HEADER        macHeader;
    A_UINT8                     pad[2];
    A_UINT32                    iv;     /* IV for encryption */
    A_UINT8                     FrameBody[MAX_80211_FRAME_BODY_SIZE];
    A_UINT32                    icv;    /* ICV for encryption */
} __ATTRIB_PACK WLAN_FRAME_DATA_ENCRYPT_PAD;


/* Maximum size data frame witn encryption fields & extended iv field */
typedef struct wlanFrameDataEncryptExtIV {
    WLAN_DATA_MAC_HEADER        macHeader;
    A_UINT32                    iv;     /* IV for encryption */
    A_UINT32                    extIv;  /* extended IV for encryption */
    A_UINT8                     FrameBody[MAX_80211_FRAME_BODY_SIZE];
    A_UINT32                    icv;    /* ICV for encryption */
} __ATTRIB_PACK WLAN_FRAME_DATA_ENCRYPT_EXTIV;

/* Maximum size data frame witn encryption fields & extended iv field and pad */
typedef struct wlanFrameDataEncryptExtIVPad {
    WLAN_DATA_MAC_HEADER        macHeader;
    A_UINT8                     pad[2];
    A_UINT32                    iv;     /* IV for encryption */
    A_UINT32                    extIv;  /* extended IV for encryption */
    A_UINT8                     FrameBody[MAX_80211_FRAME_BODY_SIZE];
    A_UINT32                    icv;    /* ICV for encryption */
} __ATTRIB_PACK WLAN_FRAME_DATA_ENCRYPT_EXTIV_PAD;

/* The standard Ethernet frame is also defined for convenience */

typedef struct lanFrameHeader {
    WLAN_MACADDR        destAddr;
    WLAN_MACADDR        srcAddr;
    A_UINT16            lanTypeOrLen;
} __ATTRIB_PACK LAN_FRAME_HEADER;

/* Maximum size LAN data frame */
typedef struct lanFrameData {
    LAN_FRAME_HEADER    lanHeader;
    A_UINT8             frameData[MAX_ETHER_BODY_SIZE];
} __ATTRIB_PACK LAN_FRAME_DATA;

typedef struct {
    LAN_FRAME_HEADER    lanHeader;
    A_UINT8             dsap;
    A_UINT8             ssap;
    A_UINT8             control;
    A_UINT8             xid[3];
/* No ethertype - see bug#8167 */
} __ATTRIB_PACK L2_UPDATE_FRAME;

#define L2UF_LEN (sizeof(L2_UPDATE_FRAME) - sizeof(LAN_FRAME_HEADER))

#define IS4ADDRFRM(hdr) \
    ((hdr)->frameControl.FromDS && (hdr)->frameControl.ToDS)

#define GETFIVPTR(h) \
    ((IS4ADDRFRM((h))) ? (A_UINT32)&(((WLAN_FRAME_DATA_ENCRYPT_EXTIV *)(h))->iv)  \
    : (A_UINT32)&(((WLAN_FRAME_3_DATA_ENCRYPT_EXTIV *)(h))->iv))

#define GETIVPTR(h) \
    ((((h)->frameControl.fType == FRAME_DATA) && \
    ((((h)->frameControl.fSubtype) & SUBT_QOS) == SUBT_QOS)) ? \
                A_ROUNDUP(((GETFIVPTR(h)) + sizeof(QOS_CNTL)), 4) : \
                A_ROUNDUP((GETFIVPTR(h)), 4))

#define GETEXTFIVPTR(h) \
    (((IS4ADDRFRM((h))) ? (A_UINT32)&(((WLAN_FRAME_DATA_ENCRYPT_EXTIV *)(h))->extIv) \
       : (A_UINT32)&(((WLAN_FRAME_3_DATA_ENCRYPT_EXTIV *)(h))->extIv)))

#define GETEXTIVPTR(h) \
    ((((h)->frameControl.fType == FRAME_DATA) && \
    ((((h)->frameControl.fSubtype) & SUBT_QOS) == SUBT_QOS)) ? \
                     A_ROUNDUP(((GETEXTFIVPTR(h))+sizeof(QOS_CNTL)),4) : \
                     A_ROUNDUP((GETEXTFIVPTR(h)),4))
#define LLC_SAP_SNAP 0xAA

/*
 * This header has been added for encapsulating SNA Frames. 
 *
 * This LLC header format is as defined in:
 *   IEEE Std 802.2, 1998 Edition (ISO/IEC 8802-2:1998)
 *   Section 3.2: LLC PDU Structure
 */
typedef struct {
    LAN_FRAME_HEADER lanHeader;
    A_UINT8 dsap;
    A_UINT8 ssap;
    A_UINT8 control;
} __ATTRIB_PACK LAN_LLC_FRAME_HEADER;

typedef struct {
    A_UINT8 dsap;
    A_UINT8 ssap;
    A_UINT8 control;
} __ATTRIB_PACK LAN_LLC_HEADER;

#define CAP_TYPE_SIZE   6
typedef struct capType {
    A_UINT8     octets[CAP_TYPE_SIZE];
} __ATTRIB_PACK CAP_CONST;

typedef struct {
    CAP_CONST   capConst;
    A_UINT16    etherType;
} __ATTRIB_PACK LLC_SNAP_HEADER;

/*
 * Management frames, section 7.2.3
 */

/*
 * MAC header for the management packets is defined separately,
 * since it is common to all of them.
 */

typedef struct wlanMgtMacHeader {
    FRAME_CONTROL frameControl;
    DURATION      durationNav;
    WLAN_MACADDR  destAddr;
    WLAN_MACADDR  srcAddr;
    WLAN_MACADDR  bssId;
    SEQ_CONTROL   seqControl;
} __ATTRIB_PACK WLAN_MGT_MAC_HEADER;

/*
 * The beacon frame is variable length. First 5 fields are
 * always present, but the information elements, i.e. sets
 * of different parameters are present only when the beacon
 * is generated by that type of AP. These sets can be variable
 * size. We just declare 'buffer' field as a place holder. The
 * algorithms should look at the first byte, i.e. element ID,
 * then parse rest of the element and look for the next one.
 */

/*
 * WiFi requires supported beacon interval to be between 20 TU and 1000 TU
 */

#define BEACON_INTERVAL_MIN     20
#define BEACON_INTERVAL_MAX     1000
#define BEACON_INTERVAL_DEFAULT 100
#define IS_VALID_BEACON_INTERVAL(x) ((x) >= BEACON_INTERVAL_MIN && (x) <= BEACON_INTERVAL_MAX)

typedef struct wlanFrameBeacon {
    WLAN_MGT_MAC_HEADER macHeader;      /* Standard mgt header */
    WLAN_TIMESTAMP      timestamp;      /* 64 bit timestamp */
    A_UINT16            beaconInterval; /* Beacon interval in TU */
    CAP_INFO            capInfo;        /* AP capability info set */
    A_UCHAR             buffer[2];      /* Generic buffer. Variable size */
                                        /* data follows */
} __ATTRIB_PACK WLAN_FRAME_BEACON;

/* Atheros Vendor Specific types */
//#define ATH_OUI                         0x007f0300
#define IS_ATHEROS_OUI(_oui)            ((_oui)[0] == 0x00 && (_oui)[1] == 0x03 && (_oui)[2] == 0x7f)
#define ATH_OUI_TYPE_CAP                0x01
#define ATH_OUI_TYPE_WME                0x02
#define ATH_OUI_TYPE_XR                 0x03
#define ATH_OUI_VER_CAP                 0x0001
#define ATH_OUI_VER_XR                  0x0001
#define ATH_OUI_SUBTYPE_WME_PARAM       0x01
#define ATH_OUI_VERSION_WME_PARAM       0x01

/* Cipher Suite Selectors, defined such that they go out on the air as little endian */
#define TGI_OUI                         0x000000
#//define WPA_OUI                         0x00F25000
#define WPAIE_VERSION                   0x0001
#define AIRONET_OUI                     0x00964000
#define IS_AIRONET_OUI(_oui)            ((_oui)[0] == 0x00 && (_oui)[1] == 0x40 && (_oui)[2] == 0x96)

#define TGI_CSE_NULL                    0x00000000
#define TGI_CSE_WEP                     0x01000000
#define TGI_CSE_TKIP                    0x02000000
#define TGI_CSE_CCM                     0x04000000
#define TGI_CSE_WEP104                  0x05000000

#define WPA_OUI_TYPE                    0x01
//#define WPA_CSE_NULL                    ((0x00<<24)|WPA_OUI)
//#define WPA_CSE_WEP40                   ((0x01<<24)|WPA_OUI)
//#define WPA_CSE_TKIP                    ((0x02<<24)|WPA_OUI)
#define WPA_CSE_AES_CCMP                ((0x04<<24)|WPA_OUI)
//#define WPA_CSE_WEP104                  ((0x05<<24)|WPA_OUI)
#define WPA_CSE_CKIP                    ((0x00<<24)|AIRONET_OUI)
#define WPA_CSE_CKIP_MMH                ((0x01<<24)|AIRONET_OUI)
#define WPA_CSE_WEP_MMH                 ((0x02<<24)|AIRONET_OUI)

#define TGI_AUTHSE_NONE                 0x00000000
#define TGI_AUTHSE_8021X_UNSPEC         0x01000000
#define TGI_AUTHSE_8021x_PSK            0x02000000

#define WPA_AUTHSE_NONE                 ((0x00<<24)|WPA_OUI)
#define WPA_AUTHSE_8021X_UNSPEC         ((0x01<<24)|WPA_OUI)
#define WPA_AUTHSE_8021X_PSK            ((0x02<<24)|WPA_OUI)
#define WPA_AUTHSE_CCKM                 ((0x00<<24)|AIRONET_OUI)

#define ATH_CSE_AES_OCB                 0x007f0300
#define ATH_CSE_AES_OCB_REVA            0x017f0300
#define ATH_CSE_AES_CCM                 0x027f0300
#define ATH_CSE_TKIP                    0x107f0300
#define ATH_CSE_BASIC_WEP               0x207f0300
#define ATH_CSE_NULL                    0xff7f0300
#define ATH_CSE_DEFAULT                 0xff7f0300

#define IS_CIPHER_AES_CCM(cse)          \
        ((cse == ATH_CSE_AES_CCM)       \
         || (cse == WPA_CSE_AES_CCMP))

#define IS_CIPHER_WEP(cse)              \
        ((cse == ATH_CSE_BASIC_WEP)     \
         || (cse == WPA_CSE_WEP40)      \
         || (cse == WPA_CSE_WEP104)     )

#define IS_CIPHER_NULL(cse)             \
        ((cse == ATH_CSE_NULL)          \
        || (cse == WPA_CSE_NULL)        )

#define IS_CIPHER_TKIP(cse)             \
        ((cse) == WPA_CSE_TKIP)

#define IS_CIPHER_CKIP_MMH(cse)         \
        ((cse) == WPA_CSE_CKIP_MMH)

#define IS_CIPHER_WEP_MMH(cse)         \
        ((cse) == WPA_CSE_WEP_MMH)

#define IS_CIPHER_CKIP(cse)             \
        ((cse) == WPA_CSE_CKIP          \
        || IS_CIPHER_CKIP_MMH(cse))

/*
 * Status code field values in the management frames 802.11 Spec section 7.3.1.9 */

#define WLAN_SUCCESS                    WLAN_OK /* Successful */
#define WLAN_UNKNOWN_FAILURE            1       /* Unspecified failure */
#define WLAN_UNSUPPORTED_CAP            10      /* Can't support all requested */
                                                /* capabilities */
#define WLAN_UNCONFIRMED_ASSOC          11      /* Can't confirm current association */
#define WLAN_OUT_OF_SCOPE               12      /* Association denied due to a reason */
                                                /* outside the scope of 802.11 standard */
#define WLAN_UNSUPPORTED_ALG            13      /* Unsupported algorithm */
#define WLAN_OUT_OF_SEQUENCE            14      /* Authentication frame out of sequence */
#define WLAN_CHLG_FAILURE               15      /* Challenge failure in authentication */
#define WLAN_AUTH_TIMEOUT               16      /* Auth timeout waiting for next frame */
#define WLAN_TOOMANY_ASSOC              17      /* AP not able to handle more assoc */
#define WLAN_UNSUPPORTED_RATE           18      /* Requesting station doesn't support */
                                                /* all the rates in BSSBasicRateSet */
#define WLAN_NO_SHORT_PREAMBLE          19      /* Requesting station doesn't support short preamble */
#define WLAN_NO_PBCC                    20      /* Requesting station doesn't support PBCC */
#define WLAN_NO_CHANNEL_AGILITY         21      /* Requesting station doesn't support channel agility */

/* Reason Code values for Disassoc and Deauth frames 802.11 Spec section 7.3.1.7 */

#define REASON_RESERVED                 0       /* Reserved */
#define REASON_UNSPECIFIED              1       /* Unspecified reason */
#define REASON_AUTH_EXPIRED             2       /* Past authentication no longer valid */
#define REASON_AUTH_LEAVING             3       /* Sending station leaving BSS */
#define REASON_INACTIVE                 4       /* Disassocd due to inactivity */
#define REASON_TOOMANY_ASSOC            5       /* AP not able to handle all assoc's */
#define REASON_CLASS2                   6       /* Class 2 frame received from non-auth */
#define REASON_CLASS3                   7       /* Class 3 frame received from non-assoc */
#define REASON_ASSOC_LEAVING            8       /* Sending station leaving BSS */
#define REASON_NOT_AUTH                 9       /* Sender not auth'ed before requesting */
                                                /* association */
                                                /* 10 reserved codes */
#define REASON_RSN_REQUIRED             11      /* Enhanced Security required by IE */
#define REASON_RSN_INCONSISTENT         12      /* Enhanced Security used inconsistently */
#define REASON_IE_INVALID               13      /* Invalid Information Element */
#define REASON_MIC_FAILURE              14      /* MIC failure */
                                                /* 15 - 65535 reserved codes */

#define ASSOCID_MIN                     1       /* Min value of Association ID */
#define ASSOCID_MAX                     2007    /* Max value of Association ID */

typedef struct wlanFrameDisassoc {
    WLAN_MGT_MAC_HEADER macHeader;      /* Standard mgt header */
    A_UINT16            reasonCode;     /* Reason for action */
} __ATTRIB_PACK WLAN_FRAME_DISASSOC;

/* Associate request frame. SSID and supported rates elements
 * are variable size. Hence, you should compute correct offset
 * to actual rates field. This structure assumes max size ssid
 * and rateSet fields.
 */
typedef struct wlanFrameAssocReq {
    WLAN_MGT_MAC_HEADER macHeader;      /* Standard mgt header */
    CAP_INFO            capInfo;        /* capability information */
    A_UINT16            listenInterval; /* interval value in TU */
    SSID                ssid;           /* SSID, variable size */
    RATE_SET            rateSet;        /* rates element */
    EXT_RATE_SET        extRateSet;     /* extended rates element */
} __ATTRIB_PACK WLAN_FRAME_ASSOC_REQ;

/* Associate response frame. Supported rates elements
 * is variable size.
 */
typedef struct wlanFrameAssocResp {
        WLAN_MGT_MAC_HEADER macHeader;  /* Standard mgt header */
        CAP_INFO        capInfo;        /* capability information */
        A_UINT16        statusCode;     /* status code */
        A_UINT16        assocId;        /* association ID */
        RATE_SET        rateSet;        /* rates element */
        EXT_RATE_SET    extRateSet;     /* extended rates element */
} __ATTRIB_PACK WLAN_FRAME_ASSOC_RESP;


/* Reassociate request frame. SSID and supported rates elements
 * are variable size. Hence, you should compute correct offset
 * to actual rates field. This structure assumes max size ssid
 * field.
 */
typedef struct wlanFrameReassocReq {
    WLAN_MGT_MAC_HEADER macHeader;      /* Standard mgt header */
    CAP_INFO            capInfo;        /* capability information */
    A_UINT16            listenInterval; /* interval value in TU */
    WLAN_MACADDR        curAPAddr;      /* Current AP Address */
    SSID                ssid;           /* SSID, variable size */
    RATE_SET            rateSet;        /* rates element */
    EXT_RATE_SET        extRateSet;     /* extended rates element */
} __ATTRIB_PACK WLAN_FRAME_REASSOC_REQ;

/* Frames for associate and reassociate response are the same */

typedef WLAN_FRAME_ASSOC_RESP   WLAN_FRAME_REASSOC_RESP;

/* Probe request frame. SSID and supported rates elements
 * are variable size. Hence, you should compute correct offset
 * to actual rates field. This structure assumes max size ssid
 * field.
 */
typedef struct wlanFrameProbeReq {
    WLAN_MGT_MAC_HEADER macHeader;      /* Standard mgt header */
    SSID                ssid;           /* SSID, variable size */
    RATE_SET            rateSet;        /* rates element */
    EXT_RATE_SET        extRateSet;     /* extended rates element */
} __ATTRIB_PACK WLAN_FRAME_PROBE_REQ;

/*
 * The probe response frame is variable length. First 5 fields are
 * always present, but the information elements, i.e. sets
 * of different parameters are present only when the frame
 * is generated by that type of AP. These sets can be variable
 * size. We just declare 'buffer' field as a place holder. The
 * algorithms should look at the first byte, i.e. element ID,
 * then parse rest of the element and look for the next one.
 */

typedef struct wlanFrameProbeResp {
    WLAN_MGT_MAC_HEADER macHeader;      /* Standard mgt header */
    WLAN_TIMESTAMP      timestamp;      /* 64 bit timestamp */
    A_UINT16            beaconInterval; /* Beacon interval in TU */
    CAP_INFO            capInfo;        /* AP capability info set */
    A_UCHAR             buffer[2];      /* Generic buffer. Variable size */
                                        /* data follows */
} __ATTRIB_PACK WLAN_FRAME_PROBE_RESP;

/* Two authentication algorithms are currently defined */
/* Use them in the field algNo of authentication frames */

#define AUTH_OPEN_SYSTEM        (A_UINT16)0     /* Open systems, no encryption */
#define AUTH_SHARED_KEY         (A_UINT16)1     /* Shared key, use WEP */
#define AUTH_SHARED_KEY_CHLG_SIZE       128     /* Section 8.1.2.2, 128 byte challenge */
#define AUTH_LEAP                       0x80
                                                /* text for shared key authentication */
/*
 * Authentication frames
 */

/*
 * Structure for #1 and #4 frames, no encryption fields.
 */

typedef struct wlanFrameAuth {
    WLAN_MGT_MAC_HEADER macHeader;      /* Standard mgt header */
    A_UINT16            algNo;          /* Algorithm number */
    A_UINT16            transSeqNo;     /* Authentication transaction */
                                        /* sequence number */
    A_UINT16            statusCode;     /* Status (result) code */
} __ATTRIB_PACK WLAN_FRAME_AUTH;

/*
 * Structure for #2 frame, challenge text, but no encryption or IV
 */

typedef struct wlanFrameAuthChlg {
        WLAN_MGT_MAC_HEADER macHeader;  /* Standard mgt header */
        A_UINT16            algNo;      /* Algorithm number */
        A_UINT16            transSeqNo; /* Authentication transaction */
                                        /* sequence number */
        A_UINT16            statusCode; /* Status (result) code */
        CHLG_TEXT           challenge;  /* Challenge text for #3 frame */
} __ATTRIB_PACK WLAN_FRAME_AUTH_CHLG;

#define GET_AUTHFRAME2_SIZE(_pChlgTxt) (                    \
        sizeof(WLAN_FRAME_AUTH) +                           \
        INFO_ELEMENT_SIZE(*(_pChlgTxt))                     \
        )                            
/*
 * Structure for #3 frame, with challenge and iv/icv fields.
 */

typedef struct wlanFrameAuthEncrypt {
    WLAN_MGT_MAC_HEADER macHeader;      /* Standard mgt header */
    A_UINT32            iv;             /* IV for encryption */
    A_UINT16            algNo;          /* Algorithm number */
    A_UINT16            transSeqNo;     /* Authentication transaction */
                                        /* sequence number */
    A_UINT16            statusCode;     /* Status (result) code */
    CHLG_TEXT           challenge;      /* Challenge text for #3 frame */
} __ATTRIB_PACK WLAN_FRAME_AUTH_ENCRYPT;

#define GET_AUTHFRAME3_SIZE(_pChlgTxt) (                    \
        sizeof(WLAN_FRAME_AUTH) +                           \
        WEP_IV_FIELD_SIZE       +                           \
        INFO_ELEMENT_SIZE(*(_pChlgTxt))                     \
        )                            

/* Deauthentication frame */

typedef struct wlanFrameDeauth {
    WLAN_MGT_MAC_HEADER macHeader;      /* Standard mgt header */
    A_UINT16            reasonCode;     /* Reason for action */
} __ATTRIB_PACK WLAN_FRAME_DEAUTH;

/* Management Notification Frame for WME. */
typedef struct wlanFrameWmeMgtNotif {
        WLAN_MGT_MAC_HEADER macHeader;    /* Standard frame header */
        A_UINT8         catCode;          /* category code */
        A_UINT8         actionCode;       /* action code */
        A_UINT8         dialogToken;      /* dialog token */
        A_UINT8         statusCode;       /* status code */
        A_UCHAR         buffer[2];        /* Generic buffer. Variable size */
                                          /* data follows */
} __ATTRIB_PACK WLAN_FRAME_WME_MGT_NOTIF;

/* Many frame types to avoid most casts */
typedef union wlanFrameUnion {
    void                            *ptr;
    A_UCHAR                         *byte;
    A_UINT32                        *word;
    WLAN_FRAME_HEADER               *header;
    WLAN_DATA_MAC_HEADER3           *header3;
    WLAN_FRAME_3_DATA_ENCRYPT       *header3Iv;
    WLAN_FRAME_3_DATA_ENCRYPT_EXTIV *header3ExtIv;
    WLAN_FRAME_DATA_ENCRYPT         *header4Iv;
    WLAN_FRAME_DATA_ENCRYPT_EXTIV   *header4ExtIv;
    WLAN_QOS_DATA_MAC_HEADER3       *qosnull;
    WLAN_QOS_DATA_MAC_HEADER4       *qosnull4;
    WLAN_FRAME_PSPOLL               *psPoll;
    WLAN_FRAME_CFEND                *cfEnd;
    WLAN_FRAME_CFENDACK             *cfEndAck;
    WLAN_FRAME_ASSOC_REQ            *assoc;
    WLAN_FRAME_ASSOC_RESP           *assocResp;
    WLAN_FRAME_DISASSOC             *disAssoc;
    WLAN_FRAME_REASSOC_REQ          *reAssoc;
    WLAN_FRAME_REASSOC_RESP         *reAssocResp;
    WLAN_FRAME_PROBE_REQ            *probe;
    WLAN_FRAME_PROBE_RESP           *probeResp;
    WLAN_FRAME_AUTH                 *auth;
    WLAN_FRAME_AUTH_CHLG            *authChal;
    WLAN_FRAME_AUTH_ENCRYPT         *authChalIv;
    WLAN_FRAME_DEAUTH               *deAuth;
    WLAN_FRAME_BEACON               *beacon;
    WLAN_MGT_MAC_HEADER             *mgtHeader;
    LAN_FRAME_HEADER                *lanHeader;
    LAN_LLC_FRAME_HEADER            *lanllcHeader;
    LLC_SNAP_HEADER                 *llcSnapHeader;
    WLAN_FRAME_WME_MGT_NOTIF        *wmeMgtNotif;
} __ATTRIB_PACK WLAN_FRAME_UNION;

/* This stuff is used when we want a simple layer-3 visibility */
struct ip {
#ifdef ARCH_BIG_ENDIAN
    A_UINT32    ip_v:4,                     /* version */
                ip_hl:4,            /* header length */
#else
    A_UINT32    ip_hl:4,                /* header length */
                ip_v:4,                 /* version */
#endif
                ip_tos:8,               /* type of service */
                ip_len:16;              /* total length */
    A_UINT16    ip_id;                  /* identification */
    A_INT16     ip_off;                 /* fragment offset field */
#define IP_DF 0x4000                    /* dont fragment flag */
#define IP_MF 0x2000                    /* more fragments flag */
#define IP_OFFMASK 0x1fff               /* mask for fragmenting bits */
    A_UINT8     ip_ttl;                 /* time to live */
    A_UINT8     ip_p;                   /* protocol */
    A_UINT16    ip_sum;                        /* checksum */
    A_UINT32    ip_src, ip_dst;  /* source and dest address */
} __ATTRIB_PACK;

/*
 * Protocols
 */
#if 0
#define IPPROTO_IP              0               /* dummy for IP */
#define IPPROTO_ICMP            1               /* control message protocol */
#define IPPROTO_IGMP            2               /* group mgmt protocol */
#endif
#define IPPROTO_GGP             3               /* gateway^2 (deprecated) */
#if 0
#define IPPROTO_TCP             6               /* tcp */
#define IPPROTO_UDP             17              /* user datagram protocol */
#define IPPROTO_IDP             22              /* xns idp */
#define IPPROTO_RAW             255             /* raw IP packet */
#define IPPROTO_MAX             256
#endif

#define IPPORT_BOOTPS           67
#define IPPORT_BOOTPC           68

#define BOOTREQUEST             1
#define BOOTREPLY               2

struct udphdr {
    A_UINT16        uh_sport;     /* source port */
    A_UINT16        uh_dport;     /* destination port */
    A_INT16         uh_ulen;      /* udp length */
    A_UINT16        uh_sum;       /* udp checksum */
} __ATTRIB_PACK;

struct dhcphdr {
    A_UINT8       op;             /* packet type */
    A_UINT8       htype;          /* Link-level interface address type */
    A_UINT8       hlen;           /* Link-level interface address length */
    A_UINT8       hops;           /* Hops through DHCP relay agents */
    A_UINT32      xid;            /* transaction ID */
    A_UINT16      secs;           /* seconds since lease negotiation started */
    A_UINT16      flags;
    A_UINT32      ciaddr;         /* Client's current IP address */
    A_UINT32      yiaddr;         /* Client's assigned IP address */
    A_UINT32      siaddr;         /* Address of (tftp) server */
    A_UINT32      giaddr;         /* Address of relay agent */
    A_UINT8       chaddr[16];     /* Client's hardware address */
    A_UINT8       sname[64];      /* Host name of DHCP server */
    A_UINT8       file[128];      /* File name of boot image */
    A_UINT8       options[1];     /* DHCP message options */
} __ATTRIB_PACK;

/*
 * DSCP code points
 */
#define DSCP_NETWORK_CONTROL    0x30        /* maps to AC3 (voip, highest priority) */
#define DSCP_GUARANTEED         0x28        /* maps to AC2 (video) */
#define DSCP_CONTROLLED_LOAD    0x18        /* maps to AC1 (best effort) */
#define DSCP_OTHER              0           /* maps to AC0 (background, worst effort) */

#if defined(WIN32) || defined(WIN64)
#pragma pack (pop)
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCwlanprotoh */

