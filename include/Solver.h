#ifndef SOLVER_H
#define SOLVER_H

#include "Maze.h"

class Solver
{
public:
    bool solveDFS(Maze& maze);
    bool solveBFS(Maze& maze);

private:
    bool dfs(Maze& maze, int row, int col);
};

#endif