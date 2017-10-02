#ifndef ICT_PERISHABLE_H__
#define ICT_PERISHABLE_H__
#include "NonPerishable.h"
#include "Date.h"

namespace ict{
	class Perishable : public NonPerishable {
		Date m_expiry;
	
	protected:
		virtual char signature() const;
	public:

		Perishable(); //Set to Date only
		virtual std::fstream& save(std::fstream&) const;
		virtual std::fstream& load(std::fstream&);
		virtual std::ostream& write(std::ostream&, bool) const;
		virtual std::istream& read(std::istream&);
	};
}






#endif
