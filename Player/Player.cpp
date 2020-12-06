#include "./Player.hpp"

Player::Player(std::string name_) {
    name = name_;
    status = alive;
    healed = false;
}

bool Player::is_name(std::string name_) { return name == name_; }

Player_status Player::get_status() { return status; }

bool Player::need_to_wake_up() { return false; }

void Player::heal() { healed = true; }

void Player::silence() { silent = true; }

void Player::assult() {
    std::cout << "Mafia tried to kill " << name << std::endl;
}

bool Player::is_healed() { return healed; }

bool Player::is_silent() { return silent; }

void Player::unsilence() { silent = false; }

std::string Player::get_name() { return name; }

void Player::change_character_to(std::string name_, bool silent_) {
    name = name_;
    if (silent_)
        silence();
    else
        unsilence();
}
