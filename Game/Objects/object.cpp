#include "object.hpp"

Object::Object(std::string name, std::string description) : _name(name), _description(description) {
    this->set_id(Id::OBJECT);
}

std::string Object::get_name() {
    return this-> _name;
}
std::string Object::get_description() {
    return this-> _description;
}
Id Object::get_id() {
    return this-> _id;
}

void Object::set_id(Id id) {
    this->_id = id;
}
void Object::set_name(std::string name) {
    this-> _name = name;
}
void Object::set_descritpion(std::string description) {
    this-> _description = description;
}