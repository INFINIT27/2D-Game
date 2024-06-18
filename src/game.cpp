#include "game.h"

Game::Game()
{
    player = Player();
}

Game::Game(int row, int col)
{
    player = Player(row, col);
}

void Game::Update()
{
    grid.Update(player.GetPlayerTiles(), 3);
}

void Game::Draw()
{
    grid.Draw();
}

void Game::Move(int x, int y)
{
    player.Move(x, y);
    if(CheckCollisionWithWalls() || CheckCollisionWithMap()) {
        if(x == 0) player.Move(x, (-1)*y);
        else player.Move((-1)*x, y);
    }
}

void Game::ManageGame() 
{
    if(IsKeyDown(KEY_UP)) Move(-1, 0);
    if(IsKeyDown(KEY_DOWN)) Move(1, 0);
    if(IsKeyDown(KEY_LEFT)) Move(0, -1);
    if(IsKeyDown(KEY_RIGHT)) Move(0, 1);
}

void Game::PrintPlayer() 
{
    player.PrintTiles();
}

bool Game::CheckCollisionWithWalls()
{
    Position left = player.GetLeftMostPosition();
    Position right = player.GetRightMostPosition();
    Position highest = player.GetHighestPosition();
    Position lowest = player.GetLowestPosition();

    int rows = grid.GetRows();
    int cols = grid.GetCols();

    if(
        left.col < 0 ||
        right.col > cols - 1 ||
        highest.row < 0 ||
        lowest.row > rows - 1
    )
    {
        return true;
    }
    return false;
}

bool Game::CheckCollisionWithMap()
{
    for(Position pos : player.GetPlayerTiles())
    {
        if(grid.grid[pos.row][pos.col] == 6)
        {
            return true;
        }
    }

    return false;
}