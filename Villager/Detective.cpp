#include "./Detective.hpp"

Detective::Detective(std::string name_) : Villager(name_) {
    done_nighttask = false;
}

void Detective::show_info() {
    std::cout << name << ": "
              << "detective" << std::endl;
}

bool Detective::need_to_wake_up() { return true; }

bool Detective::do_nighttask_on(Player* second_player) {
    if (!done_nighttask) {
        if (second_player->get_status() != alive) throw DeadSuspect();
        if (second_player->is_mafia())
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;

        done_nighttask = true;
    }else{
        throw DetectiveAsked();
    }
    return false;
}
