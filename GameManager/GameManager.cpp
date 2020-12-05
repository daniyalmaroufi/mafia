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
    remove_users();
    while (ststream >> player_name) {
        User user;
        user.name = player_name;
        user.role = no_role;
        users.push_back(user);
    }
    game_created = true;
}

void GameManager::remove_users() {
    while (!users.empty()) users.pop_back();
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

void GameManager::create_players() {
    for (auto user : users) {
        if (user.role == joker) {
            players.push_back(new Joker(user.name));
        }
        if (user.role == villager) {
            players.push_back(new Villager(user.name));
        }
        if (user.role == detective) {
            players.push_back(new Detective(user.name));
        }
        if (user.role == doctor) {
            players.push_back(new Doctor(user.name));
        }
        if (user.role == bulletproof) {
            players.push_back(new BulletProof(user.name));
        }
        if (user.role == mafia) {
            players.push_back(new Mafia(user.name));
        }
        if (user.role == godfather) {
            players.push_back(new GodFather(user.name));
        }
        if (user.role == silencer) {
            players.push_back(new Silencer(user.name));
        }
    }
    remove_users();
}

void GameManager::start_game_command() {
    try {
        if (!game_created) throw NoGame();
        if (game_started) throw GameStarted();
        check_players_role();
        create_players();
        show_players_role();
        cout << "Ready? Set! Go." << endl;
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

void GameManager::show_players_role() {
    for (auto player : players) player->show_info();
}