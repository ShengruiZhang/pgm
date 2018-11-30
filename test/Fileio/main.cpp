#include <iostream>
#include <String>		// ---]
#include <iomanip>		// ---]
#include <sstream>		// Stringstream
#include <fstream>		// Filestream
#include <vector>

#define USE_UNORDERED_MAP 0 
#if USE_UNORDERED_MAP
#include <unordered_map>
#endif


#define DEBUG_ENABLE 1
typedef unsigned int uint;


/*----------- Class Definition ------------------------*/
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


/*--------------------Constructors--------------------------*/
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



///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

uint ReadingConstr(vector <F1_Entry> &, string);
void PrintingConstr(vector <F1_Entry> &);
#if USE_UNORDERED_MAP
unordered_map <uint, uint> ReadConstr();
#endif


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {

#if USE_UNORDERED_MAP
	unordered_map <uint,uint> random = ReadConstr();
	cout << random.at(1) << endl;
	cout << random.at(2) << endl;
	cout << random.at(3) << endl;
	cout << random.at(145) << endl;
	return 0;
#endif

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
	F1_Entry testobj_1("Test", "Formula One", "Honda", 500);
	F1_Entry testobj_2("Test_2", "Formula One", "Ferrai", 400);
	F1_Entry testobj_3("Test_3", "Formula One", "McLaren", 300);

	Constructors.push_back(testobj_1);
	Constructors.push_back(testobj_2);
	Constructors.push_back(testobj_3);

	cout << "Vector size: " << Constructors.size() << endl;
	PrintingConstr(Constructors);

	cout << "------------------------------------" << endl;

	// Clear the vector before a new reading
	Constructors.clear();
	ReadingConstr(Constructors, inputFileName);

	if(Constructors.empty()) cout << "The vector is empty." << endl;

	PrintingConstr(Constructors);

	return 0;
}



///////////////////////////////////////
#if USE_UNORDERED_MAP
unordered_map <uint, uint> ReadConstr()
{
	unordered_map <uint, uint> test =
	{
		{1, 856},
		{2, 465},
		{3, 4654}
	};
	test.insert({145, 322568});
	return test;
}
#endif


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
	// Temp object
	F1_Entry temp;

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
		
		inp_SS.clear();
		inp_SS.str(input_raw);
		inp_SS >> mfg_temp;
		inp_SS >> chassis_temp;
		inp_SS >> pu_temp;
		inp_SS >> points;

#if DEBUG_ENABLE
		cout << mfg_temp << endl;
		cout << chassis_temp << endl;
		cout << pu_temp << endl;
		cout << points << endl << endl;
#endif

		temp.setConstrName(mfg_temp);
		temp.setChassis(chassis_temp);
		temp.setPowerUnit(pu_temp);
		temp.setConstrPoints(points);

		if(1) Entry.push_back(temp);
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
		cout << "Constructor: " << setw(33) << left << Entry.at(i).GetConstrName();
		cout << " Chassis: " << setw(18) << left << Entry.at(i).GetChassis();
		cout << " PowerUnit: " << setw(10) << left << Entry.at(i).GetPowerUnit();
		cout << endl << "Current Points: " << setw(3) << right << Entry.at(i).GetConstrPoints();
		cout << endl << endl;
	}
}
