#ifndef __SILENCER__
#define __SILENCER__

#include <iostream>
#include <vector>
#include <string>
#include "../main/defines.hpp"
#include "./Mafia.hpp"

class Silencer : public Mafia {
   public:
    Silencer(std::string name_);
    Silencer(){};
    void show_info();
    
   private:
};

#endif
