#pragma once
#include "../object.hpp"

class Weapon{};

class Entity : public Object {
int _health;
int _max_health;
Weapon _hands;

public:
Entity(int health, int max_health, std::string name, std::string description);

int get_health();
int get_max_health();
Weapon get_weapon();

void set_health(int health);
void set_max_health(int max_health);
void set_hand_slot(Weapon weapon);


virtual ~Entity() override = default;
};