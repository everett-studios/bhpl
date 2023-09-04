
#pragma once

#include <string>
#include "../../../bytecode/include/reader.hpp"
#include "writer.hpp"

namespace Codegen {

class X86Context {
private:
  X86Writer *writer;
  JIT::Reader *reader;

  void variable();
public:
  X86Context(std::string bytecode);
  char *emit();
};

} // Codegen
