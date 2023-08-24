
cmake_minimum_required(VERSION 3.23)
project(bhc VERSION 0.1)

set(CMAKE_CXX_STANDARD 17) # IMPORTANT!
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SRCS src/main.cpp)

add_executable(bhc ${SRCS})
