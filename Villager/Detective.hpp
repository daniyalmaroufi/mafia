#ifndef __DETECTIVE__
#define __DETECTIVE__

#include <iostream>
#include <vector>
#include <string>
#include "../main/defines.hpp"
#include "./Villager.hpp"

class Detective : public Villager {
   public:
    Detective(std::string name_);
    Detective(){};
    void show_info();
    bool need_to_wake_up();
    bool do_nighttask_on(Player* second_player);

   private:
   bool done_nighttask;
};

#endif