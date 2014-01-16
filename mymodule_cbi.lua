m = Map("mymodule_config",translate("My module configuration"),translate("Modify the Beacon runtime environment here"))

s = m:section(TypedSection,"BeaconConfig",translate("Beacon Configuration"))
s.anonymous = true
s.addremove = false

o = s:option(Value,"interval",translate("Beacon Interval"))
o.default = "100"

o = s:option(Flag, "ifenable", translate("Enable Beacon Interrupt Configuration"))
o.rmempty = false

o = s:option(Value,"repeat",translate("Beacon Interrupt Repeat Times"))
o:depends("ifenable", "1")
o.default = "100"

o = s:option(Value,"interrupt_string",translate("Interrupt String"))
o:depends("ifenable", "1")
o.default = "Beacon Interrupt!"
return m
