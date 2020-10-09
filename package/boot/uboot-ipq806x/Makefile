#
# Copyright (c) 2014 The Linux Foundation. All rights reserved.
# Copyright (C) 2012 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk
include $(INCLUDE_DIR)/version.mk

PKG_NAME:=u-boot
PKG_BUILD_DIR:=$(KERNEL_BUILD_DIR)/$(PKG_NAME)-$(BUILD_VARIANT)/$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_PROTO:=git
PKG_BRANCH:=master
PKG_RELEASE:=1

include $(INCLUDE_DIR)/local-development.mk
ifeq ($(DUMP)$(PKG_VERSION),)
  PKG_REV:=$(shell git ls-remote $(PKG_SOURCE_URL) $(PKG_BRANCH) | cut -b -7)
  PKG_VERSION:=g$(PKG_REV)
endif

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/uboot-ipq806x
  SECTION:=boot
  CATEGORY:=Boot Loaders
  DEPENDS:=@TARGET_ipq806x||TARGET_ipq
  TITLE:=U-boot for IPQ806x based platforms
  URL:=http://www.denx.de/wiki/U-Boot
endef

define Package/uboot-ipq806x-fwupgrade-tools
  SECTION:=boot
  CATEGORY:=Boot Loaders
  DEPENDS:=@TARGET_ipq806x||TARGET_ipq
  TITLE:=U-boot images tools (dumpimage, mkimage)
  URL:=http://www.denx.de/wiki/U-Boot
endef

define Build/Configure
	$(MAKE) -C $(PKG_BUILD_DIR) ipq806x_cdp_config
endef

define Build/Compile
	VERSION_CODE='$(VERSION_NICK) $(VERSION_NUMBER)' \
	REVISION='$(REVISION)' \
	$(MAKE) -C $(PKG_BUILD_DIR) HOSTCC=$(TARGET_CC) \
		HOSTSTRIP=true CROSS_COMPILE=$(TARGET_CROSS) \
		QSDK_CFLAGS="$(TARGET_CFLAGS)" \
		QSDK_LDFLAGS="$(TARGET_LDFLAGS)"
endef

define Package/uboot-ipq806x/install
	$(INSTALL_DIR) $(1)
	$(CP) $(PKG_BUILD_DIR)/u-boot $(BIN_DIR)/openwrt-$(BOARD)-u-boot.elf
	$(CP) $(PKG_BUILD_DIR)/u-boot.bin $(BIN_DIR)/openwrt-$(BOARD)-u-boot.img
	$(CP) $(PKG_BUILD_DIR)/u-boot.mbn $(BIN_DIR)/openwrt-$(BOARD)-u-boot.mbn
endef

define Package/uboot-ipq806x-fwupgrade-tools/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/tools/mkimage $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/tools/dumpimage $(1)/usr/bin
endef

$(eval $(call BuildPackage,uboot-ipq806x))
$(eval $(call BuildPackage,uboot-ipq806x-fwupgrade-tools))
