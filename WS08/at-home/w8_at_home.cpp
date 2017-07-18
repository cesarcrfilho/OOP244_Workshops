/// BTP200 Workshop 8: Virtual Functions
// File: w8_at_home.cpp
// Version: 1.0
// Date: 2017/03/15
// Author: Heidar Davoudi
// Description:
// This file tests at_home section of your workshop
///////////////////////////////////////////////////

#include <iostream>
#include "Account.h" 
#include "SavingsAccount.h" 
#include "CheckingAccount.h" 

using namespace ict;
using namespace std;

int main()
{

	// Create Account for Angelina

	Account * Angelina_Account[2];
    
	// initialize Angelina Accounts
	
	Angelina_Account[ 0 ] = new SavingsAccount( 400.0, 0.12 ); 

	Angelina_Account[ 1 ] = new CheckingAccount( 400.0, 1.0);

	cout << "**************************" << endl;

	cout << "DISPLAY Angelina Accounts:" << endl;

	cout << "**************************" << endl;

	Angelina_Account[0]->display(cout);

	cout << "-----------------------" << endl;

	Angelina_Account[1]->display(cout);

	cout << "**************************" << endl ;

	cout << "DEPOSIT $ 2000 $ into Angelina Accounts ..." << endl ;

	for(int i=0 ; i < 2 ; i++){
		Angelina_Account[i]->credit(2000);
	}

	cout << "WITHDRAW $ 1000 and $ 500 from Angelina Accounts ..." << endl ;

	Angelina_Account[0]->debit(1000);

	Angelina_Account[1]->debit(500);


	cout << "**************************" << endl;

	cout << "DISPLAY Angelina Accounts:" << endl;

	cout << "**************************" << endl;

	Angelina_Account[0]->display(cout);

	cout << "-----------------------" << endl;

	Angelina_Account[1]->display(cout);

	cout << "-----------------------" << endl;

	return 0;
}
