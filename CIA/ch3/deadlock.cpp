/*code, three specific things. Deliberately deadlock two mutexes with opposed lock order, then fix it with std::scoped_lock; write the "returns a reference/pointer to the protected data" bug and watch the mutex become decorative; implement broken double-checked locking and compare against std::call_once. Each is a five-minute program and each is a failure you cannot see by reading — that's the whole selection criterion.*/

#include <mutex>
#include <iostream>
#include <thread>

std::mutex m1; 
std::mutex m2;

void activity1()  {
  std::scoped_lock guard(m2, m1);
  

  std::cout << "Activity 1" << std::endl;

}

void activity2()  {
  
  std::scoped_lock guard(m1, m2);


  std::cout << "Activity 2" << std::endl;


}


int main(int argc, char* argv[]) {

  std::jthread t1(&activity1);
  std::jthread t2(&activity2);

  return 0;

}
