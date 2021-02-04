/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/*
 * Copyright (c) 2002-2010  Atheros Communications, Inc.  All rights reserved.
 * $ATH_LICENSE_TARGET_C$
 *
 * Atheros Hardware Access Layer
 *
 */
#ifndef _ATH_HAL_TCMD_H_
#define _ATH_HAL_TCMD_H_

#include "ar6000_tcmd.h"
#include "ar6000_internal.h"

typedef enum {
    HAL_NORMAL_MODE = 0,
    HAL_TEST_MODE,
} HAL_MODE;

typedef struct{
	A_UINT32 valid;
	A_UINT32 xctrl3;
	A_UINT32 chn_address[WHAL_TX_NUM_CHAIN];
	A_UINT32 chn_addac_address[WHAL_TX_NUM_CHAIN];
	A_UINT32 chn_txbb_2_address[WHAL_TX_NUM_CHAIN];
	A_UINT32 chn1_address[WHAL_TX_NUM_CHAIN];;

}TCMD_TX_SINE_REG;

#ifdef AR6002_REV2
#define whalReduceTxFluctuation() \
        ar6000ContReduceTxFluctuation()
#endif

#define whalSingleCarrierConfig(stbl1, stbl2, antenna) \
        ar6000SingleCarrierConfig(stbl1, stbl2, antenna)
#define whalSingleCarrierEnable(freq, txpwr, chainmask) \
        ar6000SingleCarrierEnable(freq, txpwr, chainmask)

#define whalForceSleepMac() \
        ar6000ForceSleepMac()

#define whalDisAck(flag) \
        ar6000DisAck(flag)

#define whalGetAntSwitchTbl() \
        ar6000GetAntSwitchTbl()
#define whalSetAntSwitchTbl(antSwitchTbl1, antSwitchTbl2) \
        ar6000SetAntSwitchTbl(antSwitchTbl1, antSwitchTbl2)        
#define whalSetupAntenna(antenna) \
        ar6000SetupAntenna(antenna)

#define whalEnableWeakSignalDetection() \
        ar6000EnableWeakSignalDetection()
#define whalReducePacketGap(qindex, interval, aifswait, retries) \
        ar6000ReducePacketGap(qindex, interval, aifswait, retries)

#define whalContTXTestMode(enable) \
        ar6000ContTXTestMode(enable)
#define whalDisableBackoff() \
        ar6000DisableBackoff()

#define whalEnableBackoff() \
        ar6000EnableBackoff()

#define whalDisableScramble(disable) \
         ar6000DisableScramble(disable)

#define whalHackMCS3DesiredScale(dataRate) \
         ar6000HackMCS3DesiredScale(dataRate)

#define whalPwrOnOffMAC(enable) \
         ar6000PwrOnOffMAC(enable)

/* overwrite register ini values set during reset, e.g. eep file */
#define whalPostResetRegOverwrite(pParm) \
         ar6000PostResetRegOverwrite(pParm)

#define whalForceTxGain(pcDac) \
         ar6000ForceTxGain(pcDac)

#define whalPostResetSetupOlpcCAL(pParm) \
         ar6000PostResetSetupOlpcCAL(pParm)

#define whalSetTransmitContentionWindow(dcu,cwmin,cwmax) \
         ar6000SetTransmitContentionWindow(dcu,cwmin,cwmax)

#ifdef AR6002_REV6
#define whalSetWlanKeepAwakeCount(count) \
         ar6000SetWlanKeepAwakeCount(count)

#define whalReceiveDeafMode(deaf) \
         ar6000ReceiveDeafMode(deaf)
#endif

#define whalSetTxPowerLimitAsIs(pwr) \
         ar6000SetTxPowerLimitAsIs(pwr)

#if defined(AR9888) || defined(AR900B) || defined(QCA9984) || defined(IPQ4019) || defined(QCA9888)
#define whalForceTxGainIdx(gainIdx, dacGain,txchain_mask) \
         ar6000ForceTxGainIdx(gainIdx, dacGain,txchain_mask)
#else// AR6320
#define whalForceTxGainIdx(paConfig, gainIdx, dacGain,txchain_mask) \
         ar6000ForceTxGainIdx(paConfig, gainIdx, dacGain,txchain_mask)
#endif

#define whalForceTxTgtPwr(tgtPwr, chainMask) \
         ar6000ForceTxTgtPwr(tgtPwr, chainMask)

#define whalSetTpcForceClpcWfm(freq, chainmask, gainIdx) \
         ar6000SetTpcForceClpcWfm(freq, chainmask, gainIdx)

#define whalDisTpcForceClpcWfm(freq, chainmask) \
         ar6000DisTpcForceClpcWfm(freq, chainmask)

#define whalSetTpcForceClpcPacket(freq, chainmask, gainIdx, dacGain, paCfg, clpcmode, tpcm) \
         ar6000SetTpcForceClpcPacket(freq, chainmask, gainIdx, dacGain, paCfg, clpcmode, tpcm)

#define whalSetTpcForceOlpcPacket(freq, gainIdx, dacGain) \
         ar6000SetTpcForceOlpcPacket(freq, gainIdx, dacGain)
#define  whalSetPdetDcOffset(freq, chainmask) \
         ar6000SetPdetDcOffset(freq, chainmask)

#define  whalSetTpcForceCplcPwr(freq, gainIdx, chainmask) \
         ar6000SetTpcForceCplcPwr(freq, gainIdx, chainmask)

#define  whalGetPdetPdadcWfm(freq, chainmask) \
         ar6000GetPdetPdadcWfm(freq, chainmask)

#define  whalGetPdetPdadcPacket(freq, chainmask, arr) \
         ar6000GetPdetPdadcPacket(freq, chainmask, arr)
#endif  /* _ATH_HAL_TCMD_H_ */

