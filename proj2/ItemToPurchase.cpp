#include <iostream>
#include <vector>
#include <iterator>
#include <string>

#include "ItemToPurchase.h"

using namespace std;

// A default constructor with no parameters
ItemToPurchase::ItemToPurchase()
{
	// Initialize everything in private to defualt
	itemName = "none";
	itemDescription = "none";
	itemPrice = 0;
	itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string name, string detail, uint price, uint count)
{
	itemName = name;
	itemDescription = detail;
	itemPrice = price;
	itemQuantity = count;
}

/*
void ItemToPurchase::PrintItemCost()
{
	cout << GetName() << " " << GetQuantity() <<
		" @ $" << GetPrice << " = $" << CalcSubTotal() << endl;
}
*/

/*
void ItemToPurchase::PrintItemDescription()
{
	cout << GetName() << ": " << GetDescription() << endl;
}
*/
