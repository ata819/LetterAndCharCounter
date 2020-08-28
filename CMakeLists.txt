cmake_minimum_required(VERSION 3.16)
project(prog0 C)

set(CMAKE_C_STANDARD 99)

add_executable(prog0 alphabetcount.c count.h specialcharcount.c testalphabetcount.c testspecialcharcount.c)