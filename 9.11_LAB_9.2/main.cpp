#include <iostream>

using namespace std;

#include "minFunc.h"

int main() {
   int arrSize;
   cout << "Enter size: ";
   cin >> arrSize;
   cout << endl;
   if (arrSize > 0) {
      int arr[arrSize];
      for (int i = 0; i < arrSize; ++i) {
         cout << "Enter value at index " << i << ": ";
         cin >> arr[i];
         cout << endl;
      }
      const int *minLoc = min(arr, arrSize);
      cout << *minLoc << endl;
   }   
   return 0;
}
