/*************/
/*
* File: State.cpp
* Author: Safwan Elmadani
* NetID: safwanelmadani
* Date: 03/20/2016
*
* Description: class holds the values for  vehicle position, forward (x1),vehicle position, left/right (x2),tire angle (radians) (x3),heading (radians) (x4), and time stamp at which this state is measured.
*/



#include "Vehicle.h" 
#include "Input.h"
#include "State.h"
#include <math.h>

/*************************************************************************/
// constructs a new State object with these initial values
State::State(double x1, double x2, double x3, double x4, double timestamp) {
	_xpos = x1; // vehicle position, forward (x1)
	_ypos = x2; // vehicle position, left/right (x2)
	_tire_angle = x3; // tire angle (radians) (x3)
	_heading = x4; // heading (radians) (x4)
	_timestamp = timestamp; // time stamp at which this state is measured
	return;
}
/*************************************************************************/

State::State() {
	_xpos = 0.0; // vehicle position, forward (x1)
	_ypos = 0.0; // vehicle position, left/right (x2)
	_tire_angle = 0.0; // tire angle (radians) (x3)
	_heading = 0.0; // heading (radians) (x4)
	_timestamp = 0.0; // time stamp at which this state is measured
	return;
}
/*************************************************************************/

void State::setXPos(double xpos) { // sets the _xpos
	_xpos = xpos;
	return;
}
/*************************************************************************/
void State::setYPos(double ypos) { // sets the _ypos
	_ypos = ypos;
	return;
}
/*************************************************************************/
void State::setTireAngle(double angle) { // sets the _tire_angle
	if (angle > MAX_TIRE_ANGLE_RATE) {
		angle = MAX_TIRE_ANGLE_RATE;
	}
	if (angle < MIN_TIRE_ANGLE_RATE) {
		angle = MIN_TIRE_ANGLE_RATE;
	}
	_tire_angle = angle;
	return;
}
/*************************************************************************/
void State::setHeading(double heading) { // sets the _heading
	while (1) { // cheking if the heading is negative
		if (heading < 0.0) {
			heading = heading + M_TWO_TIMES_PI;
		}
		else {
			break;
		}
	}
	_heading = heading;
	return;
}
/*************************************************************************/
void State::setTimeStamp(double timestamp) { // sets the _timestamp
	_timestamp = timestamp;
	return;
}
/*************************************************************************/
double State::getXPos() const { // returns the _xpos
	return _xpos;
}
/*************************************************************************/
double State::getYPos() const { // returns the _ypos
	return _ypos;
}
/*************************************************************************/

double State::getTireAngle() const { // returns the _tire_angle
	return _tire_angle;
}
/*************************************************************************/

double State::getHeading() const { // gets the _heading
	return _heading;
}
/*************************************************************************/

double State::getTimeStamp() const { // gets the _timestamp
	return _timestamp;
}
/*************************************************************************/
