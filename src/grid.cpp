#include "grid.h"
#include "colors.h"
#include <iostream>
#include <raylib.h>

Grid::Grid() {
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize() {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            grid[i][j] = 0;
        }
    }
}

void Grid::printGrid() {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw() {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int colorIndex = grid[i][j];
            Color color = colors[colorIndex];
            DrawRectangle(j * cellSize + 1, i * cellSize + 1, cellSize - 1, cellSize - 1, color);
        }
    }
}

bool Grid::IsCellOutside(int row, int col)
{
    if(row >= 0 && row < numRows && col >= 0 && col < numCols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
    if(grid[row][column] == 0)
    {
        return true;
    }
    return false;
}
