#pragma once
#include "Sniper.hpp"
class SniperCommander : public Sniper {
private:
    static const int INIT_HP = 120;
    static const uint DAMAGE = 100;

public:
    SniperCommander(){};
    SniperCommander(uint num) {
        player_num = num;
        type = FOOT_COMMANDER;
        hp = INIT_HP;
        damage = DAMAGE;
    };
    ~SniperCommander(){};
    void action(vector<vector<Soldier *>> &board, pair<int, int> location);
    const uint getInitHp() const;
};