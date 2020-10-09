#
# Copyright (C) 2008-2011 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk

ARCH:=mips
BOARD:=ar71xx
BOARDNAME:=Atheros AR7xxx/AR9xxx
FEATURES:=mips16
CPU_TYPE=74kc
KERNELNAME:=dtbs
SUBTARGETS:=generic nand mikrotik

LINUX_SRC_VERSION:=$(shell basename $(TOPDIR)/qca/src/linux-*.* | sed 's/[^0-9.]*\([0-9.]*\).*/\1/')

ifeq ($(LINUX_SRC_VERSION),4.4)
  CONFIG_EXTERNAL_KERNEL_TREE=$(shell \
        grep -q CONFIG_EXTERNAL_KERNEL_TREE="[^\/]*.\/" $(TOPDIR)/.config && \
        sed -n 's,CONFIG_EXTERNAL_KERNEL_TREE="\(.*\)",\1,p' $(TOPDIR)/.config || \
        echo '$(TOPDIR)/qca/src/linux-$(LINUX_SRC_VERSION)')
  $(eval _LINUX_DIR:=$(CONFIG_EXTERNAL_KERNEL_TREE))
  $(shell touch $(_LINUX_DIR)/.scmversion)
  _LINUX_MAJOR:=$(shell sed -n 's,VERSION = \([0-9]*\)$$,\1,p' $(_LINUX_DIR)/Makefile)
  _LINUX_MINOR:=$(shell sed -n 's,PATCHLEVEL = \([0-9]*\)$$,\1,p' $(_LINUX_DIR)/Makefile)
  _LINUX_SUBLEVEL:=$(shell sed -n 's,SUBLEVEL = \([0-9]*\)$$,\1,p' $(_LINUX_DIR)/Makefile)
  _LINUX_EXTRAVERSION:=$(shell sed -n 's,EXTRAVERSION = \([-rc0-9]*\)$$,\1,p' $(_LINUX_DIR)/Makefile)
  LINUX_VERSION:=$(_LINUX_MAJOR).$(_LINUX_MINOR)$(if $(_LINUX_SUBLEVEL),.$(_LINUX_SUBLEVEL))$(if $(_LINUX_EXTRAVERSION),$(_LINUX_EXTRAVERSION))
else
  KERNEL_PATCHVER:=3.18
endif

include $(INCLUDE_DIR)/target.mk

DEFAULT_PACKAGES += \
	kmod-gpio-button-hotplug swconfig \
	kmod-ath9k wpad-mini uboot-envtools kmod-usb-ath79

$(eval $(call BuildTarget))
