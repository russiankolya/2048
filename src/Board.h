#pragma once

#include <vector>
#include "Tile.h"

class Board {
public:
    Board();

    ~Board();

    const std::vector<Tile> &operator[](int i) const;
    std::vector<Tile> &operator[](int i);

private:
    std::vector<std::vector<Tile>> board;
};
