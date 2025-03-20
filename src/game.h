#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game {
public:
    Game();
    Block GetRandomBlock();
    std::vector<Block> GetBlocks();
    void HandleInput();
    void Draw();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    Grid grid;

private:
    bool IsCellOutside();
    void RotateBlock();
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};