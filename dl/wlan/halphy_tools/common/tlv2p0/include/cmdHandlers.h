// This file is auto-updated when a command is added to the dictionary by running cmdRspDictGenSrc.exe

#if !defined(__CMD_HAHNDLERS_H)
#define __CMD_HAHNDLERS_H

//
// Function prototypes from individual cmd source
//

#include "cmdTPCCALHandler.h"
#include "cmdTPCCALPWRHandler.h"
#include "cmdRxGainCalHandler.h"
#include "cmdRegReadHandler.h"
#include "cmdRegWriteHandler.h"
#include "cmdBasicRspHandler.h"
#include "cmdTxHandler.h"
#include "cmdTxStatusHandler.h"
#include "cmdRxHandler.h"
#include "cmdRxStatusHandler.h"
#include "cmdHwCalHandler.h"
#include "cmdXtalCalHandler.h"
#include "cmdCustOtpSpaceRead.h"
#include "cmdCustOtpSpaceWrite.h"
#include "cmdCustOtpSpaceGetSize.h"
#include "cmdDPDComplete.h"
#include "cmdGetTgtPwr.h"
#include "cmdSetPCIEConfigParam.h"
#include "cmdCommitOtpStream.h"
#include "cmdSetRegDmn.h"
#include "cmdMemWriteHandler.h"
#include "cmdMemReadHandler.h"
#include "cmdConfigHandler.h"
#include "cmdDPDLoopbackTiming.h"
#include "cmdDPDLoopbackAttn.h"
#include "cmdDPDTrainingQuality.h"
#include "cmdDPDAgc2Pwr.h"
#include "cmdLMHWCALHandler.h"
#include "cmdLMHWCALRSPHandler.h"
#include "cmdLMTxHandler.h"
#include "sysCmdSetChannel.h"
#include "cmdMoreSegmentHandler.h"
#include "sysCmdTestData.h"
#include "sysCmdGeneric.h"
#include "cmdLMRxHandler.h"
#include "cmdAdcCaptureHandler.h"
#include "cmdGenWaveformHandler.h"
#include "cmdEnableDfeHandler.h"
#include "cmdCalCalTimeHandler.h"
#include "cmdRxDcoHandler.h"
#include "cmdLMChannelListAndRspHandler.h"
#include "cmdLMTxInitHandler.h"
#include "cmdLMGoHandler.h"
#include "cmdLMQueryHandler.h"
#include "cmdGenericUtfCmdHandler.h"
#include "cmdLMRxInitHandler.h"
#include "cmdNoiseFloorRead.h"
//auto-updated marker - no #include statement after this line (DON'T REMOVE THIS LINE)

// union of all cmd parm structure
typedef struct cmdAllParms {
    union {
        CMD_TPCCAL_PARMS            cmdTPCCALParms;
        CMD_TPCCALRSP_PARMS         rspTPCCALParms;
        CMD_TPCCALPWR_PARMS         cmdTPCCALPWRParms;
        CMD_TPCCALDATA_PARMS        rspTPCCALDATAParms;
        CMD_RXGAINCAL_PARMS		 cmdRXGAINCALParms;
        CMD_RXGAINCALRSP_PARMS		 rspRXGAINCALRSPParms;
        CMD_RXGAINCAL_SIGL_DONE_PARMS	 cmdRXGAINCAL_SIGL_DONEParms;
        CMD_RXGAINCALRSP_DONE_PARMS	 rspRXGAINCALRSP_DONEParms;
        CMD_REGREAD_PARMS		 cmdREGREADParms;
        CMD_REGREADRSP_PARMS		 rspREGREADRSPParms;
        CMD_REGWRITE_PARMS		 cmdREGWRITEParms;
        CMD_REGWRITERSP_PARMS		 rspREGWRITERSPParms;
        CMD_BASICRSP_PARMS		 rspBASICRSPParms;
        CMD_TX_PARMS		 cmdTXParms;
        CMD_TXSTATUS_PARMS		 cmdTXSTATUSParms;
        CMD_TXSTATUSRSP_PARMS		 rspTXSTATUSRSPParms;
        CMD_RX_PARMS		 cmdRXParms;
        CMD_RXSTATUS_PARMS		 cmdRXSTATUSParms;
        CMD_RXSTATUSRSP_PARMS		 rspRXSTATUSRSPParms;
        CMD_HWCAL_PARMS		 cmdHWCALParms;
        CMD_RXRSP_PARMS		 rspRXRSPParms;
        CMD_XTALCALPROC_PARMS		 cmdXTALCALPROCParms;
        CMD_XTALCALPROCRSP_PARMS		 rspXTALCALPROCRSPParms;
        CMD_READCUSTOTPSPACERSP_PARMS		 rspREADCUSTOTPSPACERSPParms;
        CMD_WRITECUSTOTPSPACE_PARMS		 cmdWRITECUSTOTPSPACEParms;
        CMD_WRITECUSTOTPSPACERSP_PARMS		 rspWRITECUSTOTPSPACERSPParms;
        CMD_GETCUSTOTPSIZERSP_PARMS		 rspGETCUSTOTPSIZERSPParms;
        CMD_GETDPDCOMPLETERSP_PARMS		 rspGETDPDCOMPLETERSPParms;
        CMD_GETTGTPWR_PARMS		 cmdGETTGTPWRParms;
        CMD_GETTGTPWRRSP_PARMS		 rspGETTGTPWRRSPParms;
        CMD_SETPCIECONFIGPARAMS_PARMS		 cmdSETPCIECONFIGPARAMSParms;
        CMD_SETREGDMN_PARMS		 cmdSETREGDMNParms;
        CMD_MEMWRITE_PARMS		 cmdMEMWRITEParms;
        CMD_MEMWRITERSP_PARMS		 rspMEMWRITERSPParms;
        CMD_MEMREAD_PARMS		 cmdMEMREADParms;
        CMD_MEMREADRSP_PARMS		 rspMEMREADRSPParms;
        CMD_CONFIG_PARMS		 cmdCONFIGParms;
        CMD_DPDLOOPBACKTIMING_PARMS	 cmdDPDLOOPBACKTIMINGParms;
        CMD_DPDLOOPBACKTIMINGRSP_PARMS	 rspDPDLOOPBACKTIMINGRSPParms;
        CMD_DPDLOOPBACKATTN_PARMS	 cmdDPDLOOPBACKATTNParms;
        CMD_DPDLOOPBACKATTNRSP_PARMS	 rspDPDLOOPBACKATTNRSPParms;
        CMD_DPDTRAININGQUALITY_PARMS	 cmdDPDTRAININGQUALITYParms;
        CMD_DPDTRAININGQUALITYRSP_PARMS	 rspDPDTRAININGQUALITYRSPParms;
        CMD_DPDAGC2PWR_PARMS		 cmdDPDAGC2PWRParms;
        CMD_DPDAGC2PWRRSP_PARMS		 rspDPDAGC2PWRRSPParms;
        CMD_LMHWCAL_PARMS		 cmdLMHWCALParms;
        CMD_LMHWCALRSP_PARMS		 rspLMHWCALRSPParms;
        CMD_LMTX_PARMS		 cmdLMTXParms;
        CMD_MORESEGMENT_PARMS		 cmdMORESEGMENTParms;
        CMD_MORESEGMENTRSP_PARMS		 rspMORESEGMENTRSPParms;
        CMD_LMRX_PARMS		 cmdLMRXParms;

#ifdef USE_TLV2_EXTCMD

        CMD_ADCCAPTURE_PARMS		 cmdADCCAPTUREParms;
        CMD_ADCCAPTURERSP_PARMS		 rspADCCAPTURERSPParms;
        CMD_GENWAVEFORM_PARMS		 cmdGENWAVEFORMParms;
        CMD_GENWAVEFORMRSP_PARMS		 rspGENWAVEFORMRSPParms;
        CMD_ENABLEDFE_PARMS		 cmdENABLEDFEParms;
        CMD_ENABLEDFERSP_PARMS		 rspENABLEDFERSPParms;
        CMD_CALCALTIME_PARMS		 cmdCALCALTIMEParms;
        CMD_CALCALTIMERSP_PARMS		 rspCALCALTIMERSPParms;
        CMD_RXDCOGROUP_PARMS		 cmdRXDCOGROUPParms;
        CMD_RXDCOGROUPRSP_PARMS		 rspRXDCOGROUPRSPParms;
#endif

#ifdef USE_TLV2_SYSCMD

        SYSCMD_SETCHANNEL_PARMS		 sysCmdSETCHANNELParms;
        SYSCMD_SETCHANNELRSP_PARMS		 sysRspSETCHANNELRSPParms;
        SYSCMD_TESTDATA_PARMS		 sysCmdTESTDATAParms;
        SYSCMD_TESTDATARSP_PARMS		 sysRspTESTDATARSPParms;
        SYSCMD_GENERIC_PARMS		 sysCmdGENERICParms;
        SYSCMD_GENERICRSP_PARMS		 sysRspGENERICRSPParms;

#endif
        
        CMD_LMCHANNELLIST_PARMS		 cmdLMCHANNELLISTParms;
        CMD_LMCHANNELLISTRSP_PARMS		 rspLMCHANNELLISTRSPParms;
        CMD_LMTXINIT_PARMS		 cmdLMTXINITParms;
        CMD_LMTXINITRSP_PARMS		 rspLMTXINITRSPParms;
        CMD_LMGO_PARMS		 cmdLMGOParms;
        CMD_LMGORSP_PARMS		 rspLMGORSPParms;
        CMD_LMQUERY_PARMS		 cmdLMQUERYParms;
        CMD_LMQUERYRSP_PARMS		 rspLMQUERYRSPParms;
        CMD_GENERICUTFCMD_PARMS		 cmdGENERICUTFCMDParms;
        CMD_GENERICUTFCMDRSP_PARMS		 rspGENERICUTFCMDRSPParms;
        CMD_LMRXINIT_PARMS		 cmdLMRXINITParms;
        CMD_LMRXINITRSP_PARMS		 rspLMRXINITRSPParms;
        CMD_NOISEFLOORREAD_PARMS		 cmdNOISEFLOORREADParms;
        CMD_NOISEFLOORREADRSP_PARMS		 rspNOISEFLOORREADRSPParms;
    } __ATTRIB_PACK cmdParmU;

} __ATTRIB_PACK CMD_ALL_PARMS;

#endif //#if !defined(__CMD_HAHNDLERS_H)
