cmake_minimum_required(VERSION 3.10)

project(DualSenseX++)

option(DSX_V2 "Target DSX Version 2" OFF)

set(ENV{ENABLE_VIRTUAL_TERMINAL_PROCESSING} "1")

if(NOT DSX_V2)
    add_definitions(-DDSX_V3)
    message(STATUS "Build Targer: DSX version 3+")
else()
    message(STATUS "Build Targer: DSX version 2")
endif()

# by default target is DSX Version 3
# to build targeting DSX Version 2, you need to provide the above option
# e.g., cmake -B build . -DDSX_V2=ON


add_library(DSX++ STATIC
    src/UDPClient.cpp
    src/DSX++.cpp
)


set (
    PDCURSES_ROOT_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/src/thirdparty/PDCurses"
)

set (
    PDCURSES_SRC_PATH
    "${PDCURSES_ROOT_PATH}/pdcurses"
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /D_CRT_SECURE_NO_WARNINGS")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /wd4267 /wd4244")

add_library(PDcurses STATIC
    ${PDCURSES_SRC_PATH}/addch.c
    ${PDCURSES_SRC_PATH}/addchstr.c
    ${PDCURSES_SRC_PATH}/addstr.c
    ${PDCURSES_SRC_PATH}/attr.c
    ${PDCURSES_SRC_PATH}/beep.c
    ${PDCURSES_SRC_PATH}/bkgd.c
    ${PDCURSES_SRC_PATH}/border.c
    ${PDCURSES_SRC_PATH}/clear.c
    ${PDCURSES_SRC_PATH}/color.c
    ${PDCURSES_SRC_PATH}/debug.c
    ${PDCURSES_SRC_PATH}/delch.c
    ${PDCURSES_SRC_PATH}/deleteln.c
    ${PDCURSES_SRC_PATH}/getch.c
    ${PDCURSES_SRC_PATH}/getstr.c
    ${PDCURSES_SRC_PATH}/getyx.c
    ${PDCURSES_SRC_PATH}/inch.c
    ${PDCURSES_SRC_PATH}/inchstr.c
    ${PDCURSES_SRC_PATH}/initscr.c
    ${PDCURSES_SRC_PATH}/inopts.c
    ${PDCURSES_SRC_PATH}/insch.c
    ${PDCURSES_SRC_PATH}/insstr.c
    ${PDCURSES_SRC_PATH}/instr.c
    ${PDCURSES_SRC_PATH}/kernel.c
    ${PDCURSES_SRC_PATH}/keyname.c
    ${PDCURSES_SRC_PATH}/mouse.c
    ${PDCURSES_SRC_PATH}/move.c
    ${PDCURSES_SRC_PATH}/outopts.c
    ${PDCURSES_SRC_PATH}/overlay.c
    ${PDCURSES_SRC_PATH}/pad.c
    ${PDCURSES_SRC_PATH}/panel.c
    ${PDCURSES_SRC_PATH}/printw.c
    ${PDCURSES_SRC_PATH}/refresh.c
    ${PDCURSES_SRC_PATH}/scanw.c
    ${PDCURSES_SRC_PATH}/scroll.c
    ${PDCURSES_SRC_PATH}/scr_dump.c
    ${PDCURSES_SRC_PATH}/slk.c
    ${PDCURSES_SRC_PATH}/termattr.c
    ${PDCURSES_SRC_PATH}/touch.c
    ${PDCURSES_SRC_PATH}/util.c
    ${PDCURSES_SRC_PATH}/window.c
)

target_include_directories(PDcurses
        PUBLIC
        ${PDCURSES_ROOT_PATH}
)

add_executable(DSXTest
    src/main.cpp
)

target_link_libraries(DSXTest DSX++)

