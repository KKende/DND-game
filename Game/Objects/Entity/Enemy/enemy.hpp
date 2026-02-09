#pragma once
#include <iostream>
#include "../entity.hpp"

enum class Enemy_class{
    Enemy,
    Ork
};

class Enemy : public Entity {
    Enemy_class _class;
    int _bounty;
public:
    Enemy(int x, int y, int max_health, std::string name, std::string description, int bounty, int max_attack_ready);

    int get_bounty();
    Enemy_class get_class();

    void set_class(Enemy_class new_class);
    void set_bounty(int bounty);

    virtual ~Enemy() override = default;
};