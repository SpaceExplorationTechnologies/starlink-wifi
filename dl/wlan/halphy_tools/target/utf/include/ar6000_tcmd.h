/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/*
 * Copyright (c) 2002-2006 Atheros Communications, Inc.
 * All rights reserved.
 * $ATH_LICENSE_TARGET_C$
 * 
 */

#ifndef _ATH_AR6000_TCMD_H_
#define _ATH_AR6000_TCMD_H_

extern void ar6000ContReduceTxFluctuation();
extern void ar6000SingleCarrierConfig(A_UINT32 *stbl1,
                                       A_UINT32 *stbl2, A_UINT32 antenna);
extern void ar6000SingleCarrierEnable(A_UINT32 freq, A_UINT32 txpwr, A_UINT32 chainmask);
extern void ar6000ForceWakeMac();
extern void ar6000ForceSleepMac();
extern void ar6000SetupAntenna(A_UINT32 antenna);

extern void ar6000DisAck(A_BOOL flag);
extern void ar6000EnableBackoff();
extern void ar6000DisableBackoff();
extern void ar6000GetAntSwitchTbl();
extern void ar6000SetAntSwitchTbl(A_UINT32 antSwitchTbl1, A_UINT32 antSwitchTbl2);
extern void ar6000SetupAntenna(A_UINT32 ant);
extern void ar6000EnableWeakSignalDetection();
extern void ar6000ReducePacketGap(A_UINT16 queueIndex, A_UINT32 interval, A_UINT32 aifswait, A_BOOL retries);
extern void ar6000ContTXTestMode(A_BOOL enable);

extern A_BOOL ar6000SetPowerModeAwake();
extern A_BOOL ar6000SetPowerModeSleep();
extern void ar6000ToggleAni(A_UINT8 enAni);
extern void ar6000DisableScramble(A_BOOL disable);
extern void ar6000HackMCS3DesiredScale(A_UINT32 dataRate);
extern void ar6000PwrOnOffMAC(A_BOOL enable);
extern void ar6000PostResetRegOverwrite(void *pParm);
extern A_UINT16 ar6000ForceTxGain(A_UINT16 pcDac);
extern void ar6000PostResetSetupOlpcCAL(void *data);
extern void ar6000SetWlanKeepAwakeCount(A_UINT32 count);
extern void ar6000SetTransmitContentionWindow(int dcu, int cwmin, int cwmax);
extern void ar6000ReceiveDeafMode(A_UINT32 deaf);
#if defined(AR9888) || defined(AR900B) || defined(QCA9984) || defined(IPQ4019) || defined(QCA9888)
extern void ar6000ForceTxGainIdx(A_UINT8 gainIdx, A_INT8 dacGain,A_UINT8 txchain_mask);
#else // AR6320
extern void ar6000ForceTxGainIdx(A_UINT8 paConfig, A_UINT8 gainIdx, A_INT8 dacGain,A_UINT8 txchain_mask);
#endif
extern void ar6000ForceTxTgtPwr(A_UINT16 tgtPwr, A_UINT8 txchain_mask);

extern void ar6000SetTpcForceClpcWfm(A_UINT32 freq, A_UINT8 chainmask, A_UINT8 gainIdx);
extern void ar6000DisTpcForceClpcWfm(A_UINT32 freq, A_UINT8 chainmask);
extern void ar6000SetTpcForceClpcPacket(A_UINT32 freq, A_UINT8 chainmask, A_UINT8 gainIdx, A_INT8 dacGain, A_UINT8 paCfg, A_UINT8 clpcmode, A_UINT8 tpcl);
extern void ar6000SetTpcForceOlpcPacket(A_UINT32 freq, A_UINT8 gainIdx, A_INT8 dacGain);
extern void ar6000SetTpcForceClpc(A_UINT32 freq, A_UINT8 chainmask);
extern void ar6000SetPdetDcOffset(A_UINT32 freq, A_UINT8 chainmask);
extern void ar6000SetTpcForceCplcPwr(A_UINT32 freq, A_UINT8 gainIdx, A_UINT8 chainmask);
extern A_UINT16 ar6000GetPdetPdadcWfm(A_UINT32 freq, A_UINT8 chainmask);
extern void ar6000GetPdetPdadcPacket(A_UINT32 freq, A_UINT8 chainMask, A_UINT8 avg[]);

typedef struct hal_tcmd_t{
   A_UINT32            antSwitchTbl1;
   A_UINT32            antSwitchTbl2;
   A_UINT32            tcmd_mode;
   A_UINT32            antSwitchTblOverride;
   A_UINT32            org_antSwitchTbl1;
   A_UINT32            org_antSwitchTbl2;   
#ifndef AR6002_REV2
   A_UINT32            org_antCtrlChain;   
   A_UINT32            org_antCtrlChain1;   
   A_UINT32            org_antCtrlChain2;   
   A_UINT32            antCtrlChain;
   A_UINT32            antCtrlChain1;
   A_UINT32            antCtrlChain2;
#endif
} HAL_TCMD;

#endif  /* */
