/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jun 08 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 04 - Passenger implementation file
---------------------------------------------------------------*/

// headers
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;

namespace sict {
    // default constructor
    Passenger::Passenger() {
        m_flag = false; // false = empty state
        strncpy(m_passengerName, "no data", 7);
        m_passengerName[7] = char(0);
        strncpy(m_destination, "no data", 7);
        m_destination[7] = char(0);
    }

    // constructor with 2 parameters
    Passenger::Passenger(const char* passengerName, const char* destination) {
        // check if the strings are valid (not empty and not pointing to null address)
        if (passengerName != nullptr && destination != nullptr && passengerName[0] != char(0) && destination[0] != char(0)) {
            m_flag = true;
            strncpy(m_passengerName, passengerName, strlen(passengerName));
            m_passengerName[strlen(passengerName)] = char(0);
            strncpy(m_destination, destination, strlen(destination));
            m_destination[strlen(destination)] = char(0);
        }
        else {
            m_flag = false; // false = empty state
            strncpy(m_passengerName, "no data", 7);
            m_passengerName[7] = char(0);
            strncpy(m_destination, "no data", 7);
            m_destination[7] = char(0);
        }
    }

    // isEmpty query
    bool Passenger::isEmpty() const {
        return !m_flag; // default empty state is false
    }

    // display query
    void Passenger::display() const {
        if (!isEmpty()) {
            cout << m_passengerName << " - " << m_destination << endl;
        }
    }
}