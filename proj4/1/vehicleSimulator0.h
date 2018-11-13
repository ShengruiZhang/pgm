#ifndef  VehicleSimulator_h

#define VehicleSimulator_h


#include "Vehicle.h"
#include "Input.h"
#include "State.h"

#include <string>

class VehicleSimulator {

private:
	//Data Surce
	vector <Input> _Inputs;
	void quickSort(vector <Input>&InputObjects, int start, int endIndex);// private function to sorting
	int Partition(vector <Input>&InputObjects, int start, int endIndex); // part of the sorting function


	//dataSinck
	vector<State> StateObject;
	///////////////////////

	Vehicle VehicleProcess;// vehicle class to process the commands

public:
	VehicleSimulator();
	bool Raeding(string FileName);
	void sort();       // performs qsort
	bool validate();   // returns true if the vector in Input objects is valid
	int GetSize();// get the size of the Input vector
	Input RetunInput(int i); // retun Input data
	double Getduration(int i); // retun duration
	////////////////////////////
	int WritingOut(char* OutputFile);// funtion to write in a file
	void SetStateObjects(State x);// insert the data in the vector
	//////////////////////////
	void update();

};

#endif
