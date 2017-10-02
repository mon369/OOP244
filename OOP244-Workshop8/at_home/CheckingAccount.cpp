#include "CheckingAccount.h"
#include <iomanip>


using namespace std;

namespace ict{    
	
	// TODO: define CheckingAccount class member functions here 
	CheckingAccount::CheckingAccount(double p_amount, double p_transactionFee) :Account(p_amount) {
		transactionFee = (p_transactionFee < 0.0) ? 0 : p_transactionFee;
	}

	void CheckingAccount::chargeFee() {
		int ch = getBalance() - transactionFee;
		setBalance(ch);
	}

	bool CheckingAccount::debit(double d) {
		bool b = Account::debit(d);
		if (b){	chargeFee();}
		return b;
	}

	void CheckingAccount::credit(double c) {
		Account::credit(c);
		chargeFee();
	}

	void CheckingAccount::display(ostream& os) {

		os << "Account type: Checking" << endl;
		os << fixed;
		os << setprecision(2);
		os << "Balance: $ " << getBalance() << endl;
		os << "Transaction Fee: " << transactionFee << endl;

	}
}