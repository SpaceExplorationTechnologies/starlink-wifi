/*
 * Copyright (c) 2012-2018 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * 2012-2016 Qualcomm Atheros, Inc.
 */
//------------------------------------------------------------------------------
// <copyright file="wmi_unified.h" company="Atheros">
//    Copyright (c) 2004-2010 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

/**
 * @addtogroup WMIAPI
 *@{
 */

/** @file
 * This file specifies the WMI interface for the  Software Architecture.
 *
 * It includes definitions of all the commands and events. Commands are messages
 * from the host to the target. Events and Replies are messages from the target
 * to the host.
 *
 * Ownership of correctness in regards to WMI commands
 * belongs to the host driver and the target is not required to validate
 * parameters for value, proper range, or any other checking.
 *
 * Guidelines for extending this interface are below.
 *
 * 1. Add new WMI commands ONLY within the specified range - 0x9000 - 0x9fff
 * 2. Use ONLY A_UINT32 type for defining member variables within WMI command/event
 *    structures. Do not use A_UINT8, A_UINT16, A_BOOL or enum types within these structures.
 * 3. DO NOT define bit fields within structures. Implement bit fields using masks
 *    if necessary. Do not use the programming language's bit field definition.
 * 4. Define macros for encode/decode of A_UINT8, A_UINT16 fields within the A_UINT32
 *    variables. Use these macros for set/get of these fields. Try to use this to
 *    optimize the structure without bloating it with A_UINT32 variables for every lower
 *    sized field.
 * 5. Do not use PACK/UNPACK attributes for the structures as each member variable is
 *    already 4-byte aligned by virtue of being a A_UINT32 type.
 * 6. Comment each parameter part of the WMI command/event structure by using the
 *    2 stars at the begining of C comment instead of one star to enable HTML document
 *    generation using Doxygen.
 *
 */

#ifndef _WMI_UNIFIED_H_
#define _WMI_UNIFIED_H_


#ifdef __cplusplus
extern "C" {
#endif

#include <wlan_defs.h>
#include <wmi_services.h>
#include <wlan_wow.h>
#define ATH_MAC_LEN             6               /**< length of MAC in bytes */

/*
 * These don't necessarily belong here; but as the MS/SM macros require
 * ar6000_internal.h to be included, it may not be defined as yet.
 */
#define WMI_F_MS(_v, _f)                                            \
            ( ((_v) & (_f)) >> (_f##_S) )

/*
 * This breaks the "good macro practice" of only referencing each
 * macro field once (to avoid things like field++ from causing issues.)
 */
#define WMI_F_RMW(_var, _v, _f)                                     \
            do {                                                    \
                (_var) &= ~(_f);                                    \
                (_var) |= ( ((_v) << (_f##_S)) & (_f));             \
            } while (0)

/** 2 word representation of MAC addr */
typedef struct {
    /** upper 4 bytes of  MAC address */
    A_UINT32 mac_addr31to0;
    /** lower 2 bytes of  MAC address */
    A_UINT32 mac_addr47to32;
} wmi_mac_addr;

/** macro to convert MAC address from WMI word format to char array */
#define WMI_MAC_ADDR_TO_CHAR_ARRAY(pwmi_mac_addr,c_macaddr) do {               \
     (c_macaddr)[0] =    ((pwmi_mac_addr)->mac_addr31to0) & 0xff;     \
     (c_macaddr)[1] =  ( ((pwmi_mac_addr)->mac_addr31to0) >> 8) & 0xff; \
     (c_macaddr)[2] =  ( ((pwmi_mac_addr)->mac_addr31to0) >> 16) & 0xff; \
     (c_macaddr)[3] =  ( ((pwmi_mac_addr)->mac_addr31to0) >> 24) & 0xff;  \
     (c_macaddr)[4] =    ((pwmi_mac_addr)->mac_addr47to32) & 0xff;        \
     (c_macaddr)[5] =  ( ((pwmi_mac_addr)->mac_addr47to32) >> 8) & 0xff; \
   } while(0)

/** macro to convert MAC address from char array to WMI word format */
#define WMI_CHAR_ARRAY_TO_MAC_ADDR(c_macaddr,pwmi_mac_addr)  do { \
    (pwmi_mac_addr)->mac_addr31to0  =                                   \
        ( (c_macaddr)[0] | ((c_macaddr)[1] << 8)                           \
               | ((c_macaddr)[2] << 16) | ((c_macaddr)[3] << 24) );         \
    (pwmi_mac_addr)->mac_addr47to32  =                                  \
                  ( (c_macaddr)[4] | ((c_macaddr)[5] << 8));             \
   } while(0)


#define WMI_GET_BITS(_val,_index,_num_bits)                          \
    (((_val) >> (_index)) & ((1 << (_num_bits)) - 1))

#define WMI_SET_BITS(_var,_index,_num_bits,_val) do {                \
        (_var) &= ~(((1 << (_num_bits)) - 1) << (_index));           \
        (_var) |= (((_val) & ((1 << (_num_bits)) - 1)) << (_index)); \
    } while (0)

/**
 * Command IDs and commange events.
 */
typedef enum {
    WMI_START_CMDID = 0x9000,
    WMI_END_CMDID = 0x9FFF, /* WMI_RESERVED_END_CMDID = 0x9FFF */

    WMI_INIT_CMDID,    /**< initialize the wlan sub system */

    /* Scan specific commands */

    /** start scan request to FW  */
    WMI_START_SCAN_CMDID = WMI_START_CMDID, /* WMI_RESERVED_START_CMDID */
    /** stop scan request to FW  */
    WMI_STOP_SCAN_CMDID,
    /** full list of channels as defined by the regulatory that will be used by scanner   */
    WMI_SCAN_CHAN_LIST_CMDID,
    /** overwrite default priority table in scan scheduler   */
    WMI_SCAN_SCH_PRIO_TBL_CMDID,
    /** This command to adjust the priority and min.max_rest_time
     * of an on ongoing scan request.
     */
    WMI_SCAN_UPDATE_REQUEST_CMDID,
    /** echo command mainly used for testing */
    WMI_ECHO_CMDID,

    /* PDEV(physical device) specific commands */
    /** set regulatorty ctl id used by FW to determine the exact ctl power limits */
    WMI_PDEV_SET_REGDOMAIN_CMDID,
    /** set channel. mainly used for supporting monitor mode */
    WMI_PDEV_SET_CHANNEL_CMDID,
    /** set pdev specific parameters */
    WMI_PDEV_SET_PARAM_CMDID,
    /** enable packet log */
    WMI_PDEV_PKTLOG_ENABLE_CMDID,
    /** disable packet log*/
    WMI_PDEV_PKTLOG_DISABLE_CMDID,
    /** set wmm parameters */
    WMI_PDEV_SET_WMM_PARAMS_CMDID,
    /** set HT cap ie that needs to be carried probe requests HT/VHT channels */
    WMI_PDEV_SET_HT_CAP_IE_CMDID,
    /** set VHT cap ie that needs to be carried on probe requests on VHT channels */
    WMI_PDEV_SET_VHT_CAP_IE_CMDID,
    /** set the base MAC address for the physical device */
    WMI_PDEV_SET_BASE_MACADDR_CMDID,

    /** Command to send the DSCP-to-TID map to the target */
    WMI_PDEV_SET_DSCP_TID_MAP_CMDID,
    /** set quiet ie parameters. primarily used in AP mode */
    WMI_PDEV_SET_QUIET_MODE_CMDID,
    /** Enable/Disable Green AP Power Save  */
    WMI_PDEV_GREEN_AP_PS_ENABLE_CMDID,
    /** get TPC config for the current operating channel */
    WMI_PDEV_GET_TPC_CONFIG_CMDID,
    /* VDEV(virtual device) specific commands */
    /** vdev create */
    WMI_VDEV_CREATE_CMDID,
    /** vdev delete */
    WMI_VDEV_DELETE_CMDID,
    /** vdev start request */
    WMI_VDEV_START_REQUEST_CMDID,
    /** vdev restart request (RX only, NO TX, used for CAC period)*/
    WMI_VDEV_RESTART_REQUEST_CMDID,
    /** vdev up request */
    WMI_VDEV_UP_CMDID,
    /** vdev stop request */
    WMI_VDEV_STOP_CMDID,
    /** vdev down request */
    WMI_VDEV_DOWN_CMDID,
    /** vdev stanby response. sent by host in respose to standby request from FW
     *  used part of message exchange with FW to move AP vdev to a new channel
     *  along with STA vdev when the STA vdev moves to a new channel */
    WMI_VDEV_STANDBY_RESPONSE_CMDID,
    /** vdev resume response. sent by host in respose to resume request from FW
     *  used part of message exchange with FW to move AP vdev to a new channel
     *  along with STA vdev when the STA vdev moves to a new channel */
    WMI_VDEV_RESUME_RESPONSE_CMDID,
    /* set a vdev param */
    WMI_VDEV_SET_PARAM_CMDID,
    /* set a key (used for setting per peer unicast and per vdev multicast) */
    WMI_VDEV_INSTALL_KEY_CMDID,

    /* peer specific commands */

    WMI_WLAN_PEER_CACHING_ADD_PEER_CMDID,
    WMI_WLAN_PEER_CACHING_EVICT_PEER_CMDID,
    WMI_WLAN_PEER_CACHING_RESTORE_PEER_CMDID,
	WMI_WLAN_PEER_CACHING_PRINT_ALL_PEERS_INFO_CMDID,
    /** create a peer */
    WMI_PEER_CREATE_CMDID,
    /** delete a peer */
    WMI_PEER_DELETE_CMDID,
    /** flush specific  tid queues of a peer */
    WMI_PEER_FLUSH_TIDS_CMDID,
    /** set a parameter of a peer */
    WMI_PEER_SET_PARAM_CMDID,
    /** set peer to associated state. will cary all parameters determined during assocication time */
    WMI_PEER_ASSOC_CMDID,
    /**add a wds  (4 address ) entry. */
    WMI_PEER_ADD_WDS_ENTRY_CMDID,
    /**update a wds  (4 address ) entry. */
    WMI_PEER_UPDATE_WDS_ENTRY_CMDID,
    /**remove wds  (4 address ) entry. */
    WMI_PEER_REMOVE_WDS_ENTRY_CMDID,
    /**add a proxy sta entry.*/
    WMI_PEER_ADD_PROXY_STA_ENTRY_CMDID,
    /** set up mcast group infor for multicast to unicast conversion */
    WMI_PEER_MCAST_GROUP_CMDID,

    /* beacon/management specific commands */

    /** transmit beacon by reference . used for transmitting beacon on low latency interface like pcie */
    WMI_BCN_TX_CMDID,

    /** transmit beacon by value . used for transmitting beacon both by value */
    WMI_PDEV_SEND_BCN_CMDID,

    /** set the beacon/probe response template. used in beacon offload mode to setup the
     *  the common beacon/probe response template with the FW to be used by FW to generate
     *  beacons/probe responses */
    WMI_BCN_PRB_TMPL_CMDID,
    /** set beacon filter with FW */
    WMI_BCN_FILTER_RX_CMDID,
    /* enable/disable filtering of probe requests in the firmware */
    WMI_PRB_REQ_FILTER_RX_CMDID,
    /** transmit management frame by value. will be deprecated */
    WMI_MGMT_TX_CMDID,
    /** set the probe response template. used in beacon offload mode to setup the
     *  the common probe response template with the FW to be used by FW to generate
     *  probe responses */
    WMI_PRB_TMPL_CMDID,

    /** commands to directly control ba negotiation directly from host. only used in test mode */
    WMI_ADDBA_CLEAR_RESP_CMDID,
    /** send add ba request */
    WMI_ADDBA_SEND_CMDID,
    WMI_ADDBA_STATUS_CMDID,
    /** send del ba */
    WMI_DELBA_SEND_CMDID,
    WMI_ADDBA_SET_RESP_CMDID,
    /** send single VHT MPDU with AMSDU */
    WMI_SEND_SINGLEAMSDU_CMDID,

    /** Station power save specific config */
    /** enable/disable station powersave */
    WMI_STA_POWERSAVE_MODE_CMDID,
    /** set station power save specific parameter */
    WMI_STA_POWERSAVE_PARAM_CMDID,
    /** set station mimo powersave mode */
    WMI_STA_MIMO_PS_MODE_CMDID,

    /** set debug log config */
    WMI_DBGLOG_CFG_CMDID,

    /** DFS-specific commands */
    /** enable DFS (radar detection)*/
    WMI_PDEV_DFS_ENABLE_CMDID,
    /** disable DFS (radar detection)*/
    WMI_PDEV_DFS_DISABLE_CMDID,

    /* QVIT specific command id */
    WMI_PDEV_QVIT_CMDID,

    /* Offload Scan and Roaming related  commands */
    /** set roam scan mode */
    WMI_ROAM_SCAN_MODE,
    /** set roam scan rssi threshold below which roam scan is enabled  */
    WMI_ROAM_SCAN_RSSI_THRESHOLD,
    /** set roam scan period for periodic roam scan mode  */
    WMI_ROAM_SCAN_PERIOD,
    /** set roam scan trigger rssi change threshold   */
    WMI_ROAM_SCAN_RSSI_CHANGE_THRESHOLD,
    /** set roam AP profile   */
    WMI_ROAM_AP_PROFILE,
    /** set offload scan AP profile   */
    WMI_OFL_SCAN_ADD_AP_PROFILE,
    /** remove offload scan AP profile   */
    WMI_OFL_SCAN_REMOVE_AP_PROFILE,
    /** set offload scan period   */
    WMI_OFL_SCAN_PERIOD,

    /* P2P specific commands */
    /**set P2P device info. FW will used by FW to create P2P IE to be carried in probe response
     * generated during p2p listen and for p2p discoverability  */
    WMI_P2P_DEV_SET_DEVICE_INFO,
    /** enable/disable p2p discoverability on STA/AP VDEVs  */
    WMI_P2P_DEV_SET_DISCOVERABILITY,
    /** set p2p ie to be carried in beacons generated by FW for GO  */
    WMI_P2P_GO_SET_BEACON_IE,
    /** set p2p ie to be carried in probe response frames generated by FW for GO  */
    WMI_P2P_GO_SET_PROBE_RESP_IE,
    /** set the vendor specific p2p ie data. FW will use this to parse the P2P NoA
     *  attribute in the beacons/probe responses received.
     *  Note: This command is currently used only for Apple P2P implementation.
     */
    WMI_P2P_SET_VENDOR_IE_DATA_CMDID,


    /** AP power save specific config */
    /** set AP power save specific param */
    WMI_AP_PS_PEER_PARAM_CMDID,
    /** set AP UAPSD coex pecific param */
    WMI_AP_PS_PEER_UAPSD_COEX_CMDID,


    /** Rate-control specific commands */
    /* NOTE:
     * This peer rate retry sched command is used only for
     * Peregrine-family targets.
     */
    WMI_PEER_RATE_RETRY_SCHED_CMDID,

    /** WLAN Profiling commands. */
    WMI_WLAN_PROFILE_TRIGGER_CMDID,
    WMI_WLAN_PROFILE_SET_HIST_INTVL_CMDID,
    WMI_WLAN_PROFILE_GET_PROFILE_DATA_CMDID,
    WMI_WLAN_PROFILE_ENABLE_PROFILE_ID_CMDID,
    WMI_WLAN_PROFILE_LIST_PROFILE_ID_CMDID,

    /** Suspend resume command Ids */
    WMI_PDEV_SUSPEND_CMDID,
    WMI_PDEV_RESUME_CMDID,

    /* Beacon filter commands */
    /** add a beacon filter */
    WMI_ADD_BCN_FILTER_CMDID,
    /** remove a  beacon filter */
    WMI_RMV_BCN_FILTER_CMDID,

    /* WOW Specific WMI commands*/
    /** add pattern for awake */
    WMI_WOW_ADD_WAKE_PATTERN_CMDID,
    /** deleta a wake pattern */
    WMI_WOW_DEL_WAKE_PATTERN_CMDID,
    /** enable/deisable wake event  */
    WMI_WOW_ENABLE_DISABLE_WAKE_EVENT_CMDID,
    /** enable WOW  */
    WMI_WOW_ENABLE_CMDID,
    /** host woke up from sleep event to FW. Generated in response to WOW Hardware event */
    WMI_WOW_HOSTWAKEUP_FROM_SLEEP_CMDID,

    /* RTT measurement related cmd */
    /** reques to make an RTT measurement */
    WMI_RTT_MEASREQ_CMDID,
    /** reques to report a tsf measurement */
    WMI_RTT_TSF_CMDID,
    /** request to start/stop keep-alive frame */
    WMI_RTT_KEEPALIVE_CMDID,

    /* OEM related cmd */
	WMI_OEM_REQ_CMDID,

	/** Nan Request */
	WMI_NAN_CMDID,


    /* F/W stats */
    /** configure spectral scan */
    WMI_VDEV_SPECTRAL_SCAN_CONFIGURE_CMDID,
    /** enable/disable spectral scan and trigger */
    WMI_VDEV_SPECTRAL_SCAN_ENABLE_CMDID,
    /** one time request for stats */
    WMI_REQUEST_STATS_CMDID,

    /* GPIO Configuration */
    WMI_GPIO_CONFIG_CMDID,
    WMI_GPIO_OUTPUT_CMDID,
    WMI_VDEV_RATEMASK_CMDID,

    WMI_CSA_OFFLOAD_ENABLE_CMDID,
    WMI_GTK_OFFLOAD_CMDID,
    /* Q-Boost configuration test commands */
    WMI_QBOOST_CFG_CMDID,
    /** chan switch command */
    WMI_CSA_OFFLOAD_CHANSWITCH_CMDID,
    /** Enable/Disable Smart Antenna */
    WMI_PDEV_SMART_ANT_ENABLE_CMDID,
    /** Set Smart Antenna RX antenna*/
    WMI_PDEV_SMART_ANT_SET_RX_ANTENNA_CMDID,
    /** Set Smart Antenna TX antenna*/
    WMI_PEER_SMART_ANT_SET_TX_ANTENNA_CMDID,
    /** Set Smart Antenna TX train info */
    WMI_PEER_SMART_ANT_SET_TRAIN_INFO_CMDID,
    /** Set SA node config options */
    WMI_PEER_SMART_ANT_SET_NODE_CONFIG_OPS_CMDID,
    WMI_VDEV_SET_KEEPALIVE_CMDID,
    WMI_VDEV_GET_KEEPALIVE_CMDID,
    /* For fw recovery test command */
    WMI_FORCE_FW_HANG_CMDID,

    /** Override the antenna switch table */
    WMI_PDEV_SET_ANTENNA_SWITCH_TABLE_CMDID,
    /** Override the CTL table */
    WMI_PDEV_SET_CTL_TABLE_CMDID,
    /** Override the array gain table */
    WMI_PDEV_SET_MIMOGAIN_TABLE_CMDID,
    /** Set/Get the rate power table in OTP */
    WMI_PDEV_RATEPWR_TABLE_CMDID,
    /** En/disable the rate power and chain mask table in FW*/
    WMI_PDEV_RATEPWR_CHAINMSK_TABLE_CMDID,

    /** FIPS test mode command */
    WMI_PDEV_FIPS_CMDID,
    /* Set thermal throttling params */
    WMI_TT_SET_CONF_CMDID,

    /* set debug and tuning parameters */
    WMI_FWTEST_CMDID,

    /** ATF VDEV REQUEST commands. */
    WMI_VDEV_ATF_REQUEST_CMDID,
    /** ATF PEER REQUEST commands. */
    WMI_PEER_ATF_REQUEST_CMDID,

    /** get CCK ANI level */
    WMI_PDEV_GET_ANI_CCK_CONFIG_CMDID,
    /** get OFDM ANI level */
    WMI_PDEV_GET_ANI_OFDM_CONFIG_CMDID,

    /* reserve one ast entry, this is for qwrap no-ack WAR */
    WMI_PDEV_RESERVE_AST_ENTRY_CMDID,

    /** NF Cal Power dBr/dBm */
    WMI_PDEV_GET_NFCAL_POWER_CMDID,

    /** TxPPDU TPC */
    WMI_PDEV_GET_TPC_CMDID,

    /* get AST table info */
    WMI_PDEV_GET_AST_INFO_CMDID,
    /** Command to send the DSCP-to-TID map to the target for VAP */
    WMI_VDEV_SET_DSCP_TID_MAP_CMDID,

    /** Get Thermal management params **/
    WMI_PDEV_GET_TEMPERATURE_CMDID,
    /*Get Pdev information */
    WMI_PDEV_GET_INFO_CMDID,
    /*Get VDEv information */
    WMI_VDEV_GET_INFO_CMDID,
    /* Configure filter for Neighbor Rx Pkt (smart mesh selective listening) */
    WMI_VDEV_FILTER_NEIGHBOR_RX_PACKETS_CMDID,

    /* LTEU cal start */
    WMI_MU_CAL_START_CMDID,
    /** update clear-channel assessment parameters */
    WMI_SET_CCA_PARAMS_CMDID,
    /** req report (and optionally reset) of chan info (NF, cycle counters) */
    WMI_PDEV_BSS_CHAN_INFO_REQUEST_CMDID,
    /** Extended resource config (to be sent only once at boot-up) */
    WMI_EXT_RESOURCE_CFG_CMDID,

    /** set the capabilties IE, e.g. for extended caps in probe requests,
     *  assoc req etc for frames FW locally generates */
    WMI_VDEV_SET_IE_CMDID,

    /** Provide the target with parameters for computing medium utilization
     * for LTE-Unlicensed coexistence.
     */
    WMI_SET_LTEU_CONFIG_CMDID,

    /** ATF SSID GROUPING REQUEST command. */
    WMI_ATF_SSID_GROUPING_REQUEST_CMDID,

    /** ATF Peer Extended Request command. */
    WMI_PEER_ATF_EXT_REQUEST_CMDID,

    /** Periodic channel stats request command */
    WMI_SET_PERIODIC_CHANNEL_STATS_CONFIG,

    /** Bandwidth Fairness (BWF) Peer Request Commands */
    WMI_PEER_BWF_REQUEST_CMDID,

    /** BT coex config command */
    WMI_BTCOEX_CFG_CMDID,

    /** For a specific peer to display its mu packet transmitted count */
    WMI_PEER_TX_MU_TXMIT_COUNT_CMDID,

    /** For a specific peer to reset its mu packet transmitted count */
    WMI_PEER_TX_MU_TXMIT_RSTCNT_CMDID,

    /** For a specific peer to display user position list in different mu groups  */
    WMI_PEER_GID_USERPOS_LIST_CMDID,

    /** For displaying cal version and board MCN details */
    WMI_PDEV_CHECK_CAL_VERSION_CMDID,

    /** coex _VERSION_4 onwards, this command will be used as TLV to support
     * multiple coex algorithms WMI_BTCOEX_CFG_CMDID will still be used for
     * coex VERSION_1, VERSION_2 and VERSION_3
     */
    WMI_COEX_VERSION_CFG_CMID,

    /** Get pdev current RX filter value */
    WMI_PDEV_GET_RX_FILTER_CMDID,

    /** Extended NSS support */
    WMI_PDEV_EXTENDED_NSS_CFG_CMDID,

    /** Configure scan NAC rssi */
    WMI_VDEV_SET_SCAN_NAC_RSSI_CMDID,

    /** Program GPIO for band select */
    WMI_PROG_GPIO_BAND_SELECT_CMDID,

    /** Configure smart logging - Message type is wmi_smart_logging
     *
     * If 'log_case' in the message 'wmi_smart_logging' is 0, then
     * the enable/disable of logging feature communicated through
     * 'enable' in the message 'wmi_smart_logging' applies for the
     * entire smart logging facility.
     *
     * If 'log_case' is non-zero, the enable/disable applies only for the
     * corresponding feature of the smart logging facility, which is of type
     * 'WMI_SMART_LOG_SCENARIO'.
     *
     * Bit 31 of 'log_case' will be used for future extension. i.e., if Bit 31
     * is set, then, another set of logging cases can be indicated through
     * 'log_case_ext_1' which can have a different type list
     * (e.g., WMI_SMART_LOG_SCENARIO_EXT_1)
     */
    WMI_CONFIG_SMART_LOGGING_CMDID,

    /** Indicate fatal event to Firmware to collect additional logs
     * Message type is wmi_debug_fatal_condition_list
     *
     * Firmware on receiving this command is expected to perform the following:
     *  - Log any information needed to debug this fatal condition. These are
     *    standard messages carried over the existing WMI message
     *    WMI_DEBUG_MESG_EVENTID
     *  - Flush any pending logs in the FW buffer: These flushed logs would also
     *    be carried just as they are being done today using
     *    WMI_DEBUG_MESG_EVENTID
     *  - Send a completion event to the Host using
     *    WMI_DEBUG_FATAL_CONDITION_EVENTID'
     * */
    WMI_DEBUG_FATAL_CONDITION_CMDID,

    /* Return TSF Timer value */
    WMI_GET_TSF_TIMER_CMDID,

    /** Request the target to provide its final tx power table for the current operating channel */
    WMI_PDEV_GET_TPC_TABLE_CMDID,

    /* Set the time duration in msec between consecutive sifs trigger frames in TDMA mode */
    WMI_VDEV_SIFS_TRIGGER_TIME_CMDID,

    /** To send list of wds entries from FW */
    WMI_PDEV_WDS_ENTRY_LIST_CMDID,

    /** enable/disable TDLS */
    WMI_TDLS_SET_STATE_CMDID,

    /** set tdls peer state */
    WMI_TDLS_PEER_UPDATE_CMDID,

    /** TDLS Offchannel control */
    WMI_TDLS_SET_OFFCHAN_MODE_CMDID,

    /* transmit FILS Discovery frame by value  */
    WMI_PDEV_SEND_FD_CMDID,

    /* Enable or Disable FILS feature */
    WMI_ENABLE_FILS_CMDID,

    /** set the bridge MAC address of the physical device for the platform.
     * This configuration is used when bridging WLAN/WLAN traffic across
     * two BSS "cells", or when bridging WLAN/ethernet traffic.
     * The target needs to know the bridging MAC address so it can filter
     * out frames that are addressed to the bridging node itself,
     * rather that to the bridged network behind the bridging node.
     */
    WMI_PDEV_SET_BRIDGE_MACADDR_CMDID,

    /** WMM ATF Configuration for Groups */
    WMI_ATF_GROUP_WMM_AC_CONFIG_REQUEST_CMDID,

    /** Host DFS Radar confirmation command */
    WMI_HOST_DFS_RADAR_FOUND_CMDID,

    /** Peer configuration for Channel Frequency Response (CFR) capture
     * of type wmi_peer_cfr_capture_cmd.  The CFR capture is communicated
     * through HTT_T2H_MSG_TYPE_CFR_DUMP_COMPL_IND.
     */
    WMI_PEER_CFR_CAPTURE_CMDID,

    /** TID specific configurations per peer of type
     * wmi_peer_tid_configurations_cmd
     */
    WMI_PEER_TID_CONFIGURATIONS_CMDID,

    /** There is no Beacon offloading support in beeliner codebase.
     * This cmd to pass SWBA and Beacon control definition from HOST to FW
     * Naming convention is followed to keep uniformity for both codebase
     */
    WMI_BCN_OFFLOAD_CTRL_CMDID,

    /** Removes WDS (4-Address) entries,
     * It will remove all the WDS entries (if peer_addr is NULL),
     * or all the entries specific to the given peer address
     * (if a valid peer_addr is specified), or a particular entry.
     */
    WMI_PEER_REMOVE_ALL_WDS_ENTRIES_CMDID,


    /* add new CMDIDs here */

    /** UTF specific WMI commands
     * set fixed value for UTF WMI command so
     * further addition of other WMI commands
     * does not affect the communication between
     * ART2 and UTF
     */
    WMI_PDEV_UTF_CMDID = WMI_END_CMDID -1,
} WMI_CMD_ID;

typedef enum {
    /** WMI service is ready; after this event WMI messages can be sent/received  */
    WMI_SERVICE_READY_EVENTID=0x8000,
    /** WMI is ready; after this event the wlan subsystem is initialized and can process commands. */
    WMI_READY_EVENTID,
    /** event carries buffered debug messages  */
    WMI_DEBUG_MESG_EVENTID,
    WMI_START_EVENTID = 0x9000,
    WMI_END_EVENTID = 0x9FFF,

    /** Scan specific events */
    WMI_SCAN_EVENTID = WMI_START_EVENTID,

    /** echo event in response to echo command */
    WMI_ECHO_EVENTID,

    /** FW stats(periodic or on shot)  */
    WMI_UPDATE_STATS_EVENTID,

    /* Instantaneous RSSI event */
    WMI_INST_RSSI_STATS_EVENTID,
    /* VDEV specific events */
    /** VDEV started event in response to VDEV_START request */
    WMI_VDEV_START_RESP_EVENTID,

    /** vdev stanby request.this is
     *  used part of message exchange with FW to move AP vdev to a new channel
     *  along with STA vdev when the STA vdev moves to a new channel */
    WMI_VDEV_STANDBY_REQ_EVENTID,
    /** vdev resume request.this is
     *  used part of message exchange with FW to move AP vdev to a new channel
     *  along with STA vdev when the STA vdev moves to a new channel */
    WMI_VDEV_RESUME_REQ_EVENTID,
    /** vdev stopped event , generated in response to VDEV_STOP request */
    WMI_VDEV_STOPPED_EVENTID,

    /* peer  specific events */
    /** FW reauet to kick out the station for reasons like inactivity,lack of response ..etc */
    WMI_PEER_STA_KICKOUT_EVENTID,

    /* beacon/mgmt specific events */
    /** software beacon alert event to Host requesting host to Queue a beacon for transmission
        use only in host beacon mode */
    WMI_HOST_SWBA_EVENTID,
    /** beacon tbtt offset event indicating the tsf offset of the tbtt from the theritical value.
        tbtt offset is normally 0 and will be non zero if there are multiple VDEVs operating in
        staggered beacon transmission mode */
    WMI_TBTTOFFSET_UPDATE_EVENTID,
    /** RX management frame. the entire frame is carried along with the event.  */
    WMI_MGMT_RX_EVENTID,

    /** Channel stats event    */
    WMI_CHAN_INFO_EVENTID,

    /** PHY Error specific WMI event */
    WMI_PHYERR_EVENTID,

    /** Roam event to trigger roaming on host */
    WMI_ROAM_EVENTID,

    /** matching AP found from list of profiles */
    WMI_PROFILE_MATCH,

    /** debug print message used for tracing FW code while debugging  */
    WMI_DEBUG_PRINT_EVENTID,
    /** VI spoecific event  */
    WMI_PDEV_QVIT_EVENTID,
    /** FW code profile data in response to profile request  */
    WMI_WLAN_PROFILE_DATA_EVENTID,

    /*RTT related event ID*/
    /** RTT measurement report */
    WMI_RTT_MEASUREMENT_REPORT_EVENTID,
    /** TSF measurement report */
    WMI_TSF_MEASUREMENT_REPORT_EVENTID,
    /** RTT error report */
    WMI_RTT_ERROR_REPORT_EVENTID,
    /** RTT keep-alive report */
    WMI_RTT_KEEPALIVE_EVENTID,

    /* OEM Event */
    WMI_OEM_CAPABILITY_EVENTID, // TODO RTT WMI: Make sure Host and FW use the same IDs
    WMI_OEM_MEASUREMENT_REPORT_EVENTID,
    WMI_OEM_ERROR_REPORT_EVENTID,

    /* NAN Event */
    WMI_NAN_EVENTID,


    /** WOW wake up host event.generated in response to WMI_WOW_HOSTWAKEUP_FROM_SLEEP_CMDID.
        will cary wake reason */
    WMI_WOW_WAKEUP_HOST_EVENTID,
    WMI_GTK_OFFLOAD_STATUS_EVENTID,
    WMI_GTK_REKEY_FAIL_EVENTID,
    /** DCS wlan or non-wlan interference event
     */
    WMI_DCS_INTERFERENCE_EVENTID,

    /** TPC config for the current operating channel */
    WMI_PDEV_TPC_CONFIG_EVENTID,

    WMI_CSA_HANDLING_EVENTID,
    WMI_GPIO_INPUT_EVENTID,
    /* add new event IDs here */

    /** Valid rate code list for peer  */
    WMI_PEER_RATECODE_LIST_EVENTID,

    /** Send general buffer content with variable size */
    WMI_GENERIC_BUFFER_EVENTID,

    /* Mcast buffer release event ID */
    WMI_MCAST_BUF_RELEASE_EVENTID,

    /* List of mcast entry aged-out */
    WMI_MCAST_LIST_AGEOUT_EVENTID,
    /** UTF specific WMI event
     * set fixed value for UTF WMI EVT ID so
     * further addition of other WMI EVT IDs
     * does not affect the communication between
     * ART2 and UTF
     */
    /* Indicate the keepalive parameters */
    WMI_VDEV_GET_KEEPALIVE_EVENTID,

    WMI_WDS_PEER_EVENTID,

    WMI_PEER_STA_PS_STATECHG_EVENTID,
    /** FIPS test mode event */
    WMI_PDEV_FIPS_EVENTID,
    /** Thermal throttling stats */
    WMI_TT_STATS_EVENTID,

    /** Channel hopping avoidance */
    WMI_PDEV_CHANNEL_HOPPING_EVENTID,

    /** CCK ANI level event */
    WMI_PDEV_ANI_CCK_LEVEL_EVENTID,

    /** OFDM ANI level event */
    WMI_PDEV_ANI_OFDM_LEVEL_EVENTID,

    /** reserve one ast entry event, this is for qwrap no-ack WAR */
    WMI_PDEV_RESERVE_AST_ENTRY_EVENTID,

    /** NF Cal Power in DBR/DBM */
    WMI_PDEV_NFCAL_POWER_EVENTID,

    /** Tx PPDU params */
    WMI_PDEV_TPC_EVENTID,

    /** Get AST table info event */
    WMI_PDEV_GET_AST_INFO_EVENTID,

    /** Thermal Management event */
    WMI_PDEV_TEMPERATURE_EVENTID,

    /** NF Cal Power in DBR/DBM for all channels */
    WMI_PDEV_NFCAL_POWER_ALL_CHANNELS_EVENTID,

    /** provide noise floor and cycle counts for a channel */
    WMI_PDEV_BSS_CHAN_INFO_EVENTID,

    /** provide a Medium Utilization (MU) report */
    WMI_MU_REPORT_EVENTID,

    /** inform the host to block or unblock tx data for a given peer or vdev */
    WMI_TX_DATA_TRAFFIC_CTRL_EVENTID,

    /** For a specific peer to display tx mu packet transmitted count */
    WMI_PEER_TX_MU_TXMIT_COUNT_EVENTID,

    /** For a speicific peer to display user position list in different mu groups  */
    WMI_PEER_GID_USERPOS_LIST_EVENTID,

    /** For providing the caldata version to host */
    WMI_PDEV_CHECK_CAL_VERSION_EVENTID,

    /** For providing the atf peer token info to host */
    WMI_ATF_PEER_STATS_EVENTID,

    /** For providing pdev current RX filter to host */
    WMI_PDEV_GET_RX_FILTER_EVENTID,

    /* NAC RSSI event */
    WMI_NAC_RSSI_EVENTID,

    /** Indicate fatal event to Host to collect additional logs
     * Message type is wmi_debug_fatal_condition_list
     *
     * This event will be sent by the Firmware under two scenarios:
     * - FW detecting any fatal scenario: On detecting such a scenario, FW is
     *   expected to log any necessary information and flush any pending logs,
     *   if any.
     * - Response to WMI_DEBUG_FATAL_CONDITION_CMDID
     * Host on receiving this event is expected to do the following:
     * - Log any information needed to debug this fatal condition. This is
     *   needed in case of indication only. Not needed for completion since
     *   Host was the one that originally identified the error
     * - Log the recevied logs in presistent memory
     */
    WMI_DEBUG_FATAL_CONDITION_EVENTID,

    /* WMI_GET_TSF_TIMER Response event */
    WMI_GET_TSF_TIMER_RESP_EVENTID,

    /** Request the target to provide its final tx power table for the current operating channel */
    WMI_PDEV_TPC_TABLE_EVENTID,

    /** To send list of wds entries from FW */
    WMI_PDEV_WDS_ENTRY_LIST_EVENTID,

    /** TDLS Event */
    WMI_TDLS_PEER_EVENTID,

    /** software FILS Discovery alert event to Host requesting host to queue a FILS discovery frame for transmission */
    WMI_HOST_SWFDA_EVENTID,

    /** To send the percentage of air time available per AC based on the Estimate Service Parameters (ESP) calculation (802.11mc) */
    WMI_ESP_ESTIMATE_EVENTID,

    /** Host DFS check status sent to host to complete the handshake. FW
     *  confirms to host, Spoof radar or real radar or radar detection failed.
     */
    WMI_HOST_DFS_STATUS_CHECK_EVENTID,

    WMI_PDEV_UTF_EVENTID = WMI_END_EVENTID-1,
} WMI_EVT_ID;

#define WMI_FATAL_CONDITION_DEFAULT_TYPE_SUBTYPE_DATA 0

#define WMI_SMART_LOG_SCENARIO_SET(flag, scenario) ((flag) |= (scenario))
#define WMI_SMART_LOG_SCENARIO_GET(flag, scenario) ((flag) &  (scenario))

typedef enum {
    /* WMI_SMART_LOG_ALL - this value enables all the smart logging features */
    WMI_SMART_LOG_ALL                      =        0x0,
    WMI_SMART_LOG_CE_FULL_DETECT_BY_FW     =        0x1,
    WMI_SMART_LOG_TX_RX_TIMEOUT            =        0x2,
    WMI_SMART_LOG_STA_KICKOUT              =        0x4,
    WMI_SMART_LOG_BCN_CMD_FAILURE          =        0x8,
    /* Ping failure detection is done by user space entities. So, it should be
     * able to control the enable/disable of this feature. Still, adding this
     * in case the corresponding FW specific debugs alone have to be
     * enabled/disabled.
     */
    WMI_SMART_LOG_P1_PING_FAILURE          =       0x10,
    /* Connection failure detection is done by Host. So, the Host should be
     * able to control the enable/disable of this feature. Still, adding this
     * in case the corresponding FW specific debugs alone have to be
     * enabled/disabled.
     */
    WMI_SMART_LOG_CONNECTION_FAILURE       =       0x20,
    WMI_SMART_LOG_FW_INITIATED_PKT_LOG     =       0x40,

    /* New scenarios to be added here */

    /*
     * If WMI_SMART_LOG_EXTENSION_1 is set, then the 'log_case_ext_1' field
     * in 'wmi_smart_logging' is used; else log_case_ext_1 is ignored.
     */
    WMI_SMART_LOG_EXTENSION_1              = 0x80000000,
} WMI_SMART_LOG_SCENARIO;

typedef struct {
    A_UINT32 enable;
    A_UINT32 log_case;
    A_UINT32 log_case_ext_1;
} wmi_smart_logging;

typedef struct {
    A_UINT32 type;
    A_UINT32 subtype;
    union {
        /*
         * The original "reserved0" name of this field is deprecated,
         * but has to be preserved, due to code that explicitly refers
         * to this field (in order to set it to 0x0).
         */
        A_UINT32 reserved0;

        /* The previously-reserved field now holds data under some conditions.
         * The kind of data depends on the above "type" and "subtype" fields.
         * The interpretation of the type_subtype_specific_data field based
         * on different type + subtype values is shown below:
         * 1.  type == WMI_FATAL_CONDITION_PACKET_LOG_CONFIG +
         *     subtype == WMI_FATAL_SUBTYPE_PACKET_LOG_CONFIG_START ->
         *     type_subtype_specific_data = WMI_PKTLOG_EVENT
         * For any type+subtype combinations not listed above, the recipient
         * is expected to ignore the type_subtype_specific_data field.
         */
        A_UINT32 type_subtype_specific_data;
    };
} wmi_fatal_condition;

typedef struct {
    A_UINT32 num_events;
    /* Followed by num_events * wmi_fatal_condition */
} wmi_debug_fatal_condition_list;

/* values that 'type' can take in wmi_fatal_condition */
typedef enum {
    WMI_FATAL_CONDITION_EVENT_COMPLETION,
    WMI_FATAL_CONDITION_CE_FAILURE,
    WMI_FATAL_CONDITION_TIMEOUTS,
    WMI_FATAL_CONDITION_CONNECTION_ISSUE,
    WMI_FATAL_CONDITION_PACKET_LOG_CONFIG,
} WMI_FATAL_CONDITION_TYPE;

/* Possible subtypes for WMI_FATAL_CONDITION_TIMEOUTS */
typedef enum {
    WMI_FATAL_SUBTYPE_TX_TIMEOUT,
    WMI_FATAL_SUBTYPE_RX_TIMEOUT,
} WMI_FATAL_CONDITION_SUBTYPE_TIMEOUTS;

/* Possible subtypes for WMI_FATAL_CONDITION_CONNECTION_ISSUE */
typedef enum {
    WMI_FATAL_SUBTYPE_STA_KICKOUT,
    WMI_FATAL_SUBTYPE_P1_PING_FAILURE_START_DEBUG,
    WMI_FATAL_SUBTYPE_P1_PING_FAILURE_STOP_DEBUG,
    WMI_FATAL_SUBTYPE_CONNECTION_FAILURE_START_DEBUG,
    WMI_FATAL_SUBTYPE_CONNECTION_FAILURE_STOP_DEBUG,
} WMI_FATAL_CONDITION_SUBTYPE_CONNECTION_ISSUE;

/* Possible subtypes for WMI_FATAL_CONDITION_PACKET_LOG_CONFIG */
typedef enum {
    WMI_FATAL_SUBTYPE_PACKET_LOG_CONFIG_START,
    WMI_FATAL_SUBTYPE_PACKET_LOG_CONFIG_STOP,
} WMI_FATAL_CONDITION_SUBTYPE_PACKET_LOG_CONFIG;

/* Enum for OEM message sub-types */
typedef enum {
    WMI_OEM_CAPABILITY_REQ     = 0x01,
    WMI_OEM_CAPABILITY_RSP     = 0x02,
    WMI_OEM_MEASUREMENT_REQ    = 0x03,
    WMI_OEM_MEASUREMENT_RSP    = 0x04,
    WMI_OEM_ERROR_REPORT_RSP   = 0x05,
    WMI_OEM_NAN_MEAS_REQ       = 0x06,
    WMI_OEM_NAN_MEAS_RSP       = 0x07,
    WMI_OEM_NAN_PEER_INFO      = 0x08,
    WMI_OEM_CONFIGURE_LCR      = 0x09,
    WMI_OEM_CONFIGURE_LCI      = 0x0A,
} WMI_OEM_SUBTYPE;

/* mcast aged-out entry */
typedef struct {
      /* IPv4/6 mcast group addr */
      A_UINT8 grp_addr[16];
      /* mcast group vdev ID */
      A_UINT32 vdev_id;
} wmi_mcast_ageout_entry;

/* List of mcast entry aged-out */
typedef struct {
    /* Number of mcast entries timed-out */
    A_UINT32 num_entry;
    /* List data */
    wmi_mcast_ageout_entry entry[1];
} wmi_mcast_list_ageout_event;

typedef struct {
    /* Noise threshold iterations with high values */
    A_UINT32 noise_floor_report_iter;
    /* Total noise threshold iterations */
    A_UINT32 noise_floor_total_iter;
} wmi_pdev_channel_hopping_event;

#define WMI_CHAN_LIST_TAG 0x1
#define WMI_SSID_LIST_TAG 0x2
#define WMI_BSSID_LIST_TAG 0x3
#define WMI_IE_TAG 0x4
#define WMI_SCAN_START_OFFSET_TAG 0x5

typedef struct {
    /** primary 20 MHz channel frequency in mhz */
    A_UINT32 mhz;
    /** Center frequency 1 in MHz*/
    A_UINT32 band_center_freq1;
    /** Center frequency 2 in MHz - valid only for 11acvht 80plus80 mode*/
    A_UINT32 band_center_freq2;
    /** channel info described below */
    A_UINT32 info;
    /** contains min power, max power, reg power and reg class id.  */
    A_UINT32 reg_info_1;
    /** contains antennamax */
    A_UINT32 reg_info_2;
} wmi_channel;

typedef enum{
WMI_CHANNEL_CHANGE_CAUSE_NONE = 0,
WMI_CHANNEL_CHANGE_CAUSE_CSA,
}wmi_channel_change_cause;
/** channel info consists of 6 bits of channel mode */

#define WMI_SET_CHANNEL_MODE(pwmi_channel,val) do { \
     (pwmi_channel)->info &= 0xffffffc0;            \
     (pwmi_channel)->info |= (val);                 \
     } while(0)

#define WMI_GET_CHANNEL_MODE(pwmi_channel) ((pwmi_channel)->info & 0x0000003f )

#define WMI_CHAN_FLAG_HT40_PLUS   6
#define WMI_CHAN_FLAG_PASSIVE     7
#define WMI_CHAN_ADHOC_ALLOWED    8
#define WMI_CHAN_AP_DISABLED      9
#define WMI_CHAN_FLAG_DFS         10
#define WMI_CHAN_FLAG_ALLOW_HT    11  /* HT is allowed on this channel */
#define WMI_CHAN_FLAG_ALLOW_VHT   12  /* VHT is allowed on this channel */

#define WMI_CHANNEL_CHANGE_CAUSE_CSA 13 /*Indicate reason for channel switch */
#define WMI_CHAN_FLAG_HALF        13
#define WMI_CHAN_FLAG_QUARTER     14
#define WMI_CHAN_FLAG_DFS_CFREQ2  15
#define WMI_CHAN_FLAG_AGILE_MODE  16 /* Enable agile mode for zero wait DFS */

#define WMI_SET_CHANNEL_FLAG(pwmi_channel,flag) do { \
        (pwmi_channel)->info |=  (1 << flag);      \
     } while(0)

#define WMI_GET_CHANNEL_FLAG(pwmi_channel,flag)   \
        (((pwmi_channel)->info & (1 << flag)) >> flag)

#define WMI_SET_CHANNEL_MIN_POWER(pwmi_channel,val) do { \
     (pwmi_channel)->reg_info_1 &= 0xffffff00;            \
     (pwmi_channel)->reg_info_1 |= (val);                 \
     } while(0)
#define WMI_GET_CHANNEL_MIN_POWER(pwmi_channel) ((pwmi_channel)->reg_info_1 & 0xff )

#define WMI_SET_CHANNEL_MAX_POWER(pwmi_channel,val) do { \
     (pwmi_channel)->reg_info_1 &= 0xffff00ff;            \
     (pwmi_channel)->reg_info_1 |= ((val) << 8);          \
     } while(0)
#define WMI_GET_CHANNEL_MAX_POWER(pwmi_channel) ( (((pwmi_channel)->reg_info_1) >> 8) & 0xff )

#define WMI_SET_CHANNEL_REG_POWER(pwmi_channel,val) do { \
     (pwmi_channel)->reg_info_1 &= 0xff00ffff;            \
     (pwmi_channel)->reg_info_1 |= ((val) << 16);         \
     } while(0)
#define WMI_GET_CHANNEL_REG_POWER(pwmi_channel) ( (((pwmi_channel)->reg_info_1) >> 16) & 0xff )
#define WMI_SET_CHANNEL_REG_CLASSID(pwmi_channel,val) do { \
     (pwmi_channel)->reg_info_1 &= 0x00ffffff;             \
     (pwmi_channel)->reg_info_1 |= ((val) << 24);          \
     } while(0)
#define WMI_GET_CHANNEL_REG_CLASSID(pwmi_channel) ( (((pwmi_channel)->reg_info_1) >> 24) & 0xff )

#define WMI_SET_CHANNEL_ANTENNA_MAX(pwmi_channel,val) do { \
     (pwmi_channel)->reg_info_2 &= 0xffffff00;            \
     (pwmi_channel)->reg_info_2 |= (val);                 \
     } while(0)
#define WMI_GET_CHANNEL_ANTENNA_MAX(pwmi_channel) ((pwmi_channel)->reg_info_2 & 0xff )

/** max tx power is in 1 dBm units */
#define WMI_SET_CHANNEL_MAX_TX_POWER(pwmi_channel,val) do { \
     (pwmi_channel)->reg_info_2 &= 0xffff00ff;              \
     (pwmi_channel)->reg_info_2 |= ((val & 0xff) << 8);     \
     } while (0)
#define WMI_GET_CHANNEL_MAX_TX_POWER(pwmi_channel) ((((pwmi_channel)->reg_info_2)>>8) & 0xff)


/** HT Capabilities*/
#define WMI_HT_CAP_ENABLED                0x0001   /* HT Enabled/ disabled */
#define WMI_HT_CAP_HT20_SGI               0x0002   /* Short Guard Interval with HT20 */
#define WMI_HT_CAP_DYNAMIC_SMPS           0x0004   /* Dynamic MIMO powersave */
#define WMI_HT_CAP_TX_STBC                0x0008   /* B3 TX STBC */
#define WMI_HT_CAP_TX_STBC_MASK_SHIFT     3
#define WMI_HT_CAP_RX_STBC                0x0030   /* B4-B5 RX STBC */
#define WMI_HT_CAP_RX_STBC_MASK_SHIFT     4
#define WMI_HT_CAP_LDPC                   0x0040   /* LDPC supported */
#define WMI_HT_CAP_L_SIG_TXOP_PROT        0x0080   /* L-SIG TXOP Protection */
#define WMI_HT_CAP_MPDU_DENSITY           0x0700   /* MPDU Density */
#define WMI_HT_CAP_MPDU_DENSITY_MASK_SHIFT 8
#define WMI_HT_CAP_HT40_SGI               0x0800
#define WMI_HT_CAP_IBF_BFER               0x1000

/* These macros should be used when we wish to advertise STBC support for
 * only 1SS or 2SS or 3SS. */
#define WMI_HT_CAP_RX_STBC_1SS            0x0010   /* B4-B5 RX STBC */
#define WMI_HT_CAP_RX_STBC_2SS            0x0020   /* B4-B5 RX STBC */
#define WMI_HT_CAP_RX_STBC_3SS            0x0030   /* B4-B5 RX STBC */


#define WMI_HT_CAP_DEFAULT_ALL (WMI_HT_CAP_ENABLED       | \
                                WMI_HT_CAP_HT20_SGI      | \
                                WMI_HT_CAP_HT40_SGI      | \
                                WMI_HT_CAP_TX_STBC       | \
                                WMI_HT_CAP_RX_STBC       | \
                                WMI_HT_CAP_LDPC)

/* WMI_VHT_CAP_* these maps to ieee 802.11ac vht capability information
   field. The fields not defined here are not supported, or reserved.
   Do not change these masks and if you have to add new one follow the
   bitmask as specified by 802.11ac draft.
*/

#define WMI_VHT_CAP_MAX_MPDU_LEN_MASK            0x00000003
#define WMI_VHT_CAP_RX_LDPC                      0x00000010
#define WMI_VHT_CAP_SGI_80MHZ                    0x00000020
#define WMI_VHT_CAP_SGI_160MHZ                   0x00000040
#define WMI_VHT_CAP_TX_STBC                      0x00000080
#define WMI_VHT_CAP_RX_STBC_MASK                 0x00000300
#define WMI_VHT_CAP_RX_STBC_MASK_SHIFT           8
#define WMI_VHT_CAP_SU_BFER                      0x00000800
#define WMI_VHT_CAP_SU_BFEE                      0x00001000
#define WMI_VHT_CAP_MAX_CS_ANT_MASK              0x0000E000
#define WMI_VHT_CAP_MAX_CS_ANT_MASK_SHIFT        13
#define WMI_VHT_CAP_MAX_SND_DIM_MASK             0x00070000
#define WMI_VHT_CAP_MAX_SND_DIM_MASK_SHIFT       16
#define WMI_VHT_CAP_MU_BFER                      0x00080000
#define WMI_VHT_CAP_MU_BFEE                      0x00100000
#define WMI_VHT_CAP_MAX_AMPDU_LEN_EXP            0x03800000
#define WMI_VHT_CAP_MAX_AMPDU_LEN_EXP_SHIT       23
#define WMI_VHT_CAP_RX_FIXED_ANT                 0x10000000
#define WMI_VHT_CAP_TX_FIXED_ANT                 0x20000000

#define WMI_VHT_CAP_MAX_MPDU_LEN_11454           0x00000002

/* These macros should be used when we wish to advertise STBC support for
 * only 1SS or 2SS or 3SS. */
#define WMI_VHT_CAP_RX_STBC_1SS            0x00000100
#define WMI_VHT_CAP_RX_STBC_2SS            0x00000200
#define WMI_vHT_CAP_RX_STBC_3SS            0x00000300

#define WMI_VHT_CAP_DEFAULT_ALL (WMI_VHT_CAP_MAX_MPDU_LEN_11454  |      \
                                 WMI_VHT_CAP_SGI_80MHZ           |      \
                                 WMI_VHT_CAP_TX_STBC             |      \
                                 WMI_VHT_CAP_RX_STBC_MASK        |      \
                                 WMI_VHT_CAP_RX_LDPC             |      \
                                 WMI_VHT_CAP_MAX_AMPDU_LEN_EXP   |      \
                                 WMI_VHT_CAP_RX_FIXED_ANT        |      \
                                 WMI_VHT_CAP_TX_FIXED_ANT)

/* Interested readers refer to Rx/Tx MCS Map definition as defined in
   802.11ac
*/
#define WMI_VHT_MAX_MCS_4_SS_MASK(r,ss)      ((3 & (r)) << (((ss) - 1) << 1))
#define WMI_VHT_MAX_SUPP_RATE_MASK           0x1fff0000
#define WMI_VHT_MAX_SUPP_RATE_MASK_SHIFT     16

/* WMI_SYS_CAPS_* refer to the capabilities that system support
*/
#define WMI_SYS_CAP_ENABLE                       0x00000001
#define WMI_SYS_CAP_TXPOWER                      0x00000002


#define WMI_NUM_UNITS_IS_NUM_VDEVS   0x1
#define WMI_NUM_UNITS_IS_NUM_PEERS   0x2
typedef struct {
    /** ID of the request */
    A_UINT32    req_id;
    /** size of the  of each unit */
    A_UINT32    unit_size;
    /**
     * flags to  indicate that
     * the number units is dependent
     * on number of resources(num vdevs num peers .. etc)
     */
    A_UINT32    num_unit_info;
    /*
     * actual number of units to allocate . if flags in the num_unit_info
     * indicate that number of units is tied to number of a particular
     * resource to allocate then  num_units filed is set to 0 and host
     * will derive the number units from number of the resources it is
     * requesting.
     */
    A_UINT32    num_units;
} wmi_mem_req;

/*
* maximum number of memroy requests allowed from FW.
*/
#define WMI_MAX_MEM_REQS 16
/**
 * The following struct holds optional payload for
 * wmi_service_ready_event,e.g., 11ac pass some of the
 * device capability to the host.
*/
typedef struct {
    A_UINT32    sw_version;
    A_UINT32    sw_version_1; /* second dword of version info */
    A_UINT32    abi_version;
    A_UINT32    phy_capability;  /* WMI_PHY_CAPABILITY */
	A_UINT32    max_frag_entry;  /* Maximum number of frag table entries that SW will populate less 1 */
    A_UINT32    wmi_service_bitmap[WMI_SERVICE_BM_SIZE];
    A_UINT32    num_rf_chains;
    /* The following field is only valid for service type WMI_SERVICE_11AC */
    A_UINT32    ht_cap_info; /* WMI HT Capability */
    A_UINT32    vht_cap_info; /* VHT capability info field of 802.11ac */
    A_UINT32    vht_supp_mcs; /* VHT Supported MCS Set field Rx/Tx same */
    A_UINT32    hw_min_tx_power;
    A_UINT32    hw_max_tx_power;
    HAL_REG_CAPABILITIES hal_reg_capabilities;
    A_UINT32    sys_cap_info;
    A_UINT32    min_pkt_size_enable; /* Enterprise mode short pkt enable */
    /** Max beacon and Probe Response IE offload size (includes
     *  optional P2P IEs) */
    A_UINT32    max_bcn_ie_size;
    /*
     * request to host to allocate a chuck of memory and pss it down to FW via WM_INIT.
     * FW uses this as FW extesnsion memory for saving its data structures. Only valid
     * for low latency interfaces like PCIE where FW can access this memory directly (or)
     * by DMA.
     */
    A_UINT32    num_mem_reqs;
    wlan_host_mem_req  mem_reqs[1];
} wmi_service_ready_event;

/** status consists of  upper 16 bits fo A_STATUS status and lower 16 bits of module ID that retuned status */
#define WLAN_INIT_STATUS_SUCCESS   0x0
#define WLAN_GET_INIT_STATUS_REASON(status)    ((status) & 0xffff)
#define WLAN_GET_INIT_STATUS_MODULE_ID(status) (((status) >> 16) & 0xffff)

typedef A_UINT32 WLAN_INIT_STATUS;

typedef struct {
    A_UINT32    sw_version;
    A_UINT32    abi_version;
    wmi_mac_addr mac_addr;
    A_UINT32    status;
    A_UINT32    num_dscp_table;
    /* agile_capability:
     * Boolean specification of whether the target supports agile DFS,
     * by means of using one 80 MHz radio chain for radar detection,
     * concurrently with using another radio chain for non-160 MHz
     * regular operation.
     */
    A_UINT32    agile_capability;
} wmi_ready_event;

typedef struct {
/**
 * @brief num_vdev - number of virtual devices (VAPs) to support
 */
    A_UINT32 num_vdevs;
/**
 * @brief num_peers - number of peer nodes to support
 */
    A_UINT32 num_peers;
/**
 * @brief num_active_peers - number of active peer nodes to support.
 * Same as num_peers to disable QCache
 */
    A_UINT32 num_active_peers;
/*
 * @brief In offload mode target supports features like WOW, chatter and other
 * protocol offloads. In order to support them some functionalities like
 * reorder buffering, PN checking need to be done in target. This determines
 * maximum number of peers suported by target in offload mode
 */
    A_UINT32 num_offload_peers;
/* @brief Number of reorder buffers available for doing target based reorder
 * Rx reorder buffering
 */
    A_UINT32 num_offload_reorder_buffs;
/**
 * @brief num_peer_keys - number of keys per peer
 */
    A_UINT32 num_peer_keys;
/**
 * @brief num_tids - total number of TX/RX data TIDs
 */
    A_UINT32 num_tids;
/**
 * @brief ast_skid_limit - max skid for resolving hash collisions
 * @details
 *     The address search table is sparse, so that if two MAC addresses
 *     result in the same hash value, the second of these conflicting
 *     entries can slide to the next index in the address search table,
 *     and use it, if it is unoccupied.  This ast_skid_limit parameter
 *     specifies the upper bound on how many subsequent indices to search
 *     over to find an unoccupied space.
 */
    A_UINT32 ast_skid_limit;
/**
 * @brief tx_chain_mask - the nominal chain mask for transmit
 * @details
 *     The chain mask may be modified dynamically, e.g. to operate AP tx with
 *     a reduced number of chains if no clients are associated.
 *     This configuration parameter specifies the nominal chain-mask that
 *     should be used when not operating with a reduced set of tx chains.
 */
    A_UINT32 tx_chain_mask;
/**
 * @brief rx_chain_mask - the nominal chain mask for receive
 * @details
 *     The chain mask may be modified dynamically, e.g. for a client to use
 *     a reduced number of chains for receive if the traffic to the client
 *     is low enough that it doesn't require downlink MIMO or antenna
 *     diversity.
 *     This configuration parameter specifies the nominal chain-mask that
 *     should be used when not operating with a reduced set of rx chains.
 */
    A_UINT32 rx_chain_mask;
/**
 * @brief rx_timeout_pri - what rx reorder timeout (ms) to use for the AC
 * @details
 *     Each WMM access class (voice, video, best-effort, background) will
 *     have its own timeout value to dictate how long to wait for missing
 *     rx MPDUs to arrive before flushing subsequent MPDUs that have already
 *     been received.
 *     This parameter specifies the timeout in milliseconds for each class .
 */
    A_UINT32 rx_timeout_pri[4];
/**
 * @brief rx_decap mode - what mode the rx should decap packets to
 * @details
 *     MAC can decap to RAW (no decap), native wifi or Ethernet types
 *     THis setting also determines the default TX behavior, however TX
 *     behavior can be modified on a per VAP basis during VAP init
 */
    A_UINT32 rx_decap_mode;

 /**
  * @brief  scan_max_pending_req - what is the maximum scan requests than can be queued
  */
    A_UINT32 scan_max_pending_req;

    /**
     * @brief maximum VDEV that could use BMISS offload
     */
    A_UINT32 bmiss_offload_max_vdev;

    /**
     * @brief maximum VDEV that could use offload roaming
     */
    A_UINT32 roam_offload_max_vdev;

    /**
     * @brief maximum AP profiles that would push to offload roaming
     */
    A_UINT32 roam_offload_max_ap_profiles;

/**
 * @brief num_mcast_groups - how many groups to use for mcast->ucast conversion
 * @details
 *     The target's WAL maintains a table to hold information regarding which
 *     peers belong to a given multicast group, so that if multicast->unicast
 *     conversion is enabled, the target can convert multicast tx frames to a
 *     series of unicast tx frames, to each peer within the multicast group.
 *     This num_mcast_groups configuration parameter tells the target how
 *     many multicast groups to provide storage for within its multicast
 *     group membership table.
 */
    A_UINT32 num_mcast_groups;

/**
 * @brief num_mcast_table_elems - size to alloc for the mcast membership table
 * @details
 *     This num_mcast_table_elems configuration parameter tells the target
 *     how many peer elements it needs to provide storage for in its
 *     multicast group membership table.
 *     These multicast group membership table elements are shared by the
 *     multicast groups stored within the table.
 */
    A_UINT32 num_mcast_table_elems;

/**
 * @brief mcast2ucast_mode - whether/how to do multicast->unicast conversion
 * @details
 *     This configuration parameter specifies whether the target should
 *     perform multicast --> unicast conversion on transmit, and if so,
 *     what to do if it finds no entries in its multicast group membership
 *     table for the multicast IP address in the tx frame.
 *     Configuration value:
 *     0 -> Do not perform multicast to unicast conversion.
 *     1 -> Convert multicast frames to unicast, if the IP multicast address
 *          from the tx frame is found in the multicast group membership
 *          table.  If the IP multicast address is not found, drop the frame.
 *     2 -> Convert multicast frames to unicast, if the IP multicast address
 *          from the tx frame is found in the multicast group membership
 *          table.  If the IP multicast address is not found, transmit the
 *          frame as multicast.
 */
    A_UINT32 mcast2ucast_mode;


 /**
  * @brief tx_dbg_log_size - how much memory to allocate for a tx PPDU dbg log
  * @details
  *     This parameter controls how much memory the target will allocate to
  *     store a log of tx PPDU meta-information (how large the PPDU was,
  *     when it was sent, whether it was successful, etc.)
  */
    A_UINT32 tx_dbg_log_size;

 /**
  * @brief num_wds_entries - how many AST entries to be allocated for WDS
  */
    A_UINT32 num_wds_entries;

 /**
  * @brief dma_burst_size - MAC DMA burst size, e.g., on Peregrine on PCI
  * this limit can be 0 -default, 1 256B
  */
    A_UINT32 dma_burst_size;

  /**
   * @brief mac_aggr_delim - Fixed delimiters to be inserted after every MPDU
   * to account for interface latency to avoid underrun.
   */
    A_UINT32 mac_aggr_delim;

    /**
     * @brief rx_skip_defrag_timeout_dup_detection_check
     * @details
     *  determine whether target is responsible for detecting duplicate
     *  non-aggregate MPDU and timing out stale fragments.
     *
     *  A-MPDU reordering is always performed on the target.
     *
     *  0: target responsible for frag timeout and dup checking
     *  1: host responsible for frag timeout and dup checking
     */
    A_UINT32 rx_skip_defrag_timeout_dup_detection_check;

    /**
     * @brief vow_config - Configuration for VoW : No of Video Nodes to be supported
     * and Max no of descriptors for each Video link (node).
     */
    A_UINT32 vow_config;
	
    /**
     * @brief maximum VDEV that could use GTK offload
     */
	A_UINT32 gtk_offload_max_vdev;

    /**
     * @brief num_msdu_desc - Number of msdu descriptors target should use
     */

    A_UINT32 num_msdu_desc; /* Number of msdu desc */
 /**
  * @brief max_frag_entry - Max. number of Tx fragments per MSDU
  * @details
  *     This parameter controls the max number of Tx fragments per MSDU.
  *     This is sent by the target as part of the WMI_SERVICE_READY event
  *     and is overriden by the OS shim as required.
  */
    A_UINT32 max_frag_entries;
 /**
  * @brief max_peer_ext_stats - Max. number of extended peer stats
  * @details
  *     This parameter controls the max number of peers for which extended
  *     statistics are supported by target
  */
    A_UINT32 max_peer_ext_stats;

  /**
   * @brief smart_ant_cap - Smart Antenna capabilities information
   * @details
   *        1 - Smart antenna is enabled.
   *        0 - Smart antenna is disabled.
   * In future this can contain smart antenna specifc capabilities.
   */
    A_UINT32 smart_ant_cap;

  /**
   * User can configure the buffers allocated for each AC (BE, BK, VI, VO) during init
   */
   A_UINT32 BK_Minfree;
   A_UINT32 BE_Minfree;
   A_UINT32 VI_Minfree;
   A_UINT32 VO_Minfree;

  /**
   * @brief rx_batchmode - Rx batchmode capability
   * @details
   *        1 - Rx batchmode enabled
   *        0 - Rx batchmode disabled
   *
   */
    A_UINT32 rx_batchmode;

  /**
   * @brief tt_support - thermal throttling capability
   * @details
   *        1 - Capable of thermal throttling
   *        0 - Not capable of thermal throttling
   *
   */
    A_UINT32 tt_support;

   /**
    * ATF config
    * 1  - Enable ATF.
    * 0  - Disable ATF.
    */
    A_UINT32 atf_config;

    /**
     * @brief iphdr_pad_config - configure padding to manage IP header unalignment
     * 1  - Enable padding
     * 0  - Disable padding
     */
    A_UINT32 iphdr_pad_config;

    A_UINT32
    /**
     * @brief qwrap_config - configure qwrap
     *        1  - This is qwrap configuration
     *        0  - This is not qwrap
     */
      qwrap_config               :16,

     /**
      * @brief alloc_frag_desc_for_data_pkt . Controls data packet fragment
      * descriptor memory allocation.
      *   1 - Allocate fragment descriptor memory for data packet in firmware.
      *       If host wants to transmit data packet at its desired rate,
              this field must be set.
      *   0 - Don't allocate fragment descriptor for data packet.
      */
      alloc_frag_desc_for_data_pkt :16;


} wmi_resource_config;


#define QWRAP_CONFIG_MASK                   0x0000ffff
#define QWRAP_CONFIG_SHIFT                  0
#define ALLOC_FRAG_DESC_FOR_DATA_PKT_MASK   0xffff0000
#define ALLOC_FRAG_DESC_FOR_DATA_PKT_SHIFT 16

#define QWRAP_CONFIG_OFFSET \
    (offsetof(wmi_resource_config, iphdr_pad_config) + sizeof(A_UINT32))

#define WMI_GET_QWRAP(p) \
    (((*((A_UINT32 *)((A_UINT8 *)(p) + QWRAP_CONFIG_OFFSET))) & \
    QWRAP_CONFIG_MASK) >> QWRAP_CONFIG_SHIFT)

#define WMI_GET_ALLOC_FRAG(p) \
    (((*((A_UINT32 *)((A_UINT8 *)(p) + QWRAP_CONFIG_OFFSET))) & \
    ALLOC_FRAG_DESC_FOR_DATA_PKT_MASK) >> ALLOC_FRAG_DESC_FOR_DATA_PKT_SHIFT)

#define WMI_SET_QWRAP(p,value) \
    do { \
        *((A_UINT32 *)((A_UINT8 *)(p) + QWRAP_CONFIG_OFFSET)) &= \
            ~QWRAP_CONFIG_MASK; \
        *((A_UINT32 *)((A_UINT8 *)(p) + QWRAP_CONFIG_OFFSET)) |= \
           (((value) << QWRAP_CONFIG_SHIFT) & \
           QWRAP_CONFIG_MASK); \
    } while(0)

#define WMI_SET_ALLOC_FRAG(p,value) \
    do { \
        *((A_UINT32 *)((A_UINT8 *)(p) + QWRAP_CONFIG_OFFSET)) &= \
            ~ALLOC_FRAG_DESC_FOR_DATA_PKT_MASK; \
        *((A_UINT32 *)((A_UINT8 *)(p) + QWRAP_CONFIG_OFFSET)) |= \
            (((value) << ALLOC_FRAG_DESC_FOR_DATA_PKT_SHIFT) & \
            ALLOC_FRAG_DESC_FOR_DATA_PKT_MASK); \
    } while(0);

typedef enum {
    WMI_HOST_PLATFORM_HIGH_PERF,
    WMI_HOST_PLATFORM_LOW_PERF,
    WMI_HOST_PLATFORM_LOW_PERF_NO_FETCH, /* push only, no pull */
} WMI_HOST_PLATFORM_TYPE;

/**
 * Added new wmi_ext_resource_config structure  for
 * 10.2 + 2.0 Backward compatibilty issue
 * all the new configs has to added here.
 */
typedef struct {
    /**
     * @brief Host platform type config
     */
    A_UINT32 host_platform_config;

#define FW_FEATURE_LTEU_SUPPORT                   0x00000001
#define FW_FEATURE_COEX_GPIO_SUPPORT              0x00000002
#define FW_FEATURE_AUX_RADIO_SPECTRAL_INTF        0x00000004
#define FW_FEATURE_AUX_RADIO_CHAN_LOAD_INTF       0x00000008
#define FW_FEATURE_BSS_CHANNEL_INFO_64            0x00000010
#define FW_FEATURE_PEER_STATS                     0x00000020
#define FW_FEATURE_VDEV_STATS                     0x00000040
#define FW_FEATURE_TDLS                           0x00000080
#define FW_FEATURE_TDLS_OFFCHAN                   0x00000100
#define FW_FEATURE_TDLS_UAPSD_BUFFER_STA          0x00000200
#define FW_FEATURE_TDLS_UAPSD_SLEEP_STA           0x00000400
#define FW_FEATURE_TDLS_CONN_TRACKER_IN_HOST_MODE 0x00000800
#define FW_FEATURE_TDLS_EXPLICIT_MODE_ONLY        0x00001000
#define FW_FEATURE_TDLS_WIDER_BANDWIDTH           0x00002000
#define FW_FEATURE_VOW_FEATURES                   0x00004000
#define FW_FEATURE_VOW_STATS                      0x00008000
#define FW_FEATURE_TX_DATA_ACK_RSSI               0x00010000
    /**
     * @brief fw_feature_bitmask - Enable/Disable features in FW
     * @details
     *  The bits in fw_feature_bitmask are used as shown by the masks below:
     *      0x0001 - LTEU Config enable/disable
     *      0x0002 - COEX GPIO Config enable/disable
     *      0x0004 - Aux Radio enhancement for spectral scan enable/disable
     *      0x0008 - Aux Radio enhancement for chan load scan enable/disable
     *      0x0010 - BSS channel info stats enable/disable
     *      0x0020 - per peer stats
     *      0x0040 - per vdev stats
     *      0x0080 - TDLS implicit and explicit mode enable/disable
     *      0x0100 - TDLS mode offchannel enable/disable
     *      0x0200 - TDLS Buffer STA enable/disable
     *      0x0400 - TDLS Sleep STA enable/disable
     *      0x0800 - Connection tracker in Host enable/disable
     *      0x1000 - TDLS explicit mode only enable/disable
     *      0x2000 - Enable/disable STA support for a wider bandwidth than the
     *               BSS bandwidth for a TDLS direct link
     *      0x4000 - VOW features enable/disable
     *      0x8000 - VOW stats enable/disable
     *      0x10000- Tx Data ACK_RSSI enable/disable
     *  The features in question are enabled by setting the feature's bit to 1,
     *  or disabled by setting the feature's bit to 0.
     */
    A_UINT32 fw_feature_bitmap;

    /* WLAN priority GPIO number
     * The target uses a GPIO pin to indicate when it is transmitting
     * high-priority traffic (e.g. beacon, management, or AC_VI) or
     * low-priority traffic (e.g. AC_BE, AC_BK).  The HW uses this
     * WLAN GPIO pin to determine whether to abort WLAN tx in favor of
     * BT activity.
     * Which GPIO is used for this WLAN tx traffic priority specification
     * varies between platforms, so the host needs to indicate to the
     * target which GPIO to use.
     */
    A_UINT32 wlan_priority_gpio;

    /* Host will notify target which coex algorithm has to be enabled
     * based on HW, FW capability and device tree config. Till now the
     * coex algorithms were target specific. Now the same target can
     * choose between multiple coex algorithms depending on device tree
     * config on host. For backward compatibility, version support will
     * have option 0 and will rely on FW compile time flags to decide
     * the coex version between VERSION_1, VERSION_2 and VERSION_3.
     * Version info is mandatory from VERSION_4 onwards for any new coex
     * algorithms.
     *
     *  0 = no version support
     *  1 = COEX_VERSION_1 (3 wire coex)
     *  2 = COEX_VERSION_2 (2.5 wire coex)
     *  3 = COEX_VERSION_3 (2.5 wire coex+duty cycle)
     *  4 = COEX_VERSION_4 (4 wire coex)
     */
    A_UINT32 coex_version;
    /* There are multiple coex implementations on FW to support different
     * hardwares.  Since the coex algos are mutually exclusive, host will
     * use below fields to send GPIO info to FW and these GPIO pins will
     * have different usages depending on the feature enabled.
     * This is to avoid adding multiple GPIO fields for different features.
     *
     * COEX_VERSION_4 (4 wire coex):
     * 4 wire coex feature uses 1 common input request line from BT/ZB/Thread
     * which interrupts the WLAN target processor directly, 1 input priority
     * line from BT and ZB each, 1 output line to grant access to requesting
     * IoT subsystem. WLAN uses the input priority line to identify the
     * requesting IoT subsystem. Request is granted based on IoT interface
     * priority and WLAN traffic.
     * GPIO pin usage is as below:
     *     coex_gpio_pin_1 = BT PRIORITY INPUT GPIO
     *     coex_gpio_pin_2 = ZIGBEE PRIORITY INPUT GPIO
     *     coex_gpio_pin_3 = GRANT OUTPUT GPIO
     * when a BT active interrupt is raised, WLAN reads BT and ZB priority
     * input GPIO pins to compare against the coex priority table and sets the
     * grant output GPIO accordingly to give access to requesting IOT subsystem.
     */
    A_UINT32 coex_gpio_pin_1;
    A_UINT32 coex_gpio_pin_2;
    A_UINT32 coex_gpio_pin_3;

    /** number of vdevs allowed to do tdls */
    A_UINT32 num_tdls_vdevs;
    /** number of peers to track per TDLS vdev */
    A_UINT32 num_tdls_conn_table_entries;
    /** Number of tdls sleep sta supported */
    A_UINT32 max_tdls_concurrent_sleep_sta;
    /** Number of tdls buffer sta supported */
    A_UINT32 max_tdls_concurrent_buffer_sta;



    /* add new members here */
} wmi_ext_resource_config;

#define resource_config_rx_batchmode(p_cmd) \
    ((p_cmd)->resource_config.rx_batchmode)
#define resource_config_atf_mode(p_cmd) \
    ((p_cmd)->resource_config.atf_config)
#define resource_config_lteu_support(p_ext_rescfg) \
    ((((p_ext_rescfg)->fw_feature_bitmap) & \
       FW_FEATURE_LTEU_SUPPORT) ? 1 : 0)
#define resource_config_coex_gpio_support(p_ext_rescfg) \
    ((((p_ext_rescfg)->fw_feature_bitmap) & \
       FW_FEATURE_COEX_GPIO_SUPPORT) ? 1 : 0)
#define resource_config_gpio_aux_spectral_intf(p_ext_rescfg) \
    ((((p_ext_rescfg)->fw_feature_bitmap) & \
       FW_FEATURE_AUX_RADIO_SPECTRAL_INTF) ? 1: 0)
#define resource_config_gpio_aux_chan_load_intf(p_ext_rescfg) \
    ((((p_ext_rescfg)->fw_feature_bitmap) & \
       FW_FEATURE_AUX_RADIO_CHAN_LOAD_INTF) ? 1: 0)
#define resource_config_bss_channel_info_64(p_ext_rescfg) \
    ((((p_ext_rescfg)->fw_feature_bitmap) & \
       FW_FEATURE_BSS_CHANNEL_INFO_64) ? 1 : 0)
#define resource_config_peer_stats(p_ext_rescfg) \
    ((((p_ext_rescfg)->fw_feature_bitmap) & \
       FW_FEATURE_PEER_STATS) ? 1 : 0)
#define resource_config_vdev_stats(p_ext_rescfg) \
    ((((p_ext_rescfg)->fw_feature_bitmap) & \
       FW_FEATURE_VDEV_STATS) ? 1 : 0)
#define resource_config_wl_prio_gpio(p_ext_rescfg) \
    ((p_ext_rescfg)->wlan_priority_gpio)
#define resource_config_coex_version(p_ext_rescfg) \
    ((p_ext_rescfg)->coex_version)
#define resource_config_coex_gpio_pin_1(p_ext_rescfg) \
    ((p_ext_rescfg)->coex_gpio_pin_1)
#define resource_config_coex_gpio_pin_2(p_ext_rescfg) \
    ((p_ext_rescfg)->coex_gpio_pin_2)
#define resource_config_coex_gpio_pin_3(p_ext_rescfg) \
    ((p_ext_rescfg)->coex_gpio_pin_3)
#define resource_config_tdls(p_ext_rescfg) \
    ((((p_ext_rescfg)->fw_feature_bitmap) & \
       FW_FEATURE_TDLS) ? 1 : 0)
#define resource_config_tdls_explicit_mode_only(p_ext_rescfg) \
    ((((p_ext_rescfg)->fw_feature_bitmap) & \
       FW_FEATURE_TDLS_EXPLICIT_MODE_ONLY) ? 1 : 0)
#define resource_config_tdls_uapsd_buffer_sta(p_ext_rescfg) \
    ((((p_ext_rescfg)->fw_feature_bitmap) & \
       FW_FEATURE_TDLS_UAPSD_BUFFER_STA) ? 1 : 0)
#define resource_config_tdls_uapsd_sleep_sta(p_ext_rescfg) \
    ((((p_ext_rescfg)->fw_feature_bitmap) & \
       FW_FEATURE_TDLS_UAPSD_SLEEP_STA) ? 1 : 0)
#define resource_config_tdls_offchan(p_ext_rescfg) \
    ((((p_ext_rescfg)->fw_feature_bitmap) & \
       FW_FEATURE_TDLS_OFFCHAN) ? 1 : 0)
#define resource_config_tdls_conn_tracker_in_host_mode(p_ext_rescfg) \
    ((((p_ext_rescfg)->fw_feature_bitmap) & \
       FW_FEATURE_TDLS_CONN_TRACKER_IN_HOST_MODE) ? 1 : 0)
#define resource_config_tdls_wider_bandwidth(p_ext_rescfg) \
    ((((p_ext_rescfg)->fw_feature_bitmap) & \
       FW_FEATURE_TDLS_WIDER_BANDWIDTH) ? 1 : 0)
#define resource_config_fw_vow_features(p_ext_rescfg) \
    ((((p_ext_rescfg)->fw_feature_bitmap) & \
       FW_FEATURE_VOW_FEATURES) ? 1 : 0)
#define resource_config_fw_vow_stats(p_ext_rescfg) \
    ((((p_ext_rescfg)->fw_feature_bitmap) & \
       FW_FEATURE_VOW_STATS) ? 1 : 0)
#define resource_config_fw_tx_data_ack_rssi(p_ext_rescfg) \
    ((((p_ext_rescfg)->fw_feature_bitmap) & \
       FW_FEATURE_TX_DATA_ACK_RSSI) ? 1 : 0)

typedef struct {
    wmi_resource_config   resource_config;
    A_UINT32              num_host_mem_chunks;
    /*
     * variable number of host memory chunks.
     * This should be the last element in the structure
     */
    wlan_host_memory_chunk host_mem_chunks[1];
} wmi_init_cmd;
/**
 * TLV for channel list
 */

/*
 * lower 16 bits (0 - 15): frequency.
 * upper 8  bits (16-24) :  phy mode.
 */
#define WMI_SCAN_CHAN_FREQ_SHIFT         0
#define WMI_SCAN_CHAN_FREQ_MASK          0xffff
#define WMI_SCAN_CHAN_MODE_SHIFT    16
#define WMI_SCAN_CHAN_MODE_MASK     0xff


/* if mode is 0 then it is ignored by th FW and will use any mode as long as the frequency matches */
#define WMI_SCAN_CHAN_SET_MODE(_c,_m)                                   \
    ( (_c) = (((_c) & ~(WMI_SCAN_CHAN_MODE_MASK << WMI_SCAN_CHAN_MODE_SHIFT)) | \
            (((_m) & WMI_SCAN_CHAN_MODE_MASK)  <<  WMI_SCAN_CHAN_MODE_SHIFT) ))
#define WMI_SCAN_CHAN_GET_MODE(_c) \
    ( ((_c) >> WMI_SCAN_CHAN_MODE_SHIFT ) & WMI_SCAN_CHAN_MODE_MASK )
#define WMI_SCAN_CHAN_SET_FREQ(_c,_f) \
    ( (_c) =  (((_c) & ~(WMI_SCAN_CHAN_FREQ_MASK << WMI_SCAN_CHAN_FREQ_SHIFT)) | \
             (((_f) & WMI_SCAN_CHAN_FREQ_MASK) << WMI_SCAN_CHAN_FREQ_SHIFT) ))
#define WMI_SCAN_CHAN_GET_FREQ(_c) \
    ( ((_c) >> WMI_SCAN_CHAN_FREQ_SHIFT ) & WMI_SCAN_CHAN_FREQ_MASK )

typedef struct {
    /** WMI_CHAN_LIST_TAG */
    A_UINT32     tag;
    /** # if channels to scan */
    A_UINT32 num_chan;
    /*
     * channel_list lower 16bit represent frequency in mhz and bits 16-23
     * represent PHY mode
     */
    A_UINT32 channel_list[1];
} wmi_chan_list;


/**
 * TLV for bssid list
 */
typedef struct {
    /** WMI_BSSID_LIST_TAG */
    A_UINT32     tag;
    /** number of bssids   */
    A_UINT32 num_bssid;
    /** bssid list         */
    wmi_mac_addr bssid_list[1];
} wmi_bssid_list;

/**
 * TLV for  ie data.
 */
typedef struct {
    /** WMI_IE_TAG */
    A_UINT32     tag;
    /** number of bytes in ie data   */
    A_UINT32 ie_len;
    /** ie data array  (ie_len adjusted to  number of words  (ie_len + 4)/4 )  */
    A_UINT32 ie_data[1];
} wmi_ie_data;


typedef struct {
    /** Len of the SSID */
    A_UINT32     ssid_len;
    /** SSID */
    A_UINT32     ssid[8];
} wmi_ssid;

typedef struct {
    /** WMI_SSID_LIST_TAG */
    A_UINT32     tag;
    A_UINT32     num_ssids;
    wmi_ssid ssids[1];
} wmi_ssid_list;

typedef struct {
    /** WMI_SCAN_START_OFFSET_TAG */
    A_UINT32     tag;
    /** number of start tsf offsets */
    A_UINT32     num_offset;
    /** array of start tsf offsets provided in milliseconds */
    A_UINT32     start_tsf_offset[1];
} wmi_scan_start_offset;

/* prefix used by scan requestor ids on the host */
#define WMI_HOST_SCAN_REQUESTOR_ID_PREFIX 0xA000
/* prefix used by scan request ids generated on the host */
/* host cycles through the lower 12 bits to generate ids */
#define WMI_HOST_SCAN_REQ_ID_PREFIX 0xA000

#define WLAN_SCAN_PARAMS_MAX_SSID    16
#define WLAN_SCAN_PARAMS_MAX_BSSID   4
#define WLAN_SCAN_PARAMS_MAX_IE_LEN  256

typedef struct {
    /** Scan ID */
    A_UINT32 scan_id;
    /** Scan requestor ID */
    A_UINT32 scan_req_id;
    /** VDEV id(interface) that is requesting scan */
    A_UINT32 vdev_id;
    /** Scan Priority, input to scan scheduler */
    A_UINT32 scan_priority;
    /** Scan events subscription */
    A_UINT32 notify_scan_events;
    /** dwell time in msec on active channels */
    A_UINT32 dwell_time_active;
    /** dwell time in msec on passive channels */
    A_UINT32 dwell_time_passive;
    /** min time in msec on the BSS channel,only valid if atleast one VDEV is active*/
    A_UINT32 min_rest_time;
    /** max rest time in msec on the BSS channel,only valid if at least one VDEV is active*/
    /** the scanner will rest on the bss channel at least min_rest_time. after min_rest_time the scanner
     *  will start checking for tx/rx activity on all VDEVs. if there is no activity the scanner will
     *  switch to off channel. if there is activity the scanner will let the radio on the bss channel
     *  until max_rest_time expires.at max_rest_time scanner will switch to off channel
     *  irrespective of activity. activity is determined by the idle_time parameter.
     */
    A_UINT32  max_rest_time;
    /** time before sending next set of probe requests.
     *   The scanner keeps repeating probe requests transmission with period specified by repeat_probe_time.
     *   The number of probe requests specified depends on the ssid_list and bssid_list
     */
    A_UINT32  repeat_probe_time;
    /** time in msec between 2 consequetive probe requests with in a set. */
    A_UINT32  probe_spacing_time;
    /** data inactivity time in msec on bss channel that will be used by scanner for measuring the inactivity  */
    A_UINT32 idle_time;
    /** maximum time in msec allowed for scan  */
    A_UINT32  max_scan_time;
    /** delay in msec before sending first probe request after switching to a channel */
    A_UINT32  probe_delay;
    /** Scan control flags */
    A_UINT32 scan_ctrl_flags;
    /** Burst duration time in msec*/
    A_UINT32 burst_duration;
    /**
     * TLV (tag length value )  paramerters follow the scan_cmd structure.
     * TLV can contain channel list, bssid list, ssid list and
     * ie. the TLV tags are defined above;
     */
} wmi_start_scan_cmd;

/**
 * scan control flags.
 */

/** passively scan all channels including active channels */
#define WMI_SCAN_FLAG_PASSIVE        0x1
/** add wild card ssid probe request even though ssid_list is specified. */
#define WMI_SCAN_ADD_BCAST_PROBE_REQ 0x2
/** add cck rates to rates/xrate ie for the generated probe request */
#define WMI_SCAN_ADD_CCK_RATES 0x4
/** add ofdm rates to rates/xrate ie for the generated probe request */
#define WMI_SCAN_ADD_OFDM_RATES 0x8
/** To enable indication of Chan load and Noise floor to host */
#define WMI_SCAN_CHAN_STAT_EVENT 0x10
/** Filter Probe request frames  */
#define WMI_SCAN_FILTER_PROBE_REQ 0x20
/**When set, not to scan DFS channels*/
#define WMI_SCAN_BYPASS_DFS_CHN 0x40
/**When set, certain errors are ignored and scan continues.
* Different FW scan engine may use its own logic to decide what errors to ignore*/
#define WMI_SCAN_CONTINUE_ON_ERROR 0x80
/** allow mgmt transmission during off channel scan */
#define WMI_SCAN_OFFCHAN_MGMT_TX    0x20
/** allow data transmission during off channel scan */
#define WMI_SCAN_OFFCHAN_DATA_TX    0x40
/** set scan with promiscous mode */
#define WMI_SCAN_PROMISCOUS_MODE    0x80
/** allow capture ppdu with phy errrors */
#define WMI_SCAN_CAPTURE_PHY_ERROR  0x100
/** always do passive scan on passive channels */
#define WMI_SCAN_FLAG_STRICT_PASSIVE_ON_PCHN 0x200
/** set HALF (10MHz) rate support */
#define WMI_SCAN_FLAG_HALF_RATE_SUPPORT    0x20000
/** set Quarter (5MHz) rate support */
#define WMI_SCAN_FLAG_QUARTER_RATE_SUPPORT 0x40000
/** WMI_SCAN_CLASS_MASK must be the same value as IEEE80211_SCAN_CLASS_MASK */
#define WMI_SCAN_CLASS_MASK 0xFF000000

/*
* Masks identifying types/ID of scans
* Scan_Stop macros should be the same value as below defined in UMAC
* #define IEEE80211_SPECIFIC_SCAN       0x00000000
* #define IEEE80211_VAP_SCAN            0x01000000
* #define IEEE80211_ALL_SCANS           0x04000000
*/
#define WMI_SCAN_STOP_ONE 0x00000000
#define WMI_SCN_STOP_VAP_ALL 0x01000000
#define WMI_SCAN_STOP_ALL 0x04000000

typedef struct {
    /** requestor requesting cancel  */
    A_UINT32 requestor;
    /** Scan ID */
    A_UINT32 scan_id;
    /**
    * Req Type
    * req_type should be WMI_SCAN_STOP_ONE, WMI_SCN_STOP_VAP_ALL or WMI_SCAN_STOP_ALL
    * WMI_SCAN_STOP_ONE indicates to stop a specific scan with scan_id
    * WMI_SCN_STOP_VAP_ALL indicates to stop all scan requests on a specific vDev with vdev_id
    * WMI_SCAN_STOP_ALL indicates to stop all scan requests in both Scheduler's queue and Scan Engine
    */
    A_UINT32 req_type;
    /**
    * vDev ID
    * used when req_type equals to WMI_SCN_STOP_VAP_ALL, it indexed the vDev on which to stop the scan
    */
    A_UINT32 vdev_id;
} wmi_stop_scan_cmd;

typedef struct {
    A_UINT32 num_scan_chans;
    wmi_channel chan_info[1];
} wmi_scan_chan_list_cmd;

typedef enum {
    WMI_SCAN_PRIORITY_VERY_LOW    = 0,
    WMI_SCAN_PRIORITY_LOW,
    WMI_SCAN_PRIORITY_MEDIUM,
    WMI_SCAN_PRIORITY_HIGH,
    WMI_SCAN_PRIORITY_VERY_HIGH,

    WMI_SCAN_PRIORITY_COUNT   /* number of priorities supported */
} wmi_scan_priority;
typedef A_UINT32 WLAN_PRIORITY_MAPPING[WMI_SCAN_PRIORITY_COUNT];

/**
* to keep align with UMAC implementation, we pass only vdev_type but not vdev_subtype when we overwrite an entry for a specific vdev_subtype
* ex. if we need overwrite P2P Client prority entry, we will overwrite the whole table for WLAN_M_STA
* we will generate the new WLAN_M_STA table with modified P2P Client Entry but keep STA entry intact
*/
typedef struct {
    /**
    * used as an index to find the proper table for a specific vdev type in default_scan_priority_mapping_table
    * vdev_type should be one of enum in WLAN_OPMODE which inculdes WLAN_M_IBSS, WLAN_M_STA, WLAN_M_AP and WLAN_M_MONITOR currently
    */
    A_UINT32      vdev_type;
    /**
    * number of rows in mapping_table for a specific vdev
    * for WLAN_M_STA type, there are 3 entries in the table (refer to default_scan_priority_mapping_table definition)
    */
    A_UINT32                    number_rows;
    /**  mapping_table for a specific vdev */
    WLAN_PRIORITY_MAPPING mapping_table[1];
}wmi_scan_sch_priority_table_cmd;

/** update flags */
#define WMI_SCAN_UPDATE_SCAN_PRIORITY           0x1
#define WMI_SCAN_UPDATE_SCAN_MIN_REST_TIME      0x2
#define WMI_SCAN_UPDATE_SCAN_MAX_REST_TIME      0x4

typedef struct {
    /** requestor requesting update scan request  */
    A_UINT32 requestor;
    /** Scan ID of the scan request that need to be update */
    A_UINT32 scan_id;
    /** update flags, indicating which of the following fields are valid and need to be updated*/
    A_UINT32 scan_update_flags;
    /** scan priority. Only valid if WMI_SCAN_UPDATE_SCAN_PRIORITY flag is set in scan_update_flag */
    A_UINT32 scan_priority;
    /** min rest time. Only valid if WMI_SCAN_UPDATE_MIN_REST_TIME flag is set in scan_update_flag */
    A_UINT32 min_rest_time;
    /** min rest time. Only valid if WMI_SCAN_UPDATE_MAX_REST_TIME flag is set in scan_update_flag */
    A_UINT32 max_rest_time;
} wmi_scan_update_request_cmd;

enum wmi_scan_event_type {
    WMI_SCAN_EVENT_STARTED=0x1,
    WMI_SCAN_EVENT_COMPLETED=0x2,
    WMI_SCAN_EVENT_BSS_CHANNEL=0x4,
    WMI_SCAN_EVENT_FOREIGN_CHANNEL = 0x8,
    WMI_SCAN_EVENT_DEQUEUED=0x10,       /* scan request got dequeued */
    WMI_SCAN_EVENT_PREEMPTED=0x20,		/* preempted by other high priority scan */
    WMI_SCAN_EVENT_START_FAILED=0x40,   /* scan start failed */
    WMI_SCAN_EVENT_RESTARTED=0x80,    /*scan restarted*/
    WMI_SCAN_EVENT_FOREIGN_CHANNEL_EXIT = 0x100,
    WMI_SCAN_EVENT_INVALID=0x200,
    WMI_SCAN_EVENT_GPIO_TIMEOUT=0x400,
    WMI_SCAN_EVENT_MAX=0x8000
};

enum wmi_scan_completion_reason {
    /** scan related events */
     WMI_SCAN_REASON_NONE                = 0xFF,
     WMI_SCAN_REASON_COMPLETED           = 0,
     WMI_SCAN_REASON_CANCELLED           = 1,
     WMI_SCAN_REASON_PREEMPTED           = 2,
	 WMI_SCAN_REASON_TIMEDOUT            = 3,
     WMI_SCAN_REASON_INTERNAL_FAILURE    = 4, /* This reason indication failures when performaing scan */
     WMI_SCAN_REASON_INVALID_CHANNELS    = 5,
     WMI_SCAN_REASON_MAX,
};


typedef struct {
    /** scan event (wmi_scan_event_type) */
    A_UINT32 event;
    /** status of the scan completion event */
    A_UINT32 reason;
    /** channel freq , only valid for FOREIGN channel event*/
    A_UINT32 channel_freq;
    /**id of the requestor whose scan is in progress */
    A_UINT32 requestor;
    /**id of the scan that is in progress */
    A_UINT32 scan_id;
    /**id of VDEV that requested the scan */
    A_UINT32 vdev_id;
} wmi_scan_event;

/*
 * This defines how much headroom is kept in the
 * receive frame between the descriptor and the
 * payload, in order for the WMI PHY error and
 * management handler to insert header contents.
 *
 * This is in bytes.
 */
#define WMI_MGMT_RX_HDR_HEADROOM    (52)

/** This event will be used for sending scan results
 * as well as rx mgmt frames to the host. The rx buffer
 * will be sent as part of this WMI event. It would be a
 * good idea to pass all the fields in the RX status
 * descriptor up to the host.
 *
 * The WMI_RX_EXT_INFO bit in status field denotes presence
 * of extension info (wmi_mgmt_rx_ext_info) at end of beacon.
 * i.e. after buf_len from management frame start address.
 * If present, the wmi_mgmt_rx_ext_info is aligned to a 4-byte
 * boundary within the message buffer.  Hence, if buf_len is not
 * a multiple of 4, 1 to 3 alignment padding bytes will precede
 * the wmi_mgmt_rx_ext_info.
 */
#define WLAN_MAX_ANTENNA 4 /* To support beelinear, which is up to 4 chains */
typedef struct {
    /** channel on which this frame is received. */
    A_UINT32     channel;
    /** snr information used to cal rssi */
    A_UINT32     snr;
    /** RSSI of PRI 20MHz for each chain. */
    A_UINT8 rssi_ctl[WLAN_MAX_ANTENNA];
    /** Rate kbps */
    A_UINT32     rate;
    /** rx phy mode WLAN_PHY_MODE */
    A_UINT32     phy_mode;
    /** length of the frame */
    A_UINT32     buf_len;
    /** rx status */
    A_UINT32     status;
} wmi_mgmt_rx_hdr;

typedef struct {
    /** management header */
    wmi_mgmt_rx_hdr hdr;
    /** management frame buffer */
    A_UINT8 bufp[1];
} wmi_mgmt_rx_event;

/* The below structure will be appended at the A_UINT32 aligned position
 * following the end of beacon before sending it to host.
 * It contains the local TSF value when the beacon is received.
 * The lower 32 bits of the TSF (rx_tsf_l32) is copied by FW from
 * TSF timestamp in the RX MAC descriptor provided by HW.
 * The Upper 32 bits (rx_tsf_u32) is filled by reading the TSF register
 * after the packet is received.
 * The WMI_RX_EXT_INFO bit in status field in management rx header
 * specifies the presence of extension info at end of beacon.
 * For now TSF only is available in extension info.
 * Any additional data to be passed with beacon should be added
 * at end of this structure.
 */
typedef struct {
   A_UINT32 rx_tsf_l32;
   A_UINT32 rx_tsf_u32;
} wmi_mgmt_rx_ext_info;

/* WMI PHY Error RX */

#if 0
typedef struct {
    /** TSF timestamp */
    A_UINT32 tsf_timestamp;
    /** RSSI on chain 0 through 3 */
    A_UINT32 rssi_chain0;
    A_UINT32 rssi_chain1;
    A_UINT32 rssi_chain2;
    A_UINT32 rssi_chain3;
    /** Combined RSSI over all chains */
    A_UINT32 rssi_comb;
    /** PHY error code */
    A_UINT32 phy_err_code;
    /** Length of the frame */
    A_UINT32 buf_len;
}wmi_phyerr_rx_hdr;

typedef struct {
    /** Phy error event header */
    wmi_phyerr_rx_hdr hdr;
    /** frame buffer */
    A_UINT8 bufp[1];
}wmi_phyerr_rx_event;
#endif

typedef struct {
    /** TSF timestamp */
    A_UINT32 tsf_timestamp;

    /**
     * Current freq1, freq2
     *
     * [7:0]:    freq1[lo]
     * [15:8] :   freq1[hi]
     * [23:16]:   freq2[lo]
     * [31:24]:   freq2[hi]
     */
    A_UINT32 freq_info_1;

    /**
     * Combined RSSI over all chains and channel width for this PHY error
     *
     * [7:0]: RSSI combined
     * [15:8]: Channel width (MHz)
     * [23:16]: PHY error code
     * [24:16]: reserved (future use)
     */
    A_UINT32 freq_info_2;

    /**
     * RSSI on chain 0 through 3
     *
     * This is formatted the same as the PPDU_START RX descriptor
     * field:
     *
     * [7:0]:   pri20
     * [15:8]:  sec20
     * [23:16]: sec40
     * [31:24]: sec80
     */
    A_UINT32 rssi_chain0;
    A_UINT32 rssi_chain1;
    A_UINT32 rssi_chain2;
    A_UINT32 rssi_chain3;

   /**
     * Last calibrated NF value for chain 0 through 3
     *
     * nf_list_1:
     *
     * + [15:0] - chain 0
     * + [31:16] - chain 1
     *
     * nf_list_2:
     *
     * + [15:0] - chain 2
     * + [31:16] - chain 3
     */
    A_UINT32 nf_list_1;
    A_UINT32 nf_list_2;

    /** Length of the frame */
    A_UINT32 buf_len;
} wmi_single_phyerr_rx_hdr;

typedef struct {
    /** TSF timestamp */
    A_UINT32 tsf_l32;
    A_UINT32 tsf_u32;

    /**
     * Current freq1, freq2
     *
     * [7:0]:    freq1[lo]
     * [15:8] :   freq1[hi]
     * [23:16]:   freq2[lo]
     * [31:24]:   freq2[hi]
     */
    A_UINT32 freq_info_1;

    /**
     * Combined RSSI over all chains and channel width for this PHY error
     *
     * [7:0]: RSSI combined
     * [15:8]: Channel width (MHz)
     * [23:16]: PHY error code
     * [24:16]: reserved (future use)
     */
    A_UINT32 freq_info_2;

    /**
     * RSSI on chain 0 through 3
     *
     * This is formatted the same as the PPDU_START RX descriptor
     * field:
     *
     * [7:0]:   pri20
     * [15:8]:  sec20
     * [23:16]: sec40
     * [31:24]: sec80
     */
    A_UINT32 rssi_chain0;
    A_UINT32 rssi_chain1;
    A_UINT32 rssi_chain2;
    A_UINT32 rssi_chain3;

   /**
     * Last calibrated NF value for chain 0 through 3
     *
     * nf_list_1:
     *
     * + [15:0] - chain 0
     * + [31:16] - chain 1
     *
     * nf_list_2:
     *
     * + [15:0] - chain 2
     * + [31:16] - chain 3
     */
    A_UINT32 nf_list_1;
    A_UINT32 nf_list_2;

    /* Composite phy error mask */
    A_UINT32 phy_err_mask0;
    A_UINT32 phy_err_mask1;
    /* time stamp from PPDU_END */
    A_UINT32 tsf_timestamp;

    /** Length of the frame */
    A_UINT32 buf_len;
} wmi_composite_phyerr_rx_hdr;



#define WMI_UNIFIED_FREQINFO_1_LO   0x000000ff
#define WMI_UNIFIED_FREQINFO_1_LO_S 0
#define WMI_UNIFIED_FREQINFO_1_HI   0x0000ff00
#define WMI_UNIFIED_FREQINFO_1_HI_S 8
#define WMI_UNIFIED_FREQINFO_2_LO   0x00ff0000
#define WMI_UNIFIED_FREQINFO_2_LO_S 16
#define WMI_UNIFIED_FREQINFO_2_HI   0xff000000
#define WMI_UNIFIED_FREQINFO_2_HI_S 24

#define WMI_PHYERR_FLAG_5G_INTRF            0x01000000
#define WMI_PHYERR_FLAG_5G_INTRF_S          24
#define WMI_PHYERR_FLAG_2G_INTRF            0x02000000
#define WMI_PHYERR_FLAG_2G_INTRF_S          25

/*
 * Please keep in mind that these _SET macros break macro side effect
 * assumptions; don't be clever with them.
 */
#define WMI_UNIFIED_FREQ_INFO_GET(hdr, f)                                   \
            ( WMI_F_MS( (hdr)->freq_info_1,                                 \
              WMI_UNIFIED_FREQINFO_##f##_LO )                               \
              | (WMI_F_MS( (hdr)->freq_info_1,                              \
                 WMI_UNIFIED_FREQINFO_##f##_HI ) << 8) )

#define WMI_UNIFIED_FREQ_INFO_SET(hdr, f, v)                                \
        do {                                                                \
            WMI_F_RMW((hdr)->freq_info_1, (v) & 0xff,                       \
              WMI_UNIFIED_FREQINFO_##f##_LO);                               \
            WMI_F_RMW((hdr)->freq_info_1, ((v) >> 8) & 0xff,                \
                WMI_UNIFIED_FREQINFO_##f##_HI);                             \
        } while (0)

#define WMI_UNIFIED_FREQINFO_2_RSSI_COMB    0x000000ff
#define WMI_UNIFIED_FREQINFO_2_RSSI_COMB_S  0
#define WMI_UNIFIED_FREQINFO_2_CHWIDTH      0x0000ff00
#define WMI_UNIFIED_FREQINFO_2_CHWIDTH_S    8
#define WMI_UNIFIED_FREQINFO_2_PHYERRCODE   0x00ff0000
#define WMI_UNIFIED_FREQINFO_2_PHYERRCODE_S 16

#define WMI_UNIFIED_RSSI_COMB_GET(hdr)                                      \
            ( (int8_t) (WMI_F_MS((hdr)->freq_info_2,                        \
                WMI_UNIFIED_FREQINFO_2_RSSI_COMB)))

#define WMI_UNIFIED_RSSI_COMB_SET(hdr, v)                                   \
            WMI_F_RMW((hdr)->freq_info_2, (v) & 0xff,                       \
              WMI_UNIFIED_FREQINFO_2_RSSI_COMB);

#define WMI_UNIFIED_CHWIDTH_GET(hdr)                                        \
            WMI_F_MS((hdr)->freq_info_2, WMI_UNIFIED_FREQINFO_2_CHWIDTH)

#define WMI_UNIFIED_CHWIDTH_SET(hdr, v)                                     \
            WMI_F_RMW((hdr)->freq_info_2, (v) & 0xff,                       \
              WMI_UNIFIED_FREQINFO_2_CHWIDTH);

#define WMI_UNIFIED_PHYERRCODE_GET(hdr)                                     \
            WMI_F_MS((hdr)->freq_info_2, WMI_UNIFIED_FREQINFO_2_PHYERRCODE)

#define WMI_UNIFIED_PHYERRCODE_SET(hdr, v)                                  \
            WMI_F_RMW((hdr)->freq_info_2, (v) & 0xff,                       \
              WMI_UNIFIED_FREQINFO_2_PHYERRCODE);

#define WMI_UNIFIED_INTRF_SET(hdr, v, c)                                    \
               WMI_F_RMW((hdr)->freq_info_2, (v) & 0x3,                    \
               WMI_PHYERR_FLAG_##c##_INTRF);

#define WMI_UNIFIED_INTRF_GET(hdr, c)                                       \
              (WMI_F_MS((hdr)->freq_info_2,                               \
              WMI_PHYERR_FLAG_##c##_INTRF));

#define WMI_UNIFIED_CHAIN_0     0x0000ffff
#define WMI_UNIFIED_CHAIN_0_S   0
#define WMI_UNIFIED_CHAIN_1     0xffff0000
#define WMI_UNIFIED_CHAIN_1_S   16
#define WMI_UNIFIED_CHAIN_2     0x0000ffff
#define WMI_UNIFIED_CHAIN_2_S   0
#define WMI_UNIFIED_CHAIN_3     0xffff0000
#define WMI_UNIFIED_CHAIN_3_S   16

#define WMI_UNIFIED_CHAIN_0_FIELD   nf_list_1
#define WMI_UNIFIED_CHAIN_1_FIELD   nf_list_1
#define WMI_UNIFIED_CHAIN_2_FIELD   nf_list_2
#define WMI_UNIFIED_CHAIN_3_FIELD   nf_list_2

#define WMI_UNIFIED_NF_CHAIN_GET(hdr, c)                                    \
            ((int16_t) (WMI_F_MS((hdr)->WMI_UNIFIED_CHAIN_##c##_FIELD,      \
              WMI_UNIFIED_CHAIN_##c)))

#define WMI_UNIFIED_NF_CHAIN_SET(hdr, c, nf)                                \
            WMI_F_RMW((hdr)->WMI_UNIFIED_CHAIN_##c##_FIELD, (nf) & 0xffff,  \
              WMI_UNIFIED_CHAIN_##c);

/*
 * For now, this matches what the underlying hardware is doing.
 * Update ar6000ProcRxDesc() to use these macros when populating
 * the rx descriptor and then we can just copy the field over
 * to the WMI PHY notification without worrying about breaking
 * things.
 */
#define WMI_UNIFIED_RSSI_CHAN_PRI20     0x000000ff
#define WMI_UNIFIED_RSSI_CHAN_PRI20_S   0
#define WMI_UNIFIED_RSSI_CHAN_SEC20     0x0000ff00
#define WMI_UNIFIED_RSSI_CHAN_SEC20_S   8
#define WMI_UNIFIED_RSSI_CHAN_SEC40     0x00ff0000
#define WMI_UNIFIED_RSSI_CHAN_SEC40_S   16
#define WMI_UNIFIED_RSSI_CHAN_SEC80     0xff000000
#define WMI_UNIFIED_RSSI_CHAN_SEC80_S   24

#define WMI_UNIFIED_RSSI_CHAN_SET(hdr, c, ch, rssi)                         \
            WMI_F_RMW((hdr)->rssi_chain##c, (rssi) & 0xff,                  \
              WMI_UNIFIED_RSSI_CHAN_##ch);

#define WMI_UNIFIED_RSSI_CHAN_GET(hdr, c, ch)                               \
            ((int8_t) (WMI_F_MS((hdr)->rssi_chain##c,                       \
              WMI_UNIFIED_RSSI_CHAN_##ch)))

typedef struct {
    /** Phy error event header */
    wmi_single_phyerr_rx_hdr hdr;
    /** frame buffer */
    A_UINT8 bufp[1];
}wmi_single_phyerr_rx_event;

typedef struct {
    /** Phy error phy error count */
    A_UINT32 num_phyerr_events;
    A_UINT32 tsf_l32;
    A_UINT32 tsf_u32;
} wmi_comb_phyerr_rx_hdr;

typedef struct {
    /** Phy error phy error count */
    wmi_comb_phyerr_rx_hdr hdr;
    /** frame buffer - contains multiple payloads in the order:
     *                    header - payload, header - payload...
     *  (The header is of type: wmi_single_phyerr_rx_hdr) */
    A_UINT8 *bufp;
} wmi_comb_phyerr_rx_event;

typedef struct {
    /** Phy error event header */
    wmi_composite_phyerr_rx_hdr hdr;
    /** frame buffer */
    A_UINT8 bufp[1];
}wmi_composite_phyerr_rx_event;


/* WMI MGMT TX  */
typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /** xmit rate */
    A_UINT32 tx_rate;
    /** xmit power */
    A_UINT32 tx_power;
    /** Buffer length in bytes */
    A_UINT32 buf_len;
} wmi_mgmt_tx_hdr;

typedef struct {
    /** header */
    wmi_mgmt_tx_hdr hdr;
    /** buffer */
    A_UINT8 bufp[1];
} wmi_mgmt_tx_cmd;

typedef struct {
    A_UINT32 value;
} wmi_echo_event;

typedef struct {
    A_UINT32 max_tgt_msdu_cloned;
} wmi_mcast_buf_release_event;

typedef struct {
    A_UINT32 value;
}wmi_echo_cmd;


typedef struct {
    /** 2 char iso name byte 0 contains second char and
        byte 1 contains first char of the country code name */
    A_UINT32 country_code;
} wmi_pdev_set_country_cmd;

typedef struct {
    /** reg domain code */
    A_UINT32 reg_domain;
    A_UINT32 reg_domain_2G;
    A_UINT32 reg_domain_5G;
    A_UINT32 conformance_test_limit_2G;
    A_UINT32 conformance_test_limit_5G;
    A_UINT32 dfs_domain;
} wmi_pdev_set_regdomain_cmd;

typedef struct {
    /** TRUE for scan start and flase for scan end */
    A_UINT32 scan_start;
} wmi_pdev_scan_cmd;

/* WMI support for setting ratemask in target */

typedef struct {
    A_UINT32 vdev_id;
    /* 0 - cck/ofdm
     * 1 - HT
     * 2 - VHT */
    A_UINT32 type;

    A_UINT32 mask_lower32;
    A_UINT32 mask_higher32;
} wmi_vdev_config_ratemask;

/*Command to set/unset chip in quiet mode*/
typedef struct {
	A_UINT32 period;		/*period in TUs*/
	A_UINT32 duration;		/*duration in TUs*/
	A_UINT32 next_start;	/*offset in TUs*/
    A_UINT32 enabled; 		/*enable/disable*/
} wmi_pdev_set_quiet_cmd;

/*
 * Command to enable/disable Green AP Power Save.
 * This helps conserve power during AP operation. When the AP has no
 * stations associated with it, the host can enable Green AP Power Save
 * to request the firmware to shut down all but one transmit and receive
 * chains.
 */
typedef struct {
    A_UINT32 enable; 		 /*1:enable, 0:disable*/
} wmi_pdev_green_ap_ps_enable_cmd;

#define SMART_ANT_MAX_GPIOS 4 /* Maximum GPIO pins/function values to control antennas */
typedef struct {
    A_UINT32 enable;                          /*1:enable, 0:disable*/
    A_UINT32 mode;                            /*1:GPIO parallel mode, 0:GPIO serial mode*/
    A_UINT32 rx_antenna;                      /* rx antenna*/
    A_UINT32 tx_default_antenna;              /* tx default antenna */
    A_UINT32 gpio_pin[SMART_ANT_MAX_GPIOS];   /* For serial: index 0-strobe index 1-data, For Parllel: per stream */
    A_UINT32 gpio_func[SMART_ANT_MAX_GPIOS];  /* GPIO function values for Smart Antenna */
} wmi_pdev_smart_ant_enable_cmd;


typedef struct {
    A_UINT32 rx_antenna;         /* rx antenna */
} wmi_pdev_smart_ant_set_rx_antenna_cmd;

#define SMART_ANT_MAX_RATE_SERIES 2 /* Maximum rate series used for transmission */
#define SMART_ANT_MAX_SA_CHAINS   4 /* Maximum chains for rx and tx */
#define SA_NODE_CONFIG_ARGS_LEN   4 /* number of dword args */
typedef struct {
    /** unique id identifying the vdev, generated by the caller */
    A_UINT32 vdev_id;
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /* antenna array */
    A_UINT32 antenna_series[SMART_ANT_MAX_RATE_SERIES];
} wmi_peer_sant_set_tx_antenna_cmd;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /* rate array */
    A_UINT32  train_rate_series[SMART_ANT_MAX_RATE_SERIES];
    /* antenna array */
    A_UINT32 train_antenna_series[SMART_ANT_MAX_RATE_SERIES];
    /* num packets; 0-stop training */
    A_UINT32 num_pkts;
    /* Rate flags */
    /* TODO: For future use? */
    A_UINT32 rc_flags[SMART_ANT_MAX_RATE_SERIES];
} wmi_peer_sant_set_train_antenna_cmd;

typedef struct {
    /** unique id identifying the vdev, generated by the caller */
    A_UINT32 vdev_id;
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /* command id*/
    A_UINT32 cmd_id;
    /* number of arguments passed */
    A_UINT32 args_count;
    /* argument list */
    A_UINT32 args[SA_NODE_CONFIG_ARGS_LEN];
} wmi_peer_sant_set_node_config_ops_cmd;

#define MAX_CCK_OFDM_RATE_DWORDS 3 /* Maximum CCK, OFDM rates supported; 4 rates in each dword */
#define MAX_MCS_RATE_DWORDS 10      /* Maximum MCS rates supported; 4 rates in each dword */
/* TODO: ratecode_160 needs to add for future chips */

typedef struct {
    A_UINT32 ratecode_legacy[MAX_CCK_OFDM_RATE_DWORDS]; /* Rate code array for CCK OFDM */
    A_UINT32 ratecode_20[MAX_MCS_RATE_DWORDS];         /* Rate code array for 20MHz BW */
    A_UINT32 ratecode_40[MAX_MCS_RATE_DWORDS];         /* Rate code array for 40MHz BW */
    A_UINT32 ratecode_80[MAX_MCS_RATE_DWORDS];         /* Rate code array for 80MHz BW */
    A_UINT32 ratecount;                               /* Max Rate count for each mode */
}wmi_peer_rate_info_t;

typedef struct {
    wmi_mac_addr peer_macaddr;
    wmi_peer_rate_info_t    peer_rate_info;
} wmi_peer_ratecode_list_event_t;

#define MAX_HT_IE_LEN 32
typedef struct {
    A_UINT32 ie_len; 		 /*length of the ht ie */
    A_UINT32 ie_data[1]; 	 /*length of the ht ie data */
} wmi_pdev_set_ht_ie_cmd;

#define MAX_VHT_IE_LEN 32
typedef struct {
    A_UINT32 ie_len; 		 /*length of the vht ie */
    A_UINT32 ie_data[1]; 	 /*length of the vht ie data */
} wmi_pdev_set_vht_ie_cmd;

typedef struct {
    wmi_mac_addr base_macaddr;
} wmi_pdev_set_base_macaddr_cmd;

typedef struct {
    wmi_mac_addr bridge_macaddr;
} wmi_pdev_set_bridge_macaddr_cmd;

#define MAX_NUM_CHAINS   4
typedef struct {
    A_UINT32 antCtrlCommon1;
    A_UINT32 antCtrlCommon2;
    A_UINT16 antCtrlChain[MAX_NUM_CHAINS];
} wmi_pdev_set_ant_switch_tbl_cmd;

/*
 * For now, the spectral configuration is global rather than
 * per-vdev.  The vdev is a placeholder and will be ignored
 * by the firmware.
 */
typedef struct {
        A_UINT32    vdev_id;
        A_UINT32    spectral_scan_count;
        A_UINT32    spectral_scan_period;
        A_UINT32    spectral_scan_priority;
        A_UINT32    spectral_scan_fft_size;
        A_UINT32    spectral_scan_gc_ena;
        A_UINT32    spectral_scan_restart_ena;
        A_UINT32    spectral_scan_noise_floor_ref;
        A_UINT32    spectral_scan_init_delay;
        A_UINT32    spectral_scan_nb_tone_thr;
        A_UINT32    spectral_scan_str_bin_thr;
        A_UINT32    spectral_scan_wb_rpt_mode;
        A_UINT32    spectral_scan_rssi_rpt_mode;
        A_UINT32    spectral_scan_rssi_thr;
        A_UINT32    spectral_scan_pwr_format;
        A_UINT32    spectral_scan_rpt_mode;
        A_UINT32    spectral_scan_bin_scale;
        A_UINT32    spectral_scan_dBm_adj;
        A_UINT32    spectral_scan_chn_mask;
} wmi_vdev_spectral_configure_cmd;

/*---- Start of TT config command---*/

#define TT_LEVELS               4              /* Number of thermal throttle zones */

typedef struct {
    A_UINT32 tmplwm;            /* sensor value in celsius when to exit to lower state */
    A_UINT32 tmphwm;            /* sensor value in celsius when to exit to higher state */
    A_UINT32 dcoffpercent;      /* duty cycle off percent 0-100. 0 means no off, 100 means no on (shutdown the phy). */
    A_UINT32 prio;              /* disable only the queues that have lower priority than configured. 0 means disable all queues */
} tt_level_config_t;

typedef struct {
    A_UINT32 enable;                                  /* 0:disable, 1:enable */
    A_UINT32 dc;                                      /* duty cycle in ms */
    A_UINT32 dc_per_event;                            /* how often (for how many duty cycles) the FW sends stats to host */
    tt_level_config_t levelconf[TT_LEVELS];           /* per zone config parameters */
} tt_config_t;

/*---- End of TT config command---*/

/*
 * Enabling, disabling and triggering the spectral scan
 * is a per-vdev operation.  That is, it will set channel
 * flags per vdev rather than globally; so concurrent scan/run
 * and multiple STA (eg p2p, tdls, multi-band STA) is possible.
 */
typedef struct {
    A_UINT32    vdev_id;
    /* 0 - ignore; 1 - trigger, 2 - clear trigger */
    A_UINT32    trigger_cmd;
    /* 0 - ignore; 1 - enable, 2 - disable */
    A_UINT32    enable_cmd;
} wmi_vdev_spectral_enable_cmd;

typedef enum {
WMI_CSA_IE_PRESENT = 0x00000001,
WMI_XCSA_IE_PRESENT = 0x00000002,
WMI_WBW_IE_PRESENT = 0x00000004,
WMI_CSWARP_IE_PRESENT = 0x00000008,
}WMI_CSA_EVENT_IES_PRESENT_FLAG;
typedef struct{
    A_UINT32 i_fc_dur;
//  Bit 0-15: FC
//  Bit 16-31: DUR
    wmi_mac_addr i_addr1;
    wmi_mac_addr i_addr2;
    A_UINT32 csa_ie[2];
    A_UINT32 xcsa_ie[2];
    A_UINT32 wb_ie[2];
    A_UINT32 cswarp_ie;
    A_UINT32 ies_present_flag; //WMI_CSA_EVENT_IES_PRESENT_FLAG
}wmi_csa_event;

typedef enum {
    /** TX chian mask */
    WMI_PDEV_PARAM_TX_CHAIN_MASK = 0x1,
    /** RX chian mask */
    WMI_PDEV_PARAM_RX_CHAIN_MASK,
    /** TX power limit for 2G Radio */
    WMI_PDEV_PARAM_TXPOWER_LIMIT2G,
    /** TX power limit for 5G Radio */
    WMI_PDEV_PARAM_TXPOWER_LIMIT5G,
    /** TX power scale */
    WMI_PDEV_PARAM_TXPOWER_SCALE,
    /** Beacon generation mode . 0: host, 1: target   */
    WMI_PDEV_PARAM_BEACON_GEN_MODE,
    /** Beacon generation mode . 0: staggered 1: bursted   */
    WMI_PDEV_PARAM_BEACON_TX_MODE,
    /** Resource manager off chan mode .
     * 0: turn off off chan mode. 1: turn on offchan mode
     */
    WMI_PDEV_PARAM_RESMGR_OFFCHAN_MODE,
    /** Protection mode  0: no protection 1:use CTS-to-self 2: use RTS/CTS */
    WMI_PDEV_PARAM_PROTECTION_MODE,
    /** Dynamic bandwidth 0: disable 1: enable */
    WMI_PDEV_PARAM_DYNAMIC_BW,
    /** Non aggregrate/ 11g sw retry threshold.0-disable */
    WMI_PDEV_PARAM_NON_AGG_SW_RETRY_TH,
    /** aggregrate sw retry threshold. 0-disable*/
    WMI_PDEV_PARAM_AGG_SW_RETRY_TH,
    /** Station kickout threshold (non of consecutive failures).0-disable */
    WMI_PDEV_PARAM_STA_KICKOUT_TH,
    /** Aggerate size scaling configuration per AC */
    WMI_PDEV_PARAM_AC_AGGRSIZE_SCALING,
    /** LTR enable */
    WMI_PDEV_PARAM_LTR_ENABLE,
    /** LTR latency for BE, in us */
    WMI_PDEV_PARAM_LTR_AC_LATENCY_BE,
    /** LTR latency for BK, in us */
    WMI_PDEV_PARAM_LTR_AC_LATENCY_BK,
    /** LTR latency for VI, in us */
    WMI_PDEV_PARAM_LTR_AC_LATENCY_VI,
    /** LTR latency for VO, in us  */
    WMI_PDEV_PARAM_LTR_AC_LATENCY_VO,
    /** LTR AC latency timeout, in ms */
    WMI_PDEV_PARAM_LTR_AC_LATENCY_TIMEOUT,
    /** LTR platform latency override, in us */
    WMI_PDEV_PARAM_LTR_SLEEP_OVERRIDE,
    /** LTR-M override, in us */
    WMI_PDEV_PARAM_LTR_RX_OVERRIDE,
    /** Tx activity timeout for LTR, in us */
    WMI_PDEV_PARAM_LTR_TX_ACTIVITY_TIMEOUT,
    /** L1SS state machine enable */
    WMI_PDEV_PARAM_L1SS_ENABLE,
    /** Deep sleep state machine enable */
    WMI_PDEV_PARAM_DSLEEP_ENABLE,
    /** RX buffering flush enable */
    WMI_PDEV_PARAM_PCIELP_TXBUF_FLUSH,
    /** RX buffering matermark */
    WMI_PDEV_PARAM_PCIELP_TXBUF_WATERMARK,
    /** RX buffering timeout enable */
    WMI_PDEV_PARAM_PCIELP_TXBUF_TMO_EN,
    /** RX buffering timeout value */
    WMI_PDEV_PARAM_PCIELP_TXBUF_TMO_VALUE,
    /** pdev level stats update period in ms */
    WMI_PDEV_PARAM_PDEV_STATS_UPDATE_PERIOD,
    /** vdev level stats update period in ms */
    WMI_PDEV_PARAM_VDEV_STATS_UPDATE_PERIOD,
    /** peer level stats update period in ms */
    WMI_PDEV_PARAM_PEER_STATS_UPDATE_PERIOD,
    /** beacon filter status update period */
    WMI_PDEV_PARAM_BCNFLT_STATS_UPDATE_PERIOD,
    /** QOS Mgmt frame protection MFP/PMF 0: disable, 1: enable */
    WMI_PDEV_PARAM_PMF_QOS,
    /** Access category on which ARP frames are sent */
    WMI_PDEV_PARAM_ARP_AC_OVERRIDE,
    /** DCS configuration */
    WMI_PDEV_PARAM_DCS,
    /** Enable/Disable ANI on target */
    WMI_PDEV_PARAM_ANI_ENABLE,
    /** configure the ANI polling period */
    WMI_PDEV_PARAM_ANI_POLL_PERIOD,
    /** configure the ANI listening period */
    WMI_PDEV_PARAM_ANI_LISTEN_PERIOD,
    /** configure OFDM immunity level */
    WMI_PDEV_PARAM_ANI_OFDM_LEVEL,
    /** configure CCK immunity level */
    WMI_PDEV_PARAM_ANI_CCK_LEVEL,
    /** Enable/Disable CDD for 1x1 STAs in rate control module */
    WMI_PDEV_PARAM_DYNTXCHAIN,
    /** Enable/Disable proxy STA */
    WMI_PDEV_PARAM_PROXY_STA,
    /** Enable/Disable low power state when all VDEVs are inactive/idle. */
    WMI_PDEV_PARAM_IDLE_PS_CONFIG,
    /** Enable/Disable power gating sleep */
    WMI_PDEV_PARAM_POWER_GATING_SLEEP,
    /** enable and disable aggregate burst along with duration */
    WMI_PDEV_PARAM_AGGR_BURST,

    /* Set the global RX decap mode */
    WMI_PDEV_PARAM_RX_DECAP_MODE,

    /** Enable/Disable Fast channel reset */
    WMI_PDEV_PARAM_FAST_CHANNEL_RESET,
    /* Set Bursting DUR */
    WMI_PDEV_PARAM_BURST_DUR,
    /* Set Bursting ENABLE */
    WMI_PDEV_PARAM_BURST_ENABLE,
    /** Default antenna for Smart antenna */
    WMI_PDEV_PARAM_SMART_ANTENNA_DEFAULT_ANTENNA,
    /** TID override for IGMP/MLD frames  */
    WMI_PDEV_PARAM_IGMPMLD_OVERRIDE,
    /** TID on which IGMP frames are sent */
    WMI_PDEV_PARAM_IGMPMLD_TID,
    /** Set the user-specified antenna gain */
    WMI_PDEV_PARAM_ANTENNA_GAIN,
    /** Set the user-specified RX filter */
    WMI_PDEV_PARAM_RX_FILTER,
    /* configure the user-specified MCAST tid for managed mcast feature*/
    /*0 -15 is the valid range. 0xff will clear the tid setting */
    WMI_PDEV_SET_MCAST_TO_UCAST_TID,
    /** Enable/Disable Proxy sta mode */
    WMI_PDEV_PARAM_PROXY_STA_MODE,
    /*configure the mcast2ucast mode for the pdev->peer_mcast. Can be any of the following
    wal_peer_mcast2ucast_disabled    = 0,
    wal_peer_mcast2ucast_drop_empty  = 1,-> Drop the frames if match is not found
    wal_peer_mcast2ucast_mcast_empty = 2,-> Send as mcast if match is not found
    */
    WMI_PDEV_PARAM_SET_MCAST2UCAST_MODE,
    /* Sets the Mcast buffers for cloning, to support Mcast enhancement */
    WMI_PDEV_PARAM_SET_MCAST2UCAST_BUFFER,
    /* Remove the Mcast buffers added by host */
    WMI_PDEV_PARAM_REMOVE_MCAST2UCAST_BUFFER,
    /** En/disable station power save state indication */
    WMI_PDEV_PEER_STA_PS_STATECHG_ENABLE,
    /** Access category on which ARP frames are sent */
    WMI_PDEV_PARAM_IGMPMLD_AC_OVERRIDE,
    /** allow or disallow interbss frame forwarding */
    WMI_PDEV_PARAM_BLOCK_INTERBSS,
    /** Enable/Disable reset */
    WMI_PDEV_PARAM_SET_DISABLE_RESET_CMDID,
    /** Enable/Disable/Set MSDU_TTL. */
    WMI_PDEV_PARAM_SET_MSDU_TTL_CMDID,
    /** Set global PPDU duration limit (usec). */
    WMI_PDEV_PARAM_SET_PPDU_DURATION_CMDID,
    /* set txbf sounding period of vap*/
    WMI_PDEV_PARAM_TXBF_SOUND_PERIOD_CMDID,
    /** Set promiscuous mode */
    WMI_PDEV_PARAM_SET_PROMISC_MODE_CMDID,
    /** Set burst mode */
    WMI_PDEV_PARAM_SET_BURST_MODE_CMDID,
    /** enable enhanced stats */
    WMI_PDEV_PARAM_EN_STATS,
    /** Set mu-grouping policy */
    WMI_PDEV_PARAM_MU_GROUP_POLICY,
    /** Channel Hopping Enable */
    WMI_PDEV_PARAM_NOISE_DETECTION,
    /** Set Channel Hopping NF threshold */
    WMI_PDEV_PARAM_NOISE_THRESHOLD,
    /** Set PAPRD policy */
    WMI_PDEV_PARAM_DPD_ENABLE,
    /** Enable/disable mcast/bcast echo, used by ProxySTA */
    WMI_PDEV_PARAM_SET_MCAST_BCAST_ECHO,

    /** ATF enabe/disabe strict schedule */
    WMI_PDEV_PARAM_ATF_STRICT_SCH,
    /** ATF set access category duration */
    WMI_PDEV_PARAM_ATF_SCHED_DURATION,
    /** Default antenna polarization */
    WMI_PDEV_PARAM_ANT_PLZN,
    /** Set mgmt retry limit */
    WMI_PDEV_PARAM_MGMT_RETRY_LIMIT,
    /** Set CCA sensitiviy level */
    WMI_PDEV_PARAM_SENSITIVITY_LEVEL,
    /** Set 2G positive and negative Tx power in 0.5dBm units */
    WMI_PDEV_PARAM_SIGNED_TXPOWER_2G,
    /** Set 5G positive and negative Tx power in 0.5dBm
     * units */
    WMI_PDEV_PARAM_SIGNED_TXPOWER_5G,
    /** Enable/disble AMSDU for tids */
    WMI_PDEV_PARAM_ENABLE_PER_TID_AMSDU,
    /** Enable/disable AMPDU for tids */
    WMI_PDEV_PARAM_ENABLE_PER_TID_AMPDU,
    /** Set CCA threshold */
    WMI_PDEV_PARAM_CCA_THRESHOLD,
    /** RTS Fixed rate setting */
    WMI_PDEV_PARAM_RTS_FIXED_RATE,
    /** specify how often to repeat calibration */
    WMI_PDEV_PARAM_CAL_PERIOD,
    /** Pdev reset */
    WMI_PDEV_PARAM_PDEV_RESET,
    /** wapi mbssid offset **/
    WMI_PDEV_PARAM_WAPI_MBSSID_OFFSET,
    /** ARP DEBUG source address*/
    WMI_PDEV_PARAM_ARP_SRCADDR,
    /** ARP DEBUG destination address*/
    WMI_PDEV_PARAM_ARP_DSTADDR,
    /** tx power reduction in dB units */
    WMI_PDEV_PARAM_TXPOWER_DECR_DB,
    /** Enable/disable rx batchmode */
    WMI_PDEV_PARAM_RX_BATCHMODE,
    /** Enable/disable packet aggr delay */
    WMI_PDEV_PARAM_PACKET_AGGR_DELAY,
    /** ATF enable/disable obss noise scheduling */
    WMI_PDEV_PARAM_ATF_OBSS_NOISE_SCH,
    /** ATF obss noise scaling factor */
    WMI_PDEV_PARAM_ATF_OBSS_NOISE_SCALING_FACTOR,
    /**
     * TX power reduction scaling exponent - final tx power is the
     * nominal tx power (A_MIN(reg_pow,ctl,etc..)) divided by
     * 2^(scale exponent).  For example:
     * If this scale exponent is  0, the power is unchanged (divided by 2^0)
     * If this factor is 1, the power is scaled down by 2^1, i.e. 3 dB
     * If this factor is 2, the power is scaled down by 2^2, i.e. 6 dB
     * If this factor is 3, the power is scaled down by 2^3, i.e. 9 dB
     */
    WMI_PDEV_PARAM_CUST_TXPOWER_SCALE,
    /** ATF enabe/disabe dynamically */
    WMI_PDEV_PARAM_ATF_DYNAMIC_ENABLE,
    /** ATF SSID Group Policy across groups */
    WMI_PDEV_PARAM_ATF_SSID_GROUP_POLICY,
    /** enable/disable BT coex.
     * This command is not version specific and will be used to
     * enable/disable the current running coex version.
     */
    WMI_PDEV_PARAM_ENABLE_BTCOEX,
    /**
     * Enable sending ATF peer stats to host periodically.
     *
     * Currently the periodicity is fixed and target
     * will send ATF peer stats to host every 1s.
     *
     * Current param values are -
     * WMI_ATF_PEER_STATS_DISABLED & WMI_ATF_PEER_STATS_ENABLED
     *
     * In future, this pdev param can be used to configure the
     * periodicity by passing it as the param value instead of
     * the above. The target should process it accordingly.
     *
     */
    WMI_PDEV_PARAM_ATF_PEER_STATS,
    /**
     * Set the user-specified antenna gain, but in 0.5 dB units.
     * This is a finer-granularity version of WMI_PDEV_PARAM_ANTENNA_GAIN.
     * E.g. to set a gain of 15.5 dB, a value of 31 could be provided as the
     * value accompanying the PDEV_PARAM_ANTENNA_GAIN_HALF_DB parameter type.
     */
    WMI_PDEV_PARAM_ANTENNA_GAIN_HALF_DB,
    /**
     * This will configure the TX chains per packet on the fly,
     * without having to reset the WIFI module unlike WMI_PDEV_PARAM_TX_CHAIN_MASK.
     * The target programs the tx chain mask specified in the TX_CHAIN_MASK
     * pdev param into registers, which requires a target MAC HW reset
     * (which causes all clients to be disconnected).
     * The target programs the tx chain mask specified in the SOFT_TX_CHAIN_MASK
     * pdev param into the tx PPDU descriptor of each transmission,
     * and thus does not require resetting the target's MAC HW or
     * disconnecting current clients.
     */
    WMI_PDEV_PARAM_SOFT_TX_CHAIN_MASK,
    /**
     * Configures the time out of ACK on Tx path. The value should be in the
     * range of 0x40 - 0xFF (microsecond units).
     * ACK time out below 0x40 microseconds will impact the normal WIFI
     * functionality
     */
    WMI_PDEV_PARAM_TX_ACK_TIMEOUT,
    /*
     * This command allows to enable/disable/configure RX indication mitigation
     * (RX batching) in FW.
     * The parameter value is comprised of the following bit-fields:
     *  Bits | Purpose / Value
     * -----------------------------------------------
     *    0  | 0 -> disable rx indication mitigation
     *       | 1 -> enable rx indication mitigation
     * -----------------------------------------------
     *  15:1 | unused/reserved (set to 0x0)
     * -----------------------------------------------
     * 31:16 | rx indication threshold at which to begin batching
     *       | This field specifies the number of rx indications that must
     *       | occur within a 2 millisecond period in order to begin
     *       | rx indication mitigation.
     *       | (This field only applies if rx indication mitigation is enabled.)
     */
    WMI_PDEV_PARAM_RX_INDICATION_MITIGATION,
    /**
     * The below command enables/disables the FW feature of dynamically
     * enabling / disabling SIFS bursting based on PER.  The dynamic
     * bursting enabling will disable SIFS bursting if there are excessive
     * tx retries within a short time frame, and will re-enable SIFS bursting
     * after a fixed time period.
     * The retry rate threshold for disabling SIFS bursting and the time
     * period over which SIFS bursting remains disabled are hard-coded
     * in the target FW.
     */
    WMI_PDEV_PARAM_DYNAMIC_AUTO_BURST_ENABLE,

    /*
     * Configures the Estimated Throughput Calculation indication (802.11mc) settings.
     * The accompanying A_UINT32 parameter, in units of seconds, specifies how often FW needs to send the ESP estimation indication to the host.
     * Value 0: Disable this feature
     * Non zero Value: Periodicity (seconds)
     */
    WMI_PDEV_PARAM_ESP_INDICATION_PERIOD,

    /*
     * Enable/Disable periodic peer CFR capture
     * WMI_PEER_CFR_CAPTURE_ENABLE - Enable per peer periodic CFR capture
     * WMI_PEER_CFR_CAPTURE_DISABLE - Disable per peer periodic CFR capture
     */
    WMI_PDEV_PARAM_PER_PEER_PERIODIC_CFR_ENABLE,

    /*
     * Set the base timer for the periodic CFR capture. By default this is 10ms.
     * The period ('periodicity' param in wmi_peer_cfr_capture_cmd) of
     * CFR measurment of other peers will be in multiples of this base timer.
     * The unit is in milliseconds.
     */
    WMI_PDEV_PARAM_PERIODIC_CFR_BASE_TIMER,

    /*
     * Once the periodic capture is enabled using
     * WMI_PDEV_PARAM_PER_PEER_PERIODIC_CFR_ENABLE, the timer starts running in
     * the target. This parameter will ensure that the timer stops if there are
     * no active peers in the capture list. Once the peers are added again to
     * the capture list, the timer will not start again. The timer has to be
     * started again using WMI_PDEV_PARAM_PER_PEER_PERIODIC_CFR_ENABLE.
     * Value 1: Enable this feature
     * Value 0: Disable this feature
     */
    WMI_PDEV_PARAM_ENABLE_OPTIMIZED_PERIODIC_CFR_TIMER,

} WMI_PDEV_PARAM;

enum wmi_pkt_type {
    WMI_PKT_TYPE_RAW = 0,
    WMI_PKT_TYPE_NATIVE_WIFI = 1,
    WMI_PKT_TYPE_ETHERNET = 2,
};
typedef struct {
    /** parameter id   */
    A_UINT32 param_id;
    /** parametr value */
    A_UINT32 param_value;
} wmi_pdev_set_param_cmd;

/* nrp action - Filter Neighbor Rx Packets  - add/remove filter */
enum {
    WMI_FILTER_NRP_ACTION_ADD        = 0x1,
    WMI_FILTER_NRP_ACTION_REMOVE     = 0x2,
    WMI_FILTER_NRP_ACTION_GET_LIST   = 0x3,
}; /* nrp - Neighbor Rx Packets */

/* nrp type - Filter Neighbor Rx Packets  - ap/client addr */
enum {
    WMI_FILTER_NRP_TYPE_AP_BSSID     = 0x1,
    WMI_FILTER_NRP_TYPE_STA_MACADDR  = 0x2,
};

/* nrp flag - Filter Neighbor Rx Packets
 * (capture flag, 2 & 3 not initially supported)
 */
enum {
    WMI_FILTER_NRP_CAPTURE_ONLY_RX_PACKETS      = 0x1,
    WMI_FILTER_NRP_CAPTURE_ONLY_TX_PACKETS      = 0x2,
    WMI_FILTER_NRP_CAPTURE_BOTH_TXRX_PACKETS    = 0x3,
};

typedef struct {
    A_UINT32 vdev_id;
    /* AP Bssid or Client Mac-addr */
    wmi_mac_addr addr;
    /* Add/Remove NRF Filter */
    A_UINT32 action; /* WMI_FILTER_NRP_ACTION enum */
    /* client/ap filter */
    A_UINT32 type; /* WMI_FILTER_NRP_TYPE enum */
    /* optional - tx/rx capture */
    A_UINT32 flag; /* WMI_FILTER_CAPTURE enum */
    /* BSSID index - index of the BSSID register */
    A_UINT32 bssid_idx;
} wmi_vdev_filter_nrp_config_cmd; /* Filter for Neighbor Rx Packets */

/* NAC RSSI action - add/remove filter */
enum {
    WMI_FILTER_NAC_RSSI_ACTION_ADD    = 0x1,
    WMI_FILTER_NAC_RSSI_ACTION_REMOVE = 0x2,
    WMI_FILTER_NAC_RSSI_ACTION_LIST   = 0x3,
}; /* NAC RSSI command */

typedef struct {
    A_UINT32 vdev_id;
    wmi_mac_addr bssid_addr;
    wmi_mac_addr client_addr;
    A_UINT32 chan_num;
    A_UINT32 action; /* WMI_FILTER_NAC_RSSI_ACTION */
} wmi_vdev_scan_nac_rssi_config_cmd;

typedef struct {
    /** parameter   */
    A_UINT32 param;
} wmi_pdev_get_tpc_config_cmd;

typedef struct {
    A_UINT32 reserved;
} wmi_pdev_get_tpc_table_cmd;

#define WMI_TPC_RATE_MAX            240
#define WMI_TPC_TX_NUM_CHAIN        4
#define WMI_TPC_BEAMFORMING         2
#define WMI_TPC_MAX_NUM_STREAMS     4

typedef enum {
    WMI_TPC_CONFIG_EVENT_FLAG_TABLE_CDD     = 0x1,
    WMI_TPC_CONFIG_EVENT_FLAG_TABLE_STBC    = 0x2,
    WMI_TPC_CONFIG_EVENT_FLAG_TABLE_TXBF    = 0x4,
} WMI_TPC_CONFIG_EVENT_FLAG;

typedef struct {
    A_UINT32 regDomain;
    A_UINT32 chanFreq;
    A_UINT32 phyMode;
    A_UINT32 twiceAntennaReduction;
    A_UINT32 twiceMaxRDPower;
    A_INT32  twiceAntennaGain;
    A_UINT32 powerLimit;
    A_UINT32 rateMax;
    A_UINT32 numTxChain;
    A_UINT32 ctl;
    A_UINT32 flags;
    A_INT8  maxRegAllowedPower[WMI_TPC_TX_NUM_CHAIN];
    A_INT8  maxRegAllowedPowerAGCDD[WMI_TPC_TX_NUM_CHAIN][WMI_TPC_TX_NUM_CHAIN];
    A_INT8  maxRegAllowedPowerAGSTBC[WMI_TPC_TX_NUM_CHAIN][WMI_TPC_TX_NUM_CHAIN];
    A_INT8  maxRegAllowedPowerAGTXBF[WMI_TPC_TX_NUM_CHAIN][WMI_TPC_TX_NUM_CHAIN];
    A_UINT8 ratesArray[WMI_TPC_RATE_MAX];
} wmi_pdev_tpc_config_event;

typedef struct {
    A_UINT32 regDomain;
    A_UINT32 chanFreq; /* units = MHz */
    A_UINT32 phyMode;  /* refer to WLAN_PHY_MODE enum */
    A_UINT32 twiceAntennaReduction; /* units = 0.5 dB */
    A_UINT32 twiceMaxRDPower;       /* units = 0.5 dBm */
    A_INT32  twiceAntennaGain;      /* units = 0.5 dB */
    A_UINT32 txPowerLimit;          /* units = dBm */
    A_UINT32 rateMax; /* refer to WMI_TPC_RATES enum */
    A_UINT32 numTxChain;
    A_UINT32 ctl; /* refer to ATH_CTLS enum (from systemtools mEeprom.h) */
    A_UINT32 flags; /* refer to WMI_TPC_CONFIG_EVENT_FLAG enum */
    A_INT8  maxRegAllowedPower[WMI_TPC_TX_NUM_CHAIN];
    A_INT8  maxRegAllowedPowerAGCDD[WMI_TPC_TX_NUM_CHAIN][WMI_TPC_MAX_NUM_STREAMS];
    A_INT8  maxRegAllowedPowerAGSTBC[WMI_TPC_TX_NUM_CHAIN][WMI_TPC_MAX_NUM_STREAMS];
    A_INT8  maxRegAllowedPowerAGTXBF[WMI_TPC_TX_NUM_CHAIN][WMI_TPC_MAX_NUM_STREAMS];
    A_UINT8 ratesArray[WMI_TPC_RATE_MAX]; /* indexed by WMI_TPC_RATES enums */
    A_UINT8 ctlPowerTable[WMI_TPC_BEAMFORMING][WMI_TPC_TX_NUM_CHAIN][WMI_TPC_MAX_NUM_STREAMS];
} wmi_pdev_tpc_table_event;

/* Match rate index with rate table so that it can be used for TPC */
typedef enum {
    /*0    11 Mb */     _RATE_11 = 0,
#define _RATE_11S         _RATE_11
#define _RATE_11L         _RATE_11
    /*1   5.5 Mb */     _RATE_5_5,
#define _RATE_5_5S        _RATE_5_5
#define _RATE_5_5L        _RATE_5_5
    /*2     2 Mb */     _RATE_2,
#define _RATE_2S          _RATE_2
#define _RATE_2L          _RATE_2
    /*3     1 Mb */     _RATE_1,
#define _RATE_1L          _RATE_1
    /*4    48 Mb */     _RATE_48,
    /*5    24 Mb */     _RATE_24,
    /*6    12 Mb */     _RATE_12,
    /*7     6 Mb */     _RATE_6,
    /*8    54 Mb */     _RATE_54,
    /*9    36 Mb */     _RATE_36,
    /*10   18 Mb */     _RATE_18,
    /*11    9 Mb */     _RATE_9,

/* 11n HT rates */
    /*12  6.5 Mb */     _RATE_HT20_0,
    /*13   13 Mb */     _RATE_HT20_1,
    /*14 19.5 Mb */     _RATE_HT20_2,
    /*15   26 Mb */     _RATE_HT20_3,
    /*16   39 Mb */     _RATE_HT20_4,
    /*17   52 Mb */     _RATE_HT20_5,
    /*18 58.5 Mb */     _RATE_HT20_6,
    /*19   65 Mb */     _RATE_HT20_7,
    /*20   13 Mb */     _RATE_HT20_8,
    /*21   26 Mb */     _RATE_HT20_9,
    /*22   39 Mb */     _RATE_HT20_10,
    /*23   52 Mb */     _RATE_HT20_11,
    /*24   78 Mb */     _RATE_HT20_12,
    /*25  104 Mb */     _RATE_HT20_13,
    /*26  117 Mb */     _RATE_HT20_14,
    /*27  130 Mb */     _RATE_HT20_15,
    /*28   19.5 Mb*/    _RATE_HT20_16,
    /*29   39 Mb */     _RATE_HT20_17,
    /*30   58.5 Mb*/    _RATE_HT20_18,
    /*31   78 Mb */     _RATE_HT20_19,
    /*32   117 Mb */    _RATE_HT20_20,
    /*33  156 Mb */     _RATE_HT20_21,
    /*34  175.5 Mb*/    _RATE_HT20_22,
    /*35  195 Mb */     _RATE_HT20_23,
    /*36   19.5 Mb*/    _RATE_HT20_24,
    /*37   39 Mb */     _RATE_HT20_25,
    /*38   58.5 Mb*/    _RATE_HT20_26,
    /*39   78 Mb */     _RATE_HT20_27,
    /*40   117 Mb */    _RATE_HT20_28,
    /*41  156 Mb */     _RATE_HT20_29,
    /*42  175.5 Mb*/    _RATE_HT20_30,
    /*43  195 Mb */     _RATE_HT20_31,

    /*44 13.5 Mb */     _RATE_HT40_0,
    /*45 27.0 Mb */     _RATE_HT40_1,
    /*46 40.5 Mb */     _RATE_HT40_2,
    /*47   54 Mb */     _RATE_HT40_3,
    /*48   81 Mb */     _RATE_HT40_4,
    /*49  108 Mb */     _RATE_HT40_5,
    /*50 121.5Mb */     _RATE_HT40_6,
    /*51  135 Mb */     _RATE_HT40_7,
    /*52   27 Mb */     _RATE_HT40_8,
    /*53   54 Mb */     _RATE_HT40_9,
    /*54   81 Mb */     _RATE_HT40_10,
    /*55  108 Mb */     _RATE_HT40_11,
    /*56  162 Mb */     _RATE_HT40_12,
    /*57  216 Mb */     _RATE_HT40_13,
    /*58  243 Mb */     _RATE_HT40_14,
    /*59  270 Mb */     _RATE_HT40_15,
    /*60  40.5 Mb */    _RATE_HT40_16,
    /*61   54 Mb */     _RATE_HT40_17,
    /*62   81 Mb */     _RATE_HT40_18,
    /*63  108 Mb */     _RATE_HT40_19,
    /*64  162 Mb */     _RATE_HT40_20,
    /*65  216 Mb */     _RATE_HT40_21,
    /*66  243 Mb */     _RATE_HT40_22,
    /*67  270 Mb */     _RATE_HT40_23,
    /*68  40.5 Mb */    _RATE_HT40_24,
    /*69   54 Mb */     _RATE_HT40_25,
    /*70   81 Mb */     _RATE_HT40_26,
    /*71  108 Mb */     _RATE_HT40_27,
    /*72  162 Mb */     _RATE_HT40_28,
    /*73  216 Mb */     _RATE_HT40_29,
    /*74  243 Mb */     _RATE_HT40_30,
    /*75  270 Mb */     _RATE_HT40_31,

/* VHT MCS0-9 NSS 1 20 MHz */
    /*76 6.5 Mb */      _RATE_VHT20_MCS0_NSS1,
    /*77   13 Mb */     _RATE_VHT20_MCS1_NSS1,
    /*78 19.5 Mb */     _RATE_VHT20_MCS2_NSS1,
    /*79   26 Mb */     _RATE_VHT20_MCS3_NSS1,
    /*80   39 Mb */     _RATE_VHT20_MCS4_NSS1,
    /*81   52 Mb */     _RATE_VHT20_MCS5_NSS1,
    /*82 58.5 Mb */     _RATE_VHT20_MCS6_NSS1,
    /*83   65 Mb */     _RATE_VHT20_MCS7_NSS1,
    /*84   78 Mb */     _RATE_VHT20_MCS8_NSS1,
    /*85   MCS9 */      _RATE_VHT20_MCS9_NSS1,

/* VHT MCS0-9 NSS 2 20 MHz */
    /*86  13 Mb */     _RATE_VHT20_MCS0_NSS2,
    /*87  26 Mb */     _RATE_VHT20_MCS1_NSS2,
    /*88  39 Mb */     _RATE_VHT20_MCS2_NSS2,
    /*89  52 Mb */     _RATE_VHT20_MCS3_NSS2,
    /*90  78 Mb */     _RATE_VHT20_MCS4_NSS2,
    /*91  104 Mb */    _RATE_VHT20_MCS5_NSS2,
    /*92  117 Mb */    _RATE_VHT20_MCS6_NSS2,
    /*93  130 Mb */    _RATE_VHT20_MCS7_NSS2,
    /*94  156Mb */     _RATE_VHT20_MCS8_NSS2,
    /*95   MCS9 */     _RATE_VHT20_MCS9_NSS2,

 /* VHT MCS0-9 NSS 3 20 MHz */
    /*96  19.5 Mb */   _RATE_VHT20_MCS0_NSS3,
    /*97   39 Mb */    _RATE_VHT20_MCS1_NSS3,
    /*98 58.5 Mb */    _RATE_VHT20_MCS2_NSS3,
    /*99   78 Mb */    _RATE_VHT20_MCS3_NSS3,
    /*100   117 Mb */   _RATE_VHT20_MCS4_NSS3,
    /*101   156 Mb */   _RATE_VHT20_MCS5_NSS3,
    /*102 175.5 Mb */   _RATE_VHT20_MCS6_NSS3,
    /*103   195 Mb */   _RATE_VHT20_MCS7_NSS3,
    /*104   234 Mb */   _RATE_VHT20_MCS8_NSS3,
    /*105  260 */       _RATE_VHT20_MCS9_NSS3,

 /* VHT MCS0-9 NSS 4 20 MHz */
    /*106  26 Mb */     _RATE_VHT20_MCS0_NSS4,
    /*107   52 Mb */    _RATE_VHT20_MCS1_NSS4,
    /*108 78 Mb */      _RATE_VHT20_MCS2_NSS4,
    /*109   104 Mb */   _RATE_VHT20_MCS3_NSS4,
    /*110   156 Mb */   _RATE_VHT20_MCS4_NSS4,
    /*111   208 Mb */   _RATE_VHT20_MCS5_NSS4,
    /*112 234Mb */      _RATE_VHT20_MCS6_NSS4,
    /*113   260 Mb */   _RATE_VHT20_MCS7_NSS4,
    /*114   312 Mb */   _RATE_VHT20_MCS8_NSS4,
    /*115   MCS9 */     _RATE_VHT20_MCS9_NSS4,

 /* VHT MCS0-9 NSS 1 40 MHz */
    /*116  13.5Mb */    _RATE_VHT40_MCS0_NSS1,
    /*117  27Mb   */    _RATE_VHT40_MCS1_NSS1,
    /*118  40.5Mb */    _RATE_VHT40_MCS2_NSS1,
    /*119  54Mb   */    _RATE_VHT40_MCS3_NSS1,
    /*120  81Mb   */    _RATE_VHT40_MCS4_NSS1,
    /*121  108Mb  */    _RATE_VHT40_MCS5_NSS1,
    /*122  121.5Mb */   _RATE_VHT40_MCS6_NSS1,
    /*123  135Mb  */    _RATE_VHT40_MCS7_NSS1,
    /*124  162Mb  */    _RATE_VHT40_MCS8_NSS1,
    /*125  180Mb  */    _RATE_VHT40_MCS9_NSS1,

 /* VHT MCS0-9 NSS 2 40 MHz */
    /*126 27Mb  */     _RATE_VHT40_MCS0_NSS2,
    /*127 54Mb  */     _RATE_VHT40_MCS1_NSS2,
    /*128 81Mb  */     _RATE_VHT40_MCS2_NSS2,
    /*129 108Mb */     _RATE_VHT40_MCS3_NSS2,
    /*130 162Mb */     _RATE_VHT40_MCS4_NSS2,
    /*131 216Mb */     _RATE_VHT40_MCS5_NSS2,
    /*132 243Mb */     _RATE_VHT40_MCS6_NSS2,
    /*133 270Mb */     _RATE_VHT40_MCS7_NSS2,
    /*134 324Mb */     _RATE_VHT40_MCS8_NSS2,
    /*135 360Mb */     _RATE_VHT40_MCS9_NSS2,

 /* VHT MCS0-9 NSS 3 40 MHz */
    /*136 40.5Mb */    _RATE_VHT40_MCS0_NSS3,
    /*137 81Mb   */    _RATE_VHT40_MCS1_NSS3,
    /*138 121.5Mb */   _RATE_VHT40_MCS2_NSS3,
    /*139 162Mb  */    _RATE_VHT40_MCS3_NSS3,
    /*140 243Mb  */    _RATE_VHT40_MCS4_NSS3,
    /*141 324Mb  */    _RATE_VHT40_MCS5_NSS3,
    /*142 364.5Mb */   _RATE_VHT40_MCS6_NSS3,
    /*143 405Mb  */    _RATE_VHT40_MCS7_NSS3,
    /*144 486Mb  */    _RATE_VHT40_MCS8_NSS3,
    /*145 540Mb  */    _RATE_VHT40_MCS9_NSS3,

 /* VHT MCS0-9 NSS 4 40 MHz */
    /*146 54Mb   */    _RATE_VHT40_MCS0_NSS4,
    /*147 108Mb  */    _RATE_VHT40_MCS1_NSS4,
    /*148 162Mb  */    _RATE_VHT40_MCS2_NSS4,
    /*149 216Mb  */    _RATE_VHT40_MCS3_NSS4,
    /*150 324Mb  */    _RATE_VHT40_MCS4_NSS4,
    /*151 432Mb  */    _RATE_VHT40_MCS5_NSS4,
    /*152 486Mb  */    _RATE_VHT40_MCS6_NSS4,
    /*153 540Mb  */    _RATE_VHT40_MCS7_NSS4,
    /*154 648Mb  */    _RATE_VHT40_MCS8_NSS4,
    /*155 720Mb  */    _RATE_VHT40_MCS9_NSS4,

 /* VHT MCS0-9 NSS 1 80 MHz */
    /*156 29.3Mb */    _RATE_VHT80_MCS0_NSS1,
    /*157 58.5Mb */    _RATE_VHT80_MCS1_NSS1,
    /*158 87.8Mb */    _RATE_VHT80_MCS2_NSS1,
    /*159 117Mb  */    _RATE_VHT80_MCS3_NSS1,
    /*160 175.5Mb */   _RATE_VHT80_MCS4_NSS1,
    /*161 234Mb  */    _RATE_VHT80_MCS5_NSS1,
    /*162 263.3Mb */   _RATE_VHT80_MCS6_NSS1,
    /*163 292.5Mb */   _RATE_VHT80_MCS7_NSS1,
    /*164 351Mb   */   _RATE_VHT80_MCS8_NSS1,
    /*165 390Mb  */    _RATE_VHT80_MCS9_NSS1,

 /* VHT MCS0-9 NSS 2 80 MHz */
    /*166 58.5Mb  */   _RATE_VHT80_MCS0_NSS2,
    /*167 117Mb   */   _RATE_VHT80_MCS1_NSS2,
    /*168 175.5Mb */   _RATE_VHT80_MCS2_NSS2,
    /*169 234Mb   */   _RATE_VHT80_MCS3_NSS2,
    /*170 351Mb   */   _RATE_VHT80_MCS4_NSS2,
    /*171 468Mb   */   _RATE_VHT80_MCS5_NSS2,
    /*172 526.5Mb */   _RATE_VHT80_MCS6_NSS2,
    /*173 585Mb   */   _RATE_VHT80_MCS7_NSS2,
    /*174 702Mb   */   _RATE_VHT80_MCS8_NSS2,
    /*175 780Mb   */   _RATE_VHT80_MCS9_NSS2,

 /* VHT MCS0-9 NSS 3 80 MHz */
    /*176 87.8Mb  */   _RATE_VHT80_MCS0_NSS3,
    /*177 175.5Mb */   _RATE_VHT80_MCS1_NSS3,
    /*178 263.3Mb */   _RATE_VHT80_MCS2_NSS3,
    /*179 351Mb   */   _RATE_VHT80_MCS3_NSS3,
    /*180 526.5Mb */   _RATE_VHT80_MCS4_NSS3,
    /*181 702Mb   */   _RATE_VHT80_MCS5_NSS3,
    /*182 MCS6 */      _RATE_VHT80_MCS6_NSS3,
    /*183 877.5Mb */   _RATE_VHT80_MCS7_NSS3,
    /*184 1053Mb  */   _RATE_VHT80_MCS8_NSS3,
    /*185 1170Mb  */   _RATE_VHT80_MCS9_NSS3,

 /* VHT MCS0-9 NSS 4 80 MHz */
    /*186 117Mb  */    _RATE_VHT80_MCS0_NSS4,
    /*187 234Mb  */    _RATE_VHT80_MCS1_NSS4,
    /*188 351Mb  */    _RATE_VHT80_MCS2_NSS4,
    /*189 468Mb  */    _RATE_VHT80_MCS3_NSS4,
    /*190 702Mb  */    _RATE_VHT80_MCS4_NSS4,
    /*191 936Mb  */    _RATE_VHT80_MCS5_NSS4,
    /*192 1053Mb */    _RATE_VHT80_MCS6_NSS4,
    /*193 1170Mb */    _RATE_VHT80_MCS7_NSS4,
    /*194 1404Mb */    _RATE_VHT80_MCS8_NSS4,
    /*195 1560Mb */    _RATE_VHT80_MCS9_NSS4,

/* VHT MCS0-9 NSS 1 160 MHz - used for the primary 80 segment */
    /*196 58.5Mb  */   _RATE_VHT160_MCS0_NSS1,
    /*197 117Mb   */   _RATE_VHT160_MCS1_NSS1,
    /*198 175.5Mb */   _RATE_VHT160_MCS2_NSS1,
    /*199 234Mb   */   _RATE_VHT160_MCS3_NSS1,
    /*200 351Mb   */   _RATE_VHT160_MCS4_NSS1,
    /*201 468Mb   */   _RATE_VHT160_MCS5_NSS1,
    /*202 526.5Mb */   _RATE_VHT160_MCS6_NSS1,
    /*203 585Mb   */   _RATE_VHT160_MCS7_NSS1,
    /*204 702Mb   */   _RATE_VHT160_MCS8_NSS1,
    /*205 780Mb   */   _RATE_VHT160_MCS9_NSS1,

 /* VHT MCS0-9 NSS 2 160 MHz */
    /*206 117Mb   */   _RATE_VHT160_MCS0_NSS2,
    /*207 234Mb   */   _RATE_VHT160_MCS1_NSS2,
    /*208 351Mb   */   _RATE_VHT160_MCS2_NSS2,
    /*209 468Mb   */   _RATE_VHT160_MCS3_NSS2,
    /*210 702Mb   */   _RATE_VHT160_MCS4_NSS2,
    /*211 936Mb   */   _RATE_VHT160_MCS5_NSS2,
    /*212 1053Mb  */   _RATE_VHT160_MCS6_NSS2,
    /*213 1170Mb  */   _RATE_VHT160_MCS7_NSS2,
    /*214 1404Mb  */   _RATE_VHT160_MCS8_NSS2,
    /*215 1560Mb  */   _RATE_VHT160_MCS9_NSS2,

/* VHT MCS0-9 NSS 1 160 MHz - used for the secondary 80 segment */
    /*216 58.5Mb  */   _RATE_VHT160_SECONDARY_MCS0_NSS1,
    /*217 117Mb   */   _RATE_VHT160_SECONDARY_MCS1_NSS1,
    /*218 175.5Mb */   _RATE_VHT160_SECONDARY_MCS2_NSS1,
    /*219 234Mb   */   _RATE_VHT160_SECONDARY_MCS3_NSS1,
    /*220 351Mb   */   _RATE_VHT160_SECONDARY_MCS4_NSS1,
    /*221 468Mb   */   _RATE_VHT160_SECONDARY_MCS5_NSS1,
    /*222 526.5Mb */   _RATE_VHT160_SECONDARY_MCS6_NSS1,
    /*223 585Mb   */   _RATE_VHT160_SECONDARY_MCS7_NSS1,
    /*224 702Mb   */   _RATE_VHT160_SECONDARY_MCS8_NSS1,
    /*225 780Mb   */   _RATE_VHT160_SECONDARY_MCS9_NSS1,

 /* VHT MCS0-9 NSS 2 160 MHz */
    /*226 117Mb   */   _RATE_VHT160_SECONDARY_MCS0_NSS2,
    /*227 234Mb   */   _RATE_VHT160_SECONDARY_MCS1_NSS2,
    /*228 351Mb   */   _RATE_VHT160_SECONDARY_MCS2_NSS2,
    /*229 468Mb   */   _RATE_VHT160_SECONDARY_MCS3_NSS2,
    /*230 702Mb   */   _RATE_VHT160_SECONDARY_MCS4_NSS2,
    /*231 936Mb   */   _RATE_VHT160_SECONDARY_MCS5_NSS2,
    /*232 1053Mb  */   _RATE_VHT160_SECONDARY_MCS6_NSS2,
    /*233 1170Mb  */   _RATE_VHT160_SECONDARY_MCS7_NSS2,
    /*234 1404Mb  */   _RATE_VHT160_SECONDARY_MCS8_NSS2,
    /*235 1560Mb  */   _RATE_VHT160_SECONDARY_MCS9_NSS2,

/* Todo Extend support for 80+80/160 MHz in future */
     _RATE_DUP_CCK,
     _RATE_DUP_OFDM,
     _RATE_EXT_CCK,
     _RATE_EXT_OFDM,
     _RATE_XR,

     _RATE_MAX,

} WMI_TPC_RATES;

enum {
    WMI_BUFFER_TYPE_RATEPWR_TABLE,
    WMI_BUFFER_TYPE_CTL_TABLE,
};

typedef struct {
    A_UINT32 buf_type;
    A_UINT32 frag_id;
    A_UINT32 more_frag;
    A_UINT32 buf_len;
    A_UINT32 buf_info[1];
} wmi_pdev_generic_buffer_event;

typedef struct {
    /**
     * rx_filter shows the current contents of the RXPCU_RX_FILTER register.
     * Refer to the HW register documentation for the interpretation of each
     * bit within rx_filter.
     */
    A_UINT32 rx_filter;
} wmi_pdev_get_rxfilter_entry_event;

typedef struct {
    A_UINT32 mimogain_info;
    /******************************************************************************
     *Bit 7:0 len of array gain table
     *Bit 8   bypass multi chain gain or not
     ******************************************************************************/
    /** array gain table(s) (len adjusted to  number of words) */
    A_UINT32 arraygain_tbl[1];
} wmi_pdev_set_mimogain_table_cmd;

#define WMI_MIMOGAIN_ARRAY_GAIN_LEN_S 0
#define WMI_MIMOGAIN_ARRAY_GAIN_LEN (0xff << WMI_MIMOGAIN_ARRAY_GAIN_LEN_S)
#define WMI_MIMOGAIN_ARRAY_GAIN_LEN_GET(x) WMI_F_MS(x,WMI_MIMOGAIN_ARRAY_GAIN_LEN)
#define WMI_MIMOGAIN_ARRAY_GAIN_LEN_SET(x,z) WMI_F_RMW(x,z,WMI_MIMOGAIN_ARRAY_GAIN_LEN)

#define WMI_MIMOGAIN_MULTI_CHAIN_BYPASS_S 8
#define WMI_MIMOGAIN_MULTI_CHAIN_BYPASS (0x1 << WMI_MIMOGAIN_MULTI_CHAIN_BYPASS_S)
#define WMI_MIMOGAIN_MULTI_CHAIN_BYPASS_GET(x) WMI_F_MS(x,WMI_MIMOGAIN_MULTI_CHAIN_BYPASS)
#define WMI_MIMOGAIN_MULTI_CHAIN_BYPASS_SET(x,z) WMI_F_RMW(x,z,WMI_MIMOGAIN_MULTI_CHAIN_BYPASS)

typedef struct {
    /** len of CTL info */
    A_UINT32 ctl_len;
    /** ctl array (len adjusted to  number of words) */
    A_UINT32 ctl_info[1];
} wmi_pdev_set_ctl_table_cmd;

enum {
    RATEPWR_TABLE_OPS_SET,
    RATEPWR_TABLE_OPS_GET,
};

typedef struct {
    /** operation */
    A_UINT32 op;
    /** len of ratepwr table */
    A_UINT32 ratepwr_len;
    /** rate power table (len adjusted to number of words) */
    A_UINT32 ratepwr_tbl[1];
} wmi_pdev_ratepwr_table_cmd;

enum {
    RATEPWR_CHAINMSK_TABLE_OPS_DIS = 0,
    RATEPWR_CHAINMSK_TABLE_OPS_EN = 1,
};

typedef struct {
    /* operation: 0/1 - disable/enable this settings in FW */
    A_UINT32 op;

    /* 0 - CCK/OFDM
     * 1 - HT20/40
     * 2 - VHT rates */
    A_UINT32 pream_type;

    /* CCK/OFDM - 12
     * HT20/40  - 48
     * VHT rates - 90 */
    A_UINT32 rate_len;
    /** rate power table (len adjusted to number of words) */
    /** rate power and chain mask table
     * 15-12 : unused
     * 11-4 : rate power
     * 3-0  : Chainmask*/
    A_UINT32 ratepwr_chaintbl[1];
} wmi_pdev_ratepwr_chainmsk_tbl_cmd;

/*
 * Transmit power scale factor.
 *
 */
typedef enum {
    WMI_TP_SCALE_MAX    = 0,        /* no scaling (default) */
    WMI_TP_SCALE_50     = 1,        /* 50% of max (-3 dBm) */
    WMI_TP_SCALE_25     = 2,        /* 25% of max (-6 dBm) */
    WMI_TP_SCALE_12     = 3,        /* 12% of max (-9 dBm) */
    WMI_TP_SCALE_MIN    = 4,        /* min, but still on   */
    WMI_TP_SCALE_SIZE   = 5,        /* max num of enum     */
} WMI_TP_SCALE;

typedef struct {
    /* channel (only frequency and mode info are used) */
    wmi_channel chan;
} wmi_set_channel_cmd;

typedef struct {
   /** number of channels */
   A_UINT32 num_chan;
   /** array of channels */
   wmi_channel  channel_list[1];
}  wmi_pdev_chanlist_update_event;

#define WMI_MAX_DEBUG_MESG (sizeof(A_UINT32) * 32)
typedef struct {
    struct dbglog_config_msg_s config;
}WMI_DBGLOG_CFG_CMD;

typedef struct {
   /** message buffer, NULL terminated */
   char bufp[WMI_MAX_DEBUG_MESG];
} wmi_debug_mesg_event;

enum {
    /** IBSS station */
    VDEV_TYPE_IBSS  = 0,
    /** infra STA */
    VDEV_TYPE_STA   = 1,
    /** infra AP */
    VDEV_TYPE_AP    = 2,
    /** Monitor */
    VDEV_TYPE_MONITOR =3,
};

enum {
    /** P2P device */
    VDEV_SUBTYPE_P2PDEV=0,
    /** P2P client */
    VDEV_SUBTYPE_P2PCLI,
    /** P2P GO */
    VDEV_SUBTYPE_P2PGO,
    /** BT3.0 HS */
    VDEV_SUBTYPE_BT,
};

typedef struct {
    /** idnore power , only use flags , mode and freq */
   wmi_channel  chan;
}    wmi_pdev_set_channel_cmd;

typedef enum {
    WMI_PKTLOG_EVENT_RX        = 0x1,
    WMI_PKTLOG_EVENT_TX        = 0x2,
    WMI_PKTLOG_EVENT_RCF       = 0x4, /* Rate Control Find */
    WMI_PKTLOG_EVENT_RCU       = 0x8, /* Rate Control Update */
    WMI_PKTLOG_EVENT_DBG_PRINT = 0x10, /* DEBUG prints */
    WMI_PKTLOG_EVENT_SMART_ANTENNA = 0x20, /* To support Smart Antenna */
    WMI_PKTLOG_EVENT_PEER_STATS = 0x40, /* To support per peer TX stats */
    /* To preserve the compatibility between host and FW */
    WMI_PKTLOG_EVENT_RESERVED = 0x80,
    /* sends ISR status info of all TX packets and also the complete payload
     * (including 802.11 header) of local and self-generated frames */
    WMI_PKTLOG_EVENT_TX_DATA_CAPTURE = 0x100,
} WMI_PKTLOG_EVENT;

typedef PREPACK struct {
    WMI_PKTLOG_EVENT evlist;
} POSTPACK wmi_pdev_pktlog_enable_cmd;

/** Customize the DSCP (bit) to TID (0-7) mapping for QOS */
#define WMI_DSCP_MAP_MAX    (64)
    /*
     * @brief dscp_tid_map_cmdid - command to send the dscp to tid map to the target
     * @details
     * Create an API for sending the custom DSCP-to-TID map to the target
     * If this is a request from the user space or from above the UMAC
     * then the best place to implement this is in the umac_if_offload of the OL path.
     * Provide a place holder for this API in the ieee80211com (ic).
     *
     * This API will be a function pointer in the ieee80211com (ic). Any user space calls for manually setting the DSCP-to-TID mapping
     * in the target should be directed to the function pointer in the ic.
     *
     * Implementation details of the API to send the map to the target are as described-
     *
     * 1. The function will have 2 arguments- struct ieee80211com, DSCP-to-TID map.
     *    DSCP-to-TID map is a one dimensional u_int32_t array of length 64 to accomodate
     *    64 TID values for 2^6 (64) DSCP ids.
     *    Example:
     *      A_UINT32 dscp_tid_map[WMI_DSCP_MAP_MAX] = {
	 *									0, 0, 0, 0, 0, 0, 0, 0,
	 *									1, 1, 1, 1, 1, 1, 1, 1,
	 *									2, 2, 2, 2, 2, 2, 2, 2,
	 *									3, 3, 3, 3, 3, 3, 3, 3,
	 *									4, 4, 4, 4, 4, 4, 4, 4,
	 *									5, 5, 5, 5, 5, 5, 5, 5,
	 *									6, 6, 6, 6, 6, 6, 6, 6,
	 *									7, 7, 7, 7, 7, 7, 7, 7,
	 *								  };
     *
     * 2. Request for the WMI buffer of size equal to the size of the DSCP-to-TID map.
     *
     * 3. Copy the DSCP-to-TID map into the WMI buffer.
     *
     * 4. Invoke the wmi_unified_cmd_send to send the cmd buffer to the target with the
     *    WMI_PDEV_SET_DSCP_TID_MAP_CMDID. Arguments to the wmi send cmd API
     *    (wmi_unified_send_cmd) are wmi handle, cmd buffer, length of the cmd buffer and
     *    the WMI_PDEV_SET_DSCP_TID_MAP_CMDID id.
     */
typedef struct {
    /** map indicating DSCP to TID conversion */
    A_UINT32 dscp_to_tid_map[WMI_DSCP_MAP_MAX];
} wmi_pdev_set_dscp_tid_map_cmd;

typedef struct {
    A_UINT32 vdev_id;
    /** map indicating DSCP to TID conversion */
    A_UINT32 dscp_to_tid_map[WMI_DSCP_MAP_MAX];
    A_UINT32 enable_override;
} wmi_vdev_set_dscp_tid_map_cmd;

/** Fixed rate (rate-code) for broadcast/ multicast data frames */
/* @brief bcast_mcast_data_rate - set the rates for the bcast/ mcast frames
 * @details
 * Create an API for setting the custom rate for the MCAST and BCAST frames
 * in the target. If this is a request from the user space or from above the UMAC
 * then the best place to implement this is in the umac_if_offload of the OL path.
 * Provide a place holder for this API in the ieee80211com (ic).
 *
 * Implementation details of the API to set custom rates for MCAST and BCAST in
 * the target are as described-
 *
 * 1. The function will have 3 arguments-
 *    vap structure,
 *    MCAST/ BCAST identifier code,
 *    8 bit rate code
 *
 * The rate-code is a 1-byte field in which:for given rate, nss and preamble
 * b'7-b-6 indicate the preamble (0 OFDM, 1 CCK, 2, HT, 3 VHT)
 * b'5-b'4 indicate the NSS (0 - 1x1, 1 - 2x2, 2 - 3x3)
 * b'3-b'0 indicate the rate, which is indicated as follows:
 *          OFDM :     0: OFDM 48 Mbps
 *                     1: OFDM 24 Mbps
 *                     2: OFDM 12 Mbps
 *                     3: OFDM 6 Mbps
 *                     4: OFDM 54 Mbps
 *                     5: OFDM 36 Mbps
 *                     6: OFDM 18 Mbps
 *                     7: OFDM 9 Mbps
 *         CCK (pream == 1)
 *                     0: CCK 11 Mbps Long
 *                     1: CCK 5.5 Mbps Long
 *                     2: CCK 2 Mbps Long
 *                     3: CCK 1 Mbps Long
 *                     4: CCK 11 Mbps Short
 *                     5: CCK 5.5 Mbps Short
 *                     6: CCK 2 Mbps Short
 *         HT/VHT (pream == 2/3)
 *                     0..7: MCS0..MCS7 (HT)
 *                     0..9: MCS0..MCS9 (VHT)
 *
 * 2. Invoke the wmi_unified_vdev_set_param_send to send the rate value
 *    to the target.
 *    Arguments to the API are-
 *    wmi handle,
 *    VAP interface id (av_if_id) defined in ol_ath_vap_net80211,
 *    WMI_VDEV_PARAM_BCAST_DATA_RATE/ WMI_VDEV_PARAM_MCAST_DATA_RATE,
 *    rate value.
 */
typedef enum {
    WMI_SET_MCAST_RATE,
    WMI_SET_BCAST_RATE
} MCAST_BCAST_RATE_ID;

typedef struct {
    MCAST_BCAST_RATE_ID rate_id;
    A_UINT32 rate;
} mcast_bcast_rate;

typedef struct {
    A_UINT32 cwmin;
    A_UINT32 cwmax;
    A_UINT32 aifs;
    A_UINT32 txoplimit;
    A_UINT32 acm;
    A_UINT32 no_ack;
} wmi_wmm_params;

typedef struct {
    wmi_wmm_params wmm_params_ac_be;
    wmi_wmm_params wmm_params_ac_bk;
    wmi_wmm_params wmm_params_ac_vi;
    wmi_wmm_params wmm_params_ac_vo;
} wmi_pdev_set_wmm_params_cmd;

/* Bitmap of the stats id */
typedef enum {
    WMI_REQUEST_PEER_STAT  = 0x01,
    WMI_REQUEST_AP_STAT    = 0x02,
    WMI_REQUEST_INST_STAT  = 0x04,
    WMI_REQUEST_PEER_EXTD_STAT =  0x08,
    WMI_REQUEST_VDEV_EXTD_STAT =  0x10,
    WMI_REQUEST_PDEV_EXT2_STAT =  0x20,
    WMI_REQUEST_NAC_RSSI_STAT =  0x40,
} wmi_stats_id;

/*
 * cfg_retry_count is set to max number of times the AP should try sending
 * QoS Null frames to the STA for measuring the instantaneous RSSI
 *
 * retry_count is used to maintain the number of times the AP has tried sending
 * QoS Null frames to the STA for measuring the instantaneous RSSI
 */
typedef struct {
    A_UINT16 cfg_retry_count;
    A_UINT16 retry_count;
} wlan_inst_rssi_args;

typedef struct {
    wmi_stats_id stats_id;
    /*
     * Space to add parameters like
     * peer mac addr
     */

    /* vdev id */
    A_UINT32 vdev_id;
    /* peer MAC address */
    wmi_mac_addr peer_macaddr;

    /* Instantaneous RSSI arguments */
    wlan_inst_rssi_args inst_rssi_args;
} wmi_request_stats_cmd;

#define WMI_INST_STATS_INVALID_RSSI 0

typedef struct {
    A_UINT32 iRSSI;
    /* peer MAC address */
    wmi_mac_addr peer_macaddr;
} wmi_inst_stats_resp;

/** Suspend option */
enum {
    WMI_PDEV_SUSPEND, /* suspend */
    WMI_PDEV_SUSPEND_AND_DISABLE_INTR, /* suspend and disable all interrupts */
};
typedef struct {
    /* suspend option sent to target */
    A_UINT32 suspend_opt;
} wmi_pdev_suspend_cmd;


typedef struct {
    wmi_stats_id stats_id;
    /** number of pdev stats event structures (wmi_pdev_stats) 0 or 1 */
    A_UINT32 num_pdev_stats;
    /** number of pdev ext stats event structures (wmi_pdev_ext_stats) 0 or 1 */
    A_UINT32 num_pdev_ext_stats;
    /** number of vdev stats event structures  (wmi_vdev_stats) 0 or max vdevs */
    A_UINT32 num_vdev_stats;
    /** number of peer stats event structures  (wmi_peer_stats) 0 or max peers */
    A_UINT32 num_peer_stats;
    A_UINT32 num_bcnflt_stats;
    /** followed by
     * num_pdev_stats * size of(struct wmi_pdev_stats)
     * num_pdev_ext_stats * size of(struct wmi_pdev_ext_stats)
     * num_vdev_stats * size of(struct wmi_vdev_stats)
     * num_peer_stats * size of(struct wmi_peer_stats)
     *
     * Target will set WMI_REQUEST_PEER_EXTD_STAT in the stats_id in the
     * event in case target will send only peer_extd stats after bcnflt stats.
     * host has to check for this id and rip the buffer for peer_extd_stats
     * num_peer_stats * sizeof(struct wmi_peer_extd_stats)
     *
     * Target will set WMI_REQUEST_VDEV_EXTD_STAT in the stats_id in the
     * event in case target will send only vdev_extd stats after bcnflt stats.
     * host has to check for this id and rip the buffer for vdev_extd_stats
     * num_vdev_stats * sizeof(struct wmi_vdev_extd_stats)
     *
     * Target will set WMI_REQUEST_PDEV_EXT2_STAT in the stats_id in the
     * event in case target will send only pdev_ext2 stats after bcnflt stats.
     * host has to check for this id and rip the buffer for pdev_ext2_stats
     * num_pdev_stats (0 or 1) * sizeof(struct wmi_pdev_ext2_stats)
     *
     * If two or more of WMI_REQUEST_PEER_VDEV_STAT, WMI_REQUEST_PEER_EXTD_STAT,
     * and WMI_REQUEST_PDEV_EXT2_STAT are set, ripping the buffer should be in
     * the following order after bcnflt stats.
     * 1. peer_extd_stats
     * 2. vdev_extd_stats
     * 3. pdev_ext2_stats
     *
     * By having a zero sized array, the pointer to data area
     * becomes available without increasing the struct size
     */
    A_UINT8 data[0];

} wmi_stats_event;

/**
 *  PDEV statistics
 *  @todo
 *  add all PDEV stats here
 */
typedef struct {
    /** Channel noise floor */
    A_INT32 chan_nf;
    /** TX frame count */
    A_UINT32 tx_frame_count;
    /** RX frame count */
    A_UINT32 rx_frame_count;
    /** rx clear count */
    A_UINT32 rx_clear_count;
    /** cycle count */
    A_UINT32 cycle_count;
    /** Phy error count */
    A_UINT32 phy_err_count;
    /** Channel Tx Power */
    A_UINT32 chan_tx_pwr;
    /** WAL dbg stats */
    struct wlan_dbg_stats pdev_stats;
    A_UINT32    ackRcvBad;
    A_UINT32    rtsBad;
    A_UINT32    rtsGood;
    A_UINT32    fcsBad;
    A_UINT32    noBeacons;
    A_UINT32    mib_int_count;
} wmi_pdev_stats;

/**
 *  PDEV extension statistics
 */
typedef struct {
    A_UINT32    rx_rssi_comb;
    A_UINT32    rx_rssi_chain0;
    A_UINT32    rx_rssi_chain1;
    A_UINT32    rx_rssi_chain2;
    A_UINT32    rx_rssi_chain3;
    A_UINT32    rx_mcs[10];
    A_UINT32    tx_mcs[10];
    A_UINT32    ack_rssi;
} wmi_pdev_ext_stats;

/**
 *  PDEV extension statistics 2
 *  @todo
 *  add all new PDEV stats here (using the reserved space)
 */
typedef struct {
    /** Channel noise floor for secondary 80 band, return (A_UINT32) -1 if
     *  current channel is not in VHT160/VHT80+80 mode.
     */
    A_INT32    chan_nf_sec80; /* units are dBm */
    A_UINT32    reserved[7];
} wmi_pdev_ext2_stats;

/**
 *  VDEV statistics
 *  @todo
 *  add all VDEV stats here
 */

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
} wmi_vdev_stats;

/**
 *  Vdev extension statistics
 *  @todo
 *  add all New Vdev stats here
 */

/* For members of wmi_vdev_extd_stats after mpdu_fail_retry,
 * WMI_VDEV_EXTD_STATS_CONFIG is set to indicate that the count is valid.
 * If WMI_VDEV_EXTD_STATS_CONFIG is not set, the count is invalid and should
 * not be used.
 */
#define WMI_VDEV_EXTD_STATS_CONFIG      0x80000000
#define WMI_VDEV_EXTD_STATS_CONFIG_S    31

#define WMI_VDEV_EXTD_STATS_COUNT       0x7fffffff
#define WMI_VDEV_EXTD_STATS_COUNT_S     0

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /* No of Aggrs Queued to HW */
    A_UINT32 ppdu_aggr_cnt;
    /* No of PPDU's not Acked includes both aggr and nonaggr's */
    A_UINT32 ppdu_noack;
    /* No of MPDU/Subframes's queued to HW in Aggregates */
    A_UINT32 mpdu_queued;
    /* No of NonAggr/MPDU/Subframes's queued to HW in Legacy NonAggregates */
    A_UINT32 ppdu_nonaggr_cnt;
    /* No of MPDU/Subframes's SW requeued includes both Aggr and NonAggr */
    A_UINT32 mpdu_sw_requed;
    /* No of MPDU/Subframes's transmitted Successfully after Single/mul HW retry */
    A_UINT32 mpdu_suc_retry;
    /* No of MPDU/Subframes's transmitted Success after Multiple HW retry */
    A_UINT32 mpdu_suc_multitry;
    /* No of MPDU/Subframes's failed transmission after Multiple HW retry */
    A_UINT32 mpdu_fail_retry;

    union {
        /*
         * Note that not all 13 elements of the reserved array are truly
         * still reserved / available.  The anon struct within this union
         * uses some (sizeof(anon struct) / size(A_UINT32)) of this space.
         * Only the elements of the reserved array that fall beyond the
         * end of the anon struct are actually still reserved.
         * The proper change would be to add the new fields directly within the
         * wmi_vdev_extd_stats struct, and change reserved[13] -> reserved[6].
         * However, this change would expose a problem within multiple FW
         * branches, which, rather than initially setting the entire
         * wmi_vdev_extd_stats object to 0x0, only set the reserved[] elements
         * to 0x0.
         * Thus, FW branches that pick up these updated defs with the new
         * fields, but which do not explicitly initialize the new fields
         * would leave garbage values for the new fields.
         * Because it is impractical to fix this problem in all the affected
         * FW branches, the original size of the reserved[13] array is being
         * maintained, so that the FW branches that only clear the reserved[]
         * portion of this message object will still clear the portion of the
         * message that is being used for the new fields, leaving these
         * fields with a safe 0x0 value, even if they are not explicitly
         * initialized.
         */
        A_UINT32 reserved[13];

        /* Any new members of wmi_vdev_extd_stats will be added here.
         * These members have WMI_VDEV_EXTD_STATS_CONFIG set if the count value
         * is valid.
         */
        struct {
            /* No of Fine Timing Measurement frames transmitted successfully */
            A_UINT32 tx_ftm_suc;
            /* No of Fine Timing Measurement frames transmitted successfully after retry */
            A_UINT32 tx_ftm_suc_retry;
            /* No of Fine Timing Measurement frames not transmitted successfully */
            A_UINT32 tx_ftm_fail;
            /* No of Fine Timing Measurement Request frames received, including initial, non-initial, and duplicates */
            A_UINT32 rx_ftmr_cnt;
            /* No of duplicate Fine Timing Measurement Request frames received, including both initial and non-initial */
            A_UINT32 rx_ftmr_dup_cnt;
            /* No of initial Fine Timing Measurement Request frames received */
            A_UINT32 rx_iftmr_cnt;
            /* No of duplicate initial Fine Timing Measurement Request frames received */
            A_UINT32 rx_iftmr_dup_cnt;
        };

        /* Any remaining space in this union is set to 0x0. */
    };
} wmi_vdev_extd_stats;

A_COMPILE_TIME_ASSERT(wmi_vdev_extd_stats_fixed, sizeof(wmi_vdev_extd_stats) == 88);

/**
 *  peer statistics.
 *
 * @todo
 * add more stats
 *
 */
typedef struct {
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /** rssi */
    A_UINT32  peer_rssi;
    /** rssi sequence number */
    A_UINT32  peer_rssi_seq_num;
    /** last tx data rate used for peer */
    A_UINT32  peer_tx_rate;
    /** last rx data rate used for peer */
    A_UINT32  peer_rx_rate;
	/** Current PER */
	A_UINT32  currentper;
	/** Retries happend during transmission */
	A_UINT32  retries;
	/** Maximum Aggregation Size */
	A_UINT32  txratecount;
	/** Max4msframelen of tx rates used */
	A_UINT32  max4msframelen;
	/** Total no of subframes */
	A_UINT32  totalsubframes;
	/* No of bytes transmitted to the client */
	A_UINT32 txbytes;
	/** Packet Loss due to buffer overflows */
	A_UINT32  nobuffs[4];
	/** Packet Loss due to excessive retries */
	A_UINT32  excretries[4];
    /** how many times peer's RSSI changed by a non-negligible amount */
    A_UINT32  peer_rssi_changed;
} wmi_peer_stats;

/**
 * In the below sgi_count structure member bit 31 is used to convey
 * whether FW is passing the sgi_count or not to host. If this bit is 0,
 * host can ignore the sgi_count passed through peer_extd_stats.
 * This validity flag is added for backward compatibility.
 */
#define WMI_SGI_CONFIG_BIT 31
#define WMI_PEER_EXTD_STATS_SGI_CONFIG_SET (1 << WMI_SGI_CONFIG_BIT)
#define WMI_PEER_EXTD_STATS_SGI_CONFIG_GET(sgi_count) \
    (((sgi_count) & WMI_PEER_EXTD_STATS_SGI_CONFIG_SET) >> WMI_SGI_CONFIG_BIT)
#define WMI_PEER_EXTD_STATS_SGI_COUNT_SET(sgi_count) \
    (WMI_PEER_EXTD_STATS_SGI_CONFIG_SET | (sgi_count))
#define WMI_PEER_EXTD_STATS_SGI_COUNT_GET(sgi_count) \
    ((sgi_count) & (~WMI_PEER_EXTD_STATS_SGI_CONFIG_SET))

/**
  *  Peer extension statistics
  *  @todo
  *  add all New Peer stats here
  */
typedef struct {
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /** Peer Inactive time in seconds */
    A_UINT32 inactive_time;
    A_UINT32 peer_chain_rssi;
    A_UINT32 rx_duration;
    /** Total TX bytes (including dot11 header) sent to peer */
    A_UINT32 peer_tx_bytes;
    /** Total RX bytes (including dot11 header) received from peer */
    A_UINT32 peer_rx_bytes;
    /** last TX ratecode */
    A_UINT32 last_tx_rate_code;
    /** TX power used by peer - units are 0.5 dBm */
    A_UINT32 last_tx_power;
    /** tokens allocated for the peer at one ATF interval */
    A_UINT32 atf_tokens_allocated;
    /** tokens utilized by the peer at one ATF interval */
    A_UINT32 atf_tokens_utilized;
    /**
     * Number of times the MU transmission is blacklisted
     * for duration of 5 seconds for this peer due to sounding failure
     */
    A_UINT32 num_mu_tx_blacklisted;
    /*
     * Short Guard Interval count of the peer in one stats interval.
     * See above WMI_PEER_EXTD_STATS_SGI macros.
     */
    A_UINT32 sgi_count;
    A_UINT32 reserved[2]; /* for future extensions */ /* set to 0x0 */
} wmi_peer_extd_stats;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** VDEV type (AP,STA,IBSS,MONITOR) */
    A_UINT32 vdev_type;
    /** VDEV subtype (P2PDEV, P2PCLI, P2PGO, BT3.0)*/
    A_UINT32 vdev_subtype;
    /** VDEV MAC address */
    wmi_mac_addr vdev_macaddr;
} wmi_vdev_create_cmd;

typedef struct {
    A_UINT32   type_count; /** 255: continuous schedule, 0: reserved */
    A_UINT32   duration ;  /** Absent period duration in micro seconds */
    A_UINT32   interval;   /** Absent period interval in micro seconds */
    A_UINT32   start_time; /** 32 bit tsf time when in starts */
} wmi_p2p_noa_descriptor;

/** values for vdev_type */
#define WMI_VDEV_TYPE_AP         0x1
#define WMI_VDEV_TYPE_STA        0x2
#define WMI_VDEV_TYPE_IBSS       0x3
#define WMI_VDEV_TYPE_MONITOR    0x4

/** values for vdev_subtype */
#define WMI_UNIFIED_VDEV_SUBTYPE_P2P_DEVICE 0x1
#define WMI_UNIFIED_VDEV_SUBTYPE_P2P_CLIENT 0x2
#define WMI_UNIFIED_VDEV_SUBTYPE_P2P_GO     0x3
#define WMI_UNIFIED_VDEV_SUBTYPE_PROXY_STA  0x4
#define WMI_UNIFIED_VDEV_SUBTYPE_MESH       0x5
/* new subtype for 11S mesh is required as 11S functionality differs
 * in many ways from proprietary mesh
 * 11S uses 6-addr frame format and supports peering between mesh
 * stations and dynamic best path selection between mesh stations.
 * While in proprietary mesh, neighbouring mesh station MAC is manually
 * added to AST table for traffic flow between mesh stations */
#define WMI_UNIFIED_VDEV_SUBTYPE_MESH_11S   0x6

/** values for vdev_start_request flags */
/** Indicates that AP VDEV uses hidden ssid. only valid for
 *  AP/GO */
#define WMI_UNIFIED_VDEV_START_HIDDEN_SSID  (1<<0)
/** Indicates if robust management frame/management frame
 *  protection is enabled. For GO/AP vdevs, it indicates that
 *  it may support station/client associations with RMF enabled.
 *  For STA/client vdevs, it indicates that sta will
 *  associate with AP with RMF enabled. */
#define WMI_UNIFIED_VDEV_START_PMF_ENABLED  (1<<1)

typedef struct {
    /** WMI channel */
    wmi_channel chan;
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** requestor id identifying the caller module */
    A_UINT32 requestor_id;
    /** beacon interval from received beacon */
    A_UINT32 beacon_interval;
    /** DTIM Period from the received beacon */
    A_UINT32 dtim_period;
    /** Flags */
    A_UINT32 flags;
    /** ssid field. Only valid for AP/GO/IBSS/BTAmp VDEV type. */
    wmi_ssid ssid;
    /** beacon/probe reponse xmit rate. Applicable for SoftAP. */
    A_UINT32 bcn_tx_rate;
    /** beacon/probe reponse xmit power. Applicable for SoftAP. */
    A_UINT32 bcn_txPower;
    /** number of p2p NOA descriptor(s) from scan entry */
    A_UINT32  num_noa_descriptors;
    /** Disable H/W ack. This used by WMI_VDEV_RESTART_REQUEST_CMDID.
          During CAC, Our HW shouldn't ack ditected frames */
    A_UINT32  disable_hw_ack;
    /** actual p2p NOA descriptor from scan entry */
    wmi_p2p_noa_descriptor  noa_descriptors[2];
} wmi_vdev_start_request_cmd;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
} wmi_vdev_delete_cmd;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** aid (assoc id) received in association response for STA VDEV  */
    A_UINT32 vdev_assoc_id;
    /** bssid of the BSS the VDEV is joining  */
    wmi_mac_addr vdev_bssid;
} wmi_vdev_up_cmd;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
} wmi_vdev_stop_cmd;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
} wmi_vdev_down_cmd;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
} wmi_vdev_standby_response_cmd;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
} wmi_vdev_resume_response_cmd;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** parameter id   */
    A_UINT32 param_id;
    /** parameter value */
    A_UINT32 param_value;
} wmi_vdev_set_param_cmd;

typedef struct {
    A_UINT32 key_seq_counter_l;
    A_UINT32 key_seq_counter_h;
} wmi_key_seq_counter;

#define  WMI_CIPHER_NONE     0x0  /* clear key */
#define  WMI_CIPHER_WEP      0x1
#define  WMI_CIPHER_TKIP     0x2
#define  WMI_CIPHER_AES_OCB  0x3
#define  WMI_CIPHER_AES_CCM  0x4
#define  WMI_CIPHER_WAPI     0x5
#define  WMI_CIPHER_CKIP     0x6
#define  WMI_CIPHER_AES_CMAC 0x7
#define  WMI_CIPHER_AES_GCM  0x8
#define  WMI_CIPHER_AES_GMAC 0x9
#define  WMI_CIPHER_UNUSED   0xFF

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** MAC address used for installing   */
    wmi_mac_addr peer_macaddr;
    /** key index */
    A_UINT32 key_ix;
    /** key flags */
    A_UINT32 key_flags;
    /** key cipher, defined above */
    A_UINT32 key_cipher;
    /** key rsc counter */
    wmi_key_seq_counter key_rsc_counter;
    /** global key rsc counter */
    wmi_key_seq_counter key_global_rsc_counter;
    /** global key tsc counter */
    wmi_key_seq_counter key_tsc_counter;
    /** WAPI key rsc counter */
    A_UINT8 wpi_key_rsc_counter[16];
    /** WAPI key tsc counter */
    A_UINT8 wpi_key_tsc_counter[16];
    /** key length */
    A_UINT32 key_len;
    /** key tx mic length */
    A_UINT32 key_txmic_len;
    /** key rx mic length */
    A_UINT32 key_rxmic_len;
    /* actual key data */
    A_UINT8  key_data[1]; /* contains key followed by tx mic followed by rx mic */
} wmi_vdev_install_key_cmd;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** time between consecutive trigger frames in TDMA mode (units = ms) */
    A_UINT32 sifs_trigger_time;
} wmi_vdev_sifs_trigger_time_cmd;

/** Preamble types to be used with VDEV fixed rate configuration */
typedef enum {
    WMI_RATE_PREAMBLE_OFDM,
    WMI_RATE_PREAMBLE_CCK,
    WMI_RATE_PREAMBLE_HT,
    WMI_RATE_PREAMBLE_VHT,
} WMI_RATE_PREAMBLE;

/** Value to disable fixed rate setting */
#define WMI_FIXED_RATE_NONE    (0xff)


/** the definition of different VDEV parameters */
typedef enum {
    /** RTS Threshold */
    WMI_VDEV_PARAM_RTS_THRESHOLD = 0x1,
    /** Fragmentation threshold */
    WMI_VDEV_PARAM_FRAGMENTATION_THRESHOLD,
    /** beacon interval in TUs */
    WMI_VDEV_PARAM_BEACON_INTERVAL,
    /** Listen interval in TUs */
    WMI_VDEV_PARAM_LISTEN_INTERVAL,
    /** muticast rate in Mbps */
    WMI_VDEV_PARAM_MULTICAST_RATE,
    /** management frame rate in Mbps */
    WMI_VDEV_PARAM_MGMT_TX_RATE,
    /** slot time (long vs short) */
    WMI_VDEV_PARAM_SLOT_TIME,
    /** preamble (long vs short) */
    WMI_VDEV_PARAM_PREAMBLE,
    /** SWBA time (time before tbtt in msec) */
    WMI_VDEV_PARAM_SWBA_TIME,
    /** time period for updating VDEV stats */
    WMI_VDEV_STATS_UPDATE_PERIOD,
    /** age out time in msec for frames queued for station in power save*/
    WMI_VDEV_PWRSAVE_AGEOUT_TIME,
    /** Host SWBA interval (time in msec before tbtt for SWBA event generation) */
    WMI_VDEV_HOST_SWBA_INTERVAL,
    /** DTIM period (specified in units of num beacon intervals) */
    WMI_VDEV_PARAM_DTIM_PERIOD,
    /** scheduler air time limit for this VDEV. used by off chan scheduler  */
    WMI_VDEV_OC_SCHEDULER_AIR_TIME_LIMIT,
    /** enable/dsiable WDS for this VDEV  */
    WMI_VDEV_PARAM_WDS,
    /** ATIM Window */
    WMI_VDEV_PARAM_ATIM_WINDOW,
    /** BMISS max */
    WMI_VDEV_PARAM_BMISS_COUNT_MAX,
	/** BMISS first time */
	WMI_VDEV_PARAM_BMISS_FIRST_BCNT,
	/** BMISS final time */
	WMI_VDEV_PARAM_BMISS_FINAL_BCNT,
    /** WMM enables/disabled */
    WMI_VDEV_PARAM_FEATURE_WMM,
    /** Channel width */
    WMI_VDEV_PARAM_CHWIDTH,
    /** Channel Offset */
    WMI_VDEV_PARAM_CHEXTOFFSET,
    /** Disable HT Protection */
    WMI_VDEV_PARAM_DISABLE_HTPROTECTION,
    /** Quick STA Kickout */
    WMI_VDEV_PARAM_STA_QUICKKICKOUT,
    /** Rate to be used with Management frames */
    WMI_VDEV_PARAM_MGMT_RATE,
    /** Protection Mode */
    WMI_VDEV_PARAM_PROTECTION_MODE,
    /** Fixed rate setting */
    WMI_VDEV_PARAM_FIXED_RATE,
    /** Short GI Enable/Disable */
    WMI_VDEV_PARAM_SGI,
    /** Enable LDPC */
    WMI_VDEV_PARAM_LDPC,
    /** Enable Tx STBC */
    WMI_VDEV_PARAM_TX_STBC,
    /** Enable Rx STBC */
    WMI_VDEV_PARAM_RX_STBC,
    /** Intra BSS forwarding  */
    WMI_VDEV_PARAM_INTRA_BSS_FWD,
    /** Setting Default xmit key for Vdev */
    WMI_VDEV_PARAM_DEF_KEYID,
    /** NSS width */
    WMI_VDEV_PARAM_NSS,
    /** Set the custom rate for the broadcast data frames */
    WMI_VDEV_PARAM_BCAST_DATA_RATE,
    /** Set the custom rate (rate-code) for multicast data frames */
    WMI_VDEV_PARAM_MCAST_DATA_RATE,
    /** Tx multicast packet indicate Enable/Disable */
    WMI_VDEV_PARAM_MCAST_INDICATE,
    /** Tx DHCP packet indicate Enable/Disable */
    WMI_VDEV_PARAM_DHCP_INDICATE,
    /** Enable host inspection of Tx unicast packet to unknown destination */
    WMI_VDEV_PARAM_UNKNOWN_DEST_INDICATE,

    /* The minimum amount of time AP begins to consider STA inactive */
    WMI_VDEV_PARAM_AP_KEEPALIVE_MIN_IDLE_INACTIVE_TIME_SECS,

    /* An associated STA is considered inactive when there is no recent TX/RX
     * activity and no downlink frames are buffered for it. Once a STA exceeds
     * the maximum idle inactive time, the AP will send an 802.11 data-null as
     * a keep alive to verify the STA is still associated. If the STA does ACK
     * the data-null, or if the data-null is buffered and the STA does not
     * retrieve it, the STA will be considered unresponsive (see
     * WMI_VDEV_AP_KEEPALIVE_MAX_UNRESPONSIVE_TIME_SECS). */
    WMI_VDEV_PARAM_AP_KEEPALIVE_MAX_IDLE_INACTIVE_TIME_SECS,

    /* An associated STA is considered unresponsive if there is no recent
     * TX/RX activity and downlink frames are buffered for it. Once a STA
     * exceeds the maximum unresponsive time, the AP will send a
     * WMI_STA_KICKOUT event to the host so the STA can be deleted. */
    WMI_VDEV_PARAM_AP_KEEPALIVE_MAX_UNRESPONSIVE_TIME_SECS,

    /* Enable NAWDS : MCAST INSPECT Enable, NAWDS Flag set */
    WMI_VDEV_PARAM_AP_ENABLE_NAWDS,

    /** Multicast to Unicast conversion setting */
    WMI_VDEV_PARAM_MCAST2UCAST_SET,
    /** Enable/Disable RTS-CTS */
    WMI_VDEV_PARAM_ENABLE_RTSCTS,
    /** Total number of HW retries */
    WMI_VDEV_PARAM_RC_NUM_RETRIES,
   /* Enable TXBFee/er */
    WMI_VDEV_PARAM_TXBF,

    /**Set packet power save */
    WMI_VDEV_PARAM_PACKET_POWERSAVE,

    /**Drops un-encrypted packets if any received in an encryted connection
     * otherwise forwards to host
     */
    WMI_VDEV_PARAM_DROP_UNENCRY,

    /*
     * Set TX encap type.
     *
     * enum wmi_pkt_type is to be used as the parameter
     * specifying the encap type.
     */
    WMI_VDEV_PARAM_TX_ENCAP_TYPE,


    /*
     * Try to detect stations that woke-up and exited power save but did not
     * successfully transmit data-null with PM=0 to AP. When this happens,
     * STA and AP power save state are out-of-sync. Use buffered but
     * undelievered MSDU to the STA as a hint that the STA is really awake
     * and expecting normal ASAP delivery, rather than retreiving BU with
     * PS-Poll, U-APSD trigger, etc.
     *
     * 0 disables out-of-sync detection. Maximum time is 255 seconds.
     */
    WMI_VDEV_PARAM_AP_DETECT_OUT_OF_SYNC_SLEEPING_STA_TIME_SECS,

    /** Max tx percentage for cabq */
    WMI_VDEV_PARAM_CABQ_MAXDUR,
    /** MFPTEST settings */
    WMI_VDEV_PARAM_MFPTEST_SET,
    /** RTS Fixed rate setting */
    WMI_VDEV_PARAM_RTS_FIXED_RATE,
    /** VHT SGI MASK */
    WMI_VDEV_PARAM_VHT_SGIMASK,
    /** VHT80 Auto Rate MASK */
    WMI_VDEV_PARAM_VHT80_RATEMASK,

    /* Enable/Disable early rx dynamic adjust feature.
      * Early-rx dynamic adjust is a advance power save feature.
      * Early-rx is a wakeup duration before exact TBTT,which is deemed necessary to provide a cushion for various
      * timing discrepancies in the system.
      * In current code branch, the duration is set to a very conservative fix value to make sure the drift impact is minimum.
      * The fix early-tx will result in the unnessary power consume, so a dynamic early-rx adjust algorithm can be designed
      * properly to minimum the power consume.*/
    WMI_VDEV_PARAM_EARLY_RX_ADJUST_ENABLE,

    /* set target bmiss number per sample cycle if bmiss adjust was chosen.
     * In this adjust policy,early-rx is adjusted by comparing the current bmiss rate to target bmiss rate
     * which can be set by user through WMI command.
     */
    WMI_VDEV_PARAM_EARLY_RX_TGT_BMISS_NUM,

    /* set sample cycle(in the unit of beacon interval) if bmiss adjust was chosen */
    WMI_VDEV_PARAM_EARLY_RX_BMISS_SAMPLE_CYCLE,

    /* set slop_step */
    WMI_VDEV_PARAM_EARLY_RX_SLOP_STEP,

    /* set init slop */
    WMI_VDEV_PARAM_EARLY_RX_INIT_SLOP,

    /* pause adjust enable/disable */
    WMI_VDEV_PARAM_EARLY_RX_ADJUST_PAUSE,

    /* set Proxy STA features for this vap*/
    WMI_VDEV_PARAM_PROXY_STA,

    /* set MERU VC mode */
    WMI_VDEV_PARAM_MERU_VC,

    /* Set receive packet type */
    WMI_VDEV_PARAM_RX_DECAP_TYPE,

    /* Set ratemask with specific Bandwidth and NSS */
    WMI_VDEV_PARAM_BW_NSS_RATEMASK,

    /* Set SENSOR Support */
    WMI_VDEV_PARAM_SENSOR_AP,

    /* Set beacon rate */
    WMI_VDEV_PARAM_BEACON_RATE,

    /* Enable CTS to self for DTIM beacon */
    WMI_VDEV_PARAM_DTIM_ENABLE_CTS,

    /* Disable station kickout at Vap level */
    WMI_VDEV_PARAM_STA_KICKOUT,

    /* VDEV capabilities */
    WMI_VDEV_PARAM_CAPABILITIES,

    /*
     * Increment TSF in micro seconds to avoid beacon collision on mesh VAP.
     * The host must ensure that either no other vdevs share the TSF with
     * this vdev, or else that it is acceptable to apply this TSF adjustment
     * to all vdevs sharing the TSF.
     * C.f. WMI_VDEV_PARAM_TSF_DECREMENT.
     */
    WMI_VDEV_PARAM_TSF_INCREMENT,

    /*
     * Vdev level rx filter of from-ds / to-ds / no-ds / ta / ra frames.
     * Used mainly for mesh-vap.
     */
    WMI_VDEV_PARAM_RX_FILTER,

    /* vdev-specific mgmt tx power in dBm units (signed integer value) */
    WMI_VDEV_PARAM_MGMT_TX_POWER,

    /** per ssid (vdev) based ATF strict/fair scheduling policy
     *  param values are WMI_ATF_SSID_FAIR_SCHED or WMI_ATF_SSID_STRICT_SCHED
     */
    WMI_VDEV_PARAM_ATF_SSID_SCHED_POLICY,

    /**
     * When the target receives this vdev param type, it disables
     * dynamic BW RTS (regardless of the accompanying param value)
     */
    WMI_VDEV_PARAM_DISABLE_DYN_BW_RTS,

    /**
     * Decrement TSF in micro seconds to avoid beacon collision on mesh VAP.
     * The host must ensure that either no other vdevs share the TSF with
     * this vdev, or else that it is acceptable to apply this TSF adjustment
     * to all vdevs sharing the TSF.
     * C.f. WMI_VDEV_PARAM_TSF_INCREMENT.
     */
    WMI_VDEV_PARAM_TSF_DECREMENT,

    /* Set rate for Selfgen Frames generated in Firmware */
    WMI_VDEV_PARAM_SELFGEN_FIXED_RATE,

    /*
     * Disable or Enable with size limits A-MPDU per VDEV per AC
     * bits 7:0 -> Access Category (0x0=BE, 0x1=BK, 0x2=VI, 0x3=VO, 0xFF=All AC)
     * bits 31:8 -> Max number of subframes
     *
     * If the size if zero, A-MPDU is disabled for the VAP for the given AC.
     * Else, A-MPDU is enabled for the VAP for the given AC, but is limited
     * to the specified max number of sub frames.
     *
     * If Access Category is 0xff, the specified max number of subframes will
     * be applied for all the Access Categories. If not, max subframes
     * have to be applied per AC.
     *
     * This is only for TX subframe size. In RX path this new VDEV param shall
     * only be used to check, wherever needed, to see if AMPDU is enabled or
     * disabled for a given VAP.
     */
    WMI_VDEV_PARAM_AMPDU_SUBFRAME_SIZE_PER_AC,

    /* Maximum NSS per VDEV for VHT160 - Extended NSS support */
    WMI_VDEV_PARAM_NSS_VHT160,

    /* Maximum NSS per VDEV for VHT80_80 - Extended NSS support */
    WMI_VDEV_PARAM_NSS_VHT80_80,

    /*
     * Disable or Enable with size limits A-MSDU per VDEV per AC (for tx)
     * bits 7:0 -> Access Category (0x0=BE, 0x1=BK, 0x2=VI, 0x3=VO, 0xFF=All AC)
     * bits 31:8 -> Max number of msdus in AMSDU.
     *
     * If AC is 0xff, max number is applied for all Access Categories
     */
    WMI_VDEV_PARAM_AMSDU_SUBFRAME_SIZE_PER_AC,

    /* Disable multicast buffering even when the STAs are in power save */
    WMI_VDEV_PARAM_DISABLE_CABQ,

    /* Set the rate for trigger frames in TDMA mode
     * The associated parameter value is the rate code to use.
     */
    WMI_VDEV_PARAM_SIFS_TRIGGER_RATE,

    /* vdev-specific tx power in dBm units (signed integer value)
     * Applicable for all firmware generated mgmt, data and ctrl packets
     * bits 7:0  -> Power value in dBm
     * bits 15:8 -> Frame subtype
     * bits 31:16-> Frame type
     */
    WMI_VDEV_PARAM_TX_POWER,

    /** VDEV parameter to enable or disable RTT responder role
     * valid values: 0-Disable responder role, 1-Enable responder role
     */
    WMI_VDEV_PARAM_ENABLE_DISABLE_RTT_RESPONDER_ROLE,

    /* VDEV param to disable source port learning for 4-addr frames in FW */
    WMI_VDEV_PARAM_DISABLE_4_ADDR_SRC_LRN,

} WMI_VDEV_PARAM;

/* Max subframes per VAP per AC masks */
#define WMI_VDEV_PARAM_AC_BITPOS           0
#define WMI_VDEV_PARAM_AC_NUM_BITS         8
#define WMI_VDEV_PARAM_MAX_SUBFRM_BITPOS   8
#define WMI_VDEV_PARAM_MAX_SUBFRM_NUM_BITS 24

#define WMI_VDEV_PARAM_AC_SET(param, value) \
    WMI_SET_BITS(param, WMI_VDEV_PARAM_AC_BITPOS, \
        WMI_VDEV_PARAM_AC_NUM_BITS, value)
#define WMI_VDEV_PARAM_AC_GET(param)         \
    WMI_GET_BITS(param, WMI_VDEV_PARAM_AC_BITPOS, \
        WMI_VDEV_PARAM_AC_NUM_BITS)

#define WMI_VDEV_PARAM_MAX_SUBFRM_SET(param, value) \
    WMI_SET_BITS(param, WMI_VDEV_PARAM_MAX_SUBFRM_BITPOS, \
        WMI_VDEV_PARAM_MAX_SUBFRM_NUM_BITS, value)
#define WMI_VDEV_PARAM_MAX_SUBFRM_GET(param) \
    WMI_GET_BITS(param, WMI_VDEV_PARAM_MAX_SUBFRM_BITPOS, \
        WMI_VDEV_PARAM_MAX_SUBFRM_NUM_BITS)


/*Tx power */
#define WMI_VDEV_PARAM_FRAME_TYPE_BITPOS           16
#define WMI_VDEV_PARAM_FRAME_TYPE_NUM_BITS         16
#define WMI_VDEV_PARAM_FRAME_SUBTYPE_BITPOS        8
#define WMI_VDEV_PARAM_FRAME_SUBTYPE_NUM_BITS      8
#define WMI_VDEV_PARAM_TX_POWER_BITPOS             0
#define WMI_VDEV_PARAM_TX_POWER_NUM_BITS           8

#define WMI_VDEV_PARAM_FRAME_TYPE_SET(param, value) \
    WMI_SET_BITS(param, WMI_VDEV_PARAM_FRAME_TYPE_BITPOS, \
        WMI_VDEV_PARAM_FRAME_TYPE_NUM_BITS, value)
#define WMI_VDEV_PARAM_FRAME_TYPE_GET(param)         \
    WMI_GET_BITS(param, WMI_VDEV_PARAM_FRAME_TYPE_BITPOS, \
        WMI_VDEV_PARAM_FRAME_TYPE_NUM_BITS)

#define WMI_VDEV_PARAM_FRAME_SUBTYPE_SET(param, value) \
    WMI_SET_BITS(param, WMI_VDEV_PARAM_FRAME_SUBTYPE_BITPOS, \
        WMI_VDEV_PARAM_FRAME_SUBTYPE_NUM_BITS, value)
#define WMI_VDEV_PARAM_FRAME_SUBTYPE_GET(param) \
    WMI_GET_BITS(param, WMI_VDEV_PARAM_FRAME_SUBTYPE_BITPOS, \
        WMI_VDEV_PARAM_FRAME_SUBTYPE_NUM_BITS)

#define WMI_VDEV_PARAM_TX_POWER_SET(param, value) \
    WMI_SET_BITS(param, WMI_VDEV_PARAM_TX_POWER_BITPOS, \
        WMI_VDEV_PARAM_TX_POWER_NUM_BITS, value)
#define WMI_VDEV_PARAM_TX_POWER_GET(param)         \
    WMI_GET_BITS(param, WMI_VDEV_PARAM_TX_POWER_BITPOS, \
        WMI_VDEV_PARAM_TX_POWER_NUM_BITS)


/* vdev capabilities bit mask */
#define WMI_VDEV_BEACON_SUPPORT  0x1
#define WMI_VDEV_WDS_LRN_ENABLED 0x2
#define WMI_VDEV_VOW_ENABLED     0x4
#define WMI_VDEV_IS_BEACON_SUPPORTED(param) ((param) & WMI_VDEV_BEACON_SUPPORT)
#define WMI_VDEV_IS_WDS_LRN_ENABLED(param) ((param) & WMI_VDEV_WDS_LRN_ENABLED)
#define WMI_VDEV_IS_VOW_ENABLED(param) ((param) & WMI_VDEV_VOW_ENABLED)

/* TXBF capabilities masks */
#define WMI_TXBF_CONF_SU_TX_BFEE_S 0
#define WMI_TXBF_CONF_SU_TX_BFEE_M 0x1
#define WMI_TXBF_CONF_SU_TX_BFEE (WMI_TXBF_CONF_SU_TX_BFEE_M << WMI_TXBF_CONF_SU_TX_BFEE_S)
#define WMI_TXBF_CONF_SU_TX_BFEE_GET(x) WMI_F_MS(x,WMI_TXBF_CONF_SU_TX_BFEE)
#define WMI_TXBF_CONF_SU_TX_BFEE_SET(x,z) WMI_F_RMW(x,z,WMI_TXBF_CONF_SU_TX_BFEE)

#define WMI_TXBF_CONF_MU_TX_BFEE_S 1
#define WMI_TXBF_CONF_MU_TX_BFEE_M 0x1
#define WMI_TXBF_CONF_MU_TX_BFEE (WMI_TXBF_CONF_MU_TX_BFEE_M << WMI_TXBF_CONF_MU_TX_BFEE_S)
#define WMI_TXBF_CONF_MU_TX_BFEE_GET(x) WMI_F_MS(x,WMI_TXBF_CONF_MU_TX_BFEE)
#define WMI_TXBF_CONF_MU_TX_BFEE_SET(x,z) WMI_F_RMW(x,z,WMI_TXBF_CONF_MU_TX_BFEE)

#define WMI_TXBF_CONF_SU_TX_BFER_S 2
#define WMI_TXBF_CONF_SU_TX_BFER_M 0x1
#define WMI_TXBF_CONF_SU_TX_BFER (WMI_TXBF_CONF_SU_TX_BFER_M << WMI_TXBF_CONF_SU_TX_BFER_S)
#define WMI_TXBF_CONF_SU_TX_BFER_GET(x) WMI_F_MS(x,WMI_TXBF_CONF_SU_TX_BFER)
#define WMI_TXBF_CONF_SU_TX_BFER_SET(x,z) WMI_F_RMW(x,z,WMI_TXBF_CONF_SU_TX_BFER)

#define WMI_TXBF_CONF_MU_TX_BFER_S 3
#define WMI_TXBF_CONF_MU_TX_BFER_M 0x1
#define WMI_TXBF_CONF_MU_TX_BFER (WMI_TXBF_CONF_MU_TX_BFER_M << WMI_TXBF_CONF_MU_TX_BFER_S)
#define WMI_TXBF_CONF_MU_TX_BFER_GET(x) WMI_F_MS(x,WMI_TXBF_CONF_MU_TX_BFER)
#define WMI_TXBF_CONF_MU_TX_BFER_SET(x,z) WMI_F_RMW(x,z,WMI_TXBF_CONF_MU_TX_BFER)

#define WMI_TXBF_CONF_STS_CAP_S 4
#define WMI_TXBF_CONF_STS_CAP_M 0x7
#define WMI_TXBF_CONF_STS_CAP (WMI_TXBF_CONF_STS_CAP_M << WMI_TXBF_CONF_STS_CAP_S)
#define WMI_TXBF_CONF_STS_CAP_GET(x) WMI_F_MS(x,WMI_TXBF_CONF_STS_CAP);
#define WMI_TXBF_CONF_STS_CAP_SET(x,z) WMI_F_RMW(x,z,WMI_TXBF_CONF_STS_CAP)

#define WMI_TXBF_CONF_IMPLICIT_BF_S 7
#define WMI_TXBF_CONF_IMPLICIT_BF_M 0x1
#define WMI_TXBF_CONF_IMPLICIT_BF (WMI_TXBF_CONF_IMPLICIT_BF_M << WMI_TXBF_CONF_IMPLICIT_BF_S)
#define WMI_TXBF_CONF_IMPLICIT_BF_GET(x) WMI_F_MS(x,WMI_TXBF_CONF_IMPLICIT_BF)
#define WMI_TXBF_CONF_IMPLICIT_BF_SET(x,z) WMI_F_RMW(x,z,WMI_TXBF_CONF_IMPLICIT_BF)

#define WMI_TXBF_CONF_BF_SND_DIM_S 8
#define WMI_TXBF_CONF_BF_SND_DIM_M 0x7
#define WMI_TXBF_CONF_BF_SND_DIM (WMI_TXBF_CONF_BF_SND_DIM_M << WMI_TXBF_CONF_BF_SND_DIM_S)
#define WMI_TXBF_CONF_BF_SND_DIM_GET(x) WMI_F_MS(x,WMI_TXBF_CONF_BF_SND_DIM)
#define WMI_TXBF_CONF_BF_SND_DIM_SET(x,z) WMI_F_RMW(x,z,WMI_TXBF_CONF_BF_SND_DIM)

/* TXBF capabilities */
typedef struct {
    A_UINT32 txbf_cap;
} wmi_vdev_txbf_cap;

typedef enum {
    WMI_VDEV_RX_ALLOW_ALL_FRAMES  =  0x0, /* Don't drop any frames - Default */
    WMI_VDEV_RX_FILTER_OUT_FROMDS =  0x1, /* Drop FromDS frames */
    WMI_VDEV_RX_FILTER_OUT_TODS   =  0x2, /* Drop ToDS frames */
    WMI_VDEV_RX_FILTER_OUT_NODS   =  0x4, /* Drop NODS frames */
    WMI_VDEV_RX_FILTER_OUT_RA     =  0x8, /* Drop RA frames */
    WMI_VDEV_RX_FILTER_OUT_TA     = 0x10, /* Drop TA frames */
} wmi_vdev_param_filter;

/*******************************************************************
 * wmi_vdev_txbf_en is DEPRECATED in favor of wmi_vdev_txbf_cap,
 * and will soon be deleted.  Do not use it!
 *******************************************************************/
typedef struct {
    A_UINT32    su_tx_bfee  : 1,
                mu_tx_bfee  : 1,
                su_tx_bfer  : 1,
                mu_tx_bfer  : 1,
                txb_sts_cap : 3,
                implicit_bf : 1,
                bf_sounding_dim : 3;
} wmi_vdev_txbf_en;
        /** slot time long */
        #define WMI_VDEV_SLOT_TIME_LONG                                  0x1
        /** slot time short */
        #define WMI_VDEV_SLOT_TIME_SHORT                                 0x2
        /** preablbe long */
        #define WMI_VDEV_PREAMBLE_LONG                                   0x1
        /** preablbe short */
        #define WMI_VDEV_PREAMBLE_SHORT                                  0x2

/** the definition of different START/RESTART Event response  */
    typedef enum {
        /* Event response of START CMD */
        WMI_VDEV_START_RESP_EVENT = 0,
        /* Event response of RESTART CMD */
        WMI_VDEV_RESTART_RESP_EVENT,
    } WMI_START_EVENT_PARAM;

    typedef enum {
        WMI_VDEV_START_OK = 0,
        WMI_VDEV_START_CHAN_INVALID,
        /** Host DFS check - Once FW blocks DFS channels, any more VDEV start
         * with DFS channel will be responded with WMI_VDEV_START_CHAN_BLOCKED
         * vdev response status.
         */
        WMI_VDEV_START_CHAN_BLOCKED,
    } WMI_VDEV_START_STATUS;

        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;
            /** requestor id that requested the VDEV start request */
            A_UINT32 requestor_id;
            /* Respose of Event type START/RESTART */
            WMI_START_EVENT_PARAM resp_type;
            /** status of the response, see WMI_VDEV_START_STATUS */
            A_UINT32 status;
        } wmi_vdev_start_response_event;

        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;
        } wmi_vdev_standby_req_event;

        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;
        } wmi_vdev_resume_req_event;

        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;
        } wmi_vdev_stopped_event;

        /** common structure used for simple events (stopped, resume_req, standby response) */
        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;
        } wmi_vdev_simple_event;

        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;
            A_UINT32 last_rssi; /* units = dB w.r.t. noise floor */
            A_UINT32 avg_rssi; /* units = dB w.r.t. noise floor */
            A_UINT32 rssi_seq_num;
        } wmi_vdev_nac_rssi_event;

        /** VDEV start response status codes */
        #define WMI_VDEV_START_RESPONSE_STATUS_SUCCESS 0x0  /** VDEV succesfully started */
        #define WMI_VDEV_START_RESPONSE_INVALID_VDEVID  0x1  /** requested VDEV not found */
        #define WMI_VDEV_START_RESPONSE_NOT_SUPPORTED  0x2  /** unsupported VDEV combination */

        /** Beacon processing related command and event structures */
        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;
            /** xmit rate */
            A_UINT32 tx_rate;
            /** xmit power */
            A_UINT32 txPower;
            /** beacon buffer length in bytes */
            A_UINT32 buf_len;
        } wmi_bcn_tx_hdr;

        typedef struct {
            /** header */
            wmi_bcn_tx_hdr hdr;
            /** beacon buffer */
            A_UINT8 bufp[1];
        } wmi_bcn_tx_cmd;

        /* Beacon filter */
        #define WMI_BCN_FILTER_ALL   0 /* Filter all beacons */
        #define WMI_BCN_FILTER_NONE  1 /* Pass all beacons */
        #define WMI_BCN_FILTER_RSSI  2 /* Pass Beacons RSSI >= RSSI threshold */
        #define WMI_BCN_FILTER_BSSID 3 /* Pass Beacons with matching BSSID */
        #define WMI_BCN_FILTER_SSID  4 /* Pass Beacons with matching SSID */

        typedef struct {
            /** Filter ID */
            A_UINT32 bcn_filter_id;
            /** Filter type - wmi_bcn_filter */
            A_UINT32 bcn_filter;
            /** Buffer len */
            A_UINT32 bcn_filter_len;
            /** Filter info (threshold, BSSID, RSSI) */
            A_UINT8 *bcn_filter_buf;
        } wmi_bcn_filter_rx_cmd;

        /** Capabilities and IEs to be passed to firmware */
        typedef struct {
            /** Capabilities */
            A_UINT32 caps;
            /** ERP info */
            A_UINT32 erp;
            /** Advanced capabilities */
            /** HT capabilities */
            /** HT Info */
            /** ibss_dfs */
            /** wpa Info */
            /** rsn Info */
            /** rrm info */
            /** ath_ext */
            /** app IE */
        } wmi_bcn_prb_info;

        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;
            /** xmit rate */
            A_UINT32 tx_rate;
            /** xmit power */
            A_UINT32 txPower;
            /** beacon buffer offsets */
            A_UINT32 buf_len;
            /** beacon probe capabilities and IEs */
            wmi_bcn_prb_info bcn_prb_info;
        } wmi_bcn_prb_tmpl_cmd;

        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;
            /** beacon probe capabilities and IEs */
            wmi_bcn_prb_info bcn_prb_info;
            /** beacon buffer length */
            A_UINT32 buf_len;
            /** Variable length data */
            A_UINT8  data[1];
        } wmi_prb_tmpl_cmd;
        enum wmi_sta_ps_mode {
            /** enable power save for the given STA VDEV */
            WMI_STA_PS_MODE_DISABLED = 0,
            /** disable power save  for a given STA VDEV */
            WMI_STA_PS_MODE_ENABLED = 1,
        };

        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;

            /** Power save mode
             *
             * (see enum wmi_sta_ps_mode)
             */
            A_UINT32 sta_ps_mode;
        } wmi_sta_powersave_mode_cmd;

       enum wmi_csa_offload_en{
           WMI_CSA_OFFLOAD_DISABLE = 0,
           WMI_CSA_OFFLOAD_ENABLE = 1,
       };

       typedef struct{
          A_UINT32 vdev_id;
          A_UINT32 csa_offload_enable;
       } wmi_csa_offload_enable_cmd;

       typedef struct{
          A_UINT32 vdev_id;
          wmi_channel chan;
       } wmi_csa_offload_chanswitch_cmd;
        /**
         * This parameter controls the policy for retrieving frames from AP while the
         * STA is in sleep state.
         *
         * Only takes affect if the sta_ps_mode is enabled
         */
        enum wmi_sta_ps_param_rx_wake_policy {
            /* Wake up when ever there is an  RX activity on the VDEV. In this mode
             * the Power save SM(state machine) will come out of sleep by either
             * sending null frame (or) a data frame (with PS==0) in response to TIM
             * bit set in the received beacon frame from AP.
             */
            WMI_STA_PS_RX_WAKE_POLICY_WAKE = 0,

            /* Here the power save state machine will not wakeup in response to TIM
             * bit, instead it will send a PSPOLL (or) UASPD trigger based on UAPSD
             * configuration setup by WMISET_PS_SET_UAPSD  WMI command.  When all
             * access categories are delivery-enabled, the station will send a UAPSD
             * trigger frame, otherwise it will send a PS-Poll.
             */
            WMI_STA_PS_RX_WAKE_POLICY_POLL_UAPSD = 1,
        };

        /** Number of tx frames/beacon  that cause the power save SM to wake up.
         *
         * Value 1 causes the SM to wake up for every TX. Value 0 has a special
         * meaning, It will cause the SM to never wake up. This is useful if you want
         * to keep the system to sleep all the time for some kind of test mode . host
         * can change this parameter any time.  It will affect at the next tx frame.
         */
        enum wmi_sta_ps_param_tx_wake_threshold {
            WMI_STA_PS_TX_WAKE_THRESHOLD_NEVER = 0,
            WMI_STA_PS_TX_WAKE_THRESHOLD_ALWAYS = 1,

            /* Values greater than one indicate that many TX attempts per beacon
             * interval before the STA will wake up
             */
        };

        /**
         * The maximum number of PS-Poll frames the FW will send in response to
         * traffic advertised in TIM before waking up (by sending a null frame with PS
         * = 0). Value 0 has a special meaning: there is no maximum count and the FW
         * will send as many PS-Poll as are necessary to retrieve buffered BU. This
         * parameter is used when the RX wake policy is
         * WMI_STA_PS_RX_WAKE_POLICY_POLL_UAPSD and ignored when the RX wake
         * policy is WMI_STA_PS_RX_WAKE_POLICY_WAKE.
         */
        enum wmi_sta_ps_param_pspoll_count {
            WMI_STA_PS_PSPOLL_COUNT_NO_MAX = 0,
            /* Values greater than 0 indicate the maximum numer of PS-Poll frames FW
             * will send before waking up.
             */
        };

        /*
         * This will include the delivery and trigger enabled state for every AC.
         * This is the negotiated state with AP. The host MLME needs to set this based
         * on AP capability and the state Set in the association request by the
         * station MLME.Lower 8 bits of the value specify the UAPSD configuration.
         */
        #define WMI_UAPSD_AC_TYPE_DELI 0
        #define WMI_UAPSD_AC_TYPE_TRIG 1

        #define WMI_UAPSD_AC_BIT_MASK(ac,type) (type ==  WMI_UAPSD_AC_TYPE_DELI)?(1<<(ac<<1)):(1<<((ac<<1)+1))

        enum wmi_sta_ps_param_uapsd {
            WMI_STA_PS_UAPSD_AC0_DELIVERY_EN = (1 << 0),
            WMI_STA_PS_UAPSD_AC0_TRIGGER_EN  = (1 << 1),
            WMI_STA_PS_UAPSD_AC1_DELIVERY_EN = (1 << 2),
            WMI_STA_PS_UAPSD_AC1_TRIGGER_EN  = (1 << 3),
            WMI_STA_PS_UAPSD_AC2_DELIVERY_EN = (1 << 4),
            WMI_STA_PS_UAPSD_AC2_TRIGGER_EN  = (1 << 5),
            WMI_STA_PS_UAPSD_AC3_DELIVERY_EN = (1 << 6),
            WMI_STA_PS_UAPSD_AC3_TRIGGER_EN  = (1 << 7),
        };

        enum wmi_sta_powersave_param {
            /**
             * Controls how frames are retrievd from AP while STA is sleeping
             *
             * (see enum wmi_sta_ps_param_rx_wake_policy)
             */
            WMI_STA_PS_PARAM_RX_WAKE_POLICY = 0,

            /**
             * The STA will go active after this many TX
             *
             * (see enum wmi_sta_ps_param_tx_wake_threshold)
             */
            WMI_STA_PS_PARAM_TX_WAKE_THRESHOLD = 1,

            /**
             * Number of PS-Poll to send before STA wakes up
             *
             * (see enum wmi_sta_ps_param_pspoll_count)
             *
             */
            WMI_STA_PS_PARAM_PSPOLL_COUNT = 2,

            /**
             * TX/RX inactivity time in msec before going to sleep.
             *
             * The power save SM will monitor tx/rx activity on the VDEV, if no
             * activity for the specified msec of the parameter the Power save SM will
             * go to sleep.
             */
            WMI_STA_PS_PARAM_INACTIVITY_TIME = 3,

            /**
             * Set uapsd configuration.
             *
             * (see enum wmi_sta_ps_param_uapsd)
             */
            WMI_STA_PS_PARAM_UAPSD = 4,
        };

        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;
            /** station power save parameter (see enum wmi_sta_powersave_param) */
            A_UINT32 param;
            A_UINT32 value;
        } wmi_sta_powersave_param_cmd;

         /** No MIMO power save */
        #define WMI_STA_MIMO_PS_MODE_DISABLE
         /** mimo powersave mode static*/
        #define WMI_STA_MIMO_PS_MODE_STATIC
         /** mimo powersave mode dynamic */
        #define WMI_STA_MIMO_PS_MODE_DYNAMI

        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;
            /** mimo powersave mode as defined above */
            A_UINT32 mimo_pwrsave_mode;
        } wmi_sta_mimo_ps_mode_cmd;


        /** U-APSD configuration of peer station from (re)assoc request and TSPECs */
        enum wmi_ap_ps_param_uapsd {
            WMI_AP_PS_UAPSD_AC0_DELIVERY_EN = (1 << 0),
            WMI_AP_PS_UAPSD_AC0_TRIGGER_EN  = (1 << 1),
            WMI_AP_PS_UAPSD_AC1_DELIVERY_EN = (1 << 2),
            WMI_AP_PS_UAPSD_AC1_TRIGGER_EN  = (1 << 3),
            WMI_AP_PS_UAPSD_AC2_DELIVERY_EN = (1 << 4),
            WMI_AP_PS_UAPSD_AC2_TRIGGER_EN  = (1 << 5),
            WMI_AP_PS_UAPSD_AC3_DELIVERY_EN = (1 << 6),
            WMI_AP_PS_UAPSD_AC3_TRIGGER_EN  = (1 << 7),
        };

        /** U-APSD maximum service period of peer station */
        enum wmi_ap_ps_peer_param_max_sp {
            WMI_AP_PS_PEER_PARAM_MAX_SP_UNLIMITED = 0,
            WMI_AP_PS_PEER_PARAM_MAX_SP_2 = 1,
            WMI_AP_PS_PEER_PARAM_MAX_SP_4 = 2,
            WMI_AP_PS_PEER_PARAM_MAX_SP_6 = 3,

            /* keep last! */
            MAX_WMI_AP_PS_PEER_PARAM_MAX_SP,
        };

        enum wmi_ap_ps_peer_param_wnm_sleep {
            WMI_AP_PS_PEER_PARAM_WNM_SLEEP_ENABLE,
            WMI_AP_PS_PEER_PARAM_WNM_SLEEP_DISABLE,
        };

        /**
         * AP power save parameter
         * Set a power save specific parameter for a peer station
         */
        enum wmi_ap_ps_peer_param {
            /** Set uapsd configuration for a given peer.
             *
             * This will include the delivery and trigger enabled state for every AC.
             * The host  MLME needs to set this based on AP capability and stations
             * request Set in the association request  received from the station.
             *
             * Lower 8 bits of the value specify the UAPSD configuration.
             *
             * (see enum wmi_ap_ps_param_uapsd)
             * The default value is 0.
             */
            WMI_AP_PS_PEER_PARAM_UAPSD = 0,

            /**
             * Set the service period for a UAPSD capable station
             *
             * The service period from wme ie in the (re)assoc request frame.
             *
             * (see enum wmi_ap_ps_peer_param_max_sp)
             */
            WMI_AP_PS_PEER_PARAM_MAX_SP = 1,

            /** Time in seconds for aging out buffered frames for STA in power save */
            WMI_AP_PS_PEER_PARAM_AGEOUT_TIME = 2,

            /** Specify frame types that are considered SIFS RESP trigger frame */
            WMI_AP_PS_PEER_PARAM_SIFS_RESP_FRMTYPE = 3,

            /** Specifies the trigger state of TID. Valid only for UAPSD frame type  */
            WMI_AP_PS_PEER_PARAM_SIFS_RESP_UAPSD = 4,

            /** Specifies the WNM sleep state of a STA */
            WMI_AP_PS_PEER_PARAM_WNM_SLEEP = 5,
        };

        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;
            /** peer MAC address */
            wmi_mac_addr peer_macaddr;
            /** AP powersave param (see enum wmi_ap_ps_peer_param) */
            A_UINT32 param;
            /** AP powersave param value */
            A_UINT32 value;
        } wmi_ap_ps_peer_cmd;

        /** Configure peer station 11v U-APSD coexistance
         *
         * Two parameters from uaspd coexistence ie info (as specified in 11v) are
         * sent down to FW along with this command.
         *
         * The semantics of these fields are described in the following text extracted
         * from 802.11v.
         *
         * ---  If the non-AP STA specified a non-zero TSF 0 Offset value in the
         *      U-APSD Coexistence element, the AP should not transmit frames to the
         *      non-AP STA outside of the U-APSD Coexistence Service Period, which
         *      begins when the AP receives the U-APSD trigger frame and ends after
         *      the transmission period specified by the result of the following
         *      calculation:
         *
         *          End of transmission period = T + (Interval . ((T . TSF 0 Offset) mod Interval))
         *
         *      Where T is the time the U-APSD trigger frame was received at the AP
         *      Interval is the UAPSD Coexistence element Duration/Interval field
         *      value (see 7.3.2.91) or upon the successful transmission of a frame
         *      with EOSP bit set to 1, whichever is earlier.
         *
         *
         * ---  If the non-AP STA specified a zero TSF 0 Offset value in the U-APSD
         *      Coexistence element, the AP should not transmit frames to the non-AP
         *      STA outside of the U-APSD Coexistence Service Period, which begins
         *      when the AP receives a U-APSD trigger frame and ends after the
         *      transmission period specified by the result of the following
         *      calculation: End of transmission period = T + Duration
         */
        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;
            /** peer MAC address */
            wmi_mac_addr peer_macaddr;
            /** Enable U-APSD coexistence support for this peer
             *
             * 0 -> disabled (default)
             * 1 -> enabled
             */
            A_UINT32 enabled;
            /** Duration/Interval as defined by 11v U-ASPD coexistance */
            A_UINT32 duration_interval;
            /** Upper 32 bits of 64-bit TSF offset */
            A_UINT32 tsf_offset_high;
            /** Lower 32 bits of 64-bit TSF offset */
            A_UINT32 tsf_offset_low;
        } wmi_ap_powersave_peer_uapsd_coex_cmd;


        /* For legacy Peregrine / Swift: 128 clients = 4 words */
        #define WMI_TIM_BITMAP_ARRAY_SIZE_LEGACY 4
        /*
         * For current targets:
         * b0 is reserved for multicast; use 17 words so we have enough
         * bits to support 512 client stations
         */
        #define WMI_TIM_BITMAP_ARRAY_SIZE_FULL 17

        #define WMI_TIM_BITMAP_ARRAY_SIZE WMI_TIM_BITMAP_ARRAY_SIZE_FULL

        typedef struct {
            /** TIM bitmap len (in bytes)*/
            A_UINT32 tim_len;
            /** TIM Partial Virtual Bitmap */
            A_UINT32 tim_mcast;
            A_UINT32 tim_bitmap[WMI_TIM_BITMAP_ARRAY_SIZE];
            A_UINT32 tim_changed;
            A_UINT32 tim_num_ps_pending;
        } wmi_tim_info;

        typedef struct {
            /** Flag to enable quiet period IE support */
            A_UINT32   is_enabled;
            /** Quiet start */
            A_UINT32   tbttcount;
            /** Beacon intervals between quiets*/
            A_UINT32   period;
            /** TUs of each quiet*/
            A_UINT32   duration;
            /** TUs of from TBTT of quiet start*/
            A_UINT32   offset;
        } wmi_quiet_info;

#define WMI_P2P_MAX_NOA_DESCRIPTORS 1	/* Maximum number of NOA Descriptors supported */

        typedef struct {
          	/** Bit  0:		Flag to indicate an update in NOA schedule
           	 *  Bits 7-1:	Reserved
           	 *  Bits 15-8:	Index (identifies the instance of NOA sub element)
           	 *  Bit  16: 	Opp PS state of the AP
           	 * 	Bits 23-17:	Ctwindow in TUs
           	 * 	Bits 31-24:	Number of NOA descriptors
           	 */
           	A_UINT32	noa_attributes;
           	wmi_p2p_noa_descriptor	noa_descriptors[WMI_P2P_MAX_NOA_DESCRIPTORS];
        }wmi_p2p_noa_info;


#define	WMI_UNIFIED_NOA_ATTR_MODIFIED		0x1
#define	WMI_UNIFIED_NOA_ATTR_MODIFIED_S		0

#define WMI_UNIFIED_NOA_ATTR_IS_MODIFIED(hdr)                   	\
			WMI_F_MS((hdr)->noa_attributes, WMI_UNIFIED_NOA_ATTR_MODIFIED)

#define WMI_UNIFIED_NOA_ATTR_MODIFIED_SET(hdr)                  	\
            WMI_F_RMW((hdr)->noa_attributes, 0x1,                	\
            	WMI_UNIFIED_NOA_ATTR_MODIFIED);

#define	WMI_UNIFIED_NOA_ATTR_INDEX			0xff00
#define	WMI_UNIFIED_NOA_ATTR_INDEX_S		8

#define WMI_UNIFIED_NOA_ATTR_INDEX_GET(hdr)                        	\
            WMI_F_MS((hdr)->noa_attributes, WMI_UNIFIED_NOA_ATTR_INDEX)

#define WMI_UNIFIED_NOA_ATTR_INDEX_SET(hdr, v)                      \
            WMI_F_RMW((hdr)->noa_attributes, (v) & 0xff,            \
            	WMI_UNIFIED_NOA_ATTR_INDEX);

#define	WMI_UNIFIED_NOA_ATTR_OPP_PS			0x10000
#define	WMI_UNIFIED_NOA_ATTR_OPP_PS_S		16

#define WMI_UNIFIED_NOA_ATTR_OPP_PS_GET(hdr)                         \
            WMI_F_MS((hdr)->noa_attributes, WMI_UNIFIED_NOA_ATTR_OPP_PS)

#define WMI_UNIFIED_NOA_ATTR_OPP_PS_SET(hdr)                         \
            WMI_F_RMW((hdr)->noa_attributes, 0x1,                    \
            	WMI_UNIFIED_NOA_ATTR_OPP_PS);

#define	WMI_UNIFIED_NOA_ATTR_CTWIN			0xfe0000
#define	WMI_UNIFIED_NOA_ATTR_CTWIN_S		17

#define WMI_UNIFIED_NOA_ATTR_CTWIN_GET(hdr)                          \
            WMI_F_MS((hdr)->noa_attributes, WMI_UNIFIED_NOA_ATTR_CTWIN)

#define WMI_UNIFIED_NOA_ATTR_CTWIN_SET(hdr, v)                       \
            WMI_F_RMW((hdr)->noa_attributes, (v) & 0x7f,             \
            	WMI_UNIFIED_NOA_ATTR_CTWIN);

#define	WMI_UNIFIED_NOA_ATTR_NUM_DESC		0xff000000
#define	WMI_UNIFIED_NOA_ATTR_NUM_DESC_S		24

#define WMI_UNIFIED_NOA_ATTR_NUM_DESC_GET(hdr)                       \
            WMI_F_MS((hdr)->noa_attributes, WMI_UNIFIED_NOA_ATTR_NUM_DESC)

#define WMI_UNIFIED_NOA_ATTR_NUM_DESC_SET(hdr, v)                    \
            WMI_F_RMW((hdr)->noa_attributes, (v) & 0xff,             \
            	WMI_UNIFIED_NOA_ATTR_NUM_DESC);
        typedef struct {
            /** TIM info */
            wmi_tim_info tim_info;
            /** P2P NOA info */
            wmi_p2p_noa_info p2p_noa_info;
            /* TBD: More info elements to be added later */
        } wmi_bcn_info;

        typedef struct {
            /** bitmap identifying the VDEVs, generated by the caller */
            A_UINT32 vdev_map;
            /** bcn info for each VDEV set in the vdev_map arranged as a list */
            wmi_bcn_info bcn_info[1];
        } wmi_host_swba_event;

        typedef struct {
            /** vdev_id identifying the VDEV for which FILS should be generated */
            A_UINT32 vdev_id;
            /** time (in TU) at which current FILS Discovery frame is scheduled for Tx */
            A_UINT32 fils_tt;
            /** next TBTT time (in TU) for this vdev  */
            A_UINT32 tbtt;
        } wmi_host_swfda_event;

        #define WMI_MAX_AP_VDEV 16


        typedef struct {
            /** bimtap of VDEVs that has tbtt offset updated */
            A_UINT32 vdev_map;
            /** tbtt offset list in the order of the LSB to MSB in the vdev_map bitmap */
            A_UINT32 tbttoffset_list[WMI_MAX_AP_VDEV];
        } wmi_tbtt_offset_event;

        enum wmi_peer_type {
            /** Generic/Non-BSS/Self Peer */
            WMI_PEER_TYPE_DEFAULT = 0,
            /** Peer is BSS Peer entry - STA VDEV: peer of AP,
             *  AP VDEV: self peer representing BSS, IBSS VDEV: peer representing BSS */
            WMI_PEER_TYPE_BSS = 1,
            /* Peer is a TDLS Peer */
            WMI_PEER_TYPE_TDLS = 2,
            /* Host <-> Target Peer type is assigned up to 127 */
            WMI_PEER_TYPE_HOST_MAX = 127,
            /* Reserved from 128 - 255 for target internal use */
        };

        /* Peer Specific commands and events */
        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;
            /** peer MAC address */
            wmi_mac_addr peer_macaddr;
            /** Peer type as in wmi_peer_type */
            A_UINT32 peer_type;
        } wmi_peer_create_cmd;

        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;
            /** peer MAC address */
            wmi_mac_addr peer_macaddr;
        } wmi_peer_delete_cmd;

        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;
            /** peer MAC address */
            wmi_mac_addr peer_macaddr;
            /** tid bitmap identifying the tids to flush */
            A_UINT32 peer_tid_bitmap;
        } wmi_peer_flush_tids_cmd;

        typedef struct {
            /** rate mode . 0: disable fixed rate (auto rate)
             *   1: legacy (non 11n) rate  specified as ieee rate 2*Mbps
             *   2: ht20 11n rate  specified as mcs index
             *   3: ht40 11n rate  specified as mcs index
             */
            A_UINT32  rate_mode;
             /** 4 rate values for 4 rate series. series 0 is stored in byte 0 (LSB)
              *  and series 3 is stored at byte 3 (MSB) */
            A_UINT32  rate_series;
             /** 4 retry counts for 4 rate series. retry count for rate 0 is stored in byte 0 (LSB)
              *  and retry count for rate 3 is stored at byte 3 (MSB) */
            A_UINT32  rate_retries;
        } wmi_fixed_rate;

        typedef struct {
            /** unique id identifying the VDEV, generated by the caller */
            A_UINT32 vdev_id;
            /** peer MAC address */
            wmi_mac_addr peer_macaddr;
            /** fixed rate */
            wmi_fixed_rate peer_fixed_rate;
        } wmi_peer_fixed_rate_cmd;

        #define WMI_MGMT_TID    17

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
} wmi_addba_clear_resp_cmd;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /** Tid number */
    A_UINT32 tid;
    /** Buffer/Window size*/
    A_UINT32 buffersize;
} wmi_addba_send_cmd;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /** Tid number */
    A_UINT32 tid;
    /** Is Initiator */
    A_UINT32 initiator;
    /** Reason code */
    A_UINT32 reasoncode;
} wmi_delba_send_cmd;

typedef struct {
    /** unique id identifying the vdev, generated by the caller */
    A_UINT32 vdev_id;
    /** peer mac address */
    wmi_mac_addr peer_macaddr;
    /** Tid number */
    A_UINT32 tid;
    /** status code */
    A_UINT32 statuscode;
} wmi_addba_setresponse_cmd;

typedef struct {
    /** unique id identifying the vdev, generated by the caller */
    A_UINT32 vdev_id;
    /** peer mac address */
    wmi_mac_addr peer_macaddr;
    /** Tid number */
    A_UINT32 tid;
} wmi_send_singleamsdu_cmd;

/** mimo powersave state */
#define WMI_PEER_MIMO_PS_STATE                          0x1
/** enable/disable AMPDU . initial value (enabled) */
#define WMI_PEER_AMPDU                                  0x2
/** authorize/unauthorize peer. initial value is unauthorized (0)  */
#define WMI_PEER_AUTHORIZE                              0x3
/** peer channel bandwidth */
#define WMI_PEER_CHWIDTH                                0x4
/** peer NSS */
#define WMI_PEER_NSS                                    0x5
/** USE 4 ADDR */
#define WMI_PEER_USE_4ADDR                              0x6
/** Enable extended peer stats */
#define WMI_PEER_EXT_STATS_ENABLE                       0x7
/*Use FIXED Pwr */
#define WMI_PEER_USE_FIXED_PWR                          0x8
/* Set peer fixed rate */
#define WMI_PEER_PARAM_FIXED_RATE                       0x9
/* Whitelist peer TIDs */
#define WMI_PEER_SET_MU_WHITELIST                       0x10

/* for debugging purpose */
#define WMI_PEER_DEBUG                                  0xa

/* peer NSS for VHT160 - Extended NSS support */
#define WMI_PEER_NSS_VHT160                             0xb
/* peer NSS for VHT160 - Extended NSS support */
#define WMI_PEER_NSS_VHT80_80                           0xc


/* DEBUG COMMANDS - PEER_DEBUG sub commands */
#define WMI_DBGCMD_DISPLAY_TID_STATS                    0x1
#define WMI_DBGCMD_FTID_SEND_DELBA                      0x2
#define WMI_DBGCMD_FTID                                 0x3
#define WMI_DBGCMD_FTID_RETRY_FRAMES                    0x4
#define WMI_DBGCMD_KICKOUT_STA                          0x5
#define WMI_DBGCMD_TRIGGER_BA_EVENT                     0x6
#define WMI_DBGCMD_RESET_PN                             0x7
#define WMI_DBGCMD_SEND_BAR                             0x8

/** mimo ps values for the parameter WMI_PEER_MIMO_PS_STATE  */
#define WMI_PEER_MIMO_PS_NONE                          0x0
#define WMI_PEER_MIMO_PS_STATIC                        0x1
#define WMI_PEER_MIMO_PS_DYNAMIC                       0x2

typedef enum {
	e_peer_channel_width_20_MHz = 0,
	e_peer_channel_width_40_MHz,
	e_peer_channel_width_80_MHz,
	e_peer_channel_width_160_MHz,
	e_peer_channel_width_invalid,
} peer_channel_width_t;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /** parameter id   */
    A_UINT32 param_id;
    /** parametr value */
    A_UINT32 param_value;
} wmi_peer_set_param_cmd;

#define MAX_SUPPORTED_RATES 128

typedef struct {
    /** total number of rates */
    A_UINT32 num_rates;
    /**
     * rates (each 8bit value) packed into a 32 bit word.
     * the rates are filled from least significant byte to most
     * significant byte.
     */
    A_UINT32 rates[(MAX_SUPPORTED_RATES/4)+1];
} wmi_rate_set;

/* NOTE: It would bea good idea to represent the Tx MCS
 * info in one word and Rx in another word. This is split
 * into multiple words for convenience
 */
typedef struct {
    A_UINT32 rx_max_rate; /* Max Rx data rate */
    A_UINT32 rx_mcs_set;  /* Negotiated RX VHT rates */
    A_UINT32 tx_max_rate; /* Max Tx data rate */
    A_UINT32 tx_mcs_set;  /* Negotiated TX VHT rates */
    A_UINT32 tx_max_mcs_nss;  /* b0-b3: max mcs idx; b4-b7: max nss */
}wmi_vht_rate_set;

typedef struct {
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /** legacy rate set */
    wmi_rate_set peer_legacy_rates;
    /** ht rate set */
    wmi_rate_set peer_ht_rates;
}   wmi_peer_set_rates_cmd;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    A_UINT32     callback_enable;
} wmi_peer_set_q_empty_callback_cmd;
/*
 * IMPORTANT: Make sure the bit definitions here are consistent
 * with the ni_flags definitions in wlan_peer.h
 */
#define WMI_PEER_AUTH           0x00000001  /* Authorized for data */
#define WMI_PEER_QOS            0x00000002  /* QoS enabled */
#define WMI_PEER_NEED_PTK_4_WAY 0x00000004  /* Needs PTK 4 way handshake for authorization */
#define WMI_PEER_NEED_GTK_2_WAY 0x00000010  /* Needs GTK 2 way handshake after 4-way handshake */
#define WMI_PEER_VHT_INTEROP_DISABLE_AMSDU_REQ 0x00000400
#define WMI_PEER_APSD           0x00000800  /* U-APSD power save enabled */
#define WMI_PEER_HT             0x00001000  /* HT enabled */
#define WMI_PEER_40MHZ          0x00002000  /* 40MHz enabld */
#define WMI_PEER_STBC           0x00008000  /* STBC Enabled */
#define WMI_PEER_LDPC           0x00010000  /* LDPC ENabled */
#define WMI_PEER_DYN_MIMOPS     0x00020000  /* Dynamic MIMO PS Enabled */
#define WMI_PEER_STATIC_MIMOPS  0x00040000  /* Static MIMO PS enabled */
#define WMI_PEER_SPATIAL_MUX    0x00200000  /* SM Enabled */
#define WMI_PEER_VHT            0x02000000  /* VHT Enabled */
#define WMI_PEER_80MHZ          0x04000000  /* 80MHz enabld */
#define WMI_PEER_VHT_2G         0x08000000  /* VHT Enabled in 2G */
#define WMI_PEER_PMF_ENABLED    0x10000000  /* Related to IEEE80211_FC1_WEP. When PMF bit enabled, management frames to be encrypted */
#define WMI_PEER_160MHZ         0x20000000  /* 160MHZ enabled */
#define WMI_PEER_VHT_INTEROP_DISABLE_AMSDU_RESP 0x40000000
#define WMI_PEER_AMSDU_DISABLE  0x80000000

/**
 * Peer rate capabilities.
 *
 * This is of interest to the ratecontrol
 * module which resides in the firmware. The bit definitions are
 * consistent with that defined in if_athrate.c.
 *
 * @todo
 * Move this to a common header file later so there is no need to
 * duplicate the definitions or maintain consistency.
 */
#define WMI_RC_DS_FLAG          0x01    /* Dual stream flag */
#define WMI_RC_CW40_FLAG        0x02    /* CW 40 */
#define WMI_RC_SGI_FLAG         0x04    /* Short Guard Interval */
#define WMI_RC_HT_FLAG          0x08    /* HT */
#define WMI_RC_RTSCTS_FLAG      0x10    /* RTS-CTS */
#define WMI_RC_TX_STBC_FLAG     0x20    /* TX STBC */
#define WMI_RC_RX_STBC_FLAG     0xC0    /* RX STBC ,2 bits */
#define WMI_RC_RX_STBC_FLAG_S   6       /* RX STBC ,2 bits */
#define WMI_RC_WEP_TKIP_FLAG    0x100   /* WEP/TKIP encryption */
#define WMI_RC_TS_FLAG          0x200   /* Three stream flag */
#define WMI_RC_UAPSD_FLAG       0x400   /* UAPSD Rate Control */

typedef struct {
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /** VDEV id */
    A_UINT32 vdev_id;
    /** assoc = 1 reassoc = 0 */
    A_UINT32 peer_new_assoc;
    /** peer associd (16 bits) */
    A_UINT32 peer_associd;
    /** peer station flags: see definition above */
    A_UINT32 peer_flags;
    /** negotiated capabilities (lower 16 bits)*/
    A_UINT32 peer_caps;
    /** Listen interval */
    A_UINT32 peer_listen_intval;
    /** HT capabilties of the peer */
    A_UINT32 peer_ht_caps;
    /** maximum rx A-MPDU length */
    A_UINT32 peer_max_mpdu;
    /** mpdu density of the peer in usec(0 to 16) */
    A_UINT32 peer_mpdu_density;
    /** peer rate capabilties see flags above */
    A_UINT32 peer_rate_caps;
    /** negotiated legacy rate set */
    wmi_rate_set peer_legacy_rates;
    /** negotiated ht rate set */
    wmi_rate_set peer_ht_rates;
    /** num spatial streams */
    A_UINT32 peer_nss;
    /** VHT capabilties of the peer */
    A_UINT32 peer_vht_caps;
    /** phy mode */
    A_UINT32 peer_phymode;
    /** VHT capabilties of the peer */
    wmi_vht_rate_set peer_vht_rates;
    /**
     * Bitmap providing QCA proprietary mapping of bandwidths to max Rx NSS
     * for this peer.
     * This is required since 802.11 standard currently facilitates peer to be
     * able to advertise only a single max Rx NSS value across all bandwidths.
     * Some QCA chipsets might need to be able to advertise a different max
     * Rx NSS value for 160 MHz, than that for 80 MHz and lower.
     *
     *  bit[2:0] : Represents value of Rx NSS for VHT 160 MHz
     *  bit[5:3] : Represents value of Rx NSS for VHT 80_80 MHz - Extended NSS
     *  support
     *  bit[30:6]: Reserved
     *  bit[31]  : MSB(0/1): 1 in case of valid data else all bits will be set
     *             to 0 by host
     */
    A_UINT32 peer_bw_rxnss_override;
} wmi_peer_assoc_complete_cmd;

#define    WMI_SIFS_RESP_PSPOLL     0x1
#define    WMI_SIFS_RESP_UAPSD      0x2
#define    WMI_SIFS_RESP_QBST_EXP   0x4
#define    WMI_SIFS_RESP_QBST_DATA  0x8
#define    WMI_SIFS_RESP_QBST_BAR   0x10
/* WDS Entry Flags */
#define WMI_WDS_FLAG_STATIC    0x1    /* Disable aging & learning */

typedef struct {
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /** wds MAC addr */
    wmi_mac_addr wds_macaddr;
    /* Flags associated with WDS entry */
    A_UINT32 flags;
} wmi_peer_add_wds_entry_cmd;

/*
 * Command to update an already existing WDS entry. Different address setting
 * combinations are possible.
 *
 * Valid wds and peer      -> Associated WDS entry peer ptr & flags will be updated.
 * Valid wds and null peer -> Associated WDS entry flags will be updated.
 * Null wds and Valid peer -> Flags will be updated for all WDS entries behind the peer.
 * Null wds and peer       -> Flags will be updated for all WDS entries.
 */
typedef struct {
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /** wds MAC addr */
    wmi_mac_addr wds_macaddr;
    /* Flags associated with WDS entry */
    A_UINT32 flags;
} wmi_peer_update_wds_entry_cmd;

typedef struct {
    /** wds MAC addr */
    wmi_mac_addr wds_macaddr;
} wmi_peer_remove_wds_entry_cmd;

typedef struct {
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /** wds MAC addr */
    wmi_mac_addr wds_macaddr;
    /* Values defined under WDS entry flags (WMI_WDS_FLAG defs) */
    A_UINT32 flags;
    A_UINT32 reserved;
} wmi_pdev_wds_entry;

typedef struct {
    A_UINT32 reserved[4]; /** reserved for future use */
    /* number of WDS entries */
    A_UINT32 num_entries;
    wmi_pdev_wds_entry wds_entry[1/*num_entries*/];
} wmi_pdev_wds_entry_dump_event;

/* WDS Delete flag */
#define WMI_WDS_DELETE_ALL_FLAG_STATIC 0x1 /* Delete only static entries */
 
/*
 * Command to delete already existing WDS entries. Different address setting
 * combinations are possible.
 *
 *  Valid Peer and Valid WDS -> WDS entry behind the peer will be deleted if it exists.
 *  Valid peer and NULL WDS  -> All WDS entries behind the peer will be deleted.
 *  NULL Peer and valid WDS  -> WDS entry will be deleted.
 *  NULL Peer and NULL  WDS  -> All WDS entries will be deleted.
 */
typedef struct {
    /** peer MAC addr */
    wmi_mac_addr peer_macaddr;
    /** wds MAC addr */
    wmi_mac_addr wds_macaddr;
    /* flags:
     * Refer to WMI_WDS_DELETE flag defs above for a specification of which
     * bits within this flags field are used for which flags.
     */
    A_UINT32 flags;
} wmi_peer_remove_all_wds_entries_cmd;

typedef struct {
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
} wmi_peer_q_empty_callback_event;



/**
 * Channel info WMI event
 */
typedef struct {
     /** Error code */
    A_UINT32 err_code;
   /** Channel freq */
    A_UINT32 freq;
    /** Read flags */
    A_UINT32 cmd_flags;
    /** Noise Floor value */
    A_UINT32 noise_floor;
    /** rx clear count */
    A_UINT32   rx_clear_count;
    /** cycle count */
    A_UINT32   cycle_count;
    /** channel tx power per range */
    A_UINT32 chan_tx_pwr_range;
    /** channel tx power per throughput*/
    A_UINT32 chan_tx_pwr_tp;
    /** rx frame count*/
    A_UINT32   rx_frame_count;
    /** BSS rx cycle count */
    A_UINT32 my_bss_rx_cycle_count;
    /** b-mode data rx time (units are microseconds) */
    A_UINT32 rx_11b_mode_data_duration;
    /** Total cycle counts in TX, not frames
     * cycle_counts to us can be calculated as
     * cycle_counts / mac_clk_MHz = us(microseconds)
     * This cycles to time conversion is applicable for all other
     * cycle counters in this struct.
     */
    A_UINT32   tx_frame_count;
    /** rx clear extension counter HT20 */
    A_UINT32   rx_clear_ext20_count;
    /** rx clear extension counter HT40 */
    A_UINT32   rx_clear_ext40_count;
    /** rx clear extension counter HT80 */
    A_UINT32   rx_clear_ext80_count;
} wmi_chan_info_event;

/**
 * Non wlan interference event
 */
typedef struct {
    A_UINT32 channel; /* either number or freq in mhz*/
} ath_dcs_cw_int;

/**
 *  WLAN IM stats from target to host
 *
 *  Below statistics are sent from target to host periodically.
 *  These are collected at target as long as target is running
 *  and target chip is not in sleep.
 *
 */
typedef struct _dcs_mib_stats  {
	/** listen time from ANI */
    A_INT32   listen_time;

	/** tx frame count, MAC_PCU_TX_FRAME_CNT_ADDRESS */
    A_UINT32   reg_tx_frame_cnt;

	/** rx frame count, MAC_PCU_RX_FRAME_CNT_ADDRESS */
    A_UINT32   reg_rx_frame_cnt;

	/** rx clear count, MAC_PCU_RX_CLEAR_CNT_ADDRESS */
    A_UINT32   reg_rxclr_cnt;

	/** total cycle counts MAC_PCU_CYCLE_CNT_ADDRESS */
    A_UINT32   reg_cycle_cnt;    		/* delta cycle count */

	/** extension channel 20 MHz rx clear count  */
	A_UINT32   reg_rxclr_ext_cnt;

	/** OFDM phy error counts, MAC_PCU_PHY_ERR_CNT_1_ADDRESS */
    A_UINT32   reg_ofdm_phyerr_cnt;

	/** CCK phy error count, MAC_PCU_PHY_ERR_CNT_2_ADDRESS */
    A_UINT32   reg_cck_phyerr_cnt;    	/* CCK err count since last reset, read from register */
} wlan_dcs_mib_stats_t;

/**
 *  wlan_dcs_im_tgt_stats
 *
 */
typedef struct _wlan_dcs_im_tgt_stats {
	/** current running TSF from the TSF-1 */
	A_UINT32  				reg_tsf32;

	/** Known last frame rssi, in case of multiple stations, if
	 *  and at different ranges, this would not gaurantee that
	 *  this is the least rssi.
	 */
    A_UINT32  				last_ack_rssi;

	/**  Sum of all the failed durations in the last one second interval.
	 */
    A_UINT32  				tx_waste_time;
	/** count how many times the hal_rxerr_phy is marked, in this
	 *  time period
     */
	A_UINT32				rx_time;
	A_UINT32 				phyerr_cnt;

	/** collected mib stats as explained in mib structure */
	wlan_dcs_mib_stats_t 	mib_stats;

    /** Channel noise floor (units are dBm) */
    A_INT32                chan_nf;
    /** BSS rx cycle count */
    A_UINT32                my_bss_rx_cycle_count;

    /** extension channel 40Mhz rxclear count */
    A_UINT32                reg_rxclr_ext40_cnt;

    /** extension channel 80Mhz rxclear count */
    A_UINT32                reg_rxclr_ext80_cnt;
} wlan_dcs_im_tgt_stats_t;

/**
 *  wmi_dcs_interference_event_t
 *
 *  Right now this is event and stats together. Partly this is
 *  because cw interference is handled in target now. This
 *  can be done at host itself, if we can carry the NF alone
 *  as a stats event. In future this would be done and this
 *  event would carry only stats.
 */
typedef struct {
	/**
     * Type of the event present, either the cw interference event, or the wlan_im stats
	 */
    A_UINT32    interference_type;      /* type of interference, wlan or cw */
    union {
		/** cw_interference event */
        ath_dcs_cw_int            cw_int;

		/** wlan im interfernce stats  */
        wlan_dcs_im_tgt_stats_t   wlan_stat;
    } int_event;
 } wmi_dcs_interference_event_t;

typedef struct wmi_wds_addr_event {
    A_UINT32 event_type[4];
    wmi_mac_addr peer_mac;
    wmi_mac_addr dest_mac;
} wmi_wds_addr_event_t;

enum wmi_peer_mcast_group_action {
    wmi_peer_mcast_group_action_add = 0,
    wmi_peer_mcast_group_action_del = 1
};
#define WMI_PEER_MCAST_GROUP_FLAG_ACTION_M   0x1
#define WMI_PEER_MCAST_GROUP_FLAG_ACTION_S   0
#define WMI_PEER_MCAST_GROUP_FLAG_WILDCARD_M 0x2
#define WMI_PEER_MCAST_GROUP_FLAG_WILDCARD_S 1
#define WMI_PEER_MCAST_GROUP_FLAG_SRC_FILTER_EXCLUDE_M 0x4 //flag to exclude an ip while filtering. set to exclude
#define WMI_PEER_MCAST_GROUP_FLAG_SRC_FILTER_EXCLUDE_S 2
#define WMI_PEER_MCAST_GROUP_FLAG_IPV6_M 0x8 //flag to say ipv4/ipv6. Will be set for ipv6
#define WMI_PEER_MCAST_GROUP_FLAG_IPV6_S 3
#define WMI_PEER_MCAST_GROUP_FLAG_DELETEALL_M 0x10 //delete all mcast table entries.
#define WMI_PEER_MCAST_GROUP_FLAG_DELETEALL_S 4
/* multicast group membership commands */
/* typedef  struct { //TODO:: */
typedef  union {
    /*TODO Take care of this while integrating mcast enahncement*/
    struct {
        A_UINT8 flags;
        A_UINT8 pad1;
        A_UINT8 ucast_mac_addr[6]; /* in network byte order */
        A_UINT8 mcast_ip_addr[16]; /* in network byte order */
    } fields;
    /*TODO -end*/
    A_UINT32 flags;
    A_UINT8 ucast_mac_addr[6]; /* in network byte order */
    /* for ipv4, bytes (12-15) should contain ip address and other lower bytes 0. ipv6 should have all bytes valid*/
    A_UINT8 mcast_ip_addr[16];
    /*for ipv6, all 16 bytes has to be valid; for ipv4 last 4 bytes(12-15) has to be valid, rest all 0s*/
    A_UINT8 mcast_ip_mask[16];/* zero out lower bytes if ipv4*/
    /* number of address filters - irrespective of ipv4/ipv6 addresses*/
    A_UINT8 num_filter_addr;
    /* this array should contain the src IPs that are to be filtered during find
       The array should be packed.
       If there are 2 ipv4 addresses, there should be 8 bytes and rest all 0s*/
    A_UINT8 filter_addr[64];     /* 16 ipv4 addresses or 4 ipv6 addresses */
    A_UINT8  vdev_id;  /* vdev of this mcast group */
} wmi_peer_mcast_group_cmd;

/** Offload Scan and Roaming related  commands */
/** The FW performs 2 different kinds of offload scans independent
 *  of host. One is Roam scan which is primarily performed  on a
 *  station VDEV after association to look for a better AP that
 *  the station VDEV can roam to. The second scan is connect scan
 *  which is mainly performed when the station is not associated
 *  and to look for a matching AP profile from a list of
 *  configured profiles. */

/**
 * WMI_ROAM_SCAN_MODE: Set Roam Scan mode
 *   the roam scan mode is one of the periodic, rssi change, both, none.
 *   None        : Disable Roam scan. No Roam scan at all.
 *   Periodic    : Scan periodically with a configurable period.
 *   Rssi change : Scan when ever rssi to current AP changes by the threshold value
 *                 set by WMI_ROAM_SCAN_RSSI_CHANGE_THRESHOLD command.
 *   Both        : Both of the above (scan when either period expires or rss to current AP changes by X amount)
 *
 */
typedef struct {
	A_UINT32 roam_scan_mode;
} wmi_roam_scan_mode;

#define WMI_ROAM_SCAN_MODE_NONE        0x0
#define WMI_ROAM_SCAN_MODE_PERIODIC    0x1
#define WMI_ROAM_SCAN_MODE_RSSI_CHANGE 0x2
#define WMI_ROAM_SCAN_MODE_BOTH        0x3

/**
 * WMI_ROAM_SCAN_RSSI_THRESHOLD : set scan rssi thresold
 *  scan rssi threshold is the rssi threshold below which the FW will start running Roam scans.
 * Applicable when WMI_ROAM_SCAN_MODE is not set to none.
 */
typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** roam scan rssi threshold */
    A_UINT32 roam_scan_rssi_thresh;
} wmi_roam_scan_rssi_threshold;

/**
 * WMI_ROAM_SCAN_PERIOD: period for roam scan.
 *  Applicable when the scan mode is Periodic or both.
 */
typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** roam scan period value */
    A_UINT32 roam_scan_period;
} wmi_roam_scan_period;

/**
 * WMI_ROAM_SCAN_RSSI_CHANGE_THRESHOLD : rssi delta to trigger the roam scan.
 *   Rssi change threshold used when mode is Rssi change (or) Both.
 *   The FW will run the roam scan when ever the rssi changes (up or down) by the value set by this parameter.
 *   Note scan is triggered based on the rssi threshold condition set by WMI_ROAM_SCAN_RSSI_THRESHOLD
 */
typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** roam scan rssi change threshold value */
    A_UINT32 roam_scan_rssi_change_thresh;
} wmi_roam_scan_rssi_change_threshold;


/** Authentication modes */
enum {
    WMI_AUTH_NONE   , /* no upper level auth */
    WMI_AUTH_OPEN   , /* open */
    WMI_AUTH_SHARED , /* shared-key */
    WMI_AUTH_8021X  , /* 802.1x */
    WMI_AUTH_AUTO   , /* Auto */
    WMI_AUTH_WPA    , /* WPA */
    WMI_AUTH_RSNA   , /* WPA2/RSNA */
    WMI_AUTH_CCKM   , /* CCK */
    WMI_AUTH_WAPI   ,/* WAPI */
};

typedef struct {
    /** authentication mode (defined above)  */
    A_UINT32               rsn_authmode;
    /** unicast cipher set */
    A_UINT32               rsn_ucastcipherset;
    /** mcast/group cipher set */
    A_UINT32               rsn_mcastcipherset;
    /** mcast/group management frames cipher set */
    A_UINT32               rsn_mcastmgmtcipherset;
} wmi_rsn_params;

/** looking for a wps enabled AP */
#define WMI_AP_PROFILE_FLAG_WPS    0x1
/** looking for a secure AP  */
#define WMI_AP_PROFILE_FLAG_CRYPTO 0x2

/** To match an open AP, the rs_authmode should be set to WMI_AUTH_NONE
 *  and WMI_AP_PROFILE_FLAG_CRYPTO should be clear.
 *  To match a WEP enabled AP, the rs_authmode should be set to WMI_AUTH_NONE
 *  and WMI_AP_PROFILE_FLAG_CRYPTO should be set .
 */

typedef struct {
    /** flags as defined above */
    A_UINT32  flags;
	/**
	 * rssi thresold value: the value of the the candidate AP should
	 * higher by this threshold than the rssi of the currrently associated AP.
	 */
	A_UINT32 rssi_threshold;
	/**
	 * ssid vlaue to be matched.
	 */
    wmi_ssid ssid;

	/**
	 * security params to be matched.
	 */
     wmi_rsn_params rsn_params;
} wmi_ap_profile;

/** Beacon filter wmi command info */

#define BCN_FLT_MAX_SUPPORTED_IES    256
#define BCN_FLT_MAX_ELEMS_IE_LIST    BCN_FLT_MAX_SUPPORTED_IES/32

typedef struct bss_bcn_stats {
    A_UINT32    vdev_id;
    A_UINT32    bss_bcnsdropped;
    A_UINT32    bss_bcnsdelivered;
}wmi_bss_bcn_stats_t;

typedef struct bcn_filter_stats {
    A_UINT32    bcns_dropped;
    A_UINT32    bcns_delivered;
    A_UINT32    activefilters;
    wmi_bss_bcn_stats_t bss_stats;
}wmi_bcnfilter_stats_t;

typedef struct wmi_add_bcn_filter_cmd {
   A_UINT32    vdev_id;
   A_UINT32    ie_map[BCN_FLT_MAX_ELEMS_IE_LIST];
}wmi_add_bcn_filter_cmd_t;

typedef struct wmi_rmv_bcn_filter_cmd {
    A_UINT32    vdev_id;
}wmi_rmv_bcn_filter_cmd_t;


#define WMI_BCN_SEND_DTIM_ZERO         1
#define WMI_BCN_SEND_DTIM_BITCTL_SET   2
#define WMI_BCN_SEND_NEXT_BCN_IS_DTIM  4
typedef struct wmi_bcn_send_from_host {
    A_UINT32 vdev_id;
    A_UINT32 data_len;
    A_UINT32 frag_ptr; /* Physical address of the frame */
    A_UINT32 virt_addr; /* virtual address of host bcn buffer */
    A_UINT32 frame_ctrl; /* farme ctrl to setup PPDU desc */
    A_UINT32 dtim_flag;   /* to control CABQ traffic */
    A_UINT32 bcn_antenna;   /* Antenna for beacon transmission */
} wmi_bcn_send_from_host_cmd_t;

typedef struct wmi_fd_send_from_host {
    A_UINT32 vdev_id;
    A_UINT32 data_len;
    A_UINT32 frag_ptr;   /* Physical address of the frame */
    A_UINT32 frame_ctrl; /* frame ctrl to setup PPDU desc */
} wmi_fd_send_from_host_cmd_t;

/* cmd to support bcn snd for all vaps at once */
typedef struct wmi_pdev_send_bcn {
    A_UINT32                       num_vdevs;
    wmi_bcn_send_from_host_cmd_t   bcn_cmd[0];
} wmi_pdev_send_bcn_cmd_t;

 /*
  * WMI_ROAM_AP_PROFILE:  AP profile of connected AP for roaming.
  */
typedef struct {
	/** id of AP criteria */
	A_UINT32 id;

    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;

    /** AP profile info */
    wmi_ap_profile ap_profile;

} wmi_roam_ap_profile;

/**
 * WMI_OFL_SCAN_ADD_AP_PROFILE: add an AP profile.
 */
typedef struct {
	/** id of AP criteria */
	A_UINT32 id;

    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;

    /** AP profile info */
    wmi_ap_profile ap_profile;

} wmi_ofl_scan_add_ap_profile;

/**
 * WMI_OFL_SCAN_REMOVE_AP_CRITERIA: remove an ap profile.
 */
typedef struct {
	/** id of AP criteria */
	A_UINT32 id;
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
} wmi_ofl_scan_remove_ap_profile;

/**
 * WMI_OFL_SCAN_PERIOD: period in msec for offload scan.
 *  0 will disable ofload scan and a very low value will perform a continous
 *  scan.
 */
typedef struct {
	/** offload scan period value, used for scans used when not connected */
	A_UINT32 ofl_scan_period;
} wmi_ofl_scan_period;



/** WMI_ROAM_EVENT: roam event triggering the host roam logic.
 * generated when ever a better AP is found in the recent roam scan (or)
 * when beacon miss is detected (or) when a DEAUTH/DISASSOC is received
 * from the current AP.
 */
typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
	/** reason for roam event */
	A_UINT32 reason;

} wmi_roam_event;

#define WMI_ROAM_REASON_BETTER_AP 0x1 /** found a better AP */
#define WMI_ROAM_REASON_BMISS     0x2 /** beacon miss detected */
#define WMI_ROAM_REASON_DEAUTH    0x2 /** deauth/disassoc received */

/** WMI_PROFILE_MATCH_EVENT: offload scan
 * generated when ever atleast one of the matching profiles is found
 * in recent NLO scan. no data is carried with the event.
 */

/** P2P specific commands */

/**
 * WMI_P2P_DEV_SET_DEVICE_INFO : p2p device info, which will be used by
 * FW to generate P2P IE tobe carried in probe response frames.
 * FW will respond to probe requests while in listen state.
 */
typedef struct {
    /* number of secondary device types,supported */
    A_UINT32 num_secondary_dev_types;
    /**
     * followed by 8 bytes of primary device id and
     * num_secondary_dev_types * 8 bytes of secondary device
     * id.
     */
} wmi_p2p_dev_set_device_info;

/** WMI_P2P_DEV_SET_DISCOVERABILITY: enable/disable discoverability
 *  state. if enabled, an active STA/AP will respond to P2P probe requests on
 *  the operating channel of the VDEV.
 */

typedef struct {
    /* 1:enable disoverability, 0:disable discoverability */
    A_UINT32 enable_discoverability;
}  wmi_p2p_set_discoverability;

/** WMI_P2P_GO_SET_BEACON_IE: P2P IE to be added to
 *  beacons generated by FW. used in FW beacon mode.
 *  the FW will add this IE to beacon in addition to the beacon/probe response
 *  template set by WMI_BCN_PRB_TMPL_CMDID command.
 */
typedef struct {
    A_UINT32 ie_buf_len;
    /*followed by  byte stream of ie data of length ie_buf_len */
}  wmi_p2p_go_set_beacon_ie;

/** WMI_P2P_GO_PROBE_RESP_IE: P2P IE to be added to
 *  probe response generated by FW. used in FW beacon mode.
 *  the FW will add this IE to probe response in addition to the beacon/probe response
 *  template set by WMI_BCN_PRB_TMPL_CMDID command.
 */
typedef struct {
    A_UINT32 ie_buf_len;
    /*followed by  byte stream of ie data of length ie_buf_len */
}  wmi_p2p_go_set_probe_resp_ie;

/** WMI_P2P_SET_VENDOR_IE_DATA_CMDID: Vendor specific P2P IE data, which will
 *  be used by the FW to parse the P2P NoA attribute in beacons, probe resposes
 *  and action frames received by the P2P Client.
 *  Note: This command is currently used only for Apple P2P implementation.
 */
typedef struct {
    /** OS specific P2P IE OUI (3 bytes) + OUI type (1 byte)  */
    A_UINT32 p2p_ie_oui_type;
    /** OS specific NoA Attribute ID */
    A_UINT32 p2p_noa_attribute;
}  wmi_p2p_set_vendor_ie_data_cmd;


typedef struct {
    A_UINT32 time32;     //upper 32 bits of time stamp
    A_UINT32 time0;      //lower 32 bits of time stamp
} A_TIME64;


/*---- start of TT report event definition ----*/

typedef struct  {
    A_UINT32 levelcount; /* count of each time TT entered this state */
    A_UINT32 dccount;    /* total number of duty cycles spent in this state. */
                          /* this number increments by one each time we are in this state and we finish one full duty cycle. */
} tt_level_stats_t;


typedef struct {
    tt_level_stats_t levstats[TT_LEVELS];   /* stats for each level */
    A_UINT32 temp;                          /* Temperature reading in celsius */
    A_UINT32 level;                         /* current level */
} tt_stats_t;

/*---- end of TT report event definition ----*/

typedef struct {
    /** peer mac address */
    wmi_mac_addr peer_macaddr;
} wmi_peer_sta_kickout_event;


typedef struct {
    wmi_mac_addr peer_macaddr;
    A_UINT32 peer_ps_state;
} wmi_peer_sta_ps_statechange_event;

#define WMI_WLAN_PROFILE_MAX_HIST     3
#define WMI_WLAN_PROFILE_MAX_BIN_CNT 32

typedef struct _wmi_wlan_profile_t {
    A_UINT32 id;
    A_UINT32 cnt;
    A_UINT32 tot;
    A_UINT32 min;
    A_UINT32 max;
    A_UINT32 hist_intvl;
    A_UINT32 hist[WMI_WLAN_PROFILE_MAX_HIST];
} wmi_wlan_profile_t;

typedef struct _wmi_wlan_profile_ctx_t {
    A_UINT32 tot; /* time in us */
    A_UINT32 tx_msdu_cnt;
    A_UINT32 tx_mpdu_cnt;
    A_UINT32 tx_ppdu_cnt;
    A_UINT32 rx_msdu_cnt;
    A_UINT32 rx_mpdu_cnt;
    A_UINT32 bin_count;
} wmi_wlan_profile_ctx_t;

#if defined(AR9888)
typedef enum {
   PROF_CPU_IDLE,
   PROF_PPDU_PROC,
   PROF_PPDU_POST,
   PROF_HTT_TX_INPUT,
   PROF_MSDU_ENQ,
   PROF_PPDU_POST_HAL,
   PROF_COMPUTE_TX_TIME,

   /* Add new ID's above this. */
   PROF_MAX_ID,
} profile_id_t;
#endif

/** Host-based rate-control related commands  */

/* NOTE:
 * The wmi_peer_rate_retry_sched_cmd struct / message is only used
 * for Peregrine-family targets.
 */
typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32     vdev_id;
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    A_UINT32     psdu_len    [NUM_DYN_BW * NUM_SCHED_ENTRIES_AR988X];
    A_UINT32     flags       [NUM_DYN_BW * NUM_SCHED_ENTRIES_AR988X];
    A_UINT32     rix         [NUM_DYN_BW * NUM_SCHED_ENTRIES_AR988X];
    A_UINT32     tpc         [NUM_DYN_BW * NUM_SCHED_ENTRIES_AR988X];
    A_UINT32     num_mpdus   [NUM_DYN_BW * NUM_SCHED_ENTRIES_AR988X];
    A_UINT32     antmask     [NUM_SCHED_ENTRIES_AR988X];
    A_UINT32     txbf_cv_ptr;
    A_UINT32     txbf_cv_len;
    A_UINT32     tries       [NUM_SCHED_ENTRIES_AR988X];
    A_UINT32     num_valid_rates;
    A_UINT32     paprd_mask;
    A_UINT32     rts_rix;
    A_UINT32     sh_pream;
    A_UINT32     min_spacing_1_4_us;
    A_UINT32     fixed_delims;
    A_UINT32     bw_in_service;
    A_UINT32     probe_rix;
}wmi_peer_rate_retry_sched_cmd;

typedef struct {
    wmi_wlan_profile_ctx_t profile_ctx;
#if defined(AR9888)
    wmi_wlan_profile_t profile_data[PROF_MAX_ID];
#else
    wmi_wlan_profile_t profile_data[WMI_WLAN_PROFILE_MAX_BIN_CNT];
#endif
}wmi_profile_stats_event;

typedef struct {
    A_UINT32 enable;
} wmi_wlan_profile_trigger_cmd;

typedef struct {
    A_UINT32 value;
} wmi_wlan_profile_get_prof_data_cmd;

typedef struct {
    A_UINT32 profile_id;
    A_UINT32 value;
} wmi_wlan_profile_set_hist_intvl_cmd;

typedef struct {
    A_UINT32 profile_id;
    A_UINT32 enable;
} wmi_wlan_profile_enable_profile_id_cmd;

typedef struct {
    A_UINT32 m_last_byte_of_mac_addr;
} wmi_wlan_peer_caching_cmd;

/*Wifi header is upto 26, LLC is 8, with 14 byte duplicate in 802.3 header, that's 26+8-14=20.
146-128=18. So this means it is converted to non-QoS header. Riva FW take care of the QOS/non-QOS
when comparing wifi header.*/
#define WOW_DEFAULT_BITMAP_PATTERN_SIZE_DWORD 37 //Convert WOW_DEFAULT_EVT_BUF_SIZE into Int32 size

#define WOW_DEFAULT_BITMASK_SIZE_DWORD        37

#define WOW_DEFAULT_MAGIG_PATTERN_MATCH_CNT  16





typedef struct wmi_wow_enable_command {
	A_UINT32 enable;
}wmi_wow_enable_command;




typedef struct WOW_MAGIC_PATTERN_CMD
{
	wmi_mac_addr macaddr;
}WOW_MAGIC_PATTERN_CMD;

typedef struct {
    A_UINT32        pattern_id;
    A_UINT32        pattern_type;
    union {
        WOW_BITMAP_PATTERN_T       bitmap;
        WOW_IPV4_SYNC_PATTERN_T    ipv4;
        WOW_IPV6_SYNC_PATTERN_T    ipv6;
        A_UINT32                   timeout;
    }pattern_info;
}WMI_WOW_ADD_PATTERN_CMD;

typedef struct {
    A_UINT32        pattern_id;
    A_UINT32        pattern_type;
}WMI_WOW_DEL_PATTERN_CMD;

typedef struct {
    A_UINT32    is_add;
    A_UINT32    event_bitmap;
}WMI_WOW_ADD_DEL_EVT_CMD;

typedef struct  wow_event_info_s {
	A_UINT32    vdev_id;
    A_UINT32    flag;                              /*This is current reserved.*/
    A_INT32     wake_reason;
    A_UINT32    data_len;
}WOW_EVENT_INFO;

typedef enum {
    WOW_EVENT_INFO_TYPE_PACKET = 0x0001,
    WOW_EVENT_INFO_TYPE_BITMAP,
    WOW_EVENT_INFO_TYPE_GTKIGTK,
}WOW_EVENT_INFO_TYPE;

typedef struct  wow_event_info_section_s {
    A_UINT32    data_type;
    A_UINT32    data_len;
}WOW_EVENT_INFO_SECTION;

typedef struct  wow_event_info_section_packet_s {
    A_UINT8     packet[WOW_DEFAULT_EVT_BUF_SIZE];
}WOW_EVENT_INFO_SECTION_PACKET;

typedef struct  wow_event_info_section_bitmap_s {
    A_UINT32    flag;                              /*This is current reserved.*/
    A_UINT32    value;                         /*This could be the pattern id for bitmap pattern.*/
    A_UINT32    org_len;                      /*The length of the orginal packet.*/
}WOW_EVENT_INFO_SECTION_BITMAP;
#define WMI_RXERR_CRC               0x01    /* CRC error on frame */
#define WMI_RXERR_DECRYPT           0x08    /* non-Michael decrypt error */
#define WMI_RXERR_MIC               0x10    /* Michael MIC decrypt error */
#define WMI_RXERR_KEY_CACHE_MISS    0x20    /* No/incorrect key matter in h/w */
#define WMI_RX_EXT_INFO             0x40    /* extension data (TSF) is added
                                             * after the uploaded beacon */

typedef enum {
    PKT_PWR_SAVE_PAID_MATCH =         0x0001,
    PKT_PWR_SAVE_GID_MATCH =          0x0002,
    PKT_PWR_SAVE_EARLY_TIM_CLEAR =    0x0004,
    PKT_PWR_SAVE_EARLY_DTIM_CLEAR =   0x0008,
    PKT_PWR_SAVE_EOF_PAD_DELIM =      0x0010,
    PKT_PWR_SAVE_MACADDR_MISMATCH =   0x0020,
    PKT_PWR_SAVE_DELIM_CRC_FAIL =     0x0040,
    PKT_PWR_SAVE_GID_NSTS_ZERO =      0x0080,
    PKT_PWR_SAVE_RSSI_CHECK =         0x0100,
    WMI_PKT_PWR_SAVE_MAX =            0x0200,
} WMI_PKT_PWR_SAVE_TYPE;

typedef struct {
    /* This structure is used to send Factory Test Mode [FTM] command
     * to firmware for integrated chips which are binary blobs.
     * data array variable is used to access binary blob.
     * One byte is to used insure this structure compiles on all platforms
     */
    A_UINT8 data[1];
}wmi_ftm_intg_cmd;

typedef struct {
    /* This structure is used to receive Factory Test Mode [FTM] event
     * from firmware to host for integrated chips which are binary blobs.
     */
    A_UINT8 data[1];
}wmi_ftm_intg_event;

#define WMI_MAX_NS_OFFLOADS           2
#define WMI_MAX_ARP_OFFLOADS          2

#define WMI_ARPOFF_FLAGS_VALID              (1 << 0)    /* the tuple entry is valid */
#define WMI_ARPOFF_FLAGS_MAC_VALID          (1 << 1)    /* the target mac address is valid */
#define WMI_ARPOFF_FLAGS_REMOTE_IP_VALID    (1 << 2)    /* remote IP field is valid */

typedef struct _WMI_IPV6_ADDR {
    A_UINT8    address[16];    /* IPV6 in Network Byte Order */
} WMI_IPV6_ADDR;


typedef struct {
    A_UINT32           flags;                   /* flags */
    A_UINT8           target_ipaddr[4];          /* IPV4 addresses of the local node*/
    A_UINT8           remote_ipaddr[4];        /* source address of the remote node requesting the ARP (qualifier) */
	wmi_mac_addr	  target_mac;              /* mac address for this tuple, if not valid, the local MAC is used */
} WMI_ARP_OFFLOAD_TUPLE;

#define WMI_NSOFF_FLAGS_VALID           (1 << 0)    /* the tuple entry is valid */
#define WMI_NSOFF_FLAGS_MAC_VALID       (1 << 1)    /* the target mac address is valid */
#define WMI_NSOFF_FLAGS_REMOTE_IP_VALID (1 << 2)    /* remote IP field is valid */

#define WMI_NSOFF_MAX_TARGET_IPS    2

typedef struct {
    A_UINT32           flags;                     /* flags */
    WMI_IPV6_ADDR     target_ipaddr[WMI_NSOFF_MAX_TARGET_IPS]; /* IPV6 target addresses of the local node  */
    WMI_IPV6_ADDR     solicitation_ipaddr;       /* multi-cast source IP addresses for receiving solicitations */
    WMI_IPV6_ADDR     remote_ipaddr;             /* address of remote node requesting the solicitation (qualifier) */
    wmi_mac_addr	  target_mac;               /* mac address for this tuple, if not valid, the local MAC is used */
} WMI_NS_OFFLOAD_TUPLE;

typedef struct {
    A_UINT32                flags;
    WMI_NS_OFFLOAD_TUPLE    ns_tuples[WMI_MAX_NS_OFFLOADS];
    WMI_ARP_OFFLOAD_TUPLE   arp_tuples[WMI_MAX_ARP_OFFLOADS];
} WMI_SET_ARP_NS_OFFLOAD_CMD;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /** Tid number */
    A_UINT32 tid;
    /** Initiator (1) or Responder (0) for this aggregation */
    A_UINT32 initiator;
    /** size of the negotiated window */
    A_UINT32 window_size;
    /** starting sequence number (only valid for initiator) */
    A_UINT32 ssn;
    /** timeout field represents the time to wait for Block Ack in
    *   initiator case and the time to wait for BAR in responder
    *   case. 0 represents no timeout. */
    A_UINT32 timeout;
    /* BA policy: immediate ACK (0) or delayed ACK (1) */
    A_UINT32 policy;
} wmi_peer_tid_addba_cmd;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /** Tid number */
    A_UINT32 tid;
    /** Initiator (1) or Responder (0) for this aggregation */
    A_UINT32 initiator;
} wmi_peer_tid_delba_cmd;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /** Tid number */
    A_UINT32 tid;
    /** Event status */
    A_UINT32 status;
} wmi_tx_addba_complete_event;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** peer MAC address */
    wmi_mac_addr peer_macaddr;
    /** Tid number */
    A_UINT32 tid;
    /** Event status */
    A_UINT32 status;
} wmi_tx_delba_complete_event;

typedef struct {
    /** unique id identifying the VDEV, generated by the caller */
    A_UINT32 vdev_id;
    /** MAC address used for installing   */
    wmi_mac_addr peer_macaddr;
    /** key index */
    A_UINT32 key_ix;
    /** key flags */
    A_UINT32 key_flags;
    /** Event status */
    A_UINT32 status;
} wmi_vdev_install_key_complete_event;

#define WMI_NLO_MAX_SSIDS    16
#define WMI_NLO_MAX_CHAN     48

#define WMI_NLO_CONFIG_STOP      (0x1 << 0)
#define WMI_NLO_CONFIG_START     (0x1 << 1)
#define WMI_NLO_CONFIG_RESET     (0x1 << 2)
#define WMI_NLO_CONFIG_SLOW_SCAN (0x1 << 4)
#define WMI_NLO_CONFIG_FAST_SCAN (0x1 << 5)

typedef struct wmi_nlo_ssid_param
{
	A_UINT32 valid;
	wmi_ssid ssid;
}wmi_nlo_ssid_param;

typedef struct wmi_nlo_enc_param
{
	A_UINT32 valid;
	A_UINT32 enc_type;
}wmi_nlo_enc_param;

typedef struct wmi_nlo_auth_param
{
	A_UINT32 valid;
	A_UINT32 auth_type;
}wmi_nlo_auth_param;

typedef struct nlo_configured_parameters {
    wmi_nlo_ssid_param ssid;
    wmi_nlo_enc_param enc_type;
    wmi_nlo_auth_param auth_type;
} nlo_configured_parameters;

typedef struct wmi_nlo_config {
    A_UINT32    flags;
    A_UINT32    vdev_id;
    A_UINT32    fast_scan_max_cycles;
    A_UINT32    active_dwell_time;
    A_UINT32    passive_dwell_time; /* PDT in msecs */
    A_UINT32    probe_bundle_size;
    A_UINT32    rest_time;  /* ART = IRT */
    A_UINT32    max_rest_time; /* Max value that can be reached after SBM */
    A_UINT32    scan_backoff_multiplier;  /* SBM */
    A_UINT32    fast_scan_period; /* SCBM */
    A_UINT32    slow_scan_period; /* specific to windows */
    A_UINT32    no_of_ssids;
    nlo_configured_parameters    nlo_list[WMI_NLO_MAX_SSIDS];
    A_UINT32    num_of_channels;
    A_UINT32    channel_list[WMI_NLO_MAX_CHAN];
} wmi_nlo_config_cmd;

typedef struct wmi_nlo_event
{
	A_UINT32 vdev_id;
}wmi_nlo_event;
#define GTK_OFFLOAD_OPCODE_MASK				0xFF000000
/** Enable GTK offload, and provided parameters KEK,KCK and replay counter values */
#define GTK_OFFLOAD_ENABLE_OPCODE			0x01000000
/** Disable GTK offload */	
#define GTK_OFFLOAD_DISABLE_OPCODE			0x02000000
/** Read GTK offload parameters, generates WMI_GTK_OFFLOAD_STATUS_EVENT */	
#define GTK_OFFLOAD_REQUEST_STATUS_OPCODE	0x04000000
enum wmi_chatter_mode {
    /* Chatter enter/exit happens
     * automatically based on preset
     * params
     */
    WMI_CHATTER_MODE_AUTO,
    /* Chatter enter is triggered
     * manually by the user
     */
    WMI_CHATTER_MODE_MANUAL_ENTER,
    /* Chatter exit is triggered
     * manually by the user
     */
    WMI_CHATTER_MODE_MANUAL_EXIT,
    /* Placeholder max value, always last*/
    WMI_CHATTER_MODE_MAX
};

enum wmi_chatter_query_type {
    /*query coalescing filter match counter*/
    WMI_CHATTER_QUERY_FILTER_MATCH_CNT,
    WMI_CHATTER_QUERY_MAX
};

typedef struct {
    A_UINT32 chatter_mode;
} wmi_chatter_set_mode_cmd;

/** maximum number of filter supported*/
#define CHATTER_MAX_COALESCING_RULES     11
/** maximum number of field tests per filter*/
#define CHATTER_MAX_FIELD_TEST           5
/** maximum field length in number of DWORDS*/
#define CHATTER_MAX_TEST_FIELD_LEN32     2

/** field test kinds*/
#define CHATTER_COALESCING_TEST_EQUAL            1
#define CHATTER_COALESCING_TEST_MASKED_EQUAL     2
#define CHATTER_COALESCING_TEST_NOT_EQUAL        3

/** packet type*/
#define CHATTER_COALESCING_PKT_TYPE_UNICAST      (1 << 0)
#define CHATTER_COALESCING_PKT_TYPE_MULTICAST    (1 << 1)
#define CHATTER_COALESCING_PKT_TYPE_BROADCAST    (1 << 2)

/** coalescing field test*/
typedef struct _chatter_pkt_coalescing_hdr_test {
    /** offset from start of mac header, for windows native wifi host driver
     * should assume standard 802.11 frame format without QoS info and address4
     * FW would account for any non-stand fields for final offset value.
     */
    A_UINT32    offset;
    A_UINT32    length;	    /* length of test field*/
    A_UINT32    test;       /*equal, not equal or masked equal*/
    A_UINT32    mask[CHATTER_MAX_TEST_FIELD_LEN32];    /*mask byte stream*/
    A_UINT32    value[CHATTER_MAX_TEST_FIELD_LEN32];   /*value byte stream*/
} chatter_pkt_coalescing_hdr_test;

/** packet coalescing filter*/
typedef struct _chatter_pkt_coalescing_filter {
    A_UINT32    filter_id;  /*unique id assigned by OS*/
    A_UINT32    max_coalescing_delay; /*max miliseconds 1st pkt can be hold*/
    A_UINT32    pkt_type; /*unicast/multicast/broadcast*/
    A_UINT32    num_of_test_field;    /*number of field test in table*/
    chatter_pkt_coalescing_hdr_test   test_fields[CHATTER_MAX_FIELD_TEST]; /*field test tbl*/
} chatter_pkt_coalescing_filter;

/** packet coalescing filter add command*/
typedef struct {
    A_UINT32    num_of_filters;
    chatter_pkt_coalescing_filter rx_filter[1];
} wmi_chatter_coalescing_add_filter_cmd;

/** packet coalescing filter delete command*/
typedef struct {
    A_UINT32    filter_id; /*filter id which will be deleted*/
} wmi_chatter_coalescing_delete_filter_cmd;

/** packet coalescing query command*/
typedef struct {
    A_UINT32    type;    /*type of query*/
} wmi_chatter_coalescing_query_cmd;

/** chatter query reply event*/
typedef struct {
    A_UINT32    type;    /*query type*/
    union {
        A_UINT32    filter_match_cnt; /*coalescing filter match counter*/
    } report;
} wmi_chatter_query_reply_event;

#define GTK_OFFLOAD_KEK_BYTES       16
#define GTK_OFFLOAD_KCK_BYTES       16
#define GTK_REPLAY_COUNTER_BYTES    8
#ifdef IGTK_OFFLOAD
#define WMI_MAX_KEY_LEN             32
#define IGTK_PN_SIZE                6
#endif

typedef struct {
    A_UINT32 	vdev_id;    					/** unique id identifying the VDEV */
    A_UINT32    flags;          				/* status flags */
    A_UINT32    refresh_cnt;    				/* number of successful GTK refresh exchanges since last SET operation */
    A_UINT8     replay_counter[GTK_REPLAY_COUNTER_BYTES]; /* current replay counter */
#ifdef IGTK_OFFLOAD
    A_UINT8     igtk_keyIndex;
    A_UINT8     igtk_keyLength;
    A_UINT8     igtk_keyRSC[IGTK_PN_SIZE];/* key replay sequence counter */
    A_UINT8     igtk_key[WMI_MAX_KEY_LEN];
#endif
} WMI_GTK_OFFLOAD_STATUS_EVENT;

typedef struct {
    A_UINT32 	vdev_id;    					/** unique id identifying the VDEV */
    A_UINT32    flags;                          /* control flags, GTK offload command use high byte  */
    A_UINT8     KEK[GTK_OFFLOAD_KEK_BYTES];     /* key encryption key */
    A_UINT8     KCK[GTK_OFFLOAD_KCK_BYTES];     /* key confirmation key */
    A_UINT8     replay_counter[GTK_REPLAY_COUNTER_BYTES];  /* replay counter for re-key */
}WMI_GTK_OFFLOAD_CMD;

typedef struct  {
    A_UINT8    address[4];    /* IPV4 address in Network Byte Order */
} WMI_IPV4_ADDR;

typedef enum {
    WMI_STA_KEEPALIVE_METHOD_NULL_FRAME = 1,                   /* 802.11 NULL frame */
    WMI_STA_KEEPALIVE_METHOD_UNSOLICITED_ARP_RESPONSE = 2,     /* ARP response */
} WMI_STA_KEEPALIVE_METHOD;

typedef struct {
    WMI_IPV4_ADDR            sender_prot_addr;         /* Sender protocol address */
    WMI_IPV4_ADDR            target_prot_addr;         /* Target protocol address */
    wmi_mac_addr             dest_mac_addr;            /* destination MAC address */
} WMI_STA_KEEPALVE_ARP_RESPONSE;


typedef struct  {
    A_UINT32 vdev_id;
    A_UINT32 enable;                        /* 1 - Enable, 0 - disable */
    A_UINT32 method;                        /* keep alive method */
    A_UINT32 interval;                      /* time interval in seconds  */
    WMI_STA_KEEPALVE_ARP_RESPONSE arp_resp; /* ARP response */
} WMI_STA_KEEPALIVE_CMD;

typedef struct {
    A_UINT32 vdev_id;
    A_UINT32 keepaliveInterval;   /* seconds */
} wmi_vdev_set_keepalive_cmd;

typedef struct {
    A_UINT32    vdev_id;
} wmi_vdev_get_keepalive_cmd;

typedef struct {
    A_UINT32    vdev_id;
    A_UINT32 keepaliveInterval;   /* seconds */
} wmi_vdev_get_keepalive_event;
typedef enum {
    RECOVERY_SIM_ASSERT          = 0x01,
    RECOVERY_SIM_NO_DETECT       = 0x02,
    RECOVERY_SIM_CTR_EP_FULL     = 0x03,
    RECOVERY_SIM_EMPTY_POINT     = 0x04,
    RECOVERY_SIM_STACK_OV        = 0x05,
    RECOVERY_SIM_INFINITE_LOOP   = 0x06,
} RECOVERY_SIM_TYPE;

typedef struct {
    A_UINT32 type;     /*0:unused 1: ASSERT, 2: not respond detect command,3:  simulate ep-full(),4:...*/
    A_UINT32 delay_time_ms;   /*0xffffffff means the simulate will delay for random time (0 ~0xffffffff ms)*/
}WMI_FORCE_FW_HANG_CMD;

typedef struct {
    A_UINT32 vdev_id;
    A_UINT32 qb_enable;
    wmi_mac_addr peer_macaddr;
} WMI_QBOOST_CFG_CMD;

/* GPIO Command and Event data structures */

/* WMI_GPIO_CONFIG_CMDID */
enum {
    WMI_GPIO_PULL_NONE,
    WMI_GPIO_PULL_UP,
    WMI_GPIO_PULL_DOWN,
};

enum {
    WMI_GPIO_INTTYPE_DISABLE,
    WMI_GPIO_INTTYPE_RISING_EDGE,
    WMI_GPIO_INTTYPE_FALLING_EDGE,
    WMI_GPIO_INTTYPE_BOTH_EDGE,
    WMI_GPIO_INTTYPE_LEVEL_LOW,
    WMI_GPIO_INTTYPE_LEVEL_HIGH
};

typedef struct {
    A_UINT32 gpio_num;             /* GPIO number to be setup */
    A_UINT32 input;                /* 0 - Output/ 1 - Input */
    A_UINT32 pull_type;            /* Pull type defined above */
    A_UINT32 intr_mode;            /* Interrupt mode defined above (Input) */
} wmi_gpio_config_cmd;

/* WMI_GPIO_OUTPUT_CMDID */
typedef struct {
    A_UINT32 gpio_num;    /* GPIO number to be setup */
    A_UINT32 set;         /* Set the GPIO pin*/
} wmi_gpio_output_cmd;

/* WMI_GPIO_INPUT_EVENTID */
typedef struct {
    A_UINT32 gpio_num;    /* GPIO number which changed state */
} wmi_gpio_input_event;
typedef WMI_GTK_OFFLOAD_STATUS_EVENT WOW_EVENT_INFO_SECTION_GTKIGTK;

#define AES_BLOCK_LEN           16  /* in bytes */
#define FIPS_KEY_LENGTH_128     16  /* in bytes */
#define FIPS_KEY_LENGTH_256     32  /* in bytes */
#define FIPS_ENCRYPT_CMD        0
#define FIPS_DECRYPT_CMD        1
#define FIPS_ENGINE_AES_CTR     0
#define FIPS_ENGINE_AES_MIC     1
#define FIPS_ERROR_OPER_TIMEOUT 1
#define MAX_KEY_LENGTH          32

/* WMI_PDEV_FIPS_CMDID */
typedef struct {
    A_UINT32 fips_cmd;              /* Encrypt/Decrypt */
    A_UINT32 mode;                  /* Engine mode - AES_CTR or AES_MIC */
    A_UINT32 key_len;               /* 128/256 */
    A_UINT8 key[MAX_KEY_LENGTH];    /* Key */
    A_UINT32 data_len;              /* data length */
    A_UINT32 data[1];               /* In Data (keep this in the end) */
} wmi_pdev_fips_cmd;

/* WMI_PDEV_FIPS_EVENTID */
typedef struct {
    A_UINT32 error_status;          /* Error status */
    A_UINT32 data_len;              /* Data length */
    A_UINT32 data[1];               /* Out Data (keep this in the end) */
} wmi_pdev_fips_event;

typedef struct {
    A_UINT32 aid;
} wmi_peer_txmu_cnt_cmd;

typedef struct {
    A_UINT32 aid;
} wmi_peer_txmu_rstcnt_cmd;

typedef struct {
    A_UINT32 tx_mu_transmitted;
} wmi_peer_txmu_cnt_event;

typedef struct {
    A_UINT32 aid;
} wmi_peer_gid_userpos_list_cmd;

#define GID_OVERLOAD_GROUP_COUNT  15
typedef struct {
    A_UINT32 usr_list[GID_OVERLOAD_GROUP_COUNT];
} wmi_peer_gid_userpos_list_event;


typedef struct {
    /** parameter id   */
    A_UINT32 param_id;
    /** parametr value */
    A_UINT32 param_value;
} wmi_fwtest_set_param_cmd;

typedef struct {
    /*
     * Percentage of air time available for each AC
     * BIT[0-7]   : AC_BE
     * BIT[8-15]  : AC_BK
     * BIT[16-23] : AC_VI
     * BIT[24-31] : AC_VO
     */
    A_UINT32 ac_airtime_percentage;
} wmi_esp_estimation_event;

#define WMI_ATF_DENOMINATION   1000 /* Expressed in 1 part in 1000 (permille). */

#define WMI_ATF_SSID_FAIR_SCHED         0 /** fair ATF scheduling for vdev */
#define WMI_ATF_SSID_STRICT_SCHED       1 /** strict ATF scheduling for vdev */
#define WMI_ATF_SSID_FAIR_SCHED_WITH_UB 2 /** Fair ATF scheduling with upper bound for VDEV */

enum {
    WMI_ATF_PEER_STATS_DISABLED = 0,
    WMI_ATF_PEER_STATS_ENABLED  = 1,
};

typedef struct {
    /**
     * field1 contains:
     *     bits 15:0   peer_ast_index  WMI_ATF_PEER_STATS_GET_PEER_AST_IDX
     *                                 WMI_ATF_PEER_STATS_SET_PEER_AST_IDX
     *     bits 31:16  reserved
     *
     * field2 contains:
     *     bits 15:0   used tokens     WMI_ATF_PEER_STATS_GET_USED_TOKENS
     *                                 WMI_ATF_PEER_STATS_SET_USED_TOKENS
     *     bits 31:16  unused tokens   WMI_ATF_PEER_STATS_GET_UNUSED_TOKENS
     *                                 WMI_ATF_PEER_STATS_SET_UNUSED_TOKENS
     *
     * field3 for future use
     */
    A_UINT32    field1;
    A_UINT32    field2;
    A_UINT32    field3;
} wmi_atf_peer_stats_info;

typedef struct {
    A_UINT32 num_atf_peers;       /** number of peers in token_info_list */
    A_UINT32 comp_usable_airtime; /** computed usable airtime in tokens */
    A_UINT32 reserved[4];         /** reserved for future use */
    wmi_atf_peer_stats_info token_info_list[1/*num_atf_peers*/];
} wmi_atf_peer_stats_event;

#define WMI_ATF_PEER_STATS_GET_PEER_AST_IDX(token_info) \
    (token_info.field1 & 0xffff)

#define WMI_ATF_PEER_STATS_GET_USED_TOKENS(token_info) \
    ((token_info.field2 & 0xffff0000) >> 16)

#define WMI_ATF_PEER_STATS_GET_UNUSED_TOKENS(token_info) \
    (token_info.field2 & 0xffff)

#define WMI_ATF_PEER_STATS_SET_PEER_AST_IDX(token_info, peer_ast_idx) \
    do { \
        token_info.field1 &= 0xffff0000; \
        token_info.field1 |= ((peer_ast_idx) & 0xffff); \
    } while (0);

#define WMI_ATF_PEER_STATS_SET_USED_TOKENS(token_info, used_token) \
    do { \
        token_info.field2 &= 0x0000ffff; \
        token_info.field2 |= (((used_token) & 0xffff) << 16); \
    } while (0);

#define WMI_ATF_PEER_STATS_SET_UNUSED_TOKENS(token_info, unused_token) \
    do { \
        token_info.field2 &= 0xffff0000; \
        token_info.field2 |= ((unused_token) & 0xffff); \
    } while (0);

struct wmi_atf_peer_info {
    wmi_mac_addr peer_macaddr;
    A_UINT32 atf_units; /* Based on 1 part in 1000 (per mille). */
};

typedef struct {
    A_UINT32 num_peers;
    struct wmi_atf_peer_info peer_info[1];
} wmi_peer_atf_request;

/* Structure for Bandwidth Fairness peer information */
struct wmi_bwf_peer_info {
    wmi_mac_addr peer_macaddr;
    A_UINT32 bwf_guaranteed_bandwidth; /* BWF guaranteed_bandwidth for the peers in mbps*/
    A_UINT32 bwf_max_airtime; /* BWF Maximum airtime percentage that can be allocated to the peer to meet the guaranteed_bandwidth */
    A_UINT32 bwf_peer_priority; /* BWF priority of the peer to allocate the tokens dynamically */
    A_UINT32 reserved[4]; /* for future use; set to 0x0 */
};

/* Structure for Bandwidth Fairness peer request */
typedef struct {
    A_UINT32 num_peers;
    A_UINT32 reserved[8]; /* for future use; set to 0x0 */
    struct wmi_bwf_peer_info peer_info[1];
} wmi_peer_bwf_request;

#define WMI_ATF_GROUP_CFG_PEER_BIT_POS     0
#define WMI_ATF_GROUP_CFG_PEER_NUM_BITS    1

#define WMI_ATF_GROUP_GET_CFG_PEER_BIT(atf_peer_flags) \
    WMI_GET_BITS(atf_peer_flags,WMI_ATF_GROUP_CFG_PEER_BIT_POS,WMI_ATF_GROUP_CFG_PEER_NUM_BITS)

#define WMI_ATF_GROUP_SET_CFG_PEER_BIT(atf_peer_flags,val) \
    WMI_SET_BITS(atf_peer_flags,WMI_ATF_GROUP_CFG_PEER_BIT_POS,WMI_ATF_GROUP_CFG_PEER_NUM_BITS,val)

struct wmi_atf_peer_ext_info {
    wmi_mac_addr peer_macaddr;
    A_UINT32 atf_groupid; /* Group Id of the peers for ATF SSID grouping */
    /* atf_units_reserved / atf_peer_flags
     *  Bits 1-31  - Reserved (Shall be zero)
     *  Bit  0     - Configured Peer Indication (0/1), this bit would be set by
     *               host to indicate that the peer has airtime % configured
     *               explicitly by user.
     */
    union {
        A_UINT32 atf_units_reserved; /* original name */
        A_UINT32 atf_peer_flags;
    };
};

typedef struct {
    A_UINT32 num_peers;
    struct wmi_atf_peer_ext_info peer_ext_info[1];
} wmi_peer_atf_ext_request;

#define WMI_ATF_GROUP_SCHED_POLICY_BIT_POS        0
#define WMI_ATF_GROUP_SCHED_POLICY_NUM_BITS       4

#define WMI_ATF_GROUP_GET_GROUP_SCHED_POLICY(atf_group_flags)  \
    WMI_GET_BITS(atf_group_flags,WMI_ATF_GROUP_SCHED_POLICY_BIT_POS,WMI_ATF_GROUP_SCHED_POLICY_NUM_BITS)

#define WMI_ATF_GROUP_SET_GROUP_SCHED_POLICY(atf_group_flags,val)  \
    WMI_SET_BITS(atf_group_flags,WMI_ATF_GROUP_SCHED_POLICY_BIT_POS,WMI_ATF_GROUP_SCHED_POLICY_NUM_BITS,val)

struct wmi_atf_group_info {
    A_UINT32 atf_group_units; /* Based on 1 part in 1000 (per mille). */
    /* atf_group_units_reserved / atf_group_flags
     *  Bits 4-31  - Reserved (Shall be zero)
     *  Bits 0-3   - Group Schedule Policy (Fair/Strict/Fair with upper bound)
     *               Refer to WMI_ATF_SSID_ definitions
     */
    union {
        A_UINT32 atf_group_units_reserved; /* original name */
        A_UINT32 atf_group_flags;
    };
};

typedef struct {
    A_UINT32 num_groups;
    struct wmi_atf_group_info group_info[1];
} wmi_atf_ssid_grp_request;

/* Equal distribution of ATF air time within an VDEV. */
typedef struct {
    A_UINT32 vdev_id;
    A_UINT32 peer_atf_units; /* Per peer ATF units (per mille). */
} wmi_vdev_atf_request;

/* ATF Configurations for WMM ACs of a group, value for each AC shall be in percentage (0-100) %
 * This perecentage is relative to the residual airtime (derived by FW) configured for the group
 * When WMM ATF is not configured for a peer all values shall be 0
 */
struct wmi_atf_group_wmm_ac_info {
    A_UINT32 atf_config_ac_be;
    A_UINT32 atf_config_ac_bk;
    A_UINT32 atf_config_ac_vi;
    A_UINT32 atf_config_ac_vo;
    /* Reserved for future use (set to zero) */
    A_UINT32 reserved[2];
};

/* List of group WMM ATF configurations, index corresponds to group id */
typedef struct {
    A_UINT32 num_groups;
    struct wmi_atf_group_wmm_ac_info group_info[1];
} wmi_atf_grp_wmm_ac_cfg_request;

typedef struct {
    /** parameter   */
    A_UINT32 param;
} wmi_pdev_get_ani_cck_config_cmd;

typedef struct {
    /** parameter   */
    A_UINT32 param;
} wmi_pdev_get_ani_ofdm_config_cmd;

typedef struct {
    A_UINT32 cck_level;
} wmi_ani_cck_event;

typedef struct {
    A_UINT32 ofdm_level;
} wmi_ani_ofdm_event;

typedef struct {
    wmi_mac_addr mac_addr;
    A_UINT32 key_id;
    A_UINT32 mcast;
} wmi_pdev_reserve_ast_entry_cmd;

enum {
    WMI_PDEV_RESERVE_AST_ENTRY_OK,
    WMI_PDEV_RESERVE_AST_ENTRY_HASH_COLLISION,
    WMI_PDEV_RESERVE_AST_ENTRY_CROSSING_AXI_BOUNDARY,
};

typedef struct {
    A_UINT32 result;
} wmi_pdev_reserve_ast_entry_event;

typedef struct {
    A_INT8 nfdBr[MAX_NUM_CHAINS];
    A_INT8 nfdBm[MAX_NUM_CHAINS];
} wmi_pdev_nfcal_power_event;

#define RXG_CAL_CHAN_MAX    4
A_COMPILE_TIME_ASSERT(rxg_cal_chain_size,
        (RXG_CAL_CHAN_MAX!=0 && !(RXG_CAL_CHAN_MAX & 0x3)));

typedef struct {
    /**
     * nfdBr {
     *  chan0: {NFCalPower_chain0, NFCalPower_chain1, NFCalPower_chain2, NFCalPower_chain3},
     *  chan1: {NFCalPower_chain0, NFCalPower_chain1, NFCalPower_chain2, NFCalPower_chain3},
     *  chan2: {NFCalPower_chain0, NFCalPower_chain1, NFCalPower_chain2, NFCalPower_chain3},
     *  chan3: {NFCalPower_chain0, NFCalPower_chain1, NFCalPower_chain2, NFCalPower_chain3},
     *  }
     * */
    A_INT8 nfdBr[RXG_CAL_CHAN_MAX * MAX_NUM_CHAINS];
    /**
     * nfdBm {
     *  chan0: {NFCalPower_chain0, NFCalPower_chain1, NFCalPower_chain2, NFCalPower_chain3},
     *  chan1: {NFCalPower_chain0, NFCalPower_chain1, NFCalPower_chain2, NFCalPower_chain3},
     *  chan2: {NFCalPower_chain0, NFCalPower_chain1, NFCalPower_chain2, NFCalPower_chain3},
     *  chan3: {NFCalPower_chain0, NFCalPower_chain1, NFCalPower_chain2, NFCalPower_chain3},
     *  }
     *  */
    A_INT8 nfdBm[RXG_CAL_CHAN_MAX * MAX_NUM_CHAINS];
    A_UINT32 freqNum[RXG_CAL_CHAN_MAX];
} wmi_pdev_nfcal_power_all_channels_event;


typedef struct {
    A_UINT32
            rate_flags: 16,
    /**
    * FLAG_ONE_CHAIN     0x001  - one chain mask
    * FLAG_TWO_CHAIN     0x005  - two chain mask
    * FLAG_THREE_CHAIN   0x007  - three chain mask
    * FLAG_FOUR_CHAIN    0x00F  - four chain mask
    * FLAG_STBC          0x010  - STBC is set
    * FLAG_40MHZ         0x020
    * FLAG_80MHZ         0x040
    * FLAG_160MHZ        0x080
    * FLAG_TXBF          0x0100 - Tx Bf enabled
    * FLAG_RTSENA        0x0200 - RTS enabled
    * FLAG_CTSENA        0x0400 - CTS enabled
    * FLAG_LDPC          0x0800 - LDPC set
    * FLAG_SERIES1       0x1000 -
    * FLAG_SGI           0x2000 - Short gaurd interval
    * FLAG_MU2           0x4000 - MU2 data
    * FLAG_MU3           0x8000 - MU3 data
    * */
            nss : 3,
    /**
    * NSS 0x0 - 0x3
    * */
            preamble : 3,
    /**
    * PREAM_OFDM - 0x0
    * PREAM_CCK  - 0x1
    * PREAM_HT   - 0x2
    * PREAM_VHT  - 0x3
    * */
            hw_rate : 4,
    /**
     * *** HW_OFDM_RATE ***
     * OFDM_48_MBPS - 0x0
     * OFDM_24_MBPS - 0x1
     * OFDM_12_MBPS - 0x2
     * OFDM_6_MBPS  - 0x3
     * OFDM_54_MBPS - 0x4
     * OFDM_36_MBPS - 0x5
     * OFDM_18_MBPS - 0x6
     * OFDM_9_MBPS  - 0x7
     *
     * *** HW_CCK_RATE ***
     * CCK_11_LONG_MBPS   - 0x0
     * CCK_5_5_LONG_MBPS  - 0x1
     * CCK_2_LONG_MBPS    - 0x2
     * CCK_1_LONG_MBPS    - 0x3
     * CCK_11_SHORT_MBPS  - 0x4
     * CCK_5_5_SHORT_MBPS - 0x5
     * CCK_2_SHORT_MBPS   - 0x6
     *
     * *** HW_HT / VHT_RATE ***
     * MCS 0x0 - 0x9
     * */
            rsvd : 6;
} wmi_pdev_get_tpc_cmd;

typedef struct {
    A_UINT32 tpc[1];
} wmi_pdev_tpc_event;

typedef struct {
    A_INT32 temperature_degreeC; /* temperature in degree C*/
} wmi_pdev_temperature_event;

typedef struct {
    A_UINT32 reserved;  /* set to 0x0 */
} wmi_pdev_check_cal_version_cmd;

typedef enum {
    NO_FEATURE = 0,     /* The board was calibrated with a meta which did not have this feature */
    CALIBRATION_OK,     /* The calibration status is OK */
    CALIBRATION_NOT_OK, /* The calibration status is NOT OK */
} CALIBRATION_STATUS;

#define WMI_BOARD_MCN_STRING_MAX_SIZE 19
#define WMI_BOARD_MCN_STRING_BUF_SIZE (WMI_BOARD_MCN_STRING_MAX_SIZE+1) /* null-terminator */

typedef struct {
    A_UINT32 software_cal_version;
    A_UINT32 board_cal_version;
    /* board_mcn_detail:
     * Provide a calibration message string for the host to display.
     * Note: on a big-endian host, the 4 bytes within each A_UINT32 portion
     * of a WMI message will be automatically byteswapped by the copy engine
     * as the messages are transferred between host and target, to convert
     * between the target's little-endianness and the host's big-endianness.
     * Consequently, a big-endian host will have to manually unswap the bytes
     * within the board_mcn_detail string buffer to get the bytes back into
     * the desired natural order.
     */
    A_UINT8 board_mcn_detail[WMI_BOARD_MCN_STRING_BUF_SIZE];
    A_UINT32 cal_ok; /* filled with CALIBRATION_STATUS enum value */
} wmi_pdev_check_cal_version_event;

/**
 * The below definitions are used for LTE-Unlicensed support.
 * Within these definitions, "MU" refers to "Medium Utilization"
 * (not "Multi User", as in MU-MIMO)
 */

/*
 * Medium Utilization evaluation algorithms
 * These algorithms can be complementary rather than exclusive.
 */
typedef enum {
    MU_BASIC_ALGO = 0x1,
    MU_PER_BSSID_ALGO = 0x2,
    MU_HIDDEN_NODE_ALGO = 0x4,
    MU_PER_TA_ALGO = 0x8,
} MU_ALGO_TYPE;

#define MU_MAX_ALGO_TYPE  4   /* max MU alg combinations supported by target */
#define MAX_MU_DB_ENTRIES 32  /* max no. of entries supported in MU report event */
#define LTEU_MAX_BINS     10  /* max no. of bins in which packets can be categorized */

typedef enum {
    MU_SUCCESS,
    MU_BUSY,
    MU_INVALID,
    MU_BUSY_PREV_REQ_IN_PROG,
    MU_INVALID_INPUT,
    MU_FAIL_BB_WD_TRIGGER,
    MU_FAIL_DEV_RESET,
    MU_FAIL_GPIO_TIMEOUT,
} MU_STATUS_REASON;

typedef struct {
    A_UINT32     entry_type;      /* 0=AP, 1=STA, 2=Small Cell(SC) */
    wmi_mac_addr bssid_mac_addr;  /* BSSID which the node belongs to. NA for SC entry */
    wmi_mac_addr tx_addr;         /* Transmitter MAC if entry is WiFi node. PLMNID if SC */
    A_UINT32     avg_duration_us; /* Avg. duration for which node was transmitting*/
    A_UINT32     avg_rssi;        /* Avg. RSSI of all TX packets by node. Unit dBm */
    A_UINT32     mu_percent;      /* % medium utilization by node */
} wmi_mu_db_entry;


/* WMI_MU_REPORT_EVENTID */
typedef struct {
    A_UINT32         mu_request_id;
    A_UINT32         status_reason; /* MU_STATUS_REASON */
    A_UINT32         total_mu[MU_MAX_ALGO_TYPE-1]; /* MU_ALG_TYPE combinations */
    A_UINT32         num_active_bssid;

    A_UINT32         hidden_node_mu[LTEU_MAX_BINS]; /* Hidden node algo MU per bin */
    A_UINT32         num_TA_entries;                /* No. of nodes present in MU DB report. Max 32 */
    wmi_mu_db_entry  mu_entry[MAX_MU_DB_ENTRIES];   /* MU DB report per entry */
} wmi_mu_report_event;

/* WMI_MU_CAL_START_CMDID */
typedef struct {
    A_UINT32 mu_request_id;
    /* mu_duration -
     * period over which medium utilization is evaluated (millisecond units)
     */
    A_UINT32 mu_duration;
    A_UINT32 mu_type; /* MU_ALGO_TYPE combinations */
    A_UINT32 lteu_tx_power; /* dBm units */
    A_UINT32 rssi_thr_bssid; /* APs above this RSSI threshold are considered as active. Unit dBm */
    A_UINT32 rssi_thr_sta;   /* STAs above this RSSI threshold are considered as active. Unit dBm */
    A_UINT32 rssi_thr_sc;    /* SCs above this RSSI threshold are considered as active. Unit dBm */
    A_UINT32 alpha_num_bssid;/* MU thresold above which a BSSID is considered active. Range 0-100 */
    A_UINT32 plmn_id;        /* Lower 24 bits represent the PLMNID of the SC */
} wmi_mu_start_cmd;

/* WMI_SET_LTEU_CONFIG_CMDID */
typedef struct {
    A_UINT32 gpio_enable;
    A_UINT32 num_lteu_bins; /* how many of the LTEU_MAX_BINS are valid */
    /* mu_rssi_threshold -
     * Specify ranges of RSSI as a partial determination of how to categorize
     * a given burst reception into an LTE-U bin, and thus a weight to apply
     * to the burst's duration's contribution to medium utilization.
     */
    A_INT32  mu_rssi_threshold[LTEU_MAX_BINS]; /* dBm units */
    /* mu_weight -
     * Depending on the LTE-U bin a rx packet is classified as, the packets
     * are given weights for medium utilization computation.
     * (Stronger signals get higher weights.)
     */
    A_UINT32 mu_weight[LTEU_MAX_BINS];
    /* mu_gamma -
     * Gamma is the ratio of SNR/SINR, which is calculated for each Data-ack.
     * The calculated gamma is compared to the gamma thresholds specified in
     * the mu_gamma array, as one of the steps in determining how to classify
     * a given received burst into a LTE-U bin.
     */
    A_UINT32 mu_gamma[LTEU_MAX_BINS];
    A_UINT32 mu_scan_timeout;
    A_UINT32 wifi_tx_power; /* dBm units */
    /* alpha_num_bssid -
     * Alpha is a configurable weight to control how large a BSSID's medium
     * utilization score needs to be for the BSSID to be considered active,
     * and to count towards the reported num_active_bssid.
     */
    A_UINT32 alpha_num_bssid;
    /* use_actual_nf -
     * A hardcoded assumed noise floor of -95dBm is used if this is not set.
     */
    A_UINT32 use_actual_nf;
    /* allow_err_packets -
     * include phy_err or FCS error packets for MU computation
     */
    A_UINT32 allow_err_packets;
} wmi_set_lteu_config;

/*---------End LTEU Data Structures---------*/


typedef struct {
    A_UINT32 enable;
    A_INT32 cca_detection_level;
    A_UINT32 cca_detection_margin;
} wmi_set_cca_params;

typedef struct {
    A_UINT32 param;   /* 1 = read only, 2= read and clear */
    A_UINT32 reserved;
} wmi_pdev_bss_chan_info_request;

typedef struct {
    A_UINT32 freq; /* Units in MHz */
    A_UINT32 noise_floor; /* units are dBm */
    A_UINT32 rx_clear_count_low;
    A_UINT32 rx_clear_count_high;
    A_UINT32 cycle_count_low;
    A_UINT32 cycle_count_high;
    A_UINT32 tx_cycle_count_low;
    A_UINT32 tx_cycle_count_high;
    A_UINT32 rx_cycle_count_low;
    A_UINT32 rx_cycle_count_high;
    A_UINT32 rx_bss_cycle_count_low;
    A_UINT32 rx_bss_cycle_count_high;
    A_UINT32 reserved;
} wmi_pdev_bss_chan_info_event;

/* Event definition and new structure addition to send event
 * to host to block/unblock tx data traffic based on peer_ast_idx or vdev id
 */
#define WMI_INVALID_PEER_AST_INDEX              0xffff
#define WMI_TX_DATA_TRAFFIC_CTRL_BLOCK          0x1
#define WMI_TX_DATA_TRAFFIC_CTRL_UNBLOCK        0x2

#define WMI_TX_DATA_TRAFFIC_CTRL_WMM_AC_BITPOS     0
#define WMI_TX_DATA_TRAFFIC_CTRL_WMM_AC_NUMBITS    4

#define WMI_TX_DATA_TRAFFIC_CTRL_GET_WMM_AC(wmm_ac) \
        WMI_GET_BITS(wmm_ac,WMI_TX_DATA_TRAFFIC_CTRL_WMM_AC_BITPOS,WMI_TX_DATA_TRAFFIC_CTRL_WMM_AC_NUMBITS)

#define WMI_TX_DATA_TRAFFIC_CTRL_SET_WMM_AC(wmm_ac,val) \
        WMI_SET_BITS(wmm_ac,WMI_TX_DATA_TRAFFIC_CTRL_WMM_AC_BITPOS,WMI_TX_DATA_TRAFFIC_CTRL_WMM_AC_NUMBITS,val)

typedef struct {
    A_UINT32 peer_ast_idx; /* For radio based control, peer_ast_idx will be WMI_INVALID_PEER_AST_INDEX */
    A_UINT32 vdev_id; /* valid only if peer_ast_idx == INVALID */
    A_UINT32 ctrl_cmd; /* WMI_TX_DATA_TRAFFIC_CTRL_BLOCK or WMI_TX_DATA_TRAFFIC_CTRL_UNBLOCK */
    /* Bits  4-31   :  Reserved (Shall be zero)
     * Bits  0-3    :  WMM AC number
     *                 [BE (1), BK (2), VI (3), VO (4), 0xF (all TIDs)]
     *                 Intentionally started numbering from 1, to preserve
     *                 backward compatiblity
     */
    A_UINT32 wmm_ac;
} wmi_tx_data_traffic_ctrl_event;

typedef struct {
    A_UINT32 vdev_id;
    /** unique id to identify the ie_data as defined by ieee 802.11 spec */
    A_UINT32 ie_id;
    /** ie_len corresponds to num of bytes in ie_data[] */
    A_UINT32 ie_len;
    A_UINT8 ie_data[1/*ie_len*/];
} wmi_vdev_set_ie_cmd_fixed_param;

/*
 * Periodic channel stats WMI command structure
 * WMI_SET_PERIODIC_CHANNEL_STATS_CONFIG
 */
typedef struct {
    /** 1 = enable, 0 = disable */
    A_UINT32 enable;
    /** periodic stats duration (units are milliseconds) */
    A_UINT32 stats_period;
} wmi_set_periodic_channel_stats_config;


/* Below are the fields which are supported for different coex versions:
 *      VERSION_1 (3 wire coex)
 *          btcoex_wlan_priority_bitmap
 *
 *      VERSION_2 (2.5 wire coex)
 *          btcoex_wlan_priority_bitmap
 *
 *      VERSION_3 (2.5 wire coex + duty cycle)
 *          btcoex_wlan_priority_bitmap
 *          btcoex_param_flags
 *          period
 *          wlan_duration
 *
 *     VERSION_4 onwards, a new TLV command will be used.
 *     This structure will still be maintained for backward compatibility
 *     for no version, VERSION_1, VERSION_2, VERSION_3.
 */
typedef struct {
    /* WLAN priority bitmask for different frame types */
    A_UINT32 btcoex_wlan_priority_bitmap;

    /* flags bit 0: to configure wlan priority bitmap */
    #define WMI_BTCOEX_PARAM_FLAGS_WLAN_PRIORITY_BITMAP_BIT (1<<0)
    /* flags bit 1: to configure both period and wlan duration */
    #define WMI_BTCOEX_PARAM_FLAGS_DUTY_CYCLE_BIT (1<<1)

    /* This command is used to configure different btcoex params in different situations.
     * The host sets the appropriate bit(s) in btcoex_param_flags to indicate which configuration parameters are valid within a particular BT coex config message,
     * so that one BT configuration parameter can be configured without affecting other BT configuration parameters.
     * E.g. if the host wants to configure only btcoex_wlan_priority_bitmap it sets only
     * WMI_BTCOEX_PARAM_FLAGS_WLAN_PRIORITY_BITMAP_BIT in btcoex_param_flags so that firmware will not overwrite
     * other params with default value passed in the command.
     * Host can also set multiple bits in btcoex_param_flags to configure more than one param
     * in single message.
     */
    A_UINT32 btcoex_param_flags;

    /* period denotes the total time in milliseconds which WLAN and BT share
     * configured percentage for transmission and reception.
     */
    A_UINT32 period;

    /* wlan duration is the time in milliseconds given for wlan in above period */
    A_UINT32 wlan_duration;
} wmi_btcoex_cfg_cmd;

/* When a bit is set it specifies the particular WLAN traffic type is high priority.
 * BT low priority traffic has higher priority than WLAN low priority traffic and has
 * lower priority when compared to WLAN high priority traffic.
 * BT high priority traffic has higher priority than WLAN low/high priority traffic.
 */
#define WMI_PDEV_BE_PRIORITY_BIT     (1<<0)
#define WMI_PDEV_BK_PRIORITY_BIT     (1<<1)
#define WMI_PDEV_VI_PRIORITY_BIT     (1<<2)
#define WMI_PDEV_VO_PRIORITY_BIT     (1<<3)
#define WMI_PDEV_BEACON_PRIORITY_BIT (1<<4)
#define WMI_PDEV_MGMT_PRIORITY_BIT   (1<<5)
#define WMI_PDEV_IS_BE_PRIORITY_SET(val) ((val) & WMI_PDEV_BE_PRIORITY_BIT)
#define WMI_PDEV_IS_BK_PRIORITY_SET(val) ((val) & WMI_PDEV_BK_PRIORITY_BIT)
#define WMI_PDEV_IS_VI_PRIORITY_SET(val) ((val) & WMI_PDEV_VI_PRIORITY_BIT)
#define WMI_PDEV_IS_VO_PRIORITY_SET(val) ((val) & WMI_PDEV_VO_PRIORITY_BIT)
#define WMI_PDEV_IS_BEACON_PRIORITY_SET(val) ((val) & WMI_PDEV_BEACON_PRIORITY_BIT)
#define WMI_PDEV_IS_MGMT_PRIORITY_SET(val) ((val) & WMI_PDEV_MGMT_PRIORITY_BIT)

typedef struct {
    /* WLAN checks the priority of requesting IOT subsystems from user
     * configured priority table to grant/deny the request.
     * Host will program the IOT subsystem IDs in below fields for all
     * IOT subsystems.
     * Host will take care that each ID is programmed for exactly one priority.
     */
    #define ZIGBEE_SUBSYSTEM_ID  1
    #define WIFI_SUBSYSTEM_ID    2
    #define BT_SUBSYSTEM_ID      3
    #define THREAD_SUBSYSTEM_ID  4
    A_UINT32 coex_priority_0_ss_id;
    A_UINT32 coex_priority_1_ss_id;
    A_UINT32 coex_priority_2_ss_id;
    A_UINT32 coex_priority_3_ss_id;
} coex_config_v4;

#define COEX_CONFIG_BUF_MAX_LEN 32 /* 128 bytes */

typedef struct {
    /* VERSION_4 (4 wire coex)
     * Add other version descriptions here
     */
    A_UINT32 coex_version;

    /*
     * How many of the A_UINT32 elements of config_buf contain valid data.
     * Different coex versions will provide different amounts of config data.
     */
    A_UINT32 length;

    /* Payload buffer */
    A_UINT32 config_buf[COEX_CONFIG_BUF_MAX_LEN];
} wmi_coex_ver_cfg_cmd;

/*
 * Extended NSS WMI command structure
 * WMI_PDEV_EXTENDED_NSS_CFG_CMDID
 */
typedef struct {
    A_UINT32 enable; /* 1:enable, 0:disable */
} wmi_pdev_extended_nss_cfg_cmd;

/*
 * WMI command structure for the configuration
 * of dual band select GPIO pin
 * WMI_PROG_GPIO_BAND_SELECT_CMDID
 */
typedef struct {
  /*
   * The GPIO pin number to be configured to specify the band on a dual band
   * capable radio.
   * The WLAN target FW will drive the specified GPIO pin high to indicate it
   * is operating on the 2.4 GHz band, or low to indicate it is operating on
   * the 5 GHz band.
   */
  A_UINT32 gpio_pin_number;
} wmi_prog_gpio_band_select_cmd;

/* Data structure for the request for WMI_GET_TSF_TIMER_CMDID. */
typedef struct {
    /* VDEV identifier */
    A_UINT32 vdev_id;
    A_UINT32 period_ms; /* Period with which tsf_timer uploads should be sent to host. 0 if host only wants a single upload */
    A_UINT32 enable_tsf_uploads; /* 1 - Enable TSF uploads to host (single upload or periodic uploads), 0 - Disable a prior request for periodic TSF uploads */
} wmi_get_tsf_timer_cmd;

/* Data structure for the response to WMI_GET_TSF_TIMER_CMDID. */
typedef struct {
    /* VDEV identifier */
    A_UINT32 vdev_id;
    A_UINT32 tsf_timer_low;
    A_UINT32 tsf_timer_high;
} wmi_get_tsf_timer_resp_event;

/*
 * WMI command structure for FILS feature enable/disable
 */
typedef struct {
    /* VDEV identifier */
    A_UINT32 vdev_id;
    A_UINT32 fd_period; /* non-zero - enable Fils Discovery frames with this period (in TU), 0 - disable FD frames */
} wmi_enable_fils_cmd;

typedef struct {
    /** unique id identifying the VDEV */
    A_UINT32 vdev_id;
    /** Enable/Disable TDLS (wmi_tdls_state) */
    A_UINT32 state;
    /** Duration (in ms) over which to calculate tx threshold and rate values */
    A_UINT32 notification_interval_ms;
    /** number of packets OVER which notify/suggest TDLS Discovery:
     *  if current tx pps counter / notification interval >= threshold
     *  then a notification will be sent to host to advise TDLS Discovery */
    A_UINT32 tx_discovery_threshold;
    /** number of packets UNDER which notify/suggest TDLS Teardown:
     *  if current tx pps counter / notification interval < threshold
     *  then a notification will be sent to host to advise TDLS Tear down */
    A_UINT32 tx_teardown_threshold;
    /** Absolute RSSI value under which notify/suggest TDLS Teardown in dBm */
    A_INT32 rssi_teardown_threshold;
    /** Peer RSSI < (AP RSSI + delta) will trigger a teardown in dBm */
    A_INT32 rssi_delta;
    /** TDLS Option Control as in wmi_tdls_option
     * Off-Channel, Buffer STA, (later)Sleep STA support */
    A_UINT32 tdls_options;
    /** Buffering time in number of beacon intervals */
    A_UINT32 tdls_peer_traffic_ind_window;
    /** Wait time for PTR frame */
    A_UINT32 tdls_peer_traffic_response_timeout_ms;
    /** Self PUAPSD mask */
    A_UINT32 tdls_puapsd_mask;
    /** Inactivity timeout */
    A_UINT32 tdls_puapsd_inactivity_time_ms;
    /** Max of rx frame (MPDUs) during SP */
    A_UINT32 tdls_puapsd_rx_frame_threshold;
    /** Duration (in ms) over which to check whether TDLS link needs to be torn down */
    A_UINT32 teardown_notification_ms;
    /** STA kickout threshold for TDLS peer - number of packets to kick out the peer
     * e.g., if peer kick out threshold is 10, then firmware will wait for 10
     * consecutive packet failures and then send TDLS kickout notification to host driver */
    A_UINT32 tdls_peer_kickout_threshold;
} wmi_tdls_set_state_cmd;

/** TDLS state set through WMI_TDLS_SET_STATE_CMDID */
enum wmi_tdls_state {
    /** TDLS disable */
    WMI_TDLS_DISABLE,
    /** TDLS enabled - no firmware connection tracking/notifications - explicit */
    WMI_TDLS_ENABLE_PASSIVE,
    /** TDLS enabled - with firmware connection tracking/notifications - implicit default */
    WMI_TDLS_ENABLE_ACTIVE,
    /** TDLS enabled - firmware waits for peer mac for connection tracking - implicit external control */
    WMI_TDLS_ENABLE_ACTIVE_EXTERNAL_CONTROL,
    /** TDLS enabled - TDLS connection tracking is done in host */
    WMI_TDLS_ENABLE_CONNECTION_TRACKER_IN_HOST,
};

/** TDLS Options */
enum wmi_tdls_option {
    WMI_TDLS_OFFCHAN_EN    = (1 << 0), /** TDLS Off Channel support */
    WMI_TDLS_BUFFER_STA_EN = (1 << 1), /** TDLS Buffer STA support */
    WMI_TDLS_SLEEP_STA_EN  = (1 << 2), /** TDLS Sleep STA support */
};

#define WMI_TDLS_MAX_SUPP_OPER_CLASSES 32
typedef struct {
    /** Peer's QoS Info - for U-APSD
     * AC FLAGS  - accessed through macros below
     * Ack, SP, More Data Ack - accessed through macros below */
    A_UINT32 peer_qos;
    /** TDLS Peer's U-APSD Buffer STA Support*/
    A_UINT32 buff_sta_support;
    /** TDLS off channel related params */
    /** off_chan_support - 0: Not supported, 1: Supported */
    A_UINT32 off_chan_support;
    A_UINT32 peer_curr_operclass;
    A_UINT32 self_curr_operclass;
    /** Number of channels available for off channel operation */
    A_UINT32 peer_chan_len;
    A_UINT32 peer_operclass_len;
    A_UINT8  peer_operclass[WMI_TDLS_MAX_SUPP_OPER_CLASSES];
    /** Is peer initiator or responder of TDLS setup request */
    A_UINT32 is_peer_responder;
    /** Preferred off channel number as configured by user */
    A_UINT32 pref_offchan_num;
    /** Preferred off channel bandwidth as configured by user
     * 0x1: 20 MHz 0x2: 40 MHz 0x4: 80 MHz 0x8: 160 MHz */
    A_UINT32 pref_offchan_bw;
    /** Peer channel list of size peer_chan_len - This array is intersected channels which is
     * supported by both peer and DUT. freq1 in chan_info shall be same as mhz, freq2 shall be 0.
     * FW shall compute BW for an offchan based on peer's ht/vht cap received in peer_assoc
     * cmd during change STA operation */
    wmi_channel peer_chan_list[1/*peer_chan_len*/];
} wmi_tdls_peer_capabilities;

typedef struct {
    /** unique id identifying the VDEV */
    A_UINT32                    vdev_id;
    /** peer MAC address */
    wmi_mac_addr                peer_macaddr;
    /** new TDLS state for peer (wmi_tdls_peer_state) */
    A_UINT32                    peer_state;
    /** for future expansion */
    A_UINT32                    reserved[4];
    /** peer capabilities */
    wmi_tdls_peer_capabilities  peer_caps;
} wmi_tdls_peer_update_cmd;

enum wmi_tdls_peer_state {
    /** tx peer TDLS link setup now starting, traffic to DA should be
     * paused (except TDLS frames) until state is moved to CONNECTED (or
     * TEARDOWN on setup failure) */
    WMI_TDLS_PEER_STATE_PEERING,
    /** tx peer TDLS link established, running (all traffic to DA unpaused) */
    WMI_TDLS_PEER_STATE_CONNECTED,
    /** tx peer TDLS link tear down started (link paused, any frames
     * queued for DA will be requeued back through the AP)*/
    WMI_TDLS_PEER_STATE_TEARDOWN,
    /** Add peer mac into connection table */
    WMI_TDLS_PEER_ADD_MAC_ADDR,
    /** Remove peer mac from connection table */
    WMI_TDLS_PEER_REMOVE_MAC_ADDR,
};

#define WMI_TDLS_QOS_VO_FLAG           0
#define WMI_TDLS_QOS_VI_FLAG           1
#define WMI_TDLS_QOS_BK_FLAG           2
#define WMI_TDLS_QOS_BE_FLAG           3
#define WMI_TDLS_QOS_ACK_FLAG          4
#define WMI_TDLS_QOS_SP_FLAG           5
/** Value of 6 is intentionally skipped. This was a typo in cmn 1.0.
 * So, retaining the same to match with other FWs. */
#define WMI_TDLS_QOS_MOREDATA_FLAG     7

#define WMI_TDLS_PEER_SET_QOS_FLAG(ppeer_caps,flag) do { \
        (ppeer_caps)->peer_qos |=  (1 << flag);      \
     } while (0)
#define WMI_TDLS_PEER_GET_QOS_FLAG(ppeer_caps,flag)   \
        (((ppeer_caps)->peer_qos & (1 << flag)) >> flag)

#define WMI_SET_TDLS_PEER_VO_UAPSD(ppeer_caps) \
    WMI_TDLS_PEER_SET_QOS_FLAG(ppeer_caps, WMI_TDLS_QOS_VO_FLAG)
#define WMI_GET_TDLS_PEER_VO_UAPSD(ppeer_caps) \
    WMI_TDLS_PEER_GET_QOS_FLAG(ppeer_caps, WMI_TDLS_QOS_VO_FLAG)
#define WMI_SET_TDLS_PEER_VI_UAPSD(ppeer_caps) \
    WMI_TDLS_PEER_SET_QOS_FLAG(ppeer_caps, WMI_TDLS_QOS_VI_FLAG)
#define WMI_GET_TDLS_PEER_VI_UAPSD(ppeer_caps) \
    WMI_TDLS_PEER_GET_QOS_FLAG(ppeer_caps, WMI_TDLS_QOS_VI_FLAG)
#define WMI_SET_TDLS_PEER_BK_UAPSD(ppeer_caps) \
    WMI_TDLS_PEER_SET_QOS_FLAG(ppeer_caps, WMI_TDLS_QOS_BK_FLAG)
#define WMI_GET_TDLS_PEER_BK_UAPSD(ppeer_caps) \
    WMI_TDLS_PEER_GET_QOS_FLAG(ppeer_caps, WMI_TDLS_QOS_BK_FLAG)
#define WMI_SET_TDLS_PEER_BE_UAPSD(ppeer_caps) \
    WMI_TDLS_PEER_SET_QOS_FLAG(ppeer_caps, WMI_TDLS_QOS_BE_FLAG)
#define WMI_GET_TDLS_PEER_BE_UAPSD(ppeer_caps) \
    WMI_TDLS_PEER_GET_QOS_FLAG(ppeer_caps, WMI_TDLS_QOS_BE_FLAG)
#define WMI_SET_TDLS_PEER_ACK_UAPSD(ppeer_caps) \
    WMI_TDLS_PEER_SET_QOS_FLAG(ppeer_caps, WMI_TDLS_QOS_ACK_FLAG)
#define WMI_GET_TDLS_PEER_ACK_UAPSD(ppeer_caps) \
    WMI_TDLS_PEER_GET_QOS_FLAG(ppeer_caps, WMI_TDLS_QOS_ACK_FLAG)

/* SP has 2 bits */
#define WMI_SET_TDLS_PEER_SP_UAPSD(ppeer_caps,val) do { \
     (ppeer_caps)->peer_qos |=  (((val) & 0x3) << WMI_TDLS_QOS_SP_FLAG); \
     } while (0)
#define WMI_GET_TDLS_PEER_SP_UAPSD(ppeer_caps) \
    (((ppeer_caps)->peer_qos & (0x3 << WMI_TDLS_QOS_SP_FLAG)) >> WMI_TDLS_QOS_SP_FLAG)

#define WMI_SET_TDLS_PEER_MORE_DATA_ACK_UAPSD(ppeer_caps) \
    WMI_TDLS_PEER_SET_QOS_FLAG(ppeer_caps, WMI_TDLS_QOS_MOREDATA_FLAG)
#define WMI_GET_TDLS_PEER_MORE_DATA_ACK_UAPSD(ppeer_caps) \
    WMI_TDLS_PEER_GET_QOS_FLAG(ppeer_caps, WMI_TDLS_QOS_MOREDATA_FLAG)

#define WMI_TDLS_SELF_SET_QOS_FLAG(pset_cmd,flag) do { \
        (pset_cmd)->tdls_puapsd_mask |=  (1 << flag);      \
     } while (0)
#define WMI_TDLS_SELF_GET_QOS_FLAG(pset_cmd,flag)   \
        (((pset_cmd)->tdls_puapsd_mask & (1 << flag)) >> flag)

#define WMI_SET_TDLS_SELF_VO_UAPSD(pset_cmd) \
    WMI_TDLS_SELF_SET_QOS_FLAG(pset_cmd, WMI_TDLS_QOS_VO_FLAG)
#define WMI_GET_TDLS_SELF_VO_UAPSD(pset_cmd) \
    WMI_TDLS_SELF_GET_QOS_FLAG(pset_cmd, WMI_TDLS_QOS_VO_FLAG)

#define WMI_SET_TDLS_SELF_VI_UAPSD(pset_cmd) \
    WMI_TDLS_SELF_SET_QOS_FLAG(pset_cmd, WMI_TDLS_QOS_VI_FLAG)
#define WMI_GET_TDLS_SELF_VI_UAPSD(pset_cmd) \
    WMI_TDLS_SELF_GET_QOS_FLAG(pset_cmd, WMI_TDLS_QOS_VI_FLAG)
#define WMI_SET_TDLS_SELF_BK_UAPSD(pset_cmd) \
    WMI_TDLS_SELF_SET_QOS_FLAG(pset_cmd, WMI_TDLS_QOS_BK_FLAG)
#define WMI_GET_TDLS_SELF__BK_UAPSD(pset_cmd) \
    WMI_TDLS_SELF_GET_QOS_FLAG(pset_cmd, WMI_TDLS_QOS_BK_FLAG)
#define WMI_SET_TDLS_SELF_BE_UAPSD(pset_cmd) \
    WMI_TDLS_SELF_SET_QOS_FLAG(pset_cmd, WMI_TDLS_QOS_BE_FLAG)
#define WMI_GET_TDLS_SELF_BE_UAPSD(pset_cmd) \
    WMI_TDLS_SELF_GET_QOS_FLAG(pset_cmd, WMI_TDLS_QOS_BE_FLAG)
#define WMI_SET_TDLS_SELF_ACK_UAPSD(pset_cmd) \
    WMI_TDLS_SELF_SET_QOS_FLAG(pset_cmd, WMI_TDLS_QOS_ACK_FLAG)
#define WMI_GET_TDLS_SELF_ACK_UAPSD(pset_cmd) \
    WMI_TDLS_SELF_GET_QOS_FLAG(pset_cmd, WMI_TDLS_QOS_ACK_FLAG)


/* SP has 2 bits */
#define WMI_SET_TDLS_SELF_SP_UAPSD(pset_cmd,val) do { \
     (pset_cmd)->tdls_puapsd_mask |=  (((val) & 0x3) << WMI_TDLS_QOS_SP_FLAG); \
     } while (0)
#define WMI_GET_TDLS_SELF_SP_UAPSD(pset_cmd) \
    (((pset_cmd)->tdls_puapsd_mask & (0x3 << WMI_TDLS_QOS_SP_FLAG)) >> WMI_TDLS_QOS_SP_FLAG)

#define WMI_SET_TDLS_SELF_MORE_DATA_ACK_UAPSD(pset_cmd) \
    WMI_TDLS_SELF_SET_QOS_FLAG(pset_cmd, WMI_TDLS_QOS_MOREDATA_FLAG)
#define WMI_GET_TDLS_SELF_MORE_DATA_ACK_UAPSD(pset_cmd) \
    WMI_TDLS_SELF_GET_QOS_FLAG(pset_cmd, WMI_TDLS_QOS_MOREDATA_FLAG)


/** WMI_TDLS_PEER_EVENTID */
typedef struct {
    /** peer MAC address */
    wmi_mac_addr    peer_macaddr;
    /** TDLS peer status (wmi_tdls_peer_notification) */
    A_UINT32        peer_status;
    /** TDLS peer reason (wmi_tdls_peer_reason) */
    A_UINT32        peer_reason;
    /** unique id identifying the VDEV */
    A_UINT32        vdev_id;
} wmi_tdls_peer_event_fixed_param;


/** TDLS EVENTS */
enum wmi_tdls_peer_notification {
    /** tdls discovery recommended for peer (based on tx bytes per second > tx_discover threshold) */
    WMI_TDLS_SHOULD_DISCOVER,
    /** tdls link tear down recommended for peer due to tx bytes per second below tx_teardown_threshold. NB: this notification sent once */
    WMI_TDLS_SHOULD_TEARDOWN,
    /** tx peer TDLS link tear down complete */
    WMI_TDLS_PEER_DISCONNECTED,
    /** TDLS/BT role change notification for connection tracker */
    WMI_TDLS_CONNECTION_TRACKER_NOTIFICATION,
};

enum wmi_tdls_peer_reason {
    /** tdls teardown recommended due to low transmits */
    WMI_TDLS_TEARDOWN_REASON_TX,
    /** tdls link tear down recommended due to poor RSSI */
    WMI_TDLS_TEARDOWN_REASON_RSSI,
    /** tdls link tear down recommended due to offchannel scan */
    WMI_TDLS_TEARDOWN_REASON_SCAN,
    /** tdls peer disconnected due to peer deletion */
    WMI_TDLS_DISCONNECTED_REASON_PEER_DELETE,
    /** tdls peer disconnected due to PTR timeout */
    WMI_TDLS_TEARDOWN_REASON_PTR_TIMEOUT,
    /** tdls peer disconnected due wrong PTR format */
    WMI_TDLS_TEARDOWN_REASON_BAD_PTR,
    /** tdls peer not responding */
    WMI_TDLS_TEARDOWN_REASON_NO_RESPONSE,
    /** tdls entered buffer STA role, TDLS connection tracker needs to handle this */
    WMI_TDLS_ENTER_BUF_STA,
    /** tdls exited buffer STA role, TDLS connection tracker needs to handle this */
    WMI_TDLS_EXIT_BUF_STA,
    /** BT entered busy mode, TDLS connection tracker needs to handle this */
    WMI_TDLS_ENTER_BT_BUSY_MODE,
    /** BT exited busy mode, TDLS connection tracker needs to handle this */
    WMI_TDLS_EXIT_BT_BUSY_MODE,
    /** TDLS module received a scan start event, TDLS connection tracker needs to handle this */
    WMI_TDLS_SCAN_STARTED_EVENT,
    /** TDLS module received a scan complete event, TDLS connection tracker needs to handle this */
    WMI_TDLS_SCAN_COMPLETED_EVENT,
};

/*
 * Host DFS check WMI command structure
 * WMI_HOST_DFS_RADAR_FOUND_CMDID
 */
typedef struct {
    /** Host provides the min and max values of PRI, Duration and SidX detected
     *  from the radar pulses to confirm the radar detection on the DFS channel
     */
    A_UINT32 pri_min_value;
    A_UINT32 pri_max_value;
    A_UINT32 duration_min_value;
    A_UINT32 duration_max_value;
    A_UINT32 sidx_min_value;
    A_UINT32 sidx_max_value;
} wmi_host_dfs_radar_found_cmd;

/*
 * Host DFS check status
 * WMI_HOST_DFS_CHECK_STATUS
 */
typedef enum {
    /** Host indicates RADAR detected and the FW confirms it to be spoof radar
     * to host - WMI_HOST_DFS_CHECK_PASSED
     */
    WMI_HOST_DFS_CHECK_PASSED = 0,
    /** Host doesnt indicate RADAR detected OR Spoof radar parameters indicated
     * by WMI_HOST_DFS_RADAR_FOUND_CMDID doesnt match -
     * WMI_HOST_DFS_CHECK_FAILED
     */
    WMI_HOST_DFS_CHECK_FAILED = 1,
    /** Host indicates RADAR detected and the FW confirms it to be real HW radar
     * to host - WMI_HOST_DFS_CHECK_HW_RADAR
     */
    WMI_HOST_DFS_CHECK_HW_RADAR = 2,
} WMI_HOST_DFS_CHECK_STATUS;

/*
 * Host DFS check status WMI event structure
 * WMI_HOST_DFS_STATUS_CHECK_EVENTID
 */
typedef struct {
    /** FW indicates the status of the host DFS check.
     *  WMI_HOST_DFS_CHECK_STATUS indicated.
     */
    A_UINT32 status;
} wmi_host_dfs_status_check_event;

/*
 * DFS Region
 */
typedef enum {
    /* DFS_UNINIT_REG: Un-Initialized Region */
    DFS_UNINIT_REG = 0,
    /* DFS_FCC_REG: FCC Region */
    DFS_FCC_REG = 1,
    /* DFS_ETSI_REG: ETSI Region */
    DFS_ETSI_REG = 2,
    /* DFS_MKK_REG: MKK Region */
    DFS_MKK_REG = 3,
    /* DFS_CN_REG: China Region */
    DFS_CN_REG = 4,
    /* DFS_KR_REG: Korea Region */
    DFS_KR_REG = 5,
    /* DFS_UNDEF_REG: Undefined Region */
    DFS_UNDEF_REG = 0xFFFF,
} DFS_REGION;

/**
 * The request IDs RATECTRL_HOST_MEM_REQ_ID, CV_POOL0_MEM_REQ_ID,
 * CV_POOL1_MEM_REQ_ID, CV_POOL2_MEM_REQ_ID, PEER_CACHING_HOST_MEM_REQ_ID,
 * SCAN_CHANNEL_CAL_HOST_MEM_REQ_ID, HOME_CHANNEL_CAL_HOST_MEM_REQ_ID,
 * IRAM_RECOVERY_HOST_MEM_REQ_ID were defined individually by different
 * WLAN FW modules.  However, these REQ_ID defs are not only echoed back
 * in the host->target memory request response, but furthermore are
 * interpreted by the host while checking on the memory requests.
 * Since host and target both interpret the values of these memory request
 * IDs, the REQ_ID defs are part of the host/target interface, and therefore
 * are moved to the WMI interface specification.
 */
typedef enum {
    WMI_RATECTRL_HOST_MEM_REQ_ID = 1,
    WMI_CV_POOL0_MEM_REQ_ID = 2,
    WMI_CV_POOL1_MEM_REQ_ID = 3,
    WMI_CV_POOL2_MEM_REQ_ID = 4,
    WMI_PEER_CACHING_HOST_MEM_REQ_ID = 5,
    WMI_SCAN_CHANNEL_CAL_HOST_MEM_REQ_ID = 6,
    WMI_HOME_CHANNEL_CAL_HOST_MEM_REQ_ID = 7,
    WMI_IRAM_RECOVERY_HOST_MEM_REQ_ID = 8,
    WMI_CHANNEL_CAPTURE_HOST_MEM_REQ_ID = 9,
} WMI_HOST_MEM_REQ_ID;

/* The below enable/disable macros are used for both per peer CFR capture
 * control (as in wmi_peer_cfr_capture_cmd) and control of the entire periodic
 * CFR capture feature (as in WMI_PDEV_PARAM_PER_PEER_PERIODIC_CFR_ENABLE)
 */
#define WMI_PEER_CFR_CAPTURE_ENABLE   1
#define WMI_PEER_CFR_CAPTURE_DISABLE  0

#define WMI_PEER_CFR_ONE_SHOT_REQUEST 0
#define WMI_PEER_CFR_PERIODICITY_MIN  10 /* 10ms */
#define WMI_PEER_CFR_PERIODICITY_MAX  10*60*1000 /* 10 minutes */

/* Bandwidth of peer CFR captures */
typedef enum {
    WMI_PEER_CFR_CAPTURE_BW_20MHZ    = 0,
    WMI_PEER_CFR_CAPTURE_BW_40MHZ    = 1,
    WMI_PEER_CFR_CAPTURE_BW_80MHZ    = 2,
    WMI_PEER_CFR_CAPTURE_BW_160MHZ   = 3,
    WMI_PEER_CFR_CAPTURE_BW_80_80MHZ = 4,
    WMI_PEER_CFR_CAPTURE_BW_MAX,
} WMI_PEER_CFR_CAPTURE_BW;

/* Peer CFR capture method */
typedef enum {
    /* Send null frame on the requested bw and capture CFR on ACK */
    WMI_PEER_CFR_CAPTURE_METHOD_NULL_FRAME = 0,
    /* New methods to be added here */
    WMI_PEER_CFR_CAPTURE_METHOD_MAX,
} WMI_PEER_CFR_CAPTURE_METHOD;

/*
 * Peer command structure to configure the CFR capture
 */
typedef struct {
    /* WMI_PEER_CFR_CAPTURE_ENABLE: Enable CFR capture for the peer
     * WMI_PEER_CFR_CAPTURE_DISABLE: Disable CFR capture for the peer
     */
    A_UINT32 request;
    /* Peer MAC address. In AP mode, this is the address of the connected peer
     * for which CFR capture is needed. In case of STA mode, this is the address
     * of the AP to which the STA is connected
     */
    wmi_mac_addr mac_addr;
    /* vdev id */
    A_UINT32 vdev_id;
    /* Periodicity of measurement in ms.
     * WMI_PEER_CFR_ONE_SHOT_REQUEST: One-shot request i.e., Only one CFR
     * capture for the request and no periodic CFR captures.
     * The min value is WMI_PEER_CFR_PERIODICITY_MIN
     * The max value is WMI_PEER_CFR_PERIODICITY_MAX
     */
    A_UINT32 periodicity;
    /* BW of measurement - of type WMI_PEER_CFR_CAPTURE_BW */
    A_UINT32 bandwidth;
    /* Method used to capture CFR - of type WMI_PEER_CFR_CAPTURE_METHOD */
    A_UINT32 capture_method;
} wmi_peer_cfr_capture_cmd;

/*
 * ACK policy to be followed for the TID
 */
typedef enum {
  /* Used when the host does not want to configure the ACK policy */
  WMI_PEER_TID_CONFIG_ACK_POLICY_IGNORE,
  /* Allow ACK for the TID */
  WMI_PEER_TID_CONFIG_ACK,
  /* Do not expect ACK for the TID */
  WMI_PEER_TID_CONFIG_NOACK,
} WMI_PEER_TID_CONFIG_ACK_POLICY;

/*
 * Aggregation control policy for the TID
 */
typedef enum {
  /* Used when the host does not want to configure the aggregation policy */
  WMI_PEER_TID_CONFIG_AGGR_CONTROL_IGNORE,
  /* Enable aggregation for the TID */
  WMI_PEER_TID_CONFIG_AGGR_CONTROL_ENABLE,
  /* Disable aggregation for the TID */
  WMI_PEER_TID_CONFIG_AGGR_CONTROL_DISABLE,
} WMI_PEER_TID_CONFIG_AGGR_CONTROL;

/*
 * Rate control policy for the TID
 */
typedef enum {
  /* Used when the host does not want to configure the rate control policy */
  WMI_PEER_TID_CONFIG_RATE_CONTROL_IGNORE,
  /* Auto rate control */
  WMI_PEER_TID_CONFIG_RATE_CONTROL_AUTO,
  /* Fixed rate control */
  WMI_PEER_TID_CONFIG_RATE_CONTROL_FIXED_RATE,
  /* Set the Default lowest rate 6Mbps in 5GHZ and 1Mbps in 2GHZ */
  WMI_PEER_TID_CONFIG_RATE_CONTROL_DEFAULT_LOWEST_RATE,
} WMI_PEER_TID_CONFIG_RATE_CONTROL;

/*
 * SW retry threshold for the TID
 */
typedef enum {
  /* Used when the host does not want to configure the SW retry threshold */
  WMI_PEER_TID_SW_RETRY_IGNORE = 0,
  WMI_PEER_TID_SW_RETRY_MIN = 1,
  WMI_PEER_TID_SW_RETRY_MAX = 30,
  /* No SW retry for the TID */
  WMI_PEER_TID_SW_RETRY_NO_RETRY = 0xFFFFFFFF,
} WMI_PEER_TID_CONFIG_SW_RETRY_THRESHOLD;

/*
 * Command format for the TID configuration
 */
typedef struct {
  /* unique id identifying the VDEV, generated by the caller */
  A_UINT32 vdev_id;
  /* peer MAC address */
  wmi_mac_addr peer_macaddr;
  /* TID number, generated by the caller.
   * Valid range for QoS TID : 0-15
   * Valid range for non QOS/Mgmt TID: 16-19
   * Any other TID number is invalid.
   */
  A_UINT32 tid_num;
  /* ACK policy - of type WMI_PEER_TID_CONFIG_ACK_POLICY */
  A_UINT32 ack_policy;
  /* Aggregation control - of type WMI_PEER_TID_CONFIG_AGGR_CONTROL */
  A_UINT32 aggr_control;
  /* Rate control - of type WMI_PEER_TID_CONFIG_RATE_CONTROL */
  A_UINT32 rate_control;
  /* Fixed rate control parameters - of type WMI_PEER_PARAM_FIXED_RATE.
   * This is applicable only when rate_control is
   * WMI_PEER_TID_CONFIG_RATE_CONTROL_FIXED_RATE
   * The rate-code (rcode_rcflags) is a 1-byte field in which we have
   * rate, nss and preamble, combined as shown below:
   * b'7-b-6 indicate the preamble (0 OFDM, 1 CCK, 2, HT, 3 VHT)
   * b'5-b'4 indicate the NSS (0 - 1x1, 1 - 2x2, 2 - 3x3)
   * b'3-b'0 indicate the rate as given below:
   * OFDM :     0: OFDM 48 Mbps
   *            1: OFDM 24 Mbps
   *            2: OFDM 12 Mbps
   *            3: OFDM 6 Mbps
   *            4: OFDM 54 Mbps
   *            5: OFDM 36 Mbps
   *            6: OFDM 18 Mbps
   *            7: OFDM 9 Mbps
   * CCK (pream == 1)
   *            0: CCK 11 Mbps Long
   *            1: CCK 5.5 Mbps Long
   *            2: CCK 2 Mbps Long
   *            3: CCK 1 Mbps Long
   *            4: CCK 11 Mbps Short
   *            5: CCK 5.5 Mbps Short
   *            6: CCK 2 Mbps Short
   * HT/VHT (pream == 2/3)
   *            0..7: MCS0..MCS7 (HT)
   *            0..9: MCS0..MCS9 (VHT)
   */
  A_UINT32 rcode_rcflags;
  /* MPDU SW retry threshold - of type WMI_PEER_TID_CONFIG_SW_RETRY_THRESHOLD */
  A_UINT32 sw_retry_threshold;
} wmi_peer_tid_configurations_cmd;

#define WMI_BEACON_CTRL_TX_DISABLE          0
#define WMI_BEACON_CTRL_TX_ENABLE           1
#define WMI_BEACON_CTRL_SWBA_EVENT_DISABLE  2
#define WMI_BEACON_CTRL_SWBA_EVENT_ENABLE   3

/*
 * SWBA and Beacon Control definitions
 * WMI_BCN_OFFLOAD_CTRL_CMDID
 */
typedef struct {
    A_UINT32 vdev_id;
    A_UINT32 bcn_ctrl_op; /* fw default 1 (see WMI_BEACON_CTRL defs) */
} wmi_bcn_offload_ctrl_cmd_fixed_param;



// TEMPORARY CODE TO ALLOW THE HOST, MAC_CORE, AND PROTOCOL TO CONTINUE TO COMPILE/FUNCTION DURING THE TRANSITION
// DELETE ONCE THE HOST HAS BEEN FIXED
#include <rtt_interface.h>
#define WMI_RTT_REPORT_CFR                  RTT_REPORT_PER_FRAME_WITH_CFR
#define WMI_RTT_NO_REPORT_CFR               RTT_REPORT_PER_FRAME_NO_CFR
#define WMI_RTT_AGGREAGET_REPORT_NON_CFR    RTT_AGGREAGET_REPORT_NON_CFR
// END OF TEMPORARY CODE


#ifdef __cplusplus
}
#endif


#endif /*_WMI_UNIFIED_H_*/

/**@}*/
