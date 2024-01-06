#pragma once

#include <vector>
#include "Tile.h"

class Board {
public:
    Board();

    ~Board();

    const std::vector<Tile> &operator[](size_t i) const;
    std::vector<Tile> &operator[](size_t i);

private:
    std::vector<std::vector<Tile>> board;
};
