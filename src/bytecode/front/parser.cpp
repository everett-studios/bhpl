
#include <iostream>
#include <string>

#include "include/parser.hpp"

namespace Frontend {

// the main recursive descent method
Node Parser::parse() {
  Node node;

  std::string varName;
  std::string varType;

  // variable integer type parsing
  if (tokens[tknIdx].name == "$T_INTEGER") {
    node.name = "$P_VAR_VAL";
    node.tknChildren.push_back(Token {"$PT_INT_VAL", tokens[tknIdx].value});
  }

  if (tokens[tknIdx].name == "$T_LETTERS") {
    // data type
    if (tokens[tknIdx].name == "$T_LETTERS" && tokens[tknIdx].value == "int") {
      tknIdx++;
    }

    // variable parsing
    if (tokens[tknIdx + 1].name == "$T_EQUALS" && tknIdx != 0) {
      varName = tokens[tknIdx].value;
      varType = tokens[tknIdx - 1].value;
      tknIdx += 2;

      node.name = "=";
      node.tknChildren.push_back(Token {"$PT_TYPE", varType});
      node.tknChildren.push_back(Token {"$PT_VAR_NAME", varName});

      // recursive part
      Node childNode = parse();
      node.children.push_back(childNode);
    }
  }

  if (tokens[tknIdx].name == "$T_SEMICOLON") {
    node.name = "$P_TERMINATOR";
  }

  return node;
}

Parser::Parser(std::vector<Token> tokens) {
  tknIdx = 0;
  this->tokens = tokens;
  tree = parse();
}

Node Parser::getTree() {
  return tree;
}

} // Frontend
