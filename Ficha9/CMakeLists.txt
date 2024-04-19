cmake_minimum_required(VERSION 3.27)
project(Ficha9 C)

set(CMAKE_C_STANDARD 99)

add_executable(ex1 ex1/main.c ex1/parque.c ex1/parque.h)
add_executable(ex2 ex2/main.c ex2/testes.c ex2/testes.h)
add_executable(ex3 ex3/main.c ex3/dados.c ex3/dados.h)
