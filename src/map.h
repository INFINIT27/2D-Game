#pragma once
#include <vector>
#include <raylib.h>
#include "position.h"

class Map {

    private:
        std::vector<Position> mapLayout;

    public:
        Map();
        std::vector<Position> Initialize();
        std::vector<Position> GetMapLayout();

};