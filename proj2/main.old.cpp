/* Blcok Comment test



*/
#include "ItemToPurchase.h"

#define COUNT_ITEM 2

int main(void)
{
	ItemToPurchase Cart[COUNT_ITEM];
	string temp;
	uint temp1;

	for (int i = 0; i < COUNT_ITEM; ++i)
	{
		cout << "Item "<< (i + 1) << endl;
		cout << "Enter the item name:" << endl;
		getline(cin, temp);
		Cart[i].SetName(temp);

		cout << "Enter the item price:" << endl;
		cin >> temp1;
		Cart[i].SetPrice(temp1);

		cout << "Enter the item quantity:" << endl;
		cin >> temp1;
		Cart[i].SetQuantity(temp1);

		cin.ignore();
		cout << endl;
	}

	// Adding the total cost
	cout << "TOTAL COST" << endl;
	cout << Cart[0].GetName() << " " << Cart[0].GetQuantity()
		<< " @ $" << Cart[0].GetPrice() << " = $" << (Cart[0].GetPrice())*
								(Cart[0].GetQuantity())
								<< endl;
	cout << Cart[1].GetName() << " " << Cart[1].GetQuantity()
		<< " @ $" << Cart[1].GetPrice() << " = $" << (Cart[1].GetPrice())*
								(Cart[1].GetQuantity())
								<< endl;
	cout << endl;
	cout << "Total: $" << ((Cart[0].GetPrice())*(Cart[0].GetQuantity())) +
												((Cart[1].GetPrice())*(Cart[1].GetQuantity())) << endl;

	return 0;
}
