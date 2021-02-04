/* Copyright (c) 2010-2011,2013,2017, The Linux Foundation. All rights reserved.
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
 */

#ifndef _IPQ806x_H
#define _IPQ806x_H

#define LCC_PLL0_MODE                   0x0
#define LCC_PLL0_L_VAL                  0x4
#define LCC_PLL0_M_VAL                  0x8
#define LCC_PLL0_N_VAL                  0xC
#define LCC_PLL0_CONFIG                 0x14
#define LCC_PLL0_TEST_CTL               0x10
#define LCC_CODEC_I2S_MIC_NS            0x60
#define LCC_CODEC_I2S_SPKR_NS           0x6c
#define LCC_SPARE_I2S_MIC_NS            0x78
#define LCC_SPARE_I2S_SPKR_NS           0x84
#define LCC_AVT_NS                      0x90
#define LCC_PXO_SRC_CTL                 0xB4
#define LCC_AHBIX_NS                    0x38
#define LCC_PLL0_TEST_CTL               0x10
#define LCC_PLL0_CONFIG                 0x14
#define LCC_PRI_PLL_CLK_CTL             0xC4
#define LCC_SPDM_CYCNTR_CLK_CTL         0xB8
#define LCC_AHBIX_MD                    0x3c
#define LCC_AHBIX_NS                    0x38
#define LCC_MI2S_NS                     0x48
#define LCC_MI2S_MD                     0x4c
#define LCC_CODEC_I2S_MIC_NS            0x60
#define LCC_CODEC_I2S_MIC_MD            0x64
#define LCC_SLIMBUS_NS                  0xCC
#define LCC_SLIMBUS_MD                  0xD0
#define LCC_AHBEX_BRANCH_CTL            0xE4
#define LCC_PCM_MD                      0x58
#define LCC_PCM_NS                      0x54
#define LCC_SPARE_I2S_SPKR_MD           0x88
#define LCC_SPARE_I2S_MIC_MD            0x7c
#define LCC_CODEC_I2S_SPKR_NS           0x6c
#define LCC_CODEC_I2S_SPKR_MD           0x70
#define LCC_CODEC_I2S_SPKR_NS           0x6c

#define HWIO_LCC_PXO_SRC_CTL_PXO_SRC_SEL_BMSK           0x4
#define HWIO_LCC_PXO_SRC_CTL_PXO_SRC_SEL_SHFT           0x2
#define HWIO_LCC_PXO_SRC_CTL_GFM_CXO_SRC_SEL_BMSK       0x1
#define HWIO_LCC_PXO_SRC_CTL_GFM_CXO_SRC_SEL_SHFT       0
#define HWIO_LCC_PLL0_CONFIG_FRAC_MODE_EN_BMSK          0x400000
#define HWIO_LCC_PLL0_CONFIG_FRAC_MODE_EN_SHFT          0x16
#define HWIO_LCC_PLL0_CONFIG_VCO_SEL_BMSK               0x30000
#define HWIO_LCC_PLL0_MODE_REF_XO_SEL_BMSK              0x30
#define HWIO_LCC_PLL0_MODE_REF_XO_SEL_SHFT              0x4
#define HWIO_LCC_PLL0_MODE_BYPASSNL_BMSK                0x2
#define HWIO_LCC_PLL0_MODE_RESET_N_BMSK                 0x4
#define HWIO_LCC_PLL0_MODE_BYPASSNL_SHFT                0x1
#define HWIO_LCC_PLL0_MODE_RESET_N_SHFT                 0x2
#define HWIO_LCC_AHBIX_NS_GFM_SRC_SEL_SHFT              0xa
#define HWIO_LCC_AHBIX_NS_GFM_SRC_SEL_BMSK              0x400
#define HWIO_LCC_PLL0_CONFIG_VCO_SEL_SHFT               0x10
#define HWIO_LCC_PLL0_MODE_OUTCTRL_BMSK                 0x1
#define HWIO_LCC_PLL0_MODE_OUTCTRL_SHFT                 0
#define HWIO_LCC_PRI_PLL_CLK_CTL_GFM_PRI_PLL_SRC_SEL_BMSK       0x1
#define HWIO_LCC_PRI_PLL_CLK_CTL_GFM_PRI_PLL_SRC_SEL_SHFT       0
#define HWIO_LCC_SPDM_CYCNTR_CLK_CTL_CXC_EN_BMSK        0x2
#define HWIO_LCC_SPDM_CYCNTR_CLK_CTL_CXC_EN_SHFT        0x1
#define HWIO_LCC_SPDM_CYCNTR_CLK_CTL_CXC_EN_BMSK        0x2
#define HWIO_LCC_SPDM_CYCNTR_CLK_CTL_CXC_EN_SHFT        0x1
#define HWIO_LCC_SPDM_CYCNTR_CLK_CTL_CRC_EN_BMSK        0x1
#define HWIO_LCC_SPDM_CYCNTR_CLK_CTL_CRC_EN_SHFT        0
#define HWIO_LCC_SPDM_CYCNTR_CLK_CTL_FUNC_DIV_SEL_BMSK  0x18
#define HWIO_LCC_SPDM_CYCNTR_CLK_CTL_FUNC_DIV_SEL_SHFT  0x3
#define HWIO_LCC_AHBIX_MD_M_VAL_BMSK                    0xff00
#define HWIO_LCC_AHBIX_MD_M_VAL_SHFT                    0x8
#define HWIO_LCC_AHBIX_MD_NOT_2D_VAL_BMSK               0xff
#define HWIO_LCC_AHBIX_MD_NOT_2D_VAL_SHFT               0
#define HWIO_LCC_AHBIX_NS_MN_SRC_SEL_BMSK               0x7
#define HWIO_LCC_AHBIX_NS_MN_SRC_SEL_SHFT               0
#define HWIO_LCC_AHBIX_NS_MNCNTR_MODE_BMSK              0x60
#define HWIO_LCC_AHBIX_NS_MNCNTR_MODE_SHFT              0x5
#define HWIO_LCC_AHBIX_NS_PRE_DIV_SEL_BMSK              0x18
#define HWIO_LCC_AHBIX_NS_PRE_DIV_SEL_SHFT              0x3
#define HWIO_LCC_AHBIX_NS_MN_SRC_SEL_BMSK               0x7
#define HWIO_LCC_AHBIX_NS_MN_SRC_SEL_SHFT               0
#define HWIO_LCC_AHBIX_NS_MNCNTR_EN_BMSK                0x100
#define HWIO_LCC_AHBIX_NS_N_VAL_BMSK                    0xff000000
#define HWIO_LCC_AHBIX_NS_MN_SRC_SEL_SHFT               0
#define HWIO_LCC_AHBIX_NS_MNCNTR_MODE_SHFT              0x5
#define HWIO_LCC_AHBIX_NS_MNCNTR_EN_SHFT                0x8
#define HWIO_LCC_AHBIX_NS_N_VAL_SHFT                    0x18
#define HWIO_LCC_MI2S_NS_OSR_CXC_EN_BMSK                0x20000
#define HWIO_LCC_MI2S_NS_OSR_CXC_EN_SHFT                0x11
#define HWIO_LCC_MI2S_NS_BIT_INV_EN_BMSK                0x10000
#define HWIO_LCC_MI2S_NS_BIT_INV_EN_SHFT                0x10
#define HWIO_LCC_MI2S_NS_BIT_CXC_EN_BMSK                0x8000
#define HWIO_LCC_MI2S_NS_BIT_CXC_EN_SHFT                0xf
#define HWIO_LCC_MI2S_MD_M_VAL_BMSK                     0xff00
#define HWIO_LCC_MI2S_MD_M_VAL_SHFT                     0x8
#define HWIO_LCC_MI2S_MD_NOT_2D_VAL_BMSK                0xff
#define HWIO_LCC_MI2S_MD_NOT_2D_VAL_SHFT                0
#define HWIO_LCC_MI2S_NS_N_VAL_BMSK                     0xff000000
#define HWIO_LCC_MI2S_NS_N_VAL_SHFT                     0x18
#define HWIO_LCC_MI2S_NS_RESERVED_23_20_BMSK            0xf00000
#define HWIO_LCC_MI2S_NS_RESERVED_23_20_SHFT            0x14
#define HWIO_LCC_MI2S_NS_ARES_BMSK                      0x80000
#define HWIO_LCC_MI2S_NS_ARES_SHFT                      0x13
#define HWIO_LCC_MI2S_NS_OSR_INV_EN_BMSK                0x40000
#define HWIO_LCC_MI2S_NS_OSR_INV_EN_SHFT                0x12
#define HWIO_LCC_MI2S_NS_OSR_CXC_EN_BMSK                0x20000
#define HWIO_LCC_MI2S_NS_OSR_CXC_EN_SHFT                0x11
#define HWIO_LCC_MI2S_NS_BIT_INV_EN_BMSK                0x10000
#define HWIO_LCC_MI2S_NS_BIT_INV_EN_SHFT                0x10
#define HWIO_LCC_MI2S_NS_BIT_CXC_EN_BMSK                0x8000
#define HWIO_LCC_MI2S_NS_BIT_CXC_EN_SHFT                0xf
#define HWIO_LCC_MI2S_NS_MNCNTR_MODE_BMSK               0x60
#define HWIO_LCC_MI2S_NS_MNCNTR_EN_BMSK                 0x100
#define HWIO_LCC_MI2S_NS_PRE_DIV_SEL_BMSK               0x18
#define HWIO_LCC_MI2S_NS_MN_SRC_SEL_BMSK                0x7
#define HWIO_LCC_MI2S_NS_BIT_DIV_BMSK                   0x3c00
#define HWIO_LCC_MI2S_NS_N_VAL_SHFT                     0x18
#define HWIO_LCC_MI2S_NS_MNCNTR_MODE_SHFT               0x5
#define HWIO_LCC_MI2S_NS_MNCNTR_EN_SHFT                 0x8
#define HWIO_LCC_MI2S_NS_MN_SRC_SEL_SHFT                0
#define HWIO_LCC_MI2S_NS_BIT_DIV_SHFT                   0xa
#define HWIO_LCC_CODEC_I2S_MIC_NS_OSR_CXC_EN_BMSK       0x200000
#define HWIO_LCC_CODEC_I2S_MIC_NS_BIT_CXC_EN_BMSK       0x80000
#define HWIO_LCC_CODEC_I2S_MIC_NS_OSR_CXC_EN_SHFT       0x15
#define HWIO_LCC_CODEC_I2S_MIC_NS_BIT_CXC_EN_SHFT       0x13
#define HWIO_LCC_CODEC_I2S_MIC_MD_M_VAL_BMSK            0xff00
#define HWIO_LCC_CODEC_I2S_MIC_MD_M_VAL_SHFT            0x8
#define HWIO_LCC_CODEC_I2S_MIC_MD_NOT_2D_VAL_BMSK       0xff
#define HWIO_LCC_CODEC_I2S_MIC_MD_NOT_2D_VAL_SHFT       0
#define HWIO_LCC_CODEC_I2S_MIC_NS_N_VAL_BMSK            0xff000000
#define HWIO_LCC_CODEC_I2S_MIC_NS_MNCNTR_EN_BMSK        0x100
#define HWIO_LCC_CODEC_I2S_MIC_NS_MNCNTR_MODE_BMSK      0x60
#define HWIO_LCC_CODEC_I2S_MIC_NS_MN_SRC_SEL_BMSK       0x7
#define HWIO_LCC_CODEC_I2S_MIC_NS_MN_SRC_SEL_SHFT       0
#define HWIO_LCC_CODEC_I2S_MIC_NS_BIT_SRC_SEL_BMSK      0x40000
#define HWIO_LCC_CODEC_I2S_MIC_NS_BIT_DIV_BMSK          0x3fc00
#define HWIO_LCC_CODEC_I2S_MIC_NS_N_VAL_SHFT            0x18
#define HWIO_LCC_CODEC_I2S_MIC_NS_MNCNTR_EN_SHFT        0x8
#define HWIO_LCC_CODEC_I2S_MIC_NS_MNCNTR_MODE_SHFT      0x5
#define HWIO_LCC_CODEC_I2S_MIC_NS_BIT_SRC_SEL_SHFT      0x12
#define HWIO_LCC_CODEC_I2S_MIC_NS_BIT_DIV_SHFT          0xa
#define HWIO_LCC_CODEC_I2S_SPKR_NS_OSR_CXC_EN_BMSK      0x200000
#define HWIO_LCC_CODEC_I2S_SPKR_NS_BIT_CXC_EN_BMSK      0x80000
#define HWIO_LCC_CODEC_I2S_SPKR_NS_OSR_CXC_EN_SHFT      0x15
#define HWIO_LCC_CODEC_I2S_SPKR_NS_BIT_CXC_EN_SHFT      0x13
#define HWIO_LCC_CODEC_I2S_SPKR_MD_M_VAL_BMSK           0xff00
#define HWIO_LCC_CODEC_I2S_SPKR_MD_M_VAL_SHFT           0x8
#define HWIO_LCC_CODEC_I2S_SPKR_MD_NOT_2D_VAL_BMSK      0xff
#define HWIO_LCC_CODEC_I2S_SPKR_MD_NOT_2D_VAL_SHFT      0
#define HWIO_LCC_CODEC_I2S_SPKR_NS_N_VAL_BMSK           0xff000000
#define HWIO_LCC_CODEC_I2S_SPKR_NS_MNCNTR_EN_BMSK       0x100
#define HWIO_LCC_CODEC_I2S_SPKR_NS_MNCNTR_MODE_BMSK     0x60
#define HWIO_LCC_CODEC_I2S_SPKR_NS_MN_SRC_SEL_BMSK      0x7
#define HWIO_LCC_CODEC_I2S_SPKR_NS_BIT_SRC_SEL_BMSK     0x40000
#define HWIO_LCC_CODEC_I2S_SPKR_NS_BIT_DIV_BMSK         0x3fc00
#define HWIO_LCC_CODEC_I2S_SPKR_NS_N_VAL_SHFT           0x18
#define HWIO_LCC_CODEC_I2S_SPKR_NS_MNCNTR_EN_SHFT       0x8
#define HWIO_LCC_CODEC_I2S_SPKR_NS_MNCNTR_MODE_SHFT     0x5
#define HWIO_LCC_CODEC_I2S_SPKR_NS_BIT_SRC_SEL_SHFT     0x12
#define HWIO_LCC_CODEC_I2S_SPKR_NS_MN_SRC_SEL_SHFT      0
#define HWIO_LCC_CODEC_I2S_SPKR_NS_BIT_DIV_SHFT         0xa
#define HWIO_LCC_SPARE_I2S_MIC_NS_OSR_CXC_EN_BMSK       0x200000
#define HWIO_LCC_SPARE_I2S_MIC_NS_BIT_CXC_EN_BMSK       0x80000
#define HWIO_LCC_SPARE_I2S_MIC_NS_OSR_CXC_EN_SHFT       0x15
#define HWIO_LCC_SPARE_I2S_MIC_NS_BIT_CXC_EN_SHFT       0x13
#define HWIO_LCC_SPARE_I2S_MIC_MD_M_VAL_BMSK            0xff00
#define HWIO_LCC_SPARE_I2S_MIC_MD_M_VAL_SHFT            0x8
#define HWIO_LCC_SPARE_I2S_MIC_MD_NOT_2D_VAL_BMSK       0xff
#define HWIO_LCC_SPARE_I2S_MIC_MD_NOT_2D_VAL_SHFT       0
#define HWIO_LCC_SPARE_I2S_MIC_NS_N_VAL_BMSK            0xff000000
#define HWIO_LCC_SPARE_I2S_MIC_NS_MNCNTR_EN_BMSK        0x100
#define HWIO_LCC_SPARE_I2S_MIC_NS_MNCNTR_MODE_BMSK      0x60
#define HWIO_LCC_SPARE_I2S_MIC_NS_MN_SRC_SEL_BMSK       0x7
#define HWIO_LCC_SPARE_I2S_MIC_NS_BIT_DIV_BMSK          0x3fc00
#define HWIO_LCC_SPARE_I2S_MIC_NS_N_VAL_SHFT            0x18
#define HWIO_LCC_SPARE_I2S_MIC_NS_MNCNTR_EN_SHFT        0x8
#define HWIO_LCC_SPARE_I2S_MIC_NS_MNCNTR_MODE_SHFT      0x5
#define HWIO_LCC_SPARE_I2S_MIC_NS_MN_SRC_SEL_SHFT       0
#define HWIO_LCC_SPARE_I2S_MIC_NS_BIT_DIV_SHFT          0xa
#define HWIO_LCC_SPARE_I2S_SPKR_NS_OSR_CXC_EN_BMSK      0x200000
#define HWIO_LCC_SPARE_I2S_SPKR_NS_BIT_CXC_EN_BMSK      0x80000
#define HWIO_LCC_SPARE_I2S_SPKR_NS_OSR_CXC_EN_SHFT      0x15
#define HWIO_LCC_SPARE_I2S_SPKR_NS_BIT_CXC_EN_SHFT      0x13
#define HWIO_LCC_SPARE_I2S_SPKR_MD_M_VAL_BMSK           0xff00
#define HWIO_LCC_SPARE_I2S_SPKR_MD_M_VAL_SHFT           0x8
#define HWIO_LCC_SPARE_I2S_SPKR_MD_NOT_2D_VAL_BMSK      0xff
#define HWIO_LCC_SPARE_I2S_SPKR_MD_NOT_2D_VAL_SHFT      0
#define HWIO_LCC_SPARE_I2S_SPKR_NS_N_VAL_BMSK           0xff000000
#define HWIO_LCC_SPARE_I2S_SPKR_NS_MNCNTR_EN_BMSK       0x100
#define HWIO_LCC_SPARE_I2S_SPKR_NS_MNCNTR_MODE_BMSK     0x60
#define HWIO_LCC_SPARE_I2S_SPKR_NS_MN_SRC_SEL_BMSK      0x7
#define HWIO_LCC_SPARE_I2S_SPKR_NS_BIT_DIV_BMSK         0x3fc00
#define HWIO_LCC_SPARE_I2S_SPKR_NS_N_VAL_SHFT           0x18
#define HWIO_LCC_SPARE_I2S_SPKR_NS_MNCNTR_EN_SHFT       0x8
#define HWIO_LCC_SPARE_I2S_SPKR_NS_MNCNTR_MODE_SHFT     0x5
#define HWIO_LCC_SPARE_I2S_SPKR_NS_MN_SRC_SEL_SHFT      0
#define HWIO_LCC_SPARE_I2S_SPKR_NS_BIT_DIV_SHFT         0xa
#define HWIO_LCC_PCM_NS_CXC_EN_BMSK                     0x800
#define HWIO_LCC_PCM_NS_CXC_EN_SHFT                     0xb
#define HWIO_LCC_PCM_MD_M_VAL_BMSK                      0xffff0000
#define HWIO_LCC_PCM_MD_M_VAL_SHFT                      0x10
#define HWIO_LCC_PCM_MD_NOT_2D_VAL_BMSK                 0xffff
#define HWIO_LCC_PCM_MD_NOT_2D_VAL_SHFT                 0
#define HWIO_LCC_PCM_NS_N_VAL_BMSK                      0xffff0000
#define HWIO_LCC_PCM_NS_MNCNTR_EN_BMSK                  0x100
#define HWIO_LCC_PCM_NS_MNCNTR_MODE_BMSK                0x60
#define HWIO_LCC_PCM_NS_MN_SRC_SEL_BMSK                 0x7
#define HWIO_LCC_PCM_NS_N_VAL_SHFT                      0x10
#define HWIO_LCC_PCM_NS_MNCNTR_EN_SHFT                  0x8
#define HWIO_LCC_PCM_NS_MNCNTR_MODE_SHFT                0x5
#define HWIO_LCC_PCM_NS_MN_SRC_SEL_SHFT                 0
#define HWIO_LCC_AHBEX_BRANCH_CTL_CORE_SPDM_XBUS_CGC_EN_BMSK    0x10000
#define HWIO_LCC_AHBEX_BRANCH_CTL_CORE_SPDM_IBUS_CGC_EN_BMSK    0x8000
#define HWIO_LCC_AHBEX_BRANCH_CTL_CORE_SPDM_XBUS_CGC_EN_SHFT    0x10
#define HWIO_LCC_AHBEX_BRANCH_CTL_CORE_SPDM_IBUS_CGC_EN_SHFT    0xf
#define HWIO_LCC_AHBEX_BRANCH_CTL_SLIMBUS_ARES_RESET		(1 << 5)


enum lpass_ahbix_clk_src_t {
	LPASS_AHBIX_CLK_SRC_CXO,
	LPASS_AHBIX_CLK_SRC_PXO,
	LPASS_AHBIX_CLK_SRC_PLL0,
	LPASS_AHBIX_CLK_SRC_GPLL0,
	LPASS_AHBIX_CLK_SRC_CLK_TEST_SE,
	LPASS_AHBIX_CLK_SRC_PLL_TEST_SE,
	LPASS_AHBIX_CLK_SRC_SEC_PLL
};

struct request_gpio {
	uint32_t gpio_no;
	char *gpio_name;
};

struct lpass_clk_baseinfo {
	void __iomem *base;
};

extern struct lpass_clk_baseinfo lpass_clk_base;

/* MI2S GPIOs */
#define GPIO_MI2S_WS	27
#define GPIO_MI2S_SCK	28
#define GPIO_MI2S_SD3	29
#define GPIO_MI2S_SD2	30
#define GPIO_MI2S_SD1	31
#define GPIO_MI2S_SD0	32
#define GPIO_MI2S_MCLK	33

/* PCM GPIOs */
#define GPIO_PCM_DOUT	14
#define GPIO_PCM_DIN	15
#define GPIO_PCM_SYNC	16
#define GPIO_PCM_CLK	17

/* SPDIF GPIO */
#define GPIO_SPDIF	10

/* Supported Channels */
#define LPASS_STEREO	2
#define LPASS_5_1	6
#define LPASS_7_1	8

/* MI2S Hw params */
/* The period size should be multiple of 5.1 (8 bit,
 * 16 bit, 24 bit, 32 bit) and 7.1 (8 bit, 16 bit,
 * 24 bit, 32bit). Taking the Least common multiple for the
 * above values gives 288. Choosing the period size in the range of
 * 8K will be 8064(multiple of 288). Choosing the buffer
 * size in the range of 1M will be 1048320(multiple of 288).
 */

#define LPASS_MI2S_NO_OF_PERIODS	(65)
#define LPASS_MI2S_PERIOD_BYTES_MIN	(8064)

#define LPASS_MI2S_BUFF_SIZE		(LPASS_MI2S_PERIOD_BYTES_MIN * \
					LPASS_MI2S_NO_OF_PERIODS)
#define LPASS_MI2S_CAPTURE_BUFF_SIZE	(LPASS_MI2S_PERIOD_BYTES_MIN * \
					LPASS_MI2S_NO_OF_PERIODS * 2)

#endif /* _IPQ806x_H */
