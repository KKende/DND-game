#pragma once
#include <iostream>
#include <string>
#include <vector>

enum Visual {
    ENEMY,
    PLAYER,
    CHEST,
    EMPTY,
    VERTICAL_WALL_CLOSED,
    VERTICAL_WALL_OPENED,
    HORIZONTAL_WALL_CLOSED,
    HORIZONTAL_WALL_OPENED,
    VISUAL_GRID
};

class Grid {
    int _x;
    int _y;
    Visual _visual;
public:
    Grid(int x, int y, Visual visual);

    int get_x();
    int get_y();
    Visual get_visual();

    void set_x(int x);
    void set_y(int y);
    void set_visual(Visual visual);
    std::string str_visual();

    virtual ~Grid() = default;
};