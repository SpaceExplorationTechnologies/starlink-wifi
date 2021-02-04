include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=mac80211

PKG_BACKPORTS_VERSION:=2612d51d
PKG_BACKPORTS_SOURCE_URL:=git://git.kernel.org/pub/scm/linux/kernel/git/backports/backports.git
PKG_BACKPORTS_BRANCH:=master

PKG_KERNEL_VERSION:=8442d41b
PKG_KERNEL_SOURCE_URL:=git://codeaurora.org/quic/qsdk/kvalo/ath.git
PKG_KERNEL_BRANCH:=ath-qca

PKG_VERSION:=20180529
PKG_SOURCE:=backports-$(PKG_VERSION)-$(LINUX_VERSION)-$(PKG_KERNEL_VERSION).tar.bz2
PKG_SUBDIR:=backports-$(PKG_VERSION)-$(LINUX_VERSION)-$(PKG_KERNEL_VERSION)
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(KERNEL_BUILD_DIR)/$(PKG_SUBDIR)
PKG_BUILD_PARALLEL:=1

PKG_DRIVERS = ath9k-common ath9k ath9k-htc ath10k ath

PKG_CONFIG_DEPENDS:= \
	CONFIG_PACKAGE_kmod-mac80211 \
	$(patsubst %,CONFIG_PACKAGE_kmod-%,$(PKG_DRIVERS)) \
	CONFIG_PACKAGE_MAC80211_MESSAGE_TRACING \
	CONFIG_PACKAGE_MAC80211_DEBUGFS \
	CONFIG_PACKAGE_MAC80211_MESH \
	CONFIG_PACKAGE_ATH_DEBUG \
	CONFIG_ATH_USER_REGD \

include $(INCLUDE_DIR)/package.mk

WMENU:=Wireless Drivers

define KernelPackage/mac80211/Default
  SUBMENU:=$(WMENU)
  URL:=http://www.qca.qualcomm.com
  MAINTAINER:=Qualcomm Atheros
endef

define KernelPackage/cfg80211
  $(call KernelPackage/mac80211/Default)
  TITLE:=cfg80211 - wireless configuration API
  DEPENDS+= +iw +kmod-crypto-core +kmod-crypto-manager +wireless-regdb
  FILES:= \
	$(PKG_BUILD_DIR)/compat/compat.ko \
	$(PKG_BUILD_DIR)/net/wireless/cfg80211.ko
endef

define KernelPackage/cfg80211/description
cfg80211 is the Linux wireless LAN (802.11) configuration API.
endef

define Package/mac80211-scripts
  SUBMENU:=$(WMENU)
  URL:=http://www.qca.qualcomm.com
  MAINTAINER:=Qualcomm Atheros
  TITLE:=mac80211 - wireless configuration scripts
endef

define Package/mac80211-scripts/description
mac80211-scripts is the Linux wireless LAN (802.11) configuration scripts.
endef

define KernelPackage/mac80211
  $(call KernelPackage/mac80211/Default)
  TITLE:=Linux 802.11 Wireless Networking Stack
  DEPENDS+= @TARGET_ipq806x||TARGET_ipq||TARGET_ar71xx \
	+kmod-crypto-arc4 +kmod-crypto-aes +kmod-cfg80211 +hostapd-common
  PKG_BUILD_DEPENDS+= PACKAGE_kmod-qca-nss-drv:kmod-qca-nss-drv
  KCONFIG:=\
	CONFIG_AVERAGE=y
  FILES:= $(PKG_BUILD_DIR)/net/mac80211/mac80211.ko
  MENU:=1
endef

define KernelPackage/mac80211/config
  if PACKAGE_kmod-mac80211

    if PACKAGE_kmod-qca-nss-drv
	config PACKAGE_MAC80211_NSS_SUPPORT
		bool "Enable NSS support for IPQ platform"
		default y
		help
		  This option enables support for NSS in boards
		  like AP148.
    endif

	config PACKAGE_MAC80211_DEBUGFS
		bool "Export mac80211 internals in DebugFS"
		select KERNEL_DEBUG_FS
		select KERNEL_RELAY if PACKAGE_kmod-ath9k-common
		default y
		help
		  Select this to see extensive information about
		  the internal state of mac80211 in debugfs.

	config PACKAGE_MAC80211_MESH
		bool "Enable 802.11s mesh support"
		default y

	config PACKAGE_MAC80211_MESSAGE_TRACING
		bool "Enable mac80211 message tracing"
		default n
		help
		  Select this option to enable tracing.

	config PACKAGE_MAC80211_DEBUG_MENU
		bool "Select mac80211 debugging features"
		default n
		help
		  This option collects various mac80211 debug settings.

	menu "mac80211 debugging features"
		depends on PACKAGE_MAC80211_DEBUG_MENU

	config PACKAGE_MAC80211_VERBOSE_DEBUG
		bool "Verbose debugging output"
		default n
		help
		  Selecting this option causes mac80211 to print out
		  many debugging messages.

	config PACKAGE_MAC80211_MLME_DEBUG
		bool "Verbose managed MLME output"
		default n
		help
		  Selecting this option causes mac80211 to print out
		  debugging messages for the managed-mode MLME.

	config PACKAGE_MAC80211_STA_DEBUG
		bool "Verbose station debugging"
		default n
		help
		  Selecting this option causes mac80211 to print out
		  debugging messages for station addition/removal.

	config PACKAGE_MAC80211_HT_DEBUG
		bool "Verbose HT debugging"
		default n
		help
		  This option enables 802.11n High Throughput features
		  debug tracing output.

	config PACKAGE_MAC80211_IBSS_DEBUG
		bool "Verbose IBSS debugging"
		default n
		help
		  Selecting this option causes mac80211 to print out
		  very verbose IBSS debugging messages.

	config PACKAGE_MAC80211_PS_DEBUG
		bool "Verbose powersave mode debugging"
		default n
		help
		  Selecting this option causes mac80211 to print out very
		  verbose power save mode debugging messages (when mac80211
		  is an AP and has power saving stations.)

	endmenu
  endif
endef

define KernelPackage/mac80211/description
Generic IEEE 802.11 Networking Stack (mac80211)
endef

PKG_LINUX_FIRMWARE_NAME:=linux-firmware
PKG_LINUX_FIRMWARE_VERSION:=8afadbe
PKG_LINUX_FIRMWARE_BRANCH:=master
PKG_LINUX_FIRMWARE_SOURCE:=$(PKG_LINUX_FIRMWARE_NAME)-$(PKG_LINUX_FIRMWARE_VERSION).tar.bz2
PKG_LINUX_FIRMWARE_PROTO:=git
PKG_LINUX_FIRMWARE_SOURCE_URL:=git://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git
PKG_LINUX_FIRMWARE_SUBDIR:=$(PKG_LINUX_FIRMWARE_NAME)-$(PKG_LINUX_FIRMWARE_VERSION)
PKG_LINUX_FIRMWARE_MIRROR_MD5SUM:=ec34aec8b2d172b2a4438619d28f89a1

define Download/linux-firmware
  FILE:=$(PKG_LINUX_FIRMWARE_SOURCE)
  URL:=$(PKG_LINUX_FIRMWARE_SOURCE_URL)
  MD5SUM:=$(PKG_LINUX_FIRMWARE_MD5SUM)
  PROTO:=$(PKG_LINUX_FIRMWARE_PROTO)
  VERSION:=$(PKG_LINUX_FIRMWARE_VERSION)
  SUBDIR:=$(PKG_LINUX_FIRMWARE_SUBDIR)
  MIRROR_MD5SUM:=$(PKG_LINUX_FIRMWARE_MIRROR_MD5SUM)
endef
$(eval $(call Download,linux-firmware))


$(eval EXT_KERNEL_DIR:=$(CONFIG_EXTERNAL_KERNEL_TREE))
IS_EXT_KERNEL_TREE_GIT:=$(shell cd $(EXT_KERNEL_DIR) && git rev-parse --is-inside-work-tree)

ifeq ($(IS_EXT_KERNEL_TREE_GIT), true)
  $(eval _LINUX_SRC:=$(CONFIG_EXTERNAL_KERNEL_TREE))
else
  _LINUX_SRC=$(CONFIG_KERNEL_GIT_CLONE_URI)
endif


ifneq ($(call qstrip,$(_LINUX_SRC)),)
# --reference option doesn't work on git trees synced with "repo", so instead
# we're manually using clone & fetch to speed up sync time
  define FastCloneKernel
	git clone $(_LINUX_SRC) $(2)
	(cd $(2); git remote add src $(1); git fetch src)
  endef
else
  define FastCloneKernel
	GIT_NAME=$$$$(echo $(1) | sed -e 's:.*//[^/]*.::g'); \
	git clone $(1) $(2) || \
	([ -n "${CONFIG_GIT_MIRROR}" ] && \
	rm -rf $(2) && \
	git clone $(CONFIG_GIT_MIRROR)$$$$GIT_NAME $(2))
  endef
endif

define DownloadBackports
  $(eval $(Download/Defaults))
  $(eval $(Download/backports))

  $(foreach dep,$(DOWNLOAD_RDEP),
    $(dep): $(DL_DIR)/$(FILE)
  )
  download: $(DL_DIR)/$(FILE)

  $(DL_DIR)/$(FILE):
	mkdir -p $(TMP_DIR)/dl/$(PKG_NAME)-$(PKG_VERSION)
	$(call FastCloneKernel,$(PKG_KERNEL_SOURCE_URL),$(TMP_DIR)/dl/$(PKG_NAME)-kernel)
	(cd $(TMP_DIR)/dl/$(PKG_NAME)-kernel && git checkout $(PKG_KERNEL_VERSION) &&\
	git revert --no-edit db3bdcb9c3ff)

	git clone $(PKG_BACKPORTS_SOURCE_URL) $(TMP_DIR)/dl/$(PKG_NAME)-source
	cp files/copy-list.ath $(TMP_DIR)/dl/$(PKG_NAME)-source
	(cd $(TMP_DIR)/dl/$(PKG_NAME)-source && git checkout $(PKG_BACKPORTS_VERSION) && \
	git revert --no-edit b35b2767ca && \
	./gentree.py --clean --copy-list ./copy-list.ath \
		$(TMP_DIR)/dl/$(PKG_NAME)-kernel $(TMP_DIR)/dl/$(SUBDIR))
	(cd $(TMP_DIR)/dl; $(call dl_pack,$(TMP_DIR)/dl/$(FILE),$(SUBDIR)))
	mv $(TMP_DIR)/dl/$(FILE) $(DL_DIR)
	rm -rf $(TMP_DIR)/dl/$(PKG_NAME)-kernel $(TMP_DIR)/dl/$(PKG_NAME)-source

endef

define Download/backports
  FILE:=$(PKG_SOURCE)
  SUBDIR:=$(PKG_SUBDIR)
endef
$(eval $(call DownloadBackports,backports))

define KernelPackage/ath/config
  if PACKAGE_kmod-ath
	config ATH_USER_REGD
		bool "Force Atheros drivers to respect the user's regdomain settings"
		help
		  Atheros' idea of regulatory handling is that the EEPROM of the card defines
		  the regulatory limits and the user is only allowed to restrict the settings
		  even further, even if the country allows frequencies or power levels that
		  are forbidden by the EEPROM settings.

		  Select this option if you want the driver to respect the user's decision about
		  regulatory settings.

	config PACKAGE_ATH_DEBUG
		bool "Atheros wireless debugging"
		help
		  Say Y, if you want to debug atheros wireless drivers.
		  Right now only ath9k makes use of this.
  endif
endef

define KernelPackage/ath
  $(call KernelPackage/mac80211/Default)
  TITLE:=QCA common driver part
  DEPENDS+= @PCI_SUPPORT||USB_SUPPORT||TARGET_ar71xx||TARGET_atheros +kmod-mac80211
  FILES:=$(PKG_BUILD_DIR)/drivers/net/wireless/ath/ath.ko
  MENU:=1
endef

define KernelPackage/ath/description
 This module contains some common parts needed by QCA Wireless drivers.
endef

define KernelPackage/ath9k-common
  $(call KernelPackage/mac80211/Default)
  TITLE:=QCA 802.11n wireless devices (common code for ath9k and ath9k_htc)
  URL:=http://linuxwireless.org/en/users/Drivers/ath9k
  DEPENDS+= @PCI_SUPPORT||USB_SUPPORT||TARGET_ar71xx +kmod-ath +@DRIVER_11N_SUPPORT +@DRIVER_11W_SUPPORT
  FILES:= \
	$(PKG_BUILD_DIR)/drivers/net/wireless/ath/ath9k/ath9k_common.ko \
	$(PKG_BUILD_DIR)/drivers/net/wireless/ath/ath9k/ath9k_hw.ko
endef

define KernelPackage/ath9k
  $(call KernelPackage/mac80211/Default)
  TITLE:=QCA 802.11n PCI wireless cards support
  URL:=http://linuxwireless.org/en/users/Drivers/ath9k
  DEPENDS+= @PCI_SUPPORT||TARGET_ar71xx +kmod-ath9k-common
  FILES:= \
	$(PKG_BUILD_DIR)/drivers/net/wireless/ath/ath9k/ath9k.ko
  AUTOLOAD:=$(call AutoProbe,ath9k)
endef

define KernelPackage/ath9k/description
This module adds support for wireless adapters based on
QCA IEEE 802.11n AR5008, AR9001,AR9002, AR9003, AR9004 family of chipsets.
endef

define KernelPackage/ath9k-htc
  $(call KernelPackage/mac80211/Default)
  TITLE:=QCA 802.11n USB device support
  URL:=http://linuxwireless.org/en/users/Drivers/ath9k
  DEPENDS+= @USB_SUPPORT +kmod-ath9k-common +kmod-usb-core
  FILES:= \
	$(PKG_BUILD_DIR)/drivers/net/wireless/ath/ath9k/ath9k_htc.ko
  AUTOLOAD:=$(call AutoProbe,ath9k_htc)
endef

define KernelPackage/ath9k-htc/description
This module adds support for wireless adapters based on
QCA USB AR9271 and AR7010 family of chipsets.
endef

define KernelPackage/ath10k
  $(call KernelPackage/mac80211/Default)
  TITLE:=QCA 802.11ac wireless cards support
  URL:=http://wireless.kernel.org/en/users/Drivers/ath10k
  DEPENDS+= @PCI_SUPPORT +kmod-ath +@DRIVER_11N_SUPPORT +ath10k-firmware
  FILES:= \
	$(PKG_BUILD_DIR)/drivers/net/wireless/ath/ath10k/ath10k_core.ko \
	$(PKG_BUILD_DIR)/drivers/net/wireless/ath/ath10k/ath10k_pci.ko
  AUTOLOAD:=$(call AutoProbe,ath10k_core ath10k_pci)
endef

define KernelPackage/ath10k/description
This module adds support for wireless adapters based on
QCA IEEE 802.11ac family of chipsets. For now only
PCI is supported.
endef

define KernelPackage/wil6210/config
  if PACKAGE_kmod-wil6210
	if PACKAGE_kmod-qca-nss-drv
	config PACKAGE_WIL6210_NSS_SUPPORT
		bool "Enable NSS support for 11ad wil6210 driver"
		default y
		help
		This option enables support for NSS in boards
	endif

  endif
endef

define KernelPackage/wil6210
  $(call KernelPackage/mac80211/Default)
  TITLE:=QCA 802.11ad wireless cards support
  DEPENDS+= @TARGET_ipq806x||TARGET_ipq_ipq806x @PCI_SUPPORT +kmod-cfg80211
  FILES:= \
	$(PKG_BUILD_DIR)/drivers/net/wireless/ath/wil6210/wil6210.ko
  AUTOLOAD:=$(call AutoProbe,wil6210)
endef

define KernelPackage/wil6210/description
This module adds support for wireless adapters based on
60GHz QCA Wilocity family of chipsets. These support 802.11d.
endef

config_package=$(if $(CONFIG_PACKAGE_kmod-$(1)),m)

config-y:= \
	WLAN \
	NL80211_TESTMODE \
	CFG80211_WEXT \
	CFG80211_INTERNAL_REGDB \
	CFG80211_CERTIFICATION_ONUS \
	MAC80211_RC_MINSTREL \
	MAC80211_RC_MINSTREL_HT \
	MAC80211_RC_DEFAULT_MINSTREL \

config-$(call config_package,cfg80211) += CFG80211

config-$(call config_package,mac80211) += MAC80211
config-$(CONFIG_PACKAGE_MAC80211_MESH) += MAC80211_MESH
ifdef CONFIG_PACKAGE_MAC80211_DEBUGFS
  config-y += \
	CFG80211_DEBUGFS \
	MAC80211_DEBUGFS \
	ATH9K_DEBUGFS \
	ATH9K_HTC_DEBUGFS \
	ATH10K_DEBUGFS \
	ATH10K_PKTLOG
endif

config-$(CONFIG_PACKAGE_MAC80211_NSS_SUPPORT) += MAC80211_NSS_SUPPORT
config-$(CONFIG_PACKAGE_MAC80211_MESSAGE_TRACING) += MAC80211_MESSAGE_TRACING ATH10K_TRACING
config-$(CONFIG_PACKAGE_MAC80211_DEBUG_MENU) += MAC80211_DEBUG_MENU
config-$(CONFIG_PACKAGE_MAC80211_VERBOSE_DEBUG) += MAC80211_VERBOSE_DEBUG
config-$(CONFIG_PACKAGE_MAC80211_MLME_DEBUG) += MAC80211_MLME_DEBUG
config-$(CONFIG_PACKAGE_MAC80211_STA_DEBUG) += MAC80211_STA_DEBUG
config-$(CONFIG_PACKAGE_MAC80211_HT_DEBUG) += MAC80211_HT_DEBUG
config-$(CONFIG_PACKAGE_MAC80211_IBSS_DEBUG) += MAC80211_IBSS_DEBUG
config-$(CONFIG_PACKAGE_MAC80211_PS_DEBUG) += MAC80211_PS_DEBUG

config-$(call config_package,ath) += ATH_CARDS ATH_COMMON
config-$(CONFIG_PACKAGE_ATH_DEBUG) += ATH_DEBUG ATH10K_DEBUG HWMON

config-$(call config_package,ath9k) += ATH9K
config-$(call config_package,ath9k-common) += ATH9K_COMMON
config-$(CONFIG_TARGET_ar71xx) += ATH9K_AHB
config-$(CONFIG_PCI) += ATH9K_PCI
config-$(CONFIG_ATH_USER_REGD) += ATH_USER_REGD \
				      ATH_REG_DYNAMIC_USER_REG_HINTS \
				      ATH_REG_DYNAMIC_USER_CERT_TESTING

config-$(call config_package,ath9k-htc) += ATH9K_HTC
config-$(call config_package,ath10k) += ATH10K ATH10K_PCI
config-$(call config_package,wil6210) += ATH_CARDS WIL6210

config-$(CONFIG_PACKAGE_WIL6210_NSS_SUPPORT) += WIL6210_NSS_SUPPORT

config-$(CONFIG_PACKAGE_kmod-ath9k) += ATH9K_CHANNEL_CONTEXT
config-$(CONFIG_PACKAGE_kmod-ath10k) += ATH10K_DFS_CERTIFIED ATH10K_SMART_ANT_ALG \
					ATH10K_AHB ATH10K_SPECTRAL

config-$(CONFIG_LEDS_TRIGGERS) += MAC80211_LEDS

MAKE_OPTS:= -C "$(PKG_BUILD_DIR)" \
	CROSS_COMPILE="$(KERNEL_CROSS)" \
	ARCH="$(LINUX_KARCH)" \
	EXTRA_CFLAGS="-I$(PKG_BUILD_DIR)/include -I$(STAGING_DIR)/usr/include/qca-nss-drv" \
	KLIB_BUILD="$(LINUX_DIR)" \
	MODPROBE=true \
	KLIB=$(TARGET_MODULES_DIR) \
	KERNEL_SUBLEVEL=$(lastword $(subst ., ,$(KERNEL_PATCHVER))) \
	KBUILD_LDFLAGS_MODULE_PREREQ=

ifneq ($(findstring c,$(OPENWRT_VERBOSE)),)
  MAKE_OPTS += V=1
endif

define ConfigVars
$(subst $(space),,$(foreach opt,$(config-$(1)),CPTCFG_$(opt)=$(1)
))
endef

define mac80211_config
$(call ConfigVars,m)$(call ConfigVars,y)
endef
$(eval $(call shexport,mac80211_config))

define Build/Prepare
	rm -rf $(PKG_BUILD_DIR)
	mkdir -p $(PKG_BUILD_DIR)
	$(PKG_UNPACK)
	$(Build/Patch)
	$(TAR) -C $(PKG_BUILD_DIR) -xjf $(DL_DIR)/$(PKG_LINUX_FIRMWARE_SOURCE)
	rm -rf \
		$(PKG_BUILD_DIR)/include/linux/ssb \
		$(PKG_BUILD_DIR)/include/linux/bcma \
		$(PKG_BUILD_DIR)/include/net/bluetooth

	rm -f \
		$(PKG_BUILD_DIR)/include/linux/cordic.h \
		$(PKG_BUILD_DIR)/include/linux/crc8.h \
		$(PKG_BUILD_DIR)/include/linux/eeprom_93cx6.h \
		$(PKG_BUILD_DIR)/include/linux/wl12xx.h \
		$(PKG_BUILD_DIR)/include/linux/spi/libertas_spi.h \
		$(PKG_BUILD_DIR)/include/net/ieee80211.h

	echo 'compat-wireless-$(PKG_VERSION)-$(PKG_RELEASE)-$(REVISION)' > $(PKG_BUILD_DIR)/compat_version
	$(CP) ./files/regdb.txt $(PKG_BUILD_DIR)/net/wireless/db.txt
endef

ifneq ($(CONFIG_PACKAGE_kmod-cfg80211)$(CONFIG_PACKAGE_kmod-lib80211),)
 define Build/Compile/kmod
	rm -rf $(PKG_BUILD_DIR)/modules
	+$(MAKE) $(PKG_JOBS) $(MAKE_OPTS) modules
 endef
endif

define Build/Configure
	cmp $(PKG_BUILD_DIR)/include/linux/ath9k_platform.h $(LINUX_DIR)/include/linux/ath9k_platform.h
endef

define Build/Compile
	$(SH_FUNC) var2file "$(call shvar,mac80211_config)" $(PKG_BUILD_DIR)/.config
	$(MAKE) $(MAKE_OPTS) olddefconfig
	$(call Build/Compile/kmod)
endef

define Build/InstallDev
	mkdir -p \
		$(1)/usr/include/mac80211 \
		$(1)/usr/include/mac80211-backport \
		$(1)/usr/include/mac80211/ath \
		$(1)/usr/include/net/mac80211
	$(CP) $(PKG_BUILD_DIR)/net/mac80211/*.h $(PKG_BUILD_DIR)/include/* $(1)/usr/include/mac80211/
	$(CP) $(PKG_BUILD_DIR)/backport-include/* $(1)/usr/include/mac80211-backport/
	$(CP) $(PKG_BUILD_DIR)/net/mac80211/rate.h $(1)/usr/include/net/mac80211/
	$(CP) $(PKG_BUILD_DIR)/drivers/net/wireless/ath/*.h $(1)/usr/include/mac80211/ath/
endef

define Package/mac80211-scripts/install
	$(call KernelPackage/cfg80211/install,$(1))
endef

define KernelPackage/cfg80211/install
	$(INSTALL_DIR) $(1)/lib/wifi
	$(INSTALL_DIR) $(1)/lib/wifi $(1)/lib/netifd/wireless
	$(INSTALL_DATA) ./files/lib/wifi/mac80211.sh $(1)/lib/wifi
	$(INSTALL_BIN) ./files/lib/netifd/wireless/mac80211.sh $(1)/lib/netifd/wireless
endef

define KernelPackage/ath9k-htc/install
	$(INSTALL_DIR) $(1)/lib/firmware
	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/$(PKG_LINUX_FIRMWARE_SUBDIR)/htc_9271.fw \
		$(PKG_BUILD_DIR)/$(PKG_LINUX_FIRMWARE_SUBDIR)/htc_7010.fw \
		$(1)/lib/firmware/
endef

define KernelPackage/ath10k/install
	$(INSTALL_DIR) $(1)/lib/firmware/ath10k/QCA9377/hw1.0
	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/$(PKG_LINUX_FIRMWARE_SUBDIR)/ath10k/QCA9377/hw1.0/board.bin \
		$(PKG_BUILD_DIR)/$(PKG_LINUX_FIRMWARE_SUBDIR)/ath10k/QCA9377/hw1.0/firmware-5.bin \
		$(1)/lib/firmware/ath10k/QCA9377/hw1.0
endef

$(eval $(call KernelPackage,cfg80211))
$(eval $(call KernelPackage,mac80211))
$(eval $(call BuildPackage,mac80211-scripts))
$(eval $(call KernelPackage,ath9k-common))
$(eval $(call KernelPackage,ath9k))
$(eval $(call KernelPackage,ath9k-htc))
$(eval $(call KernelPackage,ath10k))
$(eval $(call KernelPackage,ath))
$(eval $(call KernelPackage,wil6210))
