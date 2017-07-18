/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jul 17 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 08 - Account header file
---------------------------------------------------------------*/

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include <iostream>

using namespace std;

namespace ict{
   
	class Account {
    private:
	    double m_balance; // data member that stores the balance

    protected:
		double getBalance() const; // return the account balance
		void setBalance( double ); // sets the account balance

    public:
		// constructor which initializes balance
		Account(const double balance);
		
		// virtual function credit 
		virtual void credit(const double amount);

		// virtual function debit
		virtual bool debit(const double amount);

		// virtual function display			
		virtual void display(ostream& ostr) const = 0;
   };
};
#endif
