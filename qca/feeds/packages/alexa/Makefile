include $(TOPDIR)/rules.mk

PKG_NAME:=avs-device-sdk
PKG_VERSION:=1.7
PKG_RELEASE:=0
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).$(PKG_RELEASE).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION).$(PKG_RELEASE)
PKG_SOURCE_URL:=https://github.com/alexa/avs-device-sdk.git
PKG_SOURCE_BRANCH:=github/master
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=688eeefb2539ce270b88ec02810d55bfbe0ea85d
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_SOURCE_SUBDIR)
CMAKE_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/avs-device-sdk
  SECTION:=ALEXA
  CATEGORY:=ALEXA software
  TITLE:=Alexa
  URL:=
  DEPENDS:=+libcurl +glib2 +gst1-plugins-base +libgstreamer1 +libstdcpp +libsqlite3
endef

TARGET_LDFLAGS += -lcurl -lsqlite3

CMAKE_OPTIONS += \
	-DCMAKE_BUILD_TYPE=MINSIZEREL \
	-DSENSORY_KEY_WORD_DETECTOR=OFF \
	-DGSTREAMER_MEDIA_PLAYER=ON \
	-DCURL_LIBRARY=${STAGING_DIR}/usr/lib/libcurl.a \
	-DCURL_INCLUDE_DIR=${STAGING_DIR}/usr/include/

define Package/avs-device-sdk/description
 Alexa voice assistance for AVS.
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr $(1)/usr/lib $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/ACL/src/libACL.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/ACL/test/Transport/Common/libACLTransportCommonTestLib.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/ADSL/src/libADSL.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/ADSL/test/common/libADSLTestCommon.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/AFML/src/libAFML.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/ApplicationUtilities/DefaultClient/src/libDefaultClient.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/ApplicationUtilities/Resources/Audio/src/libAudioResources.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/Authorization/CBLAuthDelegate/src/libCBLAuthDelegate.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/AVSCommon/libAVSCommon.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/AVSCommon/AVS/test/Attachment/Common/libAttachmentCommonTestLib.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/AVSCommon/Utils/test/Common/libUtilsCommonTestLib.a $(1)/usr/libavs
	$(CP) $(PKG_BUILD_DIR)/CapabilityAgents/AIP/src/libAIP.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/CapabilityAgents/Alerts/src/libAlerts.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/CapabilityAgents/AudioPlayer/src/libAudioPlayer.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/CapabilityAgents/ExternalMediaPlayer/src/libExternalMediaPlayer.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/CapabilityAgents/Notifications/src/libNotifications.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/CapabilityAgents/PlaybackController/src/libPlaybackController.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/CapabilityAgents/Settings/src/libSettings.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/CapabilityAgents/SpeakerManager/src/libSpeakerManager.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/CapabilityAgents/SpeechSynthesizer/src/libSpeechSynthesizer.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/CapabilityAgents/System/src/libAVSSystem.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/CapabilityAgents/TemplateRuntime/src/libTemplateRuntime.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/CertifiedSender/src/libCertifiedSender.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/ContextManager/src/libContextManager.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/DCFDelegate/src/libDCFDelegate.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/ESP/src/libESP.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/Integration/src/libIntegration.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/KWD/src/libKWD.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/MediaPlayer/src/libMediaPlayer.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/PlaylistParser/src/libPlaylistParser.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/RegistrationManager/src/libRegistrationManager.a $(1)/usr/lib/avs
	$(CP) $(PKG_BUILD_DIR)/Storage/SQLiteStorage/src/libSQLiteStorage.a $(1)/usr/lib/avs
endef
define Package/avs-device-sdk/install
	true
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
