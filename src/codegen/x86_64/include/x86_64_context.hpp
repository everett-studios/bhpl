
#pragma once

#include <string>
#include "../../../front/include/parser.hpp"
#include "writer.hpp"

namespace Codegen {

class X86Context {
private:
  X86Writer *writer;
  Frontend::Node ast;
  Frontend::Node currentNode;

  void variable();
public:
  X86Context(Frontend::Node ast);
  char *emit();
};

} // Codegen
