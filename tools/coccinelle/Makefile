#
# Copyright (C) 2014 2015 The Linux Foundation. All rights reserved.
#
include $(TOPDIR)/rules.mk

PKG_NAME:=coccinelle
PKG_VERSION:=1.0.0-rc24

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/coccinelle/coccinelle/archive/
PKG_MD5SUM:=8cbe943716a7a1033d46f8157ea986d4

HOST_BUILD_DIR:=$(BUILD_DIR_HOST)/coccinelle-coccinelle-$(PKG_VERSION)

HOST_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/host-build.mk

HOST_CONFIGURE_ARGS += --with-pdflatex=no --disable-pcre-syntax

$(eval $(call HostBuild))
