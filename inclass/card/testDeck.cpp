//----------------------------------------------------------------------//
// Author:         
// Net ID:         
// Date:           
//
//----------------------------------------------------------------------//

#include "testDeck.h"
#include "deck.h"

bool DeckTester::testDiscardEmptyDeck() {
	// create inputs
	Deck testDeck;

	testDeck.discard();

	if (testDeck.GetNumCards() == 0) {
		return true;
	}

	return false;
}

bool DeckTester::testDiscardTwoCards() {
	// create inputs
	Deck testDeck;
	testDeck.SetNumCards(2);

	testDeck.discard();

	if (testDeck.GetNumCards() == 1) {
		return true;
	}

	return false;
}
