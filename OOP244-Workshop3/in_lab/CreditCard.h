#ifndef CREDITCARD_H
#define CREDITCARD_H

namespace sict {

	const int MAX_NAME_LENGTH = 40;
	const int MIN_INST_NUMBER = 100;
	const int MAX_INST_NUMBER = 999;
	const int MIN_EXP_YEAR = 2017;
	const int MAX_EXP_YEAR = 2037;
	const unsigned long long MIN_CARD_NUMBER = 4000000000000000;
	const unsigned long long MAX_CARD_NUMBER = 4000999999999999;

	class CreditCard {
	private:
		char m_cardHolderName[MAX_NAME_LENGTH];
		unsigned long long m_cardNumber;
		int m_institutionCode;
		int m_expiryYear;
		int m_expiryMonth;
		int m_numberInTheBack;

	public:
		void name(const char cardHolderName[]);
		void initialize(unsigned long long creditCardNumber, int instCode, int expiryYear, int expiryMonth, int numberInTheBack);
		void write() const;
		bool isValid() const;
	};
}

#endif
