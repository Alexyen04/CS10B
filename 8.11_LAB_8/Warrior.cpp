#include "Warrior.h"
#include <iostream>

Warrior::Warrior(string name, double hp, double ad, string alleg)
    : Character(WARRIOR, name, hp, ad) {
        allegiance = alleg;
}

const string & Warrior::getAllegiance() const{
    return allegiance;
}
void Warrior::attack(Character& opponent){
    double dmg = (this->health / MAX_HEALTH) * this->attackStrength;
    if(opponent.getType() == WARRIOR){
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if(this->allegiance != opp.getAllegiance()){
            opp.damage(dmg);
            cout << "Warrior " << this->name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
            cout << opponent.getName() << " takes " << dmg << " damage." << endl;
        } else {
            cout << "Warrior " << this->name << " does not attack Warrior " << opponent.getName() << "."<< endl;
            cout << "They share an allegiance with " << this->allegiance << "." << endl;
        }
    } else {
        opponent.damage(dmg);
        cout << "Warrior " << this->name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << dmg << " damage." << endl;
    }
}