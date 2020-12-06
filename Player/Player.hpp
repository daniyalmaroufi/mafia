#ifndef __PLAYER__
#define __PLAYER__

#include <iostream>
#include <string>

#include "../main/defines.hpp"
#include "../GameManager/Exceptions.hpp"

class Player {
   public:
    Player(std::string name_);
    Player(){};
    virtual void show_info() = 0;
    bool is_name(std::string name_);
    virtual void die_in_day() = 0;
    Player_status get_status();
    virtual bool need_to_wake_up();
    virtual bool do_nighttask_on(Player* second_player) = 0;
    virtual bool is_mafia() = 0;
    void heal();

   protected:
    std::string name;
    Player_status status;
    bool healed;
};

#endif
