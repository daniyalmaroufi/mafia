#ifndef __MAFIA__
#define __MAFIA__

#include <iostream>
#include <string>
#include <vector>

#include "../Player/Player.hpp"
#include "../main/defines.hpp"

class Mafia : public Player {
   public:
    Mafia(std::string name_);
    Mafia(){};
    void show_info();
    void die_in_day();
    bool need_to_wake_up();
    bool do_nighttask_on(Player* second_player);
    bool is_mafia();
    void die_in_night();

   private:
};

#endif