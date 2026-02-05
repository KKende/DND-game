#include "moveable.hpp"
#include "../../../Objects/object.hpp"

Moveable::Moveable(int x, int y, Visual visual) : Grid(x, y, visual) {
    this->set_id(Grid_Id::MOVEABLE);
};

std::vector<Object*>& Moveable::get_inventory() {
    return this->_inventory;
}

void Moveable::add_to_inventory(Object *object) {
    this->_inventory.push_back(object);
}

void Moveable::auto_set_visual() {
    Id w_on_grid = Id::NONE;
    for(Object* item: this->_inventory) {
        if(item->get_id() == Id::PLAYER) {
            w_on_grid = Id::PLAYER;
            break;
        }
        else if(item->get_id() == Id::ENEMY && w_on_grid != Id::PLAYER) {
            w_on_grid = Id::ENEMY;
        }
        else if(item->get_id() == Id::WEAPON && w_on_grid != Id::ENEMY && w_on_grid != Id::PLAYER) {
            w_on_grid = Id::WEAPON;
        }
        else if(item->get_id() == Id::OBJECT && w_on_grid != Id::WEAPON && w_on_grid != Id::ENEMY && w_on_grid != Id::PLAYER) {
            w_on_grid = Id::OBJECT;
        }
    }

    switch(w_on_grid) {
        case Id::ENEMY:
            this->set_visual(Visual::ENEMY);
            break;
        case Id::OBJECT:
            this->set_visual(Visual::CHEST);
            break;
        case Id::PLAYER:
            this->set_visual(Visual::PLAYER);
            break;
        case Id::WEAPON:
            this->set_visual(Visual::CHEST);
            break;
        default:
            this->set_visual(Visual::EMPTY);
    }
}

void Moveable::clear_grid_inv() {
    for(Object* item: this->_inventory) {
        delete item;
    }
    this->_inventory.clear();
}

Moveable::~Moveable() {
    this->clear_grid_inv();
}