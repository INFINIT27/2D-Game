#pragma once
#include "grid.h"
#include "player.h"

class Game
{
    private:
    public:
        Grid grid = Grid();
        Player player;
        Game();
        Game(int row, int col);
        void Update();
        void Draw();
        void Move(int x, int y);
        void ManageGame();
        void PrintPlayer();
        bool CheckCollisionWithWalls();
        bool CheckCollisionWithMap();
};