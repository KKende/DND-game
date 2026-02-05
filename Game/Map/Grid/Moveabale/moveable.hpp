#pragma once
#include "../grid.hpp"
#include <vector>

class Object;

class Moveable : public Grid {
    std::vector<Object*> _inventory;
public:
    Moveable(int x, int y, Visual visual);
    std::vector<Object*>& get_inventory();
    void add_to_inventory(Object* object);
    void auto_set_visual();
    void clear_grid_inv();
    
    ~Moveable() override;
};