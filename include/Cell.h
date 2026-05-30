#ifndef CELL_H
#define CELL_H

struct Cell
{
    int row;
    int col;

    Cell(int r, int c)
        : row(r), col(c)
    {
    }
};

#endif