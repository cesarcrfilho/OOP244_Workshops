/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jul 27 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 09 - String header file
---------------------------------------------------------------*/

#ifndef SICT_STRING_H_
#define SICT_STRING_H_
#include <iostream>

namespace sict {
    class String {
	private:
        //string buffer
        char *m_pString;
        // capacity 
        int m_capacity;
    public:
        // default constructor
        String(int size = 1);
        String(const char* src, int size = 1);
        String(const String& src, int size = 1);
        String& operator = (const String& src);
        ~String();

        // resize
        virtual void resize (int newsize);
        // capacity
        int capacity () { return m_capacity; }
        
        // length
        int length() const;
        // empty
        bool empty() const;

        // operator overloading
        String& operator += (char c);
        String& operator+= (const String& s2);
        String operator + (const String& s2) const;
        operator const char*() const;
        operator bool() const;
        bool operator== (const String& s2)const;
        
    };

    // helper functions
    std::ostream& operator << (std::ostream&, const String&);
    std::istream& operator >> (std::istream&, String&);

};

#endif // !SICT_STRING_H_