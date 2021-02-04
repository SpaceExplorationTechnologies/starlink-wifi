/* Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
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
 *
 */

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/pwm.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/clk.h>
#include <linux/err.h>
#include <linux/io.h>

#include "ipq-adss.h"

#define SRC_FREQ		(200*1000*1000)
#define MAX_PWM_DEVICES		4

/* The default period and duty cycle values to be configured. */
#define DEFAULT_PERIOD_NS	10
#define DEFAULT_DUTY_CYCLE_NS	5

/* The frequency range supported is 762Hz to 100MHz. */
#define MIN_PERIOD_NS		10
#define MAX_PERIOD_NS		1312335

/* The max value specified for each field is based on the number of bits
 * in the pwm control regitser for that filed
 */
#define MAX_PRE_DIV		0xFF
#define MAX_PWM_DIV		0x3FF
#define MAX_HI_DUR		0x7FF

/* Enable bit is set to enable output toggling in pwm device.
 * Update bit is set to reflect the changed divider and high duration
 * values in register. Update bit is auto cleared after the update
 */
#define PWM_ENABLE		0x80000000
#define PWM_UPDATE		0x40000000

#define PWM_CTRL_PRE_DIV_SHIFT	22
#define PWM_CTRL_DIV_SHIFT	0
#define PWM_CTRL_HI_SHIFT	10

struct ipq4019_pwm_chip {
	struct pwm_chip chip;
	struct clk *clk;
};

static ssize_t count;
static uint32_t used_pwm[MAX_PWM_DEVICES];

static const uint32_t pwm_ctrl_register[] = {
	ADSS_GLB_PWM0_CTRL_REG,
	ADSS_GLB_PWM1_CTRL_REG,
	ADSS_GLB_PWM2_CTRL_REG,
	ADSS_GLB_PWM3_CTRL_REG,
};

static struct ipq4019_pwm_chip *to_ipq4019_pwm_chip(struct pwm_chip *chip)
{
	return container_of(chip, struct ipq4019_pwm_chip, chip);
}

static void config_div_and_duty(struct pwm_device *pwm, int pre_div,
				int pwm_div, int period_ns, int duty_ns)
{
	unsigned long hi_dur;
	unsigned long ctrl_reg_val = 0;

	/* high duration = pwm duty * ( pwm div + 1)
	 * pwm duty = duty_ns / period_ns
	 */
	hi_dur = ((pwm_div + 1) * duty_ns) / period_ns;

	ctrl_reg_val |= ((pre_div & MAX_PRE_DIV) << PWM_CTRL_PRE_DIV_SHIFT);
	ctrl_reg_val |= ((hi_dur & MAX_HI_DUR) << PWM_CTRL_HI_SHIFT);
	ctrl_reg_val |= ((pwm_div & MAX_PWM_DIV) << PWM_CTRL_DIV_SHIFT);
	ipq_audio_adss_writel(ctrl_reg_val, pwm_ctrl_register[pwm->hwpwm]);
}

static int ipq4019_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	unsigned long ctrl_reg_val;

	ctrl_reg_val = ipq_audio_adss_readl(pwm_ctrl_register[pwm->hwpwm]);
	ctrl_reg_val |= (PWM_ENABLE | PWM_UPDATE);
	ipq_audio_adss_writel(ctrl_reg_val, pwm_ctrl_register[pwm->hwpwm]);

	return 0;
}

static void ipq4019_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	unsigned long ctrl_reg_val;

	ctrl_reg_val = ipq_audio_adss_readl(pwm_ctrl_register[pwm->hwpwm]);
	ctrl_reg_val &= ~PWM_ENABLE;
	ipq_audio_adss_writel(ctrl_reg_val, pwm_ctrl_register[pwm->hwpwm]);
}

static int ipq4019_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
						int duty_ns, int period_ns)
{
	struct ipq4019_pwm_chip *ipq4019_chip = to_ipq4019_pwm_chip(chip);
	unsigned long freq;
	int pre_div, close_pre_div, close_pwm_div;
	int pwm_div = MAX_PWM_DIV;
	long diff;
	unsigned long rate = clk_get_rate(ipq4019_chip->clk);
	unsigned long min_diff = rate;

	/* freq in Hz for period in nano second*/
	freq = NSEC_PER_SEC / period_ns;

	if (period_ns > MAX_PERIOD_NS || period_ns < MIN_PERIOD_NS) {
		pr_err("PWM Frequency range supported is 762Hz to 100MHz\n"
			"Switching to default configuration values\n");
		period_ns = DEFAULT_PERIOD_NS;
		duty_ns = DEFAULT_DUTY_CYCLE_NS;
		pwm->period = period_ns;
		pwm->duty_cycle = duty_ns;
	}

	ipq4019_pwm_disable(chip, pwm);

	do {
		pre_div = 0;
		while (pre_div <= MAX_PRE_DIV) {
			diff = rate - (freq * (pre_div + 1) * (pwm_div + 1));
			if (diff < 0)
				diff = -diff;
			if (!diff) {
				close_pre_div = pre_div;
				close_pwm_div = pwm_div;
				break;
			}
			if (diff < min_diff) {
				min_diff = diff;
				close_pre_div = pre_div;
				close_pwm_div = pwm_div;
			}
			pre_div++;
		}
		pwm_div--;
	} while (pwm_div >= 0 && diff);

	/* config divider values for the closest possible frequency */
	config_div_and_duty(pwm, close_pre_div, close_pwm_div,
					period_ns, duty_ns);
	ipq4019_pwm_enable(chip, pwm);

	return 0;
}

static int ipq4019_pwm_request(struct pwm_chip *chip, struct pwm_device *pwm)
{
	if (!used_pwm[pwm->hwpwm])
		return -EINVAL;

	pwm->period = DEFAULT_PERIOD_NS;
	pwm->duty_cycle = DEFAULT_DUTY_CYCLE_NS;

	ipq4019_pwm_config(chip, pwm, pwm->duty_cycle, pwm->period);

	return 0;
}

static void ipq4019_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
	ipq4019_pwm_disable(chip, pwm);
}


static struct pwm_ops ipq4019_pwm_ops = {
	.request = ipq4019_pwm_request,
	.free = ipq4019_pwm_free,
	.config = ipq4019_pwm_config,
	.enable = ipq4019_pwm_enable,
	.disable = ipq4019_pwm_disable,
	.owner = THIS_MODULE,
};

static int ipq4019_pwm_probe(struct platform_device *pdev)
{
	struct ipq4019_pwm_chip *pwm;
	struct device *dev;
	unsigned int base_index;
	int ret;

	dev = &pdev->dev;
	pwm = devm_kzalloc(dev, sizeof(*pwm), GFP_KERNEL);
	if (!pwm) {
		dev_err(dev, "failed to allocate memory\n");
		return -ENOMEM;
	}

	platform_set_drvdata(pdev, pwm);

	pwm->clk = devm_clk_get(dev, "core");
	if (!IS_ERR(pwm->clk)) {
		ret = clk_set_rate(pwm->clk, SRC_FREQ);
		if (ret)
			return ret;
		ret = clk_prepare_enable(pwm->clk);
		if (ret)
			return ret;
	}

	if (of_property_read_u32(dev->of_node, "pwm-base-index", &base_index))
		base_index = 0;

	count = of_property_count_u32_elems(dev->of_node, "used-pwm-indices");

	if (of_property_read_u32_array(dev->of_node, "used-pwm-indices",
			used_pwm, count))
		return -EINVAL;

	pwm->chip.dev = dev;
	pwm->chip.ops = &ipq4019_pwm_ops;
	pwm->chip.base = base_index;
	pwm->chip.npwm = count;

	ret = pwmchip_add(&pwm->chip);
	if (ret < 0) {
		dev_err(dev, "pwmchip_add() failed: %d\n", ret);
		return ret;
	}

	return 0;
}

static int ipq4019_pwm_remove(struct platform_device *pdev)
{
	struct ipq4019_pwm_chip *pwm = platform_get_drvdata(pdev);

	return pwmchip_remove(&pwm->chip);
}

static const struct of_device_id pwm_msm_dt_match[] = {
	{
		.compatible = "qca,ipq4019-pwm",
	},
	{}
};

static struct platform_driver ipq4019_pwm_driver = {
	.driver = {
		.name = "qca,ipq4019-pwm",
		.owner = THIS_MODULE,
		.of_match_table = pwm_msm_dt_match,
	},
	.probe = ipq4019_pwm_probe,
	.remove = ipq4019_pwm_remove,
};

module_platform_driver(ipq4019_pwm_driver);

MODULE_LICENSE("Dual BSD/GPL");
