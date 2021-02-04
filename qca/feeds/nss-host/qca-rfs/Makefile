include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=qca-rfs
PKG_SOURCE_PROTO:=git
PKG_BRANCH:=master
PKG_RELEASE:=1
PKG_VERSION:=1

include $(INCLUDE_DIR)/local-development.mk
ifeq ($(DUMP)$(PKG_VERSION),)
  PKG_REV:=$(shell git ls-remote $(PKG_SOURCE_URL) $(PKG_BRANCH) | cut -b -7)
  PKG_VERSION:=g$(PKG_REV)
endif

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define KernelPackage/qca-rfs
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Support
  DEPENDS:=@TARGET_ipq806x||TARGET_ipq_ipq40xx +kmod-ipt-conntrack
  TITLE:=Kernel module for QCA Receiving Flow Steering
  FILES:=$(PKG_BUILD_DIR)/qrfs.ko
  KCONFIG:=CONFIG_NF_CONNTRACK_EVENTS=y CONFIG_NF_CONNTRACK_CHAIN_EVENTS=y
  AUTOLOAD:=$(call AutoLoad,29,qrfs)
endef

define KernelPackage/qca-rfs/Description
QCA-RFS is a kernel module for ESS Receive Flow Steering.
endef


define Build/Compile
	$(MAKE) -C "$(LINUX_DIR)" \
		CROSS_COMPILE="$(TARGET_CROSS)" \
		ARCH="$(LINUX_KARCH)" \
		SUBDIRS="$(PKG_BUILD_DIR)" \
		EXTRA_CFLAGS="$(EXTRA_CFLAGS)" \
		modules
endef

ifneq ($(CONFIG_PACKAGE_kmod-qca-rfs),)
define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include/qca-rfs
	$(CP) -rf $(PKG_BUILD_DIR)/rfs_dev.h $(1)/usr/include/qca-rfs
endef
endif

define KernelPackage/qca-rfs/install
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/qrfs.init $(1)/etc/init.d/qrfs
endef

$(eval $(call KernelPackage,qca-rfs))
