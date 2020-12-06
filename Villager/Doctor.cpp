#include "./Doctor.hpp"

Doctor::Doctor(std::string name_) : Villager(name_) {}

void Doctor::show_info() {
    std::cout << name << ": "
              << "doctor" << std::endl;
}

bool Doctor::need_to_wake_up() { return true; }

bool Doctor::do_nighttask_on(Player* second_player) {
    return false;
}
