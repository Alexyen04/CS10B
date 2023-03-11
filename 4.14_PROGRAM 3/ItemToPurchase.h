#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <iostream>
using namespace std;

class ItemToPurchase {

    public:
        ItemToPurchase();

        ItemToPurchase(const string &n, const string &d, const unsigned &p, const unsigned &q);

        void setName(const string &n);

        string name()const;

        void setPrice(const unsigned &p);

        unsigned price()const;

        void setQuantity(const unsigned &num);

        unsigned quantity()const;

        void setDescription(const string &s);

        string description()const;
        
        void printItemCost()const;

        void printItemDescription()const;
        
    private:
        string itemName;

        int itemPrice;

        int itemQuantity;

        string itemDescription;

};

#endif