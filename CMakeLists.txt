cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(calculator VERSION 1.0)
find_package(qpdf)
if(qpdf_DIR)
  message(STATUS "using qpdf")
  set(haslib 1)
else()
  set(haslib 0)
endif()


if(${haslib} STREQUAL 0)
  option(HASLIB "1" OFF)
else()
  message(STATUS "haslib")
  option(HASLIB "1" ON)
  add_definitions(-DHASLIB)
endif()

add_subdirectory(calctree)

add_executable(test1 testbuild.cpp)
add_executable(test testunique.cpp)
target_link_libraries(test1 ctl)

add_executable(gen main.cpp types.cpp gen.cpp)


if(${haslib} STREQUAL 0)
  target_link_libraries(gen ctl)
else()
  target_link_libraries(gen ctl qpdf::libqpdf)
endif()
