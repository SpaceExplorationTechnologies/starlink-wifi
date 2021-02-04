cmake_minimum_required(VERSION 2.6)

PROJECT(lacpd C)
ADD_DEFINITIONS(-O0 -Wall -Werror --std=gnu99 -Wmissing-declarations)

ADD_DEFINITIONS(-DLACPD_CONFIG_DBG_LEVEL=0xff)
ADD_DEFINITIONS(-DLACPD_STATUS_DBG_LEVEL=0xff)
ADD_DEFINITIONS(-DLACPD_LACP_DBG_LEVEL=0xff)
ADD_DEFINITIONS(-DLACPD_FSM_DBG_LEVEL=0x0)
ADD_DEFINITIONS(-DLACPD_PKT_DBG_LEVEL=0xff)
ADD_DEFINITIONS(-DLACPD_GENL_DEV_DBG_LEVEL=0xff)
ADD_DEFINITIONS(-DLACPD_WRAPPER_DBG_LEVEL=0xff)

SET(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")

SET(SOURCES
	main.c)

SET(LIBS
	ubox ubus uci)

set (LIBS ${LIBS} config)
set (LIBS ${LIBS} status)
set (LIBS ${LIBS} lacp)
set (LIBS ${LIBS} general_device)

IF(DEBUG)
  ADD_DEFINITIONS(-DDEBUG -g3)
  IF(NO_OPTIMIZE)
    ADD_DEFINITIONS(-O0)
  ENDIF()
ENDIF()

include_directories ("${PROJECT_SOURCE_DIR}/config")
include_directories ("${PROJECT_SOURCE_DIR}/status")
include_directories ("${PROJECT_SOURCE_DIR}/lacp")
include_directories ("${PROJECT_SOURCE_DIR}/lib_general_device")

add_subdirectory (lacp)
add_subdirectory (status)
add_subdirectory (config)
add_subdirectory (lib_general_device)

ADD_EXECUTABLE(lacpd ${SOURCES})

TARGET_LINK_LIBRARIES(lacpd ${LIBS})

INSTALL(TARGETS lacpd
	RUNTIME DESTINATION sbin
)
