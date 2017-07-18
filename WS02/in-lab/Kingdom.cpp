/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : May 25 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 02 - Kingdom Implementation File
---------------------------------------------------------------*/

// Headers
#include <iostream>
#include "Kingdom.h"
using namespace std;

/*---------------------------------------------------------------
--------------------------DEFINITIONS----------------------------
---------------------------------------------------------------*/

// sict namespace
namespace sict {

    // Function display(...)
    void display(const Kingdom& kingdom)
    {
        cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
    }

    // Function read(...)
    // read accepts data for a Kingdom from standard input
    void read(Kingdom& kingdom) {

        cout << "Enter the name of the kingdom: ";
        cin.get(kingdom.m_name, 32, '\n');
        cin.ignore(2000, '\n');
        cout << "Enter the number people living in " << kingdom.m_name << ": ";
        cin >> kingdom.m_population;
        cin.ignore(2000, '\n');
    }
}