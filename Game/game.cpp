#include "game.hpp"
#include "Map/map.hpp"
#include "Map/Grid/grid.hpp"
#include "Map/Grid/Moveabale/moveable.hpp"
#include "Map/Grid/Separator/separator.hpp"
#include "Map/Grid/Separator/Separator_horizontal/separator_h.hpp"
#include "Map/Grid/Separator/Separator_vertical/separator_v.hpp"

Game::Game() {
    this->_current_map = new Map(15);
}

void Game::dispay_map() {
    int y = 0;
    std::cout << this->_current_map->get_name() << std::endl;
    for(std::vector<Grid*> row: _current_map->get_map()) {
        int x = 0;
        for(Grid* g: row) {
            std::cout << g->str_visual();
            x++;
        }
        std::cout << "\n";
        y++;
    }
}

void Game::end_Game() {
    _current_map->clear_map();
    delete _current_map;
}