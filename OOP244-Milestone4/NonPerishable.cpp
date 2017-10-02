#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <iostream>
#include <iomanip>
#include <cstring>
#include "NonPerishable.h"
#include "Error.h"

using namespace std;

namespace ict {

	bool NonPerishable::ok() const {
		return m_error.isClear();
	}

	void NonPerishable::error(const char* message) {
		m_error.message(message);
	}

	char NonPerishable::signature() const {
		return 'N';
	}

	fstream& NonPerishable::save(fstream& fs) const {
		fs << signature() << "," << sku() << "," <<
			name() << "," << price() << "," << taxed() << "," << quantity();
		return fs;
	}

	fstream& NonPerishable::load(fstream& fs) {
		//IGNORE SIGNATURE
		const int buffSize = 1000;
		char buffName[buffSize];
		
		//EXTRACT SKU
		fs.getline(buffName, buffSize, ',');
		sku(buffName);
		*buffName = 0;
		

		//NAME
		fs.getline(buffName, buffSize, ',');
		name(buffName);
		*buffName = 0;

		//PRICE
		double buffPrice = 0.0;
		fs >> buffPrice;
		price(buffPrice);
		fs.ignore();
		
		//TAXED
		bool buffTaxed = false;
		fs >> buffTaxed;
		taxed(buffTaxed);
		fs.ignore();

		//QUANTITY
		int buffQty = 0;
		fs >> buffQty;
		quantity(buffQty);
		fs.ignore();

		return fs;
	}

	fstream& operator<<(fstream& fs, const NonPerishable& np) {
		np.save(fs);
		return fs;
	}
	fstream& operator >> (fstream& fs, NonPerishable& np) {
		np.load(fs);
		return fs;
	}

	ostream& NonPerishable::write(ostream& os, bool linear) const {
		char t = 'T';
		
		os << fixed;
		os << setprecision(2);
		if (ok()) {
			switch (linear) {

			case true:
				

				os << setw(MAX_SKU_LEN) << left;
				os << sku();
				os << "|";

				os << setw(20) << left;
				os << name();
				os << "|";

				//PRICE

				os << setw(7) << right;
				os << price();
				os << "|";

				//TAXED
				os << " ";
				if (!taxed()) {
					t = ' ';
				}
				os << t;
				os << signature();
				os << "|";

				//QUANTITY

				os << setw(4) << right;
				os << quantity();
				os << "|";

				//COST
				os << setw(9) << right;
				os << cost() * quantity();
				os << "|";

				break;

			case false:
				os << "Name: " << endl << name() << endl;
				os << "Sku: " << sku() << endl;
				os << "Price: " << price() << endl;
				os << "Price after tax: ";
				
				if (taxed()) {
					os << cost();
				}
				else {
					os << "N/A";
				}
				os << endl;
				os << "Quantity: " << quantity() << endl;
				os << "Total Cost: " << cost() * quantity() << endl;
				break;
			}
		}
		else {
			if (!m_error.isClear())
			{
				os << (const char*)m_error;
			}
		}
		return os;
	}
	
	istream& NonPerishable::read(istream& is) {

		
		cout << "Item Entry:" << endl;
		char buff[2000];
		int ibuff = 0;
		double dbuff = 0.0;
		char c;
		
		//RESET FLAGS AND ERRORS BEFORE PROCEEDING
		is.clear();
		m_error.clear();

		cout << "Sku: ";
		is >> buff;
		if (is.fail()) {
			error("Invalid Sku Entry");
		}
		else if (is.good()) {
			sku(buff);
			*buff = 0;
		}

		if (is.good()) {
			cout << "Name: " << endl;
			is >> buff;
			if (is.fail()) {
				error("Invalid Name Entry");
			}
			else if (is.good()) {
				name(buff);
			}
		}

		if (is.good()) {
			cout << "Price: ";
			is >> dbuff;
			if (is.fail()) {
				error("Invalid Price Entry");
			}
			else if (is.good()) {
				price(dbuff);
			}
		}

		if (is.good()){
			cout << "Taxed: ";
			is >> c;
			if (is.fail()) {
				error("Invalid Taxed Entry, (y)es or (n)o");
			}
			else if (c != 'y' && c != 'Y' && c != 'n' && c != 'N') {
				is.setstate(is.failbit);
				error("Invalid Taxed Entry, (y)es or (n)o");
			}
			else if (is.good()) {	
				taxed((c == 'y' || c == 'Y') ? true : false);
			}

		}

		if (is.good()) {
			cout << "Quantity: ";
			is >> ibuff;
			if (is.fail()) {
				error("Invalid Quantity Entry");
			}
			else if (is.good()) {
				quantity(ibuff);
			}
		}

		return is;
	}

}
