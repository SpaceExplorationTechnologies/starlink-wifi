/* Copyright (c) 2010-2018, The Linux Foundation. All rights reserved.
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
#ifndef __QCOM_SCM_INT_H
#define __QCOM_SCM_INT_H

#include <linux/qcom_scm.h>
#define QCOM_SCM_SVC_BOOT			0x1
#define SET_MAGIC				0x1
#define CLEAR_MAGIC				0x0
#define SCM_CMD_TZ_CONFIG_HW_FOR_RAM_DUMP_ID	0x9
#define SCM_CMD_TZ_FORCE_DLOAD_ID		0x10
#define SCM_CMD_TZ_SET_DLOAD_FOR_SECURE_BOOT	0x14
#define SCM_CMD_PSHOLD				0x16
#define SCM_SVC_ID_SHIFT			0xA

extern int __qcom_scm_tls_hardening(struct device *dev,
				   struct scm_cmd_buf_t *scm_cmd_buf,
				   size_t buf_size, u32 cmd_id);

#define QCOM_SCM_BOOT_ADDR		0x1
#define QCOM_SCM_BOOT_ADDR_MC		0x11

#define QCOM_SCM_FLAG_HLOS		0x01
#define QCOM_SCM_FLAG_COLDBOOT_MC	0x02
#define QCOM_SCM_FLAG_WARMBOOT_MC	0x04

#define QCOM_SCM_PARAM_BUF_RO		0x1
#define QCOM_SCM_PARAM_VAL		0x0
#define QCOM_SVC_ICE			23
#define QCOM_SCM_ICE_CMD		0x1

extern int __qcom_scm_set_warm_boot_addr(struct device *dev, void *entry,
		const cpumask_t *cpus);
extern int __qcom_qfprom_read_version(struct device *dev, uint32_t sw_type,
			uint32_t value, uint32_t qfprom_ret_ptr);
extern int __qcom_qfprom_show_authenticate(struct device *dev, char *buf);
extern int __qcom_scm_set_cold_boot_addr(void *entry, const cpumask_t *cpus);
extern int __qcom_qfprom_write_version(struct device *dev, void *wrip,
						int size);
extern int __qcom_config_ice_sec(struct device *dev, void *confBuf, int size);

extern int __qcom_sec_upgrade_auth(struct device *dev, unsigned int sw_type,
			unsigned int img_size, unsigned int load_addr);

#define QCOM_SCM_CMD_TERMINATE_PC	0x2
#define QCOM_SCM_FLUSH_FLAG_MASK	0x3
#define QCOM_SCM_CMD_CORE_HOTPLUGGED	0x10
extern void __qcom_scm_cpu_power_down(u32 flags);

#define QCOM_SCM_SVC_INFO		0x6
#define QCOM_IS_CALL_AVAIL_CMD		0x1
extern int __qcom_scm_is_call_available(struct device *dev, u32 svc_id,
		u32 cmd_id);

#define SCM_SIP_FNID(s, c) (((((s) & 0xFF) << 8) | ((c) & 0xFF)) | 0x02000000)
#define QCOM_SMC_ATOMIC_MASK		0x80000000
#define SCM_ARGS_IMPL(num, a, b, c, d, e, f, g, h, i, j, ...) (\
			(((a) & 0xff) << 4) | \
			(((b) & 0xff) << 6) | \
			(((c) & 0xff) << 8) | \
			(((d) & 0xff) << 10) | \
			(((e) & 0xff) << 12) | \
			(((f) & 0xff) << 14) | \
			(((g) & 0xff) << 16) | \
			(((h) & 0xff) << 18) | \
			(((i) & 0xff) << 20) | \
			(((j) & 0xff) << 22) | \
			(num & 0xffff))

#define SCM_ARGS(...) SCM_ARGS_IMPL(__VA_ARGS__, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

#define MAX_SCM_ARGS 10
#define MAX_SCM_RETS 3

enum scm_arg_types {
	SCM_VAL,
	SCM_RO,
	SCM_RW,
	SCM_BUFVAL,
};

/**
 * struct scm_desc
 * @arginfo: Metadata describing the arguments in args[]
 * @args: The array of arguments for the secure syscall
 * @ret: The values returned by the secure syscall
 * @extra_arg_buf: The buffer containing extra arguments
		   (that don't fit in available registers)
 * @x5: The 4rd argument to the secure syscall or physical address of
	extra_arg_buf
 */
struct scm_desc {
	u32 arginfo;
	u64 args[MAX_SCM_ARGS];
	u64 ret[MAX_SCM_RETS];

	/* private */
	void *extra_arg_buf;
	u64 x5;
};

#define QCOM_SCM_SVC_HDCP		0x11
#define QCOM_SCM_CMD_HDCP		0x01
#define QCOM_SCM_SVC_SEC_AUTH		0x01
#define QCOM_SCM_CMD_SEC_AUTH		0x15

extern void __qcom_scm_init(void);

#define QCOM_SCM_SVC_BOOT		0x1
#define QCOM_SCM_SVC_PIL		0x2
#define QCOM_SCM_PAS_INIT_IMAGE_CMD	0x1
#define QCOM_SCM_PAS_MEM_SETUP_CMD	0x2
#define QCOM_SCM_PAS_AUTH_AND_RESET_CMD	0x5
#define QCOM_SCM_PAS_SHUTDOWN_CMD	0x6
#define QCOM_SCM_PAS_IS_SUPPORTED_CMD	0x7
#define QCOM_SCM_SVC_FUSE		0x8
#define QCOM_QFPROM_IS_AUTHENTICATE_CMD	0x7
#define QCOM_QFPROM_ROW_READ_CMD                     0x8
#define QCOM_QFPROM_ROW_WRITE_CMD                    0x9
#define QCOM_SCM_PAS_MSS_RESET		0xa
#define QCOM_KERNEL_AUTH_CMD		0x15
extern bool __qcom_scm_pas_supported(struct device *dev, u32 peripheral);
extern int  __qcom_scm_pas_init_image(struct device *dev, u32 peripheral,
		dma_addr_t metadata_phys);
extern int  __qcom_scm_pas_mem_setup(struct device *dev, u32 peripheral,
		phys_addr_t addr, phys_addr_t size);
extern int  __qcom_scm_pas_auth_and_reset(struct device *dev, u32 peripheral);
extern int  __qcom_scm_pas_shutdown(struct device *dev, u32 peripheral);
extern int  __qcom_scm_pas_mss_reset(struct device *dev, bool reset);

struct qcom_scm_hdcp_req {
	u32 addr;
	u32 val;
};

extern int __qcom_scm_hdcp_req(struct device *dev,
		struct qcom_scm_hdcp_req *req, u32 req_cnt, u32 *resp);

extern int __qcom_scm_regsave(struct device *, u32 svc_id, u32 cmd_id, void *,
					unsigned int buf_size);

extern int __qcom_scm_dload(struct device *, u32 svc_id, u32 cmd_id,
				void *cmd_buf);
extern int qcom_scm_dload(u32 svc_id, u32 cmd_id, void *cmd_buf);
extern int __qcom_scm_tcsr(struct device *, u32 svc_id, u32 cmd_id,
			struct qcom_scm_tcsr_req *tcsr_cmd);

extern int __qcom_scm_sdi(struct device *, u32 svc_id, u32 cmd_id);
extern int qcom_scm_sdi(u32 svc_id, u32 cmd_id);

extern int __qcom_scm_pshold(struct device *);
extern int qcom_scm_pshold(void);


#define SCM_IO_READ	1
#define SCM_IO_WRITE	2
#define SCM_SVC_IO_ACCESS	0x5
#define SCM_CMD_CACHE_BUFFER_DUMP	0x5
#define SCM_SVC_TZSCHEDULER	0xFC
#define SCM_CMD_TZSCHEDULER	0x1

s32 __qcom_scm_pinmux_read(u32 svc_id, u32 cmd_id, u32 arg1);
s32 __qcom_scm_pinmux_write(u32 svc_id, u32 cmd_id, u32 arg1, u32 arg2);
s32 __qcom_scm_usb_mode_write(u32 svc_id, u32 cmd_id, u32 arg1, u32 arg2);

extern int __qcom_scm_cache_dump(u32 cpu);
extern int qcom_scm_cache_dump(u32 cpu);

extern int __qcom_scm_get_cache_dump_size(struct device *, u32 cmd_id,
					void *cmd_buf, u32 size);
extern int __qcom_scm_send_cache_dump_addr(struct device *, u32 cmd_id,
					void *cmd_buf, u32 size);
extern int qcom_scm_get_cache_dump_size(u32 cmd_id, void *cmd_buf, u32 size);
extern int qcom_scm_send_cache_dump_addr(u32 cmd_id, void *cmd_buf, u32 size);

extern int __qcom_scm_qseecom_notify(struct device *,
				    struct qsee_notify_app *req,
				    size_t req_size,
				    struct qseecom_command_scm_resp *resp,
				    size_t resp_size);

extern int __qcom_scm_qseecom_load(struct device *,
				  uint32_t smc_id, uint32_t cmd_id,
				  union qseecom_load_ireq *req,
				  size_t req_size,
				  struct qseecom_command_scm_resp *resp,
				  size_t resp_size);

extern int __qcom_scm_qseecom_send_data(struct device *,
				       union qseecom_client_send_data_ireq *req,
				       size_t req_size,
				       struct qseecom_command_scm_resp *resp,
				       size_t resp_size);

extern int __qcom_scm_qseecom_unload(struct device *,
				    uint32_t smc_id, uint32_t cmd_id,
				    struct qseecom_unload_ireq *req,
				    size_t req_size,
				    struct qseecom_command_scm_resp *resp,
				    size_t resp_size);

extern int __qcom_scm_tz_register_log_buf(struct device *dev,
					 struct qsee_reg_log_buf_req *request,
					 size_t req_size,
					 struct qseecom_command_scm_resp
					 *response, size_t resp_size);

extern int __qcom_scm_tzsched(struct device *, const void *req,
				size_t req_size, void *resp,
				size_t resp_size);

extern int __qcom_scm_tz_log(struct device *dev, u32 svc_id, u32 cmd_id,
				void *ker_buf, u32 buf_len);

extern int __qcom_scm_hvc_log(struct device *dev, u32 svc_id, u32 cmd_id,
				void *ker_buf, u32 buf_len);

extern int __qcom_los_scm_call(struct device *, u32 svc_id, u32 cmd_id,
			void *cmd_buf, size_t size);

#define QCOM_SCM_SVC_REGSAVE		0x3
#define QCOM_SCM_REGSAVE_CMD		0x2

/* common error codes */
#define QCOM_SCM_V2_EBUSY	-12
#define QCOM_SCM_ENOMEM		-5
#define QCOM_SCM_EOPNOTSUPP	-4
#define QCOM_SCM_EINVAL_ADDR	-3
#define QCOM_SCM_EINVAL_ARG	-2
#define QCOM_SCM_ERROR		-1
#define QCOM_SCM_INTERRUPTED	1

#define QCOM_SCM_EBUSY_WAIT_MS 30
#define QCOM_SCM_EBUSY_MAX_RETRY 20

static inline int qcom_scm_remap_error(long err)
{
	switch (err) {
	case QCOM_SCM_ERROR:
		return -EIO;
	case QCOM_SCM_EINVAL_ADDR:
	case QCOM_SCM_EINVAL_ARG:
		return -EINVAL;
	case QCOM_SCM_EOPNOTSUPP:
		return -EOPNOTSUPP;
	case QCOM_SCM_ENOMEM:
		return -ENOMEM;
	case QCOM_SCM_V2_EBUSY:
		return -EBUSY;
	}
	return -EINVAL;
}

#endif
