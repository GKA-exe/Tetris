#pragma once
// avoids duplicate definitions
#include <vector>
#include "raylib.h"

class Grid {
public:
    Grid();
    void Initialize();
    void printGrid();
    void Draw();
    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);
    int grid[20][10];

private:
    int numRows, numCols;
    int cellSize;
    std::vector<Color> colors;
};
