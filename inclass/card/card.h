//----------------------------------------------------------------------//
// Author:         
// Net ID:         
// Date:           
//
//----------------------------------------------------------------------//

#ifndef CARD_H
#define CARD_H

#include <string>

class Card{
private:
    std::string _value;
    std::string _suit;
public:
//    Card();
//    Card(unsigned int value, unsigned int suit);
    Card(std::string lineFromFile);
    
	std::string GetValue() { return _value; };
    std::string GetSuit() { return _suit; };
    void SetValue(std::string value) { _value = value; };
    void SetSuit(std::string suit) { _suit = suit; };
};

#endif

