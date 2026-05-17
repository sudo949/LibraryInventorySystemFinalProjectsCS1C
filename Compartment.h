#ifndef COMPARTMENT_H
#define COMPARTMENT_H
#include "Item.h"
#include <string>
using namespace std;

class Compartment
{
public:
	Compartment();

	bool isEmpty() const;

	Item* getItem()const;
	void setItem(Item* newItem);
	void clearItem();

	void checkoutItem(const string& personName, const string& dueDate);
	void checkinItem();

	bool isCheckedOut() const;

	string getCheckedOutBy() const;
	string getDueDate() const;

private:
	Item* item;
	bool checkedOut;
	string checkedOutBy;
	string dueDate;
};

#endif

