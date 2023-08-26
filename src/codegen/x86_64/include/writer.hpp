
#pragma once

#include <string>
#include "register.hpp"

namespace Codegen {
  class X86Writer {
  private:
    std::string buffer;
    std::string i32ToHex(uint32_t val);
  public:
    X86Writer();

    void movl(X86Register reg, uint32_t val);

    std::string getBuffer();
  };
}
