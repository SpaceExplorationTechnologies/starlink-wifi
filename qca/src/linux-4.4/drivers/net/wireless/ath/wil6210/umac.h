/*
 * Copyright (c) 2018, The Linux Foundation. All rights reserved.
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

#ifndef WIL6210_UMAC_H
#define WIL6210_UMAC_H

#include <linux/types.h>
#include <linux/skbuff.h>
#include <net/cfg80211.h>
#include <linux/ieee80211.h>
#include <linux/ktime.h>
#include <linux/list.h>
#include <linux/hashtable.h>
#include <linux/kref.h>

#define WIL_UMAC_MAX_FRAME_SIZE 512
/* enlarge this (upto 254) to support more nodes per VAP */
#define WIL_UMAC_MAX_AID 32
#define WIL_UMAC_NODE_HASH_BITS 5

/* used by mgmt_rx/mgmt_tx */
#define WIL_UMAC_FRAME_NOT_HANDLED 1

struct wil6210_priv;
struct wil_umac;

/* used by start_ap */
struct wil_umac_vap_params {
	u8 channel;
	const u8 *ssid;
	size_t ssid_len;
	u16 bi;
	enum nl80211_hidden_ssid hidden_ssid;
	bool privacy;
	u8 max_aid;
};

struct wil_umac_vap_stats {
	size_t bcast_tx_packets;
	size_t bcast_tx_bytes;
};

struct wil_umac_vap {
	struct wil_umac *umac;
	bool valid; /* for using as array item */
	void *driver_vap_ctx;
	struct net_device *ndev;
	u8 channel;
	u8 ssid[IEEE80211_MAX_SSID_LEN];
	size_t ssid_len;
	u16 bi;
	enum nl80211_hidden_ssid hidden_ssid;
	bool privacy;
	u8 max_aid;

	bool ap_started;
	u8 proberesp_ies[WIL_UMAC_MAX_FRAME_SIZE];
	size_t proberesp_ies_len;
	u8 assocresp_ies[WIL_UMAC_MAX_FRAME_SIZE];
	size_t assocresp_ies_len;
	DECLARE_BITMAP(aid_bitmap, WIL_UMAC_MAX_AID);
	struct wil_umac_vap_stats stats;
};

enum wil_umac_node_state {
	WIL_UMAC_NODE_STATE_INIT,
	WIL_UMAC_NODE_STATE_AUTHENTICATING,
	WIL_UMAC_NODE_STATE_AUTHENTICATED,
	WIL_UMAC_NODE_STATE_ASSOCIATING,
	WIL_UMAC_NODE_STATE_ASSOCIATED,
	WIL_UMAC_NODE_STATE_8021X_OPEN,
	WIL_UMAC_NODE_STATE_DISCONNECTING,
};

struct wil_umac_node_basic_stats {
	size_t packets;
	size_t bytes;
	ktime_t last_activity;
};

struct wil_umac_node_stats {
	struct wil_umac_node_basic_stats rx;
	struct wil_umac_node_basic_stats tx;
};

struct wil_umac_node {
	struct wil_umac *umac;
	struct wil_umac_vap *vap;
	struct hlist_node hlist;
	struct kref refcount;

	u8 mac[ETH_ALEN];
	u8 aid;
	enum wil_umac_node_state state;
	ktime_t assoc_ts;
	enum nl80211_auth_type auth_type; /* open or FT */
	u8 ies[WIL_UMAC_MAX_FRAME_SIZE]; /* last captured IEs */
	size_t ies_len;
	s8 last_rssi, rssi_min, rssi_max; /* from mgmt frames */
	struct wil_umac_node_stats stats;
	ktime_t last_mgmt; /* timestamp when last mgmt frame received */
};

/* callbacks from driver to UMAC */
struct wil_umac_ops {
	void (*uninit)(void *umac_handle);

	/* notify about new virtual interface
	 * returns opaque vap handle.
	 * driver_vap_ctx used for invoking driver's callbacks.
	 */
	void *(*vap_add)(void *umac_handle, void *driver_vap_ctx,
			 struct net_device *ndev);

	/* notify about virtual interface deletion */
	void (*vap_remove)(void *vap_handle);

	int (*start_ap)(void *vap_handle, struct wil_umac_vap_params *params);
	void (*stop_ap)(void *vap_handle);

	/* set application IEs for specific frame type */
	int (*vap_set_ie)(void *vap_handle, u8 stype, const u8 *ies,
			  size_t ies_len);

	/* let UMAC handle received management frame.
	 * node can be found by TA/RA inside frame.
	 * Returns 0 for success, negative value for failure, in case the frame
	 * was handled by UMAC. Otherwise returns UMAC_FRAME_NOT_HANDLED which
	 * means driver/kernel/userspace needs to handle this frame.
	 */
	int (*mgmt_rx)(void *vap_handle, s8 rssi, u8 channel,
		       struct ieee80211_mgmt *frame, size_t len);

	/* let UMAC transmit management frame originated from userspace.
	 * node can be found by TA/RA inside frame.
	 * Returns 0 for success, negative value for failure, in case the frame
	 * was handled by UMAC. Otherwise returns UMAC_FRAME_NOT_HANDLED which
	 * means driver needs to transmit this frame.
	 */
	int (*mgmt_tx)(void *vap_handle, const u8 *frame, size_t len);

	/* disconnect request from userspace
	 * UMAC should send disassociate frame.
	 */
	void (*disconnect_sta)(void *vap_handle, const u8 *mac, u16 reason);

	/* notify about disconnect complete.
	 * UMAC may delete the node object.
	 */
	void (*sta_deleted)(void *vap_handle, const u8 *mac);

	/* notify about key installed to device */
	int (*add_key)(void *vap_handle, u8 key_index, bool pairwise,
		       const u8 *mac);

	/* notify about key deleted */
	int (*del_key)(void *vap_handle, u8 key_index, bool pairwise,
		       const u8 *mac);

	/* notify about data packet queued for transmit */
	int (*tx_notify)(void *umac_handle, void *vap_handle,
			 struct sk_buff *skb);

	/* notify about received data packet */
	int (*rx_notify)(void *umac_handle, void *vap_handle,
			 struct sk_buff *skb);
};

/* callbacks from UMAC to driver */
struct wil_umac_rops {
	/* request transmission of management frame */
	int (*mgmt_tx)(void *driver_vap_ctx, const u8 *frame, size_t len);

	/* notify driver about successful STA association */
	int (*add_station)(void *driver_vap_ctx, const u8 *mac, u8 aid);

	/* notify driver about STA disassociation */
	void (*del_station)(void *driver_vap_ctx, const u8 *mac, u16 reason);
};

struct wil_umac {
	struct wil6210_priv *wil;
	u8 permanent_mac[ETH_ALEN];
	bool disable_ap_sme;
	size_t max_sta;
	size_t max_vaps;
	struct wil_umac_rops rops;
	struct platform_device *pdev;

	struct wil_umac_vap *vaps;
	struct wil_umac_node *node_array;
	DECLARE_HASHTABLE(node_hash, WIL_UMAC_NODE_HASH_BITS);
	struct mutex mutex; /* protect umac/vap/node operations */
	/* guard against vap deletion while ongoing async operations */
	atomic_t async_cnt;

	struct workqueue_struct *workq; /* for inact_worker */
	struct work_struct inact_worker;
	struct timer_list inact_timer;
};

/* callbacks from external drivers into UMAC */
struct wil_umac_external_ops {
	struct wil_umac_node *(*node_get)(void *umac_handle, const u8 *mac);
	void (*node_put)(void *umac_handle, struct wil_umac_node *node);
};

/* platform device data for interaction with external drivers */
struct wil_umac_platdata {
	struct wil_umac_external_ops ops;
	void *umac_handle;
};

/* init UMAC module.
 * returns opaque umac handle.
 */
void *wil_umac_init(struct wil6210_priv *wil, u8 *permanent_mac,
		    size_t max_vaps, size_t max_sta, bool disable_ap_sme,
		    struct wil_umac_ops *ops,
		    const struct wil_umac_rops *rops);

#endif /* WIL6210_UMAC_H */
