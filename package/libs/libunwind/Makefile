include $(TOPDIR)/rules.mk

PKG_NAME:=libunwind
PKG_VERSION:=2015-07-04
PKG_RELEASE:=$(PKG_SOURCE_VERSION)

PKG_SOURCE_PROTO:=git
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_SOURCE_VERSION).tar.gz
PKG_SOURCE_URL:=git://git.debian.org/git/collab-maint/libunwind.git
PKG_SOURCE_VERSION:=6bbcd10591d9aac11beb9fa526b6bf69ddbab437
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)

PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

TARGET_CFLAGS += $(FPIC)

include $(INCLUDE_DIR)/package.mk

define Package/libunwind
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=portable, efficient C(API) to determine call-chain
endef

define Package/libunwind-dev/description
  Its goal is  portable & efficient C(API) to determine call-chain of a program
 The API supports both local (same-process) & remote (across-process) operation
endef

CONFIGURE_ARGS += \
	--enable-shared

define Build/InstallDev
	$(CP) $(PKG_INSTALL_DIR)/* $(1)/
	$(INSTALL_DIR) $(1)/usr/include
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/include/* $(1)/usr/include/
endef

define Package/libunwind/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/lib/libunwind*.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libunwind))
