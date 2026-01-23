#include "separator.hpp"

Separator::Separator(int x, int y, Visual visual) : Grid(x, y, visual) {
    this->set_id(Grid_Id::SEPARATOR);
};

bool Separator::get_open_state() {
    return this-> _state;
}

void Separator::set_close() {
    this-> _state = false;
}
void Separator::set_open() {
    this-> _state = true;
}
void Separator::set_state_reverse() {
    this-> _state = !this-> _state;
}