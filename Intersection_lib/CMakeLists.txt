cmake_minimum_required(VERSION 3.20)
project(Intersection_lib)
set(HEADER_FILES Intersection.h)
set(SOURCE_FILES Intersection.cpp)

add_library(Intersection_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})