/*
 * Copyright (c) 2015-2017, The Linux Foundation. All rights reserved.
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
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/pinctrl/pinctrl.h>

#include "pinctrl-msm.h"

#define FUNCTION(fname)			                \
	[msm_mux_##fname] = {		                \
		.name = #fname,				\
		.groups = fname##_groups,               \
		.ngroups = ARRAY_SIZE(fname##_groups),	\
	}

#define REG_SIZE 0x1000
#define PINGROUP(id, f1, f2, f3, f4, f5, f6, f7, f8, f9)	\
	{					        \
		.name = "gpio" #id,			\
		.pins = gpio##id##_pins,		\
		.npins = (unsigned)ARRAY_SIZE(gpio##id##_pins),	\
		.funcs = (int[]){			\
			msm_mux_gpio, /* gpio mode */	\
			msm_mux_##f1,			\
			msm_mux_##f2,			\
			msm_mux_##f3,			\
			msm_mux_##f4,			\
			msm_mux_##f5,			\
			msm_mux_##f6,			\
			msm_mux_##f7,			\
			msm_mux_##f8,			\
			msm_mux_##f9			\
		},				        \
		.nfuncs = 10,				\
		.ctl_reg = REG_SIZE * id,	        	\
		.io_reg = 0x4 + REG_SIZE * id,		\
		.intr_cfg_reg = 0x8 + REG_SIZE * id,		\
		.intr_status_reg = 0xc + REG_SIZE * id,	\
		.intr_target_reg = 0x8 + REG_SIZE * id,	\
		.mux_bit = 2,			\
		.pull_bit = 0,			\
		.drv_bit = 6,			\
		.oe_bit = 9,			\
		.in_bit = 0,			\
		.out_bit = 1,			\
		.intr_enable_bit = 0,		\
		.intr_status_bit = 0,		\
		.intr_target_bit = 5,		\
		.intr_target_kpss_val = 3,	\
		.intr_raw_status_bit = 4,	\
		.intr_polarity_bit = 1,		\
		.intr_detection_bit = 2,	\
		.intr_detection_width = 2,	\
	}

static const struct pinctrl_pin_desc ipq807x_pins[] = {
	PINCTRL_PIN(0, "GPIO_0"),
	PINCTRL_PIN(1, "GPIO_1"),
	PINCTRL_PIN(2, "GPIO_2"),
	PINCTRL_PIN(3, "GPIO_3"),
	PINCTRL_PIN(4, "GPIO_4"),
	PINCTRL_PIN(5, "GPIO_5"),
	PINCTRL_PIN(6, "GPIO_6"),
	PINCTRL_PIN(7, "GPIO_7"),
	PINCTRL_PIN(8, "GPIO_8"),
	PINCTRL_PIN(9, "GPIO_9"),
	PINCTRL_PIN(10, "GPIO_10"),
	PINCTRL_PIN(11, "GPIO_11"),
	PINCTRL_PIN(12, "GPIO_12"),
	PINCTRL_PIN(13, "GPIO_13"),
	PINCTRL_PIN(14, "GPIO_14"),
	PINCTRL_PIN(15, "GPIO_15"),
	PINCTRL_PIN(16, "GPIO_16"),
	PINCTRL_PIN(17, "GPIO_17"),
	PINCTRL_PIN(18, "GPIO_18"),
	PINCTRL_PIN(19, "GPIO_19"),
	PINCTRL_PIN(20, "GPIO_20"),
	PINCTRL_PIN(21, "GPIO_21"),
	PINCTRL_PIN(22, "GPIO_22"),
	PINCTRL_PIN(23, "GPIO_23"),
	PINCTRL_PIN(24, "GPIO_24"),
	PINCTRL_PIN(25, "GPIO_25"),
	PINCTRL_PIN(26, "GPIO_26"),
	PINCTRL_PIN(27, "GPIO_27"),
	PINCTRL_PIN(28, "GPIO_28"),
	PINCTRL_PIN(29, "GPIO_29"),
	PINCTRL_PIN(30, "GPIO_30"),
	PINCTRL_PIN(31, "GPIO_31"),
	PINCTRL_PIN(32, "GPIO_32"),
	PINCTRL_PIN(33, "GPIO_33"),
	PINCTRL_PIN(34, "GPIO_34"),
	PINCTRL_PIN(35, "GPIO_35"),
	PINCTRL_PIN(36, "GPIO_36"),
	PINCTRL_PIN(37, "GPIO_37"),
	PINCTRL_PIN(38, "GPIO_38"),
	PINCTRL_PIN(39, "GPIO_39"),
	PINCTRL_PIN(40, "GPIO_40"),
	PINCTRL_PIN(41, "GPIO_41"),
	PINCTRL_PIN(42, "GPIO_42"),
	PINCTRL_PIN(43, "GPIO_43"),
	PINCTRL_PIN(44, "GPIO_44"),
	PINCTRL_PIN(45, "GPIO_45"),
	PINCTRL_PIN(46, "GPIO_46"),
	PINCTRL_PIN(47, "GPIO_47"),
	PINCTRL_PIN(48, "GPIO_48"),
	PINCTRL_PIN(49, "GPIO_49"),
	PINCTRL_PIN(50, "GPIO_50"),
	PINCTRL_PIN(51, "GPIO_51"),
	PINCTRL_PIN(52, "GPIO_52"),
	PINCTRL_PIN(53, "GPIO_53"),
	PINCTRL_PIN(54, "GPIO_54"),
	PINCTRL_PIN(55, "GPIO_55"),
	PINCTRL_PIN(56, "GPIO_56"),
	PINCTRL_PIN(57, "GPIO_57"),
	PINCTRL_PIN(58, "GPIO_58"),
	PINCTRL_PIN(59, "GPIO_59"),
	PINCTRL_PIN(60, "GPIO_60"),
	PINCTRL_PIN(61, "GPIO_61"),
	PINCTRL_PIN(62, "GPIO_62"),
	PINCTRL_PIN(63, "GPIO_63"),
	PINCTRL_PIN(64, "GPIO_64"),
	PINCTRL_PIN(65, "GPIO_65"),
	PINCTRL_PIN(66, "GPIO_66"),
	PINCTRL_PIN(67, "GPIO_67"),
	PINCTRL_PIN(68, "GPIO_68"),
	PINCTRL_PIN(69, "GPIO_69"),
	PINCTRL_PIN(70, "SDC1_CLK"),
	PINCTRL_PIN(71, "SDC1_CMD"),
	PINCTRL_PIN(72, "SDC1_DATA"),
	PINCTRL_PIN(73, "SDC2_CLK"),
	PINCTRL_PIN(74, "SDC2_CMD"),
	PINCTRL_PIN(75, "SDC2_DATA"),
};

#define DECLARE_MSM_GPIO_PINS(pin) \
	static const unsigned int gpio##pin##_pins[] = { pin }
DECLARE_MSM_GPIO_PINS(0);
DECLARE_MSM_GPIO_PINS(1);
DECLARE_MSM_GPIO_PINS(2);
DECLARE_MSM_GPIO_PINS(3);
DECLARE_MSM_GPIO_PINS(4);
DECLARE_MSM_GPIO_PINS(5);
DECLARE_MSM_GPIO_PINS(6);
DECLARE_MSM_GPIO_PINS(7);
DECLARE_MSM_GPIO_PINS(8);
DECLARE_MSM_GPIO_PINS(9);
DECLARE_MSM_GPIO_PINS(10);
DECLARE_MSM_GPIO_PINS(11);
DECLARE_MSM_GPIO_PINS(12);
DECLARE_MSM_GPIO_PINS(13);
DECLARE_MSM_GPIO_PINS(14);
DECLARE_MSM_GPIO_PINS(15);
DECLARE_MSM_GPIO_PINS(16);
DECLARE_MSM_GPIO_PINS(17);
DECLARE_MSM_GPIO_PINS(18);
DECLARE_MSM_GPIO_PINS(19);
DECLARE_MSM_GPIO_PINS(20);
DECLARE_MSM_GPIO_PINS(21);
DECLARE_MSM_GPIO_PINS(22);
DECLARE_MSM_GPIO_PINS(23);
DECLARE_MSM_GPIO_PINS(24);
DECLARE_MSM_GPIO_PINS(25);
DECLARE_MSM_GPIO_PINS(26);
DECLARE_MSM_GPIO_PINS(27);
DECLARE_MSM_GPIO_PINS(28);
DECLARE_MSM_GPIO_PINS(29);
DECLARE_MSM_GPIO_PINS(30);
DECLARE_MSM_GPIO_PINS(31);
DECLARE_MSM_GPIO_PINS(32);
DECLARE_MSM_GPIO_PINS(33);
DECLARE_MSM_GPIO_PINS(34);
DECLARE_MSM_GPIO_PINS(35);
DECLARE_MSM_GPIO_PINS(36);
DECLARE_MSM_GPIO_PINS(37);
DECLARE_MSM_GPIO_PINS(38);
DECLARE_MSM_GPIO_PINS(39);
DECLARE_MSM_GPIO_PINS(40);
DECLARE_MSM_GPIO_PINS(41);
DECLARE_MSM_GPIO_PINS(42);
DECLARE_MSM_GPIO_PINS(43);
DECLARE_MSM_GPIO_PINS(44);
DECLARE_MSM_GPIO_PINS(45);
DECLARE_MSM_GPIO_PINS(46);
DECLARE_MSM_GPIO_PINS(47);
DECLARE_MSM_GPIO_PINS(48);
DECLARE_MSM_GPIO_PINS(49);
DECLARE_MSM_GPIO_PINS(50);
DECLARE_MSM_GPIO_PINS(51);
DECLARE_MSM_GPIO_PINS(52);
DECLARE_MSM_GPIO_PINS(53);
DECLARE_MSM_GPIO_PINS(54);
DECLARE_MSM_GPIO_PINS(55);
DECLARE_MSM_GPIO_PINS(56);
DECLARE_MSM_GPIO_PINS(57);
DECLARE_MSM_GPIO_PINS(58);
DECLARE_MSM_GPIO_PINS(59);
DECLARE_MSM_GPIO_PINS(60);
DECLARE_MSM_GPIO_PINS(61);
DECLARE_MSM_GPIO_PINS(62);
DECLARE_MSM_GPIO_PINS(63);
DECLARE_MSM_GPIO_PINS(64);
DECLARE_MSM_GPIO_PINS(65);
DECLARE_MSM_GPIO_PINS(66);
DECLARE_MSM_GPIO_PINS(67);
DECLARE_MSM_GPIO_PINS(68);
DECLARE_MSM_GPIO_PINS(69);

enum ipq807x_functions {
	msm_mux_gpio,
	msm_mux_qpic_pad,
	msm_mux_,
	msm_mux_blsp5_i2c,
	msm_mux_blsp5_spi,
	msm_mux_wci20,
	msm_mux_blsp3_spi3,
	msm_mux_burn0,
	msm_mux_pcm_zsi0,
	msm_mux_blsp5_uart,
	msm_mux_mac12,
	msm_mux_blsp3_spi0,
	msm_mux_burn1,
	msm_mux_mac01,
	msm_mux_qdss_cti_trig_out_b0,
	msm_mux_qdss_cti_trig_in_b0,
	msm_mux_qpic_pad4,
	msm_mux_blsp4_uart0,
	msm_mux_blsp4_i2c0,
	msm_mux_blsp4_spi0,
	msm_mux_mac21,
	msm_mux_qdss_cti_trig_out_b1,
	msm_mux_qpic_pad5,
	msm_mux_qdss_cti_trig_in_b1,
	msm_mux_qpic_pad6,
	msm_mux_qpic_pad7,
	msm_mux_cxc0,
	msm_mux_mac13,
	msm_mux_qdss_cti_trig_in_a1,
	msm_mux_qdss_cti_trig_out_a1,
	msm_mux_wci22,
	msm_mux_qdss_cti_trig_in_a0,
	msm_mux_qpic_pad1,
	msm_mux_qdss_cti_trig_out_a0,
	msm_mux_qpic_pad2,
	msm_mux_qpic_pad3,
	msm_mux_qdss_traceclk_b,
	msm_mux_qpic_pad0,
	msm_mux_qdss_tracectl_b,
	msm_mux_qpic_pad8,
	msm_mux_pcm_zsi1,
	msm_mux_qdss_tracedata_b,
	msm_mux_led0,
	msm_mux_pwm04,
	msm_mux_led1,
	msm_mux_pwm14,
	msm_mux_led2,
	msm_mux_pwm24,
	msm_mux_pwm00,
	msm_mux_blsp4_uart1,
	msm_mux_blsp4_i2c1,
	msm_mux_blsp4_spi1,
	msm_mux_wci23,
	msm_mux_mac11,
	msm_mux_blsp3_spi2,
	msm_mux_pwm10,
	msm_mux_pwm20,
	msm_mux_pwm30,
	msm_mux_audio_txmclk,
	msm_mux_pwm02,
	msm_mux_audio_txbclk,
	msm_mux_pwm12,
	msm_mux_audio_txfsync,
	msm_mux_pwm22,
	msm_mux_audio_txd,
	msm_mux_pwm32,
	msm_mux_audio_rxmclk,
	msm_mux_pwm03,
	msm_mux_atest_char0,
	msm_mux_audio_rxbclk,
	msm_mux_pwm13,
	msm_mux_atest_char1,
	msm_mux_audio_rxfsync,
	msm_mux_pwm23,
	msm_mux_atest_char2,
	msm_mux_audio_rxd,
	msm_mux_pwm33,
	msm_mux_atest_char3,
	msm_mux_pcm_drx,
	msm_mux_mac10,
	msm_mux_mac00,
	msm_mux_pcm_dtx,
	msm_mux_pcm_fsync,
	msm_mux_mac20,
	msm_mux_qdss_traceclk_a,
	msm_mux_pcm_pclk,
	msm_mux_qdss_tracectl_a,
	msm_mux_atest_char,
	msm_mux_qdss_tracedata_a,
	msm_mux_blsp0_uart,
	msm_mux_blsp0_i2c,
	msm_mux_blsp0_spi,
	msm_mux_blsp1_uart,
	msm_mux_blsp1_i2c,
	msm_mux_blsp1_spi,
	msm_mux_blsp2_uart,
	msm_mux_blsp2_i2c,
	msm_mux_blsp2_spi,
	msm_mux_blsp3_uart,
	msm_mux_blsp3_i2c,
	msm_mux_blsp3_spi,
	msm_mux_pta2_0,
	msm_mux_wci21,
	msm_mux_cxc1,
	msm_mux_blsp3_spi1,
	msm_mux_pta2_1,
	msm_mux_pta2_2,
	msm_mux_pcie0_clk,
	msm_mux_dbg_out,
	msm_mux_cri_trng0,
	msm_mux_pcie0_rst,
	msm_mux_cri_trng1,
	msm_mux_pcie0_wake,
	msm_mux_cri_trng,
	msm_mux_pcie1_clk,
	msm_mux_rx2,
	msm_mux_ldo_update,
	msm_mux_pcie1_rst,
	msm_mux_ldo_en,
	msm_mux_pcie1_wake,
	msm_mux_gcc_plltest,
	msm_mux_sd_card,
	msm_mux_pwm01,
	msm_mux_pta1_1,
	msm_mux_pwm11,
	msm_mux_rx1,
	msm_mux_pta1_2,
	msm_mux_gcc_tlmm,
	msm_mux_pta1_0,
	msm_mux_pwm21,
	msm_mux_prng_rosc,
	msm_mux_sd_write,
	msm_mux_pwm31,
	msm_mux_rx0,
	msm_mux_tsens_max,
	msm_mux_mdc,
	msm_mux_mdio,
	msm_mux_NA,
};

static const char * const qpic_pad_groups[] = {
	"gpio0", "gpio1", "gpio2", "gpio3", "gpio4", "gpio9", "gpio10",
	"gpio11", "gpio17",
};
static const char * const _groups[] = {
	"gpio0", "gpio1", "gpio2", "gpio3", "gpio4", "gpio5", "gpio6", "gpio7",
	"gpio8", "gpio9", "gpio10", "gpio11", "gpio12", "gpio13", "gpio14",
	"gpio15", "gpio16", "gpio17", "gpio18", "gpio19", "gpio20", "gpio21",
	"gpio22", "gpio23", "gpio24", "gpio25", "gpio26", "gpio27", "gpio28",
	"gpio29", "gpio30", "gpio31", "gpio32", "gpio33", "gpio34", "gpio35",
	"gpio36", "gpio37", "gpio38", "gpio39", "gpio40", "gpio41", "gpio42",
	"gpio43", "gpio44", "gpio45", "gpio46", "gpio47", "gpio48", "gpio49",
	"gpio50", "gpio51", "gpio52", "gpio53", "gpio54", "gpio55", "gpio56",
	"gpio57", "gpio58", "gpio59", "gpio60", "gpio61", "gpio62", "gpio63",
	"gpio64", "gpio65", "gpio66", "gpio67", "gpio68", "gpio69",
};
static const char * const blsp5_i2c_groups[] = {
	"gpio0", "gpio2",
};
static const char * const blsp5_spi_groups[] = {
	"gpio0", "gpio2", "gpio9", "gpio16",
};
static const char * const wci20_groups[] = {
	"gpio0", "gpio2",
};
static const char * const blsp3_spi3_groups[] = {
	"gpio0", "gpio2", "gpio9",
};
static const char * const burn0_groups[] = {
	"gpio0",
};
static const char * const pcm_zsi0_groups[] = {
	"gpio1",
};
static const char * const blsp5_uart_groups[] = {
	"gpio0", "gpio2", "gpio9", "gpio16",
};
static const char * const mac12_groups[] = {
	"gpio1", "gpio11",
};
static const char * const blsp3_spi0_groups[] = {
	"gpio1", "gpio3", "gpio4",
};
static const char * const burn1_groups[] = {
	"gpio1",
};
static const char * const mac01_groups[] = {
	"gpio3", "gpio4",
};
static const char * const qdss_cti_trig_out_b0_groups[] = {
	"gpio3",
};
static const char * const qdss_cti_trig_in_b0_groups[] = {
	"gpio4",
};
static const char * const qpic_pad4_groups[] = {
	"gpio5",
};
static const char * const blsp4_uart0_groups[] = {
	"gpio5", "gpio6", "gpio7", "gpio8",
};
static const char * const blsp4_i2c0_groups[] = {
	"gpio5", "gpio6",
};
static const char * const blsp4_spi0_groups[] = {
	"gpio5", "gpio6", "gpio7", "gpio8",
};
static const char * const mac21_groups[] = {
	"gpio5", "gpio6",
};
static const char * const qdss_cti_trig_out_b1_groups[] = {
	"gpio5",
};
static const char * const qpic_pad5_groups[] = {
	"gpio6",
};
static const char * const qdss_cti_trig_in_b1_groups[] = {
	"gpio6",
};
static const char * const qpic_pad6_groups[] = {
	"gpio7",
};
static const char * const qpic_pad7_groups[] = {
	"gpio8",
};
static const char * const cxc0_groups[] = {
	"gpio9", "gpio16",
};
static const char * const mac13_groups[] = {
	"gpio9", "gpio16",
};
static const char * const qdss_cti_trig_in_a1_groups[] = {
	"gpio9",
};
static const char * const qdss_cti_trig_out_a1_groups[] = {
	"gpio10",
};
static const char * const wci22_groups[] = {
	"gpio11", "gpio17",
};
static const char * const qdss_cti_trig_in_a0_groups[] = {
	"gpio11",
};
static const char * const qpic_pad1_groups[] = {
	"gpio12",
};
static const char * const qdss_cti_trig_out_a0_groups[] = {
	"gpio12",
};
static const char * const qpic_pad2_groups[] = {
	"gpio13",
};
static const char * const qpic_pad3_groups[] = {
	"gpio14",
};
static const char * const qdss_traceclk_b_groups[] = {
	"gpio14",
};
static const char * const qpic_pad0_groups[] = {
	"gpio15",
};
static const char * const qdss_tracectl_b_groups[] = {
	"gpio15",
};
static const char * const qpic_pad8_groups[] = {
	"gpio16",
};
static const char * const pcm_zsi1_groups[] = {
	"gpio16",
};
static const char * const qdss_tracedata_b_groups[] = {
	"gpio16", "gpio17", "gpio18", "gpio19", "gpio20", "gpio21", "gpio22",
	"gpio23", "gpio24", "gpio25", "gpio26", "gpio27", "gpio28", "gpio29",
	"gpio30", "gpio31",
};
static const char * const led0_groups[] = {
	"gpio18",
};
static const char * const pwm04_groups[] = {
	"gpio18",
};
static const char * const led1_groups[] = {
	"gpio19",
};
static const char * const pwm14_groups[] = {
	"gpio19",
};
static const char * const led2_groups[] = {
	"gpio20",
};
static const char * const pwm24_groups[] = {
	"gpio20",
};
static const char * const pwm00_groups[] = {
	"gpio21",
};
static const char * const blsp4_uart1_groups[] = {
	"gpio21", "gpio22", "gpio23", "gpio24",
};
static const char * const blsp4_i2c1_groups[] = {
	"gpio21", "gpio22",
};
static const char * const blsp4_spi1_groups[] = {
	"gpio21", "gpio22", "gpio23", "gpio24",
};
static const char * const wci23_groups[] = {
	"gpio21", "gpio22",
};
static const char * const mac11_groups[] = {
	"gpio21", "gpio22",
};
static const char * const blsp3_spi2_groups[] = {
	"gpio21", "gpio22", "gpio23",
};
static const char * const pwm10_groups[] = {
	"gpio22",
};
static const char * const pwm20_groups[] = {
	"gpio23",
};
static const char * const pwm30_groups[] = {
	"gpio24",
};
static const char * const audio_txmclk_groups[] = {
	"gpio25",
};
static const char * const pwm02_groups[] = {
	"gpio25",
};
static const char * const audio_txbclk_groups[] = {
	"gpio26",
};
static const char * const pwm12_groups[] = {
	"gpio26",
};
static const char * const audio_txfsync_groups[] = {
	"gpio27",
};
static const char * const pwm22_groups[] = {
	"gpio27",
};
static const char * const audio_txd_groups[] = {
	"gpio28",
};
static const char * const pwm32_groups[] = {
	"gpio28",
};
static const char * const audio_rxmclk_groups[] = {
	"gpio29",
};
static const char * const pwm03_groups[] = {
	"gpio29",
};
static const char * const atest_char0_groups[] = {
	"gpio29",
};
static const char * const audio_rxbclk_groups[] = {
	"gpio30",
};
static const char * const pwm13_groups[] = {
	"gpio30",
};
static const char * const atest_char1_groups[] = {
	"gpio30",
};
static const char * const audio_rxfsync_groups[] = {
	"gpio31",
};
static const char * const pwm23_groups[] = {
	"gpio31",
};
static const char * const atest_char2_groups[] = {
	"gpio31",
};
static const char * const audio_rxd_groups[] = {
	"gpio32",
};
static const char * const pwm33_groups[] = {
	"gpio32",
};
static const char * const atest_char3_groups[] = {
	"gpio32",
};
static const char * const pcm_drx_groups[] = {
	"gpio33",
};
static const char * const mac10_groups[] = {
	"gpio33", "gpio34",
};
static const char * const mac00_groups[] = {
	"gpio33", "gpio34",
};
static const char * const pcm_dtx_groups[] = {
	"gpio34",
};
static const char * const pcm_fsync_groups[] = {
	"gpio35",
};
static const char * const mac20_groups[] = {
	"gpio35", "gpio36",
};
static const char * const qdss_traceclk_a_groups[] = {
	"gpio35",
};
static const char * const pcm_pclk_groups[] = {
	"gpio36",
};
static const char * const qdss_tracectl_a_groups[] = {
	"gpio36",
};
static const char * const atest_char_groups[] = {
	"gpio37",
};
static const char * const qdss_tracedata_a_groups[] = {
	"gpio37", "gpio38", "gpio39", "gpio40", "gpio41", "gpio42", "gpio43",
	"gpio44", "gpio45", "gpio46", "gpio47", "gpio48", "gpio49", "gpio50",
	"gpio51", "gpio52",
};
static const char * const blsp0_uart_groups[] = {
	"gpio38", "gpio39", "gpio40", "gpio41",
};
static const char * const blsp0_i2c_groups[] = {
	"gpio38", "gpio39",
};
static const char * const blsp0_spi_groups[] = {
	"gpio38", "gpio39", "gpio40", "gpio41",
};
static const char * const blsp1_uart_groups[] = {
	"gpio42", "gpio43", "gpio44", "gpio45",
};
static const char * const blsp1_i2c_groups[] = {
	"gpio42", "gpio43",
};
static const char * const blsp1_spi_groups[] = {
	"gpio42", "gpio43", "gpio44", "gpio45",
};
static const char * const blsp2_uart_groups[] = {
	"gpio46", "gpio47", "gpio48", "gpio49",
};
static const char * const blsp2_i2c_groups[] = {
	"gpio46", "gpio47",
};
static const char * const blsp2_spi_groups[] = {
	"gpio46", "gpio47", "gpio48", "gpio49",
};
static const char * const blsp3_uart_groups[] = {
	"gpio50", "gpio51", "gpio52", "gpio53",
};
static const char * const blsp3_i2c_groups[] = {
	"gpio50", "gpio51",
};
static const char * const blsp3_spi_groups[] = {
	"gpio50", "gpio51", "gpio52", "gpio53",
};
static const char * const pta2_0_groups[] = {
	"gpio54",
};
static const char * const wci21_groups[] = {
	"gpio54", "gpio56",
};
static const char * const cxc1_groups[] = {
	"gpio54", "gpio56",
};
static const char * const blsp3_spi1_groups[] = {
	"gpio54", "gpio55", "gpio56",
};
static const char * const pta2_1_groups[] = {
	"gpio55",
};
static const char * const pta2_2_groups[] = {
	"gpio56",
};
static const char * const pcie0_clk_groups[] = {
	"gpio57",
};
static const char * const dbg_out_groups[] = {
	"gpio57",
};
static const char * const cri_trng0_groups[] = {
	"gpio57",
};
static const char * const pcie0_rst_groups[] = {
	"gpio58",
};
static const char * const cri_trng1_groups[] = {
	"gpio58",
};
static const char * const pcie0_wake_groups[] = {
	"gpio59",
};
static const char * const cri_trng_groups[] = {
	"gpio59",
};
static const char * const pcie1_clk_groups[] = {
	"gpio60",
};
static const char * const rx2_groups[] = {
	"gpio60",
};
static const char * const ldo_update_groups[] = {
	"gpio60",
};
static const char * const pcie1_rst_groups[] = {
	"gpio61",
};
static const char * const ldo_en_groups[] = {
	"gpio61",
};
static const char * const pcie1_wake_groups[] = {
	"gpio62",
};
static const char * const gcc_plltest_groups[] = {
	"gpio62", "gpio63",
};
static const char * const sd_card_groups[] = {
	"gpio63",
};
static const char * const pwm01_groups[] = {
	"gpio63",
};
static const char * const pta1_1_groups[] = {
	"gpio64",
};
static const char * const pwm11_groups[] = {
	"gpio64",
};
static const char * const rx1_groups[] = {
	"gpio64",
};
static const char * const pta1_2_groups[] = {
	"gpio65",
};
static const char * const gcc_tlmm_groups[] = {
	"gpio65",
};
static const char * const pta1_0_groups[] = {
	"gpio66",
};
static const char * const pwm21_groups[] = {
	"gpio66",
};
static const char * const prng_rosc_groups[] = {
	"gpio66",
};
static const char * const sd_write_groups[] = {
	"gpio67",
};
static const char * const pwm31_groups[] = {
	"gpio67",
};
static const char * const rx0_groups[] = {
	"gpio67",
};
static const char * const tsens_max_groups[] = {
	"gpio67",
};
static const char * const mdc_groups[] = {
	"gpio68",
};
static const char * const mdio_groups[] = {
	"gpio69",
};

static const char * const gpio_groups[] = {
	"gpio0", "gpio1", "gpio2", "gpio3", "gpio4", "gpio5", "gpio6", "gpio7",
	"gpio8", "gpio9", "gpio10", "gpio11", "gpio12", "gpio13", "gpio14",
	"gpio15", "gpio16", "gpio17", "gpio18", "gpio19", "gpio20", "gpio21",
	"gpio22", "gpio23", "gpio24", "gpio25", "gpio26", "gpio27", "gpio28",
	"gpio29", "gpio30", "gpio31", "gpio32", "gpio33", "gpio34", "gpio35",
	"gpio36", "gpio37", "gpio38", "gpio39", "gpio40", "gpio41", "gpio42",
	"gpio43", "gpio44", "gpio45", "gpio46", "gpio47", "gpio48", "gpio49",
	"gpio50", "gpio51", "gpio52", "gpio53", "gpio54", "gpio55", "gpio56",
	"gpio57", "gpio58", "gpio59", "gpio60", "gpio61", "gpio62", "gpio63",
	"gpio64", "gpio65", "gpio66", "gpio67", "gpio68", "gpio69",
};

static const struct msm_function ipq807x_functions[] = {
	FUNCTION(gpio),
	FUNCTION(qpic_pad),
	FUNCTION(),
	FUNCTION(blsp5_i2c),
	FUNCTION(blsp5_spi),
	FUNCTION(wci20),
	FUNCTION(blsp3_spi3),
	FUNCTION(burn0),
	FUNCTION(pcm_zsi0),
	FUNCTION(blsp5_uart),
	FUNCTION(mac12),
	FUNCTION(blsp3_spi0),
	FUNCTION(burn1),
	FUNCTION(mac01),
	FUNCTION(qdss_cti_trig_out_b0),
	FUNCTION(qdss_cti_trig_in_b0),
	FUNCTION(qpic_pad4),
	FUNCTION(blsp4_uart0),
	FUNCTION(blsp4_i2c0),
	FUNCTION(blsp4_spi0),
	FUNCTION(mac21),
	FUNCTION(qdss_cti_trig_out_b1),
	FUNCTION(qpic_pad5),
	FUNCTION(qdss_cti_trig_in_b1),
	FUNCTION(qpic_pad6),
	FUNCTION(qpic_pad7),
	FUNCTION(cxc0),
	FUNCTION(mac13),
	FUNCTION(qdss_cti_trig_in_a1),
	FUNCTION(qdss_cti_trig_out_a1),
	FUNCTION(wci22),
	FUNCTION(qdss_cti_trig_in_a0),
	FUNCTION(qpic_pad1),
	FUNCTION(qdss_cti_trig_out_a0),
	FUNCTION(qpic_pad2),
	FUNCTION(qpic_pad3),
	FUNCTION(qdss_traceclk_b),
	FUNCTION(qpic_pad0),
	FUNCTION(qdss_tracectl_b),
	FUNCTION(qpic_pad8),
	FUNCTION(pcm_zsi1),
	FUNCTION(qdss_tracedata_b),
	FUNCTION(led0),
	FUNCTION(pwm04),
	FUNCTION(led1),
	FUNCTION(pwm14),
	FUNCTION(led2),
	FUNCTION(pwm24),
	FUNCTION(pwm00),
	FUNCTION(blsp4_uart1),
	FUNCTION(blsp4_i2c1),
	FUNCTION(blsp4_spi1),
	FUNCTION(wci23),
	FUNCTION(mac11),
	FUNCTION(blsp3_spi2),
	FUNCTION(pwm10),
	FUNCTION(pwm20),
	FUNCTION(pwm30),
	FUNCTION(audio_txmclk),
	FUNCTION(pwm02),
	FUNCTION(audio_txbclk),
	FUNCTION(pwm12),
	FUNCTION(audio_txfsync),
	FUNCTION(pwm22),
	FUNCTION(audio_txd),
	FUNCTION(pwm32),
	FUNCTION(audio_rxmclk),
	FUNCTION(pwm03),
	FUNCTION(atest_char0),
	FUNCTION(audio_rxbclk),
	FUNCTION(pwm13),
	FUNCTION(atest_char1),
	FUNCTION(audio_rxfsync),
	FUNCTION(pwm23),
	FUNCTION(atest_char2),
	FUNCTION(audio_rxd),
	FUNCTION(pwm33),
	FUNCTION(atest_char3),
	FUNCTION(pcm_drx),
	FUNCTION(mac10),
	FUNCTION(mac00),
	FUNCTION(pcm_dtx),
	FUNCTION(pcm_fsync),
	FUNCTION(mac20),
	FUNCTION(qdss_traceclk_a),
	FUNCTION(pcm_pclk),
	FUNCTION(qdss_tracectl_a),
	FUNCTION(atest_char),
	FUNCTION(qdss_tracedata_a),
	FUNCTION(blsp0_uart),
	FUNCTION(blsp0_i2c),
	FUNCTION(blsp0_spi),
	FUNCTION(blsp1_uart),
	FUNCTION(blsp1_i2c),
	FUNCTION(blsp1_spi),
	FUNCTION(blsp2_uart),
	FUNCTION(blsp2_i2c),
	FUNCTION(blsp2_spi),
	FUNCTION(blsp3_uart),
	FUNCTION(blsp3_i2c),
	FUNCTION(blsp3_spi),
	FUNCTION(pta2_0),
	FUNCTION(wci21),
	FUNCTION(cxc1),
	FUNCTION(blsp3_spi1),
	FUNCTION(pta2_1),
	FUNCTION(pta2_2),
	FUNCTION(pcie0_clk),
	FUNCTION(dbg_out),
	FUNCTION(cri_trng0),
	FUNCTION(pcie0_rst),
	FUNCTION(cri_trng1),
	FUNCTION(pcie0_wake),
	FUNCTION(cri_trng),
	FUNCTION(pcie1_clk),
	FUNCTION(rx2),
	FUNCTION(ldo_update),
	FUNCTION(pcie1_rst),
	FUNCTION(ldo_en),
	FUNCTION(pcie1_wake),
	FUNCTION(gcc_plltest),
	FUNCTION(sd_card),
	FUNCTION(pwm01),
	FUNCTION(pta1_1),
	FUNCTION(pwm11),
	FUNCTION(rx1),
	FUNCTION(pta1_2),
	FUNCTION(gcc_tlmm),
	FUNCTION(pta1_0),
	FUNCTION(pwm21),
	FUNCTION(prng_rosc),
	FUNCTION(sd_write),
	FUNCTION(pwm31),
	FUNCTION(rx0),
	FUNCTION(tsens_max),
	FUNCTION(mdc),
	FUNCTION(mdio),
};

static const struct msm_pingroup ipq807x_groups[] = {
	PINGROUP(0, qpic_pad, blsp5_uart, blsp5_i2c, blsp5_spi, wci20,
		 blsp3_spi3, NA, burn0, NA),
	PINGROUP(1, qpic_pad, pcm_zsi0, mac12, blsp3_spi0, NA, burn1, NA, NA,
		 NA),
	PINGROUP(2, qpic_pad, blsp5_uart, blsp5_i2c, blsp5_spi, wci20,
		 blsp3_spi3, NA, NA, NA),
	PINGROUP(3, qpic_pad, mac01, blsp3_spi0, qdss_cti_trig_out_b0, NA, NA,
		 NA, NA, NA),
	PINGROUP(4, qpic_pad, mac01, blsp3_spi0, qdss_cti_trig_in_b0, NA, NA,
		 NA, NA, NA),
	PINGROUP(5, qpic_pad4, blsp4_uart0, blsp4_i2c0, blsp4_spi0, mac21,
		 qdss_cti_trig_out_b1, NA, NA, NA),
	PINGROUP(6, qpic_pad5, blsp4_uart0, blsp4_i2c0, blsp4_spi0, mac21,
		 qdss_cti_trig_in_b1, NA, NA, NA),
	PINGROUP(7, qpic_pad6, blsp4_uart0, blsp4_spi0, NA, NA, NA, NA, NA, NA),
	PINGROUP(8, qpic_pad7, blsp4_uart0, blsp4_spi0, NA, NA, NA, NA, NA, NA),
	PINGROUP(9, qpic_pad, blsp5_uart, blsp5_spi, cxc0, mac13, blsp3_spi3,
		 qdss_cti_trig_in_a1, NA, NA),
	PINGROUP(10, qpic_pad, qdss_cti_trig_out_a1, NA, NA, NA, NA, NA, NA,
		 NA),
	PINGROUP(11, qpic_pad, wci22, mac12, qdss_cti_trig_in_a0, NA, NA, NA,
		 NA, NA),
	PINGROUP(12, qpic_pad1, qdss_cti_trig_out_a0, NA, NA, NA, NA, NA, NA,
		 NA),
	PINGROUP(13, qpic_pad2, NA, NA, NA, NA, NA, NA, NA, NA),
	PINGROUP(14, qpic_pad3, qdss_traceclk_b, NA, NA, NA, NA, NA, NA, NA),
	PINGROUP(15, qpic_pad0, qdss_tracectl_b, NA, NA, NA, NA, NA, NA, NA),
	PINGROUP(16, qpic_pad8, blsp5_uart, pcm_zsi1, blsp5_spi, cxc0, mac13,
		 qdss_tracedata_b, NA, NA),
	PINGROUP(17, qpic_pad, wci22, qdss_tracedata_b, NA, NA, NA, NA, NA, NA),
	PINGROUP(18, led0, pwm04, qdss_tracedata_b, NA, NA, NA, NA, NA, NA),
	PINGROUP(19, led1, pwm14, NA, qdss_tracedata_b, NA, NA, NA, NA, NA),
	PINGROUP(20, led2, pwm24, NA, qdss_tracedata_b, NA, NA, NA, NA, NA),
	PINGROUP(21, pwm00, blsp4_uart1, blsp4_i2c1, blsp4_spi1, wci23, mac11,
		 blsp3_spi2, NA, qdss_tracedata_b),
	PINGROUP(22, pwm10, blsp4_uart1, blsp4_i2c1, blsp4_spi1, wci23, mac11,
		 blsp3_spi2, NA, qdss_tracedata_b),
	PINGROUP(23, pwm20, blsp4_uart1, blsp4_spi1, blsp3_spi2, NA,
		 qdss_tracedata_b, NA, NA, NA),
	PINGROUP(24, pwm30, blsp4_uart1, blsp4_spi1, NA, qdss_tracedata_b, NA,
		 NA, NA, NA),
	PINGROUP(25, audio_txmclk, pwm02, NA, qdss_tracedata_b, NA, NA, NA, NA,
		 NA),
	PINGROUP(26, audio_txbclk, pwm12, NA, qdss_tracedata_b, NA, NA, NA, NA,
		 NA),
	PINGROUP(27, audio_txfsync, pwm22, NA, qdss_tracedata_b, NA, NA, NA,
		 NA, NA),
	PINGROUP(28, audio_txd, pwm32, NA, qdss_tracedata_b, NA, NA, NA, NA,
		 NA),
	PINGROUP(29, audio_rxmclk, pwm03, atest_char0, NA, qdss_tracedata_b,
		 NA, NA, NA, NA),
	PINGROUP(30, audio_rxbclk, pwm13, atest_char1, NA, qdss_tracedata_b,
		 NA, NA, NA, NA),
	PINGROUP(31, audio_rxfsync, pwm23, atest_char2, NA, qdss_tracedata_b,
		 NA, NA, NA, NA),
	PINGROUP(32, audio_rxd, pwm33, atest_char3, NA, NA, NA, NA, NA, NA),
	PINGROUP(33, pcm_drx, mac10, mac00, NA, NA, NA, NA, NA, NA),
	PINGROUP(34, pcm_dtx, mac10, mac00, NA, NA, NA, NA, NA, NA),
	PINGROUP(35, pcm_fsync, mac20, qdss_traceclk_a, NA, NA, NA, NA, NA, NA),
	PINGROUP(36, pcm_pclk, mac20, NA, qdss_tracectl_a, NA, NA, NA, NA, NA),
	PINGROUP(37, atest_char, NA, qdss_tracedata_a, NA, NA, NA, NA, NA, NA),
	PINGROUP(38, blsp0_uart, blsp0_i2c, blsp0_spi, NA, qdss_tracedata_a,
		 NA, NA, NA, NA),
	PINGROUP(39, blsp0_uart, blsp0_i2c, blsp0_spi, NA, qdss_tracedata_a,
		 NA, NA, NA, NA),
	PINGROUP(40, blsp0_uart, blsp0_spi, NA, qdss_tracedata_a, NA, NA, NA,
		 NA, NA),
	PINGROUP(41, blsp0_uart, blsp0_spi, NA, qdss_tracedata_a, NA, NA, NA,
		 NA, NA),
	PINGROUP(42, blsp1_uart, blsp1_i2c, blsp1_spi, NA, qdss_tracedata_a,
		 NA, NA, NA, NA),
	PINGROUP(43, blsp1_uart, blsp1_i2c, blsp1_spi, NA, qdss_tracedata_a,
		 NA, NA, NA, NA),
	PINGROUP(44, blsp1_uart, blsp1_spi, NA, qdss_tracedata_a, NA, NA, NA,
		 NA, NA),
	PINGROUP(45, blsp1_uart, blsp1_spi, qdss_tracedata_a, NA, NA, NA, NA,
		 NA, NA),
	PINGROUP(46, blsp2_uart, blsp2_i2c, blsp2_spi, qdss_tracedata_a, NA,
		 NA, NA, NA, NA),
	PINGROUP(47, blsp2_uart, blsp2_i2c, blsp2_spi, NA, qdss_tracedata_a,
		 NA, NA, NA, NA),
	PINGROUP(48, blsp2_uart, blsp2_spi, NA, qdss_tracedata_a, NA, NA, NA,
		 NA, NA),
	PINGROUP(49, blsp2_uart, blsp2_spi, NA, qdss_tracedata_a, NA, NA, NA,
		 NA, NA),
	PINGROUP(50, blsp3_uart, blsp3_i2c, blsp3_spi, NA, qdss_tracedata_a,
		 NA, NA, NA, NA),
	PINGROUP(51, blsp3_uart, blsp3_i2c, blsp3_spi, NA, qdss_tracedata_a,
		 NA, NA, NA, NA),
	PINGROUP(52, blsp3_uart, blsp3_spi, NA, qdss_tracedata_a, NA, NA, NA,
		 NA, NA),
	PINGROUP(53, blsp3_uart, blsp3_spi, NA, NA, NA, NA, NA, NA, NA),
	PINGROUP(54, pta2_0, wci21, cxc1, blsp3_spi1, NA, NA, NA, NA, NA),
	PINGROUP(55, pta2_1, blsp3_spi1, NA, NA, NA, NA, NA, NA, NA),
	PINGROUP(56, pta2_2, wci21, cxc1, blsp3_spi1, NA, NA, NA, NA, NA),
	PINGROUP(57, pcie0_clk, NA, dbg_out, cri_trng0, NA, NA, NA, NA, NA),
	PINGROUP(58, pcie0_rst, NA, cri_trng1, NA, NA, NA, NA, NA, NA),
	PINGROUP(59, pcie0_wake, NA, cri_trng, NA, NA, NA, NA, NA, NA),
	PINGROUP(60, pcie1_clk, rx2, ldo_update, NA, NA, NA, NA, NA, NA),
	PINGROUP(61, pcie1_rst, ldo_en, NA, NA, NA, NA, NA, NA, NA),
	PINGROUP(62, pcie1_wake, gcc_plltest, NA, NA, NA, NA, NA, NA, NA),
	PINGROUP(63, sd_card, pwm01, NA, gcc_plltest, NA, NA, NA, NA, NA),
	PINGROUP(64, pta1_1, pwm11, NA, rx1, NA, NA, NA, NA, NA),
	PINGROUP(65, pta1_2, NA, gcc_tlmm, NA, NA, NA, NA, NA, NA),
	PINGROUP(66, pta1_0, pwm21, prng_rosc, NA, NA, NA, NA, NA, NA),
	PINGROUP(67, sd_write, pwm31, rx0, tsens_max, NA, NA, NA, NA, NA),
	PINGROUP(68, mdc, NA, NA, NA, NA, NA, NA, NA, NA),
	PINGROUP(69, mdio, NA, NA, NA, NA, NA, NA, NA, NA),
};

static const struct msm_pinctrl_soc_data ipq807x_pinctrl = {
	.pins = ipq807x_pins,
	.npins = ARRAY_SIZE(ipq807x_pins),
	.functions = ipq807x_functions,
	.nfunctions = ARRAY_SIZE(ipq807x_functions),
	.groups = ipq807x_groups,
	.ngroups = ARRAY_SIZE(ipq807x_groups),
	.ngpios = 70,
	.gpio_pull = &msm_gpio_pull,
};

static int ipq807x_pinctrl_probe(struct platform_device *pdev)
{
	return msm_pinctrl_probe(pdev, &ipq807x_pinctrl);
}

static const struct of_device_id ipq807x_pinctrl_of_match[] = {
	{ .compatible = "qcom,ipq807x-pinctrl", },
	{ },
};

static struct platform_driver ipq807x_pinctrl_driver = {
	.driver = {
		.name = "ipq807x-pinctrl",
		.owner = THIS_MODULE,
		.of_match_table = ipq807x_pinctrl_of_match,
	},
	.probe = ipq807x_pinctrl_probe,
	.remove = msm_pinctrl_remove,
};

static int __init ipq807x_pinctrl_init(void)
{
	return platform_driver_register(&ipq807x_pinctrl_driver);
}
arch_initcall(ipq807x_pinctrl_init);

static void __exit ipq807x_pinctrl_exit(void)
{
	platform_driver_unregister(&ipq807x_pinctrl_driver);
}
module_exit(ipq807x_pinctrl_exit);

MODULE_DESCRIPTION("Qualcomm ipq807x pinctrl driver");
MODULE_LICENSE("GPL v2");
MODULE_DEVICE_TABLE(of, ipq807x_pinctrl_of_match);
