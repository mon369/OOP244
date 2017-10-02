#ifndef ICT_ACCOUNT_H__
#define ICT_ACCOUNT_H__

#include <iostream>

using namespace std;

namespace ict{

	class Account{
		private:
			double balance; // data member that stores the balance

		protected:
			double getBalance() const; // return the account balance
			void setBalance( double ); // sets the account balance

   		public:
			// TODO: Write a prototype for constructor which initializes balance
			Account(double);
			// TODO: Write a function prototype for the virtual function credit
			virtual void credit(double);
			// TODO: Write a function prototype for the virtual function debit
			virtual void debit(double);
			// TODO: Write a function prototype for the virtual function display
			virtual void display(std::ostream&) = 0;
   };
};
#endif
