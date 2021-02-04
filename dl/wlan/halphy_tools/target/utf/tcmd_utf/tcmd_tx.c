#include <wal.h>
#include <ar_wal.h>
#include <wal_peer.h>
#include "tcmd_internal.h"
#include "tcmdHostInternal.h"
#include "ar_wal_tx_internal.h"
#include "tcmd_tx.h"
#include "tcmd_rx.h"
#include <tcmd_api.h>

#include <if_athvar.h>
#include <wmi_tcmd.h>
#include <if_split.h>

#if (WIFI_IP_CODE < WIFI_IP_VER(2,0))
#if defined(PERE_SW_WAR_WALTEST_FAKE_MAC_ADDRS)
#include <hw/mac_dma_reg.h>
#include <hw/mac_pcu_reg.h>
#endif
#define WALTEST_FDP_SIZE    (8)

#if defined(AR9888_VER2)
#include <hw/bb_reg_map.h>
#endif

#include "hw/mac_descriptors/series_bw.h"
#include "hw/mac_descriptors/tx_ppdu_start.h"
#include "hw/mac_descriptors/try_status.h"
#include "hw/mac_descriptors/try_list.h"
#include "hw/mac_descriptors/ppdu_status.h"
#include "hw/mac_descriptors/tx_ppdu_end.h"
#else
/* WIFI 2.0 add on */
#include <extra/hw/map_pcu_reg.h>
#include <datastruct/msdu_link_ext.h>
#define WALTEST_FDP_SIZE    (NUM_OF_DWORDS_MSDU_LINK_EXT)
#endif

#ifdef A_SIMOS
#include <stdio.h>  /* snprintf */
#include <stdlib.h> /* rand */
#endif


#define WALTEST_FDP_MAGIC_PATTERN 0xF1F0
#define WALTEST_TX_SSN_OFFSET (0)//(4085)
extern TCMD_CONT_TX tx_tcmdParms;
extern A_BOOL g_xtal_cal_flag;
#if 0
struct waltest_ctxt {
    wal_pdev_t *pdev;
    wal_vdev_t *vdev;
    wal_peer_t *peer;
    wal_peer_t *bss_peer;
    A_UINT32 data_pkt_comp[NUM_TIDS];
    A_UINT32 curr_pkt_indx[NUM_TIDS];
    A_UINT32 bufs_in_use[NUM_TIDS][(PKTS_PER_TID / 32)];
    A_UINT32 num_mgmt_outstand;
    A_UINT32 total_mgmt_pkts;
    A_UINT32 presend_notifications;
    A_UINT32 presend_comp_requests;
    A_UINT32 presend_comp_notifications;
    A_UINT32 good_pkts;
    void *rc_dbg;
    A_BOOL setup_peers; /* setup default peers(bss peer and one destination peer) */
    void *cb_ctxt;
    waltest_tx_data_frame_completion_cb data_frame_comp_cb;
    waltest_tx_local_frame_completion_cb local_frame_comp_cb;
};
#endif
struct frame_enacap_config g_encap_cfg;
#ifdef FIXME_PKTINFO
struct tx_ppdu_start ppdu_start;
struct tx_ppdu_end ppdu_end;
#endif

struct waltest_ctxt g_waltest_ctxt;

extern struct waltest_rx_config g_waltest_rx_config;
extern A_UINT32 g_dbg_no_sw_retry;
extern A_UINT32 g_dbg_aggr_ok;
extern A_UINT8 _g_rc_non_data_bw;
extern unsigned char BCAST_ADDR[6];


#if (WIFI_IP_CODE >= WIFI_IP_VER(2,0))
extern A_UINT32 g_delay_sched;
#endif

/* memTable is a memory pool that pre-assigned for MDK
 * here we are re-using this memory pool for tcmd's pkt_buffer_seg1
 * as MDK and tcmd will not be running simultaneous */
#ifndef SIMUIO
extern A_UCHAR memTable[0][0];

/* Each packet has two segments */
A_UINT32 fdp_buffer[NUM_TIDS][PKTS_PER_TID][WALTEST_FDP_SIZE];
A_UINT8 pkt_buffer_seg0[NUM_TIDS][PKTS_PER_TID][PKT_SEG0_LEN];
A_UINT8 *pkt_buffer_seg1[NUM_TEST_PKTS];
A_UINT8 pkt_buffer_trailer[WALTEST_PKT_TRAILER_LEN];
A_UINT16 fdp_comp_msgs[PKTS_PER_TID];
#else
extern void* uio_dma_alloc(A_UINT32 size);
A_UINT32 (*fdp_buffer)[PKTS_PER_TID][WALTEST_FDP_SIZE];
A_UINT8 (*pkt_buffer_seg0)[PKTS_PER_TID][PKT_SEG0_LEN];
A_UINT8 *pkt_buffer_seg1[NUM_TEST_PKTS];
A_UINT8 *pkt_buffer_trailer;
A_UINT16 *fdp_comp_msgs;
#endif

#if (WIFI_IP_CODE >= WIFI_IP_VER(2,0)) && defined(CONFIG_TXBF_SUPPORT)
A_UINT32 g_txbf_enable = 0;
#endif
A_UINT32 g_waltest_tx_pktlen = 64;

A_UINT32 g_waltest_tx_amsdu_max_size = 4000;

A_UINT32 g_waltest_tx_80211_frag = 0;
A_UINT8  g_frag_no = 1;

void waltest_tx_setup(struct waltest_ctxt *ctxt);
#if defined(AR9888_VER2)
void waltest_tx_send_cts(wal_pdev_t *pdev);
#endif

#if !defined(A_SIMOS) && !defined(TEST_FRAMEWORK)
/* Move to utils probably ? */
static A_UINT32 rand()
{
    /* Park Miller rand */

    static A_UINT32 next_rand = 1111;

    next_rand = (next_rand * (16807));
    next_rand &= 0x7fffffff;

    return next_rand;

}
#endif

struct waltest_ctxt *waltest_tx_attach(wal_pdev_t *pdev, struct tx_setup_config *cfg,
                              void *cb_ctxt, waltest_tx_data_frame_completion_cb data_frame_comp_cb,
                              waltest_tx_local_frame_completion_cb local_frame_comp_cb)
{
    struct waltest_ctxt *ctxt = &g_waltest_ctxt;
    wal_vdev_t *vdev;

    /* free peer and vdev */
    if (tcmd_state.tcmdTxGo == 0 && tcmd_state.tcmdRxGo == 0) {
        if (g_waltest_rx_config.peer) {
            wal_peer_free(g_waltest_rx_config.peer);
            g_waltest_ctxt.peer =  NULL;
            g_waltest_rx_config.peer = NULL;
        }
        if (g_waltest_rx_config.vdev) {
            wal_vdev_detach(g_waltest_rx_config.vdev);
            g_waltest_ctxt.vdev  = NULL;
            g_waltest_rx_config.vdev = NULL;
        }
    }
    A_MEMZERO(ctxt, sizeof(*ctxt));

    ctxt->cb_ctxt = cb_ctxt;
    ctxt->data_frame_comp_cb = data_frame_comp_cb;
    ctxt->local_frame_comp_cb = local_frame_comp_cb;
    ctxt->setup_peers = cfg->setup_peers;
    if (g_waltest_rx_config.vdev)
    {
	vdev = g_waltest_rx_config.vdev;
	ctxt->vdev =  g_waltest_rx_config.vdev;
	ctxt->bss_peer = g_waltest_rx_config.peer;
    }
    else
       vdev = cfg->vdev;
      /* Setup one AP vdev */
    if (!vdev) {
        A_UINT8 i;

        for (i = 0; i < WAL_MAC_ADDR_LEN; i++)
            pdev->mac_mask[i] = ~g_encap_cfg.bss_addr[i];
        wal_vdev_attach(pdev, &vdev, g_encap_cfg.bss_addr, WAL_VDEV_TYPE_AP, 3, 0);

	if (vdev == NULL) {
		A_PRINTF("tx vdev allocation failed \n");
		return ctxt;
	}
        whalSetRecvAddrMask(pdev->mac_mask);
        whalSetOperatingMode(WHAL_M_AP);
    }

    ctxt->vdev = vdev;
    ctxt->pdev = wal_vdev_get_pdev(vdev);
   /*
    if (g_waltest_rx_config.peer)
	    g_waltest_ctxt.peer = g_waltest_rx_config.peer;
    */

#ifdef DEBUG_WAL_RC_STATS
    memset(_rc_tx_stats, 0, sizeof(_rc_tx_stats));
    ctxt->rc_dbg = _rc_tx_stats;
#endif

    g_encap_cfg.pkt_len = g_waltest_tx_pktlen;
    g_encap_cfg.vdev = vdev;
    g_encap_cfg.pattern = 0;
    g_encap_cfg.pattern_length = 0;
    g_encap_cfg.pattern_data = NULL;
    g_encap_cfg.is_qos = TRUE;

    /* Ref: htt_tgt_hif_svc.c L871*/
#if (WIFI_IP_CODE >= WIFI_IP_VER(2,0))
    /* Assign NUM_TEST_PKTS for Host data xmit
     * Local assginment set locally in wal attach
     * NOTE: valid host banks 14 (reserve 1 for local, 1 for self gen)
     */
    {
            wal_dev_desc_bank_cfg_t bank_cfg;
            A_UINT32 base = (A_UINT32) &fdp_buffer;
            bank_cfg.num_banks = 1; //bank0 for host, bank1 for local
            bank_cfg.desc_size = (NUM_OF_DWORDS_MSDU_LINK_EXT << 2);
            bank_cfg.bank_base_address[0] = A_DMA_ADDR(base);
            bank_cfg.bank_min_id[0] = 0;
            bank_cfg.bank_max_id[0] = 256 - 1;
            bank_cfg.swap[0] = 0;
            wal_pdev_desc_bank_cfg(pdev, &bank_cfg);
    }
#endif

    return ctxt;
}

wal_vdev_t *waltest_tx_get_vdev(struct waltest_ctxt *ctxt)
{
    return ctxt->vdev;
}


//#define WALTEST_USE_NONQOS
int
ieee80211_hdr_encap(
        char *buf_in, struct frame_enacap_config *cfg,
        A_UINT8 tid_num, A_UINT32 pkt_num, A_UINT32 disable_qos )
{
    struct ieee80211_frame *wh = (struct ieee80211_frame*)buf_in;
    char *buf;
    struct ieee80211_qoscntl *qos = NULL;

    A_UINT16 seq_no = 100; // Fake sequence number for raw packet
    A_UINT16 seq_ctrl;

	seq_no = WALTEST_TX_SSN_OFFSET + pkt_num;
	seq_no &= 4095;


    wh->i_fc[0] = IEEE80211_FC0_VERSION_0
        | IEEE80211_FC0_TYPE_DATA;
    wh->i_fc[1] = IEEE80211_FC1_DIR_FROMDS;
    if (cfg->is_broadcast)
        A_MEMCPY(wh->i_addr1, BCAST_ADDR, 6);
    else
        A_MEMCPY(wh->i_addr1, cfg->da_addr, 6);
    A_MEMCPY(wh->i_addr2, cfg->bss_addr, 6);
    A_MEMCPY(wh->i_addr3, cfg->sa_addr, 6);

    seq_ctrl = A_HTOLE16(seq_no++ << IEEE80211_SEQ_SEQ_SHIFT);
    wh->i_seq[0] = seq_ctrl & 0xFF;
    wh->i_seq[1] = seq_ctrl >> 8;

    if (g_waltest_tx_80211_frag) {
        wh->i_fc[1] |= IEEE80211_FC1_MORE_FRAG;
        /* set monotonously incrementing(+1) frag number */
        wh->i_seq[0] |= (g_frag_no++ & IEEE80211_SEQ_FRAG_MASK);
    }

    buf = (char*)&wh[1];

    if (!disable_qos) {
        qos = (struct ieee80211_qoscntl*)buf;

        wh->i_fc[0] |= IEEE80211_FC0_SUBTYPE_QOS;
        qos->i_qos[0] = tid_num & IEEE80211_QOS_TID;
        qos->i_qos[1] = 0xEF;
        buf += 2;
    }

    return (buf - buf_in);
}

void waltest_init_pkts(struct frame_enacap_config *cfg)
{
    A_UINT32 index, i, patternLength, pktSize, dataBodyLength, seed;
    A_UINT16 next_seed;
    A_UINT8 PN_STAGE[3] = {7, 9, 15};
    A_UINT8 fixPat[3] = {0x0, 0xFF, 0xAA};
    A_UINT8 Pattern = cfg->pattern;
    A_UINT32 PatLength = cfg->pattern_length;
    A_UCHAR *pPatData = cfg->pattern_data;
    A_UINT8 *pPkt;

    pktSize = 0; //avoid KLockwork error
    for (i = 0; i < cfg->num_desc; i++)
    {
        pPkt = pkt_buffer_seg1[i];
        pktSize = 0;
        dataBodyLength = cfg->pkt_len;
        index = (Pattern >= PN7_PATTERN) ? (Pattern - PN7_PATTERN) : Pattern;
        if (index >= sizeof(PN_STAGE))
        {
        	index = 0;
        }
        switch (Pattern)
        {
            case USER_DEFINED_PATTERN:
                index = 0;
                while (dataBodyLength)
                {
                    patternLength = (dataBodyLength < PatLength ? dataBodyLength : PatLength);
                    A_MEMCPY(pPkt, &pPatData[index], patternLength);
                    pPkt += patternLength;
                    index = (index + patternLength) < PatLength ? (index + patternLength) : 0;
                    dataBodyLength -= patternLength;
                    pktSize += patternLength;
                }
                break;

            case ZEROES_PATTERN:
            case ONES_PATTERN:
            case REPEATING_10:
                A_MEMSET(pPkt, fixPat[index], dataBodyLength);
                pktSize += dataBodyLength;
                break;

            case PN7_PATTERN:
            case PN9_PATTERN:
                patternLength =  1 << (PN_STAGE[index] - 3);
                seed = 0xffffffff >> (32 - PN_STAGE[index]);
                if (dataBodyLength <= patternLength)
                    dataBodyLength = patternLength;
                else
                    dataBodyLength -= (dataBodyLength % patternLength);
                while (dataBodyLength)
                {
                    init_pn(seed, PN_STAGE[index], pPkt, 1 << PN_STAGE[index]);
                    if (dataBodyLength > patternLength)
                        dataBodyLength -= patternLength;
                    else
                        dataBodyLength = 0;
                    pPkt += patternLength;
                    pktSize += patternLength;
                }
                break;

            case PN15_PATTERN:
            default:
                patternLength = 1 << (PN_STAGE[index] -3);/*Total 4096 bytes*/
                patternLength = patternLength >> 2;/*1024 bytes per frame*/
                if (i == 0)
                    seed = 0xffffffff >> (32 - PN_STAGE[index]);
                else
                    seed = (A_UINT32) next_seed;
                init_pn(seed, PN_STAGE[index], pPkt, ((1 << PN_STAGE[index]) >> 2) + 16);
                pPkt += patternLength;
                pktSize += patternLength;
                next_seed = (A_UINT16)(*pPkt);/*The last 16 bits is the seed
                                                for next*/
                break;
        }
    }

    cfg->pkt_len = pktSize;

    for (index = 0; index < WALTEST_PKT_TRAILER_LEN; index++) {
        pkt_buffer_trailer[index] =
            WALTEST_PKT_TRAILER_PATTERN >> ((index & 0x3) << 3);
    }

}

void waltest_free_pkt_buf(struct waltest_ctxt *ctxt, A_UINT8 tid, A_UINT32 indx)
{
    A_UINT32 *buf_bmap = &ctxt->bufs_in_use[tid][0];
    A_UINT32 offset;

    /* Clear the set bit */
    offset = indx / 32;
    buf_bmap += offset;

    indx &= 31;

    A_ASSERT(*buf_bmap & ( 1 << indx));
    *buf_bmap &= ~(1 << indx);
}

int waltest_alloc_pkt_buf(struct waltest_ctxt *ctxt, A_UINT8 tid)
{
    A_UINT32 *buf_bmap;
    A_UINT32 offset, i, val, loop;

    if(tid >= NUM_TIDS)
    {
    	A_ASSERT(FALSE);
        return -1;
    }

    buf_bmap = &ctxt->bufs_in_use[tid][0];
    loop = PKTS_PER_TID / 32;

    /* Find an unset bit */
    for (offset = 0; offset < loop; offset++, buf_bmap++){
        val = *buf_bmap;
        for (i = 0; i < 32; i++) {
            if (!(val & (1 << i))) {
            	val |= (1 << i);
            	*buf_bmap = val;
                return (offset * 32) + i;
            }
        }
    }

    return -1;
}

void waltest_setup_frameq_pkts(
    struct waltest_ctxt *ctxt, A_UINT8 tid, A_UINT32 num_pkts,
    struct frame_enacap_config *cfg)
{

    A_UINT32 pkt_indx =0, pkt_num, enque_len, seg0_len;
    A_UINT16 cookie;
    A_UINT32 hdr_len;
//    A_UINT32 l3l4_len;
    A_UINT32 pkt_len, flags = 0, nonqos;
    char *data_start;
    A_UINT32 *fdp, ix;
    A_UINT8 *addr;
    A_UINT32 ast_flags;
    wal_tid_t *ptid;

    if(tid >= NUM_TIDS)
        return;

    if (cfg->num_aggr)
    {
        num_pkts = cfg->num_aggr;
        ix = tid;
        ptid = ar_wal_ast_search(ctxt->pdev, cfg->da_addr, &ctxt->peer, &ix, &ast_flags);
        if (ptid == NULL)
        {
            A_ASSERT(0);
            return;
        }
        SET_FLG(ptid->tid_flags, WAL_TX_TID_PAUSED);
    }

    for (; num_pkts--; ctxt->curr_pkt_indx[tid]++) {
        void *dma_addr;

        pkt_indx = waltest_alloc_pkt_buf(ctxt, tid);

        if (pkt_indx == -1) {
            A_ASSERT(0);
            return;
        }

        pkt_num = ctxt->curr_pkt_indx[tid];

        /* "Encap" the packets: could be optimized and done once but its
         * just simulator
         */
        data_start = (char*)&pkt_buffer_seg0[tid][pkt_indx][0];

        if (cfg->pkt_len == 0) {
            pkt_len = A_MAX(120, rand() & ((2<<11) - 1));
            pkt_len = A_MIN(pkt_len, 1400);
        } else {
            pkt_len = cfg->pkt_len;
        }

        nonqos = cfg->is_qos ? 0 : 1;

        hdr_len = ieee80211_hdr_encap(data_start, cfg, tid, pkt_num, nonqos);
        flags |= WAL_DE_FR_ENCAP_RAW;
        /* FIXME: Temp DE code does not handle 4address qos */
        flags |= WAL_DE_TID_VALID;


        /* Add IV Pad if required. TODO: Is IV pad required to be added in
         * length ?
         */
        seg0_len = hdr_len;
        data_start += hdr_len;

        /* Setup the FragDescPtr - Ptr - Len pairs */
        fdp = &fdp_buffer[tid][pkt_indx][0];
#if (WIFI_IP_CODE >= WIFI_IP_VER(2,0))
       A_MEMZERO(fdp, WALTEST_FDP_SIZE * sizeof(A_UINT32));
       /** Skip 4 dwords for TSO fields.*/
       fdp = (A_UINT32 *)((A_UINT32)fdp + MSDU_LINK_EXT_4_BUF0_PTR_31_0_OFFSET);
       //fdp += WO(MSDU_LINK_EXT_4_BUF0_PTR_31_0);
#endif
        enque_len = 0;

        /* Warning catcher */
        if (1) {
             addr = &pkt_buffer_seg0[tid][pkt_indx][0];
        }

        *fdp++  = A_DMA_ADDR((A_UINT32)addr);
#if (WIFI_IP_CODE < WIFI_IP_VER(2,0))
        *fdp++  = seg0_len;
#else
        *fdp++  = SM(seg0_len, MSDU_LINK_EXT_5_BUF0_LEN);
#endif
        enque_len += seg0_len;

        /* Warning catcher */
        if (cfg->num_aggr) {
            addr = pkt_buffer_seg1[0];
        }
        else if (pkt_indx < NUM_TEST_PKTS) {
            addr = pkt_buffer_seg1[pkt_indx];
        }
        else {
            A_ASSERT(0);
            return;
        }


        *fdp++  = A_DMA_ADDR((A_UINT32)addr);
#if (WIFI_IP_CODE < WIFI_IP_VER(2,0))
        *fdp++  = pkt_len;
#else
        *fdp++  = SM(pkt_len, MSDU_LINK_EXT_7_BUF1_LEN);
#endif
        enque_len += pkt_len;

        /* FDP Termination */
        *fdp++  = (A_UINT32)NULL;
#if (WIFI_IP_CODE >= WIFI_IP_VER(2,0))
        /* WIFI 2.0 needs 48-bit NULL termination */
        *fdp++  = (A_UINT32)NULL;
#endif

        /* Special marker for waltest */
        *fdp++  = (WALTEST_FDP_MAGIC_PATTERN << 16) | pkt_indx;

        dma_addr = (void *)A_DMA_ADDR(&fdp_buffer[tid][pkt_indx][0]);

        /* The tid is encoded in the cookie */
        cookie = pkt_indx + (tid * PKTS_PER_TID);
 #if defined(CONFIG_MU_MIMO_FTM_SUPPORT)
        ar_wal_tx_de_input(cfg->vdev,
                (char*)&pkt_buffer_seg0[tid][pkt_indx][0],
                    dma_addr,
                    enque_len,
                    cookie,  /* Ctxt is pkt-indx which comes back */
                    nonqos ? WAL_NON_QOS_TID : tid,
                    flags, 0xffff);
#else
        ar_wal_tx_de_input(cfg->vdev,
                (char*)&pkt_buffer_seg0[tid][pkt_indx][0],
                    dma_addr,
                    enque_len,
                    cookie,  /* Ctxt is pkt-indx which comes back */
                    nonqos ? WAL_NON_QOS_TID : tid,
                    flags, 0);
#endif

        if (cfg->num_aggr)
        {
            if (num_pkts == 1)
                UNSET_FLG(ptid->tid_flags, WAL_TX_TID_PAUSED);
        }
    }

    return;
}

int waltest_tx_comp_buf_get(void *test_ctxt, A_UINT16 **frag_desc_list_buf, int num_elems)
{

    *frag_desc_list_buf = (A_UINT16 *)&fdp_comp_msgs[0];

    /* Return some random number to test completion logic */
    return (sizeof(fdp_comp_msgs) / sizeof(fdp_comp_msgs[0]));
    //return A_MIN(12, PKTS_PER_TID - ctxt->fdp_complete_msgs);
}

void waltest_proc_tx_desc(WHAL_TX_DESC_STATUS *sw_stat)
{
#ifdef FIXME_PKTINFO
    A_UINT32 sbw_valid_bitmap, sbw_data_fail_cnts, sbw_rts_fail_cnts,
        num_series_tried, sbw_indx, data_fail_cnt, rts_fail_cnt, tries;
    struct ppdu_status *ats = &ppdu_end.stat;

    /* Update software copies of the HW status */
    sw_stat->tsTstamp = (A_UINT32)(ats->wb_timestamp);
    sw_stat->tsSeqnum = ppdu_start.start_seq_num;

    /* Setup the flags */
    sw_stat->tsFlags =
               (ats->tsf_time_filtered  ? WHAL_TXS_FLAG_TSF_TIME_FILTERED : 0)
            |  (ats->wb_time_filtered   ? WHAL_TXS_FLAG_WB_TIME_FILTERED  : 0)
            |  (ats->agg_underrun       ? WHAL_TXS_FLAG_AGG_UNDERRUN      : 0)
            |  (ats->first_pkt_underrun ? WHAL_TXS_FLAG_FIRST_PKT_UNDERRUN: 0)
#if 0
            /* FIXME: Why was this removed ???? */
            |  (ats->sw_filtered        ? WHAL_TXS_FLAG_SW_FILTERED       : 0)
#endif
            |  (ats->qcu_paused         ? WHAL_TXS_FLAG_QCU_PAUSED        : 0);

    sw_stat->tsRssi = ats->ack_rssi_ave;
    sw_stat->tsStatus = WHAL_TXERR_NONE;

    sw_stat->tsLongRetry = 0;
    sw_stat->tsShortRetry = 0;
    if (!ats->tx_ok)
    {
        if (ats->tsf_time_filtered  || ats->wb_time_filtered || ats->adhoc_beacon_filtered)
            sw_stat->tsStatus = WHAL_TXERR_FILT;
        else if (ats->agg_underrun || ats->first_pkt_underrun)
            sw_stat->tsStatus = WHAL_TXERR_FIFO;
        else /* Only other type of error */
            sw_stat->tsStatus = WHAL_TXERR_XRETRY;
    }


    sbw_valid_bitmap =
        *((A_UINT32*)&ppdu_start + WO(TX_PPDU_START_20_VALID_S0_BW20)) >>
            TX_PPDU_START_20_VALID_S0_BW20_LSB;

    sbw_data_fail_cnts =
        *((A_UINT32*)ats + WO(PPDU_STATUS_5_DATA_TRIES_CNT_S0_BW20));

    sbw_rts_fail_cnts =
        *((A_UINT32*)ats + WO(PPDU_STATUS_6_RTS_TRIES_CNT_S0_BW20));


    /* Series1 used if tot_tries is greater than series 0 tries */
    num_series_tried = (ats->total_tries > ppdu_start.tries_s0) ? 2 : 1;


    for (sbw_indx = 0; sbw_indx < (num_series_tried * NUM_DYN_BW_MAX); sbw_indx++)
    {
        /* Skip unprogrammed series-bw */
        if (!(sbw_valid_bitmap & (1 << sbw_indx)))
            continue;

        data_fail_cnt = (sbw_data_fail_cnts >> (sbw_indx << 2)) & 0xf;
        rts_fail_cnt  = (sbw_rts_fail_cnts  >> (sbw_indx << 2)) & 0xf;

        tries = data_fail_cnt + rts_fail_cnt;
        if (!tries) /* with dynamic bw validate if highest bw is not used */
        {
            continue;
        }

        sw_stat->tsLongRetry += data_fail_cnt;
        sw_stat->tsShortRetry += rts_fail_cnt;
    } /* Series-bw iteration */
#endif

    return;
}


void waltest_tx_comp_indicate(void *test_ctxt, A_UINT16 *frag_desc_list_buf, int num_elems,
                int tid_num, A_UINT32 msg_type)
{
    A_UINT32 indx, cookie=0;
    A_UINT32 num_elems_per_tid[NUM_TIDS];
    struct waltest_ctxt *ctxt = (struct waltest_ctxt *)test_ctxt;

    /* Note:The tid_num returned by tx send is useless. Do NOT interpret */

    /* Derive the actual tid num from the pkt index */
    A_MEMSET(num_elems_per_tid, 0 , sizeof(num_elems_per_tid));


    for (indx = 0; indx < num_elems; indx++) {
        cookie = frag_desc_list_buf[indx];

        tid_num = cookie / PKTS_PER_TID;
        /* Offset in the per tid pool */
        cookie &= (PKTS_PER_TID - 1);

        A_ASSERT(tid_num < NUM_TIDS);

        waltest_free_pkt_buf(ctxt, tid_num, cookie);

        num_elems_per_tid[tid_num]++;
    }

    for (tid_num = 0; tid_num < NUM_TIDS; tid_num++) {
        if (num_elems_per_tid[tid_num]) {

            if (ctxt->data_frame_comp_cb) {
                if (cookie == (g_encap_cfg.num_aggr ? g_encap_cfg.num_aggr - 1 : g_encap_cfg.num_desc - 1)) {
#ifdef FIXME_PKTINFO
                    struct ppdu_status *hw_status = &(ppdu_end.stat);
#endif
                    WHAL_TX_DESC_STATUS sw_status;

                    waltest_proc_tx_desc(&sw_status);

#ifdef FIXME_PKTINFO
                    if (ctxt->data_frame_comp_cb(ctxt->cb_ctxt, cookie + 1, ctxt->good_pkts, hw_status, &sw_status) > 0)
#else
                    ctxt->good_pkts++;
                    if (ctxt->data_frame_comp_cb(ctxt->cb_ctxt, cookie + 1, ctxt->good_pkts, NULL, &sw_status) > 0)
#endif
                        waltest_setup_frameq_pkts(ctxt, WAL_DEFAULT_TID, g_encap_cfg.num_desc, &g_encap_cfg);
                    ctxt->good_pkts = 0;
                }
            } else {
                waltest_setup_frameq_pkts(ctxt, tid_num,
                                          num_elems_per_tid[tid_num], &g_encap_cfg);
            }

            g_waltest_ctxt.data_pkt_comp[tid_num]
                +=  num_elems_per_tid[tid_num];
        }
    }

    return;
}

void waltest_tid_create_handler(wal_peer_t *peer, wal_peer_event *event)
{
    wal_tid_t *ptid;
    A_UINT32 tid_num;

    //A_PRINTF("TID %d created\n", event->u.event_tid_created.tid);
    tid_num = event->u.event_tid_created.tid;
    if (tid_num < NUM_TIDS) {
        ptid = ar_wal_get_tid(peer, tid_num);
    }

    return;

}

void waltest_send_complete_handler(wal_peer_t *peer, wal_peer_event *event)
{
    if (event->u.send_complete.tx_status == WAL_FRAME_TX_DROP) {
        A_PRINTF("Presend DROP\n");
    }
    g_waltest_ctxt.presend_comp_notifications++;
}

void waltest_presend_handler(wal_peer_t *peer, wal_peer_event *event)
{
    wal_peer_event_tx_presend *presend_event;
    static int presend_notif_cnt = 0;

    presend_event = &event->u.tx_frame_presend_event;

    /* Odd tids and every 1024 packets */
    if (1 && (0 == (presend_notif_cnt & 1023))) {
        presend_event->need_notification = TRUE;
        g_waltest_ctxt.presend_comp_requests++;
    }
    presend_notif_cnt++;

    g_waltest_ctxt.presend_notifications++;
}

void waltest_setup_data_rate(struct frame_enacap_config *cfg)
{
    A_UINT32 dataRate = cfg->data_rate;
    A_UINT8 mcs = 0, nss = 0, pream = 0;
    A_UINT8 bw = 0, rc = 0;

    if (dataRate <= 3 || (dataRate >= 150 && dataRate <=152) ) // CCK
    //if (dataRate <= 3 || dataRate >= 150) // CCK
    {
        pream = 0x1;

        switch (dataRate)
        {
            case 0: // 1 Mb
                mcs = 3;
                break;

            case 1: // 2 Mb
                mcs = 2;
                break;

            case 2: // 5.5 Mb
                mcs = 1;
                break;

            case 3: // 11 Mb
                mcs = 0;
                break;

            case 150: // 2 Mb (S)
                mcs = 6;
                break;

            case 151: // 5.5 Mb (S)
                mcs = 5;
                break;

            case 152: // 11 Mb (S)
                mcs = 4;
                break;
        }
	if ((tx_tcmdParms.wlanMode == TCMD_WLAN_MODE_HT40PLUS ||
	     tx_tcmdParms.wlanMode == TCMD_WLAN_MODE_HT40MINUS ||
	     tx_tcmdParms.wlanMode == TCMD_WLAN_MODE_VHT40MINUS ||
	     tx_tcmdParms.wlanMode == TCMD_WLAN_MODE_VHT40PLUS) &&
	     (tx_tcmdParms.freq < 4800)) {
		     bw = 1;
	    }
    }
    else if (dataRate >= 4 && dataRate <= 11) // OFDM
    {
        pream = 0x0;

        switch (dataRate)
        {
            case 4: // 6 Mb
                mcs = 3;
                break;

            case 5: // 9 Mb
                mcs = 7;
                break;

            case 6: // 12 Mb
                mcs = 2;
                break;

            case 7: // 18 Mb
                mcs = 6;
                break;

            case 8: // 24 Mb
                mcs = 1;
                break;

            case 9: // 36 Mb
                mcs = 5;
                break;

            case 10: // 48 Mb
                mcs = 0;
                break;

            case 11: // 54 Mb
                mcs = 4;
                break;
        }
	//support non-ht duplicate for both 2G and 5G boards now
	if ((tx_tcmdParms.wlanMode == TCMD_WLAN_MODE_HT40PLUS ||
	     tx_tcmdParms.wlanMode == TCMD_WLAN_MODE_HT40MINUS ||
	     tx_tcmdParms.wlanMode == TCMD_WLAN_MODE_VHT40MINUS ||
	     tx_tcmdParms.wlanMode == TCMD_WLAN_MODE_VHT40PLUS)) {
		bw = 1;
	}
	//support non-ht duplicate for 5G boards only
	if ((tx_tcmdParms.wlanMode == TCMD_WLAN_MODE_VHT80_0 ||
	    tx_tcmdParms.wlanMode == TCMD_WLAN_MODE_VHT80_1 ||
	    tx_tcmdParms.wlanMode == TCMD_WLAN_MODE_VHT80_2 ||
	    tx_tcmdParms.wlanMode == TCMD_WLAN_MODE_VHT80_3) && (tx_tcmdParms.freq >= 4800)) {
		pream = 0x0;
		bw = 2;
	}
    }
    else if (dataRate >= 12 && dataRate <= 35) // HT20
    {
        dataRate -= 12;

        pream = 0x2;
        nss = dataRate / 8;
        mcs = dataRate % 8;
    }
    else if (dataRate >= 36 && dataRate <= 59) // HT40
    {
        dataRate -= 36;

        pream = 0x2;
        nss = dataRate / 8;
        mcs = dataRate % 8;

        bw = 1;
    }
    else if (dataRate >= 60 && dataRate <= 89) // VHT20
    {
        dataRate -= 60;

        pream = 0x3;
        nss = dataRate / 10;
        mcs = dataRate % 10;
    }
    else if (dataRate >= 153 && dataRate <= 162) // VHT20
    {
        dataRate -= 153;

        pream = 0x3;
        nss = 3;
        mcs = dataRate % 10;
    }
    else if (dataRate >= 90 && dataRate <= 119) // VHT40
    {
        dataRate -= 90;

        pream = 0x3;
        nss = dataRate / 10;
        mcs = dataRate % 10;

        bw = 1;
    }
    else if (dataRate >= 163 && dataRate <= 172) // VHT40
    {
        dataRate -= 163;

        pream = 0x3;
        nss = 3;
        mcs = dataRate % 10;

        bw = 1;
    }
    else if (dataRate >= 120 && dataRate <= 149) // VHT80
    {
        dataRate -= 120;

        pream = 0x3;
        nss = dataRate / 10;
        mcs = dataRate % 10;

        bw = 2;
    }
    else if (dataRate >= 173 && dataRate <= 182) // VHT80
    {
        dataRate -= 173;

        pream = 0x3;
        nss = 3;
        mcs = dataRate % 10;

        bw = 2;
    }
    else if (dataRate >= ATH_RATE_VHT160_NSS1_MCS0 && dataRate <= ATH_RATE_VHT160_NSS2_MCS9) // VHT160 VHT80p80
    {
        dataRate -= 183;

        pream = 0x3;
        nss = dataRate / 10;
        mcs = dataRate % 10;

        bw = 3;
    }
    else if (dataRate >= ATH_RATE_HT20_MCS24 && dataRate <= ATH_RATE_HT20_MCS31) // HT20 4x4
    {
        dataRate -= 203;

        pream = 0x2;
        nss = 3;
        mcs = dataRate % 8;

        bw = 0;
    }
    else if (dataRate >= ATH_RATE_HT40_MCS24 && dataRate <= ATH_RATE_HT40_MCS31) // HT40 4x4
    {
        dataRate -= 211;

        pream = 0x2;
        nss = 3;
        mcs = dataRate % 8;

        bw = 1;
    }

    if (pream == 0x3)
    {
        /* For VHT rates AMPDU max bytes is 1M */
        wal_peer_set_param(g_waltest_ctxt.peer, WAL_PEER_PARAM_AMPDU_MAXBYTES, 7);
    }
    else
    {
        /* For non-VHT rates AMPDU max bytes is 64K */
        wal_peer_set_param(g_waltest_ctxt.peer, WAL_PEER_PARAM_AMPDU_MAXBYTES, 3);
    }

    rc = (pream << 6) | (nss << 4) | mcs;

    wal_rc_set_vdev_bw(cfg->vdev, bw);
    wal_rc_set_vdev_data_rc(cfg->vdev, rc);
    wal_rc_set_vdev_mcast_data_rc(cfg->vdev, rc);
    wal_rc_set_vdev_bcast_data_rc(cfg->vdev, rc);
    _g_rc_non_data_bw = bw;

    return;
}

#ifdef FIXME_PKTINFO
static A_INT32 waltest_getbuf(void *cookie, A_UINT8 **buf,
        wal_pkt_info_type type, A_UINT16 reg_size, A_UINT32 flags)
{
    if (!CHK_FLG(flags, WAL_PKT_INFO_FLG_TX_REMOTE))
        return 0;

    if (type == WAL_PKT_INFO_TYPE_TX_PPDU_CTRL)
    {
        *buf = (A_UINT8 *) &ppdu_start;
        return sizeof(ppdu_start);
    }
    else if (type == WAL_PKT_INFO_TYPE_TX_PPDU_STAT)
    {
        *buf = (A_UINT8 *) &ppdu_end;
        return sizeof(ppdu_end);
    }
    else
        return 0;
}

static void waltest_sendbuf(void *cookie, A_UINT8 *buf,
        wal_pkt_info_type type, A_UINT16 fill_size, A_UINT32 flags)
{
    if (!CHK_FLG(flags, WAL_PKT_INFO_FLG_TX_REMOTE))
        return;

    if (type == WAL_PKT_INFO_TYPE_TX_PPDU_CTRL)
    {
//        A_PRINTF("ampdu = %d\n", ppdu_start.ampdu);
    }
    else
    {
        struct waltest_ctxt *ctxt = (struct waltest_ctxt *)cookie;

        if (ppdu_end.stat.tx_ok)
            ctxt->good_pkts++;
    }
    return;
}
#endif

void waltest_local_buf_free(struct ath_buf *abf)
{
    /* Nothing to do */

    return;
}


void waltest_tx_setup(struct waltest_ctxt *ctxt)
{
    wal_peer_t *peer;
    wal_tid_t *ptid;
    A_UINT32 types = 0, flags = 0;

    /* Register for all TID creation event */
    wal_peer_register_event_handler(NULL, ctxt->vdev,
            waltest_tid_create_handler, WAL_PEER_EVENT_TID_CREATED);

    /* Register for Presend for all Pkts */
    wal_install_presend_handler(ctxt->pdev, waltest_presend_handler);

    /* Register for send completion */
    wal_peer_register_event_handler(NULL, ctxt->vdev,
            waltest_send_complete_handler, WAL_PEER_EVENT_SEND_COMPLETE);

    types |= WAL_PKT_INFO_TYPE_TX_PPDU_CTRL;
    types |= WAL_PKT_INFO_TYPE_TX_PPDU_STAT;
    SET_FLG(flags, WAL_PKT_INFO_FLG_TX_REMOTE);
#ifdef FIXME_PKTINFO
    wal_phy_dev_register_pkt_info_handler(ctxt->pdev,
        waltest_getbuf, waltest_sendbuf, types, flags, ctxt);
#endif

    /*
     * It was assumed that the wal_peer_alloc is alloting 2 tids namely mgmt tid and default tid (0)
     * The utf is using the TID 0 for data transfer.
     */
    ctxt->setup_peers = TRUE;
    if (ctxt->setup_peers) {
	if (ctxt->bss_peer == NULL)
	    wal_peer_alloc(ctxt->vdev, &ctxt->bss_peer, g_encap_cfg.bss_addr, g_encap_cfg.bss_addr, NULL, 1);

        if(ctxt->peer == NULL)
	    wal_peer_alloc(ctxt->vdev, &ctxt->peer, g_encap_cfg.da_addr, g_encap_cfg.bss_addr, NULL, 0);

	if(ctxt->peer)
	    wal_peer_set_param(ctxt->peer, WAL_PEER_PARAM_CONNECTION_STATE, \
                                               WAL_PEER_STATE_CONNECTED_AUTHORIZED);
	else {
        A_PRINTF("ctxt->peer allocation failed \n");
	    return;
	}
        /*
         * HACK, force the tid que to map to HW BE queue. wal peer by default maps the all the data tid queues
         * CABQ and frames from CABQ only go out if beacons are enabled. here we do not enable beacons.
         */
	if(ctxt->bss_peer)
            ar_wal_peer_alloc_tid(ctxt->bss_peer, WAL_NON_QOS_TID, &ptid);
	else {
        A_PRINTF("bss_peer allocation failed \n");
        return;
	}
        if (!ptid) {
            A_PRINTF("nonqos data tid allocation failed \n");
            return;
        }
        /*for both non qos data and management tids, unregister from CABQ and re register with BE queue */
        tx_sched_trigger_conn(ptid, SCHED_TRIGGER(SCHED_EVT_UNREGISTER));
        ptid->wal_txq_id = WAL_TXQ_ID_WMM_BE;
        tx_sched_trigger_conn(ptid, SCHED_TRIGGER(SCHED_EVT_REGISTER));

        wal_rc_set_vdev_rts_cts(ctxt->vdev, 0);

        peer = ctxt->peer;
        wal_peer_set_param(peer, WAL_PEER_PARAM_AMPDU_DENSITY, 7);
        if (g_waltest_tx_amsdu_max_size) {
            wal_peer_set_param(peer, WAL_PEER_PARAM_AMSDU_MAX_SIZE, g_waltest_tx_amsdu_max_size);
        }
	SET_FLG(peer->peer_flags, WAL_PEER_ALLOW_DATA);

#if (WIFI_IP_CODE >= WIFI_IP_VER(2,0))
        wal_tx_wmm_ac_params wmm_param;
        int ac;
		
		A_MEMZERO(&wmm_param, sizeof(wal_tx_wmm_ac_params));
	/* Setting the noack policy */
        for (ac = 0; ac < WMM_NUM_AC; ac++) {
                wmm_param.no_ack = 1;
                wal_tx_send_update_wmm_params(ctxt->pdev, ac, &wmm_param);
        }

	/* Disabling short packet aggregation */
	/* This need to be set without this there won't be any data transmission */
	g_delay_sched = 0;
#endif /* only for IP 2.0 */
    }

    /* Register the Completion handlers simulating the HTT */
    tx_send_install_txcomp_buf_req(ctxt->pdev,
                                waltest_tx_comp_buf_get, (void*)ctxt);

    tx_send_install_txcomp_indicate(ctxt->pdev,
                                waltest_tx_comp_indicate, (void*)ctxt);

    wal_local_frame_register_ath_buf_free(ctxt->pdev, waltest_local_buf_free);
    wal_tx_send_setup_block_ack(ctxt->peer, WAL_DEFAULT_TID, TX_SEND_FAKE_AGGR_PARAM_SSN, TX_SEND_FAKE_AGGR_PARAM_WIN_SZ, TRUE, FALSE);

    return;
}

void waltest_tx_start(void)
{
    struct waltest_ctxt *ctxt = &g_waltest_ctxt;
    wal_pkt_type vap_pkttype;
    A_UINT8 tx_chain_masks[4] = { 0xF, 0xF, 0xF, 0xF }, i;

    /* Setup the VAP remote data input type */
    vap_pkttype = WAL_PKT_TYPE_RAW;
    wal_vdev_set_input_data_pkt_type(ctxt->vdev, vap_pkttype);

    /* For waltest put HW in AP-STA mode and fake association by setting up
     * hardcoded STA / AP / BSSID address
     */
#if defined(PERE_SW_WAR_WALTEST_FAKE_MAC_ADDRS)
    {
        A_UCHAR sa_addr[6], bss_addr[6];
        A_UINT32 addr;

        A_MEMCPY(sa_addr, g_encap_cfg.sa_addr, 6);
        A_MEMCPY(bss_addr, g_encap_cfg.bss_addr, 6);

#if 0
        addr = A_HTOLE32(*(A_UINT32*)&sa_addr[0]);
        A_WMAC_REG_WRITE(MAC_PCU_STA_ADDR_L32_ADDRESS, addr);
        addr = A_HTOLE16(*(A_UINT16*)&sa_addr[4]);
        addr |= MAC_PCU_STA_ADDR_U16_PRESERVE_SEQNUM_MASK;
        A_WMAC_REG_WRITE(MAC_PCU_STA_ADDR_U16_ADDRESS, addr | (1 << 16));
#endif

        addr = A_HTOLE32(*(A_UINT32*)&bss_addr[0]);
        A_WMAC_REG_WRITE(MAC_PCU_BSSID_L32_ADDRESS, addr);
        addr = A_HTOLE16(*(A_UINT16*)&bss_addr[4]);
        A_WMAC_REG_WRITE(MAC_PCU_BSSID_U16_ADDRESS, addr | (1 << 16));

#if 0
        /* Fake the INI ACK timeout settings */
        A_WMAC_REG_WRITE(MAC_PCU_ACK_CTS_TIMEOUT_ADDRESS, 0x10f810f8);

        /* Fake the INI triglevel settings */
        addr = A_WMAC_REG_READ(MAC_DMA_TXCFG_ADDRESS);
        addr &= ~MAC_DMA_TXCFG_TRIGLVL_MASK;
        addr |= MAC_DMA_TXCFG_TRIGLVL_SET(0x20);
        A_WMAC_REG_WRITE(MAC_DMA_TXCFG_ADDRESS, addr);
#endif

#if (WIFI_IP_CODE < WIFI_IP_VER(2,0))
        /* Turn on interrupts */
        A_WMAC_REG_WRITE(MAC_DMA_GLOBAL_IER_ADDRESS, MAC_DMA_GLOBAL_IER_ENABLE_MASK);
#endif
    }
#endif

    /* need to set the following global var in order to transmit the data,
       need to fix it. */
    g_dbg_no_sw_retry = 1;

    waltest_init_pkts(&g_encap_cfg);
    waltest_setup_data_rate(&g_encap_cfg);

    if (g_encap_cfg.num_aggr)
    {
        g_encap_cfg.is_qos = TRUE;
        g_dbg_aggr_ok = 1;
    }
    else
    {
        g_dbg_aggr_ok = 0;
    }

    ctxt->peer->qos_enabled = g_encap_cfg.is_qos ? 1 : 0;

    for (i = 0; i < 4; i++)
        tx_chain_masks[i] = g_encap_cfg.chain_mask;
    wal_rc_set_pdev_tx_chainmasks(ctxt->vdev->pdev, 0xF, tx_chain_masks);

    ctxt->data_pkt_comp[0] = 0;
    /* Insert bunch of Pkts into the FrameQ */

#if defined(AR9888_VER2)
    if (PHY_BB_GEN_CONTROLS_DYN_BW_GET(A_WMAC_REG_READ(PHY_BB_GEN_CONTROLS_ADDRESS)) == 2)
    {
        /* WAR: 5G Tx carrier leadage, send self-CTS dummy frame in HT40 mode to latch some CL correction values. */
        A_WMAC_REG_WRITE(PHY_BB_GEN_CONTROLS_ADDRESS,
           (A_WMAC_REG_READ(PHY_BB_GEN_CONTROLS_ADDRESS) & ~PHY_BB_GEN_CONTROLS_DYN_BW_MASK) |
           ((1 << PHY_BB_GEN_CONTROLS_DYN_BW_LSB) & PHY_BB_GEN_CONTROLS_DYN_BW_MASK));
        waltest_tx_send_cts(ctxt->vdev->pdev);
    }
    else
#endif
        waltest_setup_frameq_pkts(ctxt, WAL_DEFAULT_TID, g_encap_cfg.num_desc, &g_encap_cfg);

    return;
}

void setup_pkt_buffer_tx()
{
    A_UINT8 *txbufSpace;
    A_UINT32 i;

#ifndef SIMUIO
    txbufSpace = (A_UINT8 *)memTable;
#else
    fdp_buffer = uio_dma_alloc(NUM_TIDS*PKTS_PER_TID*WALTEST_FDP_SIZE*sizeof(A_UINT32));
    pkt_buffer_seg0 = uio_dma_alloc(NUM_TIDS*PKTS_PER_TID*PKT_SEG0_LEN);
    pkt_buffer_trailer = uio_dma_alloc(WALTEST_PKT_TRAILER_LEN);
    fdp_comp_msgs = uio_dma_alloc(PKTS_PER_TID*sizeof(A_UINT16));
    txbufSpace = uio_dma_alloc(NUM_TEST_PKTS*PKT_SEG1_LEN);
#endif

    // Setup pkt_buffer_seg1 addrs
    for (i = 0; i < NUM_TEST_PKTS; i++) {
        pkt_buffer_seg1[i] = txbufSpace + i * PKT_SEG1_LEN;
    }

}

void waltest_tx(wal_pdev_t *pdev, void *cb_ctxt, waltest_tx_data_frame_completion_cb frame_comp_cb,
                waltest_tx_local_frame_completion_cb local_frame_comp_cb)
{
    struct tx_setup_config cfg;

    cfg.vdev = NULL;
    waltest_tx_attach(pdev, &cfg, cb_ctxt, frame_comp_cb, local_frame_comp_cb);
    cfg.setup_peers = TRUE;
    waltest_tx_setup(&g_waltest_ctxt);

    g_waltest_rx_config.vdev = g_waltest_ctxt.vdev;
    g_waltest_rx_config.peer = g_waltest_ctxt.bss_peer;
}

void waltest_tx_detach(wal_pdev_t *pdev)
{
    struct waltest_ctxt *ctxt = &g_waltest_ctxt;

    if (ctxt->bss_peer)
    {
        wal_peer_free(ctxt->bss_peer);
        ctxt->bss_peer = NULL;
    }

    /* free peer and vdev */
#if defined(FPGA)
    if(ctxt->vdev != NULL && tcmd_state.tcmdTxGo != 0 && g_waltest_rx_config.vdev != NULL)
#else
	if(ctxt->vdev != NULL && tcmd_state.tcmdTxGo != 0 && tcmd_state.tcmdRxGo == 2 && g_waltest_rx_config.vdev != NULL)
#endif
    {
        if (ctxt->peer)
            wal_peer_free(ctxt->peer);
        if (ctxt->vdev)
	        wal_vdev_detach(ctxt->vdev);
        ctxt->peer = NULL;
	    ctxt->vdev = NULL;
	    g_waltest_rx_config.vdev = NULL;
 	    g_waltest_rx_config.peer = NULL;
	    tcmd_state.tcmdRxGo = 0;
	    //tcmd_state.tcmdTxGo = 0;
    }
    tcmd_state.tcmdTxGo = 0;
//    start_tx_status = 0;
    g_xtal_cal_flag = FALSE;
    whalEnableAni(TRUE);
}

#if defined(AR9888_VER2)
struct ath_buf  waltest_tx_ath_bufs[1];
struct txbuf    waltest_tx_ath_ctsbufs[1];

void waltest_local_comp_indicate(void *cb_ctxt, wal_peer_t *peer,
                                 struct ath_buf *abf, WAL_FRAME_COMPLETION_STATUS tx_status,
                                 wal_tx_comp_desc_t *p_tx_comp_desc)
{
    struct waltest_ctxt *ctxt = &g_waltest_ctxt;

    A_WMAC_REG_WRITE(PHY_BB_GEN_CONTROLS_ADDRESS,
       (A_WMAC_REG_READ(PHY_BB_GEN_CONTROLS_ADDRESS) & ~PHY_BB_GEN_CONTROLS_DYN_BW_MASK) |
       ((2 << PHY_BB_GEN_CONTROLS_DYN_BW_LSB) & PHY_BB_GEN_CONTROLS_DYN_BW_MASK));
    waltest_setup_frameq_pkts(ctxt, 0, g_encap_cfg.num_desc, &g_encap_cfg);
    return;
}

void waltest_tx_send_cts(wal_pdev_t *pdev)
{
    struct waltest_ctxt *ctxt = &g_waltest_ctxt;
    struct ath_buf *abf = NULL;
    struct txbuf *bf = NULL;
    struct ieee80211_frame_cts *wh_cts;
    A_UINT16 *durptr;
    wal_completion_args_t comp_args = { ctxt, waltest_local_comp_indicate };

    abf = &waltest_tx_ath_bufs[0];
    abf->bf_b.wlanBuf.tx = &waltest_tx_ath_ctsbufs[0];

    bf = abf->bf_b.wlanBuf.tx;
    WLAN_BUF_START(bf) = bf->bfData.databuf;
    WLAN_BUF_LENGTH(bf) = 14;

    wh_cts = (struct ieee80211_frame_cts *)WLAN_BUF_START(bf);
    durptr = (A_UINT16 *)&wh_cts->i_dur[0];
    *durptr = 0;

    wh_cts->i_fc[0] = IEEE80211_FC0_VERSION_0 | IEEE80211_FC0_TYPE_CTL | IEEE80211_FC0_SUBTYPE_CTS;
    wh_cts->i_fc[1] = 0;

    A_MEMCPY(wh_cts->i_ra, g_encap_cfg.sa_addr, 6);

    wal_local_frame_send(pdev, ctxt->peer, WAL_MGMT_TID, abf, 0, &comp_args);
    return;
}
#endif
