cmake_minimum_required(VERSION 3.27)
project(WORK C)

set(CMAKE_C_STANDARD 11)

add_executable(WORK main.c utility.c utility.h stb_ds.h sha256.c sha256.h)
