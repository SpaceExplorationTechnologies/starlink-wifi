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

#include "mem_use.h"
#include "asm/types.h"
#include "usb_std.h"
#include "usb_13320a_defs.h"
#include <asm/types.h>
#include <asm/addrspace.h>
#include <ar934x_soc.h>
#include "rom.addrs.h"

#define DOWNLOAD_USE_ROMBUF 0

#define writel(b,addr) (void)((*(volatile unsigned int *) (addr)) = (b))

#define readl(addr) \
    ({ unsigned int __v = (*(volatile unsigned int *) (addr)); __v; })

#define swap16(x) \
    ((((x) & 0xff00) >> 8) | \
     (((x) & 0x00ff) <<  8) )

#define cpu_to_le32(x) \
    ((((x) & 0xff000000) >> 24) | \
     (((x) & 0x00ff0000) >>  8) | \
     (((x) & 0x0000ff00) <<  8) | \
     (((x) & 0x000000ff) << 24))

#define swap32(x) cpu_to_le32(x)

#define TO_HW_ADDR(x) (((x) & 0x1FFFFFFF))  // Let first 3 bits to 0, EX: Transfer 0xBDxxxxxx->0x1Dxxxxxx


unsigned long firmware_dest_addr;
unsigned long firmware_curr_dest_addr;
unsigned long firmware_size;

static ENDPT0 *endpt0;

enum {
    OK,
    ERROR
};

int verify_firmware_checksum(__u32 addr, __u32 size)
{
    __u32 *data = (__u32 *) addr;
    __u32 checksum = 0;
    int i;

    for(i = 0; i < size; i += 4) {
        checksum = checksum ^ *data;
        data++;
    }

    return (checksum == 0) ? OK : ERROR;
}


typedef void (*firmware_func)(unsigned long, unsigned long);

void start_firmware(unsigned long entry, unsigned long firmware_size)
{
    firmware_func fw_func;

#define RESET_DELAY     3000
#define RST_RESET_ADDRESS               0x1806001c
#define RST_RESET_USB_PHY_SUSPEND_OVERRIDE_MASK     0x00000008
#define RST_RESET_USB_PHY_ARESET_MASK           0x00000800
#define RST_RESET_USB_PHY_RESET_MASK            0x00000010
#define RST_RESET_USB_HOST_RESET_MASK           0x00000020

    /* disable all USB interrupt */
    writel(0, CI13320A_USB_USBINTR);

    /* stop USB controller */
    writel(readl(CI13320A_USB_USBCMD) & (~1), CI13320A_USB_USBCMD);
    udelay(RESET_DELAY);
    /* disable USB phy to force disconnect */
    writel(readl(CI13320A_USB_PORTSC0) | (1 << 23), CI13320A_USB_PORTSC0);

    /* reset USB controller and phy */
    ar7240_reg_rmw_set(RST_RESET_ADDRESS, RST_RESET_USB_PHY_SUSPEND_OVERRIDE_MASK);
    udelay(RESET_DELAY);

    ar7240_reg_rmw_set(RST_RESET_ADDRESS, RST_RESET_USB_PHY_ARESET_MASK);
    udelay(RESET_DELAY);
    ar7240_reg_rmw_clear(RST_RESET_ADDRESS, RST_RESET_USB_PHY_ARESET_MASK);

    ar7240_reg_rmw_set(RST_RESET_ADDRESS, RST_RESET_USB_PHY_RESET_MASK);
    udelay(RESET_DELAY);
    ar7240_reg_rmw_clear(RST_RESET_ADDRESS, RST_RESET_USB_PHY_RESET_MASK);

    ar7240_reg_rmw_set(RST_RESET_ADDRESS, RST_RESET_USB_HOST_RESET_MASK);
    udelay(RESET_DELAY);
    ar7240_reg_rmw_clear(RST_RESET_ADDRESS, RST_RESET_USB_HOST_RESET_MASK);
    
    /* jump to firmware */
    if(entry) {
        fw_func = (void *) (entry);
        fw_func(entry, firmware_size);
    }
}

void do_endpt0_tx(int tx_total_bytes, __u8 *data)
{
    int i, maxDelay = 10000;
    __u8 *dst = (__u8 *) BUF1_BASE_ADDR;

    endpt0->rx.dtd->next_dtd |= cpu_to_le32(CI13320A_DTD_TERMINATE);

    /* copy data */
    for(i = 0; i < tx_total_bytes; i++)
        *dst++ = *data++;

    /* DTD handling */
    endpt0->tx.dtd->next_dtd |= cpu_to_le32(CI13320A_DTD_TERMINATE);
    endpt0->tx.dtd->size_ioc_status =  cpu_to_le32(
        (tx_total_bytes << CI13320A_DTD_TOTALBYTESSHFIT) | 
            CI13320A_DTD_IOC | CI13320A_DTD_ACTIVE);
    endpt0->tx.dtd->buff[0] = cpu_to_le32(TO_HW_ADDR(BUF1_BASE_ADDR));
    endpt0->tx.dtd->buff[1] = 0;

    /* QH handling */
    endpt0->tx.qh->maxPacketLen = cpu_to_le32(
        (CONTROL_MAX_PKT_SIZE << CI13320A_QH_SIZESHIFT) | 
            CI13320A_QH_ZLENGTH | CI13320A_QH_IOS);
    endpt0->tx.qh->size_ioc_status = 0;
    endpt0->tx.qh->curr_dtd = cpu_to_le32(TO_HW_ADDR(DTD1_ADDR));
    endpt0->tx.qh->next_dtd = cpu_to_le32(TO_HW_ADDR(DTD1_ADDR));

    /* prime the endpoint */
    writel(CI13320A_USBENDPTPRIME_ENDPT0_TX, CI13320A_USB_ENDPTPRIME);

    while(((readl(CI13320A_USB_ENDPTCOMPLETE) & CI13320A_USBENDPTPRIME_ENDPT0_TX) == 0) &&
          (maxDelay--)) {
        udelay(1);
    }

    writel(CI13320A_USBENDPTPRIME_ENDPT0_TX, CI13320A_USB_ENDPTCOMPLETE);
}

void do_endpt0_rx(unsigned long addr, int rx_total_bytes)
{
    int maxDelay = 10000;
    if (!addr)
        addr = BUF0_BASE_ADDR;

    /* DTD handling */
    endpt0->rx.dtd->next_dtd |= cpu_to_le32(CI13320A_DTD_TERMINATE);
    endpt0->rx.dtd->size_ioc_status = cpu_to_le32(
        (rx_total_bytes << CI13320A_DTD_TOTALBYTESSHFIT) | 
            CI13320A_DTD_IOC | CI13320A_DTD_ACTIVE);
    endpt0->rx.dtd->buff[0] = cpu_to_le32(TO_HW_ADDR(addr));
    endpt0->rx.dtd->buff[1] = 0;

    /* QH handling */
    endpt0->rx.qh->maxPacketLen = cpu_to_le32(
        (CONTROL_MAX_PKT_SIZE<<CI13320A_QH_SIZESHIFT) | 
            CI13320A_QH_ZLENGTH | CI13320A_QH_IOS);
    endpt0->rx.qh->size_ioc_status = 0;
    endpt0->rx.qh->curr_dtd = cpu_to_le32(TO_HW_ADDR(DTD0_ADDR));
    endpt0->rx.qh->next_dtd = cpu_to_le32(TO_HW_ADDR(DTD0_ADDR));

    writel( CI13320A_USBENDPTPRIME_ENDPT0_RX,CI13320A_USB_ENDPTPRIME);

    /* prime the endpoint */
    while(((readl(CI13320A_USB_ENDPTCOMPLETE) & CI13320A_USBENDPTPRIME_ENDPT0_RX) == 0) &&
          (maxDelay--)) {
        udelay(1);
    }

    writel(CI13320A_USBENDPTPRIME_ENDPT0_RX, CI13320A_USB_ENDPTCOMPLETE);
}

void handle_usb_vendor(struct usb_ctrlrequest *ctrl)
{

#ifdef ROMBOOTDRV_DOWNLOAD_LED_TOGGLE
#define LED_BIT_MASK 0x10
    static int current_LED_status = LED_BIT_MASK;
    static int nDownloadPacket = 0;
#endif

#if (UB124_STANDALONE == 1)
	#define FW2_SIZE (1024*3840) //FW2 Image Size
	#define FW2_FPOS 0xBF020000  //FW2 Flash Position
	#define FW2_RPOS 0x80400000  //FW2 Postion in RAM
	int i;
	unsigned long *src = (unsigned long *)FW2_FPOS, *dst = (unsigned long *)FW2_RPOS;

	if(ctrl == 0)
	{
		goto RUN_DIRECT;
	}
#endif

    if ((ctrl->bRequest == FIRMWARE1_DOWNLOAD) || 
        (ctrl->bRequest == FIRMWARE2_DOWNLOAD)) {
        __u32 total_txbytes,total_rxbytes;
#if DOWNLOAD_USE_ROMBUF
        int i = 0;
        __u32 *src_ptr= (__u32 *) (BUF0_BASE_ADDR);
        __u32 *dst_ptr = 0;
#endif

        if (firmware_dest_addr == 0) {
            firmware_dest_addr = (__u32)(ctrl->wValue << 16) + (__u32) ctrl->wIndex;
            firmware_curr_dest_addr = firmware_dest_addr;
            printf("Start: %x\n", firmware_dest_addr);
        }

        /* receive data */
        printf(".");
#ifdef ROMBOOTDRV_DOWNLOAD_LED_TOGGLE
        if (++nDownloadPacket > 60) {
            current_LED_status ^= LED_BIT_MASK;
            if (current_LED_status)
                ar7240_reg_wr_nf(0xb804000c, LED_BIT_MASK); // Turn LED On
            else
                ar7240_reg_wr_nf(0xb8040010, LED_BIT_MASK); // Turn LED off
            nDownloadPacket = 0; 
        }
#endif
        total_txbytes = 4096;
#if DOWNLOAD_USE_ROMBUF
        do_endpt0_rx(0, total_txbytes);
#else
        do_endpt0_rx(firmware_curr_dest_addr, total_txbytes);
#endif

        total_rxbytes = total_txbytes - 
            (__u32) (swap32(endpt0->rx.qh->size_ioc_status) >> CI13320A_DTD_TOTALBYTESSHFIT);

#if DOWNLOAD_USE_ROMBUF
        dst_ptr = (__u32 *) firmware_curr_dest_addr;
        /* copy fw to dest */
        for(i = 0; i < total_rxbytes >> 2; i++)
            *dst_ptr++ = *src_ptr++;
#endif

        /* housekeeping works */
        firmware_curr_dest_addr += total_rxbytes;
        firmware_size += total_rxbytes;
        do_endpt0_tx(0, 0);
    } else if ((ctrl->bRequest == FIRMWARE1_DOWNLOAD_COMP) || 
               (ctrl->bRequest == FIRMWARE2_DOWNLOAD_COMP)) {
        int ret = 1;
        __u32 firmware_entry = (__u32) (ctrl->wValue << 16) + (__u32) ctrl->wIndex;
#if (UB124_STANDALONE == 1)
RUN_DIRECT:
		serial_puts("Move stage2 fw\n");
        for(i=0;i<FW2_SIZE/4;i++)
        {
            *dst++ = *src++;
        }
		firmware_entry = FW2_RPOS;
        firmware_size = FW2_SIZE;
		serial_puts("Move done\n");
#endif


        ret = verify_firmware_checksum(firmware_dest_addr, firmware_size);
        printf("Comp: entry: %x size: %d check: %d\n", firmware_entry, firmware_size, ret);

        do_endpt0_tx(1, (__u8 *) &ret);
        do_endpt0_rx(0, 0);

        if(ret == OK)
		{
            start_firmware(firmware_entry, firmware_size);
		}
#if (UB124_STANDALONE == 1)
		else
		{
			serial_puts("Run although crc failed\n");
			serial_puts("Start Kernel\n");
            start_firmware(firmware_entry, firmware_size);
		}
#endif


        /* should not reach here */
        firmware_dest_addr = 0;
        firmware_curr_dest_addr = 0;
        firmware_size = 0;

        printf("return from firmware...");
#ifdef ROMBOOTDRV_DOWNLOAD_LED_TOGGLE
        while(1) {
            current_LED_status ^= LED_BIT_MASK;
            if (current_LED_status) {
                ar7240_reg_wr_nf(0xb804000c, LED_BIT_MASK); // Turn LED On
            } else {
                ar7240_reg_wr_nf(0xb8040010, LED_BIT_MASK); // Turn LED off
            }
            udelay(200000);
        }
#endif
    } else {
        printf("%s: %d\n", __func__, ctrl->bRequest);
    }
}

void handle_usb_setup(void)
{
    int i;
    struct usb_ctrlrequest ctrl;
    __u8 *ptr= (__u8*) &ctrl;

    for(i = 0; i < 8; i++) {
        *(ptr+i) = endpt0->rx.qh->setup_buff[i];
    }

    ctrl.wValue = swap16(ctrl.wValue);
    ctrl.wIndex = swap16(ctrl.wIndex);
    ctrl.wLength = swap16(ctrl.wLength);
    writel(CI13320A_USBSETUPSTAT_ENDPT0, CI13320A_USB_ENDPTSETUPSTAT);

    while((readl(CI13320A_USB_ENDPTSETUPSTAT) & CI13320A_USBSETUPSTAT_ENDPT0)!=0) {
        printf("Wait for clearing CI13320A_USB_ENDPTSETUPSTAT!\n");
    }

    if ((ctrl.bRequestType == SETUP_VENDOR_REQUEST_DL) || 
        (ctrl.bRequestType == SETUP_VENDOR_REQUEST_CMP)) {
        handle_usb_vendor(&ctrl);
        return;
    }

    printf("unhandled bRequest: %x\n", ctrl.bRequest);
}

void handle_usb(void)
{
    unsigned long endpt_setup_stat = readl(CI13320A_USB_ENDPTSETUPSTAT);
    unsigned long usb_status = readl(CI13320A_USB_USBSTS);

    writel(usb_status, CI13320A_USB_USBSTS);

    if (usb_status & CI13320A_USBSTS_ERROR_INTERRUPT)
        printf("usb_status: %lx\n", usb_status);
    if (endpt_setup_stat & CI13320A_USBSETUPSTAT_ENDPT0)
        handle_usb_setup();

#if (UB124_STANDALONE == 1)
	handle_usb_vendor(0);
#endif

}

void usb_fwd_main(void)
{
    firmware_dest_addr = 0;
    firmware_curr_dest_addr = 0;
    firmware_size = 0;

    endpt0 = ep0;

#ifdef ROMBOOTDRV_DOWNLOAD_LED_TOGGLE
    ar7240_reg_rmw_clear(0xb8040030, 0xFF); // Reset function of GPIO4 in bit7-0 of GPIO_OUT_FUNCTION1 register.
    ar7240_reg_rmw_clear(0xb8040000, 0x10); // Enable output for  GPIO4 in GPIO_OE register.
#endif
    while(1) {
        handle_usb();
    }
}

