/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jul 08 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 07 - SuperHero implementation file
---------------------------------------------------------------*/

#include <iostream>
#include "SuperHero.h"
using namespace std;

namespace sict {

	//////////////////////////////////////////////
	// Default constructor
	//
	SuperHero::SuperHero() : Hero() {
		// the super class default constructor will set the safe empty state
		m_superPowerAttackBonus = 0;
		m_superPowerDefendBonus = 0;
	}

	//////////////////////////////////////////////
	// Constructor
	//
	SuperHero::SuperHero(const char* name, int maximumHealth, int attack,
		int superPowerAttack, int superPowerDefend
	) : Hero(name, maximumHealth, attack) {
		m_superPowerAttackBonus = superPowerAttack;
		m_superPowerDefendBonus = superPowerDefend;
	}


	//////////////////////////////////////////////
	// member function in SuperHero
	// shadows member function in Hero
	// 
	// Call the function Hero::getAttack and 
	// add the superpowerAttackBonus to it
	int SuperHero::getAttack() const {
		return Hero::getAttack() + m_superPowerAttackBonus;
	}


	//////////////////////////////////////////////
	// new member function in SuperHero
	// note: Hero does not have a getDefend function
	// this function is only callable on SuperHeros
	//
	int SuperHero::getDefend() const {
		return m_superPowerDefendBonus;
	}



	//////////////////////////////////////////////////
	// Global helper function
	// compute the damage that A inflicts on B 
	// and of B on A
	//
	// Superhero vs Superhero fights are calculated differently
	// Defender's damage = Attacker's attack - Defender's defense
	//
	void applyDamage(SuperHero& A, SuperHero& B) {

		int damage_A = B.getAttack() - A.getDefend();
		int damage_B = A.getAttack() - B.getDefend();

		if (damage_A < 1)
		{
			damage_A = 1;
		}
		if (damage_B < 1)
		{
			damage_B = 1;
		}

		A.deductHealth(damage_A);
		B.deductHealth(damage_B);
	}

	//////////////////////
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
	const SuperHero & operator* (const SuperHero & first, const SuperHero & second) {

		// Display the names of the people fighting

		cout << "SuperFight! " << first << " vs " << second << " : ";

		// Since this is a fair tournament, we want the input 
		// arguments to be constant (so that a and b are not modified
		// during the fight.
		// So we make a copy of the objects

		SuperHero A = first;
		SuperHero B = second;
		const SuperHero *winner = nullptr;

		unsigned int rounds = 0;
		// loop while both are still alive
		while (A.isAlive() && B.isAlive() && rounds < 100)
		{
			rounds++;
			applyDamage(A, B);
		}

		// if we got here, then one Hero is dead, or it was a draw.
		bool draw = A.isAlive() && B.isAlive();

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

		cout << "Winner is " << *winner << " in " << rounds << " rounds." << endl;

		return *winner;
	}

}