cmake_minimum_required(VERSION 3.20)
project(Shape_lib)
set(HEADER_FILES Shape.h Sphere.h)
set(SOURCE_FILES Shape.cpp Sphere.cpp)

add_library(Shape_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})