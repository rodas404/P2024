cmake_minimum_required(VERSION 3.27)
project(Desafios C)

set(CMAKE_C_STANDARD 99)

add_executable(testes main.c)
add_executable(desafio1 2021136740-d1.c)
add_executable(desafio2 desafio2/funcao.h desafio2/2021136740.c desafio2/main.c)
add_executable(desafio3 desafio3/main.c desafio3/2021136740.c desafio3/lista.h)

