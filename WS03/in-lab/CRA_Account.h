/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jun 01 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 03 - CRA Account Header
---------------------------------------------------------------*/

#ifndef SICT_CRA_ACCOUNT_H__
#define SICT_CRA_ACCOUNT_H__

/*---------------------------------------------------------------
--------------------------DECLARATIONS---------------------------
---------------------------------------------------------------*/

namespace sict {
    
    // Variable declaration
    const int MAX_NAME_LENGTH = 40; // max length for account holder name + \0
    const int MIN_SIN = 100000000; // smallest SIN number possible
    const int MAX_SIN = 999999999; // largest SIN number possible

    // Class CRA_Account Declaration
    class CRA_Account {
    private:
        // class variable members
        char m_familyName[MAX_NAME_LENGTH];
        char m_givenName[MAX_NAME_LENGTH];
        int m_sin;
    public:
        // class function members
        void set(const char* familyName, const char* givenName, int sin);
        bool isValid() const;
        void display() const;
    };

}

#endif // !SICT_CRA_ACCOUNT_H__

