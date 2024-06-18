#pragma once
#include <vector>
#include <raylib.h>
#include "colors.h"
#include "position.h"
#include "constants.h"
#include <iostream>

class Grid {

private:

    const int rows = ROWS;
    const int cols = COLS;
    const int length = LENGTH;
    std::vector<Color> colors;

public:
    int grid[ROWS][COLS];
    Grid();
    void Initialize();
    void Draw();
    void Update(std::vector<Position> player, int colorIndex);
    void PrintGrid();
    int GetRows();
    int GetCols();
};