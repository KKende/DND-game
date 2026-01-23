#pragma once
#include "../grid.hpp"

class Separator : public Grid {
    bool _state;
public:
    Separator(int x, int y, Visual visual);

    bool get_open_state();

   void set_close();
   void set_open();
   void set_state_reverse();

    ~Separator() override = default;
};