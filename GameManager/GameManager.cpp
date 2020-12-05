#include "./GameManager.hpp"

GameManager::GameManager() { game_started = false; }

void GameManager::handle_inputs() {
    string command;
    while (cin >> command) {
        handle_command(command);
    }
}

void GameManager::handle_command(string command) {
    if (!command.compare(CREATE_GAME_COMMAND)) create_game_command();

    if (!command.compare(ASSIGN_ROLE_COMMAND)) assign_role_command();

    if (!command.compare(START_GAME_COMMAND)) start_game_command();
}

void GameManager::create_game_command() {
    string rest_of_command;
    getline(cin, rest_of_command);
    stringstream ststream(rest_of_command);
    string player_name;
    while (!users.empty()) users.pop_back();

    while (ststream >> player_name) {
        User user;
        user.name = player_name;
        user.role = no_role;
        users.push_back(user);
    }
    game_created = true;
}

int GameManager::find_user(string name) {
    for (int i = 0; i < users.size(); i++)
        if (users[i].name == name) return i;

    throw NoUser();
}

void GameManager::assign_role_command() {
    try {
        if (!game_created) throw NoGame();
        string name, role;
        cin >> name >> role;
        int user = find_user(name);
        cout << name << ": " << role << endl;
        set_user_role(user, role);
    } catch (NoUser& ex) {
        cout << ex.what() << endl;
    } catch (NoGame& ex) {
        cout << ex.what() << endl;
    }
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

void GameManager::start_game_command() {
    try {
        if (!game_created) throw NoGame();
        if (game_started) throw GameStarted();
        check_players_role();
        // create players
    } catch (NoGame& ex) {
        cout << ex.what() << endl;
    } catch (NoRole& ex) {
        cout << ex.what() << endl;
    } catch (GameStarted& ex) {
        cout << ex.what() << endl;
    }
}

void GameManager::check_players_role() {
    for (int i = 0; i < users.size(); i++)
        if (users[i].role == no_role) throw NoRole();
}
