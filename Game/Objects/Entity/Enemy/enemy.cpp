#include "enemy.hpp"

Enemy::Enemy(int x, int y, int max_health, std::string name, std::string description, int bounty, int max_attack_ready) : Entity(x, y, max_health, name, description, max_attack_ready), _bounty(bounty) {
    this->set_id(Id::ENEMY);
    this->set_class(Enemy_class::Enemy);
};

int Enemy::get_bounty() {
    return this->_bounty;
}

void Enemy::set_class(Enemy_class new_class) {
    this->_class = new_class;
}

void Enemy::set_bounty(int bounty) {
    this->_bounty = bounty;
}
