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
    grid.Update(player.GetPlayerTiles(), PLAYER_COLOR);
}

void Game::Draw()
{
    grid.Draw();
}

/**
 * Delay the execution of a program for a given interval of time.
 */
void Game::Delay(double interval) 
{
    double startTime = GetTime();
    double currTime = GetTime();
    while(currTime - startTime < interval) {
        currTime = GetTime();
    }
}

void Game::Jump()
{
    int count = 0;

    while(!CheckUpperWallCollision() && count < 10)
    {
        Delay(DELTA);
        Move(-1, 0);
        InClassDrawing();
        MoveLeftOrRight();
        count++;
    }
    MoveDown();
}

void Game::MoveLeftOrRight()
{
    if(IsKeyDown(KEY_LEFT)) Move(0, -1);
    if(IsKeyDown(KEY_RIGHT)) Move(0, 1);
}

void Game::InClassDrawing()
{
    if(!WindowShouldClose())
    {
        BeginDrawing();

        Draw();

        EndDrawing();
    }
}

void Game::MoveDown()
{
    while(!CheckLowerWallCollision())
    {
        Delay(DELTA);
        Move(1, 0);
        InClassDrawing();
        MoveLeftOrRight();
    }
}

void Game::Move(int x, int y)
{
    player.Move(x, y);
    if(CheckCollisionWithWalls() || CheckCollisionWithMap()) 
    {
        if(x == 0) player.Move(x, (-1)*y);
        else player.Move((-1)*x, y);
    }
    Update();
}

void Game::ManageGame() 
{
    if(IsKeyDown(KEY_UP))  Jump();

    if(IsKeyDown(KEY_LEFT)) 
    {
        Move(0, -1);
        Delay(DELTA);
    }
    
    if(IsKeyDown(KEY_RIGHT)) 
    {
        Move(0, 1);
        Delay(DELTA);
    }
    MoveDown();
}

void Game::PrintPlayer() 
{
    player.PrintTiles();
}


// -------------------- Collisions ----------------------------------
bool Game::CheckUpperWallCollision()
{
    Position highest = player.GetHighestPosition();

    if(grid.grid[highest.row][highest.col] == MAP_COLOR)
    {
        return true;
    }

    if(highest.row < 0)
    {
        return true;
    }

    return false;
}

bool Game::CheckLowerWallCollision()
{
    Position lowest = player.GetLowestPosition();

    if(lowest.row == ROWS)
    {
        return true;
    }

    if(grid.grid[lowest.row + 1][lowest.col] == MAP_COLOR)
    {
        return true;
    }

    return false;
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
        if(grid.grid[pos.row][pos.col] == MAP_COLOR)
        {
            return true;
        }
    }

    return false;
}
// ---------------------------------------------------