/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

#include "tlv2Inc.h"
#include "halphy_internal.h"
#include "wmi_tcmd.h"
#include "tcmdHostInternal.h"
#include "utf_dev.h"
#include "testcmd.h"
#include "utf.h"
#include "tcmd_api.h"
#include "cmdDPDComplete.h"
#include "getDPDComplete.h"
#include <otpstream_api.h>
#include <otpstream_id.h> /* replaces local SECTION_ID definitions */
#include <efuse_api.h>
#include "halphy_mc_paprd.h"

extern wlan_tcmd_dev_t utf_dev;
extern HALPHY_PAPRD_STRUCT *pPaprdStruct;
extern A_BOOL gDPDCalDone;
#if defined(QCA9888)
#define MAX_SEC_CHAINS_VHT160 1
#else
#define MAX_SEC_CHAINS_VHT160 2
#endif

/* -------------------------------------------------
 * FUNCTION:  getDPDComplete()
 *
 * NOTE:
 *      Get DPD complete Flag
 * --------------------------------------------------
 */

//SRAM_TEXT
//void getDPDComplete(void *pParm)
CODESWAP_MARK_EVICTABLE(void, getDPDComplete, void *pParm)
{
    A_UINT32 				tmpCmdCode;
    A_UINT8 				dpdCompleteFlag=0;
    int					tmpParaLen;
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 				*rCmdStream = NULL;
    A_UINT32 				cmdStreamLen=0;
#ifndef FPGA
    A_UINT8 				i,chains=0;
    A_UINT8				dpdBit[4] = {0};
    A_UINT8			        dpdSecBit[2] = {0};
    A_UINT16 				rxmask = 0;
    A_UINT16 				txmask = 0;
    A_UINT8 				sec_chain = 0;

#if defined(QCA9888) && defined(PERCHAIN_TXRX_SUPPORT)
    whalGetPerChainConfig(&txmask, &rxmask);
#else
    whalGetChainMasks(&txmask, &rxmask);
#endif

    if (pPaprdStruct->enable){
        dpdCompleteFlag = 1;

        if (!WHAL_IS_CHAN_VHT160(pPaprdStruct->Chan))
        {

                chains = whalChainMaskToNumChains[txmask];
		dpdBit[0] = OS_REG_RD_FIELD(PHY_BB_PAPRD_CTRL0_B0_ADDRESS,PHY_BB_PAPRD_CTRL0_B0_PAPRD_ENABLE_0);
#if (NUM_SPATIAL_STREAM > 1)
		dpdBit[1] = OS_REG_RD_FIELD(PHY_BB_PAPRD_CTRL0_B1_ADDRESS,PHY_BB_PAPRD_CTRL0_B1_PAPRD_ENABLE_1);
#if (NUM_SPATIAL_STREAM > 2)
		dpdBit[2] = OS_REG_RD_FIELD(PHY_BB_PAPRD_CTRL0_B2_ADDRESS,PHY_BB_PAPRD_CTRL0_B2_PAPRD_ENABLE_2);
#if (NUM_SPATIAL_STREAM > 3)
		dpdBit[3] = OS_REG_RD_FIELD(PHY_BB_PAPRD_CTRL0_B3_ADDRESS,PHY_BB_PAPRD_CTRL0_B3_PAPRD_ENABLE_3);
#endif
#endif
#endif
            for (i=0;i<chains;i++){
               dpdCompleteFlag = dpdCompleteFlag & dpdBit[i];
            }
         }
         else if (WHAL_IS_CHAN_VHT160(pPaprdStruct->Chan))
         {

                  sec_chain = (txmask >> MAX_SEC_CHAINS_VHT160);


		  dpdBit[0] = OS_REG_RD_FIELD(PHY_BB_PAPRD_CTRL0_B0_ADDRESS,PHY_BB_PAPRD_CTRL0_B0_PAPRD_ENABLE_0);
#if (NUM_SPATIAL_STREAM > 1)
		  dpdBit[1] = OS_REG_RD_FIELD(PHY_BB_PAPRD_CTRL0_B1_ADDRESS,PHY_BB_PAPRD_CTRL0_B1_PAPRD_ENABLE_1);
#if (NUM_SPATIAL_STREAM > 2)
		  dpdBit[2] = OS_REG_RD_FIELD(PHY_BB_PAPRD_CTRL0_B2_ADDRESS,PHY_BB_PAPRD_CTRL0_B2_PAPRD_ENABLE_2);
#if (NUM_SPATIAL_STREAM > 3)
		  dpdBit[3] = OS_REG_RD_FIELD(PHY_BB_PAPRD_CTRL0_B3_ADDRESS,PHY_BB_PAPRD_CTRL0_B3_PAPRD_ENABLE_3);
#endif
#endif
#endif
                for (i = 0;i < WHAL_TX_NUM_CHAIN; i++){
                    if (txmask & (0x1 << i))	{
                      dpdCompleteFlag = dpdCompleteFlag & dpdBit[i];
                    }
                }

#if defined(QCA9984)
                dpdSecBit[0] = OS_REG_RD_FIELD(PHY_BB_PAPRD_CTRL0_SEC80_B2_ADDRESS, PHY_BB_PAPRD_CTRL0_SEC80_B2_PAPRD_ENABLE_SEC80_2);
                dpdSecBit[1] = OS_REG_RD_FIELD(PHY_BB_PAPRD_CTRL0_SEC80_B3_ADDRESS, PHY_BB_PAPRD_CTRL0_SEC80_B3_PAPRD_ENABLE_SEC80_3);
#endif
#if defined(QCA9888)
                dpdSecBit[0] = OS_REG_RD_FIELD(PHY_BB_PAPRD_CTRL0_SEC80_B1_ADDRESS, PHY_BB_PAPRD_CTRL0_SEC80_B1_PAPRD_ENABLE_SEC80_1);                   
#endif

                for (i = 0; i < MAX_SEC_CHAINS_VHT160; i++) {
                   if (sec_chain & (0x1 << i))	dpdCompleteFlag = dpdCompleteFlag & dpdSecBit[i];
                }

          }



	  if (gDPDCalDone == FALSE)
              dpdCompleteFlag = 0;
    }
    else
    {
    	dpdCompleteFlag = 2;
    }
#endif

    /* Add delay before sending response for Test Node to settle */
	A_DELAY_USECS(200);

	tmpCmdCode = CMD_GETDPDCOMPLETERSP;
	tmpParaLen = 2;
	pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
	         PARM_DPDCOMPLETE, dpdCompleteFlag
			 );

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;


    wmi_tc_cmds_reply_event(utf_dev.wmi,cmdStreamLen,tmpCmdCode,(A_INT8*)rCmdStream);
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void ,getDPDComplete, void *);
extern void getDPDComplete(void *pParm);

// Init Get DPD complete module
SRAM_TEXT
void iniGetDPDComplete(void)
{
	registerGETDPDCOMPLETEHandler(getDPDComplete);
    return;
}

