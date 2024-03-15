cmake_minimum_required(VERSION 3.27)
project(Ficha7 C)

set(CMAKE_C_STANDARD 99)

add_executable(ex2 ex2/main.c ex2/agenda.h ex2/agenda.c)
add_executable(ex3 ex3/main.c ex3/movimento.c ex3/movimento.h)
