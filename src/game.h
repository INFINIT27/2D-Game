#pragma once
#include "grid.h"
#include "player.h"
#include "prize.h"

class Game
{
    private:
        std::vector<Position> save;
        int savedRow;
        int savedCol;
    public:
        Grid grid = Grid();
        Player player;
        Prize prize;
        Game();
        Game(int row, int col);
        void Update();
        void Draw();

        void Delay(double interval);

        void Jump();

        void MoveLeftOrRight();

        void InClassDrawing();

        void MoveDown();

        bool GameOver();
        void Reset();
        
        void Move(int x, int y);
        void ManageGame();
        void PrintPlayer();
        
        bool CheckCollisionWithPrize();
        bool CheckUpperWallCollision();
        bool CheckLowerWallCollision();

        bool CheckCollisionWithWalls();
        bool CheckCollisionWithMap();
};