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
#include <sstream>

std::string red(std::string text) {
    return "\e[0;31m" + text + "\033[0m";
}

std::string green(std::string text) {
    return "\e[0;32m" + text + "\033[0m";
}

std::string blue(std::string text) {
    return "\e[0;34m" + text + "\033[0m";
}

std::string yellow(std::string text) {
    return "\e[0;33m" + text + "\033[0m";
}

std::string purpule(std::string text) {
    return "\e[0;35m" + text + "\033[0m";
}

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
        std::stringstream inp(usr_inp);
        std::string command_word;
        std::string action_word;
        if(usr_inp == "exit") break;
        if(!(inp >> command_word >> action_word)) {std::cout << red("Invalid Input") << "\n"; continue;}

        if(command_word == "p") { if(!this->p_pickup(action_word)) std::cout << red("Invalid Input") << "\n";}
        else if (command_word == "d") { if(!this->p_drop(action_word)) std::cout << red("Invalid Input") << "\n";}
        else if (command_word == "m") {if(!this->p_move(action_word)) std::cout << red("Invalid Input") << "\n";}
        else if (command_word == "e") {if(!this->p_equip(action_word))std::cout << red("Invalid Input") << "\n";}
        else std::cout << red("Invalid Input") << "\n";
    }
}

bool Game::p_equip(std::string item) {
    int idx;
    try {
        idx = std::stoi(item) - 1;
    }
    catch (const std::invalid_argument & e) {
        return false;
    }
    if(idx + 1 < 1 || idx + 1 > this->_player->get_inventory().size() || this->_player->get_inventory()[idx]->get_id() != Id::WEAPON) return false;
    if(this->_player->get_weapon()->get_id() != Id::NONE) {
        Weapon* temp = this->_player->get_weapon();
        this->_player->set_hand_slot(static_cast<Weapon*>(this->_player->get_inventory()[idx]));
        this->_player->get_inventory().erase(this->_player->get_inventory().begin() + idx);
        this->_player->get_inventory().push_back(temp); 
    }
    else {
        this->_player->delte_hands();
        this->_player->set_hand_slot(static_cast<Weapon*>(this->_player->get_inventory()[idx]));
        this->_player->get_inventory().erase(this->_player->get_inventory().begin() + idx);
    }
    this->dispay_map();
    return true;
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
    if(dir == "u" && static_cast<Separator*>(this->_current_map->get_map()[this->_player->get_y() -1][this->_player->get_x()])->get_open_state() == true) {
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
    else if(dir == "d" && static_cast<Separator*>(this->_current_map->get_map()[this->_player->get_y() +1][this->_player->get_x()])->get_open_state() == true) {
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
    else if(dir == "r" && static_cast<Separator*>(this->_current_map->get_map()[this->_player->get_y()][this->_player->get_x() +1])->get_open_state() == true) {
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
    else if(dir == "l" && static_cast<Separator*>(this->_current_map->get_map()[this->_player->get_y()][this->_player->get_x() -1])->get_open_state() == true) {
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
    this->_player = new Player(1, 1, 100,100, name, "a basic player", 125);
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
        if(y == 0) std::cout << " Map name: " << yellow(this->_current_map->get_name());
        else if(y == 1) std::cout << " Player name: " << green(this->_player->get_name());
        else if(y == 2) std::cout << " Hp: " << red(std::to_string(this->_player->get_health()) + " / " + std::to_string(this->_player->get_max_health()));
        else if(y == 3) std::cout << " Weapon: " << purpule(this->_player->get_weapon()->get_full_name());
        else if(y == 4) std::cout << " Money: " << yellow(std::to_string(this->_player->get_money())) << " keys";
        else if(y == 6) std::cout << blue(" Commands :");
        else if(y == 7) std::cout << green(" 'm'") << " - move : " << purpule("'u'") << " - up, " << purpule("'d'") << " - down, " << purpule("'l'") << " - left, " << purpule("'r'") << " - right";
        else if(y == 8) std::cout << green(" 'p'") << " - pickup + " << purpule("item's number") << " from grid's inventory";
        else if(y == 9) std::cout << green(" 'm'") << " - drop + "<< purpule("item's number") << " from thy inventory";
        else if(y == 10) std::cout << green(" 'exit'") <<  " - quit game";
        std::cout << "\n";
        y++;
    }
    int i = 0;
    if(grid_inv.size() > 1) {
        std::cout << std::endl;
        std::cout << blue("Grid inventory: \n");
        for(Object* item : grid_inv) {
            if(item->get_id() != Id::PLAYER && item->get_id() != Id::ENEMY) {
                if(item->get_id() == Id::WEAPON) std::cout << red(std::to_string(i + 1)) << ". " << static_cast<Weapon*> (item)->get_full_name() << " ," << item->get_description() << "\n";
                else std::cout << yellow(std::to_string(i + 1)) << ". " << item->get_name() << " ," << item->get_description() << "\n";
            }
            i++;
        }
    }
    if(this->_player->get_inventory().size() > 0) {
        std::cout << std::endl;
        std::cout << green("Thy inventory : \n");
        i = 0;
        for(Object* item : this->_player->get_inventory()) {
            if(item->get_id() != Id::PLAYER && item->get_id() != Id::ENEMY) {
                if(item->get_id() == Id::WEAPON) std::cout << red(std::to_string(i + 1)) << ". " << static_cast<Weapon*> (item)->get_full_name() << " ," << item->get_description() << "\n";
                else std::cout << yellow(std::to_string(i + 1)) << ". " << item->get_name() << " ," << item->get_description() << "\n";
            }
            i++;
        }
    }
    std::cout << "\n" << blue("Commands :") << std::endl;
}

void Game::end_Game() {
    delete _current_map;
}