#pragma once
#include "grid.h"
#include "player.h"

class Game
{
    private:
        std::vector<Position> save;
        int savedRow;
        int savedCol;
    public:
        Grid grid = Grid();
        Player player;
        Game();
        Game(int row, int col);
        void Update();
        void Draw();

        void Delay(double interval);

        void Jump();

        void MoveLeftOrRight();

        void InClassDrawing();

        void MoveDown();

        void Move(int x, int y);
        void ManageGame();
        void PrintPlayer();
        
        bool CheckUpperWallCollision();
        bool CheckLowerWallCollision();

        bool CheckCollisionWithWalls();
        bool CheckCollisionWithMap();
};