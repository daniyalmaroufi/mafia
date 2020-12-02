#ifndef __GAME_MANAGER__
#define __GAME_MANAGER__

#include <iostream>
#include <string>
#include <sstream>
#include "../main/defines.hpp"
#include "../Mafia/Mafia.hpp"

using namespace std;

class GameManager {
   public:
    GameManager();
    void handle_inputs();
    void handle_command(string command);
    void create_game_command();

   private:
   Mafia* mafia;
};

#endif