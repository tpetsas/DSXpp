cmake_minimum_required(VERSION 3.10)

project(DualSenseX++)


option(DSX_V2 "Target DSX Version 2" OFF)

if(NOT DSX_V2)
    add_definitions(-DDSX_V3)
endif()

# by default target is DSX Version 3
# to build targeting DSX Version 2, you need to provide the above option
# e.g., cmake -B build . -DDSX_V2=ON

add_library(DSX++ STATIC
    src/UDPClient.cpp
    src/DSX++.cpp
)

add_executable(DSXTest
    src/main.cpp
)

target_link_libraries(DSXTest DSX++)
