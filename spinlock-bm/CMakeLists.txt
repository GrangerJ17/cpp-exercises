cmake_minimum_required(VERSION 4.0)

project(benchSpinlock LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
  googlebenchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG v1.9.1
)

 FetchContent_MakeAvailable(googlebenchmark)

 add_executable(SLbenchmark benchLocks.cpp spinlocks.cpp)


target_link_libraries(SLbenchmark PRIVATE
  benchmark::benchmark
  benchmark::benchmark_main
)























