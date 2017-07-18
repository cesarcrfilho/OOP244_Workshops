/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : May 25 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 02 - In Lab Implementation File
---------------------------------------------------------------*/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

/*---------------------------------------------------------------
-------------------------MAIN FUNCTION---------------------------
---------------------------------------------------------------*/

int main() {
    int count = 0; // the number of kingdoms in the array

    // pKingdom pointer
    Kingdom* pKingdom = nullptr;

    cout << "==========\n"
         << "Input data\n"
         << "==========\n"
         << "Enter the number of kingdoms: ";
    cin >> count;
    cin.ignore();

    if (count < 1) return 1;

    // Allocate dynamic memory for the pKingdom pointer
    pKingdom = new Kingdom[count];

    for (int i = 0; i < count; ++i) {
        cout << "Kingdom #" << i + 1 << ": " << endl;
        // Accept user input for Kingdom i
        read(pKingdom[i]);
    }
    cout << "==========" << endl << endl;

    // testing that "display(...)" works
    cout << "------------------------------" << endl
        << "The first kingdom entered is" << endl
        << "------------------------------" << endl;
    sict::display(pKingdom[0]);
    cout << "------------------------------" << endl << endl;

    // Deallocate the dynamic memory
    delete[] pKingdom;

    return 0;
}
