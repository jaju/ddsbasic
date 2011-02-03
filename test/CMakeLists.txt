enable_testing()
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules/")
find_package(GTest REQUIRED)
find_package(GMock REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GOOGLEMOCK_INCLUDE_DIR})

add_executable(setuptest setuptest.cpp)
target_link_libraries(setuptest ${GTEST_BOTH_LIBRARIES} ${GOOGLEMOCK_LIBRARIES} pthread)

add_test(SetupTests setuptest)
