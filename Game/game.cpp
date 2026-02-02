#include "game.hpp"
#include "Map/map.hpp"
#include "Map/Grid/grid.hpp"
#include "Map/Grid/Moveabale/moveable.hpp"
#include "Map/Grid/Separator/separator.hpp"
#include "Map/Grid/Separator/Separator_horizontal/separator_h.hpp"
#include "Map/Grid/Separator/Separator_vertical/separator_v.hpp"
#include "Objects/object.hpp"
#include "Objects/Entity/entity.hpp"
#include "Objects/Entity/Player/player.hpp"

Game::Game() {
    
}

void Game::main_menu() {
    system("clear");
    std::cout <<"MAIN MENU" << "\n";
    std::cout << "1 - New Game" << "\n";
    std::cout << "2 - Continue Game(WIP)" << "\n";
    std::cout << "3 - Load_Game(WIP)" << std::endl;
    while(true) {
        std::string user_ans;
        std::getline(std::cin, user_ans);
        if(user_ans == "1") {
            this->start_Game();
            return;
        }
    }
} 

void Game::start_Game() {
    system("clear");
    std::string name;
    std::cout << "Name your player: " << std::endl;
    std::getline(std::cin, name);
    this->_player = new Player(100,100, name, "a basic player");
    this->_current_map = new Map(5);
    static_cast<Moveable*>(this->_current_map->get_map()[1][1])->get_inventory().push_back(this->_player);
}

void Game::dispay_map() {
    system("clear");
    int y = 0;
    for(std::vector<Grid*> row: _current_map->get_map()) {
        int x = 0;
        for(Grid* g: row) {
            if(g->get_id() == Grid_Id::MOVEABLE) {
                static_cast<Moveable*>(g)->auto_set_visual();
            }
            std::cout << g->str_visual();
            x++;
        }
        if(y == 0) std::cout << " Map name: \33[1;33m" << this->_current_map->get_name() << "\033[0m";
        else if(y == 1) std::cout << " Player name: \033[1;32m" << this->_player->get_name() << "\033[0m";
        else if(y == 2) std::cout << " Player hp: \33[1;31m" << this->_player->get_health() << " / " << this->_player->get_max_health() << "\033[0m";
        std::cout << "\n";
        y++;
    }
}

void Game::end_Game() {
    _player->delete_inventory();
    _current_map->clear_map();
    delete _current_map;
}