/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jun 21 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 06 - Contract header file
---------------------------------------------------------------*/

#ifndef SICT_CONTRACT_H__
#define SICT_CONTRACT_H__

namespace sict {

    const int MAX_ARRAY = 21; // array size 20 + 1 for null terminator

    // Contact class
    class Contact {
    private:
        bool m_flag; // checks empty state
        char m_contactName[MAX_ARRAY];
        long long* m_phoneNumbers;
        int m_numberOfPhones;
        void set(); // sets the constructor values
        void set(const char* contactName, const long long* phoneNumber, const int& numberOfPhones);
        bool isPhoneValid(const long long& phoneNumber) const;
    public:
        Contact(); // default constructor
        Contact(const char* contactName, const long long* phoneNumber, const int& numberOfPhones);
        ~Contact();
        bool isEmpty() const;
        void display() const;
        Contact(const Contact& rhs); // copy constructor
        Contact& operator = (const Contact& rhs); // copy with assignment operator
        Contact& operator += (const long long& phoneNumber);
    };

    //-- helper functions --//

    // convert and empty array to an array of digits
    int* convertToArray(int* emptyArray, long long number, const int& numberOfDigits);

    // returns the number of digits of a long long number
    int numberOfDigits(long long phone);

}

#endif // !SICT_CONTRACT_H__
