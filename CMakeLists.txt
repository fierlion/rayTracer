project(RayTracer)
cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 14)

add_executable(RayTracer_run main.cpp Matrix_lib/Matrix.cpp Matrix_lib/Matrix.h)