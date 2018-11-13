#include "Vehicle.h"
#include "State.h"
#include "Input.h"

#include <math.h>

void Vehicle::setState(VehicleState __state)
{
	_State = __state;
}

////////////////////////////////////////////
// Constructor
Vehicle::Vehicle()
{
	_State.setxPos(0);
	_State.setyPos(0);
	_State.setSteeringAngle(0);
	_State.setHeading(0);

}
////////////////////////////////////////////
////////////////////////////////////////////


////////////////////////////////////////////
// Update the state of the current vehicle
void Vehicle::StateUpdate(Input _inp, double duration)
{
	// Outputs
	double posX = 0;
	double posY = 0;
	double steering_angle = 0;
	double heading = 0;

	// Inputs //////////////////////////
	double velocity = _inp.getVel();
	double time = _inp.getTimestamp();
	// x3, the steering rate
	double steering_rate = _inp.getSteeringRate();

	/////////////////////////////////////////////////////////////////////
	// Calculing the final output with the given duration
	//
		// Calculate the new steering angle
	steering_angle = _State.getSteeringAngle() + duration * steering_rate;

		// Calculate the new heading
	heading = _State.getHeading() + duration * velocity * (1 / L) * sin(_State.getSteeringAngle());

		// x1(t+dt)
	posX = _State.getxPos() + duration * velocity * cos(_State.getSteeringAngle()) * cos(_State.getHeading());
	posY = _State.getyPos() + duration * velocity * cos(_State.getSteeringAngle()) * sin(_State.getHeading());

	// Update the final state
	_State.setTimestamp(time + duration);
	_State.setxPos(posX);
	_State.setyPos(posY);


		// Write new angle to the _state at vehicle class as the most current value
	if(steering_angle > MAX_STEERING_ANGLE) steering_angle = MAX_STEERING_ANGLE;
	else if(steering_angle < MIN_STEERING_ANGLE) steering_angle = MIN_STEERING_ANGLE;
	_State.setSteeringAngle(steering_angle);

		// Write new heading
	while(heading < 0 && heading < M_TWO_TIMES_PI)
	{
		heading += M_TWO_TIMES_PI;
	}

	if(heading > M_TWO_TIMES_PI && heading > 0) heading -= M_TWO_TIMES_PI;

	_State.setHeading(heading);
}
////////////////////////////////////////////
////////////////////////////////////////////


////////////////////////////////////////////
// Getter for state
VehicleState Vehicle::getState() const {return _State;}
////////////////////////////////////////////
