#include "grid.hpp"

Grid::Grid(int x, int y, Visual visual) : _x(x), _y(y), _visual(visual) {
    this->_id = Grid_Id::GRID;
};

Visual Grid::get_visual() {
    return this->_visual;
}
int Grid::get_x() {
    return this-> _x;
}
int Grid::get_y() {
    return this-> _y;
}
Grid_Id Grid::get_id() {
    return this->_id;
}

void Grid::set_visual(Visual visual) {
    this-> _visual = visual;
}
void Grid::set_x(int x) {
    this-> _x = x;
}
void Grid::set_y(int y) {
    this-> _y = y;
}
void Grid::set_id(Grid_Id id) {
    this->_id = id;
}

std::string Grid::str_visual() {
    switch(this-> _visual) {
        case Visual::CHEST:
            return "\33[1;33mCHT\033[0m";
        case Visual::EMPTY:
            return "   ";
        case Visual::ENEMY:
            return "\33[1;31mEMY\033[0m";
        case Visual::HORIZONTAL_WALL_CLOSED:
            return "---";
        case Visual::HORIZONTAL_WALL_OPENED:
            return "   ";
        case Visual::PLAYER:
            return "\33[1;32mPLR\033[0m";
        case Visual::VERTICAL_WALL_CLOSED:
            return "|";
        case Visual::VERTICAL_WALL_OPENED:
            return " ";
        case Visual::VISUAL_GRID:
            return "+";
        default:
            return "ERR";
    }
}