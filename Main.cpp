/*
Kailyn Vu, Jaime Organista,  Jared Yalung
CMPR 131 - Fall 2025
November 23, 2025
Final Project 2 ,
Collaboration: STARTING OUT WITH C++, Geeksforgeeks.org
*/

#include "Bank.h"
#include "Users.h"

int main()
{
	//Creating a bank obj and 2 adding accounts
	Bank myBank;
	cout << "Adding the following 2 accounts to a bank object: " << endl;
	myBank.createAccount("Jane", 100);
	myBank.createAccount("John", 75);

	cout << "Here's their information: " << endl;
	//Display initial info
	myBank.displayAllAccounts();

	//Display just 1 account
	cout << "\nJust 1 account before changing balance" << endl;
	int janeId = myBank.findID("Jane");
	myBank.searchAccountById(janeId)->displayInfo();

	cout << "\n" << endl;
	myBank.depositToAccount(janeId, 500);
	myBank.searchAccountById(janeId)->displayInfo();
	cout << "\n" << endl;
	myBank.withdrawFromAccount(janeId, 250);
	myBank.searchAccountById(janeId)->displayInfo();

	cout << "\n" << endl;
	cout << "Copy constructor" << endl;
	Bank bank2(myBank);
	bank2.displayAllAccounts();
	cout << "\n" << endl;

	cout << "Copy assignment" << endl;
	Bank bank3 = myBank;
	bank3.displayAllAccounts();
	cout << "\n" << endl;

	cout << "Creating another bank object and adding 2 accounts: " << endl;
	Bank bank4;
	bank4.createAccount("Doe", 2);
	bank4.createAccount("Roe", 7);


	cout << "\n" << endl;
	cout << "Move constructor" << endl;
	Bank bank5 = move(bank4);
	bank5.displayAllAccounts();
	
	cout << "\n" << endl;
	cout << "Creating another bank object and adding 2 accounts: " << endl;
	Bank bank6;
	bank6.createAccount("James", 21);
	bank6.createAccount("Judy", 67);
	bank6.displayAllAccounts();

	cout << "\n" << endl;
	cout << "Move assignment" << endl;
	Bank bank7;
	bank7 = move(bank6);
	bank7.displayAllAccounts();
	return 0;
}