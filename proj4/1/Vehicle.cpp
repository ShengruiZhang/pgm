#include "Vehicle.h"
#include <iostream>

void Vehicle::setState(State x)
{
	_state = x;
}

////////////////////////////////////////////
// Constructor
Vehicle::Vehicle()
{
	_state.setXPos(0);
	_state.setYPos(0);
	_state.setTireAngle(0);
	_state.setHeading(0);

}
////////////////////////////////////////////
////////////////////////////////////////////


////////////////////////////////////////////
// Update the state of the current vehicle
void Vehicle::stateUpdate(Input inp, double duration)
{
	// Outputs
	double posX = 0;
	double posY = 0;
	double steering_angle = 0;
	double heading = 0;

	// Inputs //////////////////////////
	double velocity = inp.getVelocity();
	double time = inp.getTimeStamp();
	// x3, the steering rate
	double steering_rate = inp.getTireAngleRate();

	////////////////////////////////////////////


	// Calculing the final output with the given duration
	//
		// Calculate the new steering angle
	steering_angle = _state.getTireAngle() + duration * steering_rate;

		// Calculate the new heading
	//heading = _state.getHeading() + duration * velocity * (1 / L) * sin(steering_angle);
	heading = _state.getHeading() + duration * velocity * (1 / L) * sin(_state.getTireAngle());

		// x1(t+dt)
	posX = _state.getXPos() + duration * velocity * cos(_state.getTireAngle()) * cos(_state.getHeading());


	posY = _state.getYPos() + duration * velocity * cos(_state.getTireAngle()) * sin(_state.getHeading());

	// Update the final state
	_state.setTimeStamp(time + duration);
	_state.setXPos(posX);
	_state.setYPos(posY);


		// Write new angle to the _state at vehicle class as the most current value
	if(steering_angle > 0.5236) steering_angle = 0.5236;
	else if(steering_angle < -0.5236) steering_angle = -0.5236;
	_state.setTireAngle(steering_angle);

		// Write new heading
	//while(heading < 0) heading += M_TWO_TIMES_PI;
	//std::cout << "Before adding: " << heading << std::endl;
	while(heading < 0 && heading < M_TWO_TIMES_PI)
	{
		heading += M_TWO_TIMES_PI;
		//heading = 0;
		//std::cout << "After adding: " << heading << std::endl;
	}

	if(heading > M_TWO_TIMES_PI && heading > 0) heading -= M_TWO_TIMES_PI;
	//if(heading == M_TWO_TIMES_PI) heading = M_TWO_TIMES_PI;

	_state.setHeading(heading);
}
////////////////////////////////////////////
////////////////////////////////////////////



////////////////////////////////////////////
// Getter for state
State Vehicle::getState() const {return _state;}
////////////////////////////////////////////
////////////////////////////////////////////
