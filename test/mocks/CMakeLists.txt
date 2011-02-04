set(LIB_NAME ddsbasicmocks)
set(LIB_SRCS interpretermock.cpp)
option(DEBUG "Build the project with debug tracing on" ON)

add_library(${LIB_NAME} SHARED ${LIB_SRCS})
