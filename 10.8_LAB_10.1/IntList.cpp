#include "IntList.h"

/* Initializes an empty list.
*/
IntList::IntList() : head(nullptr) {}

/* Inserts a data value to the front of the list.
*/
void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } 
   else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

void IntList::swapHeadAndTail() {
   if(head == nullptr){
      return;
   }

   IntNode *tail = head;
   IntNode *before = nullptr, *temp = nullptr;
   while(tail->next != nullptr){
      before = tail;
      tail = tail->next;
   }

   if(head == tail){
      return;
   }

   if(head->next == tail){
      temp = head;
      head = tail;
      head->next = temp;
      temp->next = nullptr;
   } else {
      temp = head;
      head = tail;
      head->next = temp->next;
      before->next = temp;
      temp->next = nullptr;
   }
   
   
   


}
