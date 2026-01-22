#include "game.hpp"
#include "Map/map.hpp"
#include "Map/Grid/grid.hpp"
#include "Map/Grid/Moveabale/moveable.hpp"
#include "Map/Grid/Separator/separator.hpp"

Game::Game() {
    this->_current_map = new Map(5);
    this->_current_Grid = this->_current_map->get_map()[0][0];
}

void Game::dispay_map() {
    int y = 0;
    for(std::vector<Grid*> row: _current_map->get_map()) {
        int x = 0;
        for(Grid* g: row) {
            std::cout << g->str_visual();
            if(y == 3 && x == row.size() - 1) {
                std::cout << "   Selected: X: " << this->_current_Grid->get_x() << " Y: " << this->_current_Grid->get_y();
            }
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