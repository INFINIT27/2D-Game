#include "prize.h"

Prize::Prize()
{
    Initialize();
}

void Prize::Initialize()
{
    // Prize 1
    std::vector<Position> prizeOne;
    prizeOne.push_back(Position(7, 98));
    prizeOne.push_back(Position(7, 99));
    prizeOne.push_back(Position(8, 98));
    prizeOne.push_back(Position(8, 99));
    locations.push_back(prizeOne);

    // Prize 2
    std::vector<Position> prizeTwo;
    prizeTwo.push_back(Position(23, 4));
    prizeTwo.push_back(Position(23, 5));
    prizeTwo.push_back(Position(24, 4));
    prizeTwo.push_back(Position(24, 5));
    locations.push_back(prizeTwo);

    // Prize 2
    std::vector<Position> prizeThree;
    prizeThree.push_back(Position(37, 92));
    prizeThree.push_back(Position(37, 93));
    prizeThree.push_back(Position(38, 92));
    prizeThree.push_back(Position(38, 93));
    locations.push_back(prizeThree);
}

int Prize::Size()
{
    return int(locations.size());
}

int Prize::MaxScore()
{
    return total;
}

std::vector<std::vector<Position>> Prize::GetPrizeLocations()
{
    return locations;
}

void Prize::RemovePrize(Position pos)
{
    int index = 0;
    bool found = false;
    for(int i = 0; i < int(locations.size()); i++)
    {
        for(Position currPos : locations[i])
        {
            if(pos.col == currPos.col && pos.row == currPos.row)
            {
                index = i;
                found = true;
            }
            if(found) break;
        }
        if(found) break;
    }

    if(found) locations.erase(locations.begin() + index);
}