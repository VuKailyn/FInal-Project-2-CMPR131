// ShoppingCart.cpp
/*
Name: Jaime Organista
CMPR 131 – Fall 2025
November 15, 2025
Homework # 2 (Vector Version)
*/

#include"ShoppingCart.h"

void ShoppingCart::addItem(const string& name)
{
	items.push_back(name);
}

void ShoppingCart::removeItem(const string& name)
{
	bool found = false;

	for (auto it = items.begin(); it != items.end(); ++it)
	{
		if (*it == name)
		{
			items.erase(it);
			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << "Item \"" << name << "\" not found in the cart.\n";

	}
}

void ShoppingCart::listItems() const
{
	if (items.empty())
	{
		cout << "The cart is empty.\n";
		return;
	}

	cout << "Items in the shopping cart: \n";
	for (size_t i = 0; i < items.size(); i++)
	{
		cout << i + 1 << ". " << items[i] << endl;
	}
}

int ShoppingCart::getNumOfItems() const
{
	return static_cast<int>(items.size());
}

int ShoppingCart::getCapacity()const
{
	return static_cast<int>(items.capacity());
}

void ShoppingCart::clearCart()
{
	items.clear();
	items.shrink_to_fit();
}

ostream& operator<<(ostream& os, const ShoppingCart& cart)
{
	if (cart.items.empty())
	{
		os << "The shopping cart is empty.\n";
		return os;
	}

	os << "Shopping Cart Items:\n";
	for (size_t i = 0; i < cart.items.size(); i++)
	{
		os << i + 1 << ". " << cart.items[i] << "\n";
	}

	os << "Total items: " << cart.items.size() << "\n";

	return os;
}
