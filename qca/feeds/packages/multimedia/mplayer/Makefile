#
# Copyright (C) 2006-2010 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=mplayer
PKG_VERSION:=1.1.1
PKG_RELEASE:=1

PKG_SOURCE:=MPlayer-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=http://www.mplayerhq.hu/MPlayer/releases/
PKG_BUILD_DIR=$(BUILD_DIR)/MPlayer-$(PKG_VERSION)
PKG_MD5SUM:=39dd55f30eb5403f219a606e79a6648a

include $(INCLUDE_DIR)/package.mk

define Package/mplayer
  SECTION:=sound
  CATEGORY:=Sound
  TITLE:=MPlayer
  URL:=http://www.mplayerhq.hu/
  DEPENDS:=@!TARGET_ipq_ipq807x_64 +libbz2 +libpthread +libncurses +libmad +libmpg123 +libltdl +alsa-lib +liblzo +libSDL +libogg +libtheora +zlib +opencore-amr +libffmpeg-full +libspeex +libvpx

endef

define Package/mplayer/description
MPlayer can play most standard video formats out of the box
and almost all others with the help of external codecs.
endef

CONFIGURE_ARGS = \
	--target=$(GNU_TARGET_NAME) \
	--prefix=/usr \
	--disable-mencoder \
	--disable-vidix \
	--disable-vm \
	--disable-dvdnav \
	--disable-dvdread \
	--disable-dvdread-internal \
	--disable-libdvdcss-internal \
	--disable-pvr \
	--disable-tv \
	--disable-v4l2 \
	--enable-mp3lib \
	--enable-mp3lame \
	--enable-libmpeg2\
	--disable-tv-v4l1 \
	--disable-sdl\
	--disable-tv-v4l2 \
	--disable-dvb \
	--disable-xanim \
	--disable-win32dll \
	--disable-dvb \
	--disable-yuv4mpeg \
	--disable-pnm \
	--disable-tga \
	--disable-fbdev \
	--disable-aa \
	--disable-fribidi \
	--disable-gif \
	--disable-png \
	--disable-jpeg \
	--disable-faad \
	--enable-libopencore_amrnb \
	--enable-libopencore_amrwb

define Package/mplayer/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/mplayer $(1)/usr/bin/
endef

$(eval $(call BuildPackage,mplayer))
