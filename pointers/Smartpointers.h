#include <iostream>
#include <type_traits>
#include <utility>

 // Basic unique pointer implemented without custom deleters ie will not work with things that need to call more than delete (eg files)

template<typename T>
class uniquePtr {
  public:
    explicit uniquePtr(T* newData = nullptr) : data(newData) {}

    uniquePtr& operator=(const uniquePtr& ptr) = delete;
    uniquePtr(const uniquePtr
& ptr) = delete;


    ~uniquePtr() {
      delete data;
    }

    uniquePtr(uniquePtr&& ptr) noexcept 
    : data(ptr.release()) {}


    T* release() noexcept {
      T* temp = data;
      data = nullptr;

      return temp;

    }

    uniquePtr& reset( T* ptr = nullptr ) noexcept {

      T* oldPtr = data;
      data = ptr;

      if(oldPtr) delete oldPtr;

      return *this;
    }

    void swap(uniquePtr& otherPtr) noexcept {
      std::swap(data, otherPtr.data);
    }

    uniquePtr& operator=(uniquePtr&& oldPtr) {

        return reset(oldPtr.release());
      
    }


    T* get() {
      return data;
    }

    T& operator*() {
      return *data;
    }

    T* operator->() {
      return data;
    }

    explicit operator bool() {
      if(data) return true;
      else false;
    }

  private:
    T* data;


};


template<typename T, typename... Args>
uniquePtr<T> makeUnique(Args&&... args) {
      return uniquePtr (new T(std::forward<Args&&>(args)...));
    }
