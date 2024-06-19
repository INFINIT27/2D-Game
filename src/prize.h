#pragma once
#include "constants.h"
#include <vector>
#include <map>
#include "position.h"

class Prize 
{
    private:
        int total = 3;
        int color = PRIZE_COLOR;
        std::vector<std::vector<Position>> locations;
    public:
        Prize();
        void Initialize();
        int Size();
        int MaxScore();
        std::vector<std::vector<Position>> GetPrizeLocations();
        void RemovePrize(Position pos);
};
