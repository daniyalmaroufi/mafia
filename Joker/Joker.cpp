#include "./Joker.hpp"

Joker::Joker(std::string name_) : Player(name_) {}

void Joker::show_info() {
    std::cout << name << ": "
              << "joker" << std::endl;
}

void Joker::die_in_day() { status = joker_won; }
