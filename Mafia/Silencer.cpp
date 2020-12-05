#include "./Silencer.hpp"

Silencer::Silencer(std::string name_) : Mafia(name_) {}

void Silencer::show_info() {
    std::cout << name << ": "
              << "silencer" << std::endl;
}
