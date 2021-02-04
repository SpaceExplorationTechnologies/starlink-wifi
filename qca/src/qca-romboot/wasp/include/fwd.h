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

#ifndef __FWD_H
#define __FWD_H

#include "asm/types.h"

typedef enum {
	A_FALSE,
	A_TRUE
}a_bool_t;

typedef enum {
	A_STATUS_OK,
	A_STATUS_FAILED,
	A_STATUS_ENOENT,
	A_STATUS_ENOMEM,
	A_STATUS_EINVAL,
	A_STATUS_EINPROGRESS,
	A_STATUS_ENOTSUPP,
	A_STATUS_EBUSY,
	A_STATUS_E2BIG,
	A_STATUS_EADDRNOTAVAIL,
	A_STATUS_ENXIO,
	A_STATUS_EFAULT,
	A_STATUS_EIO,
} a_status_t;

typedef __u8    a_uint8_t;
typedef __s8    a_int8_t;
typedef __u16   a_uint16_t;
typedef __s16   a_int16_t;
typedef __u32   a_uint32_t;
typedef __s32   a_int32_t;
typedef __u64   a_uint64_t;
typedef __s64   a_int64_t;


/* Ensure is aligned with WASP_BOOT_xxx defines in ar7240_soc.h */
enum hostif_s {
	HIF_USB		= 0x20,
	HIF_PCIE	= 0x21,
	HIF_GMAC	= 0x22,
	HIF_NAND	= 0x23,
	HIF_S27		= 0x02,

	// HIF should be added above here
	HIF_NUM		=    5,
	HIF_NONE	= 0xff
};

typedef enum hostif_s A_HOSTIF;


#define FWD_TGT_RX_BUFS     5

/*
 * XXX Pack 'em
 */
typedef struct {
	a_uint16_t	more_data,	/* Is there more data? */
			len;           /* Len this segment    */
	a_uint32_t	offset;        /* Offset in the file  */
} fwd_cmd_t;
/*
 * No enums across platforms
 */
#define FWD_RSP_ACK     0x1
#define FWD_RSP_SUCCESS 0x2
#define FWD_RSP_FAILED  0x3

typedef struct {
	a_uint32_t	rsp,       /* ACK/SUCCESS/FAILURE */
			offset;    /* rsp for this ofset  */
#ifdef pci_dma_test
#	define	rx_pkt_cksum	offset
#endif
} fwd_rsp_t;

typedef void * hif_handle_t;

typedef struct  {
	a_uint32_t		addr;
	hif_handle_t		hif_handle;
	a_uint8_t		rx_pipe;
	a_uint8_t		tx_pipe;
} fwd_tgt_softc_t;

#define MAX_MDIO_IO_LEN             14
#define MDIO_REG_WIDTH              4
#define MDIO_REG_BASE               0x180b8000

#define MDIO_REG_TO_OFFSET( __reg_number__)\
    (MDIO_REG_BASE + (MDIO_REG_WIDTH * (__reg_number__)))

#define MDIO_OWN_TGT                0x01
#define MDIO_OWN_HST                0x02
#define MDIO_REG_WRITE_DELAY        5 /* 5 micro seconds */


#define MDIO_FWD_RESET 0x01
#define MDIO_FWD_GOOD  0x02
#define MDIO_FWD_START 0x04
typedef struct mdio_bw_exec {
	a_uint32_t	start_address,
			length,
			exec_address,
			checksum;
	a_int32_t	fwd_state;
	a_uint8_t	*current_wr_ptr;
} mdio_bw_exec_t;

typedef enum mdio_reg_set {
	mdio_lock_reg	= 0x0,
	mdio_reg_start	= 0x0,
	mdio_reg_end	= MDIO_REG_TO_OFFSET(7)
} mdio_reg_set_t;

#define mii_reg_write_32(_addr, _val) ar7240_reg_wr(_addr, _val)
#define mii_reg_read_32(_addr) (ar7240_reg_rd(_addr))

#if 0
#define A_UART_PUTS serial_puts
#define A_UART_PUTU8 serial_putu8
#endif

#endif //__FWD_H

