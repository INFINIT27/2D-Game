#include "player.h"

Player::Player()
{
    this->col = 0;
    this->row = 0;
    tiles = InitialziePlayerTiles();
}

Player::Player(int row, int col)
{
    this->col = col;
    this->row = row;
    tiles = InitialziePlayerTiles();
}

std::vector<Position> Player::InitialziePlayerTiles()
{
    std::vector<Position> tiles;

    for(int i = row; i < row + length; i++) 
    {
        for(int j = col; j < col + length; j++)
        {
            tiles.push_back(Position(i, j));
        }
    }

    return tiles;
}

std::vector<Position> Player::GetPlayerTiles() {
    return this->tiles;
}

void Player::SetPlayerTiles(std::vector<Position> newTiles)
{
    this->tiles = newTiles;
}

void Player::Move(int x, int y) 
{
    row += x;
    col += y;
    tiles = InitialziePlayerTiles();
}

void Player::PrintTiles()
{
    for(Position tile : tiles)
    {
        std::cout << tile.row << " " << tile.col << std::endl;
    }
}

Position Player::GetLowestPosition()
{
    Position lowest = tiles[0];

    std::vector<Position> lower;

    for(Position pos : tiles) 
    {
        if(pos.row > lowest.row)
        {
            lowest = pos;
            lower.empty();
            lower.push_back(lowest);
        }
        if(pos.row == lowest.row)
        {
            lower.push_back(pos);
        }

    }

    return lowest;
}

std::vector<Position> Player::GetLowestPositionVector()
{
    Position lowest = tiles[0];

    std::vector<Position> lower;

    for(Position pos : tiles) 
    {
        if(pos.row > lowest.row)
        {
            lowest = pos;
            lower.empty();
            lower.push_back(lowest);
        }
        if(pos.row == lowest.row)
        {
            lower.push_back(pos);
        }

    }

    return lower;
}

Position Player::GetHighestPosition()
{
    Position highest = tiles[0];

    for(Position pos : tiles) 
    {
        if(pos.row < highest.row)
        {
            highest = pos;
        }
    }

    return highest;
}

Position Player::GetLeftMostPosition()
{
    Position left = tiles[0];

    for(Position pos : tiles) 
    {
        if(pos.col < left.col)
        {
            left = pos;
        }
    }

    return left;
}

Position Player::GetRightMostPosition()
{
    Position right = tiles[0];

    for(Position pos : tiles) 
    {
        if(pos.col > right.col)
        {
            right = pos;
        }
    }

    return right;
}

// Accessors and Mutators

int Player::GetRow()
{
    return row;
}

int Player::GetCol()
{
    return col;
}

void Player::SetRow(int newRow)
{
    this->row = newRow;
}

void Player::SetCol(int newCol)
{
    this->col = newCol;
}