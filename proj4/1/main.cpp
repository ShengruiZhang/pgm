#include "Vehicle.h"  // vehicl header file
#include "Input.h" // Input header file
#include "State.h" // state header file
#include <string>

#include <iostream>

#include "vehicleSimulator.h"

//------------------------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------------------------

int main(int argc, char *argv[]) { // command-line argument

	vehicleSimulator object;


	if (argc != 3) {// cheching for the number of command line argument.
		cout << "Usage: catcar controlInputs stateOutputs" << endl; // usage statement
		return 0;
	}

	
	int error=object.ReadFile(argv[1]);// calling funtion to read from a file and sort the input and chech whether they are valid or not.
	if (error == 1) {
		cout << "can't read the file" << endl;
		return 0;
	}
	object.sort();
	if (object.validate() == false) { // chech whether they are valid or not
		cout << "The file " << argv[1] << " is invalid." << endl;
		object.WritingOut(argv[2]);// output empty file here
		return 0;
	
	}
	else {

		object.update();
	}

	object.WritingOut(argv[2]);// calling to a member function to writr the data to a file.




	return 0;
}