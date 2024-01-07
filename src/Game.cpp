#include "Game.h"
#include <set>
#include <utility>

Game::Game() = default;

Game::~Game() = default;

Board &Game::data() {
    return board;
}

bool Game::MoveLeft() {
    bool is_moved = false;

    std::set<std::pair<int, int>> merged;

    for (size_t j = 0; j < board.size(); j++) {
        for (size_t i = 0; i < board.size(); i++) {
            if (board[i][j].GetValue() == 0) {
                continue;
            }
            size_t new_pos = j;
            bool is_merged = false;
            for (int k = static_cast<int>(j) - 1; k >= 0; k--) {
                if (board[i][k].GetValue() == 0) {
                    new_pos = k;
                } else if (board[i][j].GetValue() == board[i][k].GetValue() && !merged.count({i, k})) {
                    board[i][k].SetValue(board[i][j].GetValue() + board[i][k].GetValue());
                    merged.insert({i, k});
                    board[i][j].SetValue(0);
                    is_merged = true;
                    break;
                } else {
                    break;
                }
            }
            if (is_merged) {
                is_moved = true;
                continue;
            }
            if (j != new_pos) {
                is_moved = true;
                board[i][new_pos].SetValue(board[i][j].GetValue());
                board[i][j].SetValue(0);
            }
        }
    }
    return is_moved;
}

bool Game::MoveUp() {
    bool is_moved = false;

    std::set<std::pair<int, int>> merged;

    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board.size(); j++) {
            if (board[i][j].GetValue() == 0) {
                continue;
            }
            size_t new_pos = i;
            bool is_merged = false;
            for (int k = static_cast<int>(i) - 1; k >= 0; k--) {
                if (board[k][j].GetValue() == 0) {
                    new_pos = k;
                } else if (board[i][j].GetValue() == board[k][j].GetValue() && !merged.count({k, j})) {
                    board[k][j].SetValue(board[i][j].GetValue() + board[k][j].GetValue());
                    merged.insert({k, j});
                    board[i][j].SetValue(0);
                    is_merged = true;
                    break;
                } else {
                    break;
                }
            }
            if (is_merged) {
                is_moved = true;
                continue;
            }
            if (i != new_pos) {
                is_moved = true;
                board[new_pos][j].SetValue(board[i][j].GetValue());
                board[i][j].SetValue(0);
            }
        }
    }
    return is_moved;
}

bool Game::MoveRight() {
    bool is_moved = false;

    std::set<std::pair<int, int>> merged;

    for (int j = static_cast<int>(board.size()) - 1; j >= 0; j--) {
        for (size_t i = 0; i < board.size(); i++) {
            if (board[i][j].GetValue() == 0) {
                continue;
            }
            size_t new_pos = j;
            bool is_merged = false;
            for (size_t k = j + 1; k < board.size(); k++) {
                if (board[i][k].GetValue() == 0) {
                    new_pos = k;
                } else if (board[i][j].GetValue() == board[i][k].GetValue()  && !merged.count({i, k})) {
                    board[i][k].SetValue(board[i][j].GetValue() + board[i][k].GetValue());
                    merged.insert({i, k});
                    board[i][j].SetValue(0);
                    is_merged = true;
                    break;
                } else {
                    break;
                }
            }
            if (is_merged) {
                is_moved = true;
                continue;
            }
            if (j != new_pos) {
                is_moved = true;
                board[i][new_pos].SetValue(board[i][j].GetValue());
                board[i][j].SetValue(0);
            }
        }
    }
    return is_moved;
}

bool Game::MoveDown() {
    bool is_moved = false;

    std::set<std::pair<int, int>> merged;

    for (int i = static_cast<int>(board.size()) - 1; i >= 0; i--) {
        for (size_t j = 0; j < board.size(); j++) {
            if (board[i][j].GetValue() == 0) {
                continue;
            }
            size_t new_pos = i;
            bool is_merged = false;
            for (size_t k = i + 1; k < board.size(); k++) {
                if (board[k][j].GetValue() == 0) {
                    new_pos = k;
                } else if (board[i][j].GetValue() == board[k][j].GetValue()  && !merged.count({k, j})) {
                    board[k][j].SetValue(board[i][j].GetValue() + board[k][j].GetValue());
                    merged.insert({k, j});
                    board[i][j].SetValue(0);
                    is_merged = true;
                    break;
                } else {
                    break;
                }
            }
            if (is_merged) {
                is_moved = true;
                continue;
            }
            if (i != new_pos) {
                is_moved = true;
                board[new_pos][j].SetValue(board[i][j].GetValue());
                board[i][j].SetValue(0);
            }
        }
    }
    return is_moved;
}

void Game::GenerateTile() {
    random.FillRandomTile(board);
}