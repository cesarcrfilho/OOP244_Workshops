/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jul 17 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 08 - Account implementation file
---------------------------------------------------------------*/

#include "Account.h"

using namespace std;

namespace ict{ 
	
	// constructor   
	Account::Account(const double balance) {
		// set the initial balance
		m_balance = balance >= 0 ? balance : 1;
	}
	

	// credit (add) an amount to the account balance
	void Account::credit(const double amount) {
		m_balance += amount;
	}

	
	// debit (subtract) an amount from the account balance return bool 
	bool Account::debit(const double amount) {
		bool result = false;
		
		if (amount <= m_balance) {
			m_balance -= amount;
			result = true;
		}

		return result;
	}

	double Account::getBalance() const {
		return m_balance;
	} 

	void Account::setBalance( double newBalance ) {
		m_balance = newBalance;
	} 
}