cmake_minimum_required(VERSION 3.20)
project(Light)
set(HEADER_FILES Light.h)
set(SOURCE_FILES Light.cpp)

add_library(Light STATIC ${SOURCE_FILES} ${HEADER_FILES})