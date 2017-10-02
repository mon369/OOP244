#include "Account.h"

using namespace std;

namespace ict{ 
	
	// constructor
	Account::Account(double p_balance) {
		p_balance = (p_balance >= 0.0) ? p_balance : 1.0;
		setBalance(p_balance);
	}
	

	// credit (add) an amount to the account balance
	void Account::credit(double c) {
		int credit = getBalance() + c;
		setBalance(credit);
	}

	
	// debit (subtract) an amount from the account balance return bool 
	void Account::debit(double d) {
		int debit = getBalance() - d;
		setBalance(debit);
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