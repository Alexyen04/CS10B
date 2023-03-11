#include <iostream>
#include "IntVector.h"

using namespace std;

int main(){
    IntVector v(10, 1);
    IntVector v1(10, 10);  
    IntVector v2(10, 10);
    IntVector v3;
    for(unsigned int i = 0; i<v1.size(); i++){
        v1.at(i) = i;
    }
  
    for(unsigned int i = 0; i<v2.size(); i++){
        v2.at(i) = i;
    }

    // //accessor tests
    // if(v.size() !=10){ cout << ".size() failed" << endl; }
    // if(v.capacity() != 10){ cout << ".capacity() failed" << endl; }
    // if(v.empty()){ cout << ".empty() failed" << endl; }
    // if(v.at(5) != 1){ cout << ".at(5) failed" << endl; }
    // if(v.front() != 1){ cout << ".front() failed" << endl; }
    // if(v.back() != 1){ cout << ".back() failed" << endl; }

    // //cout << "check out of bounds at index 999: " << v.at(999) << endl; -- passed
    
    // //at mutator test
    // v.at(5) = 10;
    // if(v.at(5) != 10){ cout << ".at(5) = 10 failed" << endl; }

    // //front and back tests
    // v.front() = 99;
    // v.back() = 99;
    // if(v.front() != 99){ cout << ".front()=99 failed" << endl;}
    // if(v.back() != 99) { cout << ".back()=99 failed" << endl;}
    
    // //push back test
    // v.push_back(11);
    // if(v.back() != 11){ cout << "push_back(11) failed" << endl; }
    // if(v.size() != 11){ cout << "expand(1) failed" << endl; }
    // if(v.capacity() != 20){ cout << "expand(1) failed" << endl; }

    // //resize test
    // v1.resize(20, 88);
    // if(v1.size() != 20){ cout << "resize failed" << endl;}

    // //reserve test
    // v.reserve(21);
    // if(v.capacity() != 21) { cout << "reserve failed" << endl;}

    // cout << "print vector v: "; 
    // for(unsigned int i = 0; i<v.size(); i++){
    //     cout << v.at(i) << " ";
    // }
    // cout << endl;

    // cout << "print vector v1: "; 
    // for(unsigned int i = 0; i<v1.size(); i++){
    //     cout << v1.at(i) << " ";
    // }
    // cout << endl;

    // //insert test
    // v1.insert(5, 7);
    // if(v1.at(5) != 7) { cout << "insert failed v1.insert(5,7)" << endl; }
    // v1.insert(0, 99); 
    // if(v1.at(0) != 99) { cout << "insert failed v1.insert(0,99)" << endl;} 
    // //v.insert(22, 7); //should throw out of bounds -- passed

    // cout << "print vector v1: "; 
    // for(unsigned int i = 0; i<v1.size(); i++){
    //     cout << v1.at(i) << " ";
    // }
    // cout << endl;

    // //erase test
    // v2.erase(8);
    // if(v2.size() != 9){ cout << "erase failed" << endl; }
    
    // cout << "print vector v2: "; 
    // for(unsigned int i = 0; i<v2.size(); i++){
    //     cout << v2.at(i) << " ";
    // }
    // cout << endl;
    
    // v3.assign(20, 1);
    // cout << "print vector v3: "; 
    // for(unsigned int i = 0; i<v3.size(); i++){
    //     cout << v3.at(i) << " ";
    // }
    // cout << endl;

    // cout << "v3 capacaity: " << v3.capacity() << endl;
    // v3.resize(20, 1);
    // cout << "v3 capacaity: " << v3.capacity() << endl;
    // cout << "v3 size: " << v3.size() << endl;
    // cout << "print vector v3: "; 
    // for(unsigned int i = 0; i<v3.size(); i++){
    //     cout << v3.at(i) << " ";
    // }
    // cout << endl;

    

    // v3.assign(20, 2);
    // cout << "print vector v3: "; 
    // for(unsigned int i = 0; i<v3.size(); i++){
    //     cout << v3.at(i) << " ";
    // }
    // cout << endl;


    return 0;
}
