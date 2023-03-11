#include <iostream> 
#include "ItemToPurchase.h"

using namespace std;

ItemToPurchase::ItemToPurchase(){
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
    itemDescription = "none";
}
ItemToPurchase::ItemToPurchase(const string &n, const string &d, const unsigned &p, const unsigned &q){
    itemName = n;
    itemDescription = d;
    itemPrice = p;
    itemQuantity = q;
}
void ItemToPurchase::setName(const string &n){
    itemName = n;
}

string ItemToPurchase::name()const{
    return itemName;
}

void ItemToPurchase::setPrice(const unsigned &p){
    itemPrice = p;
}

unsigned ItemToPurchase::price()const{
    return itemPrice;
}

void ItemToPurchase::setQuantity(const unsigned &num){
    itemQuantity = num;
}

unsigned ItemToPurchase::quantity()const{
    return itemQuantity;
}

void ItemToPurchase::setDescription(const string &s){
    itemDescription = s;
}

string ItemToPurchase::description()const{
    return itemDescription;
}

void ItemToPurchase::printItemCost()const{
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemPrice*itemQuantity << endl;
}

void ItemToPurchase::printItemDescription()const{
    cout << itemName << ": " << itemDescription << "." << endl;
}