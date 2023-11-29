
#include <iostream>
#include <string>
#include <filesystem>
#include <sys/mman.h>

#include "include/utils.hpp"
#include "bytecode/generator/include/output.hpp"
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

  Output::emitC(bytecode);

  std::filesystem::rename("build/src/jit/libbhcrt.a", "libbhcrt.a");
  system("gcc -c tmp.c -o tmp.o");
  system("gcc tmp.o -o add -L. -lbhcrt -lstdc++ -static");

  std::filesystem::remove("runtime.h");
  // std::filesystem::remove("tmp.c");
  std::filesystem::remove("tmp.o");
  std::filesystem::remove("libbhcrt.a");

  return 0;
}
