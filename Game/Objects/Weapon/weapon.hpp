#pragma once
#include <iostream>
#include "../object.hpp"

enum class Weapon_rarety {
    COMMON,
    UNCOMMON,
    RARE,
    EPIC,
    LEGENDARY
};

enum class Weapon_condition {
    BROKEN,
    POOR,
    FAIR,
    FINE,
    SHARP
};

class Weapon : public Object {
    Weapon_rarety _rarety;
    Weapon_condition _condition;
    int _damage;
    int _durability;
public:
    Weapon(std::string name, std::string description, Weapon_rarety rarety, Weapon_condition condition, int damage, int durability);

    int get_damage();
    int get_durability();
    Weapon_rarety get_rarety();
    Weapon_condition get_condition();

    void set_condition(Weapon_condition condition);
    void set_rarety(Weapon_rarety rarety);
    void set_damage(int damage);
    void set_durability(int durability);

    std::string get_str_rarety();
    std::string get_str_condition();
    std::string get_full_name();

    ~Weapon() override = default;
};