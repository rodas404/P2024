cmake_minimum_required(VERSION 3.27)
project(Ficha6 C)

set(CMAKE_C_STANDARD 99)

add_executable(teste teste.c)
add_executable(ex1 ex1/main.c ex1/tabela.c ex1/tabela.h ex1/ponto.h ex1/ponto.c ex1/retangulo.h ex1/retangulo.c)
add_executable(ex2 ex2/main.c ex2/agenda.c ex2/agenda.h)