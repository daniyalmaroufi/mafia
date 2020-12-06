#include "./Mafia.hpp"

Mafia::Mafia(std::string name_) : Player(name_) {}

void Mafia::show_info() {
    std::cout << name << ": "
              << "mafia" << std::endl;
}

void Mafia::die_in_day() {
    status = mafia_dead;
    std::cout << name << " died" << std::endl;
}

bool Mafia::need_to_wake_up() { return false; }

bool Mafia::do_nighttask_on(Player* second_player) {
    if (second_player->get_status() != alive) throw DeadVotee();
    return true;
}

bool Mafia::is_mafia() { return true; }

void Mafia::die_in_night() {
    if(healed) return;
    status = mafia_dead;
    std::cout << name << " was killed" << std::endl;
}
