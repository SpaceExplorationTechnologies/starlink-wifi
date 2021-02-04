/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * 
 */

#ifndef __BMI_IO_H__
#define __BMI_IO_H__

/*
 * Commands to support user-level agents that use Bootloader Messaging Interface.
 * BMI is a protocol used during the "BMI Phase" --  shortly after a Target with
 * embedded CPU starts.  It allows Host software to configure the Target,
 * inspect memory and registers, download firmware and data, and perform
 * other initialization tasks.
 *
 * Some implementations manage these tasks entirely within the Host driver.
 * Other implementations may use a user-level BMI agent (e.g. bmiloader)
 * to handle these initialization tasks. When a user-level agent is involved,
 * these commands are used.
 *
 * See also:
 * build-time constant ATH_SUPPORT_BMI_AGENT, which enables code
 *    to support user-level BMI agents
 * the "bmi" module parameter, which may be set when the driver
 *    is loaded in order to bypass default driver-based initialization.
 */

struct bmi_done_cmd {
    u_int32_t command;
} __attribute__ ((packed));

struct bmi_read_memory_cmd {
    union {
        struct bmi_read_memory_request {
            u_int32_t command;
            u_int32_t address;
            u_int32_t length;
        } request;
        char response[BMI_DATASZ_MAX];
    } u;
} __attribute__ ((packed));

struct bmi_write_memory_cmd {
    u_int32_t command;
    u_int32_t address;
    u_int32_t length;
    char data[BMI_DATASZ_MAX-3*sizeof(u_int32_t)];
} __attribute__ ((packed));

struct bmi_execute_cmd {
    u_int32_t command;
    u_int32_t TargetPC;
    u_int32_t parameter;
} __attribute__ ((packed));

struct bmi_set_app_start_cmd {
    u_int32_t command;
    u_int32_t address;
} __attribute__ ((packed));

struct bmi_read_soc_register_cmd {
    union {
        struct bmi_read_soc_word_request {
            u_int32_t command;
            u_int32_t address;
        } request;
        u_int32_t result;
    } u;
} __attribute__ ((packed));

struct bmi_write_soc_register_cmd {
    u_int32_t command;
    u_int32_t address;
    u_int32_t new_value;
} __attribute__ ((packed));

struct bmi_get_target_info_cmd {
    union {
        u_int32_t command;
        struct { /* NB: response format3 */
            struct bmi_target_info info;
        } response;
    } u;
} __attribute__ ((packed));

struct bmi_lz_stream_start_cmd {
    u_int32_t command;
    u_int32_t address;
} __attribute__ ((packed));

struct bmi_lz_data_cmd {
    u_int32_t command;
    u_int32_t length;
    char data[BMI_DATASZ_MAX-2*sizeof(u_int32_t)];
} __attribute__ ((packed));

struct bmi_nvram_process_cmd {
    u_int32_t command;
    u_int8_t name[BMI_NVRAM_SEG_NAME_SZ];
} __attribute__ ((packed));

#endif  /* __BMI_IO_H__ */
