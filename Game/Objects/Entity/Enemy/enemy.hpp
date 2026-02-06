#pragma once
#include <iostream>
#include "../entity.hpp"

class Enemy : public Entity {
    int _bounty;
public:
    Enemy(int x, int y, int max_health, std::string name, std::string description, int bounty);

    int get_bounty();

    void set_bounty(int bounty);

    virtual ~Enemy() override = default;
};