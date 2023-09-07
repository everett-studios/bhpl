
#pragma once

namespace JIT {
  class Reader {
  private:
    int *bytecode;
    int currentIdx;
  public:
    Reader(int *bytecode);
    std::string nextInstr();
    bool done();
  };
}
