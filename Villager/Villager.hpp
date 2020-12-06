#ifndef __VILLAGER__
#define __VILLAGER__

#include <iostream>
#include <string>
#include <vector>

#include "../Player/Player.hpp"
#include "../main/defines.hpp"

class Villager : public Player {
   public:
    Villager(std::string name_);
    Villager(){};
    void show_info();
    void die_in_day();
    bool do_nighttask_on(Player* second_player);
    bool is_mafia();
    void die_in_night();

   private:
};

#endif