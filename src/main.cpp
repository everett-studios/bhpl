
#include <iostream>
#include <string>

#include "include/utils.hpp"

#include "front/include/parser.hpp"
#include "front/include/lexer.hpp"

#include "codegen/x86_64/include/x86_64_context.hpp"
#include "linker/windows/include/linker.hpp"

int main(int argc, char *argv[]) {
  std::string src = Utilities::readSrc("examples/add.bhpl");

  auto *lexer = new Frontend::Lexer(src);
  std::vector<Token> tokens = lexer->getTokens();

  auto *parser = new Frontend::Parser(tokens);
  auto tree = parser->getTree();

  auto *ctx = new Codegen::X86Context(tree);
  std::string obj = ctx->emit();

  Linker::linkPE(obj, "test2.exe");

  return 0;
}
