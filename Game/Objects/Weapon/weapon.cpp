#include "weapon.hpp"

Weapon::Weapon(std::string name, std::string description, Weapon_rarety rarety, int damage, int durability) 
: Object(name, description), _rarety(rarety), _damage(damage), _durability(durability) {
    if(this->_durability > 90){
        if(_durability > 100)this->_durability = 100;
        set_condition(Weapon_condition::SHARP);
    }
    else if(this->_durability > 80) set_condition(Weapon_condition::FINE);
    else if(this->_durability > 60) set_condition(Weapon_condition::FAIR);
    else if(this->_durability > 40) set_condition(Weapon_condition::POOR);
    else set_condition(Weapon_condition::BROKEN);
    this->set_id(Id::WEAPON);
}

int Weapon::get_real_damage() {
    int rarety_boost;
    int condition_boost;
    switch(this->_rarety) {
        case Weapon_rarety::COMMON:
            rarety_boost = 0;
        case Weapon_rarety::UNCOMMON:
            rarety_boost = this->_damage % 4;
        case Weapon_rarety::RARE:
            rarety_boost = this->_damage % 3;
        case Weapon_rarety::EPIC:
            rarety_boost = this->_damage % 2;
        case Weapon_rarety::LEGENDARY:
            rarety_boost = this->_damage;
        default: rarety_boost = 0 ;
        }
    switch(this->_condition) {
        case Weapon_condition::BROKEN:
            condition_boost = 0;
        case Weapon_condition::POOR:
            condition_boost = this->_damage % 4;
        case Weapon_condition::FAIR:
            condition_boost = this->_damage % 3;
        case Weapon_condition::FINE:
            condition_boost = this->_damage % 2;
        case Weapon_condition::SHARP:
            condition_boost = this->_damage;
        default: condition_boost = 0 ;
    }
    return this->_damage + condition_boost + rarety_boost;
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