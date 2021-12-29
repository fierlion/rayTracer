project(RayTracer)
cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 14)

add_executable(RayTracer_run main.cpp)
set(HEADER_FILES Tuples_lib/Tuple.h Tuples_lib/Point.h Tuples_lib/Vector.h Tuples_lib/Color.h)
set(SOURCE_FILES Tuples_lib/Tuple.cpp Tuples_lib/Point.cpp Tuples_lib/Vector.cpp Tuples_lib/Color.cpp)

add_library(Tuples_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(RayTracer_run PUBLIC "${PROJECT_SOURCE_DIR}/Tuple_lib")
target_link_libraries(RayTracer_run Tuples_lib)
