/*
 *  Copyright (c) 2014 Qualcomm Atheros, Inc.  All rights reserved. 
 *
 *  Qualcomm is a trademark of Qualcomm Technologies Incorporated, registered in the United
 *  States and other countries.  All Qualcomm Technologies Incorporated trademarks are used with
 *  permission.  Atheros is a trademark of Qualcomm Atheros, Inc., registered in
 *  the United States and other countries.  Other products and brand names may be
 *  trademarks or registered trademarks of their respective owners. 
 */

#ifndef _IEEE80211_RRM_H_
#define _IEEE80211_RRM_H_ 

#define IEEE80211_RRM_CHAN_MAX            255

#define IEEE80211_RRM_NUM_CHANREQ_MAX 5
#define IEEE80211_RRM_NUM_CHANREP_MAX 2

struct ieee80211_beaconreq_chaninfo {
    u_int8_t regclass;
    u_int8_t numchans;
    u_int8_t channum[IEEE80211_RRM_NUM_CHANREQ_MAX];
};

typedef struct ieee80211_rrm_beaconreq_info_s {
    u_int16_t   num_rpt;
    u_int8_t    regclass;
    u_int8_t    channum;
    u_int16_t   random_ivl;
    u_int16_t   duration;
    u_int8_t    reqmode;
    u_int8_t    reqtype;
    u_int8_t    bssid[6];
    u_int8_t    mode;
    u_int8_t    req_ssid;
    u_int8_t    rep_cond;
    u_int8_t    rep_thresh;
    u_int8_t    rep_detail;
    u_int8_t    req_ie;
    u_int8_t    num_chanrep;
    struct ieee80211_beaconreq_chaninfo
              apchanrep[IEEE80211_RRM_NUM_CHANREP_MAX];
}ieee80211_rrm_beaconreq_info_t;

typedef struct ieee80211_rrm_chloadreq_info_s{
    u_int8_t dstmac[6];
    u_int16_t num_rpts;
    u_int8_t regclass;
    u_int8_t chnum;
    u_int16_t r_invl;
    u_int16_t m_dur;
    u_int8_t cond;
    u_int8_t c_val;
}ieee80211_rrm_chloadreq_info_t;

typedef struct ieee80211_rrm_nhist_info_s{
    u_int16_t num_rpts;
    u_int8_t dstmac[6];
    u_int8_t regclass;
    u_int8_t chnum;
    u_int16_t r_invl;
    u_int16_t m_dur;
    u_int8_t cond;
    u_int8_t c_val;
}ieee80211_rrm_nhist_info_t;

typedef struct ieee80211_rrm_frame_req_info_s{
    u_int8_t dstmac[6];
    u_int8_t peermac[6];
    u_int16_t num_rpts;
    u_int8_t regclass;
    u_int8_t chnum;
    u_int16_t r_invl;
    u_int16_t m_dur;
    u_int8_t ftype;
}ieee80211_rrm_frame_req_info_t;

typedef struct ieee80211_rrm_lcireq_info_s
{
    u_int8_t dstmac[6];
    u_int16_t num_rpts;
    u_int8_t location;
    u_int8_t lat_res;
    u_int8_t long_res;
    u_int8_t alt_res;
    u_int8_t azi_res;
    u_int8_t azi_type;
}ieee80211_rrm_lcireq_info_t;

typedef struct ieee80211_rrm_stastats_info_s{
    u_int8_t dstmac[6];
    u_int16_t num_rpts;
    u_int16_t m_dur;
    u_int16_t r_invl;
    u_int8_t  gid;
}ieee80211_rrm_stastats_info_t;

typedef struct ieee80211_rrm_tsmreq_info_s {
    u_int16_t   num_rpt;
    u_int16_t   rand_ivl;
    u_int16_t   meas_dur;
    u_int8_t    reqmode;
    u_int8_t    reqtype;
    u_int8_t    tid;
    u_int8_t    macaddr[6];
    u_int8_t    bin0_range;
    u_int8_t    trig_cond;
    u_int8_t    avg_err_thresh;
    u_int8_t    cons_err_thresh;
    u_int8_t    delay_thresh;
    u_int8_t    meas_count;
    u_int8_t    trig_timeout;
}ieee80211_rrm_tsmreq_info_t;

typedef struct ieee80211_rrm_nrreq_info_s {
    u_int8_t dialogtoken;
    u_int8_t ssid[32];
    u_int8_t ssid_len;
}ieee80211_rrm_nrreq_info_t;

struct ieee80211_rrmreq_info {
    u_int8_t rm_dialogtoken;
    u_int8_t rep_dialogtoken;
    u_int8_t bssid[6];
    u_int16_t duration;
    u_int8_t chnum;
    u_int8_t regclass;
    u_int8_t gid;
    u_int8_t location; /* Location of requesting/reporting station */
    u_int8_t lat_res;  /* Latitute resolution */
    u_int8_t long_res; /* Longitude resolution */
    u_int8_t alt_res;  /* Altitude resolution */
    u_int8_t reject_type;
    u_int8_t reject_mode;
};

typedef struct ieee80211_rrm_lci_data_s
{
  u_int8_t id;
  u_int8_t len;
  u_int8_t lat_res;
  u_int8_t alt_type;
  u_int8_t long_res;
  u_int8_t alt_res;
  u_int8_t azi_res;
  u_int8_t alt_frac;
  u_int8_t datum;
  u_int8_t azi_type;
  u_int16_t lat_integ;
  u_int16_t long_integ;
  u_int16_t azimuth;
  u_int32_t lat_frac;
  u_int32_t long_frac;
  u_int32_t alt_integ;
}ieee80211_rrm_lci_data_t;

typedef struct ieee80211_rrm_statsgid10_s{
    u_int8_t ap_avg_delay;
    u_int8_t be_avg_delay;
    u_int8_t bk_avg_delay;
    u_int8_t vi_avg_delay;
    u_int8_t vo_avg_delay;
    u_int16_t st_cnt;
    u_int8_t ch_util;
}ieee80211_rrm_statsgid10_t;

typedef struct ieee80211_rrm_statsgid0_s{
    u_int32_t txfragcnt;
    u_int32_t mcastfrmcnt;
    u_int32_t failcnt;
    u_int32_t rxfragcnt;
    u_int32_t mcastrxfrmcnt;
    u_int32_t fcserrcnt;
    u_int32_t txfrmcnt;
}ieee80211_rrm_statsgid0_t;

typedef struct ieee80211_rrm_statsgid1_s{
    u_int32_t rty;
    u_int32_t multirty;
    u_int32_t frmdup;
    u_int32_t rtsuccess;
    u_int32_t rtsfail;
    u_int32_t ackfail;
}ieee80211_rrm_statsgid1_t;

typedef struct ieee80211_rrm_statsgidupx_s {
    u_int32_t qostxfragcnt;
    u_int32_t qosfailedcnt;
    u_int32_t qosrtycnt;
    u_int32_t multirtycnt;
    u_int32_t qosfrmdupcnt;
    u_int32_t qosrtssuccnt;
    u_int32_t qosrtsfailcnt;
    u_int32_t qosackfailcnt;
    u_int32_t qosrxfragcnt;
    u_int32_t qostxfrmcnt;
    u_int32_t qosdiscadrfrmcnt;
    u_int32_t qosmpdurxcnt;
    u_int32_t qosrtyrxcnt;
}ieee80211_rrm_statsgidupx_t;

typedef struct ieee80211_rrm_tsm_data_s
{
    u_int8_t tid;
    u_int8_t brange;
    u_int8_t mac[6];
    u_int32_t tx_cnt;
    u_int32_t discnt;
    u_int32_t multirtycnt;
    u_int32_t cfpoll;
    u_int32_t qdelay;
    u_int32_t txdelay;
    u_int32_t bin[6];
}ieee80211_rrm_tsm_data_t;

typedef struct ieee80211_frmcnt_data_s
{
    u_int8_t phytype;
    u_int8_t arcpi;
    u_int8_t lrsni;
    u_int8_t lrcpi;
    u_int8_t antid;
    u_int8_t ta[6];
    u_int8_t bssid[6];
    u_int16_t frmcnt;
}ieee80211_rrm_frmcnt_data_t;

typedef struct ieee80211_rrm_lm_data_s
{
    u_int8_t tx_pow;
    u_int8_t lmargin;
    u_int8_t rxant;
    u_int8_t txant;
    u_int8_t rcpi;
    u_int8_t rsni;
}ieee80211_rrm_lm_data_t;

typedef struct ieee80211_rrm_noise_data_s
{
    u_int8_t antid;
    int8_t anpi;
    u_int8_t ipi[11];
}ieee80211_rrm_noise_data_t;

typedef struct ieee80211_rrm_node_stats_s 
{
    ieee80211_rrm_statsgid0_t   gid0;
    ieee80211_rrm_statsgid1_t   gid1;
    ieee80211_rrm_statsgidupx_t gidupx[8]; /* from 0 to seven */
    ieee80211_rrm_statsgid10_t  gid10;
    ieee80211_rrm_tsm_data_t    tsm_data;
  
    /* as per specification length can maximum be 228 */
    ieee80211_rrm_frmcnt_data_t frmcnt_data[12];
    ieee80211_rrm_lm_data_t     lm_data;
    ieee80211_rrm_lci_data_t    ni_rrm_lciinfo; /* RRM LCI information of this node */
    ieee80211_rrm_lci_data_t    ni_vap_lciinfo; /* RRM LCI information of VAP wrt this node */
}ieee80211_rrm_node_stats_t;


/* RRM statistics */
typedef struct ieee80211_rrmstats_s 
{
    u_int8_t                    chann_load[IEEE80211_RRM_CHAN_MAX];
    ieee80211_rrm_noise_data_t  noise_data[IEEE80211_RRM_CHAN_MAX];
    ieee80211_rrm_node_stats_t  ni_rrm_stats;
}ieee80211_rrmstats_t;

/* to user level */
typedef struct ieee80211_bcnrpt_s {
    u_int8_t bssid[6];
    u_int8_t rsni;
    u_int8_t rcpi;
    u_int8_t chnum;
    u_int8_t more;
}ieee80211_bcnrpt_t; 

typedef struct ieee80211req_rrmstats_s {
    u_int32_t index;
    u_int32_t data_size;
    void *data_addr;
}ieee80211req_rrmstats_t;

#endif /* _IEEE80211_RRM_PROTO_H_ */
