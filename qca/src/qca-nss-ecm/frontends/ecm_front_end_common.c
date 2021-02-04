/*
 **************************************************************************
 * Copyright (c) 2015, 2016, The Linux Foundation.  All rights reserved.
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 **************************************************************************
 */

#include <linux/version.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/debugfs.h>
#include <linux/inet.h>
#include <linux/etherdevice.h>
#include <net/netfilter/nf_conntrack.h>
#include <net/ip.h>
#include <net/ipv6.h>

/*
 * Debug output levels
 * 0 = OFF
 * 1 = ASSERTS / ERRORS
 * 2 = 1 + WARN
 * 3 = 2 + INFO
 * 4 = 3 + TRACE
 */
#define DEBUG_LEVEL ECM_FRONT_END_COMMON_DEBUG_LEVEL

#include "ecm_types.h"
#include "ecm_db_types.h"
#include "ecm_state.h"
#include "ecm_tracker.h"
#include "ecm_classifier.h"
#include "ecm_front_end_types.h"
#include "ecm_tracker_datagram.h"
#include "ecm_tracker_udp.h"
#include "ecm_tracker_tcp.h"
#include "ecm_db.h"
#include "ecm_front_end_common.h"

#ifdef ECM_INTERFACE_BOND_ENABLE
/*
 * ecm_front_end_bond_notifier_stop()
 */
void ecm_front_end_bond_notifier_stop(int num)
{
	if (ECM_FRONT_END_TYPE_NSS == ecm_front_end_type_get()) {
		ecm_nss_bond_notifier_stop(num);
	}
}

/*
 * ecm_front_end_bond_notifier_init()
 */
int ecm_front_end_bond_notifier_init(struct dentry *dentry)
{
	if (ECM_FRONT_END_TYPE_NSS == ecm_front_end_type_get()) {
		return ecm_nss_bond_notifier_init(dentry);
	}

	return 0;
}

/*
 * ecm_front_end_bond_notifier_exit()
 */
void ecm_front_end_bond_notifier_exit(void)
{
	if (ECM_FRONT_END_TYPE_NSS == ecm_front_end_type_get()) {
		ecm_nss_bond_notifier_exit();
	}
}
#endif

/*
 * ecm_front_end_destroy_failure_handle()
 *	Destroy request failure handler.
 */
void ecm_front_end_destroy_failure_handle(struct ecm_front_end_connection_instance *feci)
{
	spin_lock_bh(&feci->lock);
	feci->stats.driver_fail_total++;
	feci->stats.driver_fail++;
	if (feci->stats.driver_fail >= feci->stats.driver_fail_limit) {
		/*
		 * Reached to the driver failure limit. ECM no longer allows
		 * re-trying deceleration.
		 */
		feci->accel_mode = ECM_FRONT_END_ACCELERATION_MODE_FAIL_DRIVER;
		spin_unlock_bh(&feci->lock);
		DEBUG_WARN("%p: Decel failed - driver fail limit\n", feci);
		return;
	}

	/*
	 * Destroy request failed. The accelerated connection couldn't be destroyed
	 * in the acceleration engine. Revert back the accel_mode, unset the is_defunct
	 * flag just in case this request has come through the defunct process.
	 */
	feci->accel_mode = ECM_FRONT_END_ACCELERATION_MODE_ACCEL;
	feci->is_defunct = false;
	spin_unlock_bh(&feci->lock);

	/*
	 * Set the defunct timer to a smaller timeout value so that the connection will be
	 * tried to be defuncted again, when the timeout expires (its value is 5 seconds).
	 */
	ecm_db_connection_defunct_timer_remove_and_set(feci->ci, ECM_DB_TIMER_GROUPS_CONNECTION_DEFUNCT_RETRY_TIMEOUT);
}
