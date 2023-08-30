
#pragma once
#include <string>

// Global language utils
namespace Utilities {
  std::string readSrc(std::string filepath);
  void writeBinaryFile(std::string filepath, int bytes[]);
}
