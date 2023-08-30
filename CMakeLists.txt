
cmake_minimum_required(VERSION 3.23)
project(bhc VERSION 0.1)

set(CMAKE_CXX_STANDARD 17) # IMPORTANT!
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(LINKER_SRCS src/linker/windows/linker.cpp src/linker/windows/writer.cpp)
set(X86_SRCS src/codegen/x86_64/x86_64_context.cpp src/codegen/x86_64/writer.cpp)
set(FRONTEND_SRCS src/front/lexer.cpp src/front/parser.cpp)
set(SRCS ${FRONTEND_SRCS} ${X86_SRCS} ${LINKER_SRCS} src/main.cpp src/utils.cpp)

add_executable(bhc ${SRCS})
