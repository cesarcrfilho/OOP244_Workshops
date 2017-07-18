/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jul 17 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 08 - SavingsAccount implementation file
---------------------------------------------------------------*/

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{

	class SavingsAccount : public Account{
	private:
    	double m_interestRate; // interest rate (percentage) 
	public:
		
		// prototypes here
		SavingsAccount(const double balance, const double interest);

		// Calculate Interest
		double calculateInterest() const;

		// display
		void display(ostream& ostr) const;

   };
};
#endif
