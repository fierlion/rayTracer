cmake_minimum_required(VERSION 3.20)
project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(HEADER_FILES ../Tuples_lib/Tuple.h ../Tuples_lib/Point.h ../Tuples_lib/Vector.h ../Tuples_lib/Color.h )
set(SOURCE_FILES ../Tuples_lib/Tuple.cpp ../Tuples_lib/Point.cpp ../Tuples_lib/Vector.cpp ../Tuples_lib/Color.cpp)

add_library(Tuples_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

set(HEADER_FILES ../Canvas_lib/Canvas.h)
set(SOURCE_FILES ../Canvas_lib/Canvas.cpp ../Sphere_lib/Sphere.cpp ../Sphere_lib/Sphere.h)

add_library(Canvas_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

set(HEADER_FILES ../Matrix_lib/Matrix.h ../Matrix_lib/Transform.h)
set(SOURCE_FILES ../Matrix_lib/Matrix.cpp ../Matrix_lib/Transform.cpp)

add_library(Matrix_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

set(HEADER_FILES ../Ray_lib/Ray.h)
set(SOURCE_FILES ../Ray_lib/Ray.cpp)

add_library(Ray_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

set(HEADER_FILES ../Sphere_lib/Sphere.h)
set(SOURCE_FILES ../Sphere_lib/Sphere.cpp)

add_library(Sphere_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

# adding the Google_Tests_run target
add_executable(Google_Tests_run TupleTest.cpp CanvasTest.cpp MatrixTest.cpp RayTest.cpp RayTest.cpp)

# linking Google_Tests_run with libs which will be tested
target_link_libraries(Google_Tests_run Tuples_lib Canvas_lib Matrix_lib Ray_lib)

target_link_libraries(Google_Tests_run gtest gtest_main)