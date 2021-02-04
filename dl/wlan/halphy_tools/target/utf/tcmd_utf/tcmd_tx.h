#ifndef __TCMD_TX__
#define __TCMD_TX__

#include <wal.h>
#include <ar_wal.h>
#include <wal_peer.h>
#include "tcmd_internal.h"
/* API for tme transmit framework */


#define NUM_TIDS        (1)
#define PKTS_PER_TID    (64 / NUM_TIDS)

struct waltest_ctxt;
struct tx_setup_config {
    A_BOOL setup_peers; /* setup default peers(bss peer and one destination peer) */
    wal_vdev_t *vdev;   /* vdev to use */
};

struct frame_enacap_config {
    A_UINT32 pkt_len;
    unsigned char *sa_addr;
    unsigned char *da_addr;
    unsigned char *bss_addr;
    wal_vdev_t *vdev;   /* vdev to use for tx */
//    wal_key_info_t *tx_key_info;
    /*
     * fill the packet with custom header followed by
     * a fill pattern.
     */
    A_UINT16 pattern;
    A_UINT32 pattern_length;
    A_UCHAR *pattern_data;
    A_BOOL is_broadcast;
    A_BOOL is_qos;
    A_UINT8 chain_mask;
    A_UINT32 num_desc;
    A_UINT32 num_aggr;
    A_UINT16 data_rate;
};

void waltest_setup_frameq_pkts(
    struct waltest_ctxt *ctxt, A_UINT8 tid, A_UINT32 num_pkts,
    struct frame_enacap_config *cfg);

/*
 * call back invoked when  a set of data frames for a given tid
 * completed.
 */
typedef int (* waltest_tx_data_frame_completion_cb ) (void *txt, A_UINT32 total_pkts, A_UINT32 good_pkts, void *hw_status, void *sw_status);


/*
 * call back invoked when  a local frame is
 * completed. the abf_next need to be filled with a proper frame 
 * by the implementation and the implementation needs to call waltest_tx_send_local
 * to send the frame.
 */
typedef A_BOOL (* waltest_tx_local_frame_completion_cb ) (void *txt,struct ath_buf *abf_completed, struct ath_buf *abf_next);


/*
 * attach tx wal test. will create a vdev and any peers
 * and return context.
 */
struct waltest_ctxt *waltest_tx_attach(wal_pdev_t *pdev, struct tx_setup_config *cfg,
                              void *cb_ctxt, waltest_tx_data_frame_completion_cb frame_comp_cb,
                              waltest_tx_local_frame_completion_cb local_frame_comp_cb);

/*
 * get the allocated vdev.
 */
wal_vdev_t *waltest_tx_get_vdev(struct waltest_ctxt *ctxt);

/*
 * start sending the frames. 
 */
void waltest_tx_start(void);

/*
 * creates and queues requested number of packets for a given tid. 
 * the required information to encapsulate the frame is
 * passed via frame enacp config.
 */
void waltest_setup_frameq_pkts(
    struct waltest_ctxt *ctxt, A_UINT8 tid_id, A_UINT32 num_pkts,
    struct frame_enacap_config *cfg);

/*
 * send a local frame.
 * usually called from the waltest_tx_local_frame_completion_cb. 
 */
void waltest_tx_send_local(struct waltest_ctxt *ctxt,wal_peer_t *peer, struct ath_buf *abf);

/*
 *  *  setup tx wal test. 
 *   */
void waltest_tx(wal_pdev_t *pdev, void *cb_ctxt, waltest_tx_data_frame_completion_cb frame_comp_cb,
                waltest_tx_local_frame_completion_cb local_frame_comp_cb);

void waltest_tx_detach(wal_pdev_t *pdev);

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
