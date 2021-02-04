/*
 * Copyright (c) 2013 - 2018 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * 2013 - 2016 Qualcomm Atheros, Inc.
 *
 */
// dk_cmds.h - contains definitions for dk commands

// Copyright (c) 2000 Atheros Communications, Inc., All Rights Reserved

//NON-PORTABLE: #ident	"ACI $Id: //depot/sw/qca_main/components/wlan/qca-wifi-fw/1.2/drivers/include/systemtools/ar6003/dk_cmds.h#2 $, $Header: //depot/sw/qca_main/components/wlan/qca-wifi-fw/1.2/drivers/include/systemtools/ar6003/dk_cmds.h#2 $"

// modification history
// --------------------
// 00jan02 	sharmat		created (copied from windows client)

// DESCRIPTION
// -----------
// Contains the definitions for all of the commands sent between dk_master and dk_client.

#ifndef	 __INCdk_cmdsh
#define	 __INCdk_cmdsh

#ifdef _WINDOWS
    #pragma pack(push, 1)
#endif


#include "wlantype.h"

#include  "athreg.h"
//#if defined(ECOS)
//#else // THIN_CLIENT_BUILD
#include "mdata.h"
#include "manlib.h"
//#endif // THIN_CLIENT_BUILD

#include  "event.h"
#ifndef _MLD
#include "event.h"
#else
#ifdef JUNGO
#include "mld.h"
#endif
#if defined(VXWORKS) || defined(SOC_AP)
#include "hw.h"
#else
#include "common_hw.h"
#endif
#endif // _MLD

#include "cmdStatus.h"

#define MAX_GENERIC_CMD_LEN		1024

#define MAX_NUM_FIELDS			100
#define MAX_PCDACS				64
#define MAX_BUFFER_SIZE			2048
#define NUM_BYTES_PER_EEPROM_LOC  2

#define MPATTERN                (10*4)
#define ATH_MAC_LEN             6
#define RATE_MASK_ROW_MAX       9
#define RATE_POWER_MAX_INDEX    8
#define RATE_MASK_BIT_MAX       32

// defined in otpstream_api.h on target, not available on host
#if defined(AR6002_REV6) || defined(QC98XXDLL)
#define OTPSTREAM_MAXSZ_APP MAX_GENERIC_CMD_LEN
#else
#define OTPSTREAM_MAXSZ_APP 256
#endif //AR6002_REV6

/* As per TLV document 80-Y8050-10 Rev. B
 * Bitmap flags in _CMD_TX_PARMS
 */
#define DESC_STBC_ENA_MASK          0x00000001
#define DESC_STBC_ENA_SHIFT         0
#define DESC_LDPC_ENA_MASK          0x00000002
#define DESC_LDPC_ENA_SHIFT         1
#define PAPRD_ENA_MASK              0x00000004
#define PAPRD_ENA_SHIFT             2
#define TX_STATUS_PER_RATE_MASK		0x00000008
#define TX_STATUS_PER_RATE_SHIFT	3
#define TXRX_DISABLE_FULLHWCAL_MASK     0x00000040
#define TXRX_DISABLE_FULLHWCAL_SHIFT    6
#define BANDEDGE_HC_MASK                0x00000080
#define BANDEDGE_HC_MASK_SHIFT          7

/* Bitmap flags in _CMD_RX_PARMS */
#define RX_STATUS_PER_RATE_MASK     0x00000020
#define RX_STATUS_PER_RATE_SHIFT    5
#define NF_IN_DBM_MASK				0x00000080
#define NF_IN_DBM_SHIFT				7

/* Common Bitmap flags in _CMD_RX_PARMS, _CMD_RX_PARMS */
#define PROCESS_RATE_IN_ORDER_MASK	0x00000010
#define PROCESS_RATE_IN_ORDER_SHIFT      4

enum otpstream_op_app {
        OTPSTREAM_READ_APP  = 1,
        OTPSTREAM_WRITE_APP = 2,
};


#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

struct phsChannelToggle{
	  A_UINT32 devIndex;
      A_INT32 ch_int_cal;
      A_INT32 ch_frac_cal;
      A_INT32 ch1_int;
	  A_INT32 ch1_frac;
	  A_INT32 ch2_int;
	  A_INT32 ch2_frac;
	  A_INT32 delay_us;
};

// command ID's for the commands
#include "dkCmdIds.h"


// number of bytes that can send in a block read or write command.
// limit is impossed by the communications buffers.
#define	MAX_BLOCK_BYTES 3900
#define MAX_FIELD_SIZE 256
#define	MAX_BLOCK_DWORDS (MAX_BLOCK_BYTES / 4)
#define	MAX_BLOCK_SWORDS (MAX_BLOCK_BYTES / 2)
#define MAX_NUM_FIELDS			100

// structures for the commands
typedef struct cmdReply {
	A_UINT32 replyCmdLen;
  	A_UINT32 replyCmdId; // command ID of command to which this is a reply
  	A_UINT32 status; // status of the command
  	A_UCHAR cmdBytes[4000]; // bytes of the command reply
} CMD_REPLY;

#define PSAT_WHAL_NUM_11G_CAL_PIERS_MAX 3
#define PSAT_WHAL_NUM_11A_CAL_PIERS_MAX 8


// ATENTION ATENTION... when you chnage this tructure, please also change
// the structure TCMD_CONT_TX in //olca/include/testcmd.h
typedef	struct TxDataStartParams {
    //TCMD_CONT_TX tCmd;
    A_UINT32                testCmdId;
    A_UINT32                mode;
    A_UINT32                freq;
    A_UINT32                dataRate;
    A_INT32                 txPwr;
    A_UINT32                antenna;
    A_UINT32                enANI;
    A_UINT32                scramblerOff;
    A_UINT32                aifsn;
    A_UINT32                pktSz;
    A_UINT32                txPattern;
    A_UINT32                shortGuard;
    A_UINT32                numPackets;
    A_UINT32                wlanMode;
    A_UINT32                lpreamble;
    A_UINT32                txChain;
    A_UINT32                miscFlags;

    A_UINT32                broadcast;
    A_UCHAR                 bssid[ATH_MAC_LEN];
    A_UINT16                bandwidth;
    A_UCHAR                 txStation[ATH_MAC_LEN];
    A_UCHAR                 rxStation[ATH_MAC_LEN];
    A_UINT32                tpcm;
    A_UINT32                retries;
    A_UINT32                agg;
    A_UINT32                nPattern;
    A_UCHAR                 dataPattern[MPATTERN]; // bytes to be written
    A_INT16                 PsatPower2G_t10[2][PSAT_WHAL_NUM_11G_CAL_PIERS_MAX];//12B
    A_INT8                  PsatOfdmDelta2G_t10[2][PSAT_WHAL_NUM_11G_CAL_PIERS_MAX];//6B
    A_INT16                 PsatPower5G_t10[2][PSAT_WHAL_NUM_11A_CAL_PIERS_MAX]; //32B
    A_INT8                  PsatOfdmDelta5G_t10[2][PSAT_WHAL_NUM_11A_CAL_PIERS_MAX];//16B
    A_UINT16                unUsed4;
// The above is exactly the same as TCMD_CONT_TX
    A_UINT16                rateMaskBitPosition[RATE_POWER_MAX_INDEX];
    A_UINT16                txPower[RATE_POWER_MAX_INDEX];
    A_UINT16                pktLength[RATE_POWER_MAX_INDEX];
    //A_UINT8                 aggPerRate[RATE_POWER_MAX_INDEX];
    A_UINT32                ir;
    A_UINT16                gainIdx;
    A_INT16                 dacGain;
    A_UINT32                forcedGainPad;
} __ATTRIB_PACK TX_DATA_START_PARAMS;

typedef	struct RxDataStartParams {
    A_UINT32 freq;
    A_UINT32 antenna;
    A_UINT32                enANI;
    A_UINT32                promiscuous;
    A_UINT32                wlanMode;
    A_UINT32                rxChain;
    A_UINT32                broadcast;
    A_UCHAR                 bssid[ATH_MAC_LEN];
    A_UINT16                bandwidth;
    A_UCHAR                 rxStation[ATH_MAC_LEN];
    A_UINT16                unUsed2;
    A_UINT32                numPackets;
    A_UINT32                rateMask[RATE_MASK_ROW_MAX];
	A_UINT8                 datacheck;
	A_UINT8                 unUsed[3];
    A_UINT32                freq2;
} __ATTRIB_PACK RX_DATA_START_PARAMS;

typedef struct {
// Always make sure these start bytes are DWORD aligned
	A_UINT16 cmdLen;
  	A_UINT8 cmdID;
    A_INT8 devNum;

  	union {
    		struct memWriteCmd {
      			A_UINT32 writeAddr;
      			A_UINT32 writeValue;
      			A_UINT32 writeSize;
    		} __ATTRIB_PACK MEM_WRITE_CMD;

    		struct memReadCmd {
      			A_UINT32 readAddr;
       			A_UINT32 readSize;
    		} __ATTRIB_PACK MEM_READ_CMD;

    		struct initF2Cmd {
      			A_UINT32 whichF2; // which F2 in system to initialize
    		} __ATTRIB_PACK INIT_F2_CMD;

    		struct regReadCmd {
      			A_UINT32 readAddr; // address to read from
    		} __ATTRIB_PACK REG_READ_CMD;

    		struct regWriteCmd {
      			A_UINT32 writeAddr; // address to write to
      			A_UINT32 regValue; // value to write
    		} __ATTRIB_PACK REG_WRITE_CMD;
               struct rtcRegReadCmd {
                               A_UINT32 readAddr; // address to read from
               } __ATTRIB_PACK RTC_REG_READ_CMD;

               struct rtcRegWriteCmd {
                               A_UINT32 writeAddr; // address to write to
                               A_UINT32 regValue; // value to write
               } __ATTRIB_PACK RTC_REG_WRITE_CMD;

    		struct selectHwCmd {
      			A_UINT32 whichF2; // which F2 in system to initialize
    		} __ATTRIB_PACK SELECT_HW_CMD;

    		struct cfgReadCmd {
      			A_UINT32 cfgReadAddr; // address to read from
      			A_UINT32 readSize;  // size to read 32, 16 or 8
    		} __ATTRIB_PACK CFG_READ_CMD;

    		struct cfgWriteCmd {
      			A_UINT32 cfgWriteAddr; // address to write to
      			A_UINT32 cfgValue; // value to write
      			A_UINT32 writeSize; // size to write, 32, 16 or 8
    		} __ATTRIB_PACK CFG_WRITE_CMD;

    		struct memReadBlockCmd {
      			A_UINT32 physAddr; // phys address to read from
      			A_UINT32 length; // how many bytes to read
    		} __ATTRIB_PACK MEM_READ_BLOCK_CMD;

    		struct memWriteBlockCmd {
      			A_UINT32 physAddr; // phys address to allocate at
      			A_UINT32 length; // how many bytes to write
      			A_UINT8 bytes[MAX_BLOCK_BYTES]; // bytes to be written
    		} __ATTRIB_PACK MEM_WRITE_BLOCK_CMD;

    		struct remapHwCmd {
      			A_UINT32 mapAddress; // new address to map to
    		} __ATTRIB_PACK REMAP_HW_CMD;

    		struct createEventCmd {
      			A_UINT32 type;
      			A_UINT32 persistent;
      			A_UINT32 param1;
      			A_UINT32 param2;
      			A_UINT32 param3;
      			EVT_HANDLE eventHandle;
    		} __ATTRIB_PACK CREATE_EVENT_CMD;

    		// devNum command struct is for all funcs that only take
    		// only a devNum as an argument
    		struct eepromReadCmd {
      			A_UINT32 offset;
    		} __ATTRIB_PACK EEPROM_READ_CMD;

    		struct eepromWriteCmd {
      			A_UINT32 offset;
      			A_UINT32 value;
    		} __ATTRIB_PACK EEPROM_WRITE_CMD;

            struct hwResetCmd {
                    A_UINT8 resetMask;
            } __ATTRIB_PACK HW_RESET_CMD;

            struct pllProgramCmd {
                    A_UINT8 turbo;
                    A_UINT8 mode;
            } __ATTRIB_PACK PLL_PROGRAM_CMD;

			struct pciWriteCmd {
					A_UINT32 length;
					PCI_VALUES pPciValues[MAX_PCI_ENTRIES_PER_CMD];
			} __ATTRIB_PACK PCI_WRITE_CMD;

			struct calCheckCmd {
				A_UINT32 enableCal;
				A_UINT32 timeout;
			} __ATTRIB_PACK CAL_CHECK_CMD;

    		struct fillTxStatsCmd {
      			A_UINT32 descAddress;
      			A_UINT32 numDesc;
      			A_UINT32 dataBodyLen;
      			A_UINT32 txTime;
			} __ATTRIB_PACK FILL_TX_STATS_CMD;

    		struct createDescriptors {
      			A_UINT32 descBaseAddress;
      			A_UINT32 descInfo;
      			A_UINT32 bufAddrIncrement;
      			A_UINT32 descOp;
				A_UINT32 descWords[MAX_DESC_WORDS];
			} __ATTRIB_PACK CREATE_DESC_CMD;

		struct eepromReadBlockCmd {
      			A_UINT32 startOffset;
      			A_UINT32 length; // how many eeprom words to read
    		} __ATTRIB_PACK EEPROM_READ_BLOCK_CMD;

    		struct eepromWriteBlockCmd {
      			A_UINT32 startOffset;
      			A_UINT32 length; // how many eeprom words to read
      			A_UINT32 eepromValue[MAX_BLOCK_DWORDS]; // words to be written
    		} __ATTRIB_PACK EEPROM_WRITE_BLOCK_CMD;

                struct eepromWriteByteBasedBlockCmd {
                        A_UINT32 startOffset;
                        A_UINT32 length; // how many eeprom bytes to read
                        A_UINT8 eepromValue[MAX_BLOCK_BYTES]; // bytes to be written
                } __ATTRIB_PACK EEPROM_WRITE_BYTEBASED_BLOCK_CMD;

    		struct apRegReadCmd {
      			A_UINT32 readAddr; // address to read from
       			A_UINT32 readSize;
    		} __ATTRIB_PACK AP_REG_READ_CMD;

    		struct apRegWriteCmd {
      			A_UINT32 writeAddr; // address to write to
      			A_UINT32 regValue; // value to write
      			A_UINT32 writeSize;
    		} __ATTRIB_PACK AP_REG_WRITE_CMD;

			struct writeProdDataCmd	{
				A_UCHAR wlan0Mac[6];
				A_UCHAR wlan1Mac[6];
				A_UCHAR enet0Mac[6];
				A_UCHAR enet1Mac[6];
			} __ATTRIB_PACK WRITE_PROD_DATA_CMD;

			struct eepromReadLocsCmd {
      			A_UINT32 startOffset;
      			A_UINT32 length; // how many eeprom locs to read
                        A_UINT8 useFlash;
    		} __ATTRIB_PACK EEPROM_READ_LOCS_CMD;

	    	struct sleepFnCmd {
				A_UINT32 id;
			} __ATTRIB_PACK SLEEP_CMD;

			struct LoadAndProgramCodeCmd {
				A_UINT32 loadFlag;
				A_UINT32 csAddr;
				A_UINT32 pPhyAddr;
				A_UINT32 length;
 				A_UCHAR  pBuffer[MAX_BUFFER_SIZE];
			} __ATTRIB_PACK LOAD_AND_PROGRAM_CODE_CMD;

	    	struct phsChannelToggle PHS_CHANNEL_TOGGLE_CMD;

	    	struct stopPhsChannelToggleCmd {
				A_UINT8 dummy;
			} __ATTRIB_PACK STOP_PHS_CHANNEL_TOGGLE_CMD;

	    	struct genericFnCallCmd {
				ST_GENERIC_FN_CALL stGFnCallCmd;
			} __ATTRIB_PACK GENERIC_FN_CALL_CMD;

	    	struct sendFrameCmd {
      			A_UINT32 tx_desc_ptr;
      			A_UINT32 tx_buf_ptr;
      			A_UINT32 rx_desc_ptr;
      			A_UINT32 rx_buf_ptr;
      			A_UINT32 rate_code;
 				A_UINT8  pBuffer[MAX_LB_FRAME_LEN];
			} __ATTRIB_PACK SEND_FRAME_CMD;

	    	struct recvFrameCmd {
      			A_UINT32 tx_desc_ptr;
      			A_UINT32 tx_buf_ptr;
      			A_UINT32 rx_desc_ptr;
      			A_UINT32 rx_buf_ptr;
      			A_UINT32 rate_code;
			} __ATTRIB_PACK RECV_FRAME_CMD;

    		struct resetDeviceCmd {
      			A_UCHAR  mac[6];
      			A_UCHAR  bss[6];
      			A_UINT32 freq;
      			A_UINT32 turbo;
      			A_UINT8  wlanMode;
                A_UINT16 rxchain;
                A_UINT16 txchain;
            } __ATTRIB_PACK RESET_DEVICE_CMD;

#if defined(THIN_CLIENT_BUILD)
#else // ECOS
			struct writeNewProdDataCmd	{
				A_UINT32  devNum;
				A_INT32   argList[16];
				A_UINT32  numArgs;
			} __ATTRIB_PACK WRITE_NEW_PROD_DATA_CMD;

    		struct memAllocCmd {
      			A_UINT32 allocSize; // num bytes to allocate
      			A_UINT32 physAddr;  // phys address to allocate at
    		} __ATTRIB_PACK MEM_ALLOC_CMD;

    	 //	struct memFreeCmd {
         //	} MEM_FREE_CMD;

    		struct waitEventCmd {
      			A_UINT32 eventID;
      			A_UINT32 simulationTime;
      			A_UINT32 returnValue;
    		} __ATTRIB_PACK WAIT_EVENT_CMD;

    		struct waitTimeStruct {
      			A_UINT32 timeToWait;
    		} __ATTRIB_PACK WAIT_ON_TIME_CMD;

            struct maskForceMinCCAPWR {
                    A_UINT32 maxccapwr;
            } __ATTRIB_PACK MASK_FORCE_MIN_CCAPWR_CMD;

    		struct isrFeatureEnableCmd {
      			A_UINT32 featureID;
      			A_UINT32 param1;
      			A_UINT32 param2;
    		} __ATTRIB_PACK ISR_FEATURE_ENABLE_CMD;

    		struct isrFeatureDisableCmd {
      			A_UINT32 featureID;
    		} __ATTRIB_PACK ISR_FEATURE_DISABLE_CMD;

    		struct isrGetStatsCmd {
      			A_UINT32 clearOnRead;
    		} __ATTRIB_PACK ISR_GET_STATS_CMD;

    		struct isrSingleStatCmd {
      			A_UINT32 statID;
      			A_UINT32 clearOnRead;
    		} __ATTRIB_PACK ISR_SINGLE_STAT_CMD;

    		// setOne provides a devNum and a single parameter
    		struct setOneCmd {
      			A_UINT32 param;
    		} __ATTRIB_PACK SET_ONE_CMD;

			struct genericCmd
			{
				A_INT32  intVar1;
				A_INT32  intVar2;
				A_INT32  intVar3;
				A_CHAR	 stringVar[MAX_GENERIC_CMD_LEN];
			} __ATTRIB_PACK GENERIC_CMD;

    		struct txDataSetupCmd {
      			A_UINT32 rateMask;
      			A_UCHAR  dest[6];
      			A_UINT32 numDescPerRate;
      			A_UINT32 dataBodyLength;
      			A_UINT32 retries;
      			A_UINT32 antenna;
      			A_UINT32 broadcast;
      			A_UINT32 dataPatternLength;
      			A_UCHAR  dataPattern[MAX_BLOCK_BYTES]; // bytes to be written
    		} __ATTRIB_PACK TX_DATA_SETUP_CMD;

     		struct txDataSetupNoEndPacketCmd {
      			A_UINT32 devNum;
      			A_UINT32 rateMask;
      			A_UCHAR  dest[6];
      			A_UINT32 numDescPerRate;
      			A_UINT32 dataBodyLength;
      			A_UINT32 retries;
      			A_UINT32 antenna;
      			A_UINT32 broadcast;
      			A_UINT32 dataPatternLength;
      			A_UCHAR  dataPattern[MAX_BLOCK_BYTES]; // bytes to be written
    		} __ATTRIB_PACK TX_DATA_SETUP_NO_END_PACKET_CMD;

    		struct txDataBeginCmd {
      			A_UINT32 timeout;
      			A_UINT32 remoteStats;
    		} __ATTRIB_PACK TX_DATA_BEGIN_CMD;

     		struct txDataStartCmd {
                        TX_DATA_START_PARAMS txDataStartParams;
            } __ATTRIB_PACK TX_DATA_START_CMD;

    		struct rxDataSetupCmd {
      			A_UINT32 numDesc;
      			A_UINT32 dataBodyLength;
      			A_UINT32 enablePPM;
    		} __ATTRIB_PACK RX_DATA_SETUP_CMD;

    		struct rxDataAggSetupCmd {
      			A_UINT32 numDesc;
      			A_UINT32 dataBodyLength;
      			A_UINT32 enablePPM;
				A_UINT32 aggSize;
    		} __ATTRIB_PACK RX_DATA_AGG_SETUP_CMD;

			// also used by the txrxDataBegin()
    		struct rxDataBeginCmd {
      			A_UINT32 waitTime;
      			A_UINT32 timeout;
      			A_UINT32 remoteStats;
      			A_UINT32 enableCompare;
      			A_UINT32 dataPatternLength;
      			A_UINT8  dataPattern[MAX_BLOCK_BYTES]; // bytes to be written
    		} __ATTRIB_PACK RX_DATA_BEGIN_CMD;

     		struct rxDataStartCmd {
                        RX_DATA_START_PARAMS rxDataStartParams;
                } __ATTRIB_PACK RX_DATA_START_CMD;

    		struct getStatsCmd {
      			A_UINT32 rateInMb;
      			A_UINT32 remote;
    		} __ATTRIB_PACK GET_STATS_CMD;

    		struct rxGetDataCmd {
      			A_UINT32 bufferNum;
      			A_UINT32 sizeBuffer;
    		} __ATTRIB_PACK RX_GET_DATA_CMD;

    		struct txContBeginCmd {
      			A_UINT32 type;
      			A_UINT32 typeOption1;
      			A_UINT32 typeOption2;
      			A_UINT32 antenna;
    		} __ATTRIB_PACK TX_CONT_BEGIN_CMD;

			struct txContFrameBeginCmd
			{
			  A_UINT32 length;
			  A_UINT32 ifswait;
			  A_UINT32 typeOption1;
			  A_UINT32 typeOption2;
			  A_UINT32 antenna;
			  A_BOOL   performStabilizePower;
			  A_UINT32 numDescriptors;
     	      A_UCHAR  dest[6];
			}  __ATTRIB_PACK TX_CONT_FRAME_BEGIN_CMD;

    		struct setTransmitPowerCmd {
      			A_UCHAR  txPowerArray[17];
    		} __ATTRIB_PACK SET_TRANSMIT_POWER_CMD;


    		struct changeFieldCmd {
      			A_CHAR fieldName[MAX_FIELD_SIZE];
      			A_UINT32  newValue;
    		} __ATTRIB_PACK CHANGE_FIELD_CMD;

		struct enableWepCmd {
			A_UCHAR key;
		} __ATTRIB_PACK ENABLE_WEP_CMD;

		struct enablePAPreDistCmd {
			A_UINT16 rate;
			A_UINT32 power;
		} __ATTRIB_PACK ENABLE_PA_PRE_DIST_CMD;

		struct displayFieldValueCmd {
      			A_CHAR fieldName[MAX_FIELD_SIZE];
    		} __ATTRIB_PACK DISPLAY_FIELD_VALUES_CMD;

		struct getFieldValueCmd {
      			A_CHAR fieldName[MAX_FIELD_SIZE];
	  		A_UINT32 turbo;
    		} __ATTRIB_PACK GET_FIELD_VALUE_CMD;

		struct readFieldcmd {
      			A_CHAR fieldName[MAX_FIELD_SIZE];
      			A_UINT32  printValue;
    		} __ATTRIB_PACK READ_FIELD_CMD;

		struct writeFieldCmd {
      			A_CHAR fieldName[MAX_FIELD_SIZE];
      			A_UINT32  newValue;
    		} __ATTRIB_PACK WRITE_FIELD_CMD;

    		struct setResetParamsCmd {
			A_CHAR fileName[MAX_BUFFER_SIZE];
			A_UINT32 eePromLoad;
			A_UINT32 forceCfgLoad;
			A_UINT32 mode;
            A_UINT16   use_init;   } __ATTRIB_PACK SET_RESET_PARAMS_CMD;

		struct getFieldForModeCmd {
			 A_CHAR   fieldName[MAX_FIELD_SIZE];
			 A_UINT32  mode;
			 A_UINT32  turbo;
		} __ATTRIB_PACK GET_FIELD_FOR_MODE_CMD;
#if !defined(AR6320)
		struct changeMultiFieldsAllModesCmd {
			A_UINT32		  devNum;
			A_UINT32		  numFields;
			PARSE_MODE_INFO FieldsToChange[MAX_NUM_FIELDS];
		} __ATTRIB_PACK CHANGE_MULTI_FIELDS_ALL_MODES_CMD;

		struct changeMultiFieldsCmd {
			A_UINT32		  devNum;
			A_UINT32		  numFields;
			PARSE_FIELD_INFO FieldsToChange[MAX_NUM_FIELDS];
		} __ATTRIB_PACK CHANGE_MULTI_FIELDS_CMD;

		struct changeAddacFieldCmd {
			A_UINT32		  devNum;
			PARSE_FIELD_INFO FieldToChange;
		} __ATTRIB_PACK CHANGE_ADDAC_FIELD_CMD;

		struct saveXpaBiasLvlFreqCmd {
			A_UINT32		  devNum;
			PARSE_FIELD_INFO  FieldToChange;
            A_UINT16           biasLevel;
        } __ATTRIB_PACK SAVE_XPA_BIAS_FREQ_CMD;
#endif //AR6320
        struct forceSinglePcdacTableCmd {
			A_UINT16 pcdac;
		} __ATTRIB_PACK FORCE_SINGLE_PCDAC_TABLE_CMD;

		struct forcePcdacTableCmd {
			A_UINT16 pcdac[MAX_PCDACS];
		} __ATTRIB_PACK FORCE_PCDAC_TABLE_CMD;

        struct processPAOffsetCalCmd {
			A_UINT32		  devNum;
        } __ATTRIB_PACK PA_OFFSET_CAL_CMD_ID;

		struct forcePowerTxMaxCmd {
			A_UINT32 length;
			A_UINT16 ratesPower[MAX_BLOCK_SWORDS];
		} __ATTRIB_PACK FORCE_POWER_TX_MAX_CMD;

		struct getEepromStructCmd {
			A_UINT32 padding;
			A_UINT16 eepStructFlag;
		} __ATTRIB_PACK GET_EEPROM_STRUCT_CMD;


		struct mapQueueCmd {
			A_UINT32 qcuNumber;
			A_UINT32 dcuNumber;
		} __ATTRIB_PACK MAP_QUEUE_CMD;

		struct runScreeningTestCmd {
			A_UINT32 testId;
		} __ATTRIB_PACK RUN_SCREENING_TEST_CMD;

		struct diagCmd {
      			A_UINT32 diagNum;
      			A_UINT32 cmdSize;
      			A_UINT8  data[MAX_BLOCK_BYTES];  // bytes to be written
    		}  __ATTRIB_PACK DIAG_CMD;

		struct getMaxPowerCmd {
			A_UINT32 freq;
			A_UINT32 rate;
		} __ATTRIB_PACK GET_MAX_POWER_CMD;

		struct getPcdacForPower {
			A_UINT32 freq;
			A_INT32 power;
		} __ATTRIB_PACK GET_PCDAC_FOR_POWER_CMD;

		struct falseDetectBackoffValsCmd {
			A_UINT32 backoffValues[3];
		} __ATTRIB_PACK FALSE_DETECT_BACKOFF_VALS_CMD;

		struct getMacAddrCmd {
			A_UINT16 wmac;
			A_UINT16 instNo;
		} __ATTRIB_PACK GET_MAC_ADDR_CMD;

		struct maskConfigCaptureCmd {
			A_UINT32 dut_dev;
			A_UCHAR RX_ID[6];
			A_UCHAR BSS_ID[6];
			A_UINT32 channel;
			A_UINT32 turbo;
			A_UINT32 gain[5];
			A_UINT32 mode;
		} __ATTRIB_PACK MASK_CONFIG_CAPTURE_CMD;

		struct maskDetectSignalCmd {
			A_UINT32 desc_cnt;
			A_UINT32 adc_des_size;
			A_UINT32 mode;
			A_UINT32 ret_length;
		} __ATTRIB_PACK MASK_DETECT_SIGNAL_CMD;

		struct maskTriggerSweepCmd {
			A_UINT32 channel;
			A_UINT32 mode;
			A_UINT32 averages;
			A_UINT32 path_loss;
			A_BOOL   return_spectrum;
			A_UINT32 ret_length;
		} __ATTRIB_PACK MASK_TRIGGER_SWEEP_CMD;

			struct setLibConfigCmd {
				LIB_PARAMS libParams;
			} __ATTRIB_PACK SET_LIB_CONFIG_CMD;

			struct setChainCmd {
				A_UINT32 devNum;
				A_UINT32 curChainSel;
				A_UINT32 curPhaseDelta;
			} __ATTRIB_PACK SET_CHAIN_CMD;

			struct getPhaseCalCmd{
				A_UINT32 devNum;
				A_UINT32 curChan;
			} __ATTRIB_PACK GET_PHASE_CAL_CMD;

			struct getXpdgainCmd {
				A_INT32  power;
			} __ATTRIB_PACK GET_XPDGAIN_CMD;

			struct getPowerIndex {
				A_INT32  power;
			} __ATTRIB_PACK GET_POWER_INDEX_CMD;

			struct getArtAniLevel {
				A_UINT32 artAniType;
			} __ATTRIB_PACK GET_ART_ANI_LEVEL_CMD;

			struct setArtAniLevel {
				A_UINT32 artAniType;
				A_UINT32 artAniLevel;
			} __ATTRIB_PACK SET_ART_ANI_LEVEL_CMD;

			struct ftpDownloadFile {
				A_CHAR hostname[MAX_BUFFER_SIZE];
				A_CHAR user[MAX_BUFFER_SIZE];
				A_CHAR passwd[MAX_BUFFER_SIZE];
				A_CHAR remotefile[MAX_BUFFER_SIZE];
				A_CHAR localfile[MAX_BUFFER_SIZE];

			} __ATTRIB_PACK FTP_DOWNLOAD_FILE_CMD;

			struct getMaxLinPwr {
				A_UINT32 devNum;
			} __ATTRIB_PACK GET_MAX_LIN_PWR_CMD;

			struct LoadAndRunCodeCmd {
				A_UINT32 loadFlag;
				A_UINT32 pPhyAddr;
				A_UINT32 length;
 				A_UCHAR  pBuffer[256];
			} __ATTRIB_PACK LOAD_AND_RUN_CODE_CMD;

			struct forceSinglePcdacTableGriffinCmd {
			    A_UINT16 pcdac;
				A_UINT16 offset;
			} __ATTRIB_PACK FORCE_SINGLE_PCDAC_TABLE_GRIFFIN_CMD;

            struct getEndianMode {
                A_UINT32 devNum;
            } __ATTRIB_PACK GET_ENDIAN_MODE_CMD;

	   		struct txDataAggSetupCmd {
      			A_UINT32 rateMask;
      			A_UCHAR  dest[6];
      			A_UINT32 numDescPerRate;
      			A_UINT32 dataBodyLength;
      			A_UINT32 retries;
      			A_UINT32 antenna;
      			A_UINT32 broadcast;
				A_UINT32 aggSize;
      			A_UINT32 dataPatternLength;
      			A_UCHAR  dataPattern[MAX_BLOCK_BYTES]; // bytes to be written
    		} __ATTRIB_PACK TX_DATA_AGG_SETUP_CMD;

            struct iqCal {
				A_UINT32 devNum;
            } __ATTRIB_PACK IQ_CAL_CMD;


#endif // ECOS
            struct __artImageDownloadCmd{
                A_UINT8  ifEnd; // =1 means end; =0 no end
                A_UINT16 block_length;
                A_UINT8 bytes[2048];
                //A_UINT8 bytes[30*1024];
            } __ATTRIB_PACK ART_IMAGE_DOWNLOAD_CMD;

            struct __artThroughputTestCmd{
                A_UINT32 length;
                A_UINT8 bytes[2*1024];
            } __ATTRIB_PACK ART_THROUGHPUT_TEST_CMD;

            struct _ART_BMI_WRITE_SOC_REGISTER{
                A_UINT32 address;
                A_UINT32 value;
            } __ATTRIB_PACK ART_BMI_WRITE_SOC_REGISTER_CMD;

            struct _ART_BMI_WRITE_SOC_MEMORY{
                A_UINT32 baseaddress;
                A_UINT32 blockLength;
                A_UINT8 byte[2048];
            } __ATTRIB_PACK ART_BMI_WRITE_SOC_MEMORY_CMD;

            struct otpWriteCmd {
                A_UINT32 length;
                A_UINT8 bytes[OTPSTREAM_MAXSZ_APP];
            } __ATTRIB_PACK OTP_WRITE_CMD;

            struct otpReadCmd {
                A_UINT32 length;
            } __ATTRIB_PACK OTP_READ_CMD;

            struct otpResetCmd {
                enum otpstream_op_app resetCmd;
            } __ATTRIB_PACK OTP_RESET_CMD;

            struct efuseReadCmd {
                A_UINT32 startPos;
                A_UINT32 length;
            } __ATTRIB_PACK EFUSE_READ_CMD;

            struct BtArtGenericCmd {
                A_UINT32 length;
                A_UINT8 bytes[MAX_GENERIC_CMD_LEN];
            } __ATTRIB_PACK BTART_GENERIC_CMD;

            struct BtWriteCmd {
                A_UINT32 length;
                A_UINT8 bytes[MAX_GENERIC_CMD_LEN];
            } __ATTRIB_PACK BT_WRITE_CMD;

            struct TxEnableCmd {
                A_UINT32 enable;
                A_UINT32 qmask;
                A_UINT32 yesAgg;
            } __ATTRIB_PACK TX_ENABLE_CMD;

            struct efuseWriteCmd {
                A_UINT32 startPos;
                A_UINT32 length;
                A_UINT8 bytes[16];
            } __ATTRIB_PACK EFUSE_WRITE_CMD;

            struct EepromWriteItemsCmd {
                A_UINT32 numOfItems;
                A_UINT8 buffer[255-8];
            } __ATTRIB_PACK EEPROM_WRITE_ITEMS_CMD;

            struct StickyWriteCmd {
                A_UINT32 numOfRegs;
                A_UINT8 buffer[255-8];
            } __ATTRIB_PACK STICKY_WRITE_CMD;

            struct StickyClearCmd {
                A_UINT32 numOfRegs;
                A_UINT8 buffer[255-8];
            }  __ATTRIB_PACK STICKY_CLEAR_CMD;

            struct otpEraseCmd {
                A_UINT32 dummy;
            } __ATTRIB_PACK OTP_ERASE_CMD;

            struct otpRemainBytesCmd {
                A_UINT32 dummy;
            } OTP_REMAINBYTES_CMD;

            struct TargetMemClear {
                A_UINT32 writeAddr;
                A_UINT32 numBytes;
            } __ATTRIB_PACK TARGET_MEM_CLEAR_CMD;

            struct TargetCalCRC {
                A_UINT32 crcAddr;
                A_UINT32 crcLen;
            } __ATTRIB_PACK TARGET_CAL_CRC_CMD;

    } __ATTRIB_PACK CMD_U;
} __ATTRIB_PACK PIPE_CMD;

extern A_STATUS waitForGenericCmd
(
 void *pSock,
 A_UCHAR   *pStringVar,
 A_UINT32  *pIntVar1,
 A_UINT32  *pIntVar2,
 A_UINT32  *pIntVar3
);

#ifdef __cplusplus
}
#endif //__cplusplus


#ifdef _WINDOWS
    #pragma pack(pop)
#endif

#endif //__INCdk_cmdsh
