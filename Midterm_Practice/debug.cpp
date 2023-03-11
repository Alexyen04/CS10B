#include <iostream>
using namespace std;

void myFunction(int* arrayPointer)
{
    cout << "Currently in display function!" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *(arrayPointer + i) << ' ';
    }
    cout << endl;
}

int main()
{
    cout << "Starting program..." << endl;
    int myArray[5];
    int* arrayPointer = myArray;
    int input;
    cout << "Input 5 numbers: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> input; 
        *(arrayPointer + i) = input;
    }
    cout << "Entering function..." << endl;
    myFunction(arrayPointer);
    cout << "Ending program..." << endl;
}