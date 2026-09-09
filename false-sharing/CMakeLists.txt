 cmake_minimum_required(VERSION 3.20)

project(fsBenchmark LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.9.4
)

# Prevent Google Benchmark from building its own tests and examples.
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(benchmark)

add_executable(my_benchmark
    false-sharing-bm.cpp
)

target_link_libraries(my_benchmark
    PRIVATE
        benchmark::benchmark
        benchmark::benchmark_main
)

