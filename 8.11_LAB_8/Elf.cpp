#include "Elf.h"
#include <iostream>

using namespace std;

Elf::Elf(string name, double hp, double ad, string fam)
    : Character(ELF, name, hp, ad) {
        family = fam;
}

void Elf::attack(Character& opponent){ 
    double dmg = (this->health / MAX_HEALTH) * this->attackStrength;
    if(opponent.getType() == ELF){
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if(this->family != opp.getFamily()){
            opp.damage(dmg);
            cout << "Elf " << this->name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
            cout << opponent.getName() << " takes " << dmg << " damage." << endl;
        } else {
            cout << "Elf " << this->name << " does not attack Elf " << opponent.getName() << "." << endl;
            cout << "They are both members of the " << this->family << " family." << endl;
        }
    } else {
        opponent.damage(dmg);
        cout << "Elf " << this->name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << dmg << " damage." << endl;
    }
}

const string & Elf::getFamily() const{
    return family;
}