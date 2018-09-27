//----------------------------------------------------------------------//
// Author:         
// Net ID:         
// Date:           
//
//----------------------------------------------------------------------//

#include "testCard.h"
#include "card.h"
#include <iostream>

using namespace std;

bool CardTester::testCardAceOfSpades(){
    // create our inputs
    Card testCard("AS");
    
    if(testCard.GetSuit().compare("S") == 0 &&
       testCard.GetValue() == 13)
    {
        cout << "testCardAceOfSpades passed.\n";
        return true;
    }
    
    cout << "testCardAceOfSpades failed.\n";
    return false;
}

bool CardTester::testCardTwoOfHearts(){
    // create our inputs
    Card testCard("2H");
    
    if(testCard.GetSuit().compare("H") == 0 &&
       testCard.GetValue() == 2)
    {
        cout << "testCardTwoOfHearts passed.\n";
        return true;
    }
    
    cout << "testCardTwoOfHearts failed.\n";
    return false;
}
