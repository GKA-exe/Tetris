#include "block.h"

Block::Block() {
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
};

void Block::Draw() {
    std::vector <Position> tiles = GetCellPosition();
    for(Position item:tiles) {
        DrawRectangle(item.row * cellSize + 1, item.column * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int rows, int columns) {
    rowOffset += rows;
    columnOffset += columns;
}

std::vector <Position> Block::GetCellPosition(){
    std::vector <Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for(Position item:tiles) {
        Position newPosition = {item.row + rowOffset, item.column + columnOffset};
        movedTiles.push_back(newPosition);
    }
    return movedTiles;
}