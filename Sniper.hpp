#pragma once
#include "Soldier.hpp"
class Sniper : public Soldier {
private:
    static const int INIT_HP = 100;
    static const uint DAMAGE = 50;

public:
    Sniper(){};
    Sniper(uint num) {
        player_num = num;
        type = FOOT_SOLDIER;
        hp = INIT_HP;
        damage = DAMAGE;
    };
    ~Sniper(){};
    void action(vector<vector<Soldier *>> &board, pair<int, int> location);
    const uint getInitHp() const;
};