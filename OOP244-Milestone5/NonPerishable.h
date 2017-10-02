#ifndef ICT_NONPERISHABLE_H__
#define ICT_NONPERISHABLE_H__
#include "Item.h"
#include "Error.h"

namespace ict {
	class NonPerishable : public Item {
		Error m_error;

	protected:
		bool ok() const;
		void error(const char*);
		virtual char signature() const;

	public:
		virtual std::fstream& save(std::fstream&) const;
		virtual std::fstream& load(std::fstream& file);
		virtual std::ostream& write(std::ostream& os, bool linear)const;
		virtual std::istream& read(std::istream& is);		
	};


	std::fstream& operator<<(std::fstream&, const NonPerishable&);
	std::fstream& operator>>(std::fstream&, NonPerishable&);

}

#endif