#include "Maze.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

Maze::Maze(int r, int c)
{
    rows = r;
    cols = c;

    grid.resize(rows, std::vector<char>(cols, '#'));

    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Maze::generateMaze()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (std::rand() % 100 < 70)
                grid[i][j] = ' ';
            else
                grid[i][j] = '#';
        }
    }

    grid[0][0] = 'S';
    grid[rows - 1][cols - 1] = 'E';
}

void Maze::displayMaze() const
{
    for (const auto& row : grid)
    {
        for (char cell : row)
        {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
}

std::vector<std::vector<char>>& Maze::getGrid()
{
    return grid;
}

int Maze::getRows() const
{
    return rows;
}

int Maze::getCols() const
{
    return cols;
}