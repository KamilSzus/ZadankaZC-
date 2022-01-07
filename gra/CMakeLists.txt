cmake_minimum_required(VERSION 3.17)
project(gra)

set(CMAKE_CXX_STANDARD 14)

add_executable(gra main.cpp cpoint.h screen.h snake.h winsys.h screen.cpp snake.cpp winsys.cpp)