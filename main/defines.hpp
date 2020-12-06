#ifndef __DEFINES__
#define __DEFINES__

#define CREATE_GAME_COMMAND "create_game"
#define ASSIGN_ROLE_COMMAND "assign_role"
#define START_GAME_COMMAND "start_game"
#define END_VOTE_COMMAND "end_vote"
#define END_NIGHT_COMMAND "end_night"
#define SWAP_COMMAND "swap_character"

enum Player_status {
    alive,
    villager_dead,
    mafia_dead,
    joker_won,
    joker_dead,
    silent
};

enum Player_types { mafias, villagers, the_joker };

#endif