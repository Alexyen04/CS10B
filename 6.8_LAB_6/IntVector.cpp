#include "IntVector.h"
#include <iostream>
#include <stdexcept>


using namespace std;

IntVector::IntVector(){
    _capacity = 0;
    _size = 0;
    _data = nullptr;
}

IntVector::IntVector(unsigned capacity){
    if(capacity == 0){
        _data = nullptr;
    } else {
        _data  = new int[capacity];
        for(unsigned int i = 0; i < capacity; i++){
            _data[i] = 0;
        }
    }
    _capacity = capacity;
    _size = capacity;
}
IntVector::IntVector(unsigned capacity, int value){
    if(capacity == 0){
        _data = nullptr;
    } else {
        _data  = new int[capacity];
        for(unsigned int i = 0; i < capacity; i++){
            _data[i] = value;
        }
    }
    _capacity = capacity;
    _size = capacity;
}

IntVector::~IntVector(){
    delete _data;
}

unsigned IntVector::size()const{
    return _size;
}

unsigned IntVector::capacity()const{
    return _capacity;
}

bool IntVector::empty() const{
    return (_size == 0);
}

const int& IntVector::at(unsigned index) const{
    if(index >= _size){
        throw out_of_range("IntVector::at_range_check");
    } else {
        return _data[index];
    }
}

const int& IntVector::front() const{
    return _data[0];
}
const int& IntVector::back() const{
    return _data[_size-1];
}






