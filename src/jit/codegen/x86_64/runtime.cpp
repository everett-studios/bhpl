
#include <iostream>
#include <string>

#ifdef __unix__
#include "sys/mman.h"
#endif

#include "include/runtime.h"
#include "include/x86_64_context.hpp"
#include "../../../include/utils.hpp"

extern "C" void bhcrt_execute(int *code) {
  auto *ctx = new Codegen::X86Context(code);
  char *obj = ctx->emit();

  if (mprotect(obj, 4096, PROT_READ | PROT_EXEC) == -1) {
    std::cout << "ERROR: Failed to call 'mprotect'!" << std::endl;
    exit(1);
  }

  void (*func)();
  func = (void (*)()) obj;
  func();

  munmap(obj, 4096);
}
