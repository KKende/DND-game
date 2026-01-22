#pragma once
#include <iostream>
#include <vector>
#include <string>

class Player;
class Enemy;
class Grid;
class Map;

class Game {
    Grid* _current_Grid;
    Map* _current_map;
public:
    Game();
    int battle(Enemy* enemy);
    void p_move();
    int gridcheck();
    void dispay_map();

    void end_Game();

    ~Game(){};
};