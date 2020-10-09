#!/bin/sh

board_string=""
bldinfo=""
nodeip=""
serverip=""
crash_kern_path="/crash"
crash_kern_name="crash_kernel.elf"
crash_kernel=""
debug_flag=0

get_build_info()
{
	echo -n "KEXEC: Getting the board serial number.. "
	local serialnumber=`fw_printenv SerialNumber 2>/dev/null`
	[ $? -ne 0 ] && { echo "failed.."; exit; };
	echo done

	echo -n "KEXEC: Getting build info... "
	hstnm=`uname -n|tr -s ' ' '_'`
	vers=`uname -v|tr -s '[ #:]' '_'`
	bldinfo=`echo bldinfo=${hstnm}_${vers}`
	bldinfo=$bldinfo-${serialnumber#SerialNumber=}-`date +%Y-%m-%d_%H-%M-%S`;
	echo done
	[ $debug_flag -eq 1 ] && {
		echo "KEXEC (DEBUG): bldinfo = $bldinfo";
	};
}

get_board_type()
{
	echo -n "KEXEC: Getting board type... "

	val=$(cat /tmp/sysinfo/board_name)
	[ $? -eq 0 ] && {
		board_string="board=$(echo $val | tr 'a-z' 'A-Z')";
		echo done

		[ $debug_flag -eq 1 ] && {
			echo "KEXEC (DEBUG): board_string = $board_string";
		};

		return;
	};

	echo "error board string not found in /proc/cmdline"
	exit
}

get_node_and_server_ip_addr()
{
	echo -n "KEXEC: Getting the node ip.. "
	nodeip=`fw_printenv ipaddr 2>/dev/null`
	[ $? -ne 0 ] && { echo "failed.."; exit; };

	echo done

	echo -n "KEXEC: Getting the serverip.. "
	serverip=`fw_printenv serverip 2>/dev/null`

	[ $? -ne 0 ] && { echo "failed.."; exit; };
	echo done
	[ $debug_flag -eq 1 ] && {
		echo "KEXEC (DEBUG): nodeip = $nodeip serverip = $serverip";
	};
}

load_crash_kernel()
{
	[ $debug_flag -eq 1 ] && {
		echo "KEXEC (DEBUG): crash_kernel = $crash_kernel";
	};

	echo -n "KEXEC: Loading crash kernel.. "

	kexecout=`kexec -d -p $crash_kernel --append="$board_string $bldinfo $nodeip $serverip" 2>&1`
	[ $? -ne 0 ] && { echo "failed.."; echo $kexecout; exit; };

	echo "success"
}

usage()
{
	echo "Usage: $0 [-d] <crash kernel path> <crash kernel name>"
	exit
}

check_args()
{
	if [ $# -gt 0 ]
	then
		[ $1 = "-d" ] && { debug_flag=1; shift; };
		[ $# -ne 2 ] && { usage $0; };
		crash_kern_path=$1
		crash_kern_name=$2
		crash_kernel=`echo $crash_kern_path/$crash_kern_name`
		[ ! -f $crash_kernel ] && { echo "$0: invalid crash_kernel $crash_kernel"; exit; };
	else
		usage $0
	fi
}

main()
{
	check_args $*
	get_build_info
	get_board_type
	get_node_and_server_ip_addr
	#echo $nodeip $serverip $bldinfo $board_string
	load_crash_kernel
}

main $*
