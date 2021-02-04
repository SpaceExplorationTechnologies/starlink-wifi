// dk_cmds.h - contains definitions for dk command ID 

// Copyright (c) 2000 Atheros Communications, Inc., All Rights Reserved 

//NON-PORTABLE: #ident	"ACI $Id: //depot/sw/qca_main/components/wlan/qca-wifi-fw/1.2/drivers/include/systemtools/ar6003/dk_cmds.h#2 $, $Header: //depot/sw/qca_main/components/wlan/qca-wifi-fw/1.2/drivers/include/systemtools/ar6003/dk_cmds.h#2 $"

// modification history
// --------------------
// 00jan02 	sharmat		created (copied from windows client)

// DESCRIPTION
// -----------
// Contains the IDs for all of the commands sent between dk_master and dk_client.

/*
 * Copyright (c) 2013 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef	 _DKCMDIDS_H_
#define	 _DKCMDIDS_H_


enum COMMAND_IDS {
    INIT_F2_CMD_ID,                         //0
    SELECT_HW_CMD_ID,                       //1
    MEM_WRITE_CMD_ID,                       //2
    MEM_READ_CMD_ID,                        //3 
    REG_READ_CMD_ID,                        //4
    REG_WRITE_CMD_ID,                       //5
    CFG_READ_CMD_ID,                        //6
        CFG_WRITE_CMD_ID,                   //7
        MEM_ALLOC_CMD_ID,                   //8
        MEM_FREE_CMD_ID,                    //9
        MEM_WRITE_BLOCK_CMD_ID,             //10
        MEM_READ_BLOCK_CMD_ID,              //11
        REMAP_HW_CMD_ID,                    //12
        CREATE_EVENT_CMD_ID,                //13
        ANY_EVENTS_CMD_ID,                  //14
        GET_EVENT_CMD_ID,                   //15
        DISCONNECT_PIPE_CMD_ID,             //16
        CLOSE_PIPE_CMD_ID,                  //17
        ISR_FEATURE_ENABLE_CMD_ID,          //18
        ISR_GET_RX_STATS_CMD_ID,            //19
        ISR_GET_TX_STATS_CMD_ID,            //20
        ISR_SINGLE_RX_STAT_CMD_ID,          //21
        ISR_SINGLE_TX_STAT_CMD_ID,          //22    
        WAIT_ON_EVENT_CMD_ID,               //23
    WAIT_ON_TIME_CMD_ID,                    //24
    ISR_FEATURE_DISABLE_CMD_ID,             //25
    M_EEPROM_READ_CMD_ID,                   //26
    M_EEPROM_WRITE_CMD_ID,                  //27
    M_EEPROM_READ_BLOCK_CMD_ID,             //28
    M_EEPROM_WRITE_BLOCK_CMD_ID,            //29
    M_RESET_DEVICE_CMD_ID,                  //30
    M_GENERIC_CMD_ID,                       //31
        M_CHECK_REGS_CMD_ID,                //31
        M_CHANGE_CHANNEL_CMD_ID,            //33
        M_CHECK_PROM_CMD_ID,                //34
        M_REREAD_PROM_CMD_ID,               //35
        M_TX_DATA_SETUP_CMD_ID,             //36
        M_TX_DATA_BEGIN_CMD_ID,             //37
    M_TX_DATA_START_CMD_ID,                 //38
    M_TX_DATA_COMPLETE_CMD_ID,              //39
        M_RX_DATA_SETUP_CMD_ID,             //40
        M_RX_DATA_BEGIN_CMD_ID,             //41
    M_RX_DATA_START_CMD_ID,                 //42
    M_RX_DATA_COMPLETE_CMD_ID,              //43
    M_RX_STATS_SNAPSHOT_CMD_ID,             //44
        M_TXRX_DATA_BEGIN_CMD_ID,           //45
    M_CLEANUP_TXRX_MEMORY_CMD_ID,           //46
        M_TX_GET_STATS_CMD_ID,              //47
        M_RX_GET_STATS_CMD_ID,              //48
        M_RX_GET_DATA_CMD_ID,               //49
        M_TX_CONT_BEGIN_CMD_ID,             //50
    M_TX_CONT_FRAME_BEGIN_CMD_ID,           //51
        M_TX_CONT_END_CMD_ID,               //52
        M_SET_ANTENNA_CMD_ID,               //53
        M_SET_POWER_SCALE_CMD_ID,           //54
        M_SET_TRANSMIT_POWER_CMD_ID,        //55
        M_SET_SINGLE_TRANSMIT_POWER_CMD_ID, //56
        M_DEV_SLEEP_CMD_ID,                 //57
        M_CLOSE_DEVICE_CMD_ID,              //58
    M_CHANGE_FIELD_CMD_ID,                  //59
    M_ENABLE_WEP_CMD_ID,                    //60
    M_ENABLE_PA_PRE_DIST_CMD_ID,            //61
    M_DUMP_REGS_CMD_ID,                     //62
    M_DUMP_PCI_WRITES_CMD_ID,               //63
    M_TEST_LIB_CMD_ID,                      //64
    M_DISPLAY_FIELD_VALUES_CMD_ID,          //65
    M_GET_FIELD_VALUE_CMD_ID,               //66
    M_READ_FIELD_CMD_ID,                    //67
    M_WRITE_FIELD_CMD_ID,                   //68
    M_SET_RESET_PARAMS_CMD_ID,              //69
    M_CHANGE_MULTIPLE_FIELDS_ALL_MODES_CMD_ID, //70 
    M_CHANGE_MULTIPLE_FIELDS_CMD_ID,        //71
    M_GET_FIELD_FOR_MODE_CMD_ID,            //72
    LOAD_AND_RUN_CODE_CMD_ID,               //73
    M_FORCE_SINGLE_PCDAC_TABLE_CMD_ID,      //74
    M_FORCE_PCDAC_TABLE_CMD_ID,             //75
    M_FORCE_POWER_TX_MAX_CMD_ID,            //76
    M_GET_EEPROM_STRUCT_CMD_ID,             //77
    M_GET_DEVICE_INFO_CMD_ID,               //78
    M_WRITE_PROD_DATA_CMD_ID,               //79
    M_WRITE_NEW_PROD_DATA_CMD_ID,           //80
    M_SPECIFY_SUBSYSTEM_CMD_ID,             //81
    M_FORCE_SINGLE_POWER_TX_MAX_CMD_ID,     //82
    M_SET_QUEUE_CMD_ID,                     //83
    M_MAP_QUEUE_CMD_ID,                     //84
    M_CLEAR_KEY_CACHE_CMD_ID,               //85
    RUN_SCREENING_TEST_CMD_ID,              //86
    DIAG_CMD,                               //87
    ENABLE_HW_CAL_CMD,                      //88
    TRAM_WRITE_BLOCK_CMD_ID,                //89
    TRAM_READ_BLOCK_CMD_ID,                 //90
    M_GET_MAX_POWER_CMD_ID,                 //91
    M_GET_PCDAC_FOR_POWER_CMD_ID,           //92
    M_FALSE_DETECT_BACKOFF_VALS_CMD_ID,     //93
    M_GET_MAC_ADDR_CMD_ID,                  //94
    M_MASK_TRIGGER_SWEEP_CMD_ID,            //95
    M_MASK_DETECT_SIGNAL_CMD_ID,            //96
    M_MASK_SET_DEV_NUMS_CMD_ID,             //97
    M_MASK_FORCE_MIN_CCAPWR_CMD_ID,         //98
    M_MASK_CONFIG_CAPTURE_CMD_ID,           //99
    AP_REG_READ_CMD_ID,                     //100
    AP_REG_WRITE_CMD_ID,                    //101
    M_SET_LIB_CONFIG_CMD_ID,                //102
    M_GET_XPDGAIN_CMD_ID,                   //103
    M_SELECT_DEV_NUM_CMD_ID,                //104
    M_GET_POWER_INDEX_CMD_ID,               //105
    M_GET_ART_ANI_LEVEL_CMD_ID,             //106
    M_SET_ART_ANI_LEVEL_CMD_ID,             //107
    M_FTP_DOWNLOAD_FILE_CMD_ID,             //108
    M_GET_CTL_INFO_CMD_ID,                  //109
    M_GET_MAX_LIN_PWR_CMD_ID,               //110
    M_SET_CHAIN_CMD_ID,                     //111
    M_GET_PHASE_CAL_CMD_ID,                 //112
    M_TX_DATA_SETUP_NO_END_PACKET_CMD_ID,   //113
    M_HW_RESET_CMD_ID,                      //114
    M_PLL_PROGRAM_CMD_ID,                   //115
    M_PCI_WRITE_CMD_ID,                     //116
    M_CAL_CHECK_CMD_ID,                     //117
    M_FILL_TX_STATS_CMD_ID,                 //118
    M_CREATE_DESC_CMD_ID,                   //119
    LOAD_AND_PROGRAM_CODE_CMD_ID,           //120
    M_FORCE_SINGLE_PCDAC_TABLE_GRIFFIN_CMD_ID,  //121
    PHS_CHANNEL_TOGGLE_CMD_ID,              //122
    STOP_PHS_CHANNEL_TOGGLE_CMD_ID,         //123
    GENERIC_FN_CALL_CMD_ID,                 //124
    SEND_FRAME_CMD_ID,                      //125
    RECV_FRAME_CMD_ID,                      //126
    M_EEPROM_WRITE_BYTEBASED_BLOCK_CMD_ID,  //127
    GET_ENDIAN_MODE_CMD_ID,                 //128
    M_TX_DATA_AGG_SETUP_CMD_ID,             //129
    M_RX_DATA_AGG_SETUP_CMD_ID,             //130
    IQ_CAL_CMD_ID,                          //131
    RTC_REG_WRITE_CMD_ID,                   //132
    RTC_REG_READ_CMD_ID,                    //133
    M_CHANGE_ADDAC_FIELD_CMD_ID,            //134
    M_SAVE_XPA_BIAS_FREQ_CMD_ID,            //135
    M_PA_OFFSET_CAL_CMD_ID,                 //136

    // tbd: in case more cmds added at main branch
    // migrated from AR6002
    M_EEPROM_READ_LOCS_CMD_ID = 160,        //160
    GET_REF_CLK_SPEED_CMD_ID,               //161
    SLEEP_CMD_ID,                           //162

    ART_IMAGE_DOWNLOAD_ID,                  //163
    ART_TEST_UITRON,                        //164
    ART_TEST_CLIENT,                        //165

    ART_CLIENT_REWIND_ID,                   //166
    ART_THROUGHPUT_TEST_CMD_ID,             //167
    ART_THROUGHPUT_TEST_CMD_ID_1,           //168

    ART_BMI_WRITE_SOC_REGISTER_ID,          //169
    ART_BMI_WRITE_SOC_MEMORY_ID,            //170
    ART_BMI_OP_DONE_ID,                     //171
    ART_BMI_READ_SOC_REGISTER_ID,           //172
    ART_BMI_READ_SOC_TARGET_ID,             //173

    // added for Venus
    OTP_WRITE_CMD_ID,                       //174
    OTP_READ_CMD_ID,                        //175
    OTP_RESET_CMD_ID,                       //176
    EFUSE_READ_CMD_ID,                      //177
    M_WRITE_CARD_LABEL_TO_FILE,             //178

    // Bluetooth commands
    BTART_SEND_CMD_ID,                      //179
    BTART_RECEIVE_CMD_ID,                   //180

    BT_WRITE_CMD_ID,                        //181
    
    // added for AR6004 NART
    M_RX_ENABLE_CMD_ID,                     //182
    M_RX_DATA_STOP_CMD_ID,                  //183
    M_RX_DATA_STATUS_CMD_ID,                //184  

    M_TX_ENABLE_CMD_ID,                     //185
    M_TX_DATA_STOP_CMD_ID,                  //186
    M_TX_DATA_STATUS_CMD_ID,                //187

    EFUSE_WRITE_CMD_ID,                     //188    
    
    M_EEPROM_WRITE_ITEMS_CMD_ID,            //189

    M_STICKY_WRITE_CMD_ID,                  //190
    M_STICKY_CLEAR_CMD_ID,                  //191

    OTP_LOAD_CMD_ID,                        //192
    OTP_ERASE_CMD_ID,                       //193
    OTP_REMAINBYTES_CMD_ID,                 //194
    M_PSAT_CALIBRATION_GET_RESULT,          //195
    TARGET_MEM_CLEAR_CMD_ID,                //196  
    TARGET_CAL_CRC_CMD_ID,                  //197
    NV_SET_MAC_ADDR_CMD_ID=198,
/// SKIP 199 as we have FW_VERSION used in tools
/// DO NOT use CmdId 199
    
    M_EEEPROM_BLOCK_READ_ID= 200,
    M_EEEPROM_BLOCK_WRITE_ID= 201,
    M_HWCAL_RXDCO = 202,
    M_HWCAL_RXFILT = 203,
    M_HWCAL_RXIQ = 204,
    M_HWCAL_TXIQ = 205,
    M_HWCAL_TXCL = 206,
    M_HWCAL_PKDET = 207,

    M_WRITE_FW_BD_ID = 232,
    M_READ_FW_BD_ID = 233,
    M_READ_FW_BD_SIZE_ID = 234,
    NV_GET_MAC_ADDR_CMD_ID = 235,
    M_EEEPROM_BLOCK_ERASE_ID= 236,
    M_EEEPROM_BLOCK_CHECK_ID= 237,
    GET_TX_OFFLINE_POWER_ID= 238,
    NV_SET_MCN_NUM_CMD_ID=239,
    NV_GET_MCN_NUM_CMD_ID=240,
    NOISE_FLOOR_READ_CMD_ID=241,
};


#endif //_DKCMDIDS_H_
