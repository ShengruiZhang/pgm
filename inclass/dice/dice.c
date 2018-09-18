#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//------------------------------------------------------------------------------------------------

void CalculateDiceRollCounts(int diceRolls[], int numRolls, int diceRollCounts[]) {
   int i = 0;
   
   for(i = 0; i <= 12; ++i) {
      diceRollCounts[i] = 0;
   }
   
   for(i = 0; i < numRolls; ++i) {
      diceRollCounts[diceRolls[i]]++;
   }
}

//------------------------------------------------------------------------------------------------

void PrintHistogram(int histData[]) {
   int i = 0;
   int j = 0;
   
   for(i = 2; i <= 12; ++i) {
      for(j = 0; j < histData[i]; ++j) {
         printf("*");
      }
      printf("\n");
   }
}

//------------------------------------------------------------------------------------------------

int main() {
   const int MAX_ROLLS = 500;
   int diceRolls[MAX_ROLLS];
   int diceRollCounts[13];
   int numRolls = 0;
   int i = 0;
   int roll1 = 0;
   int roll2 = 0;
   
   // Seed random number generator
   srand((int)time(0));
   
   // Ask user for number of times to roll two dice
   printf("How many times do you want to roll the dice: ");
   scanf("%d", &numRolls);
   
   if( numRolls > MAX_ROLLS ) {
      numRolls = MAX_ROLLS;
   }
   
   // Roll two dice numRolls times and add the total into
   // the diceRolls array
   for(i = 0; i < numRolls; ++i) {
      roll1 = rand() % 6 + 1;      // Note: This is not exactly uniform
      roll2 = rand() % 6 + 1;      // Note: This is not exactly uniform
      diceRolls[i] = roll1 + roll2;
   }
   
   CalculateDiceRollCounts(diceRolls, numRolls, diceRollCounts);
   PrintHistogram(diceRollCounts);
   
   return 0;
}

//------------------------------------------------------------------------------------------------

