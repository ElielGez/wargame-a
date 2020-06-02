#pragma once
#include "Paramedic.hpp"
class ParamedicCommander : public Paramedic {
private:
    static const int INIT_HP = 200;
    static const uint DAMAGE = 0; // 0 means he cannot damaged , so he can heal full

public:
    ParamedicCommander(){};
    ParamedicCommander(uint num) {
        player_num = num;
        type = FOOT_COMMANDER;
        hp = INIT_HP;
        damage = DAMAGE;
    };
    ~ParamedicCommander(){};
    void action(vector<vector<Soldier *>> &board, pair<int, int> location);
    const uint getInitHp() const;
};