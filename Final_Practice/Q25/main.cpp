#include <iostream>

using namespace std;

void printPattern(int n1, int n2);

int main (){
    printPattern(4,1);
    return 0;
}   

void printPattern(int n1, int n2){
    cout << n1 << " ";
    if(n1 >= 0){
        printPattern(n1-n2, n2);
        cout << n1 << " ";
    }
}