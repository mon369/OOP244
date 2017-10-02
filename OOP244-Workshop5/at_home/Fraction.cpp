#include "Fraction.h"

using namespace std;

namespace sict{
    Fraction::Fraction(){  
            denom =-1;              // safe empty state
    }
    
    Fraction::Fraction(int n, int d) // n: numerator, d: denominator
    { 
        if(n >= 0 && d > 0){
            num = n;
            denom = d;
            reduce();
        }
        else 
            denom =-1;              // set to safe empty state
    }

    int Fraction::gcd()                                        // returns the greatest common divisor of num and denom 
    {
        int mn = min();                                        // min of num and denom
        int mx = max();                                        // mX of num and denom

        for (int x=mn ; x > 0 ; x--)                           // find the greatest common divisor
            if( mx % x == 0 &&  mn % x == 0)
                return x;
        return 1;

    } 

    void Fraction::reduce()                                         // simplify the Fraction number  
    {
        int tmp = gcd();
        num /= tmp;
        denom /= tmp;
    }

    int Fraction::max ()
    {
        return (num >= denom) ? num : denom; 
    }

    int Fraction::min()
    {
        return (num >= denom) ? denom : num; 
    }
  
	// TODO: write the implementation of display function HERE
	void Fraction::display() const {
		if (!isEmpty()) {
			cout << num;
			if (denom > 1) cout << "/" << denom;
		}
		else {
			cout << "Invalid Fraction Object!";
		}
	}


	// TODO: write the implementation of isEmpty function HERE
	bool Fraction::isEmpty() const {
		return (denom == -1);
	}

	// TODO: write the implementation of member operator+= function HERE
	Fraction& Fraction::operator+=(const Fraction& fraction) {
		if (!isEmpty() && !fraction.isEmpty())
		{
			num = (num * fraction.denom) + (denom * fraction.num);
			denom *= fraction.denom;
			reduce();
		}
		else
		{
			denom = -1;
		}
		return *this;
	}

	// TODO: write the implementation of member operator+ function HERE
	Fraction Fraction::operator+(const Fraction fraction) {
		Fraction f = *this;
		//Invoke the operator += function for code simplicity.
		return (f += fraction);
	}

	// TODO: write the implementation of member operator* function HERE
	Fraction Fraction::operator*(const Fraction fraction) {
		Fraction f = *this;
		if (!f.isEmpty() && !fraction.isEmpty())
		{
			f.num *= fraction.num;
			f.denom *= fraction.denom;
			f.reduce();
		}
		else
		{
			f.denom = -1;
		}
		return f;
	}


    // TODO: write the implementation of member operator== function HERE
	bool Fraction::operator==(const Fraction& f) const {

		if (isEmpty() || f.isEmpty()) {
			return false;
		}
		else
		{
			return ((num * f.denom) == (f.num * denom)) ;
		}
	}

    // TODO: write the implementation of member operator!= function HERE
	bool Fraction::operator!=(const Fraction& f) const {

		//Invoke the operator== function, but boolean returns the opposite for !=
		return (*this == f) ? false : true;
	}
    // TODO: write the implementation of member operator double () function HERE
	Fraction::operator double() {
		if (!isEmpty())
		{
			return (double)num / (double)denom;
		}
		else
		{
			return -1.0;
		}
	}
    // TODO: write the implementation of member operator double () function HERE
	Fraction::operator int() {
		
		//Invoke the double() operator, and cast the return value to int.
		return  (int)((double)*this);
	}

}
