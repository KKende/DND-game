#pragma once
#include <vector>
#include "../entity.hpp"



class Player : public Entity {
    std::vector<Object*> _inventory;
    int _money;
public:
    Player(int x, int y, int max_health, std::string name, std::string description, int money);
    
    int& get_money();

    std::vector<Object*> &get_inventory();
    void delete_inventory();

    void add_money_amaount(int amount);

    ~Player() override;
};