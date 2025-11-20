// ShoppingCart.h
/*
Name: Jaime Organista
CMPR 131 – Fall 2025
November 15, 2025
Homework # 2 (Vector Version)
*/
#pragma once
#ifndef SHOPPING_CART
#define SHOPPING_CART

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class ShoppingCart
{
private:
	vector<string> items;

public:
	ShoppingCart() = default;

	void addItem(const string& name);
	void removeItem(const string& name);
	void listItems() const;

	int getNumOfItems() const;
	int getCapacity() const;
	void clearCart();

	friend ostream& operator<<(ostream& os, const ShoppingCart& cart);

};

#endif