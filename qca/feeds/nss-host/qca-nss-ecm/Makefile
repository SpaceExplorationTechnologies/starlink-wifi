include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=qca-nss-ecm
PKG_SOURCE_PROTO:=git
PKG_BRANCH:=master
PKG_RELEASE:=1

include $(INCLUDE_DIR)/local-development.mk
ifeq ($(DUMP)$(PKG_VERSION),)
  PKG_VERSION:=$(shell git ls-remote $(PKG_SOURCE_URL) $(PKG_BRANCH) | cut -b -7)
endif
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_VERSION)

LOCAL_VARIANT=$(patsubst qca-nss-ecm-%,%,$(patsubst qca-nss-ecm-%,%,$(BUILD_VARIANT)))
include $(INCLUDE_DIR)/package.mk

ifeq ($(CONFIG_QCA_NSS_ECM_EXAMPLES_PCC),y)
	FILES_EXAMPLES:=$(PKG_BUILD_DIR)/examples/ecm_pcc_test.ko
endif

define KernelPackage/qca-nss-ecm/Default
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Support
  DEPENDS:=+!TARGET_ipq_ipq40xx:kmod-qca-nss-drv \
	+kmod-shortcut-fe-drv +iptables-mod-extra +kmod-ipt-conntrack \
	+kmod-ipv6 +kmod-l2tp +kmod-pppol2tp +kmod-bonding +kmod-pptp \
	+kmod-pppoe @!LINUX_3_18
  TITLE:=QCA NSS Enhanced Connection Manager (ECM)
  FILES:=$(PKG_BUILD_DIR)/*.ko $(FILES_EXAMPLES)
  KCONFIG:=CONFIG_BRIDGE_NETFILTER=y
  MENU:=1
endef

define KernelPackage/qca-nss-ecm/Description/Default
This package contains the QCA NSS Enhanced Connection Manager
endef

define KernelPackage/qca-nss-ecm/Default/install
	$(INSTALL_DIR) $(1)/etc/firewall.d $(1)/etc/init.d $(1)/usr/bin $(1)/lib/netifd/offload $(1)/etc/config $(1)/etc/uci-defaults $(1)/etc/sysctl.d
	$(INSTALL_DATA) ./files/qca-nss-ecm.firewall $(1)/etc/firewall.d/qca-nss-ecm
	$(INSTALL_BIN) ./files/qca-nss-ecm.init $(1)/etc/init.d/qca-nss-ecm
	$(INSTALL_BIN) ./files/ecm_dump.sh $(1)/usr/bin/
	$(INSTALL_BIN) ./files/on-demand-down $(1)/lib/netifd/offload/on-demand-down
	$(INSTALL_DATA) ./files/qca-nss-ecm.uci $(1)/etc/config/ecm
	$(INSTALL_DATA) ./files/qca-nss-ecm.defaults $(1)/etc/uci-defaults/99-qca-nss-ecm
	$(INSTALL_BIN) ./files/qca-nss-ecm.sysctl $(1)/etc/sysctl.d/qca-nss-ecm.conf
endef

define KernelPackage/qca-nss-ecm
  $(call KernelPackage/qca-nss-ecm/Default)
endef

define KernelPackage/qca-nss-ecm/Description
  $(call KernelPackage/qca-nss-ecm/Description/Default)
endef

define KernelPackage/qca-nss-ecm/install
$(call KernelPackage/qca-nss-ecm/Default/install, $(1))
endef

# Variant with additional features enabled for premium profile
define KernelPackage/qca-nss-ecm-premium/Default
$(call KernelPackage/qca-nss-ecm/Default)
  TITLE+= (with premium features)
  VARIANT:=premium
  DEPENDS+=+kmod-qca-hyfi-bridge +kmod-qca-mcs +kmod-nat46
endef

define KernelPackage/qca-nss-ecm-premium/Description/Default
$(call KernelPackage/qca-nss-ecm/Description/Default)
with the premium features enabled
endef

define KernelPackage/qca-nss-ecm-premium/Default/install
$(call KernelPackage/qca-nss-ecm/install)
endef

define KernelPackage/qca-nss-ecm-premium
$(call KernelPackage/qca-nss-ecm-premium/Default)
endef

define KernelPackage/qca-nss-ecm-premium/Description
$(call KernelPackage/qca-nss-ecm-premium/Description/Default)
endef

define KernelPackage/qca-nss-ecm-premium/install
$(call KernelPackage/qca-nss-ecm/install, $(1))
endef

define KernelPackage/qca-nss-ecm-noload
  $(call KernelPackage/qca-nss-ecm/Default)
  PROVIDES:=kmod-qca-nss-ecm
endef

define KernelPackage/qca-nss-ecm-noload/Description
  $(call KernelPackage/qca-nss-ecm/Description/Default)
  When selected, this package installs the driver but does not load it at init.
endef

define KernelPackage/qca-nss-ecm-noload/install
$(call KernelPackage/qca-nss-ecm/Default/install, $(1))
	#
	# Remove the START line from the init script, so that the symlink
	# in the /etc/rc.d directory is not created.
	#
	sed -i '/START=/d' $(1)/etc/init.d/qca-nss-ecm
endef

define KernelPackage/qca-nss-ecm-premium-noload
  $(call KernelPackage/qca-nss-ecm-premium/Default)
  PROVIDES:=kmod-qca-nss-ecm-premium
endef

define KernelPackage/qca-nss-ecm-premium-noload/Description
  $(call KernelPackage/qca-nss-ecm-premium/Description/Default)
  When selected, this package installs the driver but does not load it at init.
endef

define KernelPackage/qca-nss-ecm-premium-noload/install
$(call KernelPackage/qca-nss-ecm-premium/Default/install, $(1))
endef

EXTRA_CFLAGS+= \
	-I$(STAGING_DIR)/usr/include/hyfibr \
	-I$(STAGING_DIR)/usr/include/qca-mcs \
	-I$(STAGING_DIR)/usr/include/qca-nss-drv \
	-I$(STAGING_DIR)/usr/include/shortcut-fe \
	-I$(STAGING_DIR)/usr/include/nat46

ECM_MAKE_OPTS:=
ifeq ($(LOCAL_VARIANT),premium)
ECM_MAKE_OPTS+=ECM_CLASSIFIER_HYFI_ENABLE=y \
		ECM_MULTICAST_ENABLE=y
endif

ifneq ($(CONFIG_PACKAGE_kmod-nat46),)
ECM_MAKE_OPTS+=ECM_INTERFACE_MAP_T_ENABLE=y
endif

# Keeping default as ipq806x for branches that does not have subtarget framework
ifeq ($(CONFIG_TARGET_ipq),y)
subtarget:=$(SUBTARGET)
else
subtarget:=ipq806x
endif

define Build/Compile
	$(MAKE) -C "$(LINUX_DIR)" $(strip $(ECM_MAKE_OPTS)) \
		CROSS_COMPILE="$(TARGET_CROSS)" \
		ARCH="$(LINUX_KARCH)" \
		SUBDIRS="$(PKG_BUILD_DIR)" \
		EXTRA_CFLAGS="$(EXTRA_CFLAGS)" SoC="$(subtarget)" \
		EXAMPLES_BUILD_PCC="$(CONFIG_QCA_NSS_ECM_EXAMPLES_PCC)" \
		modules
endef

define KernelPackage/qca-nss-ecm/config
$(call Package/$(PKG_NAME)/override_source_path,kmod-$(PKG_NAME))
$(call Package/$(PKG_NAME)/override_version,kmod-$(PKG_NAME),$(PKG_SUPPORTED_VERSION))
menu "ECM Configuration"
	config QCA_NSS_ECM_EXAMPLES_PCC
		bool "Build PCC usage example"
		help
			Selecting this will build the PCC classifier usage example module.
		default n
endmenu
endef

$(eval $(call KernelPackage,qca-nss-ecm-noload))
$(eval $(call KernelPackage,qca-nss-ecm))
$(eval $(call KernelPackage,qca-nss-ecm-premium-noload))
$(eval $(call KernelPackage,qca-nss-ecm-premium))
