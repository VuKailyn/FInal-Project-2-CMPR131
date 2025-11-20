/*
Kailyn Vu, Jaime Organista,  Jared Yalung
CMPR 131 - Fall 2025
November 23, 2025
Final Project 2 ,
Collaboration: STARTING OUT WITH C++, Geeksforgeeks.org, Victoria from the MESA Center
*/

#include "Bank.h"

//Default constructor, accounts is initalized in header 
Bank::Bank()
{
	
}


//getID from accounts based on name for id based searching
int Bank::findID(string n)
{
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts.at(i).getName() == n)
		{
			return accounts.at(i).getID();
		}
	}
	return -1;
}

void Bank::createAccount(string name, double deposit)
{
	//New user
	Users newUser(name, deposit);
	
	//Search the accounts vector for the proper index to insert based on IDS
	int l = 0, r = accounts.size()-1;
	int m;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (accounts.at(m).getID() < newUser.getID())
			l = m + 1;
		else
			r = m-1;
	}
	//insert
	accounts.insert(accounts.begin() + l, newUser);
}

//Returns a pointer to User object
Users* Bank::searchAccountById(int id)
{
	int low = 0;
	int high = accounts.size() - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (accounts.at(mid).getID() == id)
		{
			return &accounts.at(mid);
		}
		if (accounts.at(mid).getID() < id)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	return nullptr;

}

void Bank::depositToAccount(int id, double amt)
{
	
	int low = 0;
	int high = accounts.size() - 1;
	int index = 0;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (accounts.at(mid).getID() == id)
		{
			index = mid;
		}
		if (accounts.at(mid).getID() < id)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	
	if (id== accounts.at(index).getID())
	{
		accounts.at(index).deposit(amt);
		
	}
	else
	{
		cout << "Account doesn't exist." << endl;
	}

}

//Withdraws from account based on ID
void Bank::withdrawFromAccount(int id, double amt)
{
	int low = 0;
	int high = accounts.size() - 1;
	int index = 0;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (accounts.at(mid).getID() == id)
		{
			index = mid;
		}
		if (accounts.at(mid).getID() < id)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}


	if (id==accounts.at(index).getID())
	{
		accounts.at(index).withdraw(amt);
	}
	else
	{
		cout << "Account doesn't exist." << endl;
	}
}

//Displays accounts in order of ID
void Bank::displayAllAccounts()
{
	for (int i = 0; i < accounts.size(); i++)
	{
		accounts.at(i).displayInfo();
	}
}

//Big 5, no destructor since vector class has its own

Bank::Bank(const Bank& other)
{
	for (int i = 0; i < other.accounts.size(); i++)
	{
		accounts.push_back(other.accounts.at(i));
	}
}

Bank& Bank:: operator=(const Bank& other)
{
	if (this != &other)
	{
		accounts.clear();
		for (int i = 0; i < other.accounts.size(); i++)
		{
			accounts.push_back(other.accounts.at(i));
		}
	}
	else
	{
		cout << "No self assignment." << endl;
	}
	return *this;
}

Bank::Bank(Bank&& other) noexcept
{
	accounts = other.accounts;
	other.accounts.clear();
}

Bank& Bank::operator=(Bank&& other) noexcept
{
	if (this != &other)
	{
		accounts.clear();
		accounts = other.accounts;
	}
	else
	{
		cout << "No self assignment." << endl;
	}
	return *this;
}
