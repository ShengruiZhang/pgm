#ifndef STATE_H
#define STATE_H

class VehicleState
{
	private:
		double _xPos;
		double _yPos;
		double _steering_angle;
		double _heading;
		double _timestamp;

	public:
		VehicleState();
		VehicleState(double _x, double _y, double _ster_angle, double _head, double _time);

		double getxPos() const;
		void setxPos(double _x);

		double getyPos() const;
		void setyPos(double _y);

		double getSteeringAngle() const;
		void setSteeringAngle(double _ster_angle);

		double getHeading() const;
		void setHeading(double _head);

		double getTimestamp() const;
		void setTimestamp(double _time);

};

#endif
