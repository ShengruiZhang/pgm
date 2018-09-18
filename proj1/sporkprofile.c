#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sporkprofile.h"

/**************************************************************************************************/

/* Reads up to maxProfiles Spork profiles from an input file specified by fileName. Functions reads
 * the input file line-by-line using the format:
 *
 *    BusinessName X.XX Y.YY R.RR A
 *
 * BusinessName is the name of the restauarant/business. The buseiness name will not include any
 * whitespace characters
 *
 * X.XX represents the X location in miles using a Cartesian coodinate system
 *
 * Y.YY represents the Y location in miles using a Cartesian coodinate system
 *
 * R.RR represents the average rating for the business
 *
 * A is the advertising level, which should 0, 1, or 2
 *
 * Alpha submission: ReadSporkDataFromFile() function should initialize isNearby and isGood
 *                   to true and initialize distMiles to 0.0 for all profile entries.
 *                   Note: This requirement is different for the final project submission.
 *
 * Project submission: ReadSporkDataFromFile() function should initialize isNearby and isGood
 *                     to false for all profile entries.
 *                     Note: This requirement is different for the alpha project submission.
 *
 * Returns: The number of Spork profiles read from the file. If the input file could not be opened,
 *          the function returns -1.
 *
 */

int ReadSporkDataFromFile
(SporkProfile sporkProfiles[], int maxProfiles,
                          char *fileName) {
   return -1;
}

/**************************************************************************************************/

/*
 * Determines if each business is nearby the user,  sets the Spork profile's isNearby flag to
 * true (is nearby) or false (not nearby), and stores the distance in miles in the Spork profile.
 *
 * userLocX, userLocY: Indicates the x and y coordiante of the user's location
 * maxDist: Indicates the maxmimum distance between the user and a nearby business
 *
 */
void FindNearbyBusinesses
(SporkProfile sporkProfiles[], int numProfiles,
                          double userLocX, double userLocY, double maxDist) {

}


/**************************************************************************************************/

/*
 * Determines if each business is good based on the user's minimum required average rating.
 * Sets the Spork profile's isGood flag to true if the business' avgRating is greater than or
 * equal to minRating, and false otherwise.
 *
 */
void FindGoodBusinesses
(SporkProfile sporkProfiles[], int numProfiles,
                        double minRating) {
   
}

/**************************************************************************************************/

/*
 * Returns the index of the Spork profile that is neary, good, and has the highest adLevel. If
 * there is a tie, the index of the first entry found with the highest ad level should be returned.
 * If no businesses are nearby and good, the function will return -1.
 *
 */

int GetIndexMaxSponsor
(SporkProfile sporkProfiles[], int numProfiles) {
   return -1;
}

/**************************************************************************************************/

/*
 * Writes all good and nearby business to an output file specified by fileName using the format:
 *
 *    BusinessName R.RR D.DD
 *
 * R.RR is the average rating with exactly two decimal digits of precision.
 * D.DD is the distance in miles with exactly two decimal digits of precision.
 *
 * If maxSponsorIndex is not -1, the cooresponding profile entry will be output first. All other
 * nearby and good profiles will be output in the order they are stored in the sporkProfiles array.
 *
 * Each entry should be separated by a single tab character (\t), and each line should end
 * with a single newline (\n).
 *
 * Returns: -1 if the output file could not be opened, and 0 otherwise.
 *
 */
int WriteSporkResultsToFile
(SporkProfile sporkProfiles[], int numProfiles,
                            int maxSponsorIndex, char *fileName) {
   return 0;
}
