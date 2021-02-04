/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//
// Copyright (c) 2010 Atheros Communications Inc.
// All rights reserved.
// $ATH_LICENSE_TARGET_C$
//

#include "osapi.h"
#if defined(AR6004)
#include "hw/bb_lc_reg.h"
#include "hw/analog_intf_athr_wlan_reg.h"
#endif

/*
 * This mini application is rolled into the ram.fw.bin image in order
 * to handle small initialization/setup details prior to loading and
 * running athwlan.
 */

#if defined(AR6004)
/* Values used to program PLLs through the SRIF. */
struct pll_val_t {
    A_UINT32 pll_dpll_val;
    A_UINT32 pll_dpll2_val;
};
#endif

LOCAL struct cmnos_clock_s {
    A_refclk_speed_t refclk_speed;
    A_UINT32         ticks_per_sec;
    A_UINT32         pll_settling_time;      /* 50us */
#if defined(AR6002_REV4)
    A_UINT32         pll_ctrl_24ghz;
    A_UINT32         pll_ctrl_5ghz;
#endif
#if defined(AR6002_REV6)
    struct pll_val_t    bb_pll[A_NUM_BANDS];
    struct pll_val_t    cpu_pll[AR6K_CPU_SPEEDS];
#endif
};

extern struct cmnos_clock_s cmnos_clocking_table[];
extern int cmnos_cpu_speed;
extern int cmnos_cpu_speed_index;

#define CMNOS_CLOCKING_TABLE_NUM_ENTRIES 7

void
utfsetup_main(void)
{


#if defined(A_CONFIG_SWITCHABLE_RAM)
    A_UINT32 switchable_iram_banks = 1;
    A_CONFIG_SWITCHABLE_RAM((char *)(TARG_SWITCHABLE_IRAM_START + switchable_iram_banks*AR6K_SWITCHABLE_RAM_BANK_SZ - 1));
#endif

#if !defined(FPGA)
#if defined(AR6002_REV61)
    {
        A_INT32 i, j;
        /* Run the CPU at 160 MHz */
        cmnos_cpu_speed_index = AR6K_CPU_SPEED_160MHZ;
        cmnos_cpu_speed = 160000000;

        /* Set the range bit for CPU and BB pll */
        for (i = 0; i < CMNOS_CLOCKING_TABLE_NUM_ENTRIES; i++)
        {
            for(j=0;j<AR6K_CPU_SPEEDS;j++)
            {
                cmnos_clocking_table[i].cpu_pll[j].pll_dpll2_val |= PHY_ANALOG_CPU_PLL_DPLL2_RANGE_MASK;
            }
            cmnos_clocking_table[i].bb_pll[A_BAND_24GHZ].pll_dpll2_val |= PHY_ANALOG_BB_PLL_DPLL2_RANGE_MASK;
            cmnos_clocking_table[i].bb_pll[A_BAND_5GHZ].pll_dpll2_val |= PHY_ANALOG_BB_PLL_DPLL2_RANGE_MASK;
        }
        /* Reserve the space at the end needed for patch and board data and test script */
        HOST_INTEREST->hi_end_RAM_reserve_sz = AR6004_REV1_RAM_RESERVE_SIZE + AR6004_REV1_RAM_RESERVE_SIZE_FOR_TEST_SCRIPT;
        HOST_INTEREST->hi_dset_list_head = AR6004_REV1_DATASET_PATCH_ADDRESS;
        //HOST_INTEREST->hi_ota_testscript = AR6004_REV1_TEST_SCRIPT_ADDRESS;
    }
#endif /* AR6002_REV61 */
#endif /* FPGA */
}
