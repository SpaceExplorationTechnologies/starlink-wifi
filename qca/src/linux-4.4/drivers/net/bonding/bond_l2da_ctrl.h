/* Copyright (c) 2016, The Linux Foundation. All rights reserved.
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

#ifndef __BOND_L2DA_CTRL_H__
#define __BOND_L2DA_CTRL_H__

int  _bond_l2da_ctrl_try_lock(struct bonding *bond, bool set);
void _bond_l2da_ctrl_unlock(struct bonding *bond, bool set);

int bond_l2da_ctrl_set_default(struct bonding *bond, const char *slave_ifname);
int bond_l2da_ctrl_get_default(struct bonding *bond, char *buf, int size);
int bond_l2da_ctrl_change_map_entry(struct bonding *bond, const u8 *da,
				    const char *slave_ifname);
int bond_l2da_ctrl_reset_map(struct bonding *bond);
int bond_l2da_ctrl_set_opts(struct bonding *bond, u32 opts);
int bond_l2da_ctrl_get_opts(struct bonding *bond, u32 *opts);

#endif /* __BOND_L2DA_CTRL_H__ */
