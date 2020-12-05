#ifndef __PLAYER__
#define __PLAYER__

#include <iostream>
#include <string>

#include "../main/defines.hpp"

class Player {
   public:
    Player(std::string name_);
    Player(){};
    virtual void show_info() = 0;
    bool is_name(std::string name_);
    virtual void die_in_day() = 0;
    Player_status get_status();

   protected:
    std::string name;
    Player_status status;
};

#endif