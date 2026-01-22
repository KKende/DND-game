#include "moveable.hpp"

Moveable::Moveable(int x, int y, Visual visual) : Grid(x, y, visual) {};

std::vector<Object*>& Moveable::get_inventory() {
    return this->_inventory;
}