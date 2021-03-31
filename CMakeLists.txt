cmake_minimum_required(VERSION 3.17)
project(Clion)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

add_executable(Clion src/Base64.cpp)

