
#include <iostream>
#include <string>
#include <sstream>
#include <filesystem>

#include "include/output.hpp"
#include "../../include/utils.hpp"

void Output::emitC(std::string bytecode) {
  std::string buf;

  if (!std::filesystem::exists("runtime.h")) {
    std::filesystem::copy_file("src/jit/codegen/x86_64/include/runtime.h", "runtime.h");
  }

  buf += "#include \"runtime.h\"\n";
  buf += "int main() { ";
  buf += "int code[] = {";

  std::string currentHex;

  for (int i = 0; i < bytecode.length(); i++) {
    char c = bytecode[i];
    currentHex += c;

    if (currentHex.length() == 2) {
      buf += "0x";
      buf += currentHex;
      buf += ", ";
      currentHex = "";
    }
  }

  buf += "}; ";
  buf += "bhcrt_execute(code); ";
  buf += "return 0; ";
  buf += "}";

  Utilities::writeTextFile("tmp.c", buf);
}
