// This is an auto-generated file from input\cmdTPCCALPWRHandler.s
#ifndef _CMDTPCCALPWRHANDLER_H_
#define _CMDTPCCALPWRHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

#if !defined(WHAL_NUM_11G_CAL_PIERS)
#define WHAL_NUM_11G_CAL_PIERS  14
#define WHAL_NUM_11A_CAL_PIERS  32
#endif
#if !defined(NUM_CAL_GAINS_2G)
#define NUM_CAL_GAINS_2G        13
#define NUM_CAL_GAINS_5G        13
#endif
#if !defined(MAX_NUM_CHAINS)
#define MAX_NUM_CHAINS          4
#endif
#define NUM_MEASURED_PWR        512
#define NUM_CALDATA_2G          256
#define NUM_CALDATA_5G          512

typedef struct tpccalpwr_parms {
    A_INT16	measuredPwr[NUM_MEASURED_PWR];
    A_UINT8	radioId;
    A_UINT8	numMeasuredPwr;
    A_UINT8	phyId;
    A_UINT8	pad[1];
} __ATTRIB_PACK CMD_TPCCALPWR_PARMS;

typedef struct tpccaldata_parms {
    A_UINT8	miscFlags;
    A_UINT8	calData2G[NUM_CALDATA_2G];
    A_UINT16	calData2GOffset;
    A_UINT16	calData2GLength;
    A_UINT8	calData5G[NUM_CALDATA_5G];
    A_UINT16	calData5GOffset;
    A_UINT16	calData5GLength;
    A_UINT8	calData2G_clpc[NUM_CALDATA_2G];
    A_UINT16	calData2GOffset_clpc;
    A_UINT16	calData2GLength_clpc;
    A_UINT8	calData5G_clpc[NUM_CALDATA_5G];
    A_UINT16	calData5GOffset_clpc;
    A_UINT16	calData5GLength_clpc;
    A_UINT8	radioId;
    A_UINT8	numFreq2G;
    A_UINT8	freq2G[WHAL_NUM_11G_CAL_PIERS];
    A_UINT8	numFreq5G;
    A_UINT8	freq5G[WHAL_NUM_11A_CAL_PIERS];
    A_UINT8	numChain;
    A_UINT8	chainMasks[MAX_NUM_CHAINS];
    A_UINT8	numCALPt2G;
    A_INT16	tgtPwr2G[NUM_CAL_GAINS_2G];
    A_UINT8	CALPt2G[NUM_CAL_GAINS_2G];
    A_UINT8	txGains2G[NUM_CAL_GAINS_2G];
    A_UINT8	dacGains2G[NUM_CAL_GAINS_2G];
    A_UINT8	paCfg2G[NUM_CAL_GAINS_2G];
    A_UINT8	numCALPt5G;
    A_INT16	tgtPwr5G[NUM_CAL_GAINS_5G];
    A_UINT8	CALPt5G[NUM_CAL_GAINS_5G];
    A_UINT8	txGains5G[NUM_CAL_GAINS_5G];
    A_UINT8	dacGains5G[NUM_CAL_GAINS_5G];
    A_UINT8	paCfg5G[NUM_CAL_GAINS_5G];
    A_UINT8	phyId;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_TPCCALDATA_PARMS;

typedef void (*TPCCALPWR_OP_FUNC)(void *pParms);
typedef void (*TPCCALDATA_OP_FUNC)(void *pParms);

// Exposed functions

void* initTPCCALPWROpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TPCCALPWROp(void *pParms);

void* initTPCCALDATAOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TPCCALDATAOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDTPCCALPWRHANDLER_H_
