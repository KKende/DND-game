#pragma once
#include <vector>
#include "../entity.hpp"



class Player : public Entity {
    std::vector<Object*> _inventory;
public:
    Player(int health, int max_health, std::string name, std::string description);
    
    std::vector<Object*> get_inventory();
    void delete_inventory();

    ~Player() override = default;
};