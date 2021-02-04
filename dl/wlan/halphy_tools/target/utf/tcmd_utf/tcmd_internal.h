#ifndef __TCMD_INTERNAL__
#define __TCMD_INTERNAL__

#ifndef ATH_TXQ_SETUP
#define ATH_TXQ_SETUP(sc, i)    ((sc)->sc_txqsetup & (1<<i))
#endif

#define WALTEST_BE_WRITE32(_ptr, _x)      do {      \
    *(_ptr)++ = ((_x) >> 24) & 0xFF;                \
    *(_ptr)++ = ((_x) >> 16) & 0xFF;                \
    *(_ptr)++ = ((_x) >>  8) & 0xFF;                \
    *(_ptr)++ = ((_x) >>  0) & 0xFF;                \
} while(0)

#define WALTEST_BE_READ32(_ptr)     \
    ((_ptr += 4),                   \
    ((_ptr)[-4 + 0] << 24) |                 \
    ((_ptr)[-4 + 1] << 16) |                 \
    ((_ptr)[-4 + 2] <<  8) |                 \
    ((_ptr)[-4 + 3] <<  0))

#define NUM_TEST_PKTS  4
#define PKT_SEG0_LEN    128
#define PKT_SEG1_LEN    4096

#if defined(A_SIMOS)
#define WALTEST_TX_LOC_CNT  ( 30)
#else
#define WALTEST_TX_LOC_CNT   (1 << 30)
#endif

/* Common patterns used for checking TX and RX */
#define WALTEST_PKT_ID_LEN (20)
#define WALTEST_PKT_PATTERN (0x55)
#define WALTEST_PKT_TRAILER_LEN (16)
#define WALTEST_PKT_TRAILER_PATTERN 0xDEBAC7E5
//#define PERE_SW_WALTEST_ENABLE_ENCRYPTION 1

#define VLAN_ETHTYPE (0x8100)
#define STT0_ETHTYPE (0x8137)
#define STT1_ETHTYPE (0x80F3)

/* maximum number of AST peer to test with */
#define WALTEST_AST_MAX_PEER 32

//#define WALTEST_USE_NONQOS

#define IV_HEADER_LEN	4
#define EXTRA_IV_HEADER_LEN	4
#define CCMP_HEADER_LEN	8
#define GCMP_HEADER_LEN	8

enum WALTEST_ID {
    WALTEST_ID_INVALID = 0x0,
    WALTEST_ID_TX_TEST,
    WALTEST_ID_RX_TEST,
    WALTEST_ID_SWBA_TEST,
    WALTEST_ID_AST_TEST,
    WALTEST_ID_DEV_TEST,
    WALTEST_ID_PAUSE_TEST,
    WALTEST_ID_AST_TX_TEST,
    WALTEST_ID_AST_RX_TEST,
    WALTEST_ID_CHANNEL_CHANGE_TEST,
    WALTEST_ID_BSSID_FILTER_TX_TEST,
    WALTEST_ID_BSSID_FILTER_RX_TEST,
    WALTEST_ID_PSTA_TX_TEST,
    WALTEST_ID_PSTA_RX_TEST,
};

enum {
    WALTEST_RX_MODE_RAW =0,
    WALTEST_RX_MODE_DECAP,
};

enum {
    WALTEST_RX_DECAP_TYPE_ETH = 0,
    WALTEST_RX_DECAP_TYPE_NWIFI,
};

enum {
    WALTEST_TX_RAW =0,
    WALTEST_TX_DIX,
    WALTEST_TX_DOT3,
    WALTEST_TX_NWIFI,
};

/* waltest associated monitor mode declarations*/
enum {
    WALTEST_MON_FRAME_TYPE,
    WALTEST_MON_FRAME_SUBTYPE = 3,
    WALTEST_MON_ALWAYS_DIR = 8,
    WALTEST_MON_ALWAYS_OTHER = 9,
    WALTEST_MON_ALWAYS_UNICAST= 10,
    WALTEST_MON_ALWAYS_BROADCAST = 11,
    WALTEST_MON_NO_WEP = 12,
    WALTEST_MON_NO_FRAG = 13,
    WALTEST_MON_NO_WDS = 14,
    WALTEST_MON_ALLOW_BCAST_WDS = 15,
    WALTEST_MON_FC_DS = 16,
    WALTEST_MON_AMSDU_SAME_DA_SA = 19,
    WALTEST_MON_NO_AMSDU = 20,
    WALTEST_MON_NO_DIR_AMSDU = 21,
    WALTEST_MON_TWO_AMSDU_SUBF = 22,
    WALTEST_MON_FIX_AMSDU_SUBF_LEN=23,
    WALTEST_MON_WILDCARD_BSSID = 24,
    WALTEST_MON_NO_CTRL_FRM = 28,
};

#define WALTEST_MON_GET_FRM_TYPE(mode) ((mode) & 0x7)

#define WALTEST_MON_GET_FRM_SUBTYPE(mode) ( \
        ((mode) >> WALTEST_MON_FRAME_SUBTYPE) & 0x1f)

#define WALTEST_MON_IS_ALWAYS_DIR(mode) ( \
        ((mode) & (1 << WALTEST_MON_ALWAYS_DIR)))

#define WALTEST_MON_IS_ALWAYS_OTHER(mode) ( \
        ((mode) & (1 << WALTEST_MON_ALWAYS_OTHER)))

#define WALTEST_MON_IS_ALWAYS_UNICAST(mode) ( \
	((mode) & (1 << WALTEST_MON_ALWAYS_UNICAST)))

#define WALTEST_MON_IS_ALWAYS_BCAST(mode) ( \
	((mode) & (1 << WALTEST_MON_ALWAYS_BROADCAST)))

#define WALTEST_MON_GET_FC_DS(mode) ( \
        ((mode) >> WALTEST_MON_FC_DS) & 0x7)

#define WALTEST_MON_IS_NO_CTRL_FRM(mode) ((mode) & \
         (1<< WALTEST_MON_NO_CTRL_FRM))

#define WALTEST_MON_IS_NO_WEP(mode) ((mode) & (1 << WALTEST_MON_NO_WEP))
#define WALTEST_MON_IS_NO_FRAG(mode) ((mode) & (1 << WALTEST_MON_NO_FRAG))
#define WALTEST_MON_IS_NO_WDS(mode) ((mode) & (1 << WALTEST_MON_NO_WDS))
#define WALTEST_MON_IS_BCAST_WDS(mode) ((mode) & \
        (1 << WALTEST_MON_ALLOW_BCAST_WDS))

#define WALTEST_MON_IS_NO_AMSDU(mode) ((mode) & (1 << WALTEST_MON_NO_AMSDU))
#define WALTEST_MON_IS_NO_DIR_AMSDU(mode) ((mode) & \
        (1 << WALTEST_MON_NO_DIR_AMSDU))

#define WALTEST_MON_IS_TWO_AMSDU_SUBF(mode) ((mode) & \
        (1 << WALTEST_MON_TWO_AMSDU_SUBF))

#define WALTEST_MON_IS_FIX_AMSDU_SUBF_LEN(mode) ((mode) & \
        (1 << WALTEST_MON_FIX_AMSDU_SUBF_LEN))

#define WALTEST_MON_IS_AMSDU_SAME_DA_SA(mode) ((mode) & \
        (1 << WALTEST_MON_AMSDU_SAME_DA_SA))

#define WALTEST_MON_IS_WILDCARD_BSSID(mode) ((mode) & \
        (1 << WALTEST_MON_WILDCARD_BSSID))

/* TX-RX shared stuff */
extern unsigned char SA_ADDR[6]; 
extern unsigned char DA_ADDR[6];
extern unsigned char BSS_ADDR[6];
extern unsigned char BCAST_ADDR[6];
extern unsigned char WDS_DA_ADDR[6];
#endif

