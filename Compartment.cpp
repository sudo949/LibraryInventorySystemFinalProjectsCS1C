#include "Compartment.h"
using namespace std;

Compartment::Compartment() : item(nullptr), checkedOut(false), checkedOutBy(""), dueDate("") {}

bool Compartment::isEmpty() const
{
	return item == nullptr;
}

Item* Compartment::getItem()const
{
	return item;
}
void Compartment::setItem(Item* newItem)
{
	item = newItem;
	checkedOut = false;
	checkedOutBy = "";
	dueDate = "";
}
void Compartment::clearItem()
{
	item = nullptr;
	checkedOut = false;
	checkedOutBy = "";
	dueDate = "";
}

void Compartment::checkoutItem(const string& personName, const string& dueDate)
{
	if (!isEmpty())
	{
		checkedOut = true;
		checkedOutBy = personName;
		this->dueDate = dueDate;
	}
}

void Compartment::checkinItem()
{
	checkedOut = false;
	checkedOutBy = "";
	dueDate = "";
}

bool Compartment::isCheckedOut() const
{
	return checkedOut;
}

string Compartment::getCheckedOutBy() const
{
	return checkedOutBy;
}
string Compartment::getDueDate() const
{
	return dueDate;
}