cmake_minimum_required(VERSION 2.8)
project(Algorithms)

set(CMAKE_C_FLAGS "-std=c99 -D_XOPEN_SOURCE=700") #[[ X/Open 7, incorporating POSIX 2008 ]]

set(CMAKE_MACOSX_RPATH 1)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

add_subdirectory(src)
add_subdirectory(test)