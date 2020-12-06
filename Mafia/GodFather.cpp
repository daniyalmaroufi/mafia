#include "./GodFather.hpp"

GodFather::GodFather(std::string name_) : Mafia(name_) {}

void GodFather::show_info() {
    std::cout << name << ": "
              << "godfather" << std::endl;
}

bool GodFather::need_to_wake_up() { return true; }

bool GodFather::is_mafia() { return false; }
