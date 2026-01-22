#pragma once
#include <vector>
#include <string>
#include <fstream>

class Grid;

class Map {
    std::string _name;
    int _size;
    std::vector<std::vector<Grid*>> _map;
public:
    Map(int size);

    std::string get_name();
    int get_size();
    std::vector<std::vector<Grid*>>& get_map();

    std::string new_name();
    void generate_map();
    void clear_map();
    ~Map() = default;
};