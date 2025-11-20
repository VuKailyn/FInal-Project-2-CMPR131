// main.cpp
/*
Name: Jaime Organista
CMPR 131 – Fall 2025
November 15, 2025
Homework # 2 (Vector Version)
*/

#include "ShoppingCart.h"
using namespace std;

int main()
{
    ShoppingCart cart;

    cart.addItem("Apple");
    cart.addItem("Banana");
    cart.addItem("Eggs");
    cart.addItem("Milk");
    cart.addItem("Bread");

    cart.listItems();

    cart.addItem("Cheese");
    cout << "\nCart List after adding cheese:\n";
    cout << cart << endl;

    cart.removeItem("Milk");
    cout << "\nItems after removing Milk:\n";
    cout << cart << endl;

    cout << "\nCurrent capacity of cart: " << cart.getCapacity() << "\n\n";

    cart.clearCart();
    cout << "After clearing cart:\n" << cart << endl;

    cout << "Current capacity of cart: " << cart.getCapacity() << "\n";

    return 0;
}
