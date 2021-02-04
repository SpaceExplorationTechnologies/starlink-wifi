/*
 * Copyright (c) 2004-2018 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * 2004 - 2016 Qualcomm Atheros, Inc.
 * $ATH_LICENSE_TARGET_C$
 *
 * This file contains the HAL layer extension for TCMD application.
 */

//#include <whal_api.h>
//#include <ar6000_internal.h>
//#include <hw/bb_reg_map.h>
#if (WIFI_IP_CODE < WIFI_IP_VER(2,0))
#include <hw/mac_dma_reg.h>
#include <hw/mac_pcu_reg.h>
#else
#include <extra/hw/map_dma_reg.h>
#include <extra/hw/map_pcu_reg.h>
#if defined(FPGA)
#include "hw/merlin2_0_radio_reg.h"
#endif
#endif
#include <ar6000_desc.h>
#include <testcmd.h>
#include <hal_tcmd.h>
#include <ar6000_tcmd.h>
#include <regulatory/reg_dbvalues.h>
#include "tcmdHostInternal.h"
#include "whalExtensionGeneric.h"

#include "whal_api.h"
#include "whal_internal.h"
#include "halphy_internal.h"

#if (NUM_SPATIAL_STREAM > 0)
#include "hw/chn0_chain_dtop_reg_csr.h"
#include "hw/chn0_addac_reg_csr.h"
#include "hw/chn0_tpc_reg_csr.h"
#include "hw/sm_reg_map.h"
#include "hw/chn0_txbb_reg_csr.h"
#endif

#if (NUM_SPATIAL_STREAM > 1)
#include "hw/chn1_chain_dtop_reg_csr.h"
#include "hw/chn1_addac_reg_csr.h"
#include "hw/chn1_tpc_reg_csr.h"
#include "hw/sm1_reg_map.h"
#include "hw/chn1_txbb_reg_csr.h"
#endif

#if (NUM_SPATIAL_STREAM > 2)
#include "hw/chn2_chain_dtop_reg_csr.h"
#include "hw/chn2_addac_reg_csr.h"
#include "hw/chn2_tpc_reg_csr.h"
#include "hw/sm2_reg_map.h"
#include "hw/chn2_txbb_reg_csr.h"
#endif

#if (NUM_SPATIAL_STREAM > 3)
#include "hw/chn3_chain_dtop_reg_csr.h"
#include "hw/chn3_addac_reg_csr.h"
#include "hw/chn3_tpc_reg_csr.h"
#include "hw/sm3_reg_map.h"
#include "hw/chn3_txbb_reg_csr.h"
#endif

#include "hw/mi_xcontrol_reg_csr.h"
#include "codeswap_api.h"
//#define WHAL_NUM_CHAINS  4  // TBD?? no time to clean up the include files, it's already defined in qc98xx_eeprom.h

//static HAL_TCMD hal_tcmd; /* hal structure, specific to TCMD */
extern A_UINT8 DA_Gain_Settings[][MAX_TX_CAL_GAIN_IDX];
extern A_UINT8 getAlutOffset(A_UINT8 is2GHz);
extern A_UINT8 getWhalNumChains(void);
void ar6000ForceTxGainAnalog(A_UINT16 pcDac, A_UINT16 chain);
void ar6000ForceTxGainAnalogClear(A_UINT16 chain);
void program_PDET_coarse_DC(A_UINT8 stage, A_UINT8 bmode, A_UINT8 gain, A_UINT8 idx_0, A_UINT8 idx_1, A_UINT8 idx_2, A_UINT8 idx_3);
void pdadc_setup(A_UINT8 clpcmode);
void program_ALUT(A_UINT8 pdet_atten_steps_ref[], A_UINT8 pdet_atten_settings_ref[], A_UINT8 bmode, A_UINT8 chain, A_UINT8 verbose);
void use_forced_txgain_idx(A_UINT8 paCfg, A_INT8 dacGain, A_UINT8 gainIdx);
void PDADC_read(A_UINT8 avg[]);

extern A_UINT8 g_pa_setting;
extern A_INT8 g_dac_gain;
extern A_UINT8 g_gain_idx;

SRAM_TEXT
void
ar6000SingleCarrierConfig(A_UINT32 *stbl1, A_UINT32 *stbl2, A_UINT32 antenna)
{
#if !defined(AR900B) && !defined(QCA9984) && !defined(IPQ4019) && !defined(QCA9888)
#ifdef NOT_YET
    if (!hal_tcmd.antSwitchTblOverride) {
        *stbl1 = OS_REG_READ(AR_PHY_ANT_SWITCH_TABLE1);
        *stbl2 = OS_REG_READ(AR_PHY_ANT_SWITCH_TABLE2);
    } else {
	    if (antenna == 0) {
        	*stbl1 = hal_tcmd.antSwitchTbl1;
        	*stbl2 = hal_tcmd.antSwitchTbl2;
	    } else if (antenna == 1) {
        	*stbl1 = hal_tcmd.antSwitchTbl1;
        	*stbl2 = hal_tcmd.antSwitchTbl1;
	    } else if (antenna == 2) {
        	*stbl1 = hal_tcmd.antSwitchTbl2;
        	*stbl2 = hal_tcmd.antSwitchTbl2;
	    }
    }

    OS_REG_WRITE(AR_PHY_ANT_SWITCH_TABLE1,
                 (*stbl1 & ~AR_PHY_ANT_SWITCH_TABLE1_R1) |
                 ((*stbl1 & AR_PHY_ANT_SWITCH_TABLE1_T1) << 6));
    OS_REG_WRITE(AR_PHY_ANT_SWITCH_TABLE2,
                 (*stbl2 & ~AR_PHY_ANT_SWITCH_TABLE2_R2) |
                 ((*stbl2 & AR_PHY_ANT_SWITCH_TABLE2_T2) << 6));
#endif
#endif
}

#if (defined(QCA9984) || defined(QCA9888)) && defined(FPGA)
extern void set_merlin_radio(A_UINT8);
#endif

#if !defined(FPGA)
const A_UINT32 chn_address[] = {
    CHN0_CH0_ADDRESS,
#if (WHAL_TX_NUM_CHAIN > 1)
    CHN1_CH0_ADDRESS,
#endif
#if (WHAL_TX_NUM_CHAIN > 2)
    CHN2_CH0_ADDRESS,
#endif
#if (WHAL_TX_NUM_CHAIN > 3)
    CHN3_CH0_ADDRESS,
#endif
};

const A_UINT32 chn1_address[] = {
    CHN0_CH1_ADDRESS,
#if (WHAL_TX_NUM_CHAIN > 1)
    CHN1_CH1_ADDRESS,
#endif
#if (WHAL_TX_NUM_CHAIN > 2)
    CHN2_CH1_ADDRESS,
#endif
#if (WHAL_TX_NUM_CHAIN > 3)
    CHN3_CH1_ADDRESS,
#endif
};

const A_UINT32 chn_addac_address[] = {
    CHN0_ADDAC0_ADDRESS,
#if (WHAL_TX_NUM_CHAIN > 1)
    CHN1_ADDAC0_ADDRESS,
#endif
#if (WHAL_TX_NUM_CHAIN > 2)
    CHN2_ADDAC0_ADDRESS,
#endif
#if (WHAL_TX_NUM_CHAIN > 3)
    CHN3_ADDAC0_ADDRESS,
#endif
};

const A_UINT32 chn_txbb_2_address[] = {
    CHN0_TXBB_2_ADDRESS,
#if (WHAL_TX_NUM_CHAIN > 1)
    CHN1_TXBB_2_ADDRESS,
#endif
#if (WHAL_TX_NUM_CHAIN > 2)
    CHN2_TXBB_2_ADDRESS,
#endif
#if (WHAL_TX_NUM_CHAIN > 3)
    CHN3_TXBB_2_ADDRESS,
#endif
};
#endif

TCMD_TX_SINE_REG sineRegSave;
void
ar6000SingleCarrierRestore(){
#if !defined(FPGA)
	A_UINT8 chIdx;
	if (sineRegSave.valid == 1){
		OS_REG_WRITE(XCTRL_3_ADDRESS,sineRegSave.xctrl3);

		for (chIdx=0; chIdx<getWhalNumChains(); chIdx++){
			OS_REG_WRITE(chn_address[chIdx],sineRegSave.chn_address[chIdx]);
			OS_REG_WRITE(chn_addac_address[chIdx],sineRegSave.chn_addac_address[chIdx]);
			OS_REG_WRITE(chn_txbb_2_address[chIdx],sineRegSave.chn_txbb_2_address[chIdx]);
			OS_REG_WRITE(chn1_address[chIdx],sineRegSave.chn1_address[chIdx]);
		}
		sineRegSave.valid = 0;
	}
#endif
}

void
ar6000SingleCarrierSave()
{
#if !defined(FPGA)
	A_UINT8 chIdx;
	sineRegSave.valid = 1;
	sineRegSave.xctrl3 = OS_REG_READ(XCTRL_3_ADDRESS);

    for (chIdx=0; chIdx<getWhalNumChains(); chIdx++){
		sineRegSave.chn_address[chIdx] = OS_REG_READ(chn_address[chIdx]);
		sineRegSave.chn_addac_address[chIdx] = OS_REG_READ(chn_addac_address[chIdx]);
		sineRegSave.chn_txbb_2_address[chIdx] = OS_REG_READ(chn_txbb_2_address[chIdx]);
		sineRegSave.chn1_address[chIdx] = OS_REG_READ(chn1_address[chIdx]);
    }
#endif
}

CODESWAP_MARK_EVICTABLE(void, ar6000SingleCarrierEnable, A_UINT32 freq, A_UINT32 txGain, A_UINT32 chainmask)
{
#if !defined(FPGA)
    A_UINT32 mode = MODE_11G;
    A_UINT32 reg32 = 0;
    A_UINT32 chIdx = 0;
    A_UINT32 xpa2g, xpa5g ,attVal=0, daGcVal=0, v2iGainVal=0;
    A_UINT32 txSetting;


    if (txGain < 10){
    	attVal = txGain;
    	daGcVal = 0;
    	v2iGainVal = 0;
    }
    else if (txGain < 20){
    	attVal = txGain - 6;
    	daGcVal = 3;
    	v2iGainVal = 0;
    }
    else if (txGain < 26){
    	attVal = txGain - 10;
    	daGcVal = 7;
    	v2iGainVal = 0;
    }
    else {
    	attVal = txGain - 16;
    	daGcVal = 7;
    	v2iGainVal = 1;
    }

    A_PRINTF_ALWAYS("se: freq %d, pwr %d, mask 0x%x\n", freq, txGain, chainmask);

    // Save previous state of analog registers
    ar6000SingleCarrierSave();

    if (freq == BG_FREQ_MAX ||
       ((freq < BG_FREQ_MAX) && (freq >= BG_FREQ_MIN) && !((freq - BG_FREQ_MIN) % 5))) {
            mode = MODE_11G;
    	}
	else {
            mode = MODE_11A;
	}

       // dac const
       reg32 = OS_REG_READ(PHY_BB_TSTDAC_CONSTANT_ADDRESS);

       reg32 &= ~(PHY_BB_TSTDAC_CONSTANT_CF_TSTDAC_CONSTANT_I_MASK |
                  PHY_BB_TSTDAC_CONSTANT_CF_TSTDAC_CONSTANT_Q_MASK);
       reg32 |= (PHY_BB_TSTDAC_CONSTANT_CF_TSTDAC_CONSTANT_I_SET(0x7ff) |
                 PHY_BB_TSTDAC_CONSTANT_CF_TSTDAC_CONSTANT_Q_SET(0x7ff));
       OS_REG_WRITE(PHY_BB_TSTDAC_CONSTANT_ADDRESS, reg32);

       // source is dac const
       reg32 = OS_REG_READ(PHY_BB_TEST_CONTROLS_STATUS_ADDRESS);

       reg32 &= ~(PHY_BB_TEST_CONTROLS_STATUS_CF_TX_SRC_ALTERNATE_MASK |
                  PHY_BB_TEST_CONTROLS_STATUS_CF_TX_SRC_IS_TSTDAC_MASK);
       reg32 |= (PHY_BB_TEST_CONTROLS_STATUS_CF_TX_SRC_ALTERNATE_SET(0x1) |
                 PHY_BB_TEST_CONTROLS_STATUS_CF_TX_SRC_IS_TSTDAC_SET(0x1));
       OS_REG_WRITE(PHY_BB_TEST_CONTROLS_STATUS_ADDRESS, reg32);

#if 0
       // set dac on
       reg32 = OS_REG_READ(PHY_BB_ADDAC_PARALLEL_CONTROL_ADDRESS);

       reg32 &= ~(PHY_BB_ADDAC_PARALLEL_CONTROL_ON_PWDDAC_MASK |
                  PHY_BB_ADDAC_PARALLEL_CONTROL_OFF_PWDDAC_MASK);
       reg32 |= (PHY_BB_ADDAC_PARALLEL_CONTROL_ON_PWDDAC_SET(0x1) |
                 PHY_BB_ADDAC_PARALLEL_CONTROL_OFF_PWDDAC_SET(0x1));
       OS_REG_WRITE(PHY_BB_ADDAC_PARALLEL_CONTROL_ADDRESS, reg32);
#endif

       if (MODE_11G == mode) {
		   xpa2g = 3;
		   xpa5g = 2;
	   } else {
		   xpa2g = 2;
		   xpa5g = 3;
	   }

       // Reset all XPA ON
       reg32 = OS_REG_READ(XCTRL_3_ADDRESS);
       reg32 &= ~(XCTRL_3_XPA2_ON0_OVR_MASK |
                  XCTRL_3_XPA2_ON1_OVR_MASK |
                  XCTRL_3_XPA2_ON2_OVR_MASK |
                  XCTRL_3_XPA2_ON3_OVR_MASK |
                  XCTRL_3_XPA5_ON0_OVR_MASK |
                  XCTRL_3_XPA5_ON1_OVR_MASK |
                  XCTRL_3_XPA5_ON2_OVR_MASK |
                  XCTRL_3_XPA5_ON3_OVR_MASK );
#if defined(QCA9888)
	   reg32 |=  XCTRL_3_XLNA2_ON0_OVR_MASK;
	   reg32 |=  XCTRL_3_XLNA2_ON1_OVR_MASK;
#endif

       for (chIdx=0; chIdx<getWhalNumChains(); chIdx++)
       {
           if ( ((chainmask >> chIdx) & 0x1) )
           {
               /// Same address offset for CHN0_CH0_TXON_OVR,CHN1_CH0_TXON_OVR etc..
               OS_REG_RMW_FIELD(chn_address[chIdx],CHN0_CH0_TXON_OVR,0x3);
               OS_REG_RMW_FIELD(chn_address[chIdx],CHN0_CH0_RXON_OVR,0x2);

               OS_REG_RMW_FIELD(chn_address[chIdx],CHN0_CH0_CHAIN_BIAS_ON_OVR,0x2);
               OS_REG_RMW_FIELD(chn_address[chIdx],CHN0_CH0_DAON_OVR,0x3);

               OS_REG_RMW_FIELD(chn_addac_address[chIdx],CHN0_ADDAC0_DACFULLSCALE_OVR,0x3);
               OS_REG_RMW_FIELD(chn_addac_address[chIdx],CHN0_ADDAC0_LOCAL_DACPWD,0x1);
               OS_REG_RMW_FIELD(chn_addac_address[chIdx],CHN0_ADDAC0_DACPWD_LS,0x0);

               reg32 |= _MAKE_CHAIN_REG_FUNC_1(XCTRL_3_XPA2_ON,chIdx,_OVR_SET,xpa2g);
               reg32 |= _MAKE_CHAIN_REG_FUNC_1(XCTRL_3_XPA5_ON,chIdx,_OVR_SET,xpa5g);

               OS_REG_RMW_FIELD(chn_txbb_2_address[chIdx],CHN0_TXBB_2_MANTXGAIN,1);
               OS_REG_RMW_FIELD(chn_txbb_2_address[chIdx],CHN0_TXBB_2_V2IGAIN_2X_LS,v2iGainVal);
#if defined(IPQ4019)
               // increase output power of single carrier
               OS_REG_RMW_FIELD(chn_txbb_2_address[chIdx],CHN0_TXBB_2_TXBB_GC_LS,7);
#else
               OS_REG_RMW_FIELD(chn_txbb_2_address[chIdx],CHN0_TXBB_2_TXBB_GC_LS,0);
#endif
               OS_REG_RMW_FIELD(chn_txbb_2_address[chIdx],CHN0_TXBB_2_TX_BQ1_LS,0);
               OS_REG_RMW_FIELD(chn_txbb_2_address[chIdx],CHN0_TXBB_2_TX_BQ2_LS,attVal);
               OS_REG_RMW_FIELD(chn_txbb_2_address[chIdx],CHN0_TXBB_2_DA_GC_LS,daGcVal);

	       if (MODE_11G == mode) {
                   OS_REG_RMW_FIELD(chn1_address[chIdx],CHN0_CH1_BMODE_OVR,0x3);
	       } else {
                   OS_REG_RMW_FIELD(chn1_address[chIdx],CHN0_CH1_BMODE_OVR,0x2);
               }
           }
       }

#if 0
       reg32 |= (XCTRL_3_XPA2_ON0_OVR_SET(xpa2g) |
                 XCTRL_3_XPA2_ON1_OVR_SET(xpa2g) |
                 XCTRL_3_XPA2_ON2_OVR_SET(xpa2g) |
                 XCTRL_3_XPA2_ON3_OVR_SET(xpa2g) |
                 XCTRL_3_XPA5_ON0_OVR_SET(xpa5g) |
                 XCTRL_3_XPA5_ON1_OVR_SET(xpa5g) |
                 XCTRL_3_XPA5_ON2_OVR_SET(xpa5g) |
                 XCTRL_3_XPA5_ON3_OVR_SET(xpa5g) );

#endif
       OS_REG_WRITE(XCTRL_3_ADDRESS,reg32);

       // force antenna switch to Tx
       reg32 = OS_REG_READ(PHY_BB_SWITCH_TABLE_COM1_ADDRESS);
       txSetting = PHY_BB_SWITCH_TABLE_COM1_SWITCH_TABLE_COM_T1_GET(reg32);

       reg32 &= ~(PHY_BB_SWITCH_TABLE_COM1_SWITCH_TABLE_COM_IDLE_MASK |
                  PHY_BB_SWITCH_TABLE_COM1_SWITCH_TABLE_COM_B_MASK);
       reg32 |= (PHY_BB_SWITCH_TABLE_COM1_SWITCH_TABLE_COM_IDLE_SET(txSetting) |
                 PHY_BB_SWITCH_TABLE_COM1_SWITCH_TABLE_COM_B_SET(txSetting));
       OS_REG_WRITE(PHY_BB_SWITCH_TABLE_COM1_ADDRESS, reg32);

       reg32 = OS_REG_READ(PHY_BB_SWITCH_TABLE_COM2_ADDRESS);
       reg32 &= ~(PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA2L1_MASK |
                  PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA12_MASK  |
                  PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA1L1_MASK |
                  PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA2L2_MASK |
                  PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA1L2_MASK );

       reg32 |=  (PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA2L1_SET(txSetting)  |
                  PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA12_SET(txSetting)   |
                  PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA1L1_SET(txSetting)  |
                  PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA2L2_SET(txSetting)  |
                  PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA1L2_SET(txSetting));

       OS_REG_WRITE(PHY_BB_SWITCH_TABLE_COM2_ADDRESS, reg32);

       txSetting = 0;

       reg32 = OS_REG_READ(PHY_BB_SWITCH_TABLE_CHN_B0_ADDRESS);
       reg32 &= ~(PHY_BB_SWITCH_TABLE_CHN_B0_SWITCH_TABLE_R_0_MASK |
                  PHY_BB_SWITCH_TABLE_CHN_B0_SWITCH_TABLE_RX1_0_MASK  |
                  PHY_BB_SWITCH_TABLE_CHN_B0_SWITCH_TABLE_RX12_0_MASK );

       reg32 |=  (PHY_BB_SWITCH_TABLE_CHN_B0_SWITCH_TABLE_R_0_SET(txSetting)  |
                  PHY_BB_SWITCH_TABLE_CHN_B0_SWITCH_TABLE_RX1_0_SET(txSetting)  |
                  PHY_BB_SWITCH_TABLE_CHN_B0_SWITCH_TABLE_RX12_0_SET(txSetting));

       OS_REG_WRITE(PHY_BB_SWITCH_TABLE_CHN_B0_ADDRESS, reg32);


#if (NUM_SPATIAL_STREAM > 1)
       reg32 = OS_REG_READ(PHY_BB_SWITCH_TABLE_CHN_B1_ADDRESS);
       reg32 &= ~(PHY_BB_SWITCH_TABLE_CHN_B1_SWITCH_TABLE_R_1_MASK |
                  PHY_BB_SWITCH_TABLE_CHN_B1_SWITCH_TABLE_RX1_1_MASK  |
                  PHY_BB_SWITCH_TABLE_CHN_B1_SWITCH_TABLE_RX12_1_MASK );

       reg32 |=  (PHY_BB_SWITCH_TABLE_CHN_B1_SWITCH_TABLE_R_1_SET(txSetting)  |
                  PHY_BB_SWITCH_TABLE_CHN_B1_SWITCH_TABLE_RX1_1_SET(txSetting)  |
                  PHY_BB_SWITCH_TABLE_CHN_B1_SWITCH_TABLE_RX12_1_SET(txSetting));

       OS_REG_WRITE(PHY_BB_SWITCH_TABLE_CHN_B1_ADDRESS, reg32);

#if (NUM_SPATIAL_STREAM > 2)
       reg32 = OS_REG_READ(PHY_BB_SWITCH_TABLE_CHN_B2_ADDRESS);
       reg32 &= ~(PHY_BB_SWITCH_TABLE_CHN_B2_SWITCH_TABLE_R_2_MASK |
                  PHY_BB_SWITCH_TABLE_CHN_B2_SWITCH_TABLE_RX1_2_MASK  |
                  PHY_BB_SWITCH_TABLE_CHN_B2_SWITCH_TABLE_RX12_2_MASK );

       reg32 |=  (PHY_BB_SWITCH_TABLE_CHN_B2_SWITCH_TABLE_R_2_SET(txSetting)  |
                  PHY_BB_SWITCH_TABLE_CHN_B2_SWITCH_TABLE_RX1_2_SET(txSetting)  |
                  PHY_BB_SWITCH_TABLE_CHN_B2_SWITCH_TABLE_RX12_2_SET(txSetting));

       OS_REG_WRITE(PHY_BB_SWITCH_TABLE_CHN_B2_ADDRESS, reg32);

#if (NUM_SPATIAL_STREAM > 3)
       reg32 = OS_REG_READ(PHY_BB_SWITCH_TABLE_CHN_B3_ADDRESS);
       reg32 &= ~(PHY_BB_SWITCH_TABLE_CHN_B3_SWITCH_TABLE_R_3_MASK |
                  PHY_BB_SWITCH_TABLE_CHN_B3_SWITCH_TABLE_RX1_3_MASK  |
                  PHY_BB_SWITCH_TABLE_CHN_B3_SWITCH_TABLE_RX12_3_MASK );

       reg32 |=  (PHY_BB_SWITCH_TABLE_CHN_B3_SWITCH_TABLE_R_3_SET(txSetting)  |
                  PHY_BB_SWITCH_TABLE_CHN_B3_SWITCH_TABLE_RX1_3_SET(txSetting)  |
                  PHY_BB_SWITCH_TABLE_CHN_B3_SWITCH_TABLE_RX12_3_SET(txSetting));

       OS_REG_WRITE(PHY_BB_SWITCH_TABLE_CHN_B3_ADDRESS, reg32);
#endif
#endif
#endif
#else
#if defined(QCA9984) || defined(QCA9888)
        set_merlin_radio(0);
        A_ANALOG_REG_WRITE(MERLIN_TOP0_ADDRESS,0xe01d3c00);
        A_ANALOG_REG_WRITE(MERLIN_TOP1_ADDRESS,0x3060aeb);
        set_merlin_radio(1);
#endif
       A_ANALOG_REG_WRITE(MERLIN_TOP0_ADDRESS,0xe01d3c00);
       A_ANALOG_REG_WRITE(MERLIN_TOP1_ADDRESS,0x3060aeb);
#endif
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void ,ar6000SingleCarrierEnable, A_UINT32 , A_UINT32 , A_UINT32);
extern void ar6000SingleCarrierEnable(A_UINT32 freq, A_UINT32 txGain, A_UINT32 chainmask);
#if 0
void
ar6000SingleCarrierEnable(A_UINT32 freq, A_UINT32 txpwr, A_UINT32 chainmask)
{
#ifdef FIXME_WIFI2
    A_UINT32 mode = MODE_11G;
    A_UINT32 reg32 = 0;
    A_UINT32 txSetting;
    //A_UINT32 dacIQConst = 2047;  //0x7ff
    //A_PRINTF_ALWAYS("se: freq %d, pwr %d, mask 0x%x\n", freq, txpwr, chainmask);

    if (freq == BG_FREQ_MAX ||
       ((freq < BG_FREQ_MAX) && (freq >= BG_FREQ_MIN) && !((freq - BG_FREQ_MIN) % 5))) {
            mode = MODE_11G;
    	}
	else {
            mode = MODE_11A;
	}

   ar6000ForceTxGainAnalogClear(chainmask);
   ar6000ForceTxGainAnalog(txpwr, chainmask);
   if (chainmask & 0x1) {

       /* force dac on */
       reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_BB_B0_BB8_ADDRESS);
       reg32 |= PHY_ANALOG_BB_B0_BB8_LOCAL_DACPWD_SET(0x1);
       reg32 &= ~PHY_ANALOG_BB_B0_BB8_DACPWD_MASK;
       A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_BB_B0_BB8_ADDRESS, reg32);

       /* set it to full scale */
       reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_BB_B0_BB7_ADDRESS);
       reg32 |= PHY_ANALOG_BB_B0_BB7_DACFULLSCALE_SET(0x1);

       /* force TXON, PAON, and SYNTHON */
       reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_RXTX_B0_RXTX2_ADDRESS);
       reg32 |= PHY_ANALOG_RXTX_B0_RXTX2_SYNTHON_OVR_MASK |
                PHY_ANALOG_RXTX_B0_RXTX2_SYNTHON_MASK     |
                PHY_ANALOG_RXTX_B0_RXTX2_TXON_OVR_MASK    |
                PHY_ANALOG_RXTX_B0_RXTX2_TXON_MASK        |
                PHY_ANALOG_RXTX_B0_RXTX2_PAON_OVR_MASK    |
                PHY_ANALOG_RXTX_B0_RXTX2_PAON_MASK
                ;
       if(mode == MODE_11A) { /* 5GHz */
           reg32 |= PHY_ANALOG_RXTX_B0_RXTX2_BMODE_OVR_MASK;
           reg32 &= ~ PHY_ANALOG_RXTX_B0_RXTX2_BMODE_MASK;
       }
       else {
           reg32 |= PHY_ANALOG_RXTX_B0_RXTX2_BMODE_OVR_MASK;
           reg32 |= PHY_ANALOG_RXTX_B0_RXTX2_BMODE_MASK;
       }
       A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_RXTX_B0_RXTX2_ADDRESS, reg32);
   }

   if (chainmask & 0x2) {
       /* force dac on */
       reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_BB_B1_BB8_ADDRESS);
       reg32 |= PHY_ANALOG_BB_B1_BB8_LOCAL_DACPWD_SET(0x1);
       reg32 &= ~PHY_ANALOG_BB_B1_BB8_DACPWD_MASK;
       A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_BB_B1_BB8_ADDRESS, reg32);

       /* set it to full scale */
       reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_BB_B1_BB7_ADDRESS);
       reg32 |= PHY_ANALOG_BB_B1_BB7_DACFULLSCALE_SET(0x1);

       /* force TXON, PAON, and SYNTHON */
       reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_RXTX_B1_RXTX2_ADDRESS);
       reg32 |= PHY_ANALOG_RXTX_B1_RXTX2_SYNTHON_OVR_MASK |
                PHY_ANALOG_RXTX_B1_RXTX2_SYNTHON_MASK     |
                PHY_ANALOG_RXTX_B1_RXTX2_TXON_OVR_MASK    |
                PHY_ANALOG_RXTX_B1_RXTX2_TXON_MASK        |
                PHY_ANALOG_RXTX_B1_RXTX2_PAON_OVR_MASK    |
                PHY_ANALOG_RXTX_B1_RXTX2_PAON_MASK
                  ;
       if(mode == MODE_11A) { /* 5GHz */
           reg32 |= PHY_ANALOG_RXTX_B1_RXTX2_BMODE_OVR_MASK;
           reg32 &= ~ PHY_ANALOG_RXTX_B1_RXTX2_BMODE_MASK;
       }
       else {
           reg32 |= PHY_ANALOG_RXTX_B1_RXTX2_BMODE_OVR_MASK;
           reg32 |= PHY_ANALOG_RXTX_B1_RXTX2_BMODE_MASK;
       }
       A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_RXTX_B1_RXTX2_ADDRESS, reg32);

       if (!(chainmask & 0x1)) {
           /* there is only one synthon, that's on chain 0, so if we are sending single tone
              on chain 1 then we have to turn on the synthon on chain 0 as well */
           reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_RXTX_B0_RXTX2_ADDRESS);
           /* turn off both txon and paon on chain 0 */
           reg32 &= ~(PHY_ANALOG_RXTX_B0_RXTX2_TXON_OVR_MASK |
                      PHY_ANALOG_RXTX_B0_RXTX2_TXON_MASK     |
                      PHY_ANALOG_RXTX_B0_RXTX2_PAON_OVR_MASK |
                      PHY_ANALOG_RXTX_B0_RXTX2_PAON_MASK);

           /* turn on SYNTHON on chain 0 */
           reg32 |= PHY_ANALOG_RXTX_B0_RXTX2_SYNTHON_OVR_MASK |
                    PHY_ANALOG_RXTX_B0_RXTX2_SYNTHON_MASK;
           A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_RXTX_B0_RXTX2_ADDRESS, reg32);
           //A_PRINTF("ch2 synth on 0x%x\n", reg32);
       }

   }

   if (chainmask & 0x4) {
       /* force dac on */
       reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_BB_B2_BB8_ADDRESS);
       reg32 |= PHY_ANALOG_BB_B2_BB8_LOCAL_DACPWD_SET(0x1);
       reg32 &= ~PHY_ANALOG_BB_B2_BB8_DACPWD_MASK;
       A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_BB_B2_BB8_ADDRESS, reg32);

       /* set it to full scale */
       reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_BB_B2_BB7_ADDRESS);
       reg32 |= PHY_ANALOG_BB_B2_BB7_DACFULLSCALE_SET(0x1);

       /* force TXON, PAON, and SYNTHON */
       reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_RXTX_B2_RXTX2_ADDRESS);
       reg32 |= PHY_ANALOG_RXTX_B2_RXTX2_SYNTHON_OVR_MASK |
                PHY_ANALOG_RXTX_B2_RXTX2_SYNTHON_MASK     |
                PHY_ANALOG_RXTX_B2_RXTX2_TXON_OVR_MASK    |
                PHY_ANALOG_RXTX_B2_RXTX2_TXON_MASK        |
                PHY_ANALOG_RXTX_B2_RXTX2_PAON_OVR_MASK    |
                PHY_ANALOG_RXTX_B2_RXTX2_PAON_MASK
                  ;
       if(mode == MODE_11A) { /* 5GHz */
           reg32 |= PHY_ANALOG_RXTX_B2_RXTX2_BMODE_OVR_MASK;
           reg32 &= ~ PHY_ANALOG_RXTX_B2_RXTX2_BMODE_MASK;
       }
       else {
           reg32 |= PHY_ANALOG_RXTX_B2_RXTX2_BMODE_OVR_MASK;
           reg32 |= PHY_ANALOG_RXTX_B2_RXTX2_BMODE_MASK;
       }
       A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_RXTX_B2_RXTX2_ADDRESS, reg32);

       if (!(chainmask & 0x1)) {
           /* there is only one synthon, that's on chain 0, so if we are sending single tone
              on chain 1 then we have to turn on the synthon on chain 0 as well */
           reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_RXTX_B0_RXTX2_ADDRESS);
           /* turn off both txon and paon on chain 0 */
           reg32 &= ~(PHY_ANALOG_RXTX_B0_RXTX2_TXON_OVR_MASK |
                      PHY_ANALOG_RXTX_B0_RXTX2_TXON_MASK     |
                      PHY_ANALOG_RXTX_B0_RXTX2_PAON_OVR_MASK |
                      PHY_ANALOG_RXTX_B0_RXTX2_PAON_MASK);

           /* turn on SYNTHON on chain 0 */
           reg32 |= PHY_ANALOG_RXTX_B0_RXTX2_SYNTHON_OVR_MASK |
                    PHY_ANALOG_RXTX_B0_RXTX2_SYNTHON_MASK;
           A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_RXTX_B0_RXTX2_ADDRESS, reg32);
           //A_PRINTF("ch3 synth on 0x%x\n", reg32);
       }

   }

       /* force XPA ON */
       reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_TOP_WLAN_TOPWLAN1_ADDRESS);
       reg32 &= ~(PHY_ANALOG_TOP_WLAN_TOPWLAN1_LOCAL_XPAON_MASK |
                  PHY_ANALOG_TOP_WLAN_TOPWLAN1_XPA5ON_MASK      |
                  PHY_ANALOG_TOP_WLAN_TOPWLAN1_XPA2ON_MASK);
       reg32 |=  (PHY_ANALOG_TOP_WLAN_TOPWLAN1_LOCAL_XPAON_SET(0x1));
       if(mode == MODE_11A) { /* 5GHz */
           reg32 |= PHY_ANALOG_TOP_WLAN_TOPWLAN1_XPA5ON_SET(chainmask);
       }
       else {
           reg32 |= PHY_ANALOG_TOP_WLAN_TOPWLAN1_XPA2ON_SET(chainmask);
       }
       A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + PHY_ANALOG_TOP_WLAN_TOPWLAN1_ADDRESS, reg32);

       // force antenna switch to Tx
       reg32 = OS_REG_READ(PHY_BB_SWITCH_TABLE_COM1_ADDRESS);
       txSetting = PHY_BB_SWITCH_TABLE_COM1_SWITCH_TABLE_COM_T1_GET(reg32);
       reg32 &= ~(PHY_BB_SWITCH_TABLE_COM1_SWITCH_TABLE_COM_IDLE_MASK |
                  PHY_BB_SWITCH_TABLE_COM1_SWITCH_TABLE_COM_B_MASK);
       reg32 |= (PHY_BB_SWITCH_TABLE_COM1_SWITCH_TABLE_COM_IDLE_SET(txSetting) |
                 PHY_BB_SWITCH_TABLE_COM1_SWITCH_TABLE_COM_B_SET(txSetting));
       OS_REG_WRITE(PHY_BB_SWITCH_TABLE_COM1_ADDRESS, reg32);

       reg32 = OS_REG_READ(PHY_BB_SWITCH_TABLE_COM2_ADDRESS);
       reg32 &= ~(PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA2L1_MASK |
                  PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA12_MASK  |
                  PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA1L1_MASK |
                  PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA2L2_MASK |
                  PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA1L2_MASK );
       reg32 |=  (PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA2L1_SET(txSetting)  |
                  PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA12_SET(txSetting)   |
                  PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA1L1_SET(txSetting)  |
                  PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA2L2_SET(txSetting)  |
                  PHY_BB_SWITCH_TABLE_COM2_SWITCH_TABLE_COM_RA1L2_SET(txSetting)  );
       OS_REG_WRITE(PHY_BB_SWITCH_TABLE_COM2_ADDRESS, reg32);

#endif
}
#endif

SRAM_TEXT
void ar6000SetWlanKeepAwakeCount(A_UINT32 count)
{
    A_UINT32 reg32;

    reg32 = A_RTC_WLAN_REG_READ(WLAN_KEEP_AWAKE_ADDRESS);
    reg32 &= ~WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_MASK;
    A_RTC_WLAN_REG_WRITE(WLAN_KEEP_AWAKE_ADDRESS, reg32 | WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_SET(count));
}


SRAM_TEXT
void
ar6000ForceWakeMac()
{
#ifdef FIXME_WIFI2
    WHAL_MAC_WAKEUP();
#endif
}

SRAM_TEXT
void
ar6000ForceSleepMac()
{
#ifdef FIXME_WIFI2
    WHAL_MAC_FORCE_SLEEP();
#endif
}

/*
 * Disable/Enable's  ACKing by the hardware at the MAC layer.
 */
SRAM_TEXT
void
ar6000DisAck(A_BOOL flag)
{
#ifdef FIXME_WIFI2
    if (flag == TRUE) {
        OS_REG_WRITE(MAC_PCU_DIAG_SW_ADDRESS, OS_REG_READ(MAC_PCU_DIAG_SW_ADDRESS) | MAC_PCU_DIAG_SW_NO_ACK_MASK);
    } else {
        OS_REG_WRITE(MAC_PCU_DIAG_SW_ADDRESS, OS_REG_READ(MAC_PCU_DIAG_SW_ADDRESS) & ~MAC_PCU_DIAG_SW_NO_ACK_MASK);
    }
#endif
}

SRAM_TEXT
void
ar6000DisableBackoff()
{
}

SRAM_TEXT
void
ar6000EnableBackoff()
{
}

SRAM_TEXT
void
ar6000SetAntSwitchTbl(A_UINT32 antSwitchTbl1, A_UINT32 antSwitchTbl2)
{
#ifdef FIXME_WIFI2
    if ((0 == antSwitchTbl1) && (0 ==antSwitchTbl2))
    {
        //restore default
        hal_tcmd.antSwitchTblOverride = 0;
        OS_REG_WRITE(PHY_BB_SWITCH_TABLE_COM1_ADDRESS, hal_tcmd.org_antSwitchTbl1);
        OS_REG_WRITE(PHY_BB_SWITCH_TABLE_COM2_ADDRESS, hal_tcmd.org_antSwitchTbl2);
        OS_REG_WRITE(PHY_BB_SWITCH_TABLE_CHN_B0_ADDRESS, hal_tcmd.org_antCtrlChain);
        OS_REG_WRITE(PHY_BB_SWITCH_TABLE_CHN_B1_ADDRESS, hal_tcmd.org_antCtrlChain1);
        OS_REG_WRITE(PHY_BB_SWITCH_TABLE_CHN_B2_ADDRESS, hal_tcmd.org_antCtrlChain2);
        ar6000GetAntSwitchTbl();
    }
    else
    {
        hal_tcmd.antSwitchTblOverride = 1;
        hal_tcmd.antSwitchTbl1 = antSwitchTbl1;
        hal_tcmd.antSwitchTbl2 = antSwitchTbl2;
    }
#if 0
    A_PRINTF("ar6000SetAntSwitchTbl\n");
    A_PRINTF("oT1 %x,T1 %x (%x=%x)\n",hal_tcmd.org_antSwitchTbl1, hal_tcmd.antSwitchTbl1, PHY_BB_SWITCH_TABLE_COM1_ADDRESS, OS_REG_READ(PHY_BB_SWITCH_TABLE_COM1_ADDRESS));
    A_PRINTF("oT2 %x,T2 %x (%x=%x)\n",hal_tcmd.org_antSwitchTbl2, hal_tcmd.antSwitchTbl2, PHY_BB_SWITCH_TABLE_COM2_ADDRESS, OS_REG_READ(PHY_BB_SWITCH_TABLE_COM2_ADDRESS));
    A_PRINTF("oCh %x,Ca %x (%x=%x)\n",hal_tcmd.org_antCtrlChain, hal_tcmd.antCtrlChain, PHY_BB_SWITCH_TABLE_CHN_B0_ADDRESS, OS_REG_READ(PHY_BB_SWITCH_TABLE_CHN_B0_ADDRESS));
    A_PRINTF("oCh1 %x,Ca %x (%x=%x)\n",hal_tcmd.org_antCtrlChain1, hal_tcmd.antCtrlChain1, PHY_BB_SWITCH_TABLE_CHN_B1_ADDRESS, OS_REG_READ(PHY_BB_SWITCH_TABLE_CHN_B1_ADDRESS));
#endif
#endif
}

SRAM_TEXT
void
ar6000GetAntSwitchTbl()
{
#ifdef FIXME_WIFI2
    hal_tcmd.org_antSwitchTbl1 = OS_REG_READ(PHY_BB_SWITCH_TABLE_COM1_ADDRESS);
    hal_tcmd.org_antSwitchTbl2 = OS_REG_READ(PHY_BB_SWITCH_TABLE_COM2_ADDRESS);
    hal_tcmd.org_antCtrlChain = OS_REG_READ(PHY_BB_SWITCH_TABLE_CHN_B0_ADDRESS);
    hal_tcmd.org_antCtrlChain1 = OS_REG_READ(PHY_BB_SWITCH_TABLE_CHN_B1_ADDRESS);
    hal_tcmd.org_antCtrlChain2 = OS_REG_READ(PHY_BB_SWITCH_TABLE_CHN_B1_ADDRESS);

    if (!hal_tcmd.antSwitchTblOverride)
    {
        hal_tcmd.antSwitchTbl1 = hal_tcmd.org_antSwitchTbl1;
        hal_tcmd.antSwitchTbl2 = hal_tcmd.org_antSwitchTbl2;
        hal_tcmd.antCtrlChain = hal_tcmd.org_antCtrlChain;
        hal_tcmd.antCtrlChain1 = hal_tcmd.org_antCtrlChain1;
        hal_tcmd.antCtrlChain2 = hal_tcmd.org_antCtrlChain2;
    }
#if 0
    A_PRINTF("ar6000GetAntSwitchTbl\n");
    A_PRINTF("oT1 %x,T1 %x (%x=%x)\n",hal_tcmd.org_antSwitchTbl1, hal_tcmd.antSwitchTbl1, PHY_BB_SWITCH_TABLE_COM1_ADDRESS, OS_REG_READ(PHY_BB_SWITCH_TABLE_COM1_ADDRESS));
    A_PRINTF("oT2 %x,T2 %x (%x=%x)\n",hal_tcmd.org_antSwitchTbl2, hal_tcmd.antSwitchTbl2, PHY_BB_SWITCH_TABLE_COM2_ADDRESS, OS_REG_READ(PHY_BB_SWITCH_TABLE_COM2_ADDRESS));
    A_PRINTF("oCh %x,Ca %x (%x=%x)\n",hal_tcmd.org_antCtrlChain, hal_tcmd.antCtrlChain, PHY_BB_SWITCH_TABLE_CHN_B0_ADDRESS, OS_REG_READ(PHY_BB_SWITCH_TABLE_CHN_B0_ADDRESS));
    A_PRINTF("oCh1 %x,Ca %x (%x=%x)\n",hal_tcmd.org_antCtrlChain1, hal_tcmd.antCtrlChain1, PHY_BB_SWITCH_TABLE_CHN_B1_ADDRESS, OS_REG_READ(PHY_BB_SWITCH_TABLE_CHN_B1_ADDRESS));
#endif
#endif
}

/*
 *  0x1 for ANT_1 0x2 for ANT_2
 */
SRAM_TEXT
void
ar6000SetupAntenna(A_UINT32 ant)
{
#ifdef FIXME_WIFI2
    if (ant == 1) {
        OS_REG_WRITE(PHY_BB_SWITCH_TABLE_COM1_ADDRESS, hal_tcmd.antSwitchTbl1);
        OS_REG_WRITE(PHY_BB_SWITCH_TABLE_COM2_ADDRESS, hal_tcmd.antSwitchTbl1);
    } else if (ant == 2) {
        OS_REG_WRITE(PHY_BB_SWITCH_TABLE_COM1_ADDRESS, hal_tcmd.antSwitchTbl2);
        OS_REG_WRITE(PHY_BB_SWITCH_TABLE_COM2_ADDRESS, hal_tcmd.antSwitchTbl2);
    } else {
        OS_REG_WRITE(PHY_BB_SWITCH_TABLE_COM1_ADDRESS, hal_tcmd.antSwitchTbl1);
        OS_REG_WRITE(PHY_BB_SWITCH_TABLE_COM2_ADDRESS, hal_tcmd.antSwitchTbl2);
    }

    /* TODO: do we need to update antCtrlChain ? */
    OS_REG_WRITE(PHY_BB_SWITCH_TABLE_CHN_B0_ADDRESS, hal_tcmd.org_antCtrlChain);
    OS_REG_WRITE(PHY_BB_SWITCH_TABLE_CHN_B1_ADDRESS, hal_tcmd.org_antCtrlChain1);
    OS_REG_WRITE(PHY_BB_SWITCH_TABLE_CHN_B2_ADDRESS, hal_tcmd.org_antCtrlChain2);
#if 0
    A_PRINTF("ar6000SetupAntenna\n");
    A_PRINTF("oT1 %x,T1 %x (%x=%x)\n",hal_tcmd.org_antSwitchTbl1, hal_tcmd.antSwitchTbl1, PHY_BB_SWITCH_TABLE_COM1_ADDRESS, OS_REG_READ(PHY_BB_SWITCH_TABLE_COM1_ADDRESS));
    A_PRINTF("oT2 %x,T2 %x (%x=%x)\n",hal_tcmd.org_antSwitchTbl2, hal_tcmd.antSwitchTbl2, PHY_BB_SWITCH_TABLE_COM2_ADDRESS, OS_REG_READ(PHY_BB_SWITCH_TABLE_COM2_ADDRESS));
    A_PRINTF("oCh %x,Ca %x (%x=%x)\n",hal_tcmd.org_antCtrlChain, hal_tcmd.antCtrlChain, PHY_BB_SWITCH_TABLE_CHN_B0_ADDRESS, OS_REG_READ(PHY_BB_SWITCH_TABLE_CHN_B0_ADDRESS));
#endif
#endif
}

/* direct copy from ar6000_ani.c -> ar6000AniControl */
SRAM_TEXT
void
ar6000EnableWeakSignalDetection()
{
#ifdef FIXME_WIFI2
    typedef A_INT16 WHAL_ANI_TABLE[];
    /* WHAL_ANI_OFDM_WEAK_SIGNAL_DETECTION Tables */
    WHAL_ANI_TABLE m1ThreshLow   = { 127,   50 };
    WHAL_ANI_TABLE m2ThreshLow   = { 127,   40 };
    WHAL_ANI_TABLE m1Thresh      = { 127, 0x4d };
    WHAL_ANI_TABLE m2Thresh      = { 127, 0x40 };
    WHAL_ANI_TABLE m2CountThr    = {  31,   16 };
    WHAL_ANI_TABLE m2CountThrLow = {  63,   48 };

    A_UINT32 on = 1;

    OS_REG_RMW_FIELD(PHY_BB_SELF_CORR_LOW_ADDRESS,
        PHY_BB_SELF_CORR_LOW_M1_THRESH_LOW, m1ThreshLow[on]);
    OS_REG_RMW_FIELD(PHY_BB_SELF_CORR_LOW_ADDRESS,
        PHY_BB_SELF_CORR_LOW_M2_THRESH_LOW, m2ThreshLow[on]);
    OS_REG_RMW_FIELD(PHY_BB_SFCORR_ADDRESS,
        PHY_BB_SFCORR_M1_THRES, m1Thresh[on]);
    OS_REG_RMW_FIELD(PHY_BB_SFCORR_ADDRESS,
        PHY_BB_SFCORR_M2_THRES, m2Thresh[on]);
    OS_REG_RMW_FIELD(PHY_BB_SFCORR_ADDRESS,
        PHY_BB_SFCORR_M2COUNT_THR, m2CountThr[on]);
    OS_REG_RMW_FIELD(PHY_BB_SELF_CORR_LOW_ADDRESS,
        PHY_BB_SELF_CORR_LOW_M2COUNT_THR_LOW, m2CountThrLow[on]);

#if 0 // No such registers in Peregrine
    OS_REG_RMW_FIELD(PHY_BB_EXT_CHAN_SCORR_THR_ADDRESS,
        PHY_BB_EXT_CHAN_SCORR_THR_M1_THRES_LOW_EXT, m1ThreshLow[on]);
    OS_REG_RMW_FIELD(PHY_BB_EXT_CHAN_SCORR_THR_ADDRESS,
        PHY_BB_EXT_CHAN_SCORR_THR_M2_THRES_LOW_EXT, m2ThreshLow[on]);
    OS_REG_RMW_FIELD(PHY_BB_EXT_CHAN_SCORR_THR_ADDRESS,
        PHY_BB_EXT_CHAN_SCORR_THR_M1_THRES_EXT, m1Thresh[on]);
    OS_REG_RMW_FIELD(PHY_BB_EXT_CHAN_SCORR_THR_ADDRESS,
        PHY_BB_EXT_CHAN_SCORR_THR_M2_THRES_EXT, m2Thresh[on]);
#endif

    if (on) {
        OS_REG_SET_BIT(PHY_BB_SELF_CORR_LOW_ADDRESS,
            PHY_BB_SELF_CORR_LOW_USE_SELF_CORR_LOW);
    } else {
        OS_REG_CLR_BIT(PHY_BB_SELF_CORR_LOW_ADDRESS,
            PHY_BB_SELF_CORR_LOW_USE_SELF_CORR_LOW);
    }
#endif
}

SRAM_TEXT
void
ar6000ReducePacketGap(A_UINT16 queueIndex, A_UINT32 interval, A_UINT32 aifswait, A_BOOL retries)
{
}

SRAM_TEXT
void ar6000ContTXTestMode(A_BOOL enable)
{
#ifdef FIXME_WIFI2
    if (enable) {
        // Put PCU and DMA in continuous data mode
        OS_REG_WRITE(MAC_PCU_TST_ADDAC_ADDRESS, OS_REG_READ(MAC_PCU_TST_ADDAC_ADDRESS) | MAC_PCU_TST_ADDAC_CONT_TX_MASK);
        //disable encryption since packet has no header
        OS_REG_WRITE(MAC_PCU_DIAG_SW_ADDRESS, OS_REG_READ(MAC_PCU_DIAG_SW_ADDRESS) | MAC_PCU_DIAG_SW_NO_ENCRYPT_MASK);
    }
    else {
        // Put PCU and DMA back to normal data mode
        OS_REG_WRITE(MAC_PCU_TST_ADDAC_ADDRESS, OS_REG_READ(MAC_PCU_TST_ADDAC_ADDRESS) & ~MAC_PCU_TST_ADDAC_CONT_TX_MASK);
        // enable encryption back
        OS_REG_WRITE(MAC_PCU_DIAG_SW_ADDRESS, OS_REG_READ(MAC_PCU_DIAG_SW_ADDRESS) & ~MAC_PCU_DIAG_SW_NO_ENCRYPT_MASK);
    }
#endif
}

SRAM_TEXT
void
ar6000DisableScramble(A_BOOL disable)
{
#if !defined(FPGA)
    if (disable) {
        //OS_REG_SET_BIT(PHY_BB_BBB_TX_CTRL_ADDRESS,PHY_BB_BBB_TX_CTRL_DISABLE_SCRAMBLER);
        //OS_REG_RMW_FIELD(PDG_FEATURE_ENABLE_ADDRESS,PDG_FEATURE_ENABLE_ENABLE_ECO,0x2);
    	//Force fixed scrambler seed
        OS_REG_WRITE(PDG_SCRAMBLING_OVERIDE_ADDRESS,0x82);
        OS_REG_RMW_FIELD(PHY_BB_GEN_CONTROLS_ADDRESS,PHY_BB_GEN_CONTROLS_USE_WALSH_FOR_NSTS_EQ_NTX,0);
        OS_REG_RMW_FIELD(PHY_BB_GEN_CONTROLS_ADDRESS,PHY_BB_GEN_CONTROLS_APPLY_WALSH_ON_LEGACY,0);
    } else {
        //OS_REG_CLR_BIT(PHY_BB_BBB_TX_CTRL_ADDRESS,PHY_BB_BBB_TX_CTRL_DISABLE_SCRAMBLER);
        OS_REG_WRITE(PDG_SCRAMBLING_OVERIDE_ADDRESS,0x00);
    }
#endif
}

SRAM_TEXT
void ar6000PwrOnOffMAC(A_BOOL enable)
{
#ifdef FIXME_WIFI2
    if (enable) {
        A_RTC_WLAN_REG_WRITE (POWER_REG_ADDRESS, (A_RTC_WLAN_REG_READ(POWER_REG_ADDRESS)
                | (POWER_REG_WLAN_PWD_EN_MASK | POWER_REG_WLAN_MAC_PWD_EN_MASK)));
    }
    else {
        A_RTC_WLAN_REG_WRITE (POWER_REG_ADDRESS,
                (A_RTC_WLAN_REG_READ(POWER_REG_ADDRESS)
                & ~(POWER_REG_WLAN_PWD_EN_MASK |  POWER_REG_WLAN_MAC_PWD_EN_MASK)));
    }
#endif
}

SRAM_TEXT
void ar6000PostResetRegOverwrite(void *data)
{
    // for now, uses generic tcmd utility, but it's envisioned that ths part will be chip specific
    // once the other ART functionality is added
    whalResetPostProcessing();
}

/*
Word 2:0  BB8_TX1DB_BIQUAD
word 4:3  BB8_TX6DB_BIQUAD2
word 8:5  BB8_TXBB_GC
word 12:9 RXTX1_PADRV2GN2G
word 16:13 RXTX1_PADRV3GN5G
word 19:17 RXTX1_PADRV2GN5G
word 21   RXTX1_PADRVHALFGN2G
*/
#define  PEREGRINE_TXGAIN_TAB_TXBB1DBGAIN_LSB        0
#define  PEREGRINE_TXGAIN_TAB_TXBB1DBGAIN_MASK       0x7
#define  PEREGRINE_TXGAIN_TAB_TXBB6DBGAIN_LSB        3
#define  PEREGRINE_TXGAIN_TAB_TXBB6DBGAIN_MASK       0x3
#define  PEREGRINE_TXGAIN_TAB_TXMXRGAIN_LSB          5
#define  PEREGRINE_TXGAIN_TAB_TXMXRGAIN_MASK         0xf
#define  PEREGRINE_TXGAIN_TAB_PADRVGNA_LSB           9
#define  PEREGRINE_TXGAIN_TAB_PADRVGNA_MASK          0xf
#define  PEREGRINE_TXGAIN_TAB_PADRVGNB_LSB           13
#define  PEREGRINE_TXGAIN_TAB_PADRVGNB_MASK          0xf
#define  PEREGRINE_TXGAIN_TAB_PADRVGNC_LSB           17
#define  PEREGRINE_TXGAIN_TAB_PADRVGNC_MASK          0x7
#define  PEREGRINE_TXGAIN_TAB_GAININHALFDB_LSB       21
#define  PEREGRINE_TXGAIN_TAB_GAININHALFDB_MASK      0x1
#define  PEREGRINE_TXGAIN_TAB_PADRVGND_LSB           21
#define  PEREGRINE_TXGAIN_TAB_PADRVGND_MASK          0x3
#if 0
#define  PEREGRINE_TXGAIN_TAB_ENABLEPAL_LSB          23
#define  PEREGRINE_TXGAIN_TAB_ENABLEPAL_MASK         0x1
#endif

SRAM_TEXT
void ar6000ForceTxGainAnalogClear(A_UINT16 chain)
{
#ifdef FIXME_WIFI2
    A_UINT32 forceGain;
#if 0
    forceGain = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS+MAKE_CHAIN_REG(PHY_ANALOG_RXTX_B, chain, _RXTX1_OFFSET));
    forceGain &= ~ ( MAKE_CHAIN_REG(PHY_ANALOG_BB_B, chain, _BB8_TX1DB_BIQUAD_MASK) |
	             MAKE_CHAIN_REG(PHY_ANALOG_BB_B, chain, _BB8_TX6DB_BIQUAD1_MASK) |
	             MAKE_CHAIN_REG(PHY_ANALOG_BB_B, chain, _BB8_TX6DB_BIQUAD2_MASK) |
                     MAKE_CHAIN_REG(PHY_ANALOG_BB_B, chain, _BB8_TXBB_GC_MSB)       |
		     MAKE_CHAIN_REG(PHY_ANALOG_RXTX_B, chain, _RXTX1_PADRV2GN2G_MASK)     |
		     MAKE_CHAIN_REG(PHY_ANALOG_RXTX_B, chain, _RXTX1_PADRV2GN5G_MASK)     |
		     MAKE_CHAIN_REG(PHY_ANALOG_RXTX_B, chain, _RXTX1_PADRV3GN5G_MASK)   |
                     MAKE_CHAIN_REG(PHY_ANALOG_RXTX_B, chain, _RXTX1_PADRVHALFGN2G_MASK) );
    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS+MAKE_CHAIN_REG(PHY_ANALOG_RXTX_B, chain, _RXTX1_OFFSET), forceGain);
#endif
    if (chain & 0x1 ) {//chain 1
        forceGain = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_BB_B0_BB8_ADDRESS);
        forceGain &= ~((PHY_ANALOG_BB_B0_BB8_TX1DB_BIQUAD_MASK) |
	               (PHY_ANALOG_BB_B0_BB8_TX6DB_BIQUAD1_MASK) |  // set biquad1 to 0x0
	               (PHY_ANALOG_BB_B0_BB8_TX6DB_BIQUAD2_MASK) |
                       (PHY_ANALOG_BB_B0_BB8_TXBB_GC_MSB));
        A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_BB_B0_BB8_ADDRESS, forceGain);

        forceGain = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_RXTX_B0_RXTX1_OFFSET);
        forceGain &= ~((PHY_ANALOG_RXTX_B0_RXTX1_PADRV2GN2G_MASK)     |
		       (PHY_ANALOG_RXTX_B0_RXTX1_PADRV2GN5G_MASK)     |
		       (PHY_ANALOG_RXTX_B0_RXTX1_PADRV3GN5G_MASK)   |
                       (PHY_ANALOG_RXTX_B0_RXTX1_PADRVHALFGN2G_MASK) );
        A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_RXTX_B0_RXTX1_OFFSET, forceGain);
    }
    if (chain & 0x2 ) {//chain 2
        forceGain = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_BB_B1_BB8_ADDRESS);
        forceGain &= ~((PHY_ANALOG_BB_B1_BB8_TX1DB_BIQUAD_MASK) |
	               (PHY_ANALOG_BB_B1_BB8_TX6DB_BIQUAD1_MASK) |
	               (PHY_ANALOG_BB_B1_BB8_TX6DB_BIQUAD2_MASK) |
                       (PHY_ANALOG_BB_B1_BB8_TXBB_GC_MSB));
        A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_BB_B1_BB8_ADDRESS, forceGain);

        forceGain = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_RXTX_B1_RXTX1_OFFSET);
        forceGain &= ~((PHY_ANALOG_RXTX_B1_RXTX1_PADRV2GN2G_MASK)     |
		       (PHY_ANALOG_RXTX_B1_RXTX1_PADRV2GN5G_MASK)     |
		       (PHY_ANALOG_RXTX_B1_RXTX1_PADRV3GN5G_MASK)   |
                       (PHY_ANALOG_RXTX_B1_RXTX1_PADRVHALFGN2G_MASK) );
        A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_RXTX_B1_RXTX1_OFFSET, forceGain);
    }
    if (chain & 0x4 ) {//chain 3
        forceGain = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_BB_B2_BB8_ADDRESS);
        forceGain &= ~((PHY_ANALOG_BB_B2_BB8_TX1DB_BIQUAD_MASK) |
	               (PHY_ANALOG_BB_B2_BB8_TX6DB_BIQUAD1_MASK) |
	               (PHY_ANALOG_BB_B2_BB8_TX6DB_BIQUAD2_MASK) |
                       (PHY_ANALOG_BB_B2_BB8_TXBB_GC_MSB));
        A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_BB_B2_BB8_ADDRESS, forceGain);

        forceGain = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_RXTX_B2_RXTX1_OFFSET);
        forceGain &= ~((PHY_ANALOG_RXTX_B2_RXTX1_PADRV2GN2G_MASK)     |
		       (PHY_ANALOG_RXTX_B2_RXTX1_PADRV2GN5G_MASK)     |
		       (PHY_ANALOG_RXTX_B2_RXTX1_PADRV3GN5G_MASK)   |
                       (PHY_ANALOG_RXTX_B2_RXTX1_PADRVHALFGN2G_MASK) );
        A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_RXTX_B2_RXTX1_OFFSET, forceGain);
    }
#endif
}

SRAM_TEXT
void ar6000ForceTxGainAnalog(A_UINT16 pcDac, A_UINT16 chain)
{
#ifdef FIXME_WIFI2
    A_UINT32 i;
    A_UINT32 reg;
    A_UINT16 desiredGain;
    A_UINT32 forceGain;
    A_UINT32 maxTxGainIdx;
    A_UINT16 chainIdx;

    //A_PRINTF("4AG %d %d\n", pcDac, chain);
    maxTxGainIdx = PHY_BB_TPC_7_TX_GAIN_TABLE_MAX_GET(OS_REG_READ(PHY_BB_TPC_7_ADDRESS));
    chain &= WHAL_RC_FLAG_CHAIN_MASK;
    for (i=0;i<(maxTxGainIdx+1)/*PHY_BB_NUM_TX_GAIN_TABLE_ENTIRES*/;i++) {
        reg = OS_REG_READ(PHY_BB_TX_GAIN_TAB_1_ADDRESS + i * 4);
        //desiredGain = PHY_BB_TX_GAIN_TAB_DESIRED_GAIN_GET(reg);
        desiredGain = ((reg & 0xff000000) >> 24);
        if (desiredGain >= pcDac) {
#if 0
          if (chain & 0x1) {
            forceGain = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_BB_B0_BB8_ADDRESS);
            forceGain &= ~((PHY_ANALOG_BB_B0_BB8_TX1DB_BIQUAD_MASK) |
	                   (PHY_ANALOG_BB_B0_BB8_TX6DB_BIQUAD1_MASK) |
	                   (PHY_ANALOG_BB_B0_BB8_TX6DB_BIQUAD2_MASK) |
                           (PHY_ANALOG_BB_B0_BB8_TXBB_GC_MASK));
	    forceGain |=(PHY_ANALOG_BB_B0_BB8_TX1DB_BIQUAD_SET((reg >> PEREGRINE_TXGAIN_TAB_TXBB1DBGAIN_LSB) & PEREGRINE_TXGAIN_TAB_TXBB1DBGAIN_MASK)  |
                PHY_ANALOG_BB_B0_BB8_TX6DB_BIQUAD2_SET((reg >> PEREGRINE_TXGAIN_TAB_TXBB6DBGAIN_LSB) & PEREGRINE_TXGAIN_TAB_TXBB6DBGAIN_MASK) |
                PHY_ANALOG_BB_B0_BB8_TXBB_GC_SET((reg >> PEREGRINE_TXGAIN_TAB_TXMXRGAIN_LSB) & PEREGRINE_TXGAIN_TAB_TXMXRGAIN_MASK) );
            A_SOC_ADDR_WRITE((WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_BB_B0_BB8_ADDRESS), forceGain);

            forceGain = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_RXTX_B0_RXTX1_OFFSET);
            forceGain &= ~((PHY_ANALOG_RXTX_B0_RXTX1_PADRV2GN2G_MASK) |
	                   (PHY_ANALOG_RXTX_B0_RXTX1_PADRV3GN5G_MASK) |
	                   (PHY_ANALOG_RXTX_B0_RXTX1_PADRV2GN5G_MASK) |
                           (PHY_ANALOG_RXTX_B0_RXTX1_PADRVHALFGN2G_MASK));
	    forceGain |=(PHY_ANALOG_RXTX_B0_RXTX1_MANTXGAIN_SET(1) |
                PHY_ANALOG_RXTX_B0_RXTX1_PADRV2GN2G_SET((reg >> PEREGRINE_TXGAIN_TAB_PADRVGNA_LSB) & PEREGRINE_TXGAIN_TAB_PADRVGNA_MASK) |
                PHY_ANALOG_RXTX_B0_RXTX1_PADRV3GN5G_SET((reg >> PEREGRINE_TXGAIN_TAB_PADRVGNB_LSB) & PEREGRINE_TXGAIN_TAB_PADRVGNB_MASK) |
                PHY_ANALOG_RXTX_B0_RXTX1_PADRV2GN5G_SET((reg >> PEREGRINE_TXGAIN_TAB_PADRVGNC_LSB) & PEREGRINE_TXGAIN_TAB_PADRVGNC_MASK) |
                PHY_ANALOG_RXTX_B0_RXTX1_PADRVHALFGN2G_SET((reg >> PEREGRINE_TXGAIN_TAB_GAININHALFDB_LSB) & PEREGRINE_TXGAIN_TAB_GAININHALFDB_MASK));
            A_SOC_ADDR_WRITE((WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_RXTX_B0_RXTX1_OFFSET), forceGain);
          }
          if (chain & 0x2) {
            forceGain = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_BB_B1_BB8_ADDRESS);
            forceGain &= ~((PHY_ANALOG_BB_B1_BB8_TX1DB_BIQUAD_MASK) |
	                   (PHY_ANALOG_BB_B1_BB8_TX6DB_BIQUAD1_MASK) |
	                   (PHY_ANALOG_BB_B1_BB8_TX6DB_BIQUAD2_MASK) |
                           (PHY_ANALOG_BB_B1_BB8_TXBB_GC_MASK));
	    forceGain |=(PHY_ANALOG_BB_B1_BB8_TX1DB_BIQUAD_SET((reg >> PEREGRINE_TXGAIN_TAB_TXBB1DBGAIN_LSB) & PEREGRINE_TXGAIN_TAB_TXBB1DBGAIN_MASK)  |
                PHY_ANALOG_BB_B1_BB8_TX6DB_BIQUAD2_SET((reg >> PEREGRINE_TXGAIN_TAB_TXBB6DBGAIN_LSB) & PEREGRINE_TXGAIN_TAB_TXBB6DBGAIN_MASK) |
                PHY_ANALOG_BB_B1_BB8_TXBB_GC_SET((reg >> PEREGRINE_TXGAIN_TAB_TXMXRGAIN_LSB) & PEREGRINE_TXGAIN_TAB_TXMXRGAIN_MASK) );
            A_SOC_ADDR_WRITE((WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_BB_B1_BB8_ADDRESS), forceGain);

            forceGain = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_RXTX_B1_RXTX1_OFFSET);
            forceGain &= ~((PHY_ANALOG_RXTX_B1_RXTX1_PADRV2GN2G_MASK) |
	                   (PHY_ANALOG_RXTX_B1_RXTX1_PADRV3GN5G_MASK) |
	                   (PHY_ANALOG_RXTX_B1_RXTX1_PADRV2GN5G_MASK) |
                           (PHY_ANALOG_RXTX_B1_RXTX1_PADRVHALFGN2G_MASK));
	    forceGain |=(PHY_ANALOG_RXTX_B1_RXTX1_MANTXGAIN_SET(1) |
                PHY_ANALOG_RXTX_B1_RXTX1_PADRV2GN2G_SET((reg >> PEREGRINE_TXGAIN_TAB_PADRVGNA_LSB) & PEREGRINE_TXGAIN_TAB_PADRVGNA_MASK) |
                PHY_ANALOG_RXTX_B1_RXTX1_PADRV3GN5G_SET((reg >> PEREGRINE_TXGAIN_TAB_PADRVGNB_LSB) & PEREGRINE_TXGAIN_TAB_PADRVGNB_MASK) |
                PHY_ANALOG_RXTX_B1_RXTX1_PADRV2GN5G_SET((reg >> PEREGRINE_TXGAIN_TAB_PADRVGNC_LSB) & PEREGRINE_TXGAIN_TAB_PADRVGNC_MASK) |
                PHY_ANALOG_RXTX_B1_RXTX1_PADRVHALFGN2G_SET((reg >> PEREGRINE_TXGAIN_TAB_GAININHALFDB_LSB) & PEREGRINE_TXGAIN_TAB_GAININHALFDB_MASK));
            A_SOC_ADDR_WRITE((WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_RXTX_B1_RXTX1_OFFSET), forceGain);
          }
          if (chain & 0x4) {
            forceGain = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_BB_B2_BB8_ADDRESS);
            forceGain &= ~((PHY_ANALOG_BB_B2_BB8_TX1DB_BIQUAD_MASK) |
	                   (PHY_ANALOG_BB_B2_BB8_TX6DB_BIQUAD1_MASK) |
	                   (PHY_ANALOG_BB_B2_BB8_TX6DB_BIQUAD2_MASK) |
                           (PHY_ANALOG_BB_B2_BB8_TXBB_GC_MASK));
	    forceGain |=(PHY_ANALOG_BB_B2_BB8_TX1DB_BIQUAD_SET((reg >> PEREGRINE_TXGAIN_TAB_TXBB1DBGAIN_LSB) & PEREGRINE_TXGAIN_TAB_TXBB1DBGAIN_MASK)  |
                PHY_ANALOG_BB_B2_BB8_TX6DB_BIQUAD2_SET((reg >> PEREGRINE_TXGAIN_TAB_TXBB6DBGAIN_LSB) & PEREGRINE_TXGAIN_TAB_TXBB6DBGAIN_MASK) |
                PHY_ANALOG_BB_B2_BB8_TXBB_GC_SET((reg >> PEREGRINE_TXGAIN_TAB_TXMXRGAIN_LSB) & PEREGRINE_TXGAIN_TAB_TXMXRGAIN_MASK) );
            A_SOC_ADDR_WRITE((WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_BB_B2_BB8_ADDRESS), forceGain);

            forceGain = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_RXTX_B2_RXTX1_OFFSET);
            forceGain &= ~((PHY_ANALOG_RXTX_B2_RXTX1_PADRV2GN2G_MASK) |
	                   (PHY_ANALOG_RXTX_B2_RXTX1_PADRV3GN5G_MASK) |
	                   (PHY_ANALOG_RXTX_B2_RXTX1_PADRV2GN5G_MASK) |
                           (PHY_ANALOG_RXTX_B2_RXTX1_PADRVHALFGN2G_MASK));
	    forceGain |=(PHY_ANALOG_RXTX_B2_RXTX1_MANTXGAIN_SET(1) |
                PHY_ANALOG_RXTX_B2_RXTX1_PADRV2GN2G_SET((reg >> PEREGRINE_TXGAIN_TAB_PADRVGNA_LSB) & PEREGRINE_TXGAIN_TAB_PADRVGNA_MASK) |
                PHY_ANALOG_RXTX_B2_RXTX1_PADRV3GN5G_SET((reg >> PEREGRINE_TXGAIN_TAB_PADRVGNB_LSB) & PEREGRINE_TXGAIN_TAB_PADRVGNB_MASK) |
                PHY_ANALOG_RXTX_B2_RXTX1_PADRV2GN5G_SET((reg >> PEREGRINE_TXGAIN_TAB_PADRVGNC_LSB) & PEREGRINE_TXGAIN_TAB_PADRVGNC_MASK) |
                PHY_ANALOG_RXTX_B2_RXTX1_PADRVHALFGN2G_SET((reg >> PEREGRINE_TXGAIN_TAB_GAININHALFDB_LSB) & PEREGRINE_TXGAIN_TAB_GAININHALFDB_MASK));
            A_SOC_ADDR_WRITE((WLAN_ANALOG_INTF_BASE_ADDRESS+PHY_ANALOG_RXTX_B2_RXTX1_OFFSET), forceGain);
          }
#endif
#if 1
          for (chainIdx=0; chainIdx<getWhalNumChains() ;chainIdx++) {
            if ((chain >> chainIdx) & 0x1) {
            forceGain = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + (MAKE_CHAIN_REG_1(PHY_ANALOG_BB_B, chainIdx, _BB8_ADDRESS)));
            forceGain &= ~( (MAKE_CHAIN_REG_1(PHY_ANALOG_BB_B, chainIdx, _BB8_TX1DB_BIQUAD_MASK)) |
	                    (MAKE_CHAIN_REG_1(PHY_ANALOG_BB_B, chainIdx, _BB8_TX6DB_BIQUAD1_MASK)) |
	                    (MAKE_CHAIN_REG_1(PHY_ANALOG_BB_B, chainIdx, _BB8_TX6DB_BIQUAD2_MASK)) |
                            (MAKE_CHAIN_REG_1(PHY_ANALOG_BB_B, chainIdx, _BB8_TXBB_GC_MASK)));
	    forceGain |=(MAKE_CHAIN_REG_FUNC_1(PHY_ANALOG_BB_B, chainIdx, _BB8_TX1DB_BIQUAD_SET, ((reg >> PEREGRINE_TXGAIN_TAB_TXBB1DBGAIN_LSB) & PEREGRINE_TXGAIN_TAB_TXBB1DBGAIN_MASK))  |
                MAKE_CHAIN_REG_FUNC_1(PHY_ANALOG_BB_B, chainIdx, _BB8_TX6DB_BIQUAD2_SET, ((reg >> PEREGRINE_TXGAIN_TAB_TXBB6DBGAIN_LSB) & PEREGRINE_TXGAIN_TAB_TXBB6DBGAIN_MASK)) |
                MAKE_CHAIN_REG_FUNC_1(PHY_ANALOG_BB_B, chainIdx, _BB8_TXBB_GC_SET, ((reg >> PEREGRINE_TXGAIN_TAB_TXMXRGAIN_LSB) & PEREGRINE_TXGAIN_TAB_TXMXRGAIN_MASK)) );
            A_SOC_ADDR_WRITE((WLAN_ANALOG_INTF_BASE_ADDRESS + (MAKE_CHAIN_REG_1(PHY_ANALOG_BB_B, chainIdx, _BB8_ADDRESS))), forceGain);
            //A_PRINTF("ch %d, 0x%x, 0x%x\n", chainIdx, (WLAN_ANALOG_INTF_BASE_ADDRESS + (MAKE_CHAIN_REG_1(PHY_ANALOG_BB_B, chainIdx, _BB8_ADDRESS))), forceGain);

            forceGain = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + (MAKE_CHAIN_REG_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_OFFSET)));
            forceGain &= ~((MAKE_CHAIN_REG_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_PADRV2GN2G_MASK)) |
	                   (MAKE_CHAIN_REG_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_PADRV3GN5G_MASK)) |
	                   (MAKE_CHAIN_REG_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_PADRV2GN5G_MASK)) |
                           (MAKE_CHAIN_REG_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_PADRVHALFGN2G_MASK)));
	    forceGain |=((MAKE_CHAIN_REG_FUNC_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_MANTXGAIN_SET, 1)) |
                (MAKE_CHAIN_REG_FUNC_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_PADRV2GN2G_SET, ((reg >> PEREGRINE_TXGAIN_TAB_PADRVGNA_LSB) & PEREGRINE_TXGAIN_TAB_PADRVGNA_MASK))) |
                (MAKE_CHAIN_REG_FUNC_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_PADRV3GN5G_SET, ((reg >> PEREGRINE_TXGAIN_TAB_PADRVGNB_LSB) & PEREGRINE_TXGAIN_TAB_PADRVGNB_MASK))) |
                (MAKE_CHAIN_REG_FUNC_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_PADRV2GN5G_SET, ((reg >> PEREGRINE_TXGAIN_TAB_PADRVGNC_LSB) & PEREGRINE_TXGAIN_TAB_PADRVGNC_MASK))) |
                (MAKE_CHAIN_REG_FUNC_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_PADRVHALFGN2G_SET, ((reg >> PEREGRINE_TXGAIN_TAB_GAININHALFDB_LSB) & PEREGRINE_TXGAIN_TAB_GAININHALFDB_MASK))));
            A_SOC_ADDR_WRITE((WLAN_ANALOG_INTF_BASE_ADDRESS + (MAKE_CHAIN_REG_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_OFFSET))), forceGain);
            //A_PRINTF("ch %d, 0x%x, 0x%x\n", chainIdx, (WLAN_ANALOG_INTF_BASE_ADDRESS + (MAKE_CHAIN_REG_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_OFFSET))), forceGain);
          }
          }
#endif
          break;
        }
    }
    if (maxTxGainIdx+1 == i) {
        for (chainIdx=0; chainIdx<getWhalNumChains(); chainIdx++) {
            if ((chain >> chainIdx) & 0x1) {
            forceGain = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + (MAKE_CHAIN_REG_1(PHY_ANALOG_BB_B, chainIdx, _BB8_ADDRESS)));
            forceGain &= ~( (MAKE_CHAIN_REG_1(PHY_ANALOG_BB_B, chainIdx, _BB8_TX1DB_BIQUAD_MASK)) |
	                    (MAKE_CHAIN_REG_1(PHY_ANALOG_BB_B, chainIdx, _BB8_TX6DB_BIQUAD1_MASK)) |
	                    (MAKE_CHAIN_REG_1(PHY_ANALOG_BB_B, chainIdx, _BB8_TX6DB_BIQUAD2_MASK)) |
                            (MAKE_CHAIN_REG_1(PHY_ANALOG_BB_B, chainIdx, _BB8_TXBB_GC_MASK)));
	    forceGain |=(MAKE_CHAIN_REG_FUNC_1(PHY_ANALOG_BB_B, chainIdx, _BB8_TX1DB_BIQUAD_SET, ((reg >> PEREGRINE_TXGAIN_TAB_TXBB1DBGAIN_LSB) & PEREGRINE_TXGAIN_TAB_TXBB1DBGAIN_MASK))  |
                MAKE_CHAIN_REG_FUNC_1(PHY_ANALOG_BB_B, chainIdx, _BB8_TX6DB_BIQUAD2_SET, ((reg >> PEREGRINE_TXGAIN_TAB_TXBB6DBGAIN_LSB) & PEREGRINE_TXGAIN_TAB_TXBB6DBGAIN_MASK)) |
                MAKE_CHAIN_REG_FUNC_1(PHY_ANALOG_BB_B, chainIdx, _BB8_TXBB_GC_SET, ((reg >> PEREGRINE_TXGAIN_TAB_TXMXRGAIN_LSB) & PEREGRINE_TXGAIN_TAB_TXMXRGAIN_MASK)) );
            A_SOC_ADDR_WRITE((WLAN_ANALOG_INTF_BASE_ADDRESS + (MAKE_CHAIN_REG_1(PHY_ANALOG_BB_B, chainIdx, _BB8_ADDRESS))), forceGain);
            A_PRINTF("ch %d, 0x%x, 0x%x\n", chainIdx, (WLAN_ANALOG_INTF_BASE_ADDRESS + (MAKE_CHAIN_REG_1(PHY_ANALOG_BB_B, chainIdx, _BB8_ADDRESS))), forceGain);

            forceGain = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + (MAKE_CHAIN_REG_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_OFFSET)));
            forceGain &= ~((MAKE_CHAIN_REG_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_PADRV2GN2G_MASK)) |
	                   (MAKE_CHAIN_REG_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_PADRV3GN5G_MASK)) |
	                   (MAKE_CHAIN_REG_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_PADRV2GN5G_MASK)) |
                           (MAKE_CHAIN_REG_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_PADRVHALFGN2G_MASK)));
	    forceGain |=((MAKE_CHAIN_REG_FUNC_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_MANTXGAIN_SET, 1)) |
                (MAKE_CHAIN_REG_FUNC_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_PADRV2GN2G_SET, ((reg >> PEREGRINE_TXGAIN_TAB_PADRVGNA_LSB) & PEREGRINE_TXGAIN_TAB_PADRVGNA_MASK))) |
                (MAKE_CHAIN_REG_FUNC_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_PADRV3GN5G_SET, ((reg >> PEREGRINE_TXGAIN_TAB_PADRVGNB_LSB) & PEREGRINE_TXGAIN_TAB_PADRVGNB_MASK))) |
                (MAKE_CHAIN_REG_FUNC_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_PADRV2GN5G_SET, ((reg >> PEREGRINE_TXGAIN_TAB_PADRVGNC_LSB) & PEREGRINE_TXGAIN_TAB_PADRVGNC_MASK))) |
                (MAKE_CHAIN_REG_FUNC_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_PADRVHALFGN2G_SET, ((reg >> PEREGRINE_TXGAIN_TAB_GAININHALFDB_LSB) & PEREGRINE_TXGAIN_TAB_GAININHALFDB_MASK))));
            A_SOC_ADDR_WRITE((WLAN_ANALOG_INTF_BASE_ADDRESS + (MAKE_CHAIN_REG_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_OFFSET))), forceGain);
            A_PRINTF("ch %d, 0x%x, 0x%x\n", chainIdx, (WLAN_ANALOG_INTF_BASE_ADDRESS + (MAKE_CHAIN_REG_1(PHY_ANALOG_RXTX_B, chainIdx, _RXTX1_OFFSET))), forceGain);
          }
        }
    }
#endif
}

SRAM_TEXT
void ar6000ForceTxGainIdx(A_UINT8 gainIdx, A_INT8 dacGain, A_UINT8 txchain_mask)
{
#ifdef FIXME_WIFI2
    A_UINT32 reg;

    //A_PRINTF_ALWAYS("gIdx %d, dac %d, chMask %d\n", gainIdx, dacGain, txchain_mask);

    reg = OS_REG_READ(PHY_BB_TX_FORCED_GAIN_ADDRESS);
    reg &= ~PHY_BB_TX_FORCED_GAIN_FORCE_TX_GAIN_MASK;
    OS_REG_WRITE(PHY_BB_TX_FORCED_GAIN_ADDRESS, reg);

    reg = OS_REG_READ(PHY_BB_TPC_18_ADDRESS);
    reg &= ~PHY_BB_TPC_18_USE_LEGACY_TPC_MASK;
    OS_REG_WRITE(PHY_BB_TPC_18_ADDRESS, reg);

    reg = OS_REG_READ(PHY_BB_TPC_7_ADDRESS);
    reg &= ~(PHY_BB_TPC_7_FORCE_DAC_GAIN_MASK | PHY_BB_TPC_7_FORCED_DAC_GAIN_MASK);
    reg |= (PHY_BB_TPC_7_FORCE_DAC_GAIN_SET(1) | PHY_BB_TPC_7_FORCED_DAC_GAIN_SET(8*dacGain));
//    reg |= (PHY_BB_TPC_7_FORCE_DAC_GAIN_SET(1) | PHY_BB_TPC_7_FORCED_DAC_GAIN_SET(dacGain));
    OS_REG_WRITE(PHY_BB_TPC_7_ADDRESS, reg);

    reg = OS_REG_READ(PHY_BB_TPC_17_ADDRESS);
    reg &= ~PHY_BB_TPC_17_FORCE_TXGAIN_IDX_MASK;
    reg |= PHY_BB_TPC_17_FORCE_TXGAIN_IDX_SET(1);
    OS_REG_WRITE(PHY_BB_TPC_17_ADDRESS, reg);

#if 0 // TBD: debug why chainIdx 2 power too high ??
    {
    A_UINT32 chainIdx;
    for (chainIdx=0;chainIdx<getWhalNumChains();chainIdx++) {
        if (txchain_mask & (0x01 << chainIdx)) {
            reg = OS_REG_READ(MAKE_CHAIN_REG(PHY_BB_TPC_11_B, chainIdx, _ADDRESS));
            reg &= ~(MAKE_CHAIN_REG_2(PHY_BB_TPC_11_B, chainIdx, _FORCED_TXGAIN_IDX_, _MASK));
            reg |=  (MAKE_CHAIN_REG_FUNC_2(PHY_BB_TPC_11_B, chainIdx, _FORCED_TXGAIN_IDX_, _SET, gainIdx));
            OS_REG_WRITE(MAKE_CHAIN_REG(PHY_BB_TPC_11_B, chainIdx, _ADDRESS), reg);
            A_PRINTF("Set chMask %d chIdx %d reg 0x%x\n", (txchain_mask & (0x01 << chainIdx)), chainIdx, reg);
        }
    }
    }
#endif
#if 1
    if ( txchain_mask & 0x1 ) //chain 1
    {
        reg = OS_REG_READ(PHY_BB_TPC_11_B0_ADDRESS);
        reg &= ~PHY_BB_TPC_11_B0_FORCED_TXGAIN_IDX_0_MASK;
        reg |= PHY_BB_TPC_11_B0_FORCED_TXGAIN_IDX_0_SET(gainIdx);
        OS_REG_WRITE(PHY_BB_TPC_11_B0_ADDRESS, reg);
        //A_PRINTF("Set chMask %d reg 0x%x\n", (txchain_mask & 0x01 ), reg);
    }

    if ( txchain_mask & 0x2 ) //chain 2
    {
        reg = OS_REG_READ(PHY_BB_TPC_11_B1_ADDRESS);
        reg &= ~PHY_BB_TPC_11_B1_FORCED_TXGAIN_IDX_1_MASK;
        reg |= PHY_BB_TPC_11_B1_FORCED_TXGAIN_IDX_1_SET(gainIdx);
        OS_REG_WRITE(PHY_BB_TPC_11_B1_ADDRESS, reg);
        //A_PRINTF("Set chMask %d reg 0x%x\n", (txchain_mask & 0x02 ), reg);
    }

    if ( txchain_mask & 0x4 ) //chain 3
    {
        reg = OS_REG_READ(PHY_BB_TPC_11_B2_ADDRESS);
        reg &= ~PHY_BB_TPC_11_B2_FORCED_TXGAIN_IDX_2_MASK;
        reg |= PHY_BB_TPC_11_B2_FORCED_TXGAIN_IDX_2_SET(gainIdx);
        OS_REG_WRITE(PHY_BB_TPC_11_B2_ADDRESS, reg);
        //A_PRINTF("Set chMask %d reg 0x%x\n", (txchain_mask & 0x04 ), reg);
    }
#endif
#endif
    return;
}

SRAM_TEXT
void ar6000ForceTxTgtPwr(A_UINT16 tgtPwr, A_UINT8 chainMask)
{
#ifdef FIXME_WIFI2
    A_UINT32 reg;

    reg = OS_REG_READ(PHY_BB_TPC_18_ADDRESS);
    reg &= ~PHY_BB_TPC_18_USE_LEGACY_TPC_MASK;
    OS_REG_WRITE(PHY_BB_TPC_18_ADDRESS, reg);

    reg = OS_REG_READ(PHY_BB_TPC_17_ADDRESS);
    reg &= ~(PHY_BB_TPC_17_FORCE_TXGAIN_IDX_MASK | PHY_BB_TPC_17_OLPC_MODE_MASK);
    reg |= PHY_BB_TPC_17_OLPC_MODE_SET(1);
    OS_REG_WRITE(PHY_BB_TPC_17_ADDRESS, reg);

    reg = OS_REG_READ(PHY_BB_TX_FORCED_GAIN_ADDRESS);
    reg &= ~PHY_BB_TX_FORCED_GAIN_FORCE_TX_GAIN_MASK;
    OS_REG_WRITE(PHY_BB_TX_FORCED_GAIN_ADDRESS, reg);

    reg = OS_REG_READ(PHY_BB_TPC_7_ADDRESS);
    reg &= ~PHY_BB_TPC_7_FORCE_DAC_GAIN_MASK;
#if 0 // Is this required, from MDK script
    reg &= ~PHY_BB_TPC_7_TX_GAIN_TABLE_MAX_MASK;
    reg |= PHY_BB_TPC_7_TX_GAIN_TABLE_MAX_SET(21);
#endif
    OS_REG_WRITE(PHY_BB_TPC_7_ADDRESS, reg);

    reg = OS_REG_READ(PHY_BB_POWERTX_MAX_SUB_ADDRESS);
    reg &= ~(PHY_BB_POWERTX_MAX_SUB_USE_PER_PACKET_POWERTX_MAX_MASK | PHY_BB_POWERTX_MAX_SUB_USE_PER_PACKET_OLPC_GAIN_DELTA_ADJ_MASK);
    OS_REG_WRITE(PHY_BB_POWERTX_MAX_SUB_ADDRESS, reg);

    reg = OS_REG_READ(PHY_BB_TPC_2_ADDRESS);
    reg &= ~(PHY_BB_TPC_2_USE_FORCED_TARGET_POWER_MASK | PHY_BB_TPC_2_FORCED_TARGET_POWER_MASK);
    reg |= PHY_BB_TPC_2_FORCED_TARGET_POWER_SET(tgtPwr);
    OS_REG_WRITE(PHY_BB_TPC_2_ADDRESS, reg);
#endif

    return;
}

#define PHY_BB_TX_GAIN_TAB_DESIRED_GAIN_GET(x) (((x) & 0xff000000) >> 24)
#define PHY_BB_TX_GAIN_TAB_DESIRED_GAIN_SET(x) (((x) << 24) &  0xff000000)
SRAM_TEXT
A_UINT16 ar6000ForceTxGain(A_UINT16 pcDac)
{
#ifdef FIXME_WIFI2
    A_UINT32 i;
    A_UINT32 reg;
    A_UINT16 desiredGain;
    A_UINT16 dacGain;
    A_UINT32 forceGain;
    A_UINT32 maxTxGainIdx;

    maxTxGainIdx = PHY_BB_TPC_7_TX_GAIN_TABLE_MAX_GET(OS_REG_READ(PHY_BB_TPC_7_ADDRESS));
    for (i=0;i<(maxTxGainIdx+1)/*PHY_BB_NUM_TX_GAIN_TABLE_ENTIRES*/;i++) {
        reg = OS_REG_READ(PHY_BB_TX_GAIN_TAB_1_ADDRESS + i * 4);
        desiredGain = PHY_BB_TX_GAIN_TAB_DESIRED_GAIN_GET(reg);
        if (desiredGain >= pcDac) {
            dacGain = desiredGain - pcDac;

            forceGain = PHY_BB_TX_FORCED_GAIN_FORCE_TX_GAIN_SET(1) | ((reg & 0x00FFFFFF) << 1);
            OS_REG_WRITE(PHY_BB_TX_FORCED_GAIN_ADDRESS, forceGain);

            reg = OS_REG_READ(PHY_BB_TPC_1_ADDRESS);
#if 0 // No such definition in Peregrine
            reg &= ~(PHY_BB_TPC_1_FORCE_DAC_GAIN_MASK | PHY_BB_TPC_1_FORCED_DAC_GAIN_MASK);
            reg |= (PHY_BB_TPC_1_FORCE_DAC_GAIN_SET(1) | PHY_BB_TPC_1_FORCED_DAC_GAIN_SET(dacGain));
#endif
            OS_REG_WRITE(PHY_BB_TPC_1_ADDRESS, reg);

            break;
        }
    }
    if (maxTxGainIdx+1 == i) {
        dacGain = 0;
        forceGain = PHY_BB_TX_FORCED_GAIN_FORCE_TX_GAIN_SET(1) | ((reg & 0x00FFFFFF) << 1);
        OS_REG_WRITE(PHY_BB_TX_FORCED_GAIN_ADDRESS, forceGain);
        reg = OS_REG_READ(PHY_BB_TPC_1_ADDRESS);
#if 0 // No such definition in Peregrine
        reg &= ~(PHY_BB_TPC_1_FORCE_DAC_GAIN_MASK | PHY_BB_TPC_1_FORCED_DAC_GAIN_MASK);
        reg |= (PHY_BB_TPC_1_FORCE_DAC_GAIN_SET(1) | PHY_BB_TPC_1_FORCED_DAC_GAIN_SET(dacGain));
#endif
        OS_REG_WRITE(PHY_BB_TPC_1_ADDRESS, reg);

    }
    return i;
#else
    return 0;
#endif
}

SRAM_TEXT
void ar6000PostResetSetupOlpcCAL(void *data)
{
#ifdef FIXME_WIFI2
    // set alpha_term, alpha_volt to 0, and olpc_gain_delta 0, keep desired_scale value the same as in non-CAL
    // chain 0
    OS_REG_WRITE(PHY_BB_TPC_19_B0_ADDRESS, ((OS_REG_READ(PHY_BB_TPC_19_B0_ADDRESS) & ~PHY_BB_TPC_19_B0_ALPHA_THERM_0_MASK) | PHY_BB_TPC_19_B0_ALPHA_THERM_0_SET(0)) );
    OS_REG_WRITE(PHY_BB_TPC_19_B0_ADDRESS, ((OS_REG_READ(PHY_BB_TPC_19_B0_ADDRESS) & ~PHY_BB_TPC_19_B0_ALPHA_VOLT_0_MASK) | PHY_BB_TPC_19_B0_ALPHA_VOLT_0_SET(0)) );
    OS_REG_WRITE(PHY_BB_TPC_11_B0_ADDRESS, ((OS_REG_READ(PHY_BB_TPC_11_B0_ADDRESS) & ~PHY_BB_TPC_11_B0_OLPC_GAIN_DELTA_0_MASK) | PHY_BB_TPC_11_B0_OLPC_GAIN_DELTA_0_SET(0)) );

    // chain 1
    OS_REG_WRITE(PHY_BB_TPC_19_B1_ADDRESS, ((OS_REG_READ(PHY_BB_TPC_19_B1_ADDRESS) & ~PHY_BB_TPC_19_B1_ALPHA_THERM_1_MASK) | PHY_BB_TPC_19_B1_ALPHA_THERM_1_SET(0)) );
    OS_REG_WRITE(PHY_BB_TPC_19_B1_ADDRESS, ((OS_REG_READ(PHY_BB_TPC_19_B1_ADDRESS) & ~PHY_BB_TPC_19_B1_ALPHA_VOLT_1_MASK) | PHY_BB_TPC_19_B1_ALPHA_VOLT_1_SET(0)) );
    OS_REG_WRITE(PHY_BB_TPC_11_B1_ADDRESS, ((OS_REG_READ(PHY_BB_TPC_11_B1_ADDRESS) & ~PHY_BB_TPC_11_B1_OLPC_GAIN_DELTA_1_MASK) | PHY_BB_TPC_11_B1_OLPC_GAIN_DELTA_1_SET(0)) );
#endif

    return;
}

SRAM_TEXT
void ar6000SetTxPowerLimitAsIs(A_UINT16 pwr)
{
#ifdef FIXME_WIFI2
    A_UINT16 pwr_t2 = pwr/* *2 */;
    A_UINT16 ratesArray[RATE_MAX];
    A_UCHAR       is2GHz = 1;//WHAL_IS_CHAN_2GHZ(chan);
    A_UCHAR       isHT40 = 1;//WHAL_IS_CHAN_HT40(chan);
    //A_UCHAR       isHT20 = 1;//WHAL_IS_CHAN_HT20(chan);
    A_INT32 i;

    A_MEMZERO(ratesArray, sizeof(ratesArray));

    ratesArray[RATE_9]  = ratesArray[RATE_12] = ratesArray[RATE_18] = ratesArray[RATE_24] =
        ratesArray[RATE_36] = ratesArray[RATE_48] = ratesArray[RATE_54] = ratesArray[RATE_XR] = ratesArray[RATE_6]  = pwr_t2;

    for (i=0; i<14/*WHAL_NUM_HT_TARGET_POWER_RATES*/; i++) {
        ratesArray[RATE_HT20_0 + i] = pwr_t2;
    }

    if (is2GHz) {
        ratesArray[RATE_2S]   = ratesArray[RATE_2L]   = ratesArray[RATE_5_5S] = ratesArray[RATE_5_5L] = ratesArray[RATE_11S]  =
            ratesArray[RATE_11L]  = ratesArray[RATE_1L]   = pwr_t2;
    }

    if (isHT40) {
        for (i=0; i<14/*WHAL_NUM_HT_TARGET_POWER_RATES*/; i++) {
            ratesArray[RATE_HT40_0 + i] = pwr_t2;
        }
        ratesArray[RATE_DUP_CCK]  = ratesArray[RATE_EXT_OFDM] = ratesArray[RATE_DUP_OFDM] = pwr_t2;
        if (is2GHz) {
            ratesArray[RATE_EXT_CCK]  = pwr_t2;
        }
    }

#if 0 // No such registers in Peregrine
    /* Write the OFDM power per rate set */
    OS_REG_WRITE(PHY_BB_POWERTX_RATE1_ADDRESS,
                    (POW_SM(ratesArray[RATE_18], 24)
                   | POW_SM(ratesArray[RATE_12], 16)
                   | POW_SM(ratesArray[RATE_9],   8)
                   | POW_SM(ratesArray[RATE_6],   0)));

    OS_REG_WRITE(PHY_BB_POWERTX_RATE2_ADDRESS,
                    (POW_SM(ratesArray[RATE_54], 24)
                   | POW_SM(ratesArray[RATE_48], 16)
                   | POW_SM(ratesArray[RATE_36],  8)
                   | POW_SM(ratesArray[RATE_24],  0)));

    if (is2GHz) {
        A_UINT32 cckOfdmDelta=0;
        /* Write the CCK power per rate set */
        OS_REG_WRITE(PHY_BB_POWERTX_RATE3_ADDRESS,
                        (POW_SM(ratesArray[RATE_2S] + cckOfdmDelta, 24)
                       | POW_SM(ratesArray[RATE_2L] + cckOfdmDelta, 16)
                       | POW_SM(ratesArray[RATE_XR],  8) /* XR target power */
                       | POW_SM(ratesArray[RATE_1L] + cckOfdmDelta,  0)));

        OS_REG_WRITE(PHY_BB_POWERTX_RATE4_ADDRESS,
                        (POW_SM(ratesArray[RATE_11S] + cckOfdmDelta, 24)
                       | POW_SM(ratesArray[RATE_11L] + cckOfdmDelta, 16)
                       | POW_SM(ratesArray[RATE_5_5S] + cckOfdmDelta, 8)
                       | POW_SM(ratesArray[RATE_5_5L] + cckOfdmDelta, 0)));
    }

    /*
     * Write the HT20 power per rate set
     * Use the same entry for MCS 1/2/3
     */
    OS_REG_WRITE(PHY_BB_POWERTX_RATE5_ADDRESS,
                    (POW_SM(ratesArray[RATE_HT20_5], 24)
                   | POW_SM(ratesArray[RATE_HT20_4], 16)
                   | POW_SM(ratesArray[RATE_HT20_1],  8)
                   | POW_SM(ratesArray[RATE_HT20_0],  0)));
    WHALDEBUG(WHAL_DEBUG_EEPROM, "PHY_BB_POWERTX_RATE5 = 0x%x \n", OS_REG_READ(PHY_BB_POWERTX_RATE5_ADDRESS));

    OS_REG_WRITE(PHY_BB_POWERTX_RATE6_ADDRESS,
                    (POW_SM(ratesArray[RATE_HT20_13], 24)
                   | POW_SM(ratesArray[RATE_HT20_12], 16)
                   | POW_SM(ratesArray[RATE_HT20_7],  8)
                   | POW_SM(ratesArray[RATE_HT20_6],  0)));
    WHALDEBUG(WHAL_DEBUG_EEPROM, "PHY_BB_POWERTX_RATE6 = 0x%x \n", OS_REG_READ(PHY_BB_POWERTX_RATE6_ADDRESS));

    if (isHT40) {
        A_UINT32 ht40PowerIncForPdadc = 0;

        /* Use the same entry for MCS 1/2/3 */
        OS_REG_WRITE(PHY_BB_POWERTX_RATE7_ADDRESS,
                        (POW_SM(ratesArray[RATE_HT40_5] + ht40PowerIncForPdadc, 24)
                       | POW_SM(ratesArray[RATE_HT40_4] + ht40PowerIncForPdadc, 16)
                       | POW_SM(ratesArray[RATE_HT40_1] + ht40PowerIncForPdadc,  8)
                       | POW_SM(ratesArray[RATE_HT40_0] + ht40PowerIncForPdadc,  0)));
        OS_REG_WRITE(PHY_BB_POWERTX_RATE8_ADDRESS,
                        (POW_SM(ratesArray[RATE_HT40_13] + ht40PowerIncForPdadc, 24)
                       | POW_SM(ratesArray[RATE_HT40_12] + ht40PowerIncForPdadc, 16)
                       | POW_SM(ratesArray[RATE_HT40_7]  + ht40PowerIncForPdadc,  8)
                       | POW_SM(ratesArray[RATE_HT40_6]  + ht40PowerIncForPdadc,  0)));

        /* Write the Dup/Ext 40 power per rate set */
        OS_REG_WRITE(PHY_BB_POWERTX_RATE9_ADDRESS,
                        (POW_SM(ratesArray[RATE_EXT_OFDM], 24)
                       | POW_SM(ratesArray[RATE_EXT_CCK],  16)
                       | POW_SM(ratesArray[RATE_DUP_OFDM],  8)
                       | POW_SM(ratesArray[RATE_DUP_CCK],   0)));
    }

    OS_REG_WRITE(PHY_BB_POWERTX_RATE10_ADDRESS,
                    (POW_SM(ratesArray[RATE_HT20_15],  8)
                   | POW_SM(ratesArray[RATE_HT20_14],  0)));

    if (isHT40) {
        A_UINT8 ht40PowerIncForPdadc=0;
        /* Write the HT40 power per rate set */

        /* Use the same entry for MCS 1/2/3 */
        OS_REG_WRITE(PHY_BB_POWERTX_RATE12_ADDRESS,
                        (POW_SM(ratesArray[RATE_HT40_15] + ht40PowerIncForPdadc,  8)
                       | POW_SM(ratesArray[RATE_HT40_14] + ht40PowerIncForPdadc,  0)));

    }
#endif


    /*
     * Set max power to 30 dBm and, optionally,
     */
    OS_REG_WRITE(PHY_BB_POWERTX_MAX_SUB_ADDRESS, WHAL_MAX_RATE_POWER);
#endif

    return;
}

/*
 * Set contention window.
 *cwmin and cwmax are limited to values that are powers of two minus 1: 0, 1, 3, 7, ....
*/
SRAM_TEXT
void ar6000SetTransmitContentionWindow(int dcu, int cwmin, int cwmax)
{
#ifdef FIXME_WIFI2
	static A_INT32 allowed[]={0x0,0x1,0x3,0x7,0xf,0x1f,0x3f,0x7f,0xff,0x1ff,0x3ff};
	A_INT32 nallowed;
	A_INT32 it;
	A_UINT32 reg;
	//
	// default values
	//
	nallowed=sizeof(allowed)/sizeof(int);

	if(cwmin<0)
	{
		cwmin=0xf;
	}
	else if(cwmin>=allowed[nallowed-1])
	{
		cwmin=allowed[nallowed-1];
	}
	else
	{
		for(it=0; it<sizeof(allowed)/sizeof(int); it++)
		{
			if(cwmin>allowed[it])
			{
				cwmin=allowed[it];
				break;
			}
		}
	}

	if(cwmax<0)
	{
		cwmax=0x3ff;
	}
	else if(cwmax>=allowed[nallowed-1])
	{
		cwmax=allowed[nallowed-1];
	}
	else
	{
		for(it=0; it<sizeof(allowed)/sizeof(int); it++)
		{
			if(cwmax>allowed[it])
			{
				cwmax=allowed[it];
				break;
			}
		}
	}

	if(cwmin>cwmax)
	{
		cwmin=cwmax;
	}

    reg = OS_REG_READ(MAC_DCU_LCL_IFS_ADDR(dcu)) & ~(MAC_DCU_LCL_IFS_0_CW_MIN_MASK | MAC_DCU_LCL_IFS_0_CW_MAX_MASK);
    OS_REG_WRITE(MAC_DCU_LCL_IFS_ADDR(dcu),(reg | MAC_DCU_LCL_IFS_0_CW_MIN_SET(cwmin) | MAC_DCU_LCL_IFS_0_CW_MAX_SET(cwmax)));
#endif
}

SRAM_TEXT
void ar6000ReceiveDeafMode(A_UINT32 deaf)
{
#ifdef FIXME_WIFI2
    static A_UINT32 deafMode=0;
    static A_UINT32 undeafThresh62 = 0;
    static A_UINT32 undeafThresh62Ext = 0;
    static A_UINT32 undeafForceAgcClear = 0;
    static A_UINT32 undeafCycpwrThr1 = 0;
//    static A_UINT32 undeafCycpwrThr1Ext = 0;
    static A_UINT32 undeafRssiThr1a = 0;


    if (deafMode == 0) {
        undeafThresh62 = MS(OS_REG_READ(PHY_BB_CCA_B0_ADDRESS), PHY_BB_CCA_B0_THR_CCA);
        undeafThresh62Ext = MS(OS_REG_READ(PHY_BB_EXT_CHAN_PWR_THR_1_ADDRESS), PHY_BB_EXT_CHAN_PWR_THR_1_THR_CCA_EXT40);
        undeafForceAgcClear = MS(OS_REG_READ(PHY_BB_TEST_CONTROLS_ADDRESS), PHY_BB_TEST_CONTROLS_FORCE_AGC_CLEAR);
        undeafCycpwrThr1 = MS(OS_REG_READ(PHY_BB_TIMING_CONTROL_5_ADDRESS), PHY_BB_TIMING_CONTROL_5_CYCPWR_THR1);
#if 0 // No such register in Peregrine
        undeafCycpwrThr1Ext = MS(OS_REG_READ(PHY_BB_EXT_CHAN_PWR_THR_2_B0_ADDRESS), PHY_BB_EXT_CHAN_PWR_THR_2_B0_CYCPWR_THR1_EXT);
#endif
        undeafRssiThr1a = MS(OS_REG_READ(PHY_BB_TIMING_CONTROL_5_ADDRESS), PHY_BB_TIMING_CONTROL_5_RSSI_THR1A);
    }

    if(deaf) {
        OS_REG_RMW_FIELD(PHY_BB_CCA_B0_ADDRESS,PHY_BB_CCA_B0_THR_CCA,0x7f);
        OS_REG_RMW_FIELD(PHY_BB_EXT_CHAN_PWR_THR_1_ADDRESS,PHY_BB_EXT_CHAN_PWR_THR_1_THR_CCA_EXT40,0x7f);
        OS_REG_RMW_FIELD(PHY_BB_TEST_CONTROLS_ADDRESS,PHY_BB_TEST_CONTROLS_FORCE_AGC_CLEAR,1);
        OS_REG_RMW_FIELD(PHY_BB_TIMING_CONTROL_5_ADDRESS,PHY_BB_TIMING_CONTROL_5_CYCPWR_THR1,0x7f);
#if 0 // No such register in Peregrine
        OS_REG_RMW_FIELD(PHY_BB_EXT_CHAN_PWR_THR_2_B0_ADDRESS,PHY_BB_EXT_CHAN_PWR_THR_2_B0_CYCPWR_THR1_EXT,0x7f);
#endif
        OS_REG_RMW_FIELD(PHY_BB_TIMING_CONTROL_5_ADDRESS,PHY_BB_TIMING_CONTROL_5_RSSI_THR1A,0x7f);
        deafMode=1;
    } else {
        OS_REG_RMW_FIELD(PHY_BB_CCA_B0_ADDRESS,PHY_BB_CCA_B0_THR_CCA,undeafThresh62);
        OS_REG_RMW_FIELD(PHY_BB_EXT_CHAN_PWR_THR_1_ADDRESS,PHY_BB_EXT_CHAN_PWR_THR_1_THR_CCA_EXT40,undeafThresh62Ext);
        OS_REG_RMW_FIELD(PHY_BB_TEST_CONTROLS_ADDRESS,PHY_BB_TEST_CONTROLS_FORCE_AGC_CLEAR,undeafForceAgcClear);
        OS_REG_RMW_FIELD(PHY_BB_TIMING_CONTROL_5_ADDRESS,PHY_BB_TIMING_CONTROL_5_CYCPWR_THR1,undeafCycpwrThr1);
#if 0 // No such register in Peregrine
        OS_REG_RMW_FIELD(PHY_BB_EXT_CHAN_PWR_THR_2_B0_ADDRESS,PHY_BB_EXT_CHAN_PWR_THR_2_B0_CYCPWR_THR1_EXT,undeafCycpwrThr1Ext);
#endif
        OS_REG_RMW_FIELD(PHY_BB_TIMING_CONTROL_5_ADDRESS,PHY_BB_TIMING_CONTROL_5_RSSI_THR1A,undeafRssiThr1a);
        deafMode=0;
    }
#endif
}

SRAM_TEXT
void ar6000Dac_playback(A_UINT8 chainmask, A_UINT8 side)
{
#if defined(_WHEN_TPC_IS_READY_ONEBYONE)
    A_UINT16 i;
    A_UINT16 data, data_low, data_high;
    A_INT16  temp_low_i, temp_low_q, temp_high_i, temp_high_q;
    A_UINT8  scale;
    A_UINT16  start_idx, end_idx, step_size;

    //A_PRINTF_ALWAYS("%s \n", __func__);

    scale = 0;
    start_idx = 0;
    end_idx = 512;
    step_size = 2;

    OS_REG_WRITE(PHY_BB_CHN_TABLES_INTF_ADDR_ADDRESS, 0xb00);//chain0 chaninfo memory interface
    OS_REG_WRITE(PHY_BB_CHN1_TABLES_INTF_ADDR_ADDRESS, 0xb00);//chain1 chaninfo memory interface
    OS_REG_WRITE(PHY_BB_CHN_TABLES_INTF_DATA_ADDRESS, 0xff0001);//chain0 chaninfo memory interface
    OS_REG_WRITE(PHY_BB_CHN1_TABLES_INTF_DATA_ADDRESS, 0xff0001);//chain1 chaninfo memory interface

    OS_REG_WRITE(PHY_BB_CHN_TABLES_INTF_ADDR_ADDRESS, 0x80003200);//chain0 chaninfo memory interface
    OS_REG_WRITE(PHY_BB_CHN1_TABLES_INTF_ADDR_ADDRESS, 0x80003200);//chain1 chaninfo memory interface

    for (i = 0 ;i < 512;i++) {
        temp_low_i = sine_wave[i][0];
        temp_low_q = sine_wave[i][1];
        if (side == 0) {
            temp_low_q = -temp_low_q;
        }
        if (temp_low_i < 0){
            temp_low_i = 2048 + temp_low_i;
	}
        if (temp_low_q < 0){
            temp_low_q = 2048 + temp_low_q;
	}
        temp_low_i = temp_low_i/(scale + 1);
        temp_low_q = temp_low_q/(scale + 1);
        i++;

        temp_high_i = sine_wave[i][0];
        temp_high_q = sine_wave[i][1];
        if (side == 0) {
            temp_high_q = -temp_high_q;
        }
        if (temp_high_i < 0){
            temp_high_i = 2048 + temp_high_i;
	}
        if (temp_high_q < 0){
            temp_high_q = 2048 + temp_high_q;
	}
        temp_high_i = temp_high_i/(scale + 1);
        temp_high_q = temp_high_q/(scale + 1);

        data = (temp_low_q << 11) + temp_low_i;
        data_low = (temp_high_i << 22) + data;

        OS_REG_WRITE(PHY_BB_CHN_TABLES_INTF_DATA_ADDRESS, data_low & 0xffffffff);
        OS_REG_WRITE(PHY_BB_CHN1_TABLES_INTF_DATA_ADDRESS, data_low & 0xffffffff);
    }

    OS_REG_WRITE(PHY_BB_CHN_TABLES_INTF_ADDR_ADDRESS, 0xb00);//chain0 chaninfo memory interface
    OS_REG_WRITE(PHY_BB_CHN1_TABLES_INTF_ADDR_ADDRESS, 0xb00);//chain1 chaninfo memory interface
    OS_REG_WRITE(PHY_BB_CHN_TABLES_INTF_DATA_ADDRESS, 0xff0003);//chain0 chaninfo memory interface
    OS_REG_WRITE(PHY_BB_CHN1_TABLES_INTF_DATA_ADDRESS, 0xff0003);//chain1 chaninfo memory interface

    OS_REG_WRITE(PHY_BB_CHN_TABLES_INTF_ADDR_ADDRESS, 0x80003200);//chain0 chaninfo memory interface
    OS_REG_WRITE(PHY_BB_CHN1_TABLES_INTF_ADDR_ADDRESS, 0x80003200);//chain1 chaninfo memory interface

    for (i = 0 ;i < 512;i++) {
        temp_low_i = sine_wave[i][0];
        temp_low_q = sine_wave[i][1];
        i++;

        temp_high_i = sine_wave[i][0];
        temp_high_q = sine_wave[i][1];
        if (side == 0) {
            temp_high_q = -temp_high_q;
        }
        if (temp_high_i < 0){
            temp_high_i = 2048 + temp_high_i;
	}
        if (temp_high_q < 0){
            temp_high_q = 2048 + temp_high_q;
	}
        temp_high_i = temp_high_i >> scale;
        temp_high_q = temp_high_q >> scale;

        data = (temp_low_q << 11) + temp_low_i;
        data_high = data >> 10;

        OS_REG_WRITE(PHY_BB_CHN_TABLES_INTF_DATA_ADDRESS, data_high & 0xffffffff);
        OS_REG_WRITE(PHY_BB_CHN1_TABLES_INTF_DATA_ADDRESS, data_high & 0xffffffff);
    }
    if (chainmask & 0x1)
    {
        OS_REG_WRITE(PHY_BB_CHN_TABLES_INTF_ADDR_ADDRESS, 0xb00);
        OS_REG_WRITE(PHY_BB_CHN_TABLES_INTF_DATA_ADDRESS, (0x21 | (start_idx << 8) | (end_idx << 16) | ((step_size & 0x3) << 2)));
    }

    if (chainmask & 0x2)
    {
        OS_REG_WRITE(PHY_BB_CHN1_TABLES_INTF_ADDR_ADDRESS, 0xb00);
        OS_REG_WRITE(PHY_BB_CHN1_TABLES_INTF_DATA_ADDRESS, (0x21 | (start_idx << 8) | (end_idx << 16) | ((step_size & 0x3) << 2)));
    }
#endif //#if defined(_WHEN_TPC_IS_READY_ONEBYONE)
}

SRAM_TEXT
void ar6000SetTpcForcedTxgainIdxWfm(A_UINT8 paConfig, A_INT8 dacGain, A_UINT8 gainIdx, A_UINT32 freq, A_UINT8 txchain_mask)
{
#if defined(_WHEN_TPC_IS_READY_ONEBYONE)
#if !defined(FPGA)
    A_UINT32  reg32;
    A_UINT32  analog_gain;
    A_UINT32  mode = MODE_11G;
    if (freq == BG_FREQ_MAX ||  ((freq < BG_FREQ_MAX) && (freq >= BG_FREQ_MIN) && !((freq - BG_FREQ_MIN) % 5))) {
        mode = MODE_11G;
    }
    else {
        mode = MODE_11A;
    }

    reg32 = OS_REG_READ(PHY_BB_TX_FORCED_GAIN_ADDRESS);
    reg32 &= ~PHY_BB_TX_FORCED_GAIN_FORCE_TX_GAIN_MASK;
    OS_REG_WRITE(PHY_BB_TX_FORCED_GAIN_ADDRESS, reg32);

    reg32 = OS_REG_READ(PHY_BB_TPC_18_ADDRESS);
    reg32 &= ~PHY_BB_TPC_18_USE_LEGACY_TPC_MASK;
    OS_REG_WRITE(PHY_BB_TPC_18_ADDRESS, reg32);

    reg32 = OS_REG_READ(PHY_BB_TPC_7_ADDRESS);
    reg32 &= ~(PHY_BB_TPC_7_FORCE_DAC_GAIN_MASK  |
//             PHY_BB_TPC_7_OLPC_MODE_MASK       |//TDB can this mode set in other functin ?
               PHY_BB_TPC_7_FORCE_PA_CFG_MASK |
               PHY_BB_TPC_7_FORCE_TXGAIN_IDX_MASK);
    reg32 |= (PHY_BB_TPC_7_FORCE_DAC_GAIN_SET(1)  |
//              PHY_BB_TPC_7_OLPC_MODE_SET(1)       |//TDB can this mode set in other functin ?
              PHY_BB_TPC_7_FORCE_PA_CFG_SET(1) |
              PHY_BB_TPC_7_FORCE_TXGAIN_IDX_SET(1));
    OS_REG_WRITE(PHY_BB_TPC_7_ADDRESS, reg32);

#if 0
    if ( txchain_mask & 0x1 ) //chain 0
    {
        reg32 = OS_REG_READ(PHY_BB_TPC_11_B0_ADDRESS);
        reg32 &= ~(PHY_BB_TPC_11_B0_FORCED_DAC_GAIN_0_MASK   |
                   PHY_BB_TPC_11_B0_FORCED_PA_CFG_0_MASK     |
                   PHY_BB_TPC_11_B0_FORCED_TXGAIN_IDX_0_MASK);
        reg32 |= (PHY_BB_TPC_11_B0_FORCED_DAC_GAIN_0_SET(dacGain*8)|  //TDB do we use dacGain*8 ?
                  PHY_BB_TPC_11_B0_FORCED_PA_CFG_0_SET(paConfig) |
                  PHY_BB_TPC_11_B0_FORCED_TXGAIN_IDX_0_SET(gainIdx));
        OS_REG_WRITE(PHY_BB_TPC_11_B0_ADDRESS, reg32);

        //A_PRINTF("Set chMask %d reg 0x%x\n", (txchain_mask & 0x01 ), reg);
    }

    if ( txchain_mask & 0x2 ) //chain 1
    {
        reg32 = OS_REG_READ(PHY_BB_TPC_11_B1_ADDRESS);
        reg32 &= ~(PHY_BB_TPC_11_B1_FORCED_DAC_GAIN_1_MASK   |
                   PHY_BB_TPC_11_B1_FORCED_TXGAIN_IDX_1_MASK);
        reg32 |= (PHY_BB_TPC_11_B1_FORCED_DAC_GAIN_1_SET(dacGain*8)|//TDB do we use dacGain*8 ?
                  PHY_BB_TPC_11_B1_FORCED_TXGAIN_IDX_1_SET(gainIdx));
        OS_REG_WRITE(PHY_BB_TPC_11_B1_ADDRESS, reg32);

        //A_PRINTF("Set chMask %d reg 0x%x\n", (txchain_mask & 0x02 ), reg);
    }

#endif

    //OS_REG_WRITE(PHY_BB_TABLES_INTF_ADDR_B0_ADDRESS, 0X80000400 + 4 * gainIdx);//5G

    if (mode == MODE_11A) { /* 5GHz */
        OS_REG_WRITE(PHY_BB_TABLES_INTF_ADDR_B0_ADDRESS, 0X400 + 4 * gainIdx);//5g
    } else {
        OS_REG_WRITE(PHY_BB_TABLES_INTF_ADDR_B0_ADDRESS, 0X480 + 4 * gainIdx);//2g
    }
    analog_gain = OS_REG_READ(PHY_BB_TABLES_INTF_DATA_B0_ADDRESS);

    A_PRINTF("!!bq2:%d , bq1:%d, gc:%d\n",analog_gain & 0xf,(analog_gain >> 4) & 0x3,(analog_gain >> 6) & 0x7);

    OS_REG_WRITE(PHY_BB_FORCE_ANALOG_ADDRESS, 7); // wb294x set 7 other set 0

    //ar6000ForcePACfg(paConfig & 0x7, txchain_mask); //in glut pa_cfg[2:0],txgain_idx_cal[7:3]
    reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B0_RXTX1_ADDRESS);

    reg32 &= ~(WL_TOP_B0_RXTX1_XPA5ON_MASK |
               WL_TOP_B0_RXTX1_XPA2ON_MASK |
               WL_TOP_B0_RXTX1_XPAON_OVR_MASK);
    reg32 |=   WL_TOP_B0_RXTX1_XPAON_OVR_SET(1);

    if(mode == MODE_11A) { /* 5GHz */
        reg32 |= (WL_TOP_B0_RXTX1_XPA5ON_SET(1) | WL_TOP_B0_RXTX1_XPA2ON_SET(0));
    }
    else
    {
        reg32 |= (WL_TOP_B0_RXTX1_XPA5ON_SET(0) | WL_TOP_B0_RXTX1_XPA2ON_SET(1));
    }

    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B0_RXTX1_ADDRESS, reg32);

    reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B1_RXTX1_ADDRESS);

    reg32 &= ~(WL_TOP_B1_RXTX1_XPA5ON_MASK |
               WL_TOP_B1_RXTX1_XPA2ON_MASK |
               WL_TOP_B1_RXTX1_XPAON_OVR_MASK);
    reg32 |=   WL_TOP_B1_RXTX1_XPAON_OVR_SET(1);

    if(mode == MODE_11A) { /* 5GHz */
        reg32 |= (WL_TOP_B1_RXTX1_XPA5ON_SET(1) | WL_TOP_B1_RXTX1_XPA2ON_SET(0));
    }
    else
    {
        reg32 |= (WL_TOP_B0_RXTX1_XPA5ON_SET(0) | WL_TOP_B1_RXTX1_XPA2ON_SET(1));
    }

    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B1_RXTX1_ADDRESS, reg32);


    OS_REG_WRITE(PHY_BB_MISC_PA_CONTROL_ADDRESS, 0);
    if (mode == MODE_11A) { /* 5GHz */
        OS_REG_RMW_FIELD(PHY_BB_MISC_PA_CONTROL_ADDRESS, PHY_BB_MISC_PA_CONTROL_ENABLE_XPAB, 1);
        OS_REG_RMW_FIELD(PHY_BB_MISC_PA_CONTROL_ADDRESS, PHY_BB_MISC_PA_CONTROL_ENABLE_XPAA, 0);
    }
    else
    {
        OS_REG_RMW_FIELD(PHY_BB_MISC_PA_CONTROL_ADDRESS, PHY_BB_MISC_PA_CONTROL_ENABLE_XPAB, 0);
        OS_REG_RMW_FIELD(PHY_BB_MISC_PA_CONTROL_ADDRESS, PHY_BB_MISC_PA_CONTROL_ENABLE_XPAA, 1);
    }

    if (mode == MODE_11A) { /* 5GHz */
        OS_REG_RMW_FIELD(PHY_BB_SYNTH_CONTROL_ADDRESS, PHY_BB_SYNTH_CONTROL_RFBMODE, 0);// it's set for 5G now
    } else {
        OS_REG_RMW_FIELD(PHY_BB_SYNTH_CONTROL_ADDRESS, PHY_BB_SYNTH_CONTROL_RFBMODE, 1);// it's set for 2G now
    }

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B0_RXTX2_ADDRESS);
    reg32 &= ~(WL_TOP_B0_RXTX2_TXON_OVR_MASK       |
               WL_TOP_B0_RXTX2_TXON_MASK           |
               WL_TOP_B0_RXTX2_BW_ST_OVR_MASK      |
               WL_TOP_B0_RXTX2_BW_ST_MASK          |
               WL_TOP_B0_RXTX2_SYNTHON_OVR_MASK    |
               WL_TOP_B0_RXTX2_SYNTHON_MASK        |
               WL_TOP_B0_RXTX2_BMODE_OVR_MASK      |
               WL_TOP_B0_RXTX2_BMODE_MASK          );

    reg32 |=  (WL_TOP_B0_RXTX2_TXON_OVR_SET(1)       |
               WL_TOP_B0_RXTX2_TXON_SET(1)           |
               WL_TOP_B0_RXTX2_BW_ST_OVR_SET(1)      |
               WL_TOP_B0_RXTX2_BW_ST_SET(3)          |
               WL_TOP_B0_RXTX2_SYNTHON_OVR_SET(1)    |
               WL_TOP_B0_RXTX2_SYNTHON_SET(1)        |
               WL_TOP_B0_RXTX2_BMODE_OVR_SET(1)      );

    if (mode == MODE_11G) { /* 2GHz */
        reg32 |= WL_TOP_B0_RXTX2_BMODE_SET(1);  // it's set for 2G now
    }

    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B0_RXTX2_ADDRESS, reg32);

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B1_RXTX2_ADDRESS);
    reg32 &= ~(WL_TOP_B1_RXTX2_TXON_OVR_MASK       |
               WL_TOP_B1_RXTX2_TXON_MASK           |
               WL_TOP_B1_RXTX2_BW_ST_OVR_MASK      |
               WL_TOP_B1_RXTX2_BW_ST_MASK          |
               WL_TOP_B1_RXTX2_SYNTHON_OVR_MASK    |
               WL_TOP_B1_RXTX2_SYNTHON_MASK        |
               WL_TOP_B1_RXTX2_BMODE_OVR_MASK      |
               WL_TOP_B1_RXTX2_BMODE_MASK
                                                   );

    reg32 |=  (WL_TOP_B1_RXTX2_TXON_OVR_SET(1)       |
               WL_TOP_B1_RXTX2_TXON_SET(1)           |
               WL_TOP_B1_RXTX2_BW_ST_OVR_SET(1)      |
               WL_TOP_B1_RXTX2_BW_ST_SET(3)          |
               WL_TOP_B1_RXTX2_SYNTHON_OVR_SET(1)    |
               WL_TOP_B1_RXTX2_SYNTHON_SET(1)        |
               WL_TOP_B1_RXTX2_BMODE_OVR_SET(1)      );

    if (mode == MODE_11G) { /* 2GHz */
        reg32 |= WL_TOP_B1_RXTX2_BMODE_SET(1);  // it's set for 2G now
    }

    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B1_RXTX2_ADDRESS, reg32);

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B0_RXTX3_ADDRESS);
    reg32 &= ~WL_TOP_B0_RXTX3_MANTXGAIN_MASK;
    reg32 |=  WL_TOP_B0_RXTX3_MANTXGAIN_SET(1);
    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B0_RXTX3_ADDRESS, reg32);

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B1_RXTX3_ADDRESS);
    reg32 &= ~WL_TOP_B1_RXTX3_MANTXGAIN_MASK;
    reg32 |=  WL_TOP_B1_RXTX3_MANTXGAIN_SET(1);
    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B1_RXTX3_ADDRESS, reg32);


    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_BB_B0_BB8_ADDRESS);
    reg32 &= ~(WL_BB_B0_BB8_TX_BQ2_MASK |
               WL_BB_B0_BB8_TX_BQ1_MASK |
               WL_BB_B0_BB8_TXBB_GC_MASK);

    reg32 |=  (WL_BB_B0_BB8_TX_BQ2_SET(analog_gain & 0xf) |
               WL_BB_B0_BB8_TX_BQ1_SET((analog_gain >> 4) & 0x3) |
               WL_BB_B0_BB8_TXBB_GC_SET((analog_gain >> 6) & 0xf));

    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_BB_B0_BB8_ADDRESS, reg32);

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_BB_B1_BB8_ADDRESS);
    reg32 &= ~(WL_BB_B1_BB8_TX_BQ2_MASK |
               WL_BB_B1_BB8_TX_BQ1_MASK |
               WL_BB_B1_BB8_TXBB_GC_MASK);

    reg32 |=  (WL_BB_B1_BB8_TX_BQ2_SET(analog_gain & 0xf) |
               WL_BB_B1_BB8_TX_BQ1_SET((analog_gain >> 4) & 0x3) |
               WL_BB_B1_BB8_TXBB_GC_SET((analog_gain >> 6) & 0xf));

    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_BB_B1_BB8_ADDRESS, reg32);

#endif//!defined(FPGA)
#endif //#if defined(_WHEN_TPC_IS_READY_ONEBYONE)
}

SRAM_TEXT
A_UINT16 ar6000GetPdetPdadcWfm_int(A_UINT32 freq, A_UINT8 chainMask, A_UINT16 *pdc0, A_UINT16 *pdc1)
{
#if defined(_WHEN_TPC_IS_READY_ONEBYONE)
    A_UINT32  reg32;
    A_UINT32  clip_pwr;
    A_UINT32  clip_dc;
    A_UINT32  i;
    A_UINT16  pdadc = 0;
//    A_UINT16  dc0 = 0;
//    A_UINT16  dc1 = 0;

#if defined(PD_DEBUG)
     A_PRINTF("in %s \n",__func__);
#endif
    //pdadc_setup();

    /* Disable AGC logic */
    //OS_REG_WRITE(PHY_BB_TEST_CONTROLS_STATUS_ADDRESS, 0);
    //OS_REG_RMW_FIELD(PHY_BB_TEST_CONTROLS_STATUS_ADDRESS, PHY_BB_TEST_CONTROLS_STATUS_DISABLE_AGC_TO_A2, 1);

    /* */
/*    OS_REG_RMW_FIELD(PHY_BB_TPC_3_ADDRESS, PHY_BB_TPC_3_TPC_CLK_GATE_ENABLE, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_12_B0_ADDRESS, PHY_BB_TPC_12_B0_PDADC_BIAS_0, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_12_B1_ADDRESS, PHY_BB_TPC_12_B1_PDADC_BIAS_1, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PD_DC_SEL, 1);
*/
    //A_DELAY_USECS(20 * 1000);
    /* Set threshold */
    OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_PDADC_CLIP_THRES, 0x1f0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_PDADC_CLIP_EN, 1);

    OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PWR_MEAS_TRIG_SW, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_MEAS_PWR_SW, 0);

    if (chainMask & 0x01) {
        for (i=0;i<1;i++) {
            /* Start */
            OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PWR_MEAS_TRIG_SW, 1);
            OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_MEAS_PWR_SW, 1);

            /* Wait 10ms */
            A_DELAY_USECS(8);

            reg32    = OS_REG_READ(PHY_BB_TPC_4_B0_ADDRESS);
            clip_pwr = PHY_BB_TPC_4_B0_PDADC_CLIP_1_CNT_0_GET(reg32);
            clip_dc  = PHY_BB_TPC_4_B0_PDADC_CLIP_2_CNT_0_GET(reg32);

            /* Stop */
            OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PWR_MEAS_TRIG_SW, 0);
            OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_MEAS_PWR_SW, 0);

            reg32 = OS_REG_READ(PHY_BB_TPC_STAT_0_B0_ADDRESS);

            pdadc &= 0xff00;
            pdadc |= PHY_BB_TPC_STAT_0_B0_PDACC_AVG_OUT_0_GET(reg32);
            *pdc0    = PHY_BB_TPC_STAT_0_B0_LATEST_DC_VALUE_0_GET(reg32);

#if defined(PD_DEBUG)
            A_PRINTF("chain0 %d clip_pwr0:%d, clip_dc0:%d, pdadc0:%d, dc0:%d \n",i,clip_pwr, clip_dc, pdadc, *pdc0);
#endif
            if ((clip_pwr<5) &&(clip_dc < 5)) {
                break;
            }
        }
    }
    if (chainMask & 0x02) {
        for (i=0;i<1;i++) {
            /* Start */
            OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PWR_MEAS_TRIG_SW, 1);
            OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_MEAS_PWR_SW, 1);

            /* Wait 10ms */
            A_DELAY_USECS(8);

            reg32    = OS_REG_READ(PHY_BB_TPC_4_B1_ADDRESS);
            clip_pwr = PHY_BB_TPC_4_B1_PDADC_CLIP_1_CNT_1_GET(reg32);
            clip_dc  = PHY_BB_TPC_4_B1_PDADC_CLIP_2_CNT_1_GET(reg32);

            /* Stop */
            OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PWR_MEAS_TRIG_SW, 0);
            OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_MEAS_PWR_SW, 0);

            reg32 = OS_REG_READ(PHY_BB_TPC_STAT_0_B1_ADDRESS);
            pdadc &=0xff;
            pdadc |= (PHY_BB_TPC_STAT_0_B1_PDACC_AVG_OUT_1_GET(reg32)) << 8;
            *pdc1    =  PHY_BB_TPC_STAT_0_B1_LATEST_DC_VALUE_1_GET(reg32);

#if defined(PD_DEBUG)
            A_PRINTF("chain1 %d clip_pwr1:%d, clip_dc1:%d, pdadc1:%d dc1:%d\n",i,clip_pwr, clip_dc, pdadc >> 8, *pdc1);
#endif
            if ((clip_pwr<5) &&(clip_dc < 5)) {
                break;
            }
        }
    }

    return pdadc;
#endif //#if defined(_WHEN_TPC_IS_READY_ONEBYONE)
    return 0;
}

SRAM_TEXT
void ar6000SetDcOffsetCancellationGain(A_UINT8 bmode, A_UINT8 stage, A_UINT8 gain, A_UINT8 Idx0, A_UINT8 Idx1)
{
#if defined(_WHEN_TPC_IS_READY_ONEBYONE)
#if !defined(FPGA)
    A_UINT32  reg32;

#if defined(PD_DEBUG)
    A_PRINTF_ALWAYS("%s \n", __func__);
A_PRINTF_ALWAYS("idx0:%d , idx1:%d\n", Idx0, Idx1);
#endif

    if (stage == 1) {
        if (bmode) { //2G
            if (gain == 0) {
                reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC2_ADDRESS);
                reg32 &= ~(TPC_B0_TPC2_DCOC_DAC1_TIA_LOGAIN_2G_MASK);
                reg32 |= TPC_B0_TPC2_DCOC_DAC1_TIA_LOGAIN_2G_SET(Idx0);
                A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC2_ADDRESS, reg32);

                reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC2_ADDRESS);
                reg32 &= ~(TPC_B1_TPC2_DCOC_DAC1_TIA_LOGAIN_2G_MASK);
                reg32 |= TPC_B1_TPC2_DCOC_DAC1_TIA_LOGAIN_2G_SET(Idx1);
                A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC2_ADDRESS, reg32);
            } else {
                reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC1_ADDRESS);
                reg32 &= ~(TPC_B0_TPC1_DCOC_DAC1_TIA_HIGAIN_2G_MASK);
                reg32 |= TPC_B0_TPC1_DCOC_DAC1_TIA_HIGAIN_2G_SET(Idx0);
                A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC1_ADDRESS, reg32);

                reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC1_ADDRESS);
                reg32 &= ~(TPC_B1_TPC1_DCOC_DAC1_TIA_HIGAIN_2G_MASK);
                reg32 |= TPC_B1_TPC1_DCOC_DAC1_TIA_HIGAIN_2G_SET(Idx1);
                A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC1_ADDRESS, reg32);
            }
        } else { //5G
            if (gain == 0) {
                reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC3_ADDRESS);
                reg32 &= ~(TPC_B0_TPC3_DCOC_DAC1_TIA_LOGAIN_5G_MASK);
                reg32 |= TPC_B0_TPC3_DCOC_DAC1_TIA_LOGAIN_5G_SET(Idx0);
                A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC3_ADDRESS, reg32);

                reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC3_ADDRESS);
                reg32 &= ~(TPC_B1_TPC3_DCOC_DAC1_TIA_LOGAIN_5G_MASK);
                reg32 |= TPC_B1_TPC3_DCOC_DAC1_TIA_LOGAIN_5G_SET(Idx1);
                A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC3_ADDRESS, reg32);

            } else {
                reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC2_ADDRESS);
                reg32 &= ~(TPC_B0_TPC2_DCOC_DAC1_TIA_HIGAIN_5G_MASK);
                reg32 |= TPC_B0_TPC2_DCOC_DAC1_TIA_HIGAIN_5G_SET(Idx0);
                A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC2_ADDRESS, reg32);

                reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC2_ADDRESS);
                reg32 &= ~(TPC_B1_TPC2_DCOC_DAC1_TIA_HIGAIN_5G_MASK);
                reg32 |= TPC_B1_TPC2_DCOC_DAC1_TIA_HIGAIN_5G_SET(Idx1);
                A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC2_ADDRESS, reg32);
            }
        }

    } else if (stage == 2) {
        if (bmode) { //2G
            if (gain == 0) {
                reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC2_ADDRESS);
                reg32 &= ~(TPC_B0_TPC2_DCOC_DAC2_TIA_LOGAIN_2G_MASK);
                reg32 |= TPC_B0_TPC2_DCOC_DAC2_TIA_LOGAIN_2G_SET(Idx0);
                A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC2_ADDRESS, reg32);

                reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC2_ADDRESS);
                reg32 &= ~(TPC_B1_TPC2_DCOC_DAC2_TIA_LOGAIN_2G_MASK);
                reg32 |= TPC_B1_TPC2_DCOC_DAC2_TIA_LOGAIN_2G_SET(Idx1);
                A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC2_ADDRESS, reg32);
            } else {
                reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC2_ADDRESS);
                reg32 &= ~(TPC_B0_TPC2_DCOC_DAC2_TIA_HIGAIN_2G_MASK);
                reg32 |= TPC_B0_TPC2_DCOC_DAC2_TIA_HIGAIN_2G_SET(Idx0);
                A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC2_ADDRESS, reg32);

                reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC2_ADDRESS);
                reg32 &= ~(TPC_B1_TPC2_DCOC_DAC2_TIA_HIGAIN_2G_MASK);
                reg32 |= TPC_B1_TPC2_DCOC_DAC2_TIA_HIGAIN_2G_SET(Idx1);
                A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC2_ADDRESS, reg32);
            }
        } else { //5G
            if (gain == 0) {
                reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC3_ADDRESS);
                reg32 &= ~(TPC_B0_TPC3_DCOC_DAC2_TIA_LOGAIN_5G_MASK);
                reg32 |= TPC_B0_TPC3_DCOC_DAC2_TIA_LOGAIN_5G_SET(Idx0);
                A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC3_ADDRESS, reg32);

                reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC3_ADDRESS);
                reg32 &= ~(TPC_B1_TPC3_DCOC_DAC2_TIA_LOGAIN_5G_MASK);
                reg32 |= TPC_B1_TPC3_DCOC_DAC2_TIA_LOGAIN_5G_SET(Idx1);
                A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC3_ADDRESS, reg32);
            } else {
                reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC2_ADDRESS);
                reg32 &= ~(TPC_B0_TPC2_DCOC_DAC2_TIA_HIGAIN_5G_MASK);
                reg32 |= TPC_B0_TPC2_DCOC_DAC2_TIA_HIGAIN_5G_SET(Idx0);
                A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC2_ADDRESS, reg32);

                reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC2_ADDRESS);
                reg32 &= ~(TPC_B1_TPC2_DCOC_DAC2_TIA_HIGAIN_5G_MASK);
                reg32 |= TPC_B1_TPC2_DCOC_DAC2_TIA_HIGAIN_5G_SET(Idx1);
                A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC2_ADDRESS, reg32);
            }
        }
    }
#endif
#endif //#if defined(_WHEN_TPC_IS_READY_ONEBYONE)
}

#define RFFE_2GTX_1_B0_WLTX2_TPC_FE2X_TPC_DCOC_MODE_MAX_ATTN_MASK    0x00040000
#define RFFE_2GTX_1_B0_WLTX2_TPC_FE2X_TPC_DCOC_MODE_MAX_ATTN_LSB     18
#define RFFE_2GTX_1_B0_WLTX2_TPC_FE2X_TPC_DCOC_MODE_MAX_ATTN_SET(x)  (((0 | (x)) << RFFE_2GTX_1_B0_WLTX2_TPC_FE2X_TPC_DCOC_MODE_MAX_ATTN_LSB) & RFFE_2GTX_1_B0_WLTX2_TPC_FE2X_TPC_DCOC_MODE_MAX_ATTN_MASK)

#define RFFE_2GTX_1_B1_WLTX2_TPC_FE2X_TPC_DCOC_MODE_MAX_ATTN_MASK    0x00040000
#define RFFE_2GTX_1_B1_WLTX2_TPC_FE2X_TPC_DCOC_MODE_MAX_ATTN_LSB     18
#define RFFE_2GTX_1_B1_WLTX2_TPC_FE2X_TPC_DCOC_MODE_MAX_ATTN_SET(x)  (((0 | (x)) << RFFE_2GTX_1_B0_WLTX2_TPC_FE2X_TPC_DCOC_MODE_MAX_ATTN_LSB) & RFFE_2GTX_1_B0_WLTX2_TPC_FE2X_TPC_DCOC_MODE_MAX_ATTN_MASK)

#define min(a,b) ((a) < (b) ?(a) : (b))
#define max(a,b) ((a) > (b) ?(a) : (b))
//#define abs(x) ((x) >=0 ? (x):(-(x)))

/* PDET_coarse_DC_calibration
*/
CODESWAP_MARK_EVICTABLE(void, ar6000PdetDcCal, A_UINT8 bmode, A_UINT8 stage, A_UINT8 gain, A_UINT8 chainmask)
{
#if !defined(FPGA)
    A_UINT32 reg32;
    A_UINT8  min_idx, max_idx;
    A_UINT8  minIdx[4];
    A_UINT8  maxIdx[4];
    A_UINT8  mid_idx[4];
    A_UINT8  dc_max[4],dc_min[4],dc_mid[4];
    A_UINT8  dc_target = 40;
    A_UINT8  done_dc[4] = {0,0,0,0};
    A_UINT8  done_flag = 0;
    A_UINT8  err[4]={30,30,30,30};
    //A_UINT8  i;
    A_UINT32 index;

    //A_PRINTF_ALWAYS("%s \n", __func__);
    OS_REG_RMW_FIELD(PHY_BB_TPC_3_ADDRESS, PHY_BB_TPC_3_TPC_CLK_GATE_ENABLE, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_12_B0_ADDRESS, PHY_BB_TPC_12_B0_PDADC_BIAS_0, 0);
#if (NUM_SPATIAL_STREAM > 1)
    OS_REG_RMW_FIELD(PHY_BB_TPC_12_B1_ADDRESS, PHY_BB_TPC_12_B1_PDADC_BIAS_1, 0);
#if (NUM_SPATIAL_STREAM > 2)
    OS_REG_RMW_FIELD(PHY_BB_TPC_12_B2_ADDRESS, PHY_BB_TPC_12_B2_PDADC_BIAS_2, 0);
#if (NUM_SPATIAL_STREAM > 3)
    OS_REG_RMW_FIELD(PHY_BB_TPC_12_B3_ADDRESS, PHY_BB_TPC_12_B3_PDADC_BIAS_3, 0);
#endif
#endif
#endif

    OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PD_DC_SEL, 1);

    OS_REG_RMW_FIELD(CHN0_TPC12_ADDRESS, CHN0_TPC12_TPC_DCO_CAL_EN_OVR, 3);
#if (NUM_SPATIAL_STREAM > 1)
    OS_REG_RMW_FIELD(CHN1_TPC12_ADDRESS, CHN0_TPC12_TPC_DCO_CAL_EN_OVR, 3);
#if (NUM_SPATIAL_STREAM > 2)
    OS_REG_RMW_FIELD(CHN2_TPC12_ADDRESS, CHN0_TPC12_TPC_DCO_CAL_EN_OVR, 3);
#if (NUM_SPATIAL_STREAM > 3)
    OS_REG_RMW_FIELD(CHN3_TPC12_ADDRESS, CHN0_TPC12_TPC_DCO_CAL_EN_OVR, 3);
#endif
#endif
#endif
    reg32 = OS_REG_READ(CHN0_TPC12_ADDRESS);
    reg32 &= ~(CHN0_TPC12_TPC_MAX_ATTN_DCO_CAL_2G_MASK | CHN0_TPC12_TPC_MAX_ATTN_DCO_CAL_5G_MASK);
    reg32 |=  (CHN0_TPC12_TPC_MAX_ATTN_DCO_CAL_2G_SET(1) | CHN0_TPC12_TPC_MAX_ATTN_DCO_CAL_5G_SET(1));
    OS_REG_WRITE(CHN0_TPC12_ADDRESS, reg32);
#if (NUM_SPATIAL_STREAM > 1)
    reg32 = OS_REG_READ(CHN1_TPC12_ADDRESS);
    reg32 &= ~(CHN1_TPC12_TPC_MAX_ATTN_DCO_CAL_2G_MASK | CHN1_TPC12_TPC_MAX_ATTN_DCO_CAL_5G_MASK);
    reg32 |=  (CHN1_TPC12_TPC_MAX_ATTN_DCO_CAL_2G_SET(1) | CHN1_TPC12_TPC_MAX_ATTN_DCO_CAL_5G_SET(1));
    OS_REG_WRITE(CHN1_TPC12_ADDRESS, reg32);
#if (NUM_SPATIAL_STREAM > 2)
    reg32 = OS_REG_READ(CHN2_TPC12_ADDRESS);
    reg32 &= ~(CHN2_TPC12_TPC_MAX_ATTN_DCO_CAL_2G_MASK | CHN2_TPC12_TPC_MAX_ATTN_DCO_CAL_5G_MASK);
    reg32 |=  (CHN2_TPC12_TPC_MAX_ATTN_DCO_CAL_2G_SET(1) | CHN2_TPC12_TPC_MAX_ATTN_DCO_CAL_5G_SET(1));
    OS_REG_WRITE(CHN2_TPC12_ADDRESS, reg32);
#if (NUM_SPATIAL_STREAM > 3)
    reg32 = OS_REG_READ(CHN3_TPC12_ADDRESS);
    reg32 &= ~(CHN3_TPC12_TPC_MAX_ATTN_DCO_CAL_2G_MASK | CHN3_TPC12_TPC_MAX_ATTN_DCO_CAL_5G_MASK);
    reg32 |=  (CHN3_TPC12_TPC_MAX_ATTN_DCO_CAL_2G_SET(1) | CHN3_TPC12_TPC_MAX_ATTN_DCO_CAL_5G_SET(1));
    OS_REG_WRITE(CHN3_TPC12_ADDRESS, reg32);
#endif
#endif
#endif
    if (0 == gain) {
        OS_REG_RMW_FIELD(CHN0_TPC1_ADDRESS, CHN0_TPC1_SET_TIA_HIGAIN_OVR, 2);
#if (NUM_SPATIAL_STREAM > 1)
        OS_REG_RMW_FIELD(CHN1_TPC1_ADDRESS, CHN0_TPC1_SET_TIA_HIGAIN_OVR, 2);
#if (NUM_SPATIAL_STREAM > 2)
        OS_REG_RMW_FIELD(CHN2_TPC1_ADDRESS, CHN0_TPC1_SET_TIA_HIGAIN_OVR, 2);
#if (NUM_SPATIAL_STREAM > 3)
        OS_REG_RMW_FIELD(CHN3_TPC1_ADDRESS, CHN0_TPC1_SET_TIA_HIGAIN_OVR, 2);
#endif
#endif
#endif
    }
    else {
        OS_REG_RMW_FIELD(CHN0_TPC1_ADDRESS, CHN0_TPC1_SET_TIA_HIGAIN_OVR, 3);
#if (NUM_SPATIAL_STREAM > 1)
        OS_REG_RMW_FIELD(CHN1_TPC1_ADDRESS, CHN0_TPC1_SET_TIA_HIGAIN_OVR, 3);
#if (NUM_SPATIAL_STREAM > 2)
        OS_REG_RMW_FIELD(CHN2_TPC1_ADDRESS, CHN0_TPC1_SET_TIA_HIGAIN_OVR, 3);
#if (NUM_SPATIAL_STREAM > 3)
        OS_REG_RMW_FIELD(CHN3_TPC1_ADDRESS, CHN0_TPC1_SET_TIA_HIGAIN_OVR, 3);
#endif
#endif
#endif
    }

    if (stage == 1) {
        minIdx[0] = minIdx[1] = minIdx[2] = minIdx[3] = min_idx = 0;
        maxIdx[0] = maxIdx[1] = maxIdx[2] = maxIdx[3] = max_idx = 127;
    } else /* if (stage == 2) */ {
        minIdx[0] = minIdx[1] = minIdx[2] = minIdx[3] = min_idx = 0;
        maxIdx[0] = maxIdx[1] = maxIdx[2] = maxIdx[3] = max_idx = 31;
    }

    program_PDET_coarse_DC(stage, bmode, gain, max_idx, max_idx, max_idx, max_idx);
    PDADC_read(dc_max);
    //A_PRINTF_ALWAYS("s %d g %d max id0-3 %d ;", stage, gain, max_idx);
    //A_PRINTF_ALWAYS("pdadc %d %d %d %d\n ", dc_max[0], dc_max[1], dc_max[2], dc_max[3]);

    program_PDET_coarse_DC(stage, bmode, gain, min_idx, min_idx, min_idx, min_idx);
    PDADC_read(dc_min);
    //A_PRINTF_ALWAYS("s %d g %d min id0-3 %d ;", stage, gain, min_idx);
    //A_PRINTF_ALWAYS("pdadc %d %d %d %d\n ", dc_max[0], dc_min[1], dc_min[2], dc_min[3]);

#if 0
    if (((dc_min[0] - dc_target) > 0) && ((dc_max[0] - dc_target) > 0) | ((dc_min[0] - dc_target) < 0) && ((dc_max[0] - dc_target) < 0))  {
        A_PRINTF_ALWAYS("chn0 DC not converge, %d %d %d %d %d\n", dc_min[0], dc_max[0], max_idx, min_idx, dc_target);
    }
    if (((dc_min[1] - dc_target) > 0) & ((dc_max[1] - dc_target) > 0) | ((dc_min[1] - dc_target) < 0) & ((dc_max[1] - dc_target) < 0))  {
        A_PRINTF_ALWAYS("chn1 DC not converge %d %d %d %d\n", dc_min[1], dc_max[1], max_idx, min_idx);
    }
    if (((dc_min[2] - dc_target) > 0) & ((dc_max[2] - dc_target) > 0) | ((dc_min[2] - dc_target) < 0) & ((dc_max[2] - dc_target) < 0))  {
        A_PRINTF_ALWAYS("chn2 DC not converge %d %d %d %d\n", dc_min[2], dc_max[2], max_idx, min_idx);
    }
    if (((dc_min[3] - dc_target) > 0) & ((dc_max[3] - dc_target) > 0) | ((dc_min[3] - dc_target) < 0) & ((dc_max[3] - dc_target) < 0))  {
        A_PRINTF_ALWAYS("chn3 DC not converge %d %d %d %d\n", dc_min[3], dc_max[3], max_idx, min_idx);
    }
#endif

    for (index =0; index <4; index++) {
        dc_mid[index] = min(dc_min[index], dc_max[index]);
    }

    while (!done_flag) {

        for (index =0; index <4; index++) {
            mid_idx[index]= (maxIdx[index]+minIdx[index])/2;
        }

        program_PDET_coarse_DC(stage, bmode, gain, mid_idx[0], mid_idx[1], mid_idx[2], mid_idx[3]);
        PDADC_read(dc_mid);
        //A_PRINTF_ALWAYS("s %d g %d mid id0-3 %d %d %d ", stage, gain, mid_idx[0], mid_idx[1], mid_idx[2]);
        //A_PRINTF_ALWAYS("%d; pdadc %d %d %d %d\n ", mid_idx[3], dc_mid[0], dc_mid[1], dc_mid[2], dc_mid[3]);

        for (index =0; index <4; index++) {
            if (abs(dc_mid[index] - dc_target) < err[index]) { 
                err[index]= abs(dc_mid[index] - dc_target);
            }
        }

#if defined(PD_DEBUG)
        A_PRINTF("idex%d, dc_mid[0]:%d, dc_mid[1]:%d, dc_target:%d \n",i,dc_mid[0],dc_mid[1],dc_target);
        A_PRINTF("err0 = %d, min_idx0= %d, max_idx0= %d mid_idx[0]=%d\n", err[0], minIdx[0], maxIdx[0], mid_idx[0]);
        A_PRINTF("err1 = %d, min_idx1= %d, max_idx1= %d mid_idx[1]=%d\n", err[1], minIdx[1], maxIdx[1], mid_idx[1]);
        A_PRINTF("dac_max[0]:%d, dac_min[0]:%d\n",dc_max[0],dc_min[0]);
#endif

        for (index =0; index <4; index++) {
            if (dc_max[index] > dc_target) {
                if (dc_mid[index] > dc_target) {
                    maxIdx[index] = mid_idx[index];
                } else if (dc_mid[index] < dc_target) {
                    minIdx[index] = mid_idx[index];
                } else {
                    minIdx[index] = mid_idx[index];
                    maxIdx[index] = mid_idx[index];
                }
            } else if (dc_max[index] < dc_target) {
                if (dc_mid[index] > dc_target) {
                    minIdx[index] = mid_idx[index];
                } else if (dc_mid[index] < dc_target) {
                    maxIdx[index] = mid_idx[index];
                } else {
                    minIdx[index] = mid_idx[index];
                    maxIdx[index] = mid_idx[index];
                }
            } else {
                minIdx[index] = maxIdx[index];
            }
        }

        for (index =0; index <4; index++) {
            if (abs(minIdx[index] - maxIdx[index]) <= 1) {
                done_dc[index] = 1;
            }
        }

        done_flag = done_dc[0] && done_dc[1] && done_dc[2] && done_dc[3];

        if (done_flag) {
            program_PDET_coarse_DC(stage, bmode, gain, maxIdx[0], maxIdx[1], maxIdx[2], maxIdx[3]);
            PDADC_read(dc_max);
            //A_PRINTF_ALWAYS("s %d g %d max id0-3 %d %d %d ", stage, gain, max_idx);
            //A_PRINTF_ALWAYS("%d pdadc %d %d %d %d\n ", dc_max[0], dc_max[1], dc_max[2], dc_max[3]);

            program_PDET_coarse_DC(stage, bmode, gain, minIdx[0], minIdx[1], minIdx[2], minIdx[3]);
            PDADC_read(dc_min);
            //A_PRINTF_ALWAYS("s %d g %d min id0-3 %d %d %d ", stage, gain, minIdx[0], minIdx[1], minIdx[2]);
            //A_PRINTF_ALWAYS("%d pdadc %d %d %d %d\n ", minIdx[3], dc_min[0], dc_min[1], dc_min[2], dc_min[3]);

            for (index =0; index <4; index++) {
                if (abs(dc_min[index] - dc_target) < abs(dc_max[index] - dc_target)) {
                    mid_idx[index] = minIdx[index];
                } else { 
                    mid_idx[index] = maxIdx[index];
                }
            }

	    //A_PRINTF("final dc0 minIdx[0]:%d, maxIdx[0]:%d, mid_idx[0]:%d\n", minIdx[0], maxIdx[0], mid_idx[0]);
	    //A_PRINTF("final dc1 minIdx[1]:%d, maxIdx[1]:%d, mid_idx[1]:%d\n", minIdx[1], maxIdx[1], mid_idx[1]);

            break;
        }
    }

    program_PDET_coarse_DC(stage, bmode, gain, mid_idx[0], mid_idx[1], mid_idx[2], mid_idx[3]);
    PDADC_read(dc_mid);
    //A_PRINTF_ALWAYS("s %d g %d mid id0-3 %d %d %d ", stage, gain, minIdx[0], minIdx[1], minIdx[2]);
    //A_PRINTF_ALWAYS("%d pdadc %d %d %d %d\n ", minIdx[3], dc_mid[0], dc_mid[1], dc_mid[2], dc_mid[3]);

    OS_REG_RMW_FIELD(CHN0_TPC1_ADDRESS, CHN0_TPC1_SET_TIA_HIGAIN_OVR, 0);
#if (NUM_SPATIAL_STREAM > 1)
    OS_REG_RMW_FIELD(CHN1_TPC1_ADDRESS, CHN0_TPC1_SET_TIA_HIGAIN_OVR, 0);
#if (NUM_SPATIAL_STREAM > 2)
    OS_REG_RMW_FIELD(CHN2_TPC1_ADDRESS, CHN0_TPC1_SET_TIA_HIGAIN_OVR, 0);
#if (NUM_SPATIAL_STREAM > 3)
    OS_REG_RMW_FIELD(CHN3_TPC1_ADDRESS, CHN0_TPC1_SET_TIA_HIGAIN_OVR, 0);
#endif
#endif
#endif

    OS_REG_RMW_FIELD(CHN0_TPC12_ADDRESS, CHN0_TPC12_TPC_DCO_CAL_EN_OVR, 0);
#if (NUM_SPATIAL_STREAM > 1)
    OS_REG_RMW_FIELD(CHN1_TPC12_ADDRESS, CHN0_TPC12_TPC_DCO_CAL_EN_OVR, 0);
#if (NUM_SPATIAL_STREAM > 2)
    OS_REG_RMW_FIELD(CHN2_TPC12_ADDRESS, CHN0_TPC12_TPC_DCO_CAL_EN_OVR, 0);
#if (NUM_SPATIAL_STREAM > 3)
    OS_REG_RMW_FIELD(CHN3_TPC12_ADDRESS, CHN0_TPC12_TPC_DCO_CAL_EN_OVR, 0);
#endif
#endif
#endif

    reg32 = OS_REG_READ(CHN0_TPC12_ADDRESS);
    reg32 &= ~(CHN0_TPC12_TPC_MAX_ATTN_DCO_CAL_2G_MASK | CHN0_TPC12_TPC_MAX_ATTN_DCO_CAL_5G_MASK);
    reg32 |=  (CHN0_TPC12_TPC_MAX_ATTN_DCO_CAL_2G_SET(0) | CHN0_TPC12_TPC_MAX_ATTN_DCO_CAL_5G_SET(0));
    OS_REG_WRITE(CHN0_TPC12_ADDRESS, reg32);
#if (NUM_SPATIAL_STREAM > 1)
    reg32 = OS_REG_READ(CHN1_TPC12_ADDRESS);
    reg32 &= ~(CHN1_TPC12_TPC_MAX_ATTN_DCO_CAL_2G_MASK | CHN1_TPC12_TPC_MAX_ATTN_DCO_CAL_5G_MASK);
    reg32 |=  (CHN1_TPC12_TPC_MAX_ATTN_DCO_CAL_2G_SET(0) | CHN1_TPC12_TPC_MAX_ATTN_DCO_CAL_5G_SET(0));
    OS_REG_WRITE(CHN1_TPC12_ADDRESS, reg32);
#if (NUM_SPATIAL_STREAM > 2)
    reg32 = OS_REG_READ(CHN2_TPC12_ADDRESS);
    reg32 &= ~(CHN2_TPC12_TPC_MAX_ATTN_DCO_CAL_2G_MASK | CHN2_TPC12_TPC_MAX_ATTN_DCO_CAL_5G_MASK);
    reg32 |=  (CHN2_TPC12_TPC_MAX_ATTN_DCO_CAL_2G_SET(0) | CHN2_TPC12_TPC_MAX_ATTN_DCO_CAL_5G_SET(0));
    OS_REG_WRITE(CHN2_TPC12_ADDRESS, reg32);
#if (NUM_SPATIAL_STREAM > 3)
    reg32 = OS_REG_READ(CHN3_TPC12_ADDRESS);
    reg32 &= ~(CHN3_TPC12_TPC_MAX_ATTN_DCO_CAL_2G_MASK | CHN3_TPC12_TPC_MAX_ATTN_DCO_CAL_5G_MASK);
    reg32 |=  (CHN3_TPC12_TPC_MAX_ATTN_DCO_CAL_2G_SET(0) | CHN3_TPC12_TPC_MAX_ATTN_DCO_CAL_5G_SET(0));
    OS_REG_WRITE(CHN3_TPC12_ADDRESS, reg32);
#endif
#endif
#endif

#endif //#if !defined(FPGA)
    return;
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void ,ar6000PdetDcCal, A_UINT8 , A_UINT8 , A_UINT8 , A_UINT8 );
extern void ar6000PdetDcCal(A_UINT8 bmode, A_UINT8 stage, A_UINT8 gain, A_UINT8 chainmask);

CODESWAP_MARK_EVICTABLE(void, program_PDET_coarse_DC, A_UINT8 stage, A_UINT8 bmode, A_UINT8 gain, A_UINT8 idx_0, A_UINT8 idx_1, A_UINT8 idx_2, A_UINT8 idx_3)
{
    if (stage==1) {
        if (bmode) {
            if (gain==0) {
                OS_REG_RMW_FIELD(CHN0_TPC2_ADDRESS, CHN0_TPC2_DCOC_DAC1_TIA_LOGAIN_2G, idx_0);
                OS_REG_RMW_FIELD(CHN1_TPC2_ADDRESS, CHN1_TPC2_DCOC_DAC1_TIA_LOGAIN_2G, idx_1);
#if (NUM_SPATIAL_STREAM > 2)
                OS_REG_RMW_FIELD(CHN2_TPC2_ADDRESS, CHN2_TPC2_DCOC_DAC1_TIA_LOGAIN_2G, idx_2);
                OS_REG_RMW_FIELD(CHN3_TPC2_ADDRESS, CHN3_TPC2_DCOC_DAC1_TIA_LOGAIN_2G, idx_3);
#endif
            } else {
                OS_REG_RMW_FIELD(CHN0_TPC2_ADDRESS, CHN0_TPC2_DCOC_DAC1_TIA_HIGAIN_2G, idx_0);
                OS_REG_RMW_FIELD(CHN1_TPC2_ADDRESS, CHN1_TPC2_DCOC_DAC1_TIA_HIGAIN_2G, idx_1);
#if (NUM_SPATIAL_STREAM > 2)
                OS_REG_RMW_FIELD(CHN2_TPC2_ADDRESS, CHN2_TPC2_DCOC_DAC1_TIA_HIGAIN_2G, idx_2);
                OS_REG_RMW_FIELD(CHN3_TPC2_ADDRESS, CHN3_TPC2_DCOC_DAC1_TIA_HIGAIN_2G, idx_3);
#endif
            }
        } else {
            if (gain==0) {
                OS_REG_RMW_FIELD(CHN0_TPC3_ADDRESS, CHN0_TPC3_DCOC_DAC1_TIA_LOGAIN_5G, idx_0);
                OS_REG_RMW_FIELD(CHN1_TPC3_ADDRESS, CHN1_TPC3_DCOC_DAC1_TIA_LOGAIN_5G, idx_1);
#if (NUM_SPATIAL_STREAM > 2)
                OS_REG_RMW_FIELD(CHN2_TPC3_ADDRESS, CHN2_TPC3_DCOC_DAC1_TIA_LOGAIN_5G, idx_2);
                OS_REG_RMW_FIELD(CHN3_TPC3_ADDRESS, CHN3_TPC3_DCOC_DAC1_TIA_LOGAIN_5G, idx_3);
#endif
            } else {
                OS_REG_RMW_FIELD(CHN0_TPC3_ADDRESS, CHN0_TPC3_DCOC_DAC1_TIA_HIGAIN_5G, idx_0);
                OS_REG_RMW_FIELD(CHN1_TPC3_ADDRESS, CHN1_TPC3_DCOC_DAC1_TIA_HIGAIN_5G, idx_1);
#if (NUM_SPATIAL_STREAM > 2)
                OS_REG_RMW_FIELD(CHN2_TPC3_ADDRESS, CHN2_TPC3_DCOC_DAC1_TIA_HIGAIN_5G, idx_2);
                OS_REG_RMW_FIELD(CHN3_TPC3_ADDRESS, CHN3_TPC3_DCOC_DAC1_TIA_HIGAIN_5G, idx_3);
#endif
            }
        }
    }
    else if (stage == 2) {
        if (bmode) {
            if (gain==0) {
                OS_REG_RMW_FIELD(CHN0_TPC2_ADDRESS, CHN0_TPC2_DCOC_DAC2_TIA_LOGAIN_2G, idx_0);
                OS_REG_RMW_FIELD(CHN1_TPC2_ADDRESS, CHN1_TPC2_DCOC_DAC2_TIA_LOGAIN_2G, idx_1);
#if (NUM_SPATIAL_STREAM > 2)
                OS_REG_RMW_FIELD(CHN2_TPC2_ADDRESS, CHN2_TPC2_DCOC_DAC2_TIA_LOGAIN_2G, idx_2);
                OS_REG_RMW_FIELD(CHN3_TPC2_ADDRESS, CHN3_TPC2_DCOC_DAC2_TIA_LOGAIN_2G, idx_3);
#endif
            } else {
                OS_REG_RMW_FIELD(CHN0_TPC2_ADDRESS, CHN0_TPC2_DCOC_DAC2_TIA_HIGAIN_2G, idx_0);
                OS_REG_RMW_FIELD(CHN1_TPC2_ADDRESS, CHN1_TPC2_DCOC_DAC2_TIA_HIGAIN_2G, idx_1);
#if (NUM_SPATIAL_STREAM > 2)
                OS_REG_RMW_FIELD(CHN2_TPC2_ADDRESS, CHN2_TPC2_DCOC_DAC2_TIA_HIGAIN_2G, idx_2);
                OS_REG_RMW_FIELD(CHN3_TPC2_ADDRESS, CHN3_TPC2_DCOC_DAC2_TIA_HIGAIN_2G, idx_3);
#endif
            }
        } else {
            if (gain==0) {
                OS_REG_RMW_FIELD(CHN0_TPC3_ADDRESS, CHN0_TPC3_DCOC_DAC2_TIA_LOGAIN_5G, idx_0);
                OS_REG_RMW_FIELD(CHN1_TPC3_ADDRESS, CHN1_TPC3_DCOC_DAC2_TIA_LOGAIN_5G, idx_1);
#if (NUM_SPATIAL_STREAM > 2)
                OS_REG_RMW_FIELD(CHN2_TPC3_ADDRESS, CHN2_TPC3_DCOC_DAC2_TIA_LOGAIN_5G, idx_2);
                OS_REG_RMW_FIELD(CHN3_TPC3_ADDRESS, CHN3_TPC3_DCOC_DAC2_TIA_LOGAIN_5G, idx_3);
#endif
            } else {
                OS_REG_RMW_FIELD(CHN0_TPC3_ADDRESS, CHN0_TPC3_DCOC_DAC2_TIA_HIGAIN_5G, idx_0);
                OS_REG_RMW_FIELD(CHN1_TPC3_ADDRESS, CHN1_TPC3_DCOC_DAC2_TIA_HIGAIN_5G, idx_1);
#if (NUM_SPATIAL_STREAM > 2)
                OS_REG_RMW_FIELD(CHN2_TPC3_ADDRESS, CHN2_TPC3_DCOC_DAC2_TIA_HIGAIN_5G, idx_2);
                OS_REG_RMW_FIELD(CHN3_TPC3_ADDRESS, CHN3_TPC3_DCOC_DAC2_TIA_HIGAIN_5G, idx_3);
#endif
            }
        }
    }
    return;
}

CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void , program_PDET_coarse_DC, A_UINT8 , A_UINT8 , A_UINT8 , A_UINT8 , A_UINT8 , A_UINT8 , A_UINT8 );
extern void  program_PDET_coarse_DC(A_UINT8 stage, A_UINT8 bmode, A_UINT8 gain, A_UINT8 idx_0, A_UINT8 idx_1, A_UINT8 idx_2, A_UINT8 idx_3);

SRAM_TEXT
void PDADC_read (A_UINT8 avg[])
{
    A_UINT8 avg0 = 0, avg1 = 0, avg2 = 0, avg3 = 0;
    A_UINT32 clip_thres = 0x1f0, reg32;
    A_UINT32 i, avg0_tmp, avg1_tmp, avg2_tmp = 0, avg3_tmp = 0, NumAvg = 1;

    reg32 = OS_REG_READ(PHY_BB_TPC_17_ADDRESS);
    reg32 &= ~(PHY_BB_TPC_17_PDADC_CLIP_THRES_MASK | PHY_BB_TPC_17_PDADC_CLIP_EN_MASK);
    reg32 |=  (PHY_BB_TPC_17_PDADC_CLIP_THRES_SET(clip_thres) | PHY_BB_TPC_17_PDADC_CLIP_EN_SET(1));
    OS_REG_WRITE(PHY_BB_TPC_17_ADDRESS, reg32);

    OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PWR_MEAS_TRIG_SW, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_MEAS_PWR_SW, 0);

    for (i=0; i<NumAvg; i++) {
        OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PWR_MEAS_TRIG_SW, 0);
        OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_MEAS_PWR_SW, 0);
        OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PWR_MEAS_TRIG_SW, 1);
        OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_MEAS_PWR_SW, 1);
        A_DELAY_USECS(10);
        avg0_tmp = PHY_BB_TPC_STAT_0_B0_PDACC_AVG_OUT_0_GET(OS_REG_READ(PHY_BB_TPC_STAT_0_B0_ADDRESS));
        avg1_tmp = PHY_BB_TPC_STAT_0_B1_PDACC_AVG_OUT_1_GET(OS_REG_READ(PHY_BB_TPC_STAT_0_B1_ADDRESS));
#if (NUM_SPATIAL_STREAM > 2)
        avg2_tmp = PHY_BB_TPC_STAT_0_B2_PDACC_AVG_OUT_2_GET(OS_REG_READ(PHY_BB_TPC_STAT_0_B2_ADDRESS));
        avg3_tmp = PHY_BB_TPC_STAT_0_B3_PDACC_AVG_OUT_3_GET(OS_REG_READ(PHY_BB_TPC_STAT_0_B3_ADDRESS));
#endif
        avg0 = avg0 + avg0_tmp;
        avg1 = avg1 + avg1_tmp;
        avg2 = avg2 + avg2_tmp;
        avg3 = avg3 + avg3_tmp;
    }
    avg[0] = (((10 * avg0)/NumAvg +5)/10);  // TBD: x10 + 5
    avg[1] = (((10 * avg1)/NumAvg +5)/10);
    avg[2] = (((10 * avg2)/NumAvg +5)/10);
    avg[3] = (((10 * avg3)/NumAvg +5)/10);

    return;
}

//sub PDET_coarse_DC_calibration_all
SRAM_TEXT
void ar6000PdetDcCalAll(A_UINT8 bmode, A_UINT8 chainmask)
{
#if !defined(FPGA)
    //A_PRINTF_ALWAYS("%s \n", __func__);

    OS_REG_RMW_FIELD(CHN0_CH0_ADDRESS, CHN0_CH0_TXON_OVR, 3);
#if (NUM_SPATIAL_STREAM > 1)
    OS_REG_RMW_FIELD(CHN1_CH0_ADDRESS, CHN1_CH0_TXON_OVR, 3);
#if (NUM_SPATIAL_STREAM > 2)
    OS_REG_RMW_FIELD(CHN2_CH0_ADDRESS, CHN2_CH0_TXON_OVR, 3);
#if (NUM_SPATIAL_STREAM > 3)
    OS_REG_RMW_FIELD(CHN3_CH0_ADDRESS, CHN3_CH0_TXON_OVR, 3);

#endif
#endif
#endif
    ar6000PdetDcCal(bmode, 1, 0, chainmask);
    /*done with stage 1, low gain*/

    ar6000PdetDcCal(bmode, 2, 0, chainmask);
    /*done with stage 2, low gain*/

    ar6000PdetDcCal(bmode, 1, 1, chainmask);
    /*done with stage 1, high gain*/

    ar6000PdetDcCal(bmode, 2, 1, chainmask);
    /*done with stage 2, high gain*/

    OS_REG_RMW_FIELD(CHN0_CH0_ADDRESS, CHN0_CH0_TXON_OVR, 0);
#if (NUM_SPATIAL_STREAM > 1)
    OS_REG_RMW_FIELD(CHN1_CH0_ADDRESS, CHN1_CH0_TXON_OVR, 0);
#if (NUM_SPATIAL_STREAM > 2)
    OS_REG_RMW_FIELD(CHN2_CH0_ADDRESS, CHN2_CH0_TXON_OVR, 0);
#if (NUM_SPATIAL_STREAM > 3)
    OS_REG_RMW_FIELD(CHN3_CH0_ADDRESS, CHN3_CH0_TXON_OVR, 0);
#endif
#endif
#endif

#endif
    return;
}

CODESWAP_MARK_EVICTABLE(void, ar6000PdSetupForced, A_UINT8 clpcmode, A_UINT8 bmode, A_UINT8 atten)
{
#if !defined(FPGA)
    A_UINT32 reg32;

    //A_PRINTF_ALWAYS("%s \n", __func__);

    /* now the below setting is for clpcmod=1 ext coupler*/
    reg32 = OS_REG_READ(CHN0_TPC1_ADDRESS);
    reg32 &= ~(CHN0_TPC1_CLPC_EN_OVR_MASK | CHN0_TPC1_SET_TIA_HIGAIN_OVR_MASK);
    reg32 |=  (CHN0_TPC1_CLPC_EN_OVR_SET(3) | CHN0_TPC1_SET_TIA_HIGAIN_OVR_SET(2));
#if (NUM_SPATIAL_STREAM > 1)
    reg32 = OS_REG_READ(CHN1_TPC1_ADDRESS);
    reg32 &= ~(CHN1_TPC1_CLPC_EN_OVR_MASK | CHN1_TPC1_SET_TIA_HIGAIN_OVR_MASK);
    reg32 |=  (CHN1_TPC1_CLPC_EN_OVR_SET(3) | CHN1_TPC1_SET_TIA_HIGAIN_OVR_SET(2));
#if (NUM_SPATIAL_STREAM > 2)
    reg32 = OS_REG_READ(CHN2_TPC1_ADDRESS);
    reg32 &= ~(CHN2_TPC1_CLPC_EN_OVR_MASK | CHN2_TPC1_SET_TIA_HIGAIN_OVR_MASK);
    reg32 |=  (CHN2_TPC1_CLPC_EN_OVR_SET(3) | CHN2_TPC1_SET_TIA_HIGAIN_OVR_SET(2));
#if (NUM_SPATIAL_STREAM > 3)
    reg32 = OS_REG_READ(CHN3_TPC1_ADDRESS);
    reg32 &= ~(CHN3_TPC1_CLPC_EN_OVR_MASK | CHN3_TPC1_SET_TIA_HIGAIN_OVR_MASK);
    reg32 |=  (CHN3_TPC1_CLPC_EN_OVR_SET(3) | CHN3_TPC1_SET_TIA_HIGAIN_OVR_SET(2));
#endif
#endif
#endif
    if ((clpcmode & 0xf) == 1) {
        reg32 = OS_REG_READ(CHN0_TPC12_ADDRESS);
        reg32 &= ~(CHN0_TPC12_TPC_ATTEN_OVR_MASK | CHN0_TPC12_TPC_ATTEN_LOCAL_MASK);
        reg32 |=  (CHN0_TPC12_TPC_ATTEN_OVR_SET(1) | CHN0_TPC12_TPC_ATTEN_LOCAL_SET(atten+16));
        OS_REG_WRITE(CHN0_TPC12_ADDRESS, reg32);

#if (NUM_SPATIAL_STREAM > 1)
        reg32 = OS_REG_READ(CHN1_TPC12_ADDRESS);
        reg32 &= ~(CHN1_TPC12_TPC_ATTEN_OVR_MASK | CHN1_TPC12_TPC_ATTEN_LOCAL_MASK);
        reg32 |=  (CHN1_TPC12_TPC_ATTEN_OVR_SET(1) | CHN1_TPC12_TPC_ATTEN_LOCAL_SET(atten+16));
        OS_REG_WRITE(CHN1_TPC12_ADDRESS, reg32);

#if (NUM_SPATIAL_STREAM > 2)
        reg32 = OS_REG_READ(CHN2_TPC12_ADDRESS);
        reg32 &= ~(CHN2_TPC12_TPC_ATTEN_OVR_MASK | CHN2_TPC12_TPC_ATTEN_LOCAL_MASK);
        reg32 |=  (CHN2_TPC12_TPC_ATTEN_OVR_SET(1) | CHN2_TPC12_TPC_ATTEN_LOCAL_SET(atten+16));
        OS_REG_WRITE(CHN2_TPC12_ADDRESS, reg32);

#if (NUM_SPATIAL_STREAM > 3)
        reg32 = OS_REG_READ(CHN3_TPC12_ADDRESS);
        reg32 &= ~(CHN3_TPC12_TPC_ATTEN_OVR_MASK | CHN3_TPC12_TPC_ATTEN_LOCAL_MASK);
        reg32 |=  (CHN3_TPC12_TPC_ATTEN_OVR_SET(1) | CHN3_TPC12_TPC_ATTEN_LOCAL_SET(atten+16));
        OS_REG_WRITE(CHN3_TPC12_ADDRESS, reg32);
#endif
#endif
#endif
    }

#endif
    return;
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void , ar6000PdSetupForced, A_UINT8 , A_UINT8 , A_UINT8);
extern void ar6000PdSetupForced(A_UINT8 clpcmode, A_UINT8 bmode, A_UINT8 atten);

CODESWAP_MARK_EVICTABLE(void, ar6000PdetSetup, A_UINT32 freq, A_UINT8 chainmask, A_UINT8 bmode, A_UINT8 clpcmode)
{
#if !defined(FPGA)
    A_UINT32 reg32;

    //A_PRINTF_ALWAYS("%s \n", __func__);
    if ((clpcmode & 0xf) == 1) {
        if (bmode == 1) {
            reg32 = OS_REG_READ(CHN0_TPC1_ADDRESS);
            reg32 &= ~(CHN0_TPC1_SQ_GAIN_TIA_HIGAIN_2G_MASK | CHN0_TPC1_SQ_GAIN_TIA_LOGAIN_2G_MASK);
            reg32 |= (CHN0_TPC1_SQ_GAIN_TIA_HIGAIN_2G_SET(3)| CHN0_TPC1_SQ_GAIN_TIA_LOGAIN_2G_SET(3));
            OS_REG_WRITE(CHN0_TPC1_ADDRESS, reg32);

#if (NUM_SPATIAL_STREAM > 1)
            reg32 = OS_REG_READ(CHN1_TPC1_ADDRESS);
            reg32 &= ~(CHN1_TPC1_SQ_GAIN_TIA_HIGAIN_2G_MASK | CHN1_TPC1_SQ_GAIN_TIA_LOGAIN_2G_MASK);
            reg32 |= (CHN1_TPC1_SQ_GAIN_TIA_HIGAIN_2G_SET(3)| CHN1_TPC1_SQ_GAIN_TIA_LOGAIN_2G_SET(3));
            OS_REG_WRITE(CHN1_TPC1_ADDRESS, reg32);

#if (NUM_SPATIAL_STREAM > 2)
            reg32 = OS_REG_READ(CHN2_TPC1_ADDRESS);
            reg32 &= ~(CHN2_TPC1_SQ_GAIN_TIA_HIGAIN_2G_MASK | CHN2_TPC1_SQ_GAIN_TIA_LOGAIN_2G_MASK);
            reg32 |= (CHN2_TPC1_SQ_GAIN_TIA_HIGAIN_2G_SET(3)| CHN2_TPC1_SQ_GAIN_TIA_LOGAIN_2G_SET(3));
            OS_REG_WRITE(CHN2_TPC1_ADDRESS, reg32);

#if (NUM_SPATIAL_STREAM > 3)
            reg32 = OS_REG_READ(CHN3_TPC1_ADDRESS);
            reg32 &= ~(CHN3_TPC1_SQ_GAIN_TIA_HIGAIN_2G_MASK | CHN3_TPC1_SQ_GAIN_TIA_LOGAIN_2G_MASK);
            reg32 |= (CHN3_TPC1_SQ_GAIN_TIA_HIGAIN_2G_SET(3)| CHN3_TPC1_SQ_GAIN_TIA_LOGAIN_2G_SET(3));
            OS_REG_WRITE(CHN3_TPC1_ADDRESS, reg32);
#endif
#endif
#endif
        }
        else {
            reg32 = OS_REG_READ(CHN0_TPC1_ADDRESS);
            reg32 &= ~(CHN0_TPC1_SQ_GAIN_TIA_HIGAIN_5G_MASK | CHN0_TPC1_SQ_GAIN_TIA_LOGAIN_5G_MASK);
            reg32 |= (CHN0_TPC1_SQ_GAIN_TIA_HIGAIN_5G_SET(3)| CHN0_TPC1_SQ_GAIN_TIA_LOGAIN_5G_SET(3));
            OS_REG_WRITE(CHN0_TPC1_ADDRESS, reg32);

#if (NUM_SPATIAL_STREAM > 1)
            reg32 = OS_REG_READ(CHN1_TPC1_ADDRESS);
            reg32 &= ~(CHN1_TPC1_SQ_GAIN_TIA_HIGAIN_5G_MASK | CHN1_TPC1_SQ_GAIN_TIA_LOGAIN_5G_MASK);
            reg32 |= (CHN1_TPC1_SQ_GAIN_TIA_HIGAIN_5G_SET(3)| CHN1_TPC1_SQ_GAIN_TIA_LOGAIN_5G_SET(3));
            OS_REG_WRITE(CHN1_TPC1_ADDRESS, reg32);

#if (NUM_SPATIAL_STREAM > 2)
            reg32 = OS_REG_READ(CHN2_TPC1_ADDRESS);
            reg32 &= ~(CHN2_TPC1_SQ_GAIN_TIA_HIGAIN_5G_MASK | CHN2_TPC1_SQ_GAIN_TIA_LOGAIN_5G_MASK);
            reg32 |= (CHN2_TPC1_SQ_GAIN_TIA_HIGAIN_5G_SET(3)| CHN2_TPC1_SQ_GAIN_TIA_LOGAIN_5G_SET(3));
            OS_REG_WRITE(CHN2_TPC1_ADDRESS, reg32);

#if (NUM_SPATIAL_STREAM > 3)
            reg32 = OS_REG_READ(CHN3_TPC1_ADDRESS);
            reg32 &= ~(CHN3_TPC1_SQ_GAIN_TIA_HIGAIN_5G_MASK | CHN3_TPC1_SQ_GAIN_TIA_LOGAIN_5G_MASK);
            reg32 |= (CHN3_TPC1_SQ_GAIN_TIA_HIGAIN_5G_SET(3)| CHN3_TPC1_SQ_GAIN_TIA_LOGAIN_5G_SET(3));
            OS_REG_WRITE(CHN3_TPC1_ADDRESS, reg32);
#endif
#endif
#endif
        }
        OS_REG_RMW_FIELD(CHN0_TPC1_ADDRESS, CHN0_TPC1_EN_XPDET, 0);
#if (NUM_SPATIAL_STREAM > 1)
        OS_REG_RMW_FIELD(CHN1_TPC1_ADDRESS, CHN1_TPC1_EN_XPDET, 0);
#if (NUM_SPATIAL_STREAM > 2)
        OS_REG_RMW_FIELD(CHN2_TPC1_ADDRESS, CHN2_TPC1_EN_XPDET, 0);
#if (NUM_SPATIAL_STREAM > 3)
        OS_REG_RMW_FIELD(CHN3_TPC1_ADDRESS, CHN3_TPC1_EN_XPDET, 0);
#endif
#endif
#endif
    }
    else if((clpcmode & 0xf) == 2) {
        OS_REG_RMW_FIELD(CHN0_TPC1_ADDRESS, CHN0_TPC1_EN_XPDET, 1);
#if (NUM_SPATIAL_STREAM > 1)
        OS_REG_RMW_FIELD(CHN1_TPC1_ADDRESS, CHN1_TPC1_EN_XPDET, 1);
#if (NUM_SPATIAL_STREAM > 2)
        OS_REG_RMW_FIELD(CHN2_TPC1_ADDRESS, CHN2_TPC1_EN_XPDET, 1);
#if (NUM_SPATIAL_STREAM > 3)
        OS_REG_RMW_FIELD(CHN3_TPC1_ADDRESS, CHN3_TPC1_EN_XPDET, 1);
#endif
#endif
#endif
    }

#endif
    return;
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void , ar6000PdetSetup, A_UINT32 , A_UINT8 , A_UINT8 , A_UINT8 );
extern void ar6000PdetSetup(A_UINT32 freq, A_UINT8 chainmask, A_UINT8 bmode, A_UINT8 clpcmode);

SRAM_TEXT
void ar6000SetTpcForceOlpcPacket(A_UINT32 freq, A_UINT8 gainIdx, A_INT8 dacGain)
{
#if !defined(FPGA)
    A_UINT32 reg32;
    A_UINT8  bmode;

    if (freq == BG_FREQ_MAX || ((freq < BG_FREQ_MAX) && (freq >= BG_FREQ_MIN) && !((freq - BG_FREQ_MIN) % 5))) {
        bmode = 1;
    } else {
        bmode = 0;
    }

    // pdet_calibration_w_pkt
    reg32= 0;
    reg32 &=~(PHY_BB_TPC_7_GAIN_CALC_MODE_MASK | PHY_BB_TPC_7_OLPC_MODE_MASK);
    reg32 |= (PHY_BB_TPC_7_GAIN_CALC_MODE_SET(1) | PHY_BB_TPC_7_OLPC_MODE_SET(1) | PHY_BB_TPC_7_TX_GAIN_TABLE_MAX_SET(31));
    OS_REG_WRITE(PHY_BB_TPC_7_ADDRESS, reg32);

    //changed to pass the per gain Idx based pa config setting.
    use_forced_txgain_idx(DA_Gain_Settings[bmode][gainIdx], dacGain, gainIdx);

    g_pa_setting = DA_Gain_Settings[bmode][gainIdx];
    g_dac_gain = dacGain;
    g_gain_idx = gainIdx;

    //A_PRINTF_ALWAYS("d olpc set gain_idx %d\n", g_gain_idx);

#endif //if !defined(FPGA)
}
#define CLPC_MODE_IN_COUPLER      0
#define CLPC_MODE_EX_COUPLER      1
#define CLPC_MODE_EX_COUPLER_PDET 2
#define CLPC_MODE_PSAT_MASK       0x10
#define CLPC_MODE_TONE_MASK       0x20

//CLPC_mode = 0: internal coupler, 1: external coupler, 2: external coupler + PDET;
//high 4 bits now bit4 use for set psat or not;bit5 use for set packet or tone.
SRAM_TEXT
void ar6000SetTpcForceClpcPacket(A_UINT32 freq, A_UINT8 chainmask, A_UINT8 gainIdx, A_INT8 dacGain, A_UINT8 paCfg, A_UINT8 clpcmode, A_UINT8 tpcm)
{
#if !defined(FPGA)
    A_UINT32 reg32;
    A_UINT8  bmode;
    A_UINT8  ATTN_Cal_idx;
    A_UINT8  attn_step[32];
    A_UINT8  attn_setting[32];
    int i;
    A_UINT8  verbose;

    if (freq == BG_FREQ_MAX || ((freq < BG_FREQ_MAX) && (freq >= BG_FREQ_MIN) && !((freq - BG_FREQ_MIN) % 5))) {
        bmode = 1;
    } else {
        bmode = 0;
    }

	if (0 == bmode) ATTN_Cal_idx=getAlutOffset(0);
	else            ATTN_Cal_idx=getAlutOffset(1);

	//A_PRINTF_ALWAYS("%s \n", __func__);
	A_MEMZERO(attn_step, sizeof(attn_step));
	A_MEMZERO(attn_setting, sizeof(attn_setting));
	if (clpcmode != CLPC_MODE_EX_COUPLER_PDET){
		for (i=0;i<32;i++) {
			attn_step[i]=128;
			attn_setting[i] = (16 + ATTN_Cal_idx);
		}
	} else {
		/*Clean ALUT_BASED, and Program ALUT = 0. So we don't need to calculate attn_step[] and attn_setting[]*/
		OS_REG_RMW_FIELD(PHY_BB_TPC_18_ADDRESS, PHY_BB_TPC_18_TPC_ALUT_BASE, 0);
	}

    //A_PRINTF_ALWAYS("clpc cfg\n");
    OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_CLPC_ERR_UPDATE_DIS, 1);

    // pdet_calibration_w_pkt
    reg32= 0;
    reg32 &=~(PHY_BB_TPC_7_GAIN_CALC_MODE_MASK | PHY_BB_TPC_7_OLPC_MODE_MASK);
    reg32 |= (PHY_BB_TPC_7_GAIN_CALC_MODE_SET(2) | PHY_BB_TPC_7_OLPC_MODE_SET(0) | PHY_BB_TPC_7_TX_GAIN_TABLE_MAX_SET(31));
    OS_REG_WRITE(PHY_BB_TPC_7_ADDRESS, reg32);

    OS_REG_RMW_FIELD(PHY_BB_TPC_12_B0_ADDRESS, PHY_BB_TPC_12_B0_PDADC_BIAS_0, 0);
#if (NUM_SPATIAL_STREAM > 1)
    OS_REG_RMW_FIELD(PHY_BB_TPC_12_B1_ADDRESS, PHY_BB_TPC_12_B1_PDADC_BIAS_1, 0);
#if (NUM_SPATIAL_STREAM > 2)
    OS_REG_RMW_FIELD(PHY_BB_TPC_12_B2_ADDRESS, PHY_BB_TPC_12_B2_PDADC_BIAS_2, 0);
#if (NUM_SPATIAL_STREAM > 3)
    OS_REG_RMW_FIELD(PHY_BB_TPC_12_B3_ADDRESS, PHY_BB_TPC_12_B3_PDADC_BIAS_3, 0);
#endif
#endif
#endif

    pdadc_setup(clpcmode);
    ar6000PdetSetup(freq, chainmask, bmode, clpcmode);
    ar6000PdSetupForced(clpcmode, bmode, ATTN_Cal_idx);
    if ((clpcmode&0xf) != CLPC_MODE_EX_COUPLER_PDET) { //fem mode need verify in future
        ar6000PdetDcCalAll(bmode, chainmask);
    }

    /* RFFE */
    if (clpcmode != CLPC_MODE_EX_COUPLER_PDET)
        OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PD_DC_SEL, 0);
    else {
        OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PD_DC_SEL, 1);
    }
    if (tpcm != TPC_FORCED_GAINIDX){
    	OS_REG_RMW_FIELD(PHY_BB_HEAVY_CLIP_2_ADDRESS, PHY_BB_HEAVY_CLIP_2_HEAVY_CLIP_ENABLE, 0);
    }

    // program ALUT
    verbose =0;
    program_ALUT(attn_step, attn_setting, bmode, 0, verbose);
    program_ALUT(attn_step, attn_setting, bmode, 1, verbose);

    //changed to pass the per gain Idx based pa config setting.
    use_forced_txgain_idx(DA_Gain_Settings[bmode][gainIdx], dacGain, gainIdx);

    g_pa_setting = DA_Gain_Settings[bmode][gainIdx];
    g_dac_gain = dacGain;
    g_gain_idx = gainIdx;

    //A_PRINTF_ALWAYS("d clpc set\n");

#endif //if !defined(FPGA)
}

SRAM_TEXT
void program_ALUT(A_UINT8 pdet_atten_steps_ref[], A_UINT8 pdet_atten_settings_ref[], A_UINT8 bmode, A_UINT8 chain, A_UINT8 verbose)
{
    A_UINT8 *pdet_atten_steps, *pdet_atten_settings;
    A_UINT32 temp, start_addr;
    int i;

    pdet_atten_steps = &(pdet_atten_steps_ref[0]);
    pdet_atten_settings = &(pdet_atten_settings_ref[0]);
    if (bmode == 0) {
        if (chain == 0)    { start_addr = 0x0fa0; }
        else if (chain == 1) { start_addr = 0x1020; }
        else if (chain == 2) { start_addr = 0x10a0; }
        else if (chain == 3) { start_addr = 0x1120; }
        else { start_addr = 0x0fa0; }
    } else {
        if (chain == 0)    { start_addr = 0x0fe0; }
        else if (chain == 1) { start_addr = 0x1060; }
        else if (chain == 2) { start_addr = 0x10e0; }
        else if (chain == 3) { start_addr = 0x1160; }
        else { start_addr = 0x0fe0; }
    }

    for (i = 0; i < 32; i=i+2) {
        OS_REG_WRITE(PHY_BB_TABLES_INTF_ADDR_B0_ADDRESS, start_addr);
#if 0
        if ($verbose) {
            print "alut_content =", $pdet_atten_steps[$i], " " , $pdet_atten_settings[$i], "\n";
            print "alut_content =", $pdet_atten_steps[$i+1], " " , $pdet_atten_settings[$i+1], "\n";
        }
#endif
        temp = pdet_atten_steps[i] | (pdet_atten_settings[i] << 8) | (pdet_atten_steps[i+1] << 13) | (pdet_atten_settings[i+1] << 21);
        OS_REG_WRITE(PHY_BB_TABLES_INTF_DATA_B0_ADDRESS, temp);
        start_addr += 4;
    }
    return;
}

SRAM_TEXT
void ar6000SetTpcForceClpcWfm(A_UINT32 freq, A_UINT8 chainmask, A_UINT8 gainIdx)
{
#if defined(_WHEN_TPC_IS_READY_ONEBYONE)
#if !defined(FPGA)
//ar6000SetTpcForceClpcPacket(freq, chainmask);
    A_UINT32 mode = MODE_11G;
    A_UINT32 reg32;
//    A_UINT32 analog_gain;


    if (freq == BG_FREQ_MAX || ((freq < BG_FREQ_MAX) && (freq >= BG_FREQ_MIN) && !((freq - BG_FREQ_MIN) % 5))) {
        mode = MODE_11G;
    } else {
        mode = MODE_11A;
    }

//    OS_REG_RMW_FIELD(PHY_BB_FORCE_CLOCK_ADDRESS, PHY_BB_FORCE_CLOCK_ENA_REG_CLK_GATING, 0);
//    OS_REG_RMW_FIELD(PHY_BB_GEN_CONTROLS_ADDRESS, PHY_BB_GEN_CONTROLS_DYN_PRI_CHN, 1);

    OS_REG_RMW_FIELD(PHY_BB_TPC_3_ADDRESS, PHY_BB_TPC_3_TPC_CLK_GATE_ENABLE, 0);
    //OS_REG_RMW_FIELD(PHY_BB_TPC_2_ADDRESS, PHY_BB_TPC_2_PDADC_STROBE_INV, 1);
    OS_REG_WRITE(PHY_BB_TPC_7_ADDRESS, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_7_ADDRESS, PHY_BB_TPC_7_GAIN_CALC_MODE, 2);
    //OS_REG_RMW_FIELD(PHY_BB_TPC_7_ADDRESS, PHY_BB_TPC_7_CLPC_ATTN_EN, 1);
    OS_REG_RMW_FIELD(PHY_BB_TPC_7_ADDRESS, PHY_BB_TPC_7_OLPC_MODE, 0);

    pdadc_setup(1);

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B0_RXTX2_ADDRESS);
    reg32 &= ~(WL_TOP_B0_RXTX2_CLPCENABLE_OVR_MASK |
               WL_TOP_B0_RXTX2_CLPCENABLE_MASK     );

    reg32 |=  (WL_TOP_B0_RXTX2_CLPCENABLE_OVR_SET(1) |
               WL_TOP_B0_RXTX2_CLPCENABLE_SET(1)   );

    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B0_RXTX2_ADDRESS, reg32);

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B1_RXTX2_ADDRESS);
    reg32 &= ~(WL_TOP_B1_RXTX2_CLPCENABLE_OVR_MASK |
               WL_TOP_B1_RXTX2_CLPCENABLE_MASK     );

    reg32 |=  (WL_TOP_B1_RXTX2_CLPCENABLE_OVR_SET(1) |
               WL_TOP_B1_RXTX2_CLPCENABLE_SET(1)     );

    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B1_RXTX2_ADDRESS, reg32);

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC1_ADDRESS);
    reg32 &= ~(TPC_B0_TPC1_FORCE_CLPC_EN_MASK |
               TPC_B0_TPC1_FORCED_CLPC_EN_MASK);

    reg32 |=  (TPC_B0_TPC1_FORCE_CLPC_EN_SET(1) |
               TPC_B0_TPC1_FORCED_CLPC_EN_SET(1));

    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC1_ADDRESS, reg32);

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC1_ADDRESS);
    reg32 &= ~(TPC_B1_TPC1_FORCE_CLPC_EN_MASK |
               TPC_B1_TPC1_FORCED_CLPC_EN_MASK);

    reg32 |=  (TPC_B1_TPC1_FORCE_CLPC_EN_SET(1) |
               TPC_B1_TPC1_FORCED_CLPC_EN_SET(1));

    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC1_ADDRESS, reg32);

    ar6000SetPdetDcOffset(freq, chainmask);
    ar6000SetTpcForcedTxgainIdxWfm(0, 0, gainIdx, freq, chainmask);

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_2GTX_1_B0_WLTX2_TPC_FE2X_ADDRESS);
    reg32 &= ~(RFFE_2GTX_1_B0_WLTX2_TPC_FE2X_TXRF_WLAN_TX_ON_MASK);
    reg32 |= RFFE_2GTX_1_B0_WLTX2_TPC_FE2X_TXRF_WLAN_TX_ON_SET(1);
    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_2GTX_1_B0_WLTX2_TPC_FE2X_ADDRESS, reg32);

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_2GTX_1_B1_WLTX2_TPC_FE2X_ADDRESS);
    reg32 &= ~(RFFE_2GTX_1_B1_WLTX2_TPC_FE2X_TXRF_WLAN_TX_ON_MASK);
    reg32 |= RFFE_2GTX_1_B1_WLTX2_TPC_FE2X_TXRF_WLAN_TX_ON_SET(1);
    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_2GTX_1_B1_WLTX2_TPC_FE2X_ADDRESS, reg32);


    if (mode == MODE_11G) {
        reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_2GTX_B0_RFFE_2GTX_EN_ADDRESS);
        reg32 &= ~(RFFE_2GTX_B0_RFFE_2GTX_EN_TXGAIN_OVERRIDE_MASK);
        reg32 |= RFFE_2GTX_B0_RFFE_2GTX_EN_TXGAIN_OVERRIDE_SET(1);
        A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_2GTX_B0_RFFE_2GTX_EN_ADDRESS, reg32);

        reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_2GTX_B1_RFFE_2GTX_EN_ADDRESS);
        reg32 &= ~(RFFE_2GTX_B1_RFFE_2GTX_EN_TXGAIN_OVERRIDE_MASK);
        reg32 |= RFFE_2GTX_B1_RFFE_2GTX_EN_TXGAIN_OVERRIDE_SET(1);
        A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_2GTX_B1_RFFE_2GTX_EN_ADDRESS, reg32);
    } else {
        reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_5G_B0_RFFE_5G_EN_ADDRESS);
        reg32 &= ~(RFFE_5G_B0_RFFE_5G_EN_TXGAIN_OVERRIDE_MASK);
        reg32 |= RFFE_5G_B0_RFFE_5G_EN_TXGAIN_OVERRIDE_SET(1);
        A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_5G_B0_RFFE_5G_EN_ADDRESS, reg32);

        reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_5G_B1_RFFE_5G_EN_ADDRESS);
        reg32 &= ~(RFFE_5G_B1_RFFE_5G_EN_TXGAIN_OVERRIDE_MASK);
        reg32 |= RFFE_5G_B1_RFFE_5G_EN_TXGAIN_OVERRIDE_SET(1);
        A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_5G_B1_RFFE_5G_EN_ADDRESS, reg32);

    }
    OS_REG_RMW_FIELD(PHY_BB_HEAVY_CLIP_2_ADDRESS, PHY_BB_HEAVY_CLIP_2_HEAVY_CLIP_ENABLE, 0);


    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC1_ADDRESS);
    reg32 &= ~(TPC_B0_TPC1_FORCE_SET_TIA_HIGAIN_MASK |
               TPC_B0_TPC1_FORCED_SET_TIA_HIGAIN_MASK);
    reg32 |=  (TPC_B0_TPC1_FORCE_SET_TIA_HIGAIN_SET(1) |
               TPC_B0_TPC1_FORCED_SET_TIA_HIGAIN_SET(0));
    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B0_TPC1_ADDRESS, reg32);

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC1_ADDRESS);
    reg32 &= ~(TPC_B1_TPC1_FORCE_SET_TIA_HIGAIN_MASK |
               TPC_B1_TPC1_FORCED_SET_TIA_HIGAIN_MASK);
    reg32 |=  (TPC_B1_TPC1_FORCE_SET_TIA_HIGAIN_SET(1) |
               TPC_B1_TPC1_FORCED_SET_TIA_HIGAIN_SET(0));
    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + TPC_B1_TPC1_ADDRESS, reg32);


    OS_REG_WRITE(PHY_BB_TEST_CONTROLS_STATUS_ADDRESS, 0);
    OS_REG_RMW_FIELD(PHY_BB_TEST_CONTROLS_STATUS_ADDRESS, PHY_BB_TEST_CONTROLS_STATUS_DISABLE_AGC_TO_A2, 1);

    ar6000Dac_playback(chainmask, 3);
#if 0
A_PRINTF("mode = %d, freq = %d\n", mode, freq);
A_PRINTF("BB_TX_FORCED_GAIN 0x%x\n", OS_REG_READ(PHY_BB_TX_FORCED_GAIN_ADDRESS));
A_PRINTF("BB_TPC2 0x%x\n", OS_REG_READ(PHY_BB_TPC_2_ADDRESS));
A_PRINTF("BB_TPC7 0x%x\n", OS_REG_READ(PHY_BB_TPC_7_ADDRESS));
A_PRINTF("BB_TPC11_B0 0x%x\n", OS_REG_READ(PHY_BB_TPC_11_B0_ADDRESS));
A_PRINTF("BB_TPC11_B1 0x%x\n", OS_REG_READ(PHY_BB_TPC_11_B1_ADDRESS));
A_PRINTF("BB_TABLES_INTF_ADDR_B0 0x%x\n", OS_REG_READ(PHY_BB_TABLES_INTF_ADDR_B0_ADDRESS));
A_PRINTF("BB_FORCE_ANALOG 0x%x\n", OS_REG_READ(PHY_BB_FORCE_ANALOG_ADDRESS));
A_PRINTF("WL_TOP_B0_RXTX2 0x%x\n", A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B0_RXTX2_ADDRESS));
A_PRINTF("WL_TOP_B1_RXTX2 0x%x\n", A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B1_RXTX2_ADDRESS));
A_PRINTF("WL_TOP_B0_RXTX3 0x%x\n", A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B0_RXTX3_ADDRESS));
A_PRINTF("WL_TOP_B1_RXTX3 0x%x\n", A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B1_RXTX3_ADDRESS));
A_PRINTF("WL_BB_B0_BB8 0x%x\n", A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_BB_B0_BB8_ADDRESS));
A_PRINTF("WL_BB_B1_BB8 0x%x\n", A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_BB_B1_BB8_ADDRESS));
#endif
    return;
#endif
#endif //#if defined(_WHEN_TPC_IS_READY_ONEBYONE)
}


SRAM_TEXT
void ar6000DisTpcForceClpcWfm(A_UINT32 freq, A_UINT8 chainmask)
{
#if defined(_WHEN_TPC_IS_READY_ONEBYONE)
#if !defined(FPGA)
    A_UINT32 mode = MODE_11G;
    A_UINT32 reg32;

    if (freq == BG_FREQ_MAX || ((freq < BG_FREQ_MAX) && (freq >= BG_FREQ_MIN) && !((freq - BG_FREQ_MIN) % 5))) {
        mode = MODE_11G;
    } else {
        mode = MODE_11A;
    }

    OS_REG_RMW_FIELD(PHY_BB_TX_FORCED_GAIN_ADDRESS, PHY_BB_TX_FORCED_GAIN_FORCE_TX_GAIN, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_18_ADDRESS, PHY_BB_TPC_18_USE_LEGACY_TPC, 0);

    reg32 = OS_REG_READ(PHY_BB_TPC_7_ADDRESS);
    reg32 &= ~(PHY_BB_TPC_7_FORCE_DAC_GAIN_MASK  |
               PHY_BB_TPC_7_FORCE_PA_CFG_MASK |
               PHY_BB_TPC_7_FORCE_TXGAIN_IDX_MASK);
    OS_REG_WRITE(PHY_BB_TPC_7_ADDRESS, reg32);

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B0_RXTX2_ADDRESS);
    reg32 &= ~(WL_TOP_B0_RXTX2_TXON_OVR_MASK       |
               WL_TOP_B0_RXTX2_BW_ST_OVR_MASK      |
               WL_TOP_B0_RXTX2_SYNTHON_OVR_MASK    |
               WL_TOP_B0_RXTX2_BMODE_OVR_MASK      |
               WL_TOP_B0_RXTX2_CLPCENABLE_OVR_MASK );

    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B0_RXTX2_ADDRESS, reg32);

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B1_RXTX2_ADDRESS);
    reg32 &= ~(WL_TOP_B1_RXTX2_TXON_OVR_MASK       |
               WL_TOP_B1_RXTX2_BW_ST_OVR_MASK      |
               WL_TOP_B1_RXTX2_SYNTHON_OVR_MASK    |
               WL_TOP_B1_RXTX2_BMODE_OVR_MASK      |
               WL_TOP_B1_RXTX2_CLPCENABLE_OVR_MASK );

    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B1_RXTX2_ADDRESS, reg32);


    reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B0_RXTX1_ADDRESS);
    reg32 &= ~(WL_TOP_B0_RXTX1_XPAON_OVR_MASK);
    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B0_RXTX1_ADDRESS, reg32);

    reg32 = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B1_RXTX1_ADDRESS);
    reg32 &= ~(WL_TOP_B1_RXTX1_XPAON_OVR_MASK);
    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B1_RXTX1_ADDRESS, reg32);

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B0_RXTX3_ADDRESS);
    reg32 &= ~WL_TOP_B0_RXTX3_MANTXGAIN_MASK;
    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B0_RXTX3_ADDRESS, reg32);

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B1_RXTX3_ADDRESS);
    reg32 &= ~WL_TOP_B1_RXTX3_MANTXGAIN_MASK;
    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_TOP_B1_RXTX3_ADDRESS, reg32);

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_2GTX_1_B0_WLTX2_TPC_FE2X_ADDRESS);
    reg32 &= ~(RFFE_2GTX_1_B0_WLTX2_TPC_FE2X_TXRF_WLAN_TX_ON_MASK);
    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_2GTX_1_B0_WLTX2_TPC_FE2X_ADDRESS, reg32);

    reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_2GTX_1_B1_WLTX2_TPC_FE2X_ADDRESS);
    reg32 &= ~(RFFE_2GTX_1_B1_WLTX2_TPC_FE2X_TXRF_WLAN_TX_ON_MASK);
    A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_2GTX_1_B1_WLTX2_TPC_FE2X_ADDRESS, reg32);


    if (mode == MODE_11G) {
        reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_2GTX_B0_RFFE_2GTX_EN_ADDRESS);
        reg32 &= ~(RFFE_2GTX_B0_RFFE_2GTX_EN_TXGAIN_OVERRIDE_MASK);
        A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_2GTX_B0_RFFE_2GTX_EN_ADDRESS, reg32);

        reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_2GTX_B1_RFFE_2GTX_EN_ADDRESS);
        reg32 &= ~(RFFE_2GTX_B1_RFFE_2GTX_EN_TXGAIN_OVERRIDE_MASK);
        A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_2GTX_B1_RFFE_2GTX_EN_ADDRESS, reg32);
    } else {
        reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_5G_B0_RFFE_5G_EN_ADDRESS);
        reg32 &= ~(RFFE_5G_B0_RFFE_5G_EN_TXGAIN_OVERRIDE_MASK);
        A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_5G_B0_RFFE_5G_EN_ADDRESS, reg32);

        reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_5G_B1_RFFE_5G_EN_ADDRESS);
        reg32 &= ~(RFFE_5G_B1_RFFE_5G_EN_TXGAIN_OVERRIDE_MASK);
        A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + RFFE_5G_B1_RFFE_5G_EN_ADDRESS, reg32);

    }

    OS_REG_RMW_FIELD(PHY_BB_TEST_CONTROLS_STATUS_ADDRESS, PHY_BB_TEST_CONTROLS_STATUS_DISABLE_AGC_TO_A2, 0);

    return;
#endif
#endif //#if defined(_WHEN_TPC_IS_READY_ONEBYONE)
}
SRAM_TEXT
void ar6000SetPdetDcOffset(A_UINT32 freq, A_UINT8 chainmask)
{
#if defined(_WHEN_TPC_IS_READY_ONEBYONE)

    A_UINT32 reg32;
    A_UINT32 pdadc;
    A_UINT32 clip_pwr;
    A_UINT32 clip_dc ;
    A_UINT32 dc ;

    //A_PRINTF_ALWAYS("%s \n", __func__);

    //OS_REG_RMW_FIELD(PHY_BB_TPC3_ADDRESS, PHY_BB_TPC3_TPC_CLK_GATE_ENABLE, 0);
    //OS_REG_RMW_FIELD(PHY_BB_TPC12_B0_ADDRESS, PHY_BB_TPC12_B0_PDADC_BIAS_0, 0);
    //OS_REG_RMW_FIELD(PHY_BB_TPC12_B1_ADDRESS, PHY_BB_TPC12_B1_PDADC_BIAS_1, 0);
    //OS_REG_RMW_FIELD(PHY_BB_TPC1_ADDRESS, PHY_BB_TPC1_PD_DC_SEL, 1);
    //pdadc read

    //OS_REG_RMW_FIELD(PHY_BB_TPC12_B0_ADDRESS, PHY_BB_TPC12_B0_PDADC_BIAS_0, 0);
    //OS_REG_RMW_FIELD(PHY_BB_TPC12_B1_ADDRESS, PHY_BB_TPC12_B1_PDADC_BIAS_1, 0);
#if 1
    OS_REG_RMW_FIELD(PHY_BB_TPC_3_ADDRESS, PHY_BB_TPC_3_TPC_CLK_GATE_ENABLE, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_12_B0_ADDRESS, PHY_BB_TPC_12_B0_PDADC_BIAS_0, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_12_B1_ADDRESS, PHY_BB_TPC_12_B1_PDADC_BIAS_1, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PD_DC_SEL, 1);
    //pdadc read
     /* Set threshold */
    OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_PDADC_CLIP_THRES, 0x1f0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_PDADC_CLIP_EN, 1);

    OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PWR_MEAS_TRIG_SW, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_MEAS_PWR_SW, 0);

        /* Start */
    OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PWR_MEAS_TRIG_SW, 1);
    OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_MEAS_PWR_SW, 1);

    /* Wait 10ms */
    A_DELAY_USECS(10 * 1000);

    reg32    = OS_REG_READ(PHY_BB_TPC_4_B0_ADDRESS);
    clip_pwr = PHY_BB_TPC_4_B0_PDADC_CLIP_1_CNT_0_GET(reg32);
    clip_dc  = PHY_BB_TPC_4_B0_PDADC_CLIP_2_CNT_0_GET(reg32);

    /* Stop */
    OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PWR_MEAS_TRIG_SW, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_MEAS_PWR_SW, 0);

    reg32 = OS_REG_READ(PHY_BB_TPC_STAT_0_B0_ADDRESS);
    pdadc = PHY_BB_TPC_STAT_0_B0_PDACC_AVG_OUT_0_GET(reg32);
    dc =   PHY_BB_TPC_STAT_0_B0_LATEST_DC_VALUE_0_GET(reg32);

    //A_PRINTF("chain0  clip_pwr0:%d, clip_dc0:%d, pdadc0:%d DC0:%d, reg32:%x\n",clip_pwr,clip_dc,pdadc,dc, reg32);

    OS_REG_RMW_FIELD(PHY_BB_TPC_12_B0_ADDRESS, PHY_BB_TPC_12_B0_PDADC_BIAS_0, pdadc);


    reg32 = OS_REG_READ(PHY_BB_TPC_STAT_0_B1_ADDRESS);
    pdadc = PHY_BB_TPC_STAT_0_B1_PDACC_AVG_OUT_1_GET(reg32);
    dc =   PHY_BB_TPC_STAT_0_B1_LATEST_DC_VALUE_1_GET(reg32);

    //A_PRINTF("chain1  clip_pwr1:%d, clip_dc1:%d, pdadc1:%d DC1:%d, reg32:%x\n",clip_pwr,clip_dc,pdadc,dc, reg32);
    OS_REG_RMW_FIELD(PHY_BB_TPC_12_B1_ADDRESS, PHY_BB_TPC_12_B1_PDADC_BIAS_1, pdadc);
#endif

#endif //#if defined(_WHEN_TPC_IS_READY_ONEBYONE)
    return;
}

SRAM_TEXT
void ar6000SetTpcForceCplcPwr(A_UINT32 freq, A_UINT8 gainIdx, A_UINT8 chainmask)
{
#if defined(_WHEN_TPC_IS_READY_ONEBYONE)
#if !defined(FPGA)
    A_UINT8 i;
    A_UINT32 analog_gain;
    A_UINT32 reg32;

    //A_PRINTF_ALWAYS("%s \n", __func__);

    for (i = 0;i < 15;i++) {

        OS_REG_WRITE(PHY_BB_TABLES_INTF_ADDR_B0_ADDRESS, 0X480 + 4*i);//2G
        analog_gain = OS_REG_READ(PHY_BB_TABLES_INTF_DATA_B0_ADDRESS);
        A_PRINTF("\nidex %d,bq2:%d , bq1:%d, gc:%d total gain:%d\n",i, analog_gain & 0xf,(analog_gain >> 4) & 0x3,(analog_gain >> 6) & 0x7, (analog_gain >> 10) & 0x3ff);
        reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_BB_B0_BB8_ADDRESS);
        reg32 &= ~(WL_BB_B0_BB8_TX_BQ2_MASK |
                   WL_BB_B0_BB8_TX_BQ1_MASK |
                   WL_BB_B0_BB8_TXBB_GC_MASK);

        reg32 |=  (WL_BB_B0_BB8_TX_BQ2_SET(analog_gain & 0xf) |
                   WL_BB_B0_BB8_TX_BQ1_SET((analog_gain >> 4) & 0x3) |
                   WL_BB_B0_BB8_TXBB_GC_SET((analog_gain >> 6) & 0x7));

        A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_BB_B0_BB8_ADDRESS, reg32);

        reg32  = A_SOC_ADDR_READ(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_BB_B1_BB8_ADDRESS);
        reg32 &= ~(WL_BB_B1_BB8_TX_BQ2_MASK |
                   WL_BB_B1_BB8_TX_BQ1_MASK |
                   WL_BB_B1_BB8_TXBB_GC_MASK);

        reg32 |=  (WL_BB_B1_BB8_TX_BQ2_SET(analog_gain & 0xf) |
                   WL_BB_B1_BB8_TX_BQ1_SET((analog_gain >> 4) & 0x3) |
                   WL_BB_B1_BB8_TXBB_GC_SET((analog_gain >> 6) & 0x7));

        A_SOC_ADDR_WRITE(WLAN_ANALOG_INTF_BASE_ADDRESS + WL_BB_B1_BB8_ADDRESS, reg32);
        /* Wait 100ms */
        A_DELAY_USECS(10 * 1000);
       ar6000GetPdetPdadcWfm(0,0x2);

    }
#endif//!defined(FPGA)
#endif //#if defined(_WHEN_TPC_IS_READY_ONEBYONE)
    return;
}

SRAM_TEXT
A_UINT16 ar6000GetPdetPdadcWfm(A_UINT32 freq, A_UINT8 chainMask)
{
#if defined(_WHEN_TPC_IS_READY_ONEBYONE)
    A_UINT32  reg32;
    A_UINT32  clip_pwr;
    A_UINT32  clip_dc;
    A_UINT32  i;
    A_UINT16  pdadc = 0;

    //A_PRINTF("in %s \n",__func__);
    //pdadc_setup();

    /* Disable AGC logic */
    //OS_REG_WRITE(PHY_BB_TEST_CONTROLS_STATUS_ADDRESS, 0);
    //OS_REG_RMW_FIELD(PHY_BB_TEST_CONTROLS_STATUS_ADDRESS, PHY_BB_TEST_CONTROLS_STATUS_DISABLE_AGC_TO_A2, 1);

    /* */
/*    OS_REG_RMW_FIELD(PHY_BB_TPC_3_ADDRESS, PHY_BB_TPC_3_TPC_CLK_GATE_ENABLE, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_12_B0_ADDRESS, PHY_BB_TPC_12_B0_PDADC_BIAS_0, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_12_B1_ADDRESS, PHY_BB_TPC_12_B1_PDADC_BIAS_1, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PD_DC_SEL, 1);
*/
    //A_DELAY_USECS(20 * 1000);
    /* Set threshold */
    OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_PDADC_CLIP_THRES, 0x1f0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_PDADC_CLIP_EN, 1);

    OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PWR_MEAS_TRIG_SW, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_MEAS_PWR_SW, 0);

    if (chainMask & 0x01) {
        for (i=0;i<5;i++) {
        /* Start */
        OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PWR_MEAS_TRIG_SW, 1);
        OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_MEAS_PWR_SW, 1);

        /* Wait 10ms */
        A_DELAY_USECS(20 * 1000);

        reg32    = OS_REG_READ(PHY_BB_TPC_4_B0_ADDRESS);
        clip_pwr = PHY_BB_TPC_4_B0_PDADC_CLIP_1_CNT_0_GET(reg32);
        clip_dc  = PHY_BB_TPC_4_B0_PDADC_CLIP_2_CNT_0_GET(reg32);

        /* Stop */
        OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PWR_MEAS_TRIG_SW, 0);
        OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_MEAS_PWR_SW, 0);

        reg32 = OS_REG_READ(PHY_BB_TPC_STAT_0_B0_ADDRESS);

        pdadc &= 0xff00;
        pdadc |= PHY_BB_TPC_STAT_0_B0_PDACC_AVG_OUT_0_GET(reg32);

        //A_PRINTF("chain0 %d clip_pwr0:%d, clip_dc0:%d, pdadc0:%d \n",i,clip_pwr,clip_dc,pdadc);
        }
    }
    if (chainMask & 0x02) {
        for (i=0;i<5;i++) {
        /* Start */
        OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PWR_MEAS_TRIG_SW, 1);
        OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_MEAS_PWR_SW, 1);

        /* Wait 10ms */
        A_DELAY_USECS(20 * 1000);

        reg32    = OS_REG_READ(PHY_BB_TPC_4_B1_ADDRESS);
        clip_pwr = PHY_BB_TPC_4_B1_PDADC_CLIP_1_CNT_1_GET(reg32);
        clip_dc  = PHY_BB_TPC_4_B1_PDADC_CLIP_2_CNT_1_GET(reg32);

        /* Stop */
        OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_PWR_MEAS_TRIG_SW, 0);
        OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_TPC_17_MEAS_PWR_SW, 0);

        reg32 = OS_REG_READ(PHY_BB_TPC_STAT_0_B1_ADDRESS);
        pdadc &=0xff;
        pdadc |= (PHY_BB_TPC_STAT_0_B1_PDACC_AVG_OUT_1_GET(reg32)) << 8;

        //A_PRINTF("chain1 %d clip_pwr1:%d, clip_dc1:%d, pdadc1:%d \n",i,clip_pwr,clip_dc, pdadc >> 8);
        }
    }

    return pdadc;
#endif //#if defined(_WHEN_TPC_IS_READY_ONEBYONE)
    return(0);
}

//PDADC_setup
SRAM_TEXT
void ar6000GetPdetPdadcPacket(A_UINT32 freq, A_UINT8 chainMask, A_UINT8 avg[])
{
    ///PDADC_read(avg);
    //A_PRINTF_ALWAYS("%s \n", __func__);
    //pdadc_setup();
#if (NUM_SPATIAL_STREAM > 2)
    avg[3] = PHY_BB_TPC_STAT_0_B3_PDACC_AVG_OUT_3_GET(OS_REG_READ(PHY_BB_TPC_STAT_0_B3_ADDRESS));
    avg[2] = PHY_BB_TPC_STAT_0_B2_PDACC_AVG_OUT_2_GET(OS_REG_READ(PHY_BB_TPC_STAT_0_B2_ADDRESS));
#endif
    avg[1] = PHY_BB_TPC_STAT_0_B1_PDACC_AVG_OUT_1_GET(OS_REG_READ(PHY_BB_TPC_STAT_0_B1_ADDRESS));
    avg[0] = PHY_BB_TPC_STAT_0_B0_PDACC_AVG_OUT_0_GET(OS_REG_READ(PHY_BB_TPC_STAT_0_B0_ADDRESS));

#if 0
    dc3 =  PHY_BB_TPC_STAT_0_B3_LATEST_DC_VALUE_3_GET(OS_REG_READ(PHY_BB_TPC_STAT_0_B3_ADDRESS));
    dc2 =  PHY_BB_TPC_STAT_0_B2_LATEST_DC_VALUE_2_GET(OS_REG_READ(PHY_BB_TPC_STAT_0_B2_ADDRESS));
    dc1 =  PHY_BB_TPC_STAT_0_B1_LATEST_DC_VALUE_1_GET(OS_REG_READ(PHY_BB_TPC_STAT_0_B1_ADDRESS));
    dc0 =  PHY_BB_TPC_STAT_0_B0_LATEST_DC_VALUE_0_GET(OS_REG_READ(PHY_BB_TPC_STAT_0_B0_ADDRESS));

    clip3 = PHY_BB_TPC_4_B3_PDADC_CLIP_1_CNT_3_GET(OS_REG_READ(PHY_BB_TPC_4_B3_ADDRESS));
    clip2 = PHY_BB_TPC_4_B2_PDADC_CLIP_1_CNT_2_GET(OS_REG_READ(PHY_BB_TPC_4_B2_ADDRESS));
    clip1 = PHY_BB_TPC_4_B1_PDADC_CLIP_1_CNT_1_GET(OS_REG_READ(PHY_BB_TPC_4_B1_ADDRESS));
    clip0 = PHY_BB_TPC_4_B0_PDADC_CLIP_1_CNT_0_GET(OS_REG_READ(PHY_BB_TPC_4_B0_ADDRESS));

    if ((clip0 > 0) & ( clip1 > 0) & ( clip2 > 0) & ( clip3 > 0)) { return; }
#endif
    return;
}

#define WL_BB_B0_PDADC2_XPDET_EN_MASK                                  0x10000000
#define WL_BB_B0_PDADC2_XPDET_EN_SET(x)                                (((0 | (x)) << 28) & WL_BB_B0_PDADC2_SPARE1_MASK)
#define WL_BB_B1_PDADC2_XPDET_EN_MASK                                  0x10000000
#define WL_BB_B1_PDADC2_XPDET_EN_SET(x)                                (((0 | (x)) << 28) & WL_BB_B1_PDADC2_SPARE1_MASK)

CODESWAP_MARK_EVICTABLE(void, pdadc_setup, A_UINT8 clpcmode)
{
#if !defined(FPGA)
    A_UINT32 reg32;
    //A_PRINTF_ALWAYS("%s \n", __func__);

    //OS_REG_RMW_FIELD(PHY_BB_TPC_3_ADDRESS, PHY_BB_TPC_3_TPC_CLK_GATE_ENABLE, 0);

    /* BB_TPC_1 */
    reg32 = OS_REG_READ(PHY_BB_TPC_1_ADDRESS);
    reg32 &= ~(PHY_BB_TPC_1_PD_DC_SEL_MASK | PHY_BB_TPC_1_PD_DC_WIN_MASK | PHY_BB_TPC_1_PD_DC_START_MASK |
              PHY_BB_TPC_1_THERM_MEAS_DUR_MASK | PHY_BB_TPC_1_THERM_INI_DUR_MASK |
              PHY_BB_TPC_1_VOLT_MEAS_DUR_MASK | PHY_BB_TPC_1_VOLT_INI_DUR_MASK);
    reg32 |= (PHY_BB_TPC_1_PD_DC_SEL_SET(0) | PHY_BB_TPC_1_PD_DC_WIN_SET(6) | PHY_BB_TPC_1_PD_DC_START_SET(220) |
              PHY_BB_TPC_1_THERM_MEAS_DUR_SET(3) | PHY_BB_TPC_1_THERM_INI_DUR_SET(10) |
              PHY_BB_TPC_1_VOLT_MEAS_DUR_SET(3) | PHY_BB_TPC_1_VOLT_INI_DUR_SET(10));
    if (clpcmode == CLPC_MODE_EX_COUPLER_PDET) // for DC based CLPC
        reg32 |= PHY_BB_TPC_1_PD_DC_SEL_SET(1);
    OS_REG_WRITE(PHY_BB_TPC_1_ADDRESS, reg32);

    /* BB_TPC_3 */
    reg32 = OS_REG_READ(PHY_BB_TPC_3_ADDRESS);
    reg32 &= ~(PHY_BB_TPC_3_PD_ACC_WINDOW_CCK_MASK | PHY_BB_TPC_3_PD_ACC_WINDOW_OFDM_MASK |
              PHY_BB_TPC_3_THERM_GAIN_ERR_DB_MAX_MASK);
    reg32 |= (PHY_BB_TPC_3_PD_ACC_WINDOW_CCK_SET(6) | PHY_BB_TPC_3_PD_ACC_WINDOW_OFDM_SET(6) |
              PHY_BB_TPC_3_THERM_GAIN_ERR_DB_MAX_SET(5));
    OS_REG_WRITE(PHY_BB_TPC_3_ADDRESS, reg32);

    /* BB_TPC_10 */
    reg32 = OS_REG_READ(PHY_BB_TPC_10_ADDRESS);
    reg32 &= ~(PHY_BB_TPC_10_CLPC_START_OFDM_MASK | PHY_BB_TPC_10_CLPC_START_CCK_MASK);
    reg32 |= (PHY_BB_TPC_10_CLPC_START_OFDM_SET(136) | PHY_BB_TPC_10_CLPC_START_CCK_SET(136));
    OS_REG_WRITE(PHY_BB_TPC_10_ADDRESS, reg32);

    /* BB_TPC_17 */
    reg32 = OS_REG_READ(PHY_BB_TPC_17_ADDRESS);
    reg32 &= ~(PHY_BB_TPC_17_PDADC_CLIP_EN_MASK | PHY_BB_TPC_17_PDADC_CLIP_THRES_MASK);
    reg32 |= (PHY_BB_TPC_17_PDADC_CLIP_EN_SET(1) | PHY_BB_TPC_17_PDADC_CLIP_THRES_SET(500));
    OS_REG_WRITE(PHY_BB_TPC_17_ADDRESS, reg32);

    /* Enable XPDET path 0: disable 1: enable */
    if ((clpcmode&0xf) == 2) {
        OS_REG_RMW_FIELD(CHN0_TPC1_ADDRESS, CHN0_TPC1_EN_XPDET, 1);
#if (NUM_SPATIAL_STREAM > 1)
        OS_REG_RMW_FIELD(CHN1_TPC1_ADDRESS, CHN1_TPC1_EN_XPDET, 1);
#if (NUM_SPATIAL_STREAM > 2)
        OS_REG_RMW_FIELD(CHN2_TPC1_ADDRESS, CHN2_TPC1_EN_XPDET, 1);
#if (NUM_SPATIAL_STREAM > 3)
        OS_REG_RMW_FIELD(CHN3_TPC1_ADDRESS, CHN3_TPC1_EN_XPDET, 1);
#endif
#endif
#endif
        OS_REG_RMW_FIELD(CHN0_TPC12_ADDRESS, CHN0_TPC12_TPC_EXT_PDET_EN, 1);
        OS_REG_RMW_FIELD(CHN1_TPC12_ADDRESS, CHN1_TPC12_TPC_EXT_PDET_EN, 1);
        OS_REG_RMW_FIELD(CHN0_TPC13_ADDRESS, CHN0_TPC13_DPD_SPARE, 1);
        OS_REG_RMW_FIELD(CHN1_TPC13_ADDRESS, CHN1_TPC13_DPD_SPARE, 1);

    }
    else {
        OS_REG_RMW_FIELD(CHN0_TPC1_ADDRESS, CHN0_TPC1_EN_XPDET, 0);
#if (NUM_SPATIAL_STREAM > 1)
        OS_REG_RMW_FIELD(CHN1_TPC1_ADDRESS, CHN1_TPC1_EN_XPDET, 0);
#if (NUM_SPATIAL_STREAM > 2)
        OS_REG_RMW_FIELD(CHN2_TPC1_ADDRESS, CHN2_TPC1_EN_XPDET, 0);
#if (NUM_SPATIAL_STREAM > 3)
        OS_REG_RMW_FIELD(CHN3_TPC1_ADDRESS, CHN3_TPC1_EN_XPDET, 0);
#endif
#endif
#endif
    }

    // CHN0_PDADC
#if 0
    reg32  = OS_REG_READ(CHN0_PDADC0_ADDRESS);
    reg32 &= ~(CHN0_PDADC0_PDADC_FULLSWING_MASK | CHN0_PDADC0_PDADC_REF_ADJ_MASK |
               CHN0_PDADC0_PDADC_VREF_CTRL_MASK | CHN0_PDADC0_PDADC_THERM_SENS_RES_MASK);
    reg32 |= (CHN0_PDADC0_PDADC_FULLSWING_SET(1) | CHN0_PDADC0_PDADC_REF_ADJ_SET(3) |
              CHN0_PDADC0_PDADC_VREF_CTRL_SET(1) | CHN0_PDADC0_PDADC_THERM_SENS_RES_SET(3));

    reg32  = OS_REG_READ(CHN0_PDADC1_ADDRESS);
    reg32 &= ~(CHN0_PDADC1_PDADC_IC25_ADC_MASK | CHN0_PDADC1_PDADC_IC25_ADCBUF1_MASK |
               CHN0_PDADC1_PDADC_IC25_ADCBUF2_MASK | CHN0_PDADC1_PDADC_IR25_SRCH_MASK |
               CHN0_PDADC1_PDADC_IR25_VREF_MASK);
    reg32 |= (CHN0_PDADC1_PDADC_IC25_ADC_SET(3) | CHN0_PDADC1_PDADC_IC25_ADCBUF1_SET(3) |
              CHN0_PDADC1_PDADC_IC25_ADCBUF2_SET(3) | CHN0_PDADC1_PDADC_IR25_SRCH_SET(3) |
              CHN0_PDADC1_PDADC_IR25_VREF_SET(3));

    // CHN1_PDADC
    reg32  = OS_REG_READ(CHN1_PDADC0_ADDRESS);
    reg32 &= ~(CHN1_PDADC0_PDADC_FULLSWING_MASK | CHN1_PDADC0_PDADC_REF_ADJ_MASK |
               CHN1_PDADC0_PDADC_VREF_CTRL_MASK | CHN1_PDADC0_PDADC_THERM_SENS_RES_MASK);
    reg32 |= (CHN1_PDADC0_PDADC_FULLSWING_SET(1) | CHN1_PDADC0_PDADC_REF_ADJ_SET(3) |
              CHN1_PDADC0_PDADC_VREF_CTRL_SET(1) | CHN1_PDADC0_PDADC_THERM_SENS_RES_SET(3));

    reg32  = OS_REG_READ(CHN1_PDADC1_ADDRESS);
    reg32 &= ~(CHN1_PDADC1_PDADC_IC25_ADC_MASK | CHN1_PDADC1_PDADC_IC25_ADCBUF1_MASK |
               CHN1_PDADC1_PDADC_IC25_ADCBUF2_MASK | CHN1_PDADC1_PDADC_IR25_SRCH_MASK |
               CHN1_PDADC1_PDADC_IR25_VREF_MASK);
    reg32 |= (CHN1_PDADC1_PDADC_IC25_ADC_SET(3) | CHN1_PDADC1_PDADC_IC25_ADCBUF1_SET(3) |
              CHN1_PDADC1_PDADC_IC25_ADCBUF2_SET(3) | CHN1_PDADC1_PDADC_IR25_SRCH_SET(3) |
              CHN1_PDADC1_PDADC_IR25_VREF_SET(3));

    // CHN2_PDADC
    reg32  = OS_REG_READ(CHN2_PDADC0_ADDRESS);
    reg32 &= ~(CHN2_PDADC0_PDADC_FULLSWING_MASK | CHN2_PDADC0_PDADC_REF_ADJ_MASK |
               CHN2_PDADC0_PDADC_VREF_CTRL_MASK | CHN2_PDADC0_PDADC_THERM_SENS_RES_MASK);
    reg32 |= (CHN2_PDADC0_PDADC_FULLSWING_SET(1) | CHN2_PDADC0_PDADC_REF_ADJ_SET(3) |
              CHN2_PDADC0_PDADC_VREF_CTRL_SET(1) | CHN2_PDADC0_PDADC_THERM_SENS_RES_SET(3));

    reg32  = OS_REG_READ(CHN2_PDADC1_ADDRESS);
    reg32 &= ~(CHN2_PDADC1_PDADC_IC25_ADC_MASK | CHN2_PDADC1_PDADC_IC25_ADCBUF1_MASK |
               CHN2_PDADC1_PDADC_IC25_ADCBUF2_MASK | CHN2_PDADC1_PDADC_IR25_SRCH_MASK |
               CHN2_PDADC1_PDADC_IR25_VREF_MASK);
    reg32 |= (CHN2_PDADC1_PDADC_IC25_ADC_SET(3) | CHN2_PDADC1_PDADC_IC25_ADCBUF1_SET(3) |
              CHN2_PDADC1_PDADC_IC25_ADCBUF2_SET(3) | CHN2_PDADC1_PDADC_IR25_SRCH_SET(3) |
              CHN2_PDADC1_PDADC_IR25_VREF_SET(3));

    // CHN3_PDADC
    reg32  = OS_REG_READ(CHN3_PDADC0_ADDRESS);
    reg32 &= ~(CHN3_PDADC0_PDADC_FULLSWING_MASK | CHN3_PDADC0_PDADC_REF_ADJ_MASK |
               CHN3_PDADC0_PDADC_VREF_CTRL_MASK | CHN3_PDADC0_PDADC_THERM_SENS_RES_MASK);
    reg32 |= (CHN3_PDADC0_PDADC_FULLSWING_SET(1) | CHN3_PDADC0_PDADC_REF_ADJ_SET(3) |
              CHN3_PDADC0_PDADC_VREF_CTRL_SET(1) | CHN3_PDADC0_PDADC_THERM_SENS_RES_SET(3));

    reg32  = OS_REG_READ(CHN3_PDADC1_ADDRESS);
    reg32 &= ~(CHN3_PDADC1_PDADC_IC25_ADC_MASK | CHN3_PDADC1_PDADC_IC25_ADCBUF1_MASK |
               CHN3_PDADC1_PDADC_IC25_ADCBUF2_MASK | CHN3_PDADC1_PDADC_IR25_SRCH_MASK |
               CHN3_PDADC1_PDADC_IR25_VREF_MASK);
    reg32 |= (CHN3_PDADC1_PDADC_IC25_ADC_SET(3) | CHN3_PDADC1_PDADC_IC25_ADCBUF1_SET(3) |
              CHN3_PDADC1_PDADC_IC25_ADCBUF2_SET(3) | CHN3_PDADC1_PDADC_IR25_SRCH_SET(3) |
              CHN3_PDADC1_PDADC_IR25_VREF_SET(3));
#endif
#endif//!defined(FPGA)
    return;
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void , pdadc_setup, A_UINT8 );
extern void pdadc_setup(A_UINT8 clpcmode);

//#=================================================================================
//# TPC: use_forced_txgain_idx
//#=================================================================================
/*SRAM_TEXT
void use_forced_txgain_idx(A_UINT8 pa_setting, A_INT8 dac_gain, A_UINT8 gain_idx)
*/
CODESWAP_MARK_EVICTABLE(void, use_forced_txgain_idx, A_UINT8 pa_setting, A_INT8 dac_gain, A_UINT8 gain_idx)
{
    A_UINT32 reg32;

    OS_REG_RMW_FIELD(PHY_BB_TX_FORCED_GAIN_ADDRESS, PHY_BB_TX_FORCED_GAIN_FORCE_TX_GAIN, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_18_ADDRESS, PHY_BB_TPC_18_USE_LEGACY_TPC, 0);

    reg32 = OS_REG_READ(PHY_BB_TPC_7_ADDRESS);
    reg32 &= ~(PHY_BB_TPC_7_FORCE_DAC_GAIN_MASK | PHY_BB_TPC_7_FORCE_PA_CFG_MASK | PHY_BB_TPC_7_FORCE_TXGAIN_IDX_MASK);
    reg32 |=  (PHY_BB_TPC_7_FORCE_DAC_GAIN_SET(1) | PHY_BB_TPC_7_FORCE_PA_CFG_SET(1) | PHY_BB_TPC_7_FORCE_TXGAIN_IDX_SET(1));
    OS_REG_WRITE(PHY_BB_TPC_7_ADDRESS, reg32);

    reg32 = OS_REG_READ(PHY_BB_TPC_11_B0_ADDRESS);
    reg32 &= ~(PHY_BB_TPC_11_B0_FORCED_DAC_GAIN_0_MASK | PHY_BB_TPC_11_B0_FORCED_PA_CFG_0_MASK |
               PHY_BB_TPC_11_B0_FORCED_TXGAIN_IDX_0_MASK);
    reg32 |=  (PHY_BB_TPC_11_B0_FORCED_DAC_GAIN_0_SET(dac_gain) | PHY_BB_TPC_11_B0_FORCED_PA_CFG_0_SET(pa_setting) |
               PHY_BB_TPC_11_B0_FORCED_TXGAIN_IDX_0_SET(gain_idx));
    OS_REG_WRITE(PHY_BB_TPC_11_B0_ADDRESS, reg32);

    reg32 = OS_REG_READ(PHY_BB_TPC_11_B1_ADDRESS);
    reg32 &= ~(PHY_BB_TPC_11_B1_FORCED_DAC_GAIN_1_MASK | PHY_BB_TPC_11_B1_FORCED_PA_CFG_1_MASK |
               PHY_BB_TPC_11_B1_FORCED_TXGAIN_IDX_1_MASK);
    reg32 |=  (PHY_BB_TPC_11_B1_FORCED_DAC_GAIN_1_SET(dac_gain) | PHY_BB_TPC_11_B1_FORCED_PA_CFG_1_SET(pa_setting) |
               PHY_BB_TPC_11_B1_FORCED_TXGAIN_IDX_1_SET(gain_idx));
    OS_REG_WRITE(PHY_BB_TPC_11_B1_ADDRESS, reg32);

#if (NUM_SPATIAL_STREAM > 2)
    reg32 = OS_REG_READ(PHY_BB_TPC_11_B2_ADDRESS);
    reg32 &= ~(PHY_BB_TPC_11_B2_FORCED_DAC_GAIN_2_MASK | PHY_BB_TPC_11_B2_FORCED_PA_CFG_2_MASK |
               PHY_BB_TPC_11_B2_FORCED_TXGAIN_IDX_2_MASK);
    reg32 |=  (PHY_BB_TPC_11_B2_FORCED_DAC_GAIN_2_SET(dac_gain) | PHY_BB_TPC_11_B2_FORCED_PA_CFG_2_SET(pa_setting) |
               PHY_BB_TPC_11_B2_FORCED_TXGAIN_IDX_2_SET(gain_idx));
    OS_REG_WRITE(PHY_BB_TPC_11_B2_ADDRESS, reg32);

    reg32 = OS_REG_READ(PHY_BB_TPC_11_B3_ADDRESS);
    reg32 &= ~(PHY_BB_TPC_11_B3_FORCED_DAC_GAIN_3_MASK | PHY_BB_TPC_11_B3_FORCED_PA_CFG_3_MASK |
               PHY_BB_TPC_11_B3_FORCED_TXGAIN_IDX_3_MASK);
    reg32 |=  (PHY_BB_TPC_11_B3_FORCED_DAC_GAIN_3_SET(dac_gain) | PHY_BB_TPC_11_B3_FORCED_PA_CFG_3_SET(pa_setting) |
               PHY_BB_TPC_11_B3_FORCED_TXGAIN_IDX_3_SET(gain_idx));
    OS_REG_WRITE(PHY_BB_TPC_11_B3_ADDRESS, reg32);
#endif
    return;

}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void , use_forced_txgain_idx, A_UINT8 , A_INT8 , A_UINT8 );
extern void  use_forced_txgain_idx(A_UINT8 pa_setting, A_INT8 dac_gain, A_UINT8 gain_idx);
