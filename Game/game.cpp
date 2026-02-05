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
#include "Objects/Weapon/weapon.hpp"

Game::Game() { 
    this->d_or_p = true;
}

void sort(std::vector<Object*>& inventory) {
    int size = inventory.size();
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(inventory[j+1] < inventory[j]) {
                Object* temp = inventory[j];
                inventory[j] = inventory[j+1];
                inventory[j+1] = temp;
            }
        }
    }
}

void Game::loop() {
    while (true) {
        std::string usr_inp;
        std::getline(std::cin, usr_inp);
        if(usr_inp == "exit") break;
        if(usr_inp == "switch") { this->d_or_p = !this->d_or_p; this->dispay_map(); continue;}
        if(this->d_or_p) {
            if(!this->p_pickup(usr_inp) && !this->p_move(usr_inp)) std::cout << "\033[1;31m" << "Invalid input! \n" << "\033[0m";
        }
        else {
            if(!this->p_drop(usr_inp) && !this->p_move(usr_inp)) std::cout << "\033[1;31m" << "Invalid input! \n" << "\033[0m";
        }
    }
}

bool Game::p_drop(std::string item) {
    std::vector<Object*> &grid_inv = static_cast<Moveable*>(this ->_current_map->get_map()[this->_player->get_y()][this->_player->get_x()])->get_inventory();
    int idx;
    try {
        idx = std::stoi(item) - 1;
    }
    catch (const std::invalid_argument & e) {
        return false;
    }
    if(std::stoi(item) < 1 || std::stoi(item) > this->_player->get_inventory().size() || _player->get_inventory()[idx]->get_id() == Id::PLAYER || _player->get_inventory()[idx]->get_id() == Id::ENEMY || _player->get_inventory()[idx]->get_id() == Id::ENTITY) return false;
    grid_inv.push_back(this->_player->get_inventory()[idx]);
    this->_player->get_inventory().erase(this->_player->get_inventory().begin() + idx);
    this->dispay_map();
    return true;
}

bool Game::p_pickup(std::string item) {
    std::vector<Object*> &grid_inv = static_cast<Moveable*>(this ->_current_map->get_map()[this->_player->get_y()][this->_player->get_x()])->get_inventory();
    int idx;
    try {
        idx = std::stoi(item) - 1;
    }
    catch (const std::invalid_argument & e){
        return false;
    }
    if(std::stoi(item) < 1 || std::stoi(item) > grid_inv.size() || grid_inv[idx]->get_id() == Id::PLAYER || grid_inv[idx]->get_id() == Id::ENEMY || grid_inv[idx]->get_id() == Id::ENTITY) return false;
    
    this->_player->get_inventory().push_back(grid_inv[idx]);
    grid_inv.erase(grid_inv.begin() + idx);
    this->dispay_map();
    return true;
}

void Game::place_loot() {
    int number_of_loot = rand() % (this->_current_map->get_size() * 2) + 1;
    for (int i = 0; i < number_of_loot; i++) {
        int weapon = rand() % 3;
        int x = rand() % ((this->_current_map->get_size() * 2) - 1);
        int y = rand() % ((this->_current_map->get_size() * 2) - 1);
        if(x % 2 == 0) x += 1;
        if(y % 2 == 0) y += 1;
        if(weapon == 1) {
            static_cast<Moveable*>(_current_map->get_map()[y][x])->add_to_inventory(new Weapon("Test_sword", "a simple sword",Weapon_rarety::EPIC, Weapon_condition::FINE, 30, 100));
        }
        else {
            static_cast<Moveable*>(_current_map->get_map()[y][x])->add_to_inventory(new Object("rubbish", "it has no value"));
        }
        
    }
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

bool Game::p_move(std::string dir) {
    int i = 0;
    std::vector<Object*> &old_inv = static_cast<Moveable*>(this ->_current_map->get_map()[this->_player->get_y()][this->_player->get_x()])->get_inventory();
    if(dir == "up" && static_cast<Separator*>(this->_current_map->get_map()[this->_player->get_y() -1][this->_player->get_x()])->get_open_state() == true) {
        static_cast<Moveable*>(this ->_current_map->get_map()[this->_player->get_y() -2][this->_player->get_x()])->add_to_inventory(this->_player);
        for (Object* item : old_inv) {
            if(item->get_id() == Id::PLAYER) {
                old_inv.erase(old_inv.begin() + i);
                break;
            }
            i++;
        }
        this->_player->set_cordinates(this->_player->get_x(), this->_player->get_y() -2);
        this->dispay_map();
        return true;
    }
    else if(dir == "down" && static_cast<Separator*>(this->_current_map->get_map()[this->_player->get_y() +1][this->_player->get_x()])->get_open_state() == true) {
        static_cast<Moveable*>(this ->_current_map->get_map()[this->_player->get_y() +2][this->_player->get_x()])->add_to_inventory(this->_player);
        for (Object* item : old_inv) {
            if(item->get_id() == Id::PLAYER) {
                old_inv.erase(old_inv.begin() + i);
                break;
            }
            i++;
        }
        this->_player->set_cordinates(this->_player->get_x(), this->_player->get_y() +2);
        this->dispay_map();
        return true;
    }
    else if(dir == "right" && static_cast<Separator*>(this->_current_map->get_map()[this->_player->get_y()][this->_player->get_x() +1])->get_open_state() == true) {
        static_cast<Moveable*>(this ->_current_map->get_map()[this->_player->get_y()][this->_player->get_x() +2])->add_to_inventory(this->_player);
        for (Object* item : old_inv) {
            if(item->get_id() == Id::PLAYER) {
                old_inv.erase(old_inv.begin() + i);
                break;
            }
            i++;
        }
        this->_player->set_cordinates(this->_player->get_x() +2,this->_player->get_y());
        this->dispay_map();
        return true;
    }
    else if(dir == "left" && static_cast<Separator*>(this->_current_map->get_map()[this->_player->get_y()][this->_player->get_x() -1])->get_open_state() == true) {
        static_cast<Moveable*>(this ->_current_map->get_map()[this->_player->get_y()][this->_player->get_x() -2])->add_to_inventory(this->_player);
        for (Object* item : old_inv) {
            if(item->get_id() == Id::PLAYER) {
                old_inv.erase(old_inv.begin() + i);
                break;
            }
            i++;
        }
        this->_player->set_cordinates(this->_player->get_x() -2,this->_player->get_y());
        this->dispay_map();
        return true;
    }
    else return false;
}

void Game::start_Game() {
    system("clear");
    std::string name;
    std::cout << "Name your player: " << std::endl;
    std::getline(std::cin, name);
    this->_player = new Player(1, 1, 100,100, name, "a basic player");
    this->_current_map = new Map(11);
    static_cast<Moveable*>(this->_current_map->get_map()[1][1])->add_to_inventory(this->_player);
}

void Game::dispay_map() {
    std::vector<Object*> &grid_inv = static_cast<Moveable*>(this->_current_map->get_map()[this->_player->get_y()][this->_player->get_x()])->get_inventory();
    sort(grid_inv);
    sort(this->_player->get_inventory());
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
        else if(y == 3) std::cout << " Player weapon: \33[1;29m" << "WIP" << "\033[0m";
        else if (y == 5) std::cout << "\33[1;34m" << " controls" << "\033[0m";
        else if (y == 6) std::cout << "\33[1;35m " << " 'down' - Down" << "\033[0m";
        else if (y == 7) std::cout << "\33[1;35m " << " 'up' - Up" << "\033[0m";
        else if (y == 8) std::cout << "\33[1;35m " << " 'right' - Right" << "\033[0m";
        else if (y == 9) std::cout << "\33[1;35m " << " 'left' - Left" << "\033[0m";
        else if (y == 10) std::cout << "\33[1;35m " << " 'exit' - Quit game" << "\033[0m";
        else if(y == 11) std::cout << "\33[1;35m " << " 'switch' - to switch between to drop or picup item" << "\033[0m";
        else if(y == 12) std::cout << "\33[1;36m " << " To pickup item type the item's number!" << "\033[0m";
        
        std::cout << "\n";
        y++;
    }
    int i = 0;
    if(!this->d_or_p) std::cout << "Currently you are switched to \33[1;31mdrop \033[0mitems \n";
    else std::cout << "Currently you are switched to \33[1;31mpick up \033[0mitems \n";
    if(grid_inv.size() > 1) {
        std::cout << std::endl;
        std::cout << "\33[1;34m" << "Grid's inventory: " << "\033[0m" <<"\n";
        for(Object* item : grid_inv) {
            if(item->get_id() != Id::PLAYER && item->get_id() != Id::ENEMY) {
                if(item->get_id() == Id::WEAPON) std::cout << " \033[1;31m" << i + 1 <<". \033[0m" << static_cast<Weapon*> (item)->get_full_name() << " ," << item->get_description() << "\n";
                else std::cout << " \033[1;37m" << i + 1 <<". \033[0m" << item->get_name() << " ," << item->get_description() << "\n";
            }
            i++;
        }
    }
    if(this->_player->get_inventory().size() > 0) {
        std::cout << std::endl;
        std::cout << "\33[1;32m" << "Your inventory: " << "\033[0m" <<"\n";
        i = 0;
        for(Object* item : this->_player->get_inventory()) {
            if(item->get_id() != Id::PLAYER && item->get_id() != Id::ENEMY) {
                if(item->get_id() == Id::WEAPON) std::cout << " \033[1;31m" << i + 1 <<". \033[0m" << static_cast<Weapon*> (item)->get_full_name() << " ," << item->get_description() << "\n";
                else std::cout << " \033[1;37m" << i + 1 <<". \033[0m" << item->get_name() << " ," << item->get_description() << "\n";
            }
            i++;
        }
    }
    std::cout << "\n" << "\033[1;34m" << "Commands:" << "\033[0m" << std::endl;
}

void Game::end_Game() {
    delete _current_map;
}