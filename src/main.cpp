#include "Maze.h"
#include "Solver.h"
#include "Database.h"
#include "Menu.h"

int main()
{
    Maze maze(15, 15);

    maze.generateMaze();
    maze.displayMaze();

    Solver solver;
    solver.solveDFS(maze);

    return 0;
}