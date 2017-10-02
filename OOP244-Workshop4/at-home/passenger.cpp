// TODO: add your headers here
#include <iostream>
#include <string.h>
#include "passenger.h"
// TODO: add the namespaces that you will be using here
using namespace std;
namespace holiday {
	// TODO: holiday namespace here


		// TODO: add the default constructor here
	Passenger::Passenger() {
		setEmptyState();
	}

	// TODO: add the constructor with 2 parameters here
	Passenger::Passenger(const char name[], const char destination[]){
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

	Passenger::Passenger(const char name[], const char destination[], int year, int month, int day) {
		if (name != nullptr && name[0] != '\0' &&
			destination != nullptr && destination[0] != '\0' &&
			year >= 2017 && year <= 2020 &&
			month >= 1 && month <= 12 &&
			day >= 1 && day <= 31) {

			strcpy(m_name, name);
			strcpy(m_destination, destination);
			m_departureMonth = month;
			m_departureDay = day;
			m_departureYear = year;
		}
		else 
		{
			setEmptyState();
		}
	}

	// TODO: add the canTravelWith(...) function here
	bool Passenger::canTravelWith(const Passenger &passenger) const {
		return (strcmp(m_destination, passenger.m_destination) == 0 &&
			m_departureMonth == passenger.m_departureMonth &&
			m_departureDay == passenger.m_departureDay &&
			m_departureYear == passenger.m_departureYear) ? true : false;

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

	// TODO: add the travelWith function here
	void Passenger::travelWith(const Passenger *arrPassengers, int size) {
		int friends = 0;
		bool* travelWithYesorNo = new bool[size];
		if (arrPassengers != nullptr)
		{
			for (int i = 0; i < size; i++) {
				if (canTravelWith(arrPassengers[i])) {
					++friends;
					travelWithYesorNo[i] = true;
				}
				else {
					travelWithYesorNo[i] = false;
				}
			}
		}

		if (friends == 0 || arrPassengers == nullptr) {
			cout << "Nobody can join " << m_name << " on vacation!" << endl;
		}
		else
		{
			if (friends == size) {
				cout << "Everybody can join " << m_name << " on vacation!" << endl;
			}
			cout << this->m_name << " will be accompanied by ";
			for (int i = 0; i < size; i++) {
				if (travelWithYesorNo[i]) {
					cout << arrPassengers[i].m_name;

					if (i < size - 1) {
						cout << ", ";
					}
				}
			}
			cout << "." << endl;
		}


		if (travelWithYesorNo != nullptr) {
			delete[] travelWithYesorNo;
			travelWithYesorNo = nullptr;
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