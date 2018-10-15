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
//
void ShoppingCart::AddItem(ItemToPurchase _newItem)
{
	cartItems.push_back(_newItem);

}




///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//  unclearified how to remove?
void ShoppingCart::RemoveItem(string _Item)
{
	//vector <ItemToPurchase> target;
	//vector <ItemToPurchase>::iterator i;

	string temp;
	uint flag = 0;
	for (uint i = 0; i < cartItems.size(); ++i)
	{
		//cout << cartItems[i].GetName() << endl;
		temp = cartItems[i].GetName();
		//cout << "The current item is: " << temp << "Item to rm: " << _Item << endl;
		if(/*temp.compare(_Item) == 1*/ temp == _Item)
		{
			this->__total -= cartItems[i].GetQuantity();
			//cout << "Inside if " << cartItems[i].GetName() << endl;


			cartItems[i].SetName("");

			cartItems[i].SetDescription("");
			cartItems[i].SetPrice(0);
			cartItems[i].SetQuantity(0);
			flag = 1;
		}


		}
		if (flag == 0) {
			cout << "Item not found in cart. Nothing removed." << endl;
	}

}
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////




//  unclearified what to modigy
void ShoppingCart::ModifyItem(ItemToPurchase _Item)
{
	string temp;
	string temp2;
	uint flag = 0;
	for (uint i = 0; i < cartItems.size(); ++i)
	{
		temp = cartItems[i].GetName();
		temp2 = _Item.GetName();
		//cout << cartItems[i].GetName() << " " << _Item.GetName() << endl;
		if(/*temp.compare(_Item) == 1*/ temp == temp2)
		{
			this->__total -= cartItems[i].GetQuantity();
			//cout << "Total: " << __total<<" old " << cartItems[i].GetQuantity();
			cartItems[i].SetQuantity(_Item.GetQuantity());
			this->__total += cartItems[i].GetQuantity();
			//cout << "Total: " << __total<<" new " << cartItems[i].GetQuantity();

			flag = 1;
		}


		}
		if (flag == 0) {
			cout << "Item not found in cart. Nothing modified." << endl;
	}
}


uint ShoppingCart::GetNumItemsInCart()
{
	uint grandcount = 0;
	for (uint h = 0; h < cartItems.size(); ++h)
	{
		grandcount += cartItems[h].GetQuantity();
	}
	__total = grandcount;
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
	cout << "Number of Items: " << __total/*ShoppingCart::GetNumItemsInCart()*/ << endl << endl;

	//if (cartItems.size() == 0) {
	if (cartItems.empty()) {
		cout << "SHOPPING CART IS EMPTY" << endl;
	}

	for (uint i = 0; i < cartItems.size(); ++i)
	{
		if (cartItems[i].GetQuantity() != 0) {
		cout << cartItems[i].GetName() << " " << cartItems[i].GetQuantity()
			<< " @ $" << cartItems[i].GetPrice() << " = $" << cartItems[i].CalcSubTotal() << endl;
		grandTotal += cartItems[i].CalcSubTotal();
	}
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
