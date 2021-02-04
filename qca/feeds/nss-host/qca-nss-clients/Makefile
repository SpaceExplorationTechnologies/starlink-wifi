include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=qca-nss-clients
PKG_SOURCE_PROTO:=git
PKG_BRANCH:=master
PKG_RELEASE:=2

include $(INCLUDE_DIR)/local-development.mk
ifeq ($(DUMP)$(PKG_VERSION),)
  PKG_VERSION:=$(shell git ls-remote $(PKG_SOURCE_URL) $(PKG_BRANCH) | cut -b -7)
endif
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_VERSION)

PKG_BUILD_DEPENDS := PACKAGE_kmod-qca-nss-crypto:kmod-qca-nss-crypto
MAKE_OPTS:=

include $(INCLUDE_DIR)/package.mk

# Keep default as ipq806x for branches that does not have subtarget framework
ifeq ($(CONFIG_TARGET_ipq),y)
subtarget:=$(SUBTARGET)
else
subtarget:=ipq806x
endif

ifneq (, $(findstring ipq807x, $(subtarget)))
# DTLS Manager v2.0 for Hawkeye
  DTLSMGR_DIR:=v2.0
# IPsec Manager v2.0 for Hawkeye
  IPSECMGR_DIR:=v2.0
else
# DTLS Manager v1.0 for Akronite.
  DTLSMGR_DIR:=v1.0
# IPsec Manager v1.0 for Akronite.
  IPSECMGR_DIR:=v1.0
endif

define KernelPackage/qca-nss-drv-tun6rd
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Devices
  TITLE:=Kernel driver for NSS (connection manager) - tun6rd
  DEPENDS:=+kmod-qca-nss-drv +kmod-sit @!LINUX_3_18
  FILES:=$(PKG_BUILD_DIR)/qca-nss-tun6rd.ko
  AUTOLOAD:=$(call AutoLoad,60,qca-nss-tun6rd)
endef

define KernelPackage/qca-nss-drv-tun6rd/Description
Kernel modules for NSS connection manager - Support for 6rd tunnel
endef

define KernelPackage/qca-nss-drv-dtlsmgr
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Devices
  TITLE:=Kernel driver for NSS (connection manager) - dtlsmgr
  DEPENDS:=+kmod-qca-nss-drv +kmod-qca-nss-cfi @!LINUX_3_18
  FILES:=$(PKG_BUILD_DIR)/dtls/$(DTLSMGR_DIR)/qca-nss-dtlsmgr.ko
endef

define KernelPackage/qca-nss-drv-dtls/Description
Kernel modules for NSS connection manager - Support for DTLS sessions
endef

define KernelPackage/qca-nss-drv-l2tpv2
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Devices
  TITLE:=Kernel driver for NSS (connection manager) - l2tp
  DEPENDS:=+kmod-qca-nss-drv +kmod-ppp +kmod-l2tp @!LINUX_3_18
  FILES:=$(PKG_BUILD_DIR)/l2tp/l2tpv2/qca-nss-l2tpv2.ko
  AUTOLOAD:=$(call AutoLoad,51,qca-nss-l2tpv2)
endef

define KernelPackage/qca-nss-drv-l2tp/Description
Kernel modules for NSS connection manager - Support for l2tp tunnel
endef

define KernelPackage/qca-nss-drv-pptp
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Devices
  TITLE:=Kernel driver for NSS (connection manager) - PPTP
  DEPENDS:=+kmod-qca-nss-drv +kmod-pptp @!LINUX_3_18
  FILES:=$(PKG_BUILD_DIR)/pptp/qca-nss-pptp.ko
  AUTOLOAD:=$(call AutoLoad,51,qca-nss-pptp)
endef

define KernelPackage/qca-nss-drv-pptp/Description
Kernel modules for NSS connection manager - Support for PPTP tunnel
endef

define KernelPackage/qca-nss-drv-map-t
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Devices
  TITLE:=Kernel driver for NSS (connection manager) - MAP-T
  DEPENDS:=+kmod-qca-nss-drv +kmod-nat46 @!LINUX_3_18
  FILES:=$(PKG_BUILD_DIR)/map/map-t/qca-nss-map-t.ko
  AUTOLOAD:=$(call AutoLoad,51,qca-nss-map-t)
endef

define KernelPackage/qca-nss-drv-map-t/Description
Kernel modules for NSS connection manager - Support for MAP-T
endef

define KernelPackage/qca-nss-drv-gre
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Devices
  TITLE:=Kernel driver for NSS (connection manager) - GRE
  DEPENDS:=@TARGET_ipq_ipq806x||TARGET_ipq806x||TARGET_ipq_ipq807x||TARGET_ipq_ipq807x_64 +kmod-qca-nss-drv @!LINUX_3_18 +kmod-gre6
  FILES:=$(PKG_BUILD_DIR)/gre/qca-nss-gre.ko $(PKG_BUILD_DIR)/gre/test/qca-nss-gre-test.ko
  AUTOLOAD:=$(call AutoLoad,51,qca-nss-gre)
endef

define KernelPackage/qca-nss-drv-gre/Description
Kernel modules for NSS connection manager - Support for GRE
endef

define KernelPackage/qca-nss-drv-tunipip6
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Devices
  TITLE:=Kernel driver for NSS (connection manager) - DS-lite and ipip6 Tunnel
  DEPENDS:=+kmod-qca-nss-drv +kmod-iptunnel6 +kmod-ip6-tunnel @!LINUX_3_18
  FILES:=$(PKG_BUILD_DIR)/qca-nss-tunipip6.ko
  AUTOLOAD:=$(call AutoLoad,60,qca-nss-tunipip6)
endef

define KernelPackage/qca-nss-drv-tunipip6/Description
Kernel modules for NSS connection manager
Add support for DS-lite and ipip6 tunnel
endef

define KernelPackage/qca-nss-drv-profile
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Devices
  DEPENDS:=+kmod-qca-nss-drv @!LINUX_3_18
  TITLE:=Profiler for QCA NSS driver (IPQ806x)
  FILES:=$(PKG_BUILD_DIR)/profiler/qca-nss-profile-drv.ko
endef

define KernelPackage/qca-nss-drv-profile/Description
This package contains a NSS driver profiler for QCA chipset
endef

define KernelPackage/qca-nss-drv-ipsecmgr
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Devices
  TITLE:=Kernel driver for NSS (ipsec manager) - ipsecmgr
  DEPENDS:=@TARGET_ipq806x||TARGET_ipq_ipq806x||TARGET_ipq_ipq807x||TARGET_ipq_ipq807x_64 \
		+kmod-qca-nss-drv +kmod-qca-nss-cfi-cryptoapi @!LINUX_3_18
  FILES:=$(PKG_BUILD_DIR)/ipsecmgr/$(IPSECMGR_DIR)/qca-nss-ipsecmgr.ko
  AUTOLOAD:=$(call AutoLoad,60,qca-nss-ipsecmgr)
endef

define KernelPackage/qca-nss-drv-ipsecmgr/Description
Kernel module for NSS IPsec offload manager
endef

define KernelPackage/qca-nss-drv-capwapmgr
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Devices
  DEPENDS:=+kmod-qca-nss-drv +kmod-qca-nss-drv-dtlsmgr @!LINUX_3_18
  TITLE:=NSS CAPWAP Manager for QCA NSS driver (IPQ806x)
  FILES:=$(PKG_BUILD_DIR)/capwapmgr/qca-nss-capwapmgr.ko
endef

define KernelPackage/qca-nss-drv-capwapmgr/Description
This package contains a NSS CAPWAP Manager
endef

define KernelPackage/qca-nss-drv-bridge-mgr
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Devices
  TITLE:=Kernel driver for NSS bridge manager
  DEPENDS:=@TARGET_ipq_ipq807x||TARGET_ipq_ipq807x_64 +kmod-bonding \
		+TARGET_ipq_ipq807x:kmod-qca-nss-drv-vlan-mgr \
		+TARGET_ipq_ipq807x_64:kmod-qca-nss-drv-vlan-mgr @!LINUX_3_18
  FILES:=$(PKG_BUILD_DIR)/bridge/qca-nss-bridge-mgr.ko
  AUTOLOAD:=$(call AutoLoad,51,qca-nss-bridge-mgr)
endef

define KernelPackage/qca-nss-drv-bridge-mgr/Description
Kernel modules for NSS bridge manager
endef

define KernelPackage/qca-nss-drv-vlan-mgr
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Devices
  TITLE:=Kernel driver for NSS vlan manager
  DEPENDS:=@TARGET_ipq_ipq807x||TARGET_ipq_ipq807x_64 +kmod-qca-nss-drv @!LINUX_3_18
ifeq ($(CONFIG_PACKAGE_kmod-bonding),y)
  DEPENDS:=+kmod-bonding
endif
  FILES:=$(PKG_BUILD_DIR)/vlan/qca-nss-vlan.ko
  AUTOLOAD:=$(call AutoLoad,51,qca-nss-vlan)
endef

define KernelPackage/qca-nss-drv-vlan-mgr/Description
Kernel modules for NSS vlan manager
endef

define KernelPackage/qca-nss-drv-qdisc
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Support
  TITLE:=Qdisc for configuring shapers in NSS
  DEPENDS:=+kmod-qca-nss-drv @!LINUX_3_18
  FILES:=$(PKG_BUILD_DIR)/nss_qdisc/qca-nss-qdisc.ko
  AUTOLOAD:=$(call AutoLoad,58,qca-nss-qdisc)
endef

define KernelPackage/qca-nss-drv-qdisc/Description
Linux qdisc that aids in configuring shapers in the NSS
endef

define KernelPackage/qca-nss-drv-lag-mgr
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Devices
  TITLE:=Kernel driver for NSS LAG manager
  DEPENDS:=+kmod-qca-nss-drv  @!LINUX_3_18 \
	   +TARGET_ipq_ipq807x:kmod-qca-nss-drv-vlan-mgr \
	   +TARGET_ipq_ipq807x_64:kmod-qca-nss-drv-vlan-mgr @!LINUX_3_18 \
	   +kmod-bonding
  FILES:=$(PKG_BUILD_DIR)/lag/qca-nss-lag-mgr.ko
  AUTOLOAD:=$(call AutoLoad,51,qca-nss-lag-mgr)
endef

define KernelPackage/qca-nss-drv-lag-mgr/Description
Kernel modules for NSS LAG manager
endef

EXTRA_CFLAGS+= \
	-I$(STAGING_DIR)/usr/include/qca-nss-drv \
	-I$(STAGING_DIR)/usr/include/qca-nss-crypto \
	-I$(STAGING_DIR)/usr/include/qca-nss-cfi \
	-I$(STAGING_DIR)/usr/include/qca-nss-gmac \
	-I$(STAGING_DIR)/usr/include/qca-ssdk \
	-I$(STAGING_DIR)/usr/include/qca-ssdk/fal \
	-I$(STAGING_DIR)/usr/include/nat46

# Build individual packages if selected
ifeq ($(CONFIG_PACKAGE_kmod-qca-nss-drv-profile),y)
MAKE_OPTS+=profile=y
endif

ifeq ($(CONFIG_PACKAGE_kmod-qca-nss-drv-capwapmgr),y)
MAKE_OPTS+=capwapmgr=y
endif

ifeq ($(CONFIG_PACKAGE_kmod-qca-nss-drv-tun6rd),y)
MAKE_OPTS+=tun6rd=m
endif

ifeq ($(CONFIG_PACKAGE_kmod-qca-nss-drv-dtlsmgr),y)
MAKE_OPTS+=dtlsmgr=y
endif

ifeq ($(CONFIG_PACKAGE_kmod-qca-nss-drv-l2tpv2),y)
MAKE_OPTS+=l2tpv2=y
endif

ifeq ($(CONFIG_PACKAGE_kmod-qca-nss-drv-pptp),y)
MAKE_OPTS+=pptp=y
endif

ifeq ($(CONFIG_PACKAGE_kmod-qca-nss-drv-map-t),y)
MAKE_OPTS+=map-t=y
endif

ifeq ($(CONFIG_PACKAGE_kmod-qca-nss-drv-tunipip6),y)
MAKE_OPTS+=tunipip6=m
endif

ifeq ($(CONFIG_PACKAGE_kmod-qca-nss-drv-qdisc),y)
MAKE_OPTS+=qdisc=y
endif

ifeq ($(CONFIG_PACKAGE_kmod-qca-nss-drv-ipsecmgr),y)
MAKE_OPTS+=ipsecmgr=y
endif

ifeq ($(CONFIG_PACKAGE_kmod-qca-nss-drv-bridge-mgr),y)
MAKE_OPTS+=bridge-mgr=y
endif

ifeq ($(CONFIG_PACKAGE_kmod-qca-nss-drv-vlan-mgr),y)
MAKE_OPTS+=vlan-mgr=y
endif

ifeq ($(CONFIG_PACKAGE_kmod-qca-nss-drv-lag-mgr),y)
MAKE_OPTS+=lag-mgr=y
endif

ifeq ($(CONFIG_PACKAGE_kmod-qca-nss-drv-gre),y)
MAKE_OPTS+=gre=y
endif

define Build/Compile
	$(MAKE) -C "$(LINUX_DIR)" $(strip $(MAKE_OPTS)) \
		CROSS_COMPILE="$(TARGET_CROSS)" \
		ARCH="$(LINUX_KARCH)" \
		SUBDIRS="$(PKG_BUILD_DIR)" \
		EXTRA_CFLAGS="$(EXTRA_CFLAGS)" \
		SoC="$(subtarget)" \
		DTLSMGR_DIR="$(DTLSMGR_DIR)" \
		IPSECMGR_DIR="$(IPSECMGR_DIR)" \
		modules
endef

$(eval $(call KernelPackage,qca-nss-drv-profile))
$(eval $(call KernelPackage,qca-nss-drv-capwapmgr))
$(eval $(call KernelPackage,qca-nss-drv-tun6rd))
$(eval $(call KernelPackage,qca-nss-drv-dtlsmgr))
$(eval $(call KernelPackage,qca-nss-drv-l2tpv2))
$(eval $(call KernelPackage,qca-nss-drv-pptp))
$(eval $(call KernelPackage,qca-nss-drv-map-t))
$(eval $(call KernelPackage,qca-nss-drv-tunipip6))
$(eval $(call KernelPackage,qca-nss-drv-qdisc))
$(eval $(call KernelPackage,qca-nss-drv-ipsecmgr))
$(eval $(call KernelPackage,qca-nss-drv-bridge-mgr))
$(eval $(call KernelPackage,qca-nss-drv-vlan-mgr))
$(eval $(call KernelPackage,qca-nss-drv-lag-mgr))
$(eval $(call KernelPackage,qca-nss-drv-gre))
