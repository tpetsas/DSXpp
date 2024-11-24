cmake_minimum_required(VERSION 3.10)

project(DualSenseX++)

add_library(DSX++ STATIC
    src/UDPClient.cpp
    src/DSX++.cpp
)

add_executable(DSXTest
    src/main.cpp
)

target_link_libraries(DSXTest DSX++)
