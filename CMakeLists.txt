cmake_minimum_required(VERSION 3.0)

project(StupidMistakes)

set(CMAKE_CXX_STANDARD 11)


#include_directories("${gtest_SOURCE_DIR}/include")
#link_directories("${CMAKE_BINARY_DIR}/googletest-build/googlemock/gtest")
add_subdirectory (src)
