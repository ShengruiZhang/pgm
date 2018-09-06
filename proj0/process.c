//----------------------------------------------------------------------//
// Author:         Roman Lysecky, Ming Li
//                 (adpated from code by Jonathan Sprinkle)
// Net ID:         rlysecky
// Date:           06 January 2016
// Project Number: 0
// Project Name:   echoer
//
// Contains the implementation for the principal logic of the
// program, which is the processWord function.
//----------------------------------------------------------------------//

#include "process.h" // get the function signature for what we implement

//----------------------------------------------------------------------//
//
// processWord
//
// This function performs the principal logic of the program, by
// echoing differently, depending on whether the word matches "Ping"
//
// If the word matches "Ping" then the echoed line will be
//
//   Give me a Ping. One Ping only, please.
//
// Otherwise, the echoed line should just be the passed in word
// with no quotes.
//
//----------------------------------------------------------------------//

void processWord(char *inputWord[], int count) {
   char pingStr[] = "Ping";  // word we want to match
   
   // if we are passed a NULL pointer, then bad things will happen.
   if (inputWord == NULL) {
      printf("Error! Received a NULL pointer.\n");
      return;
   }
   
   if (count > 1)
   {
	   printf("Usage:echoer [word]\n");
  
   return;
   }

   // match for Ping
   if (strcmp(pingStr, inputWord[1]) == 0) {
      printf("Give me a Ping. One Ping only, please.\n");
   }
   else {
//	   for (int i = 1; i < count + 1; ++i)
//	   {
		   printf("%s", inputWord[1]);
//	   }
	   printf("\n");
   }
   
   return;
}
