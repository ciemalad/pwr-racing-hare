cmake_minimum_required(VERSION 3.24)
project(pwr_racing_recrutation)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(Hare Hare/main.cpp)
add_library(Hare_core Hare/Node.cpp Hare/Node.h Hare/AStar.cpp Hare/AStar.h Hare/Field.cpp Hare/Field.h)

add_subdirectory(GoogleTest)
target_link_libraries(Hare Hare_core)

