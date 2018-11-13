#include "Input.h"

Input::Input()
{
	_velocity = 0.0;
	_steering_rate = 0.0;
	_timestamp = 0.0;
}

Input::Input(double _vel, double _ster_rate, double _time)
{
	_velocity = _vel;
	_steering_rate = _ster_rate;
	_timestamp = _time;
}

double Input::getVel() const
{
	return _velocity;
}

void Input::setVel(double _vel)
{
	_velocity = _vel;
}

double Input::getSteeringRate() const
{
	return _steering_rate;
}

void Input::setSteeringRate(double _ster_rate)
{
	_steering_rate = _ster_rate;
}

double Input::getTimestamp() const
{
	return _timestamp;
}

void Input::setTimestamp(double _time)
{
	_timestamp = _time;
}
