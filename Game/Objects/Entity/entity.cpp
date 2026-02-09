#include "entity.hpp"
#include "../Weapon/weapon.hpp"

Entity::Entity(int x, int y, int max_health, std::string name, std::string description, int max_attack_ready): _x(x), _y(y) , _max_health(max_health), _max_attack_ready(max_attack_ready) ,Object(name, description) {
    this->_health = this->_max_health;
    this->_attack_ready = this->_max_attack_ready;
    this->set_hand_slot(new Weapon("fists", "your hands", Weapon_rarety::COMMON, 10, 30)) ;
    this->set_id(Id::ENTITY);
};

int Entity::get_attack_ready() {
    return this->_attack_ready;
}
int Entity::get_max_attack_ready() {
    return this->_max_attack_ready;
}
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
Weapon* Entity::get_weapon() {
    return this->_hands;
}

void Entity::change_attack_ready(int amount) {
    this->_attack_ready += amount;
    if(this->_attack_ready > this->_max_attack_ready) this->_attack_ready = this->_max_attack_ready;
}
void Entity::change_health(int amaount) {
    this->_health += amaount;
    if(this->_health > this->_max_health) this->_health = this->_max_health;
}
void Entity::set_attack_ready(int number) {
    this->_attack_ready = number;
}
void Entity::set_max_attack_ready(int number) {
    this->_max_attack_ready = number;
}
void Entity::delte_hands() {
    delete this->_hands;
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
void Entity::set_hand_slot(Weapon* weapon) {
    this->_hands = weapon;
}

Entity::~Entity() {
    this->delte_hands();
}