#include <iostream>
#include <string>

typedef unsigned int uint;

using namespace std;

class ItemToPurchase {
	private:
		string itemName;
		uint itemPrice;
		uint itemQuantity;

	public:
		void SetName(string name) {itemName = name;};
		string GetName() { return itemName; };

		void SetPrice(uint price) {itemPrice = price;};
		uint GetPrice() { return itemPrice; };

		void SetQuantity(uint count) {itemQuantity = count;};
		uint GetQUantity() { return itemQuantity; };
};

int main(void)
{
	return 0;
}
