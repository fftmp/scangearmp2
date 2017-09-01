cmake_minimum_required(VERSION 3.4)

project(scangearmp2-sane)

set(CMAKE_INSTALL_PREFIX "/usr")
set(CFLAGS_WARN     "-Wall -Wextra -Werror")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${CFLAGS_WARN}")

include(GNUInstallDirs) # for make install

find_program(INTLTOOL_UPDATE_EXECUTABLE intltool-update)
if(NOT INTLTOOL_UPDATE_EXECUTABLE)
    message(FATAL_ERROR "Couldn't find intltool-update")
endif()

find_package(Gettext REQUIRED)
include(FindPkgConfig)
pkg_search_module(LIBUSB REQUIRED libusb-1.0)
pkg_search_module(GTK2 REQUIRED gtk+-2.0>=2.16)
pkg_search_module(SANE REQUIRED sane-backends)
find_package(JPEG REQUIRED)

option(DEBUG "turn on debug info" OFF)

add_subdirectory(po)
add_subdirectory(src)
add_subdirectory(usr/lib64)
add_subdirectory(usr/share/scangearmp2)

install(FILES "etc/udev/rules.d/80-canon_mfp2.rules" DESTINATION "/etc/udev/rules.d/")
