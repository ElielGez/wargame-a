#pragma once
#include "Soldier.hpp"
class Paramedic : public Soldier {
private:
    static const int INIT_HP = 100;
    static const uint DAMAGE = 0; // 0 means he cannot damaged , so he can heal full

public:
    Paramedic(){};
    Paramedic(uint num) {
        player_num = num;
        type = FOOT_SOLDIER;
        hp = INIT_HP;
        damage = DAMAGE;
    };
    ~Paramedic(){};
    void action(vector<vector<Soldier *>> &board, pair<int, int> location);
    const uint getInitHp() const;
};