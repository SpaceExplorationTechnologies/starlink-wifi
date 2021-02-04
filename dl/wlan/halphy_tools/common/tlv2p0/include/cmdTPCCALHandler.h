// This is an auto-generated file from input\cmdTPCCALHandler.s
#ifndef _CMDTPCCALHANDLER_H_
#define _CMDTPCCALHANDLER_H_

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
#if !defined(MAX_NUM_CHAINS)
#define MAX_NUM_CHAINS           4
#endif //!defined(MAX_NUM_CHAINS)
#if !defined(NUM_CAL_GAINS_2G)
#define NUM_CAL_GAINS_2G        13
#define NUM_CAL_GAINS_5G        13
#endif

typedef struct tpccal_parms {
    A_UINT8	radioId;
    A_UINT8	phyId;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_TPCCAL_PARMS;

typedef struct tpccalrsp_parms {
    A_UINT8	radioId;
    A_UINT8	chanFreq;
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
    A_UINT8	CALPt5G[NUM_CAL_GAINS_5G];
    A_INT16	tgtPwr5G[NUM_CAL_GAINS_5G];
    A_UINT8	txGains5G[NUM_CAL_GAINS_5G];
    A_UINT8	dacGains5G[NUM_CAL_GAINS_5G];
    A_UINT8	paCfg5G[NUM_CAL_GAINS_5G];
    A_UINT8	miscFlags;
    A_UINT8	phyId;
    A_UINT8	pad[1];
} __ATTRIB_PACK CMD_TPCCALRSP_PARMS;

typedef void (*TPCCAL_OP_FUNC)(void *pParms);
typedef void (*TPCCALRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initTPCCALOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TPCCALOp(void *pParms);

void* initTPCCALRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TPCCALRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDTPCCALHANDLER_H_
