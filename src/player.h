#pragma once
#include "grid.h"

class Player 
{

    private:
        int row;
        int col;
        std::vector<Position> tiles;
        int length = 2;
    public:
        Player();
        Player(int row, int col);
        std::vector<Position> InitialziePlayerTiles();
        std::vector<Position> GetPlayerTiles();
        void Move(int x, int y);
        void PrintTiles();
        Position GetLowestPosition();
        Position GetHighestPosition();
        Position GetLeftMostPosition();
        Position GetRightMostPosition();
};