#include "grid.h"
#include "map.h"

Grid::Grid()
{
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize() 
{
    // Define an empty canvas
    for(int row = 0; row < rows; row++) 
    {
        for(int col = 0; col < cols; col++)
        {
            grid[row][col] = BACKGROUND_COLOR;
        }
    }

    // Define the map
    Map map = Map();
    for(Position pos : map.GetMapLayout())
    {
        grid[pos.row][pos.col] = MAP_COLOR;
    }
}

void Grid::Draw()
{
    for(int row = 0; row < rows; row++) 
    {
        for(int col = 0; col < cols; col++)
        {
            DrawRectangle(col * length, row * length, length, length, BLACK);
            DrawRectangle(col * length + 1, row * length + 1, length - 1, length - 1, colors[grid[row][col]]);
            // DrawRectangle(col * length, row * length, length, length, colors[grid[row][col]]);
        }
    }
}

void Grid::Update(std::vector<Position> player, int colorIndex)
{
    for(Position index : player)
    {
        grid[index.row][index.col] = colorIndex;
    }
}

void Grid::PrintGrid()
{
    for(int row = 0; row < rows; row++) 
    {
        for(int col = 0; col < cols; col++)
        {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

int Grid::GetRows()
{
    return rows;
}

int Grid::GetCols()
{
    return cols;
}
