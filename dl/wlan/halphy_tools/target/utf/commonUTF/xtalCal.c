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
#include "cmdXtalCalHandler.h"
#include "xtalCal.h"
#include "radio_dtop_reg_csr.h"
#include <otpstream_api.h>
#include <otpstream_id.h> /* replaces local SECTION_ID definitions */
#include <efuse_api.h>
#if !defined(FPGA)
#include "hw/radio_dtop_reg_csr.h"
#include "hw/syn_reg_csr.h"
#include "hw/chn7_addac_reg_csr.h"
#include "hw/syn_1_reg_csr.h"
#include "ar6000_eeprom.h"
#include "codeswap_api.h"
void utfTxStart(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx);
extern TCMD_CONT_TX tx_tcmdParms;
#if !defined(IPQ4019)
extern A_BOOL g_xtal_cal_flag;
static A_TIMER XtalCal_complete_timer;
void XtalCal_complete_timer_handler(A_HANDLE handler, void *data);
static A_UINT32 XtalCal_complete_timeout0 = 25; //25ms
static A_UINT32 XtalCal_complete_timeout1 = 85; //85ms
static A_UINT32 XtalCal_Tx_Off_timeout2 = 100; //100ms
enum xtal_state_machine {
        WRITE_SYN_PC_0_SYNON_OVR = 0,
        WRITE_SYN_PC_0_SYNON_OVR_DONE,
        XTAL_CAL_INIT_START,
        XTAL_CAL_INIT_DONE,
};

static A_UINT32 xtal_state = XTAL_CAL_INIT_DONE;
#endif
#endif
extern wlan_tcmd_dev_t utf_dev;
//#define A_PRINTF_ONCE A_CMN(printf._printf)

extern void ar900BGenXtalCapData4BrdData(A_UINT8 capIn, A_UINT8 capOut, A_UINT8 disXtalLocalFeature);

extern void ar900BGetXtalCapDacFromBrdData(A_UINT8 *capIn, A_UINT8 *capOut);

static void send2HostXtalParms(wlan_tcmd_dev_t *dev, A_UINT8 capIn, A_UINT8 capOut, A_UINT8 errCode);

typedef enum {
    CTRL_CAL = 0,              // 0  xtal calibration
    CTRL_R_RAM_BUF,            // 1  get the capin/capout value from BDF/EEPROM buf
    CTRL_W_RAM_BUF,            // 2  save the capin/capout value to BDF/EEPROM buf
    CTRL_W_OTP,                // 3  save the capin/capout value to OTP
    CTRL_GET_CAP_RANGE,        // 4  quary the range of capin/capout in decimal value
    CTRL_R_OTP,                // 5  get the capin/capout value from OTP
} XTALCAL_CTRLFLAG;

typedef enum {
    XTAL_CAL_OK                 = 0,//                 0      ?// ok
    XTAL_OTP_WRITE_ERR_LD       = 1,//      ?// locked down already
    XTAL_OTP_WRITE_FAILURE      = 2,//      ?// OTP write failure
    XTAL_OTP_WRITE_ERR_NOT_ATE  = 3,//      ?// not ATEed device
    XTAL_CAL_NOT_LOCKED         = 4,
}XTALCALERRORCODE;

#ifndef FPGA
#if defined(IPQ4019)
SRAM_TEXT
void AdjustXtalCapinCapout(A_UINT8 desire_capOut, A_UINT8 desire_capIn)
{
    // Read current using capin/cap
    A_UINT32 current_capOut = OS_REG_RD_FIELD(TOP9_ADDRESS, TOP9_CAPOUTDAC);
    A_UINT32 current_capIn = OS_REG_RD_FIELD(TOP9_ADDRESS, TOP9_CAPINDAC);

    //A_PRINTF_ALWAYS("%s current_capOut=%d, current_capIn=%d\n", __func__, current_capOut, current_capIn);
    //A_PRINTF_ALWAYS("%s desire_capOut=%d, desire_capIn=%d\n", __func__, desire_capOut, desire_capIn);

    // write current capin/capout to TOP1 to prevent clock glitch
    OS_REG_RMW_FIELD(TOP1_ADDRESS, TOP1_CAPOUTDAC_LS, current_capOut);
    OS_REG_RMW_FIELD(TOP1_ADDRESS, TOP1_CAPINDAC_LS, current_capIn);
    OS_REG_RMW_FIELD(TOP0_ADDRESS, TOP0_LOCALXTAL, 1);

    while (current_capOut != desire_capOut){
        if (current_capOut > desire_capOut)       current_capOut--;
        else if (current_capOut < desire_capOut)  current_capOut++;

        OS_REG_RMW_FIELD(TOP1_ADDRESS, TOP1_CAPOUTDAC_LS, current_capOut);
        A_DELAY_USECS(1000);
    }
    while (current_capIn != desire_capIn){
        if (current_capIn > desire_capIn)      current_capIn--;
        else if (current_capIn < desire_capIn) current_capIn++;

        OS_REG_RMW_FIELD(TOP1_ADDRESS, TOP1_CAPINDAC_LS, current_capIn);
        A_DELAY_USECS(1000);
    }
}
#else //defined(IPQ4019)
SRAM_TEXT
static void xtalCalSetUp(void)
{
#if 0
    OS_REG_RMW_FIELD(TOP0_ADDRESS, TOP0_LOCALXTAL, 1);
    OS_REG_RMW_FIELD(TOP1_ADDRESS, TOP1_XO_VREG18_LS, 1);
    OS_REG_RMW_FIELD(TOP1_ADDRESS, TOP1_XO_VREG11_LS, 2);
    OS_REG_RMW_FIELD(TOP1_ADDRESS, TOP1_BIBXOSC_LS, 4);
    OS_REG_RMW_FIELD(TOP1_ADDRESS, TOP1_LEN_LS, 2);
    OS_REG_RMW_FIELD(TOP1_ADDRESS, TOP1_XO_DCC_EN_LS, 1);
    //OS_REG_RMW_FIELD(TOP1_ADDRESS, TOP1_XO_DRV_DCC_BUF_N_LS, 1);
    OS_REG_RMW_FIELD(TOP1_ADDRESS, TOP1_RESERVED_0, 0);
#endif

    return;
}
#endif //defined(IPQ4019)
#endif

#define SYN_CHECK_COUNT    1

#if !defined(FPGA)
extern wlan_tcmd_dev_t utf_dev;
extern tcmd_state_t tcmd_state;
extern tcmd_tx_stat_t tcmdTxStat;
extern void setRxDeaf(A_UINT32 dataRate);

#if  !defined(IPQ4019)
A_UINT8 g_errCode = 0;
A_UINT8 g_capIn = 82, g_capOut = 32;
void XtalCal_complete_timer_handler(A_HANDLE handler, void *data)
{
    A_UNTIMEOUT(&XtalCal_complete_timer);
    if (xtal_state  == XTAL_CAL_INIT_START) {
//	A_PRINTF_ONCE("XTAL_CAL_INIT_START: g_capIn=%d, g_capOut=%d\n", g_capIn, g_capOut);
        send2HostXtalParms(&utf_dev, g_capIn, g_capOut, XTAL_CAL_OK);
    }
    else if (xtal_state == WRITE_SYN_PC_0_SYNON_OVR) {
        OS_REG_RMW_FIELD(SYN_PC_0_ADDRESS,SYN_PC_0_SYNON_OVR,0x2);
        OS_REG_RMW_FIELD(SYN_PC_0_ADDRESS,SYN_PC_0_SYNON_OVR,0x3);
        A_TIMEOUT_MS(&XtalCal_complete_timer, XtalCal_complete_timeout1, 0);
        xtal_state = WRITE_SYN_PC_0_SYNON_OVR_DONE;
    } else if (xtal_state == WRITE_SYN_PC_0_SYNON_OVR_DONE) {
        setRxDeaf(4);
        xtal_state = XTAL_CAL_INIT_DONE;
        send2HostXtalParms(&utf_dev, g_capIn, g_capOut, g_errCode);
    }

}
#endif
#endif
SRAM_TEXT
A_UINT8 updateXtalCapDAC(A_UINT8 capIn, A_UINT8 capOut)
{
    //A_UINT8 capIn_back,capOut_back;
    A_UINT8 errCode = XTAL_CAL_OK;
#ifndef FPGA
#if defined(IPQ4019)
    AdjustXtalCapinCapout(capOut, capIn);
    setRxDeaf(4);
#else
    g_xtal_cal_flag = TRUE;
    whalEnableAni(FALSE);
   // if (g_xtal_cal_flag == TRUE) {
   //     OS_REG_WRITE(PHY_BB_ACTIVE_ADDRESS, 0);
   //     A_DELAY_USECS(100);
   // }
    xtalCalSetUp(); //it is initialized in INI now (0x7710)
    //OS_REG_RMW_FIELD(CHN7_ADDAC0_ADDRESS, CHN7_ADDAC0_DACFULLSCALE_OVR, 3);
    //A_PRINTF("updateXtalCapDAC: capOut=%d, capIn=%d\n", capOut, capIn);

    OS_REG_RMW_FIELD(TOP1_ADDRESS, TOP1_CAPOUTDAC_LS, capOut);
    OS_REG_RMW_FIELD(TOP1_ADDRESS, TOP1_CAPINDAC_LS, capIn);

    g_capIn  = capIn;
    g_capOut = capOut;
    xtal_state = WRITE_SYN_PC_0_SYNON_OVR;
    if (xtal_state == WRITE_SYN_PC_0_SYNON_OVR || xtal_state == XTAL_CAL_INIT_DONE)
        A_TIMEOUT_MS(&XtalCal_complete_timer, XtalCal_complete_timeout0, 0);
#endif
#endif
    return errCode;
}

#if defined(IPQ4019) && (TARGET_VER == 1)
#include "hw/efuse_reg.h"
#define EFUSE_XTAL_CAPIN_ADDR       (EFUSE_INTF_ADDRESS + 0xD8)
void ipq4019PatchEfuseRead(A_UINT32 offset, A_UINT8 *buf, A_UINT32 buflen)
{
    A_UINT32 temp_val=0;

    if (offset == IPQ4019_XTAL_CAL_OTP_OFFSET){
        /* Special case: to read xtal cal OTP content */
        A_SOC_ADDR_WRITE(WIFICMN_CTRL_REG_ADDRESS, 0x0);

        if(buflen >=2){
            //buf[0]: CAPIN, buf[1]: CAPOUT
            temp_val = A_SOC_ADDR_READ(EFUSE_XTAL_CAPIN_ADDR);
            buf[0] = (A_UINT8)((temp_val >>16) & 0x7F);
            buf[1] = (A_UINT8)((temp_val >>23) & 0x7F);
        }
        return;
    }

    efuse_read(offset, buf, buflen);
}
#endif
/*
SRAM_TEXT
A_UINT8 writeXtalCapData2Otp(A_UINT8 capIn, A_UINT8 capOut)

CODESWAP_MARK_EVICTABLE(A_UINT8, writeXtalCapData2Otp, A_UINT8 capIn, A_UINT8 capOut)*/
SRAM_TEXT
A_UINT8 writeXtalCapData2Otp(A_UINT8 capIn, A_UINT8 capOut)
{
    A_UINT8 errCode = XTAL_CAL_OK;
#ifndef FPGA
#if !defined(IPQ4019)
	A_UINT8 otpBytes[5];
	A_UINT32 nbytes;

    // get the current status in otp static region, such as, locked,  capIn / capOut
	efuse_enable_read();
	efuse_read(0,(A_UINT8*)&otpBytes[0], 5);
	efuse_disable();

    // check if the static region locked or not
	if (1 == (otpBytes[0] & XTAL_OTP_STATICS_REGION_LOCK_MASK)) return (errCode = XTAL_OTP_WRITE_ERR_LD);

    // ATEed or not
	if ( 0==(otpBytes[0]+otpBytes[1]+otpBytes[2])){
       A_PRINTF_ALWAYS("Device is not ATEed! \n");
	   //return (errCode = XTAL_OTP_WRITE_ERR_NOT_ATE);
	}

	// capin or capout is already written
	if (( 0 != (otpBytes[XTAL_OTP_CAPIN_BYTE_OFFSET] & XTAL_OTP_CAPVALUE_MASK)) || ( 0 != (otpBytes[XTAL_OTP_CAPOUT_BYTE_OFFSET]& XTAL_OTP_CAPVALUE_MASK))){
	   return (errCode = XTAL_OTP_WRITE_FAILURE);
	}

	otpBytes[XTAL_OTP_CAPIN_BYTE_OFFSET] |= capIn;
	otpBytes[XTAL_OTP_CAPOUT_BYTE_OFFSET] |= capOut;
//	otpBytes[0] |= 1;

	efuse_enable_write();

	errCode = efuse_write(XTAL_OTP_CAPIN_BYTE_OFFSET,(A_UINT8*)&otpBytes[XTAL_OTP_CAPIN_BYTE_OFFSET], (A_UINT32)2, &nbytes);

//	if(0==errCode)
//	{
//	    errCode = efuse_write(0,(A_UINT8*)&otpBytes[0], (A_UINT32)1, &nbytes);
//	}
	efuse_disable();

    A_DELAY_USECS(500);

#else
    A_UINT8 xtalBuf[2];
    A_UINT32 nbytes;

    // get the current status in otp static region, such as, locked,  capIn / capOut
    efuse_enable_read();
#if (TARGET_VER==1)
    /* efuse_read is buggy, but patch takes ram space.  *
     * try to patch here.                               */
    ipq4019PatchEfuseRead(IPQ4019_XTAL_CAL_OTP_OFFSET, (A_UINT8*)&xtalBuf[0], 2);
#else
    efuse_read(IPQ4019_XTAL_CAL_OTP_OFFSET, (A_UINT8*)&xtalBuf[0], 2);
#endif
    efuse_disable();

    // capin or capout is already written
    if (( 0 != (xtalBuf[0] & XTAL_OTP_CAPVALUE_MASK)) || ( 0 != (xtalBuf[1]& XTAL_OTP_CAPVALUE_MASK))){
        A_PRINTF_ALWAYS("Error: XTAL OTP is already written. CAPIN 0x%X, CAPOUT 0x%X\n", xtalBuf[0], xtalBuf[1]);
        return (errCode = XTAL_OTP_WRITE_FAILURE);
    }

    xtalBuf[0] = capIn;
    xtalBuf[1] = capOut;

    efuse_enable_write();
    errCode = efuse_write(IPQ4019_XTAL_CAL_OTP_OFFSET,(A_UINT8*)&xtalBuf[0], (A_UINT32)2, &nbytes);
    efuse_disable();

    A_PRINTF_ALWAYS("XTAL CAPIN 0x%X CAPOUT 0x%X write status: %d\n", xtalBuf[0], xtalBuf[1], errCode);

    A_DELAY_USECS(500);
#endif
#endif
    return errCode;
}
//CODESWAP_DEFINE_WRAPPER_NONVOIDRET(CODESWAP_ARENA_IRAM, A_UINT8, writeXtalCapData2Otp, A_UINT8 , A_UINT8 );
//extern A_UINT8 writeXtalCapData2Otp(A_UINT8 capIn, A_UINT8 capOut);

SRAM_TEXT
A_UINT8 getXtalCapDataFromOtp(A_UINT8 *capIn, A_UINT8 *capOut)
{
    A_UINT8 errCode = XTAL_CAL_OK;
#ifndef FPGA
#if !defined(IPQ4019)
	A_UINT8 otpBytes[8];

    // get the current status in otp static region
	efuse_enable_read();
	efuse_read(0,(A_UINT8*)&otpBytes[0], 8);
	efuse_disable();

	*capIn = otpBytes[XTAL_OTP_CAPIN_BYTE_OFFSET] & XTAL_OTP_CAPVALUE_MASK;
	*capOut = otpBytes[XTAL_OTP_CAPOUT_BYTE_OFFSET]& XTAL_OTP_CAPVALUE_MASK;
#else
    A_UINT8 xtalBuf[2];

    // get the current status in otp static region
    efuse_enable_read();
#if (TARGET_VER==1)
    /* efuse_read is buggy, but patch takes ram space.  *
     * try to patch here.                               */
    ipq4019PatchEfuseRead(IPQ4019_XTAL_CAL_OTP_OFFSET, (A_UINT8*)&xtalBuf[0], 2);
#else
    efuse_read(IPQ4019_XTAL_CAL_OTP_OFFSET, (A_UINT8*)&xtalBuf[0], 2);
#endif
    efuse_disable();

    *capIn = xtalBuf[0] & XTAL_OTP_CAPVALUE_MASK;
    *capOut = xtalBuf[1]& XTAL_OTP_CAPVALUE_MASK;

#endif
#endif
    return errCode;
}


/* -------------------------------------------------
 * FUNCTION:  xtalCalProc()
 *
 * NOTE:
 *      Handling the host Xtal cal cmds with parameters
 * --------------------------------------------------
 */
/*
SRAM_TEXT
void xtalCalProc(void *pParm)

CODESWAP_MARK_EVICTABLE(void, xtalCalProc, void *pParm)*/
SRAM_TEXT
void xtalCalProc(void *pParm)
{
    A_UINT8 errCode = XTAL_CAL_OK;
    A_UINT8 capIn  = 0, capOut = 0;

    CMD_XTALCALPROC_PARMS *pParms = (CMD_XTALCALPROC_PARMS *)pParm;

    switch(pParms->ctrlFlag)
    {
        case CTRL_CAL:
#if !defined(FPGA) && !defined(IPQ4019)
            pParms->capIn  &= XTAL_CAL_CAPIN_VALUE;
            pParms->capOut &= XTAL_CAL_CAPOUT_VALUE;
            g_errCode = updateXtalCapDAC(pParms->capIn, pParms->capOut);
#else
			errCode = updateXtalCapDAC(pParms->capIn, pParms->capOut);
#endif

            break;

        case CTRL_W_RAM_BUF:
            ar900BGenXtalCapData4BrdData(pParms->capIn, pParms->capOut, 0);
            break;

        case CTRL_R_RAM_BUF:
            ar900BGetXtalCapDacFromBrdData(&capIn, &capOut);
            pParms->capIn = capIn;
            pParms->capOut = capOut;
            break;

        case CTRL_GET_CAP_RANGE:

        #if !defined(FPGA)
            if (tcmd_state.tcmdTxGo != TCMD_CONT_TX_OFF) {
                utfTxStop(&utf_dev, &tx_tcmdParms);
               // A_DELAY_USECS(2000);
                tcmd_state.tcmdTxGo = TCMD_CONT_TX_OFF;
                tcmd_state.tcmdRxGo = TCMD_CONT_RX_OFF;
                A_MEMZERO(&tcmdTxStat, sizeof(struct tcmd_tx_stat_t));
            }
			#if !defined(IPQ4019)
            xtal_state = XTAL_CAL_INIT_START;
            g_capIn = XTAL_CAL_CAPIN_VALUE;
            g_capOut =  XTAL_CAL_CAPOUT_VALUE;
            A_TIMEOUT_MS(&XtalCal_complete_timer, XtalCal_Tx_Off_timeout2, 0);
			#endif
			pParms->capIn = XTAL_CAL_CAPIN_VALUE;
         	pParms->capOut = XTAL_CAL_CAPOUT_VALUE;
        #endif

            break;

        case CTRL_W_OTP:

        	errCode = writeXtalCapData2Otp(pParms->capIn, pParms->capOut);
            ar900BGenXtalCapData4BrdData(pParms->capIn, pParms->capOut, 0);

            break;

        case CTRL_R_OTP:

            getXtalCapDataFromOtp(&capIn, &capOut);

            break;

         default:
             A_PRINTF_ALWAYS("HOST->xtalCalParms-NOT supported: capIn %d, capOut %d  ctrlFlag %d\n", pParms->capIn, pParms->capOut, pParms->ctrlFlag);
             break;
    }

    A_PRINTF_ALWAYS("HOST->xtalCalParms: capIn %d, capOut %d  ctrlFlag %d\n", pParms->capIn, pParms->capOut, pParms->ctrlFlag);
#if !defined(FPGA) && !defined(IPQ4019)
    if (pParms->ctrlFlag == CTRL_CAL || pParms->ctrlFlag == CTRL_GET_CAP_RANGE)
        return;
    else
        send2HostXtalParms(&utf_dev, pParms->capIn, pParms->capOut, errCode);
#else
	send2HostXtalParms(&utf_dev, pParms->capIn, pParms->capOut, errCode);
#endif


    return;
}
//CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void , xtalCalProc, void *);
//extern void xtalCalProc(void *pParm);

// Init xtal Cal  module
SRAM_TEXT
void initXtalCal(void)
{
    registerXTALCALPROCHandler(xtalCalProc);
#if !defined(FPGA) && !defined(IPQ4019)
    A_INIT_TIMER(&XtalCal_complete_timer, XtalCal_complete_timer_handler, NULL);
#endif
    return;
}

/* -------------------------------------------------
* FUNCTION:  send2HostXtalParms()
*
* NOTE:
*	   send cal info to host for cal process
* --------------------------------------------------
*/
SRAM_TEXT
static void send2HostXtalParms(wlan_tcmd_dev_t *dev, A_UINT8 capIn, A_UINT8 capOut, A_UINT8 errCode)
{
#ifndef FPGA
    A_UINT32 tmpCmdCode;
	int tmpParaLen;
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;

	tmpCmdCode = CMD_XTALCALPROCRSP;
	tmpParaLen = 10;

	pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
	         PARM_STATUS, errCode,
			 PARM_CAPVALMIN, CAPDAC_MIN,
			 PARM_CAPVALMAX, CAPDAC_MAX,
			 PARM_CAPIN, capIn,
			 PARM_CAPOUT, capOut);

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

    wmi_tc_cmds_reply_event(dev->wmi,cmdStreamLen,tmpCmdCode,(A_INT8*)rCmdStream);
#endif
    return;
}



