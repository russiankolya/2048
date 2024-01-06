#include "Board.h"

#define SIZE 4
#define DEFAULT_COLOR "#000000"

Board::Board() {
    board.assign(SIZE, std::vector<Tile>(SIZE));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = Tile(0, DEFAULT_COLOR);
        }
    }
}

Board::~Board() = default;

std::vector<Tile> &Board::operator[](int i) {
    return board[i];
}

const std::vector<Tile> &Board::operator[](int i) const {
    return board[i];
}