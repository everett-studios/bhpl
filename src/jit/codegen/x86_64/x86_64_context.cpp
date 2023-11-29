
#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <iomanip>

#include "../../../include/utils.hpp"
#include "include/x86_64_context.hpp"

namespace Codegen {

void X86Context::variable() {
  std::string pushv;
  
  if (!reader->done()) {
    pushv = reader->nextInstr();
  }

  if (pushv != "" && pushv[0] == '\x6b') {
    // get name
    std::string varName = ""; // TODO: actually loop through this
    int varIdx = 1;

    while (varIdx < varName.length() - 1 && varName[varIdx] != '\x01') {
      varName += std::to_string(varName[varIdx]);
      varIdx++;
    }

    // get value
    std::string setvi32;

    if (!reader->done()) {
      setvi32 = reader->nextInstr();
    }

    if (setvi32.length() > 0 && setvi32[0] == '\x6a') {
      std::vector<int> val = {};
      int idx = 2;

      while (idx < setvi32.length() - 1 && setvi32[idx] != '\x01') {
        val.push_back(setvi32[idx]);
        idx++;
      }

      writer->movl(X86Register::EAX, val[0]);
    }
  }
}

X86Context::X86Context(int *bytecode) {
  reader = new JIT::Reader(bytecode);
  writer = new X86Writer();

  variable();
  writer->exitProg();
}

char *X86Context::emit() {
  char *bytes = writer->getBuffer();
  return bytes;
}

} // Codegen
