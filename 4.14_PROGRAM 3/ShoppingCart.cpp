#include <iostream>
#include "ShoppingCart.h"


using namespace std;

ShoppingCart::ShoppingCart(){
    custName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(const string &name, const string &date){
    custName = name;
    currentDate = date;
}

string ShoppingCart::customerName()const{
    return custName;
}

string ShoppingCart::date()const{
    return currentDate;
}

void ShoppingCart::addItem(const ItemToPurchase &item){
    cartItems.push_back(item);
}

void ShoppingCart::removeItem(const string &name){
    bool found = false;
    for(unsigned int i = 0; i < cartItems.size(); i++){
        if(cartItems.at(i).name() == name){
            cartItems.erase(cartItems.begin()+i);
            found = true;
            cout << endl;
        }
    }
    if(!found){
        cout << "Item not found in cart. Nothing removed." << endl << endl;
    }
}

void ShoppingCart::modifyItem(const ItemToPurchase &item){
    bool found = false;
    for(unsigned int i = 0; i < cartItems.size(); i++){
        if(cartItems.at(i).name() == item.name()){
            found = true;
            if(item.description() != "none"){
                cartItems.at(i).setDescription(item.description());
            }
            if(item.price() != 0){
                cartItems.at(i).setPrice(item.price());
            }
            if(item.quantity() != 0){
                cartItems.at(i).setQuantity(item.quantity());
            }
            cout << endl;
        }
    }

    if(!found){
        cout << "Item not found in cart. Nothing modified." << endl << endl;
    }
}

unsigned ShoppingCart::numItemsInCart()const{
    int sum = 0;
    for(unsigned int i = 0; i < cartItems.size(); i++){
        sum += cartItems.at(i).quantity();
    }
    return sum;
}

unsigned ShoppingCart::costOfCart()const{
    int sum = 0;
    for(unsigned int i = 0; i < cartItems.size(); i++){
        sum += (cartItems.at(i).price())*(cartItems.at(i).quantity());
    }
    return sum;
}

void ShoppingCart::printTotal()const{
    cout << custName << "'s Shopping Cart - " << currentDate << endl;
    if(cartItems.size() > 0){
        cout << "Number of Items: " << numItemsInCart() << endl << endl;
        for(unsigned int i = 0; i < cartItems.size(); i++){
            cartItems.at(i).printItemCost();
        }
        cout << endl;
        cout << "Total: $" << costOfCart() << endl << endl;
    } else {
        cout << "Number of Items: 0" << endl << endl;
        cout << "SHOPPING CART IS EMPTY" << endl << endl;
        cout << "Total: $" << costOfCart() << endl << endl;
    }
}

void ShoppingCart::printDescriptions()const{
    cout << custName << "'s Shopping Cart - " << currentDate << endl << endl;
    cout << "Item Descriptions" << endl;

    for (unsigned int i = 0; i < cartItems.size(); i++){
        cout << cartItems.at(i).name() << ": " << cartItems.at(i).description() << endl;
    }
}