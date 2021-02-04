#ifndef __TCMD_RX__
#define __TCMD_RX__

#include <wal.h>
#include <ar_wal.h>
#include <wal_peer.h>
#include "tcmd_internal.h"
/* API for tme transmit framework */


struct waltest_rx_ctxt;

struct waltest_rx_config {
   wal_vdev_t *vdev; /* vdev to use for the test */
   wal_peer_t *peer; /* peer to use for the test */
};
   

/*
 * call back invoked when  data frame is received.
 */
typedef int (* waltest_rx_data_frame_cb ) (void *ctxt, A_UINT32 data_len, A_UINT32 rate_index,
                                           A_UCHAR rsStatus, struct wal_rx_status *mpdu_status);


/*
 * call back invoked when a frame is received on local ring (management frames) is received.
 */
typedef int (*waltest_rx_local_frame_cb ) (void *cb_ctxt, A_UINT8 *buf, A_UINT32 buf_len); 


/*
 * attach tx wal test. will create a vdev and any peers
 * and return context.
 */
struct waltest_rx_ctxt *waltest_rx_setup(wal_pdev_t *pdev, 
                              void *cb_ctxt, waltest_rx_data_frame_cb frame_rx_cb,
                              waltest_rx_local_frame_cb local_rx_cb, 
                              struct waltest_rx_config *cfg);

/*
 * get the allocated vdev.
 */
wal_vdev_t *waltest_rx_get_vdev(struct waltest_rx_ctxt *ctxt);


/*
 *  *  setup rx wal test. 
 *   */
void waltest_rx(wal_pdev_t *pdev, void *cb_ctxt, waltest_rx_data_frame_cb frame_rx_cb,
                waltest_rx_local_frame_cb local_rx_cb);


void waltest_rx_detach(wal_pdev_t *pdev);
void waltest_rx_restore(wal_pdev_t *pdev);


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
