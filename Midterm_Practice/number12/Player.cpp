#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(){
    firstName = "Lionel";
    lastName = "Messi";
    playerNumber = 10;
}

Player::Player(const string &fname , const string &lname, int num){
    firstName = fname;
    lastName = lname;
    playerNumber = num;
}

int Player::getPlayerNumber() const{
    return playerNumber;
}

void Player::setPlayerNumber(int num){
    playerNumber = num;
}

ostream & operator<<(ostream &out , const Player &p){
    out << p.playerNumber << ": " << p.firstName << " " << p.lastName;
    return out;
}