/*
 * Copyright (c) 2017, The Linux Foundation. All rights reserved.
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

#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/phy/phy.h>
#include <linux/platform_device.h>
#include <linux/reset.h>

#define PCIE_PHY_SW_RESET			0x600
#define PCIE_PHY_POWER_DOWN_CONTROL		0x604
#define PCIE_PHY_PCS_STATUS			0x6c8

#define PHY_DELAY_MIN_US			995
#define PHY_DELAY_MAX_US			1005
#define PHY_RETRIES_COUNT			10

#define PIPE_CLK_DELAY_MIN_US			5000
#define PIPE_CLK_DELAY_MAX_US			5100
#define PIPE_CLK_RETRIES_COUNT			10

#define PCIE_USB3_PCS_POWER_DOWN_CONTROL		0x804
#define QSERDES_COM_BIAS_EN_CLKBUFLR_EN			0x34
#define QSERDES_COM_CLK_ENABLE1				0x38
#define QSERDES_COM_BG_TRIM				0x70
#define QSERDES_COM_LOCK_CMP_EN				0xC8
#define QSERDES_COM_VCO_TUNE_MAP			0x128
#define QSERDES_COM_VCO_TUNE_TIMER1			0x144
#define QSERDES_COM_VCO_TUNE_TIMER2			0x144
#define QSERDES_COM_CMN_CONFIG				0x194
#define QSERDES_COM_PLL_IVCO				0x48
#define QSERDES_COM_HSCLK_SEL				0x178
#define QSERDES_COM_SVS_MODE_CLK_SEL			0x19C
#define QSERDES_COM_CORE_CLK_EN				0x18C
#define QSERDES_COM_CORECLK_DIV				0x184
#define QSERDES_COM_RESETSM_CNTRL			0xB4
#define QSERDES_COM_BG_TIMER				0xC
#define QSERDES_COM_SYSCLK_EN_SEL			0xAC
#define QSERDES_COM_DEC_START_MODE0			0xD0
#define QSERDES_COM_DIV_FRAC_START3_MODE0		0xE4
#define QSERDES_COM_DIV_FRAC_START2_MODE0		0xE0
#define QSERDES_COM_DIV_FRAC_START1_MODE0		0xDC
#define QSERDES_COM_LOCK_CMP3_MODE0			0x54
#define QSERDES_COM_LOCK_CMP2_MODE0			0x50
#define QSERDES_COM_LOCK_CMP1_MODE0			0x4C
#define QSERDES_COM_CLK_SELECT				0x174
#define QSERDES_COM_SYS_CLK_CTRL			0x3C
#define QSERDES_COM_SYSCLK_BUF_ENABLE			0x40
#define QSERDES_COM_CP_CTRL_MODE0			0x78
#define QSERDES_COM_PLL_RCTRL_MODE0			0x84
#define QSERDES_COM_PLL_CCTRL_MODE0			0x90
#define QSERDES_COM_INTEGLOOP_GAIN1_MODE0		0x10C
#define QSERDES_COM_INTEGLOOP_GAIN0_MODE0		0x108
#define QSERDES_COM_BIAS_EN_CTRL_BY_PSM			0xA8
#define QSERDES_COM_VCO_TUNE_CTRL			0xC
#define QSERDES_COM_SSC_EN_CENTER			0x10
#define QSERDES_COM_SSC_PER1				0x1C
#define QSERDES_COM_SSC_PER2				0x20
#define QSERDES_COM_SSC_ADJ_PER1			0x14
#define QSERDES_COM_SSC_ADJ_PER2			0x18
#define QSERDES_COM_SSC_STEP_SIZE1			0x24
#define QSERDES_COM_SSC_STEP_SIZE2			0x28
#define QSERDES_TX_HIGHZ_TRANSCEIVEREN_BIAS_DRVR_EN     0x268
#define QSERDES_TX_LANE_MODE                            0x294
#define QSERDES_TX_RES_CODE_LANE_OFFSET                 0x254
#define QSERDES_TX_RCV_DETECT_LVL_2                     0x2AC
#define QSERDES_RX_SIGDET_ENABLES                       0x510
#define QSERDES_RX_SIGDET_DEGLITCH_CNTRL                0x51C
#define QSERDES_RX_RX_EQU_ADAPTOR_CNTRL2                0x4D8
#define QSERDES_RX_RX_EQU_ADAPTOR_CNTRL3                0x4DC
#define QSERDES_RX_RX_EQU_ADAPTOR_CNTRL4                0x4E0
#define QSERDES_RX_UCDR_SO_SATURATION_AND_ENABLE        0x448
#define QSERDES_RX_UCDR_SO_GAIN                         0x41C
#define QSERDES_RX_UCDR_SO_GAIN_HALF                    0x410
#define QSERDES_COM_CLK_EP_DIV                          0x74
#define PCIE_USB3_PCS_ENDPOINT_REFCLK_DRIVE             0x854
#define PCIE_USB3_PCS_OSC_DTCT_ACTIONS                  0x9AC
#define PCIE_USB3_PCS_PWRUP_RESET_DLY_TIME_AUXCLK       0x8A0
#define PCIE_USB3_PCS_L1SS_WAKEUP_DLY_TIME_AUXCLK_MSB   0x9E0
#define PCIE_USB3_PCS_L1SS_WAKEUP_DLY_TIME_AUXCLK_LSB   0x9DC
#define PCIE_USB3_PCS_PLL_LOCK_CHK_DLY_TIME_AUXCLK_LSB  0x9A8
#define PCIE_USB3_PCS_LP_WAKEUP_DLY_TIME_AUXCLK         0x8A4
#define PCIE_USB3_PCS_PLL_LOCK_CHK_DLY_TIME             0x8A8
#define QSERDES_RX_SIGDET_CNTRL                         0x514
#define PCIE_USB3_PCS_RX_SIGDET_LVL                     0x9D8
#define PCIE_USB3_PCS_TXDEEMPH_M6DB_V0                  0x824
#define PCIE_USB3_PCS_TXDEEMPH_M3P5DB_V0                0x828
#define PCIE_USB3_PCS_SW_RESET                          0x800
#define PCIE_USB3_PCS_START_CONTROL                     0x808
#define PCIE_QSERDES_TX_TX_EMP_POST1_LVL		0x218
#define PCIE_QSERDES_TX_SLEW_CNTL			0x240

struct qca_pcie_qmp_phy {
	void __iomem *base;
	struct clk *pipe_clk;
	struct reset_control *res_phy;
	struct reset_control *res_phy_phy;
	struct device *dev;
};

struct phy_regs {
	u32 reg_offset;
	u32 val;
};


static const struct phy_regs pcie_phy_regs[] = {
	{ PCIE_USB3_PCS_POWER_DOWN_CONTROL,			0x00000003 },
	{ QSERDES_COM_BIAS_EN_CLKBUFLR_EN,			0x00000018 },
	{ QSERDES_COM_CLK_ENABLE1,				0x00000010 },
	{ QSERDES_COM_BG_TRIM,					0x0000000f },
	{ QSERDES_COM_LOCK_CMP_EN,				0x00000001 },
	{ QSERDES_COM_VCO_TUNE_MAP,				0x00000000 },
	{ QSERDES_COM_VCO_TUNE_TIMER1,				0x000000ff },
	{ QSERDES_COM_VCO_TUNE_TIMER2,				0x0000001f },
	{ QSERDES_COM_CMN_CONFIG,				0x00000006 },
	{ QSERDES_COM_PLL_IVCO,					0x0000000f },
	{ QSERDES_COM_HSCLK_SEL,				0x00000000 },
	{ QSERDES_COM_SVS_MODE_CLK_SEL,				0x00000001 },
	{ QSERDES_COM_CORE_CLK_EN,				0x00000020 },
	{ QSERDES_COM_CORECLK_DIV,				0x0000000a },
	{ QSERDES_COM_RESETSM_CNTRL,				0x00000020 },
	{ QSERDES_COM_BG_TIMER,					0x00000009 },
	{ QSERDES_COM_SYSCLK_EN_SEL,				0x0000000a },
	{ QSERDES_COM_DEC_START_MODE0,				0x00000082 },
	{ QSERDES_COM_DIV_FRAC_START3_MODE0,			0x00000003 },
	{ QSERDES_COM_DIV_FRAC_START2_MODE0,			0x00000055 },
	{ QSERDES_COM_DIV_FRAC_START1_MODE0,			0x00000055 },
	{ QSERDES_COM_LOCK_CMP3_MODE0,				0x00000000 },
	{ QSERDES_COM_LOCK_CMP2_MODE0,				0x0000000D },
	{ QSERDES_COM_LOCK_CMP1_MODE0,				0x00000D04 },
	{ QSERDES_COM_CLK_SELECT,				0x00000033 },
	{ QSERDES_COM_SYS_CLK_CTRL,				0x00000002 },
	{ QSERDES_COM_SYSCLK_BUF_ENABLE,			0x0000001f },
	{ QSERDES_COM_CP_CTRL_MODE0,				0x0000000b },
	{ QSERDES_COM_PLL_RCTRL_MODE0,				0x00000016 },
	{ QSERDES_COM_PLL_CCTRL_MODE0,				0x00000028 },
	{ QSERDES_COM_INTEGLOOP_GAIN1_MODE0,			0x00000000 },
	{ QSERDES_COM_INTEGLOOP_GAIN0_MODE0,			0x00000080 },
	{ QSERDES_COM_BIAS_EN_CTRL_BY_PSM,			0x00000001 },
	{ QSERDES_COM_VCO_TUNE_CTRL,				0x0000000a },
	{ QSERDES_COM_SSC_EN_CENTER,				0x00000001 },
	{ QSERDES_COM_SSC_PER1,					0x00000031 },
	{ QSERDES_COM_SSC_PER2,					0x00000001 },
	{ QSERDES_COM_SSC_ADJ_PER1,				0x00000002 },
	{ QSERDES_COM_SSC_ADJ_PER2,				0x00000000 },
	{ QSERDES_COM_SSC_STEP_SIZE1,				0x0000002f },
	{ QSERDES_COM_SSC_STEP_SIZE2,				0x00000019 },
	{ QSERDES_TX_HIGHZ_TRANSCEIVEREN_BIAS_DRVR_EN,		0x00000045 },
	{ QSERDES_TX_LANE_MODE,					0x00000006 },
	{ QSERDES_TX_RES_CODE_LANE_OFFSET,			0x00000002 },
	{ QSERDES_TX_RCV_DETECT_LVL_2,				0x00000012 },
	{ QSERDES_RX_SIGDET_ENABLES,				0x0000001c },
	{ QSERDES_RX_SIGDET_DEGLITCH_CNTRL,			0x00000014 },
	{ QSERDES_RX_RX_EQU_ADAPTOR_CNTRL2,			0x00000001 },
	{ QSERDES_RX_RX_EQU_ADAPTOR_CNTRL3,			0x00000000 },
	{ QSERDES_RX_RX_EQU_ADAPTOR_CNTRL4,			0x000000db },
	{ QSERDES_RX_UCDR_SO_SATURATION_AND_ENABLE,		0x0000004b },
	{ QSERDES_RX_UCDR_SO_GAIN,				0x00000004 },
	{ QSERDES_RX_UCDR_SO_GAIN_HALF,				0x00000004 },
	{ QSERDES_COM_CLK_EP_DIV,				0x00000019 },
	{ PCIE_USB3_PCS_ENDPOINT_REFCLK_DRIVE,			0x00000004 },
	{ PCIE_USB3_PCS_OSC_DTCT_ACTIONS,			0x00000000 },
	{ PCIE_USB3_PCS_PWRUP_RESET_DLY_TIME_AUXCLK,		0x00000040 },
	{ PCIE_USB3_PCS_L1SS_WAKEUP_DLY_TIME_AUXCLK_MSB,	0x00000000 },
	{ PCIE_USB3_PCS_L1SS_WAKEUP_DLY_TIME_AUXCLK_LSB,	0x00000040 },
	{ PCIE_USB3_PCS_PLL_LOCK_CHK_DLY_TIME_AUXCLK_LSB,	0x00000000 },
	{ PCIE_USB3_PCS_LP_WAKEUP_DLY_TIME_AUXCLK,		0x00000040 },
	{ PCIE_USB3_PCS_PLL_LOCK_CHK_DLY_TIME,			0x00000073 },
	{ QSERDES_RX_SIGDET_CNTRL,				0x00000007 },
	{ PCIE_USB3_PCS_RX_SIGDET_LVL,				0x00000099 },
	{ PCIE_USB3_PCS_TXDEEMPH_M6DB_V0,			0x00000015 },
	{ PCIE_USB3_PCS_TXDEEMPH_M3P5DB_V0,			0x0000000e },
	{ PCIE_USB3_PCS_SW_RESET,				0x00000000 },
	{ PCIE_USB3_PCS_START_CONTROL,				0x00000003 },
	{ PCIE_QSERDES_TX_TX_EMP_POST1_LVL,			0x00000036 },
	{ PCIE_QSERDES_TX_SLEW_CNTL,				0x0000000A },
};

static int qca_pcie_qmp_phy_init(struct qca_pcie_qmp_phy *pcie)
{
	const struct phy_regs *regs = pcie_phy_regs;
	int i;

	for (i = 0; i < ARRAY_SIZE(pcie_phy_regs); i++)
		writel(regs[i].val, pcie->base + regs[i].reg_offset);

	return 0;
}

static bool qca_pcie_qmp_phy_is_ready(struct qca_pcie_qmp_phy *pcie)
{
	u32 val = readl(pcie->base + PCIE_PHY_PCS_STATUS);

	return val & BIT(6) ? false : true;
}

static int qca_pcie_qmp_phy_reset(struct qca_pcie_qmp_phy *pcie)
{
	reset_control_assert(pcie->res_phy);
	reset_control_assert(pcie->res_phy_phy);

	usleep_range(100, 150);

	reset_control_deassert(pcie->res_phy);
	reset_control_deassert(pcie->res_phy_phy);

	return 0;
}

static int qca_pcie_qmp_phy_power_on(struct phy *phy)
{
	struct qca_pcie_qmp_phy *pcie = phy_get_drvdata(phy);
	int ret, retries;

	qca_pcie_qmp_phy_reset(pcie);

	clk_set_rate(pcie->pipe_clk, 125000000);
	usleep_range(PIPE_CLK_DELAY_MIN_US, PIPE_CLK_DELAY_MAX_US);
	clk_prepare_enable(pcie->pipe_clk);

	qca_pcie_qmp_phy_init(pcie);

	retries = PHY_RETRIES_COUNT;
	do {
		ret = qca_pcie_qmp_phy_is_ready(pcie);
		if (ret)
			break;
		usleep_range(PHY_DELAY_MIN_US, PHY_DELAY_MAX_US);
	} while (retries--);

	if (retries < 0) {
		dev_err(pcie->dev, "phy failed to come up\n");
		ret = -ETIMEDOUT;
		goto fail;
	}

	return 0;

fail:
	clk_disable_unprepare(pcie->pipe_clk);
	reset_control_assert(pcie->res_phy);
	reset_control_assert(pcie->res_phy_phy);

	return ret;
}

static int qca_pcie_qmp_phy_power_off(struct phy *phy)
{
	struct qca_pcie_qmp_phy *pcie = phy_get_drvdata(phy);

	writel(1, pcie->base + PCIE_PHY_SW_RESET);
	writel(0, pcie->base + PCIE_PHY_POWER_DOWN_CONTROL);

	reset_control_assert(pcie->res_phy);
	reset_control_assert(pcie->res_phy_phy);
	clk_disable_unprepare(pcie->pipe_clk);

	return 0;
}

static struct phy_ops qca_pcie_qmp_phy_ops = {
	.power_on = qca_pcie_qmp_phy_power_on,
	.power_off = qca_pcie_qmp_phy_power_off,
	.owner = THIS_MODULE,
};

static int qca_pcie_qmp_phy_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct phy_provider *provider;
	struct qca_pcie_qmp_phy *pcie;
	struct resource *res;
	struct phy *phy;

	pcie = devm_kzalloc(dev, sizeof(*pcie), GFP_KERNEL);
	if (!pcie)
		return -ENOMEM;
	pcie->dev = &pdev->dev;
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	pcie->base = devm_ioremap_resource(pcie->dev, res);
	if (IS_ERR(pcie->base))
		return PTR_ERR(pcie->base);

	pcie->pipe_clk = devm_clk_get(dev, "pipe_clk");
	if (IS_ERR(pcie->pipe_clk)) {
		return PTR_ERR(pcie->pipe_clk);
	}

	pcie->res_phy = devm_reset_control_get(dev, "phy");
	if (IS_ERR(pcie->res_phy)) {
		dev_err(dev, "cannot get phy reset controller");
		return PTR_ERR(pcie->res_phy);
	}

	pcie->res_phy_phy = devm_reset_control_get(dev, "phy_phy");
	if (IS_ERR(pcie->res_phy_phy)) {
		dev_err(dev, "cannot get phy_phy reset controller");
		return PTR_ERR(pcie->res_phy_phy);
	}

	phy = devm_phy_create(pcie->dev, NULL, &qca_pcie_qmp_phy_ops);
	if (IS_ERR(phy)) {
		dev_err(dev, "failed to create phy\n");
		return PTR_ERR(phy);
	}

	phy_set_drvdata(phy, pcie);
	platform_set_drvdata(pdev, pcie);
	provider = devm_of_phy_provider_register(pcie->dev,
				of_phy_simple_xlate);
	if (IS_ERR(provider))
		return PTR_ERR(provider);


	return 0;
}

static int qca_pcie_qmp_phy_remove(struct platform_device *pdev)
{
	struct qca_pcie_qmp_phy *pcie = platform_get_drvdata(pdev);

	clk_disable_unprepare(pcie->pipe_clk);

	return 0;
}

static const struct of_device_id qca_pcie_qmp_phy_of_match[] = {
	{ .compatible = "qca,pcie-qmp-phy" },
	{ },
};
MODULE_DEVICE_TABLE(of, qca_pcie_qmp_phy_of_match);

static struct platform_driver qca_pcie_qmp_phy_driver = {
	.probe = qca_pcie_qmp_phy_probe,
	.remove = qca_pcie_qmp_phy_remove,
	.driver = {
		.name = "pcie-phy",
		.of_match_table = qca_pcie_qmp_phy_of_match,
	}
};
module_platform_driver(qca_pcie_qmp_phy_driver);

MODULE_DESCRIPTION("PCIe QMP PHY driver");
MODULE_ALIAS("platform:pcie-phy");
