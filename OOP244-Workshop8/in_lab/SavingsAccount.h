#ifndef ICT_SAVINGSACCOUNT_H__
#define ICT_SAVINGSACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class SavingsAccount : public Account{
		private:
    		double interestRate; // interest rate (percentage)
		public:

			SavingsAccount(double, double);
			// TODO: put prototypes here
			double calculateInterest();
			void display(std::ostream&);


   };
};
#endif
