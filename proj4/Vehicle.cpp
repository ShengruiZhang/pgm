#include "Vehicle.h"

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

	// x4, the heading
	heading = velocity * ( 1 / L ) * sin(steering_angle);

	// x1, the x position
	posX = velocity * cos(steering_angle) * cos(heading);

	// x2, the y position
	posY = velocity * cos(steering_angle) * sin(heading);


	// Calculing the final output with the given duration
	//
	// x1(t+dt)
	posX = (posX * time) + (duration * velocity * time * cos( (steering_angle * time))
	* cos( (heading * time)));
	
	
	// Update the final state
	_state.setTimeStamp(time + duration);
	_state.setXPos(posX);
}
////////////////////////////////////////////
////////////////////////////////////////////



////////////////////////////////////////////
// Getter for state
State Vehicle::getState() const {return _state;}
////////////////////////////////////////////
////////////////////////////////////////////
