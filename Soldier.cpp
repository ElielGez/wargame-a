#include "Soldier.hpp"

pair<Soldier *, pair<int, int>> Soldier::getClosestEnemy(vector<vector<Soldier *>> &board, pair<int, int> source, uint enemy_player_num) const {
    Soldier *closest_soldier = nullptr;
    pair<int, int> location = {-1, -1};
    double min_distance = numeric_limits<double>::max();
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] != nullptr) {
                if (board[i][j]->getPlayerNum() == enemy_player_num) {
                    double d = sqrt(pow(source.first - source.second, 2) +
                                    pow(i - j, 2) * 1.0);
                    if (d < min_distance) {
                        min_distance = d;
                        closest_soldier = board[i][j];
                        location = {i, j};
                    }
                }
            }
        }
    }
    return {closest_soldier, location};
}
uint Soldier::getEnemyPlayerNum() {
    if (player_num == 1)
        return 2;
    else
        return 1;
}