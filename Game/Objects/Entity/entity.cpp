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

std::vector<std::string> Entity::get_skin() {
    std::string row1 =  "      _____      ";
    std::string row2 =  "     /     \\     ";
    std::string row3 =  "    |___ ___|    ";
    std::string row4 =  "    |<O> <O>|    ";
    std::string row5 =  "     \\  V  /     ";
    std::string row6 =  "  ___/|_-_|\\___  ";
    std::string row7 =  " /   \\ ___ /   \\ ";
    std::string row8 =  "|       |       | ";
    std::string row9 =  "|  |    |    |  | ";
    std::string row10 = "|  |    |    |  |";
    std::string row11 = "|  |    |    |  |";
    std::string row12 = "|  |    |    |  |";
    std::string row13 = "|  |    |    |  |";
    std::string row14 = "|  |____|____|  |";
    std::string row15 = "|  |____|____|  |";
    std::string row16 = "|  |         |  |";
    std::string row17 = " \\ |    |    | / ";
    std::string row18 = "   |    |    |   ";
    std::string row19 = "   |    |    |   ";
    std::string row20 = "   |    |    |   ";
    std::string row21 = "   |    |    |   ";
    std::string row22 = "   |    |    |   ";
    std::string row23 = "   |    ||   |   ";
    std::string row24 = "   |___ | | __|_ ";
    std::string row25 = "   |___|   |____|";
    std::vector<std::string> picture;
    picture.push_back(row1);
    picture.push_back(row2);
    picture.push_back(row3);
    picture.push_back(row4);
    picture.push_back(row5);
    picture.push_back(row6);
    picture.push_back(row7);
    picture.push_back(row8);
    picture.push_back(row9);
    picture.push_back(row10);
    picture.push_back(row11);
    picture.push_back(row12);
    picture.push_back(row13);
    picture.push_back(row14);
    picture.push_back(row15);
    picture.push_back(row16);
    picture.push_back(row17);
    picture.push_back(row18);
    picture.push_back(row19);
    picture.push_back(row20);
    picture.push_back(row21);
    picture.push_back(row22);
    picture.push_back(row23);
    picture.push_back(row24);
    picture.push_back(row25);
    return picture;
}