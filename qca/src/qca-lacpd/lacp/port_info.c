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
#include "port_info.h"
#include "lacpdu.h"

/*
 * port_info_equal : check if informations of two port are the same. Ignore some state fields specified in 'ignore_mask'
 */
bool port_info_equal(struct lacpd_port_info *a, struct lacpd_port_info *b, uint32_t ignore_mask)
{

	if (!(ignore_mask & ignore_mask_system_priority) && (a->system_priority != b->system_priority)) {
		return false;
	}

	if (!(ignore_mask & ignore_mask_system) && !mac_addr_euqal(a->system, b->system)) {
		return false;
	}

	if (!(ignore_mask & ignore_mask_key) && (a->key != b->key)) {
		return false;
	}

	if (!(ignore_mask & ignore_mask_port_priority) && (a->port_priority != b->port_priority)) {
		return false;
	}

	if (!(ignore_mask & ignore_mask_port) && (a->port != b->port)) {
		return false;
	}

	if (!(ignore_mask & ignore_mask_state_activity) && (a->state.activity != b->state.activity)) {
		return false;
	}

	if (!(ignore_mask & ignore_mask_state_timeout) && (a->state.timeout != b->state.timeout)) {
		return false;
	}

	if (!(ignore_mask & ignore_mask_state_aggregation) && (a->state.aggregation != b->state.aggregation)) {
		return false;
	}

	if (!(ignore_mask & ignore_mask_state_synchronization) && (a->state.synchronization != b->state.synchronization)) {
		return false;
	}

	if (!(ignore_mask & ignore_mask_state_collecting) && (a->state.collecting != b->state.collecting)) {
		return false;
	}

	if (!(ignore_mask & ignore_mask_state_distributing) && (a->state.distributing != b->state.distributing)) {
		return false;
	}

	if (!(ignore_mask & ignore_mask_state_defaulted) && (a->state.defaulted != b->state.defaulted)) {
		return false;
	}

	if (!(ignore_mask & ignore_mask_state_expired) && (a->state.expired != b->state.expired)) {
		return false;
	}

	return true;
}
