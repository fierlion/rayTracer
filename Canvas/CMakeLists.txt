cmake_minimum_required(VERSION 3.20)
project(Canvas_lib)
set(HEADER_FILES Canvas.h)
set(SOURCE_FILES Canvas.cpp)

add_library(Canvas_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})