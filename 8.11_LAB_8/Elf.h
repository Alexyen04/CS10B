#include "Character.h"
#include <string> 
using namespace std;

#ifndef ELF_H
#define ELF_H

class Elf : public Character {
    public:
        Elf(string name, double hp, double ad, string fam);
        void attack(Character&);
        const string & getFamily() const;
    private:
        string family;
};

#endif