#ifndef __PLAYER__
#define __PLAYER__

#include <string>

#include "../main/defines.hpp"

class Player {
   public:
    Player(std::string name_);
    Player(){};
    virtual void show_info() = 0;

   private:
    std::string name;
};

#endif