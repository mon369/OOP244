#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
#include "POS.h"



namespace ict{


	//CONSTRUCTOR NO ARGUMENT
	Date::Date()
	{
		m_dateOnly = false;
		set();
	}
	//CONSTRUCTOR 3 ARGS
	Date::Date(int year, int month, int day) 
	{
		m_dateOnly = true;
		m_year = year;
		m_mon = month;
		m_day = day;
		m_hour = 0;
		m_min = 0;
		m_readErrorCode = NO_ERROR;
	}
	//CONSTRUCTOR 5 ARGS
	Date::Date(int year, int month, int day, int hour, int min)
	{
		m_dateOnly = false;
		set(year, month, day, hour, min);
		m_readErrorCode = NO_ERROR;
	}


  void Date::set(){
    time_t t = time(NULL);
    tm lt = *localtime(&t);
    m_day = lt.tm_mday;
    m_mon = lt.tm_mon + 1;
    m_year = lt.tm_year + 1900;
    if (dateOnly()){
      m_hour = m_min = 0;
    }
    else{
      m_hour = lt.tm_hour;
      m_min = lt.tm_min;
    }
  }

  int Date::value()const{
    return m_year * 535680 + m_mon * 44640 + m_day * 1440 + m_hour * 60 + m_min;
  }

  int Date::mdays()const {
	  int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
	  int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
	  mon--;
	  return days[mon] + int((mon == 1)*((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
  }


  void Date::errCode(int errCode)
  {
	  m_readErrorCode = errCode;
  }

  void Date::set(int year, int mon, int day, int hour, int min)
  {
	  m_year = year;
	  m_mon = mon;
	  m_day = day;
	  m_hour = hour;
	  m_min = min;
  }

  //BOOL OPERATORS
  
  bool Date::operator==(const Date& D)const
  {
	//cout << "DEBUG: " << value() << " " << D.value() << endl;
	  return (value() == D.value()) ? true : false;
  }
 
  bool Date::operator!=(const Date& D)const

  {
	//cout << "DEBUG: " << value() << " " << D.value() << endl;
	  return (value() != D.value()) ? true : false;
  }
  
  bool Date::operator<(const Date& D)const
  {
	//cout << "DEBUG: " << value() << " " << D.value() << endl;
	  return (value() < D.value()) ? true : false;
  }
  
  bool Date::operator>(const Date& D)const
  {
	//cout << "DEBUG: " << value() << " " << D.value() << endl;
	  return (value() > D.value()) ? true : false;
  }
  
  bool Date::operator<=(const Date& D)const
  {
	//cout << "DEBUG: " << value() << " " << D.value() << endl;
	  return (value() <= D.value()) ? true : false;

  }
  
  bool Date::operator>=(const Date& D)const
  {
	//cout << "DEBUG: " << value() << " " << D.value() << endl;
	  return (value() >= D.value()) ? true : false;

  }
 
  //ACCESSOR OR GETTER MEMBER FUNCTIONS

  int Date::errCode() const
  {
	  return m_readErrorCode;
  }

  bool Date::bad() const
  {	
	  return (m_readErrorCode != NO_ERROR) ? true : false;
  }

  bool Date::dateOnly() const
  {
	  return m_dateOnly;
  }

  void Date::dateOnly(bool value)
  {
	  m_dateOnly = value;
	  if (m_dateOnly)
	  {
		  m_hour = 0;
		  m_min = 0;
	  }
  }

  //IO MEMBER-FUNCTIONS
  istream& Date::read(istream& is) {
	  m_readErrorCode = NO_ERROR;
	  char slash = '\0';
	  char c = '\0';

	  is >> m_year;
	  is >> slash;
	  is >> m_mon;
	  is >> slash;
	  is >> m_day;
	  if (!m_dateOnly) {
		  is >> c;
		  is >> m_hour;
		  is >> c;
		  is >> m_min;
	  }

	  if (is.fail() || is.bad()) {
		  m_readErrorCode = CIN_FAILED;
	  }
	  else if (is.eof()) {
		  //Leave for now.
	  }
	  else if (is.good())
	  {		  
		  if (m_year < MIN_YEAR || m_year > MAX_YEAR) {
			  m_readErrorCode = YEAR_ERROR;			 
		  }
		  else if (mdays() == 0  || mdays() == -1) {
			  m_readErrorCode = MON_ERROR;		
		  }
		  else if(m_day < 1 || m_day > mdays()){
			  m_readErrorCode = DAY_ERROR;	
		  }
		  else if (m_hour < 0 || m_hour > 24) {
			  m_readErrorCode = HOUR_ERROR;	
		  }
		  else if (m_min < 0 || m_min > 59){
			  m_readErrorCode = MIN_ERROR;
		  }
		  else {
			  m_readErrorCode = NO_ERROR;
		  }
	  }
	  return is;
  }



  ostream& Date::write(ostream& os) const{


	  os << m_year << "/";
	  if (m_mon < 10) { os << "0"; }
	  os << m_mon << "/";
	  if (m_day < 10) { os << "0"; }
	  os << m_day;
	  if (!m_dateOnly)
	  {
		  os << ", ";
		  if (m_hour < 10) { os << "0"; }
		  os << m_hour << ":";
		  if (m_min < 10) { os << "0"; }
		  os << m_min;
	  }
	  return os;
  }


  std::ostream& operator<<(std::ostream& ostr, const Date& date) {
	  date.write(ostr);
	  return ostr;
  }

  std::istream& operator>>(std::istream& istr, Date& date) {
	  date.read(istr);
	  return istr;
  }


}


