#include "./Doctor.hpp"

Doctor::Doctor(std::string name_) : Villager(name_) { done_nighttask = false; }

void Doctor::show_info() {
    std::cout << name << ": "
              << "doctor" << std::endl;
}

bool Doctor::need_to_wake_up() { return true; }

bool Doctor::do_nighttask_on(Player* second_player) {
    if (!done_nighttask) {
        if (second_player->get_status() != alive) throw DeadPatient();
        second_player->heal();

        done_nighttask = true;
    } else {
        throw DoctorHealed();
    }
    return false;
}
