#include "map.hpp"
#include "Grid/grid.hpp"
#include "Grid/Moveabale/moveable.hpp"
#include "Grid/Separator/separator.hpp"
#include "Grid/Separator/Separator_horizontal/separator_h.hpp"
#include "Grid/Separator/Separator_vertical/separator_v.hpp"

void clearrow(std::vector<Grid*> &row) {
    for(Grid* g: row) {
        delete g;
    }
    row.clear();
}

Map::Map(int size) : _size(size) {
    this->generate_map();
}

void Map::clear_map() {
    for(std::vector<Grid*>& row: this->_map) {
        clearrow(row);
    }
}

void Map::generate_map() {
    this-> _name = this-> new_name();
    clear_map();
    for(int y = 0; y < this-> _size; y++) {
        //floor
        std::vector<Grid*> row;
        for(int x = 0; x < this-> _size-1; x++) {
            row.push_back(new Grid(x, y, Visual::VISUAL_GRID));
            if(y < 1) row.push_back(new Separator_Horizontal(x, y, false));
            else row.push_back(new Separator_Horizontal(x, y, rand() % 2));
        }
        row.push_back(new Grid(this->_size -2, y, Visual::VISUAL_GRID));
        this->_map.push_back(row);
        row.clear();
        
        //row
        for(int x = 0; x < this-> _size-1; x++) {
            if(x < 1) row.push_back(new Separator_Vertical(x, y, false));
            else row.push_back(new Separator_Vertical(x, y, rand() % 2));
            row.push_back(new Moveable(x, y, Visual::EMPTY));
        }
        row.push_back(new Separator_Vertical(this->_size -2, y, false));
        this->_map.push_back(row);
        row.clear();

        //if last floor end
        if(y != _size -1) continue;

        for(int x = 0; x < this-> _size-1; x++) {
            row.push_back(new Grid(x, y, Visual::VISUAL_GRID));
            row.push_back(new Separator_Horizontal(x, y, false));
        }
        row.push_back(new Grid(this->_size -2, y, Visual::VISUAL_GRID));
        this->_map.push_back(row);
        row.clear();
    }
}


std::string Map::new_name() {
    std::vector<std::string> names;
    std::fstream f("Location_names", std::ios::in);
    std::string line;
    if(f.is_open()) {
        while(std::getline(f, line)) {
        names.push_back(line);
        line.clear();
        }   
        f.close();
        return names[rand() % names.size()];
    }
    else return "ERROR";
}

std::string Map::get_name() {
    return this-> _name;
}
std::vector<std::vector<Grid*>>& Map::get_map() {
    return this->_map;
}
int Map::get_size() {
    return this-> _size;
}