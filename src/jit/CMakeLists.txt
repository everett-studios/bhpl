
cmake_minimum_required(VERSION 3.0)
project(bhcrt VERSION 0.1)

set(CMAKE_CXX_STANDARD 17) # IMPORTANT!
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SRCS ../utils.cpp bytecode/reader.cpp codegen/x86_64/x86_64_context.cpp codegen/x86_64/runtime.cpp codegen/x86_64/writer.cpp)

add_library(bhcrt ${SRCS})
target_link_libraries(bhcrt stdc++)
