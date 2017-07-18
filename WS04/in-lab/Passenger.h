/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jun 08 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 04 - Passenger header file
---------------------------------------------------------------*/

// file safeguards
#ifndef SICT_PASSENGER_H__
#define SICT_PASSENGER_H__

namespace sict {

    const int MAX_NAME = 32;

    // Passenger class here
    class Passenger {
    private:
        bool m_flag; // to check empty state
        char m_passengerName[MAX_NAME];
        char m_destination[MAX_NAME];
    public:
        Passenger();
        Passenger(const char* passengerName, const char* destination);
        bool isEmpty() const;
        void display() const;
    };

}

#endif // !SICT_PASSENGER_H__