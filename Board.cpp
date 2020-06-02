#include "Board.hpp"
using namespace std;

namespace WarGame {
Soldier *&Board::operator[](pair<int, int> location) {
    if (location.first >= board.size() || location.second >= board[location.first].size()) {
        throw invalid_argument("You cannot set soldier outside the board size");
    }
    return board[location.first][location.second];
}
Soldier *Board::operator[](pair<int, int> location) const {
    if (location.first >= board.size() || location.second >= board[location.first].size()) {
        throw invalid_argument("You cannot set soldier the board size");
    }
    return board[location.first][location.second];
}
void Board::move(uint player_number, pair<int, int> source, MoveDIR direction) {
    Soldier *soldier = board[source.first][source.second];
    if (soldier == nullptr) {
        throw invalid_argument("soldier not found on this source");
    }
    if (soldier->getPlayerNum() != player_number) {
        throw invalid_argument("this is not your soldier");
    }
    pair<int, int> target = source;
    switch (direction) {
    case MoveDIR::Up:
        target.first = source.first + 1;
        break;
    case MoveDIR::Down:
        target.first = source.first - 1;
        break;
    case MoveDIR::Left:
        target.second = source.second - 1;
        break;
    case MoveDIR::Right:
        target.second = source.second + 1;
        break;

    default:
        break;
    }
    if (target.first >= board.size() || target.second >= board[target.first].size()) {
        throw invalid_argument("You cannot move outside the board size");
    }
    if (board[target.first][target.second] != nullptr) {
        throw invalid_argument("There is already a Soldier in target location!");
    }

    board[target.first][target.second] = soldier;
    board[source.first][source.second] = nullptr;
    soldier->action(board, target);
}
bool Board::has_soldiers(uint player_number) const {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] != nullptr) {
                if (board[i][j]->getPlayerNum() == player_number) {
                    return true;
                }
            }
        }
    }
    return false;
}
} // namespace WarGame