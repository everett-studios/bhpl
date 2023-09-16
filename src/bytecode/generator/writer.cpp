
#include <iostream>
#include <string>
#include <sstream>

#include "include/writer.hpp"

namespace Bytecode {

Writer::Writer() {
  bytes = "";
}

void Writer::pushv(std::string name) {
  bytes += "6b"; // pushv

  for (auto &chr : name) {
    std::stringstream ss;
    int ascii = int(chr); // variable name
    ss << std::hex << ascii;
    bytes += ss.str();
  }

  bytes += "01"; // endinstr
}

void Writer::setvi32(std::string name, int val) {
  bytes += "6a"; // setvi32

  for (auto &chr : name) {
    std::stringstream ss;
    int ascii = int(chr); // variable name
    ss << std::hex << ascii;
    bytes += ss.str();
  }

  std::stringstream hex;
  hex << std::hex << std::uppercase << val;

  std::string valString = hex.str().substr(0, 2);
  bytes += valString;

  bytes += "01"; // endinstr
}

void Writer::exit() {
  bytes += "9a"; // exit
  bytes += "01"; // endinstr
}

std::string Writer::emit() {
  return bytes;
}

} // Bytecode
