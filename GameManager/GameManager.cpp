#include "./GameManager.hpp"

GameManager::GameManager() { mafia = new Mafia(); }

void GameManager::handle_inputs() {
    string command;
    while (cin >> command) {
        if (!command.compare("create_game")) {
            create_game_command();
        }
    }
}

void GameManager::create_game_command() {
    string rest_of_command;
    getline(cin,rest_of_command);
    stringstream ststream(rest_of_command);
    string player_name;
    while (ststream >> player_name) mafia->add_player(player_name);
}