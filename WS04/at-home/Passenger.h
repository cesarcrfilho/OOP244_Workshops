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
    const int MAX_YEAR = 2020;
    const int MIN_YEAR = 2017;
    const int MAX_MONTH = 12;
    const int MIN_MONTH = 1;
    const int MAX_DAY = 31;
    const int MIN_DAY = 1;

    // Passenger class here
    class Passenger {
    private:
        bool m_flag; // to check empty state
        char m_passengerName[MAX_NAME];
        char m_destination[MAX_NAME];
        int m_yearOfDeparture;
        int m_monthOfDeparture;
        int m_dayOfDeparture;
        void set();
    public:
        Passenger();
        Passenger(const char* passengerName, const char* destination);
        Passenger(const char* passengerName, const char* destination, const int yearOfDeparture, const int monthOfDeparture, const int dayOfDeparture);
        bool isEmpty() const;
        void display() const;
        const char* name() const;
        bool canTravelWith(const Passenger& passenger) const;
    };

}

#endif // !SICT_PASSENGER_H__