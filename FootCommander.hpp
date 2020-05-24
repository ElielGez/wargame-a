#pragma once
#include "FootSoldier.hpp"
class FootCommander : public FootSoldier {

public:
    FootCommander(){};
    FootCommander(uint num) : FootSoldier(num){};
    ~FootCommander(){};
};