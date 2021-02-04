/*
 * Copyright (c) 2014 - 2015, The Linux Foundation. All rights reserved.
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

#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/device.h>
#include <linux/qcom_scm.h>
#include <asm/cacheflush.h>
#include <linux/dma-mapping.h>
#include <linux/platform_device.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include <linux/of.h>

#define QFPROM_MAX_VERSION_EXCEEDED             0x10
#define QFPROM_IS_AUTHENTICATE_CMD_RSP_SIZE	0x2

#define SW_TYPE_DEFAULT				0xFF
#define SW_TYPE_SBL				0x0
#define SW_TYPE_TZ				0x7
#define SW_TYPE_APPSBL				0x9
#define SW_TYPE_HLOS				0x17
#define SW_TYPE_RPM				0xA
#define SW_TYPE_DEVCFG				0x5
#define SW_TYPE_APDP				0x200

static int gl_version_enable;

static ssize_t
qfprom_show_authenticate(struct device *dev,
			struct device_attribute *attr,
			char *buf)
{
	int ret;

	ret = qcom_qfprom_show_authenticate();
	if (ret == -1)
		return ret;

	/* show needs a string response */
	if (ret == 1)
		buf[0] = '1';
	else
		buf[0] = '0';

	buf[1] = '\0';

	return QFPROM_IS_AUTHENTICATE_CMD_RSP_SIZE;
}

int write_version(struct device *dev, uint32_t type, uint32_t version)
{
	int ret;
	struct qfprom_write {
		uint32_t sw_type;
		uint32_t value;
		uint32_t qfprom_ret_ptr;
	} wrip;

	uint32_t *qfprom_api_status = kzalloc(sizeof(uint32_t), GFP_KERNEL);

	if (!qfprom_api_status)
		return -ENOMEM;

	wrip.value = version;
	wrip.sw_type = type;
	wrip.qfprom_ret_ptr = dma_map_single(dev, qfprom_api_status,
			sizeof(*qfprom_api_status), DMA_FROM_DEVICE);

	ret = dma_mapping_error(dev, wrip.qfprom_ret_ptr);
	if (ret) {
		pr_err("DMA Mapping Error(api_status)\n");
		goto err_write;
	}

	ret = qcom_qfprom_write_version(&wrip, sizeof(wrip));

	dma_unmap_single(dev, wrip.qfprom_ret_ptr,
			sizeof(*qfprom_api_status), DMA_FROM_DEVICE);

	if(ret)
		pr_err("%s: Error in QFPROM write (%d, %d)\n",
					__func__, ret, *qfprom_api_status);
	if (*qfprom_api_status == QFPROM_MAX_VERSION_EXCEEDED)
		pr_err("Version %u exceeds maximum limit. All fuses blown.\n",
							    version);

err_write:
	kfree(qfprom_api_status);
	return ret;
}

int read_version(struct device *dev, int type, uint32_t **version_ptr)
{
	int ret, ret1, ret2;
	struct qfprom_read {
		uint32_t sw_type;
		uint32_t value;
		uint32_t qfprom_ret_ptr;
	} rdip;

	uint32_t *qfprom_api_status = kzalloc(sizeof(uint32_t), GFP_KERNEL);

	if (!qfprom_api_status)
		return -ENOMEM;

	rdip.sw_type = type;
	rdip.value = dma_map_single(dev, *version_ptr,
		sizeof(uint32_t), DMA_FROM_DEVICE);

	rdip.qfprom_ret_ptr = dma_map_single(dev, qfprom_api_status,
		sizeof(*qfprom_api_status), DMA_FROM_DEVICE);

	ret1 = dma_mapping_error(dev, rdip.value);
	ret2 = dma_mapping_error(dev, rdip.qfprom_ret_ptr);

	if (ret1 == 0 && ret2 == 0) {
		ret = qcom_qfprom_read_version(type, rdip.value,
			rdip.qfprom_ret_ptr);
	}
	if (ret1 == 0) {
		dma_unmap_single(dev, rdip.value,
			sizeof(uint32_t), DMA_FROM_DEVICE);
	}
	if (ret2 == 0) {
		dma_unmap_single(dev, rdip.qfprom_ret_ptr,
			sizeof(*qfprom_api_status), DMA_FROM_DEVICE);
	}
	if (ret1 || ret2) {
		pr_err("DMA Mapping Error version ret %d api_status ret %d\n",
							ret1, ret2);
		ret = ret1 ? ret1 : ret2;
		goto err_read;
	}

	if (ret || *qfprom_api_status) {
		pr_err("%s: Error in QFPROM read (%d, %d)\n",
			 __func__, ret, *qfprom_api_status);
	}
err_read:
	kfree(qfprom_api_status);
	return ret;
}

static ssize_t generic_version(struct device *dev, const char *buf,
		uint32_t sw_type, int op, size_t count)
{
	int ret = 0;
	uint32_t *version = kzalloc(sizeof(uint32_t), GFP_KERNEL);

	if (!version)
		return -ENOMEM;

	/*
	 * Operation Type: Read: 1 and Write: 2
	 */
	switch (op) {
	case 1:
		ret = read_version(dev, sw_type, &version);
		if (ret) {
			pr_err("Error in reading version: %d\n", ret);
			goto err_generic;
		}
		ret = snprintf((char *)buf, 10, "%d\n", *version);
		break;
	case 2:
		/* Input validation handled here */
		ret = kstrtouint(buf, 0, version);
		if (ret)
			goto err_generic;

		ret = write_version(dev, sw_type, *version);
		if (ret) {
			pr_err("Error in writing version: %d\n", ret);
			goto err_generic;
		}
		ret = count;
		break;
	default:
		ret = -EINVAL;
	}

err_generic:
	kfree(version);
	return ret;
}
static ssize_t
show_sbl_version(struct device *dev,
			struct device_attribute *attr,
			char *buf)
{
	return generic_version(dev, buf, SW_TYPE_SBL, 1, 0);
}

static ssize_t
store_sbl_version(struct device *dev,
			struct device_attribute *attr,
			const char *buf, size_t count)
{
	return generic_version(dev, buf, SW_TYPE_SBL, 2, count);
}

static ssize_t
show_tz_version(struct device *dev,
			struct device_attribute *attr,
			char *buf)
{
	return generic_version(dev, buf, SW_TYPE_TZ, 1, 0);
}

static ssize_t
store_tz_version(struct device *dev,
			struct device_attribute *attr,
			const char *buf, size_t count)
{
	return generic_version(dev, buf, SW_TYPE_TZ, 2, count);
}

static ssize_t
show_appsbl_version(struct device *dev,
			struct device_attribute *attr,
			char *buf)
{
	return generic_version(dev, buf, SW_TYPE_APPSBL, 1, 0);
}

static ssize_t
store_appsbl_version(struct device *dev,
			struct device_attribute *attr,
			const char *buf, size_t count)
{
	return generic_version(dev, buf, SW_TYPE_APPSBL, 2, count);
}

static ssize_t
show_hlos_version(struct device *dev,
			struct device_attribute *attr,
			char *buf)
{
	return generic_version(dev, buf, SW_TYPE_HLOS, 1, 0);
}

static ssize_t
store_hlos_version(struct device *dev,
			struct device_attribute *attr,
			const char *buf, size_t count)
{
	return generic_version(dev, buf, SW_TYPE_HLOS, 2, count);
}

static ssize_t
show_rpm_version(struct device *dev,
			struct device_attribute *attr,
			char *buf)
{
	return generic_version(dev, buf, SW_TYPE_RPM, 1, 0);
}

static ssize_t
store_rpm_version(struct device *dev,
			struct device_attribute *attr,
			const char *buf, size_t count)
{
	return generic_version(dev, buf, SW_TYPE_RPM, 2, count);
}

static ssize_t
show_devcfg_version(struct device *dev,
			struct device_attribute *attr,
			char *buf)
{
	return generic_version(dev, buf, SW_TYPE_DEVCFG, 1, 0);
}

static ssize_t
store_devcfg_version(struct device *dev,
			struct device_attribute *attr,
			const char *buf, size_t count)
{
	return generic_version(dev, buf, SW_TYPE_DEVCFG, 2, count);
}

static ssize_t
show_apdp_version(struct device *dev,
			struct device_attribute *attr,
			char *buf)
{
	return generic_version(dev, buf, SW_TYPE_APDP, 1, 0);
}

static ssize_t
store_apdp_version(struct device *dev,
			struct device_attribute *attr,
			const char *buf, size_t count)
{
	return generic_version(dev, buf, SW_TYPE_APDP, 2, count);
}

static ssize_t
store_sec_auth(struct device *dev,
			struct device_attribute *sec_attr,
			const char *buf, size_t count)
{
	int ret;
	long size, sw_type;
	unsigned int img_addr, img_size;
	char *sw, *file_name, *sec_auth_str;
	static void __iomem *file_buf;
	struct device_node *np;
	struct file *file;
	struct kstat st;

	file_name = kzalloc(count+1, GFP_KERNEL);
	if (file_name == NULL)
		return -ENOMEM;

	sec_auth_str = file_name;
	strlcpy(file_name, buf, count+1);

	sw = strsep(&file_name, " ");
	ret = kstrtol(sw, 0, &sw_type);
	if (ret) {
		pr_err("sw_type str to long conversion failed\n");
		goto free_mem;
	}

	file = filp_open(file_name, O_RDONLY, 0);
	if (IS_ERR(file)) {
		pr_err("%s File open failed\n", file_name);
		ret = -EBADF;
		goto free_mem;
	}

	ret = vfs_getattr(&file->f_path, &st);
	if (ret) {
		pr_err("get file attributes failed\n");
		goto file_close;
	}
	size = (long)st.size;

	np = of_find_node_by_name(NULL, "qfprom");
	if (!np) {
		pr_err("Unable to find qfprom node\n");
		goto file_close;
	}

	ret = of_property_read_u32(np, "img-size", &img_size);
	if (ret) {
		pr_err("Read of property:img-size from node failed\n");
		goto put_node;
	}

	if (size > img_size) {
		pr_err("File size exceeds allocated memory region\n");
		goto put_node;
	}

	ret = of_property_read_u32(np, "img-addr", &img_addr);
	if (ret) {
		pr_err("Read of property:img-addr from node failed\n");
		goto put_node;
	}

	file_buf = ioremap_nocache(img_addr, img_size);
	if (file_buf == NULL) {
		ret = -ENOMEM;
		goto put_node;
	}

	memset_io(file_buf, 0x0, img_size);

	ret = kernel_read(file, 0, file_buf, size);
	if (ret != size) {
		pr_err("%s file read failed\n", file_name);
		goto un_map;
	}

	ret = qcom_sec_upgrade_auth(sw_type, size, img_addr);
	if (ret) {
		pr_err("sec_upgrade_auth failed with return=%d\n", ret);
		goto un_map;
	}
	ret = count;

un_map:
	iounmap(file_buf);
put_node:
	of_node_put(np);
file_close:
	filp_close(file, NULL);
free_mem:
	kfree(sec_auth_str);
	return ret;
}

static struct device_attribute sec_attr =
	__ATTR(sec_auth, 0644, NULL, store_sec_auth);

struct kobject *sec_kobj;
/*
 * Do not change the order of attributes.
 * New types should be added at the end
 */
static struct device_attribute qfprom_attrs[] = {
	__ATTR(authenticate, 0444, qfprom_show_authenticate,
					NULL),
	__ATTR(sbl_version, 0644, show_sbl_version,
					store_sbl_version),
	__ATTR(tz_version, 0644, show_tz_version,
					store_tz_version),
	__ATTR(appsbl_version, 0644, show_appsbl_version,
					store_appsbl_version),
	__ATTR(hlos_version, 0644, show_hlos_version,
					store_hlos_version),
	__ATTR(rpm_version, 0644, show_rpm_version,
					store_rpm_version),
	__ATTR(devcfg_version, 0644, show_devcfg_version,
					store_devcfg_version),
	__ATTR(apdp_version, 0644, show_apdp_version,
					store_apdp_version),

};

static struct bus_type qfprom_subsys = {
	.name = "qfprom",
	.dev_name = "qfprom",
};

static struct device device_qfprom = {
	.id = 0,
	.bus = &qfprom_subsys,
};

static int __init qfprom_create_files(int size, int16_t sw_bitmap)
{
	int i;
	int err;
	int sw_bit;
	/* authenticate sysfs entry is mandatory */
	err = device_create_file(&device_qfprom, &qfprom_attrs[0]);
	if (err) {
		pr_err("%s: device_create_file(%s)=%d\n",
			__func__, qfprom_attrs[0].attr.name, err);
		return err;
	}

	if (gl_version_enable != 1)
		return 0;

	for (i = 1; i < size; i++) {
			/*
			 * Following is the BitMap adapted:
			 * SBL:0 TZ:1 APPSBL:2 HLOS:3 RPM:4. New types should
			 * be added at the end of "qfprom_attrs" variable.
			 */
			sw_bit = i - 1;
			if (!(sw_bitmap & (1 << sw_bit)))
				break;
		err = device_create_file(&device_qfprom, &qfprom_attrs[i]);
		if (err) {
			pr_err("%s: device_create_file(%s)=%d\n",
				__func__, qfprom_attrs[i].attr.name, err);
			return err;
		}
	}
	return 0;
}

int is_version_rlbk_enabled(struct device *dev, int16_t *sw_bitmap)
{
	int ret;
	uint32_t *version_enable = kzalloc(sizeof(uint32_t), GFP_KERNEL);
	if (!version_enable)
		return -ENOMEM;

	ret = read_version(dev, SW_TYPE_DEFAULT, &version_enable);
	if (ret) {
		pr_err("\n Version Read Failed with error %d", ret);
		goto err_ver;
	}

	*sw_bitmap = ((*version_enable & 0xFFFF0000) >> 16);

	ret = (*version_enable & 0x1);

err_ver:
	kfree(version_enable);
	return ret;
}

static int qfprom_probe(struct platform_device *pdev)
{
	int err, ret;
	int16_t sw_bitmap = 0;

	if (!qcom_scm_is_available()) {
		pr_info("SCM call is not initialized, defering probe\n");
		return -EPROBE_DEFER;
	}

	gl_version_enable = is_version_rlbk_enabled(&pdev->dev, &sw_bitmap);
	if (gl_version_enable == 0)
		pr_info("\nVersion Rollback Feature Disabled\n");
	/*
	 * Registering under "/sys/devices/system"
	 */
	err = subsys_system_register(&qfprom_subsys, NULL);
	if (err) {
		pr_err("%s: subsys_system_register fail (%d)\n",
			__func__, err);
		return err;
	}

	device_register(&device_qfprom);

	/*
	 * Registering sec_auth under "/sys/sec_authenticate"
	   only if board is secured
	 */
	ret = qcom_qfprom_show_authenticate();
	if (ret == -1)
		return ret;

	if (ret == 1) {
		/*
		 * Checking if secure sysupgrade scm_call is supported
		 */
		if (!qcom_scm_sec_auth_available()) {
			pr_info("qcom_scm_sec_auth_available is not supported\n");
		} else {
			sec_kobj = kobject_create_and_add("sec_upgrade", NULL);
			if (!sec_kobj) {
				pr_info("Failed to register sec_upgrade sysfs\n");
				return -ENOMEM;
			}

			err = sysfs_create_file(sec_kobj, &sec_attr.attr);
			if (err) {
				pr_info("Failed to register sec_auth sysfs\n");
				kobject_put(sec_kobj);
				sec_kobj = NULL;
			}
		}
	}

	return qfprom_create_files(ARRAY_SIZE(qfprom_attrs), sw_bitmap);
}

static const struct of_device_id qcom_qfprom_dt_match[] = {
	{ .compatible = "qcom,qfprom-sec",},
	{}
};

static struct platform_driver qcom_qfprom_driver = {
	.driver = {
		.name	= "qcom_qfprom",
		.of_match_table = qcom_qfprom_dt_match,
	},
	.probe = qfprom_probe,
};

module_platform_driver(qcom_qfprom_driver);
