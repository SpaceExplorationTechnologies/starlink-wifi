include $(TOPDIR)/rules.mk

PKG_DISTNAME:=sysupgrade-helper
PKG_NAME:=u-boot-2016
PKG_SOURCE_PROTO:=git
PKG_BRANCH:=master
PKG_RELEASE:=1

include $(INCLUDE_DIR)/local-development.mk
ifeq ($(DUMP)$(PKG_VERSION),)
  PKG_REV:=$(shell git ls-remote $(PKG_SOURCE_URL) $(PKG_BRANCH) | cut -b -7)
  PKG_VERSION:=g$(PKG_REV)
endif

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_DISTNAME)/$(PKG_NAME)-$(BUILD_VARIANT)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/sysupgrade-helper
  SECTION:=boot
  CATEGORY:=Boot Loaders
  DEPENDS:=@TARGET_ipq806x||TARGET_ipq
  TITLE:=U-boot images tools (dumpimage, mkimage)
endef

HOSTLDFLAGS+= \
	      -L$(STAGING_DIR)/usr/lib \
	      -znow -zrelro -pie

define Build/Compile
	cp config $(PKG_BUILD_DIR)/.config
	$(MAKE) -C $(PKG_BUILD_DIR) TARGETCC=$(TARGET_CC) \
		CROSS_COMPILE=$(TARGET_CROSS) \
		TARGET_CFLAGS="$(TARGET_CFLAGS)" \
		HOSTLDFLAGS="$(HOSTLDFLAGS)" \
		tools-only
endef

define Package/sysupgrade-helper/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/tools/mkimage $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/tools/dumpimage $(1)/usr/bin
endef

$(eval $(call BuildPackage,sysupgrade-helper))
