
#pragma once

namespace JIT {
  class Reader {
  private:
    std::string bytecode;
    int currentIdx;
  public:
    Reader(std::string bytecode);
    std::string nextInstr();
    bool done();
  };
}
