#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here
void flipString (string &s){
   string temp;
   if(s.size() == 0){
      return;
   } else {
      temp = s.substr(1,s.length());
      flipString(temp);
      s = temp + s.front();
   }
}


