#include "thread_safe_queue.h"
#include <gtest/gtest.h>
#include <algorithm>
#include <functional>
#include <numeric>
#include <stop_token>
#include <thread>
#include <vector>
#include <chrono>
#include <atomic>
#include <condition_variable>

std::atomic<int> count{0}; 
std::mutex m;
  std::condition_variable cv;
  std::atomic<bool> done {false};  

template<typename T>
void consumeData(tsQueue<T>& q) {

  while(!q.empty() || !q.complete()) {
    T val;
    q.waitPop(val);
    std::cerr << val << std::endl;
    count.fetch_add(val, std::memory_order_acquire);
  }
}

template<typename T>  
void produceData(tsQueue<T>& q, int loc, int size, std::vector<T>& data) { 
    while(loc < size) {
      const T& val = data[loc];
      q.push(val);
      ++loc;
    }

    q.shutdown();
}


TEST(TryPop, CorrectFalse) {
  tsQueue<int> q;

  int i = 0;
  EXPECT_EQ(q.tryPop(i), false);
}

TEST(TryPop, CorrectNull) {
  tsQueue<int> q;


  ASSERT_EQ(q.tryPop(), nullptr);
}

TEST(MultiThreaded, OnePOneC) {
  count.store(0, std::memory_order_relaxed);

  int num = 10;
  

  tsQueue<int> q;
  std::vector<int> data(num, 0);
  std::iota(data.begin(), data.end(), 1);

  int desired = 0;
  for(int n : data) desired += n;

 
  
  std::jthread c([&]() {
    consumeData(q);
    done.store(true, std::memory_order_relaxed);
    cv.notify_all();
  });   

  std::jthread p([&]() {
      produceData(q, 0, num, data);
  });

  std::unique_lock<std::mutex> lk(m);
  cv.wait(lk, [&]() { return done.load(std::memory_order_relaxed); });

 ASSERT_EQ(count.load(std::memory_order_relaxed), desired);

}

TEST(MultiThreaded, OnePManyC) {
  count.store(0, std::memory_order_relaxed);

  int num = 10;
  

  tsQueue<int> q;
  std::vector<int> data(num, 0);
  std::iota(data.begin(), data.end(), 1);

  int desired = 0;
  for(int n : data) desired += n;

 
  int threadCount = std::thread::hardware_concurrency();

  std::vector<std::jthread> threadPool;

  for(int i = 0; i < threadCount; i++) {
    threadPool.emplace_back(([&]() {
      consumeData(q);
      std::cerr << "Consume\n";
      done.store(true, std::memory_order_relaxed);
      cv.notify_all();
    }));

  }


  std::jthread p([&]() {

      produceData(q, 0, num, data);
  });


  std::unique_lock<std::mutex> lk(m);
  cv.wait(lk, [&]() { return done.load(std::memory_order_relaxed); });

  
  int trueCount = count.load(std::memory_order_relaxed);

  std::cout << "T: " << trueCount << std::endl;

 ASSERT_EQ(trueCount, desired);

}
