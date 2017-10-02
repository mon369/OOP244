#define _CRT_SECURE_NO_WARNINGS  
// Lib includes
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Item.h"
#include "POS.h"
#include "PosIO.h"

using namespace std;
namespace ict{
  // class Item implementaion

	//SET EMTPY STATE FUNCTION

	void Item::setEmptyState() {
		*m_sku = 0;
		m_name = nullptr;
		m_price = 0;
		m_taxed = false;
		m_quantity = 0;
	}

	Item::Item() {
		setEmptyState();
	}

	Item::Item(const char* p_sku, const char* p_name, double p_price, bool p_taxed) {
		bool valid = (p_sku != nullptr && p_name != nullptr && p_price > 0);
		if (valid) {
			sku(p_sku);
			name(p_name);
			price(p_price);
			taxed(p_taxed);
		}
		else {
			setEmptyState();
		}
	}

	Item::Item(const Item& item) {
		setEmptyState();
		*this = item;
	}


	Item& Item::operator=(const Item& item) {
		if (this != &item) {

			price(item.m_price);
			quantity(item.m_quantity);
			taxed(item.m_taxed);
			
			if (item.m_sku != nullptr) {
				sku(item.m_sku);
			}
			else {
				*m_name = 0;
			}
			if (item.m_name != nullptr) {
				name(item.m_name);
			}
			else {
				m_name = nullptr;
			}
		}
		return *this;
	}


	void Item::sku(const char* sku) {
		int l = ((signed int)strlen(sku) > MAX_SKU_LEN) ? MAX_SKU_LEN : strlen(sku);
		strncpy(m_sku, sku, l);
		m_sku[l] = 0;
	}

	void Item::price(const double price) {
		m_price = price;
	}

	void Item::name(const char* name) {
		delete[] m_name;
		m_name = new char[strlen(name) + 1];
		strncpy(m_name, name, strlen(name));
		m_name[strlen(name)] = 0;
	}

	void Item::taxed(const bool taxed) {
		m_taxed = taxed;
	}

	void Item::quantity(const int quantity) {
		m_quantity = quantity;
	}

	const char* Item::sku() const {
		return m_sku;
	}
	double Item::price() const {
		return m_price;
	}
	const char* Item::name() const {
		return m_name;
	}
	bool Item::taxed() const {
		return m_taxed;
	}
	int Item::quantity() const {
		return m_quantity;
	}
	double Item::cost() const {
		return (taxed() )? m_price + (m_price* TAX) : m_price;
	}
	bool Item::isEmpty() const {
		return (m_sku[0] == '\0' &&
		m_name == nullptr &&
		m_price == 0 &&
		m_quantity == 0) ? true : false;
	}

	bool Item::operator==(const char* sku) const {
		return (strcmp(m_sku, sku) == 0);
	}

	int Item::operator+=(const int n){
		m_quantity += n;
		return m_quantity;
	}

	int Item::operator-=(const int n) {
		m_quantity -= n;
		return m_quantity;
	}


	Item::~Item() {
		delete[] m_name;
	}


	//NON MEMBER OPERATOR OVERLOADS

	double operator+=(double& d, const Item& I) {	
		d += (I.cost() * I.quantity());
		return d;
	}

	ostream& operator<<(ostream& os, const Item& i) {
		i.write(os, true);
		return os;
	}
	istream& operator>>(istream& is, Item& i) {
		i.read(is);
		return is;
	}

}
