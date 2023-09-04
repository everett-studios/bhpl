
#include <iostream>
#include <string>
#include <sys/mman.h>

#include "include/utils.hpp"

#include "front/include/parser.hpp"
#include "front/include/lexer.hpp"

#include "codegen/x86_64/include/x86_64_context.hpp"

int main(int argc, char *argv[]) {
  std::string src = Utilities::readSrc("examples/add.bhpl");

  auto *lexer = new Frontend::Lexer(src);
  std::vector<Token> tokens = lexer->getTokens();

  auto *parser = new Frontend::Parser(tokens);
  auto tree = parser->getTree();

  // compile
  auto *ctx = new Codegen::X86Context(tree);
  char *obj = ctx->emit();

  // execute
  void (*func)();
  func = (void (*)()) obj;
  func();

  // release memory back to system
  munmap(obj, 4096);
  return 0;
}
