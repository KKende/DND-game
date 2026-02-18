#pragma once
#include <iostream>
#include "../enemy.hpp"

class Ork : public Enemy {
public:
    Ork(int x, int y);
    std::vector<std::string> get_skin() override;
    ~Ork() override = default;
};