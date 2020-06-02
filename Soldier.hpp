#pragma once
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

typedef enum Type {
    FOOT_SOLDIER,
    FOOT_COMMANDER,
    SNIPER,
    SNIPER_COMMANDER,
    PARAMEDIC,
    PARAMEDIC_COMMANDER
} Type;

class Soldier {
protected:
public:
    uint player_num;
    Type type;
    int hp;
    uint damage;
    Soldier(){};
    virtual ~Soldier(){};
    virtual void action(vector<vector<Soldier *>> &board, pair<int, int> location) = 0;
    virtual const uint getInitHp() const = 0;

    Type getType() { return type; }

    uint getPlayerNum() { return player_num; }

    uint getEnemyPlayerNum();
    pair<Soldier *, pair<int, int>> getClosestEnemy(vector<vector<Soldier *>> &board, pair<int, int> source, uint enemy_player_num) const;

    //need to delete
    pair<int, int> getClosestEnemyP(vector<vector<Soldier *>> &board, pair<int, int> source, uint enemy_player_num) const {
        // Soldier *closest_soldier = nullptr;
        pair<int, int> p = {0, 0};
        double min_distance = numeric_limits<double>::max();
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != nullptr) {
                    if (board[i][j]->getPlayerNum() == enemy_player_num) {
                        double d = sqrt(pow(source.first - source.second, 2) +
                                        pow(i - j, 2) * 1.0);
                        if (d < min_distance) {
                            min_distance = d;
                            p = {i, j};
                            // closest_soldier = board[i][j];
                        }
                    }
                }
            }
        }
        return p;
    }
};