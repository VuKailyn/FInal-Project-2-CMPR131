/*
Kailyn Vu, Jaime Organista,  Jared Yalung
CMPR 131 - Fall 2025
November 23, 2025
Final Project 2 ,
Collaboration: STARTING OUT WITH C++, Geeksforgeeks.org
*/

//#include "Users.h"
#include "Bank.h"
unordered_set<int> allIDS;
Users::Users(string n, double b)
{
	name = n;
	balance = b;

	//Generating a random id
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(100000, 999999);
	id = distrib(gen);

	//Binary search to see if it matches an already existing id
	int low = 0;
	int high = allIDS.size() - 1;
	
	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		auto n = next(allIDS.begin(), mid);
		if (*n==id)
			id=distrib(gen);

		if (*n < id)
			low = mid + 1;

		else
			high = mid - 1;
	}

	//Inserting id in master list of IDs
	auto pos = lower_bound(allIDS.begin(), allIDS.end(), id);
	allIDS.insert(pos, id);
		
	
}

void Users::deposit(double amt)
{
	cout << "Deposit of $" << amt << endl;
	balance += amt;
}

void Users::withdraw(double amt)
{
	if (balance - amt < 0)
	{
		cout << "Withdraw amount invalid. Please try again";
	}
	else
	{
		cout << "Withdraw of $" << amt << endl;
		balance -= amt;
	}
}

string Users::getName() const
{
	return name;
}

double Users::getBalance() const
{
	return balance;
}

int Users::getID() const
{
	return id;
}

void Users::displayInfo() const
{
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
	cout << "Balance: $" << balance << endl;
}