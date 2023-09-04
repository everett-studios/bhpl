
#include <iostream>
#include <string>

#include "include/reader.hpp"
#include "../../include/utils.hpp"

namespace JIT {

Reader::Reader(std::string bytecode) {
  this->bytecode = bytecode;
  currentIdx = 0;
}

std::string Reader::nextInstr() {
  std::string instr;

  while (currentIdx < bytecode.length() - 1 && bytecode[currentIdx] != '\x01') {
    instr += bytecode[currentIdx];
    currentIdx++;
  }

  instr += bytecode[currentIdx];
  currentIdx++;

  return instr;
}

bool Reader::done() {
  return currentIdx == bytecode.length() - 1;
}

} // JIT
