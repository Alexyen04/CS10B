#include "Wizard.h"
#include <iostream>

using namespace std;

Wizard::Wizard(string name, double hp, double ad, int r)
    : Character(WIZARD, name, hp, ad) {
        rank = r;
}

void Wizard::attack(Character& opponent){
    if(opponent.getType() == WIZARD){
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        double dmg = (this->attackStrength)*((double)this->rank / (double)opp.getRank());
        opp.damage(dmg);
        cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!"<<endl;
        cout << opponent.getName() << " takes " << dmg << " damage." << endl;
    } else {
        opponent.damage(this->attackStrength);
        cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << this->attackStrength << " damage." << endl;
    }
}

const int Wizard::getRank() const{
    return rank;
}