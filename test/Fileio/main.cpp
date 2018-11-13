#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>

typedef unsigned int uint;

class F1_Entry {
	private:
		std::string ConstrName;
		std::string Chassis;
		std::string PowerUnit;
		uint ConstrPoints;
	public:
		F1_Entry();
		F1_Entry(std::string constr, std::string _chassis, std::string _powerunit, uint points);

		std::string GetConstrName() { return ConstrName; }
		void setConstrName(std::string constr) { ConstrName = constr; }
		
		std::string GetChassis() { return Chassis; }
		void setChassis(std::string _chassis) { Chassis = _chassis; }

		std::string GetPowerUnit() { return PowerUnit; }
		void setPowerUnit(std::string _powerunit) { PowerUnit = _powerunit; }

		uint GetConstrPoints() { return ConstrPoints; }
		void setConstrPoints(uint points) { ConstrPoints = points; }

};

using namespace std;

F1_Entry::F1_Entry()
{
	ConstrName	= "empty";
	Chassis		= "empty";
	PowerUnit	= "empty";
	ConstrPoints	= 0;
}

F1_Entry::F1_Entry(string constr, string _chassis, string _powerunit, uint points)
{
	ConstrName	= constr;
	Chassis		= _chassis;
	PowerUnit	= _powerunit;
	ConstrPoints	= points;
}

uint ReadingConstr(vector <F1_Entry> &, string);
void PrintingConstr(vector <F1_Entry> &);

int main(int argc, char *argv[]) {

	/* If use commandline arguments, best 
	 * 	check the count first, so that you don't have to 
	 * 	deal with copying a empty pointer to a string.
	*/
	if(argc != 3)
	{
		cout << "Illegal arguments." << endl;
		cout << "Use: powerunit inputFileName outputFileName";
		return 0;
	}
	/* Since the argument count is already checked,
		copying any argv is safe to do.
		*/
	string inputFileName = argv[1];
	string outputFileName = argv[2];

	// Create an Constructors list object
	vector <F1_Entry> Constructors;

	// Hardcore for testing Constructors
	F1_Entry testobj("Test", "Formula One", "Honda", 500);
	F1_Entry testobj_2("Test_2", "Formula One", "Ferrai", 400);
	F1_Entry testobj_3("Test_3", "Formula One", "McLaren", 300);

	Constructors.push_back(testobj);
	Constructors.push_back(testobj_2);
	Constructors.push_back(testobj_3);

	cout << "Vector size: " << Constructors.size() << endl;
	PrintingConstr(Constructors);

	cout << "------------------------------------" << endl;

	ReadingConstr(Constructors, inputFileName);

	Constructors.clear();
	if(Constructors.empty()) cout << "The vector is empty." << endl;

	return 0;
}


///////////////////////////////////////
uint ReadingConstr(vector <F1_Entry> &Entry, string inputFile)
{
	// Create a input file stream to open the file
	ifstream inp_stream;

	// Open the file
	cout << inputFile << endl;
	inp_stream.open(inputFile);

	// Check if the file can be opened
	if( inp_stream.is_open() ) cout << "The file is opened." << endl;
	else
	{
		cout << "The file cannot be opened." << endl;
		return 0;
	}

	// Now the file is ready for reading
	
	// Create a string for raw input
	string input_raw;
	// Also create a bunch temp for setting the value later
	string mfg_temp, chassis_temp, pu_temp;
	uint points;

	// Create a stringstream for later use
	istringstream inp_SS;
	cout << "Stringstream created." << endl;

	// Use getline to get the entire line,
	// keep reading until EOF
	// This way process the input line by line
	while( !inp_stream.eof() )
	{
		cout << "Getting a line" << endl;
		getline(inp_stream, input_raw);
		cout << "Raw: " << input_raw << endl;
		inp_SS.str(input_raw);
		inp_SS >> mfg_temp;
		cout << mfg_temp << endl << endl;
	}

	return 1;
}


///////////////////////////////////////
void PrintingConstr(vector <F1_Entry> &Entry)
	/* Passing the vector as referecnce, to save memory and so that
	 * 	the complier won't be mad
	 *
	 * Declaring teh vector as const so that the content won't be
	 * 	changed unexpectly
	*/
{
	for(uint i = 0; i < Entry.size(); ++i)
	{
		cout << "Constructor: " << setw(10) << left << Entry.at(i).GetConstrName();
		cout << " Chassis: " << setw(8) << left << Entry.at(i).GetChassis();
		cout << " PowerUnit: " << setw(10) << left << Entry.at(i).GetPowerUnit();
		cout << " Current Points: " << setw(3) << right << Entry.at(i).GetConstrPoints();
		cout << endl;
	}
}
