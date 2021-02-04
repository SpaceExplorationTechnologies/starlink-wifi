include $(TOPDIR)/rules.mk

PKG_NAME:=lacpd
PKG_SOURCE_PROTO:=git
PKG_BRANCH:=master
PKG_RELEASE:=1

LOCAL_SRC:=$(TOPDIR)/qca/src/qca-lacpd
include $(INCLUDE_DIR)/local-development.mk
ifeq ($(DUMP)$(PKG_VERSION),)
  PKG_REV:=$(shell git ls-remote $(PKG_SOURCE_URL) $(PKG_BRANCH) | cut -b -7)
  PKG_VERSION:=g$(PKG_REV)
endif

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MAINTAINER:=Xiaoping Fan <xfan@codeaurora.org>

LOCAL_VARIANT=$(patsubst lacpd-%,%,$(patsubst lacpd-%,%,$(BUILD_VARIANT)))

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/lacpd
  SECTION:=net
  CATEGORY:=Network
  MAINTAINER:=Xiaoping Fan <xfan@codeaurora.org>
  DEPENDS:=+libubox +libuci +libubus +ubus +ubusd +!PACKAGE_kmod-qca-ssdk-nohnat:kmod-qca-ssdk-hnat
  TITLE:=Link aggregation control protocol Daemon
endef

TARGET_CFLAGS += \
	-I$(STAGING_DIR)/usr/include/qca-ssdk \
	-I$(STAGING_DIR)/usr/include

CMAKE_OPTIONS += \
	-DDEBUG=1

define Package/lacpd/install
	$(INSTALL_DIR) $(1)/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/lacpd $(1)/sbin/
	$(INSTALL_DIR) $(1)/lib/functions
	$(INSTALL_BIN) ./files/lib/functions/qca_switch_config.sh $(1)/lib/functions/
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/etc/init.d/lacpd $(1)/etc/init.d/
	$(INSTALL_DIR) $(1)/etc/config
	$(CP) ./files/etc/config/lacpd $(1)/etc/config/
endef

$(eval $(call BuildPackage,lacpd))
