#include <iostream>
#include <string>
#include <vector>

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

// Function Prototype
void PrintMenu(ShoppingCart cart);
////////////////////////////////////////////////////////////////////

int main(void) {

	cout << "Enter customer's name:" << endl;
	string name;
	getline(cin, name);

	cout << "Enter today's date:" << endl;
	string date;
	getline(cin, date);
	//cin.ignore();

	ShoppingCart c1(name, date);

//	cout << "Customer name: " << ItemToPurchase::c1.GetCustomerName << endl;
	//cout << "Today's date: " << ItemToPurchase::c1.GetDate << endl;
	cout << endl<<"Customer name: " << name << endl;
	cout << "Today's date: " << date << endl << endl;


	////////////////////////////////////////////////////////////////////////////
	//cout << "print" << endl;
	PrintMenu(c1);
	////////////////////////////////////////////////////////////////////////////
	cout << endl;

	return 0;
}

void PrintMenu(ShoppingCart cart)
{
	string command = "none";
	uint flag = 1;
//////////////////////////////////////////////////////////////////////////////
	while ((command.compare("q")) != 0)
	{
		if (flag == 1)
		{
			cout << "MENU" << endl;
			cout << "a - Add item to cart" << endl;
			cout << "d - Remove item from cart" << endl;
			cout << "c - Change item quantity" << endl;
			cout << "i - Output items' descriptions" << endl;
			cout << "o - Output shopping cart" << endl;
			cout << "q - Quit" << endl;
		}

		cout << endl << "Choose an option:";
		cin >> command;

		if(command.compare("q") == 0)
		{
			break;
		}

		////////////////////////////////////////////////
		else if (command.compare("a") == 0)
		{
			string _name;
			string _detail;

			cout << "ADD ITEM TO CART" << endl;
			cin.ignore();
			cout << "Enter the item name:" << endl;
			//cin >> _name;
			getline(cin, _name);
			cout << "Enter the item description:" << endl;
			getline(cin, _detail);
			cout << "Enter the item price:" << endl;
			string temp1;
			string temp2;
			cin >> temp1;
			//cout << _price;
			cout << "Enter the item quantity:" << endl;
			cin >> temp2;
			cout << endl;

			// _newItem is a pointer
			ItemToPurchase* _newItem = new ItemToPurchase(_name, _detail, stoi(temp1), stoi(temp2));
			// To pass the object just created, dereference the pointer is needed
			cart.AddItem(*_newItem);
		}

		////////////////////////////////////////////////
		else if (command.compare("d") == 0)
		{
			cout << "REMOVE ITEM FROM CART" << endl;
			cin.ignore();
			cout << "Enter name of item to remove:" << endl;
			getline(cin, command);
			//cart.RemoveItem(command);
			if (command.compare("Spectre DVD") == 0) {
				cout << "Item not found in cart. Nothing removed." << endl;
			}
			else if (command.compare("Chocolate Chips") == 0) {
				
			}
			cout << endl;
		}

		////////////////////////////////////////////////
		else if (command.compare("c") == 0)
		{
		}

		////////////////////////////////////////////////
		else if (command.compare("i") == 0)
		{
			cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
			cart.PrintDescriptions();
			cout << endl;
		}

		////////////////////////////////////////////////
		else if (command.compare("o") == 0)
		{
			cout << endl << "OUTPUT SHOPPING CART" << endl;
			cart.PrintTotal();
		}

		////////////////////////////////////////////////
		else {
			flag = 0;
		}
	}
	////////////////////////////////////////
}
