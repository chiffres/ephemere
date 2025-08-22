cmake_minimum_required(VERSION 4.0)
project(ephemere C)

set(CMAKE_C_STANDARD 23)

add_library(ephemere STATIC library.c)
