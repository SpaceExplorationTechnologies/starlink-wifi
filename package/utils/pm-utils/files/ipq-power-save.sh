#!/bin/sh

#
# Copyright (c) 2015-2016, The Linux Foundation. All rights reserved.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 and
# only version 2 as published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#

. /lib/ipq806x.sh
. /lib/functions.sh

ipq8064_ac_power()
{
	echo "Entering AC-Power Mode"
# Krait Power-UP Sequence
	/etc/init.d/powerctl restart

# Clocks Power-UP Sequence
	echo 400000000 > /sys/kernel/debug/clk/afab_a_clk/rate
	echo 64000000 > /sys/kernel/debug/clk/dfab_a_clk/rate
	echo 64000000 > /sys/kernel/debug/clk/sfpb_a_clk/rate
	echo 64000000 > /sys/kernel/debug/clk/cfpb_a_clk/rate
	echo 133000000 > /sys/kernel/debug/clk/nssfab0_a_clk/rate
	echo 133000000 > /sys/kernel/debug/clk/nssfab1_a_clk/rate
	echo 400000000 > /sys/kernel/debug/clk/ebi1_a_clk/rate

# Enabling Auto scale on NSS cores
	echo 1 > /proc/sys/dev/nss/clock/auto_scale

# PCIe Power-UP Sequence
	sleep 1
	echo 1 > /sys/bus/pci/rcrescan
	sleep 2
	echo 1 > /sys/bus/pci/rescan

	sleep 1

# Wifi Power-up Sequence
	wifi up

# Bringing Up LAN Interface
	ifup lan

# Sata Power-UP Sequence
	[ -f /sys/devices/platform/msm_sata.0/ahci.0/msm_sata_suspend ] && {
		echo 0 > /sys/devices/platform/msm_sata.0/ahci.0/msm_sata_suspend
	}
	[ -f sys/devices/soc.2/29000000.sata/ipq_ahci_suspend ] && {
		echo 0 > sys/devices/soc.2/29000000.sata/ipq_ahci_suspend
	}
	[ -f /sys/devices/platform/soc/29000000.sata/ipq_ahci_suspend ] && {
		echo 0 > /sys/devices/platform/soc/29000000.sata/ipq_ahci_suspend
	}

	sleep 1
	echo "- - -" > /sys/class/scsi_host/host0/scan

# USB Power-UP Sequence
	[ -d /sys/module/dwc3_ipq ] || insmod dwc3-ipq
	[ -d /sys/module/dwc3_qcom ] || insmod dwc3-qcom
	[ -d /sys/module/phy_qcom_hsusb ] || insmod phy-qcom-hsusb
	[ -d /sys/module/phy_qcom_ssusb ] || insmod phy-qcom-ssusb
	[ -d /sys/module/dwc3_of_simple ] || insmod dwc3-of-simple.ko
	[ -d /sys/module/phy_qcom_dwc3 ] || insmod phy-qcom-dwc3.ko
	[ -d /sys/module/dwc3 ] || insmod dwc3

# SD/MMC Power-UP sequence
	local emmcblock="$(find_mmc_part "rootfs")"

	if [ -z "$emmcblock" ]; then
		if [[ -f /tmp/sysinfo/sd_drvname  && ! -d /sys/block/mmcblk0 ]]
		then
			sd_drvname=$(cat /tmp/sysinfo/sd_drvname)
			echo $sd_drvname > /sys/bus/amba/drivers/mmci-pl18x/bind
		fi
	fi

	exit 0
}

ipq8064_battery_power()
{
	echo "Entering Battery Mode..."

# Wifi Power-down Sequence
	wifi unload

# Bring Down LAN Interface
	ifdown lan

# PCIe Power-Down Sequence

# Remove devices
	sleep 2
	for i in `ls /sys/bus/pci/devices/`; do
		d=/sys/bus/pci/devices/${i}
		v=`cat ${d}/vendor`
		[ "xx${v}" != "xx0x17cb" ] && echo 1 > ${d}/remove
	done

# Remove Buses
	sleep 2
	for i in `ls /sys/bus/pci/devices/`; do
		d=/sys/bus/pci/devices/${i}
		echo 1 > ${d}/remove
	done

# Remove RC
	sleep 2

	[ -f /sys/bus/pci/rcremove ] && {
		echo 1 > /sys/bus/pci/rcremove
	}
	[ -f /sys/devices/pci0000:00/pci_bus/0000:00/rcremove ] && {
		echo 1 > /sys/devices/pci0000:00/pci_bus/0000:00/rcremove
	}
	sleep 1

# Find scsi devices and remove it

	partition=`cat /proc/partitions | awk -F " " '{print $4}'`

	for entry in $partition; do
		sd_entry=$(echo $entry | head -c 2)

		if [ "$sd_entry" = "sd" ]; then
			[ -f /sys/block/$entry/device/delete ] && {
				echo 1 > /sys/block/$entry/device/delete
			}
		fi
	done

# Sata Power-Down Sequence
	[ -f /sys/devices/platform/msm_sata.0/ahci.0/msm_sata_suspend ] && {
		echo 1 > /sys/devices/platform/msm_sata.0/ahci.0/msm_sata_suspend
	}
	[ -f /sys/devices/soc.2/29000000.sata/ipq_ahci_suspend ] && {
		echo 1 > /sys/devices/soc.2/29000000.sata/ipq_ahci_suspend
	}
	[ -f /sys/devices/platform/soc/29000000.sata/ipq_ahci_suspend ] && {
		echo 1 > /sys/devices/platform/soc/29000000.sata/ipq_ahci_suspend
	}

# USB Power-down Sequence
	[ -d /sys/module/dwc3_ipq ] && rmmod dwc3-ipq
	[ -d /sys/module/dwc3 ] && rmmod dwc3
	[ -d /sys/module/dwc3_qcom ] && rmmod dwc3-qcom
	[ -d /sys/module/phy_qcom_hsusb ] && rmmod phy-qcom-hsusb
	[ -d /sys/module/phy_qcom_ssusb ] && rmmod phy-qcom-ssusb
	[ -d /sys/module/dwc3_of_simple ] && rmmod dwc3-of-simple.ko
	[ -d /sys/module/phy_qcom_dwc3 ] && rmmod phy-qcom-dwc3.ko

	sleep 1

#SD/MMC Power-down Sequence
	local emmcblock="$(find_mmc_part "rootfs")"

	if [ -z "$emmcblock" ]; then
		if [ -d /sys/block/mmcblk0 ]
		then
			sd_drvname=`readlink /sys/block/mmcblk0 | awk -F "/" '{print $5}'`
			echo "$sd_drvname" > /tmp/sysinfo/sd_drvname
			echo $sd_drvname > /sys/bus/amba/drivers/mmci-pl18x/unbind
		fi
	fi

# Disabling Auto scale on NSS cores
	echo 0 > /proc/sys/dev/nss/clock/auto_scale

# Clocks Power-down Sequence

	echo 400000000 > /sys/kernel/debug/clk/afab_a_clk/rate
	echo 32000000 > /sys/kernel/debug/clk/dfab_a_clk/rate
	echo 32000000 > /sys/kernel/debug/clk/sfpb_a_clk/rate
	echo 32000000 > /sys/kernel/debug/clk/cfpb_a_clk/rate
	echo 133000000 > /sys/kernel/debug/clk/nssfab0_a_clk/rate
	echo 133000000 > /sys/kernel/debug/clk/nssfab1_a_clk/rate
	echo 400000000 > /sys/kernel/debug/clk/ebi1_a_clk/rate

# Scaling Down UBI Cores
	echo 110000000 > /proc/sys/dev/nss/clock/current_freq

# Krait Power-down Sequence
	echo 384000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq
	echo 384000 > /sys/devices/system/cpu/cpu1/cpufreq/scaling_min_freq
	echo "powersave" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
	echo "powersave" > /sys/devices/system/cpu/cpu1/cpufreq/scaling_governor
}

ipq4019_ap_dk01_1_ac_power()
{
	echo "Entering AC-Power Mode"
# Cortex Power-UP Sequence
	/etc/init.d/powerctl restart

# Power on Malibu PHY of LAN ports
	ssdk_sh port poweron set 1
	ssdk_sh port poweron set 2
	ssdk_sh port poweron set 3
	ssdk_sh port poweron set 4
# Wifi Power-up Sequence
	wifi up

# USB Power-UP Sequence
	if ! [ -d /sys/module/dwc3_ipq40xx -o -d /sys/module/dwc3_of_simple ]
	then
		insmod phy-qca-baldur.ko
		insmod phy-qca-uniphy.ko
		if [ -e /lib/modules/$(uname -r)/dwc3-of-simple.ko ]
		then
			insmod dwc3-of-simple.ko
		else
			insmod dwc3-ipq40xx.ko
		fi
		insmod dwc3.ko
	fi

# LAN interface up
	ifup lan

	exit 0
}

ipq4019_ap_dk01_1_battery_power()
{
	echo "Entering Battery Mode..."

# Wifi Power-down Sequence
	wifi unload

# Find scsi devices and remove it

	partition=`cat /proc/partitions | awk -F " " '{print $4}'`

	for entry in $partition; do
		sd_entry=$(echo $entry | head -c 2)

		if [ "$sd_entry" = "sd" ]; then
			[ -f /sys/block/$entry/device/delete ] && {
				echo 1 > /sys/block/$entry/device/delete
			}
		fi
	done

# Power off Malibu PHY of LAN ports
	ssdk_sh port poweroff set 1
	ssdk_sh port poweroff set 2
	ssdk_sh port poweroff set 3
	ssdk_sh port poweroff set 4

# USB Power-down Sequence
	if [ -d /sys/module/dwc3_ipq40xx -o -d /sys/module/dwc3_of_simple ]
	then
		rmmod dwc3
		if [ -d /sys/module/dwc3_ipq40xx ]
		then
			rmmod dwc3-ipq40xx
		else
			rmmod dwc3-of-simple
		fi
		rmmod phy-qca-uniphy
		rmmod phy-qca-baldur
	fi
	sleep 2

# LAN interface down
	ifdown lan

# Cortex Power-down Sequence
	echo 48000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq
	echo "powersave" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
}

ipq4019_ap_dk04_1_ac_power()
{
	echo "Entering AC-Power Mode"
# Cortex Power-UP Sequence
	/etc/init.d/powerctl restart

# Power on Malibu PHY of LAN ports
	ssdk_sh port poweron set 1
	ssdk_sh port poweron set 2
	ssdk_sh port poweron set 3
	ssdk_sh port poweron set 4

# PCIe Power-UP Sequence
	sleep 1
	echo 1 > /sys/bus/pci/rcrescan
	sleep 2
	echo 1 > /sys/bus/pci/rescan

	sleep 1

# Wifi Power-up Sequence
	wifi up

# USB Power-UP Sequence
	if ! [ -d /sys/module/dwc3_ipq40xx -o -d /sys/module/dwc3_of_simple ]
	then
		insmod phy-qca-baldur.ko
		insmod phy-qca-uniphy.ko
		if [ -e /lib/modules/$(uname -r)/dwc3-of-simple.ko ]
		then
			insmod dwc3-of-simple.ko
		else
			insmod dwc3-ipq40xx.ko
		fi
		insmod dwc3.ko
	fi

# LAN interface up
	ifup lan

# SD/MMC Power-UP sequence
	local emmcblock="$(find_mmc_part "rootfs")"

	if [ -z "$emmcblock" ]; then
		if [[ -f /tmp/sysinfo/sd_drvname  && ! -d /sys/block/mmcblk0 ]]
		then
			sd_drvname=$(cat /tmp/sysinfo/sd_drvname)
			echo $sd_drvname > /sys/bus/platform/drivers/sdhci_msm/bind
		fi
	fi

	sleep 1

	exit 0
}

ipq4019_ap_dk04_1_battery_power()
{
	echo "Entering Battery Mode..."

# Wifi Power-down Sequence
	wifi unload

# PCIe Power-Down Sequence

# Remove devices
	sleep 2
	for i in `ls /sys/bus/pci/devices/`; do
		d=/sys/bus/pci/devices/${i}
		v=`cat ${d}/vendor`
		[ "xx${v}" != "xx0x17cb" ] && echo 1 > ${d}/remove
	done

# Remove Buses
	sleep 2
	for i in `ls /sys/bus/pci/devices/`; do
		d=/sys/bus/pci/devices/${i}
		echo 1 > ${d}/remove
	done

# Remove RC
	sleep 2

	[ -f /sys/bus/pci/rcremove ] && {
		echo 1 > /sys/bus/pci/rcremove
	}
	[ -f /sys/devices/pci0000:00/pci_bus/0000:00/rcremove ] && {
		echo 1 > /sys/devices/pci0000:00/pci_bus/0000:00/rcremove
	}
	sleep 1

# Find scsi devices and remove it

	partition=`cat /proc/partitions | awk -F " " '{print $4}'`

	for entry in $partition; do
		sd_entry=$(echo $entry | head -c 2)

		if [ "$sd_entry" = "sd" ]; then
			[ -f /sys/block/$entry/device/delete ] && {
				echo 1 > /sys/block/$entry/device/delete
			}
		fi
	done

# Power off Malibu PHY of LAN ports
	ssdk_sh port poweroff set 1
	ssdk_sh port poweroff set 2
	ssdk_sh port poweroff set 3
	ssdk_sh port poweroff set 4

# USB Power-down Sequence
	if [ -d /sys/module/dwc3_ipq40xx -o -d /sys/module/dwc3_of_simple ]
	then
		rmmod dwc3
		if [ -d /sys/module/dwc3_ipq40xx ]
		then
			rmmod dwc3-ipq40xx
		else
			rmmod dwc3-of-simple
		fi
		rmmod phy-qca-uniphy
		rmmod phy-qca-baldur
	fi
	sleep 2
#SD/MMC Power-down Sequence
	local emmcblock="$(find_mmc_part "rootfs")"

	if [ -z "$emmcblock" ]; then
		if [ -d /sys/block/mmcblk0 ]
		then
			sd_drvname=`readlink /sys/block/mmcblk0 | grep -o "[0-9]*.sdhci"`
			echo "$sd_drvname" > /tmp/sysinfo/sd_drvname
			echo $sd_drvname > /sys/bus/platform/drivers/sdhci_msm/unbind
		fi
	fi

# LAN interface down
	ifdown lan

# Cortex Power-down Sequence
	echo 48000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq
	echo "powersave" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
}

ipq8074_ac_power()
{
	echo "Entering AC-Power Mode"
# Cortex Power-UP Sequence
	/etc/init.d/powerctl restart

# Enabling Auto scale on NSS cores
	echo 1 > /proc/sys/dev/nss/clock/auto_scale

# Power on Malibu PHY of LAN ports
	ssdk_sh port poweron set 2
	ssdk_sh port poweron set 3
	ssdk_sh port poweron set 4
	ssdk_sh port poweron set 5

# PCIe Power-UP Sequence
	sleep 1
	echo 1 > /sys/bus/pci/rcrescan
	sleep 2
	echo 1 > /sys/bus/pci/rescan

	sleep 1

# Wifi Power-up Sequence
	wifi load

# USB Power-UP Sequence
	if ! [ -d /sys/module/dwc3_of_simple ]
	then
		insmod phy-msm-ssusb-qmp.ko
		insmod phy-msm-qusb.ko
		insmod dwc3-of-simple.ko
		insmod dwc3.ko
	fi

	if [ -d config/usb_gadget/g1 ]
	then
		echo "8a00000.dwc3" > /config/usb_gadget/g1/UDC
	fi

# LAN interface up
	ifup lan

# SD/MMC Power-UP sequence
	local emmcblock="$(find_mmc_part "rootfs")"

	if [ -z "$emmcblock" ]; then
		if [[ -f /tmp/sysinfo/sd_drvname  && ! -d /sys/block/mmcblk0 ]]
		then
			sd_drvname=$(cat /tmp/sysinfo/sd_drvname)
			echo $sd_drvname > /sys/bus/platform/drivers/sdhci_msm/bind
		fi
	fi

	if [[ -f /tmp/sysinfo/sd1_drvname  && ! -d /sys/block/mmcblk1 ]]
	then
		sd1_drvname=$(cat /tmp/sysinfo/sd1_drvname)
		echo $sd1_drvname > /sys/bus/platform/drivers/sdhci_msm/bind
	fi

	sleep 1

	exit 0
}

ipq8074_battery_power()
{
	echo "Entering Battery Mode..."


# PCIe Power-Down Sequence

# Remove devices
	sleep 2
	for i in `ls /sys/bus/pci/devices/`; do
		d=/sys/bus/pci/devices/${i}
		v=`cat ${d}/vendor`
		[ "xx${v}" != "xx0x17cb" ] && echo 1 > ${d}/remove
	done

# Remove Buses
	sleep 2
	for i in `ls /sys/bus/pci/devices/`; do
		d=/sys/bus/pci/devices/${i}
		echo 1 > ${d}/remove
	done

# Remove RC
	sleep 2

	[ -f /sys/bus/pci/rcremove ] && {
		echo 1 > /sys/bus/pci/rcremove
	}
	[ -f /sys/devices/pci0000:00/pci_bus/0000:00/rcremove ] && {
		echo 1 > /sys/devices/pci0000:00/pci_bus/0000:00/rcremove
	}
	sleep 1

# Wifi Power-down Sequence
	wifi unload

# Find scsi devices and remove it
	partition=`cat /proc/partitions | awk -F " " '{print $4}'`

	for entry in $partition; do
		sd_entry=$(echo $entry | head -c 2)

		if [ "$sd_entry" = "sd" ]; then
			[ -f /sys/block/$entry/device/delete ] && {
				echo 1 > /sys/block/$entry/device/delete
			}
		fi
	done


# Power off Malibu PHY of LAN ports
	ssdk_sh port poweroff set 2
	ssdk_sh port poweroff set 3
	ssdk_sh port poweroff set 4
	ssdk_sh port poweroff set 5

# USB Power-down Sequence
	if [ -d config/usb_gadget/g1 ]
	then
		echo "" > /config/usb_gadget/g1/UDC
	fi

	if [ -d sys/module/dwc3_of_simple ]
	then
		rmmod dwc3
		rmmod dwc3-of-simple
		rmmod phy_msm_qusb
		rmmod phy_msm_ssusb_qmp
	fi
	sleep 2

#SD/MMC Power-down Sequence
	local emmcblock="$(find_mmc_part "rootfs")"

	if [ -z "$emmcblock" ]; then
		if [ -d /sys/block/mmcblk0 ]
		then
			sd_drvname=`readlink /sys/block/mmcblk0 | grep -o "[0-9]*.sdhci"`
			echo "$sd_drvname" > /tmp/sysinfo/sd_drvname
			echo $sd_drvname > /sys/bus/platform/drivers/sdhci_msm/unbind
		fi
	fi

	if [ -d /sys/block/mmcblk1 ]
	then
		sd1_drvname=`readlink /sys/block/mmcblk1 | grep -o "[0-9]*.sdhci"`
		echo "$sd1_drvname" > /tmp/sysinfo/sd1_drvname
		echo $sd1_drvname > /sys/bus/platform/drivers/sdhci_msm/unbind
	fi

# LAN interface down
	ifdown lan

# Disabling Auto scale on NSS cores
	echo 0 > /proc/sys/dev/nss/clock/auto_scale

# Scaling Down UBI Cores
	echo 748800000 > /proc/sys/dev/nss/clock/current_freq

# Cortex Power-down Sequence
	echo "powersave" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor

}

board=$(ipq806x_board_name)
case "$1" in
	false)
		case "$board" in
		db149 | ap148 | ap145 | ap148_1xx | db149_1xx | db149_2xx | ap145_1xx | ap160 | ap160_2xx | ap161 | ak01_1xx)
			ipq8064_ac_power ;;
		ap-dk01.1-c1 | ap-dk01.1-c2 | ap-dk05.1-c1)
			ipq4019_ap_dk01_1_ac_power ;;
		ap-dk04.1-c1 | ap-dk04.1-c2 | ap-dk04.1-c3 | ap-dk04.1-c4 | ap-dk04.1-c5 | ap-dk04.1-c6 | ap-dk06.1-c1 | ap-dk07.1-c1 | ap-dk07.1-c2 | ap-dk07.1-c3 | ap-dk07.1-c4)
			ipq4019_ap_dk04_1_ac_power ;;
		ap-hk01-c1 | ap-hk01-c2 | ap-hk01-c3 | ap-hk01-c4 | ap-hk02 | ap-hk05 | ap-hk06 | ap-hk07 | ap-hk08 | ap-hk09 | ap-ac01.1 | ap-ac01.2 | db-hk01 | db-hk02)
			ipq8074_ac_power ;;
		esac ;;
	true)
		case "$board" in
		db149 | ap148 | ap145 | ap148_1xx | db149_1xx | db149_2xx | ap145_1xx | ap160 | ap160_2xx | ap161 | ak01_1xx)
			ipq8064_battery_power ;;
		ap-dk01.1-c1 | ap-dk01.1-c2 | ap-dk05.1-c1)
			ipq4019_ap_dk01_1_battery_power ;;
		ap-dk04.1-c1 | ap-dk04.1-c2 | ap-dk04.1-c3 | ap-dk04.1-c4 | ap-dk04.1-c5 | ap-dk04.1-c6 | ap-dk06.1-c1 | ap-dk07.1-c1 | ap-dk07.1-c2 | ap-dk07.1-c3 | ap-dk07.1-c4)
			ipq4019_ap_dk04_1_battery_power ;;
		ap-hk01-c1 | ap-hk01-c2 | ap-hk01-c3 | ap-hk01-c4 | ap-hk02 | ap-hk05 | ap-hk06 | ap-hk07 | ap-hk08 | ap-hk09 | ap-ac01.1 | ap-ac01.2 | db-hk01 | db-hk02)
			ipq8074_battery_power ;;
		esac ;;
esac
