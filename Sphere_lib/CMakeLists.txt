cmake_minimum_required(VERSION 3.20)
project(Sphere_lib)
set(HEADER_FILES Sphere.h)
set(SOURCE_FILES Sphere.cpp)

add_library(Sphere_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})