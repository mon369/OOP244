#include <iostream>
#include "SuperHero.h"


SuperHero::SuperHero() : Hero()
{
     
}
        
        
SuperHero::SuperHero( const char* name, unsigned maximumHealth, unsigned attack,
                unsigned superPowerAttack, unsigned superPowerDefend
        )  : Hero(name, maximumHealth, attack)
{ 
	m_superPowerAttack = (superPowerAttack > 0) ? superPowerAttack : 0;
	m_superPowerDefend = (superPowerDefend > 0) ? superPowerDefend : 0;
}



  
        
unsigned SuperHero::getAttack() const 
{ 
	return m_superPowerAttack;
}
