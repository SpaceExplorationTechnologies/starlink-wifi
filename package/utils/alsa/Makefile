#
# Copyright (c) 2015 The Linux Foundation. All rights reserved.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=alsa
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/alsa
  SECTION:=alsa
  CATEGORY:=Base system
  URL:=http://openwrt.org/
  TITLE:=OpenWrt ALSA configuration framework
  DEPENDS:=+alsa-utils
  PKGARCH:=all
endef

define Package/alsa/description
 UCI based sound configuration module for OpenWrt
endef

define Build/Compile
	true
endef

define Package/alsa/install
	$(INSTALL_DIR) $(1)/lib/sound
	$(INSTALL_BIN) ./files/alsa.sh $(1)/lib/sound
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/alsa.init $(1)/etc/init.d/alsa
endef

$(eval $(call BuildPackage,alsa))
