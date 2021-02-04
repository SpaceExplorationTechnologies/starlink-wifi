/*
 * (C) Copyright 2001
 * Gerald Van Baren, Custom IDEAS, vanbaren@cideas.com
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 * MII Utilities
 */

#include <common.h>
#include <command.h>

#ifdef CONFIG_ATH_NAND_BR
#include <nand.h>
#endif

#ifndef COMPRESSED_UBOOT
#if (CONFIG_COMMANDS & CFG_CMD_MII)
#include <miiphy.h>

#ifdef CONFIG_TERSE_MII
/*
 * Display values from last command.
 */
uint last_op;
uint last_addr;
uint last_data;
uint last_reg;

/*
 * MII device/info/read/write
 *
 * Syntax:
 *  mii device {devname}
 *  mii info   {addr}
 *  mii read   {addr} {reg}
 *  mii write  {addr} {reg} {data}
 */
int do_mii (cmd_tbl_t * cmdtp, int flag, int argc, char *argv[])
{
	char		op;
	unsigned char	addr, reg;
	unsigned short	data;
	int		rcode = 0;
	char		*devname;

#if defined(CONFIG_8xx) || defined(CONFIG_MCF52x2)
	mii_init ();
#endif

	/*
	 * We use the last specified parameters, unless new ones are
	 * entered.
	 */
	op   = last_op;
	addr = last_addr;
	data = last_data;
	reg  = last_reg;

	if ((flag & CMD_FLAG_REPEAT) == 0) {
		op = argv[1][0];
		if (argc >= 3)
			addr = simple_strtoul (argv[2], NULL, 16);
		if (argc >= 4)
			reg  = simple_strtoul (argv[3], NULL, 16);
		if (argc >= 5)
			data = simple_strtoul (argv[4], NULL, 16);
	}

	/* use current device */
	devname = miiphy_get_current_dev();

	/*
	 * check device/read/write/list.
	 */
	if (op == 'i') {
		unsigned char j, start, end;
		unsigned int oui;
		unsigned char model;
		unsigned char rev;

		/*
		 * Look for any and all PHYs.  Valid addresses are 0..31.
		 */
		if (argc >= 3) {
			start = addr; end = addr + 1;
		} else {
			start = 0; end = 31;
		}

		for (j = start; j < end; j++) {
			if (miiphy_info (devname, j, &oui, &model, &rev) == 0) {
				printf ("PHY 0x%02X: "
					"OUI = 0x%04X, "
					"Model = 0x%02X, "
					"Rev = 0x%02X, "
					"%3dbaseT, %s\n",
					j, oui, model, rev,
					miiphy_speed (devname, j),
					(miiphy_duplex (devname, j) == FULL)
						? "FDX" : "HDX");
			} else {
				puts ("Error reading info from the PHY\n");
			}
		}
	} else if (op == 'r') {
		if (miiphy_read (devname, addr, reg, &data) < 0) {
			puts ("Error reading from the PHY\n");
			rcode = 1;
		} else {
			printf ("%04X\n", data & 0x0000FFFF);
		}
	} else if (op == 'w') {
		if (miiphy_write (devname, addr, reg, data) != 0) {
			puts ("Error writing to the PHY\n");
			rcode = 1;
		}
	} else if (op == 'd') {
		if (argc == 2)
			miiphy_listdev ();
		else
			miiphy_set_current_dev (argv[2]);
	} else {
		printf ("Usage:\n%s\n", cmdtp->usage);
		return 1;
	}

	/*
	 * Save the parameters for repeats.
	 */
	last_op = op;
	last_addr = addr;
	last_data = data;
	last_reg = reg;

	return rcode;
}

/***************************************************/

U_BOOT_CMD(
	mii,	5,	1,	do_mii,
	"mii     - MII utility commands\n",
	"device                     - list available devices\n"
	"mii device <devname>           - set current device\n"
	"mii info   <addr>              - display MII PHY info\n"
	"mii read   <addr> <reg>        - read  MII PHY <addr> register <reg>\n"
	"mii write  <addr> <reg> <data> - write MII PHY <addr> register <reg>\n"
);

#else /* ! CONFIG_TERSE_MII ================================================= */

typedef struct _MII_reg_desc_t {
	ushort regno;
	char * name;
} MII_reg_desc_t;

MII_reg_desc_t reg_0_5_desc_tbl[] = {
	{ 0,   "PHY control register"                },
	{ 1,   "PHY status register"                 },
	{ 2,   "PHY ID 1 register"                   },
	{ 3,   "PHY ID 2 register"                   },
	{ 4,   "Autonegotiation advertisement register" },
	{ 5,   "Autonegotiation partner abilities register" },
};

typedef struct _MII_field_desc_t {
	ushort hi;
	ushort lo;
	ushort mask;
	char * name;
} MII_field_desc_t;

MII_field_desc_t reg_0_desc_tbl[] = {
	{ 15, 15, 0x01, "reset"                        },
	{ 14, 14, 0x01, "loopback"                     },
	{ 13,  6, 0x81, "speed selection"              }, /* special */
	{ 12, 12, 0x01, "A/N enable"                   },
	{ 11, 11, 0x01, "power-down"                   },
	{ 10, 10, 0x01, "isolate"                      },
	{  9,  9, 0x01, "restart A/N"                  },
	{  8,  8, 0x01, "duplex"                       }, /* special */
	{  7,  7, 0x01, "collision test enable"        },
	{  5,  0, 0x3f, "(reserved)"                   }
};

MII_field_desc_t reg_1_desc_tbl[] = {
	{ 15, 15, 0x01, "100BASE-T4 able"              },
	{ 14, 14, 0x01, "100BASE-X  full duplex able"  },
	{ 13, 13, 0x01, "100BASE-X  half duplex able"  },
	{ 12, 12, 0x01, "10 Mbps    full duplex able"  },
	{ 11, 11, 0x01, "10 Mbps    half duplex able"  },
	{ 10, 10, 0x01, "100BASE-T2 full duplex able"  },
	{  9,  9, 0x01, "100BASE-T2 half duplex able"  },
	{  8,  8, 0x01, "extended status"              },
	{  7,  7, 0x01, "(reserved)"                   },
	{  6,  6, 0x01, "MF preamble suppression"      },
	{  5,  5, 0x01, "A/N complete"                 },
	{  4,  4, 0x01, "remote fault"                 },
	{  3,  3, 0x01, "A/N able"                     },
	{  2,  2, 0x01, "link status"                  },
	{  1,  1, 0x01, "jabber detect"                },
	{  0,  0, 0x01, "extended capabilities"        },
};

MII_field_desc_t reg_2_desc_tbl[] = {
	{ 15,  0, 0xffff, "OUI portion"                },
};

MII_field_desc_t reg_3_desc_tbl[] = {
	{ 15, 10, 0x3f, "OUI portion"                },
	{  9,  4, 0x3f, "manufacturer part number"   },
	{  3,  0, 0x0f, "manufacturer rev. number"   },
};

MII_field_desc_t reg_4_desc_tbl[] = {
	{ 15, 15, 0x01, "next page able"               },
	{ 14, 14, 0x01, "reserved"                     },
	{ 13, 13, 0x01, "remote fault"                 },
	{ 12, 12, 0x01, "reserved"                     },
	{ 11, 11, 0x01, "asymmetric pause"             },
	{ 10, 10, 0x01, "pause enable"                 },
	{  9,  9, 0x01, "100BASE-T4 able"              },
	{  8,  8, 0x01, "100BASE-TX full duplex able"  },
	{  7,  7, 0x01, "100BASE-TX able"              },
	{  6,  6, 0x01, "10BASE-T   full duplex able"  },
	{  5,  5, 0x01, "10BASE-T   able"              },
	{  4,  0, 0x1f, "xxx to do"                    },
};

MII_field_desc_t reg_5_desc_tbl[] = {
	{ 15, 15, 0x01, "next page able"               },
	{ 14, 14, 0x01, "acknowledge"                  },
	{ 13, 13, 0x01, "remote fault"                 },
	{ 12, 12, 0x01, "(reserved)"                   },
	{ 11, 11, 0x01, "asymmetric pause able"        },
	{ 10, 10, 0x01, "pause able"                   },
	{  9,  9, 0x01, "100BASE-T4 able"              },
	{  8,  8, 0x01, "100BASE-X full duplex able"   },
	{  7,  7, 0x01, "100BASE-TX able"              },
	{  6,  6, 0x01, "10BASE-T full duplex able"    },
	{  5,  5, 0x01, "10BASE-T able"                },
	{  4,  0, 0x1f, "xxx to do"                    },
};

#define DESC0LEN (sizeof(reg_0_desc_tbl)/sizeof(reg_0_desc_tbl[0]))
#define DESC1LEN (sizeof(reg_1_desc_tbl)/sizeof(reg_1_desc_tbl[0]))
#define DESC2LEN (sizeof(reg_2_desc_tbl)/sizeof(reg_2_desc_tbl[0]))
#define DESC3LEN (sizeof(reg_3_desc_tbl)/sizeof(reg_3_desc_tbl[0]))
#define DESC4LEN (sizeof(reg_4_desc_tbl)/sizeof(reg_4_desc_tbl[0]))
#define DESC5LEN (sizeof(reg_5_desc_tbl)/sizeof(reg_5_desc_tbl[0]))

typedef struct _MII_field_desc_and_len_t {
	MII_field_desc_t * pdesc;
	ushort len;
} MII_field_desc_and_len_t;

MII_field_desc_and_len_t desc_and_len_tbl[] = {
	{ reg_0_desc_tbl, DESC0LEN },
	{ reg_1_desc_tbl, DESC1LEN },
	{ reg_2_desc_tbl, DESC2LEN },
	{ reg_3_desc_tbl, DESC3LEN },
	{ reg_4_desc_tbl, DESC4LEN },
	{ reg_5_desc_tbl, DESC5LEN },
};

static void dump_reg(
	ushort             regval,
	MII_reg_desc_t   * prd,
	MII_field_desc_and_len_t * pdl);

static int special_field(
	ushort regno,
	MII_field_desc_t * pdesc,
	ushort regval);

void MII_dump_0_to_5(
	ushort regvals[6],
	uchar reglo,
	uchar reghi)
{
	ulong i;

	for (i = 0; i < 6; i++) {
		if ((reglo <= i) && (i <= reghi))
			dump_reg(regvals[i], &reg_0_5_desc_tbl[i],
				&desc_and_len_tbl[i]);
	}
}

static void dump_reg(
	ushort             regval,
	MII_reg_desc_t   * prd,
	MII_field_desc_and_len_t * pdl)
{
	ulong i;
	ushort mask_in_place;
	MII_field_desc_t * pdesc;

	printf("%u.     (%04hx)                 -- %s --\n",
		prd->regno, regval, prd->name);

	for (i = 0; i < pdl->len; i++) {
		pdesc = &pdl->pdesc[i];

		mask_in_place = pdesc->mask << pdesc->lo;

		printf("  (%04hx:%04hx) %u.",
			mask_in_place,
			regval & mask_in_place,
			prd->regno);

		if (special_field(prd->regno, pdesc, regval)) {
		}
		else {
			if (pdesc->hi == pdesc->lo)
				printf("%2u   ", pdesc->lo);
			else
				printf("%2u-%2u", pdesc->hi, pdesc->lo);
			printf(" = %5u    %s",
				(regval & mask_in_place) >> pdesc->lo,
				pdesc->name);
		}
		printf("\n");

	}
	printf("\n");
}

/* Special fields:
** 0.6,13
** 0.8
** 2.15-0
** 3.15-0
** 4.4-0
** 5.4-0
*/

static int special_field(
	ushort regno,
	MII_field_desc_t * pdesc,
	ushort regval)
{
	if ((regno == 0) && (pdesc->lo == 6)) {
		ushort speed_bits = regval & PHY_BMCR_SPEED_MASK;
		printf("%2u,%2u =   b%u%u    speed selection = %s Mbps",
			6, 13,
			(regval >>  6) & 1,
			(regval >> 13) & 1,
			speed_bits == PHY_BMCR_1000_MBPS ? "1000" :
			speed_bits == PHY_BMCR_100_MBPS  ? "100" :
			speed_bits == PHY_BMCR_10_MBPS   ? "10" :
			"???");
		return 1;
	}

	else if ((regno == 0) && (pdesc->lo == 8)) {
		printf("%2u    = %5u    duplex = %s",
			pdesc->lo,
			(regval >>  pdesc->lo) & 1,
			((regval >> pdesc->lo) & 1) ? "full" : "half");
		return 1;
	}

	else if ((regno == 4) && (pdesc->lo == 0)) {
		ushort sel_bits = (regval >> pdesc->lo) & pdesc->mask;
		printf("%2u-%2u = %5u    selector = %s",
			pdesc->hi, pdesc->lo, sel_bits,
			sel_bits == PHY_ANLPAR_PSB_802_3 ?
				"IEEE 802.3" :
			sel_bits == PHY_ANLPAR_PSB_802_9 ?
				"IEEE 802.9 ISLAN-16T" :
			"???");
		return 1;
	}

	else if ((regno == 5) && (pdesc->lo == 0)) {
		ushort sel_bits = (regval >> pdesc->lo) & pdesc->mask;
		printf("%2u-%2u =     %u    selector = %s",
			pdesc->hi, pdesc->lo, sel_bits,
			sel_bits == PHY_ANLPAR_PSB_802_3 ?
				"IEEE 802.3" :
			sel_bits == PHY_ANLPAR_PSB_802_9 ?
				"IEEE 802.9 ISLAN-16T" :
			"???");
		return 1;
	}

	return 0;
}

char last_op[2];
uint last_data;
uint last_addr_lo;
uint last_addr_hi;
uint last_reg_lo;
uint last_reg_hi;

static void extract_range(
	char * input,
	unsigned char * plo,
	unsigned char * phi)
{
	char * end;
	*plo = simple_strtoul(input, &end, 16);
	if (*end == '-') {
		end++;
		*phi = simple_strtoul(end, NULL, 16);
	}
	else {
		*phi = *plo;
	}
}

/* ---------------------------------------------------------------- */
int do_mii (cmd_tbl_t * cmdtp, int flag, int argc, char *argv[])
{
	char		op[2];
	unsigned char	addrlo, addrhi, reglo, reghi;
	unsigned char	addr, reg;
	unsigned short	data;
	int		rcode = 0;
	char		*devname;

#ifdef CONFIG_8xx
	mii_init ();
#endif

	/*
	 * We use the last specified parameters, unless new ones are
	 * entered.
	 */
	op[0] = last_op[0];
	op[1] = last_op[1];
	addrlo = last_addr_lo;
	addrhi = last_addr_hi;
	reglo  = last_reg_lo;
	reghi  = last_reg_hi;
	data   = last_data;

	if ((flag & CMD_FLAG_REPEAT) == 0) {
		op[0] = argv[1][0];
		if (strlen(argv[1]) > 1)
			op[1] = argv[1][1];
		else
			op[1] = '\0';

		if (argc >= 3)
			extract_range(argv[2], &addrlo, &addrhi);
		if (argc >= 4)
			extract_range(argv[3], &reglo, &reghi);
		if (argc >= 5)
			data = simple_strtoul (argv[4], NULL, 16);
	}

	/* use current device */
	devname = miiphy_get_current_dev();

	/*
	 * check info/read/write.
	 */
	if (op[0] == 'i') {
		unsigned char j, start, end;
		unsigned int oui;
		unsigned char model;
		unsigned char rev;

		/*
		 * Look for any and all PHYs.  Valid addresses are 0..31.
		 */
		if (argc >= 3) {
			start = addrlo; end = addrhi;
		} else {
			start = 0; end = 31;
		}

		for (j = start; j <= end; j++) {
			if (miiphy_info (devname, j, &oui, &model, &rev) == 0) {
				printf("PHY 0x%02X: "
					"OUI = 0x%04X, "
					"Model = 0x%02X, "
					"Rev = 0x%02X, "
					"%3dbaseT, %s\n",
					j, oui, model, rev,
					miiphy_speed (devname, j),
					(miiphy_duplex (devname, j) == FULL)
						? "FDX" : "HDX");
			} else {
				puts ("Error reading info from the PHY\n");
			}
		}
	} else if (op[0] == 'r') {
		for (addr = addrlo; addr <= addrhi; addr++) {
			for (reg = reglo; reg <= reghi; reg++) {
				data = 0xffff;
				if (miiphy_read (devname, addr, reg, &data) < 0) {
					printf(
					"Error reading from the PHY addr=%02x reg=%02x\n",
						addr, reg);
					rcode = 1;
				} else {
					if ((addrlo != addrhi) || (reglo != reghi))
						printf("addr=%02x reg=%02x data=",
							(uint)addr, (uint)reg);
					printf("%04X\n", data & 0x0000FFFF);
				}
			}
			if ((addrlo != addrhi) && (reglo != reghi))
				printf("\n");
		}
	} else if (op[0] == 'w') {
		for (addr = addrlo; addr <= addrhi; addr++) {
			for (reg = reglo; reg <= reghi; reg++) {
				if (miiphy_write (devname, addr, reg, data) != 0) {
					printf("Error writing to the PHY addr=%02x reg=%02x\n",
						addr, reg);
					rcode = 1;
				}
			}
		}
	} else if (strncmp(op, "du", 2) == 0) {
		ushort regs[6];
		int ok = 1;
		if ((reglo > 5) || (reghi > 5)) {
			printf(
				"The MII dump command only formats the "
				"standard MII registers, 0-5.\n");
			return 1;
		}
		for (addr = addrlo; addr <= addrhi; addr++) {
			for (reg = reglo; reg < reghi + 1; reg++) {
				if (miiphy_read(devname, addr, reg, &regs[reg]) < 0) {
					ok = 0;
					printf(
					"Error reading from the PHY addr=%02x reg=%02x\n",
						addr, reg);
					rcode = 1;
				}
			}
			if (ok)
				MII_dump_0_to_5(regs, reglo, reghi);
			printf("\n");
		}
	} else if (strncmp(op, "de", 2) == 0) {
		if (argc == 2)
			miiphy_listdev ();
		else
			miiphy_set_current_dev (argv[2]);
	} else {
		printf("Usage:\n%s\n", cmdtp->usage);
		return 1;
	}

	/*
	 * Save the parameters for repeats.
	 */
	last_op[0] = op[0];
	last_op[1] = op[1];
	last_addr_lo = addrlo;
	last_addr_hi = addrhi;
	last_reg_lo  = reglo;
	last_reg_hi  = reghi;
	last_data    = data;

	return rcode;
}

/***************************************************/

U_BOOT_CMD(
	mii,	5,	1,	do_mii,
	"mii     - MII utility commands\n",
	"device                     - list available devices\n"
	"mii device <devname>           - set current device\n"
	"mii info   <addr>              - display MII PHY info\n"
	"mii read   <addr> <reg>        - read  MII PHY <addr> register <reg>\n"
	"mii write  <addr> <reg> <data> - write MII PHY <addr> register <reg>\n"
	"mii dump   <addr> <reg>        - pretty-print <addr> <reg> (0-5 only)\n"
	"Addr and/or reg may be ranges, e.g. 2-7.\n"
);

#endif /* CONFIG_TERSE_MII */
#endif /* CFG_CMD_MII */
#endif /* #ifndef COMPRESSED_UBOOT */

#ifdef BOARDCAL
extern flash_info_t flash_info[];	/* info for FLASH chips */

/**********************************************************************************
** do_mac_setting
**
** This is the executable portion of the progmac command.  This will process the
** MAC address strings, and program them into the appropriate flash sector..
**
*/
#ifdef CONFIG_ATH_NAND_BR

#define ATH_NAND_NAND_PART              "ath-nand"


unsigned long long
ath_nand_get_cal_offset(const char *ba)
{
        char *mtdparts = NULL, ch, *pn, *end;
        unsigned long long off = 0, size;
	if (ba)
		mtdparts = strstr(ba, ATH_NAND_NAND_PART);
        if (!mtdparts) {
                goto bad;
        }
        mtdparts = strstr(mtdparts, ":");
        if (!mtdparts) {
                goto bad;
        }
        end = strstr(mtdparts, " ");
        if (!end) {
                end = mtdparts + strlen(mtdparts);
        }

        for (;mtdparts && mtdparts < end;) {
                mtdparts ++;
                size = simple_strtoul(mtdparts, &mtdparts, 0);
                ch = *mtdparts;
                switch (ch) {
                case 'g': case 'G': size = size * 1024;
                case 'm': case 'M': size = size * 1024;
                case 'k': case 'K': size = size * 1024;
                }
                pn = mtdparts + 2;
                if (strncmp(pn, ATH_CAL_NAND_PARTITION,
                        sizeof(ATH_CAL_NAND_PARTITION) - 1) == 0) {
                        return off;
                }
                off += size;
                mtdparts = strstr(mtdparts, ",");
        }

bad:
        return ATH_CAL_OFF_INVAL;
}

/**********************************************************************************
** do_mac_setting
**
** This is the executable portion of the progmac command.  This will process the
** MAC address strings, and program them into the appropriate flash sector..
**
*/

int do_mac (cmd_tbl_t * cmdtp, int flag, int argc, char *argv[])
{
	char    sectorBuff[256*1024];
	int     serno;
	int     product_id;
	int     ret;
	ulong   off, size;
	nand_info_t *nand;
	char 	*p;
		
	/* 
	 * caldata partition is of 128k 
	 *
	 */
	nand = &nand_info[nand_curr_device];
	size = nand->erasesize;
	/*
	 * Argv[1] contains the value string.  Convert to binary, and
	 * program the values in flash
	 */

	serno = simple_strtoul(argv[1],0,10);

	/*
	 * If the serial number is less than 0, or greater than
	 * 0x1fff, it's out of range
	 */

	if(serno < 0 || serno > 0x1fff) {
		printf("Serno out of range\n",serno);
		return 1;
	}

    if (argc > 2) {
        product_id = simple_strtoul(argv[2], 0, 10);
    } else {
        product_id = ATHEROS_PRODUCT_ID;
    } 

	if(product_id < 0 || product_id > 0x7ff) {
		printf("product id out of range %d\n", product_id);
		return 1;
	}

	/*
	 * Create the 24 bit number that composes the lower 3 bytes of
	 * the MAC address
	 */

	serno = 0xFFFFFF & ( (product_id << 13) | (serno & 0x1fff));

	p = getenv("bootargs");
	if (p == NULL) {
		printf("No bootargs\n");
		return 1;
	}
	/*
	 * Get the Offset of Caldata partition
	 */
	off = ath_nand_get_cal_offset(p);
	if(off == ATH_CAL_OFF_INVAL) {
		printf("Invalid CAL offset \n");
		return 1;
	}
	
         
	/*
	 * Get the values from flash, and program into the MAC address
	 * registers
	 */
	ret = nand_read(nand, (loff_t)off, &size, (u_char *)sectorBuff);
	printf(" %d bytes %s: %s\n", size,
		       "read", ret ? "ERROR" : "OK");
	if(ret != 0 ) {
		return 1;
	}
	
	/*
	 * Set the first and second values
	 */

	sectorBuff[0] = 0x00;
	sectorBuff[1] = 0x03;
	sectorBuff[2] = 0x7f;

	sectorBuff[3] = 0xFF & (serno >> 16);
	sectorBuff[4] = 0xFF & (serno >> 8);
	sectorBuff[5] = 0xFF &  serno;

	/*
	 * Increment by 1 for the second MAC address
	 */

	serno++;
	memcpy(&sectorBuff[6],&sectorBuff[0],3);
	sectorBuff[9]  = 0xFF & (serno >> 16);
	sectorBuff[10] = 0xFF & (serno >> 8);
	sectorBuff[11] = 0xFF &  serno;
	
	ret = nand_erase(nand,(loff_t)off, size);
	printf(" %d bytes %s: %s\n", size,
		       "erase", ret ? "ERROR" : "OK");

	if(ret != 0 ) {
		return 1;
	}

	ret = nand_write(nand, (loff_t)off, &size, (u_char *)sectorBuff);
	printf(" %d bytes %s: %s\n", size,
		       "write", ret ? "ERROR" : "OK");
	if(ret != 0 ) {
		return 1;
	}

	return 0;
}
#else /*CONFIG_ATH_NAND_BR */

int do_mac (cmd_tbl_t * cmdtp, int flag, int argc, char *argv[])
{
	char    sectorBuff[CFG_FLASH_SECTOR_SIZE];
	int     serno;
	int     product_id;

	/*
	 * Argv[1] contains the value string.  Convert to binary, and
	 * program the values in flash
	 */

	serno = simple_strtoul(argv[1],0,10);

	/*
	 * If the serial number is less than 0, or greater than
	 * 0x1fff, it's out of range
	 */

	if(serno < 0 || serno > 0x1fff) {
		printf("Serno out of range\n",serno);
		return 1;
	}

    if (argc > 2) {
        product_id = simple_strtoul(argv[2], 0, 10);
    } else {
        product_id = ATHEROS_PRODUCT_ID;
    } 

	if(product_id < 0 || product_id > 0x7ff) {
		printf("product id out of range %d\n", product_id);
		return 1;
	}

	/*
	 * Create the 24 bit number that composes the lower 3 bytes of
	 * the MAC address
	 */

	serno = 0xFFFFFF & ( (product_id << 13) | (serno & 0x1fff));

	/*
	 * Get the values from flash, and program into the MAC address
	 * registers
	 */

	memcpy(sectorBuff,(void *)BOARDCAL, CFG_FLASH_SECTOR_SIZE);

	/*
	 * Set the first and second values
	 */

	sectorBuff[0] = 0x00;
	sectorBuff[1] = 0x03;
	sectorBuff[2] = 0x7f;

	sectorBuff[3] = 0xFF & (serno >> 16);
	sectorBuff[4] = 0xFF & (serno >> 8);
	sectorBuff[5] = 0xFF &  serno;

	/*
	 * Increment by 1 for the second MAC address
	 */

	serno++;
	memcpy(&sectorBuff[6],&sectorBuff[0],3);
	sectorBuff[9]  = 0xFF & (serno >> 16);
	sectorBuff[10] = 0xFF & (serno >> 8);
	sectorBuff[11] = 0xFF &  serno;

	flash_erase(flash_info,CAL_SECTOR,CAL_SECTOR);
	write_buff(flash_info,sectorBuff, BOARDCAL, CFG_FLASH_SECTOR_SIZE);

	return 0;
}
#endif /*CONFIG_ATH_NAND_BR */

U_BOOT_CMD(
    progmac, 3, 0, do_mac,
    "progmac - Set ethernet MAC addresses\n",
    "progmac <serno> [<product_id>] - Program the MAC addresses\n"
    "                <serno> is the value of the last\n"
    "                4 digits (decimal) of the serial number.\n"
    "                Optional parameter <product_id> specifies\n"
    "                the board's product ID (decimal)\n"
);

#ifdef CONFIG_ATH_NAND_BR
#define SECTOR_BUFF_SIZE 256*1024
#else
#define SECTOR_BUFF_SIZE CFG_FLASH_SECTOR_SIZE
#endif

static int process(char **s, u_char *val)
{
	char *p = *s;
	u_char x;

	if (*p == ':')
		p ++;

	if (*p >= '0' && *p <= '9')
		x = *p - '0';
	else if (*p >= 'a' && *p <= 'f')
		x = *p - 'a' + 10;
	else if (*p >= 'A' && *p <= 'F')
		x = *p - 'A' + 10;
	else return -1;

	x = x << 4;
	p ++;

	if (*p >= '0' && *p <= '9')
		x |= *p - '0';
	else if (*p >= 'a' && *p <= 'f')
		x |= *p - 'a' + 10;
	else if (*p >= 'A' && *p <= 'F')
		x |= *p - 'A' + 10;
	else return -1;

	*s = (p + 1);
	*val = x;

	return 0;
}

typedef union {
	uint8_t		b[6];
	uint64_t	m;
	uint32_t	w[2];
} ath_mac_addr_t;

static int str_to_mac(char *s, ath_mac_addr_t *m)
{
	ath_mac_addr_t mac;
	int i;

	mac.m = 0;

	for (i = 0; i < sizeof(mac.b) && *s; i++) {
		if (process(&s, &mac.b[i])) {
			return -1;
		}
	}

	if (i != sizeof(mac.b)) {
		return -1;
	}

	printf("%02x:%02x:%02x:%02x:%02x:%02x\n", mac.b[0], mac.b[1], mac.b[2], mac.b[3], mac.b[4], mac.b[5]);
	printf("%x %x\n", mac.w[0], mac.w[1]);

	*m = mac;

	return 0;
}

/**********************************************************************************
** do_mac_setting
**
** This is the executable portion of the progmac command.  This will process the
** MAC address strings, and program them into the appropriate flash sector..
**
*/

int do_mac2 (cmd_tbl_t * cmdtp, int flag, int argc, char *argv[])
{
	char    sectorBuff[SECTOR_BUFF_SIZE];
	ath_mac_addr_t mac0, mac1;
#ifdef CONFIG_ATH_NAND_BR
	int     ret;
	ulong   off, size;
	nand_info_t *nand;
	char *p;
		
	/* 
	 * caldata partition is of 128k 
	 *
	 */
	nand = &nand_info[nand_curr_device];
	size = nand->erasesize;
#endif

	if (argc < 3) {
		printf ("Usage:\n%s\n", cmdtp->usage);
		printf ("progmac2 <eth0 mac> <eth1 mac>\n");
		return 1;
	}

	if (str_to_mac(argv[1], &mac0)) {
		printf("eth0 mac is invalid\n");
		return 1;
	}

	if (str_to_mac(argv[2], &mac1)) {
		printf("eth1 mac is invalid\n");
		return 1;
	}
	
#ifdef CONFIG_ATH_NAND_BR

	p = getenv("bootargs");
	if (p == NULL) {
		printf("No bootargs\n");
		return 1;
	}

	/*
	 * Get the Offset of Caldata partition
	 */
	off = ath_nand_get_cal_offset(p);
	if(off == ATH_CAL_OFF_INVAL) {
		printf("Invalid CAL offset \n");
		return 1;
	}
	
         
	/*
	 * Get the values from flash, and program into the MAC address
	 * registers
	 */
	ret = nand_read(nand, (loff_t)off, &size, (u_char *)sectorBuff);
	printf(" %d bytes %s: %s\n", size,
		       "read", ret ? "ERROR" : "OK");
	if(ret != 0 ) {
		return 1;
	}
#else
	memcpy(sectorBuff,(void *)BOARDCAL, CFG_FLASH_SECTOR_SIZE);
#endif
	
	/*
	 * Set the MAC0 value
	 */
	
	memcpy(&sectorBuff[0],&mac0.b[0],6);

	/*
	 * Set the MAC1 value
	 */

	memcpy(&sectorBuff[6],&mac1.b[0],6);
	
#ifdef CONFIG_ATH_NAND_BR
	ret = nand_erase(nand,(loff_t)off, size);
	printf(" %d bytes %s: %s\n", size,
		       "erase", ret ? "ERROR" : "OK");

	if(ret != 0 ) {
		return 1;
	}

	ret = nand_write(nand, (loff_t)off, &size, (u_char *)sectorBuff);
	printf(" %d bytes %s: %s\n", size,
		       "write", ret ? "ERROR" : "OK");
	if(ret != 0 ) {
		return 1;
	}
#else
	flash_erase(flash_info,CAL_SECTOR,CAL_SECTOR);
	write_buff(flash_info,sectorBuff, BOARDCAL, CFG_FLASH_SECTOR_SIZE);
#endif

	return 0;
}

U_BOOT_CMD(
    progmac2, 3, 0, do_mac2,
    "progmac2 - Set ethernet MAC addresses\n",
    "progmac2 <eth0 mac> <eth1 mac> - Program the MAC addresses\n"
    "                  <eth0 mac> is the eth0 MAC address\n"
    "                  <eth1 mac> is the eth1 MAC address\n"
    "                  MAC address can be in the format\n"
    "                  <aa:bb:cc:dd:ee:ff> or <aabbccddeeff>\n"
);
#endif /* BOARDCAL */

