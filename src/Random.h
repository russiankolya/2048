#pragma once

#include <random>
#include "Tile.h"
#include "Board.h"

class Random {
public:
    Random();

    ~Random();

    Tile *SelectRandomTile(Board &board);

    void FillRandomTile(Board &board);

private:
    std::mt19937 generator;
};
