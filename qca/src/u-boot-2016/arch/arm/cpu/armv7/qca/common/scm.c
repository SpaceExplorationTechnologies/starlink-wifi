/*
 * Copyright (c) 2015-2017 The Linux Foundation. All rights reserved.

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
*/

#include <ubi_uboot.h>
#include <linux/stddef.h>
#include <linux/compat.h>
#include <asm-generic/errno.h>
#include <asm/io.h>
#include <asm/arch-qca-common/scm.h>
#include <common.h>

/**
 * alloc_scm_command() - Allocate an SCM command
 * @cmd_size: size of the command buffer
 * @resp_size: size of the response buffer
 *
 * Allocate an SCM command, including enough room for the command
 * and response headers as well as the command and response buffers.
 *
 * Returns a valid &scm_command on success or %NULL if the allocation fails.
 */
static struct scm_command *alloc_scm_command(size_t cmd_size, size_t resp_size)
{
	struct scm_command *cmd;
	size_t len;

	len = sizeof(*cmd) + sizeof(struct scm_response) + cmd_size;
	if (cmd_size > len)
		return NULL;

	len += resp_size;
	if (resp_size > len)
		return NULL;

	cmd = kzalloc(PAGE_ALIGN(len), GFP_KERNEL);
	if (cmd) {
		cmd->len = len;
		cmd->buf_offset = offsetof(struct scm_command, buf);
		cmd->resp_hdr_offset = cmd->buf_offset + cmd_size;
	}
	return cmd;
}

/**
 * free_scm_command() - Free an SCM command
 * @cmd: command to free
 *
 * Free an SCM command.
 */
static inline void free_scm_command(struct scm_command *cmd)
{
	kfree(cmd);
}

/**
 * scm_command_to_response() - Get a pointer to a scm_response
 * @cmd: command
 *
 * Returns a pointer to a response for a command.
 */
static inline struct scm_response *scm_command_to_response(
		const struct scm_command *cmd)
{
	return (void *)cmd + cmd->resp_hdr_offset;
}

/**
 * scm_get_command_buffer() - Get a pointer to a command buffer
 * @cmd: command
 *
 * Returns a pointer to the command buffer of a command.
 */
static inline void *scm_get_command_buffer(const struct scm_command *cmd)
{
	return (void *)cmd->buf;
}

/**
 * scm_get_response_buffer() - Get a pointer to a response buffer
 * @rsp: response
 *
 * Returns a pointer to a response buffer of a response.
 */
static inline void *scm_get_response_buffer(const struct scm_response *rsp)
{
	return (void *)rsp + rsp->buf_offset;
}

static int scm_remap_error(int err)
{
	switch (err) {
	case SCM_ERROR:
		return -EIO;
	case SCM_EINVAL_ADDR:
	case SCM_EINVAL_ARG:
		return -EINVAL;
	case SCM_EOPNOTSUPP:
		return -EOPNOTSUPP;
	case SCM_ENOMEM:
		return -ENOMEM;
	case SCM_EBUSY:
		return -EBUSY;
	}
	return -EINVAL;
}

static u32 smc(u32 cmd_addr)
{
	int context_id;
	register u32 r0 asm("r0") = 1;
	register u32 r1 asm("r1") = (u32)&context_id;
	register u32 r2 asm("r2") = cmd_addr;
	do {
		asm volatile(
			__asmeq("%0", "r0")
			__asmeq("%1", "r0")
			__asmeq("%2", "r1")
			__asmeq("%3", "r2")
			".arch_extension sec\n"
			"smc	#0	@ switch to secure world\n"
			: "=r" (r0)
			: "r" (r0), "r" (r1), "r" (r2)
			: "r3");
	} while (r0 == SCM_INTERRUPTED);

	return r0;
}

static int __scm_call(const struct scm_command *cmd)
{
	int ret;
	u32 cmd_addr = virt_to_phys((void *)cmd);

	/*
	 * Flush the entire cache here so callers don't have to remember
	 * to flush the cache when passing physical addresses to the secure
	 * side in the buffer.
	 */
	flush_dcache_all();
	ret = smc(cmd_addr);
	if (ret < 0)
		ret = scm_remap_error(ret);

	return ret;
}

static u32 cacheline_size;

static void scm_inv_range(unsigned long start, unsigned long end)
{
	start = round_down(start, cacheline_size);
	end = round_up(end, cacheline_size);
	while (start < end) {
		asm ("mcr p15, 0, %0, c7, c6, 1" : : "r" (start)
		     : "memory");
		start += cacheline_size;
	}
}

/**
 * scm_call() - Send an SCM command
 * @svc_id: service identifier
 * @cmd_id: command identifier
 * @cmd_buf: command buffer
 * @cmd_len: length of the command buffer
 * @resp_buf: response buffer
 * @resp_len: length of the response buffer
 *
 * Sends a command to the SCM and waits for the command to finish processing.
 */
int scm_call(u32 svc_id, u32 cmd_id, const void *cmd_buf, size_t cmd_len,
		void *resp_buf, size_t resp_len)
{
	int ret;
	struct scm_command *cmd;
	struct scm_response *rsp;
	unsigned long start, end;

	cmd = alloc_scm_command(cmd_len, resp_len);
	if (!cmd)
		return -ENOMEM;

	cmd->id = (svc_id << 10) | cmd_id;
	if (cmd_buf)
		memcpy(scm_get_command_buffer(cmd), cmd_buf, cmd_len);

	ret = __scm_call(cmd);

	if (ret)
		goto out;

	rsp = scm_command_to_response(cmd);
	start = (unsigned long)rsp;

	do {
		scm_inv_range(start, start + sizeof(*rsp));
	} while (!rsp->is_complete);

	end = (unsigned long)scm_get_response_buffer(rsp) + resp_len;
	scm_inv_range(start, end);

	if (resp_buf)
		memcpy(resp_buf, scm_get_response_buffer(rsp), resp_len);
out:
	free_scm_command(cmd);
	return ret;
}

int scm_init(void)
{
	u32 ctr;

	asm volatile("mrc p15, 0, %0, c0, c0, 1" : "=r" (ctr));
	cacheline_size =  4 << ((ctr >> 16) & 0xf);
	return 0;
}

int __qca_scm_call_armv8_32(u32 x0, u32 x1, u32 x2, u32 x3, u32 x4, u32 x5,
				u32 *ret1, u32 *ret2, u32 *ret3)
{
	register u32 r0 __asm__("r0") = x0;
	register u32 r1 __asm__("r1") = x1;
	register u32 r2 __asm__("r2") = x2;
	register u32 r3 __asm__("r3") = x3;
	register u32 r4 __asm__("r4") = x4;
	register u32 r5 __asm__("r5") = x5;

	asm volatile(
		__asmeq("%0", "r0")
		__asmeq("%1", "r1")
		__asmeq("%2", "r2")
		__asmeq("%3", "r3")
		__asmeq("%4", "r0")
		__asmeq("%5", "r1")
		__asmeq("%6", "r2")
		__asmeq("%7", "r3")
		__asmeq("%8", "r4")
		__asmeq("%9", "r5")
		".arch_extension sec\n"
		"smc    #0\n"
		: "=r" (r0), "=r" (r1), "=r" (r2), "=r" (r3)
		: "r" (r0), "r" (r1), "r" (r2), "r" (r3), "r" (r4),
		"r" (r5));

	if (ret1)
		*ret1 = r1;
	if (ret2)
		*ret2 = r2;
	if (ret3)
		*ret3 = r3;

	return r0;
}


/**
 * scm_call_64() - Invoke a syscall in the secure world
 *  <at> svc_id: service identifier
 *  <at> cmd_id: command identifier
 *  <at> fn_id: The function ID for this syscall
 *  <at> desc: Descriptor structure containing arguments and return values
 *
 * Sends a command to the SCM and waits for the command to finish processing.
 *
 */
static int scm_call_64(u32 svc_id, u32 cmd_id, struct qca_scm_desc *desc)
{
	int arglen = desc->arginfo & 0xf;
	int ret;
	u32 fn_id = QCA_SCM_SIP_FNID(svc_id, cmd_id);


	if (arglen > QCA_MAX_ARG_LEN) {
		printf("Error Extra args not supported\n");
		hang();
	}

	desc->ret[0] = desc->ret[1] = desc->ret[2] = 0;

	flush_dcache_all();
	ret = __qca_scm_call_armv8_32(fn_id, desc->arginfo,
			desc->args[0], desc->args[1],
			desc->args[2], desc->x5,
			&desc->ret[0], &desc->ret[1],
			&desc->ret[2]);

	return ret;
}

static enum scm_interface_version {
        SCM_UNKNOWN,
        SCM_LEGACY,
        SCM_ARMV8_32,
} scm_version = SCM_UNKNOWN;

/* This function is used to find whether TZ is in AARCH64 mode.
 * If this function returns 1, then its in AARCH64 mode and
 * calling conventions for AARCH64 TZ is different, we need to
 * use them.
 */
bool is_scm_armv8(void)
{
        int ret;
        u32 ret1, x0;

        if (likely(scm_version != SCM_UNKNOWN))
                return (scm_version == SCM_ARMV8_32);

        /* Try SMC32 call */
        ret1 = 0;
        x0 = QCA_SCM_SIP_FNID(SCM_SVC_INFO, QCA_IS_CALL_AVAIL_CMD) |
                        QCA_SMC_ATOMIC_MASK;

	flush_dcache_all();
        ret = __qca_scm_call_armv8_32(x0, QCA_SCM_ARGS(1), x0, 0, 0, 0,
                                  &ret1, NULL, NULL);
        if (ret || !ret1)
                scm_version = SCM_LEGACY;
        else
                scm_version = SCM_ARMV8_32;

        pr_debug("scm_call: scm version is %x\n", scm_version);

        return (scm_version == SCM_ARMV8_32);
}

void __attribute__ ((noreturn)) jump_kernel64(void *kernel_entry,
				void *fdt_addr)
{
	struct qca_scm_desc desc = {0};
	int ret = 0;
	kernel_params param = {0};

	param.reg_x0 = (u32)fdt_addr;
	param.kernel_start = (u32)kernel_entry;

	desc.arginfo = QCA_SCM_ARGS(2, SCM_READ_OP);
	desc.args[0] = (u32) &param;
	desc.args[1] = sizeof(param);

	if (!is_scm_armv8()) {
		printf("Can't boot kernel: %d\n", ret);
		hang();
	}

	printf("Jumping to AARCH64 kernel via monitor\n");
	ret = scm_call_64(SCM_ARCH64_SWITCH_ID, SCM_EL1SWITCH_CMD_ID,
		&desc);

	printf("Can't boot kernel: %d\n", ret);
	hang();
}


void __attribute__ ((noreturn)) execute_tzt(void *entry_addr)
{
        struct qca_scm_desc desc = {0};
        int ret = 0;
        kernel_params param = {0};

        param.kernel_start = (u32)entry_addr;

        desc.arginfo = QCA_SCM_ARGS(2, SCM_READ_OP);
        desc.args[0] = (u32) &param;
        desc.args[1] = sizeof(param);

        printf("Jumping to AARCH64 TZT via monitor\n");
        ret = scm_call_64(SCM_ARCH64_SWITCH_ID, SCM_EL1SWITCH_CMD_ID,
                &desc);

        printf("Can't boot TZT: %d\n", ret);
        hang();
}


/* We need to invalidate the buffer written by TZ before we use in u-boot
 * In some calls TZ writes to desc.args[0].
 * This arg is passed with an address of local variable with size 1.
 * This is not cache aligned and invalidate_dcache_range won't
 * invalidate this cache line at all. To avoid this we are passing a
 * buffer which is cache aligned and we will copy contents of this
 * buffer back to buffer passed by callers.
 */
/* Just aliging the address of local variable with cache line is also
 * not correct as the other stack contents will also be invalidated wrongly
 * Hence creating a seperate cache aligned buffer
 */
#ifndef CONFIG_SYS_CACHELINE_SIZE
#define CONFIG_SYS_CACHELINE_SIZE	128
#endif
static uint8_t tz_buf[CONFIG_SYS_CACHELINE_SIZE]  __aligned(CONFIG_SYS_CACHELINE_SIZE);

#ifndef CONFIG_QCA_DISABLE_SCM
int qca_scm_call(u32 svc_id, u32 cmd_id, void *buf, size_t len)
{
	int ret = 0;

	if (is_scm_armv8())
	{
		struct qca_scm_desc desc = {0};

		memcpy(tz_buf, buf, len);
		desc.arginfo = QCA_SCM_ARGS(2, SCM_READ_OP);
		desc.args[0] = (u32)tz_buf;
		desc.args[1] = len;
		ret = scm_call_64(svc_id, cmd_id, &desc);
		/* qca_scm_call is called with len 1, hence tz_buf is enough */
		invalidate_dcache_range((unsigned long)tz_buf,
					(unsigned long)tz_buf +
					CONFIG_SYS_CACHELINE_SIZE);
		memcpy(buf, tz_buf, len);
	}
	else
	{
		ret = scm_call(svc_id, cmd_id, NULL, 0, buf, len);
	}
	return ret;
}

int qca_scm_fuseipq(u32 svc_id, u32 cmd_id, void *buf, size_t len)
{
	int ret = 0;
	uint32_t *status;
	if (is_scm_armv8())
	{
		struct qca_scm_desc desc = {0};

		desc.arginfo = QCA_SCM_ARGS(1, SCM_READ_OP);
		desc.args[0] = *((unsigned int *)buf);

		ret = scm_call_64(svc_id, cmd_id, &desc);

		status = (uint32_t *)(*(((uint32_t *)buf) + 1));
		*status = desc.ret[0];
	}
	else
	{
		ret = scm_call(svc_id, cmd_id, buf, len, NULL, 0);
	}
	return ret;
}

int qca_scm_auth_kernel(void *cmd_buf,
			size_t cmd_len)
{
	int ret = 0;

	if (is_scm_armv8())
	{
		struct qca_scm_desc desc = {0};
		desc.arginfo = QCA_SCM_ARGS(1, SCM_VAL);
		/* args[0] has the kernel load address */
		desc.args[0] = * ((unsigned int *)cmd_buf);
		/* args[1] has the kernel image size */
		desc.args[1] = * (((unsigned int *)cmd_buf) + 1);
		ret = scm_call_64(SCM_SVC_BOOT, KERNEL_AUTH_CMD, &desc);
	}
	else
	{
		ret = scm_call(SCM_SVC_BOOT, KERNEL_AUTH_CMD, cmd_buf, cmd_len,
				NULL, 0);
	}

	return ret;
}

int is_scm_sec_auth_available(u32 svc_id, u32 cmd_id)
{

	int ret;
	__le32 scm_ret;

	if (is_scm_armv8())
	{
		struct qca_scm_desc desc = {0};

		desc.args[0] = QCA_SCM_SIP_FNID(svc_id, cmd_id);
		desc.arginfo = QCA_SCM_ARGS(1);

		ret = scm_call_64(SCM_SVC_INFO, IS_CALL_AVAIL_CMD, &desc);
		scm_ret = desc.ret[0];
	}
	else
	{
		__le32 svc_cmd = cpu_to_le32((svc_id << SCM_SVC_ID_SHIFT) | cmd_id);

		ret = scm_call(SCM_SVC_INFO, IS_CALL_AVAIL_CMD, &svc_cmd,
				sizeof(svc_cmd), &scm_ret, sizeof(scm_ret));
	}

	if (!ret)
		return le32_to_cpu(scm_ret);

	return ret;
}

int qca_scm_secure_authenticate(void *cmd_buf, size_t cmd_len)
{
	int ret = 0;

	if (is_scm_armv8())
	{
		struct qca_scm_desc desc = {0};

		desc.arginfo = QCA_SCM_ARGS(3, SCM_VAL, SCM_VAL, SCM_IO_WRITE);
		/* args[0] has the image SW ID*/
		desc.args[0] = * ((unsigned long *)cmd_buf);
		/* args[1] has the image size */
		desc.args[1] = * (((unsigned long *)cmd_buf) + 1);
		/* args[2] has the load address*/
		desc.args[2] = * (((unsigned long *)cmd_buf) + 2);

		ret = scm_call_64(SCM_SVC_BOOT, SCM_CMD_SEC_AUTH, &desc);
	}
	else
	{
		ret = scm_call(SCM_SVC_BOOT, SCM_CMD_SEC_AUTH, cmd_buf, cmd_len,
				NULL, 0);
	}

	return ret;
}
#else
int qca_scm_call(u32 svc_id, u32 cmd_id, void *buf, size_t len)
{
	return 0;
}
int qca_scm_fuseipq(u32 svc_id, u32 cmd_id, void *buf, size_t len)
{
	return 0;
}
int qca_scm_auth_kernel(void *cmd_buf,
			size_t cmd_len)
{
	return 0;
}
int is_scm_sec_auth_available(u32 svc_id, u32 cmd_id)
{
	return 0;
}
int qca_scm_secure_authenticate(void *cmd_buf, size_t cmd_len)
{
	return 0;
}
#endif

int qca_scm_call_write(u32 svc_id, u32 cmd_id, u32 *addr, u32 val)
{
	int ret = 0;
	struct qca_scm_desc desc = {0};

	/* In ipq807x, this SCM call is called as a Fast
	 * SCM call which means it will get executed in
	 * EL3 monitor mode itself without jumping to QSEE.
	 * But, In ipq6018, We need to jump into QSEE which
	 * will execute the SCM call, as we do not have
	 * support for Fast SCM call in ipq6018.
	 */

	desc.arginfo = QCA_SCM_ARGS(2, SCM_VAL, SCM_VAL);

	desc.args[0] = (u32)addr;
	desc.args[1] = val;
	ret = scm_call_64(svc_id, cmd_id, &desc);
	return ret;
}

static int qca_scm_sdi_v8(void)
{
	struct qca_scm_desc desc = {0};
	int ret;

	desc.args[0] = 1ul;    /* Disable wdog debug */
	desc.args[1] = 0ul;    /* SDI Enable */
	desc.arginfo = QCA_SCM_ARGS(2, SCM_VAL, SCM_VAL);
	ret = scm_call_64(SCM_SVC_BOOT,
			     SCM_CMD_TZ_CONFIG_HW_FOR_RAM_DUMP_ID, &desc);

	if (ret)
		return ret;

	return le32_to_cpu(desc.ret[0]);
}

int qca_scm_sdi(void)
{
        int ret;
        unsigned int clear_info[] = {
                1 /* Disable wdog debug */, 0 /* SDI enable*/, };

        if (is_scm_armv8())
                return qca_scm_sdi_v8();

        ret = scm_call(SCM_SVC_BOOT, SCM_CMD_TZ_CONFIG_HW_FOR_RAM_DUMP_ID, &clear_info,
                                sizeof(clear_info), NULL, 0);

        return ret;
}

int qca_scm_dload(unsigned int magic_cookie)
{
	int ret;
        if (is_scm_armv8())
	{
		ret = qca_scm_call_write(SCM_SVC_IO, SCM_IO_WRITE,
					 (u32 *)0x193D100, magic_cookie);
	}
	else
	{
		ret = scm_call(SCM_SVC_BOOT, SCM_CMD_TZ_FORCE_DLOAD_ID, &magic_cookie,
			sizeof(magic_cookie), NULL, 0);
	}

	return ret;
}

#define SCM_CLASS_REGISTER      (0x2 << 8)
#define SCM_MASK_IRQS           BIT(5)
#define SCM_ATOMIC(svc, cmd, n) (((((svc) << 10) | ((cmd) & 0x3ff)) << 12) | \
				 SCM_CLASS_REGISTER |			\
				 SCM_MASK_IRQS |			\
				 (n & 0xf))

s32  qca_scm_call_atomic_ver2_32(u32 svc, u32 cmd, u32 arg1, u32 arg2)
{
	int context_id;
	register u32 r0 asm("r0") = SCM_ATOMIC(svc, cmd, 2);
	register u32 r1 asm("r1") = virt_to_phys((void *)&context_id);
	register u32 r2 asm("r2") = arg1;
	register u32 r3 asm("r3") = arg2;

	asm volatile(
		     __asmeq("%0", "r0")
		     __asmeq("%1", "r0")
		     __asmeq("%2", "r1")
		     __asmeq("%3", "r2")
		     __asmeq("%4", "r3")

		     "smc #0 @switch to secure world\n"
		     : "=r" (r0)
		     : "r" (r0), "r" (r1), "r" (r2), "r" (r3)
		     );
	return r0;
}


int qca_scm_usb_mode_write(u32 arg1, u32 arg2)
{
	s32 ret;

	ret = qca_scm_call_atomic_ver2_32(SCM_SVC_IO, SCM_IO_WRITE, arg1, arg2);

	return ret;
}

