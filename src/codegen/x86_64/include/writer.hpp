
#pragma once

#include <string>
#include "register.hpp"

namespace Codegen {
  class X86Writer {
  private:
    char *buffer;
    int bufIdx;
    void i32ToHex(uint32_t val);
  public:
    X86Writer();

    void movl(X86Register reg, uint32_t val);
    void exitProg();

    char *getBuffer();
  };
}
