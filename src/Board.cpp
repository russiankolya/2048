#include "Board.h"

#define SIZE 4

Board::Board() {
    board.assign(SIZE, std::vector<Tile>(SIZE));
    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            board[i][j] = Tile();
            board[i][j].SetValue(0);
        }
    }
}

Board::~Board() = default;

size_t Board::size() const {
    return board.size();
}

std::vector<Tile> &Board::operator[](size_t i) {
    return board[i];
}

const std::vector<Tile> &Board::operator[](size_t i) const {
    return board[i];
}