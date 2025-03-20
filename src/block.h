#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block {
public:
    Block();
    void Draw();
    void Move(int rows, int columns);
    std::vector<Position> GetCellPosition();
    int id;
    std::map<int, std::vector<Position>> cells; 

private:
    int cellSize;
    int rotationState;
    int rowOffset;
    int columnOffset;
    std::vector<Color> colors;
};