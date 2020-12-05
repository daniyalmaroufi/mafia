#ifndef __VILLAGER__
#define __VILLAGER__

#include <iostream>
#include <vector>
#include <string>
#include "../main/defines.hpp"
#include "../Player/Player.hpp"

class Villager : public Player {
   public:
    Villager(std::string name_);
    Villager(){};
    void show_info();

   private:
};

#endif