#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <iostream>

#include "Perishable.h"
using namespace std;


namespace ict {

	char Perishable::signature() const {
		return 'P';
	}

	Perishable::Perishable() {
		m_expiry.dateOnly(true);
	}

	fstream& Perishable::save(fstream& fs) const {
		NonPerishable::save(fs);
		fs << ",";
		fs << m_expiry;
		return fs;
	}

	fstream& Perishable::load(fstream& fs) {
		NonPerishable::load(fs);
		fs.ignore();
		fs >> m_expiry;
		return fs;
	}

	ostream& Perishable::write(ostream& os, bool linear) const {	
		NonPerishable::write(os,linear);
		if (ok() && !linear) {
			os << "Expiry date: " << m_expiry << endl;
		}
		return os;
	}

	istream& Perishable::read(istream& is) {
		cout << "Perishable "; 
		NonPerishable::read(is);
		if (is.good()) {
			cout << "Expiry date (YYYY/MM/DD):";
			m_expiry.read(is);
			if (m_expiry.bad()) {
				switch (m_expiry.errCode()) {

				case CIN_FAILED:
					error("Invalid Date Entry");
					break;

				case YEAR_ERROR:
					error("Invalid Year in Date Entry");
					break;

				case MON_ERROR:
					error("Invalid Month in Date Entry");
					break;

				case DAY_ERROR:
					error("Invalid Day in Date Entry");
					break;
				}
				is.setstate(is.failbit);
			}
		}
		return is;
	}
}
