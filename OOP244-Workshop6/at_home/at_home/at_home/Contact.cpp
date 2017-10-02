#include <iostream>
#include <string.h>
#include "Contact.h"
using namespace std;

namespace communication {
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
			strncpy(m_name, name, sizeof(m_name) - 1);
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


	//TODO: Copy Constructor
	Contact::Contact(const Contact& other) {
		//Set Empty state before copying.
		m_name[0] = '\0';
		m_phoneNumbers = nullptr;
		m_noOfPhoneNumbers = 0;
		*this = other;
	}

	Contact& Contact::operator=(const Contact& other) {	 
		if (this != &other) {
			strncpy(m_name, other.m_name, sizeof(m_name)-1);
			m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;
			//Delete previously allocated phone Numbers
			delete[] m_phoneNumbers;
			if (other.m_phoneNumbers != nullptr) {
				m_phoneNumbers = new long long[m_noOfPhoneNumbers];
				for (int i = 0; i < m_noOfPhoneNumbers; i++) {
					m_phoneNumbers[i] = other.m_phoneNumbers[i];
				}
			}
			else {
				m_phoneNumbers = nullptr;
			}
		}
		return *this;
	}

	//TODO: display function
	void Contact::display() const{
		if (!isEmpty()) {
		
			cout << m_name << endl;
			if (m_noOfPhoneNumbers > 0)
			{
				for (int phone = 0; phone < m_noOfPhoneNumbers; phone++) {
					string phoneNumberString = to_string(m_phoneNumbers[phone]);
					int phoneNumberStringLength = phoneNumberString.length();
					string countryCode = phoneNumberString.substr(0, (phoneNumberStringLength - (areaCodeLength + numberLength)));
					string areaCode = phoneNumberString.substr(phoneNumberStringLength - (areaCodeLength + numberLength), areaCodeLength);
					string numberCode1 = phoneNumberString.substr(phoneNumberStringLength - numberLength, numberCode1Length);
					string numberCode2 = phoneNumberString.substr(phoneNumberStringLength - numberCode2Length, numberCode2Length);

					cout << "(+" + countryCode + ")" + " " + areaCode + " " + numberCode1 + "-" + numberCode2 << endl;
				}
			}
		}
		else 
		{
			cout << "Empty contact!" << endl;
		}
	}

	//TODO: Function Definition to validate a phone number
	bool Contact::isValidPhoneNumber(const long long phoneNumber) {

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

	//TODO: addPhoneNumber
	void Contact::addPhoneNumber(const long long phoneNumber) {
		m_noOfPhoneNumbers += 1;

		//cout << m_noOfPhoneNumbers << endl;
		if (m_phoneNumbers == nullptr) 
		{
			m_phoneNumbers = new long long[m_noOfPhoneNumbers];
			arraySize = m_noOfPhoneNumbers;
		} 	
		if (m_noOfPhoneNumbers > arraySize) 
		{
			resizeArray();
		}
		
		m_phoneNumbers[m_noOfPhoneNumbers - 1] = phoneNumber;
	}

	void Contact::resizeArray() {

		long long* temp = new long long[arraySize];

		for (int i = 0; i < arraySize; i++) {
			temp[i] = m_phoneNumbers[i];
		}

		delete[] m_phoneNumbers;
		m_phoneNumbers = nullptr;

		//Inneficient to resize array every 1 new phone Number.
		//Let's do a resize every 10 phoe numbers.
		const int resizeIncreaseBy = 10;
		m_phoneNumbers = new long long[arraySize + resizeIncreaseBy];

		for (int i = 0; i < arraySize; i++) {
			m_phoneNumbers[i] = temp[i];
		}
		arraySize += resizeIncreaseBy;
		if (temp != nullptr) {
			delete[] temp;
			temp = nullptr;
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


