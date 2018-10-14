#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

typedef unsigned int uint;

class ItemToPurchase {
	private:
		std::string itemName;
		std::string itemDescription;
		uint itemPrice;
		uint itemQuantity;

	public:
		// Constructors
		ItemToPurchase();
		ItemToPurchase(std::string name, std::string detail, uint price, uint count);

		void SetName(std::string name) {itemName = name;}
		std::string GetName() { return itemName; }

		void SetDescription(std::string detail) {itemDescription = detail;}
		std::string GetDescription() { return itemDescription; }

		void SetPrice(uint price) {itemPrice = price;}
		uint GetPrice() { return itemPrice; }

		void SetQuantity(uint count) {itemQuantity = count;}
		uint GetQuantity() { return itemQuantity; }

		uint CalcSubTotal() { return (itemPrice * itemQuantity); }

		void PrintItemCost()
		{
			std::cout << itemName << " " << itemQuantity <<
				" @ $" << itemPrice << " = $" << (itemPrice * itemQuantity) << std::endl;
		}

		void PrintItemDescription()
		{
			std::cout << itemName << ": " << itemDescription << std::endl;
		}

	/*
		friend ostream& operator << (ostream& os, const ItemToPurchase& m) {
    	os << m.m_a <<" " << m.m_b << endl;
    	return os;
		}
	*/

};

#endif
