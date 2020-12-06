#include "./Silencer.hpp"

Silencer::Silencer(std::string name_) : Mafia(name_) {}

void Silencer::show_info() {
    std::cout << name << ": "
              << "silencer" << std::endl;
}

bool Silencer::do_nighttask_on(Player* second_player) {
    return false;
    return true;
}
