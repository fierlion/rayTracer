cmake_minimum_required(VERSION 3.20)
project(Ray_lib)
set(HEADER_FILES Ray.h)
set(SOURCE_FILES Ray.cpp)

add_library(Ray STATIC ${SOURCE_FILES} ${HEADER_FILES})