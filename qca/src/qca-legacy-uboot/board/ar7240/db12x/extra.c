/* 
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 * 
 */

#include <common.h>
#include <command.h>
#include <asm/mipsregs.h>
#include <asm/addrspace.h>
#include <config.h>
#include <version.h>
#include "ar7240_soc.h"

#ifdef CONFIG_ATH_NAND_BR
#include <nand.h>
#endif

#ifdef CONFIG_ATH_NAND_BR
void *
ath_get_nand_cal_data(void)
{
        ulong           off,size;
        int             ret;
        static u_char   nand_cal_data[256 * 1024];
        nand_info_t *nand;

         /*
          * caldata partition is of 128k
          *
          */
        nand = &nand_info[nand_curr_device];
        size = nand->erasesize;

        /*
         * Get the Offset of Caldata partition
         */
        off = ath_nand_get_cal_offset(getenv("bootargs"));
        if(off == ATH_CAL_OFF_INVAL) {
                printf("Invalid CAL offset \n");
                return 1;
        }

        /*
         * Get the values from flash, and program into the MAC address
         * registers
         */
        ret = nand_read(nand, (loff_t)off, &size, nand_cal_data);
        printf(" %d bytes %s: %s\n", size,
                        "read", ret ? "ERROR" : "OK");
        if(ret != 0 ) {
                return NULL;
        }

        return nand_cal_data;
}
#endif

void ath_set_tuning_caps(void)
{
	typedef struct {
		u_int8_t	pad[0x28],
				params_for_tuning_caps[2],
				featureEnable;
	} __attribute__((__packed__)) ar9300_eeprom_t;

	ar9300_eeprom_t	*eep;
	uint32_t	val;

#ifdef CONFIG_ATH_NAND_BR
        eep = (ar9300_eeprom_t *)ath_get_nand_cal_data();
#else
        eep = (ar9300_eeprom_t *)WLANCAL;
#endif /* CONFIG_ATH_NAND_BR */

	val = 0;
	/* checking feature enable bit 6 and caldata is valid */
	if ((eep->featureEnable & 0x40) && (eep->pad[0x0] != 0xff)) {
		/* xtal_capin -bit 17:23 and xtag_capout -bit 24:30*/
		val = (eep->params_for_tuning_caps[0] & 0x7f) << 17;
		val |= (eep->params_for_tuning_caps[0] & 0x7f) << 24;
	} else {
		/* default when no caldata available*/
		/* checking clock in bit 4 */
		if (ar7240_reg_rd(RST_BOOTSTRAP_ADDRESS) & 0x10) {
			val = (0x1020 << 17);  /*default 0x2040 for 40Mhz clock*/
		} else {
			val = (0x2040 << 17); /*default 0x4080 for 25Mhz clock*/
		}
	}
	val |= (ar7240_reg_rd(XTAL_ADDRESS) & (((1 << 17) - 1) | (1 << 31)));
	ar7240_reg_wr(XTAL_ADDRESS, val);
	printf("Setting 0xb8116290 to 0x%x\n", val);
	return;
}
