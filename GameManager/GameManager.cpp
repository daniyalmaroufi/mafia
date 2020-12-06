#include "./GameManager.hpp"

GameManager::GameManager() {
    game_created = false;
    game_started = false;
    day_counter = 0;
    night_counter = 0;
    swaped = false;
    can_swap = false;
    alive_mafia = 0;
    alive_villager = 0;
}

void GameManager::handle_inputs() {
    string command;
    while (cin >> command) {
        handle_command(command);
        if (winner == the_joker) {
            cout << "Joker won";
            return;
            // reset_game();
        }
        if (winner == the_villagers) {
            cout << "Villagers won";
            return;
        }
        if (winner == the_mafias) {
            cout << "Mafia won";
            return;
        }
    }
}

void GameManager::handle_command(string command) {
    if (!command.compare(CREATE_GAME_COMMAND)) {
        create_game_command();
        return;
    }

    if (!command.compare(ASSIGN_ROLE_COMMAND) && !game_started) {
        assign_role_command();
        return;
    }

    if (!command.compare(START_GAME_COMMAND)) {
        start_game_command();
        return;
    }

    if (!command.compare(SWAP_COMMAND) && game_created) {
        swap_character();
        return;
    } else {
        can_swap = false;
    }

    if (!command.compare(GAME_STATE_COMMAND) && game_created) {
        game_state();
        return;
    }

    if (phase == day && game_started) {
        if (!command.compare(END_VOTE_COMMAND))
            end_vote();
        else
            vote_in_day(command);
        return;
    }

    if (phase == night && game_started) {
        if (!command.compare(END_NIGHT_COMMAND))
            end_night();
        else
            vote_in_night(command);
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
    } catch (NoGame& ex) {
        cout << ex.what();
    } catch (NoUser& ex) {
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
            alive_villager += 1;
        }
        if (user.role == detective) {
            players.push_back(new Detective(user.name));
            alive_villager += 1;
        }
        if (user.role == doctor) {
            players.push_back(new Doctor(user.name));
            alive_villager += 1;
        }
        if (user.role == bulletproof) {
            players.push_back(new BulletProof(user.name));
            alive_villager += 1;
        }
        if (user.role == mafia) {
            players.push_back(new Mafia(user.name));
            alive_mafia += 1;
        }
        if (user.role == godfather) {
            players.push_back(new GodFather(user.name));
            alive_mafia += 1;
        }
        if (user.role == silencer) {
            players.push_back(new Silencer(user.name));
            alive_mafia += 1;
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

    } catch (NoRole& ex) {
        cout << ex.what();
    } catch (NoGame& ex) {
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
    cout << "Day " << day_counter << endl;
}

void GameManager::vote_in_day(string voter) {
    try {
        string votee;
        cin >> votee;
        Player* the_voter = find_player(voter);
        if (the_voter->is_silent()) throw SilentVoter();
        if (the_voter->get_status() != alive) throw DeadUser();
        if (find_player(votee)->get_status() != alive) throw DeadVotee();
        votes[voter] = votee;
    } catch (NoUser& ex) {
        cout << ex.what();
    } catch (DeadUser& ex) {
        cout << ex.what();
    } catch (SilentVoter& ex) {
        cout << ex.what();
    } catch (DeadVotee& ex) {
        cout << ex.what();
    }
}

Player* GameManager::find_player(string name) {
    for (auto player : players)
        if (player->is_name(name)) return player;
    throw NoUser();
}

void GameManager::end_vote() {
    if (!votes.empty()) {
        string selected_player = find_selected();
        find_player(selected_player)->die_in_day();
        count_alive(find_player(selected_player));
        votes.clear();
    }

    if (!check_winner()) start_night();
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
    if (alive_mafia == 0) {
        winner = the_villagers;
        return true;
    }
    if (alive_villager <= alive_mafia) {
        winner = the_mafias;
        return true;
    }
    return false;
}

void GameManager::count_alive(Player* the_player) {
    if (the_player->get_status() == mafia_dead)
        alive_mafia -= 1;
    else if (the_player->get_status() == villager_dead)
        alive_villager -= 1;
}

void GameManager::start_night() {
    phase = night;
    night_counter += 1;
    cout << "Night " << night_counter << endl;
    for (auto player : players) {
        player->unsilence();
        if (player->need_to_wake_up() && player->get_status() == alive) {
            player->show_info();
            player->reset_to_first_night();
        }
    }
}

void GameManager::vote_in_night(string voter) {
    try {
        string votee;
        cin >> votee;
        auto the_voter = find_player(voter);
        if (!the_voter->need_to_wake_up()) throw CannotWakeup();
        if (the_voter->get_status() != alive) throw DeadUser();

        auto the_votee = find_player(votee);
        if (the_voter->do_nighttask_on(the_votee)) votes[voter] = votee;

    } catch (CannotWakeup& ex) {
        cout << ex.what();
    } catch (NoUser& ex) {
        cout << ex.what();
    } catch (DeadUser& ex) {
        cout << ex.what();
    } catch (DeadVotee& ex) {
        cout << ex.what();
    } catch (DetectiveAsked& ex) {
        cout << ex.what();
    } catch (DeadSuspect& ex) {
        cout << ex.what();
    } catch (DoctorHealed& ex) {
        cout << ex.what();
    } catch (DeadPatient& ex) {
        cout << ex.what();
    }
}

void GameManager::end_night() {
    string selected_player = find_selected();
    auto assulted_player = find_player(selected_player);
    if (assulted_player) assulted_player->assult();
    start_day();
    assulted_player->die_in_night();
    count_alive(assulted_player);
    show_silents();
    can_swap = true;
    swaped = false;
    votes.clear();
    check_winner();
}

void GameManager::show_silents() {
    set<string> silents;
    for (auto player : players)
        if (player->is_silent()) silents.insert(player->get_name());
    if (!silents.empty()) {
        cout << "Silenced";
        for (auto silent : silents) cout << " " << silent;
        cout << endl;
    }
}
void GameManager::swap_character() {
    try {
        string first_name;
        cin >> first_name;
        string second_name;
        cin >> second_name;
        auto first_player = find_player(first_name);
        if (first_player->get_status() != alive) throw DeadUser();
        auto second_player = find_player(second_name);
        if (second_player->get_status() != alive) throw DeadUser();
        if (phase == night) throw NightSwap();
        if (!can_swap) throw DaySwap();
        if (swaped) throw Swapped();

        do_swap(first_player, second_player);

    } catch (NoUser& ex) {
        cout << ex.what();
    } catch (DeadUser& ex) {
        cout << ex.what();
    } catch (Swapped& ex) {
        cout << ex.what();
    } catch (NightSwap& ex) {
        cout << ex.what();
    } catch (DaySwap& ex) {
        cout << ex.what();
    }
}

void GameManager::do_swap(Player* first_player, Player* second_player) {
    string first_name = first_player->get_name();
    bool first_silent = first_player->is_silent();
    string second_name = second_player->get_name();
    bool second_silent = second_player->is_silent();
    second_player->change_character_to(first_name, first_silent);
    first_player->change_character_to(second_name, second_silent);
    int first_player_place;
    int second_player_place;
    for (int i = 0; i < players.size(); i++) {
        if (players[i] == first_player) first_player_place = i;
        if (players[i] == second_player) second_player_place = i;
    }
    players[first_player_place] = second_player;
    players[second_player_place] = first_player;
    swaped = true;
}

void GameManager::game_state() {
    cout << "Mafia = " << alive_mafia << endl;
    cout << "Villager = " << alive_villager << endl;
}
