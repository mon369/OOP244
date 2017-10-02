#include "SavingsAccount.h"
#include <iomanip>

using namespace std;

namespace ict{ 
	
	// TODO: Implement SavingsAccount member functions here
	SavingsAccount::SavingsAccount(double amount, double interest) : Account(amount) {
		interestRate = (interest < 0.0) ? 0 : interest;
	}

	double SavingsAccount::calculateInterest() {
		double i;
		i = getBalance() * interestRate;
		return i;
	}

	void SavingsAccount::display(ostream& os){

		os << "Account type: Saving" << endl;
		os << fixed;
		os << setprecision(2);
		os << "Balance: $ " << getBalance() << endl;
		os << "Interest Rate (%): " << interestRate * 100 << endl;

	}

}
