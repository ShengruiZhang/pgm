#ifndef VEHICLESIMULATOR_H
#define VEHICLESIMULATOR_H

#include "Vehicle.h"
#include "Input.h"
#include "State.h"


typedef unsigned int uint;

class VehicleSimulator
{
	private:
		vector <Input> _inp;

		void QuickSort(vector <Input> &inp, uint left, uint right);

		vector <VehicleState> State
}
#endif
