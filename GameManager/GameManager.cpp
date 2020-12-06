#include "./GameManager.hpp"

GameManager::GameManager() {
    game_started = false;
    day_counter = 0;
}

void GameManager::handle_inputs() {
    string command;
    while (cin >> command) {
        handle_command(command);
        if (winner == the_joker) {
            cout << "Joker won" << endl;
            return;
        }
    }
}

void GameManager::handle_command(string command) {
    if (!command.compare(CREATE_GAME_COMMAND)) {
        create_game_command();
        return;
    }

    if (!command.compare(ASSIGN_ROLE_COMMAND)) {
        assign_role_command();
        return;
    }

    if (!command.compare(START_GAME_COMMAND)) {
        start_game_command();
        return;
    }

    if (phase == day && game_started) {
        if (!command.compare(END_VOTE_COMMAND))
            end_vote();
        else
            vote_in_day(command);
        return;
    }
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
        cout << ex.what();
    } catch (NoGame& ex) {
        cout << ex.what();
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
        game_started = true;
        cout << "Ready? Set! Go." << endl;
        start_day();

    } catch (NoGame& ex) {
        cout << ex.what();
    } catch (NoRole& ex) {
        cout << ex.what();
    } catch (GameStarted& ex) {
        cout << ex.what();
    }
}

void GameManager::check_players_role() {
    for (int i = 0; i < users.size(); i++)
        if (users[i].role == no_role) throw NoRole();
}

void GameManager::show_players_role() {
    for (auto player : players) player->show_info();
}

void GameManager::start_day() {
    phase = day;
    day_counter += 1;
    cout << "Day: " << day_counter << endl;
}

void GameManager::vote_in_day(string voter) {
    try {
        string votee;
        cin >> votee;
        find_player(voter);
        find_player(votee);
        votes[voter] = votee;
    } catch (NoUser& ex) {
        cout << ex.what();
    }
}

Player* GameManager::find_player(string name) {
    for (auto player : players)
        if (player->is_name(name)) return player;

    throw NoUser();
}

void GameManager::end_vote() {
    string selected_player = find_selected();
    find_player(selected_player)->die_in_day();
    if (!check_winner()) {
        // start_night();
    }
}

string GameManager::find_selected() {
    map<string, int> votes_count;
    for (auto vote : votes) {
        votes_count[vote.second] += 1;
    }

    string selected = votes_count.begin()->first;
    for (auto vote_count : votes_count)
        if (votes_count[selected] < vote_count.second)
            selected = vote_count.first;
        else if (votes_count[selected] = vote_count.second)
            if (vote_count.first < selected) selected = vote_count.first;

    return selected;
}

bool GameManager::check_winner() {
    map<Player_status, int> players_status;
    for (auto player : players) {
        players_status[player->get_status()] += 1;
        if (player->get_status() == joker_won) {
            winner = the_joker;
            return true;
        }
    }
    return false;
}
