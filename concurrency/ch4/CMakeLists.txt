cmake_minimum_required(VERSION 3.23)

project(concurrency4 LANGUAGES CXX)
set(CMAKE_CXX_FLAGS "-Wall -g -fsanitize=thread")
 set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_library(threadSafeQueue INTERFACE)

target_sources(threadSafeQueue
  INTERFACE
    thread_safe_queue.h
)

add_executable(TestChapter4 test.cpp)
target_link_libraries(TestChapter4
  PRIVATE
    GTest::gtest
    GTest::gtest_main
)


include(GoogleTest)
gtest_discover_tests(TestChapter4)
