/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Jul 08 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 07 - SuperHero header file
---------------------------------------------------------------*/

#ifndef SICT_SUPERHERO_H__
#define SICT_SUPERHERO_H__

#include "Hero.h"

namespace sict {

	class SuperHero : public Hero {
		int m_superPowerAttackBonus; // superpower:  attack bonus
		int m_superPowerDefendBonus; // superpower:  defense

	public:
		// constructors  
		SuperHero();
		SuperHero(const char* name, int maximumHealth, int attack, int superPowerAttack, int superPowerDefend);

		// getters
		int getAttack() const;
		int getDefend() const;
	};

	// Helper Functions
	void applyDamage(SuperHero& A, SuperHero& B);
	const SuperHero & operator*(const SuperHero &, const SuperHero &);

}
#endif // !SICT_SUPERHERO_H__