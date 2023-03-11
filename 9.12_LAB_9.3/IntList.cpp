#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream & operator<<(ostream &out, const IntList &curr){
   if(curr.head !=nullptr){
      return out << (curr.head);
   }
   return out;
}

ostream & operator<<(ostream &out, IntNode *curr){
   if(curr !=nullptr){
      if(curr->next == nullptr){
         out << curr->value;
      } else {
         out << curr->value << " ";
      }
      return out << (curr->next);
   }
   return out;
}

bool IntList::exists(IntNode *curr, int num) const{
   if(curr == nullptr){
      return false;
   } else if(curr != nullptr){
      return (num == curr->value) ? true : exists(curr->next, num);
   }
   return exists(curr->next, num);
}


bool IntList::exists(int num) const{
   return exists(head, num);
}




