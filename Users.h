/*
Kailyn Vu, Jaime Organista,  Jared Yalung
CMPR 131 - Fall 2025
November 23, 2025
Final Project 2 ,
Collaboration: STARTING OUT WITH C++, Geeksforgeeks.org, Victoria from the MESA Center
*/

#pragma once
#include <iostream>
#include <random>
#include<unordered_set>
#include "Bank.h"
using namespace std;


class Users
{

	

	private:
		int id;
		string name;
		double balance;
		
	public:
		Users( string n, double b);
		void deposit(double amt);
		void withdraw(double amt);
		double getBalance() const;
		string getName() const;
		int getID() const;
		void displayInfo() const;
};
