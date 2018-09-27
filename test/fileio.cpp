#include <iostream>
#include <fstream>
#include <ios>
#include <iomanip>

using namespace std;

/****************************************************************
 *  Function Prototype
 */

void ReadCardsFromFile(string filename);




int main(int argc, char *argv[])
{
	// Declare a new input file stream
	ifstream _PU;

	cout << "Opening file: " << argv[1] << endl;

	_PU.open(argv[1]);

	if (!_PU.is_open())
	{
		cout << "Unable to open" << endl;
		return 1;
	}
	else {
		cout << "Opened successfully" << endl << endl;
	}

	string temp[8];
	string mfg[4];
	string model[4];

	int i = 0;
	int k = 0;

	//Reading from file
	while (!_PU.eof())
	{
		_PU >> temp[i];
		++i;
	}

	// String manipulation
	for (i = 0; i < 8; i += 2)
	{
		mfg[k] = temp[i];
		++k;
	}

	k = 0;
	for (i = 1; i < 8; i += 2)
	{
		model[k] = temp[i];
		++k;
	}

	cout << setfill('-');
	for (int j = 0; j < 4; ++j)
	{
		cout << setw(20) << left << "Manufacturer: ";
		cout << left << " " << mfg[j] << endl;

		cout << "Model: " << model[j] << endl << endl;
	}

	_PU.close();

	// Output stuff to a file
	ofstream _pulist;

	_pulist.open(argv[2]);

	if (!_pulist.is_open())
	{
		cout << "Can't open output file" << endl;
		return 1;
	}

	for (k = 0; k < 4; ++k)
	{
		/*
		_pulist << setprecision(10) << k << endl;
	       	_pulist << fixed << k << endl;
		_pulist << scientific << k << endl;	
		*/
		
		_pulist << "Manufacturer: "; 

		_pulist << setw(10) << right << mfg[k] << endl;
		_pulist << "Model: " << model[k] << endl << endl;
	}

	// getline() takes a line of text, then discard the new line.
	// >> operator skips the whitespace, it reads from a text to the next whitespace, the new line will be left
	// 	in the buffer.
	// So >> only takes any integer, text, nothing else more than that.
	// getline() preserves the format from a line of text.
	
	return 0;
}

void ReadCardsFromFile(string filename)
{
	ifstream cards;

	cards.open(filename);	

	if (cards.is_open()) {
		cout << "File is opened" << endl;
	}
	else {
		cout << "File can't be opened" << endl;
	}

}
