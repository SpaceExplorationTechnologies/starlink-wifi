# Copyright (c) 2015 The Linux Foundation. All rights reserved.
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

USE_REFRESH=

# make sure we got the tools we need during the fw upgrade process
platform_add_ramfs_ioe_tools()
{
	install_bin /usr/sbin/fw_printenv /usr/sbin/fw_setenv
	install_bin /bin/busybox /usr/bin/cut /usr/bin/sed
	install_bin /usr/bin/md5sum
	install_bin /usr/sbin/nandwrite
	install_bin /usr/sbin/ubiattach
	install_bin /usr/sbin/ubidetach
	install_file /etc/fw_env.config
}
append sysupgrade_pre_upgrade platform_add_ramfs_ioe_tools

# determine size of the main firmware partition
platform_get_firmware_size() {
	local dev size erasesize name
	while read dev size erasesize name; do
		name=${name#'"'}; name=${name%'"'}
		case "$name" in
			firmware)
				printf "%d" "0x$size"
				break
			;;
		esac
	done < /proc/mtd
}

get_filesize() {
	wc -c "$1" | while read image_size _n ; do echo $image_size ; break; done
}

# This function read the MTD mapping in /proc/mtd and output
# its offset in flash
# @1) (OUTPUT) variable to store the offset to
# @2) partition name
# @3) NAND flash
get_mtdpart_offset() {
	local varname=$1
	local partname=$2
	local offset=0
	local mtdsize=0

	# Iterate over every line in mtd until the partition name matches
	local line
	while read line && echo ${line} | grep -vq ".*\"${partname}\""; do
		# If the line doesn't start with mtd* (like first line)
		# we just skip it
		echo ${line} | grep -q "^mtd.*" || continue
		echo ${line} | grep -q "rootfs_data" && continue
		echo ${line} | grep -q "firmware" && continue
		echo ${line} | grep -q "fw-2" && continue
		# Here we extract the size info and add it to the previous offset
		mtdsize=$(echo ${line}|cut -f2 -d' ')
		offset=$(printf '%x' $((0x${offset} + 0x${mtdsize})))
	done < /proc/mtd

	eval "${varname}=${offset}"
}

platform_check_image_ioe() {
	local image_size=$( get_filesize "$1" )
	local firmware_size=$( platform_get_firmware_size )

	[ $image_size -ge $firmware_size ] &&
	{
		echo "upgrade image is too big (${image_size}b > ${firmware_size}b)"
		return 1
	}

	return 0
}

ioe_update_uboot_env() {
	local file="$1"
	local nand=$2
        # NOR0 size - 16MB hex (dual NOR)
        local nor0_size=1000000
        # NOR0 size - 512kB hex (NAND flash)
        local nor0_size_nand=80000

	local kernel_addr
	local bootargs bootcmd

	# Perform sanity checks to make sure we've got all the tools we need
	[ -x /usr/sbin/fw_printenv -a -x /usr/sbin/fw_setenv -a \
	  -x /bin/grep -a -x /usr/bin/cut -a -x /usr/bin/md5sum ] || {
		v "Error: missing tools to perform FW upgrade"
		return 1
	}
	[ -f /etc/fw_env.config ] || {
		v "/etc/fw_env.config does not exist"
		return 1
	}

	get_mtdpart_offset kernel_addr "k-2"

	local bootcmd_old=$(fw_printenv -n bootcmd)
        local bootargs_old=$(fw_printenv -n bootargs)
        
        local ubi=$(fw_printenv -n bootargs |grep ubi)
        [ -n "$ubi" ] && {
                mtdx=$(cat /proc/mtd |grep "r-2" |cut -f1 -d ":")
                r_n=$(echo $mtdx |cut -f2 -d "d")

                while read line; do
                        echo $line | grep -q "rootfs" || continue
                        mtdx=$(echo $line |cut -f1 -d ":")
                        rootfs_n=$(echo $mtdx |cut -f2 -d "d")
                        break
                done < /proc/mtd
        }

	v "Updating cus-531 u-boot-env..."
	bootargs=$(fw_printenv -n bootargs | sed \
		-e 's/(kernel)/(tmp-k-1)/' \
		-e 's/(rootfs)/(tmp-r-1)/' \
		-e 's/(vendor)/(tmp-v-1)/' \
		-e 's/(firmware)/(tmp-fw-1)/' \
		\
		-e 's/(k-2)/(kernel)/' \
		-e 's/(r-2)/(rootfs)/' \
		-e 's/(v-2)/(vendor)/' \
		-e 's/(fw-2)/(firmware)/' \
		\
		-e 's/(tmp-k-1)/(k-2)/' \
		-e 's/(tmp-r-1)/(r-2)/' \
		-e 's/(tmp-v-1)/(v-2)/' \
		-e 's/(tmp-fw-1)/(fw-2)/' \
	)

	_kernel_addr=$(printf '%d' 0x${kernel_addr})
	_nor0_size=$(printf '%d' 0x${nor0_size})

	if [ -n "$nand" ]; then
		# Kernel and rootfs for NAND flash are on second SPI partition
		v "NAND flash detected"
		kernel_addr=$(printf '%x' $((0x${kernel_addr} - 0x${nor0_size_nand})))
		bootcmd="nboot 0x81000000 0 0x${kernel_addr}; run fail"
                [ -n "$ubi" ] && bootargs=$(echo ${bootargs} | sed -e 's/ubi.mtd='"${rootfs_n}"'/ubi.mtd='"${r_n}"'/')
	elif [ $_kernel_addr -lt $_nor0_size ]; then
		bootcmd="bootm 0x9f${kernel_addr}; run fail"
	else
		v "32M NOR flash detected"
		kernel_addr=$(printf '%x' $((0x${kernel_addr} - 0x${nor0_size})))
		bootcmd="flselect 1; bootm 0x9f${kernel_addr}; run fail"
	fi

	fw_setenv -s - << EOF
	swap_root set bootargs_tmp \${bootargs}; set bootargs \${bootargs_old}; set bootargs_old \${bootargs_tmp}
	swap_kernel set bootcmd_tmp \${bootcmd}; set bootcmd \${bootcmd_old}; set bootcmd_old \${bootcmd_tmp}
	fail run swap_root; run swap_kernel; save; reset
	bootargs ${bootargs}
	bootcmd ${bootcmd}
	bootargs_old ${bootargs_old}
	bootcmd_old ${bootcmd_old}
EOF
	v "done"
}

platform_do_upgrade_ioe() {
	local file=$1
	local name=$2
	local fw="firmware"
	local ubi_vol="0"
	local rootfs="rootfs"
	local rootfs_data="rootfs_data"
	local valid_env=$(fw_printenv | grep "bootcmd=bootp")

	[ -n "$valid_env" ] && {
		v "ERROR, invalid u-boot-env, sysupgrade failed"
		return
	}

	dual=$(cat /proc/mtd | grep fw-2)
	[ -n "$dual" ] && fw="fw-2"

	sync

	nand=$(echo $name | grep "nand");
        if [ -n "$nand" ] || [ "$name" = "cus532k" ]; then
		mtd_fw=$(cat /proc/mtd |grep $fw |cut -f1 -d ":")
		mtd_dev="/dev/$mtd_fw"

		ubidetach -d $ubi_vol
		mtd erase $mtd_dev
		mtd_ubi_rootfs="/dev/$(cat /proc/mtd |grep $rootfs |cut -f1 -d ":")"
		dd if=$file bs=2048 | nandwrite -p $mtd_dev -
		ubiattach -p $mtd_ubi_rootfs
		sleep 2
		mtd_ubi_rootfs_data="$(cat /proc/mtd |grep $rootfs_data |cut -f1 -d ":" | awk ' // {sub(/mtd/, "", $0);print("/dev/mtdblock"$0)}')"
		echo $mtd_ubi_rootfs_data
		mount -t jffs2 $mtd_ubi_rootfs_data /mnt
		echo $CONF_TAR
		tar xzf $CONF_TAR -C /mnt/upper
		sync
		umount /mnt
	else
		get_image "$1" | mtd -j "$CONF_TAR" write - $fw
	fi

	[ -n "$dual" ] && ioe_update_uboot_env "$file" "$nand"
}

