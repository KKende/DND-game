#include "ork.hpp"
#include "../../../Weapon/weapon.hpp"
#include "../../../Weapon/Club/club.hpp"

Ork::Ork(int x, int y) : Enemy(x, y, 50, "Ork", "a lizard like creature, an outcast to the human word.", 100, 20) {
    this->set_attack_ready(0);
    this->set_class(Enemy_class::Ork);
    this->delte_hands();
    this->set_hand_slot(new Club());
};

std::vector<std::string> Ork::get_skin() {
    std::string row1 =  "      _____       ";
    std::string row2 =  "     / ____\\      ";
    std::string row3 =  "    (  [o] [o]    ";
    std::string row4 =  "    |      oo|    ";
    std::string row5 =  "   / \\___ A--A    ";
    std::string row6 =  "  /         \\     ";
    std::string row7 =  " /           \\    ";
    std::string row8 =  "      / .    .|   ";
    std::string row9 =  "|    |        |   ";
    std::string row10 = "|    |         \\  ";
    std::string row11 = "|    |          | ";
    std::string row12 = "|    |      o   | ";
    std::string row13 = "|     | ________/ ";
    std::string row14 = " \\     \\    ___/_ ";
    std::string row15 = " | \\    \\__|_   | ";
    std::string row16 = " |   \\    ___|__| ";
    std::string row17 = " |   | _  \\ / |   ";
    std::string row18 = " |  |_| |_|   |   ";
    std::string row19 = " |   /  /_|\\_ /   ";
    std::string row20 = " |_/    \\_   |    ";
    std::string row21 = " /  <  v  \\  |    ";
    std::string row22 = " |    >   /  |    ";
    std::string row23 = "/  <     /   |    ";
    std::string row24 = "   v  v  |_  |__  ";
    std::string row25 = "<       /__|____| ";
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
