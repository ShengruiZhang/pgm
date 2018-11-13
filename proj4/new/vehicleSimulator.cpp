#include "vehicleSimulator.h"

#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

VehicleSimulator::VehicleSimulator()
{
}

bool VehicleSimulator::Reading(string FileName) {

	ifstream inp;     // Input file stream
	inp.open(FileName);

	double time, vel, steeringrate;

	Input temp;	// Temp for input

	if (!inp.is_open()) {
		cout << "Could not open file " << FileName << endl;
		return false;
	}

	string raw;
	istringstream inp_stream;
	while (!inp.eof())
	{
		getline(inp, raw);

		inp_stream.clear();
		inp_stream.str(raw);

		//if(!inp.eof())
		//{
			inp_stream >> time;
			inp_stream >> vel;
			inp_stream >> steeringrate;

			//cin.ignore();
			//cin >> raw;
			//if (inp_stream.fail()) inp_stream.clear();


			temp.setTimestamp(time);
			temp.setVel(vel);
			temp.setSteeringRate(steeringrate);


			cout << "Time: " << temp.getTimestamp() << " Vel: " << temp.getVel() << " Rate: " << temp.getSteeringRate();
			cout << endl;

			// Store the newly read data to Inputs
			if(!inp.eof()) _Inputs.push_back(temp);
		//}
	}

	inp.close();

	if (_Inputs.at(0).getTimestamp()) cout << "The file is invalid." << endl;

	for (unsigned int i = 0; i < _Inputs.size(); ++i)
	{
		//if (_Inputs.at(i).getTimestamp() < 0.0) return false;
		if (_Inputs.at(i).getTimestamp() > 100) return false;
		else if (_Inputs.at(i).getSteeringRate() < MIN_STEERING_ANGLE ||
							_Inputs.at(i).getSteeringRate() > MAX_STEERING_ANGLE) return false;
		else if (_Inputs.at(i).getVel() < 0.0 || _Inputs.at(i).getVel() > 30.0)	return false;
	}

	double duration;
	for (unsigned int i = 0; i < _Inputs.size() - 1; ++i) {
		duration = _Inputs.at(i + 1).getTimestamp() - _Inputs.at(i).getTimestamp();
		if (duration < 0.005 || duration > 0.201)
		{
		cout << "The file is invalid." << endl;
			return false;
		}
	}

	return true;
}

void VehicleSimulator::Sort()
{
	QuickSort(_Inputs, 0, _Inputs.size() - 1);
	return;
}

void VehicleSimulator::QuickSort(vector <Input>&_Inputs, int start, int endIndex)
{
	int partition;
	if (start < endIndex) {
		partition = Partition(_Inputs, start, endIndex);
		QuickSort(_Inputs, start, partition - 1);
		QuickSort(_Inputs, partition + 1, endIndex);
	}
}

int VehicleSimulator::Partition(vector <Input>&_Inputs, int start, int endIndex)
{
	Input temp;
	Input temp2;

	double pivot = _Inputs.at(endIndex).getTimestamp();
	int PartIndex = start;
	for (int i = start; i < endIndex; ++i) {
		if (_Inputs.at(i).getTimestamp() <= pivot)
		{
			temp = _Inputs.at(i);
			temp2 = _Inputs.at(PartIndex);
			_Inputs.at(i) = temp2;
			_Inputs.at(PartIndex) = temp;
			++PartIndex;
		}
	}
	// do swapping
	temp = _Inputs.at(PartIndex);
	_Inputs.at(PartIndex) = _Inputs.at(endIndex);
	_Inputs.at(endIndex) = temp;

	return PartIndex;
}

bool VehicleSimulator::isInputValid()
{
	if (_Inputs.at(0).getTimestamp()) return false;

	for (unsigned int i = 0; i < _Inputs.size(); ++i)
	{
		//if (_Inputs.at(i).getTimestamp() < 0.0) return false;
		if (_Inputs.at(i).getTimestamp() > 100) return false;
		else if (_Inputs.at(i).getSteeringRate() < MIN_STEERING_ANGLE ||
							_Inputs.at(i).getSteeringRate() > MAX_STEERING_ANGLE) return false;
		else if (_Inputs.at(i).getVel() < 0.0 || _Inputs.at(i).getVel() > 30.0)	return false;
	}

	double duration;
	for (unsigned int i = 0; i < _Inputs.size() - 1; ++i) {
		duration = _Inputs.at(i + 1).getTimestamp() - _Inputs.at(i).getTimestamp();
		if (duration < 0.005 || duration > 0.201) {
			return false;
		}
	}
	return true;
}

void VehicleSimulator::UpdatePassedStates() {
	VehicleState temp;
	double oup_duration;

	for (unsigned int i = 0; i < _Inputs.size(); ++i) {
		if (i == _Inputs.size() - 1)/*Last one add 200ms*/	oup_duration = 0.2;
		else	oup_duration = (_Inputs.at(i + 1).getTimestamp() - _Inputs.at(i).getTimestamp());
		VehicleProcess.StateUpdate(_Inputs.at(i), oup_duration);
		temp = VehicleProcess.getState();
		StateObject.push_back(temp);
	}
}

int VehicleSimulator::Writing(string output) {
	unsigned int i;
	ofstream oup; // Output file stream

	oup.open(output);// Open file

	if (!oup.is_open())
	{
		cout << "File can not be opened." << endl;
		return 1;
	}
	for (i = 0; i < StateObject.size(); ++i)
	{
		oup << StateObject.at(i).getTimestamp() << "," << StateObject.at(i).getxPos() << "," << StateObject.at(i).getyPos() << "," << StateObject.at(i).getSteeringAngle() << "," << StateObject.at(i).getHeading() << endl;
	}
	oup.close();

	return 0;
}
