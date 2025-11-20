/*
Kailyn Vu, Jaime Organista,  Jared Yalung
CMPR 131 - Fall 2025
November 23, 2025
Final Project 2 ,
Collaboration: STARTING OUT WITH C++, Geeksforgeeks.org, Victoria from the MESA Center
*/

#pragma once
#include "Users.h"
#include<vector>

class Bank
{
	private:
		//std::vector<Users> accounts;
		vector<Users> accounts;
	public:
		Bank();

		void createAccount(string name, double deposit);

		Users* searchAccountById(int id);
		void depositToAccount(int id, double amt);
		void withdrawFromAccount(int id, double amt);
		void displayAllAccounts();
		int findID(string n);

		//Big 5
		Bank(const Bank& other);
		Bank& operator=(const Bank& other);
		Bank(Bank&& other) noexcept;
		Bank& operator=(Bank&& other)noexcept;
	
		


};

