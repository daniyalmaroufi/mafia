#include "./GameManager.hpp"

GameManager::GameManager() { game_started = false; }

void GameManager::handle_inputs() {
    string command;
    while (cin >> command) {
        handle_command(command);
    }
}

void GameManager::handle_command(string command) {
    if (!command.compare(CREATE_GAME_COMMAND) && !game_started)
        create_game_command();

    if (!command.compare(ASSIGN_ROLE_COMMAND) && !game_started)
        assign_role_command();
}

void GameManager::create_game_command() {
    string rest_of_command;
    getline(cin, rest_of_command);
    stringstream ststream(rest_of_command);
    string player_name;
    while (!players.empty()) {
        delete players.back();
        players.pop_back();
    }
    while (ststream >> player_name) {
        User user;
        user.name = player_name;
        user.role = no_role;
        users.push_back(user);
    }
}

void GameManager::add_player(string player_name) {
    players.push_back(new Player(player_name));
}

void GameManager::assign_role_command() {
    // if user exists
    // find user in players
    // remove previous player
    // create new object
    // replace pointer
}
