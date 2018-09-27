//----------------------------------------------------------------------//
// Author:         
// Net ID:         
// Date:           
//
//----------------------------------------------------------------------//

#include "deck.h"
#include "card.h"
#include <fstream>
#include <iostream>

using namespace std;

void Deck::ReadCardsFromFile(std::string fileName){
    std::ifstream inputFileStream;
    std::string lineString;
    inputFileStream.open(fileName);
    
    if(!inputFileStream.is_open()){
        cout << "Could not open input file: " << fileName << endl;
        return;
    }
    
    inputFileStream.close();
}


void Deck::discard(){
    if(_num_cards == 0) return;
    
    Card newCard;  // this calls the constructor
    _cards[_num_cards - 1] = newCard;
    _num_cards--;
}
