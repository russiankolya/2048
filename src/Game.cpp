#include "Game.h"

Game::Game() = default;

Game::~Game() = default;

void Game::MoveUp() {
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
                }
                if (board[i][j].GetValue() == board[k][j].GetValue()) {
                    board[k][j].SetValue(board[i][j].GetValue() + board[k][j].GetValue());
                    board[i][j].SetValue(0);
                    board[i][j].SetColor("#f1f1f1");
                    is_merged = true;
                    break;
                }
            }
            if (is_merged) {
                continue;
            }
            if (i != new_pos) {
                board[new_pos][j].SetValue(board[i][j].GetValue());
                board[new_pos][j].SetColor("white");
                board[i][j].SetValue(0);
                board[i][j].SetColor("#f1f1f1");
            }
        }
    }
}