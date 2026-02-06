#pragma once
#include "../object.hpp"

class Weapon;

class Entity : public Object {
int _y;
int _x;
int _health;
int _max_health;
Weapon* _hands;

public:
Entity(int x, int y, int max_health, std::string name, std::string description);

int get_y();
int get_x();
int get_health();
int get_max_health();
Weapon* get_weapon();

void set_cordinates(int x, int y);
void set_health(int health);
void set_max_health(int max_health);
void set_hand_slot(Weapon *weapon);
void delte_hands();


virtual ~Entity() override;
};