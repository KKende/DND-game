#include "separator_h.hpp"

Separator_Horizontal::Separator_Horizontal(int x, int y, bool status) : Separator(x, y, Visual::EMPTY) {
    this->set_id(Grid_Id::SEPARATOR_H);
    switch (status) {
    case true:
        this->set_visual(Visual::HORIZONTAL_WALL_OPENED);
        this->set_open();
        break;
    default:
        this->set_visual(Visual::HORIZONTAL_WALL_CLOSED);
        this->set_close();
    }
};

void Separator_Horizontal::set_Close() {
    this->set_close();
    this->set_visual(Visual::HORIZONTAL_WALL_CLOSED);
}

void Separator_Horizontal::set_Open() {
    this->set_open();
    this->set_visual(Visual::HORIZONTAL_WALL_OPENED);
}