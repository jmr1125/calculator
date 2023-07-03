cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_TEST OFF)
# set(BUILD_TEST ON)
project(calculator VERSION 1.0)
find_package(qpdf)
if(qpdf_DIR)
  message(STATUS "using qpdf")
  set(haslib ON)
else()
  set(haslib OFF)
endif()

#message(${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR})

if(${haslib})
  message(STATUS "haslib")
  add_definitions(-DHASLIB)
endif()

add_subdirectory(calctree)

if(${BUILD_TEST})
	add_executable(test1 testbuild.cpp)
	add_executable(test testunique.cpp)
	if(${haslib})
		add_executable(test2 testqpdf.cpp)
		add_executable(test3 testgenpdf.cpp)
	endif()
	target_link_libraries(test1 ctl)
	if(${haslib})
		target_link_libraries(test2 qpdf::libqpdf)
		target_link_libraries(test3 genpdf)
	endif()
endif()


add_executable(gen main.cpp types.cpp gen.cpp)

add_custom_command(
	TARGET gen
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/xiaozan.conf ${CMAKE_BINARY_DIR}
	DEPENDS gen
	VERBATIM)

if(${haslib})
add_library(genpdf genpdf.cpp)
endif()

if(NOT ${haslib})
  target_link_libraries(gen ctl)
else()
  target_link_libraries(genpdf qpdf::libqpdf)
  target_link_libraries(gen ctl genpdf)
endif()
