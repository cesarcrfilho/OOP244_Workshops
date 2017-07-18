/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jul 06 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 07 - Hero header file
---------------------------------------------------------------*/

#ifndef SICT_HERO_H__
#define SICT_HERO_H__

#include <iostream>

    class Hero {
    private:
        bool m_flag; // controls safe empty state
        char m_name[41];
        int  m_attack;
        int  m_maximumHealth;
        int  m_health;

        bool isEmpty() const;

        // setter functions for constructors
        void set();
        void set(const char name[], int maximumHealth, int attack);

    public:
        // constructors
        Hero();
        Hero(const char name[], int maximumHealth, int attack);

        // member functions
        void respawn();
        bool isAlive() const { return m_health > 0; }
        int  getAttack() const { return m_attack; }
        void deductHealth(int);
        void display(std::ostream& = std::cout) const; // default cout

        // friend helper function to insert name into ostream
        friend std::ostream& operator<<(std::ostream&, const Hero&);
    };

    void applyDamage(Hero& A, Hero& B);
    const Hero & operator*(const Hero &, const Hero &);


#endif // SICT_HERO_H__
