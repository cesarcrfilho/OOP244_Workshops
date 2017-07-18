/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jun 01 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 03 - In Lab Implementation File
---------------------------------------------------------------*/

#include <iostream>
#include "CRA_Account.h"

using namespace std;
using namespace sict;

int main()
{
	CRA_Account myCRA;
	int sin;
	bool quit = false;
	char familyName[MAX_NAME_LENGTH + 1];
	char givenName[MAX_NAME_LENGTH + 1];

	cout << "Canada Revenue Agency Account App" << endl
		 << "=================================" << endl << endl;
	cout << "Please enter your family name: ";
	cin >> familyName;
	cin.ignore();
	cout << "Please enter your given name: ";
	cin >> givenName;
	cin.ignore();

	do
	{
		cout << "Please enter your social insurance number (0 to quit): ";
		cin >> sin;
		cin.ignore();
		if (sin != 0)
		{
			myCRA.set(familyName, givenName, sin);
			if (!myCRA.isValid())
			{
				cout << "Invalid input! Try again." << endl;
			}
			else
			{
				quit = true;
			}
		}
		else
		{
			quit = true;
		}
	} while (!quit);
	cout << "----------------------------------------" << endl;
	cout << "Testing the display function" << endl;
	cout << "----------------------------------------" << endl;
	myCRA.display();
	cout << "----------------------------------------" << endl;
	
	return 0;
}
