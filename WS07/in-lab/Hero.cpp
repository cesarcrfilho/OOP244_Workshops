/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jul 06 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 07 - Hero implementation file
---------------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Hero.h"
using namespace std;

    //////////////////////////////////////////////
    // Setter functions for constructors
    //

    // Set function - no parameters
    void Hero::set() {
        m_flag = false;
        m_name[0] = char(0);
        m_attack = 0;
        m_maximumHealth = 0;
        m_health = 0;
    }

    // Set function - three parameters
    void Hero::set(const char name[], int maximumHealth, int attack) {
        m_flag = true;
        if (name != nullptr)
            strncpy(m_name, name, 41);
        m_attack = attack;
        m_maximumHealth = maximumHealth;
        m_health = maximumHealth;
    }

    //////////////////////////////////////////////
    // Default constructor
    //
    Hero::Hero() {
        set();
    }

    ///////////////////////////////////////////////////
    // Constructor
    // 
    Hero::Hero(const char name[], int maximumHealth, int attack) {
        set(name, maximumHealth, attack);
    }

    /////////////////////////////////////////////////////////
    // ostream helper overloaded operator <<
    // 
    ostream& operator<<(ostream& out, const Hero& h) {
        return out << h.m_name;
    }

    /////////////////////////////////////////////////
    // Hero::isEmpty ()
    // return true if the Hero object is uninitialized
    //
    bool Hero::isEmpty() const {
        return !m_flag;
    }

    /////////////////////////////////////////////////
    // Hero::display(std::ostream&)
    // prints the hero’s name to the output stream
    //
    void Hero::display(ostream& os) const {
        if (!isEmpty())
            os << m_name;
    }

    /////////////////////////////////////////////////
    // sets the Hero object's health back to full
    //
    void Hero::respawn() {
        m_health = m_maximumHealth;
    }

    void Hero::deductHealth(int attack) {
        // if the attack is greater than the remaining health,
        // the hero dies and health = 0
        if (attack >= m_health)
            m_health = 0;
        else
            m_health -= attack;
    }

    //////////////////////////////////////////////////////////////////
    // Global helper function
    // compute the damage that A inflicts on B 
    // and of B on A
    //
    void applyDamage(Hero& A, Hero& B) {
        A.deductHealth(B.getAttack());
        B.deductHealth(A.getAttack());
    }

    //////////////////////////////////////////////////////////////////
    // Global helper operator
    // rather than type in fight(hercules, theseus), we use an operator
    // so you can type in hercules * theseus
    //
    // returns a reference to the winner object
    // 
    // so that if hercules is stronger, 
    // (hercules * theseus) == hercules
    // will be true.
    // 
    // note the inputs are const, so that you can be sure that the heros will be unharmed during the fight.
    //
    const Hero & operator* (const Hero & first, const Hero & second) {
        // Display the names of the people fighting

        cout << "AncientBattle! " << first << " vs " << second << " : ";

        // We want our heroes to exit the battle unharmed, so 
        // we make the input arguments const.
        // So how can we modify the objects during the fight?
        // We make copies of them.
        Hero A = first;
        Hero B = second;
        const Hero *winner = nullptr;

        // Now A will fight B, and winner will point to the winner.    
        // Main fight loop
        unsigned int rounds = 0;
        // loop while both are still alive
        // fight for 100 rounds
        while (A.isAlive() && B.isAlive() && rounds < 100)
        {
            rounds++;
            applyDamage(A, B);
        }

        // if we got here, then one Hero is dead, or if both are alive then it was a draw.
        bool draw;

        if (A.isAlive() && B.isAlive()) { draw = true; }
        else { draw = false; }

        // if it was a draw, then we decide by tossing an unfair coin and always
        // declare that A was the winner. 
        if (draw)
        {
            winner = &first;
        }
        else if (A.isAlive())
        {
            winner = &first;
        }
        else
        {
            winner = &second;
        }

        // print out the winner
        cout << "Winner is " << *winner << " in " << rounds << " rounds." << endl;

        // return a reference to the winner
        return *winner;
}