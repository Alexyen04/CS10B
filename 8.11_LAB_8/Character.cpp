#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(HeroType t, const string &n, double h, double a){
    type = t;
    name = n;
    health = h;
    attackStrength = a;

}
HeroType Character::getType() const{
    return type;
}

const string & Character::getName() const{
    return name;
}

int Character::getHealth() const{
    return (int)health;
}

void Character::damage(double d){
    health -= d;
}
bool Character::isAlive() const{
    return (health!=0);
}