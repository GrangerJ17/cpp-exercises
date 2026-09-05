#include <iostream>
#include <cassert>
#include <atomic>
#include <vector>

int main()  {
    int carr[3] = {1, 2, 4};     

    std::atomic<int*> p(carr);

    std::cout << *p.load() << std::endl;

    int* x = p.fetch_add(2);

    assert(x == carr);
    assert(p.load()==&carr[2]);
    std::cout << *x << std::endl;
    std::cout << *p.load() << std::endl;

    x=(p-=1);
    std::cout << *x << std::endl;
    assert(x==&carr[1]);
    assert(p.load()==&carr[1]);
    assert(*x==carr[1]);

    return 0;

}
