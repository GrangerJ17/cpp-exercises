#include "spinlocks.hpp"
#include <unistd.h>
#include <algorithm>
#include <thread>

void spinlock_TAS::lock()
{

    while(m_spin.load(std::memory_order_relaxed)) {
      __builtin_ia32_pause();
    }
}

void spinlock_TAS::unlock()
{
    m_spin.store(0, std::memory_order_release);
}

void spinlock_TTAS::lock()
{
  for (;;) {
    if (!m_spin.exchange(true, std::memory_order_acquire)) {
      return;
    }


    while(m_spin.load(std::memory_order_relaxed)) {
      __builtin_ia32_pause();
    }
  }
}

void spinlock_TTAS::unlock()
{
    m_spin.store(0, std::memory_order_release);
}

void ticket_lock::lock()
{
    const size_t ticket = next_ticket.fetch_add(1, std::memory_order_relaxed);
    size_t spins = 0;
    while (ticket != now_serving.load(std::memory_order_acquire))
    {
        if (++spins < 1000) {
            __builtin_ia32_pause();
        } else {
            spins = 0;
            sched_yield();
        }
    }
}

void ticket_lock::unlock()
{
    now_serving.fetch_add(1, std::memory_order_release);
}
