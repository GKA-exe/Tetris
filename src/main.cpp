#include <raylib.h>
#include "game.h"

double lastupdatetime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastupdatetime >= interval)
    {
        lastupdatetime = currentTime;
        return true;
    }
    return false;
}

int main() 
{
    Color darkBlue = {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.HandleInput();
        if(EventTriggered(0.5))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}