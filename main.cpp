#include <iostream>

#include "lib.h"

int main() {
  std::cout << "HELLO OTUS!!!" << std::endl;
  std::cout << "From library: " << my_library::version() << std::endl;
  return 0;
}
