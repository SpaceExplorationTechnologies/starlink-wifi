/*
 * Copyright (c) 2015, The Linux Foundation. All rights reserved.
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

#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/input.h>
#include <linux/i2c.h>
#include <linux/gpio.h>
#include <linux/irq.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/workqueue.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/debugfs.h>
#include "gsl1680_ts.h"

#define ANDROID_KEY_MENU		59
#define ANDROID_KEY_HOME		102
#define ANDROID_KEY_BACK		158

#define GSL1680_CLIENT_ADDR		0x40
#define DMA_TRANS_LEN			0x10

#define GSL_DEV_NAME			"gsl1680_ts"

#define GSL_IRQ_GPIO		35
#define GSL_RST_GPIO		34


static unsigned int gsl1680_key_map[] = {ANDROID_KEY_MENU, ANDROID_KEY_HOME,
					ANDROID_KEY_BACK};

static int pre_delta;
static int pre_x;
static int pre_y;
static int move_flag;


static u32 gsl_read_interface(struct i2c_client *client,
						u8 reg, u8 *buf, u32 num)
{
	struct i2c_msg xfer_msg[2];

	xfer_msg[0].addr = client->addr;
	xfer_msg[0].flags = client->flags & I2C_M_TEN;
	xfer_msg[0].len = 1;
	xfer_msg[0].buf = &reg;

	xfer_msg[1].addr = client->addr;
	xfer_msg[1].flags = client->flags & I2C_M_TEN;
	xfer_msg[1].flags |= I2C_M_RD;
	xfer_msg[1].len = num;
	xfer_msg[1].buf = buf;

	if (reg < 0x80)
		i2c_transfer(client->adapter, xfer_msg, 2);

	return i2c_transfer(client->adapter, xfer_msg, 2);
}

static u32 gsl_write_interface(struct i2c_client *client,
					const u8 reg, u8 *buf, u32 num)
{
	struct i2c_msg xfer_msg[1];

	buf[0] = reg;

	xfer_msg[0].addr = client->addr;
	xfer_msg[0].len = num + 1;
	xfer_msg[0].flags = client->flags & I2C_M_TEN;
	xfer_msg[0].buf = buf;

	return i2c_transfer(client->adapter, xfer_msg, 1);
}

static inline void fw2buf(u8 *buf, const u32 *fw)
{
	u32 *u32_buf = (int *)buf;
	*u32_buf = *fw;
}

static void gsl_start_core(struct i2c_client *client)
{
	u8 buf[5] = {0};
	u8 reg = GSL_START_REG;

	gsl_write_interface(client, reg, buf, 1);
}

static void gsl_reset_core(struct i2c_client *client)
{
	u8 buf[5] = {0};

	buf[1] = 0x88;
	gsl_write_interface(client, GSL_START_REG, buf, 1);
	msleep(500);

	buf[1] = 0x04;
	gsl_write_interface(client, GSL_CLOCK_REG, buf, 1);
	msleep(500);

	buf[4] = 0x00;
	buf[3] = 0x00;
	buf[2] = 0x00;
	buf[1] = 0x00;
	gsl_write_interface(client, POWE_FAIL_REG, buf, 4);
	msleep(500);
}

static void gsl_load_fw(struct i2c_client *client)
{
	u8 buf[129] = {0};
	u8 send_flag = 1;
	u8 *cur = buf + 1;
	u32 source_line = 0;
	u32 source_len = ARRAY_SIZE(GSL1680_D0_FW);

	for (; source_line < source_len; source_line++) {
		/* init page trans, set the page val */
		if (GSL1680_D0_FW[source_line].offset == GSL_PAGE_REG) {
			fw2buf(cur, &GSL1680_D0_FW[source_line].val);
			gsl_write_interface(client, GSL_PAGE_REG, buf, 4);
			send_flag = 1;
		} else {
			if (send_flag % DMA_TRANS_LEN == 1)
				buf[0] = (u8)GSL1680_D0_FW[source_line].offset;

			fw2buf(cur, &GSL1680_D0_FW[source_line].val);
			cur += 4;

			if (send_flag % DMA_TRANS_LEN == 0) {
				gsl_write_interface(client, buf[0], buf,
							cur - buf - 1);
				cur = buf + 1;
			}
			send_flag++;
		}
	}
}


static int check_mem_data(struct i2c_client *client)
{
	char buf[4] = {0};

	msleep(500);
	gsl_read_interface(client, 0xb0, buf, 4);

	if (buf[3] != 0x5a || buf[2] != 0x5a || buf[1] != 0x5a
						|| buf[0] != 0x5a) {
		pr_info("first attempt failed. firmware retry\n");
		gsl_reset_core(client);
		gsl_load_fw(client);
		gsl_start_core(client);
		gsl_reset_core(client);
		gsl_start_core(client);

		gsl_read_interface(client, 0xb0, buf, 4);
		if (buf[3] != 0x5a || buf[2] != 0x5a || buf[1] != 0x5a
						 || buf[0] != 0x5a) {
			pr_info("GSL: Firmware Upgrade Failed !!\n");
			return 1;
		}
	}

	pr_info("GSL: Firmware Upgarde Success !!\n");
	return 0;
}

static void gsl1680_touch_up(struct gsl_ts_data *ddata)
{
	int i;
	struct input_dev *ts_input = ddata->idev;

	for (i = 0; i < ARRAY_SIZE(gsl1680_key_map); i++)
		input_event(ts_input, EV_KEY, gsl1680_key_map[i], 0);
}

static void gsl_report_point(struct gsl_ts_data *ddata, u8 num)
{
	input_report_abs(ddata->idev, ABS_MT_TOUCH_MAJOR, MAX_TOUCH);
	input_report_abs(ddata->idev, ABS_MT_POSITION_X,
					ddata->ti->point[num].x);
	input_report_abs(ddata->idev, ABS_MT_POSITION_Y,
					ddata->ti->point[num].y);
	input_report_abs(ddata->idev, ABS_MT_WIDTH_MAJOR, MAX_WIDTH);
	input_mt_sync(ddata->idev);
}

static void gsl_report_work(struct work_struct *work)
{
	int tmp;
	struct gsl_ts_data *ddata =
				container_of(work, struct gsl_ts_data, work);

	gsl_read_interface(ddata->client, TOUCH_INFO_REG,
			(u8 *)(ddata->ti), sizeof(union gsl_touch_info));
	pre_delta = abs(pre_x - ddata->ti->point[0].x) +
			abs(pre_y - ddata->ti->point[0].y);
	pre_x = ddata->ti->point[0].x;
	pre_y = ddata->ti->point[0].y;
	move_flag++;
	if (pre_delta < 5 && (move_flag % 2) != 0 &&
				ddata->ti->finger_num != 0) {
		pre_delta = 0;
		return;
	}
	if (ddata->ti->finger_num == 0) {
		pr_info("gsl_report_work,finger_num==0\n");
		move_flag = 0;
		gsl1680_touch_up(ddata);
		input_mt_sync(ddata->idev);
	} else {
		pr_info("gsl_report_work,finger_num==multi finger ,gsl_report_point\n");
		for (tmp = 0; tmp < ddata->ti->finger_num; tmp++)
			gsl_report_point(ddata, tmp);
	}

	input_report_key(ddata->idev, BTN_TOUCH, !!ddata->ti->finger_num);
	input_sync(ddata->idev);
}

static irqreturn_t gsl_irq_handle(int irq, void *dev_id)
{
	struct gsl_ts_data *ddata = dev_id;

	disable_irq_nosync(irq);

	queue_work(ddata->wq, &ddata->work);
	enable_irq(ddata->irq);
	return IRQ_HANDLED;
}

static int gsl_request_input(struct gsl_ts_data *ddata)
{
	int ret = 0;
	int i;

	ddata->idev = input_allocate_device();
	if (!ddata->idev) {
		pr_info("could not allocate device");
		return -ENODEV;
	}

	ddata->idev->name = GSL_DEV_NAME;
	ddata->idev->id.bustype = BUS_I2C;
	ddata->idev->dev.parent = &ddata->client->dev;
	input_set_drvdata(ddata->idev, ddata);

	__set_bit(EV_ABS, ddata->idev->evbit);
	__set_bit(EV_KEY, ddata->idev->evbit);
	__set_bit(BTN_TOUCH, ddata->idev->keybit);
	__set_bit(INPUT_PROP_DIRECT, ddata->idev->propbit);

	for (i = 0; i < ARRAY_SIZE(gsl1680_key_map); i++)
		__set_bit(gsl1680_key_map[i], ddata->idev->keybit);

	input_set_abs_params(ddata->idev, ABS_MT_POSITION_X,
						DIS_MIN_X, DIS_MAX_X, 0, 0);
	input_set_abs_params(ddata->idev, ABS_MT_POSITION_Y,
						DIS_MIN_Y, DIS_MAX_Y, 0, 0);
	input_set_abs_params(ddata->idev, ABS_MT_TOUCH_MAJOR,
						MIN_TOUCH, MAX_TOUCH, 0, 0);
	input_set_abs_params(ddata->idev, ABS_MT_WIDTH_MAJOR,
						MIN_WIDTH, MAX_WIDTH, 0, 0);
	input_set_abs_params(ddata->idev, ABS_MT_TRACKING_ID,
						MIN_TRCKID, MAX_TRCKID, 0, 0);

	INIT_WORK(&ddata->work, gsl_report_work);

	ddata->wq = create_singlethread_workqueue(GSL_DEV_NAME);
	if (!ddata->wq) {
		ret = -ENOMEM;
		goto error_wq_create;
	}

	ret = input_register_device(ddata->idev);
	if (ret) {
		pr_info("ret = %d : could not register input device", ret);
		goto error_unreg_device;
	}
	return 0;

error_unreg_device:
	destroy_workqueue(ddata->wq);
error_wq_create:
	input_free_device(ddata->idev);
	return ret;
}

static int gsl1680_pin_config(void)
{
	gpio_request(GSL_IRQ_GPIO, "ts_irq");
	gpio_direction_input(GSL_IRQ_GPIO);

	gpio_request(GSL_RST_GPIO, "ts_rst");
	gpio_direction_output(GSL_RST_GPIO, 1);
	msleep(500);
	gpio_direction_output(GSL_RST_GPIO, 0);
	msleep(500);
	gpio_direction_output(GSL_RST_GPIO, 1);
	msleep(500);
	return gpio_to_irq(GSL_IRQ_GPIO);
}

static int gsl_hw_init(struct gsl_ts_data *ddata)
{
	int ret;

	ddata->irq = gsl1680_pin_config();
	if (ddata->irq < 0) {
		ret = ddata->irq;
		goto error_pin_config;
	}

	ret = request_irq(ddata->irq, gsl_irq_handle, IRQF_TRIGGER_RISING,
							GSL_DEV_NAME, ddata);
	if (ret)
		goto error_req_irq;

	return 0;

error_req_irq:
	free_irq(ddata->irq, ddata);
error_pin_config:
	gpio_free(GSL_IRQ_GPIO);
#ifdef GPIO_RST_USE
	gpio_free(GSL_RST_GPIO);
#endif
	return ret;
}

static int gsl_sw_init(struct gsl_ts_data *ddata)
{
	i2c_set_clientdata(ddata->client, ddata);

	if (!i2c_check_functionality(ddata->client->adapter, I2C_FUNC_I2C)) {
		dev_err(&ddata->client->dev, "I2C functionality not support!\n");
		return -EIO;
	}
	gsl_reset_core(ddata->client);
	msleep(500);
	gsl_load_fw(ddata->client);
	msleep(500);
	gsl_start_core(ddata->client);
	msleep(500);
	gsl_reset_core(ddata->client);
	msleep(500);
	gsl_start_core(ddata->client);
	msleep(500);

	if (check_mem_data(ddata->client))
		return 1;

	return 0;
}


#ifdef USE_IOCTL
#define GSL_PR_DIFVALUE         1
#define GSL_UPDATE_FIRMWARE     2

static int gsl_open(struct inode *inode, struct file *filp)
{
	return 0;
}

static void gsl_release(struct inode *inode, struct file *filp)
{
}

static ssize_t gsl_write(struct file *filp, const char __user *buf,
						size_t count, loff_t *ppos)
{
	return 0;
}

static ssize_t gsl_read(struct file *filp, const char *buf,
					size_t count, loff_t *ppos)
{
	return 0;
}

static int gsl_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	return 0;
}

static const struct file_operations gsl_fops = {
	.owner      = THIS_MODULE,
	.write      = gsl_write,
	.read       = gsl_read,
	.unlocked_ioctl = gsl_ioctl
};
#endif

static int gsl1680_probe(struct i2c_client *client,
				const struct i2c_device_id *id)
{
	struct gsl_ts_data *ddata;
	int ret = 0;
#ifdef USE_IOCTL
	struct class *i2c_dev_class;
	struct device *dev;
#endif

	ddata = kzalloc(sizeof(struct gsl_ts_data), GFP_KERNEL);
	if (!ddata)
		return -ENOMEM;

	ddata->ti = kzalloc(sizeof(union gsl_touch_info), GFP_KERNEL);
	if (!ddata->ti) {
		ret = -ENOMEM;
		goto error_alloc_mem;
	}

	ddata->client = client;

#ifdef USE_IOCTL
#define I2C_MAJOR   125

	ret = register_chrdev(I2C_MAJOR, "gsl", &gsl_fops);
	if (ret) {
		pr_info("regist chrdev error...\n");
		goto error_regist_input;
	}

	i2c_dev_class = class_create(THIS_MODULE, "gsl");
	if (IS_ERR(i2c_dev_class)) {
		ret = PTR_ERR(i2c_dev_class);
		goto error_regist_input;
	}

	dev = device_create(i2c_dev_class, &client->adapter->dev,
		MKDEV(I2C_MAJOR, client->adapter->nr), NULL,
		"gsl%d", client->adapter->nr);
	if (IS_ERR(dev)) {
		ret = PTR_ERR(dev);
		goto error_regist_input;
	}
#endif

	/* regist a input dev */
	ret = gsl_request_input(ddata);
	if (ret) {
		pr_info("failed to regist input dev!");
		goto error_regist_input;
	}

	/* setup the gpio -- irq & rst */
	ret = gsl_hw_init(ddata);
	if (ret) {
		pr_info("failed to init hw!");
		goto error_init_hw;
	}

	/* setup client data & download fw */
	ret = gsl_sw_init(ddata);
	if (ret) {
		pr_info("failed to init sw!\n");
		goto error_init_sw;
	}

	pr_info("abcd,gsl1680_probe,exit\n");

	return 0;

error_init_sw:
	free_irq(ddata->irq, ddata);
	gpio_free(GSL_IRQ_GPIO);
#ifdef GPIO_RST_USE
	gpio_free(GSL_RST_GPIO);
#endif
error_init_hw:
	input_unregister_device(ddata->idev);
	destroy_workqueue(ddata->wq);
	input_free_device(ddata->idev);
error_regist_input:
	kfree(ddata->ti);
error_alloc_mem:
	kfree(ddata);

	return ret;
}

static int gsl1680_remove(struct i2c_client *client)
{
	struct gsl_ts_data *ddata = i2c_get_clientdata(client);

	free_irq(ddata->irq, ddata);
	gpio_free(GSL_IRQ_GPIO);
#ifdef GPIO_RST_USE
	gpio_free(GSL_RST_GPIO);
#endif
	input_unregister_device(ddata->idev);
	destroy_workqueue(ddata->wq);
	input_free_device(ddata->idev);
	kfree(ddata->ti);
	kfree(ddata);

	return 0;
}

static const struct i2c_device_id gsl1680_idtable[] = {
	[0] = {
		.name = GSL_DEV_NAME,
		.driver_data = 0,
	},
	[1] = {},
};

static struct i2c_driver gsl1680_driver = {
	.driver = {
		.name	= GSL_DEV_NAME,
		.owner	= THIS_MODULE,
	},

	.id_table	= gsl1680_idtable,
	.probe		= gsl1680_probe,
	.remove		= gsl1680_remove,
};

static struct i2c_board_info gsl1680_info = {
	.type = GSL_DEV_NAME,
	.addr = GSL1680_CLIENT_ADDR,
};

static int __init gsl1680_driver_init(void)
{
	int ret;

	ret = i2c_add_driver(&gsl1680_driver);
	if (ret < 0)
		pr_info("i2c_add_driver failed");

	return ret;
}

static void __exit gsl1680_driver_exit(void)
{
	i2c_del_driver(&gsl1680_driver);
}

module_init(gsl1680_driver_init);
module_exit(gsl1680_driver_exit);
