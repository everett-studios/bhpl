
#pragma once

#include <string>
#include "../../../front/include/parser.hpp"

namespace Codegen {

class X86Context {
private:
  std::string bytes;
  Frontend::Node ast;
  Frontend::Node currentNode;

  void variable();
public:
  X86Context(Frontend::Node ast);
  std::string emit();
};

} // Codegen
