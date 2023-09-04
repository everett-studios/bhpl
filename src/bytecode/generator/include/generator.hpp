
#pragma once

#include <string>
#include "writer.hpp"
#include "../../front/include/parser.hpp"

namespace Bytecode {
  class Generator {
  private:
    Writer *writer;
    Frontend::Node currentNode;
    Frontend::Node ast;
    
    void variable();
  public:
    Generator(Frontend::Node ast);
    std::string emit();
  };
}
