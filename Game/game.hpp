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
    void place_loot();
    bool p_pickup(std::string item);
    bool p_drop(std::string item);
    bool p_move(std::string dir);
    void dispay_map();
    void main_menu();
    void start_Game();
    void end_Game();

    ~Game() = default;
};