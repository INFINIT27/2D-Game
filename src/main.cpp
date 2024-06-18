#include <raylib.h>
#include "game.h"

int main()
{

    const int screenWidth = 1000;
    const int screenHeight = 500;

    Game game = Game(43, 4);

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkBlue);
        
        game.Draw();
        game.ManageGame();
        game.Update();
        // game.PrintPlayer();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}