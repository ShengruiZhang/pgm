/* C libraries can be used in cpp */
#include <iostream>
#include <string>
#include <time.h>

#define MAX_ROLL 500

using namespace std;

namespace Dice
{
	int countDice = 0;
	void Display_dice(int dice[], int num);
}

void Dice::Display_dice(int dice[], int num)
{
	for (int i = 0; i < num; ++i)
}

int main(void)
{
	int numRoll = 0;

	Dice::countDice = 2;

	cout << "Number of dices: " << Dice::countDice << endl;
	cout << "Times to roll: ";
	cin >> numRoll;

	int diceRoll[MAX_ROLL];

	// Roll the dice
	
	for (int i = 0; i < numRoll; ++i)
	{
		diceRoll[i] = (rand() % 6 + 1) + (rand() % 6 + 1); 
	}

	return 0;
}
