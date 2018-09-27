#include <stdio.h>
#include <stdlib.h>
#include "sporkprofile.h"

/**********************************************************************************************/
#define MAX_SPORK_PROFILES 500
/**********************************************************************************************/

int main(int argc, char *argv[]) {

   SporkProfile sporkProfiles[MAX_SPORK_PROFILES];

   int numProfiles = 0;
   int maxSponsorIndex = -1;

   double userLocX = 0.0;
   double userLocY = 0.0;
   double maxDistMiles = 0.0;
   double minAvgRating = 0.0;
   
   //printf("%s, %s\n", argv[0], argv[1]);
   //
   /*
    * Check for the correct number of command line arguments. If incorrect
    * provide a usage message to the assist the user.
    *
    */

   /* FOR TEST PURPOSE*/
   /*
   if( argc != 7 ) {
      printf("Usage: FIXME\n");
      return EXIT_FAILURE;
   }
   */
   
   // Read Spork profiles from input file and store the number of profiles read.
   numProfiles  = ReadSporkDataFromFile(sporkProfiles, MAX_SPORK_PROFILES, argv[1]);
                                        /*Array passed as pointer*/
   if( numProfiles == -1 ) {
      printf("Could not read input file %s\n", argv[1]);
      return EXIT_FAILURE;
   }
	 
   // FIXME: Convert command line arguments for user's x and y location, maximum distance, and
   // minimum rating to variables userLocX, userLocY, maxDist, and minRating.
   printf("Converting arguments\n");
   sscanf(argv[4], "%lf", &userLocX);
   sscanf(argv[5], "%lf", &userLocY);
   sscanf(argv[6], "%lf", &maxDistMiles);
   sscanf(argv[7], "%lf", &minAvgRating);
   
   FindNearbyBusinesses(sporkProfiles, numProfiles, userLocX, userLocY, maxDistMiles);
   FindGoodBusinesses(sporkProfiles, numProfiles, minAvgRating);
   maxSponsorIndex = GetIndexMaxSponsor(sporkProfiles, numProfiles);
  
   // Write nearby and good Spork profiles to the output file.
   if( WriteSporkResultsToFile(sporkProfiles, numProfiles, maxSponsorIndex, argv[2]) == -1 ) {
      printf("Could not write output file %s\n", argv[2]);
      return EXIT_FAILURE;
   }

	/* TESTING PURPOSE */
	
/* 	unsigned int i = 0;
	while (i<numProfiles) {
		printf("%d",i);

		printf("Name: %s, X:%.2f, Y:%.2f, Rate: %.2f, LV: %d\n",
	      sporkProfiles[i].businessName, 
	      sporkProfiles[i].locX,
	      sporkProfiles[i].locY,
		  sporkProfiles[i].avgRating,
	      sporkProfiles[i].adLevel);
	++i;
	} */

	
   return 0;
}

