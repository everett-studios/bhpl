
#include <iostream>
#include <string>

#include "include/utils.hpp"

#include "front/include/parser.hpp"
#include "front/include/lexer.hpp"

int main(int argc, char *argv[]) {
  std::string src = Utilities::readSrc("examples/add.bhpl");

  auto *lexer = new Frontend::Lexer(src);
  std::vector<Token> tokens = lexer->getTokens();

  auto *parser = new Frontend::Parser(tokens);
  auto tree = parser->getTree();

  return 0;
}
