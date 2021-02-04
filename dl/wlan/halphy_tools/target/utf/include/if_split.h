/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/*
 * Copyright (c) 2004-2005 Atheros Communications Inc.
 * All rights reserved.
 * $ATH_LICENSE_TARGET_C$
 */
#ifndef _IF_INIT_H_
#define _IF_INIT_H_


#ifdef WLAN_DEBUG
int ath_debug = 0x0;

#define IFF_DUMPPKTS(dev, _m) \
    ((ath_debug & _m) || ieee80211_msg_dumppkts(dev->sc_ic))
static  void ath_printrxbuf(wlan_vdev_t *dev, struct ath_buf *bf, int);
static  void ath_printtxbuf(wlan_vdev_t *dev, struct ath_buf *bf, int);
enum {
    ATH_DEBUG_XMIT      = 0x00000001,   /* basic xmit operation */
    ATH_DEBUG_XMIT_DESC = 0x00000002,   /* xmit descriptors */
    ATH_DEBUG_RECV      = 0x00000004,   /* basic recv operation */
    ATH_DEBUG_RECV_DESC = 0x00000008,   /* recv descriptors */
    ATH_DEBUG_RATE      = 0x00000010,   /* rate control */
    ATH_DEBUG_RESET     = 0x00000020,   /* reset processing */
    ATH_DEBUG_MODE      = 0x00000040,   /* mode init/setup */
    ATH_DEBUG_BEACON    = 0x00000080,   /* beacon handling */
    ATH_DEBUG_WATCHDOG  = 0x00000100,   /* watchdog timeout */
    ATH_DEBUG_INTR      = 0x00001000,   /* ISR */
    ATH_DEBUG_TX_PROC   = 0x00002000,   /* tx ISR proc */
    ATH_DEBUG_RX_PROC   = 0x00004000,   /* rx ISR proc */
    ATH_DEBUG_BEACON_PROC   = 0x00008000,   /* beacon ISR proc */
    ATH_DEBUG_KEYCACHE  = 0x00020000,   /* key cache management */
    ATH_DEBUG_STATE     = 0x00040000,   /* 802.11 state transitions */
    ATH_DEBUG_NODE      = 0x00080000,   /* node management */
    ATH_DEBUG_WMM       = 0x00100000,   /* WMM */
    ATH_DEBUG_FATAL     = 0x80000000,   /* fatal errors */
    ATH_DEBUG_ANY       = 0xffffffff
};
#define DPRINTF(dev, _m, _fmt, ...) do {             \
    if (ath_debug & (_m))                \
        A_PRINTF(_fmt, __VA_ARGS__);          \
} while (0)
#define KEYPRINTF(dev, ix, hk, mac) do {             \
    if (ath_debug & ATH_DEBUG_KEYCACHE)          \
        ath_keyprint(__func__, ix, hk, mac);        \
} while (0)
#else
#define IFF_DUMPPKTS(dev, _m) 0
#define DPRINTF(dev, _m, _fmt, ...)
#define KEYPRINTF(dev, k, ix, mac)
#endif

#ifdef TXRX_PROFILING
enum { 
    HTC_RXREAP = 0,
    WLAN_RXREAP = 1,
    REAP_MAX = 2
};
#endif

typedef struct TCMD_TXRX {
    STAILQ_HEAD(, ath_buf)  sc_rxbuf;       /* low priority receive buffer */
    STAILQ_HEAD(, ath_buf)  sc_rxbuf_hi;    /* high priority receive buffer */
    WHAL_TX_STATUS          *ts_ring;       /* Transmit status ring */
    A_UINT8                 ts_head_idx;    /* Transmit status ring current index*/
    STAILQ_HEAD(, ath_buf)  sc_txbuf;       /* tx buffer queue */
    A_INT32                 sc_txqsetup;    /* h/w queues setup */
    struct ath_txq        * sc_ac2q[WHAL_NUM_TX_QUEUES];
    struct ath_txq          sc_txq[WHAL_NUM_TX_QUEUES];
    A_UINT32                sc_qnum2ac[WHAL_NUM_TX_QUEUES];
} TCMD_TXRX;

extern int
tcmd_attach(wlan_tcmd_dev_t *dev, A_UINT8* macAddr);

extern A_BOOL
ath_get_anacfg_data_immed(wlan_vdev_t *dev, A_UINT8 **ppDataBuf);

extern  int
ath_tx_setup(wlan_tcmd_dev_t *, int, int);

extern void
init_pn(A_UINT32 seed, A_UINT32 seed_len, A_UINT8 * buf, A_UINT32 seq_len);
#endif
