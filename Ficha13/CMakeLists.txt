cmake_minimum_required(VERSION 3.28)
project(Ficha13 C)

set(CMAKE_C_STANDARD 99)

add_executable(teste main.c)
add_executable(ex2 ex2/ex2.c ex2/banco.c ex2/banco.h)
