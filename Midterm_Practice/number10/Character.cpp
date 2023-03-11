#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(){
	name = "none";
	health = 0;
}

Character::Character(string n, int hp){
	name = n;
	health = hp;
}

string Character::getName(){
	return name;
}
int Character::getHealth(){
	return health;
}
void Character::setHealth(double hp){
	health = hp;
}
void Character::damage(double dmg){
	health -= dmg;
}
bool Character::isAlive(){
	if(health > 0){
		return true;
	} else {
		return false;
	}	
}
