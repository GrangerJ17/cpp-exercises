#include <memory>

int main() {
  std::unique_ptr<int> n = std::make_unique<int>(7);

  
  std::unique_ptr<int> k = n;

  return 0;
  
}
