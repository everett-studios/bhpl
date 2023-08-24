
#pragma once

#include <string>
#include <vector>

struct Token {
  std::string name;
  std::string value;
};

namespace Frontend {

class Lexer {
private:
  std::string src;
  std::vector<Token> tokens; // actual tokens
  int idx;

  // functions
  void skipWhitespace();
  void tokenizeSymbol();

  std::string tokenizeLetters();
  std::string tokenizeInt();
public:
  Lexer(std::string src);
  std::vector<Token> getTokens();
};

} // Frontend
