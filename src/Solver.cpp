#include "Solver.h"
#include "Cell.h"

#include <iostream>
#include <queue>

bool Solver::dfs(Maze& maze, int row, int col)
{
    auto& grid = maze.getGrid();

    int rows = maze.getRows();
    int cols = maze.getCols();

    if (row < 0 || col < 0 || row >= rows || col >= cols)
        return false;

    if (grid[row][col] == '#')
        return false;

    if (grid[row][col] == 'V')
        return false;

    if (grid[row][col] == 'E')
        return true;

    if (grid[row][col] != 'S')
        grid[row][col] = 'V';

    if (dfs(maze, row + 1, col))
        return true;

    if (dfs(maze, row - 1, col))
        return true;

    if (dfs(maze, row, col + 1))
        return true;

    if (dfs(maze, row, col - 1))
        return true;

    return false;
}

bool Solver::solveDFS(Maze& maze)
{
    bool found = dfs(maze, 0, 0);

    if (found)
        std::cout << "\nPath Found (DFS)\n";
    else
        std::cout << "\nNo Path Found\n";

    maze.displayMaze();

    return found;
}

bool Solver::solveBFS(Maze& maze)
{
    auto& grid = maze.getGrid();

    int rows = maze.getRows();
    int cols = maze.getCols();

    std::queue<Cell> q;

    q.push(Cell(0, 0));

    while (!q.empty())
    {
        Cell current = q.front();
        q.pop();

        int r = current.row;
        int c = current.col;

        if (r < 0 || c < 0 || r >= rows || c >= cols)
            continue;

        if (grid[r][c] == '#')
            continue;

        if (grid[r][c] == 'V')
            continue;

        if (grid[r][c] == 'E')
        {
            std::cout << "\nPath Found (BFS)\n";
            return true;
        }

        if (grid[r][c] != 'S')
            grid[r][c] = 'V';

        q.push(Cell(r + 1, c));
        q.push(Cell(r - 1, c));
        q.push(Cell(r, c + 1));
        q.push(Cell(r, c - 1));
    }

    std::cout << "\nNo Path Found\n";
    return false;
}