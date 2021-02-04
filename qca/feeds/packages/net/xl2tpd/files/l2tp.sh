#!/bin/sh
# Copyright (c) 2018, The Linux Foundation. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

[ -x /usr/sbin/xl2tpd ] || exit 0

[ -n "$INCLUDE_ONLY" ] || {
	. /lib/functions.sh
	. ../netifd-proto.sh
	init_proto "$@"
}

proto_l2tp_init_config() {
	proto_config_add_string "username"
	proto_config_add_string "password"
	proto_config_add_string "keepalive"
	proto_config_add_string "pppd_options"
	proto_config_add_boolean "ipv6"
	proto_config_add_int "mtu"
	proto_config_add_int "checkup_interval"
	proto_config_add_string "server"
	proto_config_add_string "l2tpoipsec"
	available=1
	no_device=1
	no_proto_task=1
}

proto_l2tp_setup() {
	local interface="$1"
	local optfile="/tmp/l2tp/options.${interface}"

	local ip serv_addr server l2tpoipsec_en
	json_get_var server server && {
		for ip in $(resolveip -t 5 "$server"); do
			json_get_var l2tpoipsec_en l2tpoipsec
			if [ "$l2tpoipsec_en" != "yes" ]; then
				( proto_add_host_dependency "$interface" "$ip" )
			fi
			echo "$ip" >> /tmp/server.l2tp-${interface}
			serv_addr=1
		done
	}
	[ -n "$serv_addr" ] || {
		echo "Could not resolve server address" >&2
		sleep 5
		proto_setup_failed "$interface"
		exit 1
	}

	# Start and wait for xl2tpd
	if [ ! -p /var/run/xl2tpd/l2tp-control -o -z "$(pidof xl2tpd)" ]; then
		/etc/init.d/xl2tpd restart

		local wait_timeout=0
		while [ ! -p /var/run/xl2tpd/l2tp-control ]; do
			wait_timeout=$(($wait_timeout + 1))
			[ "$wait_timeout" -gt 5 ] && {
				echo "Cannot find xl2tpd control file." >&2
				proto_setup_failed "$interface"
				exit 1
			}
			sleep 1
		done
	fi

	local ipv6 demand keepalive username password pppd_options mtu
	json_get_vars ipv6 demand keepalive username password pppd_options mtu
	[ "$ipv6" = 1 ] || ipv6=""
	if [ "${demand:-0}" -gt 0 ]; then
		demand="precompiled-active-filter /etc/ppp/filter demand idle $demand"
	else
		demand="persist"
	fi

	local interval="${keepalive##*[, ]}"
	[ "$interval" != "$keepalive" ] || interval=5

	keepalive="${keepalive:+lcp-echo-interval $interval lcp-echo-failure ${keepalive%%[, ]*}}"
	username="${username:+user \"$username\" password \"$password\"}"
	ipv6="${ipv6:++ipv6}"
	mtu="${mtu:+mtu $mtu mru $mtu}"

	mkdir -p /tmp/l2tp
	cat <<EOF >"$optfile"
usepeerdns
nodefaultroute
ipparam "$interface"
ifname "l2tp-$interface"
ip-up-script /lib/netifd/ppp-up
ipv6-up-script /lib/netifd/ppp-up
ip-down-script /lib/netifd/ppp-down
ipv6-down-script /lib/netifd/ppp-down
# Don't wait for LCP term responses; exit immediately when killed.
lcp-max-terminate 0
$keepalive
$username
$ipv6
$mtu
$pppd_options
EOF

	xl2tpd-control add l2tp-${interface} pppoptfile=${optfile} lns=${server} || {
		/etc/init.d/xl2tpd restart
		sleep 1
		echo "xl2tpd-control: Add l2tp-$interface failed" >&2
		proto_setup_failed "$interface"
		exit 1
	}
	xl2tpd-control connect l2tp-${interface} || {
		echo "xl2tpd-control: Connect l2tp-$interface failed" >&2
		proto_setup_failed "$interface"
		exit 1
	}
}

proto_l2tp_teardown() {
	local interface="$1"
	local optfile="/tmp/l2tp/options.${interface}"

	rm -f ${optfile}
	if [ -p /var/run/xl2tpd/l2tp-control ]; then
		xl2tpd-control remove l2tp-${interface} || {
			echo "xl2tpd-control: Remove l2tp-$interface failed" >&2
		}
	fi
	rm -f /tmp/server.l2tp-${interface}
	# Wait for interface to go down
        while [ -d /sys/class/net/l2tp-${interface} ]; do
		sleep 1
	done
}

[ -n "$INCLUDE_ONLY" ] || {
	add_protocol l2tp
}
