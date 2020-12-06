#ifndef __GODFATHER__
#define __GODFATHER__

#include <iostream>
#include <vector>
#include <string>
#include "../main/defines.hpp"
#include "./Mafia.hpp"

class GodFather : public Mafia {
   public:
    GodFather(std::string name_);
    GodFather(){};
    void show_info();
    bool is_mafia();

   private:
};

#endif
