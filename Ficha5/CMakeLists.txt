cmake_minimum_required(VERSION 3.27)
project(Ficha5 C)

set(CMAKE_C_STANDARD 99)

add_executable(teste teste.c)
add_executable(ex1-2 ex1-2/main.c ex1-2/ponto.c ex1-2/ponto.h
        ex1-2/retangulo.h ex1-2/retangulo.c)
