#include "SortedSet.h"
#include <iostream>

using namespace std;

SortedSet::SortedSet(const SortedSet &copy){
    if(copy.head == nullptr){
        head = nullptr;
        tail = nullptr;
    } else {
        IntNode *temp = copy.head;
        head = new IntNode(temp->value);
        IntNode *curr = head;

        while(temp->next != nullptr){
            curr->next = new IntNode(temp->next->value);
            curr = curr->next;
            temp = temp->next;
        }
        tail = curr;
        tail->next = nullptr;
    }
}

SortedSet::SortedSet(const IntList &cpy) : IntList(cpy){
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet(){ }

bool SortedSet::in(int val){
    IntNode *curr = head;
    while(curr != nullptr){
        if(curr->value == val){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void SortedSet::add(int val){
    IntNode *temp = new IntNode(val);
    if(!(in(val))){
        if(head == nullptr){
            if(head == nullptr){
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
        } else if(val < head->value){
            if(head == nullptr){
                head = temp;
                tail = temp;
            } else {
                temp->next = head;
                head = temp;
            }
        } else if(val > tail->value){
            if(head == nullptr){
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
        } else {
            auto curr = head;
            while(curr->next != nullptr && curr->next->value < temp->value){
                curr = curr->next;
            }
            temp->next = curr->next;
            curr->next = temp;
        }
    }
}

void SortedSet::push_front(int val){
    add(val);
}

void SortedSet::push_back(int val){
    add(val);
}

void SortedSet::insert_ordered(int val){
    add(val);
}

SortedSet SortedSet::operator|(const SortedSet &rhs) const{
    SortedSet temp(rhs);

    IntNode *left = this->head;

    while(left != nullptr){
        if(!(temp.in(left->value))){
            temp.add(left->value);
        }
        left = left->next;
    }

    return temp;
}

SortedSet SortedSet::operator&(const SortedSet &rhs) const{
    SortedSet temp;

    SortedSet right(rhs);
    IntNode *left = this->head;

    while(left != nullptr){
        if(right.in(left->value)){
            temp.add(left->value);
        }
        left = left->next;
    }

    return temp;
}

SortedSet SortedSet::operator|=(const SortedSet &rhs){
    SortedSet temp;
    temp = *this | rhs;
    *this = temp;
    return *this;
}

SortedSet SortedSet::operator&=(const SortedSet &rhs){
    SortedSet temp;
    temp = *this & rhs;
    *this = temp;
    return *this;
}
        

