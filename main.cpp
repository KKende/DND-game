#include <iostream>
#include "Game/game.hpp"

int main() {
    srand(time(0));
    Game* game = new Game();
    game->main_menu();
    game->place_loot();
    game->dispay_map();
    bool d_or_p = false;
    while (true) {
        std::string usr_inp;
        std::getline(std::cin, usr_inp);
        if(usr_inp == "exit") break;
        if(usr_inp == "switch") {d_or_p = !d_or_p; continue;}
        if(d_or_p) {
            if(!game->p_pickup(usr_inp) && !game->p_move(usr_inp)) std::cout << "\033[1;31m" << "Invalid input! \n" << "\033[0m";
        }
        else {
            if(!game->p_drop(usr_inp) && !game->p_move(usr_inp)) std::cout << "\033[1;31m" << "Invalid input! \n" << "\033[0m";
        }
        
    }
    game->end_Game();
    delete game;
    return 0;
}