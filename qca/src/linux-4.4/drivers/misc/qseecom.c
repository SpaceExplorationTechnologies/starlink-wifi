/* QTI Secure Execution Environment Communicator (QSEECOM) driver
 *
 * Copyright (c) 2012, 2015, 2017-2018 The Linux Foundation. All rights reserved.
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

/* Refer to Documentation/qseecom.txt for detailed usage instructions.
 */

#include "qseecom.h"

static int unload_app_libs(void)
{
	struct qseecom_unload_ireq req;
	struct qseecom_command_scm_resp resp;
	int ret = 0;
	uint32_t cmd_id = 0;
	uint32_t smc_id = 0;

	cmd_id = QSEE_UNLOAD_SERV_IMAGE_COMMAND;

	smc_id = TZ_SYSCALL_CREATE_SMC_ID(TZ_OWNER_QSEE_OS, TZ_SVC_APP_MGR,
					 TZ_ARMv8_CMD_UNLOAD_LIB);

	/* SCM_CALL to unload the app */
	ret = qcom_scm_qseecom_unload(smc_id, cmd_id, &req, sizeof(uint32_t),
				     &resp, sizeof(resp));

	if (ret) {
		pr_err("\nscm_call to unload app libs failed, ret val = %d",
		      ret);
		return ret;
	}

	pr_info("\nApp libs unloaded successfully");

	return 0;
}

static int tzdbg_register_qsee_log_buf(struct device *dev)
{
	uint64_t len = 0;
	int ret = 0;
	void *buf = NULL;
	struct qsee_reg_log_buf_req req;
	struct qseecom_command_scm_resp resp;
	dma_addr_t dma_log_buf = 0;

	len = QSEE_LOG_BUF_SIZE;
	buf = dma_alloc_coherent(dev, len, &dma_log_buf, GFP_KERNEL);
	if (buf == NULL) {
		pr_err("Failed to alloc memory for size %llu\n", len);
		return -ENOMEM;
	}
	g_qsee_log = (struct tzdbg_log_t *)buf;

	req.phy_addr = dma_log_buf;
	req.len = len;

	ret = qcom_scm_tz_register_log_buf(dev, &req, sizeof(req),
					  &resp, sizeof(resp));

	if (ret) {
		pr_err("\nSCM Call failed..SCM Call return value = %d\n", ret);
		dma_free_coherent(dev, len, (void *)g_qsee_log, dma_log_buf);
		return ret;
	}

	if (resp.result) {
		ret = resp.result;
		pr_err("\nResponse status failure..return value = %d\n", ret);
		dma_free_coherent(dev, len, (void *)g_qsee_log, dma_log_buf);
		return ret;
	}

	return 0;
}

static ssize_t
show_qsee_app_log_buf(struct device *dev, struct device_attribute *attr,
		     char *buf)
{
	ssize_t count = 0;

	if (app_state) {
		if (g_qsee_log->log_pos.wrap != 0) {
			memcpy(buf, g_qsee_log->log_buf +
			      g_qsee_log->log_pos.offset, QSEE_LOG_BUF_SIZE -
			      g_qsee_log->log_pos.offset - 64);
			count = QSEE_LOG_BUF_SIZE -
				g_qsee_log->log_pos.offset - 64;
			memcpy(buf + count, g_qsee_log->log_buf,
			      g_qsee_log->log_pos.offset);
			count = count + g_qsee_log->log_pos.offset;
		} else {
			memcpy(buf, g_qsee_log->log_buf,
			      g_qsee_log->log_pos.offset);
			count = g_qsee_log->log_pos.offset;
		}
	} else {
		pr_err("load app and then view log..\n");
		return -EINVAL;
	}

	return count;
}

static ssize_t
generate_key_blob(struct device *dev, struct device_attribute *attr, char *buf)
{
	int rc = 0;
	struct scm_cmd_buf_t scm_cmd_buf;
	struct tz_storage_service_gen_key_cmd_t *req_ptr = NULL;
	struct tz_storage_service_gen_key_resp_t *resp_ptr = NULL;
	size_t req_size = 0;
	size_t resp_size = 0;
	size_t req_order = 0;
	size_t resp_order = 0;
	dma_addr_t dma_req_addr = 0;
	dma_addr_t dma_resp_addr = 0;
	dma_addr_t dma_key_blob = 0;
	struct page *req_page = NULL;
	struct page *resp_page = NULL;

	key_blob = memset(key_blob, 0, KEY_BLOB_SIZE);
	key_blob_len = 0;

	dev = qdev;

	req_size = sizeof(struct tz_storage_service_gen_key_cmd_t);
	req_order = get_order(req_size);
	req_page = alloc_pages(GFP_KERNEL, req_order);

	if (req_page)
		req_ptr = page_address(req_page);
	else
		return -ENOMEM;

	resp_size = sizeof(struct tz_storage_service_gen_key_resp_t);
	resp_order = get_order(resp_size);
	resp_page = alloc_pages(GFP_KERNEL, resp_order);

	if (resp_page) {
		resp_ptr = page_address(resp_page);
	} else {
		pr_err("\nCannot allocate memory for key material\n");
		free_pages((unsigned long)req_ptr, req_order);
		return -ENOMEM;
	}

	dma_key_blob = dma_map_single(dev, key_blob, KEY_BLOB_SIZE,
				     DMA_FROM_DEVICE);
	rc = dma_mapping_error(dev, dma_key_blob);
	if (rc) {
		pr_err("DMA Mapping Error(key blob)\n");
		goto err_end;
	}

	req_ptr->cmd_id = TZ_STOR_SVC_GENERATE_KEY;
	req_ptr->key_blob.key_material = (uint8_t *)dma_key_blob;
	req_ptr->key_blob.key_material_len = KEY_BLOB_SIZE;

	dma_req_addr = dma_map_single(dev, req_ptr, req_size, DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_req_addr);
	if (rc) {
		pr_err("DMA Mapping Error(request str)\n");
		goto err_map_req;
	}

	dma_resp_addr = dma_map_single(dev, resp_ptr, resp_size,
				      DMA_FROM_DEVICE);
	rc = dma_mapping_error(dev, dma_resp_addr);
	if (rc) {
		pr_err("DMA Mapping Error(response str)\n");
		goto err_map_resp;
	}

	scm_cmd_buf.req_size = req_size;
	scm_cmd_buf.req_addr = dma_req_addr;
	scm_cmd_buf.resp_size = resp_size;
	scm_cmd_buf.resp_addr = dma_resp_addr;

	rc = qcom_scm_tls_hardening(&scm_cmd_buf, sizeof(scm_cmd_buf),
				   CLIENT_CMD_CRYPTO_AES);

	dma_unmap_single(dev, dma_resp_addr, resp_size, DMA_FROM_DEVICE);
	dma_unmap_single(dev, dma_req_addr, req_size, DMA_TO_DEVICE);
	dma_unmap_single(dev, dma_key_blob, KEY_BLOB_SIZE, DMA_FROM_DEVICE);

	if (rc) {
		pr_err("\nSCM Call failed..SCM Call return value = %d\n", rc);
		goto err_end;
	}

	if (resp_ptr->status) {
		rc = resp_ptr->status;
		pr_err("\nResponse status failure..return value = %d\n", rc);
		goto err_end;
	}

	key_blob_len = resp_ptr->key_blob_size;
	memcpy(buf, key_blob, key_blob_len);

	goto end;

err_map_resp:
	dma_unmap_single(dev, dma_req_addr, req_size, DMA_TO_DEVICE);

err_map_req:
	dma_unmap_single(dev, dma_key_blob, KEY_BLOB_SIZE, DMA_FROM_DEVICE);

err_end:
	free_pages((unsigned long)page_address(req_page), req_order);
	free_pages((unsigned long)page_address(resp_page), resp_order);

	return rc;

end:
	free_pages((unsigned long)page_address(req_page), req_order);
	free_pages((unsigned long)page_address(resp_page), resp_order);

	return key_blob_len;
}

static ssize_t
store_key(struct device *dev, struct device_attribute *attr,
	 const char *buf, size_t count)
{
	key = memset(key, 0, KEY_SIZE);
	key_len = 0;

	if (count != KEY_SIZE) {
		pr_info("\nInvalid input\n");
		pr_info("Key length is %lu bytes\n", (unsigned long)count);
		pr_info("Key length must be %u bytes\n", KEY_SIZE);
		return -EINVAL;
	}

	key_len = count;
	memcpy(key, buf, key_len);

	return count;
}

static ssize_t
import_key_blob(struct device *dev, struct device_attribute *attr, char *buf)
{
	int rc = 0;
	struct scm_cmd_buf_t scm_cmd_buf;
	struct tz_storage_service_import_key_cmd_t *req_ptr = NULL;
	struct tz_storage_service_gen_key_resp_t *resp_ptr = NULL;
	size_t req_size = 0;
	size_t resp_size = 0;
	size_t req_order = 0;
	size_t resp_order = 0;
	dma_addr_t dma_req_addr = 0;
	dma_addr_t dma_resp_addr = 0;
	dma_addr_t dma_key_blob = 0;
	dma_addr_t dma_key = 0;
	struct page *req_page = NULL;
	struct page *resp_page = NULL;

	key_blob = memset(key_blob, 0, KEY_BLOB_SIZE);
	key_blob_len = 0;

	if (key_len == 0) {
		pr_err("\nPlease provide key to import key blob\n");
		return -EINVAL;
	}

	dev = qdev;

	req_size = sizeof(struct tz_storage_service_import_key_cmd_t);
	req_order = get_order(req_size);
	req_page = alloc_pages(GFP_KERNEL, req_order);

	if (req_page)
		req_ptr = page_address(req_page);
	else
		return -ENOMEM;

	resp_size = sizeof(struct tz_storage_service_gen_key_resp_t);
	resp_order = get_order(resp_size);
	resp_page = alloc_pages(GFP_KERNEL, resp_order);

	if (resp_page) {
		resp_ptr = page_address(resp_page);
	} else {
		pr_err("\nCannot allocate memory for key material\n");
		free_pages((unsigned long)req_ptr, req_order);
		return -ENOMEM;
	}

	dma_key = dma_map_single(dev, key, KEY_SIZE, DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_key);
	if (rc) {
		pr_err("DMA Mapping error(key)\n");
		goto err_end;
	}

	dma_key_blob = dma_map_single(dev, key_blob, KEY_BLOB_SIZE,
				     DMA_FROM_DEVICE);
	rc = dma_mapping_error(dev, dma_key_blob);
	if (rc) {
		pr_err("DMA Mapping Error(key blob)\n");
		goto err_map_key_blob;
	}

	req_ptr->cmd_id = TZ_STOR_SVC_IMPORT_KEY;
	req_ptr->input_key = (uint8_t *)dma_key;
	req_ptr->input_key_len = KEY_SIZE;
	req_ptr->key_blob.key_material = (uint8_t *)dma_key_blob;
	req_ptr->key_blob.key_material_len = KEY_BLOB_SIZE;

	dma_req_addr = dma_map_single(dev, req_ptr, req_size, DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_req_addr);
	if (rc) {
		pr_err("DMA Mapping Error(request str)\n");
		goto err_map_req;
	}
	dma_resp_addr = dma_map_single(dev, resp_ptr, resp_size,
				      DMA_FROM_DEVICE);
	rc = dma_mapping_error(dev, dma_resp_addr);
	if (rc) {
		pr_err("DMA Mapping Error(response str)\n");
		goto err_map_resp;
	}

	scm_cmd_buf.req_size = req_size;
	scm_cmd_buf.req_addr = dma_req_addr;
	scm_cmd_buf.resp_size = resp_size;
	scm_cmd_buf.resp_addr = dma_resp_addr;

	rc = qcom_scm_tls_hardening(&scm_cmd_buf, sizeof(scm_cmd_buf),
				   CLIENT_CMD_CRYPTO_AES);

	dma_unmap_single(dev, dma_resp_addr, resp_size, DMA_FROM_DEVICE);
	dma_unmap_single(dev, dma_req_addr, req_size, DMA_TO_DEVICE);
	dma_unmap_single(dev, dma_key_blob, KEY_BLOB_SIZE, DMA_FROM_DEVICE);
	dma_unmap_single(dev, dma_key, KEY_SIZE, DMA_TO_DEVICE);

	if (rc) {
		pr_err("\nSCM Call failed..SCM Call return value = %d\n", rc);
		goto err_end;
	}

	if (resp_ptr->status) {
		rc = resp_ptr->status;
		pr_err("\nResponse status failure..return value = %d\n", rc);
		goto err_end;
	}

	key_blob_len = resp_ptr->key_blob_size;
	memcpy(buf, key_blob, key_blob_len);

	goto end;

err_map_resp:
	dma_unmap_single(dev, dma_req_addr, req_size, DMA_TO_DEVICE);

err_map_req:
	dma_unmap_single(dev, dma_key_blob, KEY_BLOB_SIZE, DMA_FROM_DEVICE);

err_map_key_blob:
	dma_unmap_single(dev, dma_key, KEY_SIZE, DMA_TO_DEVICE);

err_end:
	free_pages((unsigned long)page_address(req_page), req_order);
	free_pages((unsigned long)page_address(resp_page), resp_order);

	return rc;

end:
	free_pages((unsigned long)page_address(req_page), req_order);
	free_pages((unsigned long)page_address(resp_page), resp_order);

	return key_blob_len;
}

static ssize_t
store_key_blob(struct device *dev, struct device_attribute *attr,
	      const char *buf, size_t count)
{
	key_blob = memset(key_blob, 0, KEY_BLOB_SIZE);
	key_blob_len = 0;

	if (count != KEY_BLOB_SIZE) {
		pr_info("\nInvalid input\n");
		pr_info("Key blob length is %lu bytes\n", (unsigned long)count);
		pr_info("Key blob length must be %u bytes\n", KEY_BLOB_SIZE);
		return -EINVAL;
	}

	key_blob_len = count;
	memcpy(key_blob, buf, key_blob_len);

	return count;
}

static ssize_t
store_unsealed_data(struct device *dev, struct device_attribute *attr,
		   const char *buf, size_t count)
{
	unsealed_buf = memset(unsealed_buf, 0, MAX_PLAIN_DATA_SIZE);
	unseal_len = 0;

	if (count == 0 || count > MAX_PLAIN_DATA_SIZE) {
		pr_info("\nInvalid input\n");
		pr_info("Plain data length is %lu bytes\n",
		       (unsigned long)count);
		pr_info("Plain data length must be > 0 bytes and <= %u bytes\n",
		       MAX_PLAIN_DATA_SIZE);
		return -EINVAL;
	}

	unseal_len = count;
	memcpy(unsealed_buf, buf, unseal_len);

	return count;
}

static ssize_t
show_sealed_data(struct device *dev, struct device_attribute *attr, char *buf)
{
	int rc = 0;
	struct scm_cmd_buf_t scm_cmd_buf;
	struct tz_storage_service_seal_data_cmd_t *req_ptr = NULL;
	struct tz_storage_service_seal_data_resp_t *resp_ptr = NULL;
	size_t req_size = 0;
	size_t resp_size = 0;
	size_t req_order = 0;
	size_t resp_order = 0;
	size_t output_len = 0;
	dma_addr_t dma_req_addr = 0;
	dma_addr_t dma_resp_addr = 0;
	dma_addr_t dma_key_blob = 0;
	dma_addr_t dma_plain_data = 0;
	dma_addr_t dma_output_data = 0;
	struct page *req_page = NULL;
	struct page *resp_page = NULL;

	sealed_buf = memset(sealed_buf, 0, MAX_ENCRYPTED_DATA_SIZE);
	output_len = unseal_len + ENCRYPTED_DATA_HEADER;

	if (key_blob_len == 0 || unseal_len == 0) {
		pr_err("\nInvalid input\n");
		pr_info("Need keyblob and plain data for encryption\n");
		return -EINVAL;
	}

	dev = qdev;

	req_size = sizeof(struct tz_storage_service_seal_data_cmd_t);
	req_order = get_order(req_size);
	req_page = alloc_pages(GFP_KERNEL, req_order);

	if (req_page)
		req_ptr = page_address(req_page);
	else
		return -ENOMEM;

	resp_size = sizeof(struct tz_storage_service_seal_data_resp_t);
	resp_order = get_order(resp_size);
	resp_page = alloc_pages(GFP_KERNEL, resp_order);

	if (resp_page) {
		resp_ptr = page_address(resp_page);
	} else {
		pr_err("\nCannot allocate memory for key material\n");
		free_pages((unsigned long)req_ptr, req_order);
		return -ENOMEM;
	}

	dma_key_blob = dma_map_single(dev, key_blob, KEY_BLOB_SIZE,
				     DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_key_blob);
	if (rc) {
		pr_err("DMA Mapping Error(key blob)\n");
		goto err_end;
	}

	dma_plain_data = dma_map_single(dev, unsealed_buf, unseal_len,
				       DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_plain_data);
	if (rc) {
		pr_err("DMA Mapping Error(plain data)\n");
		goto err_map_plain_data;
	}

	dma_output_data = dma_map_single(dev, sealed_buf, output_len,
					DMA_FROM_DEVICE);
	rc = dma_mapping_error(dev, dma_output_data);
	if (rc) {
		pr_err("DMA Mapping Error(output data)\n");
		goto err_map_output_data;
	}

	req_ptr->cmd_id = TZ_STOR_SVC_SEAL_DATA;
	req_ptr->key_blob.key_material = (uint8_t *)dma_key_blob;
	req_ptr->key_blob.key_material_len = KEY_BLOB_SIZE;
	req_ptr->plain_data = (uint8_t *)dma_plain_data;
	req_ptr->plain_data_len = unseal_len;
	req_ptr->output_buffer = (uint8_t *)dma_output_data;
	req_ptr->output_len = output_len;

	dma_req_addr = dma_map_single(dev, req_ptr, req_size, DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_req_addr);
	if (rc) {
		pr_err("DMA Mapping Error(request str)\n");
		goto err_map_req;
	}

	dma_resp_addr = dma_map_single(dev, resp_ptr, resp_size,
				      DMA_FROM_DEVICE);
	rc = dma_mapping_error(dev, dma_resp_addr);
	if (rc) {
		pr_err("DMA Mapping Error(response str)\n");
		goto err_map_resp;
	}

	scm_cmd_buf.req_size = req_size;
	scm_cmd_buf.req_addr = dma_req_addr;
	scm_cmd_buf.resp_size = resp_size;
	scm_cmd_buf.resp_addr = dma_resp_addr;

	rc = qcom_scm_tls_hardening(&scm_cmd_buf, sizeof(scm_cmd_buf),
				   CLIENT_CMD_CRYPTO_AES);

	dma_unmap_single(dev, dma_resp_addr, resp_size, DMA_FROM_DEVICE);
	dma_unmap_single(dev, dma_req_addr, req_size, DMA_TO_DEVICE);
	dma_unmap_single(dev, dma_output_data, output_len, DMA_FROM_DEVICE);
	dma_unmap_single(dev, dma_plain_data, unseal_len, DMA_TO_DEVICE);
	dma_unmap_single(dev, dma_key_blob, KEY_BLOB_SIZE, DMA_TO_DEVICE);

	if (rc) {
		pr_err("\nSCM Call failed..SCM Call return value = %d\n", rc);
		goto err_end;
	}

	if (resp_ptr->status != 0) {
		rc = resp_ptr->status;
		pr_err("\nResponse status failure..return value = %d\n", rc);
		goto err_end;
	}

	seal_len = resp_ptr->sealed_data_len;
	memcpy(buf, sealed_buf, seal_len);

	goto end;

err_map_resp:
	dma_unmap_single(dev, dma_req_addr, req_size, DMA_TO_DEVICE);

err_map_req:
	dma_unmap_single(dev, dma_output_data, output_len, DMA_FROM_DEVICE);

err_map_output_data:
	dma_unmap_single(dev, dma_plain_data, unseal_len, DMA_TO_DEVICE);

err_map_plain_data:
	dma_unmap_single(dev, dma_key_blob, KEY_BLOB_SIZE, DMA_TO_DEVICE);

err_end:
	free_pages((unsigned long)page_address(req_page), req_order);
	free_pages((unsigned long)page_address(resp_page), resp_order);

	return rc;

end:
	free_pages((unsigned long)page_address(req_page), req_order);
	free_pages((unsigned long)page_address(resp_page), resp_order);

	return seal_len;
}

static ssize_t
store_sealed_data(struct device *dev, struct device_attribute *attr,
		 const char *buf, size_t count)
{
	sealed_buf = memset(sealed_buf, 0, MAX_ENCRYPTED_DATA_SIZE);
	seal_len = 0;

	if (count == 0 || count > MAX_ENCRYPTED_DATA_SIZE) {
		pr_info("\nInvalid input\n");
		pr_info("Encrypted data length is %lu bytes\n",
		       (unsigned long)count);
		pr_info("Encrypted data length must be > 0 bytes and <= %u bytes\n",
		       MAX_ENCRYPTED_DATA_SIZE);
		return -EINVAL;
	}

	seal_len = count;
	memcpy(sealed_buf, buf, seal_len);

	return count;
}

static ssize_t
show_unsealed_data(struct device *dev, struct device_attribute *attr, char *buf)
{
	int rc = 0;
	struct scm_cmd_buf_t scm_cmd_buf;
	struct tz_storage_service_unseal_data_cmd_t *req_ptr = NULL;
	struct tz_storage_service_unseal_data_resp_t *resp_ptr = NULL;
	size_t req_size = 0;
	size_t resp_size = 0;
	size_t req_order = 0;
	size_t resp_order = 0;
	size_t output_len = 0;
	dma_addr_t dma_req_addr = 0;
	dma_addr_t dma_resp_addr = 0;
	dma_addr_t dma_key_blob = 0;
	dma_addr_t dma_sealed_data = 0;
	dma_addr_t dma_output_data = 0;
	struct page *req_page = NULL;
	struct page *resp_page = NULL;

	unsealed_buf = memset(unsealed_buf, 0, MAX_PLAIN_DATA_SIZE);
	output_len = seal_len - ENCRYPTED_DATA_HEADER;

	if (key_blob_len == 0 || seal_len == 0) {
		pr_err("\nInvalid input\n");
		pr_info("Need key and sealed data for decryption\n");
		return -EINVAL;
	}

	dev = qdev;

	req_size = sizeof(struct tz_storage_service_unseal_data_cmd_t);
	req_order = get_order(req_size);
	req_page = alloc_pages(GFP_KERNEL, req_order);

	if (req_page)
		req_ptr = page_address(req_page);
	else
		return -ENOMEM;

	resp_size = sizeof(struct tz_storage_service_unseal_data_resp_t);
	resp_order = get_order(resp_size);
	resp_page = alloc_pages(GFP_KERNEL, resp_order);

	if (resp_page) {
		resp_ptr = page_address(resp_page);
	} else {
		pr_err("\nCannot allocate memory for key material\n");
		free_pages((unsigned long)req_ptr, req_order);
		return -ENOMEM;
	}

	dma_key_blob = dma_map_single(dev, key_blob, KEY_BLOB_SIZE,
				     DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_key_blob);
	if (rc) {
		pr_err("DMA Mapping Error(key blob)\n");
		goto err_end;
	}

	dma_sealed_data = dma_map_single(dev, sealed_buf, seal_len,
					DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_sealed_data);
	if (rc) {
		pr_err("DMA Mapping Error(sealed data)\n");
		goto err_map_sealed_data;
	}

	dma_output_data = dma_map_single(dev, unsealed_buf, output_len,
					DMA_FROM_DEVICE);
	rc = dma_mapping_error(dev, dma_output_data);
	if (rc) {
		pr_err("DMA Mapping Error(output data)\n");
		goto err_map_output_data;
	}

	req_ptr->cmd_id = TZ_STOR_SVC_UNSEAL_DATA;
	req_ptr->key_blob.key_material = (uint8_t *)dma_key_blob;
	req_ptr->key_blob.key_material_len = KEY_BLOB_SIZE;
	req_ptr->sealed_data = (uint8_t *)dma_sealed_data;
	req_ptr->sealed_dlen = seal_len;
	req_ptr->output_buffer = (uint8_t *)dma_output_data;
	req_ptr->output_len = output_len;

	dma_req_addr = dma_map_single(dev, req_ptr, req_size, DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_req_addr);
	if (rc) {
		pr_err("DMA Mapping Error(request str)\n");
		goto err_map_req;
	}

	dma_resp_addr = dma_map_single(dev, resp_ptr, resp_size,
				      DMA_FROM_DEVICE);
	rc = dma_mapping_error(dev, dma_resp_addr);
	if (rc) {
		pr_err("DMA Mapping Error(response str)\n");
		goto err_map_resp;
	}

	scm_cmd_buf.req_size = req_size;
	scm_cmd_buf.req_addr = dma_req_addr;
	scm_cmd_buf.resp_size = resp_size;
	scm_cmd_buf.resp_addr = dma_resp_addr;

	rc = qcom_scm_tls_hardening(&scm_cmd_buf, sizeof(scm_cmd_buf),
				   CLIENT_CMD_CRYPTO_AES);

	dma_unmap_single(dev, dma_resp_addr, resp_size, DMA_FROM_DEVICE);
	dma_unmap_single(dev, dma_req_addr, req_size, DMA_TO_DEVICE);
	dma_unmap_single(dev, dma_output_data, output_len, DMA_FROM_DEVICE);
	dma_unmap_single(dev, dma_sealed_data, seal_len, DMA_TO_DEVICE);
	dma_unmap_single(dev, dma_key_blob, KEY_BLOB_SIZE, DMA_TO_DEVICE);

	if (rc) {
		pr_err("\nSCM Call failed..SCM Call return value = %d\n", rc);
		goto err_end;
	}

	if (resp_ptr->status != 0) {
		rc = resp_ptr->status;
		pr_err("\nResponse status failure..return value = %d\n", rc);
		goto err_end;
	}

	unseal_len = resp_ptr->unsealed_data_len;
	memcpy(buf, unsealed_buf, unseal_len);

	goto end;

err_map_resp:
	dma_unmap_single(dev, dma_req_addr, req_size, DMA_TO_DEVICE);

err_map_req:
	dma_unmap_single(dev, dma_output_data, output_len, DMA_FROM_DEVICE);

err_map_output_data:
	dma_unmap_single(dev, dma_sealed_data, seal_len, DMA_TO_DEVICE);

err_map_sealed_data:
	dma_unmap_single(dev, dma_key_blob, KEY_BLOB_SIZE, DMA_TO_DEVICE);

err_end:
	free_pages((unsigned long)page_address(req_page), req_order);
	free_pages((unsigned long)page_address(resp_page), resp_order);

	return rc;

end:
	free_pages((unsigned long)page_address(req_page), req_order);
	free_pages((unsigned long)page_address(resp_page), resp_order);

	return unseal_len;
}

static ssize_t
generate_rsa_key_blob(struct device *dev, struct device_attribute *attr,
		     char *buf)
{
	int rc = 0;
	struct scm_cmd_buf_t scm_cmd_buf;
	struct tz_storage_service_rsa_gen_key_cmd_t *req_ptr = NULL;
	struct tz_storage_service_rsa_gen_key_resp_t *resp_ptr = NULL;
	size_t req_size = 0;
	size_t resp_size = 0;
	size_t req_order = 0;
	size_t resp_order = 0;
	dma_addr_t dma_req_addr = 0;
	dma_addr_t dma_resp_addr = 0;
	dma_addr_t dma_key_blob = 0;
	struct page *req_page = NULL;
	struct page *resp_page = NULL;

	rsa_key_blob = memset(rsa_key_blob, 0, RSA_KEY_BLOB_SIZE);
	rsa_key_blob_len = 0;

	dev = qdev;

	req_size = sizeof(struct tz_storage_service_rsa_gen_key_cmd_t);
	req_order = get_order(req_size);
	req_page = alloc_pages(GFP_KERNEL, req_order);

	if (req_page)
		req_ptr = page_address(req_page);
	else
		return -ENOMEM;

	resp_size = sizeof(struct tz_storage_service_rsa_gen_key_resp_t);
	resp_order = get_order(resp_size);
	resp_page = alloc_pages(GFP_KERNEL, resp_order);

	if (resp_page) {
		resp_ptr = page_address(resp_page);
	} else {
		pr_err("\nCannot allocate memory for key material\n");
		free_pages((unsigned long)req_ptr, req_order);
		return -ENOMEM;
	}

	dma_key_blob = dma_map_single(dev, rsa_key_blob, RSA_KEY_BLOB_SIZE,
				     DMA_FROM_DEVICE);
	rc = dma_mapping_error(dev, dma_key_blob);
	if (rc) {
		pr_err("DMA Mapping Error(rsa key blob)\n");
		goto err_end;
	}

	req_ptr->cmd_id = TZ_STOR_SVC_RSA_GENERATE_KEY;
	req_ptr->rsa_params.modulus_size = RSA_MODULUS_LEN;
	req_ptr->rsa_params.public_exponent = RSA_PUBLIC_EXPONENT;
	req_ptr->rsa_params.pad_algo =
				TZ_STOR_SVC_RSA_DIGEST_PAD_PKCS115_SHA2_256;
	req_ptr->key_blob.key_material =
			(struct tz_storage_service_rsa_key_t *)dma_key_blob;
	req_ptr->key_blob.key_material_len = RSA_KEY_BLOB_SIZE;

	dma_req_addr = dma_map_single(dev, req_ptr, req_size, DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_req_addr);
	if (rc) {
		pr_err("DMA Mapping Error(request str)\n");
		goto err_map_req;
	}

	dma_resp_addr = dma_map_single(dev, resp_ptr, resp_size,
				      DMA_FROM_DEVICE);
	rc = dma_mapping_error(dev, dma_resp_addr);
	if (rc) {
		pr_err("DMA Mapping Error(response str)\n");
		goto err_map_resp;
	}

	scm_cmd_buf.req_size = req_size;
	scm_cmd_buf.req_addr = dma_req_addr;
	scm_cmd_buf.resp_size = resp_size;
	scm_cmd_buf.resp_addr = dma_resp_addr;

	rc = qcom_scm_tls_hardening(&scm_cmd_buf, sizeof(scm_cmd_buf),
				   CLIENT_CMD_CRYPTO_RSA);

	dma_unmap_single(dev, dma_resp_addr, resp_size, DMA_FROM_DEVICE);
	dma_unmap_single(dev, dma_req_addr, req_size, DMA_TO_DEVICE);
	dma_unmap_single(dev, dma_key_blob,
			RSA_KEY_BLOB_SIZE, DMA_FROM_DEVICE);

	if (rc) {
		pr_err("SCM call failed..SCM Call return value = %d\n", rc);
		goto err_end;
	}

	if (resp_ptr->status) {
		rc = resp_ptr->status;
		pr_err("Response status failure..return value = %d\n", rc);
		goto err_end;
	}

	rsa_key_blob_len = resp_ptr->key_blob_size;
	memcpy(buf, rsa_key_blob, rsa_key_blob_len);

	goto end;

err_map_resp:
	dma_unmap_single(dev, dma_req_addr, req_size, DMA_TO_DEVICE);

err_map_req:
	dma_unmap_single(dev, dma_key_blob, RSA_KEY_BLOB_SIZE,
			DMA_FROM_DEVICE);

err_end:
	free_pages((unsigned long)page_address(req_page), req_order);
	free_pages((unsigned long)page_address(resp_page), resp_order);

	return rc;

end:
	free_pages((unsigned long)page_address(req_page), req_order);
	free_pages((unsigned long)page_address(resp_page), resp_order);

	return rsa_key_blob_len;
}

static ssize_t
store_rsa_key(struct device *dev, struct device_attribute *attr,
	     const char *buf, size_t count)
{
	int idx = 0;
	int ret = 0;
	int i = 0;
	int j = 0;
	char hex_len[RSA_PARAM_LEN];

	memset(rsa_import_modulus, 0, RSA_KEY_SIZE_MAX);
	rsa_import_modulus_len = 0;
	memset(rsa_import_public_exponent, 0, RSA_PUB_EXP_SIZE_MAX);
	rsa_import_public_exponent_len = 0;
	memset(rsa_import_pvt_exponent, 0, RSA_KEY_SIZE_MAX);
	rsa_import_pvt_exponent_len = 0;

	if (count != RSA_KEY_MATERIAL_SIZE) {
		pr_info("\nInvalid input\n");
		pr_info("Key material length is %lu bytes\n",
		       (unsigned long)count);
		pr_info("Key material length must be %u bytes\n",
		       RSA_KEY_MATERIAL_SIZE);
		return -EINVAL;
	}

	memcpy(rsa_import_modulus, buf, RSA_KEY_SIZE_MAX);
	idx += RSA_KEY_SIZE_MAX;
	memset(hex_len, 0, RSA_PARAM_LEN);
	for (i = idx, j = 0; i < idx + 2; i++, j++)
		snprintf(hex_len + (j * 2), 3, "%02X", buf[i]);
	ret = kstrtoul(hex_len, 16, (unsigned long *)&rsa_import_modulus_len);
	if (ret) {
		pr_info("\nCannot read modulus size from input buffer..");
		return -EINVAL;
	}
	idx += 2;

	memcpy(rsa_import_public_exponent, buf + idx, RSA_PUB_EXP_SIZE_MAX);
	idx += RSA_PUB_EXP_SIZE_MAX;
	memset(hex_len, 0, RSA_PARAM_LEN);
	for (i = idx, j = 0; i < idx + 1; i++, j++)
		snprintf(hex_len + (j * 2), 3, "%02X", buf[i]);
	ret = kstrtoul(hex_len, 16,
		      (unsigned long *)&rsa_import_public_exponent_len);
	if (ret) {
		pr_info("\nCannot read pub exp size from input buffer..");
		return -EINVAL;
	}
	idx += 1;

	memcpy(rsa_import_pvt_exponent, buf + idx, RSA_KEY_SIZE_MAX);
	idx += RSA_KEY_SIZE_MAX;
	memset(hex_len, 0, RSA_PARAM_LEN);
	for (i = idx, j = 0; i < idx + 2; i++, j++)
		snprintf(hex_len + (j * 2), 3, "%02X", buf[i]);
	ret = kstrtoul(hex_len, 16,
		      (unsigned long *)&rsa_import_pvt_exponent_len);
	if (ret) {
		pr_info("\nCannot read pvt exp size from input buffer..");
		return -EINVAL;
	}
	idx += 2;

	return count;
}

static ssize_t
import_rsa_key_blob(struct device *dev, struct device_attribute *attr,
		   char *buf)
{
	int rc = 0;
	struct scm_cmd_buf_t scm_cmd_buf;
	struct tz_storage_service_rsa_import_key_cmd_t *req_ptr = NULL;
	struct tz_storage_service_rsa_import_key_resp_t *resp_ptr = NULL;
	size_t req_size = 0;
	size_t resp_size = 0;
	size_t req_order = 0;
	size_t resp_order = 0;
	dma_addr_t dma_req_addr = 0;
	dma_addr_t dma_resp_addr = 0;
	dma_addr_t dma_key_blob = 0;
	struct page *req_page = NULL;
	struct page *resp_page = NULL;

	memset(rsa_key_blob, 0, RSA_KEY_BLOB_SIZE);
	rsa_key_blob_len = 0;

	if (rsa_import_pvt_exponent_len == 0 ||
	   rsa_import_public_exponent_len == 0 || rsa_import_modulus_len == 0) {
		pr_err("\nPlease provide key to import key blob\n");
		return -EINVAL;
	}

	if (rsa_import_pvt_exponent_len > RSA_KEY_SIZE_MAX ||
	   rsa_import_public_exponent_len > RSA_PUB_EXP_SIZE_MAX ||
	   rsa_import_modulus_len > RSA_KEY_SIZE_MAX) {
		pr_info("\nInvalid key\n");
		pr_info("\nBoth pvt and pub exponent len less than 512 bytes");
		pr_info("\nModulus len should be less than 4096 bytes");
		return -EINVAL;
	}

	dev = qdev;

	req_size = sizeof(struct tz_storage_service_rsa_import_key_cmd_t);
	req_order = get_order(req_size);
	req_page = alloc_pages(GFP_KERNEL, req_order);

	if (req_page)
		req_ptr = page_address(req_page);
	else
		return -ENOMEM;

	resp_size = sizeof(struct tz_storage_service_rsa_import_key_resp_t);
	resp_order = get_order(resp_size);
	resp_page = alloc_pages(GFP_KERNEL, resp_order);

	if (resp_page) {
		resp_ptr = page_address(resp_page);
	} else {
		pr_err("\nCannot allocate memory for key material\n");
		free_pages((unsigned long)req_ptr, req_order);
		return -ENOMEM;
	}

	dma_key_blob = dma_map_single(dev, rsa_key_blob, RSA_KEY_BLOB_SIZE,
				     DMA_FROM_DEVICE);
	rc = dma_mapping_error(dev, dma_key_blob);
	if (rc) {
		pr_err("DMA Mapping Error(rsa key blob)\n");
		goto err_end;
	}

	req_ptr->cmd_id = TZ_STOR_SVC_RSA_IMPORT_KEY;
	memcpy(req_ptr->modulus, rsa_import_modulus, rsa_import_modulus_len);
	req_ptr->modulus_len = rsa_import_modulus_len;
	memcpy(req_ptr->public_exponent, rsa_import_public_exponent,
	      rsa_import_public_exponent_len);
	req_ptr->public_exponent_len = rsa_import_public_exponent_len;
	req_ptr->digest_pad_type = TZ_STOR_SVC_RSA_DIGEST_PAD_PKCS115_SHA2_256;
	memcpy(req_ptr->pvt_exponent, rsa_import_pvt_exponent,
	      rsa_import_pvt_exponent_len);
	req_ptr->pvt_exponent_len = rsa_import_pvt_exponent_len;
	req_ptr->key_blob.key_material =
			(struct tz_storage_service_rsa_key_t *)dma_key_blob;
	req_ptr->key_blob.key_material_len = RSA_KEY_BLOB_SIZE;

	dma_req_addr = dma_map_single(dev, req_ptr, req_size, DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_req_addr);
	if (rc) {
		pr_err("DMA Mapping Error(request str)\n");
		goto err_map_req;
	}

	dma_resp_addr = dma_map_single(dev, resp_ptr, resp_size,
				      DMA_FROM_DEVICE);
	rc = dma_mapping_error(dev, dma_resp_addr);
	if (rc) {
		pr_err("DMA Mapping Error(response str)\n");
		goto err_map_resp;
	}

	scm_cmd_buf.req_size = req_size;
	scm_cmd_buf.req_addr = dma_req_addr;
	scm_cmd_buf.resp_size = resp_size;
	scm_cmd_buf.resp_addr = dma_resp_addr;

	rc = qcom_scm_tls_hardening(&scm_cmd_buf, sizeof(scm_cmd_buf),
				   CLIENT_CMD_CRYPTO_RSA);

	dma_unmap_single(dev, dma_req_addr, req_size, DMA_TO_DEVICE);
	dma_unmap_single(dev, dma_resp_addr, resp_size, DMA_FROM_DEVICE);
	dma_unmap_single(dev, dma_key_blob, RSA_KEY_BLOB_SIZE,
			DMA_FROM_DEVICE);

	if (rc) {
		pr_err("SCM Call failed..SCM Call return value = %d\n", rc);
		goto err_end;
	}

	if (resp_ptr->status) {
		rc = resp_ptr->status;
		pr_err("Response status failure..return value = %d\n", rc);
		goto err_end;
	}

	rsa_key_blob_len = RSA_KEY_BLOB_SIZE;
	memcpy(buf, rsa_key_blob, rsa_key_blob_len);

	goto end;

err_map_resp:
	dma_unmap_single(dev, dma_req_addr, req_size, DMA_TO_DEVICE);

err_map_req:
	dma_unmap_single(dev, dma_key_blob, RSA_KEY_BLOB_SIZE,
			DMA_FROM_DEVICE);

err_end:
	free_pages((unsigned long) page_address(req_page), req_order);
	free_pages((unsigned long) page_address(resp_page), resp_order);

	return rc;

end:
	free_pages((unsigned long) page_address(req_page), req_order);
	free_pages((unsigned long) page_address(resp_page), resp_order);

	return rsa_key_blob_len;
}

static ssize_t
store_rsa_key_blob(struct device *dev, struct device_attribute *attr,
		  const char *buf, size_t count)
{
	memset(rsa_key_blob, 0, RSA_KEY_BLOB_SIZE);
	rsa_key_blob_len = 0;

	if (count != RSA_KEY_BLOB_SIZE) {
		pr_info("\nInvalid input\n");
		pr_info("Key blob length is %lu bytes\n", (unsigned long)count);
		pr_info("Key blob length must be %u bytes\n",
		       RSA_KEY_BLOB_SIZE);
		return -EINVAL;
	}

	rsa_key_blob_len = count;
	memcpy(rsa_key_blob, buf, rsa_key_blob_len);

	return count;
}

static ssize_t
store_rsa_plain_data(struct device *dev, struct device_attribute *attr,
		       const char *buf, size_t count)
{
	rsa_plain_data_buf = memset(rsa_plain_data_buf, 0, MAX_PLAIN_DATA_SIZE);
	rsa_plain_data_len = 0;

	if (count == 0 || count > MAX_PLAIN_DATA_SIZE) {
		pr_info("\nInvalid input\n");
		pr_info("Plain data length is %lu bytes\n",
		       (unsigned long)count);
		pr_info("Plain data length must be > 0 bytes and <= %u bytes\n",
		       MAX_PLAIN_DATA_SIZE);
		return -EINVAL;
	}

	rsa_plain_data_len = count;
	memcpy(rsa_plain_data_buf, buf, rsa_plain_data_len);

	return count;
}

static ssize_t
show_rsa_signed_data(struct device *dev, struct device_attribute *attr,
		    char *buf)
{
	int rc = 0;
	struct scm_cmd_buf_t scm_cmd_buf;
	struct tz_storage_service_rsa_sign_data_cmd_t *req_ptr = NULL;
	struct tz_storage_service_rsa_sign_data_resp_t *resp_ptr = NULL;
	size_t req_size = 0;
	size_t resp_size = 0;
	size_t req_order = 0;
	size_t resp_order = 0;
	dma_addr_t dma_req_addr = 0;
	dma_addr_t dma_resp_addr = 0;
	dma_addr_t dma_key_blob = 0;
	dma_addr_t dma_plain_data = 0;
	dma_addr_t dma_output_data = 0;
	struct page *req_page = NULL;
	struct page *resp_page = NULL;

	memset(rsa_sign_data_buf, 0, MAX_RSA_SIGN_DATA_SIZE);
	rsa_sign_data_len = 0;

	if (rsa_key_blob_len == 0 || rsa_plain_data_len == 0) {
		pr_err("\nInvalid input\n");
		pr_info("Need key blob and plain data for RSA Signing\n");
		return -EINVAL;
	}

	dev = qdev;

	req_size = sizeof(struct tz_storage_service_rsa_sign_data_cmd_t);
	req_order = get_order(req_size);
	req_page = alloc_pages(GFP_KERNEL, req_order);

	if (req_page)
		req_ptr = page_address(req_page);
	else
		return -ENOMEM;

	resp_size = sizeof(struct tz_storage_service_rsa_sign_data_resp_t);
	resp_order = get_order(resp_size);
	resp_page = alloc_pages(GFP_KERNEL, resp_order);

	if (resp_page) {
		resp_ptr = page_address(resp_page);
	} else {
		pr_err("\nCannot allocate memory for key material\n");
		free_pages((unsigned long)req_ptr, req_order);
		return -ENOMEM;
	}

	dma_key_blob = dma_map_single(dev, rsa_key_blob, RSA_KEY_BLOB_SIZE,
				     DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_key_blob);
	if (rc) {
		pr_err("DMA Mapping Error(key blob)\n");
		goto err_end;
	}

	dma_plain_data = dma_map_single(dev, rsa_plain_data_buf,
				       rsa_plain_data_len, DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_plain_data);
	if (rc) {
		pr_err("DMA Mapping Error(plain data)\n");
		goto err_map_plain_data;
	}

	dma_output_data = dma_map_single(dev, rsa_sign_data_buf,
					MAX_RSA_SIGN_DATA_SIZE,
					DMA_FROM_DEVICE);
	rc = dma_mapping_error(dev, dma_output_data);
	if (rc) {
		pr_err("DMA Mapping Error(output data)\n");
		goto err_map_output_data;
	}

	req_ptr->cmd_id = TZ_STOR_SVC_RSA_SIGN_DATA;
	req_ptr->key_blob.key_material =
			(struct tz_storage_service_rsa_key_t *)dma_key_blob;
	req_ptr->key_blob.key_material_len = RSA_KEY_BLOB_SIZE;
	req_ptr->plain_data = (uint8_t *)dma_plain_data;
	req_ptr->plain_data_len = rsa_plain_data_len;
	req_ptr->output_buffer = (uint8_t *)dma_output_data;
	req_ptr->output_len = MAX_RSA_SIGN_DATA_SIZE;

	dma_req_addr = dma_map_single(dev, req_ptr, req_size, DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_req_addr);
	if (rc) {
		pr_err("DMA Mapping Error(request str)\n");
		goto err_map_req;
	}

	dma_resp_addr = dma_map_single(dev, resp_ptr, resp_size,
				      DMA_FROM_DEVICE);
	rc = dma_mapping_error(dev, dma_resp_addr);
	if (rc) {
		pr_err("DMA Mapping Error(response str)\n");
		goto err_map_resp;
	}

	scm_cmd_buf.req_size = req_size;
	scm_cmd_buf.req_addr = dma_req_addr;
	scm_cmd_buf.resp_size = resp_size;
	scm_cmd_buf.resp_addr = dma_resp_addr;

	rc = qcom_scm_tls_hardening(&scm_cmd_buf, sizeof(scm_cmd_buf),
				   CLIENT_CMD_CRYPTO_RSA);

	dma_unmap_single(dev, dma_resp_addr, resp_size, DMA_FROM_DEVICE);
	dma_unmap_single(dev, dma_req_addr, req_size, DMA_TO_DEVICE);
	dma_unmap_single(dev, dma_output_data, MAX_RSA_SIGN_DATA_SIZE,
			DMA_FROM_DEVICE);
	dma_unmap_single(dev, dma_plain_data, rsa_plain_data_len,
			DMA_TO_DEVICE);
	dma_unmap_single(dev, dma_key_blob, RSA_KEY_BLOB_SIZE, DMA_TO_DEVICE);

	if (rc) {
		pr_err("\nSCM Call failed..SCM Call return value = %d\n", rc);
		goto err_end;
	}

	if (resp_ptr->status != 0) {
		rc = resp_ptr->status;
		pr_err("\nResponse status failure..return value = %d\n", rc);
		goto err_end;
	}

	rsa_sign_data_len = resp_ptr->sealed_data_len;
	memcpy(buf, rsa_sign_data_buf, rsa_sign_data_len);

	goto end;

err_map_resp:
	dma_unmap_single(dev, dma_req_addr, req_size, DMA_TO_DEVICE);

err_map_req:
	dma_unmap_single(dev, dma_output_data, MAX_RSA_SIGN_DATA_SIZE,
			DMA_FROM_DEVICE);

err_map_output_data:
	dma_unmap_single(dev, dma_plain_data, rsa_plain_data_len,
			DMA_TO_DEVICE);

err_map_plain_data:
	dma_unmap_single(dev, dma_key_blob, RSA_KEY_BLOB_SIZE, DMA_TO_DEVICE);

err_end:
	free_pages((unsigned long)page_address(req_page), req_order);
	free_pages((unsigned long)page_address(resp_page), resp_order);

	return rc;

end:
	free_pages((unsigned long)page_address(req_page), req_order);
	free_pages((unsigned long)page_address(resp_page), resp_order);

	return rsa_sign_data_len;
}

static ssize_t
store_rsa_signed_data(struct device *dev, struct device_attribute *attr,
		 const char *buf, size_t count)
{
	rsa_sign_data_buf = memset(rsa_sign_data_buf, 0,
				  MAX_RSA_SIGN_DATA_SIZE);
	rsa_sign_data_len = 0;

	if (count == 0 || count > MAX_RSA_SIGN_DATA_SIZE) {
		pr_info("\nInvalid input\n");
		pr_info("Signed data length is %lu\n", (unsigned long)count);
		pr_info("Signed data length must be > 0 bytes and <= %u bytes\n",
		       MAX_RSA_SIGN_DATA_SIZE);
		return -EINVAL;
	}

	rsa_sign_data_len = count;
	memcpy(rsa_sign_data_buf, buf, rsa_sign_data_len);

	return count;
}

static ssize_t
verify_rsa_signed_data(struct device *dev, struct device_attribute *attr,
		      char *buf)
{
	int rc = 0;
	struct scm_cmd_buf_t scm_cmd_buf;
	struct tz_storage_service_rsa_verify_data_cmd_t *req_ptr = NULL;
	struct tz_storage_service_rsa_verify_data_resp_t *resp_ptr = NULL;
	size_t req_size = 0;
	size_t resp_size = 0;
	size_t req_order = 0;
	size_t resp_order = 0;
	dma_addr_t dma_req_addr = 0;
	dma_addr_t dma_resp_addr = 0;
	dma_addr_t dma_key_blob = 0;
	dma_addr_t dma_signed_data = 0;
	dma_addr_t dma_plain_data = 0;
	struct page *req_page = NULL;
	struct page *resp_page = NULL;
	const char *message = NULL;
	int message_len = 0;

	if (rsa_key_blob_len == 0 || rsa_sign_data_len == 0
	   || rsa_plain_data_len == 0) {
		pr_err("\nInvalid input\n");
		pr_info("Need key blob, signed data and plain data for RSA Verification\n");
		return -EINVAL;
	}

	dev = qdev;

	req_size = sizeof(struct tz_storage_service_rsa_verify_data_cmd_t);
	req_order = get_order(req_size);
	req_page = alloc_pages(GFP_KERNEL, req_order);

	if (req_page)
		req_ptr = page_address(req_page);
	else
		return -ENOMEM;

	resp_size = sizeof(struct tz_storage_service_rsa_verify_data_resp_t);
	resp_order = get_order(resp_size);
	resp_page = alloc_pages(GFP_KERNEL, resp_order);

	if (resp_page) {
		resp_ptr = page_address(resp_page);
	} else {
		pr_err("\nCannot allocate memory for key material\n");
		free_pages((unsigned long)req_ptr, req_order);
		return -ENOMEM;
	}

	dma_key_blob = dma_map_single(dev, rsa_key_blob, rsa_key_blob_len,
				     DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_key_blob);
	if (rc) {
		pr_err("DMA Mapping Error(key blob)\n");
		goto err_end;
	}

	dma_signed_data = dma_map_single(dev, rsa_sign_data_buf,
					rsa_sign_data_len, DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_signed_data);
	if (rc) {
		pr_err("DMA Mapping Error(sealed data)\n");
		goto err_map_sealed_data;
	}

	dma_plain_data = dma_map_single(dev, rsa_plain_data_buf,
					rsa_plain_data_len, DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_plain_data);
	if (rc) {
		pr_err("DMA Mapping Error(output data)\n");
		goto err_map_output_data;
	}

	req_ptr->cmd_id = TZ_STOR_SVC_RSA_VERIFY_SIGNATURE;
	req_ptr->key_blob.key_material =
			(struct tz_storage_service_rsa_key_t *)dma_key_blob;
	req_ptr->key_blob.key_material_len = rsa_key_blob_len;
	req_ptr->signed_data = (uint8_t *)dma_signed_data;
	req_ptr->signed_dlen = rsa_sign_data_len;
	req_ptr->data = (uint8_t *)dma_plain_data;
	req_ptr->data_len = rsa_plain_data_len;

	dma_req_addr = dma_map_single(dev, req_ptr, req_size, DMA_TO_DEVICE);
	rc = dma_mapping_error(dev, dma_req_addr);
	if (rc) {
		pr_err("DMA Mapping Error(request str)\n");
		goto err_map_req;
	}

	dma_resp_addr = dma_map_single(dev, resp_ptr, resp_size,
				      DMA_FROM_DEVICE);
	rc = dma_mapping_error(dev, dma_resp_addr);
	if (rc) {
		pr_err("DMA Mapping Error(response str)\n");
		goto err_map_resp;
	}

	scm_cmd_buf.req_size = req_size;
	scm_cmd_buf.req_addr = dma_req_addr;
	scm_cmd_buf.resp_size = resp_size;
	scm_cmd_buf.resp_addr = dma_resp_addr;

	rc = qcom_scm_tls_hardening(&scm_cmd_buf, sizeof(scm_cmd_buf),
				   CLIENT_CMD_CRYPTO_RSA);

	dma_unmap_single(dev, dma_resp_addr, resp_size, DMA_FROM_DEVICE);
	dma_unmap_single(dev, dma_req_addr, req_size, DMA_TO_DEVICE);
	dma_unmap_single(dev, dma_plain_data, rsa_plain_data_len,
			DMA_TO_DEVICE);
	dma_unmap_single(dev, dma_signed_data, rsa_sign_data_len,
			DMA_TO_DEVICE);
	dma_unmap_single(dev, dma_key_blob, RSA_KEY_BLOB_SIZE, DMA_TO_DEVICE);

	if (rc) {
		pr_err("\nSCM Call failed..SCM Call return value = %d\n", rc);
		goto err_end;
	}

	if (resp_ptr->status != 0) {
		rc = resp_ptr->status;
		pr_err("\nResponse status failure..return value = %d\n", rc);
		message = "RSA Verification Failed\0\n";
		message_len = strlen(message) + 1;
		memcpy(buf, message, message_len);
		goto err_end;
	} else {
		message = "RSA Verification Successful\0\n";
		message_len = strlen(message) + 1;
		memcpy(buf, message, message_len);
	}

	goto end;

err_map_resp:
	dma_unmap_single(dev, dma_req_addr, req_size, DMA_TO_DEVICE);

err_map_req:
	dma_unmap_single(dev, dma_plain_data, rsa_plain_data_len,
			DMA_TO_DEVICE);

err_map_output_data:
	dma_unmap_single(dev, dma_signed_data, rsa_sign_data_len,
			DMA_TO_DEVICE);

err_map_sealed_data:
	dma_unmap_single(dev, dma_key_blob, RSA_KEY_BLOB_SIZE, DMA_TO_DEVICE);

err_end:
	free_pages((unsigned long)page_address(req_page), req_order);
	free_pages((unsigned long)page_address(resp_page), resp_order);

	return rc;

end:
	free_pages((unsigned long)page_address(req_page), req_order);
	free_pages((unsigned long)page_address(resp_page), resp_order);

	return message_len;
}

struct qseecom_props {
	const int function;
	const int tz_arch;
	bool libraries_inbuilt;
	bool logging_support_enabled;
};

const struct qseecom_props qseecom_props_ipq40xx = {
	.function = (MUL | CRYPTO | AUTH_OTP | AES_SEC_KEY | RSA_SEC_KEY),
	.tz_arch = QSEE_32,
	.libraries_inbuilt = false,
	.logging_support_enabled = true,
};

const struct qseecom_props qseecom_props_ipq8064 = {
	.function = (MUL | ENC | DEC),
	.tz_arch = QSEE_32,
	.libraries_inbuilt = true,
	.logging_support_enabled = false,
};

const struct qseecom_props qseecom_props_ipq807x = {
	.function = (MUL | CRYPTO),
	.tz_arch = QSEE_64,
	.libraries_inbuilt = false,
	.logging_support_enabled = true,
};

static const struct of_device_id qseecom_of_table[] = {
	{	.compatible = "ipq40xx-qseecom",
		.data = (void *) &qseecom_props_ipq40xx,
	},
	{	.compatible = "ipq8064-qseecom",
		.data = (void *) &qseecom_props_ipq8064,
	},
	{	.compatible = "ipq807x-qseecom",
		.data = (void *) &qseecom_props_ipq807x,
	},
	{}
};
MODULE_DEVICE_TABLE(of, qseecom_of_table);

static int __init rsa_sec_key_init(void)
{
	int err = 0;
	struct page *rsa_key_blob_page = NULL;
	struct page *rsa_import_modulus_page = NULL;
	struct page *rsa_import_public_exponent_page = NULL;
	struct page *rsa_import_pvt_exponent_page = NULL;
	struct page *rsa_sign_data_buf_page = NULL;
	struct page *rsa_plain_data_buf_page = NULL;

	rsa_sec_kobj = kobject_create_and_add("rsa_sec_key", rsa_sec_kobj);

	if (!rsa_sec_kobj) {
		pr_info("\nFailed to register rsa_sec_key sysfs\n");
		return -ENOMEM;
	}

	err = sysfs_create_group(rsa_sec_kobj, &rsa_sec_key_attr_grp);

	if (err) {
		kobject_put(rsa_sec_kobj);
		rsa_sec_kobj = NULL;
		return err;
	}

	rsa_key_blob_page = alloc_pages(GFP_KERNEL,
				       get_order(RSA_KEY_BLOB_SIZE));
	rsa_import_modulus_page = alloc_pages(GFP_KERNEL,
					     get_order(RSA_KEY_SIZE_MAX));
	rsa_import_public_exponent_page = alloc_pages(GFP_KERNEL,
					  get_order(RSA_PUB_EXP_SIZE_MAX));
	rsa_import_pvt_exponent_page = alloc_pages(GFP_KERNEL,
						get_order(RSA_KEY_SIZE_MAX));
	rsa_sign_data_buf_page = alloc_pages(GFP_KERNEL,
				     get_order(MAX_RSA_SIGN_DATA_SIZE));
	rsa_plain_data_buf_page = alloc_pages(GFP_KERNEL,
				       get_order(MAX_PLAIN_DATA_SIZE));

	if (!rsa_key_blob_page || !rsa_import_modulus_page ||
	   !rsa_import_public_exponent_page || !rsa_import_pvt_exponent_page ||
	   !rsa_sign_data_buf_page || !rsa_plain_data_buf_page) {
		pr_err("\nCannot allocate memory for RSA secure-key ops\n");

		if (rsa_key_blob_page)
			free_pages((unsigned long)
				  page_address(rsa_key_blob_page),
				  get_order(RSA_KEY_BLOB_SIZE));

		if (rsa_import_modulus_page)
			free_pages((unsigned long)
				  page_address(rsa_import_modulus_page),
				  get_order(RSA_KEY_SIZE_MAX));

		if (rsa_import_public_exponent_page)
			free_pages((unsigned long)
				  page_address(rsa_import_public_exponent_page),
				  get_order(RSA_PUB_EXP_SIZE_MAX));

		if (rsa_import_pvt_exponent_page)
			free_pages((unsigned long)
				  page_address(rsa_import_pvt_exponent_page),
				  get_order(RSA_KEY_SIZE_MAX));

		if (rsa_sign_data_buf_page)
			free_pages((unsigned long)
				  page_address(rsa_sign_data_buf_page),
				  get_order(MAX_RSA_SIGN_DATA_SIZE));

		if (rsa_plain_data_buf_page)
			free_pages((unsigned long)
				  page_address(rsa_plain_data_buf_page),
				  get_order(MAX_PLAIN_DATA_SIZE));

		sysfs_remove_group(rsa_sec_kobj, &rsa_sec_key_attr_grp);
		kobject_put(rsa_sec_kobj);
		rsa_sec_kobj = NULL;

		return -ENOMEM;
	}

	rsa_key_blob = page_address(rsa_key_blob_page);
	rsa_import_modulus = page_address(rsa_import_modulus_page);
	rsa_import_public_exponent =
				page_address(rsa_import_public_exponent_page);
	rsa_import_pvt_exponent = page_address(rsa_import_pvt_exponent_page);
	rsa_sign_data_buf = page_address(rsa_sign_data_buf_page);
	rsa_plain_data_buf = page_address(rsa_plain_data_buf_page);

	return 0;
}

static int __init sec_key_init(void)
{
	int err = 0;
	struct page *key_page = NULL;
	struct page *key_blob_page = NULL;
	struct page *sealed_buf_page = NULL;
	struct page *unsealed_buf_page = NULL;

	sec_kobj = kobject_create_and_add("sec_key", NULL);

	if (!sec_kobj) {
		pr_info("\nFailed to register sec_key sysfs\n");
		return -ENOMEM;
	}

	err = sysfs_create_group(sec_kobj, &sec_key_attr_grp);

	if (err) {
		kobject_put(sec_kobj);
		sec_kobj = NULL;
		return err;
	}

	key_page = alloc_pages(GFP_KERNEL, get_order(KEY_SIZE));
	key_blob_page = alloc_pages(GFP_KERNEL, get_order(KEY_BLOB_SIZE));
	sealed_buf_page = alloc_pages(GFP_KERNEL,
				     get_order(MAX_ENCRYPTED_DATA_SIZE));
	unsealed_buf_page = alloc_pages(GFP_KERNEL,
				       get_order(MAX_PLAIN_DATA_SIZE));

	if (!key_page || !key_blob_page ||
	   !sealed_buf_page || !unsealed_buf_page) {
		pr_err("\nCannot allocate memory for secure-key ops\n");
		if (key_page)
			free_pages((unsigned long)page_address(key_page),
				  get_order(KEY_SIZE));

		if (key_blob_page)
			free_pages((unsigned long)page_address(key_blob_page),
				  get_order(KEY_BLOB_SIZE));

		if (sealed_buf_page)
			free_pages((unsigned long)page_address(sealed_buf_page),
				  get_order(MAX_ENCRYPTED_DATA_SIZE));

		if (unsealed_buf_page)
			free_pages((unsigned long)
				  page_address(unsealed_buf_page),
				  get_order(MAX_PLAIN_DATA_SIZE));

		sysfs_remove_group(sec_kobj, &sec_key_attr_grp);
		kobject_put(sec_kobj);
		sec_kobj = NULL;

		return -ENOMEM;
	}

	key = page_address(key_page);
	key_blob = page_address(key_blob_page);
	sealed_buf = page_address(sealed_buf_page);
	unsealed_buf = page_address(unsealed_buf_page);

	return 0;
}

static ssize_t mdt_write(struct file *filp, struct kobject *kobj,
	struct bin_attribute *bin_attr,
	char *buf, loff_t pos, size_t count)
{
	uint8_t *tmp;
	/*
	 * Position '0' means new file being written,
	 * Hence allocate new memory after freeing already allocated mem if any
	 */
	if (pos == 0) {
		kfree(mdt_file);
		mdt_file = kzalloc((count) * sizeof(uint8_t), GFP_KERNEL);
	} else {
		tmp = mdt_file;
		mdt_file = krealloc(tmp,
			(pos + count) * sizeof(uint8_t), GFP_KERNEL);
	}

	if (!mdt_file)
		return -ENOMEM;

	memcpy((mdt_file + pos), buf, count);
	mdt_size = pos + count;
	return count;
}

static ssize_t seg_write(struct file *filp, struct kobject *kobj,
	struct bin_attribute *bin_attr,
	char *buf, loff_t pos, size_t count)
{
	uint8_t *tmp;
	if (pos == 0) {
		kfree(seg_file);
		seg_file = kzalloc((count) * sizeof(uint8_t), GFP_KERNEL);
	} else {
		tmp = seg_file;
		seg_file = krealloc(tmp, (pos + count) * sizeof(uint8_t),
					GFP_KERNEL);
	}

	if (!seg_file)
		return -ENOMEM;

	memcpy((seg_file + pos), buf, count);
	seg_size = pos + count;
	return count;
}

static ssize_t auth_write(struct file *filp, struct kobject *kobj,
	struct bin_attribute *bin_attr,
	char *buf, loff_t pos, size_t count)
{
	uint8_t *tmp = NULL;

	if (pos == 0) {
		kfree(auth_file);
		auth_file = kzalloc((count) * sizeof(uint8_t), GFP_KERNEL);
	} else {
		tmp = auth_file;
		auth_file = krealloc(tmp, (pos + count) * sizeof(uint8_t),
					GFP_KERNEL);
	}

	if (!auth_file) {
		kfree(tmp);
		return -ENOMEM;
	}

	memcpy((auth_file + pos), buf, count);
	auth_size = pos + count;

	return count;
}

static int qseecom_unload_app(void)
{
	struct qseecom_unload_ireq req;
	struct qseecom_command_scm_resp resp;
	int ret = 0;
	uint32_t cmd_id = 0;
	uint32_t smc_id = 0;

	cmd_id = QSEOS_APP_SHUTDOWN_COMMAND;

	smc_id = TZ_SYSCALL_CREATE_SMC_ID(TZ_OWNER_QSEE_OS, TZ_SVC_APP_MGR,
					 TZ_ARMv8_CMD_UNLOAD_APP_ID);

	req.app_id = qsee_app_id;

	/* SCM_CALL to unload the app */
	ret = qcom_scm_qseecom_unload(smc_id, cmd_id, &req,
				     sizeof(struct qseecom_unload_ireq),
				     &resp, sizeof(resp));
	if (ret) {
		pr_err("scm_call to unload app (id = %d) failed\n", req.app_id);
		pr_info("scm call ret value = %d", ret);
		return ret;
	}

	pr_info("App id %d now unloaded\n", req.app_id);

	return 0;
}

static int tzapp_test(struct device *dev, void *input,
		      void *output, int input_len, int option)
{
	int ret = 0;
	int ret1, ret2;

	union qseecom_client_send_data_ireq send_data_req;
	struct qseecom_command_scm_resp resp;
	struct qsee_send_cmd_rsp *msgrsp; /* response data sent from QSEE */
	struct page *pg_tmp;
	unsigned long pg_addr;

	dev = qdev;

	/*
	 * Using alloc_pages to avoid colliding with input pointer's
	 * allocated page, since qsee_register_shared_buffer() in sampleapp
	 * checks if input ptr is in secure area. Page where msgreq/msgrsp
	 * is allocated is added to blacklisted area by sampleapp and added
	 * as secure memory region, hence input data (shared buffer)
	 * cannot be in that secure memory region
	 */
	pg_tmp = alloc_page(GFP_KERNEL);
	if (!pg_tmp) {
		pr_err("\nFailed to allocate page");
		return -ENOMEM;
	}
	/*
	 * Getting virtual page address. pg_tmp will be pointing to
	 * first page structure
	 */
	if (props->tz_arch != QSEE_64) {
		struct qsee_32_send_cmd *msgreq;

		msgreq = (struct qsee_32_send_cmd *) page_address(pg_tmp);

		if (!msgreq) {
			pr_err("Unable to allocate memory\n");
			return -ENOMEM;
		}
		/* pg_addr for passing to free_page */
		pg_addr = (unsigned long) msgreq;

		msgrsp = (struct qsee_send_cmd_rsp *)((uint8_t *) msgreq +
					sizeof(struct qsee_32_send_cmd));
		if (!msgrsp) {
			kfree(msgreq);
			pr_err("Unable to allocate memory\n");
			return -ENOMEM;
		}

		/*
		 * option = 1 -> Basic Multiplication, option = 2 -> Encryption,
		 * option = 3 -> Decryption, option = 4 -> Crypto Function
		 * option = 5 -> Authorized OTP fusing
		 */

		switch (option) {
		case 1:
			msgreq->cmd_id = CLIENT_CMD1_BASIC_DATA;
			msgreq->data = *((dma_addr_t *)input);
			break;
		case 2:
			msgreq->cmd_id = CLIENT_CMD8_RUN_CRYPTO_ENCRYPT;
			break;
		case 3:
			msgreq->cmd_id = CLIENT_CMD9_RUN_CRYPTO_DECRYPT;
			break;
		case 4:
			msgreq->cmd_id = CLIENT_CMD8_RUN_CRYPTO_TEST;
			break;
		case 5:
			if (!auth_file) {
				pr_err("No OTP file provided\n");
				return -ENOMEM;
			}

			msgreq->cmd_id = CLIENT_CMD_AUTH;
			msgreq->data = dma_map_single(dev, auth_file,
						      auth_size, DMA_TO_DEVICE);
			ret = dma_mapping_error(dev, msgreq->data);
			if (ret) {
				pr_err("DMA Mapping Error: otp_buffer %d",
					ret);
				return ret;
			}

			break;
		default:
			pr_err("\n Invalid Option");
			goto fn_exit_1;
		}
		if (option == 2 || option == 3) {
			msgreq->data = dma_map_single(dev, input,
					input_len, DMA_TO_DEVICE);
			msgreq->data2 = dma_map_single(dev, output,
					input_len, DMA_FROM_DEVICE);

			ret1 = dma_mapping_error(dev, msgreq->data);
			ret2 = dma_mapping_error(dev, msgreq->data2);

			if (ret1 || ret2) {
				pr_err("\nDMA Mapping Error:input:%d output:%d",
				      ret1, ret2);

				if (!ret1) {
					dma_unmap_single(dev, msgreq->data,
						input_len, DMA_TO_DEVICE);
				}

				if (!ret2) {
					dma_unmap_single(dev, msgreq->data2,
						input_len, DMA_FROM_DEVICE);
				}
				return ret1 ? ret1 : ret2;
			}

			msgreq->test_buf_size = input_len;
			msgreq->len = input_len;
		}
		send_data_req.v1.app_id = qsee_app_id;

		send_data_req.v1.req_ptr = dma_map_single(dev, msgreq,
					sizeof(*msgreq), DMA_TO_DEVICE);
		send_data_req.v1.rsp_ptr = dma_map_single(dev, msgrsp,
					sizeof(*msgrsp), DMA_FROM_DEVICE);

		ret1 = dma_mapping_error(dev, send_data_req.v1.req_ptr);
		ret2 = dma_mapping_error(dev, send_data_req.v1.rsp_ptr);

		if (!ret1 && !ret2) {
			send_data_req.v1.req_len =
					sizeof(struct qsee_32_send_cmd);
			send_data_req.v1.rsp_len =
					sizeof(struct qsee_send_cmd_rsp);
			ret = qcom_scm_qseecom_send_data(&send_data_req,
							sizeof(send_data_req.v1)
							, &resp, sizeof(resp));
		}

		if (option == 2 || option == 3) {
			dma_unmap_single(dev, msgreq->data,
						input_len, DMA_TO_DEVICE);
			dma_unmap_single(dev, msgreq->data2,
						input_len, DMA_FROM_DEVICE);

		}

		if (!ret1) {
			dma_unmap_single(dev, send_data_req.v1.req_ptr,
				sizeof(*msgreq), DMA_TO_DEVICE);
		}

		if (!ret2) {
			dma_unmap_single(dev, send_data_req.v1.rsp_ptr,
				sizeof(*msgrsp), DMA_FROM_DEVICE);
		}

		if (ret1 || ret2) {
			pr_err("\nDMA Mapping Error:req_ptr:%d rsp_ptr:%d",
			      ret1, ret2);
			return ret1 ? ret1 : ret2;
		}

		if (ret) {
			pr_err("qseecom_scm_call failed with err: %d\n", ret);
			goto fn_exit_1;
		}

		if (resp.result == QSEOS_RESULT_INCOMPLETE) {
			pr_err("Result incomplete\n");
			ret = -EINVAL;
			goto fn_exit_1;
		} else {
			if (resp.result != QSEOS_RESULT_SUCCESS) {
				pr_err("Response result %lu not supported\n",
								resp.result);
				ret = -EINVAL;
				goto fn_exit_1;
			} else {
				if (option == 4) {
					if (!msgrsp->status) {
						pr_info("Crypto operation success\n");
					} else {
						pr_info("Crypto operation failed\n");
						goto fn_exit;
					}
				}
			}
		}

		if (option == 1) {
			if (msgrsp->status) {
				pr_err("Input size exceeded supported range\n");
				ret = -EINVAL;
			}
			basic_output = msgrsp->data;
		} else if (option == 5) {
			if (msgrsp->status) {
				pr_err("Auth OTP failed with response %d\n",
								msgrsp->status);
				ret = -EIO;
			} else
				pr_info("Auth and Blow Success");
		}
fn_exit_1:
		free_page(pg_addr);
		if (option == 5) {
			dma_unmap_single(dev, msgreq->data, auth_size,
								DMA_TO_DEVICE);
		}

	} else {
		struct qsee_64_send_cmd *msgreq;

		msgreq = (struct qsee_64_send_cmd *) page_address(pg_tmp);

		if (!msgreq) {
			pr_err("Unable to allocate memory\n");
			return -ENOMEM;
		}
		/* pg_addr for passing to free_page */
		pg_addr = (unsigned long) msgreq;

		msgrsp = (struct qsee_send_cmd_rsp *)((uint8_t *) msgreq +
					sizeof(struct qsee_64_send_cmd));
		if (!msgrsp) {
			kfree(msgreq);
			pr_err("Unable to allocate memory\n");
			return -ENOMEM;
		}

		/*
		 * option = 1 -> Basic Multiplication, option = 2 -> Encryption,
		 * option = 3 -> Decryption, option = 4 -> Crypto Function
		 * option = 5 -> Authorized OTP fusing
		 */

		switch (option) {
		case 1:
			msgreq->cmd_id = CLIENT_CMD1_BASIC_DATA;
			msgreq->data = *((dma_addr_t *)input);
			break;
		case 2:
			msgreq->cmd_id = CLIENT_CMD8_RUN_CRYPTO_ENCRYPT;
			break;
		case 3:
			msgreq->cmd_id = CLIENT_CMD9_RUN_CRYPTO_DECRYPT;
			break;
		case 4:
			msgreq->cmd_id = CLIENT_CMD8_RUN_CRYPTO_TEST;
			break;
		case 5:
			if (!auth_file) {
				pr_err("No OTP file provided\n");
				return -ENOMEM;
			}

			msgreq->cmd_id = CLIENT_CMD_AUTH;
			msgreq->data = dma_map_single(dev, auth_file,
						      auth_size, DMA_TO_DEVICE);
			ret = dma_mapping_error(dev, msgreq->data);
			if (ret) {
				pr_err("DMA Mapping Error: otp_buffer %d",
					ret);
				return ret;
			}

			break;
		default:
			pr_err("\n Invalid Option");
			goto fn_exit;
		}
		if (option == 2 || option == 3) {
			msgreq->data = dma_map_single(dev, input,
					input_len, DMA_TO_DEVICE);
			msgreq->data2 = dma_map_single(dev, output,
					input_len, DMA_FROM_DEVICE);

			ret1 = dma_mapping_error(dev, msgreq->data);
			ret2 = dma_mapping_error(dev, msgreq->data2);

			if (ret1 || ret2) {
				pr_err("\nDMA Mapping Error:input:%d output:%d",
				      ret1, ret2);
				if (!ret1) {
					dma_unmap_single(dev, msgreq->data,
						input_len, DMA_TO_DEVICE);
				}

				if (!ret2) {
					dma_unmap_single(dev, msgreq->data2,
						input_len, DMA_FROM_DEVICE);
				}
				return ret1 ? ret1 : ret2;
			}
			msgreq->test_buf_size = input_len;
			msgreq->len = input_len;
		}
		send_data_req.v1.app_id = qsee_app_id;

		send_data_req.v1.req_ptr = dma_map_single(dev, msgreq,
					sizeof(*msgreq), DMA_TO_DEVICE);
		send_data_req.v1.rsp_ptr = dma_map_single(dev, msgrsp,
					sizeof(*msgrsp), DMA_FROM_DEVICE);

		ret1 = dma_mapping_error(dev, send_data_req.v1.req_ptr);
		ret2 = dma_mapping_error(dev, send_data_req.v1.rsp_ptr);


		if (!ret1 && !ret2) {
			send_data_req.v1.req_len =
					sizeof(struct qsee_64_send_cmd);
			send_data_req.v1.rsp_len =
					sizeof(struct qsee_send_cmd_rsp);
			ret = qcom_scm_qseecom_send_data(&send_data_req,
							sizeof(send_data_req.v2)
							, &resp, sizeof(resp));
		}

		if (option == 2 || option == 3) {
			dma_unmap_single(dev, msgreq->data,
						input_len, DMA_TO_DEVICE);
			dma_unmap_single(dev, msgreq->data2,
						input_len, DMA_FROM_DEVICE);

		}

		if (!ret1) {
			dma_unmap_single(dev, send_data_req.v1.req_ptr,
				sizeof(*msgreq), DMA_TO_DEVICE);
		}

		if (!ret2) {
			dma_unmap_single(dev, send_data_req.v1.rsp_ptr,
				sizeof(*msgrsp), DMA_FROM_DEVICE);
		}

		if (ret1 || ret2) {
			pr_err("\nDMA Mapping Error:req_ptr:%d rsp_ptr:%d",
			      ret1, ret2);
			return ret1 ? ret1 : ret2;
		}

		if (ret) {
			pr_err("qseecom_scm_call failed with err: %d\n", ret);
			goto fn_exit;
		}

		if (resp.result == QSEOS_RESULT_INCOMPLETE) {
			pr_err("Result incomplete\n");
			ret = -EINVAL;
			goto fn_exit;
		} else {
			if (resp.result != QSEOS_RESULT_SUCCESS) {
				pr_err("Response result %lu not supported\n",
								resp.result);
				ret = -EINVAL;
				goto fn_exit;
			} else {
				if (option == 4) {
					if (!msgrsp->status) {
						pr_info("Crypto operation success\n");
					} else {
						pr_info("Crypto operation failed\n");
						goto fn_exit;
					}
				}
			}
		}

		if (option == 1) {
			if (msgrsp->status) {
				pr_err("Input size exceeded supported range\n");
				ret = -EINVAL;
			}
			basic_output = msgrsp->data;
		} else if (option == 5) {
			if (msgrsp->status) {
				pr_err("Auth OTP failed with response %d\n",
								msgrsp->status);
				ret = -EIO;
			} else
				pr_info("Auth and Blow Success");
		}
fn_exit:
		free_page(pg_addr);
		if (option == 5) {
			dma_unmap_single(dev, msgreq->data, auth_size,
								DMA_TO_DEVICE);
		}
	}
	return ret;
}

static int32_t copy_files(int *img_size)
{
	uint8_t *buf;

	if (mdt_file && seg_file) {
		*img_size = mdt_size + seg_size;

		qsee_sbuffer = kzalloc(*img_size, GFP_KERNEL);
		if (!qsee_sbuffer) {
			pr_err("Error: qsee_sbuffer alloc failed\n");
			return -ENOMEM;
		}
		buf = qsee_sbuffer;

		memcpy(buf, mdt_file, mdt_size);
		buf += mdt_size;
		memcpy(buf, seg_file, seg_size);
		buf += seg_size;
	} else {
		pr_err("\nSampleapp file Inputs not provided\n");
		return -EINVAL;
	}
	return 0;
}

static int load_request(struct device *dev, uint32_t smc_id,
		       uint32_t cmd_id, size_t req_size)
{
	union qseecom_load_ireq load_req;
	struct qseecom_command_scm_resp resp;
	int ret, ret1;
	int img_size;

	kfree(qsee_sbuffer);
	ret = copy_files(&img_size);
	if (ret) {
		pr_err("Copying Files failed\n");
		return ret;
	}

	dev = qdev;

	load_req.load_lib_req.mdt_len = mdt_size;
	load_req.load_lib_req.img_len = img_size;
	load_req.load_lib_req.phy_addr = dma_map_single(dev, qsee_sbuffer,
						       img_size, DMA_TO_DEVICE);
	ret1 = dma_mapping_error(dev, load_req.load_lib_req.phy_addr);
	if (ret1 == 0) {
		ret = qcom_scm_qseecom_load(smc_id, cmd_id, &load_req,
					   req_size, &resp, sizeof(resp));
		dma_unmap_single(dev, load_req.load_lib_req.phy_addr,
				img_size, DMA_TO_DEVICE);
	}
	if (ret1) {
		pr_err("\nDMA Mapping error (qsee_sbuffer)");
		return ret1;
	}
	if (ret) {
		pr_err("SCM_CALL to load app and services failed\n");
		return ret;
	}

	if (resp.result == QSEOS_RESULT_FAILURE) {
		pr_err("SCM_CALL rsp.result is QSEOS_RESULT_FAILURE\n");
		return -EFAULT;
	}

	if (resp.result == QSEOS_RESULT_INCOMPLETE)
		pr_err("Process_incomplete_cmd ocurred\n");

	if (resp.result != QSEOS_RESULT_SUCCESS) {
		pr_err("scm_call failed resp.result unknown, %lu\n",
				resp.result);
		return -EFAULT;
	}

	pr_info("\nSuccessfully loaded app and services!!!!!\n");

	qsee_app_id = resp.data;
	return 0;
}

/* To show basic multiplication output */
static ssize_t
show_basic_output(struct device *dev, struct device_attribute *attr,
					char *buf)
{
	return snprintf(buf, (basic_data_len + 1), "%d", basic_output);
}

/* Basic multiplication App*/
static ssize_t
store_basic_input(struct device *dev, struct device_attribute *attr,
					const char *buf, size_t count)
{
	dma_addr_t __aligned(sizeof(dma_addr_t) * 8) basic_input = 0;
	uint32_t ret = 0;
	basic_data_len = count;
	if ((count - 1) == 0) {
		pr_err("\n Input cannot be NULL!");
		return -EINVAL;
	}
	if (kstrtouint(buf, 10, &basic_input) || basic_input > (U32_MAX / 10))
		pr_err("\n Please enter a valid unsigned integer less than %d",
			(U32_MAX / 10));
	else
		ret = tzapp_test(dev, &basic_input, NULL, 0, 1);

	return ret ? ret : count;
}

/* To show encrypted plain text*/
static ssize_t
show_encrypt_output(struct device *dev, struct device_attribute *attr,
					char *buf)
{
	memcpy(buf, encrypt_text, enc_len);
	return enc_len;
}

/* To Encrypt input plain text */
static ssize_t
store_encrypt_input(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	int32_t ret = -EINVAL;
	uint8_t *input_pt;
	uint8_t *output_pt;

	enc_len = count;
	if (enc_len == 0) {
		pr_err("\n Input cannot be NULL!");
		return -EINVAL;
	}
	if ((enc_len % 16 != 0) || (enc_len > MAX_INPUT_SIZE)) {
		pr_info("\n Input Length must be multiple of 16 & < 4096 bytes");
		return -EINVAL;
	}

	input_pt = kzalloc(enc_len * sizeof(uint8_t *), GFP_KERNEL);
	if (!input_pt)
		return -ENOMEM;
	memcpy(input_pt, buf, count);

	output_pt = kzalloc(enc_len * sizeof(uint8_t *), GFP_KERNEL);
	if (!output_pt) {
		kfree(input_pt);
		return -ENOMEM;
	}

	ret = tzapp_test(dev, (uint8_t *)input_pt,
			 (uint8_t *)output_pt, enc_len, 2);

	if (!ret)
		memcpy(encrypt_text, output_pt, enc_len);

	kfree(input_pt);
	kfree(output_pt);
	return count;
}

/* To show decrypted cipher text */
static ssize_t
show_decrypt_output(struct device *dev, struct device_attribute *attr,
		 char *buf)
{
	memcpy(buf, decrypt_text, dec_len);
	return dec_len;
}

/* To decrypt input cipher text */
static ssize_t
store_decrypt_input(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	int32_t ret = -EINVAL;
	uint8_t *input_pt;
	uint8_t *output_pt;

	dec_len = count;
	if (dec_len == 0) {
		pr_err("\n Input cannot be NULL!");
		return -EINVAL;
	}

	if ((dec_len % 16 != 0) || (dec_len > MAX_INPUT_SIZE)) {
		pr_info("\n Input Length must be multiple of 16 & < 4096 bytes");
		return -EINVAL;
	}

	input_pt = kzalloc(dec_len * sizeof(uint8_t *), GFP_KERNEL);
	if (!input_pt)
		return -ENOMEM;
	memcpy(input_pt, buf, dec_len);

	output_pt = kzalloc(dec_len * sizeof(uint8_t *), GFP_KERNEL);
	if (!output_pt) {
		kfree(input_pt);
		return -ENOMEM;
	}

	ret = tzapp_test(dev, (uint8_t *)input_pt,
			 (uint8_t *)output_pt, dec_len, 3);
	if (!ret)
		memcpy(decrypt_text, output_pt, dec_len);

	kfree(input_pt);
	kfree(output_pt);
	return count;
}

static ssize_t
store_load_start(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	int load_cmd;
	uint32_t smc_id = 0;
	uint32_t cmd_id = 0;
	size_t req_size = 0;

	dev = qdev;

	if (kstrtouint(buf, 10, &load_cmd)) {
		pr_err("\n Provide valid integer input!");
		pr_err("\nEcho 0 to load app libs");
		pr_err("\nEcho 1 to load app");
		pr_err("\nEcho 2 to unload app");
		return -EINVAL;
	}
	if (load_cmd == 0) {
		if (!(props->libraries_inbuilt || app_libs_state)) {
			smc_id = TZ_SYSCALL_CREATE_SMC_ID(TZ_OWNER_QSEE_OS,
				 TZ_SVC_APP_MGR, TZ_ARMv8_CMD_LOAD_LIB);
			cmd_id = QSEE_LOAD_SERV_IMAGE_COMMAND;
			req_size = sizeof(struct qseecom_load_lib_ireq);
			if (load_request(dev, smc_id, cmd_id, req_size))
				pr_info("\nLoading app libs failed");
			else
				app_libs_state = 1;
			if (props->logging_support_enabled) {
				if (tzdbg_register_qsee_log_buf(dev))
					pr_info("\nRegistering log buf failed");
			}
		} else {
			pr_info("\nLibraries are either already loaded or are inbuilt in this platform");
		}
	} else if (load_cmd == 1) {
		if (props->libraries_inbuilt || app_libs_state) {
			if (!app_state) {
				smc_id = TZ_SYSCALL_CREATE_SMC_ID(
					 TZ_OWNER_QSEE_OS, TZ_SVC_APP_MGR,
					 TZ_ARMv8_CMD_LOAD_APP_ID);
				cmd_id = QSEOS_APP_START_COMMAND;
				req_size = sizeof(struct qseecom_load_app_ireq);
				if (load_request(dev, smc_id, cmd_id, req_size))
					pr_info("\nLoading app failed");
				else
					app_state = 1;
			} else {
				pr_info("\nApp already loaded...");
			}
		} else {
			if (!app_libs_state)
				pr_info("\nApp libs must be loaded first");
			if (!props->libraries_inbuilt)
				pr_info("\nApp libs are not inbuilt in this platform");
		}
	} else if (load_cmd == 2) {
		if (app_state) {
			if (qseecom_unload_app())
				pr_info("\nApp unload failed");
			else
				app_state = 0;
		} else {
			pr_info("\nApp already unloaded...");
		}
	} else {
		pr_info("\nEcho 0 to load app libs if its not inbuilt");
		pr_info("\nEcho 1 to load app if its not already loaded");
		pr_info("\nEcho 2 to unload app if its already loaded");
	}

	return count;
}

static ssize_t
store_crypto_input(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	tzapp_test(dev, NULL, NULL, 0, 4);
	return count;
}

static ssize_t
store_fuse_otp_input(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	tzapp_test(dev, (void *)buf, NULL, 0, 5);
	return count;
}

static int __init tzapp_init(void)
{
	int err;
	int i = 0;
	struct attribute **tzapp_attrs = kzalloc((hweight_long(props->function)
				+ 1) * sizeof(*tzapp_attrs), GFP_KERNEL);

	if (!tzapp_attrs) {
		pr_err("\nCannot allocate memory..tzapp");
		return -ENOMEM;
	}

	tzapp_attrs[i++] = &dev_attr_load_start.attr;

	if (props->function & MUL)
		tzapp_attrs[i++] = &dev_attr_basic_data.attr;

	if (props->function & ENC)
		tzapp_attrs[i++] = &dev_attr_encrypt.attr;

	if (props->function & DEC)
		tzapp_attrs[i++] = &dev_attr_decrypt.attr;

	if (props->function & CRYPTO)
		tzapp_attrs[i++] = &dev_attr_crypto.attr;

	if (props->function & AUTH_OTP)
		tzapp_attrs[i++] = &dev_attr_fuse_otp.attr;

	if (props->logging_support_enabled)
		tzapp_attrs[i++] = &dev_attr_log_buf.attr;

	tzapp_attrs[i] = NULL;

	tzapp_attr_grp.attrs = tzapp_attrs;

	tzapp_kobj = kobject_create_and_add("tzapp", firmware_kobj);

	err = sysfs_create_group(tzapp_kobj, &tzapp_attr_grp);

	if (err) {
		kobject_put(tzapp_kobj);
		return err;
	}
	return 0;
}

static int __init qseecom_probe(struct platform_device *pdev)
{
	struct device_node *of_node = pdev->dev.of_node;
	const struct of_device_id *id;
	unsigned int start = 0, size = 0;
	struct qsee_notify_app notify_app;
	struct qseecom_command_scm_resp resp;
	int ret = 0, ret1 = 0;

	if (!of_node)
		return -ENODEV;

	qdev = &pdev->dev;
	id = of_match_device(qseecom_of_table, &pdev->dev);

	if (!id)
		return -ENODEV;

	ret = of_property_read_u32(of_node, "mem-start", &start);
	ret1 = of_property_read_u32(of_node, "mem-size", &size);
	if (ret || ret1) {
		pr_err("No mem-region specified, using default\n");
		goto load;
	}

	notify_app.applications_region_addr = start;
	notify_app.applications_region_size = size;

	ret = qcom_scm_qseecom_notify(&notify_app,
				     sizeof(struct qsee_notify_app),
				     &resp, sizeof(resp));
	if (ret) {
		pr_err("Notify App failed\n");
		return -1;
	}

load:
	props = ((struct qseecom_props *)id->data);

	sysfs_create_bin_file(firmware_kobj, &mdt_attr);
	sysfs_create_bin_file(firmware_kobj, &seg_attr);

	if (props->function & AUTH_OTP)
		sysfs_create_bin_file(firmware_kobj, &auth_attr);

	if (!tzapp_init())
		pr_info("\nLoaded tz app Module Successfully!\n");
	else
		pr_info("\nFailed to load tz app module\n");

	if (props->function & AES_SEC_KEY) {
		if (!sec_key_init())
			pr_info("\nLoaded Sec Key Module Successfully!\n");
		else
			pr_info("\nFailed to load Sec Key Module\n");
	}

	if (props->function & RSA_SEC_KEY) {
		if (!rsa_sec_key_init())
			pr_info("\nLoaded RSA Sec Key Module Successfully!\n");
		else
			pr_info("\nFailed to load RSA Sec Key Module\n");
	}

	return 0;
}

static int __exit qseecom_remove(struct platform_device *pdev)
{
	if (app_state) {
		if (qseecom_unload_app())
			pr_err("\nApp unload failed");
		else
			app_state = 0;
	}

	sysfs_remove_bin_file(firmware_kobj, &mdt_attr);
	sysfs_remove_bin_file(firmware_kobj, &seg_attr);

	if (props->function & AUTH_OTP)
		sysfs_remove_bin_file(firmware_kobj, &auth_attr);

	sysfs_remove_group(tzapp_kobj, &tzapp_attr_grp);
	kobject_put(tzapp_kobj);

	if (props->function & AES_SEC_KEY) {
		if (key)
			free_pages((unsigned long)key, get_order(KEY_SIZE));

		if (key_blob)
			free_pages((unsigned long)key_blob,
				  get_order(KEY_BLOB_SIZE));

		if (sealed_buf)
			free_pages((unsigned long)sealed_buf,
				  get_order(MAX_ENCRYPTED_DATA_SIZE));

		if (unsealed_buf)
			free_pages((unsigned long)unsealed_buf,
				  get_order(MAX_PLAIN_DATA_SIZE));

		sysfs_remove_group(sec_kobj, &sec_key_attr_grp);
		kobject_put(sec_kobj);
	}

	if (props->function & RSA_SEC_KEY) {
		if (rsa_key_blob)
			free_pages((unsigned long)rsa_key_blob,
				  get_order(RSA_KEY_BLOB_SIZE));

		if (rsa_import_modulus)
			free_pages((unsigned long)rsa_import_modulus,
				  get_order(RSA_KEY_SIZE_MAX));

		if (rsa_import_public_exponent)
			free_pages((unsigned long)rsa_import_public_exponent,
				  get_order(RSA_PUB_EXP_SIZE_MAX));

		if (rsa_import_pvt_exponent)
			free_pages((unsigned long)rsa_import_pvt_exponent,
				  get_order(RSA_KEY_SIZE_MAX));

		if (rsa_sign_data_buf)
			free_pages((unsigned long)rsa_sign_data_buf,
				  get_order(MAX_RSA_SIGN_DATA_SIZE));

		if (rsa_plain_data_buf)
			free_pages((unsigned long)rsa_plain_data_buf,
				  get_order(MAX_PLAIN_DATA_SIZE));

		sysfs_remove_group(rsa_sec_kobj, &rsa_sec_key_attr_grp);
		kobject_put(rsa_sec_kobj);
	}

	kfree(mdt_file);
	kfree(seg_file);

	if (props->function & AUTH_OTP)
		kfree(auth_file);

	kfree(qsee_sbuffer);

	if (app_libs_state) {
		if (unload_app_libs())
			pr_err("\nApp libs unload failed");
		else
			app_libs_state = 0;
	}

	return 0;
}

static struct platform_driver qseecom_driver = {
	.probe = qseecom_probe,
	.remove = qseecom_remove,
	.driver = {
		.name = KBUILD_MODNAME,
		.of_match_table = qseecom_of_table,
	},
};
module_platform_driver(qseecom_driver);

MODULE_DESCRIPTION("QSEECOM Driver");
MODULE_LICENSE("GPL v2");
