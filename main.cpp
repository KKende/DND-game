#include <iostream>
#include "Game/game.hpp"

int main() {
    srand(time(0));
    Game* game = new Game();
    game->main_menu();
    game->loop();
    game->end_Game();
    delete game;
    return 0;
}