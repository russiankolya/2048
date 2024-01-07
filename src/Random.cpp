#include "Random.h"
#include "Board.h"
#include <chrono>
#include <vector>

Random::Random() {
    generator.seed(std::chrono::steady_clock::now().time_since_epoch().count());
}

Random::~Random() = default;

Tile *Random::SelectRandomTile(Board &board) {
    std::vector<Tile *> emptyTiles;
    for (size_t i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j].GetValue() == 0) {
                emptyTiles.push_back(&board[i][j]);
            }
        }
    }

    if (emptyTiles.empty()) {
        return nullptr;
    }

    std::uniform_int_distribution<size_t> distribution(0, emptyTiles.size() - 1);
    return emptyTiles[distribution(generator)];
}

void Random::FillRandomTile(Board &board) {
    Tile *tile = SelectRandomTile(board);

    std::uniform_int_distribution<> distribution(0, 9);
    if (distribution(generator) == 0) {
        tile->SetValue(4);
    } else {
        tile->SetValue(2);
    }
}