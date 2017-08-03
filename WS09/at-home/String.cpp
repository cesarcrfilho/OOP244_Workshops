/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jul 27 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 09 - String implementation file
---------------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "String.h"

namespace sict {
    
	//             CONSTRUCTORS             //
	
    // default constructor
	// String x(int)
    String::String(int capacity) {
        m_pString = new char[m_capacity = capacity];
        m_pString[0] = '\0';
    }

    // String x(char*, int)
    String::String(const char* pSource, int capacity) {
        int strLength = (int)strlen(pSource) + 2;
        capacity >= strLength ? m_capacity = capacity : m_capacity = strLength ;
        m_pString = new char[m_capacity];
        strcpy(m_pString, pSource);
    }

    // copy constructor
	// String x(String&, int)
    String::String(const String& other, int capacity) {
        int strLength = other.length() + 1;
        capacity >=  strLength ? m_capacity = capacity : m_capacity = strLength;
        m_pString = new char[m_capacity];
        strcpy(m_pString, other.m_pString);
    }

	// destructor
	String::~String() {
		delete[] m_pString;
		m_pString = nullptr;
	}

	//////////////////////////////////////////

    // resize
    void String::resize(int newsize) {
        int strLength = length() + 1;
        newsize >= strLength ? m_capacity = newsize : m_capacity = strLength;
        char* strTmp = new char[m_capacity];
        strcpy(strTmp, m_pString);
        delete[] m_pString;
        m_pString = nullptr;
        m_pString = new char[m_capacity];
        strcpy(m_pString, strTmp);
    }
    
	// operator =
    // String = String
    String& String::operator=(const String& other) {
        int strLength = other.length() + 1;
        if (this != &other) {
            delete[] m_pString;
            m_pString = nullptr;
            m_capacity = 0;
            other.m_capacity >= strLength ? m_capacity = other.m_capacity : m_capacity = strLength;
            m_pString = new char[m_capacity];
            strcpy(m_pString, other.m_pString);
        }
        return *this;
    }

    // length
    int String::length() const {
        return strlen(m_pString);
    }

	// operator char*
    String::operator const char *() const {
        return m_pString;
    }

    // empty
    bool String::empty() const {
        return (m_pString[0] == char(0) || length() == 0);
    }
    
    // operator bool
    String::operator bool() const {
        return !empty();
    }
    
    // operator ==
	// String == String
    bool String::operator==(const String& s2) const {
        return std::strcmp(m_pString, s2) == 0;
    }
    
    // operator +=
	// String += String
    String& String::operator+=(const String& s2) {
        *this = (*this + s2);
        return *this;
    }
    
    // operator +
	// String + String
    String String::operator+(const String& s2) const {
        char* tmpStr = new char[length() + s2.length() + 1];
        strcpy(tmpStr, m_pString);
        strcat(tmpStr, s2.m_pString);
        return tmpStr;
    }
    
    // operator +=
	// String += char
    String& String::operator+= (char c) {
        if (m_capacity < length() + 2) {
            m_capacity = length() + 2;
        }
        char tmpStr[2];
        tmpStr[0] = c;
        tmpStr[1] = char(0);
        resize(m_capacity);
        strcat(m_pString, tmpStr);
        return *this;
    }
    
    // operator <<
	// String << ostream
    std::ostream& operator<<(std::ostream& ostream, const String &s) {
        ostream << (const char*)s;
        ostream.clear();
        return ostream;
    }

    // operator >>
	// String >> istream
    std::istream& operator>>(std::istream& istream, String &s)
    {
        s = "";
        char tempC = 0;
        do {
            tempC = istream.get();
            if (tempC != '\n') {
                s += tempC;
            }
            else
                break;
        } while(1);
        return istream;
    }
  
}