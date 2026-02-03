#pragma once
#include <iostream>

enum class Id {
    NONE,
    OBJECT,
    WEAPON,
    ENTITY,
    ENEMY,
    PLAYER
};

class Object {
    Id _id;
    std::string _name;
    std::string _description;
public:
    Object(std::string name, std::string description);

    Id get_id();
    std::string get_name();
    std::string get_description();

    void set_id(Id id);
    void set_name(std::string name);
    void set_descritpion(std::string description);

    virtual ~Object() = default;
};