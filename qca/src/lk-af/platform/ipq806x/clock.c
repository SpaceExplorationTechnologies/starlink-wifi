/*
 * Copyright (c) 2012, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of The Linux Foundation nor
 *     the names of its contributors may be used to endorse or promote
 *     products derived from this software without specific prior written
 *     permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdint.h>
#include <debug.h>
#include <reg.h>
#include <err.h>
#include <limits.h>
#include <clock.h>
#include <clock_pll.h>
#include <clock-local.h>
#include <bits.h>
#include <platform/iomap.h>
#include <platform/clock.h>
#include <platform/timer.h>
#include <sys/types.h>

extern void dmb(void);

static int xo_clk_enable(struct clk *clk)
{
	/* Assuming pxo already running */
	return 0;
}

static void xo_clk_disable(struct clk *clk)
{
	/* Do nothing */
}

static struct clk_ops clk_ops_xo = {
	.enable = xo_clk_enable,
	.disable = xo_clk_disable,
	.get_rate = fixed_clk_get_rate,
};

#define IPQ_PXO_FREQ		(25 * 1000 * 1000)

static struct fixed_clk pxo_clk = {
	.rate = IPQ_PXO_FREQ,
	.c = {
		.dbg_name = "pxo_clk",
		.ops = &clk_ops_xo,
	},
};

/*
 * PLL Clocks
 */
struct clk_ops clk_ops_pll_vote = {
	.enable = pll_vote_clk_enable,
	.disable = pll_vote_clk_disable,
	.is_enabled = pll_vote_clk_is_enabled,
	.get_rate = pll_vote_clk_get_rate,
	.get_parent = pll_vote_clk_get_parent,
};

struct clk_ops clk_ops_pll = {
	.enable = pll_clk_enable,
	.disable = pll_clk_disable,
	.get_rate = pll_clk_get_rate,
	.get_parent = pll_clk_get_parent,
};

static struct pll_vote_clk pll8_clk = {
	.rate = 384000000,
	.en_reg = (void *)BB_PLL_ENA_SC0_REG,
	.en_mask = BIT(8),
	.status_reg = (void *)PLL_LOCK_DET_STATUS,
	.status_mask = BIT(8),
	.parent = &pxo_clk.c,
	.c = {
		.dbg_name = "pll8_clk",
		.ops = &clk_ops_pll_vote,
	},
};

static struct clk_ops soc_clk_ops_ipq806x = {
	.enable = local_clk_enable,
	.disable = local_clk_disable,
	.set_rate = local_clk_set_rate,
	.get_rate = local_clk_get_rate,
	.is_enabled = local_clk_is_enabled,
	.round_rate = local_clk_round_rate,
	.get_parent = local_clk_get_parent,
};

static struct clk_ops clk_ops_branch = {
	.enable = branch_clk_enable,
	.disable = branch_clk_disable,
	.is_enabled = branch_clk_is_enabled,
	.get_parent = branch_clk_get_parent,
	.set_parent = branch_clk_set_parent,
};

struct clk_ops clk_ops_empty;

struct fixed_clk gnd_clk = {
	.c = {
		.dbg_name = "ground_clk",
		.ops = &clk_ops_empty,
	},
};

/*
 * Peripheral Clocks
 */
#define CLK_GSBI_UART(i, n, h_r, h_b) \
	struct rcg_clk i##_clk = { \
		.b = { \
			.ctl_reg = (void *)GSBIn_UART_APPS_NS_REG(n), \
			.en_mask = BIT(9), \
			.reset_reg = (void *)GSBIn_RESET_REG(n), \
			.reset_mask = BIT(0), \
			.halt_reg = (void *)h_r, \
			.halt_bit = h_b, \
		}, \
		.ns_reg = (void *)GSBIn_UART_APPS_NS_REG(n), \
		.md_reg = (void *)GSBIn_UART_APPS_MD_REG(n), \
		.root_en_mask = BIT(11), \
		.ns_mask = (BM(31, 16) | BM(6, 0)), \
		.set_rate = set_rate_mnd, \
		.freq_tbl = clk_tbl_gsbi_uart, \
		.current_freq = &local_dummy_freq, \
		.c = { \
			.dbg_name = #i "_clk", \
			.ops = &soc_clk_ops_ipq806x, \
		}, \
	}
#define F_GSBI_UART(f, s, d, m, n) \
	{ \
		.freq_hz = f, \
		.src_clk = &s##_clk.c, \
		.md_val = MD16(m, n), \
		.ns_val = NS(31, 16, n, m, 5, 4, 3, d, 2, 0, s##_to_bb_mux), \
		.mnd_en_mask = BIT(8) * !!(n), \
	}
static struct clk_freq_tbl clk_tbl_gsbi_uart[] = {
	F_GSBI_UART(       0, gnd,  1,  0,   0),
	F_GSBI_UART( 1843200, pll8, 2,  6, 625),
	F_GSBI_UART( 3686400, pll8, 2, 12, 625),
	F_GSBI_UART( 7372800, pll8, 2, 24, 625),
	F_GSBI_UART(14745600, pll8, 2, 48, 625),
	F_GSBI_UART(16000000, pll8, 4,  1,   6),
	F_GSBI_UART(24000000, pll8, 4,  1,   4),
	F_GSBI_UART(32000000, pll8, 4,  1,   3),
	F_GSBI_UART(40000000, pll8, 1,  5,  48),
	F_GSBI_UART(46400000, pll8, 1, 29, 240),
	F_GSBI_UART(48000000, pll8, 4,  1,   2),
	F_GSBI_UART(51200000, pll8, 1,  2,  15),
	F_GSBI_UART(56000000, pll8, 1,  7,  48),
	F_GSBI_UART(58982400, pll8, 1, 96, 625),
	F_GSBI_UART(64000000, pll8, 2,  1,   3),
	F_END
};

static CLK_GSBI_UART(gsbi1_uart,   1, CLK_HALT_CFPB_STATEA_REG, 12);
static CLK_GSBI_UART(gsbi2_uart,   2, CLK_HALT_CFPB_STATEA_REG,  8);
static CLK_GSBI_UART(gsbi4_uart,   4, CLK_HALT_CFPB_STATEB_REG, 26);
static CLK_GSBI_UART(gsbi5_uart,   5, CLK_HALT_CFPB_STATEB_REG, 22);
static CLK_GSBI_UART(gsbi7_uart,   7, CLK_HALT_CFPB_STATEB_REG, 14);

#define CLK_GSBI_QUP(i, n, h_r, h_b) \
	struct rcg_clk i##_clk = { \
		.b = { \
			.ctl_reg = (void *)GSBIn_QUP_APPS_NS_REG(n), \
			.en_mask = BIT(9), \
			.reset_reg = (void *)GSBIn_RESET_REG(n), \
			.reset_mask = BIT(0), \
			.halt_reg = (void *)h_r, \
			.halt_bit = h_b, \
		}, \
		.ns_reg = (void *)GSBIn_QUP_APPS_NS_REG(n), \
		.md_reg = (void *)GSBIn_QUP_APPS_MD_REG(n), \
		.root_en_mask = BIT(11), \
		.ns_mask = (BM(23, 16) | BM(6, 0)), \
		.set_rate = set_rate_mnd, \
		.freq_tbl = clk_tbl_gsbi_qup, \
		.current_freq = &local_dummy_freq, \
		.c = { \
			.dbg_name = #i "_clk", \
			.ops = &soc_clk_ops_ipq806x, \
		}, \
	}
#define F_GSBI_QUP(f, s, d, m, n) \
	{ \
		.freq_hz = f, \
		.src_clk = &s##_clk.c, \
		.md_val = MD8(16, m, 0, n), \
		.ns_val = NS(23, 16, n, m, 5, 4, 3, d, 2, 0, s##_to_bb_mux), \
		.mnd_en_mask = BIT(8) * !!(n), \
	}

static struct clk_freq_tbl clk_tbl_gsbi_qup[] = {
	F_GSBI_QUP(                 0, gnd,  1, 0,   0),
	F_GSBI_QUP( IPQ_PXO_FREQ / 25, pxo,  1, 1,  25),
	F_GSBI_QUP(  IPQ_PXO_FREQ / 5, pxo,  1, 1,   5),
	F_GSBI_QUP(IPQ_PXO_FREQ / 2.5, pxo,  1, 2,   5),
	F_GSBI_QUP(          15060000, pll8, 1, 2,  51),
	F_GSBI_QUP(          24000000, pll8, 4, 1,   4),
	F_GSBI_QUP(          25600000, pll8, 1, 1,  15),
	F_GSBI_QUP(          27000000, pll8, 1, 9, 128),
	F_GSBI_QUP(          48000000, pll8, 4, 1,   2),
	F_GSBI_QUP(          51200000, pll8, 1, 2,  15),
	F_END
};

static CLK_GSBI_QUP(gsbi1_qup,   1, CLK_HALT_CFPB_STATEA_REG, 11);
static CLK_GSBI_QUP(gsbi2_qup,   2, CLK_HALT_CFPB_STATEA_REG,  6);
static CLK_GSBI_QUP(gsbi5_qup,   5, CLK_HALT_CFPB_STATEB_REG, 20);
static CLK_GSBI_QUP(gsbi7_qup,   7, CLK_HALT_CFPB_STATEB_REG, 12);

#define CLK_USB_HS(name, n, h_b) \
	static struct rcg_clk name = { \
	.b = { \
		.ctl_reg = (void *)USB_HS##n##_XCVR_FS_CLK_NS_REG, \
		.en_mask = BIT(9), \
		.reset_reg = (void *)USB_HS##n##_RESET_REG, \
		.reset_mask = BIT(0), \
		.halt_reg = (void *)CLK_HALT_DFAB_STATE_REG, \
		.halt_bit = h_b, \
	}, \
	.ns_reg = (void *)USB_HS##n##_XCVR_FS_CLK_NS_REG, \
	.md_reg = (void *)USB_HS##n##_XCVR_FS_CLK_MD_REG, \
	.root_en_mask = BIT(11), \
	.ns_mask = (BM(23, 16) | BM(6, 0)), \
	.set_rate = set_rate_mnd, \
	.freq_tbl = clk_tbl_usb, \
	.current_freq = &local_dummy_freq, \
	.c = { \
		.dbg_name = #name, \
		.ops = &soc_clk_ops_ipq806x, \
		/* VDD_DIG_FMAX_MAP1(NOMINAL, 64000000), */ \
		/* CLK_INIT(name.c), */ \
	}, \
}

#define F_USB(f, s, d, m, n) \
	{ \
		.freq_hz = f, \
		.src_clk = &s##_clk.c, \
		.md_val = MD8(16, m, 0, n), \
		.ns_val = NS(23, 16, n, m, 5, 4, 3, d, 2, 0, s##_to_bb_mux), \
		.mnd_en_mask = BIT(8) * !!(n), \
	}
static struct clk_freq_tbl clk_tbl_usb[] = {
	F_USB(       0, gnd,  1, 0,  0),
	F_USB(60000000, pll8, 1, 5, 32),
	F_END
};

CLK_USB_HS(usb_hs1_xcvr_clk, 1, 0);

#define CLK_SDC(name, n, h_b, fmax_low, fmax_nom) \
	struct rcg_clk name = { \
		.b = { \
			.ctl_reg = (void *)SDCn_APPS_CLK_NS_REG(n), \
			.en_mask = BIT(9), \
			.reset_reg = (void *)SDCn_RESET_REG(n), \
			.reset_mask = BIT(0), \
			.halt_reg = (void *)CLK_HALT_DFAB_STATE_REG, \
			.halt_bit = h_b, \
		}, \
		.ns_reg = (void *)SDCn_APPS_CLK_NS_REG(n), \
		.md_reg = (void *)SDCn_APPS_CLK_MD_REG(n), \
		.root_en_mask = BIT(11), \
		.ns_mask = (BM(23, 16) | BM(6, 0)), \
		.set_rate = set_rate_mnd, \
		.freq_tbl = clk_tbl_sdc, \
		.current_freq = &local_dummy_freq, \
		.c = { \
			.dbg_name = #name, \
			.ops = &soc_clk_ops_ipq806x, \
		}, \
	}
#define F_SDC(f, s, d, m, n) \
	{ \
		.freq_hz = f, \
		.src_clk = &s##_clk.c, \
		.md_val = MD8(16, m, 0, n), \
		.ns_val = NS(23, 16, n, m, 5, 4, 3, d, 2, 0, s##_to_bb_mux), \
		.mnd_en_mask = BIT(8), \
	}
static struct clk_freq_tbl clk_tbl_sdc[] = {
	F_SDC(        0, gnd,   1, 0,   0),
	F_SDC(   144000, pxo,   5, 18, 625),
	F_SDC(   400000, pll8,  4, 1, 240),
	F_SDC( 16000000, pll8,  4, 1,   6),
	F_SDC( 17070000, pll8,  1, 2,  45),
	F_SDC( 20210000, pll8,  1, 1,  19),
	F_SDC( 24000000, pll8,  4, 1,   4),
	F_SDC( 48000000, pll8,  4, 1,   2),
	F_SDC( 52000000, pll8,  3, 13, 32),
	F_SDC( 64000000, pll8,  3, 1,   2),
	F_SDC( 96000000, pll8,  4, 0,   0),
	F_SDC(192000000, pll8,  2, 0,   0),
	F_END
};

static CLK_SDC(sdc1_clk, 1, 6,  52000000, 104000000);
static CLK_SDC(sdc3_clk, 3, 4, 104000000, 208000000);

static struct branch_clk ce1_core_clk = {
	.b = {
		.ctl_reg = (void *)CE1_CORE_CLK_CTL_REG,
		.en_mask = BIT(4),
		.halt_reg = (void *)CLK_HALT_CFPB_STATEC_REG,
		.halt_bit = 27,
	},
	.c = {
		.dbg_name = "ce1_core_clk",
		.ops = &clk_ops_branch,
	},
};

static struct branch_clk ce1_p_clk = {
	.b = {
		.ctl_reg = (void *)CE1_HCLK_CTL_REG,
		.en_mask = BIT(4),
		.halt_reg = (void *)CLK_HALT_CFPB_STATEC_REG,
		.halt_bit = 1,
	},
	.c = {
		.dbg_name = "ce1_p_clk",
		.ops = &clk_ops_branch,
	},
};

#define F_CE5(f, s, d) \
	{ \
		.freq_hz = f, \
		.src_clk = &s##_clk.c, \
		.ns_val = NS_DIVSRC(6, 3, d, 2, 0, s##_to_bb_mux), \
	}

static struct clk_freq_tbl clk_tbl_ce5[] = {
	F_CE5(        0, gnd,   1),
	F_CE5( 48000000, pll8,  8),
	F_END
};

static struct rcg_clk ce5_src_clk = {
	.b = {
		.ctl_reg = (void *)CE5_CLK_SRC_NS_REG,
		.halt_check = NOCHECK,
	},
	.ns_reg = (void *)CE5_CLK_SRC_NS_REG,
	.root_en_mask = BIT(7),
	.ns_mask = BM(6, 0),
	.set_rate = set_rate_nop,
	.freq_tbl = clk_tbl_ce5,
	.current_freq = &local_dummy_freq,
	.c = {
		.dbg_name = "ce5_src_clk",
		.ops = &soc_clk_ops_ipq806x,
	},
};

static struct branch_clk ce5_core_clk = {
	.b = {
		.ctl_reg = (void *)CE5_CORE_CLK_CTL_REG,
		.en_mask = BIT(4),
		.halt_reg = (void *)CLK_HALT_MSS_SMPSS_MISC_STATE_REG,
		.halt_bit = 5,
	},
	.parent = &ce5_src_clk.c,
	.c = {
		.dbg_name = "ce5_core_clk",
		.ops = &clk_ops_branch,
	}
};

static struct branch_clk ce5_p_clk = {
	.b = {
		.ctl_reg = (void *)CE5_HCLK_CTL_REG,
		.en_mask = BIT(4),
		.halt_reg = (void *)CLK_HALT_NSS_FAB0_NSS_FAB1_STATEA_REG,
		.halt_bit = 11,
	},
	.parent = &ce5_src_clk.c,
	.c = {
		.dbg_name = "ce5_p_clk",
		.ops = &clk_ops_branch,
	}
};

static struct branch_clk gsbi1_p_clk = {
	.b = {
		.ctl_reg = (void *)GSBIn_HCLK_CTL_REG(1),
		.en_mask = BIT(4),
		.halt_reg = (void *)CLK_HALT_CFPB_STATEA_REG,
		.halt_bit = 13,
	},
	.c = {
		.dbg_name = "gsbi1_p_clk",
		.ops = &clk_ops_branch,
	},
};

static struct branch_clk gsbi2_p_clk = {
	.b = {
		.ctl_reg = (void *)GSBIn_HCLK_CTL_REG(2),
		.en_mask = BIT(4),
		.halt_reg = (void *)CLK_HALT_CFPB_STATEA_REG,
		.halt_bit = 9,
	},
	.c = {
		.dbg_name = "gsbi2_p_clk",
		.ops = &clk_ops_branch,
	},
};

static struct branch_clk gsbi4_p_clk = {
	.b = {
		.ctl_reg = (void *)GSBIn_HCLK_CTL_REG(4),
		.en_mask = BIT(4),
		.halt_reg = (void *)CLK_HALT_CFPB_STATEB_REG,
		.halt_bit = 27,
	},
	.c = {
		.dbg_name = "gsbi4_p_clk",
		.ops = &clk_ops_branch,
	},
};

static struct branch_clk gsbi5_p_clk = {
	.b = {
		.ctl_reg = (void *)GSBIn_HCLK_CTL_REG(5),
		.en_mask = BIT(4),
		.halt_reg = (void *)CLK_HALT_CFPB_STATEB_REG,
		.halt_bit = 23,
	},
	.c = {
		.dbg_name = "gsbi5_p_clk",
		.ops = &clk_ops_branch,
	},
};

static struct branch_clk gsbi7_p_clk = {
	.b = {
		.ctl_reg = (void *)GSBIn_HCLK_CTL_REG(7),
		.en_mask = BIT(4),
		.halt_reg = (void *)CLK_HALT_CFPB_STATEB_REG,
		.halt_bit = 15,
	},
	.c = {
		.dbg_name = "gsbi7_p_clk",
		.ops = &clk_ops_branch,
	},
};

static struct branch_clk ebi2_clk = {
	.b = {
		.ctl_reg = (void *)EBI2_CLK_CTL,
		.en_mask = BIT(4),
		.halt_reg = (void *)CLK_HALT_CFPB_STATEA_REG,
		.halt_bit = 1,

	},
	.c = {
		.dbg_name = "ebi2_clk",
		.ops = &clk_ops_branch,
	},
};

#ifdef DEBUG_CLOCK
struct measure_sel {
	uint32_t test_vector;
	struct clk *clk;
};

static struct measure_sel measure_mux[] = {
	{ TEST_PER_LS(0x12), &sdc1_p_clk.c },
	{ TEST_PER_LS(0x13), &sdc1_clk.c },
	{ TEST_PER_LS(0x16), &sdc3_p_clk.c },
	{ TEST_PER_LS(0x17), &sdc3_clk.c },
	{ TEST_PER_LS(0x3D), &gsbi1_p_clk.c },
	{ TEST_PER_LS(0x3E), &gsbi1_uart_clk.c },
	{ TEST_PER_LS(0x3F), &gsbi1_qup_clk.c },
	{ TEST_PER_LS(0x41), &gsbi2_p_clk.c },
	{ TEST_PER_LS(0x42), &gsbi2_uart_clk.c },
	{ TEST_PER_LS(0x44), &gsbi2_qup_clk.c },
	{ TEST_PER_LS(0x49), &gsbi4_p_clk.c },
	{ TEST_PER_LS(0x4A), &gsbi4_uart_clk.c },
	{ TEST_PER_LS(0x4D), &gsbi5_p_clk.c },
	{ TEST_PER_LS(0x4E), &gsbi5_uart_clk.c },
	{ TEST_PER_LS(0x50), &gsbi5_qup_clk.c },
	{ TEST_PER_LS(0x55), &gsbi7_p_clk.c },
	{ TEST_PER_LS(0x56), &gsbi7_uart_clk.c },
	{ TEST_PER_LS(0x58), &gsbi7_qup_clk.c },
	{ TEST_PER_LS(0x85), &usb_hs1_xcvr_clk.c },
	{ TEST_PER_LS(0x88), &usb_hsic_xcvr_fs_clk.c },
	{ TEST_PER_LS(0x92), &ce1_p_clk.c },
	{ TEST_PER_LS(0xA4), &ce1_core_clk.c },
	{ TEST_PER_LS(0x5F), &ce5_p_clk.c },
	{ TEST_PER_LS(0x60), &ce5_core_clk.c },
};

static struct measure_sel *find_measure_sel(struct clk *clk)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(measure_mux); i++)
		if (measure_mux[i].clk == clk)
			return &measure_mux[i];
	return NULL;
}

static int measure_clk_set_parent(struct clk *c, struct clk *parent)
{
	int ret = 0;
	uint32_t clk_sel;
	struct measure_sel *p;
	struct measure_clk *clk = to_measure_clk(c);

	if (!parent)
		return ERR_INVALID_ARGS;

	p = find_measure_sel(parent);
	if (!p)
		return ERR_INVALID_ARGS;

	/*
	 * Program the test vector, measurement period (sample_ticks)
	 * and scaling multiplier.
	 */
	clk->sample_ticks = 0x10000;
	clk_sel = p->test_vector & TEST_CLK_SEL_MASK;
	clk->multiplier = 1;
	switch (p->test_vector >> TEST_TYPE_SHIFT) {
	case TEST_TYPE_PER_LS:
		writel_relaxed(0x4030D00|BVAL(7, 0, clk_sel), CLK_TEST_REG);
		break;
	case TEST_TYPE_PER_HS:
		writel_relaxed(0x4020000|BVAL(16, 10, clk_sel), CLK_TEST_REG);
		break;
	case TEST_TYPE_MM_LS:
		writel_relaxed(0x4030D97, CLK_TEST_REG);
		writel_relaxed(BVAL(6, 1, clk_sel)|BIT(0), DBG_CFG_REG_LS_REG);
		break;
	case TEST_TYPE_MM_HS:
		writel_relaxed(0x402B800, CLK_TEST_REG);
		writel_relaxed(BVAL(6, 1, clk_sel)|BIT(0), DBG_CFG_REG_HS_REG);
		break;
	default:
		ret = ERR_NOT_SUPPORTED;
	}
	/* Make sure test vector is set before starting measurements. */
	dmb();

	return ret;
}

/* Sample clock for 'ticks' reference clock ticks. */
static uint32_t run_measurement(unsigned ticks)
{
	/* Stop counters and set the XO4 counter start value. */
	writel_relaxed(ticks, RINGOSC_TCXO_CTL_REG);

	/* Wait for timer to become ready. */
	while ((readl_relaxed(RINGOSC_STATUS_REG) & BIT(25)) != 0)
		dmb();

	/* Run measurement and wait for completion. */
	writel_relaxed(BIT(20)|ticks, RINGOSC_TCXO_CTL_REG);
	while ((readl_relaxed(RINGOSC_STATUS_REG) & BIT(25)) == 0)
		dmb();

	/* Stop counters. */
	writel_relaxed(0x0, RINGOSC_TCXO_CTL_REG);

	/* Return measured ticks. */
	return readl_relaxed(RINGOSC_STATUS_REG) & BM(24, 0);
}


/* Perform a hardware rate measurement for a given clock.
   FOR DEBUG USE ONLY: Measurements take ~15 ms! */
static unsigned measure_clk_get_rate(struct clk *c)
{
	uint32_t pdm_reg_backup, ringosc_reg_backup;
	uint64_t raw_count_short, raw_count_full;
	struct measure_clk *clk = to_measure_clk(c);
	unsigned ret;

	ret = clk_enable(&cxo_clk.c);
	if (ret) {
		dprintf(CRITICAL, "CXO clock failed to enable. Can't measure\n");
		return 0;
	}

	/* Enable CXO/4 and RINGOSC branch and root. */
	pdm_reg_backup = readl_relaxed(PDM_CLK_NS_REG);
	ringosc_reg_backup = readl_relaxed(RINGOSC_NS_REG);
	writel_relaxed(0x2898, PDM_CLK_NS_REG);
	writel_relaxed(0xA00, RINGOSC_NS_REG);

	/*
	 * The ring oscillator counter will not reset if the measured clock
	 * is not running.  To detect this, run a short measurement before
	 * the full measurement.  If the raw results of the two are the same
	 * then the clock must be off.
	 */

	/* Run a short measurement. (~1 ms) */
	raw_count_short = run_measurement(0x1000);
	/* Run a full measurement. (~14 ms) */
	raw_count_full = run_measurement(clk->sample_ticks);

	writel_relaxed(ringosc_reg_backup, RINGOSC_NS_REG);
	writel_relaxed(pdm_reg_backup, PDM_CLK_NS_REG);

	/* Return 0 if the clock is off. */
	if (raw_count_full == raw_count_short)
		ret = 0;
	else {
		/* Compute rate in Hz. */
		raw_count_full = ((raw_count_full * 10) + 15) * 4800000;
		raw_count_full /= ((clk->sample_ticks * 10) + 35);
		ret = (raw_count_full * clk->multiplier);
	}

	/* Route dbg_hs_clk to PLLTEST.  300mV single-ended amplitude. */
	writel_relaxed(0x38F8, PLLTEST_PAD_CFG_REG);

	clk_disable(&cxo_clk.c);

	return ret;
}
#else
static int measure_clk_set_parent(struct clk *clk, struct clk *parent)
{
	return ERR_INVALID_ARGS;
}

static unsigned measure_clk_get_rate(struct clk *clk)
{
	return 0;
}
#endif

static struct clk_ops measure_clk_ops = {
	.set_parent = measure_clk_set_parent,
	.get_rate = measure_clk_get_rate,
};

static struct measure_clk measure_clk = {
	.c = {
		.dbg_name = "measure_clk",
		.ops = &measure_clk_ops,
	},
	.multiplier = 1,
};

static struct clk_lookup msm_clocks_ipq806x[] = {
	CLK_LOOKUP("gsbi1_uart_clk",	gsbi1_uart_clk.c),
	CLK_LOOKUP("gsbi2_uart_clk",	gsbi2_uart_clk.c),
	CLK_LOOKUP("gsbi4_uart_clk",	gsbi4_uart_clk.c),
	CLK_LOOKUP("gsbi5_uart_clk",	gsbi5_uart_clk.c),
	CLK_LOOKUP("gsbi7_uart_clk",	gsbi7_uart_clk.c),
	CLK_LOOKUP("gsbi1_qup_clk",		gsbi1_qup_clk.c),
	CLK_LOOKUP("gsbi2_qup_clk",		gsbi2_qup_clk.c),
	CLK_LOOKUP("gsbi5_qup_clk",		gsbi5_qup_clk.c),
	CLK_LOOKUP("gsbi7_qup_clk",		gsbi7_qup_clk.c),
	CLK_LOOKUP("gsbi1_pclk",		gsbi1_p_clk.c),
	CLK_LOOKUP("gsbi2_pclk",		gsbi2_p_clk.c),
	CLK_LOOKUP("gsbi4_pclk",		gsbi4_p_clk.c),
	CLK_LOOKUP("gsbi5_pclk",		gsbi5_p_clk.c),
	CLK_LOOKUP("gsbi7_pclk",		gsbi7_p_clk.c),
	CLK_LOOKUP("usb_hs_clk",		usb_hs1_xcvr_clk.c),
	CLK_LOOKUP("sdc1_clk",			sdc1_clk.c),
	CLK_LOOKUP("sdc3_clk",			sdc3_clk.c),
	CLK_LOOKUP("ce1_pclk",			ce1_p_clk.c),
	CLK_LOOKUP("ce1_clk",			ce1_core_clk.c),
	CLK_LOOKUP("ce5_src_clk",		ce5_src_clk.c),
	CLK_LOOKUP("ce5_pclk",			ce5_p_clk.c),
	CLK_LOOKUP("ce5_clk",			ce5_core_clk.c),
	CLK_LOOKUP("ebi2_clk",			ebi2_clk.c),
	CLK_LOOKUP("measure",			measure_clk.c),

};

static int sr_pll_clk_enable(struct clk *clk)
{
	uint32_t mode;
	struct pll_clk *pll = to_pll_clk(clk);

	mode = readl_relaxed(pll->mode_reg);
	/* De-assert active-low PLL reset. */
	mode |= BIT(2);
	writel_relaxed(mode, pll->mode_reg);

	/*
	 * H/W requires a 5us delay between disabling the bypass and
	 * de-asserting the reset. Delay 10us just to be safe.
	 */
	dmb();
	udelay(10);

	/* Disable PLL bypass mode. */
	mode |= BIT(1);
	writel_relaxed(mode, pll->mode_reg);

	/* Wait until PLL is locked. */
	dmb();
	udelay(60);

	/* Enable PLL output. */
	mode |= BIT(0);
	writel_relaxed(mode, pll->mode_reg);

	return 0;
}

static unsigned msm_num_clocks_ipq806x = ARRAY_SIZE(msm_clocks_ipq806x);

void msm_clocks_init()
{
	clk_ops_pll.enable = sr_pll_clk_enable;
	clk_init(msm_clocks_ipq806x, msm_num_clocks_ipq806x);

	/*
	 * Though LK doesn't use NAND, the kernel probes the NAND.
	 * If this is not enabled, kernel's NAND probe hangs resulting
	 * in the boot getting stuck.
	 */
	clk_get_set_enable("ebi2_clk", 0 /* rate */, 1 /* enable */);
}

