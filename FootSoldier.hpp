#pragma once
#include "Soldier.hpp"
class FootSoldier : public Soldier {

public:
    FootSoldier(){};
    FootSoldier(uint num) : Soldier(num){};
    ~FootSoldier(){};
};