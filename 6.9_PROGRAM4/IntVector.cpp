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
    delete[] _data;
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

int & IntVector::at(unsigned index){
    if(index >= _size){
        throw out_of_range("IntVector::at_range_check");
    } else {
        return _data[index];
    }
}

const int& IntVector::front() const{
    return _data[0];
}

int& IntVector::front(){
    return _data[0];
}

const int& IntVector::back() const{
    return _data[_size-1];
}

int& IntVector::back(){
    return _data[_size-1];
}

void IntVector::assign(unsigned n, int value){
    if(n > _size && n > _capacity){
        if(_capacity*2 > (_size)+(n-_capacity)){
            expand();
        } else {
            expand(n-_capacity);
        }
        _size = n;
    } else {
        _size = n;
    }
    for(unsigned int i = 0; i < _size; i++){
        _data[i] = value;
    }
}

void IntVector::push_back(int value){
    if(_size == _capacity){
        expand();
    } 
    _size++;
    _data[_size-1] = value;
}

void IntVector::pop_back(){
    _size--;
}

void IntVector::clear(){
    _size = 0;
}

void IntVector::resize(unsigned size, int value){

    if(size < _size){
        _size = size;
    } else if(size > _size && size < _capacity){
        for(unsigned int i = _size; i < size; i++){
            _data[i] = value;
        }
        _size = size;
    } else {
        if (_capacity*2 > (_size)+(size-_capacity)){
            expand();
            for(unsigned int i = _size; i < size; i++){
                _data[i] = value;
            }
            _size = size;
        } else {
            expand(size-_capacity);
            for(unsigned int i = _size; i < size; i++){
                _data[i] = value;
            }
            _size = size;
        }
    }

}

void IntVector::reserve(unsigned n){
    if (n > _capacity){
        _capacity = n;
    }
}

void IntVector::expand(){
    
    if(_capacity == 0){
        _capacity = 1;
    } else {
        _capacity = _capacity*2;
    }

    int* temp = new int[_capacity];
    for(unsigned int i = 0; i < _size; i++){
        temp[i] = _data[i];
    }
    delete[] _data;
    _data = temp;
}

void IntVector::expand(unsigned amount){
    _capacity += amount;

    int* temp = new int[_capacity];
    for(unsigned int i = 0; i < _size; i++){
        temp[i] = _data[i];
    }
    delete[] _data;
    _data = temp;
}

void IntVector::insert(unsigned index, int value){
    
    if(index > _size){
        throw out_of_range("IntVector::insert_range_check");
    } else {
        if(_size == _capacity){
        expand();
        _size++;
        } else { _size++; }
        for(unsigned int i = _size; i > index; i--){
            _data[i] = _data[i-1];
        }
        _data[index] = value;
    }

}

void IntVector::erase(unsigned index){
    if(index >= _size || _size == 0){
        throw out_of_range("IntVector::erase_range_check");
    } else {
        for(unsigned int i = index; i <= _size; i++){
            _data[i] = _data[i+1];
        }
        _size--;
    }
}



