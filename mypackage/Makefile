include $(TOPDIR)/rules.mk

PKG_NAME:=LYC-SocketPackage
PKG_VERSION:=1.0
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/$(PKG_NAME)
  SECTION:=DIY
  CATEGORY:=LYC Package
  DEFAULT:=y
  TITLE:=LYC-SocketPackage
  MAINTAINER:=Yichen Liu
  URL:=http://lyc.net/
endef

define Package/$(PKG_NAME)/description
This is LYC's socket package!This Package uses the modified ath9k driver and mac80211 driver to test!
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_NAME) $(1)/usr/bin/
endef

$(eval $(call BuildPackage,LYC-SocketPackage))
