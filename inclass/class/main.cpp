#include <iostream>
typedef unsigned int uint;

using namespace std;

class Card {
	private:
		//something here
		uint value;
		uint suit;

	public:
		//something here

		Card(uint value, uint suit);

		int getValue();
		void setValue();
		int getSuit();
		void setSuit();
};

class Deck {
	private:
		uint num_cards;

	public:
		Card _card[100];
};

Card::Card(uint value, uint suit) {
	this->value = value;
	this->suit = suit;
}

int Card::getValue() {
	return value;
}

int Card::getSuit() {
	return suit;
}

int main(void) {
	Card _test;

	cout << "Inclass-Classes & Objects & Constructor" << endl;

	cout << _test.getValue() << " " << _test.getSuit() << endl;

	return 0;
}
