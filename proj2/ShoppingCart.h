#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

//#include <iostream>
//#include <vector>

#include "ItemToPurchase.h"

typedef unsigned int uint;

class ShoppingCart{
	private:
		std::string customerName;
		std::string currentDate;
		std::vector <ItemToPurchase> cartItems;

	public:
		// Constructor
		ShoppingCart();
		ShoppingCart(std::string _name, std::string _date);

		std::string GetCustomerName() { return customerName; }
		std::string GetDate() { return currentDate; }

		void AddItem(ItemToPurchase _newItem);
		void RemoveItem(std::string _Item);
		void ModifyItem(ItemToPurchase _Item);

		uint GetNumItemsInCart();
		uint GetCostOfCart();
		void PrintTotal();

		void PrintDescriptions();

		uint __total = 0;
		/*
		{
			std::vector <int> :: iterator count;

			std::cout << this->customerName << "'s Shopping Cart - " << this->currentDate
				<< std::endl << std::endl;
			std::cout << "Item Descriptions" << std::endl;

			for (count = cartItems.begin(); count < cartItems.end(); ++count)
			{
				std::cout << *count->itemName << ": " << *count->itemDescription << std::endl;
			}
		}
		*/


};

/*
class FindItem
{
	std::string tar;
public:
	FindItem(const std::string& name) : tar(name)	{}

	bool operator() (const ItemToPurchase& attr)
		{return (attr.GetName() == tar);}
};
*/

#endif
