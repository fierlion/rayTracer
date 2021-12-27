cmake_minimum_required(VERSION 3.14)
project(testing_test)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
#add_executable(DateConverter_run ${SOURCE_FILES})

include_directories(Tuples_lib)
add_subdirectory(Tuples_lib)
add_subdirectory(Google_tests)

target_link_libraries(Tuples_lib)

