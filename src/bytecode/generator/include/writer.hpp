
#pragma once
#include <string>

namespace Bytecode {
  class Writer {
  private:
    std::string bytes;
  public:
    Writer();

    void pushv(std::string name);
    void setvi32(std::string name, int val);
    void exit();

    std::string emit();
  };
}
