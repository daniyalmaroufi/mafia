#ifndef __GAME_MANAGER__
#define __GAME_MANAGER__

#include <iostream>
#include <string>
#include <sstream>
#include "../main/defines.hpp"
#include "../Player/Player.hpp"
#include "../Mafia/Mafia.hpp"
#include "../Villager/Villager.hpp"

using namespace std;

class GameManager {
   public:
    GameManager();
    void handle_inputs();

   private:
    void add_player(string player_name);
    void handle_command(string command);
    void create_game_command();
    void assign_role_command();
   vector<Player *> players;
};

#endif