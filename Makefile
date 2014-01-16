OpenWRT_DIR=/var/OpenWRT/attitude_adjustment
all:
	@cp -f mymodule_config $(OpenWRT_DIR)/package/base-files/files/etc/config/mymodule_config
	@cp -f mymodule.lua $(OpenWRT_DIR)/build_dir/target-mips_r2_uClibc-0.9.33.2/luci-0.11+svn9932/modules/admin-full/luasrc/controller/admin/mymodule.lua
	@cp -f mymodule_cbi.lua $(OpenWRT_DIR)/build_dir/target-mips_r2_uClibc-0.9.33.2/luci-0.11+svn9932/modules/admin-full/luasrc/model/cbi/mymodule_cbi.lua
	@cp -f base.po $(OpenWRT_DIR)/build_dir/target-mips_r2_uClibc-0.9.33.2/luci-0.11+svn9932/po/zh_CN/base.po
#
	@cp -f myinit $(OpenWRT_DIR)/package/base-files/files/etc/init.d/myinit
	@cp -f myconfig/ifenable $(OpenWRT_DIR)/package/base-files/files/etc/config/myconfig/ifenable
	@cp -f myconfig/beacon_interval $(OpenWRT_DIR)/package/base-files/files/etc/config/myconfig/beacon_interval
	@cp -f myconfig/interrupt_string $(OpenWRT_DIR)/package/base-files/files/etc/config/myconfig/interrupt_string
#
	@cp -f ath9k/main.c $(OpenWRT_DIR)/build_dir/linux-ar71xx_generic/compat-wireless-2013-06-27/drivers/net/wireless/ath/ath9k/main.c
	@cp -f mac80211/main.c $(OpenWRT_DIR)/build_dir/linux-ar71xx_generic/compat-wireless-2013-06-27/net/mac80211/main.c
#
	@cp -f hostapd/ap_config.c $(OpenWRT_DIR)/build_dir/target-mips_r2_uClibc-0.9.33.2/hostapd-wpad-mini/hostapd-20130405/src/ap/ap_config.c
#
	@cp -r mypackage $(OpenWRT_DIR)/package
	
	@find ./ -name '*~' -exec rm -rf {} \;
.PHONY:all
