#ifndef __JOKER__
#define __JOKER__

#include <iostream>
#include <string>
#include <vector>

#include "../Player/Player.hpp"
#include "../main/defines.hpp"

class Joker : public Player {
   public:
    Joker(std::string name_);
    Joker(){};
    void show_info();

   private:
};

#endif
