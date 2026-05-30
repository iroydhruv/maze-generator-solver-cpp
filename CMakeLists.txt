cmake_minimum_required(VERSION 3.10)

project(MazeGeneratorSolver)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

find_package(SQLite3 REQUIRED)

add_executable(
    MazeGeneratorSolver
    src/main.cpp
    src/Maze.cpp
    src/Solver.cpp
    src/Database.cpp
    src/Menu.cpp
    src/Utils.cpp
)

target_link_libraries(
    MazeGeneratorSolver
    SQLite3::SQLite3
)