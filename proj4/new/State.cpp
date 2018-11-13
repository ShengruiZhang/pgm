#include "State.h"

VehicleState::VehicleState()
{
	_xPos = 0.0;
	_yPos = 0.0;
	_steering_angle = 0.0;
	_heading = 0.0;
	_timestamp = 0.0;
}

VehicleState::VehicleState(double _x, double _y, double _ster_angle, double _head, double _time)
{
	_xPos = _x;
	_yPos = _y;
	_steering_angle = _ster_angle;
	_heading = _head;
	_timestamp = _time;
}

/////////////////////////////////////////////////////////////////////
double VehicleState::getxPos() const
{
	return _xPos;
}
void VehicleState::setxPos(double _x)
{
	_xPos = _x;
}
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
double VehicleState::getyPos() const
{
	return _yPos;
}
void VehicleState::setyPos(double _y)
{
	_yPos = _y;
}
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
double VehicleState::getSteeringAngle() const
{
	return _steering_angle;
}
void VehicleState::setSteeringAngle(double _ster_angle)
{
	_steering_angle = _ster_angle;
}
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
double VehicleState::getHeading() const
{
	return _heading;
}
void VehicleState::setHeading(double _head)
{
	_heading = _head;
}
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
double VehicleState::getTimestamp() const
{
	return _timestamp;
}
void VehicleState::setTimestamp(double _time)
{
	_timestamp = _time;
}
/////////////////////////////////////////////////////////////////////
