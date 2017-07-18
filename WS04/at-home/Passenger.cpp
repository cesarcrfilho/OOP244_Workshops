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

    // setter
    void Passenger::set() {
        m_flag = false; // false = empty state
        strncpy(m_passengerName, "no data", 7);
        m_passengerName[7] = char(0);
        strncpy(m_destination, "no data", 7);
        m_destination[7] = char(0);
        m_yearOfDeparture = 0;
        m_monthOfDeparture = 0;
        m_dayOfDeparture = 0;
    }

    // default constructor
    Passenger::Passenger() {
        // set empty states
        set();
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
            m_yearOfDeparture = 2017;
            m_monthOfDeparture = 7;
            m_dayOfDeparture = 1;
        }
        else {
            // set empty states
            set();
        }
    }

    // constructor with 5 parameters
    Passenger::Passenger(const char* passengerName, const char* destination, const int yearOfDeparture, const int monthOfDeparture, const int dayOfDeparture) {
        // check if all parameters are valid
        if (passengerName != nullptr && destination != nullptr && passengerName[0] != char(0) && destination[0] != char(0) && yearOfDeparture <= MAX_YEAR && yearOfDeparture >= MIN_YEAR && monthOfDeparture <= MAX_MONTH && monthOfDeparture >= MIN_MONTH && dayOfDeparture <= MAX_DAY && dayOfDeparture >= MIN_DAY) {
            m_flag = true;
            strncpy(m_passengerName, passengerName, strlen(passengerName));
            m_passengerName[strlen(passengerName)] = char(0);
            strncpy(m_destination, destination, strlen(destination));
            m_destination[strlen(destination)] = char(0);
            m_yearOfDeparture = yearOfDeparture;
            m_monthOfDeparture = monthOfDeparture;
            m_dayOfDeparture = dayOfDeparture;
        }
        else {
            // set empty states
            set();
        }
    }

    // isEmpty query
    bool Passenger::isEmpty() const {
        return !m_flag; // default empty state is false
    }

    // display query
    void Passenger::display() const {
        if (!isEmpty()) {
            // prints in format PASSENGER - DESTINATION on YYYY/MM/DD<NEW_LINE>
            cout << m_passengerName << " - " << m_destination << " on " << m_yearOfDeparture << "/";
            cout.width(2);
            cout.fill('0');
            cout << m_monthOfDeparture;
            cout << "/";
            cout.width(2);
            cout.fill('0');
            cout << m_dayOfDeparture << endl;
        }
    }

    // name query
    const char* Passenger::name() const {
        // return the passenger name. if it's empty, return null address
        return (!isEmpty() ? m_passengerName : nullptr);
    }

    // canTravelWith query
    bool Passenger::canTravelWith(const Passenger& passenger) const {
        bool result = false;
        // check if the destination and date is the same
        if (!strcmp(passenger.m_destination, m_destination) && passenger.m_yearOfDeparture == m_yearOfDeparture && passenger.m_monthOfDeparture == m_monthOfDeparture && passenger.m_dayOfDeparture == m_dayOfDeparture) {
            result = true;
        }
        return result;
    }
}