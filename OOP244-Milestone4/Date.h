#ifndef H_DATE_H
#define H_DATE_H
// compilation safegaurds

#include <iostream>

// ict namespace 
namespace ict {
   // Date defined Error values
	
	const int NO_ERROR = 0;
	const int CIN_FAILED = 1;
	const int YEAR_ERROR = 2; 
	const int MON_ERROR = 3;
	const int DAY_ERROR = 4;
	const int HOUR_ERROR = 5;
	const int MIN_ERROR = 6;
	

   class Date {
   private:
	   // member variables
	   
	   int m_year; //Year; a four digit integer between MIN_YEAR and MAX_YEAR, as defined in “POS.h”
	   int m_mon; //Month of the year, between 1 to 12
	   int m_day; //Day of the month, note that in a leap year February has 29 days, (see mday() member function)
	   int m_hour; //A two digit integer between 0 and 23 for the hour the a day.
	   int m_min; //A two digit integer between 0 and 59 for the minutes passed the hour
	   int m_readErrorCode; //Error code which identifies the validity of the date and, if erroneous, the part that is erroneous.
	   bool m_dateOnly; //A flag that is true if the object is to only hold the date and not the time.In this case the values 
						//for hour and minute are zero.
	  
     // private methods
	  int value()const; 
			/* This function returns a unique integer number based on the date - time.You can use this
			value to compare two dates.If the value() of one date - time is larger than the value of
			another date - time, then the former date - time(the first one) follows the second.*/
	  void errCode(int errorCode);
			/*Sets the m_readErrorCode member variable to one of the possible values listed above.
			int mdays()const; (this function is already implemented and provided)
			This function returns the number of days in the month based on m_year and m_mon
			values.*/
	  void set();
			/*This function sets the date and time to the current date and time of the system.*/
	  void set(int year, int mon, int day, int hour, int min);
			/*Sets the member variables to the corresponding arguments and then sets the m_readErrorCode to NO_ERROR.*/

   public:
      // constructors

	   Date();
	   Date(int, int, int);
	   Date(int, int, int, int, int = 0);


      // operator ovrloads
	  bool operator==(const Date& D)const;
	  bool operator!=(const Date& D)const;
	  bool operator<(const Date& D)const;
	  bool operator>(const Date& D)const;
	  bool operator<=(const Date& D)const;
	  bool operator>=(const Date& D)const;
      
	  // methods
	  int errCode()const;
		/*Returns the m_readErrorCode value.*/
	 
	  bool bad()const;
		/*Returns true if m_readErrorCode is not equal to zero.*/
		
	  bool dateOnly()const;
	  /*Returns the m_dateOnly attribute.*/
		
	  void dateOnly(bool value);
	  /*Sets the m_dateOnly attribute to the “value” argument.Also if the “value” is true, then 
	  it will set m_hour and m_min to zero.*/
      
	  int mdays()const;

	  //CHECK IF m_year is a leap year, and then add

      // istream  and ostream read and write methods
	  std::istream& read(std::istream& = std::cin);
	  std::ostream& write(std::ostream& = std::cout)const;

   };

   // operator<< and >> overload prototypes for cout and cin
   std::ostream& operator<<(std::ostream&, const Date&);
   std::istream& operator>>(std::istream&, Date&);

}
#endif
