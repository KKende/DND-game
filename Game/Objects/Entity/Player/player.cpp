#include "player.hpp"

Player::Player(int x, int y, int max_health, std::string name, std::string description, int money, int max_attack_ready) 
: Entity(x, y, max_health, name, description, max_attack_ready), _money(money) {
    this->set_id(Id::PLAYER);
};

std::vector<Object*> &Player::get_inventory() {
    return this-> _inventory;
}

int& Player::get_money() {
    return this->_money;
}

void Player::delete_inventory() {
    for(Object* &item: this->_inventory) {
        delete item;
    }
    this->_inventory.clear();
}

void Player::add_money_amaount(int amount) {
    this->_money += amount;
}

Player::~Player() {
    this->delete_inventory();
}