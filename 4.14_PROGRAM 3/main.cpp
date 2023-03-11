#include <iostream>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
using namespace std;

void printMenu();
int main(){
    string cname;
    string cdate;
    char input = ' ';
    
    cout << "Enter customer's name: "; getline(cin, cname); cout << endl;
    cout << "Enter today's date: "; getline(cin, cdate); cout << endl << endl;

    ShoppingCart cart = ShoppingCart(cname, cdate);

    cout << "Customer name: " << cname << endl;
    cout << "Today's date: " << cdate << endl << endl;

    
    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity;
    
    printMenu();
    cin >> input;
    while (input != 'q'){

         if (input == 'a'){
            cout << endl;
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name: " << endl; cin.ignore(); getline(cin, itemName);
            cout << "Enter the item description: " << endl; getline(cin, itemDescription);
            cout << "Enter the item price: " << endl; cin >> itemPrice;
            cout << "Enter the item quantity: " << endl; cin >> itemQuantity;
            cout << endl;
            cart.addItem(ItemToPurchase(itemName, itemDescription, itemPrice, itemQuantity));
            printMenu(); 
         } else if (input == 'd'){
            cout << endl;
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove: " << endl; cin.ignore(); 
            getline(cin, itemName);
            cart.removeItem(itemName);
            printMenu(); 
         } else if (input == 'c'){
            cout << endl;
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name: " << endl; cin.ignore(); getline(cin, itemName);
            cout << "Enter the new quantity: " << endl;
            cin >> itemQuantity;
            ItemToPurchase newItem;
            newItem.setName(itemName); newItem.setQuantity(itemQuantity);
            cart.modifyItem(newItem);
            printMenu(); 
         } else if (input == 'i'){
            cout << endl;
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            cart.printDescriptions();
            cout << endl;
            printMenu(); 
         } else if (input == 'o'){
            cout << endl;
            cout << "OUTPUT SHOPPING CART" << endl;
            cart.printTotal();
            printMenu(); 
         } else if (input == 'q'){
            break;
         } else {
            cout << "Choose an option: "; cout << endl;
         }
         cin >> input;
   }

    return 0;
}

void printMenu(){
    cout << "MENU" << endl << "a - Add item to cart" << endl << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl << "q - Quit" << endl; cout << endl;
    cout << "Choose an option: "; cout << endl;

}