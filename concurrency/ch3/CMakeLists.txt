cmake_minimum_required(VERSION 4.0)
project(chapter3 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-Wall -g -fsanitize=thread")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_library(hybridMutex INTERFACE)

target_sources(hybridMutex 
  INTERFACE
  hybridMutex.h
)

add_executable(TestMutex testMutex.cpp)

target_link_libraries(TestMutex
  PRIVATE
  GTest::gtest
  GTest::gtest_main
)

target_include_directories(TestMutex 
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/include

)

include(GoogleTest)
gtest_discover_tests(TestMutex)

























