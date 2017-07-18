/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jul 17 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 08 - CheckingAccount header file
---------------------------------------------------------------*/

#ifndef SICT_CHECKINGACCOUNT_H__
#define SICT_CHECKINGACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class CheckingAccount : public Account {
	private:
		double m_transactionFee;

		// TODO: chargeFee subtract transaction fee form the balance
		void chargeFee();
		
	public:

		// constructor initializes balance and transaction fee 
		CheckingAccount(const double balance, const double transactionFee);

		// override credit function
		void credit(const double amount);
	
		// override debit function
		bool debit(const double amount);

		// override display function
		void display(ostream& ostr) const;

	};
};
#endif
