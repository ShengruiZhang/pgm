#include "Vehicle.h"
#include "Input.h"
#include "State.h"
#include "vehicleSimulator.h"

#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3) {
		cout << "Ilegal arguments." << endl;
		cout << "Usage: catcar controlInputs stateOutputs" << endl;
		return 0;
	}

	VehicleSimulator Instance_1;

	// Reads the input file
	bool isValid = Instance_1.Reading(argv[1]);
	if (!isValid)
	{
		cout << "File can not be read." << endl;
		return 0;
	}

	Instance_1.Sort();

	if (Instance_1.isInputValid() == false)
	{
		cout << "The file is invalid." << endl;
		Instance_1.Writing(argv[2]);
		return 0;
	}
	else
	{
		Instance_1.UpdatePassedStates();
	}

	Instance_1.Writing(argv[2]);
	return 0;
}
