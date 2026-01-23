#include "separator_v.hpp"

Separator_Vertical::Separator_Vertical(int x, int y, bool status) : Separator(x, y, Visual::EMPTY) {
    this->set_id(Grid_Id::SEPARATOR_V);
    switch (status) {
        case true:
            this->set_visual(Visual::VERTICAL_WALL_OPENED);
            this->set_open();
            break;
        default:
            this->set_visual(Visual::VERTICAL_WALL_CLOSED);
            this->set_close();
    }
};