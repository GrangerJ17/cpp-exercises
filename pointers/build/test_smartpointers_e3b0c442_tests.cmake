add_test([=[UniquePtrTest.DefaultIsEmpty]=]  [==[/home/james/C++Exercises/pointers/build/test_smartpointers]==] [==[--gtest_filter=UniquePtrTest.DefaultIsEmpty]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[UniquePtrTest.DefaultIsEmpty]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/pointers/test_smartpointers.cpp:36]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/pointers/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[UniquePtrTest.TakesOwnership]=]  [==[/home/james/C++Exercises/pointers/build/test_smartpointers]==] [==[--gtest_filter=UniquePtrTest.TakesOwnership]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[UniquePtrTest.TakesOwnership]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/pointers/test_smartpointers.cpp:41]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/pointers/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[UniquePtrTest.DestroyingEmptyIsSafe]=]  [==[/home/james/C++Exercises/pointers/build/test_smartpointers]==] [==[--gtest_filter=UniquePtrTest.DestroyingEmptyIsSafe]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[UniquePtrTest.DestroyingEmptyIsSafe]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/pointers/test_smartpointers.cpp:50]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/pointers/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[UniquePtrTest.ReleaseYieldsPointerAndClears]=]  [==[/home/james/C++Exercises/pointers/build/test_smartpointers]==] [==[--gtest_filter=UniquePtrTest.ReleaseYieldsPointerAndClears]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[UniquePtrTest.ReleaseYieldsPointerAndClears]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/pointers/test_smartpointers.cpp:57]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/pointers/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[UniquePtrTest.ResetDeletesOld]=]  [==[/home/james/C++Exercises/pointers/build/test_smartpointers]==] [==[--gtest_filter=UniquePtrTest.ResetDeletesOld]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[UniquePtrTest.ResetDeletesOld]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/pointers/test_smartpointers.cpp:66]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/pointers/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[UniquePtrTest.ResetToNullFreesOld]=]  [==[/home/james/C++Exercises/pointers/build/test_smartpointers]==] [==[--gtest_filter=UniquePtrTest.ResetToNullFreesOld]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[UniquePtrTest.ResetToNullFreesOld]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/pointers/test_smartpointers.cpp:74]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/pointers/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[UniquePtrTest.DefaultResetAllocatesNothing]=]  [==[/home/james/C++Exercises/pointers/build/test_smartpointers]==] [==[--gtest_filter=UniquePtrTest.DefaultResetAllocatesNothing]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[UniquePtrTest.DefaultResetAllocatesNothing]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/pointers/test_smartpointers.cpp:82]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/pointers/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[UniquePtrTest.ResetOnEmptyIsSafe]=]  [==[/home/james/C++Exercises/pointers/build/test_smartpointers]==] [==[--gtest_filter=UniquePtrTest.ResetOnEmptyIsSafe]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[UniquePtrTest.ResetOnEmptyIsSafe]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/pointers/test_smartpointers.cpp:89]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/pointers/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[UniquePtrTest.MoveConstructTransfers]=]  [==[/home/james/C++Exercises/pointers/build/test_smartpointers]==] [==[--gtest_filter=UniquePtrTest.MoveConstructTransfers]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[UniquePtrTest.MoveConstructTransfers]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/pointers/test_smartpointers.cpp:98]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/pointers/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[UniquePtrTest.MoveAssignTransfersAndFreesTarget]=]  [==[/home/james/C++Exercises/pointers/build/test_smartpointers]==] [==[--gtest_filter=UniquePtrTest.MoveAssignTransfersAndFreesTarget]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[UniquePtrTest.MoveAssignTransfersAndFreesTarget]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/pointers/test_smartpointers.cpp:107]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/pointers/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[UniquePtrTest.SelfMoveAssignDoesNotDestroy]=]  [==[/home/james/C++Exercises/pointers/build/test_smartpointers]==] [==[--gtest_filter=UniquePtrTest.SelfMoveAssignDoesNotDestroy]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[UniquePtrTest.SelfMoveAssignDoesNotDestroy]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/pointers/test_smartpointers.cpp:118]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/pointers/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[UniquePtrTest.MoveAssignFromEmpty]=]  [==[/home/james/C++Exercises/pointers/build/test_smartpointers]==] [==[--gtest_filter=UniquePtrTest.MoveAssignFromEmpty]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[UniquePtrTest.MoveAssignFromEmpty]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/pointers/test_smartpointers.cpp:126]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/pointers/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[UniquePtrTest.SwapExchangesOwnership]=]  [==[/home/james/C++Exercises/pointers/build/test_smartpointers]==] [==[--gtest_filter=UniquePtrTest.SwapExchangesOwnership]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[UniquePtrTest.SwapExchangesOwnership]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/pointers/test_smartpointers.cpp:136]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/pointers/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[UniquePtrTest.MakeUniqueForwardsArgs]=]  [==[/home/james/C++Exercises/pointers/build/test_smartpointers]==] [==[--gtest_filter=UniquePtrTest.MakeUniqueForwardsArgs]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[UniquePtrTest.MakeUniqueForwardsArgs]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/pointers/test_smartpointers.cpp:152]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/pointers/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[UniquePtrTest.MakeUniqueMovesRvalue]=]  [==[/home/james/C++Exercises/pointers/build/test_smartpointers]==] [==[--gtest_filter=UniquePtrTest.MakeUniqueMovesRvalue]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[UniquePtrTest.MakeUniqueMovesRvalue]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/home/james/C++Exercises/pointers/test_smartpointers.cpp:159]==]
    WORKING_DIRECTORY [==[/home/james/C++Exercises/pointers/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(test_smartpointers_TESTS [==[UniquePtrTest.DefaultIsEmpty]==] [==[UniquePtrTest.TakesOwnership]==] [==[UniquePtrTest.DestroyingEmptyIsSafe]==] [==[UniquePtrTest.ReleaseYieldsPointerAndClears]==] [==[UniquePtrTest.ResetDeletesOld]==] [==[UniquePtrTest.ResetToNullFreesOld]==] [==[UniquePtrTest.DefaultResetAllocatesNothing]==] [==[UniquePtrTest.ResetOnEmptyIsSafe]==] [==[UniquePtrTest.MoveConstructTransfers]==] [==[UniquePtrTest.MoveAssignTransfersAndFreesTarget]==] [==[UniquePtrTest.SelfMoveAssignDoesNotDestroy]==] [==[UniquePtrTest.MoveAssignFromEmpty]==] [==[UniquePtrTest.SwapExchangesOwnership]==] [==[UniquePtrTest.MakeUniqueForwardsArgs]==] [==[UniquePtrTest.MakeUniqueMovesRvalue]==])
