
include $(TOPDIR)/rules.mk

PKG_NAME:=lrzsz
PKG_VERSION:=0.12.20
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://ohse.de/uwe/releases/
PKG_MD5SUM:=b5ce6a74abc9b9eb2af94dffdfd372a4

include $(INCLUDE_DIR)/package.mk

define Package/lrzsz
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Modem Utilities
endef

define Package/lrzsz/description
  Modem Managment Utilities
endef

define Package/lrzsz/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/lrz $(1)/usr/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/lsz $(1)/usr/bin/
	$(LN) /usr/bin/lrz $(1)/usr/bin/rz
	$(LN) /usr/bin/lsz $(1)/usr/bin/sx
	$(LN) /usr/bin/lsz $(1)/usr/bin/sz
endef

$(eval $(call BuildPackage,lrzsz))
