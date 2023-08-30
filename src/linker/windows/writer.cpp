
#include <iostream>
#include <string>

#include "include/writer.hpp"

namespace Linker {

PEWriter::PEWriter() {

}

void PEWriter::int8(int i) {
  buffer.push_back(i);
}

void PEWriter::int16(int i) {
  buffer.push_back(i);
  buffer.push_back(i >> 8);
}

void PEWriter::int32(int i) {
  buffer.push_back(i);
  buffer.push_back(i >> 8);
  buffer.push_back(i >> 16);
  buffer.push_back(i >> 24);
}

void PEWriter::int64(int i) {
  buffer.push_back(i);
  buffer.push_back(i >> 8);
  buffer.push_back(i >> 16);
  buffer.push_back(i >> 24);
  buffer.push_back(i >> 32);
  buffer.push_back(i >> 40);
  buffer.push_back(i >> 48);
  buffer.push_back(i >> 56);
}

void PEWriter::zeroes(int num) {
  for (int i = 0; i < num; i++) {
    int8(0);
  }
}

void PEWriter::str(std::string str) {
  for (auto &c : str) {
    buffer.push_back((int)c);
  }
}

void PEWriter::strPadding(std::string str, int max) {
  this->str(str);

  for (int i = 0; i < max - str.length(); i++) {
    int8(0);
  }
}

void PEWriter::padTo(int buf[], int len) {
  while ((sizeof(buf)/sizeof(buf[0])) < len) {
    int8(0); 
  }
}

void PEWriter::write(std::vector<uint32_t> bytes) {
  for (auto &b : bytes) {
    buffer.push_back(b);
  } 
}

int *PEWriter::buf() {
  int *a = &buffer[0];
  return a;
}

}
