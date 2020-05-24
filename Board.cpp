#include "Board.hpp"
using namespace std;

namespace WarGame {
Soldier *&Board::operator[](pair<int, int> location) {
    return board[location.first][location.second];
}
Soldier *Board::operator[](pair<int, int> location) const {
    return board[location.first][location.second];
}
void Board::move(uint player_number, pair<int, int> source, MoveDIR direction) {
}
bool Board::has_soldiers(uint player_number) const {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] != nullptr) {
                if (board[i][j]->player_num == player_number) {
                    return true;
                }
            }
        }
    }
    return false;
}
} // namespace WarGame