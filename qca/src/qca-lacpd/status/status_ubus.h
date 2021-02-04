/*
 * Copyright (c) 2016, The Linux Foundation. All rights reserved.
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
#include <libubus.h>

#include "status_api.h"

#define LACPD_STATUS_BUF_SIZE 2048

enum {
	LACPD_STATUS_DUMP_ARG_LACP_NAME,
	LACPD_STATUS_DUMP_ARG_MAX
};

enum {
	LACPD_GET_AGG_OF_PORT_ARG_SW_NAME,
	LACPD_GET_AGG_OF_PORT_ARG_PORT_ID,
	LACPD_GET_AGG_OF_PORT_ARG_MAX
};

enum {
	LACPD_GET_PORTS_OF_AGG_ARG_SW_NAME,
	LACPD_GET_PORTS_OF_AGG_ARG_AGG_ID,
	LACPD_GET_PORTS_OF_AGG_ARG_MAX
};

struct lacpd_ubus_status_system {
	struct lacpd_status_system base;

	struct ubus_context *ubus_ctx;
};
