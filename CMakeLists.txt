cmake_minimum_required(VERSION 3.0)
project(calculator VERSION 1.0)

add_subdirectories(calctree)

add_executable(main main.cpp)

target_link_library(calctree)
