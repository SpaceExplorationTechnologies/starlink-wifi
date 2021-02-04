/*
 * Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#define ATH_APB_BASE		0x18000000		/* 384M */

#define ATH_UART_BASE		(ATH_APB_BASE + 0x00020000)
#define ATH_RESET_BASE		(ATH_APB_BASE + 0x00060000)

#define ATH_REV_ID		(ATH_RESET_BASE + 0x90)

#define REG_OFFSET		4
#define OFS_LINE_STATUS		(5 * REG_OFFSET)
#define OFS_SEND_BUFFER		(0 * REG_OFFSET)

#define KSEG1			0xa0000000
#define KSEG1ADDR(a)		(((a) & 0x1fffffff) | KSEG1)

#define ath_reg_rd(_phys)		\
	(*(volatile unsigned int *)KSEG1ADDR(_phys))
#define ath_reg_wr_nf(_phys, _val)	\
	((*(volatile unsigned int *)KSEG1ADDR(_phys)) = (_val))
#define ath_reg_wr(_phys, _val) do {	\
	ath_reg_wr_nf(_phys, _val);	\
	ath_reg_rd(_phys);		\
}while(0);

#define UART16550_READ(y)	ath_reg_rd((ATH_UART_BASE + y))
#define UART16550_WRITE(x, z)	ath_reg_wr((ATH_UART_BASE + x), z)

void (*serial_putc) (char byte);

/* platform serial_putc */
static void _ath_serial_putc(char byte)
{
	if (byte == '\n') _ath_serial_putc ('\r');
	while (((UART16550_READ(OFS_LINE_STATUS)) & 0x20) == 0x0);
	UART16550_WRITE(OFS_SEND_BUFFER, byte);
}

static void (*hornet_serial_putc)(char) = (void *) 0xbfc00d88;

/* platform macros */
#define ATH_REV_ID_MASK		0xff0
#define REV_ID_HORNET		0x11
#define REV_ID_WASP		0x12
#define REV_ID_SCO		0x13

void serial_init(void)
{
	int revid = (ath_reg_rd(ATH_REV_ID) & ATH_REV_ID_MASK) >> 4;
	switch(revid) {
	case REV_ID_HORNET:
		serial_putc = hornet_serial_putc;
		break;
	case REV_ID_WASP:
		serial_putc = _ath_serial_putc;
		break;
	case REV_ID_SCO:
		serial_putc = _ath_serial_putc;
		break;
	default:
		/* die */
		serial_putc = (void *) 0xbadca11;
		break;
	}
}
