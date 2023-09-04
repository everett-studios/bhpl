
#pragma once

#include "lexer.hpp"

namespace Frontend {

struct Node {
  std::string name;
  std::vector<Token> tknChildren;
  std::vector<Node> children;
};

class Parser {
private:
  std::vector<Token> tokens;
  Node tree;
  int tknIdx;

  Node parse();
public:
  Parser(std::vector<Token> tokens);
  Node getTree();
};

} // Frontend
