#ifndef __MAFIA__
#define __MAFIA__

#include <iostream>
#include <vector>
#include <string>
#include "../Player/Player.hpp"

class Mafia {
   public:
    Mafia();
    void add_player(std::string player_name);

   private:
    std::vector<Player *> players;
};

#endif