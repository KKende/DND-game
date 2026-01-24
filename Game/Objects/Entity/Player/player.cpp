#include "player.hpp"

Player::Player(int health, int max_health, std::string name, std::string description) 
: Entity(health, max_health, name, description) {
    this->set_id(Id::PLAYER);
};

std::vector<Object*> Player::get_inventory() {
    return this-> _inventory;
}

void Player::delete_inventory() {
    for(Object* &item: this->_inventory) {
        delete item;
    }
    this->_inventory.clear();
}