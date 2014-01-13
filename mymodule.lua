module("luci.controller.admin.mymodule", package.seeall)
function index()
    entry({"admin", "mymodule"}, alias("admin", "mymodule", "overview"), _("MyModule"), 70).index = true
    entry({"admin", "mymodule", "overview"}, cbi("mymodule_cbi"), _("Overview"), 1)

    entry({"admin", "reboot"}, call("action_reboot"), _("Reboot"), 80).index = true
end

function action_reboot()	
	luci.template.render("sysauth")
	luci.sys.reboot()
end
