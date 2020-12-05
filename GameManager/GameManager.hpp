#ifndef __GAME_MANAGER__
#define __GAME_MANAGER__

#include <iostream>
#include <sstream>
#include <string>

#include "../Mafia/Mafia.hpp"
#include "../Player/Player.hpp"
#include "../Villager/Villager.hpp"
#include "../main/defines.hpp"

using namespace std;

enum roles { villager, mafia, silencer, godfather, doctor, detective, no_role };

struct User {
    string name;
    roles role;
};

class GameManager {
   public:
    GameManager();
    void handle_inputs();

   private:
    void add_player(string player_name);
    void handle_command(string command);
    void create_game_command();
    void assign_role_command();

    vector<User> users;
    vector<Player *> players;
    bool game_started;
};

#endif