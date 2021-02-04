#include <wal.h>
#include <ar_wal.h>

#include "tcmd_internal.h"
#include "ar_wal_rx_internal.h"

#if (WIFI_IP_CODE < WIFI_IP_VER(2,0))
#if defined(PERE_SW_WAR_WALTEST_FAKE_MAC_ADDRS)
#include <hw/mac_dma_reg.h>
#include <hw/mac_ole_reg.h>
#endif
#include <hw/mac_pcu_reg.h>
#else
#include <extra/hw/map_pcu_reg.h>
#endif

#include "whal_api.h"     /* whalEnableRxRing */
#include "wal_rx_ring.h" /* WAL_RX_RING_REMOTE_STATUS_PKT */
#include "tcmd_tx.h"
#include "ar6000_tcmd.h"
#include <tcmd_api.h>
#include "tcmd_rx.h"

#ifdef SUPPORT_11N
#include "ar6000_internal.h"
#endif

#define WALTEST_RX_HTT_BUFS (NUM_TEST_PKTS)
#define WALTEST_RX_LOC_BUFS (20)
#define WALTEST_RX_BUFSIZE  (PKT_SEG1_LEN)
#define WALTEST_RX_HTT_RING_SIZE (WALTEST_RX_HTT_BUFS)
#define WALTEST_CHATTER_RING_SIZE (WALTEST_RX_HTT_BUFS >> 1)
#define WALTEST_CHATTER_BUFS (WALTEST_RX_HTT_BUFS >> 1)

/* memTable is a memory pool that pre-assigned for MDK
 * here we are re-using this memory pool for tcmd's waltest_rx_htt_bufs
 * as MDK and tcmd will not be running simultaneous */
#ifndef SIMUIO
extern A_UCHAR memTable[0][0];
SRAM_RODATA
struct ath_buf  waltest_ath_bufs[WALTEST_RX_LOC_BUFS];
SRAM_RODATA
struct rxbuf    waltest_rxbufs[WALTEST_RX_LOC_BUFS];
A_UINT8 *waltest_rx_htt_bufs[WALTEST_RX_HTT_BUFS];
A_UINT32 waltest_rx_htt_ring[WALTEST_RX_HTT_BUFS];
#else
extern void* uio_dma_alloc(A_UINT32 size);
struct ath_buf  *waltest_ath_bufs;
struct rxbuf    *waltest_rxbufs;
A_UINT8 *waltest_rx_htt_bufs[WALTEST_RX_HTT_BUFS];
A_UINT32 *waltest_rx_htt_ring;

#endif
A_UINT16 ring_enable_counter = 0;
A_UINT16 ring_disable_local_counter = 0;
A_UINT16 ring_disable_remote_counter = 0;
#if defined(IPQ4019) || defined(QCA9984)
#define RING_EXIT_COUNT 10
#else
#define RING_EXIT_COUNT 300
#endif
extern struct frame_enacap_config g_encap_cfg;
extern A_BOOL g_xtal_cal_flag;

/* for associated monitor mode */
A_UINT32 g_rx_buf_indx = 0;
A_UINT32 g_rate_index = 0;
A_UINT8 *g_rxbufSpace;
A_UINT32 g_rxbufSize;
#if 0
struct waltest_rx_ctxt {
    A_UINT32 rx_htt_pkt_indx;
    void *ring_ctxt;
    A_UINT32 num_recvd_packets;
    A_UINT32 rx_buf_indx;
    A_UINT32 rx_ovfl_amsdu;
    A_UINT32 rx_htt_ring_size;
    A_UINT32 rx_crc_err;
    A_UINT32 rx_pat_err;
    A_UINT32 parse_err_cnt;
    A_UINT32 err_mask;
    A_UINT32 rx_peer_idx_invalid;
    A_UINT32 rx_directed;
    A_UINT32 num_rcvd_nonqos;
    A_UINT32 num_rcvd_qos;
    A_UINT32 num_rcvd_amsdu;
    A_UINT32 num_rcvd_vlan;
    A_UINT32 num_rcvd_msdus;
    A_UINT32 num_rcvd_wds;
    A_UINT32 num_frags_recv;
    A_UINT8 rx_pkt_idx_bitmap[(NUM_TEST_PKTS / 8) + 1];
    A_UINT16 last_rx_seqs[WAL_NON_QOS_TID + 1];
    A_UINT32 mgmt_pkts;
    A_UINT32 mgmt_pkts_with_valid_peer;
    wal_vdev_t *vdev;
    wal_peer_t *peer[WALTEST_AST_MAX_PEER +1 ];
    void *cb_ctxt;
    waltest_rx_data_frame_cb frame_rx_cb;
    waltest_rx_local_frame_cb local_rx_cb;
    wal_key_info_t **peer_rx_key_info; /* AST index to rx key info, setup by test frame work */
    A_UINT32 peer_rx_key_info_len;
};
#endif

struct waltest_rx_ctxt g_waltest_rx_ctxt;
struct waltest_rx_config g_waltest_rx_config = { NULL, NULL };

enum {
    FC_ERR = 0x0001,
    A1_ERR = 0x0002,
    A2_ERR = 0x0004,
    A3_ERR = 0x0008,
    A4_ERR = 0x0010,
    SA_ERR = 0x0020,
    DA_ERR = 0x0040,
    VLAN_PRESENCE_ERR = 0x0080,
    VLAN_TAG_ERR = 0x0100,
    LLC_ERR = 0x0200,
    ETH_ERR = 0x0400,
    SEQ_ERR = 0x0800,
    PKTID_ERR = 0x1000,
    PKTCONT_ERR = 0x2000,
    DIR_ERR = 0x4000,
    SEQ_DUP_ERR = 0x8000,
    /* L3 - l4 stuff */
    FRAG_ERR = 0x10000,
    CSUM_ERR = 0x20000,
    CSUM_OV_ERR = 0x40000,
    CSUM_RX_ERR = 0x80000,
};

typedef struct {
    A_UINT32 valid_peer;
    A_UINT32 d_data;
    A_UINT32 d_group;
    A_UINT32 data;
    A_UINT32 group;
    A_UINT32 ds[16];
    A_UINT32 nds[16];
} RX_Frame_Stats_t;

RX_Frame_Stats_t g_waltest_rx_ds;

void *waltest_rx_ring_setup(wal_pdev_t *pdev, A_UINT32 ring_indx,
         A_UINT32 buffer_size, A_UINT32 headroom_dwords, A_UINT32 max_entries);
void waltest_rx_stack_handler(void *ctxt, wal_peer_t *peer, struct rxbfChain *rx_buf_chain);


void waltest_log_type_subtype(RX_Frame_Stats_t *stats,
            A_UINT8 *pkt, A_UINT32 peer_valid )
{

    struct ieee80211_qosframe *wh = (struct ieee80211_qosframe*)pkt;
    A_UINT32 subtype, dir;
    A_UINT8 bcast_addr[6] = {0xff, 0xff,0xff,0xff, 0xff, 0xff};

    stats->valid_peer += (peer_valid)?1:0;

    /* Get the dir */
    dir = wh->i_fc[1] & IEEE80211_FC1_DIR_MASK;
    subtype = (wh->i_fc[0]  >> 4) & 0xf;

    switch (dir) {
    case IEEE80211_FC1_DIR_NODS:
        if (!A_MEMCMP(wh->i_addr1, bcast_addr, 6)) {
             if (!A_MEMCMP(wh->i_addr3, BSS_ADDR, 6)) {

                 stats->d_group++;
                 stats->ds[subtype]++;
             }
             else {/* non-directed group mgmt frame */
		stats->group++;
                stats->nds[subtype]++;
             }
        } else {/* unicast directed or not */
            if (!A_MEMCMP(wh->i_addr1, BSS_ADDR, 6)) {

                 stats->d_data++;
                 stats->ds[subtype]++;
             }
             else {/* non-directed group mgmt frame */
                stats->data++;
                stats->nds[subtype]++;
             }
        }
        break;
    case IEEE80211_FC1_DIR_DSTODS:
    case IEEE80211_FC1_DIR_FROMDS:
            if (!A_MEMCMP(wh->i_addr1,bcast_addr , 6)) {
                 stats->nds[subtype]++;
                 stats->group++;
            }
             else {/* non-directed group mgmt frame */
                stats->nds[subtype]++;
                stats->data++;
             }

        break;
    case IEEE80211_FC1_DIR_TODS:
        /* only data frame now */
        if (!A_MEMCMP(wh->i_addr1, BSS_ADDR, 6)) {
             if (!A_MEMCMP(wh->i_addr3, bcast_addr, 6)) {

                 stats->d_group++;
                 stats->ds[subtype]++;
             }
             else {/* non-directed group mgmt frame */
                stats->d_data++;
                stats->ds[subtype]++;
             }
        } else {/* un directed data */
            if (!A_MEMCMP(wh->i_addr1,bcast_addr, 6)) {

                 stats->group++;
                 stats->nds[subtype]++;
             }
             else {/* non-directed data frame */
                stats->data++;
                stats->nds[subtype]++;
             }
        }

     }

}

A_BOOL is_promiscous_mode(void)
{
    return ( OS_REG_READ(MAC_PCU_RX_FILTER_ADDRESS) & WHAL_RX_FILTER_PROM );
}

A_UINT32 waltest_check_wifi_header(A_UINT8 *pkt, A_UINT32 *ptr_is_amsdu,
        A_UINT32 *ptr_hdr_len, A_UINT32 nwifi)
{

    struct ieee80211_qosframe_addr4 *wh4 = (struct ieee80211_qosframe_addr4*)pkt;
    struct ieee80211_qosframe *wh = (struct ieee80211_qosframe*)pkt;
    struct ieee80211_qoscntl *qos = NULL;
    A_UINT32 err = 0, hdr_len = 0, dir, is_amsdu = 0, tid_num, seq_num;
    A_UINT32 fragno;
    A_UINT8 bcast_addr[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

    /* Only non-null data here */
    if ((wh->i_fc[0] != 0x88) && (wh->i_fc[0] != 0x08)) {
        err |= FC_ERR;
    }

    /* Base hdr len */
    hdr_len = sizeof(struct ieee80211_frame);

    /* Get the dir */
    dir = wh->i_fc[1] & IEEE80211_FC1_DIR_MASK;

    if (nwifi) {
        goto nwifi_dir_check;
    }

    if (wh->i_fc[0] & IEEE80211_FC0_SUBTYPE_QOS) {

        hdr_len += sizeof(struct ieee80211_qoscntl);

        qos = (struct ieee80211_qoscntl*)
            ((dir == IEEE80211_FC1_DIR_DSTODS) ? wh4->i_qos : wh->i_qos);

        is_amsdu = ((qos->i_qos[0] >> IEEE80211_QOS_AMSDU_S)
                & IEEE80211_QOS_AMSDU);

        tid_num = qos->i_qos[0] & 0x7;
        g_waltest_rx_ctxt.num_rcvd_qos++;
        g_waltest_rx_ctxt.num_rcvd_amsdu += (is_amsdu) ? 1 : 0;
    } else {
        if (!nwifi) { /* Makes no sense for nwifi */
            g_waltest_rx_ctxt.num_rcvd_nonqos++;
        }
        tid_num = WAL_NON_QOS_TID;
    }

nwifi_dir_check:
    if (dir == IEEE80211_FC1_DIR_DSTODS)
        err |= DIR_ERR;

    if(!is_promiscous_mode()) {
        switch (dir) {
            case IEEE80211_FC1_DIR_NODS:
                if (A_MEMCMP(wh->i_addr1, bcast_addr, 6))
                    err |= A_MEMCMP(wh->i_addr1, g_encap_cfg.da_addr, 6) ? A1_ERR : 0;
                break;
            case IEEE80211_FC1_DIR_FROMDS:
                if (A_MEMCMP(wh->i_addr1, bcast_addr, 6))
                    err |= A_MEMCMP(wh->i_addr1, g_encap_cfg.da_addr, 6) ? A1_ERR : 0;
                break;
            case IEEE80211_FC1_DIR_TODS:
                if (A_MEMCMP(wh->i_addr1, bcast_addr, 6))
                    err |= A_MEMCMP(wh->i_addr1, g_encap_cfg.bss_addr, 6) ? A1_ERR : 0;
                err |= A_MEMCMP(wh->i_addr2, g_encap_cfg.sa_addr, 6) ? A2_ERR : 0;
                if (is_amsdu) {
                    err |= A_MEMCMP(wh->i_addr3, g_encap_cfg.bss_addr, 6) ? A3_ERR : 0;
                } else {
                    err |= A_MEMCMP(wh->i_addr3, g_encap_cfg.da_addr, 6) ? A3_ERR : 0;
                }
                break;
            case IEEE80211_FC1_DIR_DSTODS:
                g_waltest_rx_ctxt.num_rcvd_wds++;
                hdr_len += 6;
                err |= A_MEMCMP(wh->i_addr1, g_encap_cfg.da_addr, 6)  ? A1_ERR : 0;
                err |= A_MEMCMP(wh->i_addr2, g_encap_cfg.bss_addr, 6) ? A2_ERR : 0;

                if (is_amsdu) {
                    err |= A_MEMCMP(wh->i_addr3, g_encap_cfg.bss_addr, 6) ? A3_ERR : 0;
                    err |= A_MEMCMP(wh4->i_addr4, g_encap_cfg.bss_addr, 6) ? A4_ERR : 0;
                } else {
                    err |= A_MEMCMP(wh->i_addr3, WDS_DA_ADDR, 6) ? A3_ERR : 0;
                    err |= A_MEMCMP(wh4->i_addr4, g_encap_cfg.sa_addr, 6) ? A4_ERR : 0;
                }
                break;
        }
    }
    if (nwifi) {
        goto nwifi_seq_skipped;
    }

    seq_num = A_HTOLE16(*(A_UINT16*)&wh->i_seq[0]);
    fragno = seq_num & IEEE80211_SEQ_FRAG_MASK;
    seq_num >>= IEEE80211_SEQ_SEQ_SHIFT;
    //A_PRINTF("seq_num = %d\n", seq_num);

    if (wh->i_fc[1] & IEEE80211_FC1_MORE_FRAG) {
        g_waltest_rx_ctxt.num_frags_recv++;
        /* check sequence number and frag number visually, with just a few tx packets
         * both of them should be monotonically increasing(+1) */
//        A_PRINTF_ALWAYS("seq_num %x fragno %x\n", seq_num, fragno);
//        A_PRINTF_ALWAYS("seq[0] %x seq[1] %x\n", wh->i_seq[0], wh->i_seq[1]);
    }

    if (g_waltest_rx_ctxt.last_rx_seqs[tid_num] == 0xFFFF) {
        /* First Time Init */
        g_waltest_rx_ctxt.last_rx_seqs[tid_num] = seq_num;
    } else {
        g_waltest_rx_ctxt.last_rx_seqs[tid_num]++;
        g_waltest_rx_ctxt.last_rx_seqs[tid_num] &= 0xFFF;
    }
    if (seq_num != g_waltest_rx_ctxt.last_rx_seqs[tid_num]) {
        if (seq_num == (g_waltest_rx_ctxt.last_rx_seqs[tid_num] - 1))
            err |= SEQ_DUP_ERR;
        else
            err |= SEQ_ERR;
        g_waltest_rx_ctxt.last_rx_seqs[tid_num] = seq_num;
    }

nwifi_seq_skipped:
    *ptr_is_amsdu = is_amsdu;
    *ptr_hdr_len = hdr_len;
    return err;
}

A_UINT32 waltest_check_eth_hdr(A_UINT8 *pkt, A_UINT32 *is_llc_reqd,
        A_UINT32 *hdr_len)
{
    A_UINT32 err =0;
    A_UINT32 vlantag, typeorlen;
    A_UINT8 *pkt_orig = pkt;

    err |= A_MEMCMP(pkt, DA_ADDR, 6) ? DA_ERR : 0;
    pkt += 6;

    err |= A_MEMCMP(pkt, SA_ADDR, 6) ? SA_ERR : 0;
    pkt += 6;

    typeorlen = A_HTOBE16(*(A_UINT16*)pkt);
    pkt += 2;

    if (typeorlen == VLAN_ETHTYPE) {

        g_waltest_rx_ctxt.num_rcvd_vlan++;

        err |= VLAN_PRESENCE_ERR;

        vlantag = A_HTOBE16(*(A_UINT16*)pkt);
        pkt += 2;

        if (vlantag != 0xABCD) {
            err |= VLAN_TAG_ERR;
        }

        typeorlen = A_HTOBE16(*(A_UINT16*)pkt);
        pkt += 2;
    }

    *is_llc_reqd = (typeorlen >= 0x600) ? 0 : 1;
    *hdr_len = (pkt - pkt_orig);
    err = 0; // skip header checking

    return err;
}

A_UINT32 waltest_get_pkt_id(A_UINT8 *pkt, A_UINT32 *pkt_len, A_UINT32 *pkt_indx, A_UINT32 *num_pkts)
{
    A_UINT32 cnt;

    /* Start pattern */
    for(cnt = 4; cnt; cnt--) {
        if (*pkt++ != '@') return 1;
    }

    *pkt_len = 0;
    for(cnt = 4; cnt; cnt--) {
        *pkt_len <<= 8;
        *pkt_len += (A_UINT8)*pkt++;
    }

    *pkt_indx = 0;
    for(cnt = 4; cnt; cnt--) {
        *pkt_indx <<= 8;
        *pkt_indx += (A_UINT8)*pkt++;
    }

    *num_pkts = 0;
    for(cnt = 4; cnt; cnt--) {
        *num_pkts <<= 8;
        *num_pkts += (A_UINT8)*pkt++;
    }

    /* End pattern */
    for(cnt = 4; cnt; cnt--) {
        if (*pkt++ != '#') return 1;
    }

    return 0;

}

#ifdef DEBUG_RX
void   waltest_print_buf(A_UINT8 *buf, A_UINT32 len )
{
     A_UINT32 i;
     A_PRINTF(" RX BUF \n");
     for (i=0;i< (len+4)/4;++i) {
       A_PRINTF("%x %x %x %x \n ", buf[i*4],buf[i*4+1], buf[i*4+2],buf[i*4+3]);
     }

}
#endif
//#define PRINT_RATE_INDEX

enum tcmd_rx_bandwith {
     TCMD_RX_BANDWIDTH_20MHZ = 0,
     TCMD_RX_BANDWIDTH_40MHZ,
     TCMD_RX_BANDWIDTH_80MHZ,
     TCMD_RX_BANDWIDTH_80P80MHZ,
     TCMD_RX_BANDWIDTH_160MHZ,
};


A_UINT32 waltest_rx_parse_status(struct wal_rx_status *mpdu_status)
{
    struct rx_attention *attention = &mpdu_status->rx_desc.attention;
    struct rx_ppdu_start *ppdu_start = &mpdu_status->rx_desc.ppdu_start;
    A_UINT32 rate_index = 0;
    A_UINT32 bw = TCMD_RX_BANDWIDTH_20MHZ;

    if (ppdu_start->preamble_type == 0x4) // OFDM/CCK
    {
        //A_PRINTF("preamble = 0x%x  sig_rate_select = 0x%x  sig_rate = 0x%x\n", ppdu_start->preamble_type,
        //    ppdu_start->l_sig_rate_select, ppdu_start->l_sig_rate);
        if (ppdu_start->l_sig_rate_select) // CCK
        {
            switch (ppdu_start->l_sig_rate)
            {
#if (WIFI_IP_CODE >= WIFI_IP_VER(2,0))
		case 0x1:  //long 1M
			rate_index = 0;
			break;
		case 0x2: //long 2M
			rate_index = 1;
			break;
		case 0x3: //long 5.5M
			rate_index = 2;
			break;
		case 0x4: //long 11M
			rate_index = 3;
			break;
		case 0x5: //short 2M
			rate_index = 150;
			break;
		case 0x6: //short 5.5M
			rate_index = 151;
			break;
		case 0x7: //short 11M
			rate_index = 152;
			break;
#else
		case 0x8:
#ifdef PRINT_RATE_INDEX
                    A_PRINTF("CCK 11 Mbps long preamble\n");
#endif
                    rate_index = 3;
                    break;

                case 0x9:
#ifdef PRINT_RATE_INDEX
                    A_PRINTF("CCK 5.5 Mbps long preamble\n");
#endif
                    rate_index = 2;
                    break;

                case 0xa:
#ifdef PRINT_RATE_INDEX
                    A_PRINTF("CCK 2 Mbps long preamble\n");
#endif
                    rate_index = 1;
                    break;

                case 0xb:
#ifdef PRINT_RATE_INDEX
                    A_PRINTF("CCK 1 Mbps long preamble\n");
#endif
                    rate_index = 0;
                    break;

                case 0xc:
#ifdef PRINT_RATE_INDEX
                    A_PRINTF("CCK 11 Mbps short preamble\n");
#endif
                    rate_index = 152;
                    break;

                case 0xd:
#ifdef PRINT_RATE_INDEX
                    A_PRINTF("CCK 5.5 Mbps short preamble\n");
#endif
                    rate_index = 151;
                    break;

                case 0xe:
#ifdef PRINT_RATE_INDEX
                    A_PRINTF("CCK 2 Mbps short preamble\n");
#endif
                    rate_index = 150;
                    break;
#endif
            }
        }
        else // OFDM
        {
            switch (ppdu_start->l_sig_rate)
            {
                case 0x8:
#ifdef PRINT_RATE_INDEX
                    A_PRINTF("OFDM 48 Mbps\n");
#endif
                    rate_index = 10;
                    break;

                case 0x9:
#ifdef PRINT_RATE_INDEX
                    A_PRINTF("OFDM 24 Mbps\n");
#endif
                    rate_index = 8;
                    break;

                case 0xa:
#ifdef PRINT_RATE_INDEX
                    A_PRINTF("OFDM 12 Mbps\n");
#endif
                    rate_index = 6;
                    break;

                case 0xb:
#ifdef PRINT_RATE_INDEX
                    A_PRINTF("OFDM 6 Mbps\n");
#endif
                    rate_index = 4;
                    break;

                case 0xc:
#ifdef PRINT_RATE_INDEX
                    A_PRINTF("OFDM 54 Mbps\n");
#endif
                    rate_index = 11;
                    break;

                case 0xd:
#ifdef PRINT_RATE_INDEX
                    A_PRINTF("OFDM 36 Mbps\n");
#endif
                    rate_index = 9;
                    break;

                case 0xe:
#ifdef PRINT_RATE_INDEX
                    A_PRINTF("OFDM 18 Mbps\n");
#endif
                    rate_index = 7;
                    break;

                case 0xf:
#ifdef PRINT_RATE_INDEX
                    A_PRINTF("OFDM 9 Mbps\n");
#endif
                    rate_index = 5;
                    break;
            }
        }
    }
#if 0
    else
    {
        A_PRINTF("preamble = 0x%x  sig_a_1 = 0x%x  sig_a_2 = 0x%x\n", ppdu_start->preamble_type,
            ppdu_start->ht_sig_vht_sig_a_1, ppdu_start->ht_sig_vht_sig_a_2);
    }
#else
    else if (ppdu_start->preamble_type == 0x8) // HT
    {
        if (ppdu_start->ht_sig_vht_sig_a_1 & 0x80) // HT40
        {
            bw = TCMD_RX_BANDWIDTH_40MHZ;
#ifdef PRINT_RATE_INDEX
            A_PRINTF("HT40 MCS%c\n", '0' + (ppdu_start->ht_sig_vht_sig_a_1 & 0x1f));
#endif
            if ((ppdu_start->ht_sig_vht_sig_a_1 & 0x1f) >= 24)
            	rate_index = 211 + ((ppdu_start->ht_sig_vht_sig_a_1 & 0x1f) % 24);
            else
            	rate_index = 36 + (ppdu_start->ht_sig_vht_sig_a_1 & 0x1f);

        }
        else // HT20
        {
#ifdef PRINT_RATE_INDEX
            A_PRINTF("HT20 MCS%c\n", '0' + (ppdu_start->ht_sig_vht_sig_a_1 & 0x1f));
#endif
            if ((ppdu_start->ht_sig_vht_sig_a_1 & 0x1f) >= 24)
            	rate_index = 203 + ((ppdu_start->ht_sig_vht_sig_a_1 & 0x1f) % 24);
            else
            	rate_index = 12 + (ppdu_start->ht_sig_vht_sig_a_1 & 0x1f);
        }
    }
    else if (ppdu_start->preamble_type == 0x9) // HT with TxBF
    {
#ifdef PRINT_RATE_INDEX
        A_PRINTF("HT with TxBF\n");
#endif
    }
    else if (ppdu_start->preamble_type == 0xc) // VHT
    {
        switch (ppdu_start->ht_sig_vht_sig_a_1 & 0x3)
        {
            case 0x0: // VHT20
#ifdef PRINT_RATE_INDEX
                A_PRINTF("VHT20 NSS%c MCS%c\n", '1' + ((ppdu_start->ht_sig_vht_sig_a_1 >> 10) & 0x3),
                    '0' + ((ppdu_start->ht_sig_vht_sig_a_2 >> 4) & 0xf));
#endif

                if ( ((ppdu_start->ht_sig_vht_sig_a_1 >> 10) & 0x3) == 0x3 )
                {
                    //rate_index = 153 + ((ppdu_start->ht_sig_vht_sig_a_1 >> 10) & 0x3) * 10 +
                    //    ((ppdu_start->ht_sig_vht_sig_a_2 >> 4) & 0xf);
		    rate_index = 153 + ((ppdu_start->ht_sig_vht_sig_a_2 >> 4) & 0xf);
//			A_PRINTF("VHT20 rate index = %d", rate_index);
                }
                else
                {
                    rate_index = 60 + ((ppdu_start->ht_sig_vht_sig_a_1 >> 10) & 0x3) * 10 +
                        ((ppdu_start->ht_sig_vht_sig_a_2 >> 4) & 0xf);
                }
                break;

            case 0x1: // VHT40
                bw = TCMD_RX_BANDWIDTH_40MHZ;
#ifdef PRINT_RATE_INDEX
                A_PRINTF("VHT40 NSS%c MCS%c\n", '1' + ((ppdu_start->ht_sig_vht_sig_a_1 >> 10) & 0x3),
                    '0' + ((ppdu_start->ht_sig_vht_sig_a_2 >> 4) & 0xf));
#endif
             if ( ((ppdu_start->ht_sig_vht_sig_a_1 >> 10) & 0x3) == 0x3 )
                {
                    //rate_index = 163 + ((ppdu_start->ht_sig_vht_sig_a_1 >> 10) & 0x3) * 10 +
                     //   ((ppdu_start->ht_sig_vht_sig_a_2 >> 4) & 0xf);
			rate_index = 163 + ((ppdu_start->ht_sig_vht_sig_a_2 >> 4) & 0xf);
//			A_PRINTF("VHT40 rate index = %d", rate_index);

                }
                else
                {
                    rate_index = 90 + ((ppdu_start->ht_sig_vht_sig_a_1 >> 10) & 0x3) * 10 +
                        ((ppdu_start->ht_sig_vht_sig_a_2 >> 4) & 0xf);
                }
                break;

            case 0x2: // VHT80
                bw = TCMD_RX_BANDWIDTH_80MHZ;
#ifdef PRINT_RATE_INDEX
                A_PRINTF("VHT80 NSS%c MCS%c\n", '1' + ((ppdu_start->ht_sig_vht_sig_a_1 >> 10) & 0x3),
                    '0' + ((ppdu_start->ht_sig_vht_sig_a_2 >> 4) & 0xf));
#endif
             if ( ((ppdu_start->ht_sig_vht_sig_a_1 >> 10) & 0x3) == 0x3 )
                {
                    rate_index = 173 + ((ppdu_start->ht_sig_vht_sig_a_2 >> 4) & 0xf);
			//rate_index = 173 + ((ppdu_start->ht_sig_vht_sig_a_1 >> 10) & 0x3) * 10 +
                        //((ppdu_start->ht_sig_vht_sig_a_2 >> 4) & 0xf);
//			A_PRINTF("VHT80 rate index = %d", rate_index);

                }
                else
                {
                    rate_index = 120 + ((ppdu_start->ht_sig_vht_sig_a_1 >> 10) & 0x3) * 10 +
                        ((ppdu_start->ht_sig_vht_sig_a_2 >> 4) & 0xf);
                }
                break;

            case 0x3: // // VHT160 VHT80p80
                //bw = TCMD_RX_BANDWIDTH_160MHZ;
                bw = TCMD_RX_BANDWIDTH_80MHZ;   // TBD
                rate_index = 183 + ((ppdu_start->ht_sig_vht_sig_a_1 >> 10) & 0x3) * 10 + ((ppdu_start->ht_sig_vht_sig_a_2 >> 4) & 0xf);
                break;

        }
    }
    else if (ppdu_start->preamble_type == 0xd) // VHT with TxBF
    {
#ifdef PRINT_RATE_INDEX
#endif
        A_PRINTF("VHT with TxBF\n");
    }
#endif

    if (attention->first_mpdu)
        g_rate_index = rate_index;

    if (bw == TCMD_RX_BANDWIDTH_40MHZ) {
        ppdu_start->rssi_comb         += 3;
        ppdu_start->rssi_pri_chain0   += 3;
        ppdu_start->rssi_pri_chain1   += 3;
        ppdu_start->rssi_pri_chain2   += 3;
        ppdu_start->rssi_pri_chain3   += 3;

        ppdu_start->rssi_sec20_chain0 += 3;
        ppdu_start->rssi_sec20_chain1 += 3;
        ppdu_start->rssi_sec20_chain2 += 3;
        ppdu_start->rssi_sec20_chain3 += 3;

        ppdu_start->rssi_sec40_chain0 += 3;
        ppdu_start->rssi_sec40_chain1 += 3;
        ppdu_start->rssi_sec40_chain2 += 3;
        ppdu_start->rssi_sec40_chain3 += 3;

    }
    if (bw == TCMD_RX_BANDWIDTH_80MHZ) {
        ppdu_start->rssi_comb         += 6;
        ppdu_start->rssi_pri_chain0   += 6;
        ppdu_start->rssi_pri_chain1   += 6;
        ppdu_start->rssi_pri_chain2   += 6;
        ppdu_start->rssi_pri_chain3   += 6;

        ppdu_start->rssi_sec20_chain0 += 6;
        ppdu_start->rssi_sec20_chain1 += 6;
        ppdu_start->rssi_sec20_chain2 += 6;
        ppdu_start->rssi_sec20_chain3 += 6;

        ppdu_start->rssi_sec40_chain0 += 6;
        ppdu_start->rssi_sec40_chain1 += 6;
        ppdu_start->rssi_sec40_chain2 += 6;
        ppdu_start->rssi_sec40_chain3 += 6;

        ppdu_start->rssi_sec80_chain0 += 6;
        ppdu_start->rssi_sec80_chain1 += 6;
        ppdu_start->rssi_sec80_chain2 += 6;
        ppdu_start->rssi_sec80_chain3 += 6;
    }

    return g_rate_index;
}

void data_rx_ind_buf_get(void *ctxt, struct fw_rx_desc_base **fw_desc_buf, int num)
{
    *fw_desc_buf = NULL;
}

void _offldmgr_non_data_handler(void *ctxt, wal_peer_t *peer, A_UINT32 tid, struct wal_rx_status *rx_status,
    wal_rx_payload_type_t payload_type, struct rxbfChain *rxbuf)
{
    waltest_rx_stack_handler(ctxt, peer, rxbuf);
}

/* Hanlder invoked to indicate arrival of data on the Host Ring - handler
 * no AMSDU siplitting case
*/

void
waltest_rx_htt_handler(
    void *ctxt,
    wal_peer_t *wal_peer,
    wal_vdev_t *wal_vdev,
    A_UINT32 tid,
    A_UINT32 mpdu_cnt,
    A_UINT32 msdu_cnt,
    A_UINT32 buf_cnt,
    struct wal_rx_status *status,
    wal_rx_payload_type_t payload_type,
    struct wal_rx_status *ppdu_start_mpdu,
    struct wal_rx_status *ppdu_end_mpdu)

{
    struct waltest_rx_ctxt *rx_ctxt = (struct waltest_rx_ctxt*)ctxt;
    A_UINT32 pkt_len, first_msdu_att, mpdu_length,is_raw_amsdu;
    A_UINT32 padded_subfrm_len;
    A_UINT8 *pkt_buf, *pkt_buf_end, *header_desc;
    struct wal_rx_status *mpdu_status, *msdu_status;
    struct wal_rx_full_status* full_status;
    A_UINT32 err, len, is_llc_reqd, first_msdu;//, dummy;
    void *wifi_hdr,*eth_hdr;
    A_UINT32 ovfl_amsdu, ovfl_amsdu_cnt;
    A_UCHAR rsStatus = 0;
    struct rx_ppdu_end *ppdu_end;

    mpdu_status = msdu_status = status;

    /* Outer MPDU traversal loop */
    while (mpdu_status) {
        //A_PRINTF("first_mpdu = %d  last_mpdu = %d\n",
        //    mpdu_status->rx_desc.attention.first_mpdu,
        //    mpdu_status->rx_desc.attention.last_mpdu);

        ppdu_end = &mpdu_status->rx_desc.ppdu_end;
        first_msdu_att
                = WHAL_RXDESC_GET_ATTN_WORD(&mpdu_status->rx_desc.attention);

        mpdu_length = mpdu_status->rx_desc.msdu_end.reported_mpdu_length;
        first_msdu = 1;

        ovfl_amsdu = WAL_RX_IS_MPDU_OVFL_AMSDU(mpdu_status);
        ovfl_amsdu_cnt = WAL_RX_OVFL_AMSDU_GET_CNT(mpdu_status);

        do { /* MSDU traversal loop */
            A_UINT32 forme = 0;

            if (ovfl_amsdu) {
                if (ovfl_amsdu_cnt--) {
                    rx_ctxt->rx_ovfl_amsdu++;
                    goto parse_next_buf;
                } else {
                    goto parse_next_mpdu;
                }
            }
            if (first_msdu_att & RX_ATTENTION_0_FCS_ERR_MASK)
                rsStatus |= WHAL_RXERR_CRC;
            if (first_msdu_att & RX_ATTENTION_0_DECRYPT_ERR_MASK)
                rsStatus |= WHAL_RXERR_DECRYPT;
            if (first_msdu_att & RX_ATTENTION_0_TKIP_MIC_ERR_MASK)
                rsStatus |= WHAL_RXERR_MIC;
            if (first_msdu_att & RX_ATTENTION_0_MPDU_LENGTH_ERR_MASK)
                rsStatus |= WHAL_RXERR_UNKNOWN;
#if (WIFI_IP_CODE < WIFI_IP_VER(2,0))
            if (ppdu_end->phy_err)
                rsStatus |= WHAL_RXERR_PHY;
#endif

            if (first_msdu_att & (1<<25)) {
                rx_ctxt->rx_directed++;
                forme = 1;
            }
#ifdef DEBUG_RX
            A_PRINTF("RX FRAME peer ix %d encrypted %d  for me %d \n", mpdu_status->rx_desc.mpdu_start.peer_idx,
                                                       mpdu_status->rx_desc.mpdu_start.encrypted, forme);
#endif

            full_status = (struct wal_rx_full_status*)msdu_status;
            header_desc = full_status->rx_ext_status.rx_hdr_buf;

            pkt_buf = waltest_rx_htt_bufs[rx_ctxt->rx_buf_indx & (rx_ctxt->rx_htt_ring_size - 1)];


            is_raw_amsdu = 0;
            pkt_buf_end = pkt_buf + mpdu_length;

            waltest_log_type_subtype(&g_waltest_rx_ds, pkt_buf, forme);

raw_amsdu_next_msdu:

            wifi_hdr=eth_hdr=NULL;

            if (first_msdu) { /* First time only */
                first_msdu = 0;
                wifi_hdr=pkt_buf;
#ifdef DEBUG_RX
                waltest_print_buf(pkt_buf,64);
#endif
                err = waltest_check_wifi_header(pkt_buf, &is_raw_amsdu, &len, 1);
                pkt_buf += len;
                if (err == SEQ_DUP_ERR) { // duplicated frame
//                    goto parse_next_buf;
                } else if (err == SEQ_ERR) { // frame drop occurred
                    // ignore
                } else if (err) {
                    g_waltest_rx_ctxt.parse_err_cnt++;
                    g_waltest_rx_ctxt.err_mask |= err;
                    rsStatus |= WHAL_RXERR_UNKNOWN;
                }

                if (rx_ctxt->peer_rx_key_info) {
                    wal_key_info_t *prx_key_info;
                    /* if receiving from multiple peers, check with peer_rx_key_info table to get the right key info */
                    if (mpdu_status->rx_desc.mpdu_start.peer_idx < rx_ctxt->peer_rx_key_info_len) {
                        prx_key_info = rx_ctxt->peer_rx_key_info[mpdu_status->rx_desc.mpdu_start.peer_idx];
                     } else {
                        prx_key_info = NULL;
                     }
                    if (prx_key_info) {
                        if (prx_key_info->key_type == WAL_KEY_TYPE_WEP128 || prx_key_info->key_type == WAL_KEY_TYPE_WEP104) {
                            pkt_buf += IV_HEADER_LEN;
                        } else if (prx_key_info->key_type == WAL_KEY_TYPE_TKIP) {
                            pkt_buf += IV_HEADER_LEN + EXTRA_IV_HEADER_LEN;
                        } else if (prx_key_info->key_type == WAL_KEY_TYPE_AES_CCMP || prx_key_info->key_type == WAL_KEY_TYPE_AES_CCMP_256) {
                            pkt_buf += CCMP_HEADER_LEN;
                        } else if (prx_key_info->key_type == WAL_KEY_TYPE_AES_GCMP || prx_key_info->key_type == WAL_KEY_TYPE_AES_GCMP_256) {
                            pkt_buf += GCMP_HEADER_LEN;
                        }
                    }
                }
                else
                    pkt_buf += CCMP_HEADER_LEN;
            }

            if (is_raw_amsdu) {
                eth_hdr=pkt_buf;
                err = waltest_check_eth_hdr(pkt_buf, &is_llc_reqd, &len);
                pkt_buf += len;

                if (err || !is_llc_reqd) {
                    g_waltest_rx_ctxt.parse_err_cnt++;
                    g_waltest_rx_ctxt.err_mask |= err;
                    rsStatus |= WHAL_RXERR_UNKNOWN;
                }
            }

            /*  In the payload now - Check the packet pattern */
            pkt_len = pkt_buf_end - pkt_buf - 4;
            if (g_waltest_rx_ctxt.frame_rx_cb) {
                g_waltest_rx_ctxt.frame_rx_cb(g_waltest_rx_ctxt.cb_ctxt,
                    pkt_len, waltest_rx_parse_status(mpdu_status), rsStatus, mpdu_status);
                  goto skip_frame_check;
            }

skip_frame_check:
            rx_ctxt->num_recvd_packets++;

            if (is_raw_amsdu) {
                padded_subfrm_len =
                    14 + 8 + pkt_len;
//                    14 + 8 + WALTEST_PKT_ID_LEN + pkt_len;
                padded_subfrm_len += 0x3;
                padded_subfrm_len &= ~0x3;
                pkt_buf += padded_subfrm_len - (14 + 8);
                if ((pkt_buf_end - pkt_buf) > (14 + 8)) {
                    goto raw_amsdu_next_msdu;
                }
            }

parse_next_buf:
            rx_ctxt->rx_buf_indx++;
            rx_ctxt->rx_htt_pkt_indx += 1;
            if (rx_ctxt->rx_htt_pkt_indx >= rx_ctxt->rx_htt_ring_size) {
                rx_ctxt->rx_htt_pkt_indx -= rx_ctxt->rx_htt_ring_size;
            }

        /* Iterate till we hit the next MPDU */
        /* In case of overflow AMSDU the msdu link is bad */
        } while ( ovfl_amsdu ||
            ((msdu_status = STAILQ_NEXT(msdu_status, msdu_link)) !=
                (STAILQ_NEXT(mpdu_status, mpdu_link))));

parse_next_mpdu:
        mpdu_status = msdu_status = STAILQ_NEXT(mpdu_status, mpdu_link);
    }


    whalSetRxRingFwIndx(WAL_RX_RING_REMOTE_STATUS_PKT, rx_ctxt->rx_htt_pkt_indx);

    return;
}

/* Function simulates HTT host behavior in setting up the packet ring
 */
void waltest_rx_htt_setup(wal_pdev_t *pdev,A_UINT8** bufs,A_UINT32 num_bufs,A_UINT32 ring_size)
{

    A_UINT8 rx_comp_order[] = {WHAL_RX_STATUS_COMP_PKT, WHAL_RX_STATUS_EOL};
    WAL_RX_DATA_IND_HANDLER *htt_handler = waltest_rx_htt_handler;
    A_UINT32 buf_indx;
    struct waltest_rx_ctxt *rx_ctxt = &g_waltest_rx_ctxt;
    A_UINT32 pkt_sel;
    void *addr;

    /* Setup the HW ring interface */
    for (buf_indx = 0; buf_indx < num_bufs; buf_indx++) {
        waltest_rx_htt_ring[buf_indx] =
                A_DMA_ADDR(((A_UINT8*)bufs + (buf_indx*g_rxbufSize)));

    }

    pkt_sel = 0;
    RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_UCAST_DATA);
    RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_MCAST_DATA);

    /* warning catcher */
    if (1) {
        addr = &waltest_rx_htt_ring[0];
    }

    whalSetupRxRing(WAL_RX_RING_REMOTE_STATUS_PKT,
        (A_UINT32)addr, ring_size,
        g_rxbufSize / sizeof(A_UINT32), 0,
        rx_comp_order, 0 , 1, pkt_sel);

    rx_ctxt->rx_htt_pkt_indx = num_bufs-1;

    whalSetRxRingFwIndx(WAL_RX_RING_REMOTE_STATUS_PKT, rx_ctxt->rx_htt_pkt_indx);

    wal_rx_install_data_ind(pdev, htt_handler, (void*)rx_ctxt);
    wal_rx_install_data_fw_desc_buf_get(pdev, data_rx_ind_buf_get, (void *)rx_ctxt);
    wal_rx_install_non_data_ind(pdev, _offldmgr_non_data_handler, (void *)rx_ctxt);

    return;

}

void waltest_rx_stack_handler(void *ctxt,
        wal_peer_t *peer, struct rxbfChain *rx_buf_chain)
{
    BUF_LIST reque_buflist;
    struct ath_buf *buf_ptr, *buf_ptr_next;
    struct waltest_rx_ctxt *waltest_rx_ctxt = (struct waltest_rx_ctxt *)ctxt;
    WHAL_RX_DESC *rx_ds;

    A_MEMZERO(&reque_buflist, sizeof(reque_buflist));
    STAILQ_INIT(&reque_buflist.buf_list);

    buf_ptr = rx_buf_chain->head;
    if (buf_ptr == NULL) return;
   
    rx_ds = TO_WHAL_DESC(buf_ptr->bf_b.wlanBuf.rx);

    while (buf_ptr)
    {
        buf_ptr_next = STAILQ_NEXT(buf_ptr, bf_list);

        STAILQ_INSERT_TAIL(&reque_buflist.buf_list, buf_ptr, bf_list);
        reque_buflist.num_of_bufs++;

        buf_ptr = buf_ptr_next;
    }

    A_ASSERT(reque_buflist.num_of_bufs == rx_buf_chain->num_of_bufs);

    //if ((rx_ds->dsRxStat.rsStatus & WHAL_RXERR_PHY) && waltest_rx_ctxt->local_rx_cb)
    if (waltest_rx_ctxt->local_rx_cb)
    {
        waltest_rx_ctxt->local_rx_cb(waltest_rx_ctxt->cb_ctxt, (A_UINT8 *) &(rx_ds->dsRxStat), sizeof(WHAL_RX_DESC));
    }

    wal_rx_ring_reque_buffers(waltest_rx_ctxt->ring_ctxt, &reque_buflist);

    return;
}

void waltest_rx_stack_setup(wal_pdev_t *pdev)
{
    struct waltest_rx_ctxt *waltest_rx_ctxt = &g_waltest_rx_ctxt;
    BUF_LIST buffer_list;
    struct ath_buf *abf;
    A_UINT32 buf_indx;
    WAL_RX_RING_BUF_HANDLER *stack_handler = waltest_rx_stack_handler;
    void *ring_ctxt;

    /* Setup the managed ring */
    ring_ctxt = waltest_rx_ring_setup(pdev, WAL_RX_RING_LOCAL_PKT,
        sizeof(struct rxbf_data), 0, WALTEST_RX_LOC_BUFS);
    waltest_rx_ctxt->ring_ctxt = ring_ctxt;

    /* Register the handler */
    wal_rx_ring_register_buf_handler(pdev, WAL_RX_RING_LOCAL_PKT, stack_handler,
                                    (void*)waltest_rx_ctxt);


    /* Construct the Buf list and feed it to WAL */
    A_MEMZERO(&buffer_list, sizeof(buffer_list));
    STAILQ_INIT(&buffer_list.buf_list);

    for (buf_indx = 0; buf_indx < WALTEST_RX_LOC_BUFS; buf_indx++) {
        abf = &waltest_ath_bufs[buf_indx];
        abf->bf_b.wlanBuf.rx = &waltest_rxbufs[buf_indx];

        STAILQ_INSERT_TAIL(&buffer_list.buf_list, abf, bf_list);
        buffer_list.num_of_bufs++;
    }


    wal_rx_ring_reque_buffers(waltest_rx_ctxt->ring_ctxt, &buffer_list);
    if (waltest_rx_ctxt->vdev == NULL) {
        A_UINT8 i;

        for (i = 0; i < WAL_MAC_ADDR_LEN; i++)
            pdev->mac_mask[i] = ~g_encap_cfg.da_addr[i];
        wal_vdev_attach(pdev, &waltest_rx_ctxt->vdev, g_encap_cfg.da_addr, WAL_VDEV_TYPE_AP, 3, 0);

        whalSetRecvAddrMask(pdev->mac_mask);
        whalSetOperatingMode(WHAL_M_AP);
	if(waltest_rx_ctxt->vdev)
	    wal_peer_alloc(waltest_rx_ctxt->vdev, &waltest_rx_ctxt->peer[0], g_encap_cfg.bss_addr, g_encap_cfg.bss_addr, NULL, 1);
	else
	    return;

	g_waltest_rx_config.vdev = waltest_rx_ctxt->vdev;
     	g_waltest_rx_config.peer = waltest_rx_ctxt->peer[0];
   }

    return;
}

struct waltest_rx_ctxt *waltest_rx_setup(wal_pdev_t *pdev,
                              void *cb_ctxt, waltest_rx_data_frame_cb frame_rx_cb,
                              waltest_rx_local_frame_cb local_rx_cb,
                              struct waltest_rx_config  *cfg)
{
    struct waltest_rx_ctxt *waltest_rx_ctxt = &g_waltest_rx_ctxt;

    //if(waltest_rx_ctxt->vdev == NULL)
    A_MEMZERO(waltest_rx_ctxt, sizeof(*waltest_rx_ctxt));

    A_MEMSET(waltest_rx_ctxt->last_rx_seqs, 0xFF,
            sizeof(waltest_rx_ctxt->last_rx_seqs));

    waltest_rx_ctxt->rx_buf_indx = g_rx_buf_indx;
    waltest_rx_ctxt->cb_ctxt = cb_ctxt;
    waltest_rx_ctxt->frame_rx_cb = frame_rx_cb;
    waltest_rx_ctxt->local_rx_cb = local_rx_cb;
    if (cfg->vdev) {
       waltest_rx_ctxt->vdev = cfg->vdev;
       waltest_rx_ctxt->peer[0] = cfg->peer;
    }

    waltest_rx_ctxt->rx_htt_ring_size = WALTEST_RX_HTT_RING_SIZE;
    waltest_rx_htt_setup(pdev,(A_UINT8**)waltest_rx_htt_bufs[0],WALTEST_RX_HTT_BUFS,WALTEST_RX_HTT_RING_SIZE);

    /* Fake stack setup */
    waltest_rx_stack_setup(pdev);

    /* For waltest put HW in AP-STA mode and fake association by setting up
     * hardcoded STA / AP / BSSID address
     */
#if defined(PERE_SW_WAR_WALTEST_FAKE_MAC_ADDRS)
    {
        A_UCHAR da_addr[6], bss_addr[6];
        A_UINT32 addr;

        A_MEMCPY(da_addr, g_encap_cfg.da_addr, 6);
        A_MEMCPY(bss_addr, g_encap_cfg.bss_addr, 6);

        addr = A_HTOLE32(*(A_UINT32*)&da_addr[0]);
        A_WMAC_REG_WRITE(MAC_PCU_STA_ADDR_L32_ADDRESS, addr);
        addr = A_HTOLE16(*(A_UINT16*)&da_addr[4]);

        addr |= MAC_PCU_STA_ADDR_U16_PRESERVE_SEQNUM_MASK;
        A_WMAC_REG_WRITE(MAC_PCU_STA_ADDR_U16_ADDRESS, addr | (1 << 16));

        addr = A_HTOLE32(*(A_UINT32*)&bss_addr[0]);
        A_WMAC_REG_WRITE(MAC_PCU_BSSID_L32_ADDRESS, addr);
        addr = A_HTOLE16(*(A_UINT16*)&bss_addr[4]);
        A_WMAC_REG_WRITE(MAC_PCU_BSSID_U16_ADDRESS, addr | (1 << 16));

#if (WIFI_IP_CODE < WIFI_IP_VER(2,0))
        /* Turn on interrupts */
        A_WMAC_REG_WRITE(MAC_DMA_GLOBAL_IER_ADDRESS, MAC_DMA_GLOBAL_IER_ENABLE_MASK);
#endif
    }
#endif
if (waltest_rx_ctxt->peer[0])
    wal_rx_setup_block_ack(waltest_rx_ctxt->peer[0], 0, TX_SEND_FAKE_AGGR_PARAM_SSN, TX_SEND_FAKE_AGGR_PARAM_WIN_SZ, TRUE);
else
    A_PRINTF_ALWAYS("cannot set rx block ack\n");

    /* Start RX */
    while (!whalSetGlobalRxRingEnable(TRUE)) {
        ring_enable_counter++;
        A_DELAY_USECS(10);
        A_ASSERT(ring_enable_counter < RING_EXIT_COUNT);
    }
    ring_enable_counter = 0;
    whalEnableRxRing(WAL_RX_RING_REMOTE_STATUS_PKT);
    whalEnableRxRing(WAL_RX_RING_LOCAL_PKT);
    whalEnableRxRing(WAL_RX_RING_LOCAL_STATUS); // glee mod

    return waltest_rx_ctxt;

}

wal_vdev_t *waltest_rx_get_vdev(struct waltest_rx_ctxt *ctxt)
{
   return ctxt->vdev;
}

void setup_pkt_buffer_rx()
{
    A_UINT32 i;

#ifndef SIMUIO
    g_rxbufSpace = (A_UINT8 *)memTable;
#else
    waltest_ath_bufs = uio_dma_alloc(WALTEST_RX_LOC_BUFS*sizeof(struct ath_buf));
    waltest_rxbufs = uio_dma_alloc(WALTEST_RX_LOC_BUFS*sizeof(struct rxbuf));
    g_rxbufSpace = uio_dma_alloc(WALTEST_RX_HTT_BUFS*WALTEST_RX_BUFSIZE);
    waltest_rx_htt_ring = uio_dma_alloc(WALTEST_RX_HTT_BUFS*sizeof(A_UINT32));
#endif
    // Setup waltest_rx_htt_bufs addrs
    for (i = 0; i < WALTEST_RX_HTT_BUFS; i++)
        waltest_rx_htt_bufs[i] = g_rxbufSpace + i * WALTEST_RX_BUFSIZE;
}

void waltest_rx(wal_pdev_t *pdev, void *cb_ctxt, waltest_rx_data_frame_cb frame_rx_cb,
                waltest_rx_local_frame_cb local_rx_cb)
{
    A_UINT32 i;

    if (g_waltest_rx_config.vdev)
    {
	g_rxbufSize = WALTEST_RX_BUFSIZE / 4;
        for (i = 0; i < WALTEST_RX_HTT_BUFS; i++)
            waltest_rx_htt_bufs[i] = g_rxbufSpace + (WALTEST_RX_HTT_BUFS - 1) * WALTEST_RX_BUFSIZE + i * g_rxbufSize;
    }
    else
    {
	g_rxbufSize = WALTEST_RX_BUFSIZE;
        for (i = 0; i < WALTEST_RX_HTT_BUFS; i++)
            waltest_rx_htt_bufs[i] = g_rxbufSpace + i * g_rxbufSize;
        A_MEMZERO(waltest_rx_htt_bufs[0], WALTEST_RX_HTT_BUFS * g_rxbufSize);
    }
    waltest_rx_setup(pdev, cb_ctxt, frame_rx_cb, local_rx_cb, &g_waltest_rx_config);
}

void rx_data_reorder_flush(wal_pdev_t *pdev)
{
    wal_vdev_t *vdev;
    wal_peer_t *peer;
    struct wal_rx_ctxt *rx_ctxt = WAL_GET_RX_CTXT(pdev);

    if (rx_ctxt->data_reorder_flush) {
        STAILQ_FOREACH(vdev, &pdev->vdev_list, link_vdev) {
            STAILQ_FOREACH(peer, &vdev->peer_list, link_peer) {
                rx_ctxt->data_reorder_flush(rx_ctxt->data_reorder_flush_ctxt,
                    peer);
            }
        }
    }
}

#if defined(IPQ4019) || defined(QCA9984)
/* This WAR to reset MAC */
void resetMAC(void)
{
        A_UINT32 reset_control;
        //# reset MAC
        //$main::REGAH->regWr("WIFI_RESET_CONTROL.MAC_COLD_RST", 0x1);
        //$main::REGAH->regWr("WIFI_RESET_CONTROL.MAC_WARM_RST", 0x1);
        reset_control = A_RTC_WLAN_REG_READ(WIFI_RESET_CONTROL_ADDRESS);
        reset_control |= (WIFI_RESET_CONTROL_MAC_WARM_RST_MASK | WIFI_RESET_CONTROL_MAC_COLD_RST_MASK);
        A_RTC_WLAN_REG_WRITE(WIFI_RESET_CONTROL_ADDRESS, reset_control);
        
        //# start WIFI initialization
        //$main::REGAH->regWr("WIFI_MAC_SLEEP_CONTROL.FORCE_WAKE", 1);
        WHAL_MAC_WAKEUP();
        A_DELAY_USECS(1000);
        
        //# Clear Cold and Warm Resets to MAC
        //$main::REGAH->regWr("WIFI_RESET_CONTROL.MAC_COLD_RST", 0x0);
        //$main::REGAH->regWr("WIFI_RESET_CONTROL.MAC_WARM_RST", 0x0);
        reset_control = A_RTC_WLAN_REG_READ(WIFI_RESET_CONTROL_ADDRESS);
        reset_control &= ~(WIFI_RESET_CONTROL_MAC_WARM_RST_MASK |
                           WIFI_RESET_CONTROL_MAC_COLD_RST_MASK);
        A_RTC_WLAN_REG_WRITE(WIFI_RESET_CONTROL_ADDRESS, reset_control);    
}

#endif

void waltest_rx_detach(wal_pdev_t *pdev)
{
    struct waltest_rx_ctxt *ctxt = &g_waltest_rx_ctxt;
    struct wal_rx_ctxt *rx_ctxt = WAL_GET_RX_CTXT(pdev);

    if (tcmd_state.tcmdRxGo == 2 || tcmd_state.tcmdRxGo == 0 ) {
        return;
    }
  
#if 0
    whalStopPcuReceive();
    rx_ctxt->rx_abort_flag = 1;

    while(rx_process_recv_status(pdev));
    if (!whalRecvWaitOleIdle()) {
        A_ASSERT(FALSE);
    }

    whalDisableRxRing(WAL_RX_RING_LOCAL_PKT);
    whalDisableRxRing(WAL_RX_RING_REMOTE_STATUS_PKT);

    whalSetGlobalRxRingEnable(FALSE);

    /* Process all pending buffers in the hardware */
    while(rx_process_recv_status(pdev));

//    whalDisableRxRing(WAL_RX_RING_LOCAL_STATUS);

    whalSetRxRingHwIndx(WAL_RX_RING_REMOTE_STATUS_PKT, 0);
    whalSetRxRingHwIndx(WAL_RX_RING_LOCAL_PKT, 0);
//    whalSetRxRingHwIndx(WAL_RX_RING_LOCAL_STATUS, 0);

    rx_ctxt->rx_abort_flag = 0;
   // rx_data_reorder_flush(pdev);

    //whalDisableRxRing(WAL_RX_RING_LOCAL_PKT);
    //whalDisableRxRing(WAL_RX_RING_REMOTE_STATUS_PKT);

    //whalSetRxRingHwIndx(WAL_RX_RING_REMOTE_STATUS_PKT, 0);
    //whalSetRxRingHwIndx(WAL_RX_RING_LOCAL_PKT, 0);
    //whalSetRxRingHwIndx(WAL_RX_RING_LOCAL_STATUS, 0);

    g_rx_buf_indx = ctxt->rx_buf_indx;
//    wal_rx_ring_register_buf_handler(pdev, WAL_RX_RING_LOCAL_PKT, NULL, NULL);

    if (g_waltest_rx_config.vdev == NULL)
    {
        /* free peer and vdev */
        if (ctxt->peer[0])
            wal_peer_free(ctxt->peer[0]);
        if (ctxt->vdev)
            wal_vdev_detach(ctxt->vdev);
    }
    ctxt->peer[0] = NULL;
    ctxt->vdev = NULL;
#else
    whalStopPcuReceive();
    rx_ctxt->rx_abort_flag = 1;

    while(rx_process_recv_status(pdev));
//  workaround for CR700450.  Hitting this assert.  May not need this - remove for now.
//  if (!whalRecvWaitOleIdle()) {
//      A_ASSERT(FALSE);
//  }

//    whalDisableRxRing(WAL_RX_RING_LOCAL_PKT);
//    whalDisableRxRing(WAL_RX_RING_REMOTE_STATUS_PKT);

    whalSetGlobalRxRingEnable(FALSE);

    /* Process all pending buffers in the hardware */
    while(rx_process_recv_status(pdev));

    //whalSetRxRingHwIndx(WAL_RX_RING_REMOTE_STATUS_PKT, 0);
    //whalSetRxRingHwIndx(WAL_RX_RING_LOCAL_PKT, 0);

    rx_ctxt->rx_abort_flag = 0;
    //rx_data_reorder_flush(pdev);

    while ((!whalDisableRxRing(WAL_RX_RING_LOCAL_PKT)) &&
           (ring_disable_local_counter< RING_EXIT_COUNT))
    {
        ring_disable_local_counter++;
    }
    
    while ((!whalDisableRxRing(WAL_RX_RING_REMOTE_STATUS_PKT)) &&
           (ring_disable_remote_counter< RING_EXIT_COUNT))
    {
        ring_disable_remote_counter++;
    }
    
    /* 
    * Dakota found sometimes the issue that RXDMA_EN_ACT_0.RING_ACTIVE=1 is always at running
    * DVT non-adjacent channel blocker test. rx_ring_active always get assert means rxdma hang on somewhere.
    * Add WAR to reset MAC.
    */
#if defined(IPQ4019) || defined(QCA9984)
    if ((ring_disable_local_counter == RING_EXIT_COUNT) || (ring_disable_remote_counter == RING_EXIT_COUNT))
    {
        resetMAC();
    }   
#endif
    ring_disable_local_counter = 0;
    ring_disable_remote_counter = 0;

    whalSetRxRingHwIndx(WAL_RX_RING_REMOTE_STATUS_PKT, 0);
    whalSetRxRingHwIndx(WAL_RX_RING_LOCAL_PKT, 0);
//	OS_REG_WRITE(0x30894,0x0);
//	OS_REG_WRITE(0x30898,0x0);

   OS_REG_WRITE(RXDMA_IDX_0_ADDRESS,0x0);
   OS_REG_WRITE(RXDMA_IDX_1_ADDRESS,0x0);

    g_rx_buf_indx = ctxt->rx_buf_indx;
//    wal_rx_ring_register_buf_handler(pdev, WAL_RX_RING_LOCAL_PKT, NULL, NULL);

   if (ctxt->vdev != NULL && tcmd_state.tcmdRxGo == 1 && tcmd_state.tcmdTxGo == 0 && g_waltest_rx_config.vdev != NULL)//.vdev != NULL)// && start_tx_status == 0)
    {
        /* free peer and vdev */
        if (ctxt->peer[0])
            wal_peer_free(ctxt->peer[0]);
        if (ctxt->vdev)
            wal_vdev_detach(ctxt->vdev);

	    ctxt->peer[0] = NULL;
	    ctxt->vdev = NULL;
	    g_waltest_rx_config.vdev = NULL;
	    g_waltest_rx_config.peer = NULL;
    }

    if (tcmd_state.tcmdTxGo != 0)
	    tcmd_state.tcmdRxGo = 2;
    else
	    tcmd_state.tcmdRxGo = 0;

    g_xtal_cal_flag = FALSE;
#endif
}

// The following codes are copied and modified from ar_wal_rx.c file.  Need to sync with it.
extern const A_UINT8 *rx_ring_comp_orders[];
extern const A_UINT8 wal_decap_to_whal_decap[];
extern const A_UINT32 wal_pad_to_whal_pad[];     //VJ's change
#if 1 // RX stuck for long time test. So revert it temporarily. 
extern A_UINT32 g_rx_curr_fill_indx;
extern struct wal_rx_init_params rx_default_params;
#endif
void waltest_rx_restore(wal_pdev_t *pdev)
{
    A_UINT32 ring_indx = WAL_RX_RING_LOCAL_STATUS;
    struct wal_rx_ctxt *rx_ctxt = WAL_GET_RX_CTXT(pdev);
    struct wal_rx_ring_state *ring_state = &rx_ctxt->rx_rings[ring_indx];
    //struct wal_rx_full_status *status_bufs;
    struct wal_rx_status *status_bufs;
    A_UINT32 num_entries = rx_default_params.status_ring_size;
    A_UINT32 pkt_sel;
    A_UINT32 indx;
    A_UINT32 rfilt, mfilt[2];

    /* Setup the packet selection for the rings */
    pkt_sel = 0;
    switch (ring_indx) {
    case 0:
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_MGMT);
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_CTRL);
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_NULL);
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_UCAST_DATA);
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_MCAST_DATA);
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_PHY_DATA);
        break;
    case 1:
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_MGMT);
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_CTRL);
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_NULL);
        break;
    case 2:
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_UCAST_DATA);
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_MCAST_DATA);
        break;
    default:
        /* Dont turn on other rings */
        break;
    }

    whalSetupRxRing(ring_indx, (A_UINT32)ring_state->ring_base, ring_state->ring_size,
            ring_state->buffer_size / sizeof(A_UINT32), ring_state->hdroom / sizeof(A_UINT32),
            rx_ring_comp_orders[ring_indx],
            (ring_state->ring_size >> 2), /* Low water thresh */
            1, pkt_sel);

    {
        indx = 0;
        STAILQ_FOREACH(status_bufs, &rx_ctxt->rx_status_list, msdu_link) {
            ring_state->ring_base[indx] = A_DMA_ADDR((A_UINT32) status_bufs);
            indx++;
        }
    }
    ring_state->ring_free_slots = 0;
    ring_state->ring_curr_indx = num_entries - 1;
    g_rx_curr_fill_indx = num_entries;
    whalSetRxRingFwIndx(ring_state->ring_id, ring_state->ring_curr_indx);
    whalSetRxRingHwIndx(ring_indx, 0);

    /* Set up the basic filters */
    rfilt =  WHAL_RX_FILTER_UCAST |  WHAL_RX_FILTER_BCAST |  WHAL_RX_FILTER_MCAST
                | WHAL_RX_FILTER_FROM_TO_DS;
    whalSetRxFilter(WHAL_RX_FILTER_PROM);

    mfilt[0] = mfilt[1] = ~0;
    whalSetMulticastFilter(mfilt[0], mfilt[1]);

    /* Set up the OLE RX mode for the dev */
    whalSetupOle(wal_decap_to_whal_decap[pdev->rx_decap_mode], wal_pad_to_whal_pad[pdev->iphdr_pad_config]);     //VJ's change

    g_rx_buf_indx = 0;

    return;
}

void *waltest_rx_ring_setup(wal_pdev_t *pdev, A_UINT32 ring_indx,
         A_UINT32 buffer_size, A_UINT32 headroom_dwords, A_UINT32 max_entries)
{

    struct wal_rx_ctxt *rx_ctxt = WAL_GET_RX_CTXT(pdev);
    struct wal_rx_ring_state *ring_state = &rx_ctxt->rx_rings[ring_indx];
    A_UINT32 ring_flags, ring_size, is_local_ring, pkt_sel;

    ring_flags = ring_state->ring_flags;

    /* A ring with N entries has (N+1) fullness states - 0, 1, .. N.
     * However we use modulo-N math on the rings and hence only N states
     * can be commnunicated to HW. Ring can only hold hold N-1 entries at
     * if we use counters that are consistent with HW.
     */

    /* Increase entries by 1, to accomodate for local ring limitations */
    max_entries += 1;


    /* Bump up ring entries to next power of 2*/
    ring_size = 1;
    while (ring_size < max_entries) {
        ring_size <<= 1;
    }

    /* Setup the WAL ring parameters */
    ring_state->ring_size = ring_size;
    ring_state->ring_free_slots = ring_size - 1;
    ring_state->ring_curr_indx = 0;
    ring_state->buffer_size = buffer_size;

    /* Save headroom for properly setting up bufs on return from HW */
    A_ASSERT(headroom_dwords < (256 / sizeof(A_UINT32)));
    ring_state->hdroom = headroom_dwords * sizeof(A_UINT32);

    /* Pass Ring params to HW */
    /* No support for using this API to config remote rings yet */
    is_local_ring = 1;

    /* Setup the packet selection for the rings */
    pkt_sel = 0;
    switch (ring_indx) {
    case 0:
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_MGMT);
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_CTRL);
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_NULL);
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_UCAST_DATA);
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_MCAST_DATA);
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_PHY_DATA);
        break;
    case 1:
//        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_MGMT);
//        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_CTRL);
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_NULL);
//        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_PHY_DATA);
        break;
    case 2:
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_UCAST_DATA);
        RX_RING_SET_PKTSEL(pkt_sel, WHAL_RX_PKT_TYPE_MCAST_DATA);
        break;
    default:
        /* Dont turn on other rings */
        break;
    }

    whalSetupRxRing(ring_indx, (A_UINT32)ring_state->ring_base, ring_size,
            buffer_size / sizeof(A_UINT32), headroom_dwords,
            rx_ring_comp_orders[ring_indx],
            (ring_size >> 2), /* Low water thresh */
            is_local_ring, pkt_sel);

    whalEnableRxRing(ring_indx);

    SET_FLG(ring_flags, WAL_RX_RING_SETUP_DONE);
    ring_state->ring_flags = ring_flags;

    return ((void*)ring_state);
}

