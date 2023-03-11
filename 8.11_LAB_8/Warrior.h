#include "Character.h"
#include <string> 
using namespace std;

#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior : public Character {
    public:
        Warrior(string name, double hp, double ad, string allg);
        void attack(Character&);
        const string & getAllegiance() const;
    private:
        string allegiance;
};

#endif