#include "entity.hpp"

Entity::Entity(int x, int y, int health, int max_health, std::string name, std::string description): _x(x), _y(y),
 _health(health), _max_health(max_health), Object(name, description) {
    this->set_id(Id::ENTITY);
};

int Entity::get_x() {
    return this->_x;
}
int Entity::get_y() {
    return this->_y;
}
int Entity::get_health() {
    return this->_health;
}
int Entity::get_max_health() {
    return this->_max_health;
}
Weapon Entity::get_weapon() {
    return this->_hands;
}

void Entity::set_cordinates(int x, int y) {
    this->_x = x;
    this->_y = y; 
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