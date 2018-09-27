#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sporkprofile.h"

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

/* This function has been finished */
int ReadSporkDataFromFile
(SporkProfile _data[], int maxProfiles,
char *fileName)
{
	//printf("%s", fileName);
	unsigned int i = 0;
	unsigned int counter = 0;
	
	FILE *source = fopen(fileName, "r");
	
	//printf("%d", source);
	
	//perror("Error");
	
	char temp[100];
	char bim[100];

	while (!feof(source)) {
	
		fgets(temp, 100, source);

		int count =0;
		count = sscanf(temp, "%s %lf %lf %lf %d %s", 
			_data[i].businessName, 
			&_data[i].locX, 
			&_data[i].locY,
			&_data[i].avgRating, 
			&_data[i].adLevel,
			bim);

		_data[i].isNearby = 0;
		_data[i].isGood = 0;
		_data[i].distMiles = 0;
		if ((count != 5) | ((_data[i].adLevel != 0) & (_data[i].adLevel != 1) & (_data[i].adLevel != 2))) {
				counter = i;
				printf("Not-formatted line: %d", counter);
		} else {
		++i;
		}
		if (i == MAX_SPORK_PROFILES) {
			break;
		}
	}
	
	fclose(source);
	return i;
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
/* This funciton has been completed */
void FindNearbyBusinesses
(SporkProfile src[],
int numProfiles,
double userLocX, 
double userLocY, 
double maxDist)
{
	unsigned int i = 0;
	while(i < numProfiles)
	{
		//printf("userLocX: %lf, userLocY: %lf, BusX: %lf, BusY: %lf", userLocX, userLocY, src[i].locX, src[i].locY);
		src[i].distMiles = sqrt((pow((userLocX - src[i].locX), 2) + pow((userLocY - src[i].locY), 2)));
		if(src[i].distMiles <= maxDist) src[i].isNearby = 1;
			else src[i].isNearby = 0;
		++i;

		/// Testing
		printf("Miles: %f, nearby: %d\n", src[i].distMiles, src[i].isNearby);
	}
	
}


/**************************************************************************************************/

/*
 * Determines if each business is good based on the user's minimum required average rating.
 * Sets the Spork profile's isGood flag to true if the business' avgRating is greater than or
 * equal to minRating, and false otherwise.
 *
 */
/* This function has been completed */
void FindGoodBusinesses
(SporkProfile src[], int numProfiles,
                        double minRating) {
	unsigned int i = 0;
	for (i = 0; i < numProfiles; ++i)
	{
		if (src[i].avgRating >= minRating) src[i].isGood = 1;
			else src[i].isGood = 0;
	}
}

/**************************************************************************************************/

/*
 * Returns the index of the Spork profile that is neary, good, and has the highest adLevel. If
 * there is a tie, the index of the first entry found with the highest ad level should be returned.
 * If no businesses are nearby and good, the function will return -1.
 *
 */

int GetIndexMaxSponsor
(SporkProfile src[], int numProfiles) {
	unsigned int max = 0;
	unsigned int i = 0;
	unsigned int index = 0;

	for (i = 0; i < numProfiles; ++i)
	{
		//printf("ad: %d\n", src[i].adLevel);
		if ((src[i].adLevel > max) & (src[i].isNearby == 1) & (src[i].isGood == 1)) {
			max = src[i].adLevel;
			index = i;
		}
	}
	
   return index;
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
(SporkProfile source[], int numProfiles, int maxSponsorIndex, char *fileName) {
	unsigned int i;
	FILE *_out = fopen(fileName, "w+");
	if (_out == NULL) return -1;

	i = maxSponsorIndex;
	//fprintf(_out, "maxindex:\n");
	if ((source[i].isNearby == 1) & (source[i].isGood == 1))
	{
	fprintf(_out, "%s\t%.2f\t%.2f\n",
					source[i].businessName,
					source[i].avgRating,
					source[i].distMiles);
	}

	//fprintf(_out, "list:\n");
	for (i = 0; i<numProfiles; ++i)
	{
		if (i == maxSponsorIndex) ++i;
		if ((source[i].isNearby == 1) & (source[i].isGood == 1)){
			fprintf(_out, "%s\t%.2f\t%.2f\n",
					source[i].businessName,
					source[i].avgRating,
					source[i].distMiles);
		}
	}

   return 0;
}
