#include "ork.hpp"
#include "../../../Weapon/weapon.hpp"
#include "../../../Weapon/Club/club.hpp"

Ork::Ork(int x, int y) : Enemy(x, y, 50, "Ork", "a lizard like creature, an outcast to the human word.", 100) {
    this->delte_hands();
    this->set_hand_slot(new Club());
};
