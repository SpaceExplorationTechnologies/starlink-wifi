#
# Copyright (c) 2015 The Linux Foundation. All rights reserved.
#

define Profile/QSDK_Base
        PACKAGES:=luci uhttpd kmod-nf-nathelper-extra luci-app-upnp mcproxy \
          kmod-ipt-nathelper-rtsp kmod-ipv6 \
          quagga quagga-ripd quagga-zebra quagga-watchquagga rp-pppoe-relay \
          -dnsmasq dnsmasq-dhcpv6 bridge \
          luci-app-ddns ddns-scripts
endef

IOE_BASE:=luci uhttpd luci-app-upnp mcproxy rp-pppoe-relay \
	  -dnsmasq dnsmasq-dhcpv6 bridge \
	  -swconfig luci-app-ddns ddns-scripts luci-app-qos \
	  kmod-nf-nathelper-extra kmod-ipt-nathelper-rtsp kmod-ipv6 \
	  kmod-usb2 kmod-i2c-gpio-custom kmod-button-hotplug

STORAGE:=kmod-scsi-core kmod-usb-storage \
	 kmod-fs-msdos kmod-fs-ntfs kmod-fs-vfat \
	 kmod-nls-cp437 kmod-nls-iso8859-1 \
	 mdadm ntfs-3g e2fsprogs fdisk mkdosfs \
	 kmod-fs-ext4

TEST_TOOLS:=sysstat ethtool i2c-tools ip ip6tables iperf

ALLJOYN:=alljoyn alljoyn-about alljoyn-c alljoyn-config \
	 alljoyn-controlpanel alljoyn-notification \
	 alljoyn-services_common

WIFI_OPEN:=-kmod-ath5k -kmod-qca-ath -kmod-qca-ath9k -kmod-qca-ath10k \
	   kmod-ath kmod-ath9k hostapd hostapd-utils iwinfo wpa-supplicant-p2p \
	   wpa-cli wireless-tools -wpad-mini

BLUETOOTH:=bluez-daemon kmod-bluetooth usbutils

WIFI_PKGS:=kmod-qca-wifi-unified-perf kmod-art2 \
		qca-hostap qca-hostapd-cli qca-wpa-supplicant \
		qca-wpa-cli qca-wapid sigma-dut-10.4 qca-wpc \
		qca-acfg qca-wrapd qca-spectral qcmbr-10.4 whc whc-ui \
		qca-iface-mgr-10.4

WIFI_10_4_FW_PKGS:=qca-wifi-fw-hw3-10.4-asic qca-wifi-fw-hw6-10.4-asic \
		   qca-wifi-fw-hw9-10.4-asic qca-wifi-fw-hw10-10.4-asic

SWITCH_SSDK_NOHNAT_PKGS:= kmod-qca-ssdk-nohnat qca-ssdk-shell swconfig
SWITCH_SSDK_HNAT_PKGS:= kmod-qca-ssdk-hnat qca-ssdk-shell swconfig

UBOOT_PKGS:= qca-legacy-uboot-ap135 qca-legacy-uboot-ap152-16M \
	     qca-legacy-uboot-ap147-16M qca-legacy-uboot-ap151-16M \
	     qca-legacy-uboot-db12x-16M qca-legacy-uboot-ap152-dual \
	     qca-legacy-uboot-ap135-nand qca-legacy-uboot-apjet01 \
	     qca-legacy-uboot-apjet01-32M qca-legacy-uboot-apjet01-dual

HYFI:=hyfi hyfi-ui

define Profile/QSDK_IOE_SB
	NAME:=Qualcomm-Atheros SDK IoE Single Band Profile
	PACKAGES:=$(IOE_BASE) $(TEST_TOOLS) $(ALLJOYN) $(WIFI_OPEN) \
		  qca-legacy-uboot-ap143-16M qca-legacy-uboot-ap143-32M \
		  qca-legacy-uboot-cus531-16M qca-legacy-uboot-cus531-dual \
		  qca-legacy-uboot-cus531-32M qca-legacy-uboot-cus531-nand \
		  qca-legacy-uboot-cus532k
endef

define Profile/QSDK_IOE_SB/Description
	QSDK IoE SB package set configuration.
	Enables WiFi 2.4G open source packages
endef

define Profile/QSDK_IOE_DBPAN
	NAME:=Qualcomm-Atheros SDK IoE Dual Band and Personal Area Network Profile
	PACKAGES:=$(IOE_BASE) $(TEST_TOOLS) $(ALLJOYN) $(WIFI_OPEN) $(BLUETOOTH) \
		  qca-legacy-uboot-cus531mp3-16M qca-legacy-uboot-cus531mp3-32M \
		  qca-legacy-uboot-cus531mp3-dual qca-legacy-uboot-cus531mp3-nand \
		  kmod-usb-serial kmod-usb-serial-pl2303 kmod-ath10k kmod-art2
endef

define Profile/QSDK_IOE_DBPAN/Description
	QSDK IoE DBPAN package set configuration.
	Enables WiFi 2.4G, 5G, Bluetooth open source packages
endef

define Profile/QSDK_IOE_TEST
	NAME:=Qualcomm-Atheros SDK IoE test Profile
	PACKAGES:=$(IOE_BASE) $(TEST_TOOLS) $(WIFI_OPEN) $(BLUETOOTH) \
		  kmod-usb-serial kmod-usb-serial-pl2303 kmod-art2
endef

define Profile/QSDK_IOE_TEST/Description
	QSDK IoE test package set configuration.
endef

$(eval $(call Profile,QSDK_IOE_SB))
$(eval $(call Profile,QSDK_IOE_DBPAN))
$(eval $(call Profile,QSDK_IOE_TEST))

define Profile/QSDK_Premium_Beeliner_Router
	$(Profile/QSDK_Base)
	NAME:=Qualcomm-Atheros SDK Premium Beeliner Router Profile
	PACKAGES+= -kmod-ath9k -kmod-ath5k -kmod-ath -wpad-mini luci-app-samba \
	  $(STORAGE) $(WIFI_PKGS) $(WIFI_10_4_FW_PKGS) \
	  $(SWITCH_SSDK_HNAT_PKGS) $(UBOOT_PKGS) $(HYFI) \
	  mtd-utils mtd-utils-nandwrite kmod-shortcut-fe-cm
endef

define Profile/QSDK_Premium_Beeliner_Router/Description
  QSDK Premium Beeliner Router package set configuration.
  This profile is designed to fit in a 16M flash and supports the following features:
  - Bridging and routing networking
  - QCA-WiFi driver configuration
  - LuCI web configuration interface
  - USB hard drive support
  - Samba
  - IPv4/IPv6
  - DynDns
endef
$(eval $(call Profile,QSDK_Premium_Beeliner_Router))

define Profile/QSDK_Wireless_Router
	NAME:=Qualcomm-Atheros SDK Wireless Router Profile
	PACKAGES+=-kmod-ath9k -kmod-ath5k -kmod-ath -wpad-mini uhttpd kmod-ipv6 \
	  kmod-ipt-nathelper-rtsp -dnsmasq dnsmasq-dhcpv6 bridge \
	  kmod-qca-wifi-lowmem-profile qca-wpa-cli kmod-usb-storage \
	  kmod-fs-ntfs kmod-fuse qca-hostap qca-hostapd-cli qca-wpa-supplicant \
	  kmod-qca-ssdk-nohnat qca-legacy-uboot-ap136 qca-legacy-uboot-ap152-8M \
	  qca-legacy-uboot-ap151-8M qca-legacy-uboot-ap147-8M qca-legacy-uboot-db120-8M
endef

define Profile/QSDK_Wireless_Router/Description
  QSDK Wireless Router package set configuration.
  This profile is designed to fit in a 8M flash and supports the following features:
  - Bridging and routing networking
  - LuCI web configuration interface
  - USB hard drive support
  - Samba
  - IPv4/IPv6
  - DynDns
  - qca-wifi driver
endef
$(eval $(call Profile,QSDK_Wireless_Router))

define Profile/QSDK_Open_Router
        $(Profile/QSDK_Base)
        $(Profile/QSDK_Test)
        NAME:=Qualcomm-Atheros SDK Open Router Profile
        PACKAGES+= kmod-ath9k -kmod-ath5k kmod-ath -wpad-mini $(STORAGE) \
          hostapd hostapd-utils iwinfo kmod-ath10k kmod-usb2 luci-app-qos \
          wireless-tools wpa-supplicant-p2p wpa-cli qca-legacy-uboot-ap121 \
          qca-legacy-uboot-ap143-16M qca-legacy-uboot-ap152-16M
endef

define Profile/QSDK_Open_Router/Description
  QSDK Open Router package set configuration.
  This profile includes only open source packages and is designed to fit in a 16M flash. It supports:
  - Bridging and routing networking
  - LuCI web configuration interface
  - USB hard drive support
  - IPv4/IPv6
  - DynDns
  - Integrated 11abgn support using the ath9k/ath10k driver
endef
$(eval $(call Profile,QSDK_Open_Router))

define Profile/QSDK_Target_Router
	NAME:=Qualcomm-Atheros SDK Target Router Profile
	PACKAGES+= qca-legacy-uboot-ap135 kmod-qca-wifi-unified-perf \
	  qca-wifi-fw-hw6-10.4-asic

endef

define Profile/QSDK_Target_Router/Description
  QSDK Target Router package set configuration with minimal packages.
endef
$(eval $(call Profile,QSDK_Target_Router))
