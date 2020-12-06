#ifndef __SILENCER__
#define __SILENCER__

#include <iostream>
#include <vector>
#include <string>
#include "../main/defines.hpp"
#include "./Mafia.hpp"

class Silencer : public Mafia {
   public:
    Silencer(std::string name_);
    Silencer(){};
    void show_info();
    bool need_to_wake_up();
    void reset_to_first_night();
    bool do_nighttask_on(Player* second_player);

   private:
   bool done_nighttask;
};

#endif
