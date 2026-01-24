#include "entity.hpp"

Entity::Entity(int health, int max_health, std::string name, std::string description) 
: _health(health), _max_health(max_health), Object(name, description) {
    this->set_id(Id::ENTITY);
};

int Entity::get_health() {
    return this->_health;
}
int Entity::get_max_health() {
    return this->_max_health;
}
Weapon Entity::get_weapon() {
    return this->_hands;
}

void Entity::set_health(int health) {
    this->_health = health;
}
void Entity::set_max_health(int max_health) {
    this->_max_health = _max_health;
}
void Entity::set_hand_slot(Weapon weapon) {
    this->_hands = weapon;
}