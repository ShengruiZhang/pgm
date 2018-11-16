// Main funciton
#include "Graph.h"
#include "node.h"

#include <iostream>

#include <string>
#include <fstream>
#include <sstram>
#include <iomanip>

#include <vector>
#include <unordered_map>

using namespace std;

void ReadingInput(unordered_map<User, CONNECTION> &, string);

int main(int argc, char *argv[]) {
	if(argc != 4)
	{
		// Not enough arguments
		return 0;
	}
	string inputFileName = argv[1];
	string userName = argv[2];
	string outputFileName = argv[3];

	/*--------------------------------------------------------------------*/
	unordered_map < User, CONNECTION > SNAList;



	return 0;
}

void ReadingInput(unordered_map<User, CONNECTION> &SNAList, string inputFileName)
{
	ifstream inp_stream;

	cout << inputFileName << endl;	
	inp_stream.open(inputFileName);

	if( inp_stream.is_open() ) cout << "The file is opened." << endl;
	else
	{
		cout << "The file cannot be opened." << endl;
	}

	string input_raw;
	string username_temp, sub_temp;
	istringstream inp_SS;
	cout << "Stringstream created." << endl;
