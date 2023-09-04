
#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <vector>

#ifdef _WIN32
  #include <intrin.h>
#elif __unix
  #include <byteswap.h>
#endif

#include "include/writer.hpp"

namespace Codegen {

X86Writer::X86Writer() {
  buffer = "";
}

std::string X86Writer::i32ToHex(uint32_t val) {
  std::string hexString;

  // convert to little endian
  unsigned short littleEndian = 0;

  #ifdef _WIN32
    littleEndian = _byteswap_ushort(val);
  #elif __unix__
    littleEndian = bswap_16(val);
  #endif
  
  std::bitset<16> bits{littleEndian};

  // convert to hexadecimal
  std::stringstream result;
  result << std::hex << std::uppercase << bits.to_ulong();
  std::string hex = result.str();

  // add padding if needed
  if ((hex.length() / 2) < 4) {
    int diff = 4 - (hex.length() / 2);

    for (int i = 0; i < diff; i++) {
      hex += "00";
    }
  }

  // convert to usable byte string
  for (unsigned int i = 0; i < hex.length(); i += 2) {
    std::string byteString = hex.substr(i, 2);
    char byte = (char) strtol(byteString.c_str(), nullptr, 16);
    hexString += byte;
  }

  return hexString;
}

void X86Writer::movl(Codegen::X86Register reg, uint32_t val) {
  buffer += "\xb8"; // movl, width, eax
  buffer += i32ToHex(val); // little endian hex value of value provided
}

std::string X86Writer::getBuffer() {
  return buffer;
}

} // Codegen
