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

set(HEADER_FILES ../Matrix_lib/Matrix.h ../Matrix_lib/Matrix2.h ../Matrix_lib/Matrix3.h)
set(SOURCE_FILES ../Matrix_lib/Matrix.cpp ../Matrix_lib/Matrix2.cpp ../Matrix_lib/Matrix3.cpp)

add_library(Matrix_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

# adding the Google_Tests_run target
add_executable(Google_Tests_run TupleTest.cpp CanvasTest.cpp MatrixTest.cpp)

# linking Google_Tests_run with Tuples_lib, Canvas_lib which will be tested
target_link_libraries(Google_Tests_run Tuples_lib Canvas_lib Matrix_lib)

target_link_libraries(Google_Tests_run gtest gtest_main)