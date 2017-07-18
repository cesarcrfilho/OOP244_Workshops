/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jul 17 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 08 - SavingsAccount implementation file
---------------------------------------------------------------*/

#include "SavingsAccount.h"

using namespace std;

namespace ict{ 
	
	// SavingsAccount member functions here
	SavingsAccount::SavingsAccount(const double balance, const double interest) : Account(balance) {
		// if the interest is less than 0, change to 0
		m_interestRate = interest < 0 ? 0 : interest;
	}

	// Calculate Interest
	double SavingsAccount::calculateInterest() const {
		return getBalance() * m_interestRate;
	}

	void SavingsAccount::display(ostream& ostr) const {
		ostr << "Account type: Saving" << endl;
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << "Balance: $ " << getBalance() << endl;
		ostr << "Interest Rate (%): " << m_interestRate * 100 << endl;
	}
}