#ifndef ICT_ITEM_H__
#define ICT_ITEM_H__
// inlcude PosIO and POS header files
#include <iostream>
#include "PosIO.h"
#include "POS.h"


namespace ict{
  // class Item
	class Item : public PosIO {

	private:

		char m_sku[MAX_SKU_LEN + 1];
		char* m_name;
		double m_price;
		bool m_taxed;
		int m_quantity;

	public:
		//CONSTURCTORS
		Item();
		Item(const char*, const char*, double, bool);
		Item(const Item&);
		Item& operator=(const Item&);

		//SETTERS
		void sku(const char*);
		void price(const double);
		void name(const char*);
		void taxed(const bool);
		void quantity(const int);

		//GETTERS
		const char* sku() const;
		double price() const;
		const char* name() const;
		bool taxed() const;
		int quantity() const;
		double cost() const; //CONST?
		bool isEmpty() const;

		//MEMBER OPERATORS
		bool operator==(const char*) const;
		int operator+=(const int);
		int operator-=(const int);

		//SET EMPTY STATE
		void setEmptyState();

		//DESTRUCTOR
		virtual ~Item();


	};// end class Item
  
	// operator += 
  double operator+=(double& d, const Item& I);


  // operator << and operator >>
  std::ostream& operator<<(std::ostream&, const Item&);
  std::istream& operator>>(std::istream&, Item&);

}


#endif