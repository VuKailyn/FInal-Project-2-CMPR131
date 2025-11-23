/*
Kailyn Vu, Jaime Organista,  Jared Yalung
CMPR 131 - Fall 2025
November 23, 2025
Final Project 2 ,
Collaboration: STARTING OUT WITH C++, Geeksforgeeks.org, Victoria from the MESA Center
*/

#include "Bank.h"
#include "Users.h"

int main()
{
	//user defined account.
	Bank bank8;
	string name;
	double balence;
	cout << "Please Enter your name: ";
	cin >> name;
	cout << "Please enter your balence: ";
	cin >> balence;
	bank8.createAccount(name, balence);
	cout << endl;

	bank8.displayAllAccounts();




	//Creating a bank obj and 2 adding accounts
	Bank myBank;
	cout << "Adding the following 2 accounts to the myBank object: " << endl;
	myBank.createAccount("Jane", 100);
	myBank.createAccount("John", 75);

	cout << endl;
	system("pause");
	system("cls");

	cout << "Here's their information from myBank: " << endl;
	//Display initial info
	myBank.displayAllAccounts();

	cout << endl;
	system("pause");
	system("cls");

	//Display just 1 account
	cout << "\nJane's account before changing balance" << endl;
	int janeId = myBank.findID("Jane");
	myBank.searchAccountById(janeId)->displayInfo();

	cout << "\n" << endl;
	myBank.depositToAccount(janeId, 500);
	myBank.searchAccountById(janeId)->displayInfo();
	cout << "\n" << endl;
	myBank.withdrawFromAccount(janeId, 250);
	myBank.searchAccountById(janeId)->displayInfo();

	cout << "\n" << endl;
	cout << "Copy constructor - copying myBank to bank2:" << endl;
	Bank bank2(myBank);
	bank2.displayAllAccounts();
	cout << "\n" << endl;

	cout << "Copy assignment to bank3 from myBank: " << endl;
	Bank bank3 = myBank;
	bank3.displayAllAccounts();
	cout << "\n" << endl;

	cout << endl;
	system("pause");
	system("cls");

	cout << "Creating bank4 object and adding 2 accounts: " << endl;
	Bank bank4;
	bank4.createAccount("Doe", 2);
	bank4.createAccount("Roe", 7);


	cout << "\n" << endl;
	cout << "Move constructor moves bank4 to bank5: " << endl;
	Bank bank5 = move(bank4);
	bank5.displayAllAccounts();

	cout << endl;
	system("pause");
	system("cls");

	cout << "\n" << endl;
	cout << "Creating bank6 object and adding 2 accounts: " << endl;
	Bank bank6;
	bank6.createAccount("James", 21);
	bank6.createAccount("Judy", 67);
	bank6.displayAllAccounts();

	cout << "\n" << endl;
	cout << "Move assignment - bank6 moved to bank7: " << endl;
	Bank bank7;
	bank7 = move(bank6);
	bank7.displayAllAccounts();

	cout << endl;
	system("pause");

	system("cls");

	cout << "List of accounts on The bank: " << endl;
	myBank.displayAllAccounts();
	bank5.displayAllAccounts();
	bank7.displayAllAccounts();
	bank8.displayAllAccounts();

	return 0;
