/*************/
/*
* File: Input.cpp
* Author: Safwan Elmadani
* NetID: safwanelmadani
* Date: 03/20/2016
*
* Description: The Input class holds the values for the u variables used in the kinematic model.
*/


using namespace std;
#include "Vehicle.h" 
#include "Input.h"
#include "State.h"
#include <math.h>
#include <string>
/*************************************************************************/
// constructs a new Input object with these initial values
Input::Input(double velocity, double tireAngle, double timeStamp) {
	_velocity = velocity;
	_tire_angle_rate = tireAngle;
	_timestamp = timeStamp;
	return;
}
/*************************************************************************/
// constructs an empty Input object
Input::Input() {
	_velocity = 0.0;
	_tire_angle_rate = 0.0;
	_timestamp = 0.0;
	return;
}
/*************************************************************************/

void Input::setVelocity(double velocity) { // sets the _velocity
	_velocity = velocity;
	return;
}
/*************************************************************************/

void Input::setTireAngleRate(double tireAngle) { // sets the _tire_angle_rate
	_tire_angle_rate = tireAngle;
	return;
}
/*************************************************************************/

void Input::setTimeStamp(double timeStamp) {  // sets the _timestamp
	_timestamp = timeStamp;
	return;
}
/*************************************************************************/

double Input::getVelocity() const { // returns the _velocity
	return _velocity;
}
/*************************************************************************/
double Input::getTireAngleRate() const { // returns the _tire_angle_rate
	return _tire_angle_rate;
}

/*************************************************************************/

double Input::getTimeStamp() const { // gets the _timestamp
	return _timestamp;
}

/*************************************************************************/
