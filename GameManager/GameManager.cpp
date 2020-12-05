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

int GameManager::find_user(string name) {
    for (int i = 0; i < users.size(); i++)
        if (users[i].name == name) return i;

    return -1;
}

void GameManager::assign_role_command() {
    if (!game_created) {
        // dfd
    }
    string name, role;
    cin >> name >> role;
    int user = find_user(name);
    if (user == -1) {
        // throw exception
    }
    set_user_role(user, role);
    // remove previous player
    // create new object
    // replace pointer
}

void GameManager::set_user_role(int user, string role_) {
    if (role_ == "joker") users[user].role = joker;
    if (role_ == "villager") users[user].role = villager;
    if (role_ == "detective") users[user].role = detective;
    if (role_ == "doctor") users[user].role = doctor;
    if (role_ == "bulletproof") users[user].role = bulletproof;
    if (role_ == "mafia") users[user].role = mafia;
    if (role_ == "godfather") users[user].role = godfather;
    if (role_ == "silencer") users[user].role = silencer;
}

// Player* GameManager::create_player(User) {
//     switch (role_)
//     {
//     case "joker":
//         return new Joker(name);
//         break;
//     }
// }
