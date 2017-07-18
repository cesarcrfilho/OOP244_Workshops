/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : May 25 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 02 - At Home Implementation File
---------------------------------------------------------------*/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

/*---------------------------------------------------------------
-------------------------MAIN FUNCTION---------------------------
---------------------------------------------------------------*/

int main() {
    int count = 0, // the number of kingdoms in the array
        i = 0;

    // pKingdom pointer
    Kingdom* pKingdom = nullptr;
    Kingdom* pKingdom2 = nullptr;
        
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
    display(pKingdom[0]);
    cout << "------------------------------" << endl << endl;

    // Allocate dynamic memory for count + 1 Kingdoms
    pKingdom2 = new Kingdom[count+1];
    
    // Copy elements from original array into this newly allocated array
    for (i = 0; i < count; i++)
    {
        pKingdom2[i] = pKingdom[i];
    }
    
    // Deallocate the dynamic memory for the original array
    delete[] pKingdom;
    
    // Copy the address of the newly allocated array into pKingdom pointer
    pKingdom = pKingdom2;

    // Add the new Kingdom
    cout << "==========\n"
        << "Input data\n"
        << "==========\n"
        << "Kingdom #" << count + 1 << ": " << endl;
    
    // Accept input for the new element in the array
    read(pKingdom[count]);
    count++;
    cout << "==========\n" << endl;

    // testing that the overload of "display(...)" works
    display(pKingdom, count);
    cout << endl;

    // Deallocate the dynamic memory
    delete[] pKingdom;
    pKingdom = nullptr; // cleaning the pointer
    pKingdom2 = nullptr; // cleaning the pointer (dynamic memory already deleted)

    return 0;
}
