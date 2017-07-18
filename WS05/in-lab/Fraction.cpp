/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jun 15 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 05 - Fraction implementation file
---------------------------------------------------------------*/

// header files
#include <iostream>
#include "Fraction.h"
using namespace std;

// continue the namespace
namespace sict {

    // set (empty state)
    void Fraction::set() {
        m_flag = false;
        m_numerator = 0;
        m_denominator = 1;
    }

    // set
    void Fraction::set(int numerator, int denominator) {
        m_flag = true;
        m_numerator = numerator;
        m_denominator = denominator;
    }

    // default constructor
    Fraction::Fraction() {
        set();
    }

    // two-argument constructor
    Fraction::Fraction(int numerator, int denominator) {
        // if the fraction is valid, set the parameters
        // if not, set the empty state
        if (fractionIsValid(numerator, denominator)) {
            set(numerator, denominator);
            reduce();
        }
        else {
            set();
        }
    }

    // fraction is valid
    bool fractionIsValid(int numerator, int denominator){
        // numerator must be non-negative
        // denominator must be positive, non-zero
        return ( (numerator >= 0) && (denominator > 0) );
    }

    // max query
    int Fraction::max() const {
        // max returns the maximum of the numerator and denominator
        return (m_numerator > m_denominator) ? m_numerator : m_denominator;
    }

    // min query
    int Fraction::min() const {
        // min returns the minimum of the numerator and denominator
        return (m_numerator < m_denominator) ? m_numerator : m_denominator;
    }

    // gcd returns the greatest common divisor of num and denom
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // reduce modifier
    // reduce simplifies the fraction by dividing the numerator and denominator by the greatest common divisor
    void Fraction::reduce() {
        int divisor = gcd();
        m_numerator /= divisor;
        m_denominator /= divisor;
    }

    // display query
    // display inserts num/denom into the output stream
    void Fraction::display() const {
        // not empty and denominator > 1
        if (!isEmpty() && m_denominator != 1) {
            cout << m_numerator << "/" << m_denominator;
        }
        // if in empty state
        else if (isEmpty()) {
            cout << "no fraction stored";
        }
        // denominator is 1
        else if (!isEmpty() && m_denominator == 1){
            cout << m_numerator;
        }
    }

    // isEmpty query
    // isEmpty returns true if Fraction object is in a safe empty state
    bool Fraction::isEmpty() const {
        return !m_flag;
    }

    // + operator
    // + operator adds the rhs to the current object and reduces the result
    Fraction Fraction::operator + (const Fraction& rhs) {
        Fraction result;
        if (fractionIsValid(m_numerator, m_denominator) && fractionIsValid(rhs.m_numerator, rhs.m_denominator) && !isEmpty() && !rhs.isEmpty() ) {
            // set the result
            result.set((m_numerator * rhs.m_denominator) + (m_denominator * rhs.m_numerator), m_denominator * rhs.m_denominator);
            result.reduce(); // reduce the fraction
        }
        return result;
    }

}