// OOP244 Workshop 2: IN_LAB
// File KINGDOM.H
// Version 1.0
// Date January 22, 2017
// Author: ABEL INOCENCIO
// Student ID: 047-492-095
// Description
// Lab 2
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
#ifndef H_KINGDOM_H
#define H_KINGDOM_H

namespace westeros
{
	class Kingdom
	{
	public:
	//Public Fields
		char m_name[32];
		int m_population;

	//Functions
		void display(Kingdom&) const;

	};
}

#endif // !H_KINGDOM_H

