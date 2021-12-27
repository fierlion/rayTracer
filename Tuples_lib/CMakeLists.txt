project(Tuples_lib)

set(HEADER_FILES Tuple.h Point.h Vector.h)

set(SOURCE_FILES Tuple.cpp Point.cpp Vector.cpp)

add_library(Tuples_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})