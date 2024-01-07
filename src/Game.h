#pragma once

#include "Tile.h"
#include "Board.h"
#include "Random.h"

class Game {
public:
    Game();

    ~Game();

    Board& data();

    bool MoveLeft();

    bool MoveUp();

    bool MoveRight();

    bool MoveDown();

    void GenerateTile();

private:
    Board board{};
    Random random{};
};
