/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jun 01 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 03 - CRA Account Implementation File
---------------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace std;

/*---------------------------------------------------------------
---------------------------DEFINITIONS---------------------------
---------------------------------------------------------------*/

namespace sict {

    // Function member Set
    void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

        // if the sin is valid, initiate the values
        if (sin < MAX_SIN && sin > MIN_SIN) {
            m_sin = sin;
            strncpy(m_familyName, familyName, strlen(familyName));
            m_familyName[strlen(familyName)] = char(0);
            strncpy(m_givenName, givenName, strlen(givenName));
            m_givenName[strlen(givenName)] = char(0);
        }
        // if note, empty state
        else {
            m_sin = 0;
            strncpy(m_familyName, "no data", 7);
            m_familyName[7] = char(0);
            strncpy(m_givenName, "no data", 7);
            m_givenName[7] = char(0);
        }
    }

    // Function member isValid
    bool CRA_Account::isValid() const {

        bool result;

        // check is the sin is valid
        result = (m_sin < MAX_SIN && m_sin > MIN_SIN);

        return result;
    }

    // Function member Display
    void CRA_Account::display() const {

        // if the object is NOT empty (empty state)
        if (isValid()) {
            cout << "Family Name: " << m_familyName << endl;
            cout << "Given Name : " << m_givenName << endl;
            cout << "CRA Account: " << m_sin << endl;
        }
        else {
            cout << "Account object is empty!" << endl;
        }
    }


}