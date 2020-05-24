#pragma once
#include <iostream>
class Soldier {
public:
    uint player_num;
    Soldier(){};
    Soldier(uint num) : player_num(num){};
    ~Soldier(){};
};