//TODO: add header guards here
#ifndef H_PASSENGER_H
#define H_PASSENGER_H

// TODO: holiday namespace here
namespace holiday {

	// TODO: declare the class Passenger here
	class Passenger {
		
	
		char m_name[32];
		char m_destination[32];
		int m_departureYear;
		int m_departureMonth;
		int m_departureDay;
		void setEmptyState();

	public:


		// TODO: add the class the attributes,
		//       the member function already provided,
		//       and the member functions that you must implement
		
		Passenger();
		Passenger(const char[], const char[]);
		Passenger(const char[], const char[], int, int, int);
		void display(bool = false) const;
		bool isEmpty() const;
		bool canTravelWith(const Passenger&) const;
		void travelWith(const Passenger*, int);

	};

}


#endif // !H_PASSENGER_H