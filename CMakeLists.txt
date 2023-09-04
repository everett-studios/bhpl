
cmake_minimum_required(VERSION 3.0)
project(bhc VERSION 0.1)

set(CMAKE_CXX_STANDARD 17) # IMPORTANT!
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(BYTECODE_GENERATOR_SRCS src/bytecode/generator/generator.cpp src/bytecode/generator/writer.cpp)
set(BYTECODE_FRONT_SRCS src/bytecode/front/lexer.cpp src/bytecode/front/parser.cpp)
set(JIT_BYTECODE_SRCS src/jit/bytecode/reader.cpp)
set(JIT_X86_SRCS src/jit/codegen/x86_64/writer.cpp src/jit/codegen/x86_64/x86_64_context.cpp)
set(SRCS ${BYTECODE_GENERATOR_SRCS} ${BYTECODE_FRONT_SRCS} ${JIT_BYTECODE_SRCS} ${JIT_X86_SRCS} src/main.cpp src/utils.cpp)

add_executable(bhc ${SRCS})
