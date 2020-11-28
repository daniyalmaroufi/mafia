#ifndef __GAME_MANAGER__
#define __GAME_MANAGER__

#include <iostream>
#include <string>
#include <sstream>
#include "../Mafia/Mafia.hpp"

using namespace std;

class GameManager {
   public:
    GameManager();
    void handle_inputs();
    void create_game_command();

   private:
   Mafia* mafia;
};

#endif