#ifndef __DEFINES__
#define __DEFINES__

#define CREATE_GAME_COMMAND "create_game"
#define ASSIGN_ROLE_COMMAND "assign_role"
#define START_GAME_COMMAND "start_game"
#define END_VOTE_COMMAND "end_vote"

enum Player_status { alive, villager_dead, mafia_dead, joker_won, silenced };
enum Player_types { mafias, villagers, the_joker };

#endif