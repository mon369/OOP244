#include "Account.h"

using namespace std;

namespace ict{ 
	
	// constructor
	Account::Account(double p_balance) {
		balance = (p_balance >= 0.0) ? p_balance : 1.0;
	}
	

	// credit (add) an amount to the account balance
	void Account::credit(double c) {
		int credit = getBalance() + c;
		setBalance(credit);
	}

	
	// debit (subtract) an amount from the account balance return bool 
	bool Account::debit(double d) {
		bool b = getBalance() > d;
		if (b)
		{
			int debit = getBalance() - d;
			setBalance(debit);
		}
		return b;
	}

	double Account::getBalance() const
	{
		return balance;
	} 

	void Account::setBalance( double newBalance )
	{
		balance = newBalance;
	} 
}