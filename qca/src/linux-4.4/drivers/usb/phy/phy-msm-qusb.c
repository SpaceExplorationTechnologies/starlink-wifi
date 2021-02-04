/*
 * Copyright (c) 2014-2016, The Linux Foundation. All rights reserved.
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

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/err.h>
#include <linux/slab.h>
#include <linux/clk.h>
#include <linux/clk/msm-clk.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/regulator/consumer.h>
#include <linux/usb/phy.h>
#include <linux/reset.h>
#include <linux/usb/msm_hsusb.h>

/* TCSR_PHY_CLK_SCHEME_SEL bit mask */
#define PHY_CLK_SCHEME_SEL BIT(0)

#define QUSB2PHY_PLL_STATUS	0x38
#define QUSB2PHY_PLL_LOCK	BIT(5)

#define QUSB2PHY_PORT_QC1	0x70
#define VDM_SRC_EN		BIT(4)
#define VDP_SRC_EN		BIT(2)

#define QUSB2PHY_PORT_QC2	0x74
#define RDM_UP_EN		BIT(1)
#define RDP_UP_EN		BIT(3)
#define RPUM_LOW_EN		BIT(4)
#define RPUP_LOW_EN		BIT(5)

#define QUSB2PHY_PORT_POWERDOWN		0xB4
#define CLAMP_N_EN			BIT(5)
#define FREEZIO_N			BIT(1)
#define POWER_DOWN			BIT(0)

#define QUSB2PHY_PORT_UTMI_CTRL1	0xC0
#define TERM_SELECT			BIT(4)
#define XCVR_SELECT_FS			BIT(2)
#define OP_MODE_NON_DRIVE		BIT(0)

#define QUSB2PHY_PORT_UTMI_CTRL2	0xC4
#define UTMI_ULPI_SEL			BIT(7)
#define UTMI_TEST_MUX_SEL		BIT(6)

#define QUSB2PHY_PLL_TEST		0x04
#define CLK_REF_SEL			BIT(7)

#define QUSB2PHY_PORT_TUNE1             0x80
#define QUSB2PHY_PORT_TUNE2             0x84
#define QUSB2PHY_PORT_TUNE3             0x88
#define QUSB2PHY_PORT_TUNE4             0x8C

/* In case Efuse register shows zero, use this value */
#define TUNE2_DEFAULT_HIGH_NIBBLE	0xB
#define TUNE2_DEFAULT_LOW_NIBBLE	0x3

/* Get TUNE2's high nibble value read from efuse */
#define TUNE2_HIGH_NIBBLE_VAL(val, pos, mask)	((val >> pos) & mask)

#define QUSB2PHY_PORT_INTR_CTRL         0xBC
#define CHG_DET_INTR_EN                 BIT(4)
#define DMSE_INTR_HIGH_SEL              BIT(3)
#define DMSE_INTR_EN                    BIT(2)
#define DPSE_INTR_HIGH_SEL              BIT(1)
#define DPSE_INTR_EN                    BIT(0)

#define QUSB2PHY_PORT_UTMI_STATUS	0xF4
#define LINESTATE_DP			BIT(0)
#define LINESTATE_DM			BIT(1)

#define HS_PHY_CTRL_REG			0x10
#define UTMI_OTG_VBUS_VALID             BIT(20)
#define SW_SESSVLD_SEL                  BIT(28)

#define QUSB2PHY_1P8_VOL_MIN           1800000 /* uV */
#define QUSB2PHY_1P8_VOL_MAX           1800000 /* uV */
#define QUSB2PHY_1P8_HPM_LOAD          30000   /* uA */

#define QUSB2PHY_3P3_VOL_MIN		3075000 /* uV */
#define QUSB2PHY_3P3_VOL_MAX		3200000 /* uV */
#define QUSB2PHY_3P3_HPM_LOAD		30000	/* uA */

#define QUSB2PHY_REFCLK_ENABLE		BIT(0)

unsigned int tune2;
module_param(tune2, uint, S_IRUGO | S_IWUSR);
MODULE_PARM_DESC(tune2, "QUSB PHY TUNE2");
static void qusb_write_readback(void *base, u32 offset,
					const u32 mask, u32 val);

struct qusb_phy {
	struct usb_phy		phy;
	void __iomem		*base;
	void __iomem		*qscratch_base;
	void __iomem		*tune2_efuse_reg;
	void __iomem		*ref_clk_base;
	void __iomem		*tcsr_phy_clk_scheme_sel;
	void __iomem		*usb3_guctl_addr;

	struct clk		*ref_clk_src;
	struct clk		*ref_clk;
	struct clk		*phy_reset;

	struct regulator	*vdd;
	struct regulator	*vdda33;
	struct regulator	*vdda18;
	int			vdd_levels[3]; /* none, low, high */
	int			init_seq_len;
	int			*qusb_phy_init_seq;

	u32			tune2_val;
	int			tune2_efuse_bit_pos;
	int			tune2_efuse_num_of_bits;

	bool			power_enabled;
	bool			clocks_enabled;
	bool			cable_connected;
	bool			suspended;
	bool			ulpi_mode;
	bool			rm_pulldown;
	bool			dpdm_pulsing_enabled;

	/* emulation targets specific */
	bool			emulation;
};

static void qusb_reset(struct qusb_phy *qphy, u32 action)
{
	if (action == CLK_RESET_ASSERT) {
		reset_control_assert(qphy->phy_reset);
		usleep_range(100, 150);
	} else {
		reset_control_deassert(qphy->phy_reset);
		usleep_range(100, 150); /* wait 100ms */
	}
	wmb(); /* ensure data is written to hw register */
}

static void qusb_phy_enable_clocks(struct qusb_phy *qphy, bool on)
{
	dev_dbg(qphy->phy.dev, "%s(): clocks_enabled:%d on:%d\n",
			__func__, qphy->clocks_enabled, on);

	if (!IS_ERR(qphy->ref_clk_src) && !(IS_ERR(qphy->ref_clk))) {

		if (!qphy->clocks_enabled && on) {
			clk_prepare_enable(qphy->ref_clk_src);
			clk_prepare_enable(qphy->ref_clk);
			qphy->clocks_enabled = true;
		}

		if (qphy->clocks_enabled && !on) {
			clk_disable_unprepare(qphy->ref_clk);
			clk_disable_unprepare(qphy->ref_clk_src);
			qphy->clocks_enabled = false;
		}

		dev_dbg(qphy->phy.dev, "%s(): clocks_enabled:%d\n", __func__,
							qphy->clocks_enabled);
	} else {
		pr_debug("%s():ref_clk_src or ref_clk not found\n", __func__);
	}
}

static int qusb_phy_config_vdd(struct qusb_phy *qphy, int high)
{
	int min, ret;

	if (qphy->emulation)
		return 0;

	min = high ? 1 : 0; /* low or none? */
	ret = regulator_set_voltage(qphy->vdd, qphy->vdd_levels[min],
						qphy->vdd_levels[2]);
	if (ret) {
		dev_err(qphy->phy.dev, "unable to set voltage for qusb vdd\n");
		return ret;
	}

	dev_dbg(qphy->phy.dev, "min_vol:%d max_vol:%d\n",
			qphy->vdd_levels[min], qphy->vdd_levels[2]);
	return ret;
}

static int qusb_phy_enable_power(struct qusb_phy *qphy, bool on,
						bool toggle_vdd)
{
	int ret = 0;

	if (qphy->emulation)
		return 0;

	dev_dbg(qphy->phy.dev, "%s turn %s regulators. power_enabled:%d\n",
			__func__, on ? "on" : "off", qphy->power_enabled);

	if (toggle_vdd && qphy->power_enabled == on) {
		dev_dbg(qphy->phy.dev, "PHYs' regulators are already ON.\n");
		return 0;
	}

	if (!on)
		goto disable_vdda33;

	if (toggle_vdd) {
		ret = qusb_phy_config_vdd(qphy, true);
		if (ret) {
			dev_err(qphy->phy.dev, "Unable to config VDD:%d\n",
								ret);
			goto err_vdd;
		}

		ret = regulator_enable(qphy->vdd);
		if (ret) {
			dev_err(qphy->phy.dev, "Unable to enable VDD\n");
			goto unconfig_vdd;
		}
	}

	ret = regulator_set_mode(qphy->vdda18, QUSB2PHY_1P8_HPM_LOAD);
	if (ret < 0) {
		dev_err(qphy->phy.dev, "Unable to set HPM of vdda18:%d\n", ret);
		goto disable_vdd;
	}

	ret = regulator_set_voltage(qphy->vdda18, QUSB2PHY_1P8_VOL_MIN,
						QUSB2PHY_1P8_VOL_MAX);
	if (ret) {
		dev_err(qphy->phy.dev,
				"Unable to set voltage for vdda18:%d\n", ret);
		goto put_vdda18_lpm;
	}

	ret = regulator_enable(qphy->vdda18);
	if (ret) {
		dev_err(qphy->phy.dev, "Unable to enable vdda18:%d\n", ret);
		goto unset_vdda18;
	}

	ret = regulator_set_mode(qphy->vdda33, QUSB2PHY_3P3_HPM_LOAD);
	if (ret < 0) {
		dev_err(qphy->phy.dev, "Unable to set HPM of vdda33:%d\n", ret);
		goto disable_vdda18;
	}

	ret = regulator_set_voltage(qphy->vdda33, QUSB2PHY_3P3_VOL_MIN,
						QUSB2PHY_3P3_VOL_MAX);
	if (ret) {
		dev_err(qphy->phy.dev,
				"Unable to set voltage for vdda33:%d\n", ret);
		goto put_vdda33_lpm;
	}

	ret = regulator_enable(qphy->vdda33);
	if (ret) {
		dev_err(qphy->phy.dev, "Unable to enable vdda33:%d\n", ret);
		goto unset_vdd33;
	}

	if (toggle_vdd)
		qphy->power_enabled = true;

	pr_debug("%s(): QUSB PHY's regulators are turned ON.\n", __func__);
	return ret;

disable_vdda33:
	ret = regulator_disable(qphy->vdda33);
	if (ret)
		dev_err(qphy->phy.dev, "Unable to disable vdda33:%d\n", ret);

unset_vdd33:
	ret = regulator_set_voltage(qphy->vdda33, 0, QUSB2PHY_3P3_VOL_MAX);
	if (ret)
		dev_err(qphy->phy.dev,
			"Unable to set (0) voltage for vdda33:%d\n", ret);

put_vdda33_lpm:
	ret = regulator_set_mode(qphy->vdda33, 0);
	if (ret < 0)
		dev_err(qphy->phy.dev, "Unable to set (0) HPM of vdda33\n");

disable_vdda18:
	ret = regulator_disable(qphy->vdda18);
	if (ret)
		dev_err(qphy->phy.dev, "Unable to disable vdda18:%d\n", ret);

unset_vdda18:
	ret = regulator_set_voltage(qphy->vdda18, 0, QUSB2PHY_1P8_VOL_MAX);
	if (ret)
		dev_err(qphy->phy.dev,
			"Unable to set (0) voltage for vdda18:%d\n", ret);

put_vdda18_lpm:
	ret = regulator_set_mode(qphy->vdda18, 0);
	if (ret < 0)
		dev_err(qphy->phy.dev, "Unable to set LPM of vdda18\n");

disable_vdd:
	if (toggle_vdd) {
		ret = regulator_disable(qphy->vdd);
		if (ret)
			dev_err(qphy->phy.dev, "Unable to disable vdd:%d\n",
								ret);

unconfig_vdd:
		ret = qusb_phy_config_vdd(qphy, false);
		if (ret)
			dev_err(qphy->phy.dev, "Unable unconfig VDD:%d\n",
								ret);
	}
err_vdd:
	if (toggle_vdd)
		qphy->power_enabled = false;
	dev_dbg(qphy->phy.dev, "QUSB PHY's regulators are turned OFF.\n");
	return ret;
}

static void qusb_phy_get_tune2_param(struct qusb_phy *qphy)
{
	u8 num_of_bits;
	u32 bit_mask = 1;

	pr_debug("%s(): num_of_bits:%d bit_pos:%d\n", __func__,
				qphy->tune2_efuse_num_of_bits,
				qphy->tune2_efuse_bit_pos);

	/* get bit mask based on number of bits to use with efuse reg */
	if (qphy->tune2_efuse_num_of_bits) {
		num_of_bits = qphy->tune2_efuse_num_of_bits;
		bit_mask = (bit_mask << num_of_bits) - 1;
	}

	/*
	 * Read EFUSE register having TUNE2 parameter's high nibble.
	 * If efuse register shows value as 0x0, then use default value
	 * as 0xB as high nibble. Otherwise use efuse register based
	 * value for this purpose.
	 */
	qphy->tune2_val = readl_relaxed(qphy->tune2_efuse_reg);
	pr_debug("%s(): bit_mask:%d efuse based tune2 value:%d\n",
				__func__, bit_mask, qphy->tune2_val);

	qphy->tune2_val = TUNE2_HIGH_NIBBLE_VAL(qphy->tune2_val,
				qphy->tune2_efuse_bit_pos, bit_mask);

	if (!qphy->tune2_val)
		qphy->tune2_val = TUNE2_DEFAULT_HIGH_NIBBLE;

	/* Get TUNE2 byte value using high and low nibble value */
	qphy->tune2_val = ((qphy->tune2_val << 0x4) |
					TUNE2_DEFAULT_LOW_NIBBLE);
}

static void qusb_phy_write_seq(void __iomem *base, u32 *seq, int cnt,
		unsigned long delay)
{
	int i;

	pr_debug("Seq count:%d\n", cnt);
	for (i = 0; i < cnt; i = i+2) {
		pr_debug("write 0x%02x to 0x%02x\n", seq[i], seq[i+1]);
		writel_relaxed(seq[i], base + seq[i+1]);
		if (delay)
			usleep_range(delay, (delay + 2000));
	}
}

static int qusb_phy_init(struct usb_phy *phy)
{
	struct qusb_phy *qphy = container_of(phy, struct qusb_phy, phy);
	int ret, reset_val = 0;
	bool is_se_clk = true;

	dev_dbg(phy->dev, "%s\n", __func__);
	ret = qusb_phy_enable_power(qphy, true, true);
	if (ret)
		return ret;

	qusb_phy_enable_clocks(qphy, true);
	/*
	 * ref clock is enabled by default after power on reset. Linux clock
	 * driver will disable this clock as part of late init if peripheral
	 * driver(s) does not explicitly votes for it. Linux clock driver also
	 * does not disable the clock until late init even if peripheral
	 * driver explicitly requests it and cannot defer the probe until late
	 * init. Hence, Explicitly disable the clock using register write to
	 * allow QUSB PHY PLL to lock properly.
	 */
	if (qphy->ref_clk_base) {
		writel_relaxed((readl_relaxed(qphy->ref_clk_base) &
					~QUSB2PHY_REFCLK_ENABLE),
					qphy->ref_clk_base);
		/* Make sure that above write complete to get ref clk OFF */
		wmb();
	}

	/* Configure ref clock period */
	if (qphy->usb3_guctl_addr) {
		writel_relaxed((readl_relaxed(qphy->usb3_guctl_addr) &
					(~0xffc00000)) | 0x0c800000,
					qphy->usb3_guctl_addr);
		/* Make sure that above write complete */
		wmb();
	}

	/* Perform phy reset */
	qusb_reset(qphy, CLK_RESET_ASSERT);
	usleep_range(100, 150);
	qusb_reset(qphy, CLK_RESET_DEASSERT);

	/* Disable the PHY */
	writel_relaxed(CLAMP_N_EN | FREEZIO_N | POWER_DOWN,
			qphy->base + QUSB2PHY_PORT_POWERDOWN);

	/* configure for ULPI mode if requested */
	if (qphy->ulpi_mode)
		writel_relaxed(0x0, qphy->base + QUSB2PHY_PORT_UTMI_CTRL2);

	/* save reset value to override based on clk scheme */
	reset_val = readl_relaxed(qphy->base + QUSB2PHY_PLL_TEST);

	if (qphy->qusb_phy_init_seq)
		qusb_phy_write_seq(qphy->base, qphy->qusb_phy_init_seq,
				qphy->init_seq_len, 0);

	/*
	 * Check for EFUSE value only if tune2_efuse_reg is available
	 * and try to read EFUSE value only once i.e. not every USB
	 * cable connect case.
	 */
	if (qphy->tune2_efuse_reg) {
		if (!qphy->tune2_val)
			qusb_phy_get_tune2_param(qphy);

		pr_debug("%s(): Programming TUNE2 parameter as:%x\n", __func__,
				qphy->tune2_val);
		writel_relaxed(qphy->tune2_val,
				qphy->base + QUSB2PHY_PORT_TUNE2);
	}

	/* If tune2 modparam set, override tune2 value */
	if (tune2) {
		pr_debug("%s(): (modparam) TUNE2 val:0x%02x\n",
						__func__, tune2);
		writel_relaxed(tune2,
				qphy->base + QUSB2PHY_PORT_TUNE2);
	}

	/* ensure above writes are completed before re-enabling PHY */
	wmb();

	/* Enable the PHY */
	writel_relaxed(CLAMP_N_EN | FREEZIO_N,
		qphy->base + QUSB2PHY_PORT_POWERDOWN);

	/* Ensure above write is completed before turning ON ref clk */
	wmb();

	/* Require to get phy pll lock successfully */
	usleep_range(150, 160);

	if (qphy->tcsr_phy_clk_scheme_sel) {
		ret = readl_relaxed(qphy->tcsr_phy_clk_scheme_sel);
		if (ret & PHY_CLK_SCHEME_SEL) {
			pr_debug("%s:select single-ended clk src\n",
				__func__);
			is_se_clk = true;
		} else {
			pr_debug("%s:select differential clk src\n",
				__func__);
			is_se_clk = false;
		}
	}

	if (!is_se_clk)
		reset_val &= ~CLK_REF_SEL;
	else
		reset_val |= CLK_REF_SEL;

	/* Turn on phy ref_clk if DIFF_CLK else select SE_CLK */
	if (!is_se_clk && qphy->ref_clk_base)
		writel_relaxed((readl_relaxed(qphy->ref_clk_base) |
					QUSB2PHY_REFCLK_ENABLE),
					qphy->ref_clk_base);
	else
		writel_relaxed(reset_val, qphy->base + QUSB2PHY_PLL_TEST);

	/* Make sure that above write is completed to get PLL source clock */
	wmb();
	/* Required to get PHY PLL lock successfully */
	usleep_range(100, 110);

	if (!(readb_relaxed(qphy->base + QUSB2PHY_PLL_STATUS) &
				QUSB2PHY_PLL_LOCK)) {
		dev_err(phy->dev, "QUSB PHY PLL LOCK fails:%x\n",
			readb_relaxed(qphy->base
				+ QUSB2PHY_PLL_STATUS));
		WARN_ON(1);
	}

	/* Set OTG VBUS Valid from HSPHY to controller */
	qusb_write_readback(qphy->qscratch_base, HS_PHY_CTRL_REG,
				UTMI_OTG_VBUS_VALID, UTMI_OTG_VBUS_VALID);
	/* Indicate value is driven by UTMI_OTG_VBUS_VALID bit */
	qusb_write_readback(qphy->qscratch_base, HS_PHY_CTRL_REG,
				SW_SESSVLD_SEL, SW_SESSVLD_SEL);

	return 0;
}

static void qusb_phy_shutdown(struct usb_phy *phy)
{
	struct qusb_phy *qphy = container_of(phy, struct qusb_phy, phy);

	dev_dbg(phy->dev, "%s\n", __func__);

	qusb_phy_enable_clocks(qphy, true);

	/* Disable the PHY */
	writel_relaxed(CLAMP_N_EN | FREEZIO_N | POWER_DOWN,
			qphy->base + QUSB2PHY_PORT_POWERDOWN);
	wmb();

	qusb_phy_enable_clocks(qphy, false);
}
/**
 * Performs QUSB2 PHY suspend/resume functionality.
 *
 * @uphy - usb phy pointer.
 * @suspend - to enable suspend or not. 1 - suspend, 0 - resume
 *
 */
static int qusb_phy_set_suspend(struct usb_phy *phy, int suspend)
{
	struct qusb_phy *qphy = container_of(phy, struct qusb_phy, phy);
	u32 linestate = 0, intr_mask = 0;

	if (qphy->suspended && suspend) {
		dev_dbg(phy->dev, "%s: USB PHY is already suspended\n",
			__func__);
		return 0;
	}

	if (suspend) {
		/* Bus suspend case */
		if (qphy->cable_connected ||
			(qphy->phy.flags & PHY_HOST_MODE)) {
			/* Clear all interrupts */
			writel_relaxed(0x00,
				qphy->base + QUSB2PHY_PORT_INTR_CTRL);

			linestate = readl_relaxed(qphy->base +
					QUSB2PHY_PORT_UTMI_STATUS);

			/*
			 * D+/D- interrupts are level-triggered, but we are
			 * only interested if the line state changes, so enable
			 * the high/low trigger based on current state. In
			 * other words, enable the triggers _opposite_ of what
			 * the current D+/D- levels are.
			 * e.g. if currently D+ high, D- low (HS 'J'/Suspend),
			 * configure the mask to trigger on D+ low OR D- high
			 */
			intr_mask = DPSE_INTR_EN | DMSE_INTR_EN;
			if (!(linestate & LINESTATE_DP)) /* D+ low */
				intr_mask |= DPSE_INTR_HIGH_SEL;
			if (!(linestate & LINESTATE_DM)) /* D- low */
				intr_mask |= DMSE_INTR_HIGH_SEL;

			writel_relaxed(intr_mask,
				qphy->base + QUSB2PHY_PORT_INTR_CTRL);

			qusb_phy_enable_clocks(qphy, false);
		} else { /* Disconnect case */
			/* Disable all interrupts */
			writel_relaxed(0x00,
				qphy->base + QUSB2PHY_PORT_INTR_CTRL);
			/*
			 * Phy in non-driving mode leaves Dp and Dm lines in
			 * high-Z state. Controller power collapse is not
			 * switching phy to non-driving mode causing charger
			 * detection failure. Bring phy to non-driving mode by
			 * overriding controller output via UTMI interface.
			 */
			writel_relaxed(TERM_SELECT | XCVR_SELECT_FS |
				OP_MODE_NON_DRIVE,
				qphy->base + QUSB2PHY_PORT_UTMI_CTRL1);
			writel_relaxed(UTMI_ULPI_SEL | UTMI_TEST_MUX_SEL,
				qphy->base + QUSB2PHY_PORT_UTMI_CTRL2);

			/* Disable PHY */
			writel_relaxed(CLAMP_N_EN | FREEZIO_N | POWER_DOWN,
				qphy->base + QUSB2PHY_PORT_POWERDOWN);

			/* Make sure that above write is completed */
			wmb();

			qusb_phy_enable_clocks(qphy, false);
			qusb_phy_enable_power(qphy, false, true);
		}
		qphy->suspended = true;
	} else {
		/* Bus suspend case */
		if (qphy->cable_connected ||
			(qphy->phy.flags & PHY_HOST_MODE)) {
			qusb_phy_enable_clocks(qphy, true);
			/* Clear all interrupts on resume */
			writel_relaxed(0x00,
				qphy->base + QUSB2PHY_PORT_INTR_CTRL);
		} else {
			qusb_phy_enable_power(qphy, true, true);
			qusb_phy_enable_clocks(qphy, true);
		}
		qphy->suspended = false;
	}

	return 0;
}

static void qusb_write_readback(void *base, u32 offset,
					const u32 mask, u32 val)
{
	u32 write_val, tmp = readl_relaxed(base + offset);
	tmp &= ~mask; /* retain other bits */
	write_val = tmp | val;

	writel_relaxed(write_val, base + offset);

	/* Read back to see if val was written */
	tmp = readl_relaxed(base + offset);
	tmp &= mask; /* clear other bits */

	if (tmp != val)
		pr_err("%s: write: %x to QSCRATCH: %x FAILED\n",
			__func__, val, offset);
}

static int qusb_phy_notify_connect(struct usb_phy *phy,
					enum usb_device_speed speed)
{
	struct qusb_phy *qphy = container_of(phy, struct qusb_phy, phy);

	qphy->cable_connected = true;

	dev_dbg(phy->dev, " cable_connected=%d\n", qphy->cable_connected);

	/* Set OTG VBUS Valid from HSPHY to controller */
	qusb_write_readback(qphy->qscratch_base, HS_PHY_CTRL_REG,
				UTMI_OTG_VBUS_VALID,
				UTMI_OTG_VBUS_VALID);

	/* Indicate value is driven by UTMI_OTG_VBUS_VALID bit */
	qusb_write_readback(qphy->qscratch_base, HS_PHY_CTRL_REG,
				SW_SESSVLD_SEL, SW_SESSVLD_SEL);

	dev_dbg(phy->dev, "QUSB2 phy connect notification\n");
	return 0;
}

static int qusb_phy_notify_disconnect(struct usb_phy *phy,
					enum usb_device_speed speed)
{
	struct qusb_phy *qphy = container_of(phy, struct qusb_phy, phy);

	qphy->cable_connected = false;

	dev_dbg(phy->dev, " cable_connected=%d\n", qphy->cable_connected);

	/* Set OTG VBUS Valid from HSPHY to controller */
	qusb_write_readback(qphy->qscratch_base, HS_PHY_CTRL_REG,
				UTMI_OTG_VBUS_VALID, 0);

	/* Indicate value is driven by UTMI_OTG_VBUS_VALID bit */
	qusb_write_readback(qphy->qscratch_base, HS_PHY_CTRL_REG,
				SW_SESSVLD_SEL, 0);

	dev_dbg(phy->dev, "QUSB2 phy disconnect notification\n");
	return 0;
}

static int qusb_phy_probe(struct platform_device *pdev)
{
	struct qusb_phy *qphy;
	struct device *dev = &pdev->dev;
	struct resource *res;
	int ret = 0, size = 0;
	const char *phy_type;
	bool hold_phy_reset;

	qphy = devm_kzalloc(dev, sizeof(*qphy), GFP_KERNEL);
	if (!qphy)
		return -ENOMEM;

	qphy->phy.dev = dev;

	res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
							"qusb_phy_base");
	qphy->base = devm_ioremap_resource(dev, res);
	if (IS_ERR(qphy->base))
		return PTR_ERR(qphy->base);

	res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
							"qscratch_base");
	if (res) {
		qphy->qscratch_base = devm_ioremap_nocache(dev, res->start,
							resource_size(res));
		if (IS_ERR(qphy->qscratch_base)) {
			dev_dbg(dev, "couldn't ioremap qscratch_base\n");
			qphy->qscratch_base = NULL;
		}
	}

	res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
							"tune2_efuse_addr");
	if (res) {
		qphy->tune2_efuse_reg = devm_ioremap_nocache(dev, res->start,
							resource_size(res));
		if (!IS_ERR_OR_NULL(qphy->tune2_efuse_reg)) {
			ret = of_property_read_u32(dev->of_node,
					"qcom,tune2-efuse-bit-pos",
					&qphy->tune2_efuse_bit_pos);
			if (!ret) {
				ret = of_property_read_u32(dev->of_node,
						"qcom,tune2-efuse-num-bits",
						&qphy->tune2_efuse_num_of_bits);
			}

			if (ret) {
				dev_err(dev, "DT Value for tune2 efuse is invalid.\n");
				return -EINVAL;
			}
		}
	}

	res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
							"ref_clk_addr");
	if (res) {
		qphy->ref_clk_base = devm_ioremap_nocache(dev,
				res->start, resource_size(res));
		if (IS_ERR(qphy->ref_clk_base))
			dev_dbg(dev, "ref_clk_address is not available.\n");
	}

	res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
							"usb3_guctl_addr");
	if (res) {
		qphy->usb3_guctl_addr = devm_ioremap_nocache(dev,
				res->start, resource_size(res));
		if (IS_ERR(qphy->usb3_guctl_addr))
			dev_dbg(dev, "usb3_guctl_addr is not available.\n");
	}

	res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
			"tcsr_phy_clk_scheme_sel");
	if (res) {
		qphy->tcsr_phy_clk_scheme_sel = devm_ioremap_nocache(dev,
				res->start, resource_size(res));
		if (IS_ERR(qphy->tcsr_phy_clk_scheme_sel))
			dev_dbg(dev, "err reading tcsr_phy_clk_scheme_sel\n");
	}

	qphy->dpdm_pulsing_enabled = of_property_read_bool(dev->of_node,
					"qcom,enable-dpdm-pulsing");

	qphy->ref_clk_src = devm_clk_get(dev, "ref_clk_src");
	if (IS_ERR(qphy->ref_clk_src))
		dev_dbg(dev, "clk get failed for ref_clk_src\n");

	qphy->ref_clk = devm_clk_get(dev, "ref_clk");
	if (IS_ERR(qphy->ref_clk))
		dev_dbg(dev, "clk get failed for ref_clk\n");
	else
		clk_set_rate(qphy->ref_clk, 19200000);

	qphy->phy_reset = devm_reset_control_get(dev, "usb2_phy_reset");
	if (IS_ERR(qphy->phy_reset))
		return PTR_ERR(qphy->phy_reset);

	qphy->emulation = of_property_read_bool(dev->of_node,
					"qcom,emulation");

	of_get_property(dev->of_node, "qcom,qusb-phy-init-seq", &size);
	if (size) {
		qphy->qusb_phy_init_seq = devm_kzalloc(dev,
						size, GFP_KERNEL);
		if (qphy->qusb_phy_init_seq) {
			qphy->init_seq_len =
				(size / sizeof(*qphy->qusb_phy_init_seq));
			if (qphy->init_seq_len % 2) {
				dev_err(dev, "invalid init_seq_len\n");
				return -EINVAL;
			}

			of_property_read_u32_array(dev->of_node,
				"qcom,qusb-phy-init-seq",
				qphy->qusb_phy_init_seq,
				qphy->init_seq_len);
		} else {
			dev_err(dev, "error allocating memory for phy_init_seq\n");
		}
	}

	qphy->ulpi_mode = false;
	ret = of_property_read_string(dev->of_node, "phy_type", &phy_type);

	if (!ret) {
		if (!strcasecmp(phy_type, "ulpi"))
			qphy->ulpi_mode = true;
	} else {
		dev_err(dev, "error reading phy_type property\n");
		return ret;
	}

	hold_phy_reset = of_property_read_bool(dev->of_node, "qcom,hold-reset");

	if (!qphy->emulation) {
		ret = of_property_read_u32_array(dev->of_node,
				"qcom,vdd-voltage-level",
				(u32 *) qphy->vdd_levels,
				ARRAY_SIZE(qphy->vdd_levels));
		if (ret) {
			dev_err(dev, "error reading qcom,vdd-voltage-level property\n");
			return ret;
		}

		qphy->vdd = devm_regulator_get(dev, "vdd");
		if (IS_ERR(qphy->vdd)) {
			dev_err(dev, "unable to get vdd supply\n");
			return PTR_ERR(qphy->vdd);
		}

		qphy->vdda33 = devm_regulator_get(dev, "vdda33");
		if (IS_ERR(qphy->vdda33)) {
			dev_err(dev, "unable to get vdda33 supply\n");
			return PTR_ERR(qphy->vdda33);
		}

		qphy->vdda18 = devm_regulator_get(dev, "vdda18");
		if (IS_ERR(qphy->vdda18)) {
			dev_err(dev, "unable to get vdda18 supply\n");
			return PTR_ERR(qphy->vdda18);
		}
	}

	platform_set_drvdata(pdev, qphy);

	qphy->phy.label			= "msm-qusb-phy";
	qphy->phy.init			= qusb_phy_init;
	qphy->phy.set_suspend           = qusb_phy_set_suspend;
	qphy->phy.shutdown		= qusb_phy_shutdown;
	qphy->phy.type			= USB_PHY_TYPE_USB2;

	if (qphy->qscratch_base) {
		qphy->phy.notify_connect        = qusb_phy_notify_connect;
		qphy->phy.notify_disconnect     = qusb_phy_notify_disconnect;
	}

	/*
	 * On some platforms multiple QUSB PHYs are available. If QUSB PHY is
	 * not used, there is leakage current seen with QUSB PHY related voltage
	 * rail. Hence keep QUSB PHY into reset state explicitly here.
	 */
	if (hold_phy_reset)
		qusb_reset(qphy, CLK_RESET_ASSERT);

	ret = usb_add_phy_dev(&qphy->phy);
	return ret;
}

static int qusb_phy_remove(struct platform_device *pdev)
{
	struct qusb_phy *qphy = platform_get_drvdata(pdev);

	usb_remove_phy(&qphy->phy);

	if (qphy->clocks_enabled) {
		clk_disable_unprepare(qphy->ref_clk);
		clk_disable_unprepare(qphy->ref_clk_src);
		qphy->clocks_enabled = false;
	}

	qusb_phy_enable_power(qphy, false, true);

	return 0;
}

static const struct of_device_id qusb_phy_id_table[] = {
	{ .compatible = "qcom,qusb2phy", },
	{ },
};
MODULE_DEVICE_TABLE(of, qusb_phy_id_table);

static struct platform_driver qusb_phy_driver = {
	.probe		= qusb_phy_probe,
	.remove		= qusb_phy_remove,
	.driver = {
		.name	= "msm-qusb-phy",
		.of_match_table = of_match_ptr(qusb_phy_id_table),
	},
};

module_platform_driver(qusb_phy_driver);

MODULE_DESCRIPTION("MSM QUSB2 PHY driver");
MODULE_LICENSE("GPL v2");
