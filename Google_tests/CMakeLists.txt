cmake_minimum_required(VERSION 3.20)
project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(HEADER_FILES ../Tuples_lib/Tuple.h ../Tuples_lib/Point.h ../Tuples_lib/Vector.h ../Tuples_lib/Color.h )
set(SOURCE_FILES ../Tuples_lib/Tuple.cpp ../Tuples_lib/Point.cpp ../Tuples_lib/Vector.cpp ../Tuples_lib/Color.cpp)

add_library(Tuples_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

set(HEADER_FILES ../Canvas/Canvas.h)
set(SOURCE_FILES ../Canvas/Canvas.cpp ../Light/Light.cpp ../Light/Light.h)

add_library(Canvas STATIC ${SOURCE_FILES} ${HEADER_FILES})

set(HEADER_FILES ../Matrix/Matrix.h ../Matrix/Transform.h)
set(SOURCE_FILES ../Matrix/Matrix.cpp ../Matrix/Transform.cpp)

add_library(Matrix STATIC ${SOURCE_FILES} ${HEADER_FILES})

set(HEADER_FILES ../Ray/Ray.h)
set(SOURCE_FILES ../Ray/Ray.cpp)

add_library(Ray STATIC ${SOURCE_FILES} ${HEADER_FILES})

set(HEADER_FILES ../Shape_lib/Shape.h ../Shape_lib/Sphere.h)
set(SOURCE_FILES ../Shape_lib/Shape.cpp ../Shape_lib/Sphere.cpp)

add_library(Shape_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

set(HEADER_FILES ../Intersection/Intersection.h)
set(SOURCE_FILES ../Intersection/Intersection.cpp)

add_library(Intersection STATIC ${SOURCE_FILES} ${HEADER_FILES})

set(HEADER_FILES ../Light/Light.h)
set(SOURCE_FILES ../Light/Light.cpp)

add_library(Light STATIC ${SOURCE_FILES} ${HEADER_FILES})

set(HEADER_FILES ../Material_lib/Material.h)
set(SOURCE_FILES ../Material_lib/Material.cpp)

add_library(Material_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

# adding the Google_Tests_run target
add_executable(Google_Tests_run TupleTest.cpp CanvasTest.cpp MatrixTest.cpp RayTest.cpp ShapeTest.cpp IntersectionTest.cpp LightTest.cpp MaterialTest.cpp)

# linking Google_Tests_run with libs which will be tested
target_link_libraries(Google_Tests_run Tuples_lib Canvas Matrix Ray Shape_lib Intersection Light Material_lib)

target_link_libraries(Google_Tests_run gtest gtest_main)