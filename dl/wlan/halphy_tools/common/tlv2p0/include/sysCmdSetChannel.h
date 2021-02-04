// This is an auto-generated file from input/sysCmdSetChannel.s

#ifndef _SYSCMDSETCHANNEL_H_
#define _SYSCMDSETCHANNEL_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

#ifdef USE_TLV2_SYSCMD

typedef struct setchannel_parms {
    A_UINT8	phy_mask;
    A_UINT8	radio_mask;
    A_UINT8	crossing;
    A_UINT8	xconnection;
    A_UINT32	center_channel_R0;
    A_UINT32	center_channel_R1;
    A_UINT8	BW_R0;
    A_UINT8	BW_R1;
    A_UINT8	mode;
    A_UINT8	primary_location_R0;
    A_UINT8	primary_location_R1;
    A_UINT32	cal_mask;
    A_UINT32	force_cal_mask;
    A_UINT8	pad[3];
} __ATTRIB_PACK SYSCMD_SETCHANNEL_PARMS;

typedef struct setchannelrsp_parms {
    A_UINT8	phy_mask;
    A_UINT8	radio_mask;
    A_UINT8	crossing;
    A_UINT8	xconnection;
    A_UINT32	center_channel_R0;
    A_UINT32	center_channel_R1;
    A_UINT8	BW_R0;
    A_UINT8	BW_R1;
    A_UINT8	mode;
    A_UINT8	primary_location_R0;
    A_UINT8	primary_location_R1;
    A_UINT32	cal_mask;
    A_UINT32	force_cal_mask;
    A_UINT8	pad[3];
} __ATTRIB_PACK SYSCMD_SETCHANNELRSP_PARMS;

typedef void (*SETCHANNEL_OP_FUNC)(void *pParms);
typedef void (*SETCHANNELRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initSETCHANNELOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL SETCHANNELOp(void *pParms);

void* initSETCHANNELRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL SETCHANNELRSPOp(void *pParms);

#endif //USE_TLV2_SYSCMD

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_SYSCMDSETCHANNEL_H_
