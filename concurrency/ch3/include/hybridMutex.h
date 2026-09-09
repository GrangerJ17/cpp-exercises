#include <atomic>
#include <iostream>
#include <thread>

class HybridMutex {
  public:
    explicit HybridMutex(uint32_t spin_count = 4000) :
      spin_count_m(spin_count) {}


    void lock() {
       

        uint32_t count = 0;
        while(locked.test_and_set(std::memory_order_acquire)) {

          if(++count >= spin_count_m) { 
            count = 0;
            locked.wait(true);
          }
        }
      
    }

    bool try_lock() {

      return !locked.test_and_set(std::memory_order_acquire);
    }

    void unlock() {
      locked.clear(); 
    }
  private:
    std::atomic_flag locked; 
    uint32_t spin_count_m;
};























































