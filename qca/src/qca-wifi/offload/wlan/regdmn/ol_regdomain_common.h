/*
 * Copyright (c) 2011, 2017 Qualcomm Innovation Center, Inc.
 *
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Innovation Center, Inc.
 *
 * Copyright (c) 2010, Atheros Communications Inc. 
 * All Rights Reserved.
 * 
 * 2011 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * 
 *
 * This module contains the common regulatory domain database tables:
 * 	
 * 	- reg domain enum constants
 *	- reg domain enum to reg domain pair mappings
 * 	- country to regdomain mappings
 *	- channel tag enums and the frequency-to-frequency band mappings 
 *	  for all the modes
 *
 * "The country table and respective Regulatory Domain channel and power
 * settings are based on available knowledge as of software release. The
 * underlying global regulatory and spectrum rules change on a regular basis,
 * therefore, no warranty is given that the channel and power information
 * herein is complete, accurate or up to date.  Developers are responsible
 * for regulatory compliance of end-products developed using the enclosed
 * data per all applicable national requirements.  Furthermore, data in this
 * table does not guarantee that spectrum is available and that regulatory
 * approval is possible in every case. Knowldegable regulatory compliance
 * or government contacts should be consulted by the manufacturer to ensure
 * that the most current and accurate settings are used in each end-product.
 * This table was designed so that developers are able to update the country
 * table mappings as well as the Regulatory Domain definitions in order to
 * incorporate the most current channel and power settings in the end-product."
 *
 */

/* Enumerated Regulatory Domain Information 8 bit values indicate that
 * the regdomain is really a pair of unitary regdomains.  12 bit values
 * are the real unitary regdomains and are the only ones which have the
 * frequency bitmasks and flags set.
 */

enum EnumRd {
	/*
	 * The following regulatory domain definitions are
	 * found in the EEPROM. Each regulatory domain
	 * can operate in either a 5GHz or 2.4GHz wireless mode or
	 * both 5GHz and 2.4GHz wireless modes.
	 * In general, the value holds no special
	 * meaning and is used to decode into either specific
	 * 2.4GHz or 5GHz wireless mode for that particular
	 * regulatory domain.
	 */
	NO_ENUMRD	= 0x00,
    OVERRIDE_RD = 0x01,
	NULL1_WORLD	= 0x03,		/* For 11b-only countries (no 11a allowed) */
	NULL1_ETSIB	= 0x07,		/* Israel */
	NULL1_ETSIC	= 0x08,
	FCC1_FCCA	= 0x10,		/* USA */
	FCC1_WORLD	= 0x11,		/* Hong Kong */
	FCC4_FCCA	= 0x12,		/* USA - Public Safety */
	FCC5_FCCA	= 0x13,		/* US with no DFS (UNII-1 + UNII-3 Only)*/
	FCC6_FCCA	= 0x14,		/* Canada for AP only*/
	FCC7_FCCA	= 0x15,		/* For Cisco Use*/
	FCC8_FCCA	= 0x16,		/* U.S. APs with TDWR */
    FCC9_FCCA   = 0x17,     /* STA with DSRC */
    FCC10_FCCA  = 0x18,     /* AP with DSRC */
    FCC11_WORLD = 0x19,     /* Malaysia */
    
	FCC2_FCCA	= 0x20,		/* Canada */
	FCC2_WORLD	= 0x21,		/* Australia & HK */
	FCC2_ETSIC	= 0x22,
	FCC6_WORLD	= 0x23,		/* Australia for AP only*/
	FRANCE_RES	= 0x31,		/* Legacy France for OEM */
	FCC3_FCCA	= 0x3A,		/* USA & Canada w/5470 band, 11h, DFS enabled */
	FCC3_WORLD	= 0x3B,		/* USA & Canada w/5470 band, 11h, DFS enabled */
	FCC3_ETSIC	= 0x3F,		/* New Zealand, DFS enabled */ 
	FCC14_FCCB	= 0xE6,		/* Panama */
	FCC13_WORLD	= 0xE4,		/* Honduras, Jamaica, Senegal for LA */

	ETSI1_WORLD	= 0x37,
	ETSI3_ETSIA	= 0x32,		/* France (optional) */
	ETSI2_WORLD	= 0x35,		/* Hungary & others */
	ETSI3_WORLD	= 0x36,		/* France & others */
	ETSI4_WORLD	= 0x30,
	ETSI4_ETSIC	= 0x38,
	ETSI5_WORLD	= 0x39,
	ETSI6_WORLD	= 0x34,		/* Bulgaria */
	ETSI8_WORLD	= 0x3D,		/* Russia */
	ETSI9_WORLD	= 0x3E,		/* Ukraine */
	ETSI11_WORLD	= 0x26,
	ETSI12_WORLD	= 0x28,		/* United Kingdom */
	ETSI13_WORLD	= 0x27,
	ETSI14_WORLD	= 0x29,
	ETSI_RESERVED	= 0x33,		/* Reserved (Do not used) */

	APL4_WORLD	= 0x42,		/* Singapore and Morocco */
	APL_RESERVED	= 0x44,		/* Reserved (Do not used)  */
	APL2_WORLD	= 0x45,		/* Korea */
	APL2_APLC	= 0x46,
	APL3_WORLD	= 0x47,
	APL2_APLD	= 0x49,		/* Korea with 2.3G channels */
	APL2_FCCA	= 0x4D,		/* Mobile customer */
	APL11_FCCA	= 0x4F,         /* Specific AP Customer 5GHz, For APs Only */

	APL3_FCCA   = 0x50,
	APL12_WORLD	= 0x51,
	APL1_WORLD	= 0x52,		/* Latin America */
	APL1_FCCA	= 0x53,
	APL1_APLA	= 0x54,
	APL1_ETSIC	= 0x55,
	APL2_ETSIC	= 0x56,		/* Venezuela */
	APL14_WORLD	= 0x57,		/* China */
	APL5_WORLD	= 0x58,		/* Chile */
	APL15_WORLD	= 0x59,		/* India & Bahrain */
	APL16_WORLD	= 0x70,		/* Argentina AP without DFS */
	APL13_WORLD	= 0x5A,     	/* Algeria */
	APL6_WORLD	= 0x5B,		/* Singapore */
	APL7_FCCA   = 0x5C,     /* Taiwan 5.47 Band */
	APL8_WORLD  = 0x5D,     /* Malaysia 5GHz */
	APL9_WORLD  = 0x5E,     /* Korea-APs & STAs*/
	APL10_WORLD = 0x5F,     /* Saint Kitts & Nevis */
	APL20_WORLD = 0xE5,     /* Namibia for LA */
	APL23_WORLD = 0xE3,     /* Chile, Nepal for LA */

	/*
	 * World mode SKUs
	 */
	WOR0_WORLD	= 0x60,		/* World0 (WO0 SKU) */
	WOR1_WORLD	= 0x61,		/* World1 (WO1 SKU) */
	WOR2_WORLD	= 0x62,		/* World2 (WO2 SKU) */
	WOR3_WORLD	= 0x63,		/* World3 (WO3 SKU) */
	WOR4_WORLD	= 0x64,		/* World4 (WO4 SKU) */	
	WOR5_ETSIC	= 0x65,		/* World5 (WO5 SKU) */    

	WOR01_WORLD	= 0x66,		/* World0-1 (WW0-1 SKU) */
	WOR02_WORLD	= 0x67,		/* World0-2 (WW0-2 SKU) */
	EU1_WORLD	= 0x68,		/* Same as World0-2 (WW0-2 SKU), except active scan ch1-13. No ch14 */

	WOR9_WORLD	= 0x69,		/* World9 (WO9 SKU) */	
	WORA_WORLD	= 0x6A,		/* WorldA (WOA SKU) */	
	WORB_WORLD	= 0x6B,		/* WorldB (WOB SKU) */	
	WORC_WORLD	= 0x6C,		/* WorldC (WOC SKU) */	

	APL19_ETSIC	= 0x71,		/* India with 5.9GHz support */

	MKK3_MKKC	= 0x82,		/* Japan UNI-1 even + MKKC */

	MKK5_MKKC	= 0x88,		/* Japan UNI-1 even + UNI-2 + mid-band + MKKC */
	MKK5_MKKA	= 0x99,

	MKK11_MKKC	= 0xD7,		/* Japan UNI-1 even + UNI-2 + mid-band + 4.9GHz + MKKC */

	MKK16_MKKC	= 0xDF, 	/* Japan Outdoor */

	/*
	 * Regulatory domains ending in a number (e.g. APL1,
	 * MK1, ETSI4, etc) apply to 5GHz channel and power
	 * information.  Regulator domains ending in a letter
	 * (e.g. APLA, FCCA, etc) apply to 2.4GHz channel and
	 * power information.
	 */
	APL1		= 0x0150,	/* LAT & Asia */
	APL2		= 0x0250,	/* LAT & Asia */
	APL3		= 0x0350,	/* Taiwan */
	APL4		= 0x0450,	/* Jordan */
	APL5		= 0x0550,	/* Chile */
	APL6		= 0x0650,	/* Singapore */
	APL7		= 0x0750,	/* Taiwan, disable ch52 */
	APL8		= 0x0850,	/* Malaysia */
	APL9		= 0x0950,	/* Korea-APs & STAs */
	APL10		= 0x1050,	/* Saint Kitts & Nevis */
	APL11		= 0x1150,	/* Specific AP Customer 5GHz, For APs Only */
	APL12		= 0x1160,	/* Kenya */
	APL13		= 0x1170,	/* Algeria */
	APL14		= 0x1180,	/* China */
	APL15		= 0x1190,	/* India & Bahrain */
	APL16		= 0x1200,	/* Argentina for AP */
	APL19		= 0x1240,	/* India with 5.9GHz support */
	APL20		= 0x1250,	/* Namibia */
	APL23		= 0x1280,	/* Chile, Nepal */

	ETSI1		= 0x0130,	/* Europe & others */
	ETSI2		= 0x0230,	/* Europe & others */
	ETSI3		= 0x0330,	/* Europe & others */
	ETSI4		= 0x0430,	/* Europe & others */
	ETSI5		= 0x0530,	/* Europe & others */
	ETSI6		= 0x0630,	/* Europe & others */
	ETSI8		= 0x0830,	/* Russia */
	ETSI9		= 0x0930,	/* Ukraine */
	ETSIA		= 0x0A30,	/* France */
	ETSIB		= 0x0B30,	/* Israel */
	ETSIC		= 0x0C30,	/* Latin America */
	ETSI10		= 0x0D30,	/* DSRC (10MHz channels) for Europe (includes ETSI1 for AP or STA) */
	ETSI11		= 0x0E30,	/* Europe EN 302 502 Fixed Access plus ETSI1 */
	ETSI12		= 0x0E38,	/* ETSI1 + EN302 502 FWA + Overlap channels for UK per 2030/8/3 */
	ETSI13		= 0x0E39,	/* Europe EN 300 440 Upper Band at low power plus ETSI1 */
	ETSI14		= 0x0E40,	/* Qatar */

	ETSID		= 0x0F30,

	FCC1		= 0x0110,	/* US & others */
	FCC2		= 0x0120,	/* Canada, Australia & New Zealand */
	FCC3		= 0x0160,	/* US w/new middle band & DFS */    
	FCC4		= 0x0165,	/* US Public Safety */
	FCC5		= 0x0510,     	   
	FCC6		= 0x0610,	/* Canada & Australia */
	FCC7		= 0x0710,	/* Same as FCC6 but with higher power */
        FCC8            = 0x0810,       /* US for APs with TDWR enabled */
	FCCA		= 0x0A10,	 
	FCC9		= 0x0910,	/* DSRC (10&20MHz channels) for N. America (includes FCC3 for STAs) */
	FCC10		= 0x0B10,	/* DSRC (10&20MHz channels) for N. America (includes FCC8 for APs) */
	FCC11		= 0x0B20,	/* Malaysia */
	FCC13		= 0x0B60,	/* Honduras, Senegal, Jamaica */
	FCC14		= 0x0B70,	/* Panama  */
	FCCB		= 0x0B90,	/* Panama  */

	APLD		= 0x0D50,	/* South Korea */

	MKK3		= 0x0340,	/* Japan (UNI-1 even) */
	MKK5		= 0x0540,	/* Japan (UNI-1 even + UNI-2 + mid-band) */
	MKK11		= 0x1140,	/* Japan (UNI-1 even + UNI-2 + 4.9 GHZ) */
	MKK16		= 0x1640,	/* Japan Outdoor Products */
	MKKA		= 0x0A40,	/* Japan */
	MKKC		= 0x0A50,

	NULL1		= 0x0198,
	WORLD		= 0x0199,
	DEBUG_REG_DMN	= 0x01ff,
    OVER1_OVERA = 0x0200,
};

enum {					/* conformance test limits */
	FCC	= 0x10,
	MKK	= 0x40,
	ETSI	= 0x30,
	CHN	= 0x60,
	KOR	= 0x50,
	USER_DEF	= 0x70,
};
/*
 * The following are flags for different requirements per reg domain.
 * These requirements are either inhereted from the reg domain pair or
 * from the unitary reg domain if the reg domain pair flags value is
 * 0
 */

enum {
	NO_REQ			= 0x00000000,
	DISALLOW_ADHOC_11A	= 0x00000001,
	DISALLOW_ADHOC_11A_TURB	= 0x00000002,
	NEED_NFC		= 0x00000004,

	ADHOC_PER_11D		= 0x00000008,  /* Start Ad-Hoc mode */
	ADHOC_NO_11A		= 0x00000010,

	PUBLIC_SAFETY_DOMAIN	= 0x00000020, 	/* public safety domain */
	LIMIT_FRAME_4MS 	= 0x00000040, 	/* 4msec limit on the frame length */

	NO_HOSTAP		= 0x00000080,	/* No HOSTAP mode opereation */

	REQ_MASK		= 0x000000FF,   /* Requirements bit mask */
};

/*
 * Mask indicating which requirement flags can be used for each band.
 * 11a Adhoc masks should not be applied to 2GHz channels.
 */
#define REG_DOMAIN_2GHZ_MASK    (REQ_MASK & \
                                    (! (ADHOC_NO_11A | DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB)))
#define REG_DOMAIN_5GHZ_MASK    REQ_MASK

static const REG_DMN_PAIR_MAPPING ahCmnRegDomainPairs[] = {
	{NO_ENUMRD,	DEBUG_REG_DMN,	DEBUG_REG_DMN, NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
    {OVERRIDE_RD,   OVER1_OVERA,    OVER1_OVERA,    NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{NULL1_WORLD,	NULL1,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{NULL1_ETSIB,	NULL1,		ETSIB,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{NULL1_ETSIC,	NULL1,		ETSIC,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },

	{FCC2_FCCA,     FCC2,		FCCA,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{FCC2_WORLD,    FCC2,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{FCC2_ETSIC,    FCC2,		ETSIC,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{FCC3_FCCA,     FCC3,		FCCA,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{FCC3_WORLD,    FCC3,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{FCC3_ETSIC,    FCC3,		ETSIC,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{FCC4_FCCA,     FCC4,		FCCA,		DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{FCC5_FCCA,     FCC5,		FCCA,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{FCC6_FCCA,     FCC6,		FCCA,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{FCC7_FCCA,     FCC7,		FCCA,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{FCC8_FCCA,     FCC8,		FCCA,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{FCC6_WORLD,    FCC6,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{FCC9_FCCA,     FCC9,		FCCA,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{FCC10_FCCA,    FCC10,		FCCA,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{FCC11_WORLD,   FCC11,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{FCC13_WORLD,   FCC13,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{FCC14_FCCB,    FCC14,		FCCB,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },

	{ETSI1_WORLD,	ETSI1,		WORLD,		DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{ETSI2_WORLD,	ETSI2,		WORLD,		DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{ETSI3_WORLD,	ETSI3,		WORLD,		DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{ETSI4_WORLD,	ETSI4,		WORLD,		DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{ETSI5_WORLD,	ETSI5,		WORLD,		DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{ETSI6_WORLD,	ETSI6,		WORLD,		DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
    {ETSI8_WORLD,	ETSI8,		WORLD,		DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{ETSI9_WORLD,	ETSI9,		WORLD,		DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{ETSI11_WORLD,	ETSI11,		WORLD,		DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{ETSI12_WORLD,	ETSI12,		WORLD,		DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{ETSI13_WORLD,	ETSI13,		WORLD,		DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{ETSI14_WORLD,	ETSI14,		WORLD,		DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },

	{ETSI3_ETSIA,	ETSI3,		WORLD,		DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{FRANCE_RES,	ETSI3,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },

	{FCC1_WORLD,	FCC1,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{FCC1_FCCA,	    FCC1,		FCCA,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL1_WORLD,	APL1,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL2_WORLD,	APL2,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL2_FCCA,	    APL2,		FCCA,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL3_WORLD,	APL3,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL4_WORLD,	APL4,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL5_WORLD,	APL5,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL6_WORLD,	APL6,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL7_FCCA,	    APL7,		FCCA,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL8_WORLD,	APL8,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL9_WORLD,	APL9,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL10_WORLD,	APL10,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL11_FCCA,	APL11,		FCCA,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL12_WORLD,   APL12,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL13_WORLD,   APL13,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL14_WORLD,   APL14,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL15_WORLD,   APL15,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL16_WORLD,   APL16,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL19_ETSIC,   APL19,		ETSIC,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL20_WORLD,   APL20,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL23_WORLD,   APL23,		WORLD,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },

	{APL3_FCCA,		APL3,		FCCA,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL1_ETSIC,	APL1,		ETSIC,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{APL2_ETSIC,	APL2,		ETSIC,		NO_REQ, NO_REQ, PSCAN_DEFER, 0 },

	/* MKK3 */
	{MKK3_MKKC,	MKK3,		MKKC,		DISALLOW_ADHOC_11A_TURB | NEED_NFC | LIMIT_FRAME_4MS, NEED_NFC, NO_PSCAN, 0 },

	/* MKK5 */
    /* JAPAN15 to be set as default JAPAN country mapping according to Regdomain_23 Revision */
    {MKK5_MKKC,	MKK5,		MKKC,		DISALLOW_ADHOC_11A_TURB | NEED_NFC | LIMIT_FRAME_4MS, NEED_NFC, PSCAN_MKK3, CTRY_JAPAN },
    {MKK5_MKKA,	MKK5,		MKKA,		DISALLOW_ADHOC_11A_TURB | NEED_NFC | LIMIT_FRAME_4MS, NEED_NFC, PSCAN_MKK3, 0 },

	/* MKK11 */
	{MKK11_MKKC,    MKK11,		MKKC,		DISALLOW_ADHOC_11A_TURB | NEED_NFC | LIMIT_FRAME_4MS, NEED_NFC, PSCAN_MKK3, 0 },

	/* MKK16 */
	{MKK16_MKKC,    MKK16,		MKKC,		DISALLOW_ADHOC_11A_TURB | NEED_NFC | LIMIT_FRAME_4MS, NEED_NFC, PSCAN_MKK3, 0 },
		/* These are super domains */
	{WOR0_WORLD,	WOR0_WORLD,	WOR0_WORLD,	NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{WOR1_WORLD,	WOR1_WORLD,	WOR1_WORLD,	DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{WOR2_WORLD,	WOR2_WORLD,	WOR2_WORLD,	DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{WOR3_WORLD,	WOR3_WORLD,	WOR3_WORLD,	NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{WOR4_WORLD,	WOR4_WORLD,	WOR4_WORLD,	DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{WOR5_ETSIC,	WOR5_ETSIC,	WOR5_ETSIC,	DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{WOR01_WORLD,	WOR01_WORLD,	WOR01_WORLD,	NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{WOR02_WORLD,	WOR02_WORLD,	WOR02_WORLD,	NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{EU1_WORLD,	EU1_WORLD,	EU1_WORLD,	NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
	{WOR9_WORLD,	WOR9_WORLD,	WOR9_WORLD,	DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{WORA_WORLD,	WORA_WORLD,	WORA_WORLD,	DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{WORB_WORLD,	WORB_WORLD,	WORB_WORLD,	DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB, NO_REQ, PSCAN_DEFER, 0 },
	{WORC_WORLD,	WORC_WORLD,	WORC_WORLD,	NO_REQ, NO_REQ, PSCAN_DEFER, 0 },
};

/*
 * The following table of vendor specific regdomain pairs and
 * additional flags used to modify the flags5GHz and flags2GHz
 * of the original regdomain
 */

#define	NO_INTERSECT_REQ	0xFFFFFFFF
#define	NO_UNION_REQ		0


static const COUNTRY_CODE_TO_ENUM_RD ahCmnAllCountries[] = {
    {CTRY_DEBUG,       NO_ENUMRD,     "DB", "DEBUG",           YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_DEFAULT,     DEF_REGDMN,    "NA", "NO_COUNTRY_SET",  YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_AFGHANISTAN, ETSI1_WORLD,   "AF", "AFGHANISTAN",      NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_ALBANIA,     ETSI1_WORLD,   "AL", "ALBANIA",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_ALGERIA,     APL13_WORLD,   "DZ", "ALGERIA",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_AMERICAN_SAMOA, FCC3_FCCA,  "AS", "AMERICAN SAMOA",   NO,  NO, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_ANGUILLA,    ETSI1_WORLD,   "AI", "ANGUILLA",        YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_ARGENTINA,   APL16_WORLD,    "AR", "ARGENTINA",       NO,  NO, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_ARMENIA,     ETSI4_WORLD,   "AM", "ARMENIA",          NO, YES, YES, YES, YES,  NO, NO, NO, NO, 7000 },
    {CTRY_ARUBA,       ETSI1_WORLD,   "AW", "ARUBA",            NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_AUSTRALIA,   FCC6_WORLD,    "AU", "AUSTRALIA",       YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_AUSTRIA,     ETSI1_WORLD,   "AT", "AUSTRIA",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_AZERBAIJAN,  ETSI4_WORLD,   "AZ", "AZERBAIJAN",      YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_BAHAMAS,     FCC3_WORLD,    "BS", "BAHAMAS",         YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_BAHRAIN,     APL15_WORLD,   "BH", "BAHRAIN",          NO, YES, YES, YES, YES,  NO, NO, NO, NO, 7000 },
    {CTRY_BANGLADESH,  APL1_WORLD,    "BD", "BANGLADESH",       NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_BARBADOS,    FCC2_WORLD,    "BB", "BARBADOS",         NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_BELARUS,     ETSI1_WORLD,   "BY", "BELARUS",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_BELGIUM,     ETSI1_WORLD,   "BE", "BELGIUM",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_BELGIUM2,    ETSI4_WORLD,   "BE", "BELGIUM2",         NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_BELIZE,      ETSI8_WORLD,    "BZ", "BELIZE",         YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_BERMUDA,     FCC3_FCCA,     "BM", "BERMUDA",         YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_BHUTAN,      ETSI1_WORLD,   "BT", "BHUTAN",           NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_BOLIVIA,     APL8_WORLD,    "BO", "BOLIVIA",         YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_BOSNIA_HERZ, ETSI1_WORLD,   "BA", "BOSNIA AND HERZEGOVINA",   NO, YES, YES, YES, YES,  YES, YES, YES, YES, 7000 },
    {CTRY_BRAZIL,      FCC3_ETSIC,    "BR", "BRAZIL",           NO,  NO, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_BRUNEI_DARUSSALAM, APL6_WORLD, "BN", "BRUNEI DARUSSALAM",  YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_BULGARIA,    ETSI1_WORLD,   "BG", "BULGARIA",         NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_BURKINA_FASO,FCC3_WORLD,    "BF", "BURKINA-FASO",     NO,  NO, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_CAMBODIA,    ETSI1_WORLD,   "KH", "CAMBODIA",         NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_CANADA,      FCC6_FCCA,     "CA", "CANADA",          YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_CAYMAN_ISLANDS, FCC3_WORLD, "KY", "CAYMAN ISLANDS",  YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_CENTRAL_AFRICA_REPUBLIC, FCC3_WORLD, "CF", "CENTRAL AFRICA REPUBLIC",  YES, YES, YES, YES, YES, YES,  NO, NO, NO, 7000 },
    {CTRY_CHAD,        ETSI1_WORLD,   "TD", "CHAD  ",          YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_CHILE,       APL23_WORLD,    "CL", "CHILE",          YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_CHINA,       APL14_WORLD,   "CN", "CHINA",           YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_CHRISTMAS_ISLAND, FCC3_WORLD, "CX", "CHRISTMAS ISLAND",   NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_COLOMBIA,    FCC3_WORLD,     "CO", "COLOMBIA",        NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_COLOMBIA,    FCC6_FCCA,      "CO", "COLOMBIA",        NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_COSTA_RICA,  FCC3_WORLD,    "CR", "COSTA RICA",       NO, YES, YES, YES, YES,  NO, NO, NO, NO, 7000 },
    {CTRY_COSTA_RICA,  FCC6_FCCA,     "CR", "COSTA RICA",       NO, YES, YES, YES, YES,  NO, NO, NO, NO, 7000 },
    {CTRY_CROATIA,     ETSI1_WORLD,   "HR", "CROATIA",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_CYPRUS,      ETSI1_WORLD,   "CY", "CYPRUS",          YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_CZECH,       ETSI1_WORLD,   "CZ", "CZECH REPUBLIC",   NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_DENMARK,     ETSI1_WORLD,   "DK", "DENMARK",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_DOMINICA,    FCC1_FCCA,     "DM", "DOMINICA",        YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_DOMINICAN_REPUBLIC, FCC1_FCCA, "DO", "DOMINICAN REPUBLIC",  YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_ECUADOR,     FCC3_WORLD,    "EC", "ECUADOR",          NO,  NO, YES, YES, YES,  NO, NO, NO, NO, 7000 },
    {CTRY_ECUADOR,     FCC6_FCCA,     "EC", "ECUADOR",          NO,  NO, YES, YES, YES,  NO, NO, NO, NO, 7000 },
    {CTRY_EGYPT,       ETSI3_WORLD,   "EG", "EGYPT",            NO, YES, YES, YES, YES,  YES, YES, YES, NO, 7000 },
    {CTRY_EL_SALVADOR, FCC1_WORLD,    "SV", "EL SALVADOR",      NO, YES, YES, YES, YES,  NO, NO, NO, NO, 7000 },
    {CTRY_ESTONIA,     ETSI1_WORLD,   "EE", "ESTONIA",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_ETHIOPIA,    ETSI1_WORLD,   "ET", "ETHIOPIA",         NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_FINLAND,     ETSI1_WORLD,   "FI", "FINLAND",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_FRANCE,      ETSI1_WORLD,   "FR", "FRANCE",           NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_FRENCH_GUIANA, ETSI1_WORLD, "GF", "FRENCH GUIANA",    NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_FRENCH_POLYNESIA, ETSI1_WORLD, "PF", "FRENCH POLYNESIA",   NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_GEORGIA,     ETSI4_WORLD,   "GE", "GEORGIA",         YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_GERMANY,     ETSI1_WORLD,   "DE", "GERMANY",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_GHANA,       FCC3_WORLD,    "GH", "GHANA",            NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_GIBRALTAR,   ETSI1_WORLD,   "GI", "GIBRALTAR",        NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_GREECE,      ETSI1_WORLD,   "GR", "GREECE",           NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_GREENLAND,   ETSI1_WORLD,   "GL", "GREENLAND",        NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_GRENADA,     FCC3_FCCA,     "GD", "GRENADA",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_GUADELOUPE,  ETSI1_WORLD,   "GP", "GUADELOUPE",       NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_GUAM,        FCC3_FCCA,     "GU", "GUAM",             NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_GUATEMALA,   ETSI1_WORLD,   "GT", "GUATEMALA",       YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_GUYANA,      APL1_ETSIC,    "GY", "GUYANA",          YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_HAITI,       FCC3_FCCA,     "HT", "HAITI",            NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_HONDURAS,    FCC3_WORLD,    "HN", "HONDURAS",         NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_HONG_KONG,   FCC3_WORLD,    "HK", "HONG KONG",       YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_HUNGARY,     ETSI1_WORLD,   "HU", "HUNGARY",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_ICELAND,     ETSI1_WORLD,   "IS", "ICELAND",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_INDIA,       APL15_WORLD,   "IN", "INDIA",            NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_INDIA2,      APL19_ETSIC,   "IN", "INDIA2",           NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_INDONESIA,   APL2_ETSIC,    "ID", "INDONESIA",        NO, YES, YES, YES, YES,  NO,  NO, NO, NO, 7000 },
    {CTRY_IRAQ,        ETSI1_WORLD,   "IQ", "IRAQ",             NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_IRELAND,     ETSI1_WORLD,   "IE", "IRELAND",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_ISRAEL,      ETSI3_WORLD,   "IL", "ISRAEL",           NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_ITALY,       ETSI1_WORLD,   "IT", "ITALY",            NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_COTE_D_IVOIRE,FCC3_WORLD,    "CI", "COTE_D_IVOIRE",  YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_JAMAICA,     FCC13_WORLD,    "JM", "JAMAICA",         NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_JAPAN,       MKK5_MKKC,     "JP", "JAPAN",            NO,  NO, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_JORDAN,      APL4_WORLD,    "JO", "JORDAN",           NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_KAZAKHSTAN,  NULL1_WORLD,   "KZ", "KAZAKHSTAN",       NO, YES, YES, YES,  NO,  NO, NO, NO, NO, 7000 },
    {CTRY_KENYA,       APL12_WORLD,   "KE", "KENYA",            NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_KOREA_ROC,   APL9_WORLD,    "KR", "KOREA REPUBLIC",   NO,  NO, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_KUWAIT,      ETSI3_WORLD,   "KW", "KUWAIT",           NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_LATVIA,      ETSI1_WORLD,   "LV", "LATVIA",           NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_LEBANON,     FCC3_WORLD,    "LB", "LEBANON",         YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_LESOTHO,     ETSI1_WORLD,    "LS", "LESOTHO",         NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_LIECHTENSTEIN, ETSI1_WORLD, "LI", "LIECHTENSTEIN",    NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_LITHUANIA,   ETSI1_WORLD,   "LT", "LITHUANIA",        NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_LUXEMBOURG,  ETSI1_WORLD,   "LU", "LUXEMBOURG",       NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MACAU,       FCC3_WORLD,    "MO", "MACAU SAR",       YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MACEDONIA,   ETSI1_WORLD,   "MK", "MACEDONIA, FYRO",  NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MALAWI,      ETSI1_WORLD,   "MW", "MALAWI",           NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MALAYSIA,    FCC11_WORLD,   "MY", "MALAYSIA",         NO,  NO, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MALDIVES,    APL6_WORLD,    "MV", "MALDIVES",         NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MALTA,       ETSI1_WORLD,   "MT", "MALTA",            NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MARSHALL_ISLANDS, FCC3_FCCA,"MH", "MARSHALL ISLANDS", NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MARTINIQUE,  ETSI1_WORLD,   "MQ", "MARTINIQUE",       NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MAURITANIA,  ETSI1_WORLD,   "MR", "MAURITANIA",       NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MAURITIUS,   ETSI1_WORLD,    "MU", "MAURITIUS",        NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MAYOTTE,     ETSI1_WORLD,   "YT", "MAYOTTE",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MEXICO,      FCC3_ETSIC,    "MX", "MEXICO",          YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MICRONESIA,  FCC3_FCCA,     "FM", "MICRONESIA",      YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MOLDOVA,     ETSI1_WORLD,   "MD", "REPUBLIC OF MOLDOVA",  YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MONACO,      ETSI1_WORLD,   "MC", "MONACO",          YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MONGOLIA,    FCC3_WORLD,    "MN", "MONGOLIA",         NO,  NO, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MONTENEGRO,  ETSI1_WORLD,   "ME", "MONTENEGRO",       NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_MOROCCO,     ETSI3_WORLD,   "MA", "MOROCCO",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_NAMIBIA,     APL20_WORLD,    "NA", "NAMIBIA",         NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_NEPAL,       APL23_WORLD,    "NP", "NEPAL",           NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_NETHERLANDS, ETSI1_WORLD,   "NL", "NETHERLANDS",      NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_NETHERLANDS_ANTILLES, ETSI1_WORLD, "AN", "NETHERLANDS ANTILLES",   NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_NEW_ZEALAND, FCC3_ETSIC,    "NZ", "NEW ZEALAND",      NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_NICARAGUA,   FCC3_FCCA,     "NI", "NICARAGUA",        YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_NIGERIA,     APL8_WORLD,    "NG", "NIGERIA",          NO,  NO, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_NORWAY,      ETSI1_WORLD,   "NO", "NORWAY",           NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_NORTHERN_MARIANA_ISLANDS, FCC3_FCCA, "MP", "NORTHERN MARIANA ISLANDS",  NO, NO, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_OMAN,        ETSI1_WORLD,   "OM", "OMAN",             NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_PAKISTAN,    APL1_ETSIC,    "PK", "PAKISTAN",         NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_PALAU,       FCC3_FCCA,     "PW", "PALAU",           YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_PANAMA,      FCC14_FCCB,     "PA", "PANAMA",         YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_PAPUA_NEW_GUINEA, FCC3_WORLD, "PG", "PAPUA NEW GUINEA",  YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_PARAGUAY,    FCC3_WORLD,    "PY", "PARAGUAY",        YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_PARAGUAY,    FCC6_FCCA,     "PY", "PARAGUAY",         YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_PERU,        FCC3_WORLD,    "PE", "PERU",             NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_PERU,        FCC6_FCCA,     "PE", "PERU",             NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_PHILIPPINES, FCC3_WORLD,    "PH", "PHILIPPINES",     YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_PHILIPPINES, FCC6_FCCA,     "PH", "PHILIPPINES",     YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_POLAND,      ETSI1_WORLD,   "PL", "POLAND",           NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_PORTUGAL,    ETSI1_WORLD,   "PT", "PORTUGAL",         NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_PUERTO_RICO, FCC3_FCCA,     "PR", "PUERTO RICO",     YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_PUERTO_RICO, FCC6_FCCA,     "PR", "PUERTO RICO",     YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_QATAR,       ETSI14_WORLD,    "QA", "QATAR",            NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_REUNION,     ETSI1_WORLD,   "RE", "REUNION",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_ROMANIA,     ETSI1_WORLD,   "RO", "ROMANIA",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_RUSSIA,      ETSI8_WORLD,   "RU", "RUSSIA",           NO,  NO, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_RWANDA,      FCC3_WORLD,    "RW", "RWANDA",           NO, YES, YES, YES, YES,  YES, YES, YES, YES, 7000 },
    {CTRY_ST_BARTHELEMY,         ETSI1_WORLD,    "BL", "SAINT BARTHELEMY",          YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_ST_KITTS_NEVIS,        APL10_WORLD,    "KN", "SAINT KITTS AND NEVIS",      YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_ST_LUCIA,              APL10_WORLD,    "LC", "SAINT LUCIA",                YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_ST_MARTIN,             ETSI1_WORLD,    "MF", "SAINT MARTIN",               YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_ST_PIERRE_MIQUELON,    ETSI1_WORLD,    "PM", "SAINT PIERRE AND MIQUELON",  YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_ST_VINCENT_GRENADIENS, ETSI1_WORLD,    "VC", "SAINT VINCENT AND GRENADIENS",  YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_SAMOA ,      ETSI1_WORLD,   "WS", "SAMOA",            NO, YES, YES, YES, YES,  YES,  NO, NO, NO, 7000 },
    {CTRY_SAUDI_ARABIA, ETSI1_WORLD,  "SA", "SAUDI ARABIA",     NO, YES, YES, YES, YES,  YES, YES, YES, YES, 7000 },
    {CTRY_SENEGAL,     FCC13_WORLD,    "SN", "SENEGAL",         NO, YES, YES, YES, YES, YES,  YES, YES, YES, 7000 },
    {CTRY_SERBIA,      ETSI1_WORLD,   "RS", "REPUBLIC OF SERBIA",   NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_SINGAPORE,   FCC3_WORLD,    "SG", "SINGAPORE",       YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_SLOVAKIA,    ETSI1_WORLD,   "SK", "SLOVAKIA",         NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_SLOVENIA,    ETSI1_WORLD,   "SI", "SLOVENIA",         NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_SOUTH_AFRICA, FCC3_WORLD,  "ZA", "SOUTH AFRICA",      NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_SPAIN,       ETSI1_WORLD,   "ES", "SPAIN",            NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_SRI_LANKA,   FCC3_WORLD,    "LK", "SRI LANKA",        NO, YES, YES, YES, YES,  NO, NO, NO, NO, 7000 },
    {CTRY_SURINAME,    ETSI1_WORLD,   "SR", "SURINAME",         NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_SWEDEN,      ETSI1_WORLD,   "SE", "SWEDEN",           NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_SWITZERLAND, ETSI1_WORLD,   "CH", "SWITZERLAND",      NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_TAIWAN,      FCC3_FCCA,     "TW", "TAIWAN",          YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_TANZANIA,    APL1_WORLD,    "TZ", "TANZANIA",        YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_TOGO,        ETSI1_WORLD,   "TG", "TOGO",             NO, YES, YES, YES, YES, YES,  NO, NO, NO, 7000 },
    {CTRY_THAILAND,    FCC3_WORLD,    "TH", "THAILAND",         NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_TRINIDAD_Y_TOBAGO, FCC3_WORLD, "TT", "TRINIDAD AND TOBAGO",   NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_TUNISIA,     ETSI3_WORLD,   "TN", "TUNISIA",          NO, YES, YES, YES, YES,  YES, YES, YES, YES, 7000 },
    {CTRY_TURKEY,      ETSI1_WORLD,   "TR", "TURKEY",           NO, YES, YES, YES, YES,  YES, YES, YES, YES, 7000 },
    {CTRY_TURKS_CAICOS, FCC3_WORLD,    "TC", "TURKS AND CAICOS",   NO, NO, YES, YES, YES,  YES, YES, YES, YES, 7000 },
    {CTRY_UGANDA,      FCC3_WORLD,    "UG", "UGANDA",           NO, NO, YES, YES, YES,  YES, YES, YES, YES, 7000 },
    {CTRY_UKRAINE,     ETSI9_WORLD,   "UA", "UKRAINE",          NO, NO,  YES, YES, YES,  YES, YES, YES, YES, 7000 },
    {CTRY_UAE,         FCC3_WORLD,    "AE", "UNITED ARAB EMIRATES",   NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_UNITED_KINGDOM, ETSI1_WORLD, "GB", "UNITED KINGDOM",   NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_UNITED_STATES, FCC8_FCCA,   "US", "UNITED STATES",   YES, YES, YES, YES, YES, YES, YES, YES, YES, 5825 },
    {CTRY_URUGUAY,     FCC2_WORLD,    "UY", "URUGUAY",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_URUGUAY,     FCC6_FCCA,    "UY", "URUGUAY",           NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_UZBEKISTAN,  ETSI3_WORLD,   "UZ", "UZBEKISTAN",      YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_VANUATU,     FCC3_WORLD,    "VU", "VANUATU",          NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_VENEZUELA,   FCC2_ETSIC,    "VE", "VENEZUELA",        NO, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_VIET_NAM,    FCC3_WORLD,    "VN", "VIET NAM",         NO, YES, YES, YES, YES, YES, YES, NO, YES, 7000 },
    {CTRY_VIRGIN_ISLANDS, FCC3_FCCA,  "VI", "VIRGIN ISLANDS",   NO,  NO, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_WALLIS_FUTUNA, ETSI1_WORLD, "WF", "WALLIS AND FUTUNA",  YES, YES, YES, YES, YES, YES, YES, YES, YES, 7000 },
    {CTRY_YEMEN,       NULL1_WORLD,   "YE", "YEMEN",            NO, YES, YES, YES,  NO,  NO, NO, NO, NO, 7000 },
    {CTRY_ZIMBABWE,    ETSI1_WORLD,   "ZW", "ZIMBABWE",         NO, YES, YES, YES,  YES,  YES, YES, YES, YES, 7000 }
};


/* Bit masks for DFS per regdomain */

enum {
	NO_DFS   = 0x0000000000000000ULL,
	DFS_FCC3 = 0x0000000000000001ULL,
	DFS_ETSI = 0x0000000000000002ULL,
	DFS_MKK4 = 0x0000000000000004ULL,
	DFS_CN   = 0x0000000000000008ULL,
	DFS_KR   = 0x0000000000000010ULL,
};


/* The table of frequency bands is indexed by a bitmask.  The ordering
 * must be consistent with the enum below.  When adding a new
 * frequency band, be sure to match the location in the enum with the
 * comments 
 */

#ifndef ATH_NO_5G_SUPPORT
/*
 * 5GHz 11A channel tags
 */
enum {
	F1_4912_4947,
	F1_4915_4925,
	F1_4935_4945,
	F2_4920_4980,
	F1_4942_4987,
	F1_4945_4985,
	F1_4950_4980,
	F1_5032_5057,
	F2_5035_5040,
	F1_5035_5045,
	F2_5040_5080,
	F1_5055_5055,

	F1_5120_5240,


	F1_5180_5240,
	F2_5180_5240,
	F3_5180_5240,
	F4_5180_5240,
	F5_5180_5240,
	F6_5180_5240,
	F8_5180_5240,
	F9_5180_5240,
	F11_5180_5240,
	F12_5180_5240,
	F13_5180_5240,
	F14_5180_5240,
	F15_5180_5240,
	F16_5180_5240,
	F17_5180_5240,
	F18_5180_5240,

	F1_5240_5280,

	F1_5260_5280,

	F1_5260_5320,
	F2_5260_5320,
	F3_5260_5320,
	F4_5260_5320,
	F5_5260_5320,
	F6_5260_5320,
	F7_5260_5320,
	F8_5260_5320,
	F9_5260_5320,
	F10_5260_5320,
	F11_5260_5320,
	F12_5260_5320,
	F13_5260_5320,
	F14_5260_5320,
	F15_5260_5320,
	F16_5260_5320,
	F17_5260_5320,
	F18_5260_5320,
	F19_5260_5320,

	F1_5260_5700,

	F1_5280_5320,
	F2_5280_5320,

	F1_5500_5560,

	F1_5500_5580,
	F2_5500_5580,
	F4_5500_5580,

	F1_5500_5620,
    F1_5500_5640,

    F1_5500_5660,
    F2_5500_5660,

	F1_5500_5720,
	F2_5500_5720,
	F3_5500_5720,
	F7_5500_5720,
	F8_5500_5720,
	F9_5500_5720,
	F2_5500_5700,
	F3_5500_5700,
	F5_5500_5700,
	F6_5500_5700,
	F7_5500_5700,
	F8_5500_5700,
	F9_5500_5700,
	F10_5500_5720,
	F11_5500_5700,

	F1_5660_5700,
	F2_5660_5720,
	F3_5660_5720,
	F5_5660_5720,

	F1_5745_5765,

	F1_5745_5805,
	F2_5745_5805,
	F3_5745_5805,
    F4_5745_5805,

	F1_5745_5825,
	F2_5745_5825,
	F3_5745_5825,
	F4_5745_5825,
	F5_5745_5825,
	F6_5745_5825,
	F7_5745_5825,
    F8_5745_5825,
    F9_5745_5825,
	F10_5745_5825,
    F11_5745_5825,
	F13_5745_5825,
	F14_5745_5825,
	F15_5745_5825,
	F16_5745_5825,

    F1_5745_5865,
    F2_5745_5865,
    F3_5745_5865,
    F4_5745_5865,

    F1_5845_5865,
    F2_5845_5865,
    F1_5860_5920,
    F2_5860_5920,
    F1_5875_5905,

	W1_4920_4980,
	W1_5040_5080,
	W1_5170_5230,
	W1_5180_5240,
	W1_5260_5320,
	W1_5745_5825,
	W1_5500_5700,
	A_DEMO_ALL_CHANNELS,
    OVERRIDE_MODE_ALL_CHANNELS_5,
    OVERRIDE_MODE_ALL_CHANNELS_10,
    OVERRIDE_MODE_ALL_CHANNELS_20,
};

static const REG_DMN_FREQ_BAND regDmn5GhzFreq[] = {
	{ 4912, 4947, 20, 0, 5,  5, NO_DFS, PSCAN_MKK2, 16 },				/* F1_4912_4947 */
	{ 4915, 4925, 20, 0, 10, 5, NO_DFS, PSCAN_MKK2, 16 },				/* F1_4915_4925 */
	{ 4935, 4945, 20, 0, 10, 5, NO_DFS, PSCAN_MKK2, 16 },				/* F1_4935_4945 */
	{ 4920, 4980, 20, 0, 20, 20, NO_DFS, PSCAN_MKK2, 7 },				/* F2_4920_4980 */
	{ 4942, 4987, 27, 6, 5,  5, NO_DFS, PSCAN_FCC, 0 },				/* F1_4942_4987 */
	{ 4945, 4985, 30, 6, 10, 5, NO_DFS, PSCAN_FCC, 0 },				/* F1_4945_4985 */
	{ 4950, 4980, 33, 6, 20, 5, NO_DFS, PSCAN_FCC, 0 },				/* F1_4950_4980 */
	{ 5032, 5057, 20, 0,  5, 5, NO_DFS, PSCAN_MKK2, 12 },				/* F1_5032_5057 */       
	{ 5035, 5040, 23, 0, 10, 5, NO_DFS, PSCAN_MKK2, 12 },				/* F2_5035_5040 */
	{ 5035, 5045, 20, 0, 10, 5, NO_DFS, PSCAN_MKK2, 12 },	                        /* F1_5035_5045 */
	{ 5040, 5080, 20, 0, 20, 20, NO_DFS, NO_PSCAN, 6 },					/* F2_5040_5080 */
	{ 5055, 5055, 20, 0, 10, 5, NO_DFS, PSCAN_MKK2, 12 },				/* F1_5055_5055 */

	{ 5120, 5240, 5,  6, 20, 20, NO_DFS, NO_PSCAN, 0 },				/* F1_5120_5240 */


	{ 5180, 5240, 15, 0, 20, 20, NO_DFS, PSCAN_FCC | PSCAN_ETSI, 1 },		/* F1_5180_5240 */
	{ 5180, 5240, 17, 6, 20, 20, NO_DFS, NO_PSCAN, 1 },				/* F2_5180_5240 */
	{ 5180, 5240, 18, 0, 20, 20, NO_DFS, PSCAN_FCC | PSCAN_ETSI, 1 },		/* F3_5180_5240 */
	{ 5180, 5240, 20, 0, 20, 20, NO_DFS, PSCAN_FCC | PSCAN_ETSI, 1 },		/* F4_5180_5240 */
	{ 5180, 5240, 23, 0, 20, 20, NO_DFS, PSCAN_FCC | PSCAN_ETSI, 1 },		/* F5_5180_5240 */
	{ 5180, 5240, 23, 6, 20, 20, NO_DFS, PSCAN_FCC, 1 },				/* F6_5180_5240 */
	{ 5180, 5240, 17, 6, 20, 20, NO_DFS, NO_PSCAN, 1 },                             /* F8_5180_5240 */
	{ 5180, 5240, 20, 6, 20, 20, NO_DFS, NO_PSCAN, 0 },				/* F9_5180_5240 */
	{ 5180, 5240, 30, 6, 20, 20, NO_DFS, NO_PSCAN, 1 },                             /* F11_5180_5240 */
	{ 5180, 5240, 24, 6, 20, 20, NO_DFS, NO_PSCAN, 1 },				/* F12_5180_5240 */
	{ 5180, 5240, 23, 0, 20, 20, NO_DFS, NO_PSCAN, 1 },				/* F13_5180_5240 */
	{ 5180, 5240, 30, 0, 20, 20, NO_DFS, NO_PSCAN, 1 },				 /* F14_5180_5240 */
	{ 5180, 5240, 23, 6, 20, 20, NO_DFS, NO_PSCAN, 1 },				/* F15_5180_5240 */
	{ 5180, 5240, 20, 0, 20, 20, NO_DFS, NO_PSCAN, 1 },				/* F16_5180_5240 */
	{ 5180, 5240, 24, 0, 20, 20, NO_DFS, NO_PSCAN, 1 },				/* F17_5180_5240 */
	{ 5180, 5240, 30, 0, 20, 20, NO_DFS, NO_PSCAN, 1 },				/* F18_5180_5240 */

	{ 5240, 5280, 23, 0, 20, 20, DFS_FCC3, PSCAN_FCC | PSCAN_ETSI, 0 },		/* F1_5240_5280 */

	{ 5260, 5280, 23, 0, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_FCC | PSCAN_ETSI, 2 },	/* F1_5260_5280 */

	{ 5260, 5320, 18, 0, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_FCC | PSCAN_ETSI, 2 },	/* F1_5260_5320 */

	{ 5260, 5320, 20, 0, 20, 20, DFS_FCC3 | DFS_ETSI | DFS_MKK4 | DFS_KR, PSCAN_FCC | PSCAN_ETSI | PSCAN_MKK3 , 0 },
	/* F2_5260_5320 */

	{ 5260, 5320, 24, 6, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_FCC | PSCAN_ETSI, 2 },/* F3_5260_5320 */
	{ 5260, 5320, 23, 6, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_FCC, 2 },		/* F4_5260_5320 */
	{ 5260, 5320, 23, 6, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_FCC, 2 },		/* F5_5260_5320 */
	{ 5260, 5320, 30, 0, 20, 20, DFS_ETSI, PSCAN_ETSI, 2 },				/* F6_5260_5320 */
	{ 5260, 5320, 23, 0, 20, 20, DFS_FCC3 | DFS_ETSI | DFS_MKK4 | DFS_KR, PSCAN_FCC | PSCAN_ETSI | PSCAN_MKK3 | PSCAN_MKK1, 0 },
	/* F7_5260_5320 */
	{ 5260, 5320, 30, 6, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_FCC, 2 },		/* F8_5260_5320 */
	{ 5260, 5320, 24, 6, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_FCC, 2 },		/* F9_5260_5320 */

	{ 5260, 5320, 23, 0, 20, 20, NO_DFS, PSCAN_FCC , 2 },/* F10_5260_5320 */
	{ 5260, 5320, 23, 0, 20, 20, DFS_FCC3 | DFS_CN, PSCAN_FCC, 2 },              /* F11_5260_5320 */
	{ 5260, 5320, 30, 0, 20, 20, NO_DFS, PSCAN_FCC, 2 },                           /* F12_5260_5320 */
	{ 5260, 5320, 30, 0, 20, 20, NO_DFS, NO_PSCAN, 2 },		/* F13_5260_5320 */
	{ 5260, 5320, 23, 0, 20, 20, NO_DFS, NO_PSCAN, 2 },		/* F14_5260_5320 */
	{ 5260, 5320, 30, 0, 20, 20, DFS_FCC3 , PSCAN_FCC, 2 },		/*F15_5260_5320*/
	{ 5260, 5320, 20, 0, 20, 20, NO_DFS , NO_PSCAN, 0 },		/*F16_5260_5320*/
	{ 5260, 5320, 24, 0, 20, 20, NO_DFS , NO_PSCAN, 2 },		/*F17_5260_5320*/
	{ 5260, 5320, 23, 0, 20, 20, DFS_FCC3 | DFS_ETSI | DFS_MKK4 | DFS_KR, PSCAN_FCC | PSCAN_ETSI | PSCAN_MKK3 , 0 },
	/* F18_5260_5320 */
	{ 5260, 5320, 23, 0, 20, 20,  DFS_MKK4 , PSCAN_MKK3 , 0 }, /*F19_5260_5320*/


	{ 5260, 5700, 5,  6, 20, 20, DFS_FCC3 | DFS_ETSI, NO_PSCAN, 0 },		/* F1_5260_5700 */

	{ 5280, 5320, 17, 6, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_FCC, 2 },		/* F1_5280_5320 */

	{ 5280, 5320, 17, 6, 20, 20, NO_DFS, NO_PSCAN, 2 },		                /* F2_5280_5320 */

	{ 5500, 5560, 30, 0, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_FCC | PSCAN_ETSI, 4},   /* F1_5500_5560 */

	{ 5500, 5580, 24, 6, 20, 20, DFS_FCC3, PSCAN_FCC, 4},                           /* F1_5500_5580 */
	{ 5500, 5580, 30, 6, 20, 20, DFS_FCC3, PSCAN_FCC, 4},                           /* F2_5500_5580 */
	{ 5500, 5580, 30, 0, 20, 20, NO_DFS, PSCAN_FCC, 4},                             /* F4_5500_5580 */

	{ 5500, 5620, 30, 6, 20, 20, DFS_ETSI, PSCAN_ETSI, 3 },				/* F1_5500_5620 */
    
	{ 5500, 5640, 24, 6, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_FCC, 4 },		/* F1_5500_5640 */
    
    { 5500, 5660, 20, 0, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_FCC | PSCAN_ETSI, 0 },   /* F1_5500_5660 */
    { 5500, 5660, 23, 0, 20, 20, DFS_ETSI, PSCAN_ETSI, 0 },                         /* F2_5500_5660 */

	{ 5500, 5720, 24, 6, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_FCC, 4 },		/* F1_5500_5720 */
	{ 5500, 5720, 30, 0, 20, 20, DFS_ETSI, PSCAN_ETSI, 0 },             /* F2_5500_5720 */
	{ 5500, 5720, 23, 0, 20, 20, DFS_ETSI, PSCAN_ETSI, 0 },                 /* F3_5500_5720 */
	{ 5500, 5720, 30, 6, 20, 20, DFS_ETSI | DFS_KR, PSCAN_ETSI, 0 },            /* F7_5500_5720 */
	{ 5500, 5720, 30, 6, 20, 20, NO_DFS, NO_PSCAN, 0 },                     /* F8_5500_5720 */
	{ 5500, 5720, 24, 0, 20, 20, NO_DFS, NO_PSCAN, 0 },                     /* F9_5500_5720 */
	{ 5500, 5700, 27, 0, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_FCC | PSCAN_ETSI, 3 },	/* F2_5500_5700 */
	{ 5500, 5700, 30, 0, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_FCC | PSCAN_ETSI, 3 },	/* F3_5500_5700 */
	{ 5500, 5700, 30, 6, 20, 20, DFS_ETSI | DFS_FCC3 | DFS_KR, PSCAN_FCC | PSCAN_ETSI, 0 },					/* F5_5500_5700 */
	{ 5500, 5700, 26, 0, 20, 20, DFS_FCC3 | DFS_ETSI | DFS_MKK4, PSCAN_MKK3 | PSCAN_FCC, 0 },/* F6_5500_5700 */
	{ 5500, 5700, 24, 0, 20, 20, DFS_ETSI, PSCAN_ETSI, 3 },	/* F7_5500_5700 */
	{ 5500, 5700, 24, 0, 20, 20, DFS_MKK4 | DFS_ETSI, PSCAN_MKK3, 0 },/* F8_5500_5700 */
	{ 5500, 5700, 23, 0, 20, 20, DFS_MKK4, PSCAN_MKK3, 0 },/* F9_5500_5700 */
	{ 5500, 5720, 20, 0, 20, 20, DFS_ETSI, PSCAN_ETSI, 0 },                 /* F10_5500_5720 */
	{ 5500, 5700, 23, 0, 20, 20, DFS_FCC3 | DFS_ETSI | DFS_MKK4, PSCAN_MKK3 | PSCAN_FCC, 0 },/* F11_5500_5700 */

	{ 5660, 5700, 30, 0, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_FCC | PSCAN_ETSI, 4},           /* F1_5660_5700 */
	{ 5660, 5720, 24, 6, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_FCC | PSCAN_ETSI, 4},           /* F2_5660_5720 */
	{ 5660, 5720, 30, 6, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_FCC | PSCAN_ETSI, 4},           /* F3_5660_5720 */
	{ 5660, 5720, 30, 0, 20, 20, NO_DFS, PSCAN_FCC, 0},                        /* F5_5660_5720 */

	{ 5745, 5765, 23, 0, 20, 20, NO_DFS, NO_PSCAN, 3 },				/* F1_5745_5765 */

	{ 5745, 5805, 30, 0, 20, 20, NO_DFS, NO_PSCAN, 3 },				/* F1_5745_5805 */
	{ 5745, 5805, 30, 6, 20, 20, NO_DFS, NO_PSCAN, 3 },				/* F2_5745_5805 */
	{ 5745, 5805, 30, 6, 20, 20, NO_DFS, NO_PSCAN, 0 },			/* F3_5745_5805 */
    { 5745, 5805, 20, 0, 20, 20, NO_DFS, NO_PSCAN, 0 },			    /* F4_5745_5805 */

	{ 5745, 5825, 5,  6, 20, 20, NO_DFS, NO_PSCAN, 5 },				/* F1_5745_5825 */
	{ 5745, 5825, 17, 0, 20, 20, NO_DFS, NO_PSCAN, 5 },				/* F2_5745_5825 */
	{ 5745, 5825, 20, 0, 20, 20, NO_DFS, NO_PSCAN, 0 },				/* F3_5745_5825 */	
	{ 5745, 5825, 30, 0, 20, 20, NO_DFS, NO_PSCAN, 0 },				/* F4_5745_5825 */
	{ 5745, 5825, 30, 6, 20, 20, NO_DFS, NO_PSCAN, 5 },				/* F5_5745_5825 */
	{ 5745, 5825, 30, 6, 20, 20, NO_DFS, NO_PSCAN, 5 },				/* F6_5745_5825 */
    { 5745, 5825, 30, 6, 20, 20, NO_DFS, PSCAN_ETSI, 0 },			/* F7_5745_5825 */
        { 5745, 5825, 20, 6, 20, 20, NO_DFS, PSCAN_ETSI, 0 },			/* F8_5745_5825 */
    { 5745, 5825, 23, 0, 20, 20, NO_DFS, NO_PSCAN, 0 },				/* F9_5745_5825 */
    { 5745, 5825, 30, 6, 20, 20, NO_DFS, NO_PSCAN, 0 },			        /* F10_5745_5825 */
    { 5745, 5825, 24, 6, 20, 20, NO_DFS, NO_PSCAN, 0 },             /* F11_5745_5825 */
	{ 5745, 5825, 30, 0, 20, 20, NO_DFS, NO_PSCAN, 0 },             /* F13_5745_5825 */
	{ 5745, 5825, 36, 0, 20, 20, NO_DFS, NO_PSCAN, 0 },				/* F14_5745_5825 */
	{ 5745, 5825, 33, 0, 20, 20, NO_DFS, NO_PSCAN, 0 },				/* F15_5745_5825 */
	{ 5745, 5825, 23, 0, 20, 20, DFS_ETSI, PSCAN_ETSI, 0 },				/* F16_5745_5825 */

    { 5745, 5865, 27, 0, 20, 20, DFS_ETSI, PSCAN_ETSI, 0 },			/* F1_5745_5865 */
    { 5745, 5865, 27, 0, 10, 20, DFS_ETSI, PSCAN_ETSI, 0 },			/* F2_5745_5865 */
    { 5745, 5865, 14, 0, 10, 20, DFS_ETSI, PSCAN_ETSI, 0 },			/* F3_5745_5865 */
    { 5745, 5865, 20, 0, 20, 20, DFS_ETSI, PSCAN_ETSI, 0 },			/* F4_5745_5865 */

    { 5845, 5865, 30, 6, 20, 20, NO_DFS, PSCAN_ETSI, 0 },			/* F1_5845_5865 */
    { 5845, 5865, 30, 0, 20, 20, NO_DFS, NO_PSCAN, 0 },				/* F2_5845_5865 */

    { 5860, 5920, 24, 6, 10, 10, NO_DFS, PSCAN_FCC, 0 },			/* F1_5860_5920 */
    { 5860, 5920, 30, 6, 10, 10, DFS_ETSI, PSCAN_ETSI, 0 },			/* F2_5860_5920 */
    { 5875, 5905, 24, 6, 20, 30, NO_DFS, PSCAN_FCC, 0 },			/* F1_5875_5905 */

	/*
	 * Below are the world roaming channels
	 * All WWR domains have no power limit, instead use the card's CTL
	 * or max power settings.
	 */
	{ 4920, 4980, 30, 0, 20, 20, NO_DFS, PSCAN_WWR, 0 },				/* W1_4920_4980 */
	{ 5040, 5080, 30, 0, 20, 20, NO_DFS, PSCAN_WWR, 0 },				/* W1_5040_5080 */
	{ 5170, 5230, 30, 0, 20, 20, NO_DFS, PSCAN_WWR, 0 },				/* W1_5170_5230 */
	{ 5180, 5240, 30, 0, 20, 20, NO_DFS, PSCAN_WWR, 0 },				/* W1_5180_5240 */
	{ 5260, 5320, 30, 0, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, 0 },		/* W1_5260_5320 */
	{ 5745, 5825, 30, 0, 20, 20, NO_DFS, PSCAN_WWR, 0 },				/* W1_5745_5825 */
	{ 5500, 5700, 30, 0, 20, 20, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, 0 },		/* W1_5500_5700 */
	{ 4920, 6100, 30, 6, 20, 20, NO_DFS, NO_PSCAN, 0 },				/* A_DEMO_ALL_CHANNELS */
    { 4920, 6100, 50, 20, 20, 5,  DFS_FCC3 | DFS_ETSI | DFS_MKK4, NO_PSCAN, 0 },             /* OVERRIDE_MODE_ALL_CHANNELS_5 */
    { 4920, 6100, 50, 20, 20, 10, DFS_FCC3 | DFS_ETSI | DFS_MKK4, NO_PSCAN, 0 },             /* OVERRIDE_MODE_ALL_CHANNELS_10 */
    { 4920, 6100, 50, 20, 20, 20, DFS_FCC3 | DFS_ETSI | DFS_MKK4, NO_PSCAN, 0 },             /* OVERRIDE_MODE_ALL_CHANNELS_20 */
};

/*
 * 5GHz Turbo (dynamic & static) tags
 */

enum {
	T1_5130_5650,
	T1_5150_5670,

	T1_5200_5200,
	T2_5200_5200,
	T3_5200_5200,
	T4_5200_5200,
	T5_5200_5200,
	T6_5200_5200,
	T7_5200_5200,
	T8_5200_5200,
	T9_5200_5200,

	T1_5200_5280,
	T2_5200_5280,
	T3_5200_5280,
	T4_5200_5280,
	T5_5200_5280,
	T6_5200_5280,

	T1_5200_5240,
	T1_5210_5210,
	T2_5210_5210,
	T3_5210_5210,
	T4_5210_5210,
	T5_5210_5210,
	T6_5210_5210,
	T7_5210_5210,
	T8_5210_5210,
	T9_5210_5210,
	T10_5210_5210,
	T11_5210_5210,
	T1_5240_5240,
	T2_5240_5240,

	T1_5210_5250,
	T1_5210_5290,
	T2_5210_5290,
	T3_5210_5290,

	T1_5280_5280,
	T2_5280_5280,
	T3_5280_5280,
	T1_5290_5290,
	T2_5290_5290,
	T3_5290_5290,
	T1_5250_5290,
	T2_5250_5290,
	T3_5250_5290,
	T4_5250_5290,
	T5_5250_5290,

	T1_5540_5660,
	T2_5540_5660,
	T3_5540_5660,
	T1_5760_5800,
	T2_5760_5800,
	T3_5760_5800,
	T4_5760_5800,
	T5_5760_5800,
	T6_5760_5800,
	T7_5760_5800,

	T1_5765_5805,
	T2_5765_5805,
	T3_5765_5805,
	T4_5765_5805,
	T5_5765_5805,
	T6_5765_5805,
	T7_5765_5805,
	T8_5765_5805,
	T9_5765_5805,

	WT1_5210_5250,
	WT1_5290_5290,
	WT1_5540_5660,
	WT1_5760_5800,
};

static const REG_DMN_FREQ_BAND regDmn5GhzTurboFreq[] = {
	{ 5130, 5650, 5,  6, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T1_5130_5650 */
  	{ 5150, 5670, 5,  6, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T1_5150_5670 */

	{ 5200, 5200, 20, 0, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T1_5200_5200 */
	{ 5200, 5200, 18, 0, 40, 40, DFS_ETSI, NO_PSCAN, 0},	/* T2_5200_5200 */
	{ 5200, 5200, 15, 0, 40, 40, DFS_ETSI, NO_PSCAN, 0},	/* T3_5200_5200 */
	{ 5200, 5200, 17, 6, 40, 40, DFS_FCC3, NO_PSCAN, 0},	/* T4_5200_5200 */
	{ 5200, 5200, 23, 0, 40, 40, DFS_MKK4, NO_PSCAN, 0},	/* T5_5200_5200 */
	{ 5200, 5200, 20, 0, 40, 40, DFS_MKK4, NO_PSCAN, 0},	/* T6_5200_5200 */
	{ 5200, 5200, 30, 6, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T7_5200_5200 */
	{ 5200, 5200, 17, 6, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T8_5200_5200 */
	{ 5200, 5200, 30, 6, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T9_5200_5200 */

	{ 5200, 5280, 20, 0, 40, 40, DFS_ETSI, NO_PSCAN, 0},	/* T1_5200_5280 */
	{ 5200, 5280, 20, 0, 40, 40, DFS_ETSI, NO_PSCAN, 0},	/* T2_5200_5280 */
	{ 5200, 5280, 18, 0, 40, 40, DFS_ETSI, NO_PSCAN, 0},	/* T3_5200_5280 */
	{ 5200, 5280, 23, 0, 40, 40, DFS_ETSI, NO_PSCAN, 0},	/* T4_5200_5280 */
	{ 5200, 5280, 20, 0, 40, 40, DFS_MKK4, NO_PSCAN, 0},	/* T5_5200_5280 */
	{ 5200, 5280, 20, 0, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T6_5200_5280 */

	{ 5200, 5240, 17, 6, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T1_5200_5240 */
	{ 5210, 5210, 20, 6, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T1_5210_5210 */
	{ 5210, 5210, 20, 0, 40, 40, DFS_ETSI, NO_PSCAN, 0},	/* T2_5210_5210 */
	{ 5210, 5210, 18, 0, 40, 40, DFS_ETSI, NO_PSCAN, 0},	/* T3_5210_5210 */
	{ 5210, 5210, 17, 0, 40, 40, DFS_FCC3, NO_PSCAN, 0},	/* T4_5210_5210 */
	{ 5210, 5210, 15, 0, 40, 40, DFS_ETSI, NO_PSCAN, 0},	/* T5_5210_5210 */
	{ 5210, 5210, 17, 6, 40, 40, DFS_FCC3, NO_PSCAN, 0},	/* T6_5210_5210 */
	{ 5210, 5210, 30, 6, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T7_5210_5210 */
	{ 5210, 5210, 27, 6, 40, 40, DFS_FCC3, NO_PSCAN, 0},	/* T8_5210_5210 */
	{ 5210, 5210, 20, 0, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T9_5210_5210 */
	{ 5210, 5210, 20, 0, 40, 40, DFS_MKK4, NO_PSCAN, 0},	/* T10_5210_5210 */
	{ 5210, 5210, 30, 6, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T11_5210_5210 */
	{ 5240, 5240, 30, 6, 40, 40, NO_DFS, PSCAN_FCC_T, 0},	/* T1_5240_5240 */
	{ 5240, 5240, 30, 6, 40, 40, NO_DFS, PSCAN_FCC_T, 0},	/* T2_5240_5240 */

	{ 5210, 5250, 23, 0, 40, 40, DFS_ETSI, NO_PSCAN, 0},	/* T1_5210_5250 */
	{ 5210, 5290, 20, 0, 40, 40, DFS_ETSI, NO_PSCAN, 0},	/* T1_5210_5290 */
	{ 5210, 5290, 18, 0, 40, 40, DFS_ETSI, NO_PSCAN, 0},	/* T2_5210_5290 */
	{ 5210, 5290, 20, 0, 40, 40, DFS_MKK4, NO_PSCAN, 0},	/* T3_5210_5290 */

	{ 5280, 5280, 30, 0, 40, 40, NO_DFS, PSCAN_FCC_T, 0},	/* T1_5280_5280 */
	{ 5280, 5280, 30, 6, 40, 40, DFS_FCC3, PSCAN_FCC_T, 0},	/* T2_5280_5280 */
	{ 5280, 5280, 30, 6, 40, 40, DFS_FCC3, PSCAN_FCC_T, 0},	/* T3_5280_5280 */
	{ 5290, 5290, 17, 0, 40, 40, NO_DFS,   PSCAN_FCC_T, 0},	/* T1_5290_5290 */
	{ 5290, 5290, 30, 0, 40, 40, NO_DFS,  PSCAN_FCC_T, 0},	/* T2_5290_5290 */
	{ 5290, 5290, 20, 0, 40, 40, DFS_ETSI,  PSCAN_FCC_T, 0},/* T3_5290_5290 */
	{ 5250, 5290, 20, 0, 40, 40, DFS_ETSI, PSCAN_FCC_T, 0},	/* T1_5250_5290 */
	{ 5250, 5290, 23, 6, 40, 40, DFS_FCC3, PSCAN_FCC_T, 0},	/* T2_5250_5290 */
	{ 5250, 5290, 30, 6, 40, 40, NO_DFS, PSCAN_FCC_T, 0},	/* T3_5250_5290 */
	{ 5250, 5290, 27, 6, 40, 40, DFS_FCC3, PSCAN_FCC_T, 0},	/* T4_5250_5290 */
	{ 5250, 5290, 30, 6, 40, 40, NO_DFS, PSCAN_FCC_T, 0},	/* T5_5250_5290 */

	{ 5540, 5660, 30, 0, 40, 40, DFS_ETSI, PSCAN_FCC_T, 0},	/* T1_5540_5660 */
	{ 5540, 5660, 27, 0, 40, 40, DFS_ETSI, PSCAN_FCC_T, 0},	/* T2_5540_5660 */
	{ 5540, 5660, 20, 0, 40, 40, DFS_MKK4, PSCAN_FCC_T, 0},	/* T3_5540_5660 */
	{ 5760, 5800, 23, 0, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T1_5760_5800 */
	{ 5760, 5800, 30, 0, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T2_5760_5800 */
	{ 5760, 5800, 20, 0, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T3_5760_5800 */
	{ 5760, 5800, 17, 0, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T4_5760_5800 */
	{ 5760, 5800, 30, 0, 40, 40, DFS_ETSI, NO_PSCAN, 0},	/* T5_5760_5800 */
	{ 5760, 5800, 30, 6, 40, 40, DFS_ETSI, NO_PSCAN, 0},	/* T6_5760_5800 */
	{ 5760, 5800, 27, 6, 40, 40, DFS_FCC3, NO_PSCAN, 0},	/* T7_5760_5800 */

	{ 5765, 5805, 30, 0, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T1_5765_5805 */
	{ 5765, 5805, 23, 0, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T2_5765_5805 */
	{ 5765, 5805, 20, 0, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T3_5765_5805 */
	{ 5765, 5805, 17, 0, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T4_5765_5805 */
	{ 5765, 5805, 20, 0, 40, 40, DFS_ETSI, NO_PSCAN, 0},	/* T5_5765_5805 */
	{ 5765, 5805, 30, 0, 40, 40, DFS_ETSI, NO_PSCAN, 0},	/* T6_5765_5805 */
	{ 5765, 5805, 30, 6, 40, 40, NO_DFS, NO_PSCAN, 0},	/* T7_5765_5805 */
	{ 5765, 5805, 30, 6, 40, 40, DFS_FCC3, NO_PSCAN, 0},	/* T8_5765_5805 */
	{ 5765, 5805, 27, 6, 40, 40, DFS_FCC3, NO_PSCAN, 0},	/* T9_5765_5805 */
	/*
	 * Below are the WWR frequencies
	 */

	{ 5210, 5250, 15, 0, 40, 40, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, 0}, /* WT1_5210_5250 */
	{ 5290, 5290, 18, 0, 40, 40, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, 0}, /* WT1_5290_5290 */
	{ 5540, 5660, 20, 0, 40, 40, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, 0}, /* WT1_5540_5660 */
	{ 5760, 5800, 20, 0, 40, 40, NO_DFS, PSCAN_WWR, 0},	/* WT1_5760_5800 */
};
#endif /* #ifndef ATH_NO_5G_SUPPORT */

/*
 * 2GHz 11b channel tags
 */
enum {
	F1_2312_2372,
	F2_2312_2372,

	F1_2412_2472,
	F2_2412_2472,
	F3_2412_2472,
	F4_2412_2472,

	F1_2412_2462,
	F2_2412_2462,
	F3_2412_2462,

	F1_2432_2442,

	F1_2457_2472,

	F1_2467_2472,

	F1_2484_2484,
	F2_2484_2484,

	F1_2512_2732,

	W1_2312_2372,
	W1_2412_2412,
	W1_2417_2432,
	W1_2437_2442,
	W1_2447_2457,
	W1_2462_2462,
	W1_2467_2467,
	W2_2467_2467,
	W1_2472_2472,
	W2_2472_2472,
	W1_2484_2484,
	W2_2484_2484,
};

static const REG_DMN_FREQ_BAND regDmn2GhzFreq[] = {
	{ 2312, 2372, 5,  6, 20, 5, NO_DFS, NO_PSCAN, 0},	/* F1_2312_2372 */
	{ 2312, 2372, 20, 0, 20, 5, NO_DFS, NO_PSCAN, 0},	/* F2_2312_2372 */

	{ 2412, 2472, 5,  6, 20, 5, NO_DFS, NO_PSCAN, 0},	/* F1_2412_2472 */
	{ 2412, 2472, 30, 0, 20, 5, NO_DFS, PSCAN_MKKA, 30},/* F2_2412_2472 */
	{ 2412, 2472, 30, 0, 20, 5, NO_DFS, NO_PSCAN, 4},	/* F3_2412_2472 */
	{ 2412, 2472, 30, 0, 20, 5, NO_DFS, PSCAN_MKKA, 0},	/* F4_2412_2472 */

	{ 2412, 2462, 30, 6, 20, 5, NO_DFS, NO_PSCAN, 12},	/* F1_2412_2462 */
	{ 2412, 2462, 23, 0, 20, 5, NO_DFS, PSCAN_MKKA, 30},	/* F2_2412_2462 */
	{ 2412, 2462, 36, 0, 20, 5, NO_DFS, NO_PSCAN, 12},	/* F3_2412_2462 */

	{ 2432, 2442, 20, 0, 20, 5, NO_DFS, NO_PSCAN, 4},	/* F1_2432_2442 */

	{ 2457, 2472, 20, 0, 20, 5, NO_DFS, NO_PSCAN, 0},	/* F1_2457_2472 */

	{ 2467, 2472, 23, 0, 20, 5, NO_DFS, PSCAN_MKKA2 | PSCAN_MKKA, 30}, /* F1_2467_2472 */

	{ 2484, 2484, 5,  6, 20, 5, NO_DFS, NO_PSCAN, 0},	/* F1_2484_2484 */
	{ 2484, 2484, 23, 0, 20, 5, NO_DFS, PSCAN_MKKA | PSCAN_MKKA1 | PSCAN_MKKA2, 31},	/* F2_2484_2484 */

	{ 2512, 2732, 5,  6, 20, 5, NO_DFS, NO_PSCAN, 0},	/* F1_2512_2732 */

	/*
	 * WWR have powers opened up to 20dBm.  Limits should often come from CTL/Max powers
	 */

	{ 2312, 2372, 20, 0, 20, 5, NO_DFS, NO_PSCAN, 0},	/* W1_2312_2372 */
	{ 2412, 2412, 20, 0, 20, 5, NO_DFS, NO_PSCAN, 0},	/* W1_2412_2412 */
	{ 2417, 2432, 20, 0, 20, 5, NO_DFS, NO_PSCAN, 0},	/* W1_2417_2432 */
	{ 2437, 2442, 20, 0, 20, 5, NO_DFS, NO_PSCAN, 0},	/* W1_2437_2442 */
	{ 2447, 2457, 20, 0, 20, 5, NO_DFS, NO_PSCAN, 0},	/* W1_2447_2457 */
	{ 2462, 2462, 20, 0, 20, 5, NO_DFS, NO_PSCAN, 0},	/* W1_2462_2462 */
	{ 2467, 2467, 20, 0, 20, 5, NO_DFS, PSCAN_WWR | IS_ECM_CHAN, 0}, /* W1_2467_2467 */
	{ 2467, 2467, 20, 0, 20, 5, NO_DFS, NO_PSCAN | IS_ECM_CHAN, 0},	/* W2_2467_2467 */
	{ 2472, 2472, 20, 0, 20, 5, NO_DFS, PSCAN_WWR | IS_ECM_CHAN, 0}, /* W1_2472_2472 */
	{ 2472, 2472, 20, 0, 20, 5, NO_DFS, NO_PSCAN | IS_ECM_CHAN, 0},	/* W2_2472_2472 */
	{ 2484, 2484, 20, 0, 20, 5, NO_DFS, PSCAN_WWR | IS_ECM_CHAN, 0}, /* W1_2484_2484 */
	{ 2484, 2484, 20, 0, 20, 5, NO_DFS, NO_PSCAN | IS_ECM_CHAN, 0},	/* W2_2484_2484 */
};

/*
 * 2GHz 11g channel tags
 */

enum {
	G1_2312_2372,
	G2_2312_2372,

	G1_2412_2472,
	G2_2412_2472,
	G3_2412_2472,
	G4_2412_2472,

	G1_2412_2462,
	G2_2412_2462,
	G3_2412_2462,

	G1_2432_2442,

	G1_2457_2472,

	G1_2512_2732,

	G1_2467_2472,
	G2_2467_2472,

	G1_2484_2484,

	WG1_2312_2372,
	WG1_2412_2462,
	WG1_2412_2472,
	WG2_2412_2472,
	G_DEMO_ALMOST_ALL_CHANNELS,
	G_DEMO_ALL_CHANNELS,
    G_OVERRIDE_MODE_ALL_CHANNELS_20,
};

static const REG_DMN_FREQ_BAND regDmn2Ghz11gFreq[] = {
	{ 2312, 2372, 5,  6, 20, 5, NO_DFS, NO_PSCAN, 0},	/* G1_2312_2372 */
	{ 2312, 2372, 20, 0, 20, 5, NO_DFS, NO_PSCAN, 0},	/* G2_2312_2372 */

	{ 2412, 2472, 5,  6, 20, 5, NO_DFS, NO_PSCAN, 0},	/* G1_2412_2472 */
	{ 2412, 2472, 30, 0, 20, 5,  NO_DFS, PSCAN_MKKA_G | PSCAN_MKKA2 | PSCAN_MKKA | PSCAN_EXT_CHAN, 30},	/* G2_2412_2472 */
	{ 2412, 2472, 30, 0, 20, 5, NO_DFS, NO_PSCAN, 4},	/* G3_2412_2472 */
	{ 2412, 2472, 30, 0, 20, 5,  NO_DFS, PSCAN_MKKA_G | PSCAN_MKKA2 | PSCAN_MKKA | PSCAN_EXT_CHAN, 0},	/* G4_2412_2472 */

	{ 2412, 2462, 30, 6, 20, 5, NO_DFS, NO_PSCAN, 12},	/* G1_2412_2462 */
	{ 2412, 2462, 20, 0, 20, 5, NO_DFS, PSCAN_MKKA_G, 30},	/* G2_2412_2462 */
	{ 2412, 2462, 36, 0, 20, 5, NO_DFS, NO_PSCAN, 12},	/* G3_2412_2462 */

	{ 2432, 2442, 20, 0, 20, 5, NO_DFS, NO_PSCAN, 4},	/* G1_2432_2442 */

	{ 2457, 2472, 20, 0, 20, 5, NO_DFS, NO_PSCAN, 0},	/* G1_2457_2472 */

	{ 2512, 2732, 5,  6, 20, 5, NO_DFS, NO_PSCAN, 0},	/* G1_2512_2732 */

	{ 2467, 2472, 20, 0, 20, 5, NO_DFS, PSCAN_MKKA2 | PSCAN_MKKA, 30 }, /* G1_2467_2472 */
	{ 2467, 2472, 20, 0, 20, 5, NO_DFS, PSCAN_MKKA_G | PSCAN_MKKA2, 0 }, /* G2_2467_2472 */

	{ 2484, 2484, 5,  6, 20, 5, NO_DFS, NO_PSCAN, 0},	/* G1_2484_2484 */
	/*
	 * WWR open up the power to 20dBm
	 */

	{ 2312, 2372, 20, 0, 20, 5, NO_DFS, NO_PSCAN, 0},	/* WG1_2312_2372 */
	{ 2412, 2462, 20, 0, 20, 5, NO_DFS, NO_PSCAN, 0},	/* WG1_2412_2462 */
	{ 2412, 2472, 20, 0, 20, 5, NO_DFS, PSCAN_WWR | IS_ECM_CHAN | PSCAN_EXT_CHAN, 0}, /* WG1_2412_2472 */
	{ 2412, 2472, 20, 0, 20, 5, NO_DFS, NO_PSCAN | IS_ECM_CHAN, 0}, /* WG2_2412_2472 */
	{ 2312, 2532, 27, 6, 20, 5, NO_DFS, NO_PSCAN, 0}, 		/* G_DEMO_ALMOST_ALL_CHANNELS */
	{ 2312, 2732, 27, 6, 20, 5, NO_DFS, NO_PSCAN, 0}, 		/* G_DEMO_ALL_CHANNELS */
    { 2312, 2532, 50, 20, 20, 5, NO_DFS, NO_PSCAN, 0},       /* G_OVERRIDE_MODE_ALL_CHANNELS_20 */
};

/*
 * 2GHz Dynamic turbo tags
 */
#ifndef ATH_REMOVE_2G_TURBO_RD_TABLE
enum {
	T1_2312_2372,
	T1_2437_2437,
	T2_2437_2437,
	T3_2437_2437,
	T1_2512_2732
};

static const REG_DMN_FREQ_BAND regDmn2Ghz11gTurboFreq[] = {
	{ 2312, 2372, 5,  6, 40, 40, NO_DFS, NO_PSCAN, 0},  /* T1_2312_2372 */
	{ 2437, 2437, 5,  6, 40, 40, NO_DFS, NO_PSCAN, 0},  /* T1_2437_2437 */
	{ 2437, 2437, 30, 6, 40, 40, NO_DFS, NO_PSCAN, 0},  /* T2_2437_2437 */
	{ 2437, 2437, 18, 6, 40, 40, NO_DFS, PSCAN_WWR, 0}, /* T3_2437_2437 */
	{ 2512, 2732, 5,  6, 40, 40, NO_DFS, NO_PSCAN, 0},  /* T1_2512_2732 */
};
#endif /* ATH_REMOVE_2G_TURBO_RD_TABLE */

static const REG_DOMAIN ahCmnRegDomains[] = {

	{DEBUG_REG_DMN, FCC, DFS_FCC3, NO_PSCAN, NO_REQ,
	 CHAN_11A_BM(A_DEMO_ALL_CHANNELS,F6_5745_5825,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BM(T1_5130_5650, T1_5150_5670, F6_5745_5825,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BM(T1_5200_5240, T1_5280_5280, T1_5540_5660, T1_5765_5805,
                 -1, -1, -1, -1, -1, -1, -1, -1)
	 BM(F1_2312_2372, F1_2412_2472, F1_2484_2484, F1_2512_2732,
        -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(G_DEMO_ALMOST_ALL_CHANNELS,
        G1_2484_2484, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T1_2312_2372, T1_2437_2437, T1_2512_2732,
                     -1, -1, -1, -1, -1, -1, -1, -1, -1)
    },

    {OVER1_OVERA, NO_CTL, DFS_FCC3 | DFS_ETSI | DFS_MKK4, NO_PSCAN, NO_REQ,
     BM(OVERRIDE_MODE_ALL_CHANNELS_20, OVERRIDE_MODE_ALL_CHANNELS_10, OVERRIDE_MODE_ALL_CHANNELS_5, -1, -1, -1, -1, -1, -1, -1, -1, -1),
     BMZERO,
     BMZERO,
     BMZERO,
     BM(G_OVERRIDE_MODE_ALL_CHANNELS_20, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
     CHAN_TURBO_G_BMZERO
     },

#ifndef ATH_NO_5G_SUPPORT
	{APL1, FCC, NO_DFS, NO_PSCAN, NO_REQ,
	 BM(F4_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T2_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{APL2, FCC, NO_DFS, NO_PSCAN, NO_REQ,
	 BM(F1_5745_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T2_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{APL3, FCC, DFS_FCC3, PSCAN_FCC, NO_REQ,
	 BM(F1_5280_5320, F6_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5290_5290, T1_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{APL4, FCC, NO_DFS, NO_PSCAN, NO_REQ,
	 BM(F5_5180_5240,  F9_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5210_5210, T3_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5200_5200, T3_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{APL5, FCC, NO_DFS, NO_PSCAN, NO_REQ,
	 BM(F2_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T4_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T4_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{APL6, ETSI, DFS_ETSI, PSCAN_FCC_T | PSCAN_FCC , NO_REQ,
	 BM(F4_5180_5240, F2_5260_5320, F3_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T2_5210_5210, T1_5250_5290, T1_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5200_5280, T5_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{APL7, FCC, DFS_FCC3, PSCAN_FCC | PSCAN_ETSI , NO_REQ,
	 BM(F2_5280_5320, F2_5500_5580, F3_5660_5720, F10_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T3_5290_5290, T5_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5540_5660, T6_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{APL8, ETSI, DFS_ETSI, PSCAN_ETSI, DISALLOW_ADHOC_11A|DISALLOW_ADHOC_11A_TURB,
	 BM(F6_5260_5320, F4_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T2_5290_5290, T2_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5280_5280, T1_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{APL9, ETSI, DFS_KR, PSCAN_ETSI, DISALLOW_ADHOC_11A|DISALLOW_ADHOC_11A_TURB,
	 BM(F9_5180_5240, F7_5260_5320, F5_5500_5700, F10_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T3_5290_5290, T5_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5540_5660, T6_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{APL10, ETSI, DFS_FCC3, PSCAN_FCC, DISALLOW_ADHOC_11A|DISALLOW_ADHOC_11A_TURB,
	 BM(F15_5180_5240, F15_5260_5320, F5_5500_5700, F3_5745_5805, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T3_5290_5290, T5_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5540_5660, T6_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

 	{APL11, ETSI, DFS_ETSI, PSCAN_ETSI , DISALLOW_ADHOC_11A|DISALLOW_ADHOC_11A_TURB,
	 BM(F9_5180_5240, F2_5260_5320, F5_5500_5700, F7_5745_5825, F1_5845_5865, -1, -1, -1, -1, -1, -1, -1),
	 BM(T3_5290_5290, T5_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5540_5660, T6_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{APL12, ETSI, DFS_ETSI, PSCAN_ETSI, DISALLOW_ADHOC_11A|DISALLOW_ADHOC_11A_TURB,
	 BM(F5_5180_5240, F1_5500_5560, F1_5745_5765, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T2_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{APL13, ETSI, DFS_ETSI, PSCAN_ETSI, DISALLOW_ADHOC_11A|DISALLOW_ADHOC_11A_TURB,
	 BM(F5_5180_5240, F7_5260_5320, F2_5500_5660, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{APL14,FCC, DFS_CN, PSCAN_FCC | PSCAN_FCC_T, NO_REQ,
	 BM(F13_5180_5240, F11_5260_5320, F15_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T7_5210_5210, T3_5250_5290, T2_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T7_5200_5200, T1_5240_5240, T2_5280_5280, T1_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{APL15, FCC , NO_DFS, PSCAN_FCC_T | PSCAN_FCC, NO_REQ,
	 BM(F13_5180_5240, F10_5260_5320, F15_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T2_5210_5210, T1_5250_5290, T1_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5200_5280, T5_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{APL16, FCC, NO_DFS, PSCAN_FCC, NO_REQ,
	 BM(F14_5180_5240,F12_5260_5320, F4_5500_5580, F5_5660_5720, F13_5745_5825, -1, -1, -1, -1, -1, -1, -1),
	 BM(T7_5210_5210, T3_5250_5290, T2_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T7_5200_5200, T1_5240_5240, T2_5280_5280, T1_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

        {APL19, FCC, NO_DFS, PSCAN_FCC_T | PSCAN_FCC, NO_REQ,
         BM(F13_5180_5240, F10_5260_5320, F4_5745_5825, F2_5845_5865, -1, -1, -1, -1, -1, -1, -1, -1),
         CHAN_TURBO_G_BMZERO
         CHAN_TURBO_G_BMZERO
         BMZERO,
         BMZERO,
         CHAN_TURBO_G_BMZERO
     },

	{APL20, ETSI, DFS_ETSI, PSCAN_ETSI, NO_REQ,
	 BM(F13_5180_5240,F7_5260_5320, F2_5500_5720, F15_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{APL23, ETSI, NO_DFS, NO_PSCAN, NO_REQ,
	 BM(F16_5180_5240,F16_5260_5320, F3_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{ETSI1, ETSI, DFS_ETSI, PSCAN_ETSI, DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 BM(F5_5180_5240, F7_5260_5320, F3_5500_5700, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5210_5290, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T2_5200_5280, T2_5540_5660, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{ETSI2, ETSI, DFS_ETSI, PSCAN_ETSI, DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 BM(F3_5180_5240, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T3_5210_5210, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T2_5200_5200, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{ETSI3, ETSI, DFS_ETSI, PSCAN_ETSI, DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 BM(F4_5180_5240, F2_5260_5320, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5210_5290, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T2_5200_5280, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{ETSI4, ETSI, DFS_ETSI, PSCAN_ETSI, DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 BM(F3_5180_5240, F1_5260_5320, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T2_5210_5290, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T3_5200_5280, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{ETSI5, ETSI, DFS_ETSI, PSCAN_ETSI, DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 BM(F1_5180_5240, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T4_5210_5210, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T3_5200_5200, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{ETSI6, ETSI, DFS_ETSI, PSCAN_ETSI, DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 BM(F5_5180_5240, F1_5260_5280, F3_5500_5700, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5210_5250, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T4_5200_5280, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{ETSI8, ETSI, NO_DFS, NO_PSCAN, DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 BM(F13_5180_5240,F14_5260_5320, F8_5500_5720, F4_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5210_5290, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T2_5200_5280, T2_5540_5660, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 BMZERO
     },

	{ETSI9, ETSI, DFS_ETSI, PSCAN_ETSI, DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 BM(F13_5180_5240, F7_5260_5320, F8_5500_5700, F11_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5210_5290, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T2_5200_5280, T2_5540_5660, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 BMZERO
     },

	{ETSI10, ETSI, DFS_ETSI, PSCAN_ETSI, DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 BM(F4_5180_5240, F2_5260_5320, F2_5500_5700, F2_5860_5920, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5210_5290, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T2_5200_5280, T2_5540_5660, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{ETSI11, ETSI, DFS_ETSI, PSCAN_ETSI, DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 BM(F4_5180_5240, F2_5260_5320, F2_5500_5700, F1_5745_5865, F2_5745_5865, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5210_5290, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T2_5200_5280, T2_5540_5660, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{ETSI12, ETSI, DFS_ETSI, PSCAN_ETSI, DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 BM(F4_5180_5240, F2_5260_5320, F3_5500_5720, F16_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5210_5290, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T2_5200_5280, T2_5540_5660, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{ETSI13, ETSI, DFS_ETSI, PSCAN_ETSI, DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 BM(F5_5180_5240, F18_5260_5320, F2_5500_5720, F3_5745_5865, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5210_5290, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T2_5200_5280, T2_5540_5660, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{ETSI14, ETSI, DFS_ETSI, PSCAN_ETSI, DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 BM(F13_5180_5240, F18_5260_5320, F10_5500_5720, F4_5745_5865, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{FCC1, FCC, DFS_FCC3, PSCAN_FCC | PSCAN_FCC_T, NO_REQ,
	 BM(F2_5180_5240, F4_5260_5320, F5_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T6_5210_5210, T2_5250_5290, T6_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5200_5240, T2_5280_5280, T7_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{FCC2, FCC, DFS_FCC3, PSCAN_FCC | PSCAN_FCC_T, NO_REQ,
	 BM(F6_5180_5240, F5_5260_5320, F6_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T7_5210_5210, T3_5250_5290, T2_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T7_5200_5200, T1_5240_5240, T2_5280_5280, T1_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{FCC3, FCC, DFS_FCC3, PSCAN_FCC | PSCAN_FCC_T, NO_REQ,
	 BM(F12_5180_5240, F3_5260_5320, F1_5500_5720, F5_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T6_5210_5210, T2_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T4_5200_5200, T8_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },
         /*
     
          Bug Fix: EV 98583 Public Safety channel
          Exclude the following channel in FCC Public safety domain
          Uni-1: 5180, 5200, 5220, 5240 
          Uni-2: 5260, 5280, 5300, 5320 
          Uni-3: 5745, 5765, 5785, 5805, 5825 
         */
	{FCC4, FCC, DFS_FCC3, PSCAN_FCC | PSCAN_FCC_T, NO_REQ,
	 BM(F1_4942_4987, F1_4945_4985, F1_4950_4980, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T8_5210_5210, T4_5250_5290, T7_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5200_5240, T1_5280_5280, T9_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{FCC5, FCC, NO_DFS, NO_PSCAN, NO_REQ,
	 BM(F11_5180_5240, F6_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T6_5210_5210, T2_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T8_5200_5200, T7_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	{FCC6, FCC, DFS_FCC3, PSCAN_FCC, NO_REQ,
	 BM(F12_5180_5240, F5_5260_5320, F1_5500_5580, F2_5660_5720, F6_5745_5825, -1, -1, -1, -1, -1, -1, -1),
	 BM(T7_5210_5210, T3_5250_5290, T2_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T7_5200_5200, T1_5240_5240, T2_5280_5280, T1_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },
     
	{FCC7, FCC, DFS_FCC3, PSCAN_FCC, NO_REQ,
	 BM(F11_5180_5240, F8_5260_5320, F2_5500_5580, F3_5660_5720, F6_5745_5825, -1, -1, -1, -1, -1, -1, -1),
	 BM(T11_5210_5210, T5_5250_5290, T2_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T9_5200_5200, T2_5240_5240, T3_5280_5280, T1_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },
     
	{FCC8, FCC, DFS_FCC3, PSCAN_FCC, NO_REQ,
	 BM(F11_5180_5240, F3_5260_5320, F1_5500_5720, F5_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T7_5210_5210, T3_5250_5290, T2_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T7_5200_5200, T1_5240_5240, T2_5280_5280, T1_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },


	{FCC9, FCC, DFS_FCC3, PSCAN_FCC, NO_REQ,
	 BM(F11_5180_5240, F3_5260_5320, F1_5500_5720, F5_5745_5825,F1_5860_5920, F1_5875_5905, -1, -1, -1, -1, -1, -1),
	 BM(T6_5210_5210, T2_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T4_5200_5200, T8_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

    {FCC10, FCC, DFS_FCC3, PSCAN_FCC, NO_REQ,
     BM(F11_5180_5240, F3_5260_5320, F1_5500_5720, F5_5745_5825, F1_5860_5920, F1_5875_5905, -1, -1, -1, -1, -1, -1),
     BM(T6_5210_5210, T2_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
     BM(T4_5200_5200, T8_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
     BMZERO,
     BMZERO,
     CHAN_TURBO_G_BMZERO
     },

    {FCC11, FCC, DFS_FCC3, PSCAN_FCC, NO_REQ,
     BM(F12_5180_5240, F3_5260_5320, F1_5500_5640, F11_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1),
     BM(T6_5210_5210, T2_5760_5800, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
     BM(T4_5200_5200, T8_5765_5805, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
     BMZERO,
     BMZERO,
     CHAN_TURBO_G_BMZERO
     },

    {FCC13, FCC, NO_DFS, NO_PSCAN, NO_REQ,
     BM(F17_5180_5240, F17_5260_5320, F9_5500_5720, F4_5745_5825, -1, -1, -1, -1, -1, -1, -1, -1),
     BMZERO,
     BMZERO,
     BMZERO,
     BMZERO,
     CHAN_TURBO_G_BMZERO
     },

	{FCC14, FCC, NO_DFS, NO_PSCAN, NO_REQ,
	 BM(F18_5180_5240, F17_5260_5320,  F9_5500_5720 , F13_5745_5825 , -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	/* UNI-1 even */
	{MKK3, MKK, NO_DFS, PSCAN_MKK3, DISALLOW_ADHOC_11A_TURB,
	 BM(F4_5180_5240, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T9_5210_5210, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5200_5200, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	/* UNI-1 even + UNI-2 + mid-band */
	{MKK5, MKK, DFS_MKK4, PSCAN_MKK3, DISALLOW_ADHOC_11A_TURB,
	 BM(F5_5180_5240, F19_5260_5320, F9_5500_5700, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T3_5210_5290, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T5_5200_5280, T3_5540_5660, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	/* Japan UNI-1 even + UNI-2 + mid-band + 4.9GHz */
	{MKK11, MKK, DFS_MKK4, PSCAN_MKK3, DISALLOW_ADHOC_11A_TURB,
	 BM(F1_4912_4947, F1_5032_5057, F1_4915_4925, F1_4935_4945, F2_4920_4980, F1_5035_5045, F1_5055_5055, F2_5040_5080, F5_5180_5240, F18_5260_5320, F11_5500_5700, -1),
	 BM(T3_5210_5290, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(T1_5200_5280, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },

	/* Japan Outdoor */
	{MKK16, MKK, DFS_MKK4, PSCAN_MKK1 | PSCAN_MKK3, DISALLOW_ADHOC_11A_TURB,
	 BM(F6_5500_5700, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BMZERO,
	 BMZERO,
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },
#endif /* ATH_NO_5G_SUPPORT */

    /*=== 2 GHz ===*/

	/* Defined here to use when 2G channels are authorised for country K2 */
	{APLD, NO_CTL, NO_DFS, NO_PSCAN, NO_REQ,
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 BM(F2_2312_2372,F4_2412_2472, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(G2_2312_2372,G4_2412_2472, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
     CHAN_TURBO_G_BMZERO
    },

	{ETSIA, NO_CTL, NO_DFS, PSCAN_ETSIA, DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 BM(F1_2457_2472,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(G1_2457_2472,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T2_2437_2437,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{ETSIB, ETSI, NO_DFS, PSCAN_ETSIB, DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 BM(F1_2432_2442,-1,-1,-1,-1,-1,-1,-1, -1, -1, -1, -1),
	 BM(G1_2432_2442,-1,-1,-1,-1,-1,-1,-1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T2_2437_2437,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{ETSIC, ETSI, NO_DFS, PSCAN_ETSIC, DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 BM(F3_2412_2472,-1,-1,-1,-1,-1,-1,-1, -1, -1, -1, -1),
	 BM(G3_2412_2472,-1,-1,-1,-1,-1,-1,-1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T2_2437_2437,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{FCCA, FCC, NO_DFS, NO_PSCAN, NO_REQ,
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 BM(F1_2412_2462,-1,-1,-1,-1,-1,-1,-1, -1, -1, -1, -1),
	 BM(G1_2412_2462,-1,-1,-1,-1,-1,-1,-1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T2_2437_2437,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{FCCB, FCC, NO_DFS, NO_PSCAN, NO_REQ,
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 BM(F3_2412_2462,-1,-1,-1,-1,-1,-1,-1, -1, -1, -1, -1),
	 BM(G3_2412_2462,-1,-1,-1,-1,-1,-1,-1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BMZERO
     },

	{MKKA, MKK, NO_DFS, PSCAN_MKKA | PSCAN_MKKA_G | PSCAN_MKKA1 | PSCAN_MKKA1_G | PSCAN_MKKA2 | PSCAN_MKKA2_G, DISALLOW_ADHOC_11A_TURB,
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 BM(F2_2412_2462, F1_2467_2472, F2_2484_2484,
        -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 BM(G2_2412_2472, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T2_2437_2437,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{MKKC, MKK, NO_DFS, NO_PSCAN, NO_REQ,
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 BM(F2_2412_2472,-1,-1,-1,-1,-1,-1,-1, -1, -1, -1, -1),
	 BM(G2_2412_2472,-1,-1,-1,-1,-1,-1,-1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T2_2437_2437,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{WORLD, ETSI, NO_DFS, NO_PSCAN, NO_REQ,
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 BM(F4_2412_2472,-1,-1,-1,-1,-1,-1,-1, -1, -1, -1, -1),
	 BM(G4_2412_2472,-1,-1,-1,-1,-1,-1,-1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T2_2437_2437,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{WOR0_WORLD, NO_CTL, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, ADHOC_PER_11D,
	 CHAN_11A_BM(W1_5260_5320, W1_5180_5240, W1_5170_5230, W1_5745_5825,
                 W1_5500_5700, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BM(WT1_5210_5250, WT1_5290_5290, WT1_5760_5800,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BMZERO
	 BM(W1_2412_2412,W1_2437_2442,W1_2462_2462,W1_2472_2472,W1_2417_2432,
        W1_2447_2457, W1_2467_2467, W1_2484_2484, -1, -1, -1, -1),
	 BM(WG1_2412_2472,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T3_2437_2437, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{WOR01_WORLD, NO_CTL, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, ADHOC_PER_11D,
	 CHAN_11A_BM(W1_5260_5320, W1_5180_5240, W1_5170_5230, W1_5745_5825,
                 W1_5500_5700, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BM(WT1_5210_5250, WT1_5290_5290, WT1_5760_5800,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BMZERO
	 BM(W1_2412_2412, W1_2437_2442, W1_2462_2462, W1_2417_2432, W1_2447_2457,
        -1, -1, -1, -1, -1, -1, -1),
	 BM(WG1_2412_2462, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T3_2437_2437, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{WOR02_WORLD, NO_CTL, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, ADHOC_PER_11D,
	 CHAN_11A_BM(W1_5260_5320, W1_5180_5240,W1_5170_5230,W1_5745_5825,
                 W1_5500_5700, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BM(WT1_5210_5250, WT1_5290_5290, WT1_5760_5800,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BMZERO
	 BM(W1_2412_2412,W1_2437_2442,W1_2462_2462, W1_2472_2472,W1_2417_2432,
        W1_2447_2457, W1_2467_2467, -1, -1, -1, -1, -1),
	 BM(WG1_2412_2472,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T3_2437_2437, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{EU1_WORLD, NO_CTL, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, ADHOC_PER_11D,
	 CHAN_11A_BM(W1_5260_5320, W1_5180_5240,W1_5170_5230,W1_5745_5825,
                 W1_5500_5700, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BM(WT1_5210_5250, WT1_5290_5290, WT1_5760_5800,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BMZERO
	 BM(W1_2412_2412,W1_2437_2442,W1_2462_2462, W2_2472_2472,W1_2417_2432,
        W1_2447_2457, W2_2467_2467, -1, -1, -1, -1, -1),
	 BM(WG2_2412_2472,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T3_2437_2437, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{WOR1_WORLD, NO_CTL, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, ADHOC_NO_11A,
	 CHAN_11A_BM(W1_5260_5320, W1_5180_5240, W1_5170_5230, W1_5745_5825,
                 W1_5500_5700, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 BM(W1_2412_2412,W1_2437_2442,W1_2462_2462,W1_2472_2472,W1_2417_2432,
        W1_2447_2457, W1_2467_2467, W1_2484_2484, -1, -1, -1, -1),
	 BM(WG1_2412_2472,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T3_2437_2437, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{WOR2_WORLD, NO_CTL, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, ADHOC_NO_11A,
	 CHAN_11A_BM(W1_5260_5320, W1_5180_5240, W1_5170_5230, W1_5745_5825,
                 W1_5500_5700, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BM(WT1_5210_5250, WT1_5290_5290, WT1_5760_5800,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BMZERO
	 BM(W1_2412_2412,W1_2437_2442,W1_2462_2462,W1_2472_2472,W1_2417_2432,
        W1_2447_2457, W1_2467_2467, W1_2484_2484, -1, -1, -1, -1),
	 BM(WG1_2412_2472,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T3_2437_2437, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{WOR3_WORLD, NO_CTL, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, ADHOC_PER_11D,
	 CHAN_11A_BM(W1_5260_5320, W1_5180_5240, W1_5170_5230, W1_5745_5825,
                 -1, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BM(WT1_5210_5250, WT1_5290_5290, WT1_5760_5800,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BMZERO
	 BM(W1_2412_2412,W1_2437_2442,W1_2462_2462,W1_2472_2472,W1_2417_2432,
        W1_2447_2457, W1_2467_2467, -1, -1, -1, -1, -1),
	 BM(WG1_2412_2472,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T3_2437_2437, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{WOR4_WORLD, NO_CTL, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, ADHOC_NO_11A,
	 CHAN_11A_BM(W1_5260_5320, W1_5180_5240,W1_5745_5825,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BM(WT1_5210_5250, WT1_5290_5290, WT1_5760_5800,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BMZERO
	 BM(W1_2412_2412,W1_2437_2442,W1_2462_2462, W1_2417_2432,W1_2447_2457,
        -1, -1, -1, -1, -1, -1, -1),
	 BM(WG1_2412_2462,-1,-1,-1,-1,-1, -1, -1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T3_2437_2437, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{WOR5_ETSIC, NO_CTL, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, ADHOC_NO_11A,
	 CHAN_11A_BM(W1_5260_5320, W1_5180_5240,W1_5745_5825,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 BM(W1_2412_2412, W1_2437_2442, W1_2462_2462, W1_2472_2472, W1_2417_2432,
        W1_2447_2457, W1_2467_2467, -1, -1, -1, -1, -1),
	 BM(WG1_2412_2472,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T3_2437_2437, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{WOR9_WORLD, NO_CTL, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, ADHOC_NO_11A,
	 CHAN_11A_BM(W1_5260_5320, W1_5180_5240, W1_5745_5825, W1_5500_5700,
                 -1, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BM(WT1_5210_5250, WT1_5290_5290, WT1_5760_5800,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BMZERO
	 BM(W1_2412_2412, W1_2437_2442, W1_2462_2462, W1_2417_2432, W1_2447_2457,
        -1, -1, -1, -1, -1, -1, -1),
	 BM(WG1_2412_2462, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T3_2437_2437, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{WORA_WORLD, NO_CTL, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, ADHOC_NO_11A,
	 CHAN_11A_BM(W1_5260_5320, W1_5180_5240, W1_5745_5825, W1_5500_5700,
                 -1, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 BM(W1_2412_2412, W1_2437_2442, W1_2462_2462, W1_2472_2472, W1_2417_2432,
        W1_2447_2457, W1_2467_2467, -1, -1, -1, -1, -1),
	 BM(WG1_2412_2472,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T3_2437_2437, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{WORB_WORLD, NO_CTL, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, ADHOC_NO_11A,
	 CHAN_11A_BM(W1_5260_5320, W1_5180_5240, W1_5500_5700,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 BM(W1_2412_2412, W1_2437_2442, W1_2462_2462, W1_2472_2472, W1_2417_2432,
        W1_2447_2457, W1_2467_2467, -1, -1, -1, -1, -1),
	 BM(WG1_2412_2472,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T3_2437_2437, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{WORC_WORLD, NO_CTL, DFS_FCC3 | DFS_ETSI, PSCAN_WWR, ADHOC_PER_11D,
	 CHAN_11A_BM(W1_5260_5320, W1_5180_5240, W1_5500_5700, W1_5745_5825,
                 -1, -1, -1, -1, -1, -1, -1, -1)
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 BM(W1_2412_2412, W1_2437_2442, W1_2462_2462, W1_2472_2472, W1_2417_2432,
        W1_2447_2457, W1_2467_2467, -1, -1, -1, -1, -1),
	 BM(WG1_2412_2472,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
	 CHAN_TURBO_G_BM(T3_2437_2437, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
     },

	{NULL1, NO_CTL, NO_DFS, NO_PSCAN, NO_REQ,
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 CHAN_11A_BMZERO
	 BMZERO,
	 BMZERO,
	 CHAN_TURBO_G_BMZERO
     },
};

static const struct cmode modes[] = {
	{ REGDMN_MODE_TURBO,	        IEEE80211_CHAN_ST},	/* TURBO means 11a Static Turbo */
#ifndef ATH_NO_5G_SUPPORT
	{ REGDMN_MODE_11A,		        IEEE80211_CHAN_A},
#endif
	{ REGDMN_MODE_11B,		        IEEE80211_CHAN_B},
	{ REGDMN_MODE_11G,		        IEEE80211_CHAN_PUREG},
	{ REGDMN_MODE_11G_TURBO,	    IEEE80211_CHAN_108G},
#ifndef ATH_NO_5G_SUPPORT
	{ REGDMN_MODE_11A_TURBO,	    IEEE80211_CHAN_108A},
#endif
        { REGDMN_MODE_11NG_HT20,           IEEE80211_CHAN_11NG_HT20},
        { REGDMN_MODE_11NG_HT40PLUS,       IEEE80211_CHAN_11NG_HT40PLUS},
        { REGDMN_MODE_11NG_HT40MINUS,      IEEE80211_CHAN_11NG_HT40MINUS},
#ifndef ATH_NO_5G_SUPPORT
        { REGDMN_MODE_11NA_HT20,           IEEE80211_CHAN_11NA_HT20},
        { REGDMN_MODE_11NA_HT40PLUS,       IEEE80211_CHAN_11NA_HT40PLUS},
        { REGDMN_MODE_11NA_HT40MINUS,      IEEE80211_CHAN_11NA_HT40MINUS},
        { REGDMN_MODE_11AC_VHT20,          IEEE80211_CHAN_11AC_VHT20},
        { REGDMN_MODE_11AC_VHT40PLUS,      IEEE80211_CHAN_11AC_VHT40PLUS},
        { REGDMN_MODE_11AC_VHT40MINUS,     IEEE80211_CHAN_11AC_VHT40MINUS},
        { REGDMN_MODE_11AC_VHT80,          IEEE80211_CHAN_11AC_VHT80},
        { REGDMN_MODE_11AC_VHT160,         IEEE80211_CHAN_11AC_VHT160},
        { REGDMN_MODE_11AC_VHT80_80,       IEEE80211_CHAN_11AC_VHT80_80},
#endif
};

#ifndef ATH_NO_5G_SUPPORT
static const JAPAN_BANDCHECK j_bandcheck[] = { 
	{F4_5180_5240, REGDMN_EEPROM_EEREGCAP_EN_KK_U1_EVEN},
	{F2_5260_5320, REGDMN_EEPROM_EEREGCAP_EN_KK_U2},
};
#endif


static const COMMON_MODE_POWER common_mode_pwrtbl[] = {
	{ 4900, 5000, 17 },
	{ 5000, 5100, 17 },
	{ 5150, 5250, 17 }, /* ETSI & MKK */
	{ 5250, 5350, 18 }, /* ETSI */
	{ 5470, 5725, 20 }, /* ETSI */
	{ 5725, 5825, 20 }, /* Singapore */
	{ 5825, 5850, 23 }  /* Korea */
};

