
#pragma once

namespace JIT {
  class Reader {
  private:
    int *bytecode;
  public:
    int currentIdx;

    Reader(int *bytecode);
    std::string nextInstr();
    bool done();
  };
}
