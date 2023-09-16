
#include <iostream>
#include <string>

#include "include/reader.hpp"
#include "../../include/utils.hpp"

namespace JIT {

Reader::Reader(int *bytecode) {
  this->bytecode = bytecode;
  currentIdx = 0;
}

std::string Reader::nextInstr() {
  std::string instr;
  int bytecodeLen = sizeof(bytecode)/sizeof(bytecode[0]);

  while (bytecode[currentIdx] != '\x01') {
    instr += bytecode[currentIdx];
    currentIdx++;
  }

  instr += bytecode[currentIdx];
  currentIdx++;

  return instr;
}

bool Reader::done() {
  return currentIdx == sizeof(bytecode)/sizeof(bytecode[0]) - 1;
}

} // JIT
