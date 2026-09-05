add_test([=[TryPop.CorrectFalse]=]  [==[/home/james/C++Exercises/CIA/ch4/build/TestChapter4]==] [==[--gtest_filter=TryPop.CorrectFalse]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TryPop.CorrectFalse]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/CIA/ch4/test.cpp:41]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/CIA/ch4/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[TryPop.CorrectNull]=]  [==[/home/james/C++Exercises/CIA/ch4/build/TestChapter4]==] [==[--gtest_filter=TryPop.CorrectNull]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TryPop.CorrectNull]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/CIA/ch4/test.cpp:48]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/CIA/ch4/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[MultiThreaded.OnePOneC]=]  [==[/home/james/C++Exercises/CIA/ch4/build/TestChapter4]==] [==[--gtest_filter=MultiThreaded.OnePOneC]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[MultiThreaded.OnePOneC]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/CIA/ch4/test.cpp:55]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/CIA/ch4/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[MultiThreaded.OnePManyC]=]  [==[/home/james/C++Exercises/CIA/ch4/build/TestChapter4]==] [==[--gtest_filter=MultiThreaded.OnePManyC]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[MultiThreaded.OnePManyC]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/CIA/ch4/test.cpp:87]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/CIA/ch4/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(TestChapter4_TESTS [==[TryPop.CorrectFalse]==] [==[TryPop.CorrectNull]==] [==[MultiThreaded.OnePOneC]==] [==[MultiThreaded.OnePManyC]==])
