/*----------------------------------------------------------------------*/
/* Author:         
// Net ID:         
// Date:           
//
//----------------------------------------------------------------------*/

#include "card.h"
#include <sstream>

Card::Card(std::string lineFromFile){
    std::istringstream lineStream(lineFromFile);
    lineStream >> _value >> _suit;
}

