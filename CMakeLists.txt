cmake_minimum_required(VERSION 2.8)
project(ddsbasic C CXX)
include(CheckIncludeFiles)
include(CheckFunctionExists)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)
configure_file(${SRC_DIR}/config.h.in
  ${SRC_DIR}/config.h)

add_subdirectory(src)
add_subdirectory(test)
