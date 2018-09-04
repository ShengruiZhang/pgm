//----------------------------------------------------------------------//
// Author:         Roman Lysecky, Ming Li
//                 (adpated from code by Jonathan Sprinkle)
// Net ID:         rlysecky
// Date:           06 January 2016
// Project Number: 0
// Project Name:   echoer
//
// Contains the main function.
//----------------------------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING 32  // Maximum string size

// Include the header for the function we want to call after we get
// the inputs from the user.

#include "process.h"

int main( void ) {
   
   char userWord[MAX_STRING+1]; // Read from user into this string
   int scanfResult = 0;	        // Used to store the result from scanf

   // Prompt the user.
	printf("Enter your word: ");

   // Scan the word from the user.
   //
   // Note the use of 32 to limit the amount of the string we capture,
   // in order to prevent a buffer overflow situation; your logic will
   // be different when processing the command line arguments.
	scanfResult = scanf("%32s", userWord);
	
   // Make sure that scanf returns a 1, since that will indicate
   // exactly 1 string was matched.
	if (scanfResult == 1) {
		processWord(userWord);
	}
   // Tell the user that something went wrong
	else {
		printf("Error! Did not match input format.\n");
      // since something prevented us from running the program
      // at all, we return that we failed.
		return EXIT_FAILURE;
	}
	
   // return success, if we got to this point.
	return EXIT_SUCCESS;
}
