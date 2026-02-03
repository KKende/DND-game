#pragma once
#include <iostream>
#include <vector>
#include <string>

class Player;
class Enemy;
class Grid;
class Map;

class Game {
    Player* _player;
    Map* _current_map;
public:
    Game();
    int battle(Enemy* &enemy);
    void p_move(std::string dir);
    int gridcheck();
    void dispay_map();
    void main_menu();
    void start_Game();
    void end_Game();

    ~Game() = default;
};