#include "map.hpp"
#include "Grid/grid.hpp"
#include "Grid/Moveabale/moveable.hpp"
#include "Grid/Separator/separator.hpp"
#include "Grid/Separator/Separator_horizontal/separator_h.hpp"
#include "Grid/Separator/Separator_vertical/separator_v.hpp"

void clearrow(std::vector<Grid*> &row) {
    for(Grid* g: row) {
        if(g->get_id() == Grid_Id::MOVEABLE) {
            dynamic_cast<Moveable*>(g)->clear_grid_inv();
        }
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
    this->_name = this-> new_name();
    this-> clear_map();
    for(int y = 0; y < this-> _size; y++) {
        //floor
        std::vector<Grid*> row;
        for(int x = 0; x < this-> _size-1; x++) {
            row.push_back(new Grid(x, y, Visual::VISUAL_GRID));
            if(y < 1) row.push_back(new Separator_Horizontal(x, y, false));
            else row.push_back(new Separator_Horizontal(x, y, rand() % 2)); //rand() % 2
        }
        row.push_back(new Grid(this->_size -2, y, Visual::VISUAL_GRID));
        this->_map.push_back(row);
        row.clear();
        
        //row
        for(int x = 0; x < this-> _size-1; x++) {
            if(x < 1) row.push_back(new Separator_Vertical(x, y, false));
            else row.push_back(new Separator_Vertical(x, y, rand() % 2)); //rand() % 2
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

    //drill
    int point = 1;
    //if(point % 2 == 0) point += 1;
    
    for(int y = 1; y < this->_map.size(); y+=2) {
        int next_point = rand() % (this->_map[y].size() - 1);
        if(next_point % 2 == 0) next_point += 1;
        int max = std::max(point, next_point);
        int min = std::min(point, next_point);
        for(int x = 0; x < this->_map[y].size(); x++) {
            if(this->_map[y][x]->get_id() == Grid_Id::SEPARATOR_V && (min <= x && x <= max)) {
                dynamic_cast<Separator_Vertical*>(_map[y][x])->set_Open();
            }
        }

        for(int x = 0; x < this->_map[y+1].size(); x ++) {
            if(next_point == x) {
                dynamic_cast<Separator_Horizontal*>(_map[y+1][x])->set_Open();
            }
        }

        point = next_point;
    }
}

std::string Map::new_name() {
    std::vector<std::string> names;
    std::fstream f;
    f.open("ReadFiles/Location_names.txt", std::ios::in);
    if(!f.is_open()) return "ERROR_FILE";
    std::string line;
    while(std::getline(f, line)) {
        names.push_back(line);
        line.clear();
    }   
    f.close();
    if(names.size() < 1) return "ERROR_EMPTY_VEC";
    return names[rand() % names.size()];
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