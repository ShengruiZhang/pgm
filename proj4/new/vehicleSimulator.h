#ifndef VehicleSimulator_h
#define VehicleSimulator_h

#include "Vehicle.h"
#include "Input.h"
#include "State.h"

#include <string>
#include <vector>

class VehicleSimulator
{
private:
	std::vector <Input> _Inputs;
	void quickSort(std::vector <Input>&InputObjects, int start, int endIndex);// private function to sorting
	int Partition(std::vector <Input>&InputObjects, int start, int endIndex); // part of the sorting function

	std::vector <VehicleState> StateObject;
	Vehicle VehicleProcess;

public:
	VehicleSimulator();

	bool Reading(std::string FileName);
	int Writing(std::string OutputFile);
	bool isInputValid();

	void Sort();
	void QuickSort(std::vector <Input>&_Inputs, int start, int endIndex);

	void UpdatePassedStates();
};

#endif
