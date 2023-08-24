
cmake_minimum_required(VERSION 3.23)
project(bhc VERSION 0.1)

set(CMAKE_CXX_STANDARD 17) # IMPORTANT!
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(FRONTEND_UTILS src/front/lexer.cpp)
set(SRCS ${FRONTEND_UTILS} src/main.cpp src/utils.cpp)

add_executable(bhc ${SRCS})
