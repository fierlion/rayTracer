cmake_minimum_required(VERSION 3.20)
project(Matrix_lib)
set(HEADER_FILES Matrix.h)
set(SOURCE_FILES Matrix.cpp)

add_library(Matrix_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})