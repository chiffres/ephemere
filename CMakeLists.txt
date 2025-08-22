cmake_minimum_required(VERSION 3.31.6)
project(ephemeral C)

set(CMAKE_C_STANDARD 23)


add_library(ephemeral STATIC ephemeral.c)

install(FILES ephemeral.h DESTINATION include)
install(TARGETS ephemeral DESTINATION lib)
