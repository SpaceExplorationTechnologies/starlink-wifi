
include $(TOPDIR)/rules.mk

PKG_NAME:=alsa-plugins
PKG_VERSION:=1.0.28
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=ftp://ftp.alsa-project.org/pub/plugins/
PKG_MD5SUM:=6fcbbb31e96f8ebc5fb926184a717aa4
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/alsa-plugins/Default
  SECTION:=sound
  CATEGORY:=Sound
  DEPENDS:=+alsa-lib +libncursesw +libpthread
  TITLE:=ALSA (Advanced Linux Sound Architecture) Plugins
endef

define Package/alsa-plugins-speex
 $(call Package/alsa-plugins/Default)
 TITLE+= Speex
endef

define Package/alsa-plugins-oss
 $(call Package/alsa-plugins/Default)
 TITLE+= oss
endef

define Package/alsa-plugins-gcs
 $(call Package/alsa-plugins/Default)
 DEPENDS:=+ffmpeg +libspeexdsp graphite-client
 TITLE+= gcs
endef

define Package/alsa-plugins-full
 $(call Package/alsa-plugins/Default)
 TITLE+= full
endef

define Package/alsa-plugins-oss/description
 ALSA (Advanced Linux Sound Architecture) oss Plugins required for audio.
endef

define Package/alsa-plugins-speex/description
 ALSA (Advanced Linux Sound Architecture) Speex Plugins required for audio.
endef

TARGET_CFLAGS += \
		 -I$(STAGING_DIR)/usr/include/gcs -I$(STAGING_DIR)/usr/include/osal -include stdint.h -DMREMAP_MAYMOVE=1 -D_OPEN_WRT_

CONFIGURE_ARGS+= \
		--enable-jack \
		--enable-pcm \
		--with-speex=lib \
		--enable-pulseaudio \
		--enable-samplerate

define Package/alsa-plugins-speex/install
	$(INSTALL_DIR) $(1)/usr/lib/alsa-lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/alsa-lib/libasound_module_rate_speexrate.so $(1)/usr/lib/alsa-lib/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/alsa-lib/libasound_module_rate_speexrate_medium.so $(1)/usr/lib/alsa-lib/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/alsa-lib/libasound_module_rate_speexrate_best.so $(1)/usr/lib/alsa-lib/
endef

define Package/alsa-plugins-oss/install
	$(INSTALL_DIR) $(1)/usr/lib/alsa-lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/alsa-lib/libasound_module_ctl_oss.so $(1)/usr/lib/alsa-lib/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/alsa-lib/libasound_module_pcm_oss.so $(1)/usr/lib/alsa-lib/
endef

define Package/alsa-plugins-full/install
	$(INSTALL_DIR) $(1)/usr/lib/alsa-lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/alsa-lib/libasound_module_*.so $(1)/usr/lib/alsa-lib/
endef

define Package/alsa-plugins-gcs/install
	$(INSTALL_DIR) $(1)/usr/lib/alsa-lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/alsa-lib/libasound_module_pcm_*.so $(1)/usr/lib/alsa-lib/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/alsa-lib/libasound_module_pcm_gcs_io.so $(1)/usr/lib/alsa-lib/
endef

$(eval $(call BuildPackage,alsa-plugins-oss))
$(eval $(call BuildPackage,alsa-plugins-speex))
$(eval $(call BuildPackage,alsa-plugins-full))
$(eval $(call BuildPackage,alsa-plugins-gcs))
