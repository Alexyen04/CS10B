#include "IntList.h"
#include <iostream>

using namespace std;

IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList(){
    while(head != nullptr){
        IntNode *next = head->next;
        delete head;
        head = next;
    }
}

void IntList::push_front(int num){
    IntNode *temp = new IntNode(num);
    temp->next = head;
    head = temp;

    //assigned tail to the end
    IntNode *curr = head;
    while(curr !=nullptr){
        if(curr->next == nullptr){
            tail = curr;
        }
        curr = curr->next;
    }

}

void IntList::pop_front(){
    IntNode *temp = head->next;
    delete head;
    head = temp;
}

bool IntList::empty() const{
    return (head == nullptr);
}

const int& IntList::front() const{
    return head->value;
}

const int& IntList::back() const{
    return tail->value;
}


ostream & operator<<(ostream &out, const IntList &rhs){
    auto i = rhs.head;
    while(i != nullptr){
        if(i->next == nullptr){
            out << i->value;
        } else{
            out << i->value << " ";
        }
        i = i->next;
    }
    return out;
}  

