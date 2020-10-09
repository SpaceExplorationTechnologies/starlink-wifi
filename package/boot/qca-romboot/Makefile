#
# Copyright (c) 2013 The Linux Foundation. All rights reserved.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=qca-romboot
PKG_SOURCE_PROTO:=git
PKG_VERSION:=master
PKG_RELEASE:=1

LOCAL_SRC=$(TOPDIR)/qca/src/qca-romboot
include $(INCLUDE_DIR)/local-development.mk
ifeq ($(DUMP)$(PKG_VERSION),)
  PKG_VERSION:=$(shell git ls-remote $(PKG_SOURCE_URL) $(PKG_BRANCH) | cut -b -7)
endif
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_VERSION)

PKG_BUILD_DEPENDS:=qca-romboot/host

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/host-build.mk

define DefineRomboot
  define Package/qca-romboot-$(1)
    TITLE:=Rom boot code for $(1)
    SECTION:=boot
    CATEGORY:=Boot Loaders
    DEPENDS:=@TARGET_ar71xx
    URL:=http://www.qca.qualcomm.com
    VARIANT:=$(1)
  endef

  define Package/qca-romboot-$(1)/description
    This package contains the assembly code requied to init the chip and
    perform specific initialization prior to the bootloader. It's mainly
    executed before the bootloader for NAND boot.
    This package generates code for the $(1) SoC.
  endef

  define Package/qca-romboot-qca955x_target_drv/install
	$(INSTALL_DIR) $$(1)/lib/firmware
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(ROMBOOT_SUBDIR)/ath_tgt_fw1.fw $$(1)/lib/firmware
  endef

  $$(eval $$(call BuildPackage,qca-romboot-$(1)))
endef

define Package/qca-romboot-fw2
  TITLE:=Second stage firmware for target
  SECTION:=boot
  CATEGORY:=Boot Loaders
  DEPENDS:=@TARGET_ar71xx
  URL:=http://www.qca.qualcomm.com
endef

define Package/qca-romboot-fw2/description
  This package contains the 2nd stage firmware corresponding to the target
device.
endef


MAKEOPTS_QCA_ROMBOOT:= \
	CROSS_COMPILE=$(TARGET_CROSS) \
	UTILPATH=$(STAGING_DIR_HOST)/bin

ifeq ($(BUILD_VARIANT),ar934x)
  ROMBOOT_SUBDIR:=wasp
endif
ifeq ($(BUILD_VARIANT),qca955x)
  ROMBOOT_SUBDIR:=sco
endif
ifeq ($(BUILD_VARIANT),qca955x_target_drv)
  ROMBOOT_SUBDIR:=sco
endif

ifneq ("$(wildcard $(KERNEL_BUILD_DIR)/tmp/vmlinux-initramfs-ap135-020)","")
  define Build/Compile/qca-romboot-fw2
	$(CP) $(KERNEL_BUILD_DIR)/tmp/vmlinux-initramfs-ap135-020 $(PKG_BUILD_DIR)/utils/simple-lzma/vmlrd.bin
	make -C $(PKG_BUILD_DIR)/utils/simple-lzma all STAGING_UTIL_PATH=$(STAGING_DIR_HOST)/bin \
		$(MAKEOPTS_QCA_ROMBOOT) TOPDIR=$(PKG_BUILD_DIR)/utils/simple-lzma
  endef
endif

define Build/Compile
	($(foreach var,$(strip $(shell cat configs/$(BUILD_VARIANT).config)), export ${var};) \
	 env; \
	 make -C $(PKG_BUILD_DIR)/$(ROMBOOT_SUBDIR) clean all $(MAKEOPTS_QCA_ROMBOOT) \
		TOPDIR=$(PKG_BUILD_DIR)/$(ROMBOOT_SUBDIR)/ \
	)
	$(call Build/Compile/qca-romboot-fw2)
endef

define Build/InstallDev
	$(INSTALL_DIR) $(STAGING_DIR)/boot
	$(CP) $(PKG_BUILD_DIR)/$(ROMBOOT_SUBDIR)/rombootdrv.bin $(STAGING_DIR)/boot/openwrt-$(BOARD)-$(BUILD_VARIANT)-rombootdrv.bin
endef

ifneq ("$(wildcard $(KERNEL_BUILD_DIR)/tmp/vmlinux-initramfs-ap135-020)","")
  define Package/qca-romboot-fw2/install
	$(INSTALL_DIR) $(1)/lib/firmware
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/utils/simple-lzma/ath_tgt_fw2.fw $(1)/lib/firmware/
  endef
endif

define Host/Prepare
	$(CP) $(TOPDIR)/qca/src/qca-romboot/utils $(HOST_BUILD_DIR)/
endef

define Host/Compile
	$(HOSTCC) $(HOST_CFLAGS) -o $(HOST_BUILD_DIR)/bin2hex src/bin2hex.c
	$(HOSTCC) $(HOST_CFLAGS) -o $(HOST_BUILD_DIR)/bin2barray $(HOST_BUILD_DIR)/utils/bin2barray/bin2barray.c
	$(HOSTCC) $(HOST_CFLAGS) -o $(HOST_BUILD_DIR)/checksum src/checksum.c
	$(HOSTCC) $(HOST_CFLAGS) -o $(HOST_BUILD_DIR)/array2bin src/array2bin.c
endef

define Host/Install
	$(INSTALL_DIR) $(STAGING_DIR_HOST)/bin
	$(INSTALL_BIN) $(HOST_BUILD_DIR)/bin2hex $(STAGING_DIR_HOST)/bin
	$(INSTALL_BIN) $(HOST_BUILD_DIR)/bin2barray $(STAGING_DIR_HOST)/bin
	$(INSTALL_BIN) $(HOST_BUILD_DIR)/checksum $(STAGING_DIR_HOST)/bin
	$(INSTALL_BIN) $(HOST_BUILD_DIR)/array2bin $(STAGING_DIR_HOST)/bin
	$(INSTALL_BIN) $(LOCAL_SRC)/wasp/mk2stage $(STAGING_DIR_HOST)/bin/mk2stage-ar934x
	$(INSTALL_BIN) $(LOCAL_SRC)/sco/mk2stage $(STAGING_DIR_HOST)/bin/mk2stage-qca955x
endef

$(eval $(call DefineRomboot,ar934x))
$(eval $(call DefineRomboot,qca955x))
$(eval $(call DefineRomboot,qca955x_target_drv))
$(eval $(call BuildPackage,qca-romboot-fw2))
$(eval $(call HostBuild))
