# Copyright (c) 2013 The Linux Foundation. All rights reserved.
#
include $(TOPDIR)/rules.mk

ARCH:=arm
BOARD:=ipq
BOARDNAME:=Qualcomm Atheros IPQ
FEATURES:=ubifs squashfs pcie usbgadget
CPU_TYPE:=cortex-a7
SUBTARGETS:=ipq806x ipq40xx ipq807x ipq807x_64
MAINTAINER:=John Crispin <blogic@openwrt.org>

KERNELNAME:=zImage Image dtbs

LINUX_SRC_VERSION:=$(shell basename $(TOPDIR)/qca/src/linux-*.* | sed 's/[^0-9.]*\([0-9.]*\).*/\1/')
# check .config for an overridden Linux dir, otherwise use qca/src/linux
CONFIG_EXTERNAL_KERNEL_TREE=$(shell \
	grep -q CONFIG_EXTERNAL_KERNEL_TREE="[^\/]*.\/" $(TOPDIR)/.config && \
	sed -n 's,CONFIG_EXTERNAL_KERNEL_TREE="\(.*\)",\1,p' $(TOPDIR)/.config || \
	echo '$(TOPDIR)/qca/src/linux-$(LINUX_SRC_VERSION)')


ifneq ($(CONFIG_EXTERNAL_KERNEL_TREE),"")
  $(eval _LINUX_DIR:=$(CONFIG_EXTERNAL_KERNEL_TREE))
  $(shell touch $(_LINUX_DIR)/.scmversion)
  _LINUX_MAJOR:=$(shell sed -n 's,VERSION = \([0-9]*\)$$,\1,p' $(_LINUX_DIR)/Makefile)
  _LINUX_MINOR:=$(shell sed -n 's,PATCHLEVEL = \([0-9]*\)$$,\1,p' $(_LINUX_DIR)/Makefile)
  _LINUX_SUBLEVEL:=$(shell sed -n 's,SUBLEVEL = \([0-9]*\)$$,\1,p' $(_LINUX_DIR)/Makefile)
  _LINUX_EXTRAVERSION:=$(shell sed -n 's,EXTRAVERSION = \([-rc0-9]*\)$$,\1,p' $(_LINUX_DIR)/Makefile)
  LINUX_VERSION:=$(_LINUX_MAJOR).$(_LINUX_MINOR)$(if $(_LINUX_SUBLEVEL),.$(_LINUX_SUBLEVEL))$(if $(_LINUX_EXTRAVERSION),$(_LINUX_EXTRAVERSION))
else
  LINUX_VERSION:=3.18.21
endif

include $(INCLUDE_DIR)/target.mk
DEFAULT_PACKAGES += \
	uboot-envtools kmod-leds-gpio kmod-gpio-button-hotplug kmod-button-hotplug \
	kmod-ata-core kmod-ata-ahci kmod-ata-ahci-platform kmod-usb2 kmod-usb3 \
	kmod-usb-dwc3-qcom kmod-usb-phy-qcom-dwc3 kmod-usb-dwc3-of-simple swconfig

$(eval $(call BuildTarget))
