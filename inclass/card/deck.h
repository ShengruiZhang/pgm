//----------------------------------------------------------------------//
// Author:         
// Net ID:         
// Date:           
//
//----------------------------------------------------------------------//

#ifndef DECK_H
#define DECK_H

#include "card.h"

class Deck{
private:
    unsigned int _num_cards;
    Card _cards[52];
public:
    void ReadCardsFromFile(std::string fileName);

	unsigned int GetNumCards() { return _num_cards; };
	void SetNumCards(unsigned int num_cards) { _num_cards = num_cards; };
    void discard();
};
#endif

