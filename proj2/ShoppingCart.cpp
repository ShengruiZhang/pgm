#include <iostream>
#include <vector>
#include <iterator>

#include "ShoppingCart.h"

using namespace std;

// Constructor definition
ShoppingCart::ShoppingCart()
{
	customerName = "none";
	currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string _name, string _date)
{
	customerName = _name;
	currentDate = _date;
}

////////////////////////////////////////////////////////
// TODO
void ShoppingCart::AddItem(ItemToPurchase _newItem)
{
	cartItems.push_back(_newItem);
}




///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
// TODO unclearified how to remove?
void ShoppingCart::RemoveItem(string _Item)
{
	//vector <ItemToPurchase> target;
	//vector <ItemToPurchase>::iterator i;
	/*
	for (i; i < cartItems.size(); ++i)
	{
		if(  (  cartItems[i].GetName() )  .compare(_Item) == 0         )
		{
			cout << "Found it." << endl;
			cartItems.erase(i);
		}
		else {
			cout << "Not Found." << endl;
		}
	}
	*/
}
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////




// TODO unclearified what to modigy
void ShoppingCart::ModifyItem(ItemToPurchase _Item)
{
}


uint ShoppingCart::GetNumItemsInCart()
{
	uint grandcount = 0;
	for (uint h = 0; h < cartItems.size(); ++h)
	{
		grandcount += cartItems[h].GetQuantity();
	}
	return grandcount;
}
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
uint ShoppingCart::GetCostOfCart()
{
	uint cost = 0;

	for (uint h = 0; h < cartItems.size(); ++h)
	{
		cost += cartItems[h].CalcSubTotal();
	}

	return cost;
}
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////




void ShoppingCart::PrintTotal()
{
	uint grandTotal = 0;

	cout << this->customerName << "'s Shopping Cart - " << this->currentDate << endl;
	//cout << "Number of Items: " << GetNumItemsInCart() << endl;
	cout << "Number of Items: " << ShoppingCart::GetNumItemsInCart() << endl << endl;

	//if (cartItems.size() == 0) {
	if (cartItems.empty()) {
		cout << "SHOPPING CART IS EMPTY" << endl;
	}

	for (uint i = 0; i < cartItems.size(); ++i)
	{
		cout << cartItems[i].GetName() << " " << cartItems[i].GetQuantity()
			<< " @ $" << cartItems[i].GetPrice() << " = $" << cartItems[i].CalcSubTotal() << endl;
		grandTotal += cartItems[i].CalcSubTotal();
	}

	cout << endl << "Total: $" << grandTotal << endl << endl;
}


void ShoppingCart::PrintDescriptions()
{
	//vector <int> :: iterator count;

	cout << this->customerName << "'s Shopping Cart - " << this->currentDate
		<< endl << endl;
	cout << "Item Descriptions" << endl;

/*
	for (count = cartItems.begin(); count < cartItems.end(); ++count)
	{
		cout << *count->itemName << ": " << *count->itemDescription << endl;
	}
*/

	string _name, _detail;

	for (uint i = 0; i < cartItems.size(); ++i)
	{
		_name = cartItems[i].GetName();
		_detail = cartItems[i].GetDescription();
		cout << _name << ": "<< _detail << endl;
	}
}
