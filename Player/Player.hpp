#ifndef __PLAYER__
#define __PLAYER__

#include <iostream>
#include <string>

#include "../GameManager/Exceptions.hpp"
#include "../main/defines.hpp"

class Player {
   public:
    Player(std::string name_);
    Player(){};
    virtual void show_info() = 0;
    bool is_name(std::string name_);
    virtual void die_in_day() = 0;
    Player_status get_status();
    virtual bool need_to_wake_up();
    virtual bool can_wake_up();
    virtual bool do_nighttask_on(Player* second_player) = 0;
    virtual bool is_mafia() = 0;
    void heal();
    bool is_healed();
    void silence();
    void unsilence();
    bool is_silent();
    std::string get_name();
    virtual void assult();
    virtual void die_in_night() = 0;
    void change_character_to(std::string name_, bool silent);

   protected:
    std::string name;
    Player_status status;
    bool healed;
};

#endif
