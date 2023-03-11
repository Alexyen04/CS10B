#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

class Player {
    private:
        string firstName;
        string lastName;
        int playerNumber;

    public:
        Player();
        Player(const string &, const string &, int);
        string getFirstName() const;
        string getLastName() const;
        int getPlayerNumber() const;
        void setFirstName(const string &);
        void setLastName(const string &);
        void setPlayerNumber(int);
        /* Outputs to the stream a Player in the format:
        Player #: first name last name
        e.g.
        10: Lionel Messi 
        Does not output a newline.
        */
        friend ostream & operator<<(ostream &, const Player &);
};

#endif