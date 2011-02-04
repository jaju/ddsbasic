set(LIB_NAME ddsbasic)
set(LIB_SRCS repl.cpp interpreter.cpp)
option(DEBUG "Build the project with debug tracing on" ON)

add_library(${LIB_NAME} SHARED ${LIB_SRCS})
