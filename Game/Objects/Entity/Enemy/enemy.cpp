#include "enemy.hpp"

Enemy::Enemy(int x, int y, int max_health, std::string name, std::string description, int bounty) : Entity(x, y, max_health, name, description), _bounty(bounty) {
    Enemy::set_id(Id::ENEMY);
};

int Enemy::get_bounty() {
    return this->_bounty;
}

void Enemy::set_bounty(int bounty) {
    this->_bounty = bounty;
}
