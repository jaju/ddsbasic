enable_testing()
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules/")
find_package(GTest REQUIRED)
find_package(GMock REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GOOGLEMOCK_INCLUDE_DIR})
include_directories (${CMAKE_SOURCE_DIR}/src)

link_directories(${CMAKE_SOURCE_DIR}/src)
link_libraries(ddsbasic)

add_executable(repltest.exe repltest.cpp)
target_link_libraries(repltest.exe ${GTEST_BOTH_LIBRARIES} ${GOOGLEMOCK_LIBRARIES} pthread)

add_executable(interpretertest.exe interpretertest.cpp)
target_link_libraries(interpretertest.exe ${GTEST_BOTH_LIBRARIES} ${GOOGLEMOCK_LIBRARIES} pthread)

add_test(REPLTests repltest)
add_test(InterpreterTests interpretertest)
