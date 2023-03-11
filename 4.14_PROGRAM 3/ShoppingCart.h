#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "ItemToPurchase.h"
#include <iostream> 
#include <vector>
using namespace std;

class ShoppingCart {
    public:

        ShoppingCart();
        
        ShoppingCart(const string &name, const string &date);

        string customerName()const;

        string date()const;

        void addItem(const ItemToPurchase &item);

        void removeItem(const string &name);

        void modifyItem(const ItemToPurchase &item);

        unsigned numItemsInCart()const;

        unsigned costOfCart()const;
        
        void printTotal()const;

        void printDescriptions()const;

    private:

        string custName;

        string currentDate;

        vector <ItemToPurchase> cartItems;

};

#endif
