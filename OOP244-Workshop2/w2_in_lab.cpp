// OOP244 Workshop 2: IN_LAB
// File W2_IN_LAB.CPP
// Version 1.0
// Date January 27, 2017
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
using namespace westeros;

int main(void)
{
	int count = 0; // the number of kingdoms in the array
	
	// TODO: declare the kingdoms pointer here (don't forget to initialize it)
	Kingdom* pKingdoms = nullptr;


	cout << "==========" << endl
		 << "Input data" << endl
		 << "==========" << endl
		 << "Enter the number of kingdoms: ";
	cin >> count;
	cin.ignore();

	// TODO: allocate dynamic memory here for the kingdoms pointer
	if (pKingdoms == nullptr) {
		pKingdoms = new Kingdom[count];
	}

	for (int i = 0; i < count; i++)
	{
		// TODO: add code to accept user input for the kingdoms array
		cout << "Enter the name for kingdom #" << i+1 << ": ";
		cin >> pKingdoms[i].m_name;
		cout << "Enter the number people living in " << pKingdoms[i].m_name << ": ";
		cin >> pKingdoms[i].m_population;
		
	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
		cout << "------------------------------" << endl
		<< "The first kingdom of Westeros" << endl
		<< "------------------------------" << endl;

		pKingdoms[0].display(pKingdoms[0]);
	
		cout << "------------------------------" << endl << endl;

	// TODO: deallocate the dynamic memory here

	if (pKingdoms != nullptr) {
		delete[] pKingdoms;
		pKingdoms = nullptr;
	}
	return 0;
}
