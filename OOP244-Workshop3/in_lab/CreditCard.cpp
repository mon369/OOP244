#include <iostream>
#include <cstring>
#include "CreditCard.h"
using namespace std;

namespace sict {

	void CreditCard::name(const char cardHolderName[]) {
		
		strcpy(m_cardHolderName, cardHolderName);
	}
	void CreditCard::initialize(unsigned long long creditCardNumber, int instCode, int expiryYear, int expiryMonth, int numberInTheBack) {
		m_cardNumber = creditCardNumber;
		m_institutionCode = instCode;
		m_expiryYear = expiryYear;
		m_expiryMonth = expiryMonth;
		m_numberInTheBack = numberInTheBack;
	}
	bool CreditCard::isValid() const{
		const int validCountTotal = 6;
		int validCounter = 0;
		int nameLength = strlen(m_cardHolderName);
		
		if (nameLength > 0 && nameLength <= MAX_NAME_LENGTH) {
			++validCounter;
		}
		if(m_cardNumber >=  MIN_CARD_NUMBER && m_cardNumber <= MAX_CARD_NUMBER){
			++validCounter;
		}
		if(m_institutionCode >=  MIN_INST_NUMBER && m_institutionCode <= MAX_INST_NUMBER){
			++validCounter;
		}
		if(m_expiryYear >= MIN_EXP_YEAR && m_expiryYear <= MAX_EXP_YEAR) {
			++validCounter;
		}
		if(m_expiryMonth >= 1 && m_expiryMonth <= 12) {
			++validCounter;
		}
		if (m_numberInTheBack >= 0 && m_numberInTheBack <= 999) {
			++validCounter;
		}

		return
			(validCounter == validCountTotal) ? true : false;
	}

	void CreditCard::write() const{
		if (isValid())
		{
			cout << "Cardholder: " << m_cardHolderName << endl;
			cout << "Card Number: " << m_cardNumber << endl;
			cout << "Institution: " << m_institutionCode << endl;
			cout << "Expires: " << m_expiryMonth << "/" << m_expiryYear << endl;
			cout << "Number at the back: " << m_numberInTheBack;
		}
	}
}
