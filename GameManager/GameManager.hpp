#ifndef __GAME_MANAGER__
#define __GAME_MANAGER__

#include <iostream>
#include <sstream>
#include <string>

#include "../Joker/Joker.hpp"
#include "../Mafia/GodFather.hpp"
#include "../Mafia/Mafia.hpp"
#include "../Mafia/Silencer.hpp"
#include "../Player/Player.hpp"
#include "../Villager/BulletProof.hpp"
#include "../Villager/Detective.hpp"
#include "../Villager/Doctor.hpp"
#include "../Villager/Villager.hpp"
#include "../main/defines.hpp"

using namespace std;

enum roles { joker, villager, mafia, silencer, godfather, doctor, detective, bulletproof, no_role };

struct User {
    string name;
    roles role;
};

class GameManager {
   public:
    GameManager();
    void handle_inputs();

   private:
    void handle_command(string command);
    void create_game_command();
    void assign_role_command();
    int find_user(string name);
    void set_user_role(int user, string role_);

    // Player* create_player(string name, string role);

    vector<User> users;
    vector<Player*> players;
    bool game_created;
    bool game_started;
};

#endif