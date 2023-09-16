
cmake_minimum_required(VERSION 3.0)
project(bhc VERSION 0.1)

set(CMAKE_CXX_STANDARD 17) # IMPORTANT!
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(BYTECODE_GENERATOR_SRCS src/bytecode/generator/generator.cpp src/bytecode/generator/writer.cpp src/bytecode/generator/output.cpp)
set(BYTECODE_FRONT_SRCS src/bytecode/front/lexer.cpp src/bytecode/front/parser.cpp)
set(SRCS ${BYTECODE_GENERATOR_SRCS} ${BYTECODE_FRONT_SRCS} src/main.cpp src/utils.cpp)

add_subdirectory(src/jit)
add_executable(bhc ${SRCS})
