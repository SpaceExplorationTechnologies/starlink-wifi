/*
 *
 */
#include <athdefs.h>
#include <utf_dev.h>
#include <if_athvar.h>
#include <sw_version.h>
#include <osapi.h>
#include <testcmd.h>
#include <wmi_tcmd.h>
#include <tcmd_api.h>
#include <whal_api.h>
#include <queue.h>
#include <hal_tcmd.h>
#include <if_split.h>
//#include <regDb.h>
#ifdef SUPPORT_11N
//#include "ar6000_internal.h"
#endif
#include "whalExtensionGeneric.h"
#include "wlantype.h"
#include "tcmdHostInternal.h"
#include "cmdStream.h"
#include "parmBinTemplate.h"
#include "parseBinCmdStream.h"
#include "cmdAllParms.h"
#include "ar6000_reset.h"

/*
 * MACROS
 */

//
// Exported section
//
_POST_WHAL_RESET_SETTINGS _PostWhalResetSettings;

void whalResetPostProcessing(void);
void ar6000SetTxPowerLimitAsIs(A_UINT16 pwr);

#if 0
#define \
whalResetPlus((opmode), (chan), (resetFlags)) { \
    whalReset((opmode), (chan), (resetFlags));      \
    if (_PostWhalResetSettings.numOfRegs_AlsoMeantPostProcInstalledIfNonZero) { \
        if (_PostWhalResetSettings.pPostProc) { \
            (_PostWhalResetSettings.pPostProc)(NULL); \
        } \
    } \
}
#endif

//
// Local section
//
#if 0
#define _utfWriteReg(addrMode, value, mask) { \
    if (addrMode & ADDRMODE_MODE_MASK) { \
        OS_REG_WRITE((addrMode & ADDRMODE_ADDR_MASK), value);  \
    }  \
    else {  \
        OS_REG_WRITE((addrMode & ADDRMODE_ADDR_MASK),	\
            ((OS_REG_READ(addrMode & ADDRMODE_ADDR_MASK) & ~(mask)) | value)); \
    } \
}
#endif
static void _utfWriteReg(addrMode, value, mask) { 
    A_UINT32 regDbg;
    if (addrMode & ADDRMODE_MODE_MASK) { 
        A_SOC_ADDR_WRITE((addrMode & ADDRMODE_ADDR_MASK), value);  
        //A_PRINTF(".w %x 0x%x reg %x\n", (addrMode & ADDRMODE_ADDR_MASK), value, A_SOC_ADDR_READ(addrMode & ADDRMODE_ADDR_MASK)); 
    }  
    else {  
        regDbg = ((A_SOC_ADDR_READ(addrMode & ADDRMODE_ADDR_MASK)) & ~(mask)) | value; 
        A_SOC_ADDR_WRITE((addrMode & ADDRMODE_ADDR_MASK), regDbg);	
        //
        //A_PRINTF(".rwm %x %x %x to %x reg %x\n", (addrMode & ADDRMODE_ADDR_MASK), value, mask,regDbg, A_SOC_ADDR_READ(addrMode & ADDRMODE_ADDR_MASK) ); 
    } 
}

void whalResetPostProcessing(void)
{
    A_UINT32 i;
    A_UINT32 numRegs=0;
    _UTF_REG_MODE regMode;
    WLAN_PHY_MODE mode;
    _POST_WHAL_RESET_SETTINGS *pReg=&_PostWhalResetSettings;
    mode = tcmd_get_curmode();
    for (i=0;i<MAX_UTF_CAL_WRITE_REG;i++) {
        if (pReg->addrMode[i]) {
            regMode = (pReg->addrMode[i] & ADDRMODE_MODAL_MASK) >> ADDRMODE_MODAL_SHIFT;
            if (_UTF_NO_MODAL == regMode) {
                _utfWriteReg((pReg->addrMode[i]), (pReg->value[i]), (pReg->mask[i]));
            }
            else if ((MODE_11A == mode || MODE_11NA_HT20 == mode) && (_UTF_11A_LEG_HT20 == regMode || _UTF_11A == regMode)) {
                _utfWriteReg((pReg->addrMode[i]), (pReg->value[i]), (pReg->mask[i]));
            }
            else if ((MODE_11NA_HT40 == mode) && (_UTF_11A_HT40 == regMode || _UTF_11A == regMode)) {
                _utfWriteReg((pReg->addrMode[i]), (pReg->value[i]), (pReg->mask[i]));
            }
            else if ((MODE_11G == mode || MODE_11NG_HT20 == mode || MODE_11GONLY == mode) && (_UTF_11G_LEG_HT20 == regMode || _UTF_11G == regMode)) {
                _utfWriteReg((pReg->addrMode[i]), (pReg->value[i]), (pReg->mask[i]));
            }
            else if ((MODE_11NG_HT40 == mode) && (_UTF_11G_HT40 == regMode || _UTF_11G == regMode)) {
                _utfWriteReg((pReg->addrMode[i]), (pReg->value[i]), (pReg->mask[i]));
            }
            else {
                // regMode not for the current mode, not written
            }
            numRegs++;
        }
        if (numRegs > pReg->numOfRegs_AlsoMeantPostProcInstalledIfNonZero) {
            A_PRINTF(".why here numRegs(%d) > Total(%d)\n", numRegs,pReg->numOfRegs_AlsoMeantPostProcInstalledIfNonZero); 
            break;  // should NOT happpen, since we know the number of regs
        }
    }
    return;
}

void whalStickyCmdResetPostProcessing(void *pParam)
{
    A_UINT32 i;
    A_UINT32 numRegs=0;
    _UTF_REG_MODE regMode;
    _POST_WHAL_RESET_SETTINGS *pReg=&_PostWhalResetSettings;
    WHAL_CHANNEL *chan;
    A_UINT8 prePost;
    unsigned long *ptr = pParam;
    
    if (pParam == NULL) {
        return;
    }
    chan = (WHAL_CHANNEL *)ptr[0];
   	prePost = (A_UINT8)ptr[1];
 
    //A_PRINTF("whalStickyCmdResetPostProcessing : chan 0x%08x, prePost %d \n", chan, prePost );

    for (i=0;i<pReg->numOfRegs_AlsoMeantPostProcInstalledIfNonZero;i++) {

        if (pReg->addrMode[i] && ((pReg->addrMode[i] & ADDRMODE_FLAG_MASK) >> ADDRMODE_FLAG_SHIFT) == prePost) {
            regMode = (pReg->addrMode[i] & ADDRMODE_MODAL_MASK) >> ADDRMODE_MODAL_SHIFT;
            //A_PRINTF("whalStickyCmdResetPostProcessing : pReg->addrMode[%d] = 0x%x, regMode %d \n", i, pReg->addrMode[i], regMode);

            if ((_UTF_NO_MODAL == regMode) ||
                ((_UTF_11G_LEG_HT20 == regMode || _UTF_11G == regMode) && (WHAL_IS_CHAN_G(chan) && WHAL_IS_CHAN_20MHZ(chan))) ||
                ((_UTF_11G_HT40 == regMode || _UTF_11G == regMode) && (WHAL_IS_CHAN_G(chan) && WHAL_IS_CHAN_40MHZ(chan))) ||
                ((_UTF_11A_LEG_HT20 == regMode || _UTF_11A == regMode) && (WHAL_IS_CHAN_A(chan) && WHAL_IS_CHAN_20MHZ(chan))) ||
                ((_UTF_11A_HT40 == regMode || _UTF_11A == regMode) && (WHAL_IS_CHAN_A(chan) && WHAL_IS_CHAN_40MHZ(chan))) ||
                ((_UTF_11A_VHT80 == regMode || _UTF_11A == regMode) && (WHAL_IS_CHAN_A(chan) && WHAL_IS_CHAN_80MHZ(chan))))
            {
                _utfWriteReg((pReg->addrMode[i]), (pReg->value[i]), (pReg->mask[i]));
            }
            else {
                // regMode not for the current mode, not written
            }
            numRegs++;
        }
        if (numRegs > pReg->numOfRegs_AlsoMeantPostProcInstalledIfNonZero) {
            A_PRINTF(".why here numRegs(%d) > Total(%d)\n", numRegs,pReg->numOfRegs_AlsoMeantPostProcInstalledIfNonZero); 
            break;  // should NOT happpen, since we know the number of regs
        }
    }
    return;
}

A_UINT16 whalSetTxPowerLimitPlus(A_UINT16 pwrGain)
{
    if (_PostWhalResetSettings.pPostSetPwrProc) { 
        // NOTE: Must use TX_PWR_DEFAULT for "open" loop.
        // There is hard limit of 63, and descripter settings.
        // If not set to default, the tx signal can not be demodulated
        // after pcDac exceeds 63.
        whalSetTxPowerLimit(TX_PWR_DEFAULT, 0); //whalSetTxPowerLimit(pwrGain); 
        whalSetTxPowerLimit(TX_PWR_DEFAULT, 1); //whalSetTxPowerLimit(pwrGain); 
        (_PostWhalResetSettings.pPostSetPwrProc)(pwrGain); 
        return(TX_PWR_DEFAULT); //return(pwrGain);
    } 
    else { 
#ifndef FPGA
#if 1
        whalForceTxPower(pwrGain);
#endif
#endif
        //whalSetTxPowerLimit(pwrGain); 
        //whalSetTxPowerLimitAsIs(pwrGain); 

        return(pwrGain);
    }
}

#if 0
extern WHAL_RESET_INDIRECTION_TABLE *pWhalResetIndirectionTable;
A_BOOL (* rom_ar6000DoCalibration)(A_UINT32 resetCause, A_BOOL bHomeChan);

/* 
 * for Mckinley, we moved the sticky write portion from after reset to before BB Cal
 * this is done by patching DoCalibration function, when patching this rom function, we first 
 * save pointer of it and then point it to utf_ar6000DoCalibration.
 * in utf_ar6000DoCalibration, sticky writes will be exeucted first then jump to rom DoCalibration
 */
static A_BOOL utf_ar6000DoCalibration(A_UINT32 resetCause, A_BOOL bHomeChan)
{
#if defined(AR6002_REV6) 
    if (_PostWhalResetSettings.numOfRegs_AlsoMeantPostProcInstalledIfNonZero) {
        if (_PostWhalResetSettings.pPostProc) {
            (_PostWhalResetSettings.pPostProc)(NULL);
        }
    }
#endif

    (*rom_ar6000DoCalibration) (resetCause, bHomeChan);
}

void whal_install_patches_utf(WHAL_STRUCT *pWhalStruct)
{
    rom_ar6000DoCalibration = pWhalResetIndirectionTable->DoCalibration;
    pWhalResetIndirectionTable->DoCalibration = utf_ar6000DoCalibration;
}
#endif
