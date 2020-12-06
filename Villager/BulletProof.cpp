#include "./BulletProof.hpp"

BulletProof::BulletProof(std::string name_) : Villager(name_) {
    killed_once = false;
}

void BulletProof::show_info() {
    std::cout << name << ": "
              << "bulletproof" << std::endl;
}

void BulletProof::die_in_night() {
    if (killed_once) {
        Villager::die_in_night();
    } else {
        killed_once = true;
    }
}
