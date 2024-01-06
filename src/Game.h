#pragma once

#include "Tile.h"
#include "Board.h"

class Game {
public:
    Game();

    ~Game();

    void MoveLeft();

    void MoveUp();

    void MoveRight();

    void MoveDown();

    void UpdateTable();

private:
    Board board;
};
