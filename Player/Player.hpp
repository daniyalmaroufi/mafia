#ifndef __PLAYER__
#define __PLAYER__

#include <string>
#include "../main/defines.hpp"


class Player {
   public:
    Player(std::string name_);
    Player(){};

   private:
    std::string name;
};

#endif