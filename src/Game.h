#pragma once

#include "Tile.h"
#include "Board.h"

class Game {
public:
    Game();

    ~Game();

    Board& data();

    Board data() const;

    void MoveLeft();

    void MoveUp();

    void MoveRight();

    void MoveDown();

private:
    Board board;
};
