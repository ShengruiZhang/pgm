#include <iostream>
#include <sstream>
#include <string>

typedef unsigned int uint;

using namespace std;

class PowerUnit {
	public:
		PowerUnit();
		uint UnitAllows();
		uint Components();
		uint numSupplier();
	private:
		char Supplier[4];
};

class Card {
	public:
		Card();
		Card(uint value, uint suit);
		Card(std::string cardString);
	private:
		uint _value;
		uint _suit;
};

Card::Card()
{
	_value = 0;
	_suit = 0;
};

Card::Card(uint value, uint suit)
{
	_value = value;
	_suit = suit;
};

Card::Card(std::string cardString)
{
	if(cardString[0] == 'k') {
		_value = 12;
	} else 
	if(cardString[0] - '0' < 10) {
		_value = cardString[0] - '0';
	}
};

int main(void) {
	return 0;
}
