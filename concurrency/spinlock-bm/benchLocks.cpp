#include "spinlocks.hpp"
#include <mutex>
#include <benchmark/benchmark.h>
#include <thread>
#include <vector>

template <typename Lock>
static void BM_Lock(benchmark::State& state) {

    static Lock lock;
    static long long counter;
    if (state.thread_index() == 0) counter = 0;

    const int criticalWork = state.range(0);

    for (auto _ : state) {
        lock.lock();
        for (int i = 0; i < criticalWork; ++i) {
          benchmark::DoNotOptimize(++counter);
        }
        lock.unlock();
    }
    state.SetItemsProcessed(state.iterations());

}

BENCHMARK(BM_Lock<spinlock_TAS>)->Arg(1)->Arg(50)->Arg(500)->ThreadRange(1, 16)->UseRealTime();
BENCHMARK(BM_Lock<ticket_lock>)->Arg(1)->Arg(50)->Arg(500)->ThreadRange(1, 16)->UseRealTime();
BENCHMARK(BM_Lock<std::mutex>)->Arg(1)->Arg(50)->Arg(500)->ThreadRange(1, 16)->UseRealTime();
BENCHMARK(BM_Lock<spinlock_TTAS>)->Arg(1)->Arg(50)->Arg(500)->ThreadRange(1, 16)->UseRealTime();


