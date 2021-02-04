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

#include <linux/etherdevice.h>
#include <linux/log2.h>
#include <linux/platform_device.h>
#include "umac.h"
#include "wil6210.h" /* wil_dbg */

/* simple hash is enough for variation of macaddr */
#define WIL_UMAC_NODE_HASH(mac) \
	((mac)[ETH_ALEN - 1] % (1 << WIL_UMAC_NODE_HASH_BITS))
#define WIL_UMAC_NODE_INACTIVITY_MS 0 /* disable for now */

#define WIL_UMAC_SUPPORTED_RSN_VERSION 1
#define WIL_UMAC_CIPHER_SUITE_OUI 0xac0f00
#define WIL_UMAC_CIPHER_SUITE_TYPE_GCMP 0x08
#define WIL_UMAC_CIPHER_SUITE_GCMP  \
		(((WIL_UMAC_CIPHER_SUITE_TYPE_GCMP) << 24) | \
		 WIL_UMAC_CIPHER_SUITE_OUI)

static const char *state2string(enum wil_umac_node_state state)
{
	switch (state) {
	case WIL_UMAC_NODE_STATE_INIT:
		return "INIT";
	case WIL_UMAC_NODE_STATE_AUTHENTICATING:
		return "AUTHENTICATING";
	case WIL_UMAC_NODE_STATE_AUTHENTICATED:
		return "AUTHENTICATED";
	case WIL_UMAC_NODE_STATE_ASSOCIATING:
		return "ASSOCIATING";
	case WIL_UMAC_NODE_STATE_ASSOCIATED:
		return "ASSOCIATED";
	case WIL_UMAC_NODE_STATE_8021X_OPEN:
		return "8021X_OPEN";
	case WIL_UMAC_NODE_STATE_DISCONNECTING:
		return "DISCONNECTING";
	default:
		return "Invalid";
	}
}

static const char *stype2string(u16 stype)
{
	switch (stype) {
	case IEEE80211_STYPE_ASSOC_REQ:
		return "ASSOC_REQ";
	case IEEE80211_STYPE_ASSOC_RESP:
		return "ASSOC_RESP";
	case IEEE80211_STYPE_REASSOC_REQ:
		return "REASSOC_REQ";
	case IEEE80211_STYPE_REASSOC_RESP:
		return "REASSOC_RESP";
	case IEEE80211_STYPE_PROBE_REQ:
		return "PROBE_REQ";
	case IEEE80211_STYPE_PROBE_RESP:
		return "PROBE_RESP";
	case IEEE80211_STYPE_DISASSOC:
		return "DISASSOC";
	case IEEE80211_STYPE_AUTH:
		return "AUTH";
	case IEEE80211_STYPE_DEAUTH:
		return "DEAUTH";
	case IEEE80211_STYPE_ACTION:
		return "ACTION";
	default:
		return "Unknown frame";
	}
}

/* find free item in vaps array */
static struct wil_umac_vap *wil_umac_find_free_vap(struct wil_umac *umac)
{
	int i;

	WARN_ON(!mutex_is_locked(&umac->mutex));

	for (i = 0; i < umac->max_vaps; i++)
		if (!umac->vaps[i].valid)
			return &umac->vaps[i];

	return NULL;
}

static inline bool wil_umac_node_valid(struct wil_umac_node *node)
{
	return atomic_read(&node->refcount.refcount) > 0;
}

/* find free item in node_array */
static struct wil_umac_node *wil_umac_find_free_node(struct wil_umac *umac)
{
	int i;

	WARN_ON(!mutex_is_locked(&umac->mutex));

	for (i = 0; i < umac->max_sta; i++)
		if (!wil_umac_node_valid(&umac->node_array[i]))
			return &umac->node_array[i];

	return NULL;
}

/* search in node hash table */
static struct wil_umac_node *wil_umac_node_find(struct wil_umac *umac,
						const u8 *mac)
{
	struct wil_umac_node *node;
	int key = WIL_UMAC_NODE_HASH(mac);

	WARN_ON(!mutex_is_locked(&umac->mutex));

	hash_for_each_possible(umac->node_hash, node, hlist, key)
		if (ether_addr_equal(node->mac, mac))
			return node;

	return NULL;
}

static struct wil_umac_node *
wil_umac_first_connected_node(struct wil_umac *umac)
{
	int i;
	struct wil_umac_node *node;

	WARN_ON(!mutex_is_locked(&umac->mutex));

	for (i = 0; i < umac->max_sta; i++) {
		node = &umac->node_array[i];
		if (wil_umac_node_valid(node) &&
		    node->state != WIL_UMAC_NODE_STATE_DISCONNECTING)
			return node;
	}

	return NULL;
}

static struct wil_umac_node *wil_umac_node_alloc(struct wil_umac_vap *vap,
						 const u8 *mac)
{
	struct wil_umac *umac = vap->umac;
	struct wil_umac_node *node;

	WARN_ON(!mutex_is_locked(&umac->mutex));

	node = wil_umac_find_free_node(umac);
	if (!node)
		return NULL;

	memset(node, 0, sizeof(struct wil_umac_node));
	node->umac = umac;
	node->vap = vap;
	kref_init(&node->refcount);
	ether_addr_copy(node->mac, mac);
	node->state = WIL_UMAC_NODE_STATE_INIT;
	node->rssi_max = S8_MIN;

	hash_add(umac->node_hash, &node->hlist, WIL_UMAC_NODE_HASH(node->mac));

	return node;
}

static void wil_umac_node_release(struct kref *kref)
{
	struct wil_umac_node *node = container_of(kref, struct wil_umac_node,
						  refcount);
	struct wil_umac *umac = node->umac;

	wil_dbg_umac(umac->wil, "node %pM release\n", node->mac);

	clear_bit(node->aid - 1, node->vap->aid_bitmap);
}

static void wil_umac_node_dealloc(struct wil_umac_node *node)
{
	struct wil_umac_vap *vap = node->vap;

	WARN_ON(!mutex_is_locked(&vap->umac->mutex));

	hash_del(&node->hlist);

	kref_put(&node->refcount, wil_umac_node_release);
}

static void wil_umac_node_change_state(struct wil_umac_node *node,
				       enum wil_umac_node_state new_state)
{
	struct wil_umac *umac = node->umac;

	WARN_ON(!mutex_is_locked(&umac->mutex));

	wil_dbg_umac(umac->wil, "node %pM change state %s => %s\n", node->mac,
		     state2string(node->state), state2string(new_state));
	node->state = new_state;
}

static int wil_umac_send_assoc_resp(struct wil_umac_vap *vap, const u8 *mac,
				    u8 aid, u16 status_code, bool reassoc)
{
	struct wil_umac *umac = vap->umac;
	struct ieee80211_mgmt *assoc_resp;
	u16 fc, capab;
	u8 *ies;
	int rc;

	assoc_resp = kzalloc(WIL_UMAC_MAX_FRAME_SIZE, GFP_KERNEL);
	if (!assoc_resp)
		return -ENOMEM;

	fc = IEEE80211_FTYPE_MGMT;
	fc |= (reassoc ? IEEE80211_STYPE_REASSOC_RESP :
	       IEEE80211_STYPE_ASSOC_RESP);

	assoc_resp->frame_control = cpu_to_le16(fc);

	ether_addr_copy(assoc_resp->da, mac);
	ether_addr_copy(assoc_resp->sa, vap->ndev->dev_addr);
	ether_addr_copy(assoc_resp->bssid, vap->ndev->dev_addr);

	capab = WLAN_CAPABILITY_DMG_TYPE_AP | WLAN_CAPABILITY_DMG_CBAP_ONLY;
	if (vap->privacy)
		capab |= WLAN_CAPABILITY_DMG_PRIVACY;
	assoc_resp->u.assoc_resp.capab_info = cpu_to_le16(capab);

	assoc_resp->u.assoc_resp.status_code = cpu_to_le16(status_code);
	assoc_resp->u.assoc_resp.aid = cpu_to_le16(aid);

	/* app_ies expected to include SSID */
	ies = assoc_resp->u.assoc_resp.variable;
	memcpy(ies, vap->assocresp_ies, vap->assocresp_ies_len);
	ies += vap->assocresp_ies_len;

	rc = umac->rops.mgmt_tx(vap->driver_vap_ctx, (u8 *)assoc_resp,
				ies - (u8 *)assoc_resp);

	kfree(assoc_resp);

	if (rc)
		wil_err(umac->wil, "fail to send %sassoc response, mac %pM aid %d status_code %d (rc %d)\n",
			reassoc ? "re" : "", mac, aid, status_code, rc);
	else
		wil_dbg_umac(umac->wil,
			     "%sassoc response sent, mac %pM aid %d status_code %d\n",
			     reassoc ? "re" : "", mac, aid, status_code);

	return rc;
}

static int wil_umac_send_auth(struct wil_umac_vap *vap, const u8 *mac,
			      u16 auth_alg, u16 auth_transaction,
			      u16 status_code)
{
	struct wil_umac *umac = vap->umac;
	struct ieee80211_mgmt *auth;
	u16 fc;
	int rc;

	auth = kzalloc(WIL_UMAC_MAX_FRAME_SIZE, GFP_KERNEL);
	if (!auth)
		return -ENOMEM;

	fc = IEEE80211_FTYPE_MGMT | IEEE80211_STYPE_AUTH;

	auth->frame_control = cpu_to_le16(fc);

	ether_addr_copy(auth->da, mac);
	ether_addr_copy(auth->sa, vap->ndev->dev_addr);
	ether_addr_copy(auth->bssid, vap->ndev->dev_addr);

	auth->u.auth.auth_alg = cpu_to_le16(auth_alg);
	auth->u.auth.auth_transaction = cpu_to_le16(auth_transaction);
	auth->u.auth.status_code = cpu_to_le16(status_code);

	rc = umac->rops.mgmt_tx(vap->driver_vap_ctx, (u8 *)auth,
				offsetof(struct ieee80211_mgmt,
					 u.auth.variable));

	kfree(auth);

	if (rc)
		wil_err(umac->wil,
			"fail to send auth frame, mac %pM auth_alg %d auth_transaction %d status_code %d (rc %d)\n",
			mac, auth_alg, auth_transaction, status_code, rc);
	else
		wil_dbg_umac(umac->wil,
			     "auth frame sent, mac %pM auth_alg %d auth_transaction %d status_code %d\n",
			     mac, auth_alg, auth_transaction, status_code);

	return rc;
}

static int wil_umac_send_probe_resp(struct wil_umac_vap *vap, const u8 *mac)
{
	struct wil_umac *umac = vap->umac;
	struct ieee80211_mgmt *probe_resp;
	u16 fc, capab;
	u8 *ies;
	int rc;

	probe_resp = kzalloc(WIL_UMAC_MAX_FRAME_SIZE, GFP_KERNEL);
	if (!probe_resp)
		return -ENOMEM;

	fc = IEEE80211_FTYPE_MGMT | IEEE80211_STYPE_PROBE_RESP;
	probe_resp->frame_control = cpu_to_le16(fc);

	ether_addr_copy(probe_resp->da, mac);
	ether_addr_copy(probe_resp->sa, vap->ndev->dev_addr);
	ether_addr_copy(probe_resp->bssid, vap->ndev->dev_addr);

	probe_resp->u.probe_resp.beacon_int = cpu_to_le16(vap->bi);

	capab = WLAN_CAPABILITY_DMG_TYPE_AP | WLAN_CAPABILITY_DMG_CBAP_ONLY;
	if (vap->privacy)
		capab |= WLAN_CAPABILITY_DMG_PRIVACY;
	probe_resp->u.probe_resp.capab_info = cpu_to_le16(capab);

	/* app_ies expected to include SSID, RSN */
	ies = probe_resp->u.probe_resp.variable;
	memcpy(ies, vap->proberesp_ies, vap->proberesp_ies_len);
	ies += vap->proberesp_ies_len;

	rc = umac->rops.mgmt_tx(vap->driver_vap_ctx, (u8 *)probe_resp,
				ies - (u8 *)probe_resp);

	kfree(probe_resp);

	if (rc)
		wil_err(umac->wil, "fail to send probe response, mac %pM (rc %d)\n",
			mac, rc);
	else
		wil_dbg_umac(umac->wil, "probe response sent, mac %pM\n", mac);

	return rc;
}

static int wil_umac_send_disassoc(struct wil_umac_vap *vap, const u8 *mac,
				  u16 reason)
{
	struct wil_umac *umac = vap->umac;
	struct ieee80211_mgmt *disassoc;
	u16 fc, capab;
	int rc, frame_len;

	disassoc = kzalloc(WIL_UMAC_MAX_FRAME_SIZE, GFP_KERNEL);
	if (!disassoc)
		return -ENOMEM;

	fc = IEEE80211_FTYPE_MGMT | IEEE80211_STYPE_DISASSOC;
	disassoc->frame_control = cpu_to_le16(fc);

	ether_addr_copy(disassoc->da, mac);
	ether_addr_copy(disassoc->sa, vap->ndev->dev_addr);
	ether_addr_copy(disassoc->bssid, vap->ndev->dev_addr);

	capab = WLAN_CAPABILITY_DMG_TYPE_AP | WLAN_CAPABILITY_DMG_CBAP_ONLY;
	if (vap->privacy)
		capab |= WLAN_CAPABILITY_DMG_PRIVACY;
	disassoc->u.disassoc.reason_code = cpu_to_le16(reason);

	frame_len = offsetof(struct ieee80211_mgmt, u.disassoc.reason_code) +
		    sizeof(disassoc->u.disassoc.reason_code);
	rc = umac->rops.mgmt_tx(vap->driver_vap_ctx, (u8 *)disassoc,
				frame_len);

	kfree(disassoc);

	if (rc)
		wil_err(umac->wil, "fail to send disassoc, mac %pM reason %d (rc %d)\n",
			mac, reason, rc);
	else
		wil_dbg_umac(umac->wil, "disassoc sent, mac %pM reason %d\n",
			     mac, reason);

	return rc;
}

static void wil_umac_inact_worker(struct work_struct *work)
{
	struct wil_umac *umac = container_of(work, struct wil_umac,
					     inact_worker);
	struct wil_umac_node *node;
	struct hlist_node *tmp_node;
	int bkt;

	mutex_lock(&umac->mutex);

	hash_for_each_safe(umac->node_hash, bkt, tmp_node, node, hlist) {
		ktime_t idle_time = (ktime_sub(ktime_get(), node->last_mgmt));

		if  (ktime_to_ms(idle_time) > WIL_UMAC_NODE_INACTIVITY_MS) {
			const u8 *mac = node->mac;

			wil_info(umac->wil, "drop idle node %pM\n", mac);
			wil_umac_node_change_state(
				node, WIL_UMAC_NODE_STATE_DISCONNECTING);

			/* make sure vap won't get removed */
			atomic_inc(&umac->async_cnt);
			mutex_unlock(&umac->mutex);

			wil_umac_send_disassoc(node->vap, mac,
					       WLAN_REASON_UNSPECIFIED);

			mutex_lock(&umac->mutex);
			atomic_dec(&umac->async_cnt);
		}
	}

	mutex_unlock(&umac->mutex);
}

static void wil_umac_inact_fn(ulong x)
{
	struct wil_umac *umac = (struct wil_umac *)x;

	queue_work(umac->workq, &umac->inact_worker);
	mod_timer(&umac->inact_timer,
		  jiffies + msecs_to_jiffies(WIL_UMAC_NODE_INACTIVITY_MS));
}

static void *wil_umac_vap_add(void *umac_handle, void *driver_vap_ctx,
			      struct net_device *ndev)
{
	struct wil_umac *umac = umac_handle;
	struct wil_umac_vap *vap;

	wil_dbg_umac(umac->wil, "umac vap add: name %s, mac %pM\n",
		     ndev->name, ndev->dev_addr);

	mutex_lock(&umac->mutex);

	vap = wil_umac_find_free_vap(umac);
	if (!vap)
		goto out;

	vap->driver_vap_ctx = driver_vap_ctx;
	vap->umac = umac;
	vap->ndev = ndev;
	vap->valid = true;
out:
	mutex_unlock(&umac->mutex);

	return vap;
}

static void wil_umac_vap_remove(void *vap_handle)
{
	struct wil_umac_vap *vap = vap_handle;
	struct wil_umac *umac = vap->umac;
	struct wil_umac_node *node;
	struct hlist_node *tmp_node;
	int bkt, i = 0;

	wil_dbg_umac(umac->wil, "umac vap remove: name %s, mac %pM\n",
		     vap->ndev->name, vap->ndev->dev_addr);

	mutex_lock(&umac->mutex);

	vap->valid = false;

	/* wait for ongoing txrx operations to complete */
	while (atomic_read(&umac->async_cnt) && i < 30) {
		mutex_unlock(&umac->mutex);
		msleep(100);
		i++;
		mutex_lock(&umac->mutex);
	}

	if (atomic_read(&umac->async_cnt))
		wil_err(umac->wil, "timeout waiting for async to complete\n");

	/* deallocate VAPs nodes */
	hash_for_each_safe(umac->node_hash, bkt, tmp_node, node, hlist) {
		if (node->vap == vap) {
			wil_dbg_umac(umac->wil, "removing node %pM. aid %d\n",
				     node->mac, node->aid);
			wil_umac_node_dealloc(node);
		}
	}

	mutex_unlock(&umac->mutex);
}

static int wil_umac_start_ap(void *vap_handle,
			     struct wil_umac_vap_params *params)
{
	struct wil_umac_vap *vap = vap_handle;
	struct wil_umac *umac = vap->umac;

	if (params->max_aid == 0 || params->max_aid > WIL_UMAC_MAX_AID)
		return -EINVAL;

	wil_dbg_umac(umac->wil, "umac start AP: name %s, mac %pM\n",
		     vap->ndev->name, vap->ndev->dev_addr);

	mutex_lock(&umac->mutex);

	vap->channel = params->channel;
	memcpy(vap->ssid, params->ssid, IEEE80211_MAX_SSID_LEN);
	vap->ssid_len = params->ssid_len;
	vap->bi = params->bi;
	vap->hidden_ssid = params->hidden_ssid;
	vap->privacy = params->privacy;
	vap->max_aid = params->max_aid;

	vap->ap_started = true;

	mutex_unlock(&umac->mutex);

	return 0;
}

static void wil_umac_stop_ap(void *vap_handle)
{
	struct wil_umac_vap *vap = vap_handle;
	struct wil_umac *umac = vap->umac;
	struct wil_umac_node *node;
	struct hlist_node *tmp_node;
	int bkt;

	wil_dbg_umac(umac->wil, "umac stop AP: name %s, mac %pM\n",
		     vap->ndev->name, vap->ndev->dev_addr);

	mutex_lock(&umac->mutex);

	/* deallocate VAPs nodes */
	hash_for_each_safe(umac->node_hash, bkt, tmp_node, node, hlist) {
		if (node->vap == vap) {
			wil_dbg_umac(umac->wil, "removing node %pM. aid %d\n",
				     node->mac, node->aid);
			wil_umac_node_dealloc(node);
		}
	}

	vap->ap_started = false;

	mutex_unlock(&umac->mutex);
}

static int wil_umac_vap_set_ie(void *vap_handle, u8 stype,
			       const u8 *ies, size_t ies_len)
{
	struct wil_umac_vap *vap = vap_handle;
	struct wil_umac *umac = vap->umac;

	wil_dbg_umac(umac->wil, "SET IE for %s (0x%x)\n",
		     stype2string(stype), stype);
	wil_hex_dump_umac("IE: ", DUMP_PREFIX_OFFSET, 16, 1,
			  ies, ies_len, true);

	if (ies_len > WIL_UMAC_MAX_FRAME_SIZE)
		return -ENOMEM;

	mutex_lock(&umac->mutex);

	switch (stype) {
	case IEEE80211_STYPE_ASSOC_RESP:
		memcpy(vap->assocresp_ies, ies, ies_len);
		vap->assocresp_ies_len = ies_len;
		break;
	case IEEE80211_STYPE_PROBE_RESP:
		memcpy(vap->proberesp_ies, ies, ies_len);
		vap->proberesp_ies_len = ies_len;
		break;
	default:
		break;
	}

	mutex_unlock(&umac->mutex);

	return 0;
}

/* returns 0 as error indication (aid 0 is invalid) */
static u8 wil_umac_aid_allocate(struct wil_umac_vap *vap)
{
	u8 aid;

	WARN_ON(!mutex_is_locked(&vap->umac->mutex));

	for (aid = 1; aid <= vap->max_aid; aid++)
		if (!test_bit(aid - 1, vap->aid_bitmap))
			break;

	/* this cannot wraparound because max_aid < 255 */
	if (aid > vap->max_aid)
		return 0;

	set_bit(aid - 1, vap->aid_bitmap);
	return aid;
}

static bool wil_umac_is_valid_bssid(struct wil_umac_vap *vap, u8 *bssid,
				    bool allow_broadcast)
{
	if (allow_broadcast && is_broadcast_ether_addr(bssid))
		return true;

	if (ether_addr_equal(bssid, vap->ndev->dev_addr))
		return true;

	return false;
}

static bool wil_umac_is_ssid_match(struct wil_umac_vap *vap, const u8 *ssid_ie,
				   bool allow_wildcard)
{
	if (!ssid_ie)
		return false;

	wil_hex_dump_umac("SSID IE: ", DUMP_PREFIX_OFFSET, 16, 1,
			  &ssid_ie[2], ssid_ie[1], true);
	if (vap->ssid_len == ssid_ie[1] &&
	    memcmp(vap->ssid, &ssid_ie[2], ssid_ie[1]) == 0)
		/* exact match */
		return true;

	if (!allow_wildcard)
		return false;

	if (ssid_ie[1] == 0 &&
	    vap->hidden_ssid == NL80211_HIDDEN_SSID_NOT_IN_USE)
		/* wildcard ssid and vap is not hidden */
		return true;

	return false;
}

static bool wil_umac_is_ssid_list_match(struct wil_umac_vap *vap,
					const u8 *ssid_list_ie)
{
	size_t remaining;
	const u8 *ssid_ie;

	if (!ssid_list_ie)
		return false;

	wil_dbg_umac(vap->umac->wil, "SSID List IE\n");

	remaining = ssid_list_ie[1];
	ssid_ie = &ssid_list_ie[2];
	while (remaining >= 2) {
		if (2 + ssid_ie[1] > remaining)
			return false;
		if (wil_umac_is_ssid_match(vap, ssid_ie, false))
			return true;

		ssid_ie += (2 + ssid_ie[1]);
		remaining -= (2 + ssid_ie[1]);
	}

	return false;
}

static bool wil_umac_relock(struct wil_umac *umac,
			    struct wil_umac_node *orig_node, const u8 *mac)
{
	struct wil_umac_node *node;

	mutex_lock(&umac->mutex);

	node = wil_umac_node_find(umac, mac);
	if (!node) {
		wil_dbg_umac(umac->wil, "relock: node gone\n");
		return false;
	}
	if (node != orig_node) {
		wil_dbg_umac(umac->wil, "relock: node re-allocated\n");
		return false;
	}
	if (node->state == WIL_UMAC_NODE_STATE_DISCONNECTING) {
		wil_dbg_umac(umac->wil, "relock: node disconnecting\n");
		return false;
	}

	return true;
}

static void wil_umac_node_update_rssi(struct wil_umac_node *node, s8 rssi)
{
	node->last_rssi = rssi;
	if (rssi < node->rssi_min)
		node->rssi_min = rssi;
	if (rssi > node->rssi_max)
		node->rssi_max = rssi;
}

static bool wil_umac_rsn_valid(struct wil_umac_vap *vap, const u8 *ie)
{
	struct wil_umac *umac = vap->umac;
	size_t len = ie[1];
	u16 version, cipher_cnt;
	u32 cipher;

	/* Check the length. We assume minimum of:
	 * version, mcast cipher, and 2 selector counts with atleast one
	 * unicast cipher.
	 * Other, variable-length data, must be checked separately.
	 */

	if (len < 14) {
		wil_err(umac->wil, "RSN IE too short, len %zu\n", len);
		return false;
	}

	ie += 2;
	version = le16_to_cpu(*(__le16 *)ie);
	if (version != WIL_UMAC_SUPPORTED_RSN_VERSION) {
		wil_err(umac->wil, "RSN bad version %u\n", version);
		return false;
	}
	ie += 2;
	len -= 2;

	/* multicast/group cipher */
	cipher = le32_to_cpu(*(__le32 *)ie);
	if (cipher != WIL_UMAC_CIPHER_SUITE_GCMP) {
		wil_err(umac->wil, "RSN unsupported mcast cipher 0x%x\n",
			cipher);
		return false;
	}
	ie += 4;
	len -= 4;

	/* unicast ciphers */
	cipher_cnt = le16_to_cpu(*(__le16 *)ie);
	ie += 2;
	len -= 2;
	if (len < cipher_cnt * 4 + 2) {
		wil_err(umac->wil, "RSN ucast cipher data too short, len %zu, cipher_cnt %u\n",
			len, cipher_cnt);
		return false;
	}

	cipher = le32_to_cpu(*(__le32 *)ie);
	if (cipher != WIL_UMAC_CIPHER_SUITE_GCMP) {
		wil_err(umac->wil, "RSN unsupported ucast cipher 0x%x\n",
			cipher);
		return false;
	}

	/* followed by:
	 * key management algrorithms, optional RSN capabilities,
	 * optional XXXPMKID, optional multicast/group management frame cipher
	 */

	return true;
}

static int wil_umac_mgmt_rx_assoc_req(struct wil_umac_vap *vap, s8 rssi,
				      struct ieee80211_mgmt *frame, size_t len)
{
	struct wil_umac *umac = vap->umac;
	struct wil_umac_node *node;
	size_t ies_len;
	u8 aid, *ies, *sa = frame->sa;
	const u8 *rsn_ie, *ssid_ie;
	int rc;
	ktime_t now;

	/* frame validation */

	if (!wil_umac_is_valid_bssid(vap, frame->bssid, false)) {
		wil_dbg_umac(umac->wil, "wrong bssid (%pM). ignoring\n",
			     frame->bssid);
		return 0;
	}

	if (len < offsetof(struct ieee80211_mgmt, u.assoc_req.variable)) {
		wil_err(umac->wil, "assoc req frame too short %zu\n", len);
		return 0;
	}

	ies = frame->u.assoc_req.variable;
	ies_len = len - offsetof(struct ieee80211_mgmt, u.assoc_req.variable);

	ssid_ie = cfg80211_find_ie(WLAN_EID_SSID, ies, ies_len);
	if (!wil_umac_is_ssid_match(vap, ssid_ie, false)) {
		wil_info(umac->wil, "assoc req ssid mismatch\n");
		wil_umac_send_assoc_resp(vap, sa, 0,
					 WLAN_STATUS_REQUEST_DECLINED, false);
		return 0;
	}

	rsn_ie = cfg80211_find_ie(WLAN_EID_RSN, ies, ies_len);
	if (rsn_ie) {
		if (!vap->privacy) {
			wil_err(umac->wil, "assoc req rsn not expected\n");
			wil_umac_send_assoc_resp(vap, sa, 0,
						 WLAN_STATUS_REQUEST_DECLINED,
						 false);
			return 0;
		}
		if (!wil_umac_rsn_valid(vap, rsn_ie)) {
			wil_umac_send_assoc_resp(vap, sa, 0,
						 WLAN_STATUS_INVALID_IE,
						 false);
			return 0;
		}
	}
	if (!rsn_ie && vap->privacy)
		wil_info(umac->wil, "WPS connection\n");

	mutex_lock(&umac->mutex);

	node = wil_umac_node_find(umac, sa);
	if (node) {
		wil_info(umac->wil, "assoc req while node in state %s\n",
			 state2string(node->state));
		if (node->state == WIL_UMAC_NODE_STATE_ASSOCIATED ||
		    node->state == WIL_UMAC_NODE_STATE_8021X_OPEN) {
			if (umac->disable_ap_sme) {
				/* in userspace sme, send the frame to
				 * userspace, to clean its state
				 */
				mutex_unlock(&umac->mutex);
				return WIL_UMAC_FRAME_NOT_HANDLED;
			}

			wil_umac_node_dealloc(node);
			mutex_unlock(&umac->mutex);
			wil_umac_send_disassoc(vap, sa,
					       WLAN_REASON_UNSPECIFIED);
			return 0;
		}
		goto out;
	}

	node = wil_umac_node_alloc(vap, sa);
	if (!node) {
		wil_err(umac->wil, "cannot allocate node\n");
		mutex_unlock(&umac->mutex);
		wil_umac_send_assoc_resp(
			vap, sa, 0, WLAN_STATUS_AP_UNABLE_TO_HANDLE_NEW_STA,
			false);
		return 0;
	}

	/* update node ies */
	ies_len = min_t(size_t, ies_len, WIL_UMAC_MAX_FRAME_SIZE);
	memcpy(node->ies, ies, ies_len);
	node->ies_len = ies_len;

	wil_umac_node_update_rssi(node, rssi);

	wil_umac_node_change_state(node, WIL_UMAC_NODE_STATE_ASSOCIATING);

	now = ktime_get();
	node->stats.rx.last_activity = now;
	node->last_mgmt = now;

	if (umac->disable_ap_sme) {
		wil_dbg_umac(umac->wil, "node %pM added\n", sa);
		mutex_unlock(&umac->mutex);
		return WIL_UMAC_FRAME_NOT_HANDLED;
	}
	aid = wil_umac_aid_allocate(vap);
	if (!aid) {
		wil_err(umac->wil, "cannot allocate aid\n");
		mutex_unlock(&umac->mutex);
		wil_umac_send_assoc_resp(
			vap, sa, 0,
			WLAN_STATUS_AP_UNABLE_TO_HANDLE_NEW_STA,
			false);
		if (!wil_umac_relock(umac, node, sa))
			goto out;
		goto node_dealloc;
	}
	node->aid = aid;

	mutex_unlock(&umac->mutex);
	rc = wil_umac_send_assoc_resp(vap, sa, aid,
				      WLAN_STATUS_SUCCESS, false);
	if (!wil_umac_relock(umac, node, sa))
		/* node is disconnecting and will be freed elsewhere */
		goto out;
	if (rc)
		goto node_dealloc;

	node->assoc_ts = now;
	node->stats.tx.last_activity = now;

	if (vap->privacy)
		wil_umac_node_change_state(node,
					   WIL_UMAC_NODE_STATE_ASSOCIATED);
	else
		wil_umac_node_change_state(node,
					   WIL_UMAC_NODE_STATE_8021X_OPEN);

	mutex_unlock(&umac->mutex);
	rc = umac->rops.add_station(vap->driver_vap_ctx, node->mac, node->aid);
	if (rc) {
		wil_dbg_umac(umac->wil, "add_station failed\n");
		wil_umac_send_disassoc(vap, sa, WLAN_REASON_UNSPECIFIED);
		if (!wil_umac_relock(umac, node, sa))
			goto out;
		goto node_dealloc;
	}

	wil_dbg_umac(umac->wil, "node %pM added. aid %d\n", sa, aid);

	return 0;

node_dealloc:
	wil_umac_node_dealloc(node);
out:
	mutex_unlock(&umac->mutex);
	return 0;
}

static int wil_umac_mgmt_rx_reassoc_req(struct wil_umac_vap *vap, s8 rssi,
					struct ieee80211_mgmt *frame,
					size_t len)
{
	struct wil_umac *umac = vap->umac;
	struct wil_umac_node *node;
	size_t ies_len;
	u8 *ies, *sa = frame->sa;
	const u8 *rsn_ie, *ssid_ie;
	const u8 *md_ie, *ft_ie;
	ktime_t now;

	/* frame validation */

	if (!wil_umac_is_valid_bssid(vap, frame->bssid, false)) {
		wil_dbg_umac(umac->wil, "wrong bssid (%pM). ignoring\n",
			     frame->bssid);
		return 0;
	}

	if (len < offsetof(struct ieee80211_mgmt, u.reassoc_req.variable)) {
		wil_err(umac->wil, "reassoc req frame too short %zu\n", len);
		return 0;
	}

	if (!umac->disable_ap_sme) {
		wil_err(umac->wil, "reassoc req not supported in ap_sme\n");
		wil_umac_send_assoc_resp(vap, sa, 1,
					 WLAN_STATUS_REQUEST_DECLINED,
					 true);
		return 0;
	}

	ies = frame->u.reassoc_req.variable;
	ies_len = len - offsetof(struct ieee80211_mgmt, u.reassoc_req.variable);

	mutex_lock(&umac->mutex);

	node = wil_umac_node_find(umac, sa);
	if (!node) {
		wil_err(umac->wil,
			"reassoc req is supported only in FT roam\n");
		mutex_unlock(&umac->mutex);
		wil_umac_send_assoc_resp(vap, sa, 1,
					 WLAN_STATUS_REQUEST_DECLINED,
					 true);
		return 0;
	}

	if (node->state != WIL_UMAC_NODE_STATE_AUTHENTICATED) {
		wil_err(umac->wil, "reassoc req while node in state %s\n",
			state2string(node->state));
		goto out;
	}

	ssid_ie = cfg80211_find_ie(WLAN_EID_SSID, ies, ies_len);
	if (!wil_umac_is_ssid_match(vap, ssid_ie, false)) {
		wil_err(umac->wil, "reassoc req ssid mismatch\n");
		goto out;
	}

	rsn_ie = cfg80211_find_ie(WLAN_EID_RSN, ies, ies_len);
	if (rsn_ie) {
		if (!vap->privacy) {
			wil_err(umac->wil, "reassoc req rsn not expected\n");
			goto out;
		}
		if (!wil_umac_rsn_valid(vap, rsn_ie))
			goto out;
	} else if (vap->privacy) {
		wil_err(umac->wil,
			"rsn ie must be included in reassoc frame when privacy is on\n");
		goto out;
	}

	/* check mde and fte ies in reassoc req frame */
	md_ie = cfg80211_find_ie(WLAN_EID_MOBILITY_DOMAIN, ies, ies_len);
	if (!md_ie) {
		wil_err(umac->wil,
			"mobility domain (MD) ie was not found in reassoc req\n");
		goto out;
	}

	ft_ie = cfg80211_find_ie(WLAN_EID_FAST_BSS_TRANSITION, ies, ies_len);
	if (!ft_ie) {
		wil_err(umac->wil,
			"fast transition (FT) ie was not found in reassoc req\n");
		goto out;
	}

	/* update node ies */
	ies_len = min_t(size_t, ies_len, WIL_UMAC_MAX_FRAME_SIZE);
	memcpy(node->ies, ies, ies_len);
	node->ies_len = ies_len;

	wil_umac_node_update_rssi(node, rssi);
	now = ktime_get();
	node->stats.rx.last_activity = now;
	node->last_mgmt = now;

	wil_umac_node_change_state(node, WIL_UMAC_NODE_STATE_ASSOCIATING);
out:
	mutex_unlock(&umac->mutex);

	return WIL_UMAC_FRAME_NOT_HANDLED;
}

/* this function handle receiving deauth and disassoc frames */
static int wil_umac_mgmt_rx_disassoc(struct wil_umac_vap *vap,
				     struct ieee80211_mgmt *frame, size_t len,
				     bool deauth)
{
	struct wil_umac *umac = vap->umac;
	struct wil_umac_node *node;
	u16 reason;
	size_t min_len;

	/* frame validation */
	if (!wil_umac_is_valid_bssid(vap, frame->bssid, false)) {
		wil_dbg_umac(umac->wil, "wrong bssid (%pM). ignoring\n",
			     frame->bssid);
		return 0;
	}

	if (deauth)
		min_len = offsetof(struct ieee80211_mgmt,
				   u.deauth.reason_code) +
				   sizeof(frame->u.deauth.reason_code);
	else
		min_len = offsetof(struct ieee80211_mgmt,
				   u.disassoc.reason_code) +
				   sizeof(frame->u.disassoc.reason_code);

	if (len < min_len) {
		wil_dbg_umac(umac->wil, "frame too short %zu\n", len);
		return 0;
	}

	mutex_lock(&umac->mutex);

	node = wil_umac_node_find(umac, frame->sa);
	if (!node) {
		wil_dbg_umac(umac->wil, "%s from unknown sta (%pM)\n",
			     deauth ? "deauth" : "disassoc", frame->sa);
		goto out;
	}

	if (node->state == WIL_UMAC_NODE_STATE_DISCONNECTING) {
		wil_dbg_umac(umac->wil, "node %pM already disassociating\n",
			     frame->sa);
		mutex_unlock(&umac->mutex);
		return WIL_UMAC_FRAME_NOT_HANDLED;
	}

	wil_umac_node_change_state(node, WIL_UMAC_NODE_STATE_DISCONNECTING);

	if (deauth)
		reason = le16_to_cpu(frame->u.deauth.reason_code);
	else
		reason = le16_to_cpu(frame->u.disassoc.reason_code);

	wil_dbg_umac(umac->wil, "node %pM disassociating, reason %d\n",
		     frame->sa, reason);

	mutex_unlock(&umac->mutex);

	if (umac->disable_ap_sme)
		return WIL_UMAC_FRAME_NOT_HANDLED;

	umac->rops.del_station(vap->driver_vap_ctx, frame->sa, reason);
	/* node object is gone (freed in sta_deleted) */

	return 0;

out:
	mutex_unlock(&umac->mutex);
	return 0;
}

static int wil_umac_mgmt_rx_probe_req(struct wil_umac_vap *vap,
				      struct ieee80211_mgmt *frame, size_t len)
{
	struct wil_umac *umac = vap->umac;
	u8 *ies;
	size_t ies_len;
	const u8 *ssid_ie;

	/* validate the frame */

	if (!wil_umac_is_valid_bssid(vap, frame->bssid, true)) {
		wil_dbg_umac(umac->wil, "wrong bssid (%pM). ignoring\n",
			     frame->bssid);
		return 0;
	}

	if (len < offsetof(struct ieee80211_mgmt, u.probe_req.variable)) {
		wil_dbg_umac(umac->wil, "probe req frame too short %zu\n",
			     len);
		return 0;
	}

	ies = frame->u.probe_req.variable;
	ies_len = len - offsetof(struct ieee80211_mgmt, u.probe_req.variable);

	/* check SSID */
	ssid_ie = cfg80211_find_ie(WLAN_EID_SSID, ies, ies_len);
	if (!wil_umac_is_ssid_match(vap, ssid_ie, true)) {
		ssid_ie = cfg80211_find_ie(WLAN_EID_SSID_LIST, ies, ies_len);
		if (!wil_umac_is_ssid_list_match(vap, ssid_ie)) {
			wil_dbg_umac(umac->wil, "probe req ssid mismatch\n");
			return 0;
		}
	}

	wil_umac_send_probe_resp(vap, frame->sa);

	return 0;
}

static int wil_umac_mgmt_rx_auth(struct wil_umac_vap *vap, s8 rssi,
				 struct ieee80211_mgmt *frame, size_t len)
{
	struct wil_umac *umac = vap->umac;
	struct wil_umac_node *node;
	size_t ies_len;
	u8 *ies, *sa = frame->sa;
	const u8 *md_ie, *ft_ie;
	u16 auth_alg, auth_transaction, status_code;
	ktime_t now;

	/* frame validation */
	if (!wil_umac_is_valid_bssid(vap, frame->bssid, false)) {
		wil_dbg_umac(umac->wil, "wrong bssid (%pM). ignoring\n",
			     frame->bssid);
		return 0;
	}

	if (len < offsetof(struct ieee80211_mgmt, u.auth.variable)) {
		wil_err(umac->wil, "auth frame too short %zu\n", len);
		return 0;
	}

	auth_alg = le16_to_cpu(frame->u.auth.auth_alg);
	if (auth_alg != WLAN_AUTH_FT) {
		wil_err(umac->wil, "auth frame supports only FT auth. received auth %d\n",
			auth_alg);
		wil_umac_send_auth(vap, sa, auth_alg, 2,
				   WLAN_REASON_UNSPECIFIED);
		return 0;
	}

	auth_transaction = le16_to_cpu(frame->u.auth.auth_transaction);
	if (auth_transaction != 1) {
		wil_err(umac->wil, "auth frame: invalid auth_transaction %d\n",
			auth_transaction);
		wil_umac_send_auth(vap, sa, WLAN_AUTH_FT, 2,
				   WLAN_REASON_UNSPECIFIED);
		return 0;
	}

	status_code = le16_to_cpu(frame->u.auth.status_code);
	if (status_code != 0) {
		wil_err(umac->wil, "auth frame: status_code %d. ignore\n",
			status_code);
		return 0;
	}

	if (!umac->disable_ap_sme) {
		wil_err(umac->wil, "auth frame not supported in ap_sme\n");
		wil_umac_send_auth(vap, sa, WLAN_AUTH_FT, 2,
				   WLAN_REASON_UNSPECIFIED);
		return 0;
	}

	ies = frame->u.auth.variable;
	ies_len = len - offsetof(struct ieee80211_mgmt, u.auth.variable);

	/* check mde and fte ies in auth req frame */
	md_ie = cfg80211_find_ie(WLAN_EID_MOBILITY_DOMAIN, ies, ies_len);
	if (!md_ie) {
		wil_err(umac->wil,
			"mobility domain (MDE) ie was not found in auth req\n");
		wil_umac_send_auth(vap, sa, WLAN_AUTH_FT, 2,
				   WLAN_REASON_UNSPECIFIED);
		return 0;
	}

	ft_ie = cfg80211_find_ie(WLAN_EID_FAST_BSS_TRANSITION, ies, ies_len);
	if (!ft_ie) {
		wil_err(umac->wil,
			"fast transition (FT) ie was not found in auth req\n");
		wil_umac_send_auth(vap, sa, WLAN_AUTH_FT, 2,
				   WLAN_REASON_UNSPECIFIED);
		return 0;
	}

	mutex_lock(&umac->mutex);

	node = wil_umac_node_find(umac, sa);
	if (node) {
		wil_err(umac->wil, "auth req while node in state %s\n",
			state2string(node->state));
		/* in disable_ap_sme, send the frame to
		 * userspace, to clean its state
		 */
		mutex_unlock(&umac->mutex);
		return WIL_UMAC_FRAME_NOT_HANDLED;
	}

	node = wil_umac_node_alloc(vap, sa);
	if (!node) {
		wil_err(umac->wil, "cannot allocate node\n");
		mutex_unlock(&umac->mutex);
		wil_umac_send_auth(vap, sa, WLAN_AUTH_FT, 2,
				   WLAN_STATUS_REQUEST_DECLINED);
		return 0;
	}

	/* update node ies */
	ies_len = min_t(size_t, ies_len, WIL_UMAC_MAX_FRAME_SIZE);
	memcpy(node->ies, ies, ies_len);
	node->ies_len = ies_len;

	node->auth_type = auth_alg;
	wil_umac_node_update_rssi(node, rssi);

	wil_umac_node_change_state(node, WIL_UMAC_NODE_STATE_AUTHENTICATING);

	now = ktime_get();
	node->stats.rx.last_activity = now;
	node->last_mgmt = now;

	mutex_unlock(&umac->mutex);

	return WIL_UMAC_FRAME_NOT_HANDLED;
}

static int wil_umac_mgmt_rx(void *vap_handle, s8 rssi, u8 channel,
			    struct ieee80211_mgmt *frame, size_t len)
{
	struct wil_umac_vap *vap = vap_handle;
	struct wil_umac *umac = vap->umac;
	int rc = WIL_UMAC_FRAME_NOT_HANDLED;
	u16 fc;

	if (len < offsetof(struct ieee80211_mgmt, seq_ctrl)) {
		wil_dbg_umac(umac->wil, "rx frame too short %zu\n", len);
		return WIL_UMAC_FRAME_NOT_HANDLED;
	}

	if (!ieee80211_is_mgmt(frame->frame_control))
		return WIL_UMAC_FRAME_NOT_HANDLED;

	if (!ether_addr_equal(frame->da, vap->ndev->dev_addr)) {
		wil_dbg_umac(umac->wil, "wrong DA (%pM). ignoring\n",
			     frame->da);
		return WIL_UMAC_FRAME_NOT_HANDLED;
	}

	fc = le16_to_cpu(frame->frame_control);
	wil_dbg_umac(umac->wil, "handling %s from %pM, rssi %d len %zu\n",
		     stype2string(fc & IEEE80211_FCTL_STYPE), frame->sa,
		     rssi, len);

	switch (fc & IEEE80211_FCTL_STYPE) {
	case IEEE80211_STYPE_ASSOC_REQ:
		rc = wil_umac_mgmt_rx_assoc_req(vap, rssi, frame, len);
		break;
	case IEEE80211_STYPE_REASSOC_REQ:
		rc = wil_umac_mgmt_rx_reassoc_req(vap, rssi, frame, len);
		break;
	case IEEE80211_STYPE_PROBE_REQ:
		rc = wil_umac_mgmt_rx_probe_req(vap, frame, len);
		break;
	case IEEE80211_STYPE_DISASSOC:
		rc = wil_umac_mgmt_rx_disassoc(vap, frame, len, false);
		break;
	case IEEE80211_STYPE_AUTH:
		rc = wil_umac_mgmt_rx_auth(vap, rssi, frame, len);
		break;
	case IEEE80211_STYPE_DEAUTH:
		rc = wil_umac_mgmt_rx_disassoc(vap, frame, len, true);
		break;
	case IEEE80211_STYPE_ACTION:
		/* note: most action frames (Class 3) allowed only when
		 * associated
		 */
		break;
	default:
		break;
	}

	return rc;
}

static int wil_umac_mgmt_tx_assoc_resp(struct wil_umac_vap *vap,
				       struct ieee80211_mgmt *frame,
				       size_t len, bool reassoc)
{
	struct wil_umac *umac = vap->umac;
	struct wil_umac_node *node;
	u8 aid, *da = frame->da;
	ktime_t now;
	u16 status_code;
	int rc;

	if (len < offsetof(struct ieee80211_mgmt, u.assoc_resp.variable)) {
		wil_err(umac->wil, "%sassoc resp frame too short %zu\n",
			reassoc ? "re" : "", len);
		return -EINVAL;
	}

	aid = le16_to_cpu(frame->u.assoc_resp.aid);
	status_code = le16_to_cpu(frame->u.assoc_resp.status_code);

	mutex_lock(&umac->mutex);

	node = wil_umac_node_find(umac, da);
	if (!node) {
		wil_err(umac->wil, "%sassoc resp to %pM. node not found\n",
			reassoc ? "re" : "", da);
		goto fail;
	}

	if (node->state != WIL_UMAC_NODE_STATE_ASSOCIATING) {
		wil_err(umac->wil, "%sassoc resp while node in state %s\n",
			reassoc ? "re" : "", state2string(node->state));
		goto fail;
	}

	if (reassoc && node->auth_type != WLAN_AUTH_FT) {
		wil_err(umac->wil,
			"reassoc resp to %pM. reassoc supported only with FT authentication\n",
			da);
		goto fail;
	}

	if (!reassoc && node->auth_type == WLAN_AUTH_FT) {
		wil_err(umac->wil,
			"assoc resp to %pM with FT auth. assoc is not supported with FT authentication\n",
			da);
		goto fail;
	}

	now = ktime_get();
	if (status_code == 0) {
		if (vap->privacy)
			wil_umac_node_change_state(
				node,
				WIL_UMAC_NODE_STATE_ASSOCIATED);
		else
			wil_umac_node_change_state(
				node,
				WIL_UMAC_NODE_STATE_8021X_OPEN);

		node->aid = aid;
		node->assoc_ts = now;
		node->stats.tx.last_activity = now;
	} else {
		wil_err(umac->wil,
			"%sassoc resp with fail status %d\n",
			reassoc ? "re" : "", status_code);
		if (!reassoc) {
			wil_umac_node_dealloc(node);
		} else {
			node->stats.tx.last_activity = now;
			wil_umac_node_change_state(
				node, WIL_UMAC_NODE_STATE_AUTHENTICATED);
		}
	}

	mutex_unlock(&umac->mutex);

	rc = umac->rops.mgmt_tx(vap->driver_vap_ctx, (u8 *)frame,
				len);
	if (rc)
		wil_err(umac->wil, "fail to transmit %sassoc response, da %pM (rc %d)\n",
			reassoc ? "re" : "", da, rc);
	else
		wil_dbg_umac(umac->wil,
			     "transmit %sassoc response, da %pM aid %d status_code %d\n",
			     reassoc ? "re" : "", da, aid, status_code);

	return rc;

fail:
	mutex_unlock(&umac->mutex);

	return -EINVAL;
}

static int wil_umac_mgmt_tx_disassoc(struct wil_umac_vap *vap,
				     struct ieee80211_mgmt *frame,
				     size_t len, bool deauth)
{
	struct wil_umac *umac = vap->umac;
	struct wil_umac_node *node;
	u8 *da = frame->da;
	u16 reason;
	int rc;
	size_t min_len;

	if (deauth)
		min_len = offsetof(struct ieee80211_mgmt,
				   u.deauth.reason_code) +
				   sizeof(frame->u.deauth.reason_code);
	else
		min_len = offsetof(struct ieee80211_mgmt,
				   u.disassoc.reason_code) +
				   sizeof(frame->u.disassoc.reason_code);

	if (len < min_len) {
		wil_dbg_umac(umac->wil, "%s frame too short %zu\n",
			     deauth ? "deauth" : "disassoc", len);
		return 0;
	}

	mutex_lock(&umac->mutex);

	if (deauth)
		reason = le16_to_cpu(frame->u.deauth.reason_code);
	else
		reason = le16_to_cpu(frame->u.disassoc.reason_code);

	wil_dbg_umac(umac->wil, "node %pM disassociating, reason %d\n",
		     frame->da, reason);

	if (!is_broadcast_ether_addr(frame->da)) {
		node = wil_umac_node_find(umac, frame->da);
		if (!node) {
			wil_dbg_umac(umac->wil, "disassoc unknown sta (%pM)\n",
				     frame->da);

			mutex_unlock(&umac->mutex);
			/* do not transmit the frame to its da */
			return 0;
		}

		wil_umac_node_dealloc(node);
	} else {
		/* disconnect all */
		do {
			struct wil_umac_node *node;

			node = wil_umac_first_connected_node(umac);
			if (!node)
				break;
			wil_umac_node_dealloc(node);
		} while (1);
	}
	mutex_unlock(&umac->mutex);

	/* transmit the frame to its da */
	rc = umac->rops.mgmt_tx(vap->driver_vap_ctx, (u8 *)frame, len);
	if (rc)
		wil_err(umac->wil,
			"fail to transmit %s frame, da %pM (rc %d)\n",
			deauth ? "deauth" : "disassoc", da, rc);
	else
		wil_dbg_umac(umac->wil,
			     "transmit %s frame, da %pM\n",
			     deauth ? "deauth" : "disassoc", da);

	return rc;
}

static int wil_umac_mgmt_tx_auth(struct wil_umac_vap *vap,
				 struct ieee80211_mgmt *frame,
				 size_t len)
{
	struct wil_umac *umac = vap->umac;
	struct wil_umac_node *node;
	u8 *da = frame->da;
	int rc;
	u16 status_code, auth_transaction;
	ktime_t now;

	if (len < offsetof(struct ieee80211_mgmt, u.auth.variable)) {
		wil_err(umac->wil, "auth resp frame too short %zu\n", len);
		return -EINVAL;
	}

	status_code = le16_to_cpu(frame->u.auth.status_code);
	auth_transaction = le16_to_cpu(frame->u.auth.auth_transaction);

	mutex_lock(&umac->mutex);

	node = wil_umac_node_find(umac, da);
	if (!node) {
		wil_err(umac->wil, "auth resp to %pM. node not found\n", da);
		mutex_unlock(&umac->mutex);
		return -EINVAL;
	}

	if (node->state != WIL_UMAC_NODE_STATE_AUTHENTICATING) {
		wil_err(umac->wil, "auth resp while node in state %s\n",
			state2string(node->state));
		mutex_unlock(&umac->mutex);
		return -EINVAL;
	}

	if (status_code == 0) {
		wil_umac_node_change_state(node,
					   WIL_UMAC_NODE_STATE_AUTHENTICATED);

		now = ktime_get();
		node->stats.tx.last_activity = now;
	} else {
		wil_err(umac->wil,
			"auth resp with status 0x%x. delete %pM node\n",
			status_code, da);
		wil_umac_node_dealloc(node);
	}

	mutex_unlock(&umac->mutex);

	rc = umac->rops.mgmt_tx(vap->driver_vap_ctx, (u8 *)frame, len);
	if (rc)
		wil_err(umac->wil, "fail to transmit auth frame, da %pM (rc %d)\n",
			da, rc);
	else
		wil_dbg_umac(umac->wil,
			     "transmit auth frame, da %pM  status_code %d auth_transaction %d\n",
			     da, status_code, auth_transaction);

	return rc;
}

static int wil_umac_mgmt_tx(void *vap_handle, const u8 *buf, size_t len)
{
	struct ieee80211_mgmt *frame = (struct ieee80211_mgmt *)buf;
	struct wil_umac_vap *vap = vap_handle;
	struct wil_umac *umac = vap->umac;
	int rc = WIL_UMAC_FRAME_NOT_HANDLED;
	u16 fc;
	bool reassoc = false;

	if (len < offsetof(struct ieee80211_mgmt, seq_ctrl)) {
		wil_dbg_umac(umac->wil, "tx frame too short %zu\n", len);
		return WIL_UMAC_FRAME_NOT_HANDLED;
	}

	if (!ieee80211_is_mgmt(frame->frame_control))
		return WIL_UMAC_FRAME_NOT_HANDLED;

	fc = le16_to_cpu(frame->frame_control);
	wil_dbg_umac(umac->wil, "handling %s to %pM, len %zu\n",
		     stype2string(fc & IEEE80211_FCTL_STYPE), frame->da, len);

	wil_hex_dump_umac("umac mgmt tx ", DUMP_PREFIX_OFFSET, 16, 1, buf,
			  len, true);

	if (!umac->disable_ap_sme) {
		wil_dbg_umac(umac->wil,
			     "tx %s frame in disable ap sme\n",
			     stype2string(fc & IEEE80211_FCTL_STYPE));
		return WIL_UMAC_FRAME_NOT_HANDLED;
	}

	switch (fc & IEEE80211_FCTL_STYPE) {
	case IEEE80211_STYPE_REASSOC_RESP:
		reassoc = true;
		/* fallthrough */
	case IEEE80211_STYPE_ASSOC_RESP:
		rc = wil_umac_mgmt_tx_assoc_resp(vap, frame, len, reassoc);
		break;
	case IEEE80211_STYPE_PROBE_REQ:
		break;
	case IEEE80211_STYPE_DISASSOC:
		rc = wil_umac_mgmt_tx_disassoc(vap, frame, len, false);
		break;
	case IEEE80211_STYPE_AUTH:
		rc = wil_umac_mgmt_tx_auth(vap, frame, len);
		break;
	case IEEE80211_STYPE_DEAUTH:
		rc = wil_umac_mgmt_tx_disassoc(vap, frame, len, true);
		break;
	case IEEE80211_STYPE_ACTION:
		/* note: most action frames (Class 3) allowed only when
		 * associated
		 */
		break;
	default:
		break;
	}

	return rc;
}

static void wil_umac_disconnect_one_sta(void *vap_handle, const u8 *mac,
					u16 reason)
{
	struct wil_umac_vap *vap = vap_handle;
	struct wil_umac *umac = vap->umac;
	struct wil_umac_node *node;

	mutex_lock(&umac->mutex);

	node = wil_umac_node_find(umac, mac);
	if (!node) {
		wil_dbg_umac(umac->wil, "disconnect unknown sta (%pM)\n", mac);
		goto out;
	}

	if (node->state == WIL_UMAC_NODE_STATE_DISCONNECTING) {
		wil_dbg_umac(umac->wil, "node %pM already disconnecting\n",
			     mac);
		goto out;
	}

	wil_dbg_umac(umac->wil, "disconnecting node %pM, reason %d\n",
		     mac, reason);
	wil_umac_node_change_state(node, WIL_UMAC_NODE_STATE_DISCONNECTING);

	mutex_unlock(&umac->mutex);
	wil_umac_send_disassoc(vap, mac, reason);

	return;

out:
	mutex_unlock(&umac->mutex);
}

static void wil_umac_disconnect_sta(void *vap_handle, const u8 *mac,
				    u16 reason)
{
	struct wil_umac_vap *vap = vap_handle;
	struct wil_umac *umac = vap->umac;

	if (mac) {
		wil_umac_disconnect_one_sta(vap_handle, mac, reason);
		return;
	}

	/* disconnect all */
	do {
		struct wil_umac_node *node;

		mutex_lock(&umac->mutex);
		node = wil_umac_first_connected_node(umac);
		if (!node) {
			mutex_unlock(&umac->mutex);
			break;
		}
		mac = node->mac;
		mutex_unlock(&umac->mutex);
		wil_umac_disconnect_one_sta(vap_handle, mac, reason);
	} while (1);
}

static void wil_umac_sta_deleted(void *vap_handle, const u8 *mac)
{
	struct wil_umac_vap *vap = vap_handle;
	struct wil_umac *umac = vap->umac;
	struct wil_umac_node *node;

	mutex_lock(&umac->mutex);

	node = wil_umac_node_find(umac, mac);
	if (!node)
		goto out;

	wil_dbg_umac(umac->wil, "removing node %pM, aid %d state %s\n",
		     node->mac, node->aid, state2string(node->state));

	switch (node->state) {
	case WIL_UMAC_NODE_STATE_ASSOCIATING:
		mutex_unlock(&umac->mutex);
		wil_umac_send_assoc_resp(vap, mac, 0,
					 WLAN_STATUS_ASSOC_DENIED_UNSPEC,
					 false);
		if (!wil_umac_relock(umac, node, mac))
			/* node will be freed elsewhere */
			goto out;
		break;
	case WIL_UMAC_NODE_STATE_ASSOCIATED:
	case WIL_UMAC_NODE_STATE_8021X_OPEN:
		mutex_unlock(&umac->mutex);
		wil_umac_send_disassoc(vap, mac, WLAN_REASON_UNSPECIFIED);
		if (!wil_umac_relock(umac, node, mac))
			/* node will be freed elsewhere */
			goto out;
		break;
	default:
		break;
	}

	wil_umac_node_dealloc(node);

out:
	mutex_unlock(&umac->mutex);
}

static int wil_umac_add_key(void *vap_handle, u8 key_index, bool pairwise,
			    const u8 *mac)
{
	struct wil_umac_vap *vap = vap_handle;
	struct wil_umac *umac = vap->umac;
	struct wil_umac_node *node;
	int rc = 0;

	if (!pairwise) {
		wil_dbg_umac(umac->wil, "add_key GTK\n");
		return 0;
	}

	mutex_lock(&umac->mutex);

	node = wil_umac_node_find(umac, mac);
	if (!node) {
		wil_err(umac->wil, "add_key for unknown sta (%pM)\n", mac);
		rc = -ENOENT;
		goto out;
	}

	if (node->state == WIL_UMAC_NODE_STATE_8021X_OPEN) {
		wil_dbg_umac(umac->wil, "re-key for node %pM\n", mac);
		goto out;
	}

	if (!vap->privacy || node->state != WIL_UMAC_NODE_STATE_ASSOCIATED) {
		wil_err(umac->wil, "add_key in wrong state.  node %pM, privacy %d, state %s\n",
			mac, vap->privacy, state2string(node->state));
		rc = -EINVAL;
		goto out;
	}

	wil_dbg_umac(umac->wil, "add_key PTK for node %pM, key_index %d\n", mac,
		     key_index);
	wil_umac_node_change_state(node, WIL_UMAC_NODE_STATE_8021X_OPEN);

out:
	mutex_unlock(&umac->mutex);
	return rc;
}

static int wil_umac_del_key(void *vap_handle, u8 key_index, bool pairwise,
			    const u8 *mac)
{
	struct wil_umac_vap *vap = vap_handle;
	struct wil_umac *umac = vap->umac;
	struct wil_umac_node *node;

	if (!pairwise) {
		wil_dbg_umac(umac->wil, "del_key GTK\n");
		return 0;
	}

	mutex_lock(&umac->mutex);

	node = wil_umac_node_find(umac, mac);
	if (!vap->privacy || !node ||
	    node->state != WIL_UMAC_NODE_STATE_8021X_OPEN)
		/* silently ignore */
		goto out;

	wil_dbg_umac(umac->wil, "del_key for node %pM, key_index %d\n", mac,
		     key_index);
	wil_umac_node_change_state(node, WIL_UMAC_NODE_STATE_ASSOCIATED);

out:
	mutex_unlock(&umac->mutex);
	return 0;
}

static int wil_umac_tx_notify(void *umac_handle, void *vap_handle,
			      struct sk_buff *skb)
{
	struct wil_umac_vap *vap = vap_handle;
	struct wil_umac *umac = umac_handle;
	struct wil_umac_node *node = NULL;
	struct ethhdr *eth = (void *)skb->data;
	const u8 *mac;
	int key, rc = 0;

	atomic_inc(&umac->async_cnt);

	/* check vap still alive */
	if (!vap->valid) {
		wil_dbg_umac(umac->wil, "vap is gone\n");
		rc = -ENOENT;
		goto out;
	}

	mac = eth->h_dest;

	if (is_broadcast_ether_addr(mac)) {
		vap->stats.bcast_tx_packets++;
		vap->stats.bcast_tx_bytes += skb->len;

		goto out;
	}

	key = WIL_UMAC_NODE_HASH(mac);
	hash_for_each_possible(umac->node_hash, node, hlist, key)
		if (ether_addr_equal(node->mac, mac)) {
			WARN_ON(node->vap != vap);
			break;
		}

	if (!node) {
		rc = -ENOENT;
		goto out;
	}

	if (node->state != WIL_UMAC_NODE_STATE_8021X_OPEN &&
	    node->state != WIL_UMAC_NODE_STATE_ASSOCIATED) {
		rc = -EINVAL;
		goto out;
	}

	/* update statistics */
	node->stats.tx.packets++;
	node->stats.tx.bytes += skb->len;
	node->stats.tx.last_activity = ktime_get();

out:
	atomic_dec(&umac->async_cnt);
	return rc;
}

static int wil_umac_rx_notify(void *umac_handle, void *vap_handle,
			      struct sk_buff *skb)
{
	struct wil_umac_vap *vap = vap_handle;
	struct wil_umac *umac = umac_handle;
	struct wil_umac_node *node = NULL;
	struct ethhdr *eth = (void *)skb->data;
	const u8 *mac;
	int key, rc = 0;

	atomic_inc(&umac->async_cnt);

	/* check vap still alive */
	if (!vap->valid) {
		wil_dbg_umac(umac->wil, "vap is gone\n");
		rc = -ENOENT;
		goto out;
	}

	mac = eth->h_source;
	key = WIL_UMAC_NODE_HASH(mac);
	hash_for_each_possible(umac->node_hash, node, hlist, key)
		if (ether_addr_equal(node->mac, mac)) {
			WARN_ON(node->vap != vap);
			break;
		}

	if (!node) {
		rc = -ENOENT;
		goto out;
	}

	if (node->state != WIL_UMAC_NODE_STATE_8021X_OPEN &&
	    node->state != WIL_UMAC_NODE_STATE_ASSOCIATED) {
		rc = -EINVAL;
		goto out;
	}

	/* update statistics */
	node->stats.rx.packets++;
	node->stats.rx.bytes += skb->len;
	node->stats.rx.last_activity = ktime_get();

out:
	atomic_dec(&umac->async_cnt);
	return rc;
}

static void wil_umac_uninit(void *umac_handle)
{
	struct wil_umac *umac = umac_handle;
	int i;

	wil_dbg_umac(umac->wil, "umac uninit\n");

	del_timer_sync(&umac->inact_timer);
	cancel_work_sync(&umac->inact_worker);
	destroy_workqueue(umac->workq);

	mutex_lock(&umac->mutex);

	for (i = 0; i < umac->max_vaps; i++)
		if (umac->vaps[i].valid)
			wil_umac_vap_remove(&umac->vaps[i]);

	kfree(umac->node_array);
	kfree(umac->vaps);

	mutex_unlock(&umac->mutex);

	platform_device_unregister(umac->pdev);

	kfree(umac);
}

/* callbacks from external drivers into UMAC */
static struct wil_umac_node *wil_umac_node_get(void *umac_handle, const u8 *mac)
{
	struct wil_umac *umac = umac_handle;
	int key;
	struct wil_umac_node *node = NULL;

	if (!umac)
		return NULL;

	wil_dbg_umac(umac->wil, "node get %pM", mac);

	key = WIL_UMAC_NODE_HASH(mac);
	hash_for_each_possible(umac->node_hash, node, hlist, key)
		if (ether_addr_equal(node->mac, mac))
			break;
	if (!node)
		return NULL;

	return kref_get_unless_zero(&node->refcount) ? node : NULL;
}

static void wil_umac_node_put(void *umac_handle, struct wil_umac_node *node)
{
	struct wil_umac *umac = umac_handle;

	if (!umac || !node)
		return;

	wil_dbg_umac(umac->wil, "node put %pM", node->mac);

	kref_put(&node->refcount, wil_umac_node_release);
}

static struct wil_umac_ops wil_umac_ops = {
	.uninit = wil_umac_uninit,
	.vap_add = wil_umac_vap_add,
	.vap_remove = wil_umac_vap_remove,
	.start_ap = wil_umac_start_ap,
	.stop_ap = wil_umac_stop_ap,
	.vap_set_ie = wil_umac_vap_set_ie,
	.mgmt_rx = wil_umac_mgmt_rx,
	.mgmt_tx = wil_umac_mgmt_tx,
	.disconnect_sta = wil_umac_disconnect_sta,
	.sta_deleted = wil_umac_sta_deleted,
	.add_key = wil_umac_add_key,
	.del_key = wil_umac_del_key,
	.tx_notify = wil_umac_tx_notify,
	.rx_notify = wil_umac_rx_notify,
};

void *wil_umac_init(struct wil6210_priv *wil, u8 *permanent_mac,
		    size_t max_vaps, size_t max_sta, bool disable_ap_sme,
		    struct wil_umac_ops *ops,
		    const struct wil_umac_rops *rops)
{
	struct wil_umac *umac = NULL;
	int rc;
	struct wil_umac_platdata pdata;

	wil_dbg_umac(wil, "umac init\n");

	if (!ops || !rops)
		return NULL;

	umac = kzalloc(sizeof(*umac), GFP_KERNEL);
	if (!umac)
		return NULL;

	umac->wil = wil;
	umac->disable_ap_sme = disable_ap_sme;
	ether_addr_copy(umac->permanent_mac, permanent_mac);
	umac->max_vaps = max_vaps;
	umac->vaps = kcalloc(max_vaps, sizeof(struct wil_umac_vap),
			     GFP_KERNEL);
	if (!umac->vaps)
		goto err;

	umac->max_sta = max_sta;
	umac->node_array = kcalloc(max_sta, sizeof(struct wil_umac_node),
				   GFP_KERNEL);
	if (!umac->node_array)
		goto err;

	umac->workq = create_singlethread_workqueue(WIL_NAME "_umac");
	if (!umac->workq)
		goto err;
	INIT_WORK(&umac->inact_worker, wil_umac_inact_worker);

	umac->pdev = platform_device_alloc("wil_umac", PLATFORM_DEVID_AUTO);
	if (!umac->pdev)
		goto err;

	pdata.ops.node_get = &wil_umac_node_get;
	pdata.ops.node_put = &wil_umac_node_put;
	pdata.umac_handle = umac;
	rc = platform_device_add_data(umac->pdev, &pdata, sizeof(pdata));
	if (rc)
		goto err;
	rc = platform_device_add(umac->pdev);
	if (rc) {
		wil_err(wil, "failed to add platform device, err %d\n", rc);
		goto err;
	}

	setup_timer(&umac->inact_timer, wil_umac_inact_fn, (ulong)umac);
	if (WIL_UMAC_NODE_INACTIVITY_MS)
		mod_timer(&umac->inact_timer,
			  jiffies +
				msecs_to_jiffies(WIL_UMAC_NODE_INACTIVITY_MS));

	hash_init(umac->node_hash);
	mutex_init(&umac->mutex);

	*ops = wil_umac_ops;
	umac->rops = *rops;

	return umac;

err:
	if (umac->pdev)
		platform_device_put(umac->pdev);
	if (umac->workq)
		destroy_workqueue(umac->workq);
	kfree(umac->node_array);
	kfree(umac->vaps);
	kfree(umac);

	return NULL;
}
