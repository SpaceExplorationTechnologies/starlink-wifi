#
# Copyright (C) 2008-2010 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=ocf-crypto-headers
PKG_VERSION:=20110720
PKG_RELEASE:=1

PKG_LICENSE:=GPL-2.0
PKG_LICENSE_FILES:=cryptodev.h

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/local-development.mk
include $(INCLUDE_DIR)/package.mk

HDR_SRC_DIR:=$(LINUX_DIR)/crypto/ocf

define Package/ocf-crypto-headers
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=OCF-Linux cryptodev header
  PKGARCH:=all
  URL:=http://ocf-linux.sourceforge.net/
endef

define Build/Configure
endef

define Build/Compile
endef

define Build/InstallDev
	mkdir -p $(1)/usr/include/crypto
	$(CP) $(HDR_SRC_DIR)/cryptodev.h $(1)/usr/include/crypto || true
	$(CP) $(HDR_SRC_DIR)/ocf-compat.h $(1)/usr/include/crypto || true
endef

$(eval $(call BuildPackage,ocf-crypto-headers))
