#include "IntList.h"
#include "SortedSet.h"


#include <iostream>

using namespace std;

int main() {
    cout << "Enter a test number(1-3): ";
	int test;
	cin >> test;
	cout << endl;

    if(test == 1){
        IntList List1;
        cout << "pushfront 10" << endl;
        List1.push_front(10);
        cout << "pushfront 20" << endl;
        List1.push_front(20);
        cout << "pushfront 30" << endl;
        List1.push_front(30);
        cout << "List1: " << List1 << endl;

        SortedSet Set1(List1);
        cout << "Set1: " << Set1 << endl;

        SortedSet Set2(Set1);
        cout << "Set2: " << Set2 << endl;

        cout << "1 = true, 0 = false" << endl;
        cout << Set1.in(10) << endl;
        cout << Set1.in(100) << endl;
    }

    if(test == 2){
        SortedSet Set2;
        Set2.add(1);
        Set2.add(42);
        Set2.add(11);
        Set2.add(54);
        Set2.add(-1);
        Set2.add(98);
        cout << "Set2: " << Set2 << endl;

        SortedSet Set3;
        Set3.add(200);
        Set3.add(42);
        Set3.add(11);
        Set3.add(57);
        Set3.add(-1);
        Set3.add(98);
        cout << "Set3: " << Set3 << endl;

        SortedSet Set4;
        Set4 = Set2 | Set3;
        cout << "Set4 = Set2 | Set3" << endl; 
        cout << "Set4: " << Set4 << endl;

        SortedSet Set5;
        Set5 = Set2 & Set3;
        cout << "Set5 = Set2 & Set3" << endl;
        cout << "Set5: " << Set5 << endl;
    }

    if(test == 3){
        SortedSet Set3;
        Set3.add(1);
        Set3.add(2);
        Set3.add(3);
        Set3.add(4);
        Set3.add(5);
        Set3.add(6);
        cout << "Set3: " << Set3 << endl;

        SortedSet Set4;
        Set4.add(1);
        Set4.add(3);
        Set4.add(5);
        Set4.add(7);
        Set4.add(9);
        Set4.add(11);
        cout << "Set4: " << Set4 << endl;

        cout << "Set4 |= Set3" << endl;
        Set4 |= Set3;
        cout << "Set4: " << Set4 << endl;

        cout << "Set3 &= Set4" << endl;
        Set3 &= Set4;
        cout << "Set3: " << Set3 << endl;

        

        
    }
    return 0;
}

