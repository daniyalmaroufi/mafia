#include "./Joker.hpp"

Joker::Joker(std::string name_) : Player(name_) {}

void Joker::show_info() {
    std::cout << name << ": "
              << "joker" << std::endl;
}

void Joker::die_in_day() {
    status = joker_won;
    std::cout << name << " died" << std::endl;
}

bool Joker::need_to_wake_up() { return false; }

bool Joker::do_nighttask_on(Player* second_player) { return false; }

bool Joker::is_mafia() { return false; }
