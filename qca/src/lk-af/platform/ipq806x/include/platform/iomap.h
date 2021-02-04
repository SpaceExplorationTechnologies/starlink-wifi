/* Copyright (c) 2009-2015, The Linux Foundation. All rights reserved.
 *
 * Copyright (c) 2008, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _PLATFORM_IPQ806X_IOMAP_H_
#define _PLATFORM_IPQ806X_IOMAP_H_

#define CONFIG_IPQ806X_I2C
#define MSM_IOMAP_BASE			0x00100000
#define MSM_IOMAP_END			0x28000000

#define MSM_IMEM_BASE			0x2A000000

#define MSM_SHARED_IMEM_BASE		0x2A03F000
#define MSM_APPS_DLOAD_MAGIC1_ADDR	(MSM_SHARED_IMEM_BASE)
#define MSM_APPS_DLOAD_MAGIC2_ADDR	(MSM_SHARED_IMEM_BASE + 0x4)
#define RESTART_REASON_ADDR		(MSM_SHARED_IMEM_BASE + 0x65C)

#define MSM_SHARED_BASE			0x41000000

#define MSM_TCSR_BASE			0x1A400000
#define MSM_GIC_DIST_BASE		0x02000000
#define MSM_TMR_BASE			0x0200A000
#define MSM_GPT_BASE			(MSM_TMR_BASE + 0x04)
#define MSM_DGT_BASE			(MSM_TMR_BASE + 0x24)
#define SPSS_TIMER_STATUS		(MSM_TMR_BASE + 0x88)

#define GPT_REG(off)			(MSM_GPT_BASE + (off))
#define DGT_REG(off)			(MSM_DGT_BASE + (off))

#define GPT_MATCH_VAL			GPT_REG(0x0000)
#define GPT_COUNT_VAL			GPT_REG(0x0004)
#define GPT_ENABLE			GPT_REG(0x0008)
#define GPT_CLEAR			GPT_REG(0x000C)

#define DGT_MATCH_VAL			DGT_REG(0x0000)
#define DGT_COUNT_VAL			DGT_REG(0x0004)
#define DGT_ENABLE			DGT_REG(0x0008)
#define DGT_CLEAR			DGT_REG(0x000C)
#define DGT_CLK_CTL			DGT_REG(0x0010)

#define MSM_GIC_CPU_BASE		0x02002000
#define MSM_VIC_BASE			0x02080000
#define MSM_TCSR_SIZE			4096
#define MSM_USB_BASE			0x12500000
#define TLMM_BASE_ADDR			0x00800000

#define TCSR_WDOG_CFG			0x30
#define MSM_WDT0_RST			(MSM_TMR_BASE + 0x38)
#define MSM_WDT0_EN			(MSM_TMR_BASE + 0x40)
#define MSM_WDT0_BT			(MSM_TMR_BASE + 0x4C)
#define MSM_PSHOLD_CTL_SU		(TLMM_BASE_ADDR + 0x820)

#define MSM_SDC1_BASE			0x12400000
#define MSM_SDC1_BAM_BASE		0x12402000
#define MSM_SDC1_DML_BASE		0x12400800

#define MSM_SDC2_BASE			0x12140000
#define MSM_SDC2_BAM_BASE		0x12142000
#define MSM_SDC2_DML_BASE		0x12140800

#define MSM_SDC3_BASE			0x12180000
#define MSM_SDC3_BAM_BASE		0x12182000
#define MSM_SDC3_DML_BASE		0x12180800

#define MSM_SDC4_BASE			0x121c0000
#define MSM_SDC4_BAM_BASE		0x121c2000
#define MSM_SDC4_DML_BASE		0x121c0800

#define GPIO_CONFIG_ADDR(x)		(TLMM_BASE_ADDR + 0x1000 + (x)*0x10)
#define GPIO_IN_OUT_ADDR(x)		(TLMM_BASE_ADDR + 0x1004 + (x)*0x10)
#define GSBIn_UART_I2C_SEL(x)		(TLMM_BASE_ADDR + 0x20D0 + (x)*0x4)


#define GSBI_BASE(id)         ((id) <= 2 ? (0x12440000 + (0x40000 * ((id)-1))) : \
                                           (0x16200000 + (((id)-3) << 20)))
#define QUP_BASE(id)          ((id) <= 2 ? (GSBI_BASE(id) + 0x20000) : \
						(GSBI_BASE(id) + 0x80000))
#define I2C_GSBI2_BASE          UART_GSBI2_BASE
#define I2C_GSBI4_BASE          UART_GSBI4_BASE

#define UART1_DM_BASE			0x12450000
#define UART_GSBI1_BASE			0x12440000
#define UART2_DM_BASE			0x12490000
#define UART_GSBI2_BASE			0x12480000
#define UART4_DM_BASE			0x16340000
#define UART_GSBI4_BASE			0x16300000

#define EBI2_CHIP_SELECT_CFG0		0x1A100000
#define EBI2_XMEM_CS3_CFG1		0x1A110034

#define MSM_CLK_CTL_BASE		0x00900000

#define CE1_CRYPTO4_BASE		(0x18500000)
#define CE3_CRYPTO4_BASE		(0x11000000)

#define NSS_GMAC0_BASE			0x37000000
#define NSS_GMAC1_BASE			0x37200000
#define NSS_GMAC2_BASE			0x37400000
#define NSS_GMAC3_BASE			0x37600000

#define GMAC_CORE_RESET(n)	((void *)(0x903CBC + ((n) * 0x20)))
#define GMACSEC_CORE_RESET(n)	((void *)(0x903E28 + ((n - 1) * 4)))
#define GMAC_AHB_RESET		0x903E24

#endif
