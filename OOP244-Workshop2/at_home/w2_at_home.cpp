// OOP244 Workshop 2: AT_HOME
// File W2_AT_HOME.CPP
// Version 1.0
// Date January 22, 2017
// Author: ABEL INOCENCIO
// Student ID: 047-492-095
// Description
// Lab 2 at home
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
	Kingdom* pKingdoms = nullptr;
	
	// TODO: declare the pKingdoms pointer here (don't forget to initialize it)

	cout << "==========" << endl
		 << "Input data" << endl
		 << "==========" << endl
		 << "Enter the number of kingdoms: ";
	cin >> count;
	cin.ignore();

	if (pKingdoms == nullptr) {
		// TODO: allocate dynamic memory here for the pKingdoms pointer
		pKingdoms = new Kingdom[count];

		for (int i = 0; i < count; ++i)
		{
			// TODO: add code to accept user input for the pKingdoms array
			cout << "Enter the name for kingdom #" << i + 1 << ": ";
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

		// testing that the first overload of "display(...)" works
		pKingdoms[0].display(pKingdoms, count);
		cout << endl;

		// testing that the second overload of "display(...)" works
		pKingdoms[0].display(pKingdoms, count, 345678);
		cout << endl;

		// testing that the third overload of "display(...)" works
		pKingdoms[0].display(pKingdoms, count, "Mordor");
		cout << endl;

		pKingdoms[0].display(pKingdoms, count, "The_Vale");
		cout << endl;
		}

	// TODO: deallocate the dynamic memory here
	if (pKingdoms != nullptr) {
		delete[] pKingdoms;
		pKingdoms = nullptr;
	}

	return 0;
}
