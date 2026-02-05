#pragma once
#include <iostream>
#include <../entity.hpp>

class Enemy : public Entity {
    int bounty;
public:
    Enemy(int x, int y, int health, int max_health, std::string name, std::string description);
    ~Enemy();
};