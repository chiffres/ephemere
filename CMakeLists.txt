cmake_minimum_required(VERSION 4.0)
project(ephemeral C)

set(CMAKE_C_STANDARD 23)

add_library(ephemeral STATIC ephemeral.c
        ephemeral.c
        ephemeral.h)
