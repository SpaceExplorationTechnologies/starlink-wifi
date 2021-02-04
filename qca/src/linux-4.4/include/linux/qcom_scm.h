/* Copyright (c) 2010-2018, The Linux Foundation. All rights reserved.
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
 */
#ifndef __QCOM_SCM_H
#define __QCOM_SCM_H

struct qcom_scm_tcsr_req {
	u32 mask;
	u32 status;
	u16 tcsr_reg;
	u16 set;
};

struct log_read {
	uint32_t log_buf;
	uint32_t buf_size;
};

#define TZ_SVC_CRYPTO	10
#define TZ_SYSCALL_CREATE_CMD_ID(s, f) \
	((uint32_t)(((s & 0x3ff) << 10) | (f & 0x3ff)))

struct scm_cmd_buf_t {
	uint32_t req_addr;
	uint32_t req_size;
	uint32_t resp_addr;
	uint32_t resp_size;
};

extern int qcom_scm_tls_hardening(struct scm_cmd_buf_t *scm_cmd_buf,
				 size_t buf_size, u32 cmd_id);

extern int qcom_qfprom_write_version(void *wrip, int size);
int qcom_qfprom_read_version(uint32_t sw_type, uint32_t value,
				uint32_t qfprom_ret_ptr);
extern int qcom_qfprom_show_authenticate(void);
extern int qcom_sec_upgrade_auth(unsigned int sw_type, unsigned int img_size,
					 unsigned int load_addr);
extern bool qcom_scm_sec_auth_available(void);
extern int qcom_scm_set_cold_boot_addr(void *entry, const cpumask_t *cpus);
extern int qcom_scm_set_warm_boot_addr(void *entry, const cpumask_t *cpus);

#define SCM_SVC_INFO                   0x6
#define SCM_GSBI_ADM_MUX_SEL_CMD       0x5
extern int qcom_scm_tcsr(u32 svc_id, u32 cmd_id,
			struct qcom_scm_tcsr_req *tcsr_cmd);

#define QCOM_SCM_HDCP_MAX_REQ_CNT	5

extern bool qcom_scm_is_available(void);

extern bool qcom_scm_hdcp_available(void);

extern bool qcom_scm_pas_supported(u32 peripheral);
extern int qcom_scm_pas_init_image(u32 peripheral, const void *metadata,
		size_t size);
extern int qcom_scm_pas_mem_setup(u32 peripheral, phys_addr_t addr,
		phys_addr_t size);
extern int qcom_scm_pas_auth_and_reset(u32 peripheral);
extern int qcom_scm_pas_shutdown(u32 peripheral);

#define SCM_SVC_UTIL		0x3
#define SCM_CMD_SET_REGSAVE 	0x2

extern int qcom_scm_regsave(u32 svc_id, u32 cmd_id, void *,
						unsigned int size);

#define TZ_INFO_GET_DIAG_ID	0x2
#define SCM_SVC_INFO		0x6
#define HVC_INFO_GET_DIAG_ID	0x7

extern int qcom_scm_tz_log(u32 svc_id, u32 cmd_id, void *ker_buf, u32 buf_len);
extern int qcom_scm_hvc_log(void *ker_buf, u32 buf_len);
extern int qcom_scm_pshold(void);

extern int qcom_config_sec_ice(void *buf, int size);

#define QCOM_SCM_CPU_PWR_DOWN_L2_ON	0x0
#define QCOM_SCM_CPU_PWR_DOWN_L2_OFF	0x1

extern void qcom_scm_cpu_power_down(u32 flags);

#define QCOM_SCM_VERSION(major, minor) (((major) << 16) | ((minor) & 0xFF))

extern u32 qcom_scm_get_version(void);

extern s32 qcom_scm_pinmux_read(u32 arg1);
extern s32 qcom_scm_pinmux_write(u32 arg1, u32 arg2);
extern s32 qcom_scm_usb_mode_write(u32 arg1, u32 arg2);

extern int qcom_scm_cache_dump(u32 cpu);
extern int qcom_scm_get_cache_dump_size(u32 cmd_id, void *cmd_buf, u32 size);
extern int qcom_scm_send_cache_dump_addr(u32 cmd_id, void *cmd_buf, u32 size);
extern int qcom_scm_tzsched(const void *req, size_t req_size,
				void *resp, size_t resp_size);

#define TZ_OWNER_QSEE_OS		50
#define TZ_OWNER_TZ_APPS		48
#define TZ_SVC_APP_MGR			1     /* Application management */
#define TZ_SVC_APP_ID_PLACEHOLDER	0     /* SVC bits will contain App ID */

#define TZ_ARMv8_CMD_NOTIFY_REGION_ID		0x05
#define TZ_ARMv8_CMD_REGISTER_LOG_BUF		0x06
#define TZ_ARMv8_CMD_LOAD_LIB			0x07
#define TZ_ARMv8_CMD_UNLOAD_LIB			0x08
#define TZ_ARMv8_CMD_LOAD_APP_ID		0x01
#define TZ_ARMv8_CMD_SEND_DATA_ID		0x01
#define TZ_ARMv8_CMD_UNLOAD_APP_ID		0x02

#define MAX_APP_NAME_SIZE               32

#define TZ_SYSCALL_CREATE_SMC_ID(o, s, f) \
	((uint32_t)((((o & 0x3f) << 24) | (s & 0xff) << 8) | (f & 0xff)))

enum qseecom_qceos_cmd_id {
	QSEOS_APP_START_COMMAND	= 0x01,
	QSEOS_APP_SHUTDOWN_COMMAND,
	QSEOS_APP_LOOKUP_COMMAND,
	QSEOS_REGISTER_LISTENER,
	QSEOS_DEREGISTER_LISTENER,
	QSEOS_CLIENT_SEND_DATA_COMMAND,
	QSEOS_LISTENER_DATA_RSP_COMMAND,
	QSEOS_LOAD_EXTERNAL_ELF_COMMAND,
	QSEOS_UNLOAD_EXTERNAL_ELF_COMMAND,
	QSEOS_CMD_MAX		= 0xEFFFFFFF,
	QSEE_LOAD_SERV_IMAGE_COMMAND = 0xB,
	QSEE_UNLOAD_SERV_IMAGE_COMMAND = 12,
	QSEE_APP_NOTIFY_COMMAND	= 13,
	QSEE_REGISTER_LOG_BUF_COMMAND = 14
};

__packed struct qseecom_load_lib_ireq {
	uint32_t qsee_cmd_id;
	uint32_t mdt_len;		/* Length of the mdt file */
	uint32_t img_len;		/* Length of .bxx and .mdt files */
	phys_addr_t phy_addr;		/* phy addr of the start of image */
};

__packed struct qseecom_load_app_ireq {
	struct qseecom_load_lib_ireq load_ireq;
	char app_name[MAX_APP_NAME_SIZE];	/* application name*/
};

union qseecom_load_ireq {
	struct qseecom_load_lib_ireq load_lib_req;
	struct qseecom_load_app_ireq load_app_req;
};

struct qsee_notify_app {
	uint32_t cmd_id;
	phys_addr_t applications_region_addr;
	size_t applications_region_size;
};

__packed struct qseecom_client_send_data_v1_ireq {
	uint32_t qsee_cmd_id;
	uint32_t app_id;
	dma_addr_t req_ptr;
	uint32_t req_len;
	/** First 4 bytes should always be the return status */
	dma_addr_t rsp_ptr;
	uint32_t rsp_len;
};

__packed struct qseecom_client_send_data_v2_ireq {
	struct qseecom_client_send_data_v1_ireq send_data_ireq;
	uint64_t sglistinfo_ptr;
	uint32_t sglistinfo_len;
};

union qseecom_client_send_data_ireq {
	struct qseecom_client_send_data_v1_ireq v1;
	struct qseecom_client_send_data_v2_ireq v2;
};

__packed struct qseecom_unload_ireq {
	uint32_t qsee_cmd_id;
	uint32_t app_id;
};

enum qseecom_command_scm_resp_type {
	QSEOS_APP_ID = 0xEE01,
	QSEOS_LISTENER_ID
};

__packed struct qseecom_command_scm_resp {
	unsigned long result;
	enum qseecom_command_scm_resp_type resp_type;
	unsigned long data;
};

struct tzdbg_log_pos_t {
	uint16_t wrap;
	uint16_t offset;
};

struct tzdbg_log_t {
	struct tzdbg_log_pos_t log_pos;
	uint8_t	log_buf[];
};

struct qsee_reg_log_buf_req {
	uint32_t qsee_cmd_id;
	phys_addr_t phy_addr;
	uint64_t len;
};

extern int qcom_scm_qseecom_notify(struct qsee_notify_app *req,
				  size_t req_size,
				  struct qseecom_command_scm_resp *resp,
				  size_t resp_size);

extern int qcom_scm_qseecom_load(uint32_t smc_id, uint32_t cmd_id,
				union qseecom_load_ireq *req, size_t req_size,
				struct qseecom_command_scm_resp *resp,
				size_t resp_size);

extern int qcom_scm_qseecom_send_data(union qseecom_client_send_data_ireq *req,
				     size_t req_size,
				     struct qseecom_command_scm_resp *resp,
				     size_t resp_size);

extern int qcom_scm_qseecom_unload(uint32_t smc_id, uint32_t cmd_id,
				  struct qseecom_unload_ireq *req,
				  size_t req_size,
				  struct qseecom_command_scm_resp *resp,
				  size_t resp_size);

extern int qcom_scm_tz_register_log_buf(struct device *dev,
				       struct qsee_reg_log_buf_req *request,
				       size_t req_size,
				       struct qseecom_command_scm_resp
				       *response, size_t resp_size);

#define QCOM_SCM_SVC_FUSE		0x8

extern int qcom_los_scm_call(struct device *, u32 svc_id, u32 cmd_id,
		void *cmd_buf, size_t size);

#endif
