// TODO: add your headers here
#include <iostream>
#include <string.h>
#include "passenger.h"
// TODO: add the namespaces that you will be using here
using namespace std;
namespace holiday {
	// TODO: holiday namespace here

		// TODO: add the default constructor here
	Passenger::Passenger(){
		setEmptyState();
	}

	// TODO: add the constructor with 2 parameters here
	Passenger::Passenger(const char name[], const char destination[]) {

		if (name != nullptr && name[0] != '\0' &&
			destination != nullptr && destination[0] != '\0') {
			strcpy(m_name, name);
			strcpy(m_destination, destination);
			m_departureMonth = 7;
			m_departureDay = 1;
			m_departureYear = 2017;
		}
		else 
		{
			setEmptyState();
		}
	}

	// TODO: add the canTravelWith(...) function here
	bool Passenger::canTravelWith(const Passenger &passenger) const {
		return (strcmp(this->m_destination, passenger.m_destination) == 0 &&
			this->m_departureMonth == passenger.m_departureMonth &&
			this->m_departureDay == passenger.m_departureDay &&
			this->m_departureYear == passenger.m_departureYear) ? true : false;
	}

	// TODO: add the isEmpty() function here
	bool Passenger::isEmpty()const {
		return (m_name[0] == '\0' &&
			m_destination[0] == '\0' &&
			m_departureYear == 0 &&
			m_departureMonth == 0 &&
			m_departureDay == 0) ? true : false;
		}
	
	// below is the member function already provided
	// TODO: read it and understand how it accomplishes its task
	void Passenger::display(bool nameOnly) const
	{
		if (false == this->isEmpty())
		{
			cout << this->m_name;
			if (false == nameOnly)
			{
				cout << " will travel to " << this->m_destination << ". "
					<< "The journey will start on "
					<< this->m_departureYear << "-"
					<< this->m_departureMonth << "-"
					<< this->m_departureDay
					<< "." << endl;
			}
		}
		else
		{
			cout << "Invalid passenger!" << endl;
		}
	}
	void Passenger::setEmptyState()
	{
		m_name[0] = '\0';
		m_destination[0] = '\0';
		m_departureYear = 0;
		m_departureMonth = 0;
		m_departureDay = 0;
	}
	
}