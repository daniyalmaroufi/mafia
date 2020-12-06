#ifndef __GAME_MANAGER__
#define __GAME_MANAGER__

#include <iostream>
#include <map>
#include <set>
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
#include "./Exceptions.hpp"

using namespace std;

enum roles {
    joker,
    villager,
    mafia,
    silencer,
    godfather,
    doctor,
    detective,
    bulletproof,
    no_role
};

enum game_phase { day, night };

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
    void remove_users();
    void set_user_role(int user, string role_);
    void start_game_command();
    void check_players_role();
    void create_players();
    void show_players_role();
    void start_day();
    void vote_in_day(string voter);
    Player* find_player(string name);
    void end_vote();
    string find_selected();
    bool check_winner();
    void count_alive(Player* the_player);
    void start_night();
    void vote_in_night(string voter);
    void end_night();
    void show_silents();
    void swap_character();
    void do_swap(Player* first_player, Player* second_player);
    void game_state();

    vector<User> users;
    vector<Player*> players;
    bool game_created;
    bool game_started;
    int day_counter;
    int night_counter;
    game_phase phase;
    map<string, string> votes;
    Player_types winner;
    bool can_swap;
    bool swaped;
    int alive_mafia;
    int alive_villager;
};

#endif