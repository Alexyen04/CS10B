#include <iostream>
#include <vector> 
#include "Player.h"



using namespace std;

int main (){
    Player p;
    cout << p << endl;

    Player l("Lebron", "James", 23);
    cout << l << endl;

   cout << "Player p number: " << l.getPlayerNumber() << endl;
   l.setPlayerNumber(6);

   cout << "Player p new number: " << l.getPlayerNumber() << endl;
    return 0;
}