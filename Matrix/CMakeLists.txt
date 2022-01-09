cmake_minimum_required(VERSION 3.20)
project(Matrix)
set(HEADER_FILES Matrix.h Transform.h)
set(SOURCE_FILES Matrix.cpp Transform.cpp)

add_library(Matrix STATIC ${SOURCE_FILES} ${HEADER_FILES})