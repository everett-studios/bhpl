
#include <iostream>
#include <string>

#include "include/lexer.hpp"

namespace Frontend {

void Lexer::skipWhitespace() {
  while (isspace(src[idx])) {
    idx++;
  }
}

std::string Lexer::tokenizeLetters() {
  std::string letters;

  while (isalpha(src[idx]) || src[idx] == '_') {
    letters += src[idx];
    idx++;
  }

  return letters;
}

std::string Lexer::tokenizeInt() {
  std::string integer;

  while (isdigit(src[idx])) {
    integer += src[idx];
    idx++;
  }

  return integer;
}

void Lexer::tokenizeSymbol() {
  Token tkn;

  // equal sign; used in assignment
  if (src[idx] == '=') {
    tkn.name = "$T_EQUALS";
  }

  // semicolon; used to terminate a line
  if (src[idx] == ';') {
    tkn.name = "$T_SEMICOLON";
  }

  // if the character was actually parsed, add the token
  if (tkn.name != "") {
    tkn.value = src[idx];
    tokens.push_back(tkn);
  }
}

Lexer::Lexer(std::string src) {
  idx = 0;
  this->src = src;

  skipWhitespace();

  // tokenization (line by line)
  while (idx < src.length() - 1) {
    // attempt to tokenize letters first
    std::string letters = tokenizeLetters();

    // if letters were actually found, append it to the token stream
    if (letters.length() > 0) {
      Token tkn;

      tkn.name = "$T_LETTERS";
      tkn.value = letters;

      tokens.push_back(tkn);

      // move on
      skipWhitespace();
      continue;
    }

    // now try to tokenize an integer
    std::string integer = tokenizeInt();

    // repeat the same thing
    if (integer.length() > 0) {
      Token tkn;

      tkn.name = "$T_INTEGER";
      tkn.value = integer;

      tokens.push_back(tkn);

      // move on
      skipWhitespace();
      continue;
    }

    // one more time but with symbols (e.g. = - * + - ...)
    tokenizeSymbol();

    idx++;
    skipWhitespace();
  }
}

std::vector<Token> Lexer::getTokens() {
  return tokens;
}

} // Frontend
