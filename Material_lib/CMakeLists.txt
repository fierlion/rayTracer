cmake_minimum_required(VERSION 3.20)
project(Material_lib)
set(HEADER_FILES Material.h)
set(SOURCE_FILES Material.cpp)

add_library(Material_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})