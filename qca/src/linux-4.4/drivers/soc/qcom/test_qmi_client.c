/* Copyright (c) 2013-2014, The Linux Foundation. All rights reserved.
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

#include <linux/module.h>
#include <linux/slab.h>
#include <linux/errno.h>
#include <linux/delay.h>
#include <linux/debugfs.h>
#include <linux/qmi_encdec.h>
#include <linux/types.h>
#include <linux/kthread.h>
#include <linux/list.h>
#include <linux/completion.h>
#include <linux/kernel.h>

#include <asm/uaccess.h>

#include <soc/qcom/msm_qmi_interface.h>

#include "kernel_test_service_v01.h"

#define TEST_SERVICE_SVC_ID 0x0000000f
#define TEST_SERVICE_V1 1
#define TEST_SERVICE_INS_ID 0

// Number of iterations to run during test
static unsigned long iterations = 5;
module_param_named(iterations, iterations, ulong, S_IRUGO | S_IWUSR | S_IWGRP);

// Size of data during "data" command
static unsigned long data_size = 50;
module_param_named(data_size, data_size, ulong, S_IRUGO | S_IWUSR | S_IWGRP);

// Number of cuncurrent Threads running during test
static unsigned long nthreads = 5;
module_param_named(nthreads, nthreads, ulong, S_IRUGO | S_IWUSR | S_IWGRP);

// Enable debug prints
static unsigned long debug_mask;
module_param_named(debug_mask, debug_mask, ulong, S_IRUGO | S_IWUSR | S_IWGRP);

#define D(x...) do { \
	if (debug_mask) \
	pr_debug(x); \
} while (0)

/* Variable to initiate the test through debugfs interface */
static struct dentry *root_dentry;

/* Test client port for IPC Router */
static struct qmi_handle *test_clnt;
static int test_clnt_reset;

/* Reader thread to receive responses & indications */
static void test_clnt_recv_msg(struct work_struct *work);
static DECLARE_DELAYED_WORK(work_recv_msg, test_clnt_recv_msg);
static void test_clnt_svc_arrive(struct work_struct *work);
static DECLARE_DELAYED_WORK(work_svc_arrive, test_clnt_svc_arrive);
static void test_clnt_svc_exit(struct work_struct *work);
static DECLARE_DELAYED_WORK(work_svc_exit, test_clnt_svc_exit);
static struct workqueue_struct *test_clnt_workqueue;

// Completion variable to avoid race between threads and fs write operation
static struct completion qmi_complete;

// List to hold the incoming command from user-space
static struct list_head data_list;

// Data element to be queued during multiple commands
struct test_qmi_data {
	struct list_head list;
	char data[64];
	atomic_t refs_count;
};

/* Variable to hold the test result */
static unsigned long test_res;

// DebugFS directory structure for QMI
static struct qmi_dir {
	char string[16];
	unsigned long *value;
	umode_t mode;
}qdentry[] = {
	{"test", &test_res, S_IRUGO | S_IWUGO},
	{"iterations", &iterations, S_IRUGO | S_IWUGO},
	{"data_size", &data_size, S_IRUGO | S_IWUGO},
	{"nthreads", &nthreads, S_IRUGO | S_IWUGO},
	{"debug_mask", &debug_mask, S_IRUGO | S_IWUGO},
};

static unsigned int callback_count;

static void qmi_data_compare(const char *req, const char  *resp)
{
	if (strcmp(req, resp) == 0){
		pr_err("SUCCESS:\tThread[%s]\tData[%luB]\n", current->comm, data_size);
	} else {
		pr_err("FAILURE:\tThread[%s]\tData[%luB]\n", current->comm, data_size);
	}
}
static void test_async_resp_cb(struct qmi_handle *handle,
		unsigned int msg_id, void *msg,
		void *resp_cb_data, int stat)
{
	callback_count++;
	if (stat == 0) {
		D("%s invoked %d time(s): [RESP_LEN] = %d, [RESP_VALID] = %d",
				__func__, callback_count,
				((struct test_data_resp_msg_v01 *)msg)->data_len,
				((struct test_data_resp_msg_v01 *)msg)->data_valid);
	} else if (stat < 0) {
		D("%s: Request Failed [MSG_ID]: %d, [ERR_ID]: %d, [Callback_count]: %d",
				__func__, msg_id, stat,	callback_count);
	}

	kfree(msg);
	kfree(resp_cb_data);
}

static int test_qmi_ping_pong_send_sync_msg(void)
{
	struct test_ping_req_msg_v01 req;
	struct test_ping_resp_msg_v01 resp;
	struct msg_desc req_desc, resp_desc;
	int rc;

	memcpy(req.ping, "ping", sizeof(req.ping));
	req.client_name_valid = 0;

	req_desc.max_msg_len = TEST_PING_REQ_MAX_MSG_LEN_V01;
	req_desc.msg_id = TEST_PING_REQ_MSG_ID_V01;
	req_desc.ei_array = test_ping_req_msg_v01_ei;

	resp_desc.max_msg_len = TEST_PING_REQ_MAX_MSG_LEN_V01;
	resp_desc.msg_id = TEST_PING_REQ_MSG_ID_V01;
	resp_desc.ei_array = test_ping_resp_msg_v01_ei;

	rc = qmi_send_req_wait(test_clnt, &req_desc, &req, sizeof(req),
			&resp_desc, &resp, sizeof(resp), 0);
	if (rc < 0) {
		pr_err("%s: send req failed %d\n", __func__, rc);
		return rc;
	}

	D("%s: Received %s response\n", __func__, resp.pong);
	return rc;
}

static int test_qmi_data_send_sync_msg(unsigned int data_len)
{
	struct test_data_req_msg_v01 *req;
	struct test_data_resp_msg_v01 *resp;
	struct msg_desc req_desc, resp_desc;
	int rc, i;

	req = kzalloc(sizeof(struct test_data_req_msg_v01), GFP_KERNEL);
	if (!req) {
		pr_err("%s: Data req msg alloc failed\n", __func__);
		return -ENOMEM;
	}

	resp = kzalloc(sizeof(struct test_data_resp_msg_v01), GFP_KERNEL);
	if (!resp) {
		pr_err("%s: Data resp msg alloc failed\n", __func__);
		kfree(req);
		return -ENOMEM;
	}

	req->data_len = data_len;
	for (i = 0; i < data_len; i = i + sizeof(int))
		memcpy(req->data + i, (uint8_t *)&i, sizeof(int));
	req->client_name_valid = 0;

	req_desc.max_msg_len = TEST_DATA_REQ_MAX_MSG_LEN_V01;
	req_desc.msg_id = TEST_DATA_REQ_MSG_ID_V01;
	req_desc.ei_array = test_data_req_msg_v01_ei;

	resp_desc.max_msg_len = TEST_DATA_REQ_MAX_MSG_LEN_V01;
	resp_desc.msg_id = TEST_DATA_REQ_MSG_ID_V01;
	resp_desc.ei_array = test_data_resp_msg_v01_ei;

	rc = qmi_send_req_wait(test_clnt, &req_desc, req, sizeof(*req),
			&resp_desc, resp, sizeof(*resp), 0);
	if (rc < 0) {
		pr_err("%s: send req failed\n", __func__);
		goto data_send_err;
	}

	D("%s: data_valid %d\n", __func__, resp->data_valid);
	D("%s: data_len %d\n", __func__, resp->data_len);

	qmi_data_compare(req->data, resp->data);

data_send_err:
	kfree(resp);
	kfree(req);
	return rc;
}

static int test_qmi_data_send_async_msg(unsigned int data_len)
{
	struct test_data_req_msg_v01 *req;
	struct test_data_resp_msg_v01 *resp;
	struct msg_desc req_desc, *resp_desc;
	int rc, i;

	req = kzalloc(sizeof(struct test_data_req_msg_v01), GFP_KERNEL);
	if (!req) {
		pr_err("%s: Data req msg alloc failed\n", __func__);
		return -ENOMEM;
	}

	resp = kzalloc(sizeof(struct test_data_resp_msg_v01), GFP_KERNEL);
	if (!resp) {
		pr_err("%s: Data resp msg alloc failed\n", __func__);
		kfree(req);
		return -ENOMEM;
	}

	resp_desc = kzalloc(sizeof(struct msg_desc), GFP_KERNEL);
	if (!resp_desc) {
		pr_err("%s: Resp_desc msg alloc failed\n", __func__);
		kfree(req);
		kfree(resp);
		return -ENOMEM;
	}

	req->data_len = data_len;
	for (i = 0; i < data_len; i = i + sizeof(int))
		memcpy(req->data + i, (uint8_t *)&i, sizeof(int));
	req->client_name_valid = 0;

	req_desc.max_msg_len = TEST_DATA_REQ_MAX_MSG_LEN_V01;
	req_desc.msg_id = TEST_DATA_REQ_MSG_ID_V01;
	req_desc.ei_array = test_data_req_msg_v01_ei;

	resp_desc->max_msg_len = TEST_DATA_REQ_MAX_MSG_LEN_V01;
	resp_desc->msg_id = TEST_DATA_REQ_MSG_ID_V01;
	resp_desc->ei_array = test_data_resp_msg_v01_ei;

	rc = qmi_send_req_nowait(test_clnt, &req_desc, req, sizeof(*req),
			resp_desc, resp, sizeof(*resp),
			test_async_resp_cb, (void *)resp_desc);
	if (rc < 0) {
		pr_err("%s: send req failed\n", __func__);
		kfree(resp);
		kfree(resp_desc);
	}
	kfree(req);
	return rc;
}

static void test_clnt_recv_msg(struct work_struct *work)
{
	int rc;

	do {
		D("%s: Notified about a Receive Event", __func__);
	} while ((rc = qmi_recv_msg(test_clnt)) == 0);

	if (rc != -ENOMSG)
		pr_err("%s: Error receiving message\n", __func__);
}

static void test_clnt_notify(struct qmi_handle *handle,
		enum qmi_event_type event, void *notify_priv)
{
	switch (event) {
		case QMI_RECV_MSG:
			queue_delayed_work(test_clnt_workqueue,
					&work_recv_msg, 0);
			break;
		default:
			break;
	}
}

static void test_clnt_svc_arrive(struct work_struct *work)
{
	int rc;

	D("%s begins\n", __func__);

	/* Create a Local client port for QMI communication */
	test_clnt = qmi_handle_create(test_clnt_notify, NULL);
	if (!test_clnt) {
		pr_err("%s: QMI client handle alloc failed\n", __func__);
		return;
	}

	D("%s: Lookup server name\n", __func__);
	rc = qmi_connect_to_service(test_clnt, TEST_SERVICE_SVC_ID,
			TEST_SERVICE_V1,
			TEST_SERVICE_INS_ID);
	if (rc < 0) {
		pr_err("%s: Server not found\n", __func__);
		qmi_handle_destroy(test_clnt);
		test_clnt = NULL;
		return;
	}
	test_clnt_reset = 0;
	D("%s complete\n", __func__);
}

static void test_clnt_svc_exit(struct work_struct *work)
{
	D("%s begins\n", __func__);

	qmi_handle_destroy(test_clnt);
	test_clnt_reset = 1;
	test_clnt = NULL;

	D("%s complete\n", __func__);
}

static int test_clnt_svc_event_notify(struct notifier_block *this,
		unsigned long code,
		void *_cmd)
{
	D("%s: event %ld\n", __func__, code);
	switch (code) {
		case QMI_SERVER_ARRIVE:
			queue_delayed_work(test_clnt_workqueue,
					&work_svc_arrive, 0);
			break;
		case QMI_SERVER_EXIT:
			queue_delayed_work(test_clnt_workqueue,
					&work_svc_exit, 0);
			break;
		default:
			break;
	}
	return 0;
}

int qmi_process_user_input(void *data)
{
	struct test_qmi_data *qmi_data, *temp_qmi_data;
	unsigned short count = iterations;
	unsigned short index = 0;

	wait_for_completion_timeout(&qmi_complete, msecs_to_jiffies(1000));

	list_for_each_entry_safe(qmi_data, temp_qmi_data, &data_list, list) {

		atomic_inc(&qmi_data->refs_count);
		while (count) {
			count --;
			msleep(1000);
		}

		if (!strncmp(qmi_data->data, "ping_pong", sizeof(qmi_data->data))) {
			for (index = 0; index < iterations; index++) {
				test_res = test_qmi_ping_pong_send_sync_msg();
				if (test_res == -ENETRESET || test_clnt_reset) {
					do {
						msleep(50);
					} while (test_clnt_reset);
				}
			}
		} else if (!strncmp(qmi_data->data, "data", sizeof(qmi_data->data))) {
			for (index = 0; index < iterations; index++) {
				test_res = test_qmi_data_send_sync_msg(data_size);
				if (test_res == -ENETRESET || test_clnt_reset) {
					do {
						msleep(50);
					} while (test_clnt_reset);
				}
			}
		} else if (!strncmp(qmi_data->data, "data_async", sizeof(qmi_data->data))) {
			int index;
			callback_count = 0;
			for (index = 0; index < iterations; index++) {
				test_res = test_qmi_data_send_async_msg(data_size);
				if (test_res == -ENETRESET || test_clnt_reset) {
					--index;
					do {
						msleep(50);
					} while (test_clnt_reset);
				} else if (test_res < 0) {
					--index;
					pr_err("%s: Error sending txn, aborting now",
							__func__);
					break;
				}
			}
			while (callback_count < index) {
				if (test_clnt_reset) {
					pr_err("%s: Service Exited", __func__);
					break;
				}
				msleep(50);
			}
			pr_err("%s complete\n", __func__);
			callback_count = 0;
		} else {
			test_res = -EINVAL;
		}

		if (atomic_dec_and_test(&qmi_data->refs_count)) {
			pr_err("deleted qmi_data\n");
			list_del(&qmi_data->list);
			kfree(qmi_data);
			qmi_data = NULL;
		}
	}

	return 0;
}

static int test_qmi_open(struct inode *ip, struct file *fp)
{
	char thread_name[32];
	struct task_struct *qmi_task;
	int index = 0;

	for (index = 1; index < sizeof(qdentry)/sizeof(struct qmi_dir); index++) {
		if (!strncmp(fp->f_path.dentry->d_iname, qdentry[index].string, \
					sizeof(fp->f_path.dentry->d_iname)))
			return 0;
	}

	if (!test_clnt) {
		pr_err("%s Test client is not initialized\n", __func__);
		return -ENODEV;

	}
	init_completion(&qmi_complete);
	for (index = 0; index < nthreads; index++) {
		snprintf(thread_name, sizeof(thread_name), "qmi_test_""%d", index);
		qmi_task = kthread_run(qmi_process_user_input, &data_list, thread_name);
	}
	return 0;
}

static ssize_t test_qmi_read(struct file *fp, char __user *buf,
		size_t count, loff_t *pos)
{
	char _buf[16] = {0};
	int index = 0;

	for (index = 0; index < sizeof(qdentry)/sizeof(struct qmi_dir); index++) {
		if (!strncmp(fp->f_path.dentry->d_iname, qdentry[index].string, \
					sizeof(fp->f_path.dentry->d_iname)))
			snprintf(_buf, sizeof(_buf), "%lu\n", *qdentry[index].value);
	}

	return simple_read_from_buffer(buf, count, pos, _buf, strnlen(_buf, 16));
}

static int test_qmi_release(struct inode *ip, struct file *fp)
{
	return 0;
}

static ssize_t test_qmi_write(struct file *fp, const char __user *buf,
		size_t count, loff_t *pos)
{
	unsigned char cmd[64];
	int len;
	int index = 0;
	struct test_qmi_data *qmi_data;

	if (count < 1)
		return 0;

	len = min(count, (sizeof(cmd) - 1));

	if (copy_from_user(cmd, buf, len))
		return -EFAULT;

	cmd[len] = 0;
	if (cmd[len-1] == '\n') {
		cmd[len-1] = 0;
		len--;
	}

	for (index = 1; index < sizeof(qdentry)/sizeof(struct qmi_dir); index++) {
		if (!strncmp(fp->f_path.dentry->d_iname, qdentry[index].string, \
					sizeof(fp->f_path.dentry->d_iname))) {
			kstrtoul(cmd, 0, qdentry[index].value);
			return count;
		}
	}

	qmi_data = kmalloc(sizeof(struct test_qmi_data), GFP_KERNEL);
	if (!qmi_data) {
		pr_err("Unable to allocate memory for qmi_data\n");
		return -ENOMEM;
	}

	memcpy(qmi_data->data, cmd, sizeof(cmd));

	atomic_set(&qmi_data->refs_count, 0);
	list_add_tail(&qmi_data->list, &data_list);
	complete_all(&qmi_complete);

	return count;
}

static struct notifier_block test_clnt_nb = {
	.notifier_call = test_clnt_svc_event_notify,
};

static const struct file_operations debug_ops = {
	.owner = THIS_MODULE,
	.open = test_qmi_open,
	.read = test_qmi_read,
	.write = test_qmi_write,
	.release = test_qmi_release,
};

static int __init test_qmi_init(void)
{
	int rc, index = 0;
	struct dentry *ret;

	test_clnt_workqueue = create_singlethread_workqueue("test_clnt");
	if (!test_clnt_workqueue)
		return -EFAULT;

	rc = qmi_svc_event_notifier_register(TEST_SERVICE_SVC_ID,
			TEST_SERVICE_V1, TEST_SERVICE_INS_ID,
			&test_clnt_nb);
	if (rc < 0) {
		pr_err("%s: notifier register failed\n", __func__);
		destroy_workqueue(test_clnt_workqueue);
		return rc;
	}

	root_dentry = debugfs_create_dir("qmi_test", NULL);
	if (IS_ERR(root_dentry)) {
		pr_err("%s: unable to create debugfs %d\n",
				__func__, IS_ERR(root_dentry));
		ret = root_dentry;
		goto root_dentry_failed;
	}

	for (index = 0; index < sizeof(qdentry)/sizeof(struct qmi_dir); index++) {
		ret = debugfs_create_file(qdentry[index].string, qdentry[index].mode, root_dentry,
				NULL, &debug_ops);
		if (IS_ERR(ret)) {
			pr_err("Failed to create debugfs entry for %s\n",
					qdentry[index].string);
			goto sub_dentry_failed;
		}
	}

	INIT_LIST_HEAD(&data_list);

	return 0;

sub_dentry_failed:
	debugfs_remove_recursive(root_dentry);
root_dentry_failed:
	root_dentry = NULL;
	qmi_svc_event_notifier_unregister(TEST_SERVICE_SVC_ID,
			TEST_SERVICE_V1, TEST_SERVICE_INS_ID,
			&test_clnt_nb);
	destroy_workqueue(test_clnt_workqueue);
	return PTR_ERR(ret);

}

static void __exit test_qmi_exit(void)
{
	struct test_qmi_data *qmi_data, *temp_qmi_data;

	qmi_svc_event_notifier_unregister(TEST_SERVICE_SVC_ID,
			TEST_SERVICE_V1,
			TEST_SERVICE_INS_ID, &test_clnt_nb);
	destroy_workqueue(test_clnt_workqueue);
	debugfs_remove_recursive(root_dentry);

	list_for_each_entry_safe(qmi_data, temp_qmi_data, &data_list, list) {
		list_del(&qmi_data->list);
		kfree(qmi_data);
	}
	list_del(&data_list);
}

module_init(test_qmi_init);
module_exit(test_qmi_exit);

MODULE_DESCRIPTION("TEST QMI Client Driver");
MODULE_LICENSE("GPL v2");
