/*
 * Qualcomm SCM driver
 *
 * Copyright (c) 2010, 2015-2018, The Linux Foundation. All rights reserved.
 * Copyright (C) 2015 Linaro Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#include <linux/platform_device.h>
#include <linux/init.h>
#include <linux/cpumask.h>
#include <linux/export.h>
#include <linux/dma-mapping.h>
#include <linux/types.h>
#include <linux/qcom_scm.h>
#include <linux/of.h>
#include <linux/of_platform.h>
#include <linux/clk.h>
#include <linux/reset-controller.h>

#include "qcom_scm.h"

#define SCM_NOCLK 1

struct qcom_scm {
	struct device *dev;
	struct clk *core_clk;
	struct clk *iface_clk;
	struct clk *bus_clk;
	struct reset_controller_dev reset;
	int is_clkdisabled;
};

static struct qcom_scm *__scm;

static int qcom_scm_clk_enable(void)
{
	int ret;

	if (__scm->is_clkdisabled)
		return 0;

	ret = clk_prepare_enable(__scm->core_clk);
	if (ret)
		goto bail;

	ret = clk_prepare_enable(__scm->iface_clk);
	if (ret)
		goto disable_core;

	ret = clk_prepare_enable(__scm->bus_clk);
	if (ret)
		goto disable_iface;

	return 0;

disable_iface:
	clk_disable_unprepare(__scm->iface_clk);
disable_core:
	clk_disable_unprepare(__scm->core_clk);
bail:
	return ret;
}

static void qcom_scm_clk_disable(void)
{
	if (__scm->is_clkdisabled)
		return;

	clk_disable_unprepare(__scm->core_clk);
	clk_disable_unprepare(__scm->iface_clk);
	clk_disable_unprepare(__scm->bus_clk);
}

int qcom_scm_qseecom_notify(struct qsee_notify_app *req, size_t req_size,
			   struct qseecom_command_scm_resp *resp,
			   size_t resp_size)
{
	int ret = 0;

	ret = __qcom_scm_qseecom_notify(__scm->dev, req, req_size,
				       resp, resp_size);

	return ret;
}
EXPORT_SYMBOL(qcom_scm_qseecom_notify);

int qcom_scm_qseecom_load(uint32_t smc_id, uint32_t cmd_id,
			 union qseecom_load_ireq *req, size_t req_size,
			 struct qseecom_command_scm_resp *resp,
			 size_t resp_size)
{
	int ret = 0;

	ret = __qcom_scm_qseecom_load(__scm->dev, smc_id, cmd_id, req, req_size,
				     resp, resp_size);

	return ret;
}
EXPORT_SYMBOL(qcom_scm_qseecom_load);

int qcom_scm_qseecom_send_data(union qseecom_client_send_data_ireq *req,
			      size_t req_size,
			      struct qseecom_command_scm_resp *resp,
			      size_t resp_size)
{
	int ret = 0;

	ret = __qcom_scm_qseecom_send_data(__scm->dev, req, req_size,
					  resp, resp_size);

	return ret;
}
EXPORT_SYMBOL(qcom_scm_qseecom_send_data);

int qcom_scm_qseecom_unload(uint32_t smc_id, uint32_t cmd_id,
			   struct qseecom_unload_ireq *req,
			   size_t req_size,
			   struct qseecom_command_scm_resp *resp,
			   size_t resp_size)
{
	int ret = 0;

	ret = __qcom_scm_qseecom_unload(__scm->dev, smc_id, cmd_id, req,
				       req_size, resp, resp_size);

	return ret;
}
EXPORT_SYMBOL(qcom_scm_qseecom_unload);


int qcom_scm_tz_register_log_buf(struct device *dev,
				struct qsee_reg_log_buf_req *request,
				size_t req_size,
				struct qseecom_command_scm_resp *response,
				size_t resp_size)
{
	int ret = 0;

	ret = __qcom_scm_tz_register_log_buf(__scm->dev, request, req_size,
					     response, resp_size);

	return ret;
}
EXPORT_SYMBOL(qcom_scm_tz_register_log_buf);

int qcom_scm_tls_hardening(struct scm_cmd_buf_t *scm_cmd_buf, size_t buf_size,
			  u32 cmd_id)
{
	int ret = 0;

	ret = __qcom_scm_tls_hardening(__scm->dev, scm_cmd_buf,
				      buf_size, cmd_id);

	return ret;
}
EXPORT_SYMBOL(qcom_scm_tls_hardening);

/**
 * qcom_qfprom_show_authenticate() - Check secure boot fuse is enabled
 */
int qcom_qfprom_show_authenticate(void)
{
	int ret;
	char buf;

	ret = __qcom_qfprom_show_authenticate(__scm->dev, &buf);

	if (ret) {
		pr_err("%s: Error in QFPROM read : %d\n", __func__, ret);
		return -1;
	}

	return buf == 1 ? 1 : 0;
}
EXPORT_SYMBOL(qcom_qfprom_show_authenticate);

/*
 * qcom_config_sec_ice() - Configure ICE block securely
 */
int qcom_config_sec_ice(void *buf, int size)
{
	return __qcom_config_ice_sec(__scm->dev, buf, size);
}
EXPORT_SYMBOL(qcom_config_sec_ice);

int qcom_qfprom_write_version(void *wrip, int size)
{
	return __qcom_qfprom_write_version(__scm->dev, wrip, size);
}

int qcom_qfprom_read_version(uint32_t sw_type,
			uint32_t value, uint32_t qfprom_ret_ptr)
{
	return __qcom_qfprom_read_version(__scm->dev, sw_type, value,
						qfprom_ret_ptr);
}

/**
 * qcom_scm_set_cold_boot_addr() - Set the cold boot address for cpus
 * @entry: Entry point function for the cpus
 * @cpus: The cpumask of cpus that will use the entry point
 *
 * Set the cold boot address of the cpus. Any cpu outside the supported
 * range would be removed from the cpu present mask.
 */
int qcom_scm_set_cold_boot_addr(void *entry, const cpumask_t *cpus)
{
	return __qcom_scm_set_cold_boot_addr(entry, cpus);
}
EXPORT_SYMBOL(qcom_scm_set_cold_boot_addr);

/**
 * qcom_scm_set_warm_boot_addr() - Set the warm boot address for cpus
 * @entry: Entry point function for the cpus
 * @cpus: The cpumask of cpus that will use the entry point
 *
 * Set the Linux entry point for the SCM to transfer control to when coming
 * out of a power down. CPU power down may be executed on cpuidle or hotplug.
 */
int qcom_scm_set_warm_boot_addr(void *entry, const cpumask_t *cpus)
{
	return __qcom_scm_set_warm_boot_addr(__scm->dev, entry, cpus);
}
EXPORT_SYMBOL(qcom_scm_set_warm_boot_addr);

/**
 * qcom_scm_cpu_power_down() - Power down the cpu
 * @flags - Flags to flush cache
 *
 * This is an end point to power down cpu. If there was a pending interrupt,
 * the control would return from this function, otherwise, the cpu jumps to the
 * warm boot entry point set for this cpu upon reset.
 */
void qcom_scm_cpu_power_down(u32 flags)
{
	__qcom_scm_cpu_power_down(flags);
}
EXPORT_SYMBOL(qcom_scm_cpu_power_down);

/**
 * qcom_scm_hdcp_available() - Check if secure environment supports HDCP.
 *
 * Return true if HDCP is supported, false if not.
 */
bool qcom_scm_hdcp_available(void)
{
	int ret = qcom_scm_clk_enable();

	if (ret)
		return ret;

	ret = __qcom_scm_is_call_available(__scm->dev, QCOM_SCM_SVC_HDCP,
						QCOM_SCM_CMD_HDCP);

	qcom_scm_clk_disable();

	return ret > 0 ? true : false;
}
EXPORT_SYMBOL(qcom_scm_hdcp_available);

/**
 * qcom_scm_hdcp_req() - Send HDCP request.
 * @req: HDCP request array
 * @req_cnt: HDCP request array count
 * @resp: response buffer passed to SCM
 *
 * Write HDCP register(s) through SCM.
 */
int qcom_scm_hdcp_req(struct qcom_scm_hdcp_req *req, u32 req_cnt, u32 *resp)
{
	int ret = qcom_scm_clk_enable();

	if (ret)
		return ret;

	ret = __qcom_scm_hdcp_req(__scm->dev, req, req_cnt, resp);
	qcom_scm_clk_disable();
	return ret;
}
EXPORT_SYMBOL(qcom_scm_hdcp_req);

int qcom_scm_regsave(u32 svc_id, u32 cmd_id, void *scm_regsave,
						unsigned int buf_size)
{
	int ret = qcom_scm_clk_enable();

	if (ret)
		return ret;
	ret = __qcom_scm_regsave(__scm->dev, svc_id, cmd_id,
						scm_regsave, buf_size);
	qcom_scm_clk_disable();
	return ret;

}
EXPORT_SYMBOL(qcom_scm_regsave);

int qcom_sec_upgrade_auth(unsigned int sw_type, unsigned int img_size,
				 unsigned int load_addr)
{
	return __qcom_sec_upgrade_auth(__scm->dev, sw_type,
						img_size, load_addr);
}
EXPORT_SYMBOL(qcom_sec_upgrade_auth);

/**
 * qcom_scm_sec_auth_available() - Check if SEC_AUTH is supported.
 *
 * Return true if SEC_AUTH is supported, false if not.
 */
bool qcom_scm_sec_auth_available(void)
{
	int ret;

	ret = __qcom_scm_is_call_available(__scm->dev, QCOM_SCM_SVC_SEC_AUTH,
						QCOM_SCM_CMD_SEC_AUTH);

	return ret > 0 ? true : false;
}
EXPORT_SYMBOL(qcom_scm_sec_auth_available);

/**
 * qcom_scm_pas_supported() - Check if the peripheral authentication service is
 *			      available for the given peripherial
 * @peripheral:	peripheral id
 *
 * Returns true if PAS is supported for this peripheral, otherwise false.
 */
bool qcom_scm_pas_supported(u32 peripheral)
{
	int ret;

	ret = __qcom_scm_is_call_available(__scm->dev, QCOM_SCM_SVC_PIL,
					   QCOM_SCM_PAS_IS_SUPPORTED_CMD);
	if (ret <= 0)
		return false;

	return __qcom_scm_pas_supported(__scm->dev, peripheral);
}
EXPORT_SYMBOL(qcom_scm_pas_supported);

/**
 * qcom_scm_pas_init_image() - Initialize peripheral authentication service
 *			       state machine for a given peripheral, using the
 *			       metadata
 * @peripheral: peripheral id
 * @metadata:	pointer to memory containing ELF header, program header table
 *		and optional blob of data used for authenticating the metadata
 *		and the rest of the firmware
 * @size:	size of the metadata
 *
 * Returns 0 on success.
 */
int qcom_scm_pas_init_image(u32 peripheral, const void *metadata, size_t size)
{
	dma_addr_t mdata_phys;
	void *mdata_buf;
	int ret;

	/*
	 * During the scm call memory protection will be enabled for the meta
	 * data blob, so make sure it's physically contiguous, 4K aligned and
	 * non-cachable to avoid XPU violations.
	 */
	mdata_buf = dma_alloc_coherent(__scm->dev, size, &mdata_phys,
				       GFP_KERNEL);
	if (!mdata_buf) {
		dev_err(__scm->dev, "Allocation of metadata buffer failed.\n");
		return -ENOMEM;
	}
	memcpy(mdata_buf, metadata, size);

	ret = qcom_scm_clk_enable();
	if (ret)
		goto free_metadata;

	ret = __qcom_scm_pas_init_image(__scm->dev, peripheral, mdata_phys);

	qcom_scm_clk_disable();

free_metadata:
	dma_free_coherent(__scm->dev, size, mdata_buf, mdata_phys);

	return ret;
}
EXPORT_SYMBOL(qcom_scm_pas_init_image);

/**
 * qcom_scm_pas_mem_setup() - Prepare the memory related to a given peripheral
 *			      for firmware loading
 * @peripheral:	peripheral id
 * @addr:	start address of memory area to prepare
 * @size:	size of the memory area to prepare
 *
 * Returns 0 on success.
 */
int qcom_scm_pas_mem_setup(u32 peripheral, phys_addr_t addr, phys_addr_t size)
{
	int ret;

	ret = qcom_scm_clk_enable();
	if (ret)
		return ret;

	ret = __qcom_scm_pas_mem_setup(__scm->dev, peripheral, addr, size);
	qcom_scm_clk_disable();

	return ret;
}
EXPORT_SYMBOL(qcom_scm_pas_mem_setup);

/**
 * qcom_scm_pas_auth_and_reset() - Authenticate the given peripheral firmware
 *				   and reset the remote processor
 * @peripheral:	peripheral id
 *
 * Return 0 on success.
 */
int qcom_scm_pas_auth_and_reset(u32 peripheral)
{
	int ret;

	ret = qcom_scm_clk_enable();
	if (ret)
		return ret;

	ret = __qcom_scm_pas_auth_and_reset(__scm->dev, peripheral);
	qcom_scm_clk_disable();

	return ret;
}
EXPORT_SYMBOL(qcom_scm_pas_auth_and_reset);

/**
 * qcom_scm_pas_shutdown() - Shut down the remote processor
 * @peripheral: peripheral id
 *
 * Returns 0 on success.
 */
int qcom_scm_pas_shutdown(u32 peripheral)
{
	int ret;

	ret = qcom_scm_clk_enable();
	if (ret)
		return ret;

	ret = __qcom_scm_pas_shutdown(__scm->dev, peripheral);
	qcom_scm_clk_disable();

	return ret;
}
EXPORT_SYMBOL(qcom_scm_pas_shutdown);

static int qcom_scm_pas_reset_assert(struct reset_controller_dev *rcdev,
				     unsigned long idx)
{
	if (idx != 0)
		return -EINVAL;

	return __qcom_scm_pas_mss_reset(__scm->dev, 1);
}

static int qcom_scm_pas_reset_deassert(struct reset_controller_dev *rcdev,
				       unsigned long idx)
{
	if (idx != 0)
		return -EINVAL;

	return __qcom_scm_pas_mss_reset(__scm->dev, 0);
}

static const struct reset_control_ops qcom_scm_pas_reset_ops = {
	.assert = qcom_scm_pas_reset_assert,
	.deassert = qcom_scm_pas_reset_deassert,
};

/**
 * qcom_scm_is_available() - Checks if SCM is available
 */
bool qcom_scm_is_available(void)
{
	return !!__scm;
}
EXPORT_SYMBOL(qcom_scm_is_available);

static const struct of_device_id qcom_scm_dt_match[] = {
	{ .compatible = "qcom,scm-apq8064",},
	{ .compatible = "qcom,scm-msm8660",},
	{ .compatible = "qcom,scm-msm8960",},
	{ .compatible = "qcom,scm-ipq807x", .data = (void *)SCM_NOCLK },
	{ .compatible = "qcom,scm-ipq806x", .data = (void *)SCM_NOCLK },
	{ .compatible = "qcom,scm-ipq40xx", .data = (void *)SCM_NOCLK },
	{ .compatible = "qcom,scm-msm8960",},
	{ .compatible = "qcom,scm-msm8960",},
	{ .compatible = "qcom,scm",},
	{}
};

static int qcom_scm_probe(struct platform_device *pdev)
{
	struct qcom_scm *scm;
	const struct of_device_id *id;
	int ret;

	scm = devm_kzalloc(&pdev->dev, sizeof(*scm), GFP_KERNEL);
	if (!scm)
		return -ENOMEM;

	id = of_match_device(qcom_scm_dt_match, &pdev->dev);
	if (id)
		scm->is_clkdisabled = (unsigned int)id->data;
	else
		scm->is_clkdisabled = 0;

	if (!(scm->is_clkdisabled)) {

		scm->core_clk = devm_clk_get(&pdev->dev, "core");
		if (IS_ERR(scm->core_clk)) {
			if (PTR_ERR(scm->core_clk) == -EPROBE_DEFER)
				return PTR_ERR(scm->core_clk);

			scm->core_clk = NULL;
		}

		if (of_device_is_compatible(pdev->dev.of_node, "qcom,scm")) {
			scm->iface_clk = devm_clk_get(&pdev->dev, "iface");
			if (IS_ERR(scm->iface_clk)) {
				if (PTR_ERR(scm->iface_clk) != -EPROBE_DEFER)
					dev_err(&pdev->dev, "failed to acquire iface clk\n");
				return PTR_ERR(scm->iface_clk);
			}

			scm->bus_clk = devm_clk_get(&pdev->dev, "bus");
			if (IS_ERR(scm->bus_clk)) {
				if (PTR_ERR(scm->bus_clk) != -EPROBE_DEFER)
					dev_err(&pdev->dev, "failed to acquire bus clk\n");
				return PTR_ERR(scm->bus_clk);
			}
		}

	}

	scm->reset.ops = &qcom_scm_pas_reset_ops;
	scm->reset.nr_resets = 1;
	scm->reset.of_node = pdev->dev.of_node;
	reset_controller_register(&scm->reset);

	if (!(scm->is_clkdisabled)) {
		/* vote for max clk rate for highest performance */
		ret = clk_set_rate(scm->core_clk, INT_MAX);
		if (ret)
			return ret;
	}

	__qcom_scm_init();

	scm->dev = &pdev->dev;
	__scm = scm;

	return 0;
}

static struct platform_driver qcom_scm_driver = {
	.driver = {
		.name	= "qcom_scm",
		.of_match_table = qcom_scm_dt_match,
	},
	.probe = qcom_scm_probe,
};

static int __init qcom_scm_init(void)
{
	struct device_node *np, *fw_np;
	int ret;

	fw_np = of_find_node_by_name(NULL, "firmware");

	if (!fw_np)
		return -ENODEV;

	np = of_find_matching_node(fw_np, qcom_scm_dt_match);

	if (!np) {
		of_node_put(fw_np);
		return -ENODEV;
	}

	of_node_put(np);

	ret = of_platform_populate(fw_np, qcom_scm_dt_match, NULL, NULL);

	of_node_put(fw_np);

	if (ret)
		return ret;

	return platform_driver_register(&qcom_scm_driver);
}
subsys_initcall(qcom_scm_init);

int qcom_scm_tcsr(u32 svc_id, u32 cmd_id, struct qcom_scm_tcsr_req *tcsr_cmd)
{
	int ret;

	ret = qcom_scm_clk_enable();
	if (ret)
		return ret;

	ret = __qcom_scm_tcsr(__scm->dev, svc_id, cmd_id, tcsr_cmd);

	qcom_scm_clk_disable();

	return ret;
}
EXPORT_SYMBOL(qcom_scm_tcsr);

int qcom_scm_dload(u32 svc_id, u32 cmd_id, void *cmd_buf)
{
	int ret;

	ret = qcom_scm_clk_enable();
	if (ret)
		return ret;

	ret = __qcom_scm_dload(__scm->dev, svc_id, cmd_id, cmd_buf);

	qcom_scm_clk_disable();

	return ret;

}
EXPORT_SYMBOL(qcom_scm_dload);

int qcom_scm_pshold(void)
{
	int ret;

	ret = qcom_scm_clk_enable();
	if (ret)
		return ret;
	ret = __qcom_scm_pshold(__scm->dev);

	qcom_scm_clk_disable();

	return ret;
}

EXPORT_SYMBOL(qcom_scm_pshold);

int qcom_scm_sdi(u32 svc_id, u32 cmd_id)
{
	int ret;

	ret = qcom_scm_clk_enable();
	if (ret)
		return ret;
	ret = __qcom_scm_sdi(__scm->dev, svc_id, cmd_id);

	qcom_scm_clk_disable();

	return ret;
}
EXPORT_SYMBOL(qcom_scm_sdi);

int qcom_scm_tzsched(const void *req, size_t req_size,
				void *resp, size_t resp_size)
{	int ret;

	ret = qcom_scm_clk_enable();
	if (ret)
		return ret;

	ret = __qcom_scm_tzsched(__scm->dev, req, req_size,
				resp, resp_size);

	qcom_scm_clk_disable();

	return ret;
}
EXPORT_SYMBOL(qcom_scm_tzsched);

int qcom_scm_pinmux_read(u32 arg1)
{
	return __qcom_scm_pinmux_read(SCM_SVC_IO_ACCESS, SCM_IO_READ, arg1);
}
EXPORT_SYMBOL(qcom_scm_pinmux_read);

int qcom_scm_pinmux_write(u32 arg1, u32 arg2)
{
	return __qcom_scm_pinmux_write(SCM_SVC_IO_ACCESS, SCM_IO_WRITE,
					arg1, arg2);
}
EXPORT_SYMBOL(qcom_scm_pinmux_write);

int qcom_scm_usb_mode_write(u32 arg1, u32 arg2)
{
	return __qcom_scm_usb_mode_write(SCM_SVC_IO_ACCESS, SCM_IO_WRITE,
					arg1, arg2);
}
EXPORT_SYMBOL(qcom_scm_usb_mode_write);

int qcom_scm_cache_dump(u32 cpu)
{
	return __qcom_scm_cache_dump(cpu);
}
EXPORT_SYMBOL(qcom_scm_cache_dump);

int qcom_scm_get_cache_dump_size(u32 cmd_id, void *cmd_buf, u32 size)
{
	return __qcom_scm_get_cache_dump_size(__scm->dev, cmd_id,
					cmd_buf, size);
}
EXPORT_SYMBOL(qcom_scm_get_cache_dump_size);

int qcom_scm_send_cache_dump_addr(u32 cmd_id, void *cmd_buf, u32 size)
{
	return __qcom_scm_send_cache_dump_addr(__scm->dev, cmd_id,
					cmd_buf, size);
}
EXPORT_SYMBOL(qcom_scm_send_cache_dump_addr);

int qcom_scm_tz_log(u32 svc_id, u32 cmd_id, void *ker_buf, u32 buf_len)
{
	return __qcom_scm_tz_log(__scm->dev, SCM_SVC_INFO, TZ_INFO_GET_DIAG_ID,
					ker_buf, buf_len);
}
EXPORT_SYMBOL(qcom_scm_tz_log);

int qcom_scm_hvc_log(void *ker_buf, u32 buf_len)
{
	return __qcom_scm_hvc_log(__scm->dev, SCM_SVC_INFO,
			HVC_INFO_GET_DIAG_ID, ker_buf, buf_len);
}
EXPORT_SYMBOL(qcom_scm_hvc_log);


int qcom_los_scm_call(struct device *dev, u32 svc_id, u32 cmd_id,
				void *cmd_buf, size_t size)
{
	return __qcom_los_scm_call(dev, svc_id, cmd_id,
				cmd_buf, size);
}
EXPORT_SYMBOL(qcom_los_scm_call);
