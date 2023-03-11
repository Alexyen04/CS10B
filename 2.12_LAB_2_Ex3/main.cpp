#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   vector <int> numsList;
   int num;
   int average = 0;
   ifstream inFS;
   ofstream outFS;

   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];

   // Create input stream and open input csv file.
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   // Read in integers from input file to vector.
   // Close input stream.
   // Get integer average of all values read in.
   // Convert each value within vector to be the difference between the original value and the average.
   inFS.open(inputFile);
   
   if(!inFS.is_open()){
      cout << "Error opening " << inputFile << endl;
      return 1;
   }

   while(inFS >> num){
      numsList.push_back(num);
      inFS.ignore();
   }

   inFS.close();
   
   for(unsigned int i = 0; i < numsList.size(); i++){
      average+= numsList[i];
   }
   average = average/numsList.size();
   
   for(unsigned int i = 0; i < numsList.size(); i++){
      numsList[i] = numsList[i] - average;
   }

   // Create output stream and open/create output csv file.
   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   // Write converted values into ouptut csv file, each integer separated by a comma.
   // Close output stream.
   outFS.open(outputFile);

   if(!outFS.is_open()){
      cout << "Error opening " << outputFile << endl;
      return 1;
   }
   
   for(unsigned int i = 0; i < numsList.size(); i++){
      outFS << numsList[i];
      if (i  < numsList.size()-1){
         outFS << ',';
      }
   }

   outFS.close();

   return 0;
}