#include <raylib.h>
#include "game.h"

int main()
{

    Game game = Game(STARTING_ROW, STARTING_COL);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "My first RAYLIB program!");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkBlue);
        
        game.Draw();
        game.ManageGame();
        game.Update();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}