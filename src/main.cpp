
#include <iostream>
#include <string>

#include "include/utils.hpp"

int main(int argc, char *argv[]) {
  std::string src = Utilities::readSrc("examples/add.bhpl");
  std::cout << src << std::endl;

  return 0;
}
