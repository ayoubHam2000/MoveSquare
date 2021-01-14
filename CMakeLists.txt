cmake_minimum_required(VERSION 3.17)
project(MoveSquare C)

set(CMAKE_C_STANDARD 99)


include_directories(src/sdl/include/SDL2 src/headers src/sdl/sdl_ttf/include)
link_directories(src/sdl/lib src/sdl/sdl_ttf/lib/x64)


add_executable(MoveSquare src/main.c src/headers/mainHeader.h src/functions/sdlBasics.c src/headers/sdlBasics.h src/headers/myStruct.h src/functions/rect.c src/headers/rect.h)
target_link_libraries(MoveSquare SDL2main SDL2 SDL2_ttf)