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
    bool IsCellOutside(int row, int col);
    int grid[20][10];

private:
    int numRows, numCols;
    int cellSize;
    std::vector<Color> colors;
};
