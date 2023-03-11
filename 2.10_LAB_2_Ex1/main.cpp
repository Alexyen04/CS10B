#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;


// Place fileSum prototype (declaration) here
int fileSum(string filename);

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   if(sum != 0) {
      cout << "Sum: " << sum << endl;
   } else {
      return 0;
   }
   
}

// Place fileSum implementation here
int fileSum(string filename){
   ifstream inFS;
   int total = 0;
   int num = 0;

   inFS.open(filename);
   if(!inFS.is_open()){
      cout << "Error opening " << filename << endl;
   } else {
      while(inFS >> num){
         total += num;
      }
   }
   return total;
}