#ifndef  vehicleSimulator_h

#define vehicleSimulator_h


#include "Vehicle.h"  // vehicl header file
#include "Input.h" // Input header file
#include "State.h" // state header file
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>


using namespace std;

class vehicleSimulator {

private:
	//Data Surce
	vector <Input> InputObjects; // vector of Input data
	void quickSort(vector <Input>&InputObjects, int start, int endIndex);// private function to sorting
	int Partition(vector <Input>&InputObjects, int start, int endIndex); // part of the sorting function


	//dataSinck
	vector<State> StateObject;
	///////////////////////

	Vehicle VehicleProcess;// vehicle class to process the commands



public:
	vehicleSimulator();
	int ReadFile(char*FileName);
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















#endif // ! 
