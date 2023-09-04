
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

  auto *ctx = new Codegen::X86Context(tree);
  std::string obj = ctx->emit();

  // compile & execute the assembly
  char *mem = (char*)mmap(NULL, 4096, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  if (mem == MAP_FAILED) {
    std::cout << "ERROR: Failed to allocate memory for program!" << std::endl;
    exit(1);
  }

  int i = 0;

  mem[i++] = 0xb8;
  mem[i++] = 0x9a;
  mem[i++] = 0x00;
  mem[i++] = 0x00;

  munmap(mem, 4096);

  return 0;
}
