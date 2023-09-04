
#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <vector>

#ifdef _WIN32
  #include <intrin.h>
#elif __unix
  #include <sys/mman.h>
  #include <byteswap.h>
#endif

#include "include/writer.hpp"

namespace Codegen {

X86Writer::X86Writer() {
  buffer = (char*)mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  bufIdx = 0;

  if (buffer == MAP_FAILED) {
    std::cout << "ERROR: Failed to allocate memory for program!" << std::endl;
    exit(1);
  }
}

void X86Writer::i32ToHex(uint32_t val) {
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
    int byte = strtol(byteString.c_str(), nullptr, 16);
    buffer[bufIdx++] += byte;
  }
}

void X86Writer::movl(Codegen::X86Register reg, uint32_t val) {
  buffer[bufIdx++] = 0xba; // movl %edx
  i32ToHex(val); // little endian hex value of value provided
}

void X86Writer::exitProg() {
  buffer[bufIdx++] = 0xb8; // movl %eax
  buffer[bufIdx++] = 0x01; // sys_exit
  buffer[bufIdx++] = 0x00; // padding
  buffer[bufIdx++] = 0x00; // padding
  buffer[bufIdx++] = 0x00; // padding

  buffer[bufIdx++] = 0xbb; // movl %ebx
  buffer[bufIdx++] = 0x00; // exit code 0
  buffer[bufIdx++] = 0x00; // padding
  buffer[bufIdx++] = 0x00; // padding
  buffer[bufIdx++] = 0x00; // padding

  buffer[bufIdx++] = 0xcd; // int
  buffer[bufIdx++] = 0x80; // 0x80
}

char *X86Writer::getBuffer() {
  return buffer;
}

} // Codegen
