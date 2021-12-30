cmake_minimum_required(VERSION 3.20)
project(Matrix_lib)
set(HEADER_FILES Matrix.h Matrix2.h Matrix3.h)
set(SOURCE_FILES Matrix.cpp Matrix2.cpp Matrix3.cpp)

add_library(Matrix_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})