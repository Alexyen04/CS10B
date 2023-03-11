#include "IntList.h"

using namespace std;

#ifndef SORTEDSET_H
#define SORTEDSET_H


class SortedSet : public IntList {
    public: 
        SortedSet() : IntList() {};
        SortedSet(const SortedSet &);
        SortedSet(const IntList &);
        ~SortedSet();
        bool in(int val);
        void add(int val);
        void push_front(int);
        void push_back(int);
        void insert_ordered(int);
        SortedSet operator|(const SortedSet&) const;
        SortedSet operator&(const SortedSet&) const;
        SortedSet operator|=(const SortedSet&);
        SortedSet operator&=(const SortedSet&);

};

#endif
