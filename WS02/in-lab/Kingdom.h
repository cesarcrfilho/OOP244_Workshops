/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : May 25 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 02 - Kingdom Header File
---------------------------------------------------------------*/

// Header safeguards
#ifndef SICT_KINGDOM_H__
#define SICT_KINGDOM_H__

/*---------------------------------------------------------------
-------------------------DECLARATIONS----------------------------
---------------------------------------------------------------*/

// sict namespace
namespace sict {

    // Structure Kingdom
    struct Kingdom {
        char m_name[32]; // Kingdom name
        int m_population; // Kingdom population
    };

    // Function display(...)
    void display(const Kingdom&);

    // Function read(...)
    void read(Kingdom&);

}
#endif // !SICT_KINGDOM_H__