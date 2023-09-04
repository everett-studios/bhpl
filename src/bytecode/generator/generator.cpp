
#include <iostream>
#include <string>

#include "include/generator.hpp"

namespace Bytecode {

void Generator::variable() {
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

          writer->pushv(varName);
          writer->setvi32(varName, intVal);
        }
      }
    }
  }
}

Generator::Generator(Frontend::Node ast) {
  this->ast = ast;
  currentNode = ast;
  writer = new Writer();

  variable();
  writer->exit();
}

std::string Generator::emit() {
  std::string bytes = writer->emit();
  return bytes;
}

} // Bytecode