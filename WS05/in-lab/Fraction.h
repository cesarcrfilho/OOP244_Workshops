/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jun 15 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 05 - Fraction header file
---------------------------------------------------------------*/

// header file guard
#ifndef SICT_FRACTION_H__
#define SICT_FRACTION_H__

// create namespace
namespace sict {

    // Fraction class
    class Fraction {
    private:
        bool m_flag; // empty state flag
        int m_numerator;
        int m_denominator;
        int gcd() const; // returns the greatest common divisor of num and denom
        int max() const; // returns the maximum of num and denom
        int min() const; // returns the minimum of num and denom
        void reduce();   // simplifies a Fraction by dividing the 
                         // numerator and denominator to their greatest common divisor
        void set(); // sets the object to empty state
        void set(int numerator, int denominator); // sets the object
    public:
        Fraction(); // default constructor
        Fraction(int numerator, int denominator); // constructor with 2 parameters
        bool isEmpty() const; // check if the object is in the empty state
        void display() const;
        Fraction operator + (const Fraction& rhs); // operator overloading
    };

    bool fractionIsValid(int numerator, int denominator); // checks if the numerator and denominator are valid
}

#endif // !SICT_FRACTION_H__