/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jul 17 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 08 - CheckingAccount implementation file
---------------------------------------------------------------*/

#include "CheckingAccount.h"

using namespace std;

namespace ict{    
	
	// CheckingAccount class member functions here 
	CheckingAccount::CheckingAccount(const double balance, const double transactionFee) : Account(balance) {
		// if fee is less than 0, change to 0
		m_transactionFee = transactionFee < 0 ? 0 : transactionFee;
	}

	void CheckingAccount::chargeFee() {
		// update balance
		setBalance(getBalance() - m_transactionFee);
	}

	bool CheckingAccount::debit(const double amount) {
		bool result = false;
		
		// calculate the fee and then debit
		if (Account::debit(amount)) {
			chargeFee();
			result = true;
		}

		return result;
	}

	void CheckingAccount::credit(const double amount) {
		chargeFee();
		Account::credit(amount);
	}

	void CheckingAccount::display(ostream& ostr) const {
		ostr << "Account type: Checking" << endl;
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << "Balance: $ " << getBalance() << endl;
		ostr << "Transaction Fee: " << m_transactionFee << endl;
	}



}