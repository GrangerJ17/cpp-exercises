#include <hybridMutex.h>
#include <gtest/gtest.h>
#include <atomic>
#include <thread>
#include <mutex>
#include <vector>

 TEST(Interface, isLockable) {
  HybridMutex hm;

  // BasicLockable: works with lock_guard
  { std::lock_guard<HybridMutex> lg(hm); }

  // Lockable: try_lock succeeds when free
  ASSERT_TRUE(hm.try_lock());
  hm.unlock();

  // try_lock fails when held by another thread
  std::lock_guard<HybridMutex> lg(hm);
  std::atomic<bool> acquired{true};
  std::jthread t([&] { acquired = hm.try_lock(); });
  t.join();
  EXPECT_FALSE(acquired);
}

TEST(Interface, worksWithUniqueLock) {
  HybridMutex hm;
  std::unique_lock<HybridMutex> ul(hm);
  EXPECT_TRUE(ul.owns_lock());
  ul.unlock();
  EXPECT_FALSE(ul.owns_lock());
  ul.lock();
  EXPECT_TRUE(ul.owns_lock());
}

static_assert(!std::is_copy_constructible_v<HybridMutex>);
static_assert(!std::is_move_constructible_v<HybridMutex>);

TEST(Logic, atomicCounter) {

  int nThread = 5;
  int mInc = 100;
  HybridMutex hm;
  std::vector<std::jthread> threads;

  std::atomic<int> csCounter{0};
  int count = 0;
  std::function<void()> counterFunc = [&]() {

    hm.lock();
    EXPECT_TRUE(csCounter.fetch_add(1, std::memory_order_relaxed) == 0);
    for(int j = 0; j < mInc; ++j) {
      ++count;
    }


    EXPECT_TRUE(csCounter.fetch_sub(1, std::memory_order_relaxed) == 1);
    hm.unlock();
  };


  for(int i = 0; i < nThread; i++) {
    threads.emplace_back([&]() {
      counterFunc();
    });
  }


  threads.clear();

  EXPECT_EQ(count, nThread*mInc);
                      
}

