#include "game.h"
#include <random>

Game::Game() {
    grid = Grid();
    blocks = GetBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock() {
    if(blocks.empty()) {
        blocks = GetBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector <Block> Game::GetBlocks() {
    return {ZBlock(), LBlock(), JBlock(), IBlock(), OBlock(), SBlock()};
}

void Game::HandleInput() {
    int keyPressed = GetKeyPressed();
    switch(keyPressed) {
        case KEY_LEFT:
            MoveBlockLeft();
            break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            break;
        case KEY_UP:
            RotateBlock();
            break;
    }
}

void Game::Draw() {
    grid.Draw();
    currentBlock.Draw();
}

void Game::MoveBlockLeft()
{
    currentBlock.Move(0, -1);
    if (IsCellOutside() || BlockFits() == false)
    {
        currentBlock.Move(0, 1);
    }
}
void Game::MoveBlockRight()
{
    currentBlock.Move(0, 1);
    if (IsCellOutside() || BlockFits() == false)
    {
        currentBlock.Move(0, -1);
    }
}
void Game::MoveBlockDown()
{
    currentBlock.Move(1, 0);
    if(IsCellOutside() || BlockFits() == false) {
        currentBlock.Move(-1, 0);
        LockBlock();
    }
}

bool Game::IsCellOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPosition();
    for(Position item: tiles) {
        if(grid.IsCellOutside(item.column, item.row)) {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock()
{
    currentBlock.Rotate();
    if (IsCellOutside() || BlockFits() == false)
    {
        currentBlock.UndoRotate();
    }
}

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPosition();
    for(Position item: tiles) {
        grid.grid[item.column][item.row] = currentBlock.id;
    }
    currentBlock = nextBlock;
    nextBlock = GetRandomBlock();
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPosition();
    for(Position item : tiles) {
        if(grid.IsCellEmpty(item.column, item.row) == false) {
            return false;
        }
    }
    return true;
}
