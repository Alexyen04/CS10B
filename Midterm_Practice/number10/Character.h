#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>

using namespace std;

class Character {
	public:
		Character();
		Character(string n, int hp);
		string getName();
		int getHealth();
		void setHealth(double hp);
		void damage(double dmg);
		bool isAlive();
	private:
		string name;
		double health;
};

#endif
