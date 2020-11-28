#ifndef __MAFIA__
#define __MAFIA__

#include <iostream>
#include <vector>
#include "../Player/Player.hpp"

class Mafia {
   public:
    Mafia();

   private:
    std::vector<Player *> players;
};

#endif