
#include <iostream>
#include <string>

#include "include/x86_64_context.hpp"

namespace Codegen {

void X86Context::variable() {
  if (currentNode.name == "$P_VAR_VAL") {
    if (currentNode.tknChildren[0].name == "=") {
      std::cout << "??" << std::endl;
    }
  }
}

X86Context::X86Context(Frontend::Node ast) {
  this->ast = ast;
  currentNode = ast;

  variable();
}

std::string X86Context::emit() {
  return bytes;
}

} // Codegen
