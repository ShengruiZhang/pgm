#include <iostream>
#include <sstream>
#include <string>

typedef unsigned int uint;

using namespace std;

class Card {
	public:
		Card();
		Card(uint value, uint suit);
		Card(std::string cardString);
	private:
		uint _value;
		uint _suit;
};

//Constructor can be used to initinalize members in classes. multiple constructors can be defined for initinalizing differnt
//	members.
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

int card_test()
{
	// Members of the object can be initinalized upon defining, by putting the corresponding parameters within the ().
	Card card_1("ks");
}

int main(void) {

	return 0;
}
