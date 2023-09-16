
#include <iostream>
#include <string>
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
    std::string varName = std::to_string(pushv[1]); // TODO: actually loop through this

    // get value
    std::string setvi32;

    if (!reader->done()) {
      // reader->currentIdx++;
      setvi32 = reader->nextInstr();
    }

    if (setvi32.length() > 0 && setvi32[0] == '\x6a') {
      std::string val = std::to_string(setvi32[2]); // HACK: HARDCODED!
      int intVal = std::stoi(val);
      writer->movl(X86Register::EAX, intVal);
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
