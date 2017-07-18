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

    // Function display(...)
    void display(const Kingdom kingdom[], int elements)
    {
        int i = 0,
            totalPopulation = 0;

        // Header
        cout << "------------------------------" << endl;
        cout << "Kingdoms of SICT" << endl;
        cout << "------------------------------" << endl;

        for (i = 0; i < elements; i++)
        {
            cout << i + 1 << ". ";
            display(kingdom[i]); // display the kingdom element

            // Increment the total population
            totalPopulation += kingdom[i].m_population;
        }

        // Footer
        cout << "------------------------------" << endl;
        cout << "Total population of SICT: " << totalPopulation << endl;
        cout << "------------------------------" << endl;
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