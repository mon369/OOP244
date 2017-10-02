// OOP244 Workshop 2: AT_HOME
// File KINGDOM.CPP
// Version 1.0
// Date January 22, 2017
// Author: ABEL INOCENCIO
// Student ID: 047-492-095
// Description
// Lab 2
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include "kingdom.h"

using namespace std;

namespace westeros {
	void Kingdom::display(Kingdom &kingdom) const {
		
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}
	void Kingdom::display(Kingdom kingdom[], int count) const{
		int total_population = 0;
		cout << "------------------------------" << endl;
		cout << "Kingdoms of Westeros" << endl;
		cout << "------------------------------" << endl;
		for (int index = 0; index < count; ++index) {
			
			cout << index + 1 << ". " << kingdom[index].m_name << ", population " << kingdom[index].m_population << endl;
			total_population += kingdom[index].m_population;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of Westeros: " << total_population << endl;
		cout << "------------------------------" << endl;

	}
	//Overload #2
	void Kingdom::display(Kingdom  kingdom[], int count, int min) const {

		cout << "------------------------------" << endl;
		cout << "Kingdoms of Westeros with more than " << min << " people" << endl;
		cout << "------------------------------" << endl;
		for (int index = 0; index < count; ++index) {

			if (kingdom[index].m_population >= min) {
				cout << kingdom[index].m_name << ", population " << kingdom[index].m_population << endl;
			}
		}
		cout << "------------------------------" << endl;

	}
	//Overload #3
	void Kingdom::display(Kingdom kingdom[], int count, const char* findKingdom) const {

		int found = 0;
		cout << "------------------------------" << endl;
		cout << "Searching for kingdom " << findKingdom <<  " in Westeros" << endl;
		cout << "------------------------------" << endl;
		for (int index = 0; index < count; ++index) {
			if (strcmp(kingdom[index].m_name,findKingdom) == 0) {
				cout << kingdom[index].m_name << ", population " << kingdom[index].m_population << endl;
				++found;
			}
		}
		if (found == 0) {
			cout << findKingdom << " is not part of Westeros." << endl;
		}
		cout << "------------------------------" << endl;
		cout << endl;

	}
}
