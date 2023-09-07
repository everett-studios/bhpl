
#include <iostream>
#include <string>
#include <sys/mman.h>

#include "include/utils.hpp"
#include "bytecode/generator/include/generator.hpp"

int main(int argc, char *argv[]) {
  std::string src = Utilities::readSrc("examples/add.bhpl");

  auto *lexer = new Frontend::Lexer(src);
  std::vector<Token> tokens = lexer->getTokens();

  auto *parser = new Frontend::Parser(tokens);
  auto tree = parser->getTree();

  // generate bytecode
  auto *bytecodeGenerator = new Bytecode::Generator(tree);
  std::string bytecode = bytecodeGenerator->emit();

  return 0;
}
