#ifndef H_POSSAPP_H
#define	H_POSSAPP_H
#include "Item.h"
#include <fstream>


namespace ict {
	class PosApp {
	private:
		//MEMBERS
		char m_filename[129];
		char m_billfname[129];
		Item* m_items[MAX_NO_ITEMS];
		int m_noOfItems; //Items - 1 for array indexing

	public:
		//CONSTRUCTORS
		PosApp(const char*, const char*);

		//DELETED
		PosApp(const PosApp&) = delete;
		PosApp& operator=(const PosApp&) = delete;

	private:
		//Data maagement member functions
		int menu();
		void deallocateItems();
		void loadRecs();
		void saveRecs();
		int searchItems(const char*) const;
		void updateQty();
		void addItem(bool);
		void listItems()const;

		//POS member functions
		void truncateBillFile();
		void showBill();
		void addToBill(Item&);
		void POS();

	public:
		void run();
	
	};


}
#endif // !1
