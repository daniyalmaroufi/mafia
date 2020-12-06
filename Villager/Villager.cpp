#include "./Villager.hpp"

Villager::Villager(std::string name_) : Player(name_) {}

void Villager::show_info() {
    std::cout << name << ": "
              << "villager" << std::endl;
}

void Villager::die_in_day() {
    status = villager_dead;
    std::cout << name << " died" << std::endl;
}

bool Villager::do_nighttask_on(Player* second_player) {
    return false;
}
