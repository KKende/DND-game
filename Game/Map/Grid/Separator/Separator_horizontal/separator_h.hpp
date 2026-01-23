#pragma once
#include "../separator.hpp"

class Separator_Horizontal : public Separator {
public:
    Separator_Horizontal(int x, int y, bool status);
    void set_Close();
    void set_Open();
};
