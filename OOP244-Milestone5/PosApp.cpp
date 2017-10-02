#define _CRT_SECURE_NO_WARNINGS
#include "PosApp.h"
#include "NonPerishable.h"
#include "Perishable.h"
#include "Date.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;
namespace ict {

	PosApp::PosApp(const char* filename, const char* billfname) {
		//Robust string copy
		int l = (strlen(filename) < sizeof(m_filename)) ? strlen(filename) : sizeof(m_filename);
		strncpy(m_filename, filename, l);
		m_filename[l] = 0;
		l = (strlen(billfname) < sizeof(m_billfname)) ? strlen(billfname) : sizeof(m_billfname);
		strncpy(m_billfname, billfname, l);
		m_billfname[l] = 0;
		m_noOfItems = 0;
		loadRecs();
	}

	int PosApp::menu() {
		int m = 0;

		cout << "The Sene-Store " << endl;
		cout << "1 - List items" << endl;
		cout << "2 - Add Perishable item" << endl;
		cout << "3 - Add Non - Perishable item" << endl;
		cout << "4 - Update item quantity" << endl;
		cout << "5 - Show Item" << endl;
		cout << "6 - POS" << endl;
		cout << "0 - exit program" << endl;
		cout << "> ";
		cin >> m;
			
		if (cin.fail() || cin.bad() || m < 0 || m > 6 ) {
			cin.clear();
			m = -1;		
		}
		cin.ignore(1000,'\n');
		return m;
	}

	void PosApp::deallocateItems() {
		for (int i = 0; i < m_noOfItems; i++) {
			delete m_items[i];
		}
		m_noOfItems = 0;
	}

	void PosApp::loadRecs() {
		fstream f;
		char N_NP = 0;

		if (m_noOfItems > 0) {
			deallocateItems();
		}


		f.open(m_filename, f.in);
		if (!f) {
			f.clear();
			f.close();
			f.open(m_filename, f.out);
			f.close();
		}
		else {
			while (!f.eof()) {
				f.get(N_NP);
				if (f.good()) {
					if (N_NP == 'N' || N_NP == 'P') {
						f.ignore(1, ',');
						switch (N_NP) {

						case 'N':
							m_items[m_noOfItems] = new NonPerishable;
							break;

						case 'P':
							m_items[m_noOfItems] = new Perishable;
							break;
						}
						m_items[m_noOfItems]->load(f);
						m_noOfItems += 1;
					}
				}
			}
			
		}
		f.close();
	}

	void PosApp::saveRecs() {
		fstream f;
		f.open(m_filename, f.out);
		if (f) {
			for (int i = 0; i < m_noOfItems; i++) {
				if (m_items[i]->quantity() > 0) {
					m_items[i]->save(f);
				}
			}
		}
		else if (!f) {
			f.clear();
			f.close();
			f.open(m_filename, f.out);
			f.close();
		}

		f.close();
		loadRecs();	
	}

	int PosApp::searchItems(const char* sku) const {
		
		for (int i = 0; i < m_noOfItems; i++) {
			if (*m_items[i] == sku) {
				return i;
			}
		}
		return -1;
	}

	void PosApp::updateQty() {

		char tempSKU[MAX_SKU_LEN+1];
		*tempSKU = 0;

		cout << "Please enter the SKU: ";
		cin.getline(tempSKU, MAX_SKU_LEN + 1, '\n');
		int item = searchItems(tempSKU);
		if (item == -1) {
			cout << "Not found!" << endl;
		}
		else {
			m_items[item]->write(cout, false); 
			cout << endl;
			cout << "Please enter the number of purchased items: ";
			int q = 0;
			cin >> q;
			if (cin.good() && q > 0) {
				*m_items[item] += q;
				saveRecs();
				cout << "Updated!" << endl;
			}
			else {
				cout << "Invalid quantity" << endl;
			}

		}
	}

	void PosApp::addItem(bool isPerishable) {
		Item* i = nullptr;
		if (isPerishable) {
			i = new Perishable;
		}
		else {
			i = new NonPerishable;
		}
		cin >> *i;
		if (cin.good()) {
			m_items[m_noOfItems++] = i;
			saveRecs();
			cout << "Item added" << endl;
		}
		else if (cin.fail() || cin.bad()) {
			cout << *i << endl << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			delete i;
		}
	}

	void PosApp::listItems() const {
		
		double totalAssets = 0.0;
		cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total |" << endl;
		cout << "-----|--------|--------------------|-------|---|----|---------|" << endl;
		for (int i = 0; i < m_noOfItems; i++) {
			cout << setw(4) << right << i + 1 << " | " << *m_items[i] << endl;
			totalAssets += (m_items[i]->cost() * m_items[i]->quantity());
		}
		cout << "-----^--------^--------------------^-------^---^----^---------^" << endl;
		cout << "                               Total Asset: $  |" << setw(14) << right <<  totalAssets << "|" << endl;
		cout << "-----------------------------------------------^--------------^" << endl;

	}

	void PosApp::truncateBillFile() {
		fstream bill;
		bill.open(m_billfname, bill.out | bill.trunc);
		bill.close();
	}

	void PosApp::showBill() {
		Item *i = nullptr;
		fstream bill;
		Date d;
		double total = 0.0;
		d.dateOnly(false);
		char N_NP = 0;

		bill.open(m_billfname, bill.in);
		if (bill){

			cout << "v--------------------------------------------------------v" << endl;
			cout << "| " << d << "                                      |" << endl;
			cout << "| SKU    | Item Name          | Price |TX |Qty |   Total |" << endl;
			cout << "|--------|--------------------|-------|---|----|---------|" << endl;
			while (!bill.eof())
			{
				bill.get(N_NP);

				if (N_NP == 'N' || N_NP == 'P') {
					bill.ignore(1, ',');
					switch (N_NP) {

					case 'N':
						i = new NonPerishable;
						break;

					case 'P':
						i = new Perishable;
						break;
					}
					i->load(bill);
					total += i->cost();
					cout << "| " << *i << endl;
					delete i;
				}
			}
			cout << "^--------^--------------------^-------^---^----^---------^" << endl;
			cout << "|                               Total: $  |         " << total << "|" << endl;
			cout << "^-----------------------------------------^--------------^" << endl;
		}
		else if (!bill) {
			bill.clear();
			bill.close();
			bill.open(m_billfname, bill.out);
			bill.close();
		}

		bill.close();
		truncateBillFile();
	}

	void PosApp::addToBill(Item& I) {
		fstream bill;
		int q = I.quantity();
		I.quantity(1);
		bill.open(m_billfname, bill.out | bill.app);
		if (bill) {
			I.save(bill);
			I.quantity(q);
			I -= 1;
			saveRecs();
		}
		else if (!bill) {
			bill.clear();
			bill.close();
			bill.open(m_billfname, bill.out);
			bill.close();
		}
		bill.close();
	}


	void PosApp::POS() {
		bool exit = false;
		char sku[MAX_SKU_LEN + 1];
		*sku = 0;
		int search = 0;

		while (!exit) {
			cout << "Sku: ";
			cin.getline(sku, MAX_SKU_LEN + 1, '\n');
			if (cin.fail()) {
				cin.ignore(1000, '\n');
				cin.clear();
			}
			else if (cin.good()) {				
				if (strcmp(sku,"") == 0) {				
					showBill();
					exit = true;
				}
				else {
					search = searchItems(sku);
					switch (search) {

					case -1:
						cout << "Not found!" << endl;
						break;

					default:
						cout << "v------------------->" << endl;
						cout << "| " << m_items[search]->name() << endl;
						cout << "^------------------->" << endl;
						addToBill(*m_items[search]);
						break;
					}
					search = 0;
				}
			}
		}
	}

	void PosApp::run() {
		int q = -1;
		int search = -1;
		char sku[MAX_SKU_LEN + 1];
		*sku = 0;
		

		while (q != 0) {
			q = menu();
			cout << endl;
			switch (q) {
			case 0:
				cout << "Goodbye!" << endl;
				break;
			case 1:
				listItems();
				break;
			case 2: 
				addItem(true);
				break;
			case 3:
				addItem(false);
				break;
			case 4:
				updateQty();
				break;
			case 5:
				cout << "Please enter the SKU : " << endl;
				cin.getline(sku, MAX_SKU_LEN + 1, '\n');
				search = searchItems(sku);
				if (search == -1) {
					cout << "Not Found!" << endl << endl;
				}
				else {
					cout << "v-----------------------------------v" << endl;
					m_items[search]->write(cout, false);
					cout << "^-----------------------------------^" << endl << endl;
				}
				search = -1; //Reset
				break;
			case 6:
				POS();
				break;
			case -1:
				cout << "=== Invalid Selection, try again===" << endl;
				break;
			}
			cout << endl;
		}
	}
}


/*
ouputs:
-------------------------------------
update:
Please enter the SKU: 1313
Name:
Paper Tissue
Sku: 1313
Price: 1.22
Price after tax: 1.38
Quantity: 194
Total Cost: 267.45

Please enter the number of purchased items: 12
Updated!

------------------------------
Please enter the SKU: 3434
Not found!

-------------------------------------
add item:
Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 1200/10/12
Invalid Year in Date Entry

Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 2017/5/15
Item added.

--------------------------------------------
list item:
 Row | SKU    | Item Name          | Price |TX |Qty |   Total |
-----|--------|--------------------|-------|---|----|---------|
   1 | 1234   |Milk                |   3.99|  P|   2|     7.98|
   2 | 3456   |Paper Cups          |   5.99| TN|  38|   257.21|
   3 | 4567   |Butter              |   4.56| TP|   9|    46.38|
   4 | 1212   |Salted Butter       |   5.99|  P| 111|   664.89|
   5 | 1313   |Paper Tissue        |   1.22| TN| 206|   283.99|
   6 | 5656   |Honey               |  12.99| TP|  12|   176.14|
-----^--------^--------------------^-------^---^----^---------^
                               Total Asset: $  |       1436.59|
-----------------------------------------------^--------------^


--------------------------------------
printbill:
v--------------------------------------------------------v
| 2017/04/02, 12:42                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         22.05|
^-----------------------------------------^--------------^

-------------------------------------------------------
POS:
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1313
v------------------->
| Paper Tissue
^------------------->
Sku: 1234
v------------------->
| Milk
^------------------->
Sku: 7654
Not found!
Sku: 5656
v------------------->
| Honey
^------------------->
Sku:
v--------------------------------------------------------v
| 2017/04/02, 12:58                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 1234   |Milk                |   3.99|  P|   1|     3.99|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         32.03|
^-----------------------------------------^--------------^

------------------------------------------------------
run:
The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 5656
v-----------------------------------v
Name:
Honey
Sku: 5656
Price: 12.99
Price after tax: 14.68
Quantity: 10
Total Cost: 146.79
Expiry date: 2017/05/15
^-----------------------------------^

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 12345
Not found!

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> five

===Invalid Selection, try again===

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 0

Goodbye!

*/