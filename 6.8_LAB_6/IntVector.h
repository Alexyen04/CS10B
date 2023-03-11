#ifndef INTVECTOR_H
#define INTVECTOR_H
#include <iostream>

using namespace std;
 
class IntVector{
    public:
        IntVector();
        IntVector(unsigned capacity);
        IntVector(unsigned capacity, int value);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned index) const;
        const int & front() const;
        const int & back() const;
    private: 
        unsigned _size;
        unsigned _capacity;
        int *_data;
};

#endif