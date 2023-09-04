
#include <iostream>
#include <string>
#include <sstream>

#include "include/writer.hpp"

namespace Bytecode {

Writer::Writer() {
  bytes = "";
}

void Writer::pushv(std::string name) {
  bytes += "\x6b"; // pushv
  bytes += name; // variable name
  bytes += "\x01"; // endinstr
}

void Writer::setvi32(std::string name, int val) {
  bytes += "\x6a"; // setvi32
  bytes += name; // variable name

  std::stringstream hex;
  hex << std::hex << std::uppercase << val;

  std::string valString = hex.str().substr(0, 2);
  int num = strtol(valString.c_str(), nullptr, 16);

  bytes += "\x01";
  bytes += "\x01"; // endinstr
}

void Writer::exit() {
  bytes += "\x9a"; // exit
  bytes += "\x01"; // endinstr
}

std::string Writer::emit() {
  return bytes;
}

} // Bytecode
