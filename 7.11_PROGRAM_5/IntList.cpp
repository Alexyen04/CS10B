#include "IntList.h"
#include <iostream>

using namespace std;

IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList(){
    IntNode* curr = head;
    while(curr != nullptr) {
        IntNode* temp = curr->next;
        delete curr;
        curr = temp;
    }
    head = nullptr;
    tail = nullptr;
}

IntList::IntList(const IntList &cpy){
    if(cpy.head == nullptr){
        head = nullptr;
        tail = nullptr;
    } else {
        IntNode *temp = cpy.head;
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

void IntList::push_front(int num){
    IntNode *temp = new IntNode(num);
    if(head == nullptr){
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void IntList::pop_front(){
    if(head != nullptr){
        IntNode *temp = head;
        head = head->next;
        delete temp;
    }
}

void IntList::push_back(int value){
    IntNode *temp = new IntNode(value);
    if(head == nullptr){
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void IntList::selection_sort(){
    if(head != nullptr){
        int temp;
        for(auto i = head; i !=nullptr; i = i->next){
            IntNode *min = head;
            for(auto j = i->next; j != nullptr; j = j->next){
                if(j->value < i->value){
                    min = j;
                    temp = min->value;
                    min->value = i->value;
                    i->value = temp;
                }
            }
            if(i->next == nullptr){
                tail = i;
                tail->next=nullptr;
            }
        }
    }
}

void IntList::insert_ordered(int value){
    if(head == nullptr){
        push_back(value);
    } else if(value < head->value){
        push_front(value);
    } else if(value > tail->value){
        push_back(value);
    } else {
        IntNode *temp = new IntNode(value);
        auto curr = head;
        while(curr->next != nullptr && curr->next->value < temp->value){
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

void IntList::remove_duplicates(){
    IntNode *curr = head;
    if(head == nullptr){
        tail = nullptr;
    }
    while(curr!= nullptr){
        IntNode *before = curr;
        IntNode *nxt = curr->next;
        while(nxt != nullptr){
            if(curr->value == nxt->value){
                before->next = nxt->next;
                delete nxt;
                nxt = before->next;
            } else {
                before = before->next;
                nxt = nxt->next;
            }
        }
        if(curr->next == nullptr){
            tail = curr;
            tail->next = nullptr;
        }
        curr = curr->next;
    }
}

void IntList::clear(){
    IntNode *curr = head;
    while(curr != nullptr){
        IntNode *next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
    tail = nullptr;
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

IntList& IntList::operator=(const IntList &rhs){
    if(rhs.head == nullptr){
        head = nullptr;
        tail = nullptr;
    } else {
        IntNode *temp = rhs.head;
        this->head = new IntNode(temp->value);
        IntNode *curr = head;

        while(temp->next != nullptr){
            curr->next = new IntNode(temp->next->value);
            curr = curr->next;
            temp = temp->next;
        }
        tail = curr;
        tail->next = nullptr;
    }
    return *this;
}

