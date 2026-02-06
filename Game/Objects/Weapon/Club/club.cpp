#include "club.hpp"

Club::Club() : Weapon("club", "a wooden club", Weapon_rarety(rand() % 5), 10, rand() % 101 + 1) {}