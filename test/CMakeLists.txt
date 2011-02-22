enable_testing()
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(MOCKS_DIR "${CMAKE_SOURCE_DIR}/test/mocks")

find_package(GTest REQUIRED)
find_package(GMock REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GOOGLEMOCK_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${MOCKS_DIR})

add_subdirectory(${MOCKS_DIR})

link_directories(${CMAKE_SOURCE_DIR}/src)
link_directories(${MOCKS_DIR})
link_libraries(ddsbasic ddsbasicmocks)

add_executable(repltest.exe repltest.cpp)
target_link_libraries(repltest.exe ${GTEST_BOTH_LIBRARIES} ${GOOGLEMOCK_LIBRARIES} pthread)

add_executable(interpretertest.exe interpretertest.cpp)
target_link_libraries(interpretertest.exe ${GTEST_BOTH_LIBRARIES} ${GOOGLEMOCK_LIBRARIES} pthread)

add_test(REPLTests repltest.exe)
add_test(InterpreterTests interpretertest.exe)
