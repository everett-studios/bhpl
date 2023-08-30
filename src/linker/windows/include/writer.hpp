
#pragma once

#include <string>
#include <vector>

namespace Linker {
  class PEWriter {
  private:
    std::vector<int> buffer;
  public:
    PEWriter();

    void int8(int i);
    void int16(int i);
    void int32(int i);
    void int64(int i);
    void zeroes(int num);
    void str(std::string str);
    void strPadding(std::string str, int max);
    void padTo(int buf[], int len);
    void write(std::vector<uint32_t> bytes);

    int *buf();
  };
}
