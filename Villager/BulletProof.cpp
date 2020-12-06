#include "./BulletProof.hpp"

BulletProof::BulletProof(std::string name_) : Villager(name_) {
    killed_once = false;
}

void BulletProof::show_info() {
    std::cout << name << ": "
              << "bulletproof" << std::endl;
}

void BulletProof::die_in_day() {
    if (killed_once) {
        status = villager_dead;
        std::cout << name << " died" << std::endl;
    } else
        killed_once = true;
}
