
#include <iostream>
#include <string>

#include "../../include/utils.hpp"
#include "include/x86_64_context.hpp"

namespace Codegen {

void X86Context::variable() {
  if (currentNode.name == "=") {
    if (currentNode.tknChildren[0].name == "$PT_TYPE") {
      // integer type
      if (currentNode.tknChildren[0].value == "int") {
        // get name
        std::string varName = currentNode.tknChildren[1].value;

        // get value
        if (currentNode.children[0].name == "$P_VAR_VAL") {
          std::string val = currentNode.children[0].tknChildren[0].value;
          int intVal = std::stoi(val);
          writer->movl(X86Register::EAX, intVal);
        }
      }
    }
  }
}

X86Context::X86Context(Frontend::Node ast) {
  this->ast = ast;
  currentNode = ast;
  writer = new X86Writer();

  variable();
  writer->exitProg();
}

char *X86Context::emit() {
  char *bytes = writer->getBuffer();
  return bytes;
}

} // Codegen
