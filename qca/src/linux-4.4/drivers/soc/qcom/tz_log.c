/*
 * Copyright (c) 2015-2017, The Linux Foundation. All rights reserved.
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

#include <linux/init.h>
#include <linux/module.h>
#include <linux/debugfs.h> /* this is for DebugFS libraries */
#include <linux/fs.h>
#include <linux/dma-mapping.h>
#include <linux/qcom_scm.h>
#include <linux/slab.h>
#include <linux/irqdomain.h>
#include <linux/interrupt.h>
#include <linux/irqreturn.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/irq.h>
#include <linux/platform_device.h>
#include <linux/threads.h>
#include <linux/of_device.h>
#include <linux/mm.h>
#include <linux/gfp.h>

#define BUF_LEN_V8 0x2000
#define BUF_LEN_V7 0x1000

static unsigned int paniconaccessviolation = 0;

/* Maximum size for buffers to support AARCH64 TZ */
#define HVC_PRESENT BIT(0)
#define TZ_64 BIT(1)
#define TZ_KPSS BIT(2)

#define TZ64_HVC_PRESENT (HVC_PRESENT | TZ_64)

struct tzbsp_log_pos_t {
	uint16_t wrap;		/* Ring buffer wrap-around ctr */
	uint16_t offset;	/* Ring buffer current position */
};

struct tzbsp_diag_log_t {
	struct tzbsp_log_pos_t log_pos;	/* Ring buffer position mgmt */
	uint8_t log_buf[1];		/* Open ended array to the end
					 * of the 4K IMEM buffer
					 */
};

struct tzbsp_diag_t {
	uint32_t unused[7];	/* Unused variable is to support the
				 * corresponding structure in trustzone
				 */
	uint32_t ring_off;
	uint32_t unused1[514];
	struct tzbsp_diag_log_t log;
};

struct tzbsp_diag_t_kpss {
	uint32_t magic_num;	/* Magic Number */
	uint32_t version;	/* Major.Minor version */
	uint32_t skip1[5];
	uint32_t ring_off;	/* Ring Buffer Offset */
	uint32_t ring_len;	/* Ring Buffer Len */
	uint32_t skip2[369];
	uint8_t ring_buffer[];	/* TZ Ring Buffer */
};

/* Below structure to support AARCH64 TZ */
struct tzbsp_diag_t_v8 {
	uint32_t unused[7];	/* Unused variable is to support the
				 * corresponding structure in trustzone
				 * and size is varying based on AARCH64 TZ
				 */
	uint32_t ring_off;
	uint32_t unused1[571];
	struct tzbsp_diag_log_t log;
};

typedef struct hyp_log_pos_s {
	uint16_t wrap;
	uint16_t offset;
} hyp_log_pos_t;

/* Boot Info Table */
typedef struct hyp_diag_boot_info_s {
	uint32_t warm_entry_cnt;
	uint32_t warm_exit_cnt;
	uint32_t warmboot_marker;
} hyp_diag_boot_info_t;

typedef struct hyp_diag_log_s {
	uint32_t magic_num;
	uint32_t cpu_count;
	uint32_t ring_off;
	hyp_log_pos_t log_pos;
	uint32_t  log_len;
	uint32_t  s2_fault_counter;
	hyp_diag_boot_info_t    boot_info[NR_CPUS];
	char *log_buf_p;
} hyp_diag_log_t;

struct tz_hvc_log_struct {
	struct dentry *tz_dirret;
	char *ker_buf;
	char *copy_buf;
	int copy_len;
	int flags;
	int buf_len;
	struct mutex lock;
};

static int tz_log_open(struct inode *inode, struct file *file)
{
	struct tz_hvc_log_struct *tz_hvc_log;
	char *ker_buf;
	char *tmp_buf;
	uint32_t buf_len;
	uint16_t wrap;
	struct tzbsp_diag_t *tz_diag;
	struct tzbsp_diag_t_v8 *tz_diag_v8;
	struct tzbsp_diag_t_kpss *tz_diag_kpss;
	struct tzbsp_diag_log_t *log;
	uint16_t offset;
	uint16_t ring;
	int ret;

	file->private_data = inode->i_private;

	tz_hvc_log = file->private_data;
	mutex_lock(&tz_hvc_log->lock);

	ker_buf = tz_hvc_log->ker_buf;
	tmp_buf = tz_hvc_log->copy_buf;
	buf_len = tz_hvc_log->buf_len;
	tz_hvc_log->copy_len = 0;

	/* SCM call to TZ to get the tz log */
	ret = qcom_scm_tz_log(SCM_SVC_INFO, TZ_INFO_GET_DIAG_ID, ker_buf,
				buf_len);
	if (ret != 0) {
		pr_err("Error in getting tz log\n");
		mutex_unlock(&tz_hvc_log->lock);
		return -EIO;
	}

	if (tz_hvc_log->flags & TZ_KPSS) {
		tz_diag_kpss = (struct tzbsp_diag_t_kpss *)ker_buf;
		ring = tz_diag_kpss->ring_off;
		memcpy(tmp_buf, (ker_buf + ring), (buf_len - ring));
		tz_hvc_log->copy_len = buf_len - ring;
	} else {
		if (tz_hvc_log->flags & TZ_64) {
			tz_diag_v8 = (struct tzbsp_diag_t_v8 *)ker_buf;
			ring = tz_diag_v8->ring_off;
			log = &tz_diag_v8->log;
		} else {
			tz_diag = (struct tzbsp_diag_t *) ker_buf;
			ring = tz_diag->ring_off;
			log = &tz_diag->log;
		}

		offset = log->log_pos.offset;
		wrap = log->log_pos.wrap;

		if (wrap != 0) {
			memcpy(tmp_buf, (ker_buf + offset + ring),
					(buf_len - offset - ring));
			memcpy(tmp_buf + (buf_len - offset - ring),
					(ker_buf + ring), offset);
			tz_hvc_log->copy_len = (buf_len - offset - ring)
					+ offset;
		} else {
			memcpy(tmp_buf, (ker_buf + ring), offset);
			tz_hvc_log->copy_len = offset;
		}
	}

	return 0;
}

static int tz_log_release(struct inode *inode, struct file *file)
{
	struct tz_hvc_log_struct *tz_hvc_log;

	tz_hvc_log = file->private_data;
	mutex_unlock(&tz_hvc_log->lock);

	return 0;
}

/* Read file operation */
static ssize_t tz_log_read(struct file *fp, char __user *user_buffer,
				size_t count, loff_t *position)
{
	struct tz_hvc_log_struct *tz_hvc_log;

	tz_hvc_log = fp->private_data;

	return simple_read_from_buffer(user_buffer, count,
					position, tz_hvc_log->copy_buf,
					tz_hvc_log->copy_len);
}

static int hvc_log_open(struct inode *inode, struct file *file)
{
	struct tz_hvc_log_struct *tz_hvc_log;
	int ret;
	uint16_t offset;
	uint16_t ring;
	uint32_t buf_len;
	hyp_diag_log_t *phyp_diag_log;
	uint16_t wrap;
	char *ker_buf;
	char *tmp_buf;

	file->private_data = inode->i_private;
	tz_hvc_log = file->private_data;
	mutex_lock(&tz_hvc_log->lock);

	ker_buf = tz_hvc_log->ker_buf;
	tmp_buf = tz_hvc_log->copy_buf;
	buf_len = tz_hvc_log->buf_len;

	/* SCM call to TZ to get the hvc log */
	ret = qcom_scm_hvc_log(ker_buf, buf_len);
	if (ret != 0) {
		pr_err("Error in getting hvc log\n");
		mutex_unlock(&tz_hvc_log->lock);
		return -EIO;
	}

	phyp_diag_log = (hyp_diag_log_t *)ker_buf;
	offset = phyp_diag_log->log_pos.offset;
	ring = phyp_diag_log->ring_off;
	wrap = phyp_diag_log->log_pos.wrap;

	if (wrap != 0) {
		memcpy(tmp_buf, (ker_buf + offset + ring),
				(buf_len - offset - ring));
		memcpy(tmp_buf + (buf_len - offset - ring), (ker_buf + ring),
			offset);
		tz_hvc_log->copy_len = (buf_len - offset - ring) + offset;
	} else {
		memcpy(tmp_buf, (ker_buf + ring), offset);
		tz_hvc_log->copy_len = offset;
	}

	return 0;
}

static int hvc_log_release(struct inode *inode, struct file *file)
{
	struct tz_hvc_log_struct *tz_hvc_log;

	tz_hvc_log = file->private_data;
	mutex_unlock(&tz_hvc_log->lock);

	return 0;
}

static ssize_t hvc_log_read(struct file *fp, char __user *user_buffer,
				size_t count, loff_t *position)
{
	struct tz_hvc_log_struct *tz_hvc_log;

	tz_hvc_log = fp->private_data;

	return simple_read_from_buffer(user_buffer, count,
					position, tz_hvc_log->copy_buf,
					tz_hvc_log->copy_len);
}

static const struct file_operations fops_tz_log = {
	.open = tz_log_open,
	.read = tz_log_read,
	.release = tz_log_release,
};

static const struct file_operations fops_hvc_log = {
	.open = hvc_log_open,
	.read = hvc_log_read,
	.release = hvc_log_release,
};

static irqreturn_t tzerr_irq(int irq, void *data)
{
	if (paniconaccessviolation) {
		panic("WARN: Access Violation!!!");
	} else {
		pr_emerg("WARN: Access Violation!!!, "
			"Run \"cat /sys/kernel/debug/qcom_debug_logs/tz_log\" "
			"for more details \n");
	}
	return IRQ_HANDLED;
}

static const struct of_device_id qca_tzlog_of_match[] = {
	{ .compatible = "qca,tzlog" },
	{ .compatible = "qca,tz64-hv-log", .data = (void *)TZ64_HVC_PRESENT},
	{ .compatible = "qca,tz64log", .data = (void *)TZ_64},
	{ .compatible = "qca,tzlog_ipq806x", .data = (void *)TZ_KPSS },
	{}
};
MODULE_DEVICE_TABLE(of, qca_tzlog_of_match);

static int qca_tzlog_probe(struct platform_device *pdev)
{
	int irq;
	int ret = 0;
	const struct of_device_id *id;
	struct dentry *tz_fileret;
	struct dentry *hvc_fileret;
	struct tz_hvc_log_struct *tz_hvc_log;
	struct page *page_buf;

	tz_hvc_log = (struct tz_hvc_log_struct *)
			kzalloc(sizeof(struct tz_hvc_log_struct), GFP_KERNEL);
	if (tz_hvc_log == NULL) {
		dev_err(&pdev->dev, "unable to get tzlog memory\n");
		return -ENOMEM;
	}

	id = of_match_device(qca_tzlog_of_match, &pdev->dev);

	if (id) {
		tz_hvc_log->flags = (unsigned long)id->data;
		if (tz_hvc_log->flags & TZ_KPSS)
			tz_hvc_log->buf_len = BUF_LEN_V7;
		else
			tz_hvc_log->buf_len = BUF_LEN_V8;
	} else {
		tz_hvc_log->flags = 0;
		tz_hvc_log->buf_len = BUF_LEN_V7;
	}

	page_buf = alloc_pages(GFP_KERNEL,
					get_order(tz_hvc_log->buf_len));
	if (page_buf == NULL) {
		dev_err(&pdev->dev, "unable to get data buffer memory\n");
		ret = -ENOMEM;
		goto free_mem;
	}

	tz_hvc_log->ker_buf = page_address(page_buf);

	page_buf = alloc_pages(GFP_KERNEL,
					get_order(tz_hvc_log->buf_len));
	if (page_buf == NULL) {
		dev_err(&pdev->dev, "unable to get copy buffer memory\n");
		ret = -ENOMEM;
		goto free_mem;
	}

	tz_hvc_log->copy_buf = page_address(page_buf);

	mutex_init(&tz_hvc_log->lock);

	tz_hvc_log->tz_dirret = debugfs_create_dir("qcom_debug_logs", NULL);
	if (IS_ERR(tz_hvc_log->tz_dirret) || !(tz_hvc_log->tz_dirret)) {
		dev_err(&pdev->dev, "unable to create debugfs\n");
		ret = -EIO;
		goto free_mem;
	}

	tz_fileret = debugfs_create_file("tz_log", 0444,  tz_hvc_log->tz_dirret,
					tz_hvc_log, &fops_tz_log);
	if (IS_ERR(tz_fileret) || !tz_fileret) {
		dev_err(&pdev->dev, "unable to create tz_log debugfs\n");
		ret = -EIO;
		goto remove_debugfs;
	}

	if ((tz_hvc_log->flags) & HVC_PRESENT) {
		hvc_fileret = debugfs_create_file("hvc_log", 0444,
			tz_hvc_log->tz_dirret, tz_hvc_log, &fops_hvc_log);
		if (IS_ERR(hvc_fileret) || !hvc_fileret) {
			dev_err(&pdev->dev, "can't create hvc_log debugfs\n");
			ret = -EIO;
			goto remove_debugfs;
		}
	}

	irq = platform_get_irq(pdev, 0);
	if (irq > 0) {
		devm_request_irq(&pdev->dev, irq, tzerr_irq,
				IRQF_ONESHOT, "tzerror", NULL);
	}

	platform_set_drvdata(pdev, tz_hvc_log);

	if (paniconaccessviolation) {
		printk("TZ Log : Will panic on Access Violation, as paniconaccessviolation is set\n");
	} else {
		printk("TZ Log : Will warn on Access Violation, as paniconaccessviolation is not set\n");
	}
	return 0;

remove_debugfs:
	debugfs_remove_recursive(tz_hvc_log->tz_dirret);
free_mem:
	if (tz_hvc_log->copy_buf)
		__free_pages(virt_to_page(tz_hvc_log->copy_buf),
				get_order(tz_hvc_log->buf_len));

	if (tz_hvc_log->ker_buf)
		__free_pages(virt_to_page(tz_hvc_log->ker_buf),
				get_order(tz_hvc_log->buf_len));

	kfree(tz_hvc_log);

	return ret;
}

static int qca_tzlog_remove(struct platform_device *pdev)
{
	struct tz_hvc_log_struct *tz_hvc_log = platform_get_drvdata(pdev);

	/* removing the directory recursively which
	in turn cleans all the file */
	debugfs_remove_recursive(tz_hvc_log->tz_dirret);
	__free_pages(virt_to_page(tz_hvc_log->ker_buf),
			get_order(tz_hvc_log->buf_len));

	kfree(tz_hvc_log);

	return 0;
}

static struct platform_driver qca_tzlog_driver = {
	.probe = qca_tzlog_probe,
	.remove = qca_tzlog_remove,
	.driver  = {
		.name  = "qca_tzlog",
		.of_match_table = qca_tzlog_of_match,
	},
};

MODULE_PARM_DESC(paniconaccessviolation, "Panic on Access Violation detected: 0,1");
module_platform_driver(qca_tzlog_driver);
module_param(paniconaccessviolation, uint, 0644);
