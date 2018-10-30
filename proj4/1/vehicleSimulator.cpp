#include "vehicleSimulator.h"

#include <iostream>
/***************************************************************************************/

vehicleSimulator::vehicleSimulator(): InputObjects(0),StateObject(0) {


}

/*************************************************************************/
int vehicleSimulator::ReadFile(char*FileName) {// read from a file
	string inputLine;
	double time, u1, u2;
	Input data;
	ifstream inFS;     // Input file stream
	inFS.open(FileName);
	if (!inFS.is_open()) {
		cout << "Could not open file " << FileName << endl;
		return 1;
	}

	while (!inFS.eof()) { // cheking the enf od the file
		getline(inFS, inputLine);
		istringstream lineStream(inputLine); // parsing the input
		lineStream >> time;
		lineStream >> u1;
		lineStream >> u2;
		if (lineStream.fail()) {
			continue;
		}
		data.setVelocity(u1); // update the Input vector 
		data.setTireAngleRate(u2);
		data.setTimeStamp(time);
		if (!inFS.eof()) { // if doesn't equal eof
			InputObjects.push_back(data);
		}

	}

	inFS.close();// close the file
	if (InputObjects.size() == 0) {
		return 1;
	}
	return 0;
}
/*************************************************************************/

void vehicleSimulator::sort() {       // performs qsort

	quickSort(InputObjects, 0, InputObjects.size() - 1);
	return;

}
/*************************************************************************/


void vehicleSimulator::quickSort(vector <Input>&InputObjects, int start, int endIndex) {// quick sorting funtion
	int partition;
	if (start < endIndex) {

		partition = Partition(InputObjects, start, endIndex);
		quickSort(InputObjects, start, partition - 1);
		quickSort(InputObjects, partition + 1, endIndex);
	}
}
///*************************************************************************/
//
int vehicleSimulator::Partition(vector <Input>&InputObjects, int start, int endIndex) {// part of the quick sort function
	int i;
	Input temp;

	double pivot = InputObjects.at(endIndex).getTimeStamp();
	int PartIndex = start;
	for (i = start; i < endIndex; i++) {
		if (InputObjects.at(i).getTimeStamp() <= pivot) {
			// do swapping
			temp = InputObjects.at(i);
			InputObjects.at(i) = InputObjects.at(PartIndex);
			InputObjects.at(PartIndex) = temp;

			PartIndex++;
		}
	}
	// do swapping
	temp = InputObjects.at(PartIndex);
	InputObjects.at(PartIndex) = InputObjects.at(endIndex);
	InputObjects.at(endIndex) = temp;

	return PartIndex;
}


/*************************************************************************/
bool vehicleSimulator::validate() {// check if the input file is valid
	int i;
	double duration;
	double timeSt;
	timeSt = InputObjects.at(0).getTimeStamp();// �	The rst element of the sorted list must be at exactly time 0.
	if (timeSt != 0.0) {
		return false;
	}
	for (i = 0; i < InputObjects.size(); i++) {
		//�checking commanded tire angle rate
		if (InputObjects.at(i).getTireAngleRate() < MIN_TIRE_ANGLE || InputObjects.at(i).getTireAngleRate() > MAX_TIRE_ANGLE) {
			return false;
		}
		if (InputObjects.at(i).getVelocity() < 0.0 || InputObjects.at(i).getVelocity() > 30.0) {//�	Commanded velocity must be between [0, 30] 
			return false;
		}
		if (InputObjects.at(i).getTimeStamp() < 0.0) {//�	Time values must be non-negative
			return false;
		}
	}
	for (i = 0; i < InputObjects.size() - 1; i++) {//�Duration between sorted input objects must be between [5, 201] ms
		duration = InputObjects.at(i + 1).getTimeStamp() - InputObjects.at(i).getTimeStamp();
		if (duration < 0.005 || duration > 0.201) {
			return false;
		}
	}
	return true;
}
/***************************************************************************************/
int vehicleSimulator::GetSize() { // get the size of the Input vector
	return InputObjects.size();

}
/***************************************************************************************/
Input vehicleSimulator::RetunInput(int i) {  // retun Input data
	return InputObjects.at(i);
}

/***************************************************************************************/
double vehicleSimulator::Getduration(int i) { // retun duration 
	if (i == InputObjects.size() - 1) {
		return 0.2;
	}
	else {
		return	 InputObjects.at(i + 1).getTimeStamp() - InputObjects.at(i).getTimeStamp();
	}

}
/***************************************************************************************/
void vehicleSimulator::update() {
	State temp;
	int i = 0;
	for (i = 0; i < GetSize(); i++) {
		VehicleProcess.stateUpdate(RetunInput(i), Getduration(i));//pass Input values along to the Vehicle

		temp = VehicleProcess.getState();
		SetStateObjects(temp);// store states in a vecotr
	}

}
/***************************************************************************************/
void vehicleSimulator::SetStateObjects(State x) { // insert the data in the vector
	StateObject.push_back(x);
	return;
}
/***************************************************************************************/
int vehicleSimulator::WritingOut(char* OutFile) { // funtion to write in a file
	int i;
	ofstream outFS; // Output file stream

	outFS.open(OutFile);// Open file
	if (!outFS.is_open()) {
		cout << "Could not open file to write." << endl;
		return 1;
	}
	for (i = 0; i < StateObject.size(); i++) {
		outFS << StateObject.at(i).getTimeStamp() << "," << StateObject.at(i).getXPos() << "," << StateObject.at(i).getYPos() << "," << StateObject.at(i).getTireAngle() << "," << StateObject.at(i).getHeading() << endl;
	}
	outFS.close();

	return 0;

}
/***************************************************************************************/