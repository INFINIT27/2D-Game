#include "map.h"
#include "grid.h"

Map::Map()
{
    mapLayout = Initialize();
}

std::vector<Position> Map::Initialize()
{
    std::vector<Position> map;
    
    // Bottom of the map.
    for(int i = 45; i < ROWS; i++) 
    {
        for(int j = 0; j < COLS; j++)
        {
            map.push_back(Position(i, j));
        }    
    }

    // Wall 1
    for(int i = 30; i < 32; i++) 
    {
        for(int j = 30; j < 45; j++)
        {
            map.push_back(Position(i, j));
        }
    }

    // Wall 2
    for(int i = 25; i < 27; i++) 
    {
        for(int j = 60; j < 75; j++)
        {
            map.push_back(Position(i, j));
        }
    }

    // Wall 3   
    for(int i = 27; i < 45; i++) 
    {
        for(int j = 73; j < 75; j++)
        {
            map.push_back(Position(i, j));
        }
    }

    // Wall 4   
    for(int i = 35; i < 37; i++) 
    {
        for(int j = 90; j < COLS; j++)
        {
            map.push_back(Position(i, j));
        }
    }

    // Wall 5   
    for(int i = 37; i < 43; i++) 
    {
        for(int j = 90; j < 92; j++)
        {
            map.push_back(Position(i, j));
        }
    }

    return map;
}

std::vector<Position> Map::GetMapLayout()
{
    return mapLayout;
}