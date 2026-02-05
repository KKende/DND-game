#include "player.hpp"

Player::Player(int x, int y, int health, int max_health, std::string name, std::string description) 
: Entity(x, y, health, max_health, name, description) {
    this->set_id(Id::PLAYER);
};

std::vector<Object*> &Player::get_inventory() {
    return this-> _inventory;
}

void Player::delete_inventory() {
    for(Object* &item: this->_inventory) {
        delete item;
    }
    this->_inventory.clear();
}

Player::~Player() {
    this->delete_inventory();
}