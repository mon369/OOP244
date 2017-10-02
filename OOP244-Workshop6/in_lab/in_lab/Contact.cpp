#include <iostream>
#include <string.h>
#include "Contact.h"
using namespace std;


namespace communication {

	//TODO: Function Definition to validate a phone number
	bool Contact::isValidPhoneNumber( const long long phoneNumber) {

		string phoneString;		
		if (phoneNumber <= 0) {
			return false;
		}
		phoneString = to_string(phoneNumber);				
		if (phoneString.length() < 11 || phoneString.length() > 12) {
			return false;
		}																						  
		if (phoneString[phoneString.length() - numberLength] == '0' || 
			phoneString[phoneString.length() - (areaCodeLength + numberLength)] == '0')
		{
			return false;
		}
		return true;
	}

	//TODO: isEmtpy
	bool Contact::isEmpty() const {

		return (m_name[0] == '\0' &&
			m_phoneNumbers == nullptr &&
			m_noOfPhoneNumbers == 0) 
			? true : false;
	}

	//TODO: Empty constructor
	Contact::Contact() {
		m_name[0] = '\0';
		m_phoneNumbers = nullptr;
		m_noOfPhoneNumbers = 0;
	}

	//TODO: Constructor with three parameters
	Contact::Contact(const char* name, const long long * phoneNumbers, const int noOfPhoneNumbers)
	{
		if (name != nullptr && name[0] != '\0')
		{
			int sizeOf_m_name = (sizeof(m_name) - 1);
			int parameter_name_length = strlen(name);
			int m_name_length = (parameter_name_length > sizeOf_m_name) ? sizeOf_m_name : parameter_name_length;
			for (int i = 0; i < m_name_length; i++)
			{
				m_name[i] = name[i];
			}
			m_name[m_name_length] = '\0';

		}
		else
		{
			m_name[0] = '\0';
		}
		if (phoneNumbers != nullptr && noOfPhoneNumbers > 0)
			{
				if (phoneNumbers != nullptr) {
					m_phoneNumbers = new long long[noOfPhoneNumbers];
					m_noOfPhoneNumbers = 0;
					for (int phone = 0; phone < noOfPhoneNumbers; phone++) {
						if (isValidPhoneNumber(phoneNumbers[phone])) {
							m_noOfPhoneNumbers += 1;
							m_phoneNumbers[m_noOfPhoneNumbers - 1] = phoneNumbers[phone];
						}
					}
				}
			}
			else 
			{
				m_phoneNumbers = nullptr;
				m_noOfPhoneNumbers = 0;
			}
	}

	//TODO: display function
	void Contact::display() const{
		string countryCode;
		string areaCode;
		string numberCode1;
		string numberCode2;
		string phoneNumberString;
		int phoneNumberStringLength;
		if (!isEmpty()) {
		
			cout << m_name << endl;
			for (int phone = 0; phone < m_noOfPhoneNumbers; phone++) {
				phoneNumberString = to_string(m_phoneNumbers[phone]);
				phoneNumberStringLength = phoneNumberString.length();
				countryCode = phoneNumberString.substr(0, (phoneNumberStringLength - (areaCodeLength + numberLength)));
				areaCode = phoneNumberString.substr(phoneNumberStringLength - (areaCodeLength + numberLength), areaCodeLength);
				numberCode1 = phoneNumberString.substr(phoneNumberStringLength - numberLength, numberCode1Length);
				numberCode2 = phoneNumberString.substr(phoneNumberStringLength - numberCode2Length, numberCode2Length);
				
				cout << "(+" + countryCode + ")" + " " + areaCode + " " + numberCode1 + "-" + numberCode2 << endl;			
			}
		}
		else 
		{
			cout << "Empty contact!" << endl;
		}
	}

	//TODO: Destructor
	Contact::~Contact() {
		if(m_phoneNumbers != nullptr)
		{
			delete[] m_phoneNumbers;
			m_phoneNumbers = nullptr;
		}		
		
	}
}


