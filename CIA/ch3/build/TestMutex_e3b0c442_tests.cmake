add_test([=[Interface.isLockable]=]  [==[/home/james/C++Exercises/CIA/ch3/build/TestMutex]==] [==[--gtest_filter=Interface.isLockable]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Interface.isLockable]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/CIA/ch3/testMutex.cpp:8]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/CIA/ch3/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[Interface.worksWithUniqueLock]=]  [==[/home/james/C++Exercises/CIA/ch3/build/TestMutex]==] [==[--gtest_filter=Interface.worksWithUniqueLock]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Interface.worksWithUniqueLock]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/CIA/ch3/testMutex.cpp:26]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/CIA/ch3/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[Logic.atomicCounter]=]  [==[/home/james/C++Exercises/CIA/ch3/build/TestMutex]==] [==[--gtest_filter=Logic.atomicCounter]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Logic.atomicCounter]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/CIA/ch3/testMutex.cpp:39]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/CIA/ch3/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(TestMutex_TESTS [==[Interface.isLockable]==] [==[Interface.worksWithUniqueLock]==] [==[Logic.atomicCounter]==])
