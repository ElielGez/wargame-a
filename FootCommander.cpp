#include "FootCommander.hpp"

void FootCommander::action(vector<vector<Soldier *>> &board, pair<int, int> location) {
    FootSoldier::action(board, location); // super
    //here needs to come loop on every Foot Soldier and call action
}
const uint FootCommander::getInitHp() const {
    return INIT_HP;
}