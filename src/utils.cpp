
#include <iostream>
#include <string>
#include <fstream>

#include "include/utils.hpp"

// Read the BHPL source code as a std::string
std::string Utilities::readSrc(std::string filepath) {
  std::string line, src;
  std::ifstream file(filepath);

  // actually reading the file here
  if (file.is_open()) {
    while (std::getline(file, line)) {
      src += line + '\n';
    }
  } else {
    // simple error handling
    std::cout << "ERROR: No such file \"" + filepath + "\"!" << std::endl;
    exit(1);
  }

  // we're done; free
  file.close();
  return src;
}

void Utilities::writeBinaryFile(std::string filepath, int bytes[]) {
  std::ofstream file(filepath, std::ios::out | std::ios::binary);

  if (!file.is_open()) {
    std::cout << "ERROR: Can't write file to path \"" + filepath + "\"!" << std::endl;
    exit(1);
  }

  file.write(reinterpret_cast<const char*>(bytes), sizeof(bytes));
  file.close();
}
