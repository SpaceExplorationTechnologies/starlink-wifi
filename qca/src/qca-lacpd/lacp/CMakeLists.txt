add_library(lacp aggregator.c fsm.c lacp.c lacpdu.c lacp_fsm.c port.c port_info.c)
target_link_libraries(lacp ubox)
