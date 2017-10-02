#include <string.h>
#include <iostream>
#include "Hero.h"

using namespace std;


//////////////////////////////////////////////
// Default constructor
//
Hero::Hero ()
{
	*m_name = '\0';
	m_health = 0;
	m_maximumHealth = 0;
	m_attack = 0;
}


///////////////////////////////////////////////////
// Constructor
// 
Hero::Hero (const char name[], unsigned maximumHealth, unsigned attack)
{
	if (name == nullptr || name[0] == '\0') {
		*m_name = '\0';
	}
	else {

			
		int nullTerminateAt = (strlen(name) > (sizeof(m_name) - 1)) ? strlen(name) : sizeof(m_name);
		strncpy(m_name, name, sizeof(m_name) - 1);
		m_name[nullTerminateAt] = '\0';
	}
	m_maximumHealth = (maximumHealth > 0) ? maximumHealth : 0;
	m_health = m_maximumHealth;
	m_attack = (attack > 0) ? attack : 0;
}



/////////////////////////////////////////////////////////
// 
// Hero::display function
void Hero::display (ostream & out) const 
{
	if (!isEmpty()) {
		out << m_name;
	}
 
}



/////////////////////////////////////////////////
// Hero::isEmpty ()
// return true if the Hero object is uninitialized
//
bool Hero::isEmpty () const 
{
	return (m_name[0] == '\0' &&
		m_maximumHealth == 0 &&
		m_health == 0 &&
		m_attack == 0) ?
		true : false;
}

/////////////////////////////////////////////////
// sets the Hero object's health back to full
//
void Hero::respawn() 
{
	m_health = m_maximumHealth;
}

