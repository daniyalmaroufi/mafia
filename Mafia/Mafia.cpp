#include "./Mafia.hpp"

Mafia::Mafia(std::string name_) : Player(name_) { }

void Mafia::show_info() {
    std::cout << name << ": "
              << "mafia" << std::endl;
}
