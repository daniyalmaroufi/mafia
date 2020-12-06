#ifndef __JOKER__
#define __JOKER__

#include <iostream>
#include <string>
#include <vector>

#include "../Player/Player.hpp"
#include "../main/defines.hpp"

class Joker : public Player {
   public:
    Joker(std::string name_);
    Joker(){};
    void show_info();
    void die_in_day();
    bool need_to_wake_up();
    bool do_nighttask_on(Player* second_player);
    bool is_mafia();

   private:
};

#endif
