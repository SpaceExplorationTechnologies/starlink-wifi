/*
 * Copyright (c) 2013, 2016-2018 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * 2013, 2016 Qualcomm Atheros, Inc.
 */

/**
 * This file defines WMI services bitmap and the set of WMI services . 
 * defines macrso to set/clear/get different service bits from the bitmap. 
 * the service bitmap is sent up to the host via WMI_READY command.
 *    
 */

#ifndef _WMI_SERVICES_H_
#define _WMI_SERVICES_H_


#ifdef __cplusplus
extern "C" {
#endif



typedef  enum  {
    WMI_SERVICE_BEACON_OFFLOAD=0,     /* beacon offload */
    WMI_SERVICE_SCAN_OFFLOAD=1,         /* scan offload */
    WMI_SERVICE_ROAM_OFFLOAD=2,         /* roam offload */
    WMI_SERVICE_BCN_MISS_OFFLOAD=3,     /* beacon miss offload */
    WMI_SERVICE_STA_PWRSAVE=4,          /* fake sleep + basic power save */
    WMI_SERVICE_STA_ADVANCED_PWRSAVE=5, /* uapsd, pspoll, force sleep */
    WMI_SERVICE_AP_UAPSD=6,             /* uapsd on AP */
    WMI_SERVICE_AP_DFS=7,               /* DFS on AP */
    WMI_SERVICE_11AC=8,                 /* supports 11ac */
    WMI_SERVICE_BLOCKACK=9,             /* Supports triggering ADDBA/DELBA from host*/
    WMI_SERVICE_PHYERR=10,               /* PHY error */
    WMI_SERVICE_BCN_FILTER=11,           /* Beacon filter support */
    WMI_SERVICE_RTT=12,                  /* RTT (round trip time) support */
    WMI_SERVICE_RATECTRL=13,             /* Rate-control */
    WMI_SERVICE_WOW=14,                  /* WOW Support */
    WMI_SERVICE_RATECTRL_CACHE=15,       /* Rate-control caching */
    WMI_SERVICE_IRAM_TIDS=16,            /* TIDs in IRAM */
    WMI_SERVICE_BURST=17,                /* SIFS spaced burst */
    WMI_SERVICE_SMART_ANTENNA_SW_SUPPORT=18,        /* SMARTANTENNA Software support */
    WMI_SERVICE_GTK_OFFLOAD=19,                /* GTK offload */
    WMI_SERVICE_SCAN_SCH=20,                   /* Scan Scheduler Service */
    WMI_SERVICE_CSA_OFFLOAD=21,          /* CSA offload service */
    WMI_SERVICE_CHATTER=22,              /* Chatter service */
    WMI_SERVICE_COEX_FREQAVOID=23,       /* FW report freq range to avoid */
    WMI_SERVICE_PACKET_POWER_SAVE=24,   /* packet power save service */
    WMI_SERVICE_FORCE_FW_HANG=25,        /* Service to test the firmware recovery mechanism */
    WMI_SERVICE_SMART_ANTENNA_HW_SUPPORT=26, /* Smart Antenna HW support */
    WMI_SERVICE_GPIO=27,                 /* GPIO service */
    WMI_STA_UAPSD_BASIC_AUTO_TRIG=28,          /* Basic version of station UAPSD AC Trigger Generation Method with
                                             * variable tigger periods (service, delay, and suspend intervals) */
    WMI_STA_UAPSD_VAR_AUTO_TRIG=29,            /* Station UAPSD AC Trigger Generation Method with variable 
                                             * trigger periods (service, delay, and suspend intervals) */
    WMI_SERVICE_STA_KEEP_ALIVE=30,             /* Serivce to support the STA KEEP ALIVE mechanism */
    WMI_SERVICE_TX_ENCAP=31,                   /* Packet type for TX encapsulation */
    WMI_SERVICE_AP_PS_DETECT_OUT_OF_SYNC=32,   /* detect out-of-sync sleeping stations */
    WMI_SERVICE_EARLY_RX=33,                   /* adaptive early-rx feature */
    WMI_SERVICE_ENHANCED_PROXY_STA=34,         /* Enhanced ProxySTA mode support */
    WMI_SERVICE_TT=35,                         /* Thermal throttling support */
    WMI_SERVICE_ATF=36,                        /* Air Time Fairness support */
    WMI_SERVICE_PEER_CACHING=37,         /* QCache support (caching inactive peers to the host) */
    WMI_SERVICE_COEX_GPIO=38,            /* BTCOEX GPIO support */
    WMI_SERVICE_AUX_SPECTRAL_INTF=39,    /* Aux Radio enhancement support for ignoring spectral scan intf from main radios */
    WMI_SERVICE_AUX_CHAN_LOAD_INTF=40,   /* Aux Radio enhancement support for ignoring chan load intf from main radios*/
    WMI_SERVICE_BSS_CHANNEL_INFO_64=41,  /* BSS channel info (freq, noise floor, 64-bit counters) event support */
    WMI_SERVICE_EXT_RES_CFG_SUPPORT=42,  /* Support for extended resource configuration */
    WMI_SERVICE_MESH=43,                 /* MESH Service Support */
    WMI_SERVICE_RESTRT_CHNL_SUPPORT=44,  /* Restricted Channel Support */
    WMI_SERVICE_PEER_STATS=45,           /* support for per peer stats */
    WMI_SERVICE_MESH_11S=46,             /* 11S MESH Service Support */
    WMI_SERVICE_PERIODIC_CHAN_STAT_SUPPORT=47, /* periodic channel stats service */
    WMI_SERVICE_TX_MODE_PUSH_ONLY=48,    /* support only push mode, no queue in host */
    WMI_SERVICE_TX_MODE_PUSH_PULL=49,    /* support push and pull, host maintains queue for data packet */
    WMI_SERVICE_TX_MODE_DYNAMIC=50,      /* support dynamic switch between push and pull modes */
    WMI_SERVICE_VDEV_RX_FILTER=51,       /* Support per-vdev specs of which rx frames to filter out */
    WMI_SERVICE_BTCOEX=52,               /* Support BlueTooth coexistence */
    WMI_SERVICE_CHECK_CAL_VERSION=53,    /* Support cal version check */
    WMI_SERVICE_DBGLOG_WARN2=54,         /* Support a 2nd level of WARN in dbglog */
    WMI_SERVICE_BTCOEX_DUTY_CYCLE=55,    /* Support BlueTooth coexistence duty cycle */
    WMI_SERVICE_4_WIRE_COEX_SUPPORT=56,  /* Support for 4 wire COEX between WiFi, BT, ZB and Thread */
    WMI_SERVICE_EXTENDED_NSS_SUPPORT=57, /* Support for Extended NSS - VHT160/VHT80_80 Max NSS values */
    WMI_SERVICE_PROG_GPIO_BAND_SELECT=58,/* Support GPIO programming for specifying the band of operation */
    WMI_SERVICE_SMART_LOGGING_SUPPORT=59,/* Support for smart logging */
    WMI_SERVICE_TDLS=60,                 /* TDLS support - both implicit and explicit */
    WMI_SERVICE_TDLS_OFFCHAN=61,         /* TDLS off channel support */
    WMI_SERVICE_TDLS_UAPSD_BUFFER_STA=62,/* TDLS UAPSD Buffer STA support */
    WMI_SERVICE_TDLS_UAPSD_SLEEP_STA=63, /* TDLS UAPSD Sleep STA support */

    WMI_MAX_SERVICE=64,                  /* max service */

    /*
     * NOTE:
     * WMI service IDs above this demarcation use the old method of
     * determining which bit corresponds to the service ID, using bits
     * 3:0 within each element of the the service bitmap array.
     * (See WMI_SERVICE_ENABLE_LEGACY.)
     * WMI service IDs below this demarcation use the new method of
     * determining which bit corresponds to the service ID, using bits
     * 31:4 within each element of the service bitmap array.
     * (See WMI_SERVICE_ENaBLE_EXT.)
     */

    WMI_SERVICE_TDLS_CONN_TRACKER_IN_HOST_MODE=64, /* FW supports a new mode that allows to run connection tracker in host */
    WMI_SERVICE_TDLS_EXPLICIT_MODE_ONLY=65,        /* TDLS support - explicit mode only */
    WMI_SERVICE_TDLS_WIDER_BANDWIDTH=66,           /* STA supports a wider bandwidth than the BSS bandwidth for a TDLS direct link */
    WMI_SERVICE_HTT_MGMT_TX_COMP_VALID_FLAGS=67,   /* FW HTT_MGMT_TX_COMPLETION header flags are valid */
    WMI_SERVICE_HOST_DFS_CHECK_SUPPORT=68,         /* Host DFS Check support by FW indication to host */
    WMI_SERVICE_TPC_STATS_FINAL=69,                /* Support for TPC Stats */
    WMI_SERVICE_CFR_CAPTURE_SUPPORT=70,            /* Support to capture uncompressed Channel Frequency Response (CFR) */
    WMI_SERVICE_TX_DATA_ACK_RSSI=71,               /* Support Data ACK RSSI in HTT Tx Compeletion indication */
    WMI_SERVICE_CFR_CAPTURE_IND_MSG_TYPE_1=72,     /* Message type HTT_PEER_CFR_CAPTURE_MSG_TYPE_1 in HTT_T2H_MSG_TYPE_CFR_DUMP_COMPL_IND */
    WMI_SERVICE_PER_PACKET_SW_ENCRYPT=73,          /* Support per packet software encryption */
    WMI_SERVICE_PEER_TID_CONFIGS_SUPPORT=74,       /* Support TID specific configuratinos per peer (ack,aggr,retry,rate) */
    WMI_SERVICE_VDEV_BCN_RATE_CONTROL=75,          /* Support VDEV level beacon rate control configurations */
    WMI_SERVICE_VDEV_DIFFERENT_BEACON_INTERVAL_SUPPORT=76, /* Support different beacon intervals on different VDEVs */
    WMI_SERVICE_HTT_ASSERT_TRIGGER_SUPPORT=77,     /* Support for host to trigger assert in FW when WMI CE is stuck */  
    WMI_SERVICE_VDEV_FILTER_NEIGHBOR_RX_PACKETS=78,/* Support to filter for Neighbor Rx Packets at VDEV level */
    WMI_SERVICE_VDEV_DISABLE_4_ADDR_SRC_LRN_SUPPORT=79, /* Support to disable source port learning for 4-addr frames in FW per VDEV */

    /* ADD NEW SERVICE IDS HERE */

} WMI_SERVICE;

/*
 * WMI_SERVICE_BM_SIZE is based on the legacy method of using only
 * bits 3:0 from each service bitmap array element.
 */
#define WMI_SERVICE_BM_SIZE   ((WMI_MAX_SERVICE + sizeof(A_UINT32)- 1)/sizeof(A_UINT32))
/*
 * WMI_EXT_MAX_SERVICE is based on the extension method of using all bits
 * from each service bitmap array element.
 */
#define WMI_EXT_MAX_SERVICE   ((WMI_SERVICE_BM_SIZE)*32) /* 512 */

/*
 * For WMI service IDs < 64, use the legacy method for turning on
 * the WMI service bit corresponding to the WMI service.
 * This legacy method uses bits 3:0 within each element of the
 * service bitmap array.
 */
#define WMI_SERVICE_ENABLE_LEGACY(pwmi_svc_bmap,svc_id) \
    ( (pwmi_svc_bmap)[(svc_id)/4] |= \
         (1 << ((svc_id)%4)) ) 

#define WMI_SERVICE_DISABLE_LEGACY(pwmi_svc_bmap,svc_id) \
    ( (pwmi_svc_bmap)[(svc_id)/4] &=  \
      ( ~(1 << ((svc_id)%4)) ) ) 
      
#define WMI_SERVICE_IS_ENABLED_LEGACY(pwmi_svc_bmap,svc_id) \
    ( ((pwmi_svc_bmap)[(svc_id)/4] &  \
       (1 << ((svc_id)%4)) ) != 0) 

/*
 * For WMI service IDs >= 64, use the extension method for turning on
 * the WMI service bit corresponding to the WMI service.
 * This extension method uses bits 31:4 within each element of the
 * service bitmap array.
 */
#define WMI_SERVICE_ENABLE_EXT(pwmi_svc_bmap,svc_id_ext) \
    ( (pwmi_svc_bmap)[(svc_id_ext)/28] |= \
         (1 << ((((svc_id_ext)%28) & 0x1f) + 4)) ) 

#define WMI_SERVICE_DISABLE_EXT(pwmi_svc_bmap,svc_id_ext) \
    ( (pwmi_svc_bmap)[(svc_id_ext)/28] &=  \
      ( ~(1 << ((((svc_id_ext)%28) & 0x1f) +4)) ) ) 
      
#define WMI_SERVICE_IS_ENABLED_EXT(pwmi_svc_bmap,svc_id_ext) \
    ( ((pwmi_svc_bmap)[(svc_id_ext)/28] &  \
       (1 << ((((svc_id_ext)%28) & 0x1f) + 4)) ) != 0) 

/*
 * Turn on the WMI service bit corresponding to the WMI service.
 * A different method is used so associate bits to WMI services for
 * service IDs less than 64 (i.e. WMI_MAX_SERICE), versus for 64 and beyond.
 */
#define WMI_SERVICE_ENABLE(pwmi_svc_bmap,svc_id) \
    do { \
        if ((svc_id) < WMI_MAX_SERVICE) { \
            WMI_SERVICE_ENABLE_LEGACY(pwmi_svc_bmap, svc_id); \
        } else { \
            WMI_SERVICE_ENABLE_EXT(pwmi_svc_bmap, (svc_id)-WMI_MAX_SERVICE); \
        } \
    } while (0)

#define WMI_SERVICE_DISABLE(pwmi_svc_bmap,svc_id) \
    do { \
        if ((svc_id) < WMI_MAX_SERVICE) { \
            WMI_SERVICE_DISABLE_LEGACY(pwmi_svc_bmap, svc_id); \
        } else { \
            WMI_SERVICE_DISABLE_EXT(pwmi_svc_bmap, (svc_id)-WMI_MAX_SERVICE); \
        } \
    } while (0)

#define WMI_SERVICE_IS_ENABLED(pwmi_svc_bmap,svc_id) \
    (((svc_id) < WMI_MAX_SERVICE) ? \
        WMI_SERVICE_IS_ENABLED_LEGACY(pwmi_svc_bmap, svc_id) : \
        WMI_SERVICE_IS_ENABLED_EXT(pwmi_svc_bmap, (svc_id)-WMI_MAX_SERVICE)) 


#ifdef __cplusplus
}
#endif

#endif /*_WMI_SERVICES_H_*/
