#
# Copyright (c) 2014 The Linux Foundation. All rights reserved.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=pm-utils
PKG_VERSION:=1.4.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://pm-utils.freedesktop.org/releases
PKG_MD5SUM:=1742a556089c36c3a89eb1b957da5a60

include $(INCLUDE_DIR)/package.mk

define Package/pm-utils
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Power Management Utilities
  URL:=http://pm-utils.freedesktop.org/wiki/
  DEPENDS:=+flock
endef

define Package/pm-utils/description
  Power Managment Utilities is a small collection of scripts to
  suspend/hibernate system that can be used to run user supplied
  scripts on suspend and resume
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
		CC="$(TARGET_CC)" \
		LD="$(TARGET_CC)" \
		LDFLAGS="$(TARGET_LDFLAGS)" \
		all
endef

define Package/pm-utils/install
	$(INSTALL_DIR) $(1)/usr/lib/pm-utils
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/pm/pm-functions $(1)/usr/lib/pm-utils/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/pm/functions $(1)/usr/lib/pm-utils/

	$(INSTALL_DIR) $(1)/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/on_ac_power $(1)/sbin

	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/pm-is-supported $(1)/usr/bin

	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/pm-powersave $(1)/usr/sbin

	$(INSTALL_DIR) $(1)/usr/lib/pm-utils/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/pm-action $(1)/usr/lib/pm-utils/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/service $(1)/usr/lib/pm-utils/bin

	$(INSTALL_DIR) $(1)/etc/pm/power.d
	$(INSTALL_BIN) ./files/ipq-power-save.sh $(1)/etc/pm/power.d
endef

$(eval $(call BuildPackage,pm-utils))
