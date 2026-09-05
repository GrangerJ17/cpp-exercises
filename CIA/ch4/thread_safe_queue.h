#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>


template <typename T> 
class tsQueue {
  public:

    // Boilerplate
    tsQueue() = default;
    tsQueue(const tsQueue& old) {
      
      std::lock_guard<std::mutex> lk(m_);
      data_ = old.data_;

    }

    tsQueue& operator =(const tsQueue&) = delete;

    // To implement
    void push(T newVal) {
      std::lock_guard<std::mutex> lk(m_);
      data_.push(newVal);
      cv_.notify_one();
    }

    bool tryPop(T& val) {
      std::lock_guard<std::mutex> lk(m_);
      if(data_.empty()) return false;

      val = data_.front();
      data_.pop();

      return true;
    }
    std::shared_ptr<T> tryPop() {
      std::lock_guard<std::mutex> lk(m_);
      if(data_.empty()) return nullptr;
      std::shared_ptr<T> val(std::make_shared<T>(data_.front()));
      data_.pop();
      return val;
    }

    void waitPop(T& val) {
      std::unique_lock<std::mutex> lk(m_);
      cv_.wait(lk, [&] {return !data_.empty() || done; });
      if(!data_.empty()) {
        val = data_.front();
        data_.pop();
      }

    }
    std::shared_ptr<T> waitPop() {
      std::unique_lock<std::mutex> lk(m_);
      cv_.wait(lk, [&] {return !data_.empty() || done; });

      std::shared_ptr<T> val(std::make_shared<T>(data_.front()));
      data_.pop();
      return val;
    }     
    bool empty() {
      std::lock_guard<std::mutex> lk(m_);
      return data_.empty();
    }

    void shutdown()  {
      std::lock_guard<std::mutex> lk(m_);
      done = true;
      cv_.notify_all();
    }


    bool complete()  {
      std::lock_guard<std::mutex> lk(m_);
      return done;
    }

  private:
    mutable std::mutex m_;
    std::queue<T> data_;
    std::condition_variable cv_;
    bool done = false;

};


