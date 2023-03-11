#include <iostream>
#include "IntVector.h"

using namespace std;

int main(){
    IntVector v(10,1);
    cout << "vector size: " << v.size() << endl;
    cout << "vector capacity: " << v.capacity() << endl;
    cout << "vector empty? " << v.empty() << endl; //1 true, 0 false
    cout << "value at index 5 is: " << v.at(5) << endl;
    cout << "value at front: " << v.front() << endl;
    cout << "value at back: " << v.back() << endl;
    cout << "check out of bounds at index 11: " << v.at(11) << endl;

    return 0;
}