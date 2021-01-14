cmake_minimum_required(VERSION 3.17)
project(MoveSquare C)

set(CMAKE_C_STANDARD 99)


include_directories(src/sdl/include/SDL2)
link_directories(src/sdl/lib)


add_executable(MoveSquare src/main.c src/mainHeader.h)
target_link_libraries(MoveSquare SDL2main SDL2)