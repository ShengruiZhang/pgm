#ifndef VEHICLE_H
#define VEHICLE_H

#include "State.h"
#include "Input.h"

#define L 2.6187
#define MAX_STEERING_ANGLE  0.5236
#define MIN_STEERING_ANGLE -0.5236
#define M_TWO_TIMES_PI (2 * M_PI)

class Vehicle
{
	private:
		VehicleState _State;
		void setState(VehicleState __state);

	public:
		Vehicle();

		void StateUpdate(Input _inp, double duration);
		VehicleState getState() const;

};

#endif
