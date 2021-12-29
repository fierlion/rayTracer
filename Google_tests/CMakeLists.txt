cmake_minimum_required(VERSION 3.20)
project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(HEADER_FILES ../Tuples_lib/Tuple.h ../Tuples_lib/Point.h ../Tuples_lib/Vector.h ../Tuples_lib/Color.h )
set(SOURCE_FILES ../Tuples_lib/Tuple.cpp ../Tuples_lib/Point.cpp ../Tuples_lib/Vector.cpp ../Tuples_lib/Color.cpp)

add_library(Tuples_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

set(HEADER_FILES ../Canvas_lib/Canvas.h)
set(SOURCE_FILES ../Canvas_lib/Canvas.cpp)

add_library(Canvas_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

# adding the Google_Tests_run target
add_executable(Google_Tests_run TupleTest.cpp CanvasTest.cpp)

# linking Google_Tests_run with Tuples_lib, Canvas_lib which will be tested
target_link_libraries(Google_Tests_run Tuples_lib Canvas_lib)

target_link_libraries(Google_Tests_run gtest gtest_main)