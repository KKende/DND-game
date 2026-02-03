#include <iostream>
#include "Game/game.hpp"

int main() {
    srand(time(0));
    Game* game = new Game();
    game->main_menu();
    game->place_loot();
    game->dispay_map();
    while (true) {
        std::string usr_inp;
        std::getline(std::cin, usr_inp);
        if(usr_inp == "exit") break;
        if(!game->p_pickup(usr_inp) && !game->p_move(usr_inp)) std::cout << "invalid input";
    }
    game->end_Game();
    delete game;
    return 0;
}