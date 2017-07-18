/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jun 21 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 06 - Contract implementation file
---------------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "Contact.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace sict {

    // set method
    void Contact::set() {
        m_flag = false; // safe empty state
        m_contactName[0] = char(0);
        m_phoneNumbers = nullptr;
        m_numberOfPhones = 0;
    }

    // set method - 3 parameters
    void Contact::set(const char* contactName, const long long* phoneNumbers, const int& numberOfPhones) {

        if (contactName != nullptr && contactName[0] != char(0) ) {
            int nameSize = strlen(contactName);
            long long* validPhones = new long long[numberOfPhones];
            int numberOfValidPhones = 0;

            m_flag = true;

            // check if the contact name is valid
            if (nameSize <= MAX_ARRAY) {
                strncpy(m_contactName, contactName, nameSize);
                m_contactName[nameSize] = char(0);
            }
            else {
                // copies only 19 positions
                strncpy(m_contactName, contactName, MAX_ARRAY-2);
                m_contactName[MAX_ARRAY-2] = char(0);
            }

            // check if the phones are valid and fill the aux array
            for (int i = 0; i < numberOfPhones; i++) {
                if (isPhoneValid(phoneNumbers[i])) {
                    validPhones[numberOfValidPhones] = phoneNumbers[i];
                    numberOfValidPhones++;
                }
            }

            // allocate memory for valid phones
            m_phoneNumbers = new long long[numberOfValidPhones];
            m_numberOfPhones = numberOfValidPhones;

            // fill the member array with the valid phones
            for (int i = 0; i < m_numberOfPhones; i++) {
                m_phoneNumbers[i] = validPhones[i];
            }

            // deallocate memory for the aux array
            delete[] validPhones;
            validPhones = nullptr;
        }
        // if it's invalid, the allocated memory should point to null address
        else {
            m_phoneNumbers = nullptr;
        }
    }
    
    // Default Constructor
    Contact::Contact() {
        set();
    }

    // Constructor - 3 parameters
    Contact::Contact(const char* contactName, const long long* phoneNumbers, const int& numberOfPhones) {
        set(contactName, phoneNumbers, numberOfPhones);
    }

    // copy constructor
    Contact::Contact(const Contact& rhs) {
        // shallow copies
        m_flag = rhs.m_flag;
        strncpy(m_contactName, rhs.m_contactName, strlen(rhs.m_contactName));
        m_contactName[strlen(rhs.m_contactName)] = char(0);
        
        // allocate memory
        m_phoneNumbers = new long long[m_numberOfPhones = rhs.m_numberOfPhones];

        for (int i = 0; i < m_numberOfPhones; i++) {
            m_phoneNumbers[i] = rhs.m_phoneNumbers[i];
        }
    }

    // Destructor
    Contact::~Contact() {
        delete[] m_phoneNumbers;
        m_phoneNumbers = nullptr;
    }

    // isEmpty method
    bool Contact::isEmpty() const {
        return !m_flag;
    }

    // isPhoneValid method
    bool Contact::isPhoneValid(const long long& phoneNumber) const {
        bool result = false;
        long long phoneAux = phoneNumber;
        int digits = 0;
        int* phoneDigits = nullptr;

        if (phoneNumber > 0) {

            // get the number of digits
            digits = numberOfDigits(phoneNumber);

            // the number of digits is only valid if it's 11 or 12
            if (digits == 11 || digits == 12) {

                // allocate memory for the phone digits array
                phoneDigits = new int[digits];

                // convert int to array
                convertToArray(phoneDigits, phoneAux, digits);

                // check if the phone is valid
                // phoneDigits[0] + phoneDigits[digits-11] to check if country code is 0
                // phoneDigits[digits-10] is the first area code digit
                // phoneDigits[digits-7] is the first phone number digit
                if (phoneDigits[digits-7] != 0 && phoneDigits[digits-10] != 0 && ( phoneDigits[0] + phoneDigits[digits-11] ) != 0) {
                    result = true;
                }

                // deallocate memory
                delete[] phoneDigits;
                phoneDigits = nullptr;
            }
        }
        return result;
    }

    // display method
    void Contact::display() const {
        if (isEmpty()) {
            cout << "Empty contact!" << endl;
        }
        else {
            cout << m_contactName << endl;

            if (m_numberOfPhones > 0) {
                for (int i = 0; i < m_numberOfPhones; i++) {
                    // check number of digits and declare the array
                    int digits = numberOfDigits(m_phoneNumbers[i]);
                    int* phoneDigits = new int[digits];

                    // convert the number to array of digits
                    convertToArray(phoneDigits, m_phoneNumbers[i], digits);

                    // print the phone number depending on the number of digits
                    if (digits == 11) {
                        // country code
                        cout << "(+" << phoneDigits[0] << ") ";
                        // area code
                        cout << phoneDigits[1] << phoneDigits[2] << phoneDigits[3] << " ";
                        // number
                        cout << phoneDigits[4] << phoneDigits[5] << phoneDigits[6] << "-" << phoneDigits[7] << phoneDigits[8] << phoneDigits[9] << phoneDigits[10] << endl;
                    }
                    else if (digits == 12) {
                        // country code
                        cout << "(+" << phoneDigits[0] << phoneDigits[1] << ") ";
                        // area code
                        cout << phoneDigits[2] << phoneDigits[3] << phoneDigits[4] << " ";
                        // number
                        cout << phoneDigits[5] << phoneDigits[6] << phoneDigits[7] << "-" << phoneDigits[8] << phoneDigits[9] << phoneDigits[10] << phoneDigits[11] << endl;
                    }

                    // deallocate memory for the array
                    delete[] phoneDigits;
                    phoneDigits = nullptr;
                }
            }
        }

    }

    // assignment overload
    Contact& Contact::operator = (const Contact& rhs) {
        // check for empty object and self-assigned
        if (!isEmpty() && this != &rhs) {
            // shallow copies
            m_flag = rhs.m_flag;
            strncpy(m_contactName, rhs.m_contactName, strlen(rhs.m_contactName));
            m_contactName[strlen(rhs.m_contactName)] = char(0);

            // allocate memory
            m_phoneNumbers = new long long[m_numberOfPhones = rhs.m_numberOfPhones];

            for (int i = 0; i < m_numberOfPhones; i++) {
                m_phoneNumbers[i] = rhs.m_phoneNumbers[i];
            }
        }
        return *this;
    }

    // plus assignment overload
    Contact& Contact::operator += (const long long& phoneNumber) {

        if (!isEmpty() && isPhoneValid(phoneNumber)) {
            long long* phoneAux = new long long[m_numberOfPhones];

            // copy the phone number to the array aux
            for (int i = 0; i < m_numberOfPhones; i++) {
                phoneAux[i] = m_phoneNumbers[i];
            }

            // deallocate memory
            delete[] m_phoneNumbers;

            // allocate new memory
            m_phoneNumbers = new long long[m_numberOfPhones+1];
            m_numberOfPhones++;

            // copy the phones back to the original array
            for (int i = 0; i < m_numberOfPhones-1; i++) {
                m_phoneNumbers[i] = phoneAux[i];
            }

            // add the phone param
            m_phoneNumbers[m_numberOfPhones - 1] = phoneNumber;

        }
        return *this;
    }

    // convert to array helper function
    int* convertToArray(int* emptyArray, long long number, const int& numberOfDigits) {

        //fill the array with the split number
        for (int i = numberOfDigits-1; i >= 0; i--) {
            emptyArray[i] = number % 10;
            number /= 10;
        }

        return emptyArray;
    }

    // number of digits
    int numberOfDigits(long long phone) {
        int result = 0;

        // count number of digits
        while (phone) {
            result++;
            phone /= 10;
        }

        return result;
    }

}