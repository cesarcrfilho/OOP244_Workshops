/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : May 18 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 01 - Tools File
---------------------------------------------------------------*/

#include <iostream>
#include "tools.h"
using namespace std;

/*---------------------------------------------------------------
----------------------FUNCTION DEFINITION------------------------
---------------------------------------------------------------*/

namespace sict {

    // Performs a fool-proof integer entry
    int getInt(int min, int max) {
        int val;
        bool done = false;
        while (!done) {
            cin >> val;
            if (cin.fail()) {
                cin.clear();
                cout << "Invalid Integer, try again: ";
            }
            else {
                if (val < min || val > max) {
                    cout << "Invalid value!" << endl << "Enter a value between " << min << " and " << max << ": ";
                }
                else {
                    done = true;
                }
            }
            cin.ignore(1000, '\n');
        }
        return val;
    }

    // displays the user interface menu
    int menu() {
        cout << "1- Number of Samples" << endl;
        cout << "2- Sample Entry" << endl;
        cout << "3- Draw Graph" << endl;
        cout << "0- Exit" << endl;
        cout << "> ";
        return getInt(0, 3);
    }
}