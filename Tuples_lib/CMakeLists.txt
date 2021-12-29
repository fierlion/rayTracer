cmake_minimum_required(VERSION 3.20)
project(Tuples_lib)
set(HEADER_FILES Tuple.h Point.h Vector.h Color.h)
set(SOURCE_FILES Tuple.cpp Point.cpp Vector.cpp Color.cpp)

add_library(Tuples_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})