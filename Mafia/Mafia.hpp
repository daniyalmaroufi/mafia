#ifndef __MAFIA__
#define __MAFIA__

#include <iostream>
#include <vector>
#include <string>
#include "../main/defines.hpp"
#include "../Player/Player.hpp"

class Mafia : public Player {
   public:
    Mafia(std::string name_);
    Mafia(){};
    void show_info();
    void die_in_day();

   private:
};

#endif