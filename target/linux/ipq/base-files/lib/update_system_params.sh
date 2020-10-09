#!/bin/sh
#
# Copyright (c) 2016 The Linux Foundation. All rights reserved.
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

. /lib/ipq806x.sh

disable_qrfs() {
	board=$(ipq806x_board_name)
	case "$board" in
		ap-dk0*)
		if [ $(cat /proc/qrfs/enable) == 1 ]; then
			echo "0" > /proc/qrfs/enable
			echo "1" > /var/qrfs_disabled_by_wifi
		fi
	esac
}

enable_rps() {
	board=$(ipq806x_board_name)
	ifname=$1
	case "$board" in
		ap-dk0*)
		# Steer Rx packets to all the CPUs other than
	        # CPU1(which can be utilized max for wifi2,if configured in 4x4)
		echo d > /sys/class/net/$ifname/queues/rx-0/rps_cpus
	esac
}
