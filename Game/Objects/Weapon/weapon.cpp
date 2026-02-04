#include "weapon.hpp"

Weapon::Weapon(std::string name, std::string description, Weapon_rarety rarety, Weapon_condition condition, int damage, int durability) 
: Object(name, description), _rarety(rarety), _condition(condition), _damage(damage), _durability(durability) {
    this->set_id(Id::WEAPON);
}

int Weapon::get_damage() {
    return this->_damage;
}
int Weapon::get_durability() {
    return this->_durability;
}
Weapon_rarety Weapon::get_rarety() {
    return this->_rarety;
}
Weapon_condition Weapon::get_condition() {
    return this->_condition;
}

void Weapon::set_condition(Weapon_condition condition) {
    this->_condition = condition;
}
void Weapon::set_rarety(Weapon_rarety rarety) {
    this->_rarety = rarety;
}
void Weapon::set_damage(int damage) {
    this->_damage = damage;
}
void Weapon::set_durability(int durability) {
    this->_durability = durability;
}

std::string Weapon::get_str_rarety() {
    switch(this->_rarety) {
        case Weapon_rarety::COMMON:
            return "common";
        case Weapon_rarety::UNCOMMON:
            return "uncomon";
        case Weapon_rarety::RARE:
            return "rare";
        case Weapon_rarety::EPIC:
            return "epic";
        case Weapon_rarety::LEGENDARY:
            return "legendary";
        default :
            return "MISSING_RARETY";
    }
}
std::string Weapon::get_str_condition() {
    switch(this->_condition) {
        case Weapon_condition::BROKEN:
            return "broken";
        case Weapon_condition::FAIR:
            return "fair";
        case Weapon_condition::FINE:
            return "fine";
        case Weapon_condition::POOR:
            return "poor";
        case Weapon_condition::SHARP:
            return "sharp";
        default :
            return "MISSING_CONDITION";
    }
}
std::string Weapon::get_full_name() {
    return "A " + this->get_str_rarety() + " " + this->get_str_condition() + " " + this->get_name();
}