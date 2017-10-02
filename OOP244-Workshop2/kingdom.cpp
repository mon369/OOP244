// OOP244 Workshop 2: IN_LAB
// File KINGDOM.CPP
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
#include <iostream>
#include "kingdom.h"
using namespace std;

namespace westeros {
	void Kingdom::display(Kingdom &kingdom) const{

		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}
}
