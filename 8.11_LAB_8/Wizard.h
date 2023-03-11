#include "Character.h"
#include <string> 
using namespace std;

#ifndef WIZARD_H
#define WIZARD_H

class Wizard : public Character {
    public:
        Wizard(string name, double hp, double ad, int r);
        void attack(Character&);
        const int getRank() const;
    private:
        int rank;
};

#endif