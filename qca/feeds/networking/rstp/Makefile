include $(TOPDIR)/rules.mk

PKG_NAME:=rstp
PKG_VERSION:=2011-10-11
PKG_RELEASE=$(PKG_SOURCE_VERSION)

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=git://git.kernel.org/pub/scm/linux/kernel/git/shemminger/rstp.git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=434d24bae108dbb21461a13a4abcf014afa8b029
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_SOURCE_VERSION).tar.gz
PKG_MAINTAINER:=Stephen Hemminger <shemminger@vyatta.com>
# PKG_MIRROR_MD5SUM:=
# CMAKE_INSTALL:=1

PKG_LICENSE:=GPLv2
PKG_LICENSE_FILES:=
PKG_BUILD_PARALLEL:=1
SSDK_NOHNAT:=PACKAGE_kmod-qca-ssdk-nohnat
SSDK_HNAT:=PACKAGE_kmod-qca-ssdk-hnat

include $(INCLUDE_DIR)/package.mk

define Package/rstp
  SECTION:=net
  CATEGORY:=Network
  MAINTAINER:=Stephen Hemminger <shemminger@vyatta.com>
  URL:=http://git.kernel.org/cgit/linux/kernel/git/shemminger/rstp.git/
  TITLE:=Rapid Spanning Tree Protocol implement
  DEPENDS:=+$(SSDK_NOHNAT):kmod-qca-ssdk-nohnat +$(SSDK_HNAT):kmod-qca-ssdk-hnat
endef

define Package/rstp/description
  This package installs the RSTP daemon and tools
endef

TARGET_CFLAGS += \
	-I$(STAGING_DIR)/usr/include/qca-ssdk \
	-fpie

TARGET_LDFLAGS += -pie

define Package/rstp/install
	$(INSTALL_DIR) $(1)/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/bridge-stp $(1)/sbin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/rstpctl $(1)/sbin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/rstpd $(1)/sbin/
	$(CP) ./files/* $(1)/
endef

$(eval $(call BuildPackage,rstp))
