#ifndef MAZE_H
#define MAZE_H

#include <vector>

class Maze
{
private:
    int rows;
    int cols;
    std::vector<std::vector<char>> grid;

public:
    Maze(int r, int c);

    void generateMaze();
    void displayMaze() const;

    std::vector<std::vector<char>>& getGrid();

    int getRows() const;
    int getCols() const;
};

#endif