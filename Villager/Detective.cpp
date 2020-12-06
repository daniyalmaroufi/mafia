#include "./Detective.hpp"

Detective::Detective(std::string name_) : Villager(name_) {}

void Detective::show_info() {
    std::cout << name << ": "
              << "detective" << std::endl;
}

bool Detective::need_to_wake_up() { return true; }

bool Detective::do_nighttask_on(Player* second_player) {
    return false;
}
