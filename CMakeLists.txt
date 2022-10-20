cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 20)
project(calculator VERSION 1.0)

add_subdirectory(calctree)

add_executable(main main.cpp)
add_executable(test testunique.cpp)

target_link_libraries(ctl)
