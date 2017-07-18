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

    // Constructor to safe empty state
    CRA_Account::CRA_Account() {
        m_sin = 0;
        strncpy(m_familyName, "no data", 7);
        m_familyName[7] = char(0);
        strncpy(m_givenName, "no data", 7);
        m_givenName[7] = char(0);
    }

    // Function member Set
    void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

        // if the sin is valid, initiate the values
        if (sin < MAX_SIN && sin > MIN_SIN) {
            m_sin = sin;
            strncpy(m_familyName, familyName, strlen(familyName));
            m_familyName[strlen(familyName)] = char(0);
            strncpy(m_givenName, givenName, strlen(givenName));
            m_givenName[strlen(givenName)] = char(0);
            m_years = 0;
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

        bool result = false;
        int sinAux = m_sin;
        int sinDigits[9];
        int evenSum = 0;
        int oddSum = 0;
        int total = 0;
        int highestTenMult = 0;
        int checkDigit = 0;

        // check if the object is not empty
        if (!isEmpty()) {

            // fill the numArray with the split sin number
            for (int i = 8; i >= 0; i--) {
                sinDigits[i] = sinAux % 10;
                sinAux /= 10;
            }

            // store the check digit
            checkDigit = sinDigits[8];

            // split the odd elements and add the digits
            for (int i = 1; i <= 7; i++) {

                // add each odd element to itself
                sinDigits[i] *= 2;

                if (sinDigits[i] < 10) {
                    oddSum += sinDigits[i];
                }
                else {
                    oddSum += sinDigits[i] % 10; // add the remainder
                    oddSum++; // add ONE representing the digit 1 from the number (e.g. 18 -> 1+8)
                }

                i++; // increment to iterate only in odd elements
            }

            // sum the even elements
            evenSum = sinDigits[0] + sinDigits[2] + sinDigits[4] + sinDigits[6];

            total = oddSum + evenSum;

            // Next highest integer multiple of 10
            if (total % 10) {
                highestTenMult = total + (10 - total % 10);
            }

            // check if the check digit matches
            if ((highestTenMult - total) == checkDigit) {
                result = true;
            }
            else {
                result = false;
            }
        }

        return result;
    }

    bool CRA_Account::isEmpty() const {
        return (m_sin == 0);
    }

    // Function member Display
    void CRA_Account::display() const {

        // if the object is NOT empty (empty state)
        if (!isEmpty()) {
            cout << "Family Name: " << m_familyName << endl;
            cout << "Given Name : " << m_givenName << endl;
            cout << "CRA Account: " << m_sin << endl;
            
            cout.setf(ios::fixed);

            for (int i = 0; i < m_years; i++) {
                if (m_balance[i] > 2) {
                    cout.precision(2);
                    cout << "Year (" << m_year[i] << ") balance owing: " << m_balance[i] << endl;
                }
                else if (m_balance[i] < -2) {
                    cout.precision(2);
                    cout << "Year (" << m_year[i] << ") refund due: " << ( m_balance[i] * -1 ) << endl;
                }
                else {
                    cout << "Year (" << m_year[i] << ") No balance owing or refund due!" << endl;
                }
            }

            cout.unsetf(ios::fixed);
        }
        else {
            cout << "Account object is empty!" << endl;
        }
    }

    // Function member Set (overload)
    void CRA_Account::set(int year, double balance) {
        if (!isEmpty() && m_years < MAX_YRS) {
            m_year[m_years] = year;
            m_balance[m_years] = balance;
            m_years++;
        }
    }


}