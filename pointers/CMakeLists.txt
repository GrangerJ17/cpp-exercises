 cmake_minimum_required(VERSION 3.20)
project(smartpointers CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_smartpointers test_smartpointers.cpp)
target_include_directories(test_smartpointers PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test_smartpointers PRIVATE GTest::gtest_main)
target_compile_options(test_smartpointers PRIVATE -Wall -Wextra)

# build with -DSANITIZE=ON to run under ASan/UBSan (catches double-free, leaks)
option(SANITIZE "Enable address and UB sanitizers" OFF)
if(SANITIZE)
  target_compile_options(test_smartpointers PRIVATE -fsanitize=address,undefined -g)
  target_link_options(test_smartpointers PRIVATE -fsanitize=address,undefined)
endif()

include(GoogleTest)
gtest_discover_tests(test_smartpointers)
