#!/bin/sh

# Copyright (c) 2016, The Linux Foundation. All rights reserved.
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

#Expected result : "switch_name_1 switch_name_2 switch_name_n"
#The order of name should be the same with its index in QCA switch driver
#It's the better to use control channel of switch
get_switch_list(){
	echo "sw1"
}

#poll link status of switch port if switch don't support link event
#interval is in unit of msec
get_linkstatus_poll_interval(){
	local sw_name=$1

	case "$sw_name" in
	sw1)
		echo "3000"
		;;
	*)
		echo "3000"
		;;
	esac
}

get_private_header_type(){
	local sw_name=$1

	case "$sw_name" in
	sw1)
		echo "0xfefe"
		;;
	*)
		echo "0xfefe"
		;;
	esac
}

#Which switch port we should trap control/protocol packet to
get_cpu_port(){
	local sw_name=$1

	case "$sw_name" in
	sw1)
		echo "0"
		;;
	*)
		echo "0"
		;;
	esac
}

#Which switch port we should mirror control/protocol packet to
get_mirror_port(){
	local sw_name=$1

	case "$sw_name" in
	sw1)
		echo "6"
		;;
	*)
		echo "6"
		;;
	esac
}

get_ap160_ap161_switch_ports(){
	local sw_name=$1

	case "$sw_name" in
	sw1)
		echo "@sw1 eth1 eth1 1 port1"
		echo "@sw1 eth1 eth1 2 port2"
		echo "@sw1 eth1 eth1 3 port3"
		echo "@sw1 eth1 eth2 4 eth2"
		;;
	*)
		echo "Not support"
		;;
	esac
}

get_default_switch_ports(){
	local sw_name=$1

	case "$sw_name" in
	sw1)
		echo "@sw1 eth1 eth1 1 port1"
		echo "@sw1 eth1 eth1 2 port2"
		echo "@sw1 eth1 eth1 3 port3"
		echo "@sw1 eth1 eth1 4 port4"
		echo "@sw1 eth1 eth0 5 eth0"
		;;
	*)
		echo "Not support"
		;;
	esac
}

#Expected result : "@switch_name control_channel data_channel port_num port_name"
get_switch_ports(){
	. /lib/ipq806x.sh
	board=$(ipq806x_board_name)

	case "$board" in
	ap160|ap161)
		get_ap160_ap161_switch_ports $@
		;;
	*)
		get_default_switch_ports $@
		;;
	esac
}

func=$1
shift
$func $@
