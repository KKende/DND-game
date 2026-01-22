#include <iostream>
#include "Game/game.hpp"

int main() {
    Game* game = new Game();
    game->dispay_map();
    game->end_Game();
    delete game;
    return 0;
}