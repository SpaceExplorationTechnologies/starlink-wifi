#!/bin/sh
#
# Copyright (c) 2014 The Linux Foundation. All rights reserved.
# Copyright (C) 2011 OpenWrt.org
#

IPQ806X_BOARD_NAME=
IPQ806X_MODEL=

ipq806x_board_detect() {
	local machine
	local name

	machine=$(cat /proc/device-tree/model)

	case "$machine" in
	*"DB149")
		name="db149"
		;;
	*"DB149-1XX")
		name="db149_1xx"
		;;
	*"DB149-2XX")
		name="db149_2xx"
		;;
	*"AP148")
		name="ap148"
		;;
	*"AP148-1XX")
		name="ap148_1xx"
		;;
	*"AP145")
		name="ap145"
		;;
	*"AP145-1XX")
		name="ap145_1xx"
		;;
	*"AP160")
		name="ap160"
		;;
	*"AP161")
		name="ap161"
		;;
	*"AP160-2XX")
		name="ap160_2xx"
		;;
	*"STORM")
		name="storm"
		;;
	*"WHIRLWIND")
		name="whirlwind"
		;;
	*"AK01-1XX")
		name="ak01_1xx"
		;;
	*"AP-DK01.1-C1")
		name="ap-dk01.1-c1"
		;;
	*"AP-DK01.1-C2")
		name="ap-dk01.1-c2"
		;;
	*"AP-DK04.1-C1")
		name="ap-dk04.1-c1"
		;;
	*"AP-DK04.1-C2")
		name="ap-dk04.1-c2"
		;;
	*"AP-DK04.1-C3")
		name="ap-dk04.1-c3"
		;;
	*"AP-DK04.1-C4")
		name="ap-dk04.1-c4"
		;;
	*"AP-DK04.1-C5")
		name="ap-dk04.1-c5"
		;;
	*"AP-DK04.1-C6")
		name="ap-dk04.1-c6"
		;;
	*"AP-DK05.1-C1")
		name="ap-dk05.1-c1"
		;;
	*"AP-DK06.1-C1")
		name="ap-dk06.1-c1"
		;;
	*"AP-DK07.1-C1")
		name="ap-dk07.1-c1"
		;;
	*"AP-DK07.1-C2")
		name="ap-dk07.1-c2"
		;;
	*"AP-DK07.1-C3")
		name="ap-dk07.1-c3"
		;;
	*"AP-DK07.1-C4")
		name="ap-dk07.1-c4"
		;;
	*"AP-HK01-C1")
		name="ap-hk01-c1"
		;;
	*"AP-HK01-C2")
		name="ap-hk01-c2"
		;;
	*"AP-HK01-C3")
		name="ap-hk01-c3"
		;;
	*"AP-HK01-C4")
		name="ap-hk01-c4"
		;;
	*"AP-HK02")
		name="ap-hk02"
		;;
	*"AP-HK05")
		name="ap-hk05"
		;;
	*"AP-HK06")
		name="ap-hk06"
		;;
	*"AP-HK07")
		name="ap-hk07"
		;;
	*"AP-HK08")
		name="ap-hk08"
		;;
	*"AP-HK09")
		name="ap-hk09"
		;;
	*"AP-AC01.1")
		name="ap-ac01.1"
		;;
	*"AP-AC01.2")
		name="ap-ac01.2"
		;;
	*"DB.HK01")
		name="db-hk01"
		;;
	*"DB.HK02")
		name="db-hk02"
		;;
	esac

	[ -z "$name" ] && name="unknown"

	[ -z "$IPQ806X_BOARD_NAME" ] && IPQ806X_BOARD_NAME="$name"
	[ -z "$IPQ806X_MODEL" ] && IPQ806X_MODEL="$machine"

	[ -e "/tmp/sysinfo/" ] || mkdir -p "/tmp/sysinfo/"

	echo "$IPQ806X_BOARD_NAME" > /tmp/sysinfo/board_name
	echo "$IPQ806X_MODEL" > /tmp/sysinfo/model
}

ipq806x_board_name() {
	local name

	[ -f /tmp/sysinfo/board_name ] && name=$(cat /tmp/sysinfo/board_name)
	[ -z "$name" ] && name="unknown"

	echo "$name"
}
