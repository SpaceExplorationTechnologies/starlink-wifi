add_library(status status.c status_hotplug.c status_ubus.c)
target_link_libraries(status ubus)
